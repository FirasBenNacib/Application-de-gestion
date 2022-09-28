#include "houssem_fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <curl/curl.h>

#define from "gestionfoyer2022@gmail.com"
#define pw "gestion@2022"


static const char *payload_text[] = {

  "To: " "etudiant" "\r\n",
  "From: " "agent du foyer" "\r\n",
  "Cc: " "inscription foyer" "\r\n",
  "Subject: vous etes bien inscrit au foyer\r\n",
  "\r\n",
};

char cinemail[2][10] = {""};
int hkj=0;
/*
struct upload_status {
  int lines_read;
};*/

  char flag[100];
static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
  struct upload_status *upload_ctx = (struct upload_status *)userp;
  const char *data;

  if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
    return 0;
  }
if (hkj == 5){
  
    strcpy(flag,"le numero cin :  <");
    strcat(flag,cinemail[0]);
    strcat(flag, ">   est bien inscrit au foyer.\r\n");
  payload_text[5] = flag;
  }
if (hkj == 6){
  payload_text[6] = NULL;}
  data = payload_text[hkj];
  if(data) {
    size_t len = strlen(data);
    memcpy(ptr, data, len);
    upload_ctx->lines_read++;
    hkj++;

    return len;
  }

  return 0;
}

void hksend_email(char to[],char cinem[] )
{
strcpy(cinemail[0],cinem);
hkj=0;
  CURL *curl;
  CURLcode res = CURLE_OK;
  struct curl_slist *recipients = NULL;
  struct upload_status upload_ctx;
  upload_ctx.lines_read = 0;

  curl = curl_easy_init();
  if(curl) {

    curl_easy_setopt(curl, CURLOPT_USERNAME, from);
    curl_easy_setopt(curl, CURLOPT_PASSWORD, pw);

    curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");

    curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);

    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);

    recipients = curl_slist_append(recipients, to);

    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

    curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
    curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
    else


    curl_slist_free_all(recipients);

    curl_easy_cleanup(curl);
  }
}

//#############################################
void hkajouter(char fich[],etudiant e){
    FILE *f=NULL;

    f = fopen(fich,"a+");
    if (f!=NULL){
        
fprintf(f,"%s %s %s %s %s %s %d %d %d %d \n",e.cin,e.nom,e.prenom,e.genre,e.niveau,e.chambre,e.d.jour,e.d.num_mois,e.d.annee,e.duree);
    }
    fclose(f);
}

enum
{
	CIN,
	NOM,
	PRENOM,
	GENRE,
	NIVEAU,
	CHAMBRE,
	DUREE,
	JOUR,
	MOIS,
	ANNEE,
	COLUMNS
};

void hkafficher(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter  iter;
GtkListStore *store;

store=NULL; 

etudiant e ;
FILE *f;

store=gtk_tree_view_get_model(liste);

if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" cin",renderer,"text",CIN,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" genre",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" niveau",renderer,"text",NIVEAU,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" chambre",renderer,"text",CHAMBRE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" duree",renderer,"text",DUREE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
 

store = gtk_list_store_new( COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT,  G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

f = fopen("etudiants.txt","r");
if (f==NULL){

	return;

}else{
f = fopen("etudiants.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %d %d %d %d \n",e.cin,e.nom,e.prenom,e.genre,e.niveau,e.chambre,&e.d.jour,&e.d.num_mois,&e.d.annee,&e.duree) != EOF){
gtk_list_store_append (store,&iter);
gtk_list_store_set(GTK_LIST_STORE(store),&iter,CIN,e.cin,NOM,e.nom,PRENOM,e.prenom,GENRE,e.genre,NIVEAU,e.niveau,CHAMBRE,e.chambre,DUREE,e.duree,JOUR,e.d.jour,MOIS,e.d.num_mois,ANNEE,e.d.annee,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}

void hksupprimer(char cin[]){  
char cinsp[20];
char nomsp[20];
char prenomsp[20];
char genresp[20];
char niveausp[20];
char chambresp[20];
char dureesp[20];
char joursp[20];
char num_moissp[20];
char anneesp[20];

    FILE *f=NULL;
    FILE *t = NULL;
    etudiant e ;
    f = fopen("etudiants.txt","r");
    t = fopen("temp.txt" , "w+");
    if (f!=NULL)
    {
    while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",cinsp,nomsp,prenomsp,genresp,niveausp,chambresp,dureesp,joursp,num_moissp,anneesp)!=EOF){
            if (strcmp(cin,cinsp)!=0){
                fprintf(t,"%s %s %s %s %s %s %s %s %s %s \n",cinsp,nomsp,prenomsp,genresp,niveausp,chambresp,dureesp,joursp,num_moissp,anneesp);
            }
        }
        fclose(f);
        remove("etudiants.txt");
        fclose(t);
        rename("temp.txt","etudiants.txt");

    }

}

void recherchergendre(GtkWidget *liste,int ma, int fe)
{

etudiant e ;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" cin",renderer,"text",CIN,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" genre",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" niveau",renderer,"text",NIVEAU,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" chambre",renderer,"text",CHAMBRE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
 
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" duree",renderer,"text",DUREE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store = gtk_list_store_new( COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT,  G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
f = fopen("etudiants.txt","r");

char cinre[30];
char nomre[30];
char prenomre[30];
char genrere[30];
char niveaure[30];
char chambrere[30];
int jourre;
int moisre;
int anneere;
int dureere;

f = fopen("etudiants.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s %d %d %d %d \n",cinre,nomre,prenomre,genrere,niveaure,chambrere,&jourre,&moisre,&anneere,&dureere)!=EOF)
	{if (strcmp(genrere,"male")==0 && ma == 1){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CIN,cinre,NOM,nomre,PRENOM,prenomre,GENRE,genrere,NIVEAU,niveaure,CHAMBRE,chambrere,JOUR,jourre,MOIS,moisre,ANNEE,anneere,DUREE,dureere,-1);
}
else if (strcmp(genrere,"female")==0 && fe == 1){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CIN,cinre,NOM,nomre,PRENOM,prenomre,GENRE,genrere,NIVEAU,niveaure,CHAMBRE,chambrere,JOUR,jourre,MOIS,moisre,ANNEE,anneere,DUREE,dureere,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}


void hkrechercher(GtkWidget *liste,char ch[30] )
{

etudiant e ;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" cin",renderer,"text",CIN,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" genre",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" niveau",renderer,"text",NIVEAU,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" chambre",renderer,"text",CHAMBRE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
 
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" duree",renderer,"text",DUREE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
store = gtk_list_store_new( COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT,  G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
f = fopen("etudiants.txt","r");

char cinre[30];
char nomre[30];
char prenomre[30];
char genrere[30];
char niveaure[30];
char chambrere[30];
int jourre;
int moisre;
int anneere;
int dureere;

f = fopen("etudiants.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s %d %d %d %d \n",cinre,nomre,prenomre,genrere,niveaure,chambrere,&jourre,&moisre,&anneere,&dureere)!=EOF)
	{if ((strcmp(cinre,ch)==0) || (strcmp(nomre,ch)==0) || (strcmp(prenomre,ch)==0)) {
gtk_list_store_append(store,&iter); 
gtk_list_store_set(store,&iter,CIN,cinre,NOM,nomre,PRENOM,prenomre,GENRE,genrere,NIVEAU,niveaure,CHAMBRE,chambrere,JOUR,jourre,MOIS,moisre,ANNEE,anneere,DUREE,dureere,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}

int verifier_cin (char ch[20])
{int i;int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' &&ch[i] != '4' &&ch[i] != '5' &&ch[i] != '6' &&ch[i] != '7' &&ch[i] != '8' &&ch[i] != '9'  || strlen(ch)!=8 )
    x = 1 ;}
   if ( x == 0 ) return 1;
    else return 0;
}
int verifier_chambre (char ch[20])
{int i;int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' &&ch[i] != '4' &&ch[i] != '5' &&ch[i] != '6' &&ch[i] != '7' &&ch[i] != '8' &&ch[i] != '9'  || strlen(ch)>=4 )
    x = 1 ;}
   if ( x == 0 ) return 1;
    else return 0;
}

int exist_cin (char ch[20])
{
FILE*f=NULL;
etudiant e;
f=fopen("etudiants.txt","r");
   while(fscanf(f,"%s %s %s %s %s %s %d %d %d %d \n",e.cin,e.nom,e.prenom,e.genre,e.niveau,e.chambre,&e.d.jour,&e.d.num_mois,&e.d.annee,&e.duree)!=EOF)
{
if(strcmp(e.cin,ch)==0)
return 1;  
}
fclose(f);
return 0;
}

int exist_chambre (char ch[20])
{
FILE*f=NULL;
etudiant e;
f=fopen("etudiants.txt","r");
   while(fscanf(f,"%s %s %s %s %s %s %d %d %d %d \n",e.cin,e.nom,e.prenom,e.genre,e.niveau,e.chambre,&e.d.jour,&e.d.num_mois,&e.d.annee,&e.duree)!=EOF)
{
if(strcmp(e.chambre,ch)==0)
return 1;  
}
fclose(f);
return 0;
}


int calcule_etudiants_niveau(char fich[], char niv[20]) {
     FILE *f=NULL;
    int   duree , jour, num_mois, annee ;
    char nom[20] , genre[20] , prenom[20],cin[20],chambre[20],niveau[20];
    int n=0; 

    f = fopen(fich,"r");
    if (f!=NULL)
    {
    while (fscanf(f,"%s %s %s %s %s %s %d %d %d %d \n",cin,nom,prenom,genre,niveau,chambre,&duree,&jour,&num_mois,&annee)!=EOF){
      if (strcmp(niveau,niv) == 0) n++;}
    fclose(f);
    return n;         
 }

}
void hkmodifier(char cin[],etudiant e){

char cinm[30];
char nomm[30];
char prenomm[30];
char genrem[30];
char niveaum[30];
char chambrem[30];
char dureem[30];
char jourm[30];
char num_moism[30];
char anneem[30];

FILE*f=NULL;
FILE*f1=NULL;
date d;
f=fopen("etudiants.txt","r");
f1=fopen("ancien.txt","w+");
while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",cinm,nomm,prenomm,genrem,niveaum,chambrem,jourm,num_moism,anneem,dureem)!=EOF){
      if (strcmp(e.cin,cinm) == 0) {
fprintf(f1,"%s %s %s %s %s %s %d %d %d %d \n",e.cin,e.nom,e.prenom,e.genre,e.niveau,e.chambre,e.d.jour,e.d.num_mois,e.d.annee,e.duree);
}
else 
{
fprintf(f1,"%s %s %s %s %s %s %s %s %s %s \n",cinm,nomm,prenomm,genrem,niveaum,chambrem,jourm,num_moism,anneem,dureem);
}
}
fclose(f);
fclose(f1);
remove("etudiants.txt");
rename("ancien.txt","etudiants.txt");
}





