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
	if (opcio != 'I' or opcio != 'J' or opcio != 'D' or opcio != 'P' or opcio != 'F')
		cout << "OPCIO NO DEFINIDA" << endl;
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

// MAIN
int main()
{
	int llavor = introduir_llavor();
	int n_jugadors = introduir_n_jugadors();
	string* nom_jugadors = introduir_noms_jugadors(n_jugadors);

	Joc joc(llavor, n_jugadors, nom_jugadors);
	joc.inicialitzar_partida();
	
	mostrar_menu();
	// LA PARTIDA POT INICIAR


	return 0;
}