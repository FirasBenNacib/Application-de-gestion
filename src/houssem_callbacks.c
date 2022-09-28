#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
//#include "callbacks.h"
#include "hamzacallbacks.h"
#include "houssem_callbacks.h"
#include "nada_callbacks.h"

#include "interface.h"
#include "support.h"
#include "houssem_fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gender = 1; //0 si femme et 1 si homme
int dureeajout = 3;
int ma ;
int fe ;
char cinspp[20];
void
on_buttonafficher_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *tree;
char fich[20]= "etudiants.txt";

tree=lookup_widget(objet_graphique,"hktreeviewgestion");

recherchergendre(tree,ma,fe);
//afficher(tree);
}


void
on_hkbuttonsupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
if (strcmp(cinspp,"")!=0) {
GtkWidget* suppwind;
suppwind = create_hkwindowsupp();
gtk_widget_show(suppwind);
}
//supprimer(cinspp);

}

//rechercher
void
on_hkbuttonrechercher_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cherche;
char ch[20];
GtkWidget *hktreeviewgestion;
GtkWidget *hkwindowgestion;
hkwindowgestion=lookup_widget(button,"hkwindowgestion");

hktreeviewgestion=lookup_widget(hkwindowgestion,"hktreeviewgestion");
cherche = lookup_widget (button ,"hkentrycinrech");
strcpy(ch, gtk_entry_get_text(GTK_ENTRY(cherche)));
hkrechercher(hktreeviewgestion,ch);


}


void
on_hkbuttonmodifier_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{


date d ;
etudiant e;
char cinm[30];
char nomm[30];
char prenomm[30];
char genrem[30];
char niveaum[30];
char chambrem[30];
char dureem[30];
int jourm;
int num_moism;
int anneem;

FILE *f;
f=fopen("etudiants.txt","r");
if (strcmp(cinspp,"")!=0) {
GtkWidget *hkwindowmodifier;
hkwindowmodifier = create_hkwindowmodifier();
gtk_widget_show(hkwindowmodifier);

GtkWidget *togglebutton1,*togglebutton2,*togglebutton3,*togglebutton4,*togglebutton5;
GtkWidget *output;
GtkWidget *hkentrynomm;
hkentrynomm = lookup_widget (hkwindowmodifier ,"hkentrynomm");

GtkWidget *hkentryprenomm;
hkentryprenomm = lookup_widget (hkwindowmodifier ,"hkentryprenomm");

GtkWidget *hkentrycinm;
hkentrycinm = lookup_widget (hkwindowmodifier ,"hkentrycinm");

GtkWidget *hkentrychambrem;
hkentrychambrem = lookup_widget (hkwindowmodifier ,"hkentrychambrem");

GtkWidget *hkcomboboxniveaum;
hkcomboboxniveaum = lookup_widget (hkwindowmodifier ,"hkcomboboxniveaum");

GtkWidget *hkspinbuttonjoursm;
hkspinbuttonjoursm = lookup_widget (hkwindowmodifier ,"hkspinbuttonjoursm");
GtkWidget *hkspinbuttonmoism;
hkspinbuttonmoism = lookup_widget (hkwindowmodifier ,"hkspinbuttonmoism");
GtkWidget *hkspinbuttonanneem;
hkspinbuttonanneem = lookup_widget (hkwindowmodifier ,"hkspinbuttonanneem");

togglebutton1=lookup_widget(hkwindowmodifier,"hkradiobuttonmalem");
togglebutton2=lookup_widget(hkwindowmodifier,"hkradiobuttonfemalem");
togglebutton3=lookup_widget(hkwindowmodifier,"hkradiobutton3moism");
togglebutton4=lookup_widget(hkwindowmodifier,"hkradiobutton6moism");
togglebutton5=lookup_widget(hkwindowmodifier,"hkradiobutton9moism"); 
int index=0;
 while (fscanf(f,"%s %s %s %s %s %s %d %d %d %s \n",cinm,nomm,prenomm,genrem,niveaum,chambrem,&jourm,&num_moism,&anneem,dureem)!=EOF){
if (strcmp(cinspp,cinm)==0){
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(hkwindowmodifier,"hkentrynomm")),nomm);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(hkwindowmodifier,"hkentryprenomm")),prenomm);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(hkwindowmodifier,"hkentrycinm")),cinm);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(hkwindowmodifier,"hkentrychambrem")),chambrem);
	if (strcmp(niveaum,"1")==0){
		index = 0;
	}
	if (strcmp(niveaum,"2")==0){
		index = 1;
	}
	if (strcmp(niveaum,"3")==0){
		index = 2;
	}if (strcmp(niveaum,"4")==0){
		index = 3;
	}if (strcmp(niveaum,"5")==0){
		index = 4;
	}
             	gtk_combo_box_set_active(GTK_ENTRY(lookup_widget(hkwindowmodifier,"hkcomboboxniveaum")),index);
		
		gtk_spin_button_set_value(hkspinbuttonjoursm,jourm);
		gtk_spin_button_set_value(hkspinbuttonmoism,num_moism);
		gtk_spin_button_set_value(hkspinbuttonanneem,anneem);
if (strcmp(genrem,"male")==0)
{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (togglebutton1),TRUE );
	gtk_label_set_text(GTK_LABEL(output),"");
}
else if (strcmp(genrem,"female")==0)
{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (togglebutton2),TRUE );
	gtk_label_set_text(GTK_LABEL(output),"");
}

if (strcmp(dureem,"3")==0)
{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (togglebutton3),TRUE );
	gtk_label_set_text(GTK_LABEL(output),"");
}
else if (strcmp(dureem,"6")==0)
{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (togglebutton4),TRUE );
	gtk_label_set_text(GTK_LABEL(output),"");
}
else if (strcmp(dureem,"9")==0)
{
	gtk_toggle_button_set_active(GTK_RADIO_BUTTON (togglebutton5),TRUE );
	gtk_label_set_text(GTK_LABEL(output),"");
}
strcpy(cinspp,"");
}}}}




void
on_hkbuttonajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout;
ajout = create_hkwindowajouter();
gtk_widget_show(ajout);

GtkWidget *hkcomboboxniveaum;
hkcomboboxniveaum = lookup_widget (ajout ,"hkcomboboxniveau");
gtk_combo_box_set_active(GTK_ENTRY(lookup_widget(ajout,"hkcomboboxniveau")),0);
}


void
on_hkbuttonvaliderajout_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *nom , *prenom , *jours , *mois , *annee , *genre , *cin , *niveau , *chambre , *duree;

char fich[20] = "etudiants.txt";
etudiant e;

nom = lookup_widget(GTK_WIDGET(button), "hkentrynom");
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
prenom = lookup_widget(GTK_WIDGET(button), "hkentryprenom");
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
cin = lookup_widget(GTK_WIDGET(button), "hkentrycin");
strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
chambre = lookup_widget(GTK_WIDGET(button), "hkentrychambre");
strcpy(e.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));
jours = lookup_widget(GTK_WIDGET(button), "hkspinbuttonjours");
mois = lookup_widget(GTK_WIDGET(button), "hkspinbuttonmois");
annee = lookup_widget(GTK_WIDGET(button), "hkspinbuttonannee");
e.d.jour =     gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jours));
e.d.num_mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
e.d.annee =    gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
niveau = lookup_widget(GTK_WIDGET(button), "hkcomboboxniveau");
strcpy(e.niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau)));

if (gender == 1){
strcpy(e.genre,"male");
}
else if (gender == 2){
strcpy(e.genre,"female");
}

e.duree=3 ;
if (dureeajout == 6){
e.duree=6 ;

}
if (dureeajout == 9){
e.duree=9 ;
}

GtkWidget *hklabelverifcin;
hklabelverifcin = lookup_widget (button ,"hklabelverifcin");
GtkWidget *hklabelverifchambre;
hklabelverifchambre = lookup_widget (button ,"hklabelverifchambre");
GtkWidget *hklabelverifchampvide;
hklabelverifchampvide = lookup_widget (button ,"hklabelverifchampvide");
int bbb=0;
if ( exist_cin (e.cin)==1 || verifier_cin (e.cin)==0 || (strcmp(e.cin,"")==0)){bbb=1;
	          gtk_widget_show (hklabelverifcin);
}
else {
		  gtk_widget_hide(hklabelverifcin);

}
if ( exist_chambre (e.chambre)==1 || verifier_chambre (e.chambre)==0 || (strcmp(e.chambre,"")==0)){bbb=1;
	          gtk_widget_show (hklabelverifchambre);
}
else {
		  gtk_widget_hide(hklabelverifchambre);

}
if  ( (strcmp(e.nom,"")==0) || (strcmp(e.prenom,"")==0) || (strcmp(e.niveau,"")==0)){bbb=1;
	          gtk_widget_show (hklabelverifchampvide);
}
else {
		  gtk_widget_hide(hklabelverifchampvide);

} 
if (bbb == 0){
hkajouter(fich,e);

GtkWidget *hkwindowajouter;
hkwindowajouter=lookup_widget(button,"hkwindowajouter");
gtk_widget_destroy(hkwindowajouter);

          
}
}


void
on_hkbuttonvaliderm_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *nom , *prenom , *jours , *mois , *annee , *genre , *cin , *niveau , *chambre , *duree;

char fich[20] = "etudiants.txt";
etudiant e;

nom = lookup_widget(GTK_WIDGET(button), "hkentrynomm");
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
prenom = lookup_widget(GTK_WIDGET(button), "hkentryprenomm");
strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
cin = lookup_widget(GTK_WIDGET(button), "hkentrycinm");
strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
chambre = lookup_widget(GTK_WIDGET(button), "hkentrychambrem");
strcpy(e.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));
jours = lookup_widget(GTK_WIDGET(button), "hkspinbuttonjoursm");
mois = lookup_widget(GTK_WIDGET(button), "hkspinbuttonmoism");
annee = lookup_widget(GTK_WIDGET(button), "hkspinbuttonanneem");
e.d.jour =     gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jours));
e.d.num_mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
e.d.annee =    gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
niveau = lookup_widget(GTK_WIDGET(button), "hkcomboboxniveaum");
strcpy(e.niveau,gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau)));

if (gender == 1){
strcpy(e.genre,"male");
}
else if (gender == 2){
strcpy(e.genre,"female");
}

e.duree=3 ;
if (dureeajout == 6){
e.duree=6 ;

}
if (dureeajout == 9){
e.duree=9 ;
}

GtkWidget *hklabelverifcinm;
hklabelverifcinm = lookup_widget (button ,"hklabelverifcinm");
GtkWidget *hklabelverifchambrem;
hklabelverifchambrem = lookup_widget (button ,"hklabelverifchambrem");
int bbb=0;
if ( /*exist_cin (e.cin)==1 ||*/ verifier_cin (e.cin)==0 || (strcmp(e.cin,"")==0)){bbb=1;
	          gtk_widget_show (hklabelverifcinm);
}
else {
		  gtk_widget_hide(hklabelverifcinm);

}
if ( /*exist_chambre (e.chambre)==1 ||*/ verifier_chambre (e.chambre)==0 || (strcmp(e.chambre,"")==0)){bbb=1;
	          gtk_widget_show (hklabelverifchambrem);
}
else {
		  gtk_widget_hide(hklabelverifchambrem);

}
if (bbb == 0){ 
hkmodifier(cinspp,e);


GtkWidget *hkwindowmodifier;
hkwindowmodifier=lookup_widget(button,"hkwindowmodifier");
gtk_widget_destroy(hkwindowmodifier);
}
}

void
on_hkradiobuttonmale_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
	    gender = 1;
}
}


void
on_hkradiobuttonfemale_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
	gender = 2;
}
}

void
on_hkradiobuttonmalem_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
	    gender = 1;
}
}


void
on_hkradiobuttonfemalem_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
	gender = 2;
}
}



void
on_hkradiobutton3mois_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
dureeajout = 3;
}
}


void
on_hkradiobutton6mois_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
dureeajout = 6;
}

}


void
on_hkradiobutton9mois_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
dureeajout = 9;
}
}


void
on_hkradiobutton9moism_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
dureeajout = 9;
}

}
void
on_hkradiobutton6moism_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
dureeajout = 6;
}

}
void
on_hkradiobutton3moism_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
dureeajout = 3;
}
}


void
on_hkwindowmodifier_destroy            (GtkObject       *object,
                                        gpointer         user_data)
{

}


void
on_hktreeviewgestion_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;

gchar* cin;
gchar* nom;
gchar* prenom;
gchar* genre;
gchar* niveau;
gchar* chambre;
gchar* duree;
gchar* jour;
gchar* num_mois;
gchar* annee;


GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter , path))
 {
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&cin,1,&nom,2,&prenom,3,&genre,4,&niveau,5,&chambre,6,&duree,7,&jour,8,&num_mois,9,&annee,-1);
strcpy(cinspp,cin);
//afficher(tree); 

}
}
void
on_hkbuttonretour_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hkwindowajouter;
hkwindowajouter=lookup_widget(button,"hkwindowajouter");
gtk_widget_destroy(hkwindowajouter);

}


void
on_hkbuttonretourm_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *hkwindowmodifier;
hkwindowmodifier=lookup_widget(button,"hkwindowmodifier");
gtk_widget_destroy(hkwindowmodifier);

}

void
on_hkbuttontache2_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget* tachecalcul;
tachecalcul = create_hkwindowtache2();
gtk_widget_show(tachecalcul);
 


}



void
on_hkbuttoncalcul_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

char fich[20] = "etudiants.txt";
char niv1[20] , niv2[20] , niv3[20],niv4[20],niv5[20];
etudiant e;


GtkWidget* hklabeln1;
hklabeln1 = lookup_widget(button,"hklabeln1");
sprintf(niv1,"%d",calcule_etudiants_niveau(fich,"1"));
gtk_label_set_text(GTK_LABEL(hklabeln1), niv1);
GtkWidget* hklabeln2;
hklabeln2 = lookup_widget(button,"hklabeln2");
sprintf(niv2,"%d",calcule_etudiants_niveau(fich,"2"));
gtk_label_set_text(GTK_LABEL(hklabeln2),niv2);
GtkWidget* hklabeln3;
hklabeln3 = lookup_widget(button,"hklabeln3");
sprintf(niv3,"%d",calcule_etudiants_niveau(fich,"3"));
gtk_label_set_text(GTK_LABEL(hklabeln3),niv3);
GtkWidget *hklabeln4;
hklabeln4 = lookup_widget(button,"hklabeln4");
sprintf(niv4,"%d",calcule_etudiants_niveau(fich,"4"));
gtk_label_set_text(GTK_LABEL(hklabeln4),niv4);
GtkWidget *hklabeln5;
hklabeln5 = lookup_widget(button,"hklabeln5");
sprintf(niv5,"%d",calcule_etudiants_niveau(fich,"5"));
gtk_label_set_text(GTK_LABEL(hklabeln5),niv5);
}



void
on_hkcheckbuttonfemmes_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
fe=1;}
else {fe = 0;}
}


void
on_hkcheckbuttonhommes_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
ma=1;}
else {ma = 0;}
}


void
on_hkbuttonactualiser_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *treev;
char fich[20]= "etudiants.txt";
treev=lookup_widget(objet_graphique,"hktreeviewgestion");
recherchergendre(treev,1,1);
//afficher(treev);
}


void
on_hkbuttonmail_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget* envmail;
envmail = create_hkwindowmail();
gtk_widget_show(envmail);
}


void
on_hkbuttonannulermail_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hkwindowmail;
hkwindowmail=lookup_widget(button,"hkwindowmail");
gtk_widget_destroy(hkwindowmail);
}


void
on_hkbuttonconfmail_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

char mailto[50];
GtkWidget *hkentrymail;
hkentrymail = lookup_widget (button,"hkentrymail");
strcpy(mailto,gtk_entry_get_text(GTK_ENTRY(hkentrymail)));
 hksend_email(mailto,cinspp );


GtkWidget *hkwindowmail;
hkwindowmail=lookup_widget(button,"hkwindowmail");
gtk_widget_destroy(hkwindowmail);
}


void
on_hkbuttonannulsupp_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *hkwindowsupp;
hkwindowsupp=lookup_widget(button,"hkwindowsupp");
gtk_widget_destroy(hkwindowsupp);
strcpy(cinspp,"");
}


void
on_hkbuttonvalidsupp_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{


hksupprimer(cinspp);

GtkWidget *hkwindowsupp;
hkwindowsupp=lookup_widget(button,"hkwindowsupp");
gtk_widget_destroy(hkwindowsupp);
strcpy(cinspp,"");
}



gboolean
on_hkwindowgestion_focus_in_event      (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data)
{

GtkWidget *tree;
char fich[20]= "etudiants.txt";

tree=lookup_widget(widget,"hktreeviewgestion");

recherchergendre(tree,1,1);
  return FALSE;
}


