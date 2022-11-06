#include <stdio.h>// bug: < instaed >.
#include <stdlib.h>
#pragma warning(disable : 4996) // bug: there was no pragma.
int main(){	int a = 4, b = 7; //bug: ; instead of ,
	float c;
	scanf("%f", &c); //bug: no & before c in the scanf
	if (c = 5)  //bug: 5=c instead of c=5, Lvalue.
		printf("%f", c); // bug: print insread of printf	return 0;  //bug: no return 0.}