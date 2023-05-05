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