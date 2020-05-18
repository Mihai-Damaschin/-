#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
struct carte
{
    int id;
    char autor[20];
    char titlu[20];
    int anulEditiei;
    char editura[20];
    int nrDePagini;
} carti[13];

void citesteDinConsola() {
    int i;

    printf("Numarul de elemente ce vor fi introduse: ");
    scanf("%i", &n);

    printf("Introduceti datele pentru fiecare carte :\n\n");
    for (i = 0; i < n; i++) {
        
        printf("Numar de inregistrare:");
        scanf("%i", &carti[i].id);
        printf("Autor: ");
        scanf("%s", carti[i].autor);
        printf("Titlu: ");
        scanf("%s", carti[i].titlu);
        printf("Anul editiei: ");
        scanf("%i", &carti[i].anulEditiei);
        printf("Editura: ");
        scanf("%s", carti[i].editura);
        printf("Numarul de pagini: ");
        scanf("%i", &carti[i].nrDePagini);
        printf("\n");
    }
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
            "%i %s %s %i %s %i",
            &carti[i].id, 
            carti[i].autor,
            carti[i].titlu,
            &carti[i].anulEditiei,
            carti[i].editura,
            &carti[i].nrDePagini
        );
    }
    fclose(fgrafic);
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
            "%i %s %s %i %s %i\n",
            carti[i].id, 
            carti[i].autor,
            carti[i].titlu,
            carti[i].anulEditiei,
            carti[i].editura,
            carti[i].nrDePagini
        );
    }
    fclose(fgrafic);
}

void afiseazaFolosindFiltre() {
    int i, anul;
    FILE *output;

    output = fopen("output.txt", "a");

    printf("\nIntroduceti anul: ");
    scanf("%i", &anul);

    printf("\nCaritle ce au fost tiparite dupa anul %i sunt:\n", anul);
    fprintf(output, "\nCaritle ce au fost tiparite dupa anul %i sunt:\n", anul);
    for(i = 0; i < n; i++) {
        if (carti[i].anulEditiei > anul) {
            printf("%s\n", carti[i].titlu);
            fprintf(output, "%s\n", carti[i].titlu);
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
        if (!carti[0].id) {
            printf("\nDin pacate fisierul este nu are date\n");
            exit(1);
        }
    } else {
        citesteDinConsola();
        salveazaInFisier();
    }

    afiseazaFolosindFiltre();

    return 0;
}
