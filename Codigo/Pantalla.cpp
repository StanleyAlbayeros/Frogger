#include "Pantalla.h"
#include <cstdlib>
#include <ctime>

/**
 * Constructor de la Pantalla.
 * Aquesta pantalla té una sola cova imaginària ja que no té parets.
 */
Pantalla::Pantalla()
{
	// Carreguem els components gràfics a fer servir.
	m_graficFons.crea("data/GraficsGranota/Fons.png");
	m_graficCova.crea("data/GraficsGranota/CovaNo.png");
	m_graficCotxe.crea("data/GraficsGranota/Cotxe_1.png");
	m_graficGranotaAmunt.crea("data/GraficsGranota/Granota_Amunt_1.png");
	// Inicialitzem l'area total de la pantalla, així com l'espai pels carrils, el número de carrils i instanciem els objectes granota i cova.
	m_areaTotal = Area(INICI_X, FI_X, INICI_Y, FI_Y);
	m_iniciCarrilsY = INICI_Y + m_graficCova.getScaleY();
	m_nCarrils = (((FI_Y - m_graficGranotaAmunt.getScaleY()) - m_iniciCarrilsY) / m_graficCotxe.getScaleY()) -1 ;
	m_granota = Granota(m_graficGranotaAmunt, (FI_X - INICI_X - m_graficGranotaAmunt.getScaleX())/2, FI_Y - m_graficGranotaAmunt.getScaleY());
	m_cova = Cova(m_graficCova, INICI_X, INICI_Y);
	// Fixem l'hora actual com a llavor pel generador d'aleatoris.
	std::srand(std::time(0));
}

/**
 * Destructor per defecte
 */
Pantalla::~Pantalla()
{
	m_graficFons.destrueix();
	m_graficCova.destrueix();
	m_graficCotxe.destrueix();
	m_graficGranotaAmunt.destrueix();
}

/**
 * Inicia la pantalla instanciant l'objecte Cotxe i colocant la granota i el Cotxe a la posició inicial.
 * @param nivell Nivell de la pantalla.
 */
void Pantalla::inicia(int nivell)
{

	m_cotxe=Cotxe(m_graficCotxe, nivell);
	m_cotxe.mouAIniciCarril(INICI_X,m_iniciCarrilsY);
	m_granota.mouAPosicioInicial();

}

/**
 * Tria aleatòriament un carril pel que circular.
 * @return posicio Y del carril pel que circular
 */
int Pantalla::triaCarril()
{
	return (INICI_Y+3) + (rand()% ((FI_Y-35)-INICI_Y));
}

/**
 * Comprova si una àrea donada es troba dins la cova.
 * @param area Area a comprovar si es troba dins una cova.
 * @return true si l'àrea es troba dins la cova i false si no s'hi troba. 
 */
bool Pantalla::esGranotaDinsCova()
{
	bool dentro=false;

	if (m_cova.esDins(m_granota.getAreaOcupada()))
	{
		dentro=true;
	}

	return dentro; 
}

/**
 * Comprova si una àrea donada es troba dins l'espai permés de moviment.
 * @param area Area a comprovar si es troba dins l'espai permés de moviment.
 * @return true si l'àrea es troba dins l'espai permés de moviment i false si no és així.
 */
bool Pantalla::espaiPermes(Area area)
{
	bool permitido = false;

	if (m_areaTotal.inclou(area))
	{
		permitido = true;
	}

	return permitido;

}

/**
 * Dibuixa tots els elements grafics a la posició on es troben.
 */
void Pantalla::dibuixa()
{
	m_graficFons.dibuixa(0,0);
	m_cova.dibuixa();
	m_cotxe.dibuixa();
	m_granota.dibuixa();
}

/**
 * Mou el Cotxe.
 */
void Pantalla::mouCotxe()
{
	if (espaiPermes(m_cotxe.getAreaOcupada()))
	{
		m_cotxe.mou();
	}
	else 
	{
		m_cotxe.mouAIniciCarril(INICI_X,m_iniciCarrilsY);
	}
}

/**
 * Comprova si la granota ha mort.
 * @return true si la granota és morta i false si és viva.
 */
bool Pantalla::haMortLaGranota()
{
	bool mort = false;

	if ((m_cotxe.getAreaOcupada().solapa(m_granota.getAreaOcupada()))
		|| (m_granota.getAreaOcupada().solapa(m_cotxe.getAreaOcupada())))
	{
		mort = true;
	}

	return mort;
}

/**
 * Mou la granota en la direcció donada.
 * @param direccio Direcció cap on s'ha de moure la granota. Fer servir constants AMUNT, AVALL, DRETA i ESQUERRA.
 */
void Pantalla::mouGranota(int direccio)
{
//	if (espaiPermes(m_granota.getAreaOcupada()))
//	{
		switch (direccio){

			case 1:
					m_granota.mouEsquerra();
			break;
			
			case 2:
					m_granota.mouDreta();
			break;

			case 3:
					m_granota.mouAmunt();
			break;

			case 4:
					m_granota.mouAvall();
			break;
//			}

	}


}
