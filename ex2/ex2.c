#include <stdio.h>

void main() {
    char marca[20],
        model[20],
        memorieDeStocare[20],
        culoare[20],
        pret[20];

    printf("Introduceti marca : \n");
    scanf("%s" , marca);
    printf("Introduceti modelul : \n");
    scanf("%s" , model);
    printf("Introduceti memoria de stocare : \n");
    scanf("%s" , memorieDeStocare);
    printf("Introduceti culoarea : \n");
    scanf("%s" , culoare);
    printf("Introduceti pret : \n");
    scanf("%s" , pret);
    printf("%s\t%s\t%s\t%s\t%s\n", marca, model, memorieDeStocare, culoare, pret);
}
