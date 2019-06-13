#include<stdio.h>
#include <cstdlib>
int main(){
	unsigned int a = ( rand() % 256 ) * 256 * 256 * 256;
	printf("Number : %u\n",a);
	return 0;
}