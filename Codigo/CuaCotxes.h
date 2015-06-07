#include "Cua.h"
#include "Iterador.h"
#include "Node.h"

class CuaCotxes
{
public:
	CuaCotxes(Grafic grafic, int velocitat, bool direccio, int iniciY);
	bool getColisions(Area area);
	void mouCua(Area areaTotal, int iniciCarrilY);
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
	int m_velocitat;
	int m_contador;
	int m_iniciY;
};

