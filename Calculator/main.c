#include "Header.h"

int main() {
	double a, b, result;
	char opt;
	char repeat_prog;
	bool have_error; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// system("chcp 1251 & cls");
	system("color F0");

	printf("<-- Arithmetic Calculator -->\n");

	authorization();

	do {
		result = 0;
		have_error = false;

		do {
			fseek(stdin, 0, SEEK_END);
			printf(" First number: ");
		} while (!scanf_s("%lf", &a));
		fseek(stdin, 0, SEEK_END);

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
					SETCOLOR(RED);
					printf("Division by zero!\n");
					SETCOLOR(BLACK);
					have_error = true;
				} else {
					result = a / b;
				}
				break;
			default:
				SETCOLOR(RED);
				printf("Unknown operation!\n");
				SETCOLOR(BLACK);
				have_error = true;
				break;
		}

		if (!have_error) {
			printf("Result: %g\n", result);
		}

		printf("\n Continue (y/n)? ");
		while ((repeat_prog = getchar()) == ' ' || repeat_prog == '\n' || repeat_prog == '\t');
		fseek(stdin, 0, SEEK_END);
		putchar('\n');
	} while (repeat_prog == 'Y' || repeat_prog == 'y');

	system("pause");
	return 0;
}