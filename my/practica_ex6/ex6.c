#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
struct autobus {
    int numar;
    char tipul[50];
    char statiaTerminus[50];
    char timpulPornirii[50];
    char timpulSosirii[50];
} autobuse[100];

void citesteDinConsola() {
    int i;

    printf("Numarul inregistrarilor ce vor fi introduse: ");
    scanf("%d", &n);

    printf("\nIntroduceti datele pentru fiecare ruta :\n");
        for (i = 0; i < n; i++) {
            
            printf("Numarul rutei: ");
            scanf("%i", &autobuse[i].numar);
            printf("Tipul autobusului: ");
            scanf("%s", autobuse[i].tipul);
            printf("Statia terminus: ");
            scanf("%s", autobuse[i].statiaTerminus);
            printf("Timpul pornirii: ");
            scanf("%s", autobuse[i].timpulPornirii);
            printf("Timpul sosirii: ");
            scanf("%s", autobuse[i].timpulSosirii);
            printf("\n");
        }
}

void salveazaInFisier() {
    int i;
    FILE *fgrafic;

    fgrafic = fopen("data.txt", "w");

    if (fgrafic == NULL) {
        printf("\nFisierul nu poate fi deschis\n");
        exit(1);
    }

    fprintf(fgrafic, "%i\n", n);
    for (i = 0; i < n; i++) {
        fprintf(fgrafic,
            "%i %s %s %s %s\n",
            autobuse[i].numar, 
            autobuse[i].tipul,
            autobuse[i].statiaTerminus,
            autobuse[i].timpulPornirii,
            autobuse[i].timpulSosirii
        );
    }
    fclose(fgrafic);
}

void citesteDinFisier() {
    int i;
    FILE *fgrafic;

    fgrafic = fopen("data.txt", "r");

    if (fgrafic == NULL) {
        printf("\nFisierul nu poate fi deschis\n");
        exit(1);
    }

    fscanf(fgrafic, "%i", &n);
    for (i = 0; i < n; i++) {
        fscanf(fgrafic,
            "%i %s %s %s %s",
            &autobuse[i].numar, 
            autobuse[i].tipul,
            autobuse[i].statiaTerminus,
            autobuse[i].timpulPornirii,
            autobuse[i].timpulSosirii
        );
    }
    fclose(fgrafic);
}

void calculeaza() {
    char destinatie[50];
    char timpul_max[50];
    char matchArray[200];
    FILE *output;

    output = fopen("output.txt", "a");

    printf("Posibilele destinatii sunt :\n");
    for (int i = 0; i < n; i++) {
        if (strstr(matchArray, autobuse[i].statiaTerminus) == NULL) {
            printf("%s\n", autobuse[i].statiaTerminus);
            strcat(matchArray, autobuse[i].statiaTerminus);
        }
    }
    printf("\n");

    printf("Introduceti destinatia: ");
    scanf("%s", destinatie);

    printf("Introduceti ora maxima in formatul ora:minute : ");
    scanf("%s", timpul_max);

    printf("Va puteti folosi de rutele :\n");
    fprintf(output, "Va puteti folosi de rutele :\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(destinatie, autobuse[i].statiaTerminus) == 0 &&
            strcmp(timpul_max, autobuse[i].timpulSosirii) > 0) {
            printf("%i\n", autobuse[i].numar);
            fprintf(output, "%i\n", autobuse[i].numar);
        }
    }

    fprintf(output, "\n");
    fclose(output);
}

void main () {
    char fromFile, repeat = 'n';

    printf("Doriti sa utilizati datele din fisier? ( y/n ): ");
    scanf("%c", &fromFile);

    if (fromFile == 'y') {
        citesteDinFisier();
        if (!autobuse[0].numar) {
            printf("\nDin pacate fisierul este nu are date\n");
            exit(1);
        }
    } else {
        citesteDinConsola();
        salveazaInFisier();
    }

    calculeaza();
};
