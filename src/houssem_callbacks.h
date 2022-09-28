#include <gtk/gtk.h>


void
on_khbuttonajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonafficher_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_hkbuttonsupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttonrechercher_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttonmodifier_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttonajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttonvaliderajout_clicked        (GtkWidget        *button,
                                        gpointer         user_data);

void
on_hkbuttonvaliderm_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkradiobuttonmale_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hkradiobuttonfemale_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
void
on_hkradiobuttonmalem_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hkradiobuttonfemalem_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_hkradiobutton3mois_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hkradiobutton6mois_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hkradiobutton9mois_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hkradiobutton9moism_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hkradiobutton6moism_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hkradiobutton3moism_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_hkwindowmodifier_focus_in_event     (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_hkwindowmodifier_destroy            (GtkObject       *object,
                                        gpointer         user_data);

void
on_hktreeviewgestion_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_hkbuttonretour_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttonretourm_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttontache2_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttoncalcul_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkcheckbuttonfemmes_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hkcheckbuttonhommes_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hkbuttonactualiser_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_hkbuttonmail_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttonannulermail_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttonconfmail_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttonannulsupp_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttonvalidsupp_clicked           (GtkButton       *button,
                                        gpointer         user_data);


gboolean
on_hktreeviewgestion_focus_in_event    (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

gboolean
on_hkwindowgestion_focus_in_event      (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_button_deconnexion_gestion_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajout_gestion_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_gestion_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_gestion_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rechercher_gestion_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_hors_norme_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rechercher_liste_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_liste_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_supp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_supprimer_supprission_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_suppression_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_temp_ajout_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_fumee_ajout_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_debit_ajout_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajouter_ajout_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_ajout_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_debit_modif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_fum_modif_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_temp_moodif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_modifier_modification_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_modification_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_hors_norme_clicked    (GtkButton       *button,
                                        gpointer         user_data);
