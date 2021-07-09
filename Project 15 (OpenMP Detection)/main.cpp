#include <iostream>
#include <omp.h>
#include <string>

int main(int argc, char* argv[])
{
	std::cout << "Number of available processors: " << omp_get_num_procs() << '\n';
	std::cout << "Number of threads: " << omp_get_max_threads() << '\n';

	long long n;

	if (argc > 1)
	{
		n = std::stoi(argv[1]);
	}
	else
	{
		n = 1000000000;
	}
	std::cout << "We will now sum from one to " << n << '\n';

	//start timer
	double t = omp_get_wtime();

	long long s = 0LL;

#pragma omp parallel for reduction(+ : s)
	for (long long i = 1; i <= n; i++)
	{
		s += i;
	}

	//stop timer
	double t1 = omp_get_wtime();

	std::cout << "sum: " << s << '\n';
	std::cout << "Elapsed wall clock time: " << t1 - t << " seconds\n";

	return 0;
}