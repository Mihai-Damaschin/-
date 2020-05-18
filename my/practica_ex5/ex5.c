#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int myStrlen(char *p) {
    int i = 0;
    char *start = p;

    while(*p!='\0')
    {
        i++;
        p++;
    }

    return p - start;
}

void citeste() {
    int i, flag;
    char word[200];

    fgets(word, sizeof word, stdin);

    for (i = 0; i < myStrlen(word); i++) {
        if (word[i] == '+' || word[i] == '-') {
            if (isdigit(word[i+1])) {
                printf("  %c", word[i]);
                flag = 1;
            } else {
                printf("%c", word[i]);
            }
        } else {
            if (isdigit(word[i]) && !isdigit(word[i+1]) && flag == 1) {
                printf("%c  ", word[i]);
                flag = 0;
            } else {
                printf("%c", word[i]);
            }
        }
    }
}

void main () {

  citeste();
}