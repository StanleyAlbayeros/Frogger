#include "Bonus.h"
#include "Pantalla.h"

/**
 * Constructor per defecte.
 */
Bonus::Bonus()
{
}

/**
 * Constructor del Bonus
 * @param grafic Grafic amb el que ilustrar el objecte de bonus
 */
Bonus::Bonus(Grafic grafic)
{
	m_grafic = grafic;
	m_direccio = DIRECCIO_INICIAL;
}

/**
 * Destructor per defecte.
 */
Bonus::~Bonus()
{
}

/**
 * Retorna l'area ocupada pel objecte de bonus.
 */
Area Bonus::getAreaOcupada()
{
	return Area(m_posicioX, m_posicioX+m_grafic.getScaleX(), m_posicioY, m_posicioY+m_grafic.getScaleY());
}

/**
 * Dibuixa el objecte de bonus a la posició actual.
 */
void Bonus::dibuixa()
{
	m_grafic.dibuixa(m_posicioX, m_posicioY);
}

/**
 * Mou el objecte bonus a una posicio inicial
 * @param iniciXCarril Coordenada X inicial del carril
 * @param iniciYCarril Coordenada Y del carril
 */
void Bonus::setCoordenadas(int X, int Y)
{
	m_posicioX=X;
	m_posicioY=Y;
}

int Bonus::getDireccio()
{
	return m_direccio;
}

void Bonus::setDireccio(int direccio)
{
	 m_direccio = direccio;
}