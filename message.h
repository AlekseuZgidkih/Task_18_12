#include <iostream>

class Message {
std::string _text;
std::string _sender;
std::string _receiver;

public:
Message(std::string text, std::string sender, std::string receiver) {
_text = text;
_sender = sender;
_receiver = receiver;
}
std::string getText() const { return _text; }
std::string getSender() const { return _sender; }
std::string getReceiver() const { return _receiver; }
};