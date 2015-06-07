#include "Pantalla.h"
#include "CuaCotxes.h"
#include <cstdlib>
#include <ctime>

/**
 * Constructor de la Pantalla.
 * Aquesta pantalla té una sola cova imaginària ja que no té parets.
 */
Pantalla::Pantalla()
{
	// Grafics de cova y fons
	m_graficFons.crea("data/GraficsGranota/Fons.png");
	m_graficCova.crea("data/GraficsGranota/Cova120.png");
	m_graficCovaOcupada.crea("data/GraficsGranota/CovaOcupada.png");

	//Grafics de cotxes
	m_graficCotxe1.crea("data/GraficsGranota/Tractor.png");
	m_graficCotxe2.crea("data/GraficsGranota/Camio.png");
	m_graficCotxe3.crea("data/GraficsGranota/Cotxe_1.png");
	m_graficCotxe4.crea("data/GraficsGranota/Cotxe_2.png");
	m_graficCotxe5.crea("data/GraficsGranota/Cotxe_3.png");
	
	//Grafics de granota en repos
	m_graficGranotaAmunt.crea("data/GraficsGranota/Granota_Amunt_1.png");
	m_graficGranotaAvall.crea("data/GraficsGranota/Granota_Avall_1.png");
	m_graficGranotaEsquerra.crea("data/GraficsGranota/Granota_Esquerra_1.png");
	m_graficGranotaDreta.crea("data/GraficsGranota/Granota_Dreta_1.png");
	
	//Grafics de granota en moviment
	m_graficGranotaAmunt2.crea("data/GraficsGranota/Granota_Amunt_2.png");
	m_graficGranotaAvall2.crea("data/GraficsGranota/Granota_Avall_2.png");
	m_graficGranotaEsquerra2.crea("data/GraficsGranota/Granota_Esquerra_2.png");
	m_graficGranotaDreta2.crea("data/GraficsGranota/Granota_Dreta_2.png");
	
	//Grafics del game over
	m_GameOver1.crea("data/GraficsGranota/GameOver1.png");
	m_GameOver2.crea("data/GraficsGranota/GameOver2.png");
	m_GameOver3.crea("data/GraficsGranota/GameOver3.png");
	m_GameOver4.crea("data/GraficsGranota/GameOver4.png");
	m_GameOver5.crea("data/GraficsGranota/GameOver5.png");

	//Grafics de l'animacio dels points
	m_graficPoints100.crea("data/GraficsGranota/Points100.png");


	//grafics del level up
	m_LevelUp1.crea("data/GraficsGranota/LevelUp1.png");
	m_LevelUp2.crea("data/GraficsGranota/LevelUp2.png");
	m_LevelUp3.crea("data/GraficsGranota/LevelUp3.png");
	m_LevelUp4.crea("data/GraficsGranota/LevelUp4.png");
	m_LevelUp5.crea("data/GraficsGranota/LevelUp5.png");
		
	// Inicialitzem l'area total de la pantalla, així com l'espai pels carrils, el número de carrils i instanciem els objectes granota i cova.
	m_areaTotal = Area(INICI_X-1, FI_X+1, INICI_Y-1, FI_Y+1);
	m_iniciCarrilsY = INICI_Y + m_graficCova.getScaleY();
	
	//Granota
	m_granota = Granota(m_graficGranotaAmunt, (FI_X - INICI_X - m_graficGranotaAmunt.getScaleX())/2, FI_Y - m_graficGranotaAmunt.getScaleY());
	
	//Coves
	m_cova1 = Cova(m_graficCova, m_graficCovaOcupada, INICI_X, INICI_Y);
	m_cova2 = Cova(m_graficCova, m_graficCovaOcupada, INICI_X + m_graficCova.getScaleX(), INICI_Y);
	m_cova3 = Cova(m_graficCova, m_graficCovaOcupada, INICI_X + ( 2 * m_graficCova.getScaleX()), INICI_Y);
	m_cova4 = Cova(m_graficCova, m_graficCovaOcupada, INICI_X + ( 3 * m_graficCova.getScaleX()), INICI_Y);
	m_cova5 = Cova(m_graficCova, m_graficCovaOcupada, INICI_X + ( 4 * m_graficCova.getScaleX()), INICI_Y);

	//Grafics dels numeros
	m_graficNum0.crea("data/numeros/numero0000.png");
	m_graficNum1.crea("data/numeros/numero0001.png");
	m_graficNum2.crea("data/numeros/numero0002.png");
	m_graficNum3.crea("data/numeros/numero0003.png");
	m_graficNum4.crea("data/numeros/numero0004.png");
	m_graficNum5.crea("data/numeros/numero0005.png");
	m_graficNum6.crea("data/numeros/numero0006.png");
	m_graficNum7.crea("data/numeros/numero0007.png");
	m_graficNum8.crea("data/numeros/numero0008.png");
	m_graficNum9.crea("data/numeros/numero0009.png");

	for (int j=0 ; j<5 ; j++)
	{
		m_randomCotxe[j]=0;
	}

}

/**
 * Destructor per defecte
 */

Pantalla::~Pantalla()
{
	m_graficFons.destrueix();

	m_graficCova.destrueix();


	m_graficCotxe1.destrueix();
	m_graficCotxe2.destrueix();
	m_graficCotxe3.destrueix();
	m_graficCotxe4.destrueix();
	m_graficCotxe5.destrueix();

	m_graficGranotaAmunt.destrueix();
	m_graficGranotaAvall.destrueix();
	m_graficGranotaEsquerra.destrueix();
	m_graficGranotaDreta.destrueix();

	m_graficGranotaAmunt2.destrueix();
	m_graficGranotaAvall2.destrueix();
	m_graficGranotaEsquerra2.destrueix();
	m_graficGranotaDreta2.destrueix();

	m_LevelUp1.destrueix();
	m_LevelUp2.destrueix();
	m_LevelUp3.destrueix();
	m_LevelUp4.destrueix();
	m_LevelUp5.destrueix();

	m_graficPoints100.destrueix();

	m_GameOver1.destrueix();
	m_GameOver2.destrueix();
	m_GameOver3.destrueix();
	m_GameOver4.destrueix();
	m_GameOver5.destrueix();

	
}

/**
 * Inicia la pantalla instanciant l'objecte Cotxe i colocant la granota i el Cotxe a la posició inicial.
 * @param nivell Nivell de la pantalla.
 */
void Pantalla::inicia(int nivell)
{
	//Coves
	m_cova1 = Cova(m_graficCova, m_graficCovaOcupada, INICI_X, INICI_Y);
	m_cova2 = Cova(m_graficCova, m_graficCovaOcupada, INICI_X + m_graficCova.getScaleX(), INICI_Y);
	m_cova3 = Cova(m_graficCova, m_graficCovaOcupada, INICI_X + ( 2 * m_graficCova.getScaleX()), INICI_Y);
	m_cova4 = Cova(m_graficCova, m_graficCovaOcupada, INICI_X + ( 3 * m_graficCova.getScaleX()), INICI_Y);
	m_cova5 = Cova(m_graficCova, m_graficCovaOcupada, INICI_X + ( 4 * m_graficCova.getScaleX()), INICI_Y);


	//Cotxes
		// Fixem l'hora actual com a llavor pel generador d'aleatoris.
	std::srand(std::time(0));
	for (int j=0 ; j<5 ; j++)
	{
		if (rand()%2 == 1)
		{
			m_randomCotxe[j]=false;
		}
		else
		{
			m_randomCotxe[j]=true;
		}
	}
	m_cotxe1=Cotxe(m_graficCotxe1, nivell+5 , m_randomCotxe[0]);
	m_cotxe2=Cotxe(m_graficCotxe2, nivell+10, m_randomCotxe[1]);
	m_cotxe3=Cotxe(m_graficCotxe3, nivell+13, m_randomCotxe[2]);
	m_cotxe4=Cotxe(m_graficCotxe4, nivell+16, m_randomCotxe[3]);
	m_cotxe5=Cotxe(m_graficCotxe5, nivell+24, m_randomCotxe[4]);

	m_cotxe1.mouAIniciCarril(triaCarril(1));
	m_cotxe2.mouAIniciCarril(triaCarril(2));
	m_cotxe3.mouAIniciCarril(triaCarril(3));
	m_cotxe4.mouAIniciCarril(triaCarril(4));
	m_cotxe5.mouAIniciCarril(triaCarril(5));
	
	//Granota
	m_granota.mouAPosicioInicial();

}


/**
 * Utilitzat per fer el "reset" que es necessita quan 
 * la granota ocupa una cova o colisiona amb un cotxe
 * @param nivell Nivell de la pantalla.
 */
void Pantalla::reset(int nivell)
{

	//Granota
	m_granota.mouAPosicioInicial();

}

/**
 * Tria aleatòriament un carril pel que circular.
 * @return posicio Y del carril pel que circular
 */
int Pantalla::triaCarril(int numcotxe)
{
	int result = ((m_iniciCarrilsY) + (m_graficGranotaAmunt.getScaleY()*((numcotxe-1)*1.35)));
	return result;
}

/**
 * Comprova si una àrea donada es troba dins la cova.
 * @param area Area a comprovar si es troba dins una cova.
 * @return true si l'àrea es troba dins la cova i false si no s'hi troba. 
 */
int Pantalla::esGranotaDinsCova()
{
	
	if (m_cova1.esDins(m_granota.getAreaOcupada()))
	{
			return true;
	}
	if (m_cova2.esDins(m_granota.getAreaOcupada()))
	{
		return true;
	}
	if (m_cova3.esDins(m_granota.getAreaOcupada()))
	{
		return true;
	}
	if (m_cova4.esDins(m_granota.getAreaOcupada()))
	{
		return true;
	}
	if (m_cova5.esDins(m_granota.getAreaOcupada()))
	{
		return true;
	}
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
void Pantalla::dibuixa(int dir, int count)
{
	m_graficFons.dibuixa(0,0);

	m_cova1.dibuixa();
	m_cova2.dibuixa();
	m_cova3.dibuixa();
	m_cova4.dibuixa();
	m_cova5.dibuixa();

	m_cotxe1.dibuixa();
	m_cotxe2.dibuixa();
	m_cotxe3.dibuixa();
	m_cotxe4.dibuixa();
	m_cotxe5.dibuixa();

	if (count == 0)
	{
		switch (dir){

			case 1: //izquierda
					m_granota.setGrafic(m_graficGranotaEsquerra);
			break;
			
			case 2: //derecha
					m_granota.setGrafic(m_graficGranotaDreta);
			break;

			case 3: //arriba
					m_granota.setGrafic(m_graficGranotaAmunt);
			break;

			case 4: //abajo
					m_granota.setGrafic(m_graficGranotaAvall);
			break;
					}
	
	}
	m_granota.dibuixa();
}

/**
 * Mou el Cotxe.
 */
void Pantalla::mouCotxes()
{
//mover primer coche
	if (m_areaTotal.solapa(m_cotxe1.getAreaOcupada()))
	{
		m_cotxe1.mou();
	}
	if (!m_areaTotal.solapa(m_cotxe1.getAreaOcupada()))
	{
		m_cotxe1.mouAIniciCarril(triaCarril(1));
	}
//mover segundo coche
	if (m_areaTotal.solapa(m_cotxe2.getAreaOcupada()))
	{
		m_cotxe2.mou();
	}
	if (!m_areaTotal.solapa(m_cotxe2.getAreaOcupada()))
	{
		m_cotxe2.mouAIniciCarril(triaCarril(2));
	}
//mover tercer coche
	if (m_areaTotal.solapa(m_cotxe3.getAreaOcupada()))
	{
		m_cotxe3.mou();
	}
	if (!m_areaTotal.solapa(m_cotxe3.getAreaOcupada()))
	{
		m_cotxe3.mouAIniciCarril(triaCarril(3));
	}
//mover cuarto coche
	if (m_areaTotal.solapa(m_cotxe4.getAreaOcupada()))
	{
		m_cotxe4.mou();
	}
	if (!m_areaTotal.solapa(m_cotxe4.getAreaOcupada()))
	{
		m_cotxe4.mouAIniciCarril(triaCarril(4));
	}
//mover quinto coche
	if (m_areaTotal.solapa(m_cotxe5.getAreaOcupada()))
	{
		m_cotxe5.mou();
	}
	if (!m_areaTotal.solapa(m_cotxe5.getAreaOcupada()))
	{
		m_cotxe5.mouAIniciCarril(triaCarril(5));
	}

}

/**
 * Comprova si la granota ha mort.
 * @return true si la granota és morta i false si és viva.
 */
bool Pantalla::haMortLaGranota()
{
	bool mort = false;

	if ((m_cotxe1.getAreaOcupada().solapa(m_granota.getAreaOcupada()))
		|| (m_granota.getAreaOcupada().solapa(m_cotxe1.getAreaOcupada()))
				|| (m_cotxe2.getAreaOcupada().solapa(m_granota.getAreaOcupada()))
		|| (m_granota.getAreaOcupada().solapa(m_cotxe2.getAreaOcupada()))
				|| (m_cotxe3.getAreaOcupada().solapa(m_granota.getAreaOcupada()))
		|| (m_granota.getAreaOcupada().solapa(m_cotxe3.getAreaOcupada()))
				|| (m_cotxe4.getAreaOcupada().solapa(m_granota.getAreaOcupada()))
		|| (m_granota.getAreaOcupada().solapa(m_cotxe4.getAreaOcupada()))
				|| (m_cotxe5.getAreaOcupada().solapa(m_granota.getAreaOcupada()))
		|| (m_granota.getAreaOcupada().solapa(m_cotxe5.getAreaOcupada())))
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
	//declarar rana2 y == a la rana1 para el cambio de sprite a la hora de caminar
	if (m_areaTotal.solapa(m_granota.getAreaOcupada()))
	{
		switch (direccio){

			case 1:
					m_granota.mouEsquerra();
					m_granota.setGrafic(m_graficGranotaEsquerra2);

			break;
			
			case 2:
					m_granota.mouDreta();
					m_granota.setGrafic(m_graficGranotaDreta2);
			break;

			case 3: // DUDA:PREGUNTAR COMO HACER PARA CONTROLAR QUE LA 
					// RANA PUEDA MOVERSE SI LA CUEVA ESTA COMPLETA PERO
					// LA RANA AUN NO ESTA CERCA DE LA CUEVA!
				if (m_cova1.esAccessible(m_granota.getAreaOcupada()) &&
					m_cova2.esAccessible(m_granota.getAreaOcupada()) &&
					m_cova3.esAccessible(m_granota.getAreaOcupada()) &&
					m_cova4.esAccessible(m_granota.getAreaOcupada()) &&
					m_cova5.esAccessible(m_granota.getAreaOcupada())   )
				{
					if (true)
					{
						m_granota.mouAmunt();
					}
				}
				m_granota.setGrafic(m_graficGranotaAmunt2);
				

			break;

			case 4:
					m_granota.mouAvall();
					m_granota.setGrafic(m_graficGranotaAvall2);
			break;
			}

	}


}

//Funcio que mostra les vides
void Pantalla::mostraVides (int life, bool onedown)
{
	switch (life)
	{
		case 1:
			m_graficGranotaAmunt.dibuixa(INICI_X, FI_Y+10+m_graficGranotaAmunt.getScaleY());
			break;
			
		case 2:
			m_graficGranotaAmunt.dibuixa(INICI_X, FI_Y+10+m_graficGranotaAmunt.getScaleY());
			m_graficGranotaAmunt.dibuixa(INICI_X+m_graficGranotaAmunt.getScaleX(), FI_Y+10+m_graficGranotaAmunt.getScaleY());
			break;
		
		case 3:
			m_graficGranotaAmunt.dibuixa(INICI_X, FI_Y+10+m_graficGranotaAmunt.getScaleY());
			m_graficGranotaAmunt.dibuixa(INICI_X+m_graficGranotaAmunt.getScaleX(), FI_Y+10+m_graficGranotaAmunt.getScaleY());
			m_graficGranotaAmunt.dibuixa(INICI_X+(2*m_graficGranotaAmunt.getScaleX()), FI_Y+10+m_graficGranotaAmunt.getScaleY());
			break;

	}
}

void Pantalla::puntos100(int pointsup, int suma)
{
	int m_pointsup=pointsup;

	int score[5];
	int j;

	suma=suma;

	score[0]= ( suma ) / 10000 % 10 ;
	score[1]= ( suma ) / 1000 % 10;
	score[2]= ( suma ) / 100 % 10 ;
	score[3]= ( suma ) / 10 % 10;
	score[4]= ( suma ) % 10 ;


	if (m_pointsup >= 80 && m_pointsup != 666)
		{
			//m_graficPoints100.dibuixa(230,350);

			for(j=0;j<5;j++)												
					{
						if(score[j]==0)
						m_graficNum0.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),350);
						
						if(score[j]==1)
						m_graficNum1.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),350);
						
						if(score[j]==2)
						m_graficNum2.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),350);
						
						if(score[j]==3)
						m_graficNum3.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),350);
						
						if(score[j]==4)
						m_graficNum4.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),350);
						
						if(score[j]==5)
						m_graficNum5.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),350);
						
						if(score[j]==6)
						m_graficNum6.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),350);
						
						if(score[j]==7)
						m_graficNum7.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),350);
						
						if(score[j]==8)
						m_graficNum8.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),350);
						
						if(score[j]==9)
						m_graficNum9.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),350);
					//printf("%d\n",puntos);
			}


		}


	if ((m_pointsup < 80) && (m_pointsup > 20))
		{

			//m_graficPoints100.dibuixa(230,330);
			for(j=0;j<5;j++)												
					{
						if(score[j]==0)
						m_graficNum0.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),330);
						
						if(score[j]==1)
						m_graficNum1.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),330);
						
						if(score[j]==2)
						m_graficNum2.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),330);
						
						if(score[j]==3)
						m_graficNum3.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),330);
						
						if(score[j]==4)
						m_graficNum4.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),330);
						
						if(score[j]==5)
						m_graficNum5.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),330);
						
						if(score[j]==6)
						m_graficNum6.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),330);
						
						if(score[j]==7)
						m_graficNum7.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),330);
						
						if(score[j]==8)
						m_graficNum8.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),330);
						
						if(score[j]==9)
						m_graficNum9.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),330);
					//printf("%d\n",puntos);
			}
		}


	if ((m_pointsup < 20) && (m_pointsup > 0) )
		{

			//m_graficPoints100.dibuixa(230,310);
			for(j=0;j<5;j++)												
					{
						if(score[j]==0)
						m_graficNum0.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),310);
						
						if(score[j]==1)
						m_graficNum1.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),310);
						
						if(score[j]==2)
						m_graficNum2.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),310);
						
						if(score[j]==3)
						m_graficNum3.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),310);
						
						if(score[j]==4)
						m_graficNum4.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),310);
						
						if(score[j]==5)
						m_graficNum5.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),310);
						
						if(score[j]==6)
						m_graficNum6.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),310);
						
						if(score[j]==7)
						m_graficNum7.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),310);
						
						if(score[j]==8)
						m_graficNum8.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),310);
						
						if(score[j]==9)
						m_graficNum9.dibuixa((((FI_X - INICI_X)/2) - (5 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())),310);
					//printf("%d\n",puntos);
			}
		}

	if (m_pointsup==666)
	{
		m_graficPoints100.dibuixa(666,666);
	}
}

void Pantalla::GameOver(int nopls)
{
	int m_uSuck=nopls;
	if (m_uSuck >= 16)
		{
			m_GameOver1.dibuixa(0,0);
		}
	if ((m_uSuck < 16) && (m_uSuck > 12))
		{
			m_GameOver2.dibuixa(0,0);
		}
	if ((m_uSuck < 12) && (m_uSuck > 8))
		{
			m_GameOver3.dibuixa(0,0);
		}
	if ((m_uSuck <8) && (m_uSuck > 4))
		{

			m_GameOver4.dibuixa(0,0);
		}
	if ((m_uSuck < 4) && (m_uSuck >= 0) )
		{

			m_GameOver5.dibuixa(0,0);

		}


}


void Pantalla::LevelUp(int yespls)
{
	int m_uRock=yespls;
	if (m_uRock >= 16)
		{
			m_LevelUp1.dibuixa(0,0);

		}
	if ((m_uRock < 16) && (m_uRock > 12))
		{

			m_LevelUp2.dibuixa(0,0);
		}
	if ((m_uRock < 12) && (m_uRock > 8))
		{

			m_LevelUp3.dibuixa(0,0);
		}
	if ((m_uRock <8) && (m_uRock > 4))
		{

			m_LevelUp4.dibuixa(0,0);
		}
	if ((m_uRock < 4) && (m_uRock >= 0) )
		{

			m_LevelUp5.dibuixa(0,0);

		}


}

void Pantalla::tiemporestante(int tiempo, int tempmax)
{
	int digits[2];
	int i;



	digits[0]= ( tempmax - tiempo ) / 10000 % 10 ;
	digits[1]= ( tempmax - tiempo ) / 1000 % 10;

	for(i=0;i<2;i++)												
			{
				if(digits[i]==0)
				m_graficNum0.dibuixa((FI_X - INICI_X)/2 + (i*m_graficNum0.getScaleX()), FI_Y + m_graficNum0.getScaleY());
				
				if(digits[i]==1)
				m_graficNum1.dibuixa((FI_X - INICI_X)/2 + (i*m_graficNum0.getScaleX()), FI_Y + m_graficNum0.getScaleY());
				
				if(digits[i]==2)
				m_graficNum2.dibuixa((FI_X - INICI_X)/2 + (i*m_graficNum0.getScaleX()), FI_Y + m_graficNum0.getScaleY());
				
				if(digits[i]==3)
				m_graficNum3.dibuixa((FI_X - INICI_X)/2 + (i*m_graficNum0.getScaleX()), FI_Y + m_graficNum0.getScaleY());
				
				if(digits[i]==4)
				m_graficNum4.dibuixa((FI_X - INICI_X)/2 + (i*m_graficNum0.getScaleX()), FI_Y + m_graficNum0.getScaleY());
				
				if(digits[i]==5)
				m_graficNum5.dibuixa((FI_X - INICI_X)/2 + (i*m_graficNum0.getScaleX()), FI_Y + m_graficNum0.getScaleY());
				
				if(digits[i]==6)
				m_graficNum6.dibuixa((FI_X - INICI_X)/2 + (i*m_graficNum0.getScaleX()), FI_Y + m_graficNum0.getScaleY());
				
				if(digits[i]==7)
				m_graficNum7.dibuixa((FI_X - INICI_X)/2 + (i*m_graficNum0.getScaleX()), FI_Y + m_graficNum0.getScaleY());
				
				if(digits[i]==8)
				m_graficNum8.dibuixa((FI_X - INICI_X)/2 + (i*m_graficNum0.getScaleX()), FI_Y + m_graficNum0.getScaleY());
				
				if(digits[i]==9)
				m_graficNum9.dibuixa((FI_X - INICI_X)/2 + (i*m_graficNum0.getScaleX()), FI_Y + m_graficNum0.getScaleY());
				//printf("%d",digits[i]);
	}

}


void Pantalla::puntuacion(int puntos)
{
	int score[7];
	int j;

	puntos=puntos;

	score[0]= ( puntos ) / 1000000 % 10 ;
	score[1]= ( puntos ) / 100000 % 10 ;
	score[2]= ( puntos ) / 10000 % 10 ;
	score[3]= ( puntos ) / 1000 % 10;
	score[4]= ( puntos ) / 100 % 10 ;
	score[5]= ( puntos ) / 10 % 10;
	score[6]= ( puntos ) % 10 ;


	for(j=0;j<7;j++)												
			{
				if(score[j]==0)
				m_graficNum0.dibuixa((FI_X - (7 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())), FI_Y + (m_graficNum0.getScaleY()));
				
				if(score[j]==1)
				m_graficNum1.dibuixa((FI_X - (7 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())), FI_Y + (m_graficNum0.getScaleY()));
				
				if(score[j]==2)
				m_graficNum2.dibuixa((FI_X - (7 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())), FI_Y + (m_graficNum0.getScaleY()));
				
				if(score[j]==3)
				m_graficNum3.dibuixa((FI_X - (7 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())), FI_Y + (m_graficNum0.getScaleY()));
				
				if(score[j]==4)
				m_graficNum4.dibuixa((FI_X - (7 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())), FI_Y + (m_graficNum0.getScaleY()));
				
				if(score[j]==5)
				m_graficNum5.dibuixa((FI_X - (7 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())), FI_Y + (m_graficNum0.getScaleY()));
				
				if(score[j]==6)
				m_graficNum6.dibuixa((FI_X - (7 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())), FI_Y + (m_graficNum0.getScaleY()));
				
				if(score[j]==7)
				m_graficNum7.dibuixa((FI_X - (7 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())), FI_Y + (m_graficNum0.getScaleY()));
				
				if(score[j]==8)
				m_graficNum8.dibuixa((FI_X - (7 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())), FI_Y + (m_graficNum0.getScaleY()));
				
				if(score[j]==9)
				m_graficNum9.dibuixa((FI_X - (7 * m_graficNum0.getScaleX())  + (j*m_graficNum0.getScaleX())), FI_Y + (m_graficNum0.getScaleY()));
			
				printf("%d\n",puntos);
	}


}