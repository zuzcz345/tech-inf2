#include <stdio.h>
#include <stdlib.h>

void showMenu(void) {
    printf("1. Pokaz tablice \n");
    printf("2. Minimum \n");
    printf("3. Suma \n");
    printf("4. Srednia \n");
    printf("5. Zapisz tablice do pliku \n");
    printf("6. Wczytaj tablice z pliku \n");
    printf("0. Zamknij program \n");
    printf("Wybierz opcje: ");
}

void printArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("array[%d] = %d \n", i, array[i]);
    }
}

//void printArray(int *array, int arraySize) {
//    for (int i = 0; i < arraySize; ++i) {
//        printf("array[%d] = %d \n", i, array[i]);
//        printf("*(%p) = %d\n\n", array + i, *(array + i));
//    }
//}


int minArrayValue(int array[], int arraySize) {
    int minArrayValue = array[0];
    for (int i = 0; i < arraySize - 1; i++) {
        if (minArrayValue > array[i + 1]) {
            minArrayValue = array[i + 1];
        }
    }
    return minArrayValue;
}

//int minArrayValue(int *array, int arraySize) {
//    int minArrayValue = *array;
//    for (int i = 0; i < arraySize - 1; i++) {
//        if (minArrayValue > *(array + i + 1)) {
//            minArrayValue = *(array + i + 1);
//        }
//    }
//    return minArrayValue;
//}


int sum(int array[], int arraySize) {
    int sum = 0;
    for (int i = 0; i < arraySize; ++i) {
        sum = sum + array[i];
    }
    return sum;
}

//int sum(int *array, int arraySize) {
//    int sum = 0;
//    for (int i = 0; i < arraySize; ++i) {
//        sum = sum + *(array + i);
//    }
//    return sum;
//}

float average(int array[], int arraySize) {
    float avg = (float) sum(array, arraySize) / arraySize;
    return avg;
}

int arrToTxt(int array[], int arraySize) {
    FILE *fptr;
    fptr = fopen("../plik.txt", "w");
    if(fptr == NULL) return 1;
    for (int i = 0; i < arraySize; ++i) {
        fprintf(fptr, "%d\n", array[i]);
    }
    fclose(fptr);
    return 0;
};

int arrFromTxt(int array[], int arraySize) {
    FILE *fptr;
    fptr = fopen("../plik.txt", "r");
    if(fptr == NULL) return 1;
    char buff[255];
    while (fgets(buff, sizeof(buff), fptr)) {
        for (int i = 0; i < arraySize; ++i) {
            array[i] = buff[i];
        }
    };
    fclose(fptr);
    return 0;
};

int main(void) {
    int array[] = {4, 2};
    int arraySize = sizeof array / sizeof array[0];
//    qsort(array, arraySize, sizeof array[0]);
    do {
        showMenu();
        int menuOption;
        scanf("%d", &menuOption);
        switch (menuOption) {
            case 1:
                printArray(array, arraySize);
                break;
            case 2:
                printf("Minimalna wartosc z tablicy: %d \n", minArrayValue(array, arraySize));
                break;
            case 3:
                printf("Suma: %d \n", sum(array, arraySize));
                break;
            case 4:
                printf("Srednia: %f \n", average(array, arraySize));
                break;
            case 5:
                arrToTxt(array, arraySize);
                break;
            case 6:
                arrFromTxt(array, arraySize);
                break;
            case 0:
                return 0;
            default:
                printf("Podano nieprawidlowa opcje z menu \n");
                break;
        }
    } while (1);
    return 0;
}


//SUMA
//int sum = 0;
//for (int i = 0; i < arrayLength; ++i) {
//sum = sum + array[i];
//}
//float average = (float) sum / arrayLength;
