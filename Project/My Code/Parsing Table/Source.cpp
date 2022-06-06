#include<stdio.h>
#include<string.h>

void Fill() {

}

void main() {
	char ParsingTable[5][10];

	for (int i = 0; i < 5; i++) {
		//for (int j = 0; j < 10; j++) {
			scanf_s("%s", &ParsingTable[i]);
		//}
	}


	for (int i = 0; i < 5; i++) {
		//for (int j = 0; j < 10; j++) {
			printf("%s\t", ParsingTable[i]);
		//}
		printf("\n");
	}
}