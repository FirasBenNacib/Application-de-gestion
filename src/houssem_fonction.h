
#include <gtk/gtk.h>
typedef struct
{
int jour ;
int num_mois ;
int annee ;
}date;


typedef struct
{
char cin[20];
char chambre[20];
char niveau[20];
char nom[20];
char prenom[20];
date d ;
int duree ;
char genre[20];
}etudiant;
void hkajouter(char fich[],etudiant e);
void hkmodifier(char cin[],etudiant e);
void hksupprimer(char cin[]);
void hkrechercher(GtkWidget *liste, char ch[] );
int calcule_etudiants_niveau(char fich[],char niv[]);
void hkafficher( GtkWidget *liste);
void hksend_email(char to[],char cinem[] );
static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp);
struct upload_status{
int lines_read;};


