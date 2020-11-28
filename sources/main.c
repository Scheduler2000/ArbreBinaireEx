#include <stdio.h>
#include <stdlib.h>
#include "../includes/arbre.h"
#include "../includes/fichier.h"

int main(int argc, char const *argv[])
{
    FILE* db = fopen("Arbre.txt","w+");

    t_noeud* arbre;
    t_noeud* noeud1 = FusionnerNoeud(CreerNoeud("Chien"),CreerNoeud("Cheval"),"Aboie-t-il ?");
    t_noeud* noeud2 = FusionnerNoeud(CreerNoeud("Canari"),CreerNoeud("Vipere"),"Vole-t-il ?");
    arbre = FusionnerNoeud(noeud1,noeud2,"Est-ce un mammifere ?");

    printf("Affichage de l'arbre :\n");
    printf("-----------------------------\n");
    AfficherArbre(arbre);
    printf("-----------------------------\n");


    ParcourirArbre(arbre);
    system("cls");
    printf("Affichage de l'arbre :\n");
    printf("-----------------------------\n");
    AfficherArbre(arbre);
    printf("-----------------------------\n");

    SauvegarderArbrePrefix(arbre,db);
    printf("Arbre correctement sauvegarde !");
    SupprimerArbre(arbre);

    fclose(db);
    return 0;
}
