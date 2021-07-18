#include "version.h"

#include <stdio.h>

int main()
{
	printf("This is output from code %s\n", PROJECT_VERSION);
	printf("Major version number: %i\n", PROJECT_VERSION_MAJOR);
	printf("Minor version number: %i\n", PROJECT_VERSION_MINOR);
	printf("Patch version number: %i\n", PROJECT_VERSION_PATCH);

	printf("Hello CMake World\n");

	return 0;
}