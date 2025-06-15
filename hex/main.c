#include <stdio.h>

int main(void) {
    int input = 0;
    printf("Podaj wartosc w zapisie dziesietnym \n");
    scanf("%d", &input);
    printf("Twoja wartosc w zapisie heksadecymalnym %x", input);
    return 0;
}

