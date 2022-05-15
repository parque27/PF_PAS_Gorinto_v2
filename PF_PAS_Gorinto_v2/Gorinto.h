#ifndef GORINTO_H
#define GORINTO_H
#include "Fitxa.h"
class Gorinto
{
	// DEFINICIO:
	// INVARIABLE:
public:
	// CONSTRUCTUROS
	Gorinto();
	// Pre: --; Post: el gorinto es buit
	Gorinto(const Gorinto& o);
	// Pre: --; Post: el gorinto es una copia de o

	// DESTRUCTOR
	~Gorinto();
	// Pre: --; Post: memoria alliberada

	// OPERADORS
	Gorinto& operator= (const Gorinto& o);
	// Pre: --; Post: aquest gorinto es una copia de o

	// METODES CONSULTORS
	bool es_buida() const;
	// Pre: --; Post: retorna true si el gorinto es buit, false altrament
	bool existeix(Fitxa f) const;
	// Pre: llista no buida; Post: retorna true si f existeix al gorinto, fals altrament
	void mostrar() const;
	// Pre: --; Post: mostra el gorinto per pantalla
	int calcular_puntuacio() const; // TODO!
	// Pre: --; Post: retorna la puntuacio total del jugador
	int n_fitxes() const; 
	// Pre: --; Post: retorna el nombre de fitxes al gorinto
	
	// METODES MODIFICADORS
	void inserir(Fitxa f);
	// Pre: --; Post: insereix la fitxa f de forma ordenada
	void eliminar(Fitxa f);
	// Pre: la llista es buida; Post: es borra f de la llista

private:
	// ESTRUCTURA DE DADES
	struct Node
	{
		Fitxa f;
		Node* seg;
	};

	// ATRIBUTS
	Node* a_inici;

	// METODES D'INSTANCIA
	void copia(const Gorinto& o);
	// Pre: --; Post:
	void allibera();
	// Pre: --; Post:
};
#endif // !GORINTO_H