#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule Cellule;
struct Cellule{
    int val;
    Cellule *suivant;
};

Cellule *creer_cellule(int val)
{
    Cellule *c = (Cellule *)malloc(sizeof(Cellule));
    c->val = val;
    c->suivant = NULL;

    return c;
}

Cellule *enfiler(Cellule *debut, int val)
{
    Cellule *nouveau = creer_cellule(val);

    if(nouveau == NULL)
        exit(EXIT_FAILURE);

    if(debut != NULL)
    {
        Cellule *elementActuel = debut;

        while(elementActuel->suivant != NULL)
            elementActuel = elementActuel->suivant;
        elementActuel->suivant = nouveau;
    }
    else
        debut = nouveau;

    return debut;
}

Cellule *defiler(Cellule *debut)
{
    if(debut == NULL)
    {
        printf("Queue is empty...");
        exit(EXIT_FAILURE);
    }

    Cellule *elementDefile = debut;
    if(debut != NULL)
    {
        debut = elementDefile->suivant;
        free(elementDefile);
    }
    return debut;
}

void afficherFile(Cellule *debut)
{
    if(debut == NULL)
    {
        printf("Queue is empty...");
        exit(EXIT_FAILURE);
    }

    while(debut != NULL)
    {
        printf(" %d -> ", debut->val);
        debut = debut->suivant;
    }
    printf("NULL\n");
}

int main(){
    Cellule *maFile = NULL;

    maFile = enfiler(maFile, 1);
    maFile = enfiler(maFile, 2);
    maFile = enfiler(maFile, 3);
    maFile = enfiler(maFile, 4);
    maFile = enfiler(maFile, 5);
    maFile = enfiler(maFile, 6);
    maFile = enfiler(maFile, 7);

    printf("Etat de la file:\n");
    afficherFile(maFile);

    printf("Je defile : %d\n", maFile->val);
    maFile = defiler(maFile);
    printf("Je defile : %d\n", maFile->val);
    maFile = defiler(maFile);

    printf("Etat de la file:\n");
    afficherFile(maFile);
}