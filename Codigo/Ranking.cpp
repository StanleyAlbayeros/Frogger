#include "cRanking.h"
#include <stdio.h>
#include <iostream>

#include <fstream>
using namespace std;


//===================================================================================
// NOM: InicialitzarTaulaMillorJugadors
//===================================================================================
// DESCRIPCIÓ: Inicialitza la taula que guarda les millors puntuacions amb totes les
// puntuacions a 0
//===================================================================================
void cRanking::InicialitzarTaulaMillorJugadors()
{
	int i;

	for(i=0;i<MAX_MILLORSJUGADORS;i++)
	{
		strcpy(millorsJugadors[i].nom,"--------------");
		millorsJugadors[i].puntuacio=0;
	}
}


//===================================================================================
// NOM: EsMillorPuntuacio
//===================================================================================
// DESCRIPCIÓ: Mira si la puntuació que es passa a "punts" és millor que alguna de les
// que hi ha guardada a la taula de millors puntuacions. Si és millor, retorna l'índex
// de la primera posició de la taula que s'ha trobat amb una puntuació inferior. Si no 
// en troba cap d'inferior retorna un -1
//===================================================================================
int cRanking::EsMillorPuntuacio(int punts)
{
	int i=0;
	int trobat=0;

	do
	{
		if(millorsJugadors[i].puntuacio < punts)
		{
			trobat=1;
		}
		i++;

	}while ((i<MAX_MILLORSJUGADORS) && (!trobat));

	if (trobat)
	{
		return (i-1);
	}
	else
	{
		return -1;
	}
}

//===================================================================================
// NOM: DesplacarArray
//===================================================================================
// DESCRIPCIÓ: Mou tots els registres de la taula a partir de "posicio" una posicio a
// la dreta per deixar lloc a un nou registre de puntuacions
//===================================================================================
void cRanking::DesplacarArray(int posicio)
{
	int i;

	for (i=MAX_MILLORSJUGADORS-1; i>posicio; i--)
	{
		strcpy(millorsJugadors[i].nom,millorsJugadors[i-1].nom);
		millorsJugadors[i].puntuacio=millorsJugadors[i-1].puntuacio;
	}
}

//===================================================================================
// NOM: EmplenarPosicioArray
//===================================================================================
// DESCRIPCIÓ: omple un registre de puntuacions ("jugador") amb els punts que es passen
// com a paràmetre i el nom que s'introdueix per teclat
//===================================================================================
void cRanking::EmplenarPosicioArray(int posicio,int punts)
{
	printf("Entra el teu nom\n");
	scanf("%s",&(millorsJugadors[posicio].nom));
	millorsJugadors[posicio].puntuacio=punts;
}


//===================================================================================
// NOM: EscriuRanking
//===================================================================================
// DESCRIPCIÓ: mostra per pantalla les millors puntuacions
//===================================================================================
void cRanking::EscriuRanking()
{
	int i;

	for(i=0;i<MAX_MILLORSJUGADORS;i++)
	{
		printf("%d.- %s %d\n", i+1, millorsJugadors[i].nom, millorsJugadors[i].puntuacio);
	}

}
void cRanking::LlegirPuntuacions()
{
	ifstream llegir;
	bool correcte;
	bool final;
	int i = 0;

	llegir.open(NOM_FITXER);
	correcte = llegir.is_open();
	final = llegir.eof();
	if(correcte)
	{
		while(!final && (i<MAX_MILLORSJUGADORS))
		{
			llegir >> millorsJugadors[i].nom;
			llegir >> millorsJugadors[i].puntuacio;
			i++;
			final = llegir.eof();
		}
	}
	llegir.close();
}
void cRanking::EscriurePuntuacions()
{
	ofstream escriure;
	int i = 0;
	bool correcte;
	bool final;

	escriure.open(NOM_FITXER);
	correcte = escriure.is_open();
	final = escriure.eof();
	if(correcte)
	{
		while(!final && (i<MAX_MILLORSJUGADORS))
		{	
			escriure << millorsJugadors[i].nom <<'\t' << millorsJugadors[i].puntuacio << '\n';
			i++;
			final = escriure.eof();
		}
	}
	escriure.close();
}