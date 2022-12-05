#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logement.h"


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
    
    /*cette boucle permet de ligne les différrentes lignes du dataset*/  
    for (i = 2; i < 7918; i++)
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

    
     liste_de_logement[i] = logement; 
            

    }

   /*ici je calcule toutes les distance par rapport au logfement x et j'en fait un tableau */
    Logement logement_x = {105, 3, 2, 1, 3, 508, 4, 1100, 178}; 
        
    for( i =0; i < 7918; i++)
    {

        toute_les_distances[i] =  calcul_distance(&logement_x , &liste_de_logement[i], 5);

       //printf("distance[%d] -> %f\n", i, toute_les_distances[i]);
    } 

    /* ici je tri le tableau qui contient les distances*/

    qsort(toute_les_distances, 7918, sizeof(double), comparer_double);


    /*l'utilisateur entre les nombre de logement les plus proches*/
    int k;

    printf("*******entrer la valeur de k****** --->");
    scanf("%d", &k);

    /*ici j'affiche les k logements les plus proches */
    double k_distance[k];
    for (int i = 1; i <= k; i++)
    {
        k_distance[i] = toute_les_distances[i];
        printf("distance[%d] -> %f\n", i, k_distance[i]);
        
    }

    /*ici je fais la moyenne des k premiers logements*/
    
    double somme = 0;
    for (i=0 ; i< k ; i++)
    {
         somme += k_distance[i];
    }
    float moyenne = (float)somme / (float)k;




    
    return 0; 


}
        