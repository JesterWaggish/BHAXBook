#include <stdio.h>

int main(){
	int db = 1;
	int szo = 1;

	while (szo <<= 1){
		db++;
		//printf("%d\n", szo);
	}

	printf("Szóhossz: %d bit\n", db);

	return 0;
}