#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "user.h"
#include "message.h"

namespace fs = std::filesystem;

using namespace std;

void demo_perms (fs::perms p){
 std::cout  << ((p& fs::perms::owner_read)  != fs::perms::none ? "r" : "-")
            << ((p& fs::perms::owner_write) != fs::perms::none ? "w" : "-")
            << ((p& fs::perms::owner_exec)  != fs::perms::none ? "x" : "-")
            << ((p& fs::perms::group_read)  != fs::perms::none ? "r" : "-")
            << ((p& fs::perms::group_write) != fs::perms::none ? "w" : "-")
            << ((p& fs::perms::group_exec)  != fs::perms::none ? "x" : "-")
            << ((p& fs::perms::others_read)  != fs::perms::none ? "r" : "-")
            << ((p& fs::perms::others_write) != fs::perms::none ? "w" : "-")
            << ((p& fs::perms::others_exec)  != fs::perms::none ? "x" : "-")
            << '\n';

}

bool is_file_accessible(const string& filename) {
ifstream file(filename.c_str());
return file.good();
}

void write_user_to_file(const User& user, const string& filename) {
ofstream outfile(filename.c_str());
if (outfile.good()) {
outfile << user.getName() << endl;
outfile << user.getLogin() << endl;
outfile << user.getPass() << endl;
}
outfile.close();
}

void write_message_to_file(const Message& msg, const string& filename) {
ofstream outfile(filename.c_str());
if (outfile.good()) {
outfile << msg.getText() << endl;
outfile << msg.getSender() << endl;
outfile << msg.getReceiver() << endl;
}
outfile.close();
}

User read_user_from_file(const string& filename) {
ifstream infile(filename.c_str());
if (infile.good()) {
string name, login, pass;
getline(infile, name);
getline(infile, login);
getline(infile, pass);
return User(name, login, pass);
}
infile.close();
return User("", "", "");
}

Message read_message_from_file(const string& filename) {
ifstream infile(filename.c_str());
if (infile.good()) {
string text, sender, receiver;
getline(infile, text);
getline(infile, sender);
getline(infile, receiver);
return Message(text, sender, receiver);
}
infile.close();
return Message("", "", "");
}

int main() {

//creat files and set permissions
std::ofstream("user.txt");
fs::permissions("user.txt", 
    fs::perms::group_all |
    fs::perms::others_all,
    fs::perm_options::remove);

std::cout <<"File user.txt has permissions: ";
demo_perms(fs::status("user.txt").permissions());

std::ofstream ("message.txt");
fs::permissions("message.txt", 
    fs::perms::group_all |
    fs::perms::others_all,
    fs::perm_options::remove);

std::cout <<"File message.txt has permissions: ";
demo_perms(fs::status("message.txt").permissions());



// checking file availability
if (!is_file_accessible("user.txt")) {
cout << "Error: file user.txt do not availably for read/write !";
return 1;
}
if (!is_file_accessible("message.txt")) {
cout << "Error: file message.txt do not availably for read/write !";
return 1;
}

// make user and message
User user("Alexey", "Gidkih", "Alex");
Message msg("Home work 18_12", "Gidkih", "Mentor");

// write object into file
write_user_to_file(user, "user.txt");
write_message_to_file(msg, "message.txt");

// read object from file and output on the console
User read_user = read_user_from_file("user.txt");
Message read_msg = read_message_from_file("message.txt");
cout << "User: " << read_user.getName() << endl;
cout << "Login: " << read_user.getLogin() << endl;
cout << "Password: " << read_user.getPass() << endl;

cout << "Message: " << read_msg.getText() << endl;
cout << "Sender: " << read_msg.getSender() << endl;
cout << "Recepient: " << read_msg.getReceiver() << endl;

//fs::permissions("user.txt", fs::perms::group_write | fs::perms::group_read,fs::perm_options::nofollow);





return 0;
}