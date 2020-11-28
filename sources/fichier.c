#include "../includes/fichier.h"
#include "../includes/arbre.h"
#include <stdio.h>
#include <stdlib.h>


void SauvegarderArbrePrefix(t_noeud* noeud, FILE* fichier)
{
    if(fichier != NULL)
    {

        if(noeud->parent != NULL)
            fprintf(fichier,"%s -> %s\n",noeud->parent->contenu,noeud->contenu);
        else
           fprintf(fichier,"%s\n",noeud->contenu);

        if(noeud->gauche != NULL)
            SauvegarderArbrePrefix(noeud->gauche,fichier);
        if(noeud->droit != NULL)
            SauvegarderArbrePrefix(noeud->droit,fichier);
    }
    else
        printf("Fichier introuvable, sauvegarde non effectuee !");
}
