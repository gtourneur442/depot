#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#define LARGEUR 25
#define HAUTEUR 25

typedef struct{
    char fantome[4];
    unsigned int x;
    unsigned int y;
} Fantome;

void terrain(char board[LARGEUR][HAUTEUR]);
void affichage(int x, int y, char board[LARGEUR][HAUTEUR],Fantome ghosts[],char perso[]);
//void deplacementFantomes(Fantome ghosts[],char board[LARGEUR][HAUTEUR]);
int distance(int x, int y, Fantome ghosts[]);
void phantomPursuit(int dist,int x, int y,Fantome ghosts[]);

#endif // PACMAN_H_INCLUDED
