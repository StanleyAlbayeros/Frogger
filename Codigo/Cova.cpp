#include "Cova.h"
#include "Granota.h"

/**
 * Constructor per defecte.
 */
Cova::Cova()
{
}

/**
 * Constructor de la cova.
 * Nota: Aquesta cova és imaginària. El seu interior ocupa tota l'amplada de la pantalla, no té cap paret que faci d'obstacle per accedir-hi.
 * @param grafic Grafic ilustrant la cova
 * @param posicioX Coordenada horitzontal de la cova
 * @param posicioY Coordenada vertical de la cova
 */
Cova::Cova(Grafic grafic, Grafic grafic2, int posicioX, int posicioY)
{
	m_posicioX = posicioX;
	m_posicioY = posicioY;

	m_posicioFantasmaY = m_posicioY + DESPLACAMENT_GRANOTA;
	m_grafic = grafic;
	m_graficOcupada = grafic2;
	m_covaOcupada = false;
	m_interior = Area(m_posicioX, m_posicioX + m_grafic.getScaleX(), m_posicioY, m_posicioY + m_grafic.getScaleY());
	m_interiorAmbParets = Area(m_posicioX+10 , m_posicioX+m_grafic.getScaleX()-10 , m_posicioY, m_posicioY + m_grafic.getScaleY()+10);
}

/**
 * Destructor per defecte.
 */
Cova::~Cova(void)
{
}

/**
 * Dibuixa la cova a la seva posició.
 */
void Cova::dibuixa()
{
	m_grafic.dibuixa(m_posicioX, m_posicioY);
}

/**
 * Comprova si una àrea donada no es solapa amb cap paret de la cova.
 * @param area Area a comprovar
 * @returns true si l'àrea no es solapa amb cap parets de la cova.
 */
bool Cova::esAccessible(Area area)
{
	if (m_covaOcupada) //esto es magia!
	{
		return !m_interiorAmbParets.solapa(area);
	}
	//return !area.solapa(m_interiorAmbParets);
	return !m_interiorAmbParets.solapa(area);
}

/**
 * Comprova si l'àrea donada es troba totalment a l'interior de la cova.
 * @param area Area a comprovar
 * @returns true si l'àrea es troba totalment dins la cova i false si no és així.
 */
bool Cova::esDins(Area area)
{
	if (m_covaOcupada)
	{
		return false;
	}

	if (m_interiorAmbParets.inclou(area))
	{
		m_covaOcupada = true;
		changeGrafic();
		return true;
	}
	return m_interiorAmbParets.inclou(area);
}

bool Cova::getCovaOcupada()
{
	return m_covaOcupada;
}

void Cova::changeGrafic()
{
	m_grafic = m_graficOcupada;
}