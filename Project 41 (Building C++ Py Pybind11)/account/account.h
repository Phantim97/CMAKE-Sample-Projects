#pragma once

#include <pybind11/pybind11.h>

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

namespace py = pybind11;

PYBIND11_MODULE(account, m)
{
	py::class_<Account>(m, "Account")
		.def(py::init())
		.def("deposit", &Account::deposit)
		.def("withdraw", &Account::withdraw)
		.def("get_balance", &Account::get_balance);
}