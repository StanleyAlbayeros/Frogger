#include "Granota.h"
#include "Pantalla.h"
#include "Joc.h"

/**
 * Constructor per defecte.
 */
Granota::Granota()
{
}

/**
 * Constructor de la Granota.
 * @param grafic Grafic amb el que ilustrar la granota
 * @param posicioInicialX Posició inicial en coordenada horitzontal
 * @param posicioInicialY Posició inicial en coordenada vertical
 */
Granota::Granota(Grafic grafic, int posicioInicialX, int posicioInicialY)
{
	m_grafic = grafic;
	m_posicioInicialX = posicioInicialX;
	m_posicioInicialY = posicioInicialY;
}

/**
 * Destructor per defecte.
 */
Granota::~Granota()
{
}

/**
 * Obté l'àrea ocupada per la granota.
 * @return Area ocupada
 */
Area Granota::getAreaOcupada()
{
	int x0 = m_posicioX;
	int x1 = x0 + m_grafic.getScaleX() ;
	int y0 = m_posicioY;
	int y1 = y0 + m_grafic.getScaleY() ;
	
	return Area(x0 , x1 , y0 , y1);
}

/**
 * Dibuixa la granota a la posició actual.
 */
void Granota::dibuixa()
{
	m_grafic.dibuixa(m_posicioX,m_posicioY);
}

/**
 * Mou la granota cap a l'esquerra.
 */
void Granota::mouEsquerra()
{
	m_posicioX -= DESPLACAMENT_GRANOTA;
}

/**
 * Mou la granota cap a la dreta.
 */
void Granota::mouDreta()
{
	m_posicioX += DESPLACAMENT_GRANOTA;
}

/**
 * Mou la granota cap amunt.
 */
void Granota::mouAmunt()
{
	m_posicioY -= DESPLACAMENT_GRANOTA;
}

/**
 * Mou la granota cap avall.
 */
void Granota::mouAvall()
{
	m_posicioY += DESPLACAMENT_GRANOTA;
}

/**
 * Mou la granota a la seva posició inicial.
 */
void Granota::mouAPosicioInicial()
{
	m_posicioX = (FI_X - INICI_X - m_grafic.getScaleX())/2;
	m_posicioY = FI_Y - m_grafic.getScaleY();
}