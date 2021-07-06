#pragma once
#include <iosfwd>
#include <string>

class Message
{
private:
	std::string _message;
	std::ostream& _printObject(std::ostream& os);
public:
	Message(const std::string& m) : _message(m) {}

	friend std::ostream& operator<<(std::ostream& os, Message& obj)
	{
		return obj._printObject(os);
	}
};