#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logement.h"
#include "logement.c"
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

logement.distance_x = abs((logement.accomodates-logement_x.accomodates)); // on rajoute la caractéristique distance 

liste_de_logement[i] = logement; // les logement sont stockés par un tableau de logement 
    
    
} 


fclose(dataset);

for (int i = 0; i < 1000; i++)
{
    afficher_logement(&liste_de_logement[i]);
}

}