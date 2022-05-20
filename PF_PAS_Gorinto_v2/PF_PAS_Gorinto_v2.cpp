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
#include <limits>
#include <iomanip>
#include "Joc.h"
using namespace std;

// ------------------------ ACCIONS I FUNCIONS ------------------------- 
// INTRODUCCIO DE PARAMETRES PER PREPARAR LA PARTIDA
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
string* introduir_noms_jugadors(int n)
{
	string* noms = new string[n];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i = 0; i < n; i++)
	{
		string nom;
		cout << "ENTRA EL NOM DEL JUGADOR " << i+1 << ":" << endl;
		getline(cin, nom);
		noms[i] = nom;
	}
	return noms;
}

void jugada_amb_intercanvi(Joc& joc)
{

}

char introduir_sender(const Joc& joc)
{
	// Pre:
	// Post:
	cout << "DADES DE LA JUGADA QUE VOLS FER:" << endl;
	cout << "SENDER DEL QUAL VOLS AGAFAR LA FITXA:" << endl;
	char sender; cin >> sender;
	while (not joc.validar_tipus_sender(sender))
	{
		cout << "SENDER NO VALID" << endl;
		cout << "SENDER DEL QUAL VOLS AGAFAR LA FITXA:" << endl;
		cin >> sender;
	}
	return sender;
}
int introduir_pos_sender(const Joc& joc)
{
	// Pre:
	// Post:
	cout << "POSICIO DE LA FITXA EN EL SENDER:" << endl;
	int pos_fitxa_sender; cin >> pos_fitxa_sender;
	while (joc.validar_posicio_sender(pos_fitxa_sender))
	{
		cout << "POSICIO NO VALIDA" << endl;
		cout << "POSICIO DE LA FITXA EN EL SENDER:" << endl;
		cin >> pos_fitxa_sender;
	}
	return pos_fitxa_sender;
}
void introduir_posicio_muntanya_deixar(const Joc& joc, int& pos_i_deixar, int& pos_j_deixar)
{
	// Pre:
	// Post:
	cout << "POSICIO DE LA MUNTANYA ON VOLS DEIXAR UNA FITXA:" << endl;
	cin >> pos_i_deixar >> pos_j_deixar;
	while (not joc.validar_posicions_muntanya(pos_i_deixar, pos_j_deixar))
	{
		cout << "POSICIO NO VALIDA" << endl;
		cout << "POSICIO DE LA MUNTANYA ON VOLS DEIXAR UNA FITXA:" << endl;
		cin >> pos_i_deixar >> pos_j_deixar;
	}
}
void introduir_posicio_muntanya_agafar(const Joc& joc, int& pos_i_agafar, int& pos_j_agafar, const int pos_i_deixar, const int pos_j_deixar)
{
	// Pre:
	// Post:
	cout << "POSICIO DE LA MUNTANYA ON VOLS AGAFAR UNA FITXA:" << endl;
	cin >> pos_i_agafar >> pos_j_agafar; // COMPROVAR POS -> RANG MAT I TAULA
	while (not joc.validar_posicions_muntanya(pos_i_agafar, pos_j_agafar) and pos_i_agafar != pos_i_deixar and pos_j_agafar != pos_j_deixar)
	{
		cout << "POSICIO NO VALIDA" << endl;
		cout << "POSICIO DE LA MUNTANYA ON VOLS AGAFAR UNA FITXA:" << endl;
		cin >> pos_i_agafar >> pos_j_agafar;
	}
}

void jugada_sense_intercanvi(Joc& joc)
{
	// INTRODUCCIO I VALIDACIO DE DADES
	char sender = introduir_sender(joc);
	int pos_fitxa_sender = introduir_pos_sender(joc);
	int pos_i_deixar, pos_j_deixar;
	int pos_i_agafar, pos_j_agafar;
	introduir_posicio_muntanya_deixar(joc, pos_i_deixar, pos_j_deixar);
	introduir_posicio_muntanya_agafar(joc, pos_i_agafar, pos_j_agafar, pos_i_deixar, pos_j_deixar);
	// VALIDACIO DE JUGADA

	/*if (not jugada_valida))	cout << "JUGADA NO PERMESA" << endl;
	else joc.realitzar_jugada(sender, pos_fitxa_sender, pos_i_deixar, pos_j_deixar, pos_i_agafar, pos_j_agafar);*/
}

void comprovar_dades(int& i, int& j, const Joc& joc)
{
	bool dades_valides = joc.validar_posicions_muntanya(i, j);
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
bool validar_opcio(const char o)
{
	return o == 'I' or o == 'J' or o == 'D' or o == 'P' or o == 'F' or o == 'T';
}
char demanar_opcio()
{
	// Pre: --;
	// Post: retorna una opcio llegida de teclat
	cout << endl << "ENTRAR OPCIO:" << endl;
	char opcio; cin >> opcio;
	if (not validar_opcio(opcio)) cout << "OPCIO NO DEFINIDA" << endl;
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

		opcio = demanar_opcio();
	}

	// TRACTEM EL FINAL DE LA PARTIDA
	if (opcio == 'F') cout << endl << "PARTIDA ABANDONADA DESPRES DE " << joc.estacions() << " ESTACIONS I " << joc.torns_jugats() << " TORNS" << endl;
	else if (joc.es_final_partida()) joc.mostrar_resultat_final();
	return 0;
}