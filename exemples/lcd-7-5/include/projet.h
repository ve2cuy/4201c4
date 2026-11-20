/*****************************************/
#define   UART_VITESSE          115200
#define   BOUTON                2
#define   BOUTON_DELAI_REBOND   5
#define   DELAI_MSG_DEBUT       1000
#define   LCD_DELAI             50
#define   LCD_NB_LIGNE          2
#define   LCD_NB_COLONNE        16
#define   LCD_LIGNE1            0
#define   LCD_LIGNE2            1
#define   LCD_LIGNE3            2
#define   LCD_PREMIERE_COLONNE  0
#define   LCD_POSITION_COMPTEUR 10
#define   LCD_ADRESSE_I2C       0x27
#define   LCD_POS_COL_MENU      0
#define   LCD_POS_LIG_MENU      0

#define   MENU_POS_OPTION_1     LCD_POS_COL_MENU + 0
#define   MENU_POS_OPTION_2     LCD_POS_COL_MENU + 6
#define   MENU_POS_OPTION_3     LCD_POS_COL_MENU + 12

#define   MSG_CHOIX_MENU_SELECTIONNE "Choix --> Menu"

/*****************************************/

enum  optionMenu {
  menu1,
  menu2,
  menu3
};
