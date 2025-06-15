#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int randomValue = rand() % 20 + 1;

    printf("Zgadnij liczbe z zakresu 1-20 \n");
    int  userInput = 0;
    int counter = 0;

    while (randomValue != userInput) {
        scanf("%d", &userInput);
        if (randomValue > userInput) {
            printf("Liczba do zgadniecia jest wieksza\n");
        }
        if (randomValue < userInput){
            printf("Liczba do zgadniecia jest mniejsza\n");
        }
        counter++;
    }
    printf("Zgadles za %d razem", counter);
    return 0;
}
