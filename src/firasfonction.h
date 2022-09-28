#include <gtk/gtk.h>

typedef struct
{
	char id[20];
	char type[20];
	char entree[20];
	char plat_principal[20];
	char dessert[20];
         int  Jour;
         int Mois;
         int Annee;
	 char qd[20];

}menu;
typedef struct dechets
{
    int jour1;
    int type1;
    char valeur[10];
}dechets;

int ajouter_menu(menu m);
int supprimer_menu(char id[]);
int modifier_menu(menu m);
void rechercher_menu(GtkWidget *liste, char id[]);
void afficher_menu(GtkWidget *liste);
void dechets_menu(GtkWidget *liste);
void afficher_dechets(GtkWidget  *liste);
int test_menu(char id[]);
