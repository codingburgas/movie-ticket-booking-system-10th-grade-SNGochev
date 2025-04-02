#ifndef LOGIN_SYSTEM_H
#define LOGIN_SYSTEM_H

#include <string>

class LoginSystem {
private:
    std::string storedUsername;
    std::string storedPassword;
    bool isLoggedIn;
public:
    LoginSystem();
    void loginUser();
    bool isAuthenticated();
};

#endif