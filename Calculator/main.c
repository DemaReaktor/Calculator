// v0.1.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#define STR_LEN 80
#define BLACK 0
#define RED 4
#define WHITE 15
#define SETCOLOR(COLOR) SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | COLOR));

int get_field(char* name) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!fgets(name, STR_LEN + 1, stdin)) {
		SETCOLOR(RED);
		printf("Error\n");
		SETCOLOR(BLACK);
		return 1;
	}
	fseek(stdin, 0, SEEK_END);
	return 0;
}

void registration() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("<-- Log In or Sign Up -->\n"
		"Mode 0 : Log In\n"
		"Mode 1 : Create New Account\n");
	int mode;
	bool match;
	do {
		fseek(stdin, 0, SEEK_END);
		printf("Select mode: ");;
	} while (!scanf_s("%d", &mode));
	fseek(stdin, 0, SEEK_END);
	if (mode) {
		char first_name[STR_LEN + 1];
		char last_name[STR_LEN + 1];
		char new_password[STR_LEN + 1];
		char confirm_password[STR_LEN + 1];
		do {
			printf("First name: ");
		} while (get_field(first_name));
		do {
			printf("Last name: ");
		} while (get_field(last_name));
		do {
			match = true;
			do {
				printf("Password: ");
			} while (get_field(new_password));
			do {
				printf("Confirm password: ");
			} while (get_field(confirm_password));
			if (strcmp(new_password, confirm_password)) {
				SETCOLOR(RED);
				printf("The values entered for Password and Confirm password\n"
					"do not match. Please enter the same password for both fields.\n");
				SETCOLOR(BLACK);
				match = false;
			}
		} while (!match);
	} else {
		// log in
	}
}

int main() {
	double a, b, result;
	char opt;
	char repeat_prog;
	bool have_error; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// system("chcp 1251 & cls");
	system("color F0");

	printf("<-- Arithmetic Calculator -->\n");

	registration();

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