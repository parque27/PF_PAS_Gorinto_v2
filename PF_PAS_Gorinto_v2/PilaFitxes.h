#ifndef PILAFITXES_H
#define PILAFITXES_H
#include "Fitxa.h"
class PilaFitxes
{
	// DESCRIPCCIO: Una pila dinamica de fitxes
	// INVARIABLE:
public:
	// CONSTRUCTORS
	PilaFitxes();
	// Pre: --; Post: pila buida
	PilaFitxes(const PilaFitxes& o);
	// Pre: --; Post: aquesta pila es una copia de o

	// DESTRUCTOR
	~PilaFitxes();
	// Pre: --; Post: memoria alliberada

	// OPERADORS
	PilaFitxes& operator=(const PilaFitxes& o);
	// Pre: --; Post: aquesta cua es una copia de o

	// METODES CONSULTORS
	bool es_buida() const;
	// Pre: --; Post: retorna true si la pila es buida, fals altrament
	Fitxa cim() const;
	// Pre: pila no buida; Post: retorna la fitxa que esta al cim de la pila
	void mostra() const;
	// Pre: --; Post: mostra la pila de fitxes separades per tres espais

	// METODES MODIFICADORS
	void empila(Fitxa f);
	// Pre: --; Post: ha empilat la fitxa f al cim de la pila
	void desempila();
	// Pre: pila no buida; Post: ha desempilat la fitxa del cim de la pila

private:
	// ESTRUCTURA DE DADES
	struct Node
	{
		Fitxa f;
		Node* seg;
	};

	// ATRIBUTS
	Node* a_cim;

	// METODES D'INSTANCIA
	void copia(const PilaFitxes& o);
	// Pre: pila buida; Post: aquesta pila es copia de o
	void allibera();
	// Pre: --; Post: pila buida
};
#endif // !PILAFITXES_H

