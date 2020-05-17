#include <stdio.h>
#include <ctype.h>

struct  produs {
    char nume[50];
    float pret;
    int cantitate;
    float cost;
} produse[100];

void citesteProduse (int n) {
    for (int i = 0; i < n; i++) {
        printf("Numele : ");
        scanf("%s", produse[i].nume);
        printf("Pret : ");
        scanf("%f", &produse[i].pret);
        printf("Cantitate : ");
        scanf("%i", &produse[i].cantitate);
        produse[i].cost = produse[i].pret * produse[i].cantitate;
    }
}

int main () {
    int n;
    float pretMax;
    float costTotal = 0;
    char *denumire;

    scanf("%d", &n);

    citesteProduse(n);

    pretMax = produse[0].pret;
    denumire = produse[0].nume;
    for (int i = 0; i < n; i++) {
        if (pretMax < produse[i].pret) {
            pretMax = produse[i].pret;
            denumire = produse[i].nume;
        }
        costTotal += produse[i].cost;
    }

    printf("\nCostul total este : %.2f\n", costTotal);
    printf("Cel mai scump produs este : %s\n", denumire);


    return 0;
};
