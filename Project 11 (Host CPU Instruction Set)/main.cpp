#include "config.h"

#include <cstdlib>
#include <iostream>

int main()
{
	std::cout << "Number of logical cores: " << NUMBER_OF_LOGICAL_CORES << '\n';
	std::cout << "Number of physical cores: " << NUMBER_OF_PHYSICAL_CORES << '\n';
	std::cout << "Total virtual memory in megabytes: " << TOTAL_VIRTUAL_MEMORY << '\n';
	std::cout << "Available virtual memory in megabytes: " << AVAILABLE_VIRTUAL_MEMORY << '\n';
	std::cout << "Total physical memory in megabytes: " << TOTAL_PHYSICAL_MEMORY << '\n';
	std::cout << "Available physical memory in megabytes: " << AVAILABLE_PHYSICAL_MEMORY << '\n';
	std::cout << "Processor is 64Bit: " << IS_64BIT << '\n';
	std::cout << "Processor has floating point unit: " << HAS_FPU << '\n';
	std::cout << "Processor supports MMX instructions: " << HAS_MMX << '\n';
	std::cout << "Processor supports Ext. MMX instructions: " << HAS_MMX_PLUS << '\n';
	std::cout << "Processor supports SSE instructions: " << HAS_SSE << '\n';
	std::cout << "Processor supports SSE2 instructions: " << HAS_SSE2 << '\n';
	std::cout << "Processor supports SSE FP instructions: " << HAS_SSE_FP << '\n';
	std::cout << "Processor supports SSE MMX instructions: " << HAS_SSE_MMX << '\n';
	std::cout << "Processor supports 3DNow instructions: " << HAS_AMD_3DNOW << '\n';
	std::cout << "Processor supports 3DNow+ instructions: " << HAS_AMD_3DNOW_PLUS << '\n';
	std::cout << "IA64 processor emulating x86 : "<< HAS_IA64 << '\n';
	std::cout << "OS name: " << OS_NAME << '\n';
	std::cout << "OS sub-type: " << OS_RELEASE << '\n';
	std::cout << "OS build ID: " << OS_VERSION << '\n';
	std::cout << "OS platform: " << OS_PLATFORM << '\n';
	return 0;
}