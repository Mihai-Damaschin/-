#include <stdio.h>

int main () {
    int n, m, i, j, a[100][100];

    printf("n = ");
    scanf("%i", &n);
    printf("m = ");
    scanf("%i", &m);

    printf("Introduceti matricea:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", a[i][j]);

    return 0;
}