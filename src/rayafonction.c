#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rayafonction.h"
#include <gtk/gtk.h>

////////////AJOUTER
int ajouter_reclamation(reclamation r)
{
int ajout=0;
FILE *f=NULL;
f=fopen("rec.txt","a+") ;
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %d %d %d  \n" , r.id , r.reff ,r.prec ,r.texte ,r.Jour,r.Mois,r.Annee);
ajout=1;
}
fclose(f);
return ajout;

}


//////////////////////////////////////////////////////////////////////////////////////////////////////


///////AFFICHER

enum
{ 
 Eid,
    Ereff,
     Eprec,
      Etexte,
       EJour,
       EMois,
        EAnnee,
 COLUMNS };

void afficher_reclamation(GtkWidget  *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	reclamation r;
	char id[20];
	char reff[20];
	char prec[20];
        char texte[200];
	int  Jour;
	int Mois;
        int Annee;
	

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer, "text",Eid,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("reff",renderer,"text",Ereff,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" prec",renderer, "text", Eprec,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" texte",renderer, "text",Etexte,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Jour",renderer, "text", EJour,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Mois",renderer, "text",EMois,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Annee",renderer, "text",EAnnee,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	

	
	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_INT,  G_TYPE_INT, G_TYPE_INT);
	f=fopen("rec.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
	 	while(fscanf(f,"%s %s %s %s %d %d %d \n",id,reff,prec,texte,&Jour,&Mois,&Annee)!=EOF)	          						  
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, Eid,id,Ereff,reff,Eprec,prec,Etexte,texte,EJour,Jour,EMois,Mois,EAnnee,Annee,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

/////////////////////////////////////////////////////////////////

//////////////SUPRIMER
void supprimer_reclamation(char ids[])

{

FILE *f;
FILE *tmp;
reclamation r;
f=fopen("rec.txt","r");

tmp=fopen("tempo.txt","a+");


  while(fscanf(f,"%s %s %s %s %d %d %d \n",r.id , r.reff ,r.prec ,r.texte,&r.Jour ,&r.Mois,&r.Annee)!=EOF)
    {
	if(strcmp(r.id,ids)!=0)
        {fprintf(tmp,"%s %s %s %s %d %d %d  \n" ,r.id,r.reff,r.prec ,r.texte,r.Jour ,r.Mois,r.Annee);
}

    }

fclose(f);
fclose(tmp);
remove("rec.txt");
rename("tempo.txt","rec.txt");

}
//////////////////////////////////////////////////////////////////////////////////////

///////////MODIFIER
int modifier_reclamation(reclamation r)
{       
        
        char id[20];
	char reff[20];
	char prec[20];
        char texte[200];
	int  Jour;
	int Mois;
        int Annee;
 
	

FILE *f;
FILE *tmp;

f=fopen("rec.txt","r");
tmp=fopen("tmp.txt","a+");
while (fscanf(f,"%s %s %s %s %d %d %d \n",id,reff,prec,texte,&Jour,&Mois,&Annee)!=EOF)
{
if (strcmp(r.id,id)==0)
	{fprintf(tmp,"%s %s %s %s %d %d %d  \n" , r.id,r.reff,r.prec ,r.texte ,r.Mois,r.Annee,r.Jour);

}
else
	fprintf(tmp,"%s %s %s %s %d %d %d  \n" , id,reff,prec,texte,Jour,Mois,Annee);
}

fclose(f);
fclose(tmp);
remove("rec.txt");
rename("tmp.txt","rec.txt");


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////SUPPRIMER
void rechercher_reclamation(GtkWidget *liste, char idr[])

{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	reclamation r;
	char id[20];
	char reff[20];
	char prec[20];
        char texte[200];
	int  Jour;
	int Mois;
        int Annee;
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer, "text",Eid,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column =gtk_tree_view_column_new_with_attributes("reff",renderer,"text",Ereff,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prec",renderer, "text", Eprec,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("texte",renderer, "text", Etexte,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",EJour,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Mois",renderer, "text",EMois,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Annee",renderer, "text",EAnnee,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	
	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_INT,G_TYPE_INT,G_TYPE_INT );
	f=fopen("rec.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
	 	while(fscanf(f,"%s %s %s %s %d %d %d  \n",id,reff,prec,texte,&Jour,&Mois,&Annee)!=EOF)
	          	{
            if(strcmp(id,idr)==0)                						  
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter,Eid,id,Ereff,reff,Eprec,prec,Etexte,texte,EJour,Jour, EMois,Mois,EAnnee,Annee,-1);
		}
                 }
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}
}
///////////////////////////////////////////////

////////DASHBOARD

int service_plus()
{
reclamation r;
char reff [20];
reclamation mm[30];
int nb_1=0;
int nb_2=0;
 int i=0; 
int j;
int serv =0;
FILE*f;
f=fopen("rec.txt","r");
while(fscanf(f,"%s %s %d %d %d \n",r.id,r.reff,r.prec,r.texte,&r.Jour,&r.Mois,&r.Annee)!= EOF)
{strcpy(mm[i].reff,r.reff);
i++;}

fclose(f);

for(int j =0;j<30;j++){
    if (strcpy(mm[j].reff,"1") )nb_1+=1;
    else nb_2+=1;
}
if (nb_1>nb_2)


  {  printf("le service d'hebergement est le plus reclame\n ");
serv=1;}
else if  (nb_1<nb_2){
      printf("le service de restauration est le plus reclame \n");
serv=0;}
return serv;
}






////////////////////////////////tester si l'utilisateur existe ou non 
int test_reclamation(char *idt)
{
FILE*f=NULL;
reclamation r;
f=fopen("rec.txt","r");
while(fscanf(f,"%s %s %s %s  %d %d %d \n",r.id,r.reff,r.prec,r.texte,&r.Jour,&r.Mois, &r.Annee)!=EOF)
{
if(strcmp(r.id,idt)==0)
return 1;  
}
fclose(f);
return 0;
}
////////////////////les fonctions verifiant les controles de saisie ////////////////

/////////////// champs contenant que des lettres /////////////
int RE_verifier_lettre (char ch[20])
{
int i;
int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] != 'a' && ch[i] != 'b' && ch[i] != 'c' && ch[i] != 'd' &&ch[i] != 'e' &&ch[i] != 'f' &&ch[i] != 'g' &&ch[i] != 'h' &&ch[i] != 'i' &&ch[i] != 'j' &&ch[i] != 'k'&&ch[i] != 'l'&&ch[i] != 'm'&&ch[i] != 'n'&&ch[i] != 'o'&&ch[i] != 'p'&&ch[i] != 'q'&&ch[i] != 'r'&&ch[i] != 's'&&ch[i] != 't'&&ch[i] != 'u'&&ch[i] != 'v'&&ch[i] != 'w'&&ch[i] != 'x'&&ch[i] != 'z'&&ch[i] != 'y'  )
    x = 1 ;}
   if ( x == 0 ) return 1;
    else return 0;
}



/////////////// champs contenant que des CHIFFRES /////////////
int RE_verifier_id (char ch[20])
{int i;int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' &&ch[i] != '4' &&ch[i] != '5' &&ch[i] != '6' &&ch[i] != '7' &&ch[i] != '8' &&ch[i] != '9'  || strlen(ch)!=8 )
    x = 1 ;}
   if ( x == 0 ) return 1;
   else return 0;}
///////Longueur de texte//////
int RE_longueur(char ch[200])
{int i;int x = 0;
   for (i=0 ; i < strlen (ch) ; i++)
   {if (i>50);
    x = 1 ;}
  
   return x;

}
