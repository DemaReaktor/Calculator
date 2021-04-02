//Functions v0.0.1(main v0.0.3)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool charP(char* s1, char* s2) {
	while (*s1 != '\0')
		if (*s1 == *s2) {
			s1 = s1 + 1;
			s2 = s2 + 1;
		}
		else return false;
	return *s2 == '\0' ? true : false;
}

int main() {
	double a, b, result;
	char opt;
	char repeat_prog;
	bool have_error = false;
	char* s;
	// system("chcp 1251 & cls");

	printf("<--Not only arithmetic, but calculator -->\n");

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
		case '^':
			result = pow(a, b);
			break;
		case '%':
			result = (int)a % (int)b;
			break;
		case 'm':
			s = malloc(sizeof(char));
			int i = 0;
			while ((s[i] = getchar()) != '\n')i++;
			s[i] = '\0';
			if (charP("idlle arefmetice", s)) result = (a + b) * 0.5;
			else
				if (charP("idlle geometrice", s)) result = sqrt(a * b);
				else {
					have_error = true;
					printf("Unknown operation!\n");
				}
			break;
		case '/':
			if (b == 0) {
				printf("Division by zero!\n");
				have_error = true;
			}
			else {
				result = a / b;
			}
			break;
		default:
			have_error = true;
			printf("Unknown operation!\n");
			break;
		}
		if (!have_error) printf("Result: %g\n", result);

		printf("\n Continue (y/n)? ");
		while ((repeat_prog = getchar()) == ' ' || repeat_prog == '\n' || repeat_prog == '\t');
		putchar('\n');
	} while (repeat_prog == 'Y' || repeat_prog == 'y');

	system("pause");
	return 0;
}