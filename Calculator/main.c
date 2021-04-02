// v0.0.3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	double a, b, result;
	char opt;
	char repeat_prog;
	bool have_error = false; 
	// system("chcp 1251 & cls");

	printf("<-- Arithmetic calculator -->\n");

	do {
		result = 0;
		do {
			fseek(stdin, 0, SEEK_END);
			printf(" First number: ");
		} while (!scanf_s("%lf", &a));

		do {
			fseek(stdin, 0, SEEK_END);
			printf(" Second number: ");
		} while (!scanf_s("%lf", &b));
		fseek(stdin, 0, SEEK_END);

		printf(" Operation: ");
		opt = getchar();
		fseek(stdin, 0, SEEK_END);
		switch (opt) {
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				if (b == 0) {
					printf("Division by zero!\n");
					have_error = true;
				} else {
					result = a / b;
				}
				break;
			default:
				printf("Unknown operation!\n");
				have_error = true;
				break;
		}
		if (!have_error) {
			printf("Result: %g\n", result);
		}

		printf("\n Continue (y/n)? ");
		while ((repeat_prog = getchar()) == ' ' || repeat_prog == '\n' || repeat_prog == '\t');
		putchar('\n');
	} while (repeat_prog == 'Y' || repeat_prog == 'y');

	system("pause");
	return 0;
}