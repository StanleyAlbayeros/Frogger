#pragma once
#include "Area.h"
#include "lib\Grafic.h"

#define BORDE_COVA 20

class Cova
{
public:
	Cova();
	Cova(Grafic grafic, Grafic grafic2, int posicioX, int posicioY);
	~Cova();
	void Cova::dibuixa();
	bool esAccessible(Area area);
	bool esDins(Area area);
	bool getCovaOcupada();
	void changeGrafic(); // utilizado para cambiar el grafico de la cueva
						// una vez la rana la haya ocupado
private:
	int m_posicioX;
	int m_posicioY;

	// Creo una variable "fantasma" para controlar si la rana puede
	// o no acceder a la cueva. La idea es que las funciones solapa de 
	// area.cpp no toman en cuenta el posible movimiento de la rana
	// de tal manera que no consideran el caso en el cual el siguiente movimiento
	// colocaría a la rana dentro de la cueva, o solapandola en area
	int m_posicioFantasmaY;
	
	bool m_covaOcupada;
	Grafic m_grafic;
	Grafic m_graficOcupada;
	Area m_interior;
	Area m_interiorAmbParets;
};

