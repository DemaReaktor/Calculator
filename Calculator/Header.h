#pragma warning(disable : 6054)

#include <stdio.h> // printf, scanf_s, fgets, stdin, FILE
#include <stdlib.h> // system
#include <string.h> // strcmp
#include <stdbool.h> // bool
#include <Windows.h> // GetStdHandle, SetConsoleTextAttribute
#include <errno.h> // errno_t


#define STR_LEN 50
#define BLACK 0
#define RED 4
#define WHITE 15
#define SETCOLOR(COLOR) SetConsoleTextAttribute(hConsole, (WORD)((WHITE << 4) | COLOR));


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
			fseek(stdin, 0, SEEK_END);
			printf("User name: ");
		} while (!scanf_s("%s", user_name, STR_LEN + 1));
		do {
			fseek(stdin, 0, SEEK_END);
			printf("First name: ");
		} while (!scanf_s("%s", first_name, STR_LEN + 1));
		do {
			fseek(stdin, 0, SEEK_END);
			printf("Last name: ");
		} while (!scanf_s("%s", last_name, STR_LEN + 1));

		do {
			match = true;

			do {
				fseek(stdin, 0, SEEK_END);
				printf("Password: ");
			} while (!scanf_s("%s", new_password, STR_LEN + 1));
			do {
				fseek(stdin, 0, SEEK_END);
				printf("Confirm password: ");
			} while (!scanf_s("%s", confirm_password, STR_LEN + 1));

			if (strcmp(new_password, confirm_password)) {
				SETCOLOR(RED);
				printf("The values entered for Password and Confirm password\n"
					"do not match. Please enter the same password for both fields.\n");
				SETCOLOR(BLACK);
				match = false;
			}
		} while (!match);

		// 

		FILE* db;
		errno_t err;
		if ((err = fopen_s(&db, "Database.txt", "a")) != 0) {
			printf("File was not opened!\n");
		}
		else {
			fprintf(db, "%s %s %s %s\n", user_name, first_name, last_name, new_password);
			fclose(db);
		}
	}
	else {
		char password[STR_LEN + 1];

		do {
			fseek(stdin, 0, SEEK_END);
			printf("User name: ");
		} while (!scanf_s("%s", user_name, STR_LEN + 1));
		do {
			fseek(stdin, 0, SEEK_END);
			printf("Password: ");
		} while (!scanf_s("%s", password, STR_LEN + 1));
		// searching in db ...
	}
}