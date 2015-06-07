#include "CuaCotxes.h"
#include <time.h>

CuaCotxes::CuaCotxes(Grafic grafic, int velocitat, bool direccio)
{
	m_grafic = grafic;
	m_velocitat = velocitat;
	m_direccio = direccio;
	//creamos la cola y una instancia de coche que copiariemos para cada nodo de la cola
	m_cua=Cua();
	m_cotxe = Cotxe(m_grafic, m_velocitat, m_direccio);
	m_nouCotxe = Cotxe(m_grafic, m_velocitat, m_direccio);
	m_cua.afegeix(m_cotxe);
}


void CuaCotxes::mouCua(Area areaTotal, int iniciCarrilY)
{
	//creo un coche temporal, le asigno el último de la lista y miro si puedo spawnear un segundo coche
	Cotxe tmp;
	tmp = m_cua.getUltim();
	
	if (tmp.canSpawn())
		{
			m_cua.afegeix(m_nouCotxe);
		}

	//creo un iterador para recorrer la cola e ir moviendo los coches
	Iterador current = m_cua.getInici();
	while (!current.esNul())
		{
			Cotxe& tmp2 = current.getElement();
			///////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////        MOVIMIENTO DE COCHES       //////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////
			if (areaTotal.solapa(tmp2.getAreaOcupada()))
				{
					tmp2.mou();
				}
			if (!areaTotal.solapa(tmp2.getAreaOcupada()))
				{
					tmp2.mouAIniciCarril(iniciCarrilY);
				}
			///////////////////////////////////////////////////////////////////////////////////////////////////
			current.seguent();
		}

	Cotxe tmp3;
	tmp3 = m_cua.getPrimer();
	if (!areaTotal.solapa(tmp3.getAreaOcupada()))
		{
			m_cua.treu();
			m_cua.afegeix(m_nouCotxe);
		}

}


void CuaCotxes::dibuixaCua()
{
	Iterador current = m_cua.getInici();
	while (!current.esNul())
	{
		Cotxe& tmp = current.getElement();

		///////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////        DIBUJAMOS LOS COCHES       //////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////

		tmp.dibuixa();

		///////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////



		current.seguent();
	}

}




CuaCotxes::~CuaCotxes(void)
{
	m_cua.~Cua();
}
