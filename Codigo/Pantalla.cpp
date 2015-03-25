#include "Pantalla.h"
#include <cstdlib>
#include <ctime>

/**
 * Constructor de la Pantalla.
 * Aquesta pantalla t� una sola cova imagin�ria ja que no t� parets.
 */
Pantalla::Pantalla()
{
	// Carreguem els components gr�fics a fer servir.
	m_graficFons.crea("data/GraficsGranota/Fons.png");
	m_graficCova.crea("data/GraficsGranota/CovaNo.png");
	m_graficVehicle.crea("data/GraficsGranota/Cotxe_1.png");
	m_graficGranotaAmunt.crea("data/GraficsGranota/Granota_Amunt_1.png");
	// Inicialitzem l'area total de la pantalla, aix� com l'espai pels carrils, el n�mero de carrils i instanciem els objectes granota i cova.
	m_areaTotal = Area(INICI_X, FI_X, INICI_Y, FI_Y);
	m_iniciCarrilsY = INICI_Y + m_graficCova.getScaleY();
	m_nCarrils = (((FI_Y - m_graficGranotaAmunt.getScaleY()) - m_iniciCarrilsY) / m_graficVehicle.getScaleY()) -1 ;
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
	m_graficVehicle.destrueix();
	m_graficGranotaAmunt.destrueix();
}

/**
 * Inicia la pantalla instanciant l'objecte vehicle i colocant la granota i el vehicle a la posici� inicial.
 * @param nivell Nivell de la pantalla.
 */
void Pantalla::inicia(int nivell)
{
	// TODO emplenar
}

/**
 * Tria aleat�riament un carril pel que circular.
 * @return posicio Y del carril pel que circular
 */
int Pantalla::triaCarril()
{
	// TODO emplenar
	return 0; // TODO modificar
}

/**
 * Comprova si una �rea donada es troba dins la cova.
 * @param area Area a comprovar si es troba dins una cova.
 * @return true si l'�rea es troba dins la cova i false si no s'hi troba. 
 */
bool Pantalla::esGranotaDinsCova()
{
	// TODO emplenar
	return true; // TODO modificar
}

/**
 * Comprova si una �rea donada es troba dins l'espai perm�s de moviment.
 * @param area Area a comprovar si es troba dins l'espai perm�s de moviment.
 * @return true si l'�rea es troba dins l'espai perm�s de moviment i false si no �s aix�.
 */
bool Pantalla::espaiPermes(Area area)
{
	// TODO emplenar
	return true; // TODO modificar
}

/**
 * Dibuixa tots els elements grafics a la posici� on es troben.
 */
void Pantalla::dibuixa()
{
	// TODO emplenar
}

/**
 * Mou el vehicle.
 */
void Pantalla::mouVehicle()
{
	// TODO emplenar
}

/**
 * Comprova si la granota ha mort.
 * @return true si la granota �s morta i false si �s viva.
 */
bool Pantalla::haMortLaGranota()
{
	// TODO emplenar
	return true; // TODO modificar
}

/**
 * Mou la granota en la direcci� donada.
 * @param direccio Direcci� cap on s'ha de moure la granota. Fer servir constants AMUNT, AVALL, DRETA i ESQUERRA.
 */
void Pantalla::mouGranota(int direccio)
{
	// TODO emplenar
}
