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
Cotxe::Cotxe(Grafic grafic, int velocitat, bool direccio)
{
	m_grafic = grafic;
	m_velocitat = velocitat;
	m_contador = 0;
	m_direccio= direccio;	//a�ado esta variable para poder cambiar 
							//facilmente la direcci�n del veh�culo.
							//Probable m�todo si se quiere implementar ++
							// dificultad randomizar la direcci�n entre 
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

/**
 * Dibuixa el vehicle a la posici� actual.
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
	if (m_direccio) {
		dir=1;
	}
	else {
		dir=-1;
	}
	//if (m_contador%100 != 5){
		m_posicioX = m_posicioX + (DESPLACAMENT_COTXE * dir * m_velocitat/6);
	//}
	//m_contador++;
}

/**
 * Mou el vehicle a l'inici d'un carril.
 * @param iniciXCarril Coordenada X inicial del carril
 * @param iniciYCarril Coordenada Y del carril
 */
void Cotxe::mouAIniciCarril(int iniciYCarril)
{
	//la posici�n de inicio de la X depende de la direcci�n del vehiculo
	// lo �nico que nos pasa la "main" es el carril en el que va.
	if (m_direccio){
	m_posicioX = INICI_X;
	}
	else {
	m_posicioX = FI_X;
	}
	m_posicioY= iniciYCarril;
	
}