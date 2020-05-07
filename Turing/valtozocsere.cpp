#include <stdio.h>
#include <algorithm>

int main(){

	int a = 10;
	int b = 20;
	printf("Eredeti: a=%d, b=%d.\n", a, b);

	int temp = 0;
	temp = a;
	a = b;
	b = temp;
	printf("Segédes változás: a=%d, b=%d.\n", a, b);

	b = b - a;
	a = a + b;
	b = a - b;
	printf("Matoperátoros változás: a=%d, b=%d.\n", a, b);

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("XOR operátoros változás: a=%d, b=%d.\n", a, b);

	std::swap(a, b);
	printf("Swap változás: a=%d, b=%d.\n", a, b);

	return 0;
}