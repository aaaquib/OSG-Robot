#include "TestEnvironment.h"



int main(int argc, char* argv[])
{

	TestEnvironment* environment = new TestEnvironment();
	environment->init(argc, argv);
	environment->run();

	return 0;
}