#include "CuaCotxes.h"

CuaCotxes::CuaCotxes(Grafic grafic, int velocitat, bool direccio)
{
	m_grafic = grafic;
	m_velocitat = velocitat;
	m_direccio = direccio;
	//creamos la cola y una instancia de coche que copiariemos para cada nodo de la cola
	m_cua=Cua();
	m_cotxe = Cotxe(m_grafic, m_velocitat, m_direccio);
}




CuaCotxes::~CuaCotxes(void)
{
	m_cua.~Cua();
}
