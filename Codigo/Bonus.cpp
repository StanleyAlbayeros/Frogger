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
 * Mou el objecte de bonus.
 */
void Bonus::mou(int posicio, int direccio)
{
	int m_tempX;
	int m_tempY;
	switch (direccio)
	{
		case 1:
				m_tempX = m_posicioX-DESPLACAMENT_BONUS; 

				if (m_tempX >= INICI_X)
				{
				m_posicioX -= DESPLACAMENT_BONUS;
				}
				break;
		case 2:
				m_tempX = m_posicioX+DESPLACAMENT_BONUS; 
				if (m_tempX <= FI_X)
				{
				m_posicioX += DESPLACAMENT_BONUS;
				}
				break;
		case 3:
				m_tempY = m_posicioY-DESPLACAMENT_BONUS; 

				if (m_tempY >= INICI_Y)
				{
					m_posicioY -= DESPLACAMENT_BONUS;
				}
				break;
		case 4:
				m_tempY = m_posicioY+DESPLACAMENT_BONUS; 

				if (m_tempY >= INICI_Y)
				{
					m_posicioY += DESPLACAMENT_BONUS;
				}
				break;
	}
}

/**
 * Mou el objecte bonus a una posicio inicial
 * @param iniciXCarril Coordenada X inicial del carril
 * @param iniciYCarril Coordenada Y del carril
 */
void Bonus::mouAPosicioInicial(int posicioX, int posicioY)
{
	m_posicioX= posicioX;
	m_posicioY= posicioY;
}