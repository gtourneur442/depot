#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "pacman2.h"

#define LARGEUR 25
#define HAUTEUR 25
#define MAX 20
#define MIN 1

int main()
{
    char board[LARGEUR][HAUTEUR];
    char perso[] = "('<";
    char choix_deplac;
    int x = 1;
    int y = 0;
    int i,j;
    int cpt = 0;
    int continuer = 1;

    Fantome ghosts[3];
    ghosts[0].fantome[0] = '/';
    ghosts[0].fantome[1] = '!';
    ghosts[0].fantome[2] = '\\';
    ghosts[1].fantome[0] = '-';
    ghosts[1].fantome[1] = 'w';
    ghosts[1].fantome[2] = '-';
    ghosts[2].fantome[0] = '~';
    ghosts[2].fantome[1] = 'X';
    ghosts[2].fantome[2] = '~';

    srand(time(NULL));
    ghosts[0].x = (rand() % (MAX - MIN + 1) + MIN);
    ghosts[0].y = (rand() % (MAX - MIN + 1) + MIN);
    ghosts[1].x = (rand() % (MAX - MIN + 1) + MIN);
    ghosts[1].y = (rand() % (MAX - MIN + 1) + MIN);
    ghosts[2].x = (rand() % (MAX - MIN + 1) + MIN);
    ghosts[2].y = (rand() % (MAX - MIN + 1) + MIN);

    for(i = 0;i < HAUTEUR;i++)
    {
        for(j = 0;j < LARGEUR;j++)
        {
            board[i][j] = '.';
        }
    }

        printf("--------------------------------------------------------------------------\n\r");
        board[y][x] = perso;
        switch (choix_deplac)
        {

        /* deplacement vers le bas */
            case 's' :
                board[y][x] = ' ';
                y++;
                if(board[y][x] == '.')
                    cpt++;
                if(board[y][x] == '#')
                    y--;
                //printf("%d",cpt);
                if(((x==ghosts[0].x)&&(y==ghosts[0].y)) || ((x==ghosts[1].x)&&(y==ghosts[1].y)) || ((x==ghosts[2].x)&&(y==ghosts[2].y)))
                {
                    printf("GAME OVER\n");
                    continuer = 0;
                }
            break;

            case 'q' :
                continuer = 0;
            break;

            default : printf("\n" );
            break;
        }
        terrain(board);
        affichage(x,y,board,ghosts,perso);
        //deplacementFantomes(ghosts,board);

        printf("--------------------------------------------------------------------------\n\r");
    printf("\n\n Déplacements de Pacman : taper une touche, puis 'Entrée' \n -> s : vers le Bas,\n -> q : pour stopper le jeu.\n" );

    while(continuer)
    {
        scanf("%c", &choix_deplac);
        if(choix_deplac == '\n')
            continue;
        printf("--------------------------------------------------------------------------\n\r");
        board[y][x] = perso;

        switch (choix_deplac)
        {

        /* deplacement vers le bas */
            case 's' :
                board[y][x] = ' ';
                y++;
                if(board[y][x] == '.')
                    cpt++;
                if(board[y][x] == '#')
                    y--;
                //printf("%d",cpt);
                if(((x==ghosts[0].x)&&(y==ghosts[0].y)) || ((x==ghosts[1].x)&&(y==ghosts[1].y)) || ((x==ghosts[2].x)&&(y==ghosts[2].y)))
                {
                    printf("GAME OVER\n");
                    continuer = 0;
                }
            break;


        /* deplacment vers le haut */
            case 'z' :
                board[y][x] = ' ';
                y--;
                if(board[y][x] == '.')
                    cpt++;
                if(board[y][x] == '#')
                    y++;
                //printf("%d",cpt);
                if(((x==ghosts[0].x)&&(y==ghosts[0].y)) || ((x==ghosts[1].x)&&(y==ghosts[1].y)) || ((x==ghosts[2].x)&&(y==ghosts[2].y)))
                {
                    printf("GAME OVER\n");
                    continuer = 0;
                }
            break;

        /* deplacmeent vers la gauche */
            case 'a' :
                board[y][x] = ' ';
                x--;
                if(board[y][x] == '.')
                    cpt++;
                if(board[y][x] == '#')
                    x++;
                //printf("%d",cpt);
                if(((x==ghosts[0].x)&&(y==ghosts[0].y)) || ((x==ghosts[1].x)&&(y==ghosts[1].y)) || ((x==ghosts[2].x)&&(y==ghosts[2].y)))
                {
                    printf("GAME OVER\n");
                    continuer = 0;
                }
            break;

        /* deplacement vers la droite */
            case 'd' :
                board[y][x] = ' ';
                x++;
                if(board[y][x] == '.')
                    cpt++;
                if(board[y][x] == '#')
                    x--;
                //printf("%d",cpt);
                if(((x==ghosts[0].x)&&(y==ghosts[0].y)) || ((x==ghosts[1].x)&&(y==ghosts[1].y)) || ((x==ghosts[2].x)&&(y==ghosts[2].y)))
                {
                    printf("GAME OVER\n");
                    continuer = 0;
                }
            break;

            case 'q' :
                continuer = 0;
            break;

            default : printf("erreur\n" );
            break;
        }
        terrain(board);
        affichage(x,y,board,ghosts,perso);
        //deplacementFantomes(ghosts,board);
        int dist = distance(x,y,ghosts);
        phantomPursuit(dist,x,y,ghosts);

        printf("--------------------------------------------------------------------------\n\r");
        printf("\n\n Déplacements de Pacman : taper une touche, puis 'Entrée' \n -> z : vers le Haut,\n -> s : vers le Bas,\n -> d : vers la Droite,\n -> a : vers la Gauche,\n -> q : pour stopper le jeu.\n" );

        if(cpt == 529)
        {
            printf("BRAVO ! PACMAN est repu !\n");
            continuer = 0;
        }
    }
    return 0;
}

void terrain(char board[LARGEUR][HAUTEUR])
{
    int i, j;

      /* bord du haut */
    for (j = 0;j < HAUTEUR;j++){
        board[0][j] = '#';
    }

    /* bord du bas */
    for (j = 0;j < HAUTEUR;j++){
        board[LARGEUR-1][j] = '#';
    }

    /* bord gauche */
    for (i = 1;i < LARGEUR-1;i++){
        board[i][0] = '#';
        }

    /* bord de droite */
    for (i = 1;i < LARGEUR-1;i++){
        board[i][HAUTEUR-1] = '#';
    }
}

void affichage(int x, int y, char board[LARGEUR][HAUTEUR],Fantome ghosts[],char perso[])
{
    for(int i = 0;i < HAUTEUR; i++)
    {
        for(int j = 0; j < LARGEUR; j++)
        {
            if((x == j) && (y == i))
            {
                printf("%s",perso);
            }
            /*else if((i == 5) && (j == 5))
            {
                printf("%s",fantome);
            }*/
            else if((i == ghosts[0].y) && (j == ghosts[0].x))
            {
                printf("%c",ghosts[0].fantome[0]);
                printf("%c",ghosts[0].fantome[1]);
                printf("%c",ghosts[0].fantome[2]);
            }
            else if((i == ghosts[1].y) && (j == ghosts[1].x))
            {
                printf("%c",ghosts[1].fantome[0]);
                printf("%c",ghosts[1].fantome[1]);
                printf("%c",ghosts[1].fantome[2]);
            }
            else if((i == ghosts[2].y) && (j == ghosts[2].x))
            {
                printf("%c",ghosts[2].fantome[0]);
                printf("%c",ghosts[2].fantome[1]);
                printf("%c",ghosts[2].fantome[2]);
            }
            else
            {
                printf(" %c ",board[i][j]);
            }
        }
        printf("\n\r");
    }
}

/*void deplacementFantomes(Fantome ghosts[], char board[LARGEUR][HAUTEUR])
{
    int lancementDe = rand() % 4;
    if(lancementDe == 1)
    {
        ghosts[0].x++;
        ghosts[1].x--;
        ghosts[2].y++;
        if(board[ghosts[0].y][ghosts[0].x] == '#')
            ghosts[0].x--;
        if(board[ghosts[1].y][ghosts[1].x] == '#')
            ghosts[1].x++;
        if(board[ghosts[2].y][ghosts[2].x] == '#')
            ghosts[2].y--;
    }
    else if(lancementDe == 2)
    {
        ghosts[0].y++;
        ghosts[1].y--;
        ghosts[2].x--;
        if(board[ghosts[0].y][ghosts[0].x] == '#')
            ghosts[0].y--;
        if(board[ghosts[1].y][ghosts[1].x] == '#')
            ghosts[1].y++;
        if(board[ghosts[2].y][ghosts[2].x] == '#')
            ghosts[2].x++;
    }
    else if(lancementDe == 3)
    {
        ghosts[0].y--;
        ghosts[1].x++;
        ghosts[2].y--;
        if(board[ghosts[0].y][ghosts[0].x] == '#')
            ghosts[0].y++;
        if(board[ghosts[1].y][ghosts[1].x] == '#')
            ghosts[1].x--;
        if(board[ghosts[2].y][ghosts[2].x] == '#')
            ghosts[2].y++;
    }
    else
    {
        ghosts[0].x--;
        ghosts[1].y++;
        ghosts[2].x++;
        if(board[ghosts[0].y][ghosts[0].x] == '#')
            ghosts[0].x++;
        if(board[ghosts[1].y][ghosts[1].x] == '#')
            ghosts[1].y--;
        if(board[ghosts[2].y][ghosts[2].x] == '#')
            ghosts[2].x--;
    }
}*/

int distance(int x, int y, Fantome ghosts[])
{
    int dAbs = ghosts[0].x - x;
    int dOrd = ghosts[0].y - y;
    int puissX = pow(dAbs,2);
    int puissY = pow(dOrd,2);
    int addPuiss = puissX + puissY;
    int d = sqrt(addPuiss);
    return d;
}

void phantomPursuit(int dist,int x, int y,Fantome ghosts[])
{
    if(dist <= 3)
    {
        if(ghosts[0].y++ < dist)
            ghosts[0].y++;
        if(ghosts[0].y-- < dist)
            ghosts[0].y--;
        if(ghosts[0].x++ < dist)
            ghosts[0].x++;
        if(ghosts[0].x-- < dist)
            ghosts[0].x--;
    }
}
