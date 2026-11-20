/*
    Fichier:  code.alarme.h
    Auteur:   Alain Boudreault
    Date:     2021.11.21
    ---------------------------------------------------------
    Description:  Définir un type enum à utiliser pour les
                  différents états du système d'alarme.

                  Note: Inclure ce fichier dans le dossier de
                        votre projet.

                        Puis, programmer la syntaxe suivante 
                        pour utiliser ce type:

                        codesAlarme code;
                        ...
                        code = evenement_systeme_enligne;
    ---------------------------------------------------------
    M-A-J: 2022.11.11 A.B. - Ajout de 'evenement_nb_codes'
    ---------------------------------------------------------
*/

// S'assurer que ce fichier ne sera inclus qu'une seule fois lors de la compilation du projet
#ifndef LES_CODES_ERREUR_H
#define LES_CODES_ERREUR_H
enum codesAlarme {
  evenement_temperature_depassee,
  evenement_dectection_mouvement,
  evenement_code_invalide,
  evenement_code_valide,
  evenement_alarme_active,
  evenement_alarme_inactive,
  evenement_systeme_enligne,
  evenement_nb_codes
};

#endif // LES_CODES_ERREUR_H_ _
