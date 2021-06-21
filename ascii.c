#include <stdio.h>

int byte(char a);					/* Prototype for custom function for returning a string of bits */

int main() {						/* This program does not take direct command-line arguments */
	int c;
	while ((c = getchar()) != EOF) {		/* Stop the program when the EOF character is encountered (typically by sending Ctrl+d while waiting for data) */
		if (c != '\n') {			/* Ignore newline characters */
			printf("bin: 0b");		/* Print formatting for output purposes; the real work is done by byte() in the next line */
			byte(c);			/* Send the current character in the string to the byte() function. It's method of operation is outlined below */
			printf("dec: %d\n", c);		/* Convert and display the current character as its decimal representation */
			printf("hex: 0x%X\n", c);	/* Convert and display the current character as its hexidecimal representation */
		}
		else					/* Since we're only checking for the new line character in the if else statement, we can drop from else as we're not looking for anything. Requires a trailing semicolon to close. */
			;
	}

	return 0;
}

int byte(char a) {					/* Begin by reading in the current character passed from the byte() call inside main() */
	int i;						/* Declare a counter variable */
	for (i = 0; i < 8; i++) {			/* Initiate a counter and interate through the loop eight times */
		printf("%d", !!((a << i) & 0x80));	/* Still trying to fully understand this mechanism, but I'll try to outline as best I can from left to right: */
	}						/* Print out the single bit value of the left-most bit in the character by taking the character, 
	printf("\n");					/* shifting the bits to the left one bit, then ANDing it against 0b10000000 to get the current Significant Bit */
							/* then taking the inverse twice - first to negate the answer to a single bit, second to negate the single bit */
	return 0;					/* value to it's original form. We then print these single bits individually for the character, then new line. */
}
