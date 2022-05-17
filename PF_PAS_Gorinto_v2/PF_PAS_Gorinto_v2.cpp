/*
    ----------------------------------------------
    METODOLOGIA I TECNOLOGIA DE LA PROGRAMACIO II
    PRACTICA FINAL: Gorinto
    ----------------------------------------------
    PAU ARQUEROS I SUREDA - u1972850
    GRAU EN ENGINYERIA INFORMATICA
    Universitat de Girona
    Curs 2021 - 2022
*/
/*
    ENTRADA:
    SORTIDA:
*/

#include <iostream>
#include "Joc.h"
using namespace std;

// ACCIONS I FUNCIONS
void COUTS()
{
	// Variables
	int numero_de_jugador, estacions, torns;

	// COUTs
	// cout << "ENTRA LA LLAVOR:" << endl;
	// cout << "ENTRA EL NUMERO DE JUGADORS:" << endl;
	// cout << "ENTRA EL NOM DEL JUGADOR " << numero_de_jugador << ":" << endl;
	// cout << endl << "OPCIONS:" << endl;
	// cout << "(I) FER JUGADA AMB INTERCANVI PREVI" << endl;
	// cout << "(J) FER JUGADA SENSE INTERCANVI PREVI" << endl;
	// cout << "(D) MOSTRAR DISPENSADOR" << endl;
	// cout << "(P) MOSTRAR UNA PILA DE LA MUNTANYA" << endl;
	// cout << "(F) ABANDONAR LA PARTIDA" << endl;
	// cout << endl << "ENTRAR OPCIO:" << endl;
	cout << "OPCIO NO DEFINIDA" << endl;
	cout << "SENDER DEL QUAL VOLS AGAFAR LA FITXA:" << endl;
	cout << "SENDER NO VALID" << endl;
	cout << "POSICIO DE LA FITXA EN EL SENDER:" << endl;
	cout << "POSICIO DE LA MUNTANYA ON VOLS DEIXAR UNA FITXA:" << endl;
	cout << "POSICIO DE LA MUNTANYA ON VOLS AGAFAR UNA FITXA:" << endl;
	cout << "POSICIO NO VALIDA" << endl;
	cout << "NO POTS FER INTERCANVI, NO TENS FITXES EN EL TEU GORINTO" << endl;
	cout << "ENTRA LA FITXA QUE VOLS INTERCANVIAR:" << endl;
	cout << "ENTRA LA FITXA QUE VOLS OBTENIR:" << endl;
	cout << "INTERCANVI NO VALID" << endl;
	cout << "DADES DE LA JUGADA QUE VOLS FER:" << endl;
	cout << "JUGADA NO PERMESA" << endl;
	cout << "POSICIO DE LA PILA:" << endl;
	cout << "POSICIO NO VALIDA" << endl;
	/*cout << endl << "PARTIDA ABANDONADA DESPRES DE " << estacions << " ESTACIONS I " << torns << " TORNS" << endl;
	cout << endl << "PARTIDA ACABADA DESPRES DE " << estacions << "	ESTACIONS I " << torns << " TORNS" << endl;*/
}
int introduir_llavor()
{
	cout << "ENTRA LA LLAVOR:" << endl;
	int llavor; cin >> llavor;
	return llavor;
}
int introduir_n_jugadors()
{
	cout << "ENTRA EL NUMERO DE JUGADORS:" << endl;
	int n; cin >> n;
	while (n < 2 or n > 4) // TODO: Canviar a constants
	{
		cout << "ENTRA EL NUMERO DE JUGADORS:" << endl;
		cin >> n;
	}
	return n;
}
void processar_jugadors(int n, Joc& joc)
{
	for (int i = 0; i < n; i++)
	{
		cout << "ENTRA EL NOM DEL JUGADOR " << i+1 << ":" << endl;
		string nom; cin >> nom;
	}
}
string* introduir_noms_jugadors(int n)
{
	string* noms = new string[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nom del jugador " << i + 1 << endl;
		cin >> noms[i];
	}
	return noms;
}
char demanar_opcio()
{
	// Pre: --;
	// Post: retorna una opcio llegida de teclat
	cout << endl << "ENTRAR OPCIO:" << endl;
	char opcio; cin >> opcio;
	if (opcio != 'P')
	{
		cout << "OPCIO NO DEFINIDA" << endl;
		opcio = 'R';
	}
	return opcio;
}
void mostrar_menu()
{
	// Pre: --;
	// Post: mostra el menu per pantalla
	cout << endl << "OPCIONS:" << endl;
	cout << "(I) FER JUGADA AMB INTERCANVI PREVI" << endl;
	cout << "(J) FER JUGADA SENSE INTERCANVI PREVI" << endl;
	cout << "(D) MOSTRAR DISPENSADOR" << endl;
	cout << "(P) MOSTRAR UNA PILA DE LA MUNTANYA" << endl;
	cout << "(F) ABANDONAR LA PARTIDA" << endl;
}
// OPCIO I
void jugada_amb_intercanvi(Joc& joc)
{

}

// OPCIO J
void jugada_sense_intercanvi(Joc& joc)
{

}

// OPCIO D IMLEMENTADA DIRECTAMENT
// OPCIO P
void comprovar_dades(int& i, int& j, const Joc& joc)
{
	bool dades_valides = joc.dades_valides(i, j);
	while (not dades_valides)
	{
		cout << "POSICIO NO VALIDA" << endl;
		cout << "POSICIO DE LA PILA:" << endl;
		cin >> i >> j;
	}
}
void mostrar_pila_muntanya(const Joc& joc)
{
	cout << "POSICIO DE LA PILA:" << endl;
	int pos_i, pos_j; cin >> pos_i >> pos_j;
	comprovar_dades(pos_i, pos_j, joc);
	joc.mostrar_pila_muntanya(pos_i, pos_j);
}

// MAIN
int main()
{
	// INCIALITZEM LES VARIABLES
	int llavor = introduir_llavor();
	int n_jugadors = introduir_n_jugadors();
	string* nom_jugadors = introduir_noms_jugadors(n_jugadors);
	Joc joc(llavor, n_jugadors, nom_jugadors);

	// INICIALTZEM LA PARTIDA
	joc.inicialitzar_partida();
	mostrar_menu();
	joc.mostrar_estat_actual();
	char opcio = demanar_opcio();

	// BUCLE DE JOC
	while (opcio != 'F' and not joc.es_final_partida())
	{
		if (opcio == 'I') jugada_amb_intercanvi(joc);
		else if (opcio == 'J') jugada_sense_intercanvi(joc);
		else if (opcio == 'D') joc.mostrar_dispensador();
		else if (opcio == 'P') mostrar_pila_muntanya(joc);

		joc.incrementa_torn(opcio);

		mostrar_menu();
		joc.mostrar_estat_actual();
		char opcio = demanar_opcio();
	}

	// TRACTEM EL FINAL DE LA PARTIDA
	if (opcio == 'F') cout << "ABANDONAMENT" << endl;
	else if (joc.es_final_partida()) cout << "FINAL NATURAL" << endl;
	return 0;
}