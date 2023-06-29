using namespace std;
#include <iostream>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task5.h"
#define task 4

int main()
{
#if task == 1
	//adding elements to the end of array
	master();
#elif task == 2 
	//adding elements into array by index
	task2main();
#elif task == 3
	//deleting elements from arr
	task3main();
#endif
	//big task
	bigtask();

}

