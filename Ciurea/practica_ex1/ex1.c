#include <stdio.h>

int main () {
    int n, suma = 0;

    printf("Introduceti numarul: ");
    scanf("%i", &n);
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }

    printf("Suma cifrelor este: %d\n", suma);

    return 0;
}