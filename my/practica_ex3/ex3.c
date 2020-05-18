#include <stdio.h>
#include <math.h>

float calculeaza(float x, int n) {
    if (n == 0)
        return x;
    else 
        return ((pow(-1, n) * ((pow(x, 2*n+1))/(2*n+1))) + calculeaza(x, n-1));
}

int main () {
    float x;

    printf("x = ");
    scanf("%f", &x);
    
    printf("S = %f\n", calculeaza(x, 15));

    return 0;
}
