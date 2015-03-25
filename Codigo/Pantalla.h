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
	void dibuixa();
	void mouGranota(int direccio);
	bool esGranotaDinsCova();
	void mouCotxe();
	bool haMortLaGranota();
private:
	Grafic m_graficFons;
	Grafic m_graficCova;
	Grafic m_graficGranotaAmunt;
	Grafic m_graficCotxe;
	Area m_areaTotal;
	Cova m_cova;
	Granota m_granota;
	Cotxe m_cotxe;
	int m_iniciCarrilsY;
	int m_nCarrils;
	int triaCarril();
	bool espaiPermes(Area area);
};

