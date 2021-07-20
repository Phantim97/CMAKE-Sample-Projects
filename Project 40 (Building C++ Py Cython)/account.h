#pragma once

class Account
{
private:
	double _balance;
public:
	Account();
	~Account();

	void deposit(const double amount);
	void withdraw(const double amount);
	double get_balance() const;
};