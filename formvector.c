/*
    Formulario Uso Basico y atachados a una Ventana
*/
#include "mi.h"

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);


int main()
{ 
   FIELD *field[ELEMENTOS];
   FORM *my_form;
   WINDOW *my_form_win;
   int ch, i, fil, col;

   /* Initialize curses */
   initscr();
   start_color();
   cbreak();
   noecho();
   keypad(stdscr, TRUE);

   /* Initialize few color pairs */
   init_pair(1, COLOR_WHITE, COLOR_BLUE);
   init_pair(2, COLOR_WHITE, COLOR_BLUE);
   
   
   /* Initialize the fields */
   fil = col = 0;
   for(i = 0; i < ELEMENTOS - 1; ++i)
   {
          if (i==9){
             fil = fil + 8;
             col = 1;
          } 
          if (i==17){
             fil = fil + 8;
             col = 2;
          } 
          if (i==24){
             fil = fil + 8;
             col = 3;
          }              
          if (i==30){
             fil = fil + 8;
             col = 4;
          }
          if (i==35){
             fil = fil + 8;
             col = 5;
          }
          if (i==39){
             fil = fil + 8;
             col = 6;
          }
          if (i==42){
             fil = fil + 8;
             col = 7;
          }
          if (i==44){
             fil = fil + 8;
             col = 8;
          }
          
          field[i] = new_field(1, ANCHO, COOR_IY + col, COOR_IX + fil, 0, 0);
          col = col + 1; 
   } 
   field[ELEMENTOS-1] = NULL;

   
   /* Set field options */
   for (i=0; i<ELEMENTOS; ++i)
   {
          set_field_back(field[i], A_UNDERLINE);               /* Print a line for the option */
          field_opts_on(field[i], O_AUTOSKIP);       
   }       
  
   /* Create the form and post it */
   my_form = new_form(field);
   
   /* Calculate the area required for the form */
   fil = col = 9; 
 
   scale_form(my_form, &fil, &col);

   /* Create the window to be associated with the form */
   my_form_win = newwin(LINES-5, COLS-1, 4, 1);
   keypad(my_form_win, TRUE);

  
   /* Set main window and sub window */
   set_form_win(my_form, my_form_win);
   set_form_sub(my_form, derwin(my_form_win, fil, col, 2, 2)); 

   /* Print a border around the main window and print a title */
   box(my_form_win, 0, 0);
   
   /* Initialize the field  en el Formulario */
    int indice = 0;
    col =  fil = 0;
    for(i = 0; i < ELEMENTOS - 1; ++i)
    {
         indice=indice+1;
         
         if (indice==10) {
             indice=(indice+(indice/10)+1);
             col = col + 8;
             fil = (indice/10);
          }   
 
          if (indice==20) {
             indice=(indice+(indice/10)+1);
             col = col + 8;
             fil = (indice/10);
          }   
          if (indice==30) {
             indice=(indice+(indice/10)+1);
             col = col + 8;
             fil = (indice/10);
          }

           if (indice==40) {
             indice=(indice+(indice/10)+1);
             col = col + 8;
             fil = (indice/10);
          }
          if (indice==50) {
             indice=(indice+(indice/10)+1);
             col = col + 8;
             fil = (indice/10);
          }
          if (indice==60) {
             indice=(indice+(indice/10)+1);
             col = col + 8;
             fil = (indice/10);
          }
          if (indice==70) {
             indice=(indice+(indice/10)+1);
             col = col + 8;
             fil = (indice/10);
          }
          if (indice==80) {
             indice=(indice+(indice/10)+1);
             col = col + 8;
             fil = (indice/10);
          }

          mvwprintw(my_form_win, fil,  col,  "%d: ",  indice);
    }
   wrefresh(my_form_win);   


   print_in_middle(my_form_win, 1, 0, col+ 4, "My Form", COLOR_PAIR(1));
   
   post_form(my_form);
   wrefresh(my_form_win);

   mvprintw(LINES-3, 6, "Use Flecha Arriba, Flecha Abajo para desplazarse ->F10<-, para Salir...");
   refresh();

   /* Loop through to get user requests */
   while((ch = wgetch(my_form_win)) != KEY_F(10))

   { switch(ch)
              {  case KEY_DOWN:
                      /* Go to next field */
                      form_driver(my_form, REQ_NEXT_FIELD);
                      /* Go to the end of the present buffer */
                      /* Leaves nicely at the last character */
                      form_driver(my_form, REQ_END_LINE);
                  break;

                  case KEY_UP:
                       /* Go to previous field */
                       form_driver(my_form, REQ_PREV_FIELD);
                       form_driver(my_form, REQ_END_LINE);
                  break;

                  default:
                       /* If this is a normal character, it gets */
                       /* Printed */
                       form_driver(my_form, ch);
                  break;
               }
    }

    /* Un post form and free the memory */
    unpost_form(my_form);
    free_form(my_form);
    free_field(field[0]);
    free_field(field[1]);

    endwin();
    return 0;
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{ 
    int length, x, y;
    float temp;
    
    if(win == NULL)
       win = stdscr;
    
    getyx(win, y, x);
      
    if(startx != 0)
       x = startx;
    if(starty != 0)
       y = starty;
    if(width == 0)
       width = 80;

    length = strlen(string);
    temp = (width - length)/ 2;
    x = startx + (int)temp;
    wattron(win, color);
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, color);
    refresh();
}
