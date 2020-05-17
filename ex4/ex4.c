#include <stdio.h>

void main() {
    int temperatura;

    printf("Introduceti temperatura : \n");
    scanf("%i" , &temperatura);

    printf("%.2f", (temperatura - 32) / 1.8);
}
