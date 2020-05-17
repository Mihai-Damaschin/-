#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct autobus {
    int numar;
    char tipul[50];
    char statiaTerminus[50];
    char timpulPornirii[50];
    char timpulSosorii[50];
} autobuse[100];

void main () {
    FILE *fgrafic;
    int n;
    int j = 0;
    char destinatie[50];
    char timpul_max[50];

    fgrafic = fopen("grafic.txt", "r");
    if (fgrafic == NULL) {
        printf("Fisierul nu poate fi deschis");
        exit(1);
    }

    while (!feof(fgrafic)) {
        fscanf(fgrafic, "%i", &autobuse[j].numar);
        fscanf(fgrafic, "%s", autobuse[j].tipul);
        fscanf(fgrafic, "%s", autobuse[j].statiaTerminus);
        fscanf(fgrafic, "%s", autobuse[j].timpulPornirii);
        fscanf(fgrafic, "%s", autobuse[j].timpulSosorii);
        j++;
    }
    n = j;

    printf("Posibilele destinatii sunt :\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", autobuse[i].statiaTerminus);
    }
    printf("\n");

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

};
