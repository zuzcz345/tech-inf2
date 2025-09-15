#include <stdio.h>
#include <string.h>

void showMenu(void) {
	printf("1. Wyswietl zadania \n");
	printf("2. Dodaj nowe zadanie \n");
	printf("3. Oznacz zadanie [1-20] jako wykonane (zadania wykonane oznaczone sa sercem) \n");
}

int countLines(void) {
	FILE *fptr;
	fptr = fopen("../tasks.txt", "r");
	if(fptr == NULL) return 1;

	int lineCount = 0;
	char line[256];

	while (fgets(line, sizeof(line), fptr)) {
		lineCount++;
	}

	fclose(fptr);

	return lineCount;
}

int showTasks(int *maxLineCount) {
	FILE *fptr;
	fptr = fopen("../tasks.txt", "r");
	if(fptr == NULL) return 1;

	int task = 0;
	char line[256];

	if (countLines() < *maxLineCount + 1) {
		while (fgets(line, sizeof(line), fptr)) {
			task++;
			printf("%d. %s", task, line);
		}
		printf("\n");
	} else {
		printf("Twoja lista jest zbyt dluga, aby ja wyswietlic \n");
	}

	fclose(fptr);

	return 0;
}

int newTask(int *maxLineCount) {
	FILE *fptr;
	fptr = fopen("../tasks.txt", "a");
	if(fptr == NULL) return 1;

	char task[50];

	if (countLines() < *maxLineCount) {
		printf("Wpisz zadanie: \n");
		getchar();
		fgets(task, 50, stdin);
		fprintf(fptr, "%s", task);
	} else {
		printf("Twoja lista jest za dluga nie mozna dodac wiecej zadan \n");
	}

	fclose(fptr);

	return 0;
};

int markComplete(void) {
    char *tasks[20];
    int task = 0;

    FILE *fptr;
    fptr = fopen("../tasks.txt", "r");
    if(fptr == NULL) return 1;

    char line[256];
	int taskToMark = 0;
	printf("Podaj numer wykonanego zadania: \n");
	scanf("%d", &taskToMark);

    while (fgets(line, sizeof(line), fptr)) {
    	if (task == taskToMark - 1) {
    		//The line below inserts character according to its "alt code", but I'm not sure why it does that.
    		line[strcspn(line, "\n")] = 3;

    		tasks[task] = strdup(strcat(line, "\n"));
    		tasks[task] = strdup(line);
    	} else {
    		tasks[task] = strdup(line);
    	}
    	task++;
    }
    fclose(fptr);

	fptr = fopen("../tasks.txt", "w");
	if(fptr == NULL) return 1;

	for (int i = 0; i < task; i++) {
		fprintf(fptr, "%s", tasks[i]);
	}
	fclose(fptr);

    return 0;
}

int main(void) {
	int maxLineCount = 20;
	if (countLines() > maxLineCount) {
		printf("Twoja lista jest za dluga \n");
	}

	do {
		showMenu();
		int menuOption;
		scanf("%d", &menuOption);
		switch (menuOption) {
			case 1:
				showTasks(&maxLineCount);
				break;
			case 2:
				newTask(&maxLineCount);
				break;
			case 3:
				markComplete();
				break;
			case 0:
				return 0;
			default:
				printf("Podano nieprawidlowa opcje z menu \n");
				break;
		}
	} while (1);
}