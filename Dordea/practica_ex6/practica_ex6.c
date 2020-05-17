#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char denumirileLunilor[12][10] = {
    "Ianuarie",
    "Februarie",
    "Martie",
    "Aprilie",
    "Mai",
    "Iunie",
    "Iulie",
    "August",
    "Septembrie",
    "Octombrie",
    "Noiembrie",
    "Decembrie"
};

struct luna
{
    int n;
    float temperaturi[100];
    char denumire[20];
} luni[13];

void prelucrareActiuni(char tipulActiunii) {
    int i, k;

    switch (tipulActiunii)
    {
        case 'r': {
            FILE *data;

            data = fopen("data.txt", "r");

            if (data == NULL) {
                printf("\nFisierul nu poate fi deschis\n");
                exit(1);
            }

            for (i = 0; i < 12; i++) {
                fscanf(data, "%s", luni[i].denumire);
                fscanf(data, "%i", &luni[i].n);
                for (k = 0; k < luni[i].n; k++) {
                    fscanf(data, "%f", &luni[i].temperaturi[k]);
                }
            }
            fclose(data);
        }
        break;
        case 'w': {
            FILE *data;
            
            data = fopen("data.txt", "w");

            for (i = 0; i < 12; i++) {
                fprintf(data, "%s\n", luni[i].denumire);
                fprintf(data, "%i\n", luni[i].n);
                for (k = 0; k < luni[i].n; k++) {
                    fprintf(data, "%.1f ", luni[i].temperaturi[k]);
                }
                fprintf(data, "\n");
            }
            fclose(data);
        }
        break;
        case 'c': {
            printf("Introduceti temperaturile pentru fiecare luna :\n\n");
            for (i = 0; i < 12; i++) {
                
                strcpy(luni[i].denumire, denumirileLunilor[i]);
                printf("Luna %s \n", luni[i].denumire);
                printf("Numarul de temperaturi ce urmeaza a fi introduse : ");
                scanf("%i", &luni[i].n);
                printf("Introdu %d valori : ", luni[i].n);
                for (k = 0; k < luni[i].n; k++) {
                    scanf("%f", &luni[i].temperaturi[k]);
                }
            }
        }
        break;
    
    default:
        break;
    }
}

void ordoneazaAlfabetic () {
    int i, j;

    for(i = 0; i < 12; i++)
        for(j = i + 1; j < 12; j++) {
            if(strcmp(luni[i].denumire, luni[j].denumire) > 0) {
            luni[13] = luni[i];
            luni[i] = luni[j];
            luni[j] = luni[13];
            }
        }
}

void afiseazaFolosindFiltre() {
    char c;
    float min, max;
    int i, k, afiseaza;
    FILE *output;

    output = fopen("output.txt", "a");

    printf("\nIntroduceti valoarea temperaturii minimale: ");
    scanf("%f", &min);
    printf("Introduceti valoarea temperaturii maximale: ");
    scanf("%f", &max);

    printf("\nLunile ce au valorile termice cuprinse intre %.1f si %.1f sunt:\n", min, max);
    fprintf(output, "Lunile ce au valorile termice cuprinse intre %.1f si %.1f sunt:\n", min, max);
    for(i = 0; i < 12; i++) {
        afiseaza = 1;
        for(k = 0; k < luni[i].n; k++) {
            if (!(luni[i].temperaturi[k] > min) || !(luni[i].temperaturi[k] < max)) {
                afiseaza = 0;
            }
        }
        if (afiseaza) {
            printf("%s\n", luni[i].denumire);
            fprintf(output, "%s\n", luni[i].denumire);
        }
    }
    fprintf(output, "\n");
    fclose(output);
}

void main() {
    char fromFile, repeat = 'n';

    printf("Doriti sa utilizati datele din fisier? ( y/n ): ");
    scanf("%c", &fromFile);

    if (fromFile == 'y') {
        prelucrareActiuni('r');
        if (strcmp(luni[0].denumire, "Ianuarie") != 0) {
            printf("\nDin pacate fisierul este nu are date\n");
            exit(1);
        }
    } else {
        prelucrareActiuni('c');
        prelucrareActiuni('w');
    }

    ordoneazaAlfabetic();

    do {
        afiseazaFolosindFiltre();
        printf("\nDoriti sa aplicati alte filtre? ( y/n ):");
        scanf(" %c", &repeat);
    } while (repeat == 'y');
}
