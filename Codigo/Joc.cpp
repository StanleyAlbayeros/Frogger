#include "Joc.h"
#include "lib\libreria.h"
#include "lib\event.h"
#include "lib\Grafic.h"
#include "Pantalla.h"
#include "Granota.h"


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
		x= x+7;
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

//Funcio que mostra les vides
void mostraVides (int vides, Grafic granotaVida)
{
	switch (vides)
	{
		case 1:
			granotaVida.dibuixa(INICI_X, FI_Y+10+granotaVida.getScaleY());
			break;
		
		case 2:
			granotaVida.dibuixa(INICI_X, FI_Y+10+granotaVida.getScaleY());
			granotaVida.dibuixa(INICI_X+granotaVida.getScaleX(), FI_Y+10+granotaVida.getScaleY());
			break;
		
		case 3:
			granotaVida.dibuixa(INICI_X, FI_Y+10+granotaVida.getScaleY());
			granotaVida.dibuixa(INICI_X+granotaVida.getScaleX(), FI_Y+10+granotaVida.getScaleY());
			granotaVida.dibuixa(INICI_X+(2*granotaVida.getScaleX()), FI_Y+10+granotaVida.getScaleY());
			break;

	}
}

/**
 * Juga una partida de tres vides
 *
 * @param nivell nivell de la partida
 * @return
 */
int juga(int nivell)
{
	t_programStatus estat;
	
	// Inicialitzem
	InitGame (estat);
	Pantalla pantalla;
	char tecla = 0; // Variable char on desar la tecla pulsada
	int haMortLaGranota = 0; // Variable boleana per saber si la granota esta morta
	int punts = 0; // Punts acumulats durant la partida
	int vides = 3; // Vides que li queden a la granota
	pantalla.inicia(vides);
	Video_ShowWindow();
	//pantalla.dibuixa();
	// Inizialitza llavor per a la funci� rand()
	srand((unsigned) time(NULL));

	do
	{
		haMortLaGranota = 0;

		ProcessEvents (estat); // Captura els events que s'han produit en el darrer cicle

		if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
		{
			estat.bExit=true;
		}
		//mouGranota(X) x=1->4 1=left 2=right 3=up 4=down
		if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
		{
			pantalla.mouGranota(1);
			
		}
		if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
		{
			pantalla.mouGranota(2);
		}

		if (Keyboard_GetKeyTrg(KEYBOARD_UP))
		{
			pantalla.mouGranota(3);
		}

		if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
		{
			pantalla.mouGranota(4);
		}

		// Secuencia de control del coche
		pantalla.mouCotxe();


		if (pantalla.haMortLaGranota())
		{
			vides= vides-1;
			pantalla.inicia(3);
		}

		if (pantalla.esGranotaDinsCova())
		{
			punts += 100 * nivell;
			nivell+=1;

			if (nivell<4)
			{
				pantalla.inicia(nivell+1);
			}
		}


		// Dibuixa els gràfics
		pantalla.dibuixa();

		VideoUpdate(estat); // Actualitza la pantalla

	} while ((nivell < 4) && (vides > 0) && (!estat.bExit));


	Video_Release(); // Allibera els recursos

	return punts;
}
