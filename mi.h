#include <stdlib.h>      // para us de exit
//#include <stdio_ext.h>   // para utiizar __fpurge
#include <string.h>
#include <ncurses.h>
#include <form.h>

#define ELEMENTOS 46
//#define FIL 180
//#define COL 4
#define COOR_IX 5
#define COOR_IY 1
#define ANCHO 1

//int wcx, wcy;

int vector45[ELEMENTOS];    // vector45: nombre_arreglo es apuntador al 1er elemento de la lista vector45[0]
int ind[ELEMENTOS];         // arreglo de indices, solo para vistocidad por pantalla
//int tablabase[FIL][COL];
//int matriz_coor[FIL][COL];
//int matriz180[FIL][COL];
//int matriz180_2[FIL][COL];
 

// PtotoTipos
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
//void inicializar_arreglo(int i, int *appia);
//int valida_uno(int nro);
//void imprimir_arreglo(int i, int *appia);
//void grabarvector_binario(int *appia, FILE *sufp);
//void recuperarMatriz(int sumatriz[][COL], FILE *sufp);
//void recuperarVector(int suvector[ELEMENTOS], FILE *sufp);
//void grabarmatriz_binario(int sumatriz[][COL], FILE *sufp);
