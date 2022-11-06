#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996) // bug: no pragma.

int main()
{
	int x, y;
	int nums[6];
	int* arrPtr;

	// Section A - Print the variables
	printf("***** Section A *****");  //bug: puts instead of printf
	printf(" Base = %d\n", x);
	printf(" Height = %d\n", y);
	printf(" Area = %d\n", (x * y) / 2); //bug: triangle area is height*base/2 and not base*height
	// Section B - Print the static array "nums".
	printf("***** Section B *****");  //bug: puts instead of printf
	int i = 0;
	while (i < 6) {
		printf(" nums[%d] = %d\n", i, nums[i]);
		i++; //bug: no i++, index is staying the same.
	}

	// Section C - Print allocated array.
	printf("***** Section C *****");   //bug: puts instead of printf
	arrPtr = (int*)malloc(sizeof(int) * 6); //bug: no malloc casting, array size should be 6 and not 10.
	int* root = arrPtr; //bug: root was not defined.
	if (arrPtr) {
		for (i = 0; i < 6; i++) {
			printf(" array[%d] = %d\n", i, *arrPtr); //bug: arrPtr is not a regular array, to print we need to use *arrPtr.
			arrPtr++; //bug: no proceeding, if we want to print all of the array we need to write arrPtr++.
		}
		free(root); //bug: the allocation is not being freed;
	}
	else {
		printf("Error Allocating Memory!\n");
		exit(1);
	}
	return 0;
}