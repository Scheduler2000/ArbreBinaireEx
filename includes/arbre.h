#ifndef __ARBRE__
#define __ARBRE__


typedef struct Noeud
{
	char* contenu;
	struct Noeud* gauche;
	struct Noeud* droit;
	struct Noeud* parent;

}t_noeud;


t_noeud* CreerNoeud(char* contenu);
t_noeud* FusionnerNoeud(t_noeud* gauche, t_noeud* droit, char* contenu);
void ApprendreAnimal(t_noeud* noeudParent);
t_noeud* ChercherElement(t_noeud* noeud);
void ParcourirArbre(t_noeud* noeud);
void AfficherArbre(t_noeud* noeud);
void SupprimerArbre(t_noeud* noeud);

#endif
