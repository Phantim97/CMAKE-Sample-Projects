#include "leaky_impl.h"

int do_some_work()
{
	//allocate an array
	double* my_arr = new double[1000];

	//do some work
	 
	//we forget to delete array
	return 0;
}