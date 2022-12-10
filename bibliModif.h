#ifndef LOG_M
#define LOG_M


/*structure qui permet d'enregistrer les logements*/
 typedef struct Logement {
    double id, accomodates, bedrooms, bathdrooms, beds, price, min_nights, max_nights, number_of_reviews;
    double distance[3]; // contient la similarité avec le logement x suivant le nombre accomodate, le nombre de chambre bedrooms, le nombre de lits;
    }Logement;

const Logement logement_x = {105, 3, 2, 1, 3, 508, 4, 110, 178, {0, 0, 0}}; 


/*tableau où seront stockés les structures logement*/
Logement liste_de_logement[7917];

int k;
/*******************************************************************************************************************/

/*variables qui me permettent de lire le fichier*/
char * donnee_alphabetique; // contient les valeur du dataset sous forme de chaine de caractere
double donnee_numerique;
char ligne_du_fichier[256];



/*PROTOTYPES*/
void afficher_logement(Logement *l);
void stockage_dans_logement(double *donnee, int *t, Logement *l);
double calcul_distance(Logement *x, Logement *y, int ref_variable);
int comparer_logement ( const void * first, const void  * second );

#endif