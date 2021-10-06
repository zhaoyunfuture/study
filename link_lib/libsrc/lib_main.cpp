#include <string.h>
#include <string>
#include <iostream>

#include <test_lib/lib_header.hpp>

int lib_main(int argc, char* argv[])
{
    std::cout << "lib main world!" << std::endl;
    int _argc = argc;
    char** _argv = argv;
	return app_enter(_argc,_argv);
}




