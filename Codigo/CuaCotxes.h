#include "Cua.h"
#include "Iterador.h"
#include "Node.h"

class CuaCotxes
{
public:
	CuaCotxes(Grafic grafic, int velocitat, bool direccio);
	~CuaCotxes(void);

private:
	Grafic m_grafic;
	bool m_direccio;
	int m_posicioX;
	int m_posicioY;
	int m_velocitat;
	int m_contador;
};

