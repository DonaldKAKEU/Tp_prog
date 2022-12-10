#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliModif.h"
#include "fonctionModif.c"
#include <search.h>

int main()
{


char * sep =",";
int i=0; // boucle sur les lignes du fichier
    
     /*ouverture du fichier pour traitement*/ 
   
FILE *dataset = fopen("airbnb_donnees_propre.csv", "r");
    
if (dataset == NULL)
{
    printf("ERREUR fopen\n");
    return 1;
}

    
fgets(ligne_du_fichier, 255, dataset); // premiere lecture pour eliminer la ligne qui contient les noms des varaiables
    
    /*cette boucle permet de lire les différentes lignes du dataset*/  
for (i = 0; i < 1000; i++)
{
    int t=0; //compteur qui permet de remplir les logements
        
    Logement logement;
        
        /*lire la premiere ligne du fichier pour eliminer les noms des variables*/
    fgets(ligne_du_fichier, 255, dataset);
    
    donnee_alphabetique=strtok(ligne_du_fichier, sep); // intruction qui permet d'extraire les données de la ligne lu 
    
        while(donnee_alphabetique != NULL)
            
        { 
             
            donnee_numerique = atof(donnee_alphabetique); // pour transformer la chaine de caractere en un double 
                
            stockage_dans_logement(&donnee_numerique, &t, &logement); // la fonction permet de stocker la valeur extraite dans un tableau d'entier
               
            t+=1;

            donnee_alphabetique=strtok(NULL, sep);   // permet de passer à la valeur suivante sur la meme ligne                                           
                
        } 

logement.distance[0] = abs((logement.accomodates-logement_x.accomodates)); // on rajoute la caractéristique distance 
logement.distance[1] = abs((logement.bedrooms-logement_x.bedrooms));
logement.distance[2] = abs((logement.beds-logement_x.beds));
liste_de_logement[i] = logement; // les logement sont stockés par un tableau de logement 
    
} 

fclose(dataset);

for (int i = 0; i < 1000; i++)
{
    afficher_logement(&liste_de_logement[i]);
}

printf("*************APRES LE TRI *************************\n");

//fonction_random(liste_de_logement);

    /* ici je tri le tableau qui contient les distances*/

qsort(liste_de_logement, 20, sizeof(liste_de_logement[0]), comparer_logement);



for (int i = 0; i < 1000; i++)
{
    afficher_logement(&liste_de_logement[i]);
}


    /*l'utilisateur entre les nombre de logement les plus proches*/


printf("******************* entrer la valeur de k : Le nombre de logement sur lesquels vous souhaitez evaluer le prix de votre logement ************************ --->       ");
scanf("%d", &k);

    /*ici j'affiche les k logements les plus proches*/ 
Logement *k_logement = NULL;

k_logement = malloc(k*sizeof(Logement));
if (k_logement == NULL)
    exit(1);

for (int i = 0; i < k; i++)
{
    k_logement[i] = liste_de_logement[i];
    afficher_logement(&k_logement[i]);
    
}



    /*ici je fais la moyenne des k premiers logements*/
   
double somme = 0;
for (i=0 ; i< k ; i++)
{
    somme += k_logement[i].price;
}
double moyenne = (double)somme / (double)k;

printf("la moyenne des distance>>>>   %f\n", moyenne);

   
return 0; 


}
        