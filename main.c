#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *fp = fopen("./arts/menu.txt", "r");
    char linha[100];
    char opcao;

    system("clear");
    while(fgets(linha, 100, fp) != NULL)
        printf("%s", linha);
    printf("\n");

    printf("Teste git 2");

    printf("Barbarinha");
}
