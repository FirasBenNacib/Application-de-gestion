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

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_hh_rechercher_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_prod_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_rupture_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_mail_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_supp_oui_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hh_supp_valider_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_affich_supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_fruit_a_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_liquides_a_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ingredients_a_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_legume_a_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_viande_a_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_hh_ajout_prod_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_annuler_ajout_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_affich_ajout_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_modif_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_modif_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_affich_modif_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_rech_valider_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_recherche_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_rupture_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_rupture_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_mail_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_valider_mail_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_annuler_mail_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_treeview1_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_RE_button_deconnexion_gestion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_Ges_service_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_button_ajout_gestion_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_button_modifier_gestion_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_button_rechercher_gestion_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_button_supprimer_gestion_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_button_rechercher_liste_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_button_retour_liste_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_checkbutton_supp_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RE_button_retour_suppression_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_button_supprimer_suppression_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_radiobutton_temp_ajout_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RE_radiobutton_fumee_ajout_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RE_button_retour_ajout_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_button_ajouter_ajout_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_radiobutton_temp_moodif_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RE_radiobutton_fum_modif_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RE_button_modifier_modification_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_button_retour_modification_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_Service_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_RE_retour_dash_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_button1_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_button2_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_button3_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_button4_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_button5_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_button7_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_button6_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_checkbutton1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FB_button8_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_button9_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_radiobutton1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FB_radiobutton2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FB_radiobutton3_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FB_button10_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_button11_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_radiobutton4_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FB_radiobutton5_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FB_radiobutton6_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FB_button13_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_button12_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_FB_treeview3_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_FB_button_ret_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_MNtreeview1_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_MN_ajouteracc_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_modifieracc_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_supprimeracc_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_rechercheracc_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_afficheraccu_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_buttontache2_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_deconnexion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_validerajout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_retourajout_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_MNradio_femelle_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MNradio_male_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MN_radiofemellemodif_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MN_radiomalemodif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MN_retourmodifier_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_validermodif_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_checkconfirm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_MN_buttonsupprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_retoursupprimer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_MNtreeview2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_MN_chercherbutton_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_retourchercher_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_MNtreeview3_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_MN_retourtache2_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_login_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_entryauth_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_entrytdashbord_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_ajouteracc_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_modifieracc_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_MN_supprimeracc_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_hkbuttondeconnecte_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_hh_button_deconnexion_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_auth_tomenu_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_firasbutton_retour_menu_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_nour_tree_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_firas_tree_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_hamza_tree_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_calcul_dashboard_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_dashoboard_retourwind_clicked       (GtkButton       *button,
                                        gpointer         user_data);
