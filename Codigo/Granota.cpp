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
	// TODO emplenar
	return Area(); // TODO modificar
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
	if(m_posicioX>(INICI_X+DESPLACAMENT_GRANOTA))
	{	
		m_posicioX -= DESPLACAMENT_GRANOTA;
	}
}

/**
 * Mou la granota cap a la dreta.
 */
void Granota::mouDreta()
{
	if ((m_posicioX+m_grafic.getScaleX())<(FI_X-DESPLACAMENT_GRANOTA))
	{
		m_posicioX += DESPLACAMENT_GRANOTA;
	}
}

/**
 * Mou la granota cap amunt.
 */
void Granota::mouAmunt()
{
	if((m_posicioY+m_grafic.getScaleY())>(INICI_Y-DESPLACAMENT_GRANOTA))
	{
		m_posicioY -= DESPLACAMENT_GRANOTA;
	}
	
}

/**
 * Mou la granota cap avall.
 */
void Granota::mouAvall()
{
	if((m_posicioY+m_grafic.getScaleY())<(FI_Y-DESPLACAMENT_GRANOTA))
	{
		m_posicioY += DESPLACAMENT_GRANOTA;
	}
}

/**
 * Mou la granota a la seva posició inicial.
 */
void Granota::mouAPosicioInicial()
{
	m_posicioX = INICI_X + ((FI_X - INICI_X) / 2) - m_grafic.getScaleX()/2;
	m_posicioY = INICI_Y_GRANOTA;
}