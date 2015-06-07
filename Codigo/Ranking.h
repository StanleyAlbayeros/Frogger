#ifndef _RANKING
#define _RANKING

#include <string.h>

const int MAX_NOM_JUGADOR = 15;
const int MAX_MILLORSJUGADORS = 5;
const char NOM_FITXER[20] = "Puntuacio.txt"; 

// Registre que serveix per guardar la puntuació d'un jugador
typedef struct
{
  char nom[MAX_NOM_JUGADOR];
  int puntuacio;
}
tJugador;

class cRanking{

private:
	tJugador millorsJugadors[MAX_MILLORSJUGADORS];
public:
	void InicialitzarTaulaMillorJugadors();
	void LlegirPuntuacions();
	void EscriurePuntuacions();
	int  EsMillorPuntuacio( int punts);
	void DesplacarArray( int posicio);
	void EmplenarPosicioArray(int posicio, int punts);
	void EscriuRanking();
};


#endif