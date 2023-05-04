
#include <iostream>

class User {
std::string _name;
std::string _login;
std::string _pass;

public:
User(std::string name, std::string login, std::string pass) {
_name = name;
_login = login;
_pass = pass;
}

std::string getName() const { return _name; }
std::string getLogin() const { return _login; }
std::string getPass() const { return _pass; }
};