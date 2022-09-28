/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *hkwindowgestion;
  GtkWidget *window1_gestion;
  GtkWidget *hh_window_produits;
  GtkWidget *RE_window1_gestion;
  GtkWidget *FB_window1;
  GtkWidget *MNaccueil;
  GtkWidget *MNauthentification;
  GtkWidget *MNmenu;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  /* MNaccueil = create_MNaccueil();
  gtk_widget_show(MNaccueil);
  window1_gestion = create_window1_gestion();
  gtk_widget_show(window1_gestion);
  hkwindowgestion = create_hkwindowgestion ();
  gtk_widget_show (hkwindowgestion);
  hh_window_produits = create_hh_window_produits();
  gtk_widget_show(hh_window_produits);
  RE_window1_gestion = create_RE_window1_gestion ();
  gtk_widget_show (RE_window1_gestion); 
  FB_window1 = create_FB_window1();
  gtk_widget_show(FB_window1);*/
 // MNauthentification = create_MNauthentification();
 // gtk_widget_show(MNauthentification);

  MNmenu = create_MNmenu();
  gtk_widget_show(MNmenu);
	

  gtk_main ();
  return 0;
}
