#ifndef JUGADOR_H
#define JUGADOR_H
#include "Gorinto.h"
#include <string>
using namespace std;

class Jugador
{
	// DEFINICIO:
	// INVARIABLE:
public:
	// CONSTRUCTORS
	Jugador();
	Jugador(string nom, int ordre_torn);

	// OPERADORS
	bool operator >(const Jugador& j) const;

	// METODES CONSULTORS
	void mostrar() const;
	// Pre: --; Post: mostra la informacio del jugador per pantalla
	int ordre() const;
	// Pre: --; Post: mostra l'ordre del jugador.
	string nom() const;
	// Pre: --; Post: 

	// METODES MODIFICADORS
	void treure_fitxa();
	void afegir_fitxa(Fitxa f);

private:
	// CONSTANTS DE CLASSE
	// ESTRUCTURES DE DADES
	// ATRIBUTS
	string a_nom;
	Gorinto a_gorinto;
	int a_punts;
	int a_ordre;

	// METODES PRIVATS
	void actualitzar_punts();
};
#endif // !JUGADOR_H
