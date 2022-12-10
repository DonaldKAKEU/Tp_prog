#ifndef LOG_H
#define LOG_H


/*structure qui permet d'enregistrer les logements*/
 typedef struct Logement {
    double id, accomodates, bedrooms, bathdrooms, beds, price, min_nights, max_nights, number_of_reviews, distance_x;
    }Logement;
const Logement logement_x = {105, 3, 2, 1, 3, 508, 4, 110, 178, 0};    

/**********************************************************/
Logement liste_de_logement[7917];

int toute_les_distances[7917]; // tableau qui contient toute les distance par rapport au logement x
int k;

/********************************************************/
//  variable 

char * donnee_alphabetique; // contient les valeur du dataset sous forme de chaine de caractere
double donnee_numerique;
/******************************************************/


char ligne_du_fichier[256];

/*****************************************************/
 

 /*PROTOTYPE*/
void afficher_logement(Logement *l);
void stockage_dans_logement(double *donnee, int *t, Logement *l);
double calcul_distance(Logement *x, Logement *y, int ref_variable);
int comparer_logement ( const void * first, const void  * second );
void fonction_random( Logement log[]);

#endif


