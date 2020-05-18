#include <stdio.h>
#include <math.h>

int factorial(int n)  {
    if (n == 0)  
        return 1;  
    else  
        return (n * factorial(n-1));
}

float calculeaza(float x, int n) {
    if (n == 0)
        return x;
    else 
        return ((pow(-1, n) * ((pow(x, 2*n+1))/(2*n+1))) + calculeaza(x, n-1));
}

int main () {
    float x;

    printf("Introduceti numarul: ");
    scanf("%f", &x);
    
    printf("S = %f\n", calculeaza(x, 15));

    return 0;
}