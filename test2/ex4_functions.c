#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

struct autobus {
    int numar;
    char tipul[50];
    char statiaTerminus[50];
    char timpulPornirii[50];
    char timpulSosorii[50];
} autobuse[100];

void citesteGrafic () {
    FILE *fgrafic;
    int i = 0;

    fgrafic = fopen("grafic.txt", "r");

    if (fgrafic == NULL) {
        printf("Fisierul nu poate fi deschis");
        exit(1);
    }

    while (!feof(fgrafic)) {
        fscanf(fgrafic, "%i", &autobuse[i].numar);
        fscanf(fgrafic, "%s", autobuse[i].tipul);
        fscanf(fgrafic, "%s", autobuse[i].statiaTerminus);
        fscanf(fgrafic, "%s", autobuse[i].timpulPornirii);
        fscanf(fgrafic, "%s", autobuse[i].timpulSosorii);
        i++;
    }
    n = i;
}

void afiseazaPosibilitatile() {
    printf("Posibilele destinatii sunt :\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", autobuse[i].statiaTerminus);
    }
    printf("\n");
}

void proceseazaDatele() {
    char destinatie[50];
    char timpul_max[50];

    printf("Introduceti destinatia: ");
    scanf("%s", destinatie);

    printf("Introduceti ora maxima in formatul ora:minute : ");
    scanf("%s", timpul_max);

    printf("Va puteti folosi de rutele :\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(destinatie, autobuse[i].statiaTerminus) == 0 &&
            strcmp(timpul_max, autobuse[i].timpulSosorii) > 0) {
            printf("%i\n", autobuse[i].numar);
        }
    }
}

void main () {
    citesteGrafic();
    afiseazaPosibilitatile();
    proceseazaDatele();
};
