#pragma once 
#include <iostream>

#define M_ASSERT(cond, message) {\
	if (!cond) {\
		std::cout << "assertion failed: " <<message << std::endl;\
		assert(false);\
	}\
}


