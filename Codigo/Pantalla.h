#pragma once
#include "Area.h"
#include "lib\Grafic.h"
#include "Cova.h"
#include "Cotxe.h"
#include "Granota.h"

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
	void dibuixa(int dir, int count);
	void mouGranota(int direccio);
	bool esGranotaDinsCova();
	void mouCotxes(); //JUGUETEANDO CON MAS COCHES!!!
	bool haMortLaGranota();
private:
	Grafic m_graficFons;
	Grafic m_graficCova;
	
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

	Area m_areaTotal;
	Cova m_cova;
	Granota m_granota;
	Cotxe m_cotxe1;
	Cotxe m_cotxe2;
	Cotxe m_cotxe3;
	Cotxe m_cotxe4;
	Cotxe m_cotxe5;
	int m_iniciCarrilsY;
	int m_nCarrils1;
	int m_nCarrils2;
	int triaCarril(int numcotxe);
	bool espaiPermes(Area area);
};

