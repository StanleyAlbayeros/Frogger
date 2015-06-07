#pragma once
#include "Area.h"
#include "lib\Grafic.h"

// Definicio de la velocitat dels objectes bonus
#define DESPLACAMENT_BONUS 2


class Bonus
{
public:
	Bonus();
	Bonus(Grafic grafic);
	~Bonus();
	Area getAreaOcupada();
	void dibuixa();
	void mou(int posicio, int direccio);
	void mouAPosicioInicial(int posicioX, int posicioY);
private:
	Grafic m_grafic;
	int m_posicioX;
	int m_posicioY;
	int m_contador;
};