#include <stdio.h> // printf, scanf_s, fgets, stdin
#include <stdlib.h> // system
#include <string.h> // strcmp
#include <stdbool.h> // bool
#include <Windows.h> // GetStdHandle, SetConsoleTextAttribute


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
	bool match; // new_password and confirm_password are identical

	do {
		fseek(stdin, 0, SEEK_END);
		printf("Select mode: ");;
	} while (!scanf_s("%d", &mode));
	fseek(stdin, 0, SEEK_END);

	char user_name[STR_LEN + 1];

	if (mode) {
		char first_name[STR_LEN + 1];
		char last_name[STR_LEN + 1];
		char new_password[STR_LEN + 1];
		char confirm_password[STR_LEN + 1];

		do {
			printf("User name: ");
		} while (get_field(first_name));
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
	}
	else {
		char password[STR_LEN + 1];

		do {
			printf("User name: ");
		} while (get_field(user_name));
		do {
			printf("Password: ");
		} while (get_field(password));
		// searching in db ...
	}
}