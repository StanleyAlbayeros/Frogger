#pragma once
#include "Area.h"
#include "lib\Grafic.h"

// nº de píxels que es desplaça la granota a cada moviment
#define DESPLACAMENT_GRANOTA 5

class Granota
{
public:
	Granota();
	Granota(Grafic grafic, int posicioInicialX, int posicioInicialY);
	~Granota();
	Area getAreaOcupada();
	void dibuixa();
	void mouAmunt();
	void mouAvall();
	void mouDreta();
	void mouEsquerra();
	void mouAPosicioInicial();

private:
	Grafic m_grafic;
	int m_posicioX;
	int m_posicioY;
	int m_posicioInicialX;
	int m_posicioInicialY;
};

