#include <iostream>
#include <chrono>

#include <Eigen\Dense>

EIGEN_DONT_INLINE
double simple_function(Eigen::VectorXd& va, EigenVectorXd& vb)
{
	//Dot product of va and vb
	double d = va.dot(vb);
	return d;
}

int main()
{
	int len = 1000000;
	int num_repititions = 100;

	//generate two random vectors
	Eigen::VectorXd va = Eigen::VectorXd::Random(len);
	Eigen::VectorXd vb = Eigen::VectorXd::Random(len);

	double result = 0.0;
	
	auto start = std::chrono::system_clock::now();
	
	for (int i = 0; i < num_repititions; i++)
	{
		result = simple_function(va, vb);
	}
	
	auto end = std::chrono::system_clock::now();
	auto elapsed_seconds = end - start;

	std::cout << "Result: " << result << '\n';
	std::cout << "Elapsed Time: " << elapsed_seconds.count() << '\n';

	

	return 0;
}