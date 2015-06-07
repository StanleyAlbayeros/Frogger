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
Cotxe::Cotxe(Grafic grafic, int velocitat, bool direccio, int iniciY)
{
	m_grafic = grafic;
	m_velocitat = velocitat;
	m_contador = 0;
	m_posicioY = iniciY;
	m_direccio= direccio;	//añado esta variable para poder cambiar 
							//facilmente la dirección del vehículo.
							//Probable método si se quiere implementar ++
							// dificultad randomizar la dirección entre 
							// spawns de vehiculo
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
	int x0 = m_posicioX;
	int x1 = x0 + m_grafic.getScaleX() ;
	int y0 = m_posicioY;
	int y1 = y0 + m_grafic.getScaleY() ;
	
	return Area(x0 , x1 , y0 , y1);
}

bool Cotxe::canSpawn()
{
	bool canSpawn = false;
	int tempX = INICI_X + m_grafic.getScaleX() + DESPLACAMENT_COTXE;

	if (m_posicioX > tempX)
		{
			canSpawn = true;
		}

	return canSpawn;
}

/**
 * Dibuixa el vehicle a la posició actual.
 */
void Cotxe::dibuixa()
{
	m_grafic.dibuixa(m_posicioX,m_posicioY);
}

/**
 * Mou el vehicle tenint en compte la velocitat d'aquest.
 */
void Cotxe::mou()
{
	int dir;

	if (m_direccio) 
	{
		dir=1;
	}

	else 
	{
		dir=-1;
	}
		m_posicioX = m_posicioX + (DESPLACAMENT_COTXE * dir * m_velocitat/10);
}

/**
 * Mou el vehicle a l'inici d'un carril.
 * @param iniciXCarril Coordenada X inicial del carril
 * @param iniciYCarril Coordenada Y del carril
 */
void Cotxe::mouAIniciCarril(int iniciYCarril)
{
	//la posición de inicio de la X depende de la dirección del vehiculo
	// lo único que nos pasa la "main" es el carril en el que va.
	if (m_direccio){
	m_posicioX = INICI_X - m_grafic.getScaleX();
	}
	else {
	m_posicioX = FI_X ; //aqui no hace falta el getScaleX porque
						//la esquina del coche ya comienza fuera del 
						//tablero
	}
	m_posicioY= iniciYCarril;
	
}