#include "Menu.h"
#include "Joc.h"
#include "GestioResultats.h"

#define OPCIO_JUGAR '1'
#define OPCIO_DIFFICULTAT '2'
#define OPCIO_ANIMACIONS '3'
#define OPCIO_PUNTUACIO '4'
#define OPCIO_SORTIR '5'

/**
 * Programa principal que permet jugar al joc de la granota (frog) desant puntuacions
 * @return
 */
int main()
{
	char opcio;
	int punts;
	int posicio = -1;
	char nivell = '1';
	char lletra = 'y';
	bool animacions = true;
	TipusJugador millorsJugadors[MAX_MILLORSJUGADORS];
	iniciaTaulaMillorJugadors(millorsJugadors);

	do
	{
		mostraMenuPrincipal();
		opcio = _getch(); // Llegeix tecla apretada
		switch (opcio)
		{
			case OPCIO_JUGAR:
				punts = juga(nivell-'0',animacions); // COMPTE!: aquí hi ha una conversió de char a int
				posicio = haMilloratPuntuacio(millorsJugadors, punts);
				if (posicio >= 0) // Ha millorat puntuacio
				{
					desplacaArray(millorsJugadors, posicio);
					emplenaPosicioArray(millorsJugadors[posicio], punts);
				}
				break;
			case OPCIO_DIFFICULTAT:
				do
				{
					mostraMenuNivellDificultat();
					nivell = _getch(); // Llegeix tecla apretada
					// Comprova si tecla es valida
					if ((nivell != '1') && (nivell != '2') && (nivell != '3') && (nivell != '4'))
					{
						printf("Try again\n"); // Mostra text
						Sleep(2000);
					}
				} while ((nivell != '1') && (nivell != '2') && (nivell != '3') && (nivell != '4')); // Repeteix mentre tecla no valida
				break;

			case OPCIO_ANIMACIONS:
				do
				{
					mostraMenuanimacions();
					lletra = _getch(); // Llegeix tecla apretada
					// Comprova si tecla es valida
					if ((lletra != 'y') && (lletra != 'Y') && (lletra != 'n') && (lletra != 'N'))
					{
						printf("Try again\n"); // Mostra text
						Sleep(2000);
					}
					switch (lletra)
					{
					case 'y':
						animacions = true;
						break;

					case 'Y':
						animacions = true;
						break;
					
					case 'n':
						animacions = false;
						break;
					
					case 'N':
						animacions = false;
						break;
					}

				} while ((lletra != 'y') && (lletra != 'Y') && (lletra != 'n') && (lletra != 'N')); // Repeteix mentre tecla no valida
				break;
			case OPCIO_PUNTUACIO:
				escriuRanking(millorsJugadors);
				printf("Press a key to return to the main menu\n");
				_getch(); // Llegeix tecla apretada
				break;
			
		}
	} while (opcio != OPCIO_SORTIR);
	return 0;
}
