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

bool authorization() {
	printf("*** Log In or Sign Up ***\n"
		"Mode 0 : Log In\n"
		"Mode 1 : Create New Account\n");

	int mode;
	do {
		fseek(stdin, 0, SEEK_END);
		printf(" Select mode: ");;
	} while (!scanf_s("%d", &mode));
	fseek(stdin, 0, SEEK_END);
	putchar('\n');

	if (mode) {
		sign_up();
	}
	else {
		if (!log_in()) {
			return false;
		}
	}
	return true;
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
				"do not match. Please enter the same password for both fields.\n\n");
			SETCOLOR(BLACK);
			match = false;
		}
	} while (!match);

	long hash_password = hash(new_password);

	FILE* db;
	errno_t err;
	if ((err = fopen_s(&db, "Database.txt", "a")) != 0) {
		printf("File was not opened!\n");
		exit(EXIT_FAILURE);
	}
	else {
		fprintf(db, "%20s %20s %20s %20ld\n", user_name, first_name, last_name, hash_password);
		if (fclose(db) != 0) {
			fprintf(stderr, "Error closing file\n");
			exit(EXIT_FAILURE);
		}
		SETCOLOR(GREEN);
		printf("\n*** Welcome! ***\n");
		SETCOLOR(BLACK);
	}
}

bool log_in() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char user_name[STR_LEN + 1];
	char password[STR_LEN + 1];
	bool repeat = true;
	int attempts = 3;

	do {
		do {
			fseek(stdin, 0, SEEK_END);
			printf("User name: ");
		} while (!scanf_s("%s", user_name, STR_LEN + 1));
		do {
			fseek(stdin, 0, SEEK_END);
			printf("Password: ");
		} while (!scanf_s("%s", password, STR_LEN + 1));


		if (search(user_name)) {
			long hash_password = hash(password);
			char db_password[STR_LEN + 1] = { '\0' };

			FILE* db;
			errno_t err;
			if ((err = fopen_s(&db, "Database.txt", "rb")) != 0) {
				printf("File was not opened!\n");
				exit(EXIT_FAILURE);
			}
			else {
				char uname[STR_LEN + 1];
				char c;
				int j;
				fseek(db, 20, SEEK_SET);
				do {
					fseek(db, 65, SEEK_CUR);
					j = 0;
					for (int i = 0; i < 20; i++) {
						if ((c = fgetc(db)) != ' ') {
							uname[j++] = c;
						}
					}
					uname[j] = '\0';
				} while (strcmp(user_name, uname));
				fseek(db, 43, SEEK_CUR);
				j = 0;
				for (int i = 0; i < 20; i++) {
					if ((c = fgetc(db)) != ' ') {
						db_password[j++] = c;
					}
				}
				db_password[j] = '\0';
				if (fclose(db) != 0) {
					fprintf(stderr, "Error closing file\n");
					exit(EXIT_FAILURE);
				}
			}
			if (hash_password == atol(db_password)) {
				repeat = false;
				SETCOLOR(GREEN);
				printf("*** Welcome! ***\n");
				SETCOLOR(BLACK);
			}
			else {
				repeat = true;
				attempts--;
				SETCOLOR(RED);
				printf("*** Incorrect password! ***\n");
				SETCOLOR(BLACK);
			}
		}
		else {
			SETCOLOR(RED);
			repeat = true;
			attempts--;
			printf("*** Not Found! Try again. Attempts left: %d ***\n", attempts);
			SETCOLOR(BLACK);
		}
	} while (repeat && attempts != 0);
	if (attempts == 0) {
		SETCOLOR(RED);
		printf("*** You tried to log in too often. ***\n");
		SETCOLOR(BLACK);
		exit(0);
	}
	return true;
}

bool search(char* user_name) {
	bool found = false;
	FILE* db;
	errno_t err;
	if ((err = fopen_s(&db, "Database.txt", "rb")) != 0) {
		printf("File was not opened!\n");
	}
	else {
		char uname[STR_LEN + 1];
		char c;
		int j;
		do {
			j = 0;
			for (int i = 0; i < 20; i++) {
				if ((c = fgetc(db)) != ' ') {
					uname[j++] = c;
				}
			}
			uname[j] = '\0';
			fseek(db, 64, SEEK_CUR);
			if (!strcmp(user_name, uname)) {
				found = true;
			}
		} while (fgetc(db) != EOF);
		if (fclose(db) != 0) {
			fprintf(stderr, "Error closing file\n");
		}
	}
	return found;
}