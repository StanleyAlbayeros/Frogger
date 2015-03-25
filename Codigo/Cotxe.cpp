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
	// TODO emplenar
	return Area(); // TODO modificar
}

/**
 * Dibuixa el vehicle a la posició actual.
 */
void Cotxe::dibuixa()
{
	// TODO emplenar
}

/**
 * Mou el vehicle tenint en compte la velocitat d'aquest.
 */
void Cotxe::mou()
{
	// TODO emplenar
}

/**
 * Mou el vehicle a l'inici d'un carril.
 * @param iniciXCarril Coordenada X inicial del carril
 * @param iniciYCarril Coordenada Y del carril
 */
void Cotxe::mouAIniciCarril(int iniciXCarril, int iniciYCarril)
{
	// TODO emplenar
}