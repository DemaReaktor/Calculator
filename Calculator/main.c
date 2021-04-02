// v0.0.2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	double a, b, result;
	char opt;
	char repeat_prog;
	bool have_error = false; 
	system("chcp 1251 & cls");

	printf("<-- Арифметичний калькулятор -->\n");

	do {
		result = 0;
		do {
			fseek(stdin, 0, SEEK_END);
			printf(" Перше число: ");
		} while (!scanf_s("%lf", &a));

		do {
			fseek(stdin, 0, SEEK_END);
			printf(" Друге число: ");
		} while (!scanf_s("%lf", &b));
		fseek(stdin, 0, SEEK_END);

		printf(" Операція: ");
		opt = getchar();
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
					printf("Ділення на нуль!\n");
					have_error = true;
				} else {
					result = a / b;
				}
				break;
			default:
				printf("Невідома операція!\n");
				have_error = true;
				break;
		}
		if (!have_error) {
			printf("Результат: %g\n", result);
		}

		printf("\n Продовжувати роботу (Y - так)? ");
		while ((repeat_prog = getchar()) == ' ' || repeat_prog == '\n' || repeat_prog == '\t');
		putchar('\n');
	} while (repeat_prog == 'Y' || repeat_prog == 'y' || repeat_prog == 'Т' || repeat_prog == 'т');

	system("pause");
	return 0;
}