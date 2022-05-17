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
	a_estaico = 1;
	a_torn = 1;
	a_taula_jugadors = NULL;
}
Joc::Joc(int llavor, int n_jugadors, string* noms)
{
	a_bossa = Bossa(llavor);
	a_dispensador = Dispensador();
	a_tauler = Tauler();

	a_n_jugadors = n_jugadors;
	a_estaico = 1;
	a_torn = 1;
	a_taula_jugadors = new Jugador[a_n_jugadors];

	for (int i = 0; i < a_n_jugadors; i++)
		a_taula_jugadors[i] = Jugador(noms[i], i+1);
}

// METODES CONSULTORS
void Joc::mostrar_estat_actual() const
{
	cout << endl << "TORN DE " << "<nom>" << endl <<
		"====================" << endl;
	cout << endl << "ESTAT DEL JOC - ESTACIO " << a_estaico << endl;
	cout << endl << "TAULER" << endl;
	a_tauler.mostrar();
	mostrar_estat_jugadors();
}
void Joc::mostrar_estat_jugadors() const
{
	for (int i = 0; i < a_n_jugadors; i++)
		a_taula_jugadors[i].mostrar();
}
void Joc::mostrar_resultat_final() const
{

}
void Joc::mostrar_dispensador() const
{
	a_dispensador.mostrar();
}
bool Joc::es_final_partida() const
{
	return a_estaico == 4;
}
void Joc::mostrar_pila_muntanya(int pos_i, int pos_j) const
{
	a_tauler.mostrar_pila(pos_i, pos_j);
}
bool Joc::dades_valides(int pos_i, int pos_j) const
{
	return a_tauler.existeix_posicio(pos_i, pos_j);
}
// METODES MODIFICADORS
void Joc::inicialitzar_partida()
{
	a_bossa.barrejar();
	emplenar_dispensador();
	emplenar_tauler();
}
void Joc::canvi_estacio()
{

}
void Joc::incrementa_torn(char opcio)
{
	if (opcio == 'I' or opcio == 'J')
	{
		// CAL INCREMENTAR TORN

	}
}
void Joc::fer_jugada()
{

}
void Joc::intercanvi_gorinto_amb_sender()
{

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