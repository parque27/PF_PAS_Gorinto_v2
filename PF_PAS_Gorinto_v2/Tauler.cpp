#include "Tauler.h"
#include <iostream>
#include <iomanip>
using namespace std;

// CONSTRUCTORS
Tauler::Tauler()
{
	a_mida = 5;
	a_sender_h = NULL;
	a_sender_v = NULL;
	a_muntanya = NULL;
	reserva();
}
Tauler::Tauler(int mida)
{
	a_mida = mida;
	a_sender_h = NULL;
	a_sender_v = NULL;
	a_muntanya = NULL;
	reserva();
}
Tauler::Tauler(const Tauler& o)
{
	copia(o);
}
// DESTRUCTOR
Tauler::~Tauler()
{
	allibera();
}
// OPERADOR
Tauler& Tauler::operator=(const Tauler& o)
{
	if (this != &o)
	{
		allibera();
		copia(o);
	}
	return *this;
}

// METODES PUBLICS
int Tauler::recompte_fitxes_sender() const
{
	int recompte = 0;
	for (int i = 0; i < a_mida; i++)
		if (not a_sender_h->es_nula()) recompte++;
	for (int i = 0; i < a_mida; i++)
		if (not a_sender_v->es_nula()) recompte++;
	return recompte;
}
int Tauler::mida() const
{
	return a_mida;
}
void Tauler::mostrar_pila(int i, int j) const
{
	a_muntanya[i][j].mostra();
}
void Tauler::mostrar() const
{
	cout << setfill(' ') << setw(6) << ' ';
	for (int i = 0; i < a_mida; i++)
	{
		cout << setfill(' ') << setw(6) << i;
	}
	cout << endl;
	cout << setfill(' ') << setw(8) << ' ';
	for (int i = 0; i < a_mida; i++)
	{
		cout << " ";
		a_sender_h[i].mostra();
	}
	cout << endl << endl;
	for (int i = 0; i < a_mida; i++)
	{
		cout << i << " "; a_sender_v[i].mostra();
		cout << " ";
		for (int j = 0; j < a_mida; j++)
		{
			cout << " ";
			if (not a_muntanya[i][j].es_buida()) a_muntanya[i][j].cim().mostra();
			else cout << "(   )";
		}
		cout << endl;
	}
}
void Tauler::posar_fitxa(int pos_i, int pos_j, Fitxa f)
{
	a_muntanya[pos_i][pos_j].empila(f);
}
Fitxa Tauler::treure_fitxa_sender(char tipus_sender, int pos_i)
{
	Fitxa fitxa_a_treure;
	if (tipus_sender == 'v' and not a_sender_v[pos_i].es_nula()) a_sender_v[pos_i] = fitxa_a_treure;
	else if (tipus_sender == 'h' and not a_sender_h[pos_i].es_nula()) a_sender_h[pos_i] = fitxa_a_treure;

	return fitxa_a_treure;
}
void Tauler::posar_sender(char tipus_sender, int posicio, Fitxa f)
{
	if (tipus_sender == 'v') a_sender_v[posicio] = f;
	else if (tipus_sender == 'h') a_sender_h[posicio] = f;
}
bool Tauler::existeix_posicio(int pos_i, int pos_j) const
{
	return pos_i >= 0 and pos_i <= a_mida and pos_j >= 0 and pos_j <= a_mida;
}
// METODES PRIVATS
void Tauler::copia(const Tauler& o)
{
	a_mida = o.a_mida;
	reserva();
	for (int i = 0; i < a_mida; i++)
		for (int j = 0; j < a_mida; j++)
			a_muntanya[i][j] = o.a_muntanya[i][j];
}
void Tauler::reserva()
{
	a_muntanya = new PilaFitxes * [a_mida];
	for (int i = 0; i < a_mida; i++)
		a_muntanya[i] = new PilaFitxes[a_mida];
	a_sender_h = new Fitxa[a_mida];
	a_sender_v = new Fitxa[a_mida];
}
void Tauler::allibera()
{
	for (int i = 0; i < a_mida; i++) delete[] a_muntanya[i];
	delete[] a_muntanya;
}
void Tauler::allibera_sender(char tipus_sender)
{
	if (tipus_sender == 'h') delete[] a_sender_h;
	else if (tipus_sender == 'v') delete[] a_sender_v;
}