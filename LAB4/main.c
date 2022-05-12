#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h> 
#include <stdio.h>
#include "meniu.h"
#include "test.h"

int main()
{
	all_test();
	optiuni();
	_CrtDumpMemoryLeaks();
	return 0;
}