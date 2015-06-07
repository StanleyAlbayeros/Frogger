#pragma once
#include "Area.h"
#include "lib\Grafic.h"

// Definicio de la velocitat dels objectes bonus
#define DESPLACAMENT_BONUS 1
#define DIRECCIO_INICIAL 0


class Bonus
{
public:
	Bonus();
	Bonus(Grafic grafic);
	~Bonus();
	Area getAreaOcupada();
	void dibuixa();
	void setCoordenadas(int X, int Y);
	int getDireccio();
	void setDireccio(int direccio);
private:
	Grafic m_grafic;
	int m_posicioX;
	int m_posicioY;
	int m_contador;
	int m_direccio;
};