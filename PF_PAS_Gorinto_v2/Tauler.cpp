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
bool Tauler::existeix_posicio_muntanya(int pos_i, int pos_j) const
{
	return pos_i >= 0 and pos_i <= a_mida and pos_j >= 0 and pos_j <= a_mida;
}
bool Tauler::existeix_posicio_sender(int pos_i) const
{
	return pos_i >= 0 and pos_i <= a_mida;
}
bool Tauler::es_buida_posicio_muntanya(int pos_i, int pos_j) const
{
	return a_muntanya[pos_i][pos_j].es_buida();
}
bool Tauler::es_buida_posicio_sender(char sender, int pos_i) const
{
	bool es_buida = false;
	if (sender == 'h') es_buida = a_sender_h[pos_i].es_nula();
	else es_buida = a_sender_v[pos_i].es_nula();
	return es_buida;
}
bool Tauler::es_jugada_valida(char sender, int pos_fitxa_sender, int pos_i_deixar, int pos_j_deixar, int pos_i_agafar, int pos_j_agafar) const
{
	return
		not es_buida_posicio_muntanya(pos_i_agafar, pos_j_agafar) and
		not es_buida_posicio_sender(sender, pos_fitxa_sender) and
		coincideixen_sender_muntanya(sender, pos_fitxa_sender, pos_i_deixar, pos_j_deixar) and
		es_valid_patro_seleccio(sender, pos_fitxa_sender, pos_i_deixar, pos_j_deixar, pos_i_agafar, pos_j_agafar);
}
bool Tauler::es_valid_patro_seleccio(char sender, int pos_fitxa_sender, int pos_i_deixar, int pos_j_deixar, int pos_i_agafar, int pos_j_agafar) const
{
	bool patro_seleccio_correcte = false;

	if (sender == 'h')
	{
		if (a_sender_h[pos_fitxa_sender].tipus_element() == 'a')
		{

		}
	}
	/*
	else if (a_sender_h[pos_fitxa_sender].tipus_element() == 'e')
	else if (a_sender_h[pos_fitxa_sender].tipus_element() == 'f')
	else if (a_sender_h[pos_fitxa_sender].tipus_element() == 't')
	else if (a_sender_h[pos_fitxa_sender].tipus_element() == 'v')
}
else
{
	if (a_sender_h[pos_fitxa_sender].tipus_element() == 'a')
	else if (a_sender_v[pos_fitxa_sender].tipus_element() == 'e')
	else if (a_sender_v[pos_fitxa_sender].tipus_element() == 'f')
	else if (a_sender_v[pos_fitxa_sender].tipus_element() == 't')
	else if (a_sender_v[pos_fitxa_sender].tipus_element() == 'v')
}*/
	return patro_seleccio_correcte;
}
bool Tauler::patro_seleccio_aigua(int i, int j, int pos_i_agafar, int pos_j_agafar) const
{
	// pos on deixem: i,j
	bool trobat = false;
	int n = -2;
	while (not existeix_posicio_muntanya(i, j + n) and j + n != pos_j_agafar and not trobat and n < 2)
	{
		if ((existeix_posicio_muntanya(i, j + n) and j + n == pos_j_agafar and n <=2)) trobat = true;
		else n++;
	}
	return trobat;
}
bool Tauler::patro_seleccio_eter(int i, int j, int pos_i_agafar, int pos_j_agafar) const
{
	bool trobat = false;
	if (existeix_posicio_muntanya(i - 1, j - 1) and i - 1 == pos_i_agafar and j - 1 == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i - 1, j + 1) and i - 1 == pos_i_agafar and j + 1 == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i + 1, j - 1) and i + 1 == pos_i_agafar and j - 1 == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i + 1, j + 1) and i + 1 == pos_i_agafar and j + 1 == pos_j_agafar) trobat = true;
	return trobat;
}
bool Tauler::patro_seleccio_terra(int i, int j, int pos_i_agafar, int pos_j_agafar) const
{
	bool trobat = false;
	if (existeix_posicio_muntanya(i-1, j-1) and i-1 == pos_i_agafar and j-1 == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i - 1, j) and i - 1 == pos_i_agafar and j == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i - 1, j+1) and i - 1 == pos_i_agafar and j == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i, j - 1) and i == pos_i_agafar and j - 1== pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i, j + 1) and i == pos_i_agafar and j + 1== pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i+1, j-1) and i + 1 == pos_i_agafar and j - 1 == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i+1, j) and i + 1 == pos_i_agafar and j == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i+1, j+1) and i + 1 == pos_i_agafar and j + 1 == pos_j_agafar) trobat = true;
	return trobat;
}
bool Tauler::patro_seleccio_foc(int i, int j, int pos_i_agafar, int pos_j_agafar) const
{
	bool trobat = false;
	if (existeix_posicio_muntanya(i - 2, j) and i - 2 == pos_i_agafar and j == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i - 1, j) and i - 1 == pos_i_agafar and j == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i + 1, j) and i + 1 == pos_i_agafar and j == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i + 2, j) and i + 2 == pos_i_agafar and j == pos_j_agafar) trobat = true;
	return trobat;
}
bool Tauler::patro_seleccio_vent(int i, int j, int pos_i_agafar, int pos_j_agafar) const
{
	bool trobat = false;
	if (existeix_posicio_muntanya(i - 1, j) and i - 1 == pos_i_agafar and j == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i, j-1) and i == pos_i_agafar and j-1 == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i, j+1) and i == pos_i_agafar and j+1 == pos_j_agafar) trobat = true;
	else if (existeix_posicio_muntanya(i+1, j) and i+1 == pos_i_agafar and j == pos_j_agafar) trobat = true;
	return trobat;
}
bool Tauler::coincideixen_sender_muntanya(char sender, int pos_sender, int pos_i_deixar, int pos_j_deixar) const
{
	bool concorden_posicions = false;
	if (sender == 'h') concorden_posicions = pos_sender == pos_j_deixar;
	else concorden_posicions = pos_sender == pos_i_deixar;
	return concorden_posicions;
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