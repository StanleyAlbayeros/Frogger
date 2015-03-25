/**
 * Joc interactiu de la granota.
 */

#include <conio.h>      /* getch */ 
#include <stdio.h>      /* printf */
#include <time.h>       /* time */
#include <windows.h>

//========================================================================
// Inici del taulell respecte la cantonada superior esquerre

const int INICI_X = 0; //TODO els cotxes comencen aqui
const int INICI_Y = 80;

//========================================================================
// Fi del taulell respecte la cantonada superior esquerre
const int FI_X = 600; //TODO els cotxes arriben fins aquí
const int FI_Y = 390;

//========================================================================
// Desplaçament inicial de la granota respecte al final del taulell
const int INICI_Y_GRANOTA = FI_Y + 5;

int juga(int Nivell);

void mouGranota(int &x, int &y, int despX, int despY);

void mouCotxe(int &x, int &y);