#include "Message.h"

#include <iostream>

std::ostream& Message::_printObject(std::ostream& os)
{
	os << "This is my very nice message \n";
	os << _message;

	return os;
}