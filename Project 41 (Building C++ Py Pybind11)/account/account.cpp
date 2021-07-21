#include "account.h"

Account::Account()
{
	_balance = 0.0;
}

Account::~Account()
{
}

void Account::deposit(const double amount)
{
	_balance += amount;
}

void Account::withdraw(const double amount)
{
	_balance -= amount;
}

double Account::get_balance() const
{
	return _balance;
}
