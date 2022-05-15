#include "Jugador.h"
#include <iostream>
using namespace std;

Jugador::Jugador()
{
	a_nom = " ";
	a_gorinto = Gorinto();
	a_punts = 0;
	a_ordre = 0;
}

Jugador::Jugador(string nom, int ordre)
{
	a_nom = nom;
	a_gorinto = Gorinto();
	a_punts = 0;
	a_ordre = ordre;
}

bool Jugador::operator>(const Jugador& j) const
{
	bool es_major = a_punts > j.a_punts;
	if (a_punts == j.a_punts)
	{
		// evaluar fitxes gorinto
	}
	return es_major;
}

void Jugador::mostrar() const
{
	cout << endl;
	cout << "JUGADOR " << a_ordre << ": " << a_nom << endl;
	cout << "PUNTS DE SAVIESA: " << a_punts << endl;
	cout << "GORINTO: "; a_gorinto.mostrar();
}