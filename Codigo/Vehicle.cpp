#include "Vehicle.h"
#include "Pantalla.h"

/**
 * Constructor per defecte.
 */
Vehicle::Vehicle()
{
}

/**
 * Constructor del Vehicle.
 * @param grafic Grafic amb el que ilustrar el vehicle
 * @param velocitat Velocitat de moviment
 */
Vehicle::Vehicle(Grafic grafic, int velocitat)
{
	m_grafic = grafic;
	m_velocitat = velocitat;
}

/**
 * Destructor per defecte.
 */
Vehicle::~Vehicle()
{
}

/**
 * Retorna l'area ocupada pel vehicle.
 */
Area Vehicle::getAreaOcupada()
{
	// TODO emplenar
	return Area(); // TODO modificar
}

/**
 * Dibuixa el vehicle a la posició actual.
 */
void Vehicle::dibuixa()
{
	// TODO emplenar
}

/**
 * Mou el vehicle tenint en compte la velocitat d'aquest.
 */
void Vehicle::mou()
{
	// TODO emplenar
}

/**
 * Mou el vehicle a l'inici d'un carril.
 * @param iniciXCarril Coordenada X inicial del carril
 * @param iniciYCarril Coordenada Y del carril
 */
void Vehicle::mouAIniciCarril(int iniciXCarril, int iniciYCarril)
{
	// TODO emplenar
}