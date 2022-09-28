#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "firascallbacks.h"
#include "interface.h"
#include "support.h"
#include "firasfonction.h"
#include <stdlib.h>
#include <string.h>

int xfb = 1;
int suppfb = 0;

void
on_FB_button4_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* FB_window1;
FB_window1=lookup_widget(button,"FB_window1");
gtk_widget_destroy(FB_window1);
GtkWidget* FB_window2;
FB_window2=create_FB_window2();
gtk_widget_show(FB_window2);
}


void
on_FB_button3_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* FB_window1;
FB_window1=lookup_widget(button,"FB_window1");
gtk_widget_destroy(FB_window1);
GtkWidget* FB_window3;
FB_window3=create_FB_window3();
gtk_widget_show(FB_window3);
}


void
on_FB_button2_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* FB_window1;
FB_window1=lookup_widget(button,"FB_window1");
gtk_widget_destroy(FB_window1);
GtkWidget* FB_window5;
FB_window5=create_FB_window5();
gtk_widget_show(FB_window5);
}


void
on_FB_button1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* FB_window1;
FB_window1=lookup_widget(button,"FB_window1");
gtk_widget_destroy(FB_window1);
GtkWidget* FB_window4;
FB_window4=create_FB_window4();
gtk_widget_show(FB_window4);
}


void
on_FB_button5_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *FB_window1;
GtkWidget *FB_window6;
GtkWidget *FB_treeview3;

FB_window1=lookup_widget(button,"FB_window1");
gtk_widget_destroy(FB_window1);
FB_window6=lookup_widget(button,"FB_window6");
FB_window6=create_FB_window6();
gtk_widget_show(FB_window6);
FB_treeview3=lookup_widget(FB_window6,"FB_treeview3");
dechets_menu(FB_treeview3);

//remove(FB_treeview3);
//gtk_widget_destroy(FB_window1);
}


void
on_FB_button6_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* FB_window2;
GtkWidget *FB_treeview1;

FB_window2=lookup_widget(button,"FB_window2");
gtk_widget_destroy(FB_window2);
GtkWidget* FB_window1;
FB_window1=create_FB_window1();
gtk_widget_show(FB_window1);
FB_treeview1 = lookup_widget(FB_window1,"FB_treeview1");
afficher_menu(FB_treeview1);
}


void
on_FB_button7_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *FB_window2;
	GtkWidget *FB_treeview2;
	GtkWidget *FB_entry1;


	FB_window2 = lookup_widget(button,"FB_window2");
	FB_treeview2 = lookup_widget(FB_window2,"FB_treeview2");
	FB_entry1 = lookup_widget(FB_window2,"FB_entry1");

	rechercher_menu(FB_treeview2, gtk_entry_get_text(GTK_ENTRY(FB_entry1)));
}


void
on_FB_button8_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *FB_window3;
	GtkWidget *FB_entry2;
	GtkWidget *FB_label_supp_message;

	FB_window3 = lookup_widget(button,"FB_window3");
	FB_entry2 = lookup_widget(FB_window3,"FB_entry2");
	FB_label_supp_message = lookup_widget(FB_window3,"FB_label_supp_message");

	if(suppfb == 1){
		supprimer_menu(gtk_entry_get_text(GTK_ENTRY(FB_entry2)));
		gtk_label_set_text(GTK_LABEL(FB_label_supp_message),"menu supprimé avec succée!");
		gtk_widget_show(FB_label_supp_message);
	}else if(suppfb == 0){
		gtk_label_set_text(GTK_LABEL(FB_label_supp_message),"Cocher la confirmation de supprission!");
		gtk_widget_show(FB_label_supp_message);
	}
}


void
on_FB_checkbutton1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
		suppfb = 1;
	} else {
		suppfb = 0;
	}
}


void
on_FB_button9_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* FB_window3;
GtkWidget *FB_treeview1;
FB_window3=lookup_widget(button,"FB_window3");
gtk_widget_destroy(FB_window3);
GtkWidget* FB_window1;
FB_window1=create_FB_window1();
gtk_widget_show(FB_window1);
FB_treeview1 = lookup_widget(FB_window1,"FB_treeview1");
afficher_menu(FB_treeview1);
}


void
on_FB_radiobutton3_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
xfb=3;
}
}


void
on_FB_button10_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
menu m;
   GtkWidget *id;
   GtkWidget *type;
   GtkWidget *entree;
   GtkWidget *plat_principal;
   GtkWidget *dessert;
   GtkWidget *Jour;
   GtkWidget *Mois;
   GtkWidget *Annee;
   GtkWidget *FB_Combobox1;
   GtkWidget *FB_label21;
   GtkWidget *FB_label132;
   GtkWidget *outputMsg;
   GtkWidget *outputMsg2;
   int ajout,verif,test;
   char text[200];
   char text1[200];
   char text2[200];
  
  
FB_label21 = lookup_widget(button,"FB_label21");
id=lookup_widget(button,"FB_entry3");
strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(id)));
entree=lookup_widget(button,"FB_entry5");
strcpy(m.entree,gtk_entry_get_text(GTK_ENTRY(entree)));
plat_principal=lookup_widget(button,"FB_entry6");
strcpy(m.plat_principal,gtk_entry_get_text(GTK_ENTRY(plat_principal)));
dessert=lookup_widget(button,"FB_entry7");
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(dessert)));
/////////////////////////////////////////////////////////
Jour=lookup_widget(button,"FB_spinbutton1");
Mois=lookup_widget(button,"FB_spinbutton2");
Annee=lookup_widget(button,"FB_spinbutton3");
m.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
m.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
m.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
///////////////////////////////////////////////////////////
FB_Combobox1=lookup_widget(button,"FB_combobox1");
strcpy(m.qd,gtk_combo_box_get_active_text(GTK_COMBO_BOX(FB_Combobox1)));
///////////////////////////////////////////////////////////////////////////
if(xfb==1)
{strcpy(m.type,"p-dejeuner");}
else
if(xfb==2)
{strcpy(m.type,"dejeuner");}
else
if(xfb==3)
{strcpy(m.type,"diner");}

test=test_menu(m.id);

if (test==1)

    { strcpy (text1,"Identifiant déja existe !");
    outputMsg=lookup_widget(button,("label132"));
    GdkColor color;
    gdk_color_parse("red",&color);
    gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg),text1);
    }
else
        {
	ajouter_menu(m);
	strcpy (text2,"ajoutée avec succes");
    outputMsg2=lookup_widget(button,("FB_label21"));
    GdkColor color;
    gdk_color_parse("green",&color);
    gtk_widget_modify_fg(outputMsg2,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg2),text2);;
        }
}


void
on_FB_button11_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* FB_window4;
GtkWidget *FB_treeview1;
FB_window4=lookup_widget(button,"FB_window4");
gtk_widget_destroy(FB_window4);
GtkWidget* FB_window1;
FB_window1=create_FB_window1();
gtk_widget_show(FB_window1);
FB_treeview1 = lookup_widget(FB_window1,"FB_treeview1");
afficher_menu(FB_treeview1);
}


void
on_FB_radiobutton2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
xfb=2;
}
}


void
on_FB_radiobutton1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
xfb=1;
}
}


void
on_FB_radiobutton4_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
xfb=1;
}
}


void
on_FB_radiobutton5_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
xfb=2;
}
}

void
on_FB_radiobutton6_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
xfb=3;
}
}
void
on_FB_button13_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* FB_window5;
GtkWidget *FB_treeview1;
FB_window5=lookup_widget(button,"FB_window5");
gtk_widget_destroy(FB_window5);
GtkWidget* FB_window1;
FB_window1=create_FB_window1();
gtk_widget_show(FB_window1);
FB_treeview1 = lookup_widget(FB_window1,"FB_treeview1");
afficher_menu(FB_treeview1);
}


void
on_FB_button12_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{menu m;
   GtkWidget *id;
   GtkWidget *type;
   GtkWidget *entree;
   GtkWidget *plat_principal;
   GtkWidget *dessert;
   GtkWidget *Jour;
   GtkWidget *Mois;
   GtkWidget *Annee;
   GtkWidget *FB_Combobox2 ;
   
   //char text[200];

  
  
GtkWidget *FB_window5;

FB_window5=lookup_widget(button,"FB_window5");
id=lookup_widget(button,"FB_entry4");
strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(id)));
entree=lookup_widget(button,"FB_entry8");
strcpy(m.entree,gtk_entry_get_text(GTK_ENTRY(entree)));
plat_principal=lookup_widget(button,"FB_entry9");
strcpy(m.plat_principal,gtk_entry_get_text(GTK_ENTRY(plat_principal)));
dessert=lookup_widget(button,"FB_entry10");
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(dessert)));
/////////////////////////////////////////////////////////
Jour=lookup_widget(button,"FB_spinbutton4");
Mois=lookup_widget(button,"FB_spinbutton5");
Annee=lookup_widget(button,"FB_spinbutton6");
m.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
m.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
m.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
///////////////////////////////////////////////////////////
FB_Combobox2=lookup_widget(button,"FB_combobox2");
strcpy(m.qd,gtk_combo_box_get_active_text(GTK_COMBO_BOX(FB_Combobox2)));
///////////////////////////////////////////////////////////////////////////
if(xfb==1)
{strcpy(m.type,"p-dejeuner");}
else
if(xfb==2)
{strcpy(m.type,"dejeuner");}
else
if(xfb==3)
{strcpy(m.type,"diner");}

modifier_menu(m);}
/*{

char text[100];
GtkWidget *outputMsg;
GtkWidget *FB_window1;
GtkWidget *FB_window5;
GtkWidget *FB_treeview1;
GtkTreeSelection *selection;
GtkTreeModel *model;
GtkTreeIter iter;
	gchar *id;
	gchar *type;
	gchar *entree; 
	gchar *plat_principal; 
	gchar *dessert;
	gchar *Jour; 
        gchar *Mois;
        gchar *Annee;
	gchar *qd; 
        menu m;
      
	
GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*input5;
GtkWidget*input6;
GtkWidget*input7;
GtkWidget*input8;
GtkWidget*input9;
GtkWidget*input10;
GtkWidget*input11;

FB_window1=lookup_widget(button,"FB_window1");
FB_treeview1=lookup_widget(FB_window1,"FB_treeview1");

selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(FB_treeview1));

if(gtk_tree_selection_get_selected(selection,&model,&iter))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&id,1,&type,2,&entree,3,&plat_principal,4,&dessert,5,&Jour,6,&Mois,7,&Annee,8,&qd,-1);
	
	strcpy(m.id,id);
	strcpy(m.type,type);
	strcpy(m.entree,entree);
	strcpy(m.plat_principal,plat_principal);
	strcpy(m.dessert,dessert);
	m.Jour=Jour;
	m.Mois=Mois;
        m.Annee=Annee;
	strcpy(m.qd,qd);

gtk_widget_hide(FB_window1);
FB_window5=create_FB_window5();
gtk_widget_show(FB_window5);
input1=lookup_widget(FB_window5,"FB_entry4");
input2=lookup_widget(FB_window5,"FB_radiobutton4");
input3=lookup_widget(FB_window5,"FB_radiobutton5");
input4=lookup_widget(FB_window5,"FB_radiobutton6");
input5=lookup_widget(FB_window5,"FB_entry8");
input6=lookup_widget(FB_window5,"FB_entry9");
input7=lookup_widget(FB_window5,"FB_entry10");
input8=lookup_widget(FB_window5,"FB_spinbutton4");
input9=lookup_widget(FB_window5,"FB_spinbutton5");
input10=lookup_widget(FB_window5,"FB_spinbutton6");
input11=lookup_widget(FB_window5,"FB_combobox2");


          		

gtk_entry_set_text (GTK_ENTRY(input1),m.id);
gtk_entry_set_text (GTK_ENTRY(input5),m.entree);
gtk_entry_set_text (GTK_ENTRY(input6),m.plat_principal);
gtk_entry_set_text (GTK_ENTRY(input7),m.dessert);


gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8),m.Jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input9),m.Mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(input10),m.Annee);*/

//gtk_combo_box_set_text(GTK_COMBO_BOX(input11),m.qd);

//}

/*else
{
         strcpy (text,"veuillez selectionner l'utilisateur à modifier !");
         outputMsg=lookup_widget(button,("FB_label37"));
         GdkColor color;
         gdk_color_parse("red",&color);
         gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
         gtk_label_set_text(GTK_LABEL(outputMsg),text);
}*/



void
on_FB_treeview3_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *jour1;
	gchar *type1; 
	gchar *valeur; 
        dechets d;                                 
	FILE *f=NULL;


	GtkTreeModel *tree_model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(tree_model,&iter,path))
	{gtk_tree_model_get (GTK_LIST_STORE(tree_model),&iter,0,&jour1,1,&type1,2,&valeur,-1);


	d.jour1=jour1;
        d.type1=type1;
        strcpy(d.valeur,valeur);
	afficher_dechets(treeview);
}
void
on_FB_button14_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* FB_window1;
GtkWidget *FB_treeview1;
FB_window1=lookup_widget(button,"FB_window1");
gtk_widget_destroy(FB_window1);
GtkWidget* FB_window6;
FB_window6=create_FB_window6();
gtk_widget_show(FB_window6);
FB_treeview1 = lookup_widget(FB_window6,"FB_treeview1");
afficher_menu(FB_treeview1);
}
}

void
on_FB_button_ret_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* input;
GtkWidget* output;
GtkWidget* FB_window6;
GtkWidget *FB_treeview1;

FB_window6=lookup_widget(button,"FB_window6");
gtk_widget_destroy(FB_window6);
GtkWidget* FB_window1;
FB_window1=create_FB_window1();
gtk_widget_show(FB_window1);
FB_treeview1 = lookup_widget(FB_window1,"FB_treeview1");
afficher_menu(FB_treeview1);
}

