#include "Joc.h"
#include "lib\libreria.h"
#include "lib\event.h"
#include "lib\Grafic.h"
#include "Pantalla.h"
#include "Granota.h"
#include <time.h>


/**
 * Correspon la posicio a la gespa?
 * @param x coordenada horitzontal de la posicio
 * @param y coordenada vertical de la posicio
 * @return 1 (true) si és gespa i 0 (false) si no ho és
 */
int esGespa(int x, int y)
{
	return (y >= FI_Y - 1) || (y < INICI_Y + 3);
}


/**
 * Tria un carril pel que circular.
 * Ho fa aleatoriament entre tots els carrils disponibles.
 *
 * Tenir en compte que:
 * El primer carril disponible es troba a la linia (INICI_Y + 3).
 * El darrer carril disponible es troba a la linia FI_Y - 2 = (INICI_Y + 3) + (FI_Y - INICI_Y - 4) - 1
 * En aplicar el mòdul 'rand() % B', el resultat és un valor enter entre 0 i B-1.
 * @return carril pel que circular
 */
int triaCarril()
{
	return (INICI_Y+3) + ( rand()% ((FI_Y-35)-INICI_Y));
}

/**
 * Mou el cotxe representat per un caracter a la posició donada.
 * Si el cotxe es troba al final d'un carril, llavors es coloca al principi d'un nou carril.
 * @param x coordenada horitzontal de la posicio del caracter
 * @param y coordenada vertical de la posicio del caracter
 * @param hScreen
 */
void mouCotxe(int &x, int &y)
{
	if (x < FI_X)
	{
		x = x+7;
	}
	else
	{
		x = INICI_X;
		y = triaCarril();
	}
}

/**
 * Mou la granota representada per un caracter a la posició donada.
 * @param x coordenada horitzontal de la posicio del caracter
 * @param y coordenada vertical de la posicio del caracter
 * @param despX desplaçament de la granota en l'eix horitzontal (despX > 0 mou a la dreta, despX < 0 mou a l'esquerra)
 * @param despY desplaçament de la granota en l'eix vertical (despY > 0 mou avall, despY < 0 mou amunt)
 * @param hScreen
 */
void mouGranota(int &x, int &y, int despX, int despY)
{
	x += despX;
	y += despY;
}



/**
 * Juga una partida de tres vides
 *
 * @param nivell nivell de la partida
 * @return
 */
int juga(int nivell, bool animacio)
{
	t_programStatus estat;
	
	// Inicialitzem
	InitGame (estat);
	Pantalla pantalla;
	char tecla = 0;				// Variable char on desar la tecla pulsada
	int countdown = 100000000;	// iniciamos una cuenta atrás para evitar que se pueda ganar el juego manteniendo dir(up)!
	int haMortLaGranota = 0;	// Variable boleana per 
								//saber si la granota esta morta

	int iter = 0;				//controla gameover/levelup
	int punts = 0;				// Punts acumulats durant la partida
	int vides = 3;				// Vides que li queden a la granota
	int count = 10;
	int dir = 0;
	int puntscount= 0 ;
	int sumapunts = 0 ; 
	int covaOcupada = 0;
	int covaCount = 0;
	bool onedown = false;		//controla la animacion de perder vida TODO
	int gameover = THEEND;
	bool end = false;
	bool godmode = false;
	int tempmax = 60000;		//tiempo máximo utilizado para el contador de las cuevas.
								//1k =  1 segundo, 60k = 60segundos

	if (nivell == 4 )
	{
		nivell = 3;
		godmode=true;
	}

	//variables usadas para el countdown
	clock_t t;
	clock_t t2;
	t = clock();
	t2 = clock();

	pantalla.inicia(nivell);
	Grafic granotaVida;
	granotaVida.crea("data/GraficsGranota/Granota_Amunt_1.png");
	Video_ShowWindow();

	// Inizialitza llavor per a la funci� rand()
	srand((unsigned) time(NULL));

	do
	{
		haMortLaGranota = 0;
		//bucle pequeño para evitar que se pueda ganar solo pulsando arriba
		while (countdown != 0) 
		{
			countdown--;
		}

		ProcessEvents (estat);	// Captura els events que 
								// s'han produit en el darrer cicle
		
		if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
		{
			estat.bExit = true;
		}
		//direcciones
			if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
			{
				dir = 1;
				pantalla.mouGranota(dir);
			}
			
			if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
			{
				dir = 2;
				pantalla.mouGranota(dir);
			}

			if (Keyboard_GetKeyTrg(KEYBOARD_UP))
			{
				dir = 3;
				pantalla.mouGranota(dir);
			}

			if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
			{
				if (!godmode)
					{
					dir = 4;
					pantalla.mouGranota(dir);
					}
			}


		t2 = clock() -t;	//guardamos en t2 la diferencia de tiempo desde
							// t hasta ahora
		// Cotxes
		pantalla.mouCotxes();
						

		if (pantalla.haMortLaGranota() || (t2 >= tempmax) )
		{
			vides = vides-1;
			pantalla.reset(nivell);
			t = clock();
			t2 = t;
		}

		//puntuación que depende del nivel y de cada cueva!
		if ( pantalla.esGranotaDinsCova() )
			{
				puntscount = THEEND*5;				
				covaCount++;
				sumapunts = ((tempmax - t2) * nivell )/1000;			//formula para calcular el score
				punts += sumapunts;
				pantalla.reset(nivell);
				t = clock();
				t2 = t;

			}

		//REVISAMOS SI HEMOS OCUPADO TODAS LAS CUEVAS
		if ( covaCount == 5 )
			{
				// pantalla del LevelUp, el if controla si queremos animaciones de pantalla
				if (animacio)
				{
				iter = 4;
				do {
					
					pantalla.LevelUp(gameover);
					gameover--;
					if (gameover == 0){ gameover = THEEND ; iter--; }
					VideoUpdate(estat); // Actualitza la pantalla
				
					} while (iter != 0);
				}

				nivell+=1;
				tempmax = tempmax - 15000;	//si pasamos el nivel, el contador comienza
											//con 15 segundos menos para completar el juego
				if (nivell<4)
				{
					pantalla.inicia(nivell+1);
				}
				countdown = 100000;
				covaCount = 0;
			}

		
		
		count--;// Contador que controla alternar las graficas de Granota
		
		// Dibuixa els gràfics
		pantalla.dibuixa(dir, count);
		
		if (count == 0)
			{
			count = 10;
			}
		// vidas de la rana
		pantalla.mostraVides(vides, onedown);

		// pantalla de Gameover
		if (vides == 0 && animacio)
		{	
			iter = 4;
			do {
				pantalla.GameOver(gameover);
				gameover--;
				if (gameover == 0){ gameover = THEEND ; iter--; }
				VideoUpdate(estat); // Actualiza la pantalla
				} while (iter != 0);
		}

		if (animacio)
		{
			pantalla.puntos100(puntscount, sumapunts);
			puntscount--;
		}

		//tiempo restante
		pantalla.tiemporestante(t2, tempmax);

		pantalla.puntuacion(punts);

		VideoUpdate(estat); // Actualitza la pantalla

	} while (/*(nivell < 4) &&*/ (vides != 0) && (!estat.bExit));

	Video_Release(); // Allibera els recursos

	return punts;
}
