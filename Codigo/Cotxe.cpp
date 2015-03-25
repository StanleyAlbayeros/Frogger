#include "Cotxe.h"
#include "Pantalla.h"

/**
 * Constructor per defecte.
 */
Cotxe::Cotxe()
{
}

/**
 * Constructor del Cotxe.
 * @param grafic Grafic amb el que ilustrar el vehicle
 * @param velocitat Velocitat de moviment
 */
Cotxe::Cotxe(Grafic grafic, int velocitat)
{
	m_grafic = grafic;
	m_velocitat = velocitat;
}

/**
 * Destructor per defecte.
 */
Cotxe::~Cotxe()
{
}

/**
 * Retorna l'area ocupada pel vehicle.
 */
Area Cotxe::getAreaOcupada()
{
	int x0 = m_posicioX;
	int x1 = x0 + m_grafic.getScaleX() ;
	int y0 = m_posicioY;
	int y1 = y0 + m_grafic.getScaleY() ;
	
	return Area(x0 , x1 , y0 , y1);
}

/**
 * Dibuixa el vehicle a la posició actual.
 */
void Cotxe::dibuixa()
{
	m_grafic.dibuixa(m_posicioX,m_posicioY);
}

/**
 * Mou el vehicle tenint en compte la velocitat d'aquest.
 */
void Cotxe::mou()
{
	m_posicioX = m_posicioX+(DESPLACAMENT_COTXE*m_velocitat);
}

/**
 * Mou el vehicle a l'inici d'un carril.
 * @param iniciXCarril Coordenada X inicial del carril
 * @param iniciYCarril Coordenada Y del carril
 */
void Cotxe::mouAIniciCarril(int iniciXCarril, int iniciYCarril)
{
	m_grafic.dibuixa(iniciXCarril , iniciYCarril);
}