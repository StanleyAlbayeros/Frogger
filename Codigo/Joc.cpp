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
	Pantalla();
	// Inicialitzem
	InitGame (estat);

	//Grafic granota;
	Grafic fons;
	Grafic cotxe;

	//granota.crea("data/GraficsGranota/Granota_Amunt_1.png");

	fons.crea("data/GraficsGranota/fons.png");
	cotxe.crea("data/GraficsGranota/Cotxe_1.png");

	int posicioCotxeX, posicioCotxeY; // Posicio del cotxe per coordenades (X,Y)
	//int posicioGranotaX, posicioGranotaY;   // Posicio de la granota per coordenades (X,Y)
	//int DESPLACAMENT_GRANOTA = granota.getScaleY()/2; //Desplaçament de la granota
	//int DESPLACAMENT_COTXE= 4; //Desplaçament del cotxe
	char tecla = 0; // Variable char on desar la tecla pulsada
	int velocitatCotxe= nivell*DESPLACAMENT_COTXE;
	int contFreCotxe = velocitatCotxe / nivell*2; // Comptador per a frenar l'avanç del cotxe
	int haMortLaGranota = 0; // Variable boleana per saber si la granota esta morta
	int punts = 0; // Punts acumulats durant la partida
	int vides = 3; // Vides que li queden a la granota

	//Pantalla();


	//Mostrem la finestra
	Video_ShowWindow();

	// Inizialitza llavor per a la funci� rand()
	srand((unsigned) time(NULL));

	// Inicialitzaci� de la posici� de la granota
	//posicioGranotaX = INICI_X + ((FI_X - INICI_X) / 2) - granota.getScaleX()/2;
	//posicioGranotaY = INICI_Y_GRANOTA;

	// Inicialitzaci� de la posici� del cotxe
	posicioCotxeX = INICI_X;
	posicioCotxeY = triaCarril();


	do
	{
		haMortLaGranota = 0;

		ProcessEvents (estat); // Captura els events que s'han produit en el darrer cicle

		if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
		{
			estat.bExit=true;
		}

		if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
		{
			// Si la posició de la granota és més gran que el límit esquerra + el desplaçament de cada moviment
			if (posicioGranotaX > (INICI_X + DESPLACAMENT_GRANOTA))
			{
				// Movem la granota cap a l'esquerra
				posicioGranotaX -= DESPLACAMENT_GRANOTA;
				
			}
		}
		if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
		{

			// Si la posició de la granota + el tamany en horizontal de la granota és més petita que el límit dret - el desplaçament de cada moviment
			if ((posicioGranotaX+granota.getScaleX())<(FI_X-DESPLACAMENT_GRANOTA))
			{
				// Movem la granota cap a la dreta
				posicioGranotaX += DESPLACAMENT_GRANOTA;
			}
		}

		if (Keyboard_GetKeyTrg(KEYBOARD_UP))
		{

			// Si la posició de la granota + el tamany en horizontal de la granota és més petita que el límit dret - el desplaçament de cada moviment
			if ((posicioGranotaY+granota.getScaleY())>(INICI_Y-DESPLACAMENT_GRANOTA))
			{
				// Movem la granota cap a la dreta
				posicioGranotaY -= DESPLACAMENT_GRANOTA;
			}
		}

		if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
		{

			// Si la posició de la granota + el tamany en horizontal de la granota és més petita que el límit dret - el desplaçament de cada moviment
			if ((posicioGranotaY+granota.getScaleY())<(FI_Y+DESPLACAMENT_GRANOTA))
			{
				// Movem la granota cap a la dreta
				posicioGranotaY += DESPLACAMENT_GRANOTA;
			}
		}

		// Secuencia de control del coche
		if (contFreCotxe==0)
		{
			mouCotxe(posicioCotxeX, posicioCotxeY);
			contFreCotxe = velocitatCotxe / nivell;
		}
		contFreCotxe--;


		if ((posicioGranotaX<posicioCotxeX+cotxe.getScaleX())&&(posicioGranotaX+granota.getScaleX()>posicioCotxeX)
			&&(posicioGranotaY<posicioCotxeY+cotxe.getScaleY())&&(posicioGranotaY+granota.getScaleY()>posicioCotxeY))
		{
			vides= vides-1;
			
			if (vides>0)
			{
				posicioGranotaX = INICI_X + ((FI_X - INICI_X) / 2) - granota.getScaleX()/2;
				posicioGranotaY = INICI_Y_GRANOTA;
			}
		}

		if (posicioGranotaY+granota.getScaleY()<INICI_Y-7)
		{
			punts += 100 * nivell;
			nivell+=1;

			if (nivell<4)
			{
				posicioGranotaX = INICI_X + ((FI_X - INICI_X) / 2) - granota.getScaleX()/2;
				posicioGranotaY = INICI_Y_GRANOTA;
			}
		}


		// Dibuixa els gràfics
		fons.dibuixa(0,0);
		granota.dibuixa(posicioGranotaX, posicioGranotaY);
		cotxe.dibuixa(posicioCotxeX, posicioCotxeY);
		mostraVides (vides, granota);

		VideoUpdate(estat); // Actualitza la pantalla

	} while ((nivell < 4) && (vides > 0) && (!estat.bExit));

	granota.destrueix();
	fons.destrueix();
	cotxe.destrueix();

	Video_Release(); // Allibera els recursos

	return punts;
}
