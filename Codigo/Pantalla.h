#pragma once
#include "Area.h"
#include "lib\Grafic.h"
#include "Cova.h"
#include "Vehicle.h"
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
	void mouVehicle();
	bool haMortLaGranota();
private:
	Grafic m_graficFons;
	Grafic m_graficCova;
	Grafic m_graficGranotaAmunt;
	Grafic m_graficVehicle;
	Area m_areaTotal;
	Cova m_cova;
	Granota m_granota;
	Vehicle m_vehicle;
	int m_iniciCarrilsY;
	int m_nCarrils;
	int triaCarril();
	bool espaiPermes(Area area);
};

