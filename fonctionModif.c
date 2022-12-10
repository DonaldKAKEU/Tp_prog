#include "bibliModif.h"
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

        printf("{%f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; %f ; dist[ %f , %f , %f ]\n", (*l).id, (*l).accomodates, (*l).bedrooms, (*l).bathdrooms, (*l).beds, (*l).price, (*l).min_nights, (*l).max_nights, (*l).number_of_reviews, (*l).distance[0], (*l).distance[1], (*l).distance[2]);

}
/************************************************************************************************/

 int comparer_logement( const void *first, const void *second )
{
    double i1 =((*(const Logement*)first).distance[0] + (*(const Logement*)first).distance[1] + (*(const Logement*)first).distance[2])/3 ;
    double i2 = ((*(const Logement*)second).distance[0] + (*(const Logement*)second).distance[1] + (*(const Logement*)second).distance[2])/3 ;
    if (i1 < i2)
        return -1;
    else
        return +1;
}