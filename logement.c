#include "logement.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
 /*cette fonction permet de transformer les chaines de caractere collectées en entier et les stocke dans un tableau*/  
 void stockage_dans_logement(double *donnee, int *t, Logement *l){
    
    switch (*t)
    {
    case 0:
        (*l).id = *donnee;
        break;
    case 1:
        (*l).accomodates = *donnee;
        break;
    case 2:
        (*l).bedrooms = *donnee;
        break;
    case 3:
        (*l).bathdrooms = *donnee;
        break;
    case 4:
        (*l).beds = *donnee;
        break;
    case 5:
        (*l).price = *donnee;
        break;
    case 6:
        (*l).min_nights = *donnee;
        break;
    case 7:
        (*l).max_nights = *donnee;
        break; 
     case 8:
        (*l).number_of_reviews = *donnee;
        break;
    default:
        printf("******************ERROR stockage dans logement***************\n");
        break;
    }
}
/*********************************************************************************************/
 /*pour afficher un logement*/
void afficher_logement(Logement *l){

        printf("{%f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f}\n", (*l).id, (*l).accomodates, (*l).bedrooms, (*l).bathdrooms, (*l).beds, (*l).price, (*l).min_nights, (*l).max_nights, (*l).number_of_reviews, (*l).distance_x);
}
/************************************************************************************************/

/*pour calculer la distance entre deux logements*/
double calcul_distance(Logement *x, Logement *y, int ref_variable){

    double resultat; 


    switch (ref_variable)
    {
    case 0:
       return fabs((*x).id - (*y).id);
        break;
    case 1:
         return (*x).accomodates - (*y).accomodates;
        break;
    case 2:
        return (*x).bedrooms - (*y).bedrooms;
        break;
    case 3:
        return (*x).bathdrooms - (*y).bathdrooms;
        break;
    case 4:
        return (*x).beds - (*y).beds;
        break;
    case 5:
        resultat = fabs((*x).price - (*y).price);
        return resultat;

        break;
    case 6:
        return (*x).min_nights - (*y).min_nights;
        break;
    case 7:
        return (*x).max_nights -  (*y).max_nights;
        break; 
     case 8:
        return (*x).number_of_reviews - (*y).number_of_reviews;
        break; 
    default:
        printf("***********ERROR  calcul de distance******************\n");
        break;
    }


}
/************************************************************************************************************/

/*comparer deux Logement par rapport au champ distance*/


 int comparer_logement( const void *first, const void *second )
{
    double i1 = (*(const Logement*)first).distance_x;
    double i2 = (*(const Logement*)second).distance_x;
    if (i1 < i2)
        return -1;
    else
        return +1;
}

/*foncton qui randomise le tableau de logement*/
void fonction_random( Logement log[])
{   
    int p;
    int t = 0;
    Logement temp;
    srand(time(NULL));
    for(int i=0; i<7917; i++)
    {
        p = rand() % 7917;
        while(p != t)
        {
            temp = log[i];
            log[i] = log[p];
            log[p] = temp;
        }
        
        int t = p;
    }    
}
