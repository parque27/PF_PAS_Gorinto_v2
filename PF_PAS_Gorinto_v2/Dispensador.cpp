#include "Dispensador.h"
#include <iostream>
using namespace std;

// CONSTRUCTORS
// CONSTRUCTOR PER DEFECTE
Dispensador::Dispensador()
{
	a_primera = a_ultima = NULL; // El primer node es igual a l'ultim, que apunta a NULL. Per tant, tot es NULL.
}
// CONSTRUCTOR COPIA
Dispensador::Dispensador(const Dispensador& o)
{
	a_primera = a_ultima = NULL;
	copia(o);
}

// DESTRUCTOR
Dispensador::~Dispensador()
{
	allibera(); // El destructor crida a una funcio privada que allibera la memoria.
}

// OPERADORS
Dispensador& Dispensador::operator=(const Dispensador& o)
{
	if (this != &o)
	{
		allibera();
		copia(o);
	}
	return *this;
}

// METODES CONSULTORS
bool Dispensador::es_buida() const
{
	return a_primera == NULL; // Retornem true si el primer node apunta a NULL, fals altrament.
}
void Dispensador::primera() const
{
	a_primera->f.mostra(); // Cridem la accio mostra() de la fitxa del primer node de la cua.
}
Fitxa Dispensador::primer() const
{
	return a_primera->f;
}
void Dispensador::mostrar() const
{

	Node* p = new Node;
	p = a_primera;
	while (p != NULL)
	{
		p->f.mostra(); cout << " ";
		p = p->seg;
	}
	delete p;
	cout << endl;
}

// METODES MODIFICADORS
void Dispensador::encua(Fitxa fitxa)
{
	Node* nou = new Node;
	nou->f = fitxa;
	nou->seg = NULL;
	if (es_buida())
		a_primera = a_ultima = nou;
	else
	{
		a_ultima->seg = nou;
		a_ultima = nou;
	}
}
void Dispensador::desencua()
{
	Node* aux = a_primera;
	if (a_primera == a_ultima) a_primera = a_ultima = NULL;
	else a_primera = a_primera->seg;
	delete aux;
}

// METODES D'INSTNACIA
void Dispensador::copia(const Dispensador& o)
{
	Node* p = o.a_primera;
	while (p != NULL)
	{
		encua(p->f);
		p = p->seg;
	}
}
void Dispensador::allibera()
{
	while (a_primera != NULL)
	{
		Node* aux = a_primera;
		a_primera = a_primera->seg;
		delete aux;
	}
	a_ultima = NULL;
}
