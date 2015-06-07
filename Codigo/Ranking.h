#ifndef _RANKING
#define _RANKING
#include <string.h>

const int MAX_NOM_JUGADOR = 15;
const int MAX_MILLORSJUGADORS = 10;
const char NOM_FITXER[20] = "Ranking.txt"; 

// struct para guardar la puntuacion maxima
typedef struct
{
  char nom[MAX_NOM_JUGADOR];
  int puntuacio;
}
tJugador;

class Ranking{

private:
	tJugador millorsJugadors[MAX_MILLORSJUGADORS];
public:
	void InicialitzarTaulaTopPlayers();
	void LlegirPuntuacions();
	void EscriurePuntuacions();
	int  EsMillorPuntuacio( int punts);
	void DesplacarArray( int posicio);
	void EmplenarPosicioArray(int posicio, int punts);
	void EscriuRanking();
};


#endif