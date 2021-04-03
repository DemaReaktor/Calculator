/* C file for functions bodies */

#include "Header.h"

long hash(char* str) {
	long hash = 5381;
	int c;

	while (c = *str++) {
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return hash;
}

void authorization() {
	printf("<-- Log In or Sign Up -->\n"
		"Mode 0 : Log In\n"
		"Mode 1 : Create New Account\n");

	int mode;
	do {
		fseek(stdin, 0, SEEK_END);
		printf("Select mode: ");;
	} while (!scanf_s("%d", &mode));
	fseek(stdin, 0, SEEK_END);

	if (mode) {
		sign_up();
	}
	else {
		log_in();
	}
}

void sign_up() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool match; // new_password and confirm_password are identical
	char user_name[STR_LEN + 1];
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

	long hash_password = hash(new_password);

	FILE* db;
	errno_t err;
	if ((err = fopen_s(&db, "Database.txt", "a")) != 0) {
		printf("File was not opened!\n");
	}
	else {
		fprintf(db, "%s %s %s %ld\n", user_name, first_name, last_name, hash_password);
		fclose(db);
	}

}

void log_in() {
	char user_name[STR_LEN + 1];
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