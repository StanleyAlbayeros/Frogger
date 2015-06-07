#include "CuaCotxes.h"
#include "lib\Grafic.h"
#include <time.h>
#include <ctime>
#include <cstdlib>

CuaCotxes::CuaCotxes()
{
}


CuaCotxes::CuaCotxes(Grafic grafic, int velocitat, bool direccio, int iniciY, int spawn)
{
	m_grafic = grafic;
	m_velocitat = velocitat;
	m_direccio = direccio;
	m_iniciY = iniciY;
	m_spawn=spawn;
	//creamos la cola y una instancia de coche que copiariemos para cada nodo de la cola
	m_cua=Cua();
	m_cotxe = Cotxe(m_grafic, m_velocitat, m_direccio, m_iniciY);
	m_nouCotxe = Cotxe(m_grafic, m_velocitat, m_direccio, m_iniciY);
	//m_cua.afegeix(m_cotxe);
	//m_cua.afegeix(m_cotxe);
}


void CuaCotxes::mouCua(Area areaTotal, int temps)
{
	bool spawn = m_spawn;

	if (m_cua.esBuida())
		{
			m_cua.afegeix(m_nouCotxe);
		}
	





	//creo un iterador para recorrer la cola e ir moviendo los coches
	Iterador current = m_cua.getInici();
	while (!current.esNul())
		{
			Cotxe tmp2 = current.getElement();
			///////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////        MOVIMIENTO DE COCHES       //////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////////////////////
			/*if (!areaTotal.solapa(tmp2.getAreaOcupada()))
				{
					tmp2.mouAIniciCarril(m_iniciY);
				}			
			*/
			if (areaTotal.solapa(tmp2.getAreaOcupada()))
				{
					tmp2.mou();
					current.setElement(tmp2);

				}
				
			///////////////////////////////////////////////////////////////////////////////////////////////////
			current.seguent();
		}
		

		if ((temps%15 == 1)&&(spawn))
		{
			Cotxe tmp;
			tmp = m_cua.getUltim();
			
			if (tmp.canSpawn() )
			{
				m_cua.afegeix(m_nouCotxe);
				spawn = false;
			}
		}	

		Cotxe tmp3;
		tmp3 = m_cua.getPrimer();
		if (!areaTotal.solapa(tmp3.getAreaOcupada()))
			{
			
				if ((m_cua.getUltim().canSpawn())&&(m_cua.numElements() <= 4))
					{
						m_cua.afegeix(m_nouCotxe);
					}
				m_cua.treu();
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

bool CuaCotxes::tenimColisioAmbGranota(Area areaGranota)
{
	bool tenimColisio = false;
	Iterador current = m_cua.getInici();
	while (!current.esNul())
	{
		Cotxe& tmp = current.getElement();

		///////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////        DIBUJAMOS LOS COCHES       //////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////

		if ((tmp.getAreaOcupada().solapa(areaGranota))
		|| (areaGranota.solapa(tmp.getAreaOcupada())))
		{
			tenimColisio = true;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////
		
		current.seguent();
	}

	return tenimColisio;

}


CuaCotxes::~CuaCotxes(void)
{
	m_cua.~Cua();
}
