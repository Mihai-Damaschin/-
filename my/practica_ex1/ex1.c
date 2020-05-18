#include <stdio.h>
#include <math.h>

int main () {
    int n, suma = 0, k;

    printf("Introduceti numarul: ");
    scanf("%i", &n);
    k = n * n;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }

    k == pow(suma, 3) ? printf("1\n") : printf("0\n");

    return 0;
}
