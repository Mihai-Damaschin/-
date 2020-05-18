#include <stdio.h>
#include <math.h>

void main () {
    int i, j, k, n, m, suma, result = 0, a[100][100];

    printf("n = ");
    scanf("%i", &n);
    printf("m = ");
    scanf("%i", &m);

    printf("Introduceti matricea %i x %i\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%i", &a[i][j]);
        }        
    }

    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            suma = 0;

            for (k = 0; k < n; k++) {
                if (k != i) {
                    suma += a[k][j];
                }
            }

            if (suma < a[i][j]) {
                result++;
            }
        }        
    }

    printf("Sunt %i elemente deosebite\n", result);
}
