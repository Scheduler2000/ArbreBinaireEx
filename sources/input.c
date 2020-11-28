#include "../includes/input.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char DemanderLettre()
{
    char reponse = '\0';

    do
    {
        reponse = toupper(fgetc(stdin));
        if(reponse != 'O' && reponse != 'N')
            printf("Reponse invalide, reponses possibles : Oui(O) || Non(N) \n");
        fflush(stdin);
    }
    while(reponse != 'O' && reponse !='N');

    return reponse;
}

char* DemanderReponse(char* question)
{
    char buffer[40] = "\0";
    char* reponse = NULL;

    printf("%s",question);
    fgets(buffer,39,stdin);
    reponse = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(reponse,buffer);
    fflush(stdin);

    return FormaterString(reponse);
}

char* FormaterString(char* reponse)
{

    int i;

    for(i= 0; i < strlen(reponse); i++)
    {
        if(reponse[i] == '\n')
        {
            reponse[i] = '\0';
            break;
        }
    }
    return reponse;
}
