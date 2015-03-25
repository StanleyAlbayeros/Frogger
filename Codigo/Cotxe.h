#pragma once
#include "Area.h"
#include "lib\Grafic.h"

// nº de píxels que es desplaça el cotxe a cada moviment del nivell 1
#define DESPLACAMENT_COTXE 5

class Cotxe
{
public:
	Cotxe();
	Cotxe(Grafic grafic, int velocitat);
	~Cotxe();
	Area getAreaOcupada();
	void dibuixa();
	void mou();
	void mouAIniciCarril(int posicioX, int posicioY);
private:
	Grafic m_grafic;
	int m_posicioX;
	int m_posicioY;
	int m_velocitat;
};

