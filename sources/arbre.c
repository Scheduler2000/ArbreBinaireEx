#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../includes/arbre.h"
#include "../includes/input.h"

t_noeud* CreerNoeud(char* question)
{
    t_noeud* racine = NULL;

    racine = malloc(sizeof(t_noeud));
    if(racine == NULL)
    {
        printf("Probleme allocation dynamique racine !");
        exit(EXIT_FAILURE);
    }
    racine->contenu = malloc(strlen(question)* sizeof(char));

    strcpy(racine->contenu,question);
    racine->gauche = NULL;
    racine->droit = NULL;
    racine->parent = NULL;

    return racine;
}

t_noeud* FusionnerNoeud(t_noeud* gauche, t_noeud* droit,char* contenu)
{
    t_noeud* noeud = NULL;
    noeud = CreerNoeud(contenu);

    if(gauche != NULL)
        gauche->parent = noeud;
    if(droit != NULL)
        droit->parent = noeud;

    noeud->gauche = gauche;
    noeud->droit = droit;

    return noeud;
}

t_noeud* ChercheElement(t_noeud* noeud)
{
    char reponse = '\0';

    do
    {
        printf("Question : %s ",noeud->contenu);
        reponse = DemanderLettre();
        if(reponse == 'O')
            noeud = noeud->gauche;
        else
            noeud = noeud->droit;
    }
    while(noeud->gauche != NULL || noeud->droit != NULL);

    return noeud;
}

void ParcourirArbre(t_noeud* noeud)
{
    if(noeud == NULL)
        return;

    char reponse;
    int stop = 0;
    t_noeud* racine = noeud;
    while(!stop)
    {
        t_noeud* feuille = ChercheElement(racine);

        printf("C'est donc l'animal suivant : %s, Etes vous d'accord ?",feuille->contenu);
        reponse = DemanderLettre();

        if(reponse == 'N')
            ApprendreAnimal(feuille);

        printf("Encore ? ");
        reponse = DemanderLettre();
        if(reponse != 'O')
            stop = 1;
    }
    AfficherArbre(racine);
}

void ApprendreAnimal(t_noeud* noeudParent)
{
    char* question;
    char* animal;
    char* contenuAncien= noeudParent->contenu;

    animal = DemanderReponse("A quel animal pensiez-vous ? ");
    question = DemanderReponse("Entrez une question permettant de caracteriser cet animal et pour laquelle la reponse est OUI : ");

    noeudParent->contenu = question;
    noeudParent->gauche = CreerNoeud(animal);
    noeudParent->droit = CreerNoeud(contenuAncien);
}

void AfficherArbre(t_noeud* noeud)
{
    if(noeud == NULL)
        return;

    if(noeud->parent != NULL)
        printf("(%s) -> (%s)\n",noeud->parent->contenu,noeud->contenu);
    else
        printf("(%s)\n",noeud->contenu);

    if(noeud->droit != NULL)
        AfficherArbre(noeud->droit);
    if(noeud->gauche != NULL)
        AfficherArbre(noeud->gauche);
}

void SupprimerArbre(t_noeud* noeud)
{
    t_noeud* ptr1;
    t_noeud* ptr2;

    if(noeud == NULL)
        return;

    ptr1 = noeud->gauche;
    ptr2 = noeud->droit;
    free(noeud);

    SupprimerArbre(ptr1);
    SupprimerArbre(ptr2);
}
