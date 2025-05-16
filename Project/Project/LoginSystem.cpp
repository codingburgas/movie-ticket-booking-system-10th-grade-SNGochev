#include "LoginSystem.h"
#include <iostream>

using namespace std;

LoginSystem::LoginSystem() {
    storedUsername = "user";
    storedPassword = "pass";
    isLoggedIn = false;
}

void LoginSystem::loginUser() {
    string username, password;
    while (!isLoggedIn) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (username == storedUsername && password == storedPassword) {
            cout << "Login successful! Welcome, " << username << "!\n";
            isLoggedIn = true;
        }
        else {
            cout << "Invalid username or password. Try again.\n";
        }
    }
}

bool LoginSystem::isAuthenticated() {
    return isLoggedIn;
}