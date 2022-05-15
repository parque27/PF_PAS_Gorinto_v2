#include "Jugador.h"

Jugador::Jugador()
{
	a_nom = " ";
	a_gorinto = Gorinto();
	a_punts = 0;
	a_ordre = -1;
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