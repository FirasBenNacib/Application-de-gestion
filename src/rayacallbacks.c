#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "rayacallbacks.h"
#include "interface.h"
#include "support.h"
#include "rayafonction.h"
#include <stdlib.h>
#include <string.h>

int rax = 1;

int ajout;
int service;









void
on_Service_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
        
        int result;
	char res[120];
          char text[200] ;
	GtkWidget *outputMsg;
	GtkWidget *Resultat_label;



     result = service_plus();

	if(result == 1){


    strcpy(text,"Le sevice le plus reclamé est Hebergement! :");
    outputMsg= lookup_widget(button,"Resultat_label");
    GdkColor color;
    gdk_color_parse("blue",&color);
    gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
}

else {strcpy(text,"Le sevice le plus reclamé Restauration! :");
    outputMsg= lookup_widget(button,"Resultat_label");
    GdkColor color;
    gdk_color_parse("blue",&color);
    gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
	
}

}


void
on_Ges_service_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* RE_window1_gestion;

RE_window1_gestion=lookup_widget(button,"RE_window1_gestion");
gtk_widget_destroy(RE_window1_gestion);
GtkWidget* RE_dash;
RE_dash=create_RE_dash();
gtk_widget_show(RE_dash);
}


void
on_RE_button_deconnexion_gestion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* RE_window1_gestion;
GtkWidget* MNauthentification;


RE_window1_gestion=lookup_widget(button,"RE_window1_gestion");
gtk_widget_destroy(RE_window1_gestion);
MNauthentification=lookup_widget(button,"MNauthentification");
MNauthentification=create_MNauthentification();
gtk_widget_show(MNauthentification);
}


void
on_RE_button_ajout_gestion_clicked     (GtkButton       *button,
                                        gpointer         user_data)

{GtkWidget* input;
GtkWidget* output;
GtkWidget* RE_window1_gestion;
RE_window1_gestion=lookup_widget(button,"RE_window1_gestion");
gtk_widget_destroy(RE_window1_gestion);
GtkWidget* RE_window4_ajout;
RE_window4_ajout=create_RE_window4_ajout();
gtk_widget_show(RE_window4_ajout);

  
}


void
on_RE_button_modifier_gestion_clicked  (GtkButton       *button,
                                        gpointer         user_data)
/*
{GtkWidget* input;
GtkWidget* output;
GtkWidget* RE_window1_gestion;
RE_window1_gestion=lookup_widget(button,"RE_window1_gestion");
gtk_widget_destroy(RE_window1_gestion);
GtkWidget* RE_window5_modif;
RE_window5_modif=create_RE_window5_modif();
gtk_widget_show(RE_window5_modif);
}
*/{
GtkWidget *RE_window1_gestion;
GtkWidget *RE_window5_modif;
GtkWidget *RE_treeview1;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;

   char texto[100];
   reclamation r;
    gchar *id;
    gchar *reff;
    gchar *prec;
    gchar *texte;
    gchar *Jour;
    gchar *Mois;
    gchar *Annee;     
	
GtkWidget *outputMsg;

GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*input5;
GtkWidget*input6;
GtkWidget*input7;
GtkWidget*input8;


RE_window1_gestion=lookup_widget(button,"RE_window1_gestion");
RE_treeview1=lookup_widget(RE_window1_gestion,"RE_treeview1");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(RE_treeview1));

if(gtk_tree_selection_get_selected(selection,&model,&iter))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&id,1,&reff,2,&prec,3,&texte,4,&Jour,5,&Mois,6,&Annee,-1);

	strcpy(r.id,id);
	strcpy(r.reff,reff);
	strcpy(r.prec,prec);
	strcpy(r.texte,texte);

        r.Jour=Jour;
        r.Mois=Mois;
        r.Annee=Annee; 

gtk_widget_hide(RE_window1_gestion);
RE_window5_modif=create_RE_window5_modif();
gtk_widget_show(RE_window5_modif);
input1=lookup_widget(RE_window5_modif,"RE_entry_id_modif");
input2=lookup_widget(RE_window5_modif,"RE_entry_valmin_modif");
input3=lookup_widget(RE_window5_modif,"RE_spinbutton4_modif");
input4=lookup_widget(RE_window5_modif,"RE_spinbutton5_modif");
input5=lookup_widget(RE_window5_modif,"RE_spinbutton6_modif");
input6=lookup_widget(RE_window5_modif,"RE_combobox2");
input7=lookup_widget(RE_window5_modif,"RE_radiobutton_fum_modif");
input8=lookup_widget(RE_window5_modif,"RE_radiobutton_temp_modif");



gtk_entry_set_text (GTK_ENTRY(input1),r.id);
gtk_entry_set_text (GTK_ENTRY(input2),r.texte);



gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3),r.Jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),r.Mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5),r.Annee);


}

else
{
         strcpy (texto,"veuillez selectionner la reclamation à modifier !");
         outputMsg=lookup_widget(button,("RE_selection"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg),texto);
}
}
////////////////////////////////////////////////////////////////////



void
on_RE_button_supprimer_gestion_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
char text[100];
GtkWidget *outputMsg;
GtkWidget *RE_window1_gestion;
GtkWidget *RE_window3_supp;
GtkWidget *RE_treeview1;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
	gchar *id;
	gchar *reff;
	gchar *prec; 
	gchar *texte; 
	
	gchar *Jour; 
        gchar *Mois;
        gchar *Annee;
	
        reclamation r;               
	

GtkWidget *input0;

RE_window1_gestion=lookup_widget(button,"RE_window1_gestion");
RE_treeview1=lookup_widget(RE_window1_gestion,"RE_treeview1");
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(RE_treeview1));

if(gtk_tree_selection_get_selected(selection,&model,&iter))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&id,1,&reff,2,&prec,3,&texte,4,&Jour,5,&Mois,6,&Annee,-1);
	
	strcpy(r.id,id);
	strcpy(r.reff,reff);
	strcpy(r.prec,prec);
	strcpy(r.texte,texte);
        r.Jour=Jour;
        r.Mois=Mois;
        r.Annee=Annee; 
	


gtk_widget_destroy(RE_window1_gestion);
RE_window3_supp=create_RE_window3_supp();
gtk_widget_show(RE_window3_supp);
input0=lookup_widget(RE_window3_supp,"RE_entry2");
gtk_entry_set_text (GTK_ENTRY(input0),r.id);
}
else
{
         strcpy (text,"veuillez selectionner la reclamation à supprimer !");
         outputMsg=lookup_widget(button,("RE_selection"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
}





/*{GtkWidget* input;
GtkWidget* output;
GtkWidget* RE_window1_gestion;
RE_window1_gestion=lookup_widget(button,"RE_window1_gestion");
gtk_widget_destroy(RE_window1_gestion);
GtkWidget* RE_window3_supp;
RE_window3_supp=create_RE_window3_supp();
gtk_widget_show(RE_window3_supp);

}
*/


void
on_RE_button_rechercher_gestion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)


{GtkWidget* input;
GtkWidget* output;
GtkWidget* RE_window1_gestion;
RE_window1_gestion=lookup_widget(button,"RE_window1_gestion");
gtk_widget_destroy(RE_window1_gestion);
GtkWidget* RE_window2_liste;
RE_window2_liste=create_RE_window2_liste();
gtk_widget_show(RE_window2_liste);


}


void
on_RE_button_rechercher_liste_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2_liste;
	GtkWidget *RE_treeview3;
	GtkWidget *RE_entry1;
	GtkWidget *RE_window2_liste;


	RE_window2_liste = lookup_widget(button,"RE_window2_liste");
	RE_treeview3 = lookup_widget(RE_window2_liste,"RE_treeview3");
	RE_entry1 = lookup_widget(RE_window2_liste,"RE_entry1");

	rechercher_reclamation(RE_treeview3, gtk_entry_get_text(GTK_ENTRY(RE_entry1)));
}


void
on_RE_button_retour_liste_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* RE_window2_liste;
GtkWidget *RE_treeview1;

RE_window2_liste=lookup_widget(button,"RE_window2_liste");
gtk_widget_destroy(RE_window2_liste);
GtkWidget* RE_window1_gestion;
RE_window1_gestion=create_RE_window1_gestion();
gtk_widget_show(RE_window1_gestion);
RE_treeview1 = lookup_widget(RE_window1_gestion,"RE_treeview1");
afficher_reclamation(RE_treeview1);
}

int rasupp=0;

void
on_RE_button_supprimer_suppression_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *window3_supp;
	GtkWidget *RE_entry2;
	GtkWidget *RE_label_supp_message;
	GtkWidget *RE_window3_supp;

	RE_window3_supp = lookup_widget(button,"RE_window3_supp");
	RE_entry2 = lookup_widget(RE_window3_supp,"RE_entry2");
	RE_label_supp_message = lookup_widget(RE_window3_supp,"RE_label_supp_message");

	if(rasupp == 1){
		supprimer_reclamation(gtk_entry_get_text(GTK_ENTRY(RE_entry2)));
		gtk_label_set_text(GTK_LABEL(RE_label_supp_message),"reclamation supprimé avec succée!");
		gtk_widget_show(RE_label_supp_message);
	}else if(rasupp == 0){
		gtk_label_set_text(GTK_LABEL(RE_label_supp_message),"Ete vous sure?!");
		gtk_widget_show(RE_label_supp_message);
}








/*
reclamation r;
GtkWidget *RE_window3_supp;
GtkWidget *RE_window1_gestion;
GtkWidget *RE_treeview1;
GtkWidget *outputMsg;
GtkWidget *input1;
char text[200];
char id[20];
supp=supprimer_reclamation(id);


RE_window3_supp=lookup_widget(button,"RE_window3_supp");
input1=lookup_widget(button,"RE_entry2");   
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
if(supp=1)
{
supprimer_reclamation(id);
strcpy (text,"reclamation supprimé avec succès");
outputMsg=lookup_widget(button,("RE_label_supp_message"));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
else
{
strcpy (text,"La confirmation est obligatoire!");
outputMsg=lookup_widget(button,("RE_label_supp_message"));
GdkColor color;
gdk_color_parse("red",&color);
gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(outputMsg),text);
}
*/
}



void
on_RE_radiobutton_temp_ajout_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
rax=1;
}
}


void
on_RE_radiobutton_fumee_ajout_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
rax=2;
}

}
void
on_RE_button_ajouter_ajout_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
  /* reclamation r;
   GtkWidget *id;
   GtkWidget *reff;
   GtkWidget *prec;
   GtkWidget *texte;
   GtkWidget *Jour;
   GtkWidget *Mois;
   GtkWidget *Annee;

GtkWidget *outputMsg;
GtkWidget *outputMsg1;
GtkWidget *outputMsg2;
GtkWidget *outputMsg3;
GtkWidget *outputMsg4;



  
   GtkWidget *RE_ComboboxZoCov;
   GtkWidget *RE_label_ajut_reussite; 
   int test,x;
   char text[200];
   char text1[200]; char text2[200]; char text3[200]; char text4[200]; char text5[200];

*/







reclamation r;
   GtkWidget *id;
   GtkWidget *reff;
   GtkWidget *prec;
   GtkWidget *texte;
   GtkWidget *Jour;
   GtkWidget *Mois;
   GtkWidget *Annee;

  
   GtkWidget *RE_ComboboxZoCov;
   GtkWidget *RE_label_ajut_reussite; 
   int ajout,verif;
   char text[200];

  
  
RE_label_ajut_reussite = lookup_widget(button,"RE_label_ajut_reussite");
id=lookup_widget(button,"RE_entry_id_ajout");

strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));

/////////////////////////////////////////////////////////
Jour=lookup_widget(button,"RE_spinbutton1_ajout");
Mois=lookup_widget(button,"RE_spinbutton2_ajout");
Annee=lookup_widget(button,"RE_spinbutton3_ajout");
r.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
r.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
r.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
///////////////////////////////////////////////////////////
texte=lookup_widget(button,"RE_entry_valmin_ajout");
strcpy(r.texte,gtk_entry_get_text(GTK_ENTRY(texte)));
RE_ComboboxZoCov=lookup_widget(button,"RE_combobox1");
strcpy(r.prec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(RE_ComboboxZoCov)));
///////////////////////////////////////////////////////////////////////////
strcpy(r.reff,"Hebergement");
if(rax==1)
{strcpy(r.reff,"Hebergement");}
if(rax==2)
{strcpy(r.reff,"Restauration");}

ajout=ajouter_reclamation(r);
gtk_label_set_text(GTK_LABEL(RE_label_ajut_reussite),"reclamation ajoutee avec succée!");
gtk_widget_show(RE_label_ajut_reussite);
}



	/*GtkWidget *RE_verif_id;
	GtkWidget *RE_verif_type;
	GtkWidget *RE_verif_precision;
	GtkWidget *RE_verif_text;*/

/*
RE_ComboboxZoCov=lookup_widget(button,"RE_combobox1");
texte=lookup_widget(button,"RE_entry_valmin_ajout");
Jour=lookup_widget(button,"RE_spinbutton1_ajout");
Mois=lookup_widget(button,"RE_spinbutton2_ajout");
Annee=lookup_widget(button,"RE_spinbutton3_ajout");
id=lookup_widget(button,"RE_entry_id_ajout");

  int reverif=0;
////////////////////////////
strcpy(r.prec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(RE_ComboboxZoCov)));
strcpy(r.texte,gtk_entry_get_text(GTK_ENTRY(texte)));
r.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
r.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
r.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));


strcpy(r.reff,"Hebergement");
if(rax==1)
{strcpy(r.reff,"Hebergement");}
if(rax==2)
{strcpy(r.reff,"Restauration");}
/////////////////////////////////////



rax=RE_longueur(r.texte);
test=test_reclamation(r.id);
switch (test)
{
     case 1:
    { strcpy (text1,"ID existe deja ! veuillez entrer une nouvelle ID");
    outputMsg=lookup_widget(button,("RE_verif_id"));
    GdkColor color;
    gdk_color_parse("red",&color);
    gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg),text1);
    }
    break;

    case 0:
    { if (RE_verifier_id (r.id)==0 ||(strcmp(r.id,"")==0))
        {reverif=1;
         strcpy (text2,"Verifier votre id,ID contient que des chiffres !");
         outputMsg1=lookup_widget(button,("RE_verif_type"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg1,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg1),text2);
        }
     
      if (RE_verifier_lettre (r.texte)==0 ||(strcmp(r.texte,"")==0))
        {reverif=1;
         strcpy (text3,"Verifier votre texte,votre texte doit contenir que des lettres !");
         outputMsg2=lookup_widget(button,("RE_verif_text"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg2,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg2),text3);
        }

      if (rax=1) 
        {reverif=1;
         strcpy (text4,"Veuillez saisir un texte plus court");
         outputMsg3=lookup_widget(button,("RE_verif_precision"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg3,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg3),text4);}
if (reverif==0)
    {
    ajouter_reclamation(r);
    strcpy (text5,"Ajout Réussi");
    outputMsg4=lookup_widget(button,("RE-label_ajut_reussite"));
    GdkColor color;
    gdk_color_parse("green",&color);
    gtk_widget_modify_fg(outputMsg4,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg4),text5);
    }
        }

    break; 
    break;
} 
  
}

*/
/////////////////////////////////


void
on_RE_button_modifier_modification_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
 reclamation r;
   GtkWidget *id;
   GtkWidget *reff;
   GtkWidget *prec;
   GtkWidget *texte;
   GtkWidget *Jour;
   GtkWidget *Mois;
   GtkWidget *Annee;
   GtkWidget *re_label; 
   GtkWidget *ComboboxZoCov;
   GtkWidget *RE_window5_modif;

   GtkWidget *outputMsg;
   char texto[200];



RE_window5_modif=lookup_widget(button,"RE_window5_modif");
/////////////
id=lookup_widget(button,"RE_entry_id_modif");
strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));

/////////////////////////////////////////////////////////

Jour=lookup_widget(button,"RE_spinbutton4_modif");
Mois=lookup_widget(button,"RE_spinbutton5_modif");
Annee=lookup_widget(button,"RE_spinbutton6_modif");
r.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
r.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
r.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));

///////////////////////////////////////////////////////////
texte=lookup_widget(button,"RE_entry_valmin_modif");
strcpy(r.texte,gtk_entry_get_text(GTK_ENTRY(texte)));
//////////////////////////////////////////////////
ComboboxZoCov=lookup_widget(button,"RE_combobox2");
strcpy(r.prec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxZoCov)));
///////////////////////////////////////////////////////////////////////////
strcpy(r.reff,"Hebergement");
if(rax==1)
{strcpy(r.reff,"Hebergement");}

if(rax==2)
{strcpy(r.reff,"Restauration");}


modifier_reclamation(r);
strcpy(texto,"Modification effectué avec succes");

outputMsg=lookup_widget(button,("re_label"));
GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(outputMsg),texto);;
}


void
on_RE_button_retour_modification_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget *RE_window5_modif;
GtkWidget *RE_treeview1;
RE_window5_modif=lookup_widget(button,"RE_window5_modif");
gtk_widget_destroy(RE_window5_modif);
GtkWidget* RE_window1_gestion;
RE_window1_gestion=create_RE_window1_gestion();
gtk_widget_show(RE_window1_gestion);
RE_treeview1 = lookup_widget(RE_window1_gestion,"RE_treeview1");
afficher_reclamation(RE_treeview1);
}


void
on_RE_button_affichier_modification_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_RE_radiobutton_fum_modif_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
rax=1;
}
}


void
on_RE_radiobutton_temp_moodif_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
rax=2;
}
}






void
on_RE_button_retour_ajout_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* RE_window4_ajout;
GtkWidget *RE_treeview1;
RE_window4_ajout=lookup_widget(button,"RE_window4_ajout");
gtk_widget_destroy(RE_window4_ajout);
GtkWidget* RE_window1_gestion;
RE_window1_gestion=create_RE_window1_gestion();
gtk_widget_show(RE_window1_gestion);
RE_treeview1 = lookup_widget(RE_window1_gestion,"RE_treeview1");
afficher_reclamation(RE_treeview1);
}




void
on_RE_checkbutton_supp_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
rasupp=1;
else
rasupp=0;
}


void
on_RE_button_retour_suppression_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget *RE_window3_supp;
GtkWidget *RE_treeview1;
RE_window3_supp=lookup_widget(button,"RE_window3_supp");
gtk_widget_destroy(RE_window3_supp);
GtkWidget* RE_window1_gestion;
RE_window1_gestion=create_RE_window1_gestion();
gtk_widget_show(RE_window1_gestion);
RE_treeview1 = lookup_widget(RE_window1_gestion,"RE_treeview1");
afficher_reclamation(RE_treeview1);
}


void
on_RE_treeview1_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *id;
	gchar *reff;
	gchar *prec; 
	gchar *texte; 
	gchar *Jour; 
        gchar *Mois;
        gchar *Annee;
	reclamation r;                               
	FILE *f=NULL;


	GtkTreeModel *tree_model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(tree_model,&iter,path))
	{gtk_tree_model_get (GTK_LIST_STORE(tree_model),&iter,0,&id,1,&reff,2,&prec,3,&texte,4,&Jour,5,&Mois,6,&Annee,-1);

	strcpy(r.id,id);
	strcpy(r.reff,reff);
	strcpy(r.prec,prec);
	strcpy(r.texte,texte);

        r.Jour=Jour;
        r.Mois=Mois;
        r.Annee=Annee; 
	
afficher_reclamation(treeview);
}
}


void
on_RE_retour_dash_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* RE_dash;
GtkWidget *RE_treeview1;

RE_dash=lookup_widget(button,"RE_dash");
gtk_widget_destroy(RE_dash);
GtkWidget* RE_window1_gestion;
RE_window1_gestion=create_RE_window1_gestion();
gtk_widget_show(RE_window1_gestion);
RE_treeview1 = lookup_widget(RE_window1_gestion,"RE_treeview1");
afficher_reclamation(RE_treeview1);
}

