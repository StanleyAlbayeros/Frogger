#pragma once
#include "Area.h"
#include "lib\Grafic.h"


// nº de píxels que es desplaça el cotxe a cada moviment del nivell 1
#define DESPLACAMENT_COTXE 3

class Cotxe
{
public:
	Cotxe();
	Cotxe(Grafic grafic, int velocitat, bool direccio);
	~Cotxe();
	Area getAreaOcupada();
	void dibuixa();
	void mou();
	void mouAIniciCarril(int posicioY);
	bool canSpawn();

private:
	Grafic m_grafic;
	bool m_direccio;
	int m_posicioX;
	int m_posicioY;
	int m_velocitat;
	int m_contador;
};

