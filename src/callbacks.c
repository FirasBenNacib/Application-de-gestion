#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

//#include "callbacks.h"
#include "hamzacallbacks.h"
#include "houssem_callbacks.h"
#include "nada_callbacks.h"
#include "rayacallbacks.h"
#include "firascallbacks.h"
#include "nourcallbacks.h"
#include "interface.h"
#include "support.h"
#include "houssem_fonction.h"
/* #include "nada_fonction.h"
#include "hamzafonction.h"
#include "rayafonction.h" */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>






void
on_hkbuttondeconnecte_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* hkwindowgestion;
GtkWidget* MNauthentification;


hkwindowgestion=lookup_widget(button,"hkwindowgestion");
gtk_widget_destroy(hkwindowgestion);
MNauthentification=lookup_widget(button,"MNauthentification");
MNauthentification=create_MNauthentification();
gtk_widget_show(MNauthentification);
}


void
on_hh_button_deconnexion_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* hhwind;
GtkWidget* MNauthentification;


hhwind=lookup_widget(button,"hh_window_produits");
gtk_widget_destroy(hhwind);
MNauthentification=lookup_widget(button,"MNauthentification");
MNauthentification=create_MNauthentification();
gtk_widget_show(MNauthentification);
}


void
on_button_retour_auth_tomenu_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* MNauthentification;
GtkWidget* MNmenu;


MNauthentification=lookup_widget(button,"MNauthentification");
gtk_widget_destroy(MNauthentification);
MNmenu=lookup_widget(button,"MNmenu");
MNmenu=create_MNmenu();
gtk_widget_show(MNmenu);
}


void
on_firasbutton_retour_menu_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* FB_window1;
GtkWidget* MNauthentification;


FB_window1=lookup_widget(button,"FB_window1");
gtk_widget_destroy(FB_window1);
MNauthentification=lookup_widget(button,"MNauthentification");
MNauthentification=create_MNauthentification();
gtk_widget_show(MNauthentification);
}


void
on_nour_tree_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_firas_tree_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_hamza_tree_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_calcul_dashboard_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
///////////////////raya
        int result;
char res[120];
          char text[200] ;
GtkWidget *outputMsg;
GtkWidget *rayalabel124;



     result = service_plus();

if(result == 1){


    strcpy(text,"Le sevice le plus reclamé est Hebergement! ");
    outputMsg= lookup_widget(button,"rayalabel124");
    GdkColor color;
    gdk_color_parse("green",&color);
    gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg),text);
}

else {strcpy(text,"Le sevice le plus reclamé Restauration! ");
    outputMsg= lookup_widget(button,"rayalabel124");
    GdkColor color;
    gdk_color_parse("green",&color);
    gtk_widget_modify_fg(outputMsg,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(outputMsg),text);

}


////////////////////houssem

char fich[20] = "etudiants.txt";
char niv111[20] , niv222[20] , niv333[20],niv444[20],niv555[20];
//etudiant e;


GtkWidget* houssemniv11;
houssemniv11 = lookup_widget(button,"houssemniv11");
sprintf(niv111,"%d",calcule_etudiants_niveau(fich,"1"));
gtk_label_set_text(GTK_LABEL(houssemniv11), niv111);
GtkWidget* houssemniv22;
houssemniv22 = lookup_widget(button,"houssemniv22");
sprintf(niv222,"%d",calcule_etudiants_niveau(fich,"2"));
gtk_label_set_text(GTK_LABEL(houssemniv22),niv222);
GtkWidget* houssemniv33;
houssemniv33 = lookup_widget(button,"houssemniv33");
sprintf(niv333,"%d",calcule_etudiants_niveau(fich,"3"));
gtk_label_set_text(GTK_LABEL(houssemniv33),niv333);
GtkWidget *houssemniv44;
houssemniv44 = lookup_widget(button,"houssemniv44");
sprintf(niv444,"%d",calcule_etudiants_niveau(fich,"4"));
gtk_label_set_text(GTK_LABEL(houssemniv44),niv444);
GtkWidget *houssemniv55;
houssemniv55 = lookup_widget(button,"houssemniv55");
sprintf(niv555,"%d",calcule_etudiants_niveau(fich,"5"));
gtk_label_set_text(GTK_LABEL(houssemniv55),niv555);

//
}


void
on_dashoboard_retourwind_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* MNmenu;
GtkWidget* dashboard_window_int;


dashboard_window_int=lookup_widget(button,"dashboard_window_int");
gtk_widget_destroy(dashboard_window_int);
MNmenu=lookup_widget(button,"MNmenu");
MNmenu=create_MNmenu();
gtk_widget_show(MNmenu);

}

