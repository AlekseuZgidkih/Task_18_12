#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#include "file.h"

using namespace std;

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

return 0;
}