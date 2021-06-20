#include <stdio.h>

int byte(char a);

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c != '\n') {
			printf("bin: 0b");
			byte(c);
			printf("dec: %d\n", c);
			printf("hex: 0x%X\n", c);
		}
		else
			;
	}

	return 0;
}

int byte(char a) {
	int i;
	for (i = 0; i < 8; i++) {
		printf("%d", !!((a << i) & 0x80));
	}
	printf("\n");

	return 0;
}
