#include "Joc.h"
#include <iostream>
using namespace std;

// CONSTRUCTORS
Joc::Joc()
{
	a_bossa = Bossa();
	a_dispensador = Dispensador();
	a_tauler = Tauler();

	a_n_jugadors = 0;
	a_taula_jugadors = NULL;
}
Joc::Joc(int llavor, int n_jugadors, string* noms)
{
	a_bossa = Bossa(llavor);
	a_dispensador = Dispensador();
	a_tauler = Tauler();

	a_n_jugadors = n_jugadors;
	a_taula_jugadors = new Jugador[a_n_jugadors];

	for (int i = 0; i < a_n_jugadors; i++)
		a_taula_jugadors[i] = Jugador(noms[i], i);
}

// METODES CONSULTORS
void Joc::debug_mostrar_estat() const
{
	// Mostra les piles de fitxes
	cout << "PILES:" << endl;
	for (int i = 0; i < a_tauler.mida(); i++)
		for (int j = 0; j < a_tauler.mida(); j++)
			a_tauler.mostrar_pila(i, j);

	// Mostra el tauler
	cout << "TAULER:" << endl;
	a_tauler.mostrar();
}
// METODES MODIFICADORS
void Joc::inicialitzar_partida()
{
	a_bossa.barrejar();
	emplenar_dispensador();
	emplenar_tauler();
}

// METODES PRIVATS
void Joc::buidar_senders()
{

}
void Joc::emplenar_dispensador()
{
	while (not a_bossa.es_buida())
		a_dispensador.encua(a_bossa.robar_fitxa());
}
void Joc::emplenar_tauler()
{
	emplenar_nivell(0, a_tauler.mida());     // 25 fitxes
	emplenar_nivell(0, a_tauler.mida());     // 
	emplenar_nivell(1, a_tauler.mida() - 1); // 9 fitxes
	emplenar_nivell(2, a_tauler.mida() - 2); // 1 fitxa

	for (int i = 0; i < a_tauler.mida(); i++)
	{
		a_tauler.posar_sender('h', i, a_dispensador.primer());
		a_dispensador.desencua();
	}
	for (int i = 0; i < a_tauler.mida(); i++)
	{
		a_tauler.posar_sender('v', i, a_dispensador.primer());
		a_dispensador.desencua();
	}
}
void Joc::emplenar_nivell(int inici, int final)
{
	for (int i = inici; i < final; i++) 
	{
		for (int j = inici; j < final; j++) {
			a_tauler.posar_fitxa(i, j, a_dispensador.primer());
			a_dispensador.desencua();
		}
	}
}