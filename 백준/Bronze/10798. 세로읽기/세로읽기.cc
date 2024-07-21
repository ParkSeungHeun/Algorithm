#include <stdio.h>

char arr[5][15];

int main() {

	for (int i = 0; i < 5; i++)
		scanf("%s", arr[i]);

	for (int i = 0; i < 15; i++) {
		for (int k = 0; k < 5; k++) {
			if (arr[k][i] != NULL)
				printf("%c", arr[k][i]);
		}
	}

	return 0;
}