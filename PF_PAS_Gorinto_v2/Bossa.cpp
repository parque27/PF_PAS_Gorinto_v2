#include "Bossa.h"
#include <iostream>
using namespace std;

// CONSTRUCTORS
// CONSTRUCTOR PER DEFECTE
Bossa::Bossa()
{
	a_n = 0;
	a_max = 5;
	reserva();
}
// CONSTRUCTOR AMB PARAMETRES
Bossa::Bossa(unsigned llavor)
{
	a_n = 0;
	a_max = 5;
	a_llavor = llavor;

	reserva();
	omplir_bossa();
}
// CONSTRUCTOR COPIA
Bossa::Bossa(const Bossa& t)
{
	copia(t);
}

// DESTRUCTOR
Bossa::~Bossa()
{
	allibera();
}

// OPERADORS
Bossa& Bossa::operator= (const Bossa& t)
{
	if (this != &t)
	{
		allibera();
		copia(t);
	}
	return *this;
}

// METODES CONSULTORS
void Bossa::mostrar() const
{
	if (es_buida()) cout << "NO HI HA CAP FITXA";
	else {
		for (int i = 0; i < a_n; i++) a_t[i].mostra();
		cout << " ";
	}
	cout << endl;
}
bool Bossa::es_buida() const
{
	return a_n == 0;
}
// METODES MODIFICADORS
void Bossa::afegir_fitxa(const Fitxa& f)
{
	if (a_n == a_max) expandeix();
	a_t[a_n] = f;
	a_n++;
}
Fitxa Bossa::robar_fitxa()
{
	Fitxa f_robada = a_t[a_n - 1];
	a_n--;
	return f_robada;
}
void Bossa::barrejar()
{
	for (int i = a_n - 1; i > 0; i--)
	{
		int pos = this->generar_aleatori(i + 1);
		intercanvi(a_t[pos], a_t[i]);
	}
}
void Bossa::omplir_bossa()
{
	for (int i = 0; i < MAX_FITXES; i++)
	{

		if (i < 20)
		{
			Fitxa f('a', i + 1);
			afegir_fitxa(f);
		}
		else if (i >= 20 and i < 40)
		{
			Fitxa f('e', i - 19);
			afegir_fitxa(f);
		}
		else if (i >= 40 and i < 60)
		{
			Fitxa f('f', i - 39);
			afegir_fitxa(f);
		}
		else if (i >= 60 and i < 80)
		{
			Fitxa f('t', i - 59);
			afegir_fitxa(f);
		}
		else if (i >= 80 and i < MAX_FITXES)
		{
			Fitxa f('v', i - 79);
			afegir_fitxa(f);
		}
	}
}
int Bossa::generar_aleatori(int n)
{
	int aleatori = (((GENERADOR_A * a_llavor + GENERADOR_C) / 32) % GENERADOR_M) % n;
	a_llavor = GENERADOR_A * a_llavor + GENERADOR_C;
	return aleatori;
}

// METODES D'INSTANCIA
void Bossa::allibera()
{
	delete[] a_t;
}
void Bossa::reserva()
{
	a_t = new Fitxa[a_max];
}
void Bossa::copia(const Bossa& t)
{
	a_n = t.a_n;
	a_max = t.a_max;
	reserva();
	for (int i = 0; i < a_n; i++)
		a_t[i] = t.a_t[i];
}
void Bossa::intercanvi(Fitxa& f1, Fitxa& f2)
{
	Fitxa aux = f1;
	f1 = f2;
	f2 = aux;
}
void Bossa::expandeix()
{
	Fitxa* aux = a_t;
	a_max = 2 * a_max;
	reserva();
	for (int i = 0; i < a_n; i++)
		a_t[i] = aux[i];
	delete[] aux;
}