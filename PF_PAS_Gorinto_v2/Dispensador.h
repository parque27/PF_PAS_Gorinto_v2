#ifndef DISPENSADOR_H
#define DISPENSADOR_H
#include "Fitxa.h"

class Dispensador
{
	// DESCRIPCCIO:
	// INVARIABLE:
public:

	// CONSTRUCTORS
	Dispensador();
	// Pre: --; Post: cua buida
	Dispensador(const Dispensador& o);
	// Pre: --; Post: aquesta cua es copia de la cua o

	// DESTRUCTOR
	~Dispensador();
	// Pre: --; Post: memoria alliberada

	// OPERADORS
	Dispensador& operator=(const Dispensador& o);
	// Pre: --; Post: aquesta cua es copia de o

	// METODES CONSULTORS
	bool es_buida() const;
	// Pre: --; Post: retorna true si la cua es buida, fals altrament
	void primera() const;
	// Pre: cua no buida; Post: mostra la fitxa que esta la primera de la cua
	Fitxa primer() const;
	void mostrar() const;
	// Pre: --; Post: mostra les fitxes que estan encuades

	// METODES MODIFICADORS
	void encua(Fitxa f);
	// Pre: --; Post: ha afegit la fitxa f al final de la cua
	void desencua();
	// Pre: cua no buida; Post: ha eliminat el primer element de la cua

private:
	// ESTRUCTURA DE DADES
	struct Node
	{
		Fitxa f;
		Node* seg;
	};

	// ATRIBUTS
	Node* a_primera;
	Node* a_ultima;

	// METODES D'INSTANCIA
	void copia(const Dispensador& o);
	// Pre: cua buida; Post: aquesta cua es copia de o
	void allibera();
	// Pre: --; Post: cua buida
};
#endif // !CUA_H