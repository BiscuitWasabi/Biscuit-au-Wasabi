#include <stdio.h>
#include <stdlib.h>

                                    /**CONSTANTE**/
#define TAILLE 24
#define TROUE -5
#define VIDE 0
#define POINT 1
#define POINT2 2
#define POINT3 3
#define MOINS -1

/**OBJETS FIXE**/
#define SAUT 4
#define BOMBE  5
#define BOUCLIER 6

/**OBJETS  FIXE ET ALEATOIRE**/        // pourcentage actuel de l'apparition des objets avec l'aléatoire
#define AIMANT 7                       // 11%
#define BOOST 8                        // 11%

/**OBJETS ALEATOIRE**/
#define REDUCT 9                       // 8%
#define MALEDICTION 10                 // 4%
#define MALUS 11                       // 14%
#define STOP 12                         // 6%
#define TELEPORT 13                    // 15%
#define BONUS 14                       // 14%
#define DOUBLEPOINT 15                 // 11%

/**ALEATOIRE**/
#define ALEATOIRE 16                   // OBJET QUI GENERE LES OBJETS ALEATOIRES

/**STATUT SPECIAL**/
#define PARALYSER 20                  // DONNE LE STATUT PARALYSé AU JOUEUR

/**JOUEUR**/
#define NBPLAYERS 2
#define PLAYER1 30                  // joueur 1
#define PLAYER2 31

/**NOMBRE DE TOURS**/
#define TURNS 3

                                    // voir le plateau avec nombre allez ligne 955 environ retirer commentaire de la boucle for

                                     /**FONCTION**/


/**CARTES (déconseiller de lire)**/
void map_1(int** map){
    int i,j;
            for (i=0;i<TAILLE; i++)
        {
            for (j=0;j<TAILLE;j++)
            {
                map[i][j]=VIDE;
            }
        }
       for (i=0;i<TAILLE;i++)
       {
           if((i==1) || (i==22))
           {
               for(j=1; j<TAILLE-1 ; j++)
               {
                   map[i][j]=TROUE;
                   map[j][i]=TROUE;
               }
           }
           if((i==3)|| (i==20))
           {
               for(j=3; j<TAILLE-3 ; j++)
               {
                   map[i][j]=TROUE;
                   map[j][i]=TROUE;
               }
           }
           if ((i>=10) && (i<=13))
           {
                  for(j=10; j<TAILLE-10 ; j++)
               {
                   map[i][j]=TROUE;
                   map[j][i]=TROUE;
               }
           }
       }
       map[5][5]=TROUE;
       map[5][6]=TROUE;
       map[5][7]=TROUE;
       map[6][5]=TROUE;
       map[7][5]=TROUE;

       map[18][5]=TROUE;
       map[18][6]=TROUE;
       map[18][7]=TROUE;
       map[17][5]=TROUE;
       map[16][5]=TROUE;

       map[5][18]=TROUE;
       map[6][18]=TROUE;
       map[7][18]=TROUE;
       map[5][17]=TROUE;
       map[5][16]=TROUE;

       map[18][18]=TROUE;
       map[17][18]=TROUE;
       map[16][18]=TROUE;
       map[18][17]=TROUE;
       map[18][16]=TROUE;

       map[3][11]=VIDE;
       map[20][11]=VIDE;

       map[11][1]=VIDE;
       map[11][22]=VIDE;

       map[4][12]=TROUE;
       map[5][12]=TROUE;
       map[5][11]=TROUE;
       map[5][10]=TROUE;

       map[19][10]=TROUE;
       map[18][10]=TROUE;
       map[18][11]=TROUE;
       map[18][12]=TROUE;

}
void map_2 (int** map ){
    int i,j ;
       for(i=0; i<TAILLE; i++){
            for(j=0; j<TAILLE; j++){
                map[i][j]=0;
            }
        }
        for (i=2;i<9;i++){//de la ligne 2 à 9 avec Case-initial=0
            for (j=TAILLE-2;j>TAILLE-9;j--){//parcours le tableau en haut à droite et descend jusqu'à [8][TAILLE-9]
                if (j==TAILLE-i)//tracer la bisectrice de l'angle haut-droite
                   {map[i][j]=TROUE;
                   }
                else if ((i>=8)&&(i<=15)){
                    map[i][j]=0;
                }
                else if (((i>=16)&&(i<=23))&&((j>=8)&&(j<=15))){
                    map[i][j]=0;
                }
                else {
                    map[i][j]=0;
                }

            }
        }
        map[18][4]=TROUE;//diagonale haut-gauche à bas-droite |bas de la bouche
        map[19][5]=TROUE;
        map[20][6]=TROUE;
        map[21][7]=TROUE;

        map[14][4]=TROUE;//diagonale bas-gauche à haut-droit |coté gauche de la bouche
        map[13][5]=TROUE;
        map[12][6]=TROUE;

        map[19][13]=TROUE;//diagonale bas-gauche à haut-droit| coté droit de la bouche
        map[20][12]=TROUE;
        map[21][11]=TROUE;

        map[13][7]=TROUE;//haut de la bouche
        map[14][8]=TROUE;
        map[15][9]=TROUE;
        map[16][10]=TROUE;
        map[17][11]=TROUE;
        map[18][12]=TROUE;

      for (i=3;i<10;i++)// oeil gauche:
      {
          map[i][9]= TROUE;// trait vertical
          map[9][i]=TROUE;//ici "i" gère les colones | oeil gauche : trait horizontal
      }
      for (i=TAILLE-3;i>TAILLE-9;i--)//oeil droit
      {
          map[i][16]=TROUE;//vertical
          map[16][i]=TROUE;// horizontal
      }

}
void map_3(int** map){
    int i;
    int j;
   for(i=0; i<TAILLE; i++){
            for(j=0; j<TAILLE; j++){
                map[i][j]=0;
            }
        }
    for (i=0; i<TAILLE; i++){
        if (i==4){
            for (j=4; j<=10; j++){
                map[i][j]=TROUE;
        }
            for (j=15; j<=21; j++)
                {
                map[i][j]=TROUE;
            }
        }
        map[5][4]=TROUE;
        map[6][4]=TROUE;
        map[5][10]=TROUE;
        map[6][10]=TROUE;
        map[6][15]=TROUE;
        map[5][15]=TROUE;
        map[5][21]=TROUE;
        map[6][21]=TROUE; //les murs en forment de C à gauche

        if (i==21){
            for (j=4; j<=10; j++){
                map[i][j]=TROUE;
        }
            for (j=15; j<=21; j++){
                map[i][j]=TROUE;
            }
        }
        map[19][4]=TROUE;
        map[20][4]=TROUE;
        map[19][10]=TROUE;
        map[20][10]=TROUE;
        map[19][15]=TROUE;
        map[20][15]=TROUE;
        map[19][21]=TROUE;
        map[20][21]=TROUE;//les murs en forme de C à droite

        if (i==10){
            for (j=1; j<=7; j++){
                map[i][j]=TROUE;
            }
            for (j=17; j<=22; j++){
                map[i][j]=TROUE;
            }
        }
        map[9][7]=TROUE;
        map[8][7]=TROUE;
        map[7][7]=TROUE;
        map[9][17]=TROUE;
        map[8][17]=TROUE;
        map[7][17]=TROUE;//les murs en L de gauche

        if (i==15){
            for (j=1; j<=7; j++){
                map[i][j]=TROUE;
            }
            for (j=17; j<=22; j++){
                map[i][j]=TROUE;
            }
        }
    }
        map[16][7]=TROUE;
        map[17][7]=TROUE;
        map[18][7]=TROUE;
        map[16][17]=TROUE;
        map[17][17]=TROUE;
        map[18][17]=TROUE;//les murs en L de droite
        }
void map_4 (int** map){
    int i,j;
  for (i=0;i<24;i++)
        {
            for (j=0;j<24;j++)
            {
                if ((j==11)||(j==12))
                {
                    map[i][j]=0;
                }
                else if (((j==10)||(j==13))&&(i!=0)&&(i!=23))
                {
                    map[i][j]=0;
                }
                else if (((j==9)||(j==14))&&(i!=0)&&(i!=23)&&(i!=1)&&(i!=22))
                {
                    map[i][j]=0;
                }
                else if (((j==8)||(j==15))&&(i!=0)&&(i!=23)&&(i!=1)&&(i!=22)&&(i!=2)&&(i!=21))
                {
                    map[i][j]=0;
                }
                else if (((j==7)||(j==16))&&(i!=0)&&(i!=23)&&(i!=1)&&(i!=22)&&(i!=2)&&(i!=21)&&(i!=3)&&(i!=20))
                {
                    map[i][j]=0;
                }
                else if (((j==6)||(j==17))&&(i!=0)&&(i!=23)&&(i!=1)&&(i!=22)&&(i!=2)&&(i!=21)&&(i!=3)&&(i!=20)&&(i!=4)&&(i!=19))
                {
                    map[i][j]=0;
                }
                else if (((j==5)||(j==18))&&(i!=0)&&(i!=23)&&(i!=1)&&(i!=22)&&(i!=2)&&(i!=21)&&(i!=3)&&(i!=20)&&(i!=4)&&(i!=19)&&(i!=5)&&(i!=18))
                {
                    map[i][j]=0;
                }
                else if (((j==4)||(j==19))&&(i!=0)&&(i!=23)&&(i!=1)&&(i!=22)&&(i!=2)&&(i!=21)&&(i!=3)&&(i!=20)&&(i!=4)&&(i!=19)&&(i!=5)&&(i!=18)&&(i!=6)&&(i!=17))
                {
                    map[i][j]=0;
                }
                else if (((j==3)||(j==20))&&(i!=0)&&(i!=23)&&(i!=1)&&(i!=22)&&(i!=2)&&(i!=21)&&(i!=3)&&(i!=20)&&(i!=4)&&(i!=19)&&(i!=5)&&(i!=18)&&(i!=6)&&(i!=17)&&(i!=7)&&(i!=16))
                {
                    map[i][j]=0;
                }
                else if (((j==2)||(j==21))&&(i!=0)&&(i!=23)&&(i!=1)&&(i!=22)&&(i!=2)&&(i!=21)&&(i!=3)&&(i!=20)&&(i!=4)&&(i!=19)&&(i!=5)&&(i!=18)&&(i!=6)&&(i!=17)&&(i!=7)&&(i!=16)&&(i!=8)&&(i!=15))
                {
                    map[i][j]=0;
                }
                else if (((j==1)||(j==22))&&(i!=0)&&(i!=23)&&(i!=1)&&(i!=22)&&(i!=2)&&(i!=21)&&(i!=3)&&(i!=20)&&(i!=4)&&(i!=19)&&(i!=5)&&(i!=18)&&(i!=6)&&(i!=17)&&(i!=7)&&(i!=16)&&(i!=8)&&(i!=15)&&(i!=9)&&(i!=14))
                {
                    map[i][j]=0;
                }
                else if (((j==0)||(j==23))&&(i!=0)&&(i!=23)&&(i!=1)&&(i!=22)&&(i!=2)&&(i!=21)&&(i!=3)&&(i!=20)&&(i!=4)&&(i!=19)&&(i!=5)&&(i!=18)&&(i!=6)&&(i!=17)&&(i!=7)&&(i!=16)&&(i!=8)&&(i!=15)&&(i!=9)&&(i!=14)&&(i!=10)&&(i!=13))
                {
                    map[i][j]=0;
                }
                else map[i][j]=TROUE;
            }
        }
        for (i=8;i<11;i++)
        {
            map[i][7]=TROUE;
            map[i][16]=TROUE;
        }
        for (i=12;i<15;i++)
        {
            map[i][7]=TROUE;
            map[i][16]=TROUE;
        }
        map[6][11]=TROUE;
        map[6][12]=TROUE;
        map[16][11]=TROUE;
        map[16][12]=TROUE;
}

/**APPARITON DES JOUEURS**/
void apprition_joueur(int** map, int carte  )                 //Positionner les joueurs selon la carte selectionnée
{
    switch(carte)
    {
    case 1:
        map[1][23]=PLAYER1;
        map[23][0]=PLAYER2;
        break;
    case 2:
        map[6][6]=PLAYER1;
        map[19][19]= PLAYER2;
        break;
    case 3:
        map[11][11]=PLAYER1;
        map[14][14]= PLAYER2;
        break;
    case 4:
        map[2][14]= PLAYER1;
        map [22][11]= PLAYER2;
        break;

    }
}


/**REMPLISSAGE DU TABLEAU**/

void remplir_map(int** map)
{
    int i,j;
    srand(time(NULL));                          //  reinitisation de l'aléatoire
    for (i=0; i<=23; i++)
    {
        for (j=0; j<=23; j++)
        {
            if (map[i][j]==0)
            {
                map[i][j]=(rand()%100);         //on genere un nombre entre 1 et 99 pour les cases vide
                if (map[i][j]<=59)
                    {
                    map[i][j]=1;                //61% de chance +1 point
                }

                else if((map[i][j]>=60)&&(map[i][j]<=79))
                    {
                        map[i][j]=-1;           //20% de chance -1 point
                    }
                else if((map[i][j]>=80)&&(map[i][j]<=94))
                    {
                            map[i][j]=2;        //15% de chance 2 points
                    }
                else{
                    map[i][j]=3;                //4% de chance 3 points
                }
            }
        }
    }

}

void remplir_tab (int ** map , int carte)                     // Faire appelle à la carte selectionnée
{
    /**DEFINITION CARTE**/
    switch (carte)
    {

    case 1:
        map_1(map);                                         // carte 1
        break;
    case 2:
        map_2(map);                                         // carte 2
        break;
    case 3:
        map_3(map);                                          // carte 3
        break;
    case 4:
        map_4(map);                                         // carte 4
        break;
    default:
        break;
    }

    apprition_joueur(map, carte);                           // apparition des joueur selon la carte
    /**REMPLISSAGE CARTE (objet à venir)**/
    remplir_map(map);                                       // remplissage de la carte sans objet


}



/**INITIALISATION DU JEU**/
void initialisation_copie_carte (int ** map , int ** copie)   // Initialisation du plateau et copie du plateau
{
    int i, j ;
    int carte;
    srand(time(NULL));
    carte=(rand()%4);                                         // selection d'une de nos 4 cartes si =0 alors on met 4
    if (carte==0){
        carte=4;
        }

    remplir_tab(map, carte);                                   // fonction qui remplies la carte selon la carte choisie

    for (i=0; i<TAILLE ; i++)
    {
        for (j=0 ; j<TAILLE; j ++)                             // copie de la carte
            {
                copie[i][j] = map[i][j];

            }
    }
}
void initialisation_copie_tab(int* tab, int* copie )      // Initialisation et copie des tableaux 1D
{
    int i;
    for (i=0; i< NBPLAYERS; i++)                           // tableau et la copie pour chaque joueur est mit a 0
    {
       tab[i]=0;
       copie[i]=0;
    }

}

/** L'INITIALISATION & COPIE DU JEU**/
void initialisation_jeux (int** map, int** copie_map, int* objet, int* copie_objet, int* score, int* copie_score, int* statut, int* copie_statut, int* compteur, int* copie_compteur ){
    /**initialisation tableau 1D**/
    initialisation_copie_tab(objet, copie_objet);
    initialisation_copie_tab(score, copie_score);
    initialisation_copie_tab(statut, copie_statut);
    initialisation_copie_tab(compteur, copie_compteur);

    initialisation_copie_carte(map , copie_map);          // initialiser et remplir la carte
}

/**MISE A JOUR DES COPIES**/
void mise_a_jour (int** map,int ** copie_map, int* objet, int* copie_objet, int* score, int* copie_score, int* statut, int* copie_statut, int* compteur, int* copie_compteur){
    int i,j;
    for (i=0; i<TAILLE ; i++)
    {
        for (j=0 ; j<TAILLE; j ++)                   // copies entierement la carte
            {
                copie_map[i][j] = map[i][j];

            }
    }
    for(i=0;i<NBPLAYERS;i++)                        // on met toute les valeurs dans les copies
    {
        copie_objet[i]=objet[i];
        copie_score[i]= score[i];
        copie_statut[i]= statut[i];
        copie_compteur[i]= compteur[i];

    }

}


/**AUTRE INITIALISATION REINITIALISER A FOIS QU'UN AUTRE JOUEUR JOUE**/
void initialisation_action(int* action)                       // Initialisation et remise à zero des mouvements possibles des joueurs
{
    int i;
    for (i=0 ; i<3 ; i++)
    {
        action[i]=0;
    }
}
void recherche_position(int** map,int* position, int* copie , int joueur)    // Recherche la position du joueur qui joue et cree une copie de la position
{
    int i, j;
    for (i=0;i<TAILLE;i++)
    {
        for (j=0;j<TAILLE;j++)
        {
            if (map[i][j] == joueur)                                        // regarde tout la carte pour trouvez le joueur
            {
                position[0]=j;
                position[1]=i;
            }
        }
    }
    for (i=0; i < 2 ; i++)
    {
        copie[i]=position[i];                                               // copie la positino
    }
}

/**TRICHE**/
void triche (int* deplacement)                                // Stop le joueur si triche
{
    int i;
    for (i=0 ; i<3 ; i++)
    {
        deplacement[i]=0;
    }
}

/**OBJET**/
void objet_statuts(int* objet, int*score, int* statut , int joueur)        // Utilisation objet simple sinon mettre l'objet dans le statut du joueur
{
    int i;
    switch(objet[joueur % 30])
    {
    case AIMANT:
        statut[joueur%30]=AIMANT;
        break;
    case BOOST:
         statut[joueur%30]=BOOST;
        break;
    case REDUCT:
        for (i=0;i<NBPLAYERS;i++)
        {
            if (i!= (joueur%30)){
                score[i]=score[i]-10;
            }
        }
        objet[joueur%30]=0;
        break;

    case MALEDICTION:
         statut[joueur%30]=MALEDICTION;
        break;

    case MALUS:
        score[joueur % 30]=score[joueur % 30]-10;
        objet[joueur % 30] = 0;
        break;
    case STOP:
         statut[joueur%30]=STOP;
        break;
    case TELEPORT :
         statut[joueur%30]=TELEPORT;
        break;
    case BONUS:
        score[joueur % 30]=score[joueur%30]+10;
        score = 0;
        break;
    case DOUBLEPOINT:
         statut[joueur%30]=DOUBLEPOINT;
        break;
    case BOUCLIER:
         statut[joueur%30]=BOUCLIER;
    case BOMBE:
        statut[joueur%30]=BOMBE;
        break;
    case SAUT:
        statut[joueur%30]=SAUT;
        break;
    default:
        break;
    }
}


/**FONCTION DES OBJETS**/

void fin_paralyse(int*objet, int*statut, int joueur)                        // fonction qui met fin a la paralysi
{
    int i ;
    for (i=0; i<NBPLAYERS; i++)
        {
            if (i!= joueur%30 && statut[i]==PARALYSER)
            {
                objet[i]= statut[i];
            }
        }
}


void paralyse(int* statut, int joueur, int*compteur, int* objet)           //Objet STOP
{

    int i;
    if (compteur[joueur%30]==0)                                         // vérification si objet a deja été utiliser une fois ou nn
    {
        for(i=0 ; i<NBPLAYERS; i++)
        {
            if ((i !=(joueur % 30)))                                   // attaque sur les autres joueur
            {
                if (statut[i] == BOUCLIER)                             // si bouclier le joueur est protégé
                {
                    statut[i]=0;
                    objet[i]=0;
                }
                else                                                // sinon il est paralyser
                {
                    statut[i]=PARALYSER;

                }

            }
        }
    }

    compteur[joueur % 30]=compteur[joueur % 30]+1;              // incrementatino du compteur

    if (compteur[joueur%30]== 3)                                // regard si l'objet est finie ou non
    {
        compteur[joueur%30]=0;
        statut[joueur%30]=0;
        objet[joueur%30]=0;                                    // remet a 0 tout sur les objets
        fin_paralyse(objet,statut,joueur);                   // retire le statut paralyser aux autre joueur
    }
}

void bombe(int** map , int* position, int* score,int joueur)               // Objet BOMBE
{
    // A venir .
}


/**UTILISATION OBJET**/                                                    // Appelle la fonction d'un objet associer au Statut ou a son action du joueur (BOMBE non compris)
void utilisation_objet(int**map, int* position, int* compteur,int* score,int* statut, int* objet, int* action ,int joueur)
{
  switch (statut[joueur % 30])
  {
  case STOP:
        paralyse(statut,joueur, compteur, objet);
        break;
  case AIMANT:
      // a venir
    break;
  case DOUBLEPOINT:
      // a venir
    break;
  case MALEDICTION :
    // a venir
    break;
  case TELEPORT :
    // a venir
    break;
  case BOOST:
    // a venir (le plus compliqué)
    break;
  default:
    break;
  }

  if (action[2]==SAUT)                      // incrementation du compteur saut
  {
      compteur[joueur%30]=compteur[joueur%30]+1;

      if (compteur[joueur%30]>= 2)      // fin utilisation saut
      {
          compteur[joueur%30]=0;
          statut[joueur]=0;
          objet[joueur]=0;
      }
  }
}



/**VERIFICATION**/
void verification_deplacement (int** map ,int* action, int*objet,int* position ,int joueur, int* statut)   //Vérifie si le déplacement est autorisé ou non
{
    int deplacement_y = position[1]+ action[1];                         // coordonnée après deplacement y
    int deplacement_x = position[0]+ action[0];                        // coordonnée après deplacement x

    if ((action[0]>1) || (action[1]>1)|| action[0]<-1 || action[1]<-1)         // mouvement particulier quand superieur à 1
    {
        if ((action[0]>2) || (action[1]>2)|| (action[0]<-2) || (action[1]<-2)) // si mouvement est autorisé
        {
            triche(action);
        }
        else if ((action[2] == SAUT) && (action[2] == objet[(joueur%30)]))      // si l'objet SAUT et bien utilisé
        {
            if ((((action[0]==2) &&(action[1]!=0))||((action[0]==-2) &&(action[1]!=0)))||(((action[0]!=0) &&(action[1]==2))|| ((action[0]!=0) &&(action[1]==-2)))) // si le deplacement est bon avec l'objet SAUT
            {
                triche(action);
            }
        }
        else
        {
            triche(action);
        }
    }
    else if (((action[0]==1)&&(action[1]!=0))||((action[0]==-1) &&(action[1]!=0))||((action[0]!=0) &&(action[1]==1))|| ((action[0]!=0) &&(action[1]==-1))) // si le deplecement est bon
    {
        triche(action);
    }

    if ((deplacement_y>23) || (deplacement_y< 0)||(deplacement_x >23) || (deplacement_x < 0) )  // si depassement du tableau ( erreur de segmentation)
    {
        triche(action);
    }
    else if ((map[deplacement_y][deplacement_x]== TROUE )|| (map[deplacement_y][deplacement_x]>=30)) // verification si le deplacement n'est pas interdit par les régles
    {
        triche(action);
    }

    if(statut[joueur % 30]==PARALYSER)                          // si joueur paralyser ne bouge pas
        {
            action[0]=0;
            action[1]=0;
        }
}

void verification_objet_bombe(int** map,int* position, int* score, int* objet, int*action,int* compteur,int*statut, int joueur) // Vérifie si l'objet utilisé esr autorisé ou nn plus utilisation de la bombe si le joueuer le souhaite
{
    if ((action[2]>3))                                      // si objet utiliserr
    {
        if (objet[(joueur%30)]!= action[2])                 // vérification si objet utilisé correspond a ce que le joueur possède
        {
            triche(action);
        }
        else if (action[2]==BOMBE)                          // si bombe utilisation
        {
            bombe(map, position, score, joueur);            // a venir
        }
    }
}

/**DEPLACEMENT**/                                                         // Deplacement du joueuer et recuperartion des points ou objets
void deplacement(int** map, int* action,int* objet, int*score , int* position,int* compteur, int*statut, int joueur )
{
    int save;
    int deplacement_y = position[1]+ action[1];                         // coordonnée après deplacement
    int deplacement_x = position[0]+ action[0];                         // coordonnée après deplacement

    if (action[0]!= action[1])                                          // vérification si pas 0 0
    {
        save = map[deplacement_y][deplacement_x];                       // sauvegarde de la valeur où le joueur veut aller
        map[deplacement_y][deplacement_x]=joueur;                       // faire avancer le joueur
        map[(position[1])][(position[0])]=VIDE;                         // mettre à 0 la case où le joueur était

        if (save<=3 && statut [joueur%30]== DOUBLEPOINT)                // si point et objet double point
        {
            score[(joueur % 30)]= (score[(joueur % 30)]+ (save*2));
        }
        else if (save<=3)                                               // si point
        {
            score[(joueur % 30)]= (score[(joueur % 30)]+ save);
        }
        else if (save== ALEATOIRE)                                      // objet aléatoire
        {
            // a venir
        }
        else                                                            // sinon objet
        {
            if (statut[joueur%30]=STOP)                                 // si joueur avait objet STOP
            {
                fin_paralyse(objet,statut,joueur);                      // retire "paralysé" à tous les autres joueurs
            }
            objet[(joueur % 30)]= save;                                 // met objet dans le tableau objet du joueur
            compteur[joueur%30]=0;
            statut[joueur%30]=0;                                        // remise à zero des compteurs et des statuts
            objet_statuts(objet, score, statut , joueur);               // l'objet dans le statut ou utilisation objet simple
        }
    }
    else
    {
        //printf("jouer %d ne bouge pas \n", joueur);                   //afficher que le joueur n'a pas bougé
    }
}


void negative(int* score, int joueur)                                     // remet les points du joueur à 0 si son score est inferieur à 0
{
    if (score[joueur % 30 ]<0)
    {
        score[joueur % 30]=0;
    }
}



/**IA**/                                                                  // IA à programmer par les joueurs
void ia_1(int* action,int** map,int* objet,int* score,int* position,int* statut,int*compteur, int current_player)
{
       action[2]=0;
    action[1]=1;
    action[0]=0;

}
void ia_2 (int* action,int** map,int* objet,int* score,int* position,int* statut,int* compteur, int current_player)
{
    action[0]=-1;
    action[1]=0;
    action[2]=0;
}



void trie_a_bulle(int* tab)                                                //fonction qui fait un tri à bulles
{
    int i;
    int sauvegarde;
    int reset;
    do{
        reset=0;
        for(i=0; i<(NBPLAYERS-1); i++)
        {
            if (tab[i]<tab[i+1])
            {
                sauvegarde= tab[i+1];
                tab[i+1]=tab[i];
                tab[i]=sauvegarde;
                reset=1;
            }
        }
    }while(reset!=0);

}

/**GAGNANT**/
void gagnant(int* score)
{
    int* classement= malloc(NBPLAYERS*sizeof(int));
    int i,j;
    int rang=1;
    int suivant;
    j=0;
    for (i=0 ; i<NBPLAYERS; i++)
    {
        classement[i]=score[i];                 // donne les valeurs de score à classement
    }
    trie_a_bulle(classement);
    do{
        suivant=0;
        for(i=0;i< NBPLAYERS;i++)               // on regarde à partir du score le plus haut afin de determiner le joueur
        {
            if (classement[j]==score[i])       // retirer le commentaire pour voir le printf
            {
              /*  printf("joueur %d tu es classé %d / %d avec un score de %d",(i+30),rang,NBPLAYERS,score[i]);
                printf("\n");*/
                suivant= suivant+1;             // si égalité les personnes auront le rang le plus haut.
            }
        }
        j=j+suivant;
        rang=rang + suivant;
    }while (j<NBPLAYERS);                       // on continue jusqu'a ce que le tableau classement soit entièrement parcouru

}

/**JEUX**/
void jeux_ia ()
{
    int i , j ;
    srand(time(NULL));
    /**INITIALISATION DES TABLEAUX DYNAMIQUE**/          //Lorsque l'allocation se fait dans une fonction le programme ne marche pas
    int** map = malloc(TAILLE*sizeof(int*));                                        // carte
    int** copie_map = malloc(TAILLE*sizeof(int*));                                  // copie de la carte
    for (i=0; i<TAILLE; i++)
    {
        map[i]=(int*) malloc(TAILLE*sizeof(int));
    }
    for (i=0; i<TAILLE; i++)
    {
        copie_map[i]=(int*) malloc(TAILLE*sizeof(int));
    }

    int* score = malloc(NBPLAYERS*sizeof(int));                                    // score des joueurs
    int* copie_score= malloc(NBPLAYERS*sizeof(int));                                // copie des scores

    int* objet = malloc(NBPLAYERS*sizeof(int));                                    // l'objet des joueurs
    int* copie_objet = malloc(NBPLAYERS*sizeof(int));                              // copie des objets

    int* statut_joueur= malloc(NBPLAYERS*sizeof(int));                              // statut des joueurs
    int* copie_statut= malloc(NBPLAYERS*sizeof(int));                              // copie des statuts

    int* compteur = malloc(NBPLAYERS*sizeof(int));                                 // compteur: compte la durée d'utilisation des objets des joueurs
    int* copie_compteur = malloc(NBPLAYERS*sizeof(int));                          // copie_ compteur

    /**Appel la fonction qui va initialiser le jeu **/
    initialisation_jeux(map, copie_map , objet , copie_objet , score, copie_score, statut_joueur, copie_statut, compteur, copie_compteur);

    int* position = (int*) malloc(2 * sizeof(int));                               // la position des joueurs
    int* copie_position = (int*) malloc(2 * sizeof(int));                         // copie position

    int* action  = (int*) malloc(3 * sizeof(int));                                // action du joueur: 0=x(ligne) 1=y (ligne) 2= objet



    int current_player = 0;
    current_player= rand()%2;                                                       // Premier joueur aléatoire

    if (current_player==1)
        {
        current_player=30;
        }
    else
        {
        current_player=31;
    }



 for(i = 0; i < TURNS; i++)
    {
        for(j = 1; j <= NBPLAYERS; j++)
        {
            recherche_position(map,position, copie_position, current_player);     // cherche position du joueur
            initialisation_action(action);                                         // remet action à 0
            switch(current_player) {                                              // choix du joueur
                case PLAYER1:                                                      // joueur 30 avec toute les données auquelles il a accès
                    ia_1(action, copie_map, copie_objet, copie_score, copie_position,copie_statut,copie_compteur, current_player);
                    break;
                case PLAYER2:                                                      // joueur 30 avec toute les données auquel il à accès
                    ia_2(action, copie_map, copie_objet, copie_score, copie_position,copie_statut,copie_compteur, current_player);
                default:
                    break;
            }
            verification_deplacement(map, action,objet,position, current_player, statut_joueur);                        // appelle de la verification du deplacement
            verification_objet_bombe( map, position, score, objet,action, compteur ,statut_joueur,current_player);      // verification de l'objet et utilisation bombe
            deplacement(map,action,objet,score,position, compteur,statut_joueur,current_player);                        // appelle fonction de deplacement
            utilisation_objet(map,position, compteur,score,statut_joueur,objet,action, current_player);                  // appelle fonction qui utilise objet
            negative(score,current_player);                                                                             // fonction qui met le score à 0 si négatif
            mise_a_jour(map,copie_map, objet, copie_objet, score, copie_score, statut_joueur, copie_statut, compteur, copie_compteur); // mise a jour des copies

            current_player = current_player + 1;            // changement de joueur

            if((current_player % 30) == NBPLAYERS)          // remet le joueurs 30 si tout le monde au dessus de lui a joué
            {
                    current_player = 30;
            }
        }
    }
    gagnant(score);                                         // fonction qui fait le classement


   /*for (i=0;i<TAILLE;i++){                               // affichage du jeu sans SDL retirer les commentaire pour voir la map
        for (j=0;j<TAILLE;j++)                        
        {
            printf("%3d", map[i][j]);
        }
        printf("\n");*/
    }

    // On ne peut pas free les tableaux cela fait planter le programme

}




int main()
{
    jeux_ia();
    return 0 ;
}
