#ifndef LOG_H
#define LOG_H


/*structure qui permet d'enregistrer les logements*/
 typedef struct Logement {
    double id, accomodates, bedrooms, bathdrooms, beds, price, min_nights, max_nights, number_of_reviews;
    } Logement;

/**********************************************************/
Logement liste_de_logement[7917];

double toute_les_distances[7917]; // tableau qui contient toute les distance par rapport au logement x



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
int comparer_double ( const void * first, const void * second );

#endif


