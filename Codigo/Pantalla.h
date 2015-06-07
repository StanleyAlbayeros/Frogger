#pragma once
#include "Area.h"
#include "lib\Grafic.h"
#include "Cova.h"
#include "Cotxe.h"
#include "Granota.h"
#include "CuaCotxes.h"

// Inici del taulell respecte la cantonada superior esquerre
#define INICI_X 0
#define INICI_Y 0

// Fi del taulell respecte la cantonada superior esquerre
#define FI_X 600
#define FI_Y 450

#define AMUNT 0
#define AVALL 1
#define DRETA 2
#define ESQUERRA 3

class Pantalla
{
public:
	Pantalla();
	~Pantalla();
	void inicia(int nivell);
	void reset(int nivell);
	void dibuixaCovesOcupades();
	void dibuixa(int dir, int count);
	void mouGranota(int direccio);
	int esGranotaDinsCova();
	void mouCotxes(int t2);
	bool haMortLaGranota();
	void mostraVides(int life, bool onedown);
	void GameOver(int nopls);
	void LevelUp(int yespls);
	void puntos100(int pointsup, int suma);
	void tiemporestante(int tiempo, int tempmax);
	void puntuacion(int puntos);

private:
	Grafic m_graficFons;
	Grafic m_graficCova;
	Grafic m_graficCovaOcupada;
	
	Grafic m_graficGranotaAmunt;
	Grafic m_graficGranotaAvall;
	Grafic m_graficGranotaEsquerra;
	Grafic m_graficGranotaDreta;

	Grafic m_graficGranotaAmunt2;
	Grafic m_graficGranotaAvall2;
	Grafic m_graficGranotaEsquerra2;
	Grafic m_graficGranotaDreta2;

	Grafic m_graficCotxe1;
	Grafic m_graficCotxe2;
	Grafic m_graficCotxe3;
	Grafic m_graficCotxe4;
	Grafic m_graficCotxe5;

	Grafic m_GameOver1;
	Grafic m_GameOver2;
	Grafic m_GameOver3;
	Grafic m_GameOver4;
	Grafic m_GameOver5;

	Grafic m_graficPoints100;

	Grafic m_LevelUp1;
	Grafic m_LevelUp2;
	Grafic m_LevelUp3;
	Grafic m_LevelUp4;
	Grafic m_LevelUp5;

	Grafic m_graficNum0;
	Grafic m_graficNum1;
	Grafic m_graficNum2;
	Grafic m_graficNum3;
	Grafic m_graficNum4;
	Grafic m_graficNum5;
	Grafic m_graficNum6;
	Grafic m_graficNum7;
	Grafic m_graficNum8;
	Grafic m_graficNum9;

	Area m_areaTotal;

	Cova m_cova1;
	Cova m_cova2;
	Cova m_cova3;
	Cova m_cova4;
	Cova m_cova5;

	Granota m_granota;

	CuaCotxes m_cuaCotxes1;
	CuaCotxes m_cuaCotxes2;
	CuaCotxes m_cuaCotxes3;
	CuaCotxes m_cuaCotxes4;
	CuaCotxes m_cuaCotxes5;

	int m_iniciCarrilsY;
	int m_nCarrils1;
	int m_nCarrils2;
	int triaCarril(int numcotxe);
	bool m_randomCotxe [4];
	bool espaiPermes(Area area);
	int m_temps[2]; // digitos del tiempo
};

