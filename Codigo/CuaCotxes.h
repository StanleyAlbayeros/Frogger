#pragma once
#include "Cua.h"
#include "Iterador.h"
#include "Node.h"

class CuaCotxes
{
public:
	CuaCotxes();
	CuaCotxes(Grafic grafic, int velocitat, bool direccio, int iniciY, int spawn);
	bool tenimColisioAmbGranota(Area areaGranota);
	void mouCua(Area areaTotal, int temps);
	void dibuixaCua();
	~CuaCotxes(void);

private:
	Cua m_cua;
	Cotxe m_cotxe;
	Cotxe m_nouCotxe;
	Grafic m_grafic;
	bool m_direccio;
	int m_posicioLiderX;
	int m_posicioLiderY;
	bool m_spawn;
	int m_velocitat;
	int m_contador;
	int m_iniciY;
};

