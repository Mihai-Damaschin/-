#include <stdio.h>
#include <math.h>

void main () {
    int n, k;
    char denumirileAnimalelor[12][10] = {
        "Sobolan",
        "Taur",
        "Tigru",
        "Iepure",
        "Dragon",
        "Sarpe",
        "Cal",
        "Oaie",
        "Maimuta",
        "Cocos",
        "Ciine",
        "Purcel"
    };

    printf("Introduceti anul: ");
    scanf("%i", &n);

    k = (n > 1984 ? n - 1984 : 1984 - n) % 60 ;

    printf("%i - %s", n, denumirileAnimalelor[k % 12]);

    switch (k % 5) {
        case 0:
            printf(" verde\n");
            break;
        case 1:
            printf(" rosu\n");
            break;
        case 2:
            printf(" yellow\n");
            break;
        case 3:
            printf(" white\n");
            break;
        case 4:
            printf(" negru\n");
            break;    
        default:
            break;
    }
}
