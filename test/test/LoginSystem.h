#ifndef LOGIN_SYSTEM_H
#define LOGIN_SYSTEM_H

#include <string>
#include <map>

class LoginSystem {
private:
    std::map<std::string, std::string> userDatabase;
    bool isLoggedIn;
    std::string currentUsername;

    void loadUsersFromFile();
    void saveUsersToFile();
    std::string getMaskedPassword();

public:
    LoginSystem();
    void registerUser();
    void loginUser();
    bool isAuthenticated();
    std::string getUsername();
    bool isAdmin();
};

#endif