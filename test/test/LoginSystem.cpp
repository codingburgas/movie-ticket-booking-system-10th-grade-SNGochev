#include "LoginSystem.h"
#include <iostream>
#include <fstream>
#include <conio.h>  // For _getch() on Windows

using namespace std;

LoginSystem::LoginSystem() {
    isLoggedIn = false;
    loadUsersFromFile();

    // Ensure default admin exists
    if (userDatabase.find("admin") == userDatabase.end()) {
        userDatabase["admin"] = "admin123";  // Default admin password
        saveUsersToFile();
    }
}

void LoginSystem::loadUsersFromFile() {
    ifstream infile("users.txt");
    string username, password;
    while (infile >> username >> password) {
        userDatabase[username] = password;
    }
    infile.close();
}

void LoginSystem::saveUsersToFile() {
    ofstream outfile("users.txt");
    for (const auto& user : userDatabase) {
        outfile << user.first << " " << user.second << endl;
    }
    outfile.close();
}

string LoginSystem::getMaskedPassword() {
    string password;
    char ch;
    while ((ch = _getch()) != '\r') {  // Enter key
        if (ch == '\b') {
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

void LoginSystem::registerUser() {
    string username, password;
    cout << "\n🔐 Register New Account\n";
    cout << "Enter new username: ";
    cin >> username;

    if (userDatabase.find(username) != userDatabase.end()) {
        cout << "⚠️ Username already exists. Try another.\n";
        return;
    }

    cout << "Enter new password: ";
    password = getMaskedPassword();

    userDatabase[username] = password;
    saveUsersToFile();

    cout << "✅ Registration successful!\n";
}

void LoginSystem::loginUser() {
    string username, password;
    while (!isLoggedIn) {
        cout << "\n1. Login\n2. Register\nChoose an option: ";
        int option;
        cin >> option;

        if (option == 2) {
            registerUser();
            continue;
        }

        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        password = getMaskedPassword();

        auto it = userDatabase.find(username);
        if (it != userDatabase.end() && it->second == password) {
            cout << "\n✅ Login successful! Welcome, " << username << "!\n";
            isLoggedIn = true;
            currentUsername = username;
        }
        else {
            cout << "❌ Invalid username or password. Try again.\n";
        }
    }
}

bool LoginSystem::isAuthenticated() {
    return isLoggedIn;
}

string LoginSystem::getUsername() {
    return currentUsername;
}

bool LoginSystem::isAdmin() {
    return currentUsername == "admin";
}
