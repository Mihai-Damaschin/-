#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

struct convorbire
{
    char dataConvorbirii[20];
    char codOras[20];
    char numeOras[20];
    int timp;
    float tarif;
    char prefixOras[20];
    char nrTelefon[20];
} convorbiri[100];

void citesteDinConsola() {
    int i;

    printf("Numarul inregistrarilor ce vor fi introduse: ");
    scanf("%d", &n);

    printf("\nIntroduceti datele pentru fiecare convorbire :\n");
        for (i = 0; i < n; i++) {
            
            printf("Data convorbirii: ");
            scanf("%s", convorbiri[i].dataConvorbirii);
            printf("Codul orasului: ");
            scanf("%s", convorbiri[i].codOras);
            printf("Numele orasului: ");
            scanf("%s", convorbiri[i].numeOras);
            printf("Timpul convorbirii: ");
            scanf("%i", &convorbiri[i].timp);
            printf("Tariful: ");
            scanf("%f", &convorbiri[i].tarif);
            printf("Prefixul orasului: ");
            scanf("%s", convorbiri[i].prefixOras);
            printf("Numarul abonatului: ");
            scanf("%s", convorbiri[i].nrTelefon);
            printf("\n");
        }
}

void salveazaInFisier() {
    int i;
    FILE *data;

    data = fopen("data.txt", "w");

    fprintf(data, "%i\n", n);
    for (i = 0; i < n; i++) {
        fprintf(data, 
            "%s %s %s %i %f %s %s",
            convorbiri[i].dataConvorbirii, 
            convorbiri[i].codOras,
            convorbiri[i].numeOras,
            convorbiri[i].timp,
            convorbiri[i].tarif,
            convorbiri[i].prefixOras,
            convorbiri[i].nrTelefon
        );
        
        fprintf(data, "\n");
    }
    fclose(data);
}

void citesteDinFisier() {
    int i;
    FILE *data;

    data = fopen("data.txt", "r");

    if (data == NULL) {
        printf("\nFisierul nu poate fi deschis\n");
        exit(1);
    }

    fscanf(data, "%i", &n);
    for (i = 0; i < n; i++) {
        fscanf(data,
            "%s %s %s %i %f %s %s",
            convorbiri[i].dataConvorbirii, 
            convorbiri[i].codOras,
            convorbiri[i].numeOras,
            &convorbiri[i].timp,
            &convorbiri[i].tarif,
            convorbiri[i].prefixOras,
            convorbiri[i].nrTelefon
        );
    }
    fclose(data);
}

void calculeaza() {
    int i, j, total;
    float suma;
    FILE *output;
    char matchArray[200];

    output = fopen("output.txt", "a");

    for (i = 0; i < n; i++) {
        total = 0;
        suma = 0;
        
        if (strstr(matchArray, convorbiri[i].numeOras) == NULL) {
            for (j = 0; j < n; j++) {
                if (strcmp(convorbiri[i].numeOras, convorbiri[j].numeOras) == 0) {

                    total += convorbiri[j].timp;
                    suma += convorbiri[j].timp * convorbiri[j].tarif;
                }
            }
            strcat(matchArray, convorbiri[i].numeOras);
            printf("%s Timp: %i  Cost: %.2f\n", convorbiri[i].numeOras, total, suma);
            fprintf(output, "%s Timp: %i  Cost: %.2f\n", convorbiri[i].numeOras, total, suma);
        }
    }
    fprintf(output, "\n");
    fclose(output);
}

int main() {
    char fromFile, repeat = 'n';

    printf("Doriti sa utilizati datele din fisier? ( y/n ): ");
    scanf("%c", &fromFile);

    if (fromFile == 'y') {
        citesteDinFisier();
        if (!convorbiri[0].dataConvorbirii) {
            printf("\nDin pacate fisierul este nu are date\n");
            exit(1);
        }
    } else {
        citesteDinConsola();
        salveazaInFisier();
    }

    calculeaza();

    return 0;
}
