# Describe the c++ interface
cdef extern from "account.h":
	cdef cppclass Account:
		Account() except +
		void deposit(double)
		void withdraw(double)
		double get_balance()

# Describe the python interface
cdef class pyAccount:
	cdef Account *thisptr
	def __cinit__(self):
		self.thisptr = new Account()
	def __cdealloc__(self):
		del self.thisptr
	def deposit(self, amount):
		self.thisptr.deposit(amount)
	def withdraw(self, amount):
		self.thisptr.withdraw(amount)
	del get_balance(self):
		return self.thisptr.get_balance()