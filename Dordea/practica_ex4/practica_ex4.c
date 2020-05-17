#include <stdio.h>

void main () {
    int n;
    int a[100];

    printf("n = ");
    scanf("%i", &n);

    printf("Introduceti tabloul :\n");
    for (int i = 0; i < n; i++)
        scanf("%i", &a[i]);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            printf("%i ", a[i + j]);
        for (int j = 0; j < i; j++)
            printf("%i ", a[j]);
        printf("\n");
    }
}