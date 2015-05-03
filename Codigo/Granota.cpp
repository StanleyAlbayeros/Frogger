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
* utilizado para los movimientos intermedios
*/

void Granota::setGrafic(Grafic grafic2)
{
	m_grafic = grafic2;
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
	int m_tempX=m_posicioX-DESPLACAMENT_GRANOTA; 
	// creo una variable adicional que evita
	// que la rana se salga hacia el lado, ya que la funcion
	// espaiPermes no lo evita, simplemente prohibe que se mueva
	// una vez fuera del espaiPermes
	if (m_tempX>=INICI_X)
	{
	m_posicioX -= DESPLACAMENT_GRANOTA;
	}
}

/**
 * Mou la granota cap a la dreta.
 */
void Granota::mouDreta()
{
	int m_tempX=m_posicioX+DESPLACAMENT_GRANOTA; 
	// creo una variable adicional que evita
	// que la rana se salga hacia el lado, ya que la funcion
	// espaiPermes no lo evita, simplemente prohibe que se mueva
	// una vez fuera del espaiPermes
	if (m_tempX<=FI_X)
	{
	m_posicioX += DESPLACAMENT_GRANOTA;
	}
}

/**
 * Mou la granota cap amunt.
 */
void Granota::mouAmunt()
{	
	int m_tempY=m_posicioY-DESPLACAMENT_GRANOTA; 
	// creo una variable adicional que evita
	// que la rana se salga hacia el lado, ya que la funcion
	// espaiPermes no lo evita, simplemente prohibe que se mueva
	// una vez fuera del espaiPermes
	if (m_tempY>=INICI_Y)
	{
		m_posicioY -= DESPLACAMENT_GRANOTA;
		Grafic rana2;
		rana2.crea("data/GraficsGranota/Granota_Amunt_2.png");
		Granota rana_temp = Granota(rana2 , m_posicioX-10, m_posicioY-10);
		rana_temp.mouAPosicioInicial();
		rana_temp.dibuixa();
		int i = 0;
	}
}

/**
 * Mou la granota cap avall.
 */
void Granota::mouAvall()
{
	int m_tempY=m_posicioY+m_grafic.getScaleY()+DESPLACAMENT_GRANOTA; 
	// creo una variable adicional que evita
	// que la rana se salga hacia el lado, ya que la funcion
	// espaiPermes no lo evita, simplemente prohibe que se mueva
	// una vez fuera del espaiPermes
	if (m_tempY<=FI_Y)
	{
		m_posicioY += DESPLACAMENT_GRANOTA;
	}
}

/**
 * Mou la granota a la seva posició inicial.
 */
void Granota::mouAPosicioInicial()
{
	m_posicioX = (m_posicioInicialX);
	m_posicioY = (m_posicioInicialY);
}

