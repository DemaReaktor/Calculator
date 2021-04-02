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

	printf("<-- ������������ ����������� -->\n");

	do {
		result = 0;
		do {
			fseek(stdin, 0, SEEK_END);
			printf(" ����� �����: ");
		} while (!scanf_s("%lf", &a));

		do {
			fseek(stdin, 0, SEEK_END);
			printf(" ����� �����: ");
		} while (!scanf_s("%lf", &b));
		fseek(stdin, 0, SEEK_END);

		printf(" ��������: ");
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
					printf("ĳ����� �� ����!\n");
					have_error = true;
				} else {
					result = a / b;
				}
				break;
			default:
				printf("������� ��������!\n");
				have_error = true;
				break;
		}
		if (!have_error) {
			printf("���������: %g\n", result);
		}

		printf("\n ������������ ������ (Y - ���)? ");
		while ((repeat_prog = getchar()) == ' ' || repeat_prog == '\n' || repeat_prog == '\t');
		putchar('\n');
	} while (repeat_prog == 'Y' || repeat_prog == 'y' || repeat_prog == '�' || repeat_prog == '�');

	system("pause");
	return 0;
}