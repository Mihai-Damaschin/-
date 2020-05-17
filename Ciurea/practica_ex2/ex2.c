#include <stdio.h>

float atribuie(float first, float second) {
    return (first + second) / 2;
    printf("%f", (first + second) / 2);
}

int main () {
    float x, y, z;

    printf("x = ");
    scanf("%f", &x);
    printf("y = ");
    scanf("%f", &y);
    printf("z = ");
    scanf("%f", &z);

    if (x + y + z < 1) {
        if (x < y && x < z) x = atribuie(y, z); 
            else
            if (y < x && y < z) y = atribuie(x, z); 
                else z = atribuie(x, y);
    } else {
        if (x < y) {
            x = atribuie(y, z);
        } else {
            y = atribuie(x, z);
        }
    }

    printf("x = %.2f\ny = %.2f\nz = %.2f\n", x, y, z);

    return 0;
}