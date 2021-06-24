#include <stdio.h>

void printCharBits(char a) {
	printf("bin: 0b");
	for (int i = 0; i < 8; i++) {
		printf("%d", !!((a << i) & 0x80));	/* shift bits of char over by i bits, AND against 0b10000000, then double-negate to cast to bool */
	}
	printf("\n");
}

void main() {
	int c;
	while ((c = getchar()) != EOF) {		/* ctrl+d will send EOF character */
		if (c != '\n') {
			printCharBits(c);
			printf("dec: %d\n", c);
			printf("hex: 0x%X\n", c);
		}
	}
}
