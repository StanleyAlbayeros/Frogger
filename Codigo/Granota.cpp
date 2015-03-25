#include "Granota.h"

/**
 * Constructor per defecte.
 */
Granota::Granota()
{
}

/**
 * Constructor de la Granota.
 * @param grafic Grafic amb el que ilustrar la granota
 * @param posicioInicialX Posici� inicial en coordenada horitzontal
 * @param posicioInicialY Posici� inicial en coordenada vertical
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
 * Obt� l'�rea ocupada per la granota.
 * @return Area ocupada
 */
Area Granota::getAreaOcupada()
{
	// TODO emplenar
	return Area(); // TODO modificar
}

/**
 * Dibuixa la granota a la posici� actual.
 */
void Granota::dibuixa()
{
	// TODO emplenar
}

/**
 * Mou la granota cap a l'esquerra.
 */
void Granota::mouEsquerra()
{
	// TODO emplenar
}

/**
 * Mou la granota cap a la dreta.
 */
void Granota::mouDreta()
{
	// TODO emplenar
}

/**
 * Mou la granota cap amunt.
 */
void Granota::mouAmunt()
{
	// TODO emplenar
}

/**
 * Mou la granota cap avall.
 */
void Granota::mouAvall()
{
	// TODO emplenar
}

/**
 * Mou la granota a la seva posici� inicial.
 */
void Granota::mouAPosicioInicial()
{
	// TODO emplenar
}