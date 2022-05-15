#include "PilaFitxes.h"
#include <iostream>
using namespace std;

// CONSTRUCTORS
// CONSTRUCTOR PER DEFECTE
PilaFitxes::PilaFitxes()
{
	a_cim = NULL;
}
// CONSTRUCTOR COPIA
PilaFitxes::PilaFitxes(const PilaFitxes& o)
{
	a_cim = NULL; // Abans de copiar res, posem el cim a NULL
	copia(o); // Ara ho copiem (veure impl. del metode)
}
// DESTRUCTOR
PilaFitxes::~PilaFitxes()
{
	allibera();
}
// OPERADORS
PilaFitxes& PilaFitxes::operator=(const PilaFitxes& o)
{
	if (this != &o)
	{
		allibera();
		copia(o);
	}
	return *this;
}

// METODES CONSULTORS
bool PilaFitxes::es_buida() const
{
	return a_cim == NULL;
}

Fitxa PilaFitxes::cim() const
{
	return a_cim->f;
}

void PilaFitxes::mostra() const
{
	Node* p = new Node;
	p = a_cim;
	while (p != NULL)
	{
		p->f.mostra(); cout << " ";
		p = p->seg;
	}
	delete p;
	cout << endl;
}
// METODES MODIFICADRS
void PilaFitxes::empila(Fitxa fitxa)
{
	Node* nou = new Node; // reservem memoria "virtual"?
	nou->f = fitxa; // la fitxa f apuntada per nou = fitxa a empilar
	nou->seg = a_cim; // el node seg de nou apunta al mateix lloc que a_cim (NULL en el n=1 cas, a_cim en n=2,3...)
	a_cim = nou; // a_cim apunta al mateix lloc que apunta nou (es a dir al nou node que volem empilar)
}

void PilaFitxes::desempila()
{
	Node* aux = a_cim;
	a_cim = a_cim->seg;
	delete aux;
}

// METODES D'INSTANCIA
void PilaFitxes::allibera()
{
	while (not es_buida())
	{
		Node* aux = a_cim;
		a_cim = a_cim->seg;
		delete aux;
	}
}

void PilaFitxes::copia(const PilaFitxes& o)
{
	if (not o.es_buida())
	{
		Node* p, * q, * aux;
		p = new Node;
		a_cim = p;
		aux = o.a_cim;
		p->f = aux->f;
		p->seg = NULL;
		q = p;
		aux = aux->seg;
		while (aux != NULL)
		{
			p = new Node;
			q->seg = p;
			p->f = aux->f;
			p->seg = NULL;
			q = p;
			aux = aux->seg;
		}
	}
}