// v0.1.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

#define BLACK 0
#define RED 4
#define WHITE 15
#define SETCOLOR(COLOR) SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | COLOR));

int main() {
	double a, b, result;
	char opt;
	char repeat_prog;
	bool have_error = false; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// system("chcp 1251 & cls");
	system("color F0");
	system("mode 80, 20");

	printf("<-- Arithmetic calculator -->\n");

	do {
		result = 0;
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