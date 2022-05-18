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

// METODES QUE MOSTREN
void Joc::mostrar_estat_actual() const
{
	cout << endl << "TORN DE " << a_jugador_actual << endl <<
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
void Joc::mostrar_pila_muntanya(int pos_i, int pos_j) const
{
	a_tauler.mostrar_pila(pos_i, pos_j);
}

// METODES BOOLEANS
bool Joc::es_final_partida() const
{
	return a_estaico == 4 and es_final_estacio();
}
bool Joc::es_final_estacio() const
{
	return a_tauler.recompte_fitxes_sender() < a_n_jugadors;
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
	a_estaico++;
	// Descartar fitxes dels senders
	buidar_senders();
	// Emplenar senders de nou
	emplenar_sender('h');
	emplenar_sender('v');
	// Jugador que tenia torn passa a ser el 1r de la nova estacio
}
void Joc::incrementa_torn(char opcio)
{
	if (opcio == 'I' or opcio == 'J')
	{
		a_torn++;
		if (a_jugador_actual->ordre() == a_n_jugadors)
			a_jugador_actual = a_taula_jugadors;
		else a_jugador_actual++;

		if (es_final_estacio())
			if (es_final_partida()) mostrar_resultat_final();
			else canvi_estacio();
		// Seguim a la mateixa estacio
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
	for (int i = 0; i < a_tauler.mida(); i++)
	{
		a_dispensador.encua(a_tauler.treure_fitxa_sender('h', i));
		a_tauler.allibera_sender('h');	// NO FUNCA
	}

	for (int i = 0; i < a_tauler.mida(); i++)
	{ 
		a_dispensador.encua(a_tauler.treure_fitxa_sender('v', i));
		a_tauler.allibera_sender('v');	// NO FUNCA
	}
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

	emplenar_sender('h');
	emplenar_sender('v');

}
void Joc::emplenar_sender(char tipus_sender)
{
	if (tipus_sender == 'h')
	{
		for (int i = 0; i < a_tauler.mida(); i++)
		{
			a_tauler.posar_sender('h', i, a_dispensador.primer());
			a_dispensador.desencua();
		}
	}
	else if (tipus_sender == 'v')
	{
		for (int i = 0; i < a_tauler.mida(); i++)
		{
			a_tauler.posar_sender('v', i, a_dispensador.primer());
			a_dispensador.desencua();
		}
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