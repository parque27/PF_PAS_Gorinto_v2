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
    ENTRADA: Una llavor, nombre de jugadors, i els seus noms
    SORTIDA: El joc del GORINTO implementat amb les seves funcions corresponents.
*/

#include <iostream>
#include <limits>
#include <iomanip>
#include "Joc.h"
using namespace std;
const int MIN_JUGADORS = 2;
const int MAX_JUGADORS = 4;
// ------------------------ ACCIONS I FUNCIONS ------------------------- 
unsigned introduir_llavor()
{
    // Pre:
    // Post: retorna la llavor introduida per teclat
    cout << "ENTRA LA LLAVOR:" << endl;
    unsigned llavor; cin >> llavor;
    return llavor;
}
int introduir_n_jugadors()
{
    // Pre:
    // Post: retorna el nombre de jugadors de la partida
    cout << "ENTRA EL NUMERO DE JUGADORS:" << endl;
    int n; cin >> n;
    while (n < MIN_JUGADORS or n > MAX_JUGADORS) // TODO: Canviar a constants
    {
        cout << "ENTRA EL NUMERO DE JUGADORS:" << endl;
        cin >> n;
    }
    return n;
}
string* introduir_noms_jugadors(int n)
{
    // Pre: MIN_JUGADORS <= n <= MAX_JUGADORS
    // Post: retorna un punter a un array de noms
    string* noms = new string[n];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; i++)
    {
        string nom;
        cout << "ENTRA EL NOM DEL JUGADOR " << i + 1 << ":" << endl;
        getline(cin, nom);
        noms[i] = nom;
    }
    return noms;
}
void jugada_amb_intercanvi(Joc& joc)
{
    // NO IMPLEMENTADA
}
char introduir_sender(const Joc& joc)
{
    // Pre:
    // Post: retorna el caracter corresponent al sender
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
    // Pre: --
    // Post: retorna la posicio del sender
    cout << "POSICIO DE LA FITXA EN EL SENDER:" << endl;
    int pos_fitxa_sender; cin >> pos_fitxa_sender;
    while (not joc.validar_posicio_sender(pos_fitxa_sender))
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
    // Post: s'ha introduit les posicions i,j de les fitxes que es treuen
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
    // Post: s'ha introduit les posicions i,j de les fitxes que s'agafen
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
    // Pre: 
    // Post: realitza una jugada sense intercanvi previ
    // INTRODUCCIO I VALIDACIO DE DADES
    char sender = introduir_sender(joc);
    int pos_fitxa_sender = introduir_pos_sender(joc);
    int pos_i_deixar, pos_j_deixar;
    int pos_i_agafar, pos_j_agafar;
    introduir_posicio_muntanya_deixar(joc, pos_i_deixar, pos_j_deixar);
    introduir_posicio_muntanya_agafar(joc, pos_i_agafar, pos_j_agafar, pos_i_deixar, pos_j_deixar);

    while (not(joc.validar_jugada(sender, pos_fitxa_sender, pos_i_deixar, pos_j_deixar, pos_i_agafar, pos_j_agafar)))
    {
        cout << "JUGADA NO PERMESA" << endl;
        char sender = introduir_sender(joc);
        int pos_fitxa_sender = introduir_pos_sender(joc);
        introduir_posicio_muntanya_deixar(joc, pos_i_deixar, pos_j_deixar);
        introduir_posicio_muntanya_agafar(joc, pos_i_agafar, pos_j_agafar, pos_i_deixar, pos_j_deixar);
    }
    joc.realitzar_jugada(sender, pos_fitxa_sender, pos_i_deixar, pos_j_deixar, pos_i_agafar, pos_j_agafar);
}
void comprovar_dades(int& i, int& j, const Joc& joc)
{
    // Pre:
    // Post: les dades de la pila que es troba a i,j son correctes
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
    // Pre:
    // Post: mostra la pila per patnalla
    cout << "POSICIO DE LA PILA:" << endl;
    int pos_i, pos_j; cin >> pos_i >> pos_j;
    comprovar_dades(pos_i, pos_j, joc);
    joc.mostrar_pila_muntanya(pos_i, pos_j);
}
bool validar_opcio(const char o)
{
    // Pre: --
    // Post: retorna true si la opcio o es un dels caracters especificats, fals altrament
    return o == 'I' or o == 'J' or o == 'D' or o == 'P' or o == 'F';
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

// ------------------------------ MAIN -------------------------------- 
int main()
{
    unsigned llavor = introduir_llavor();
    int n_jugadors = introduir_n_jugadors();
    string* nom_jugadors = introduir_noms_jugadors(n_jugadors);
    Joc joc(llavor, n_jugadors, nom_jugadors);
    joc.inicialitzar_partida();
    mostrar_menu();
    joc.mostrar_estat_actual();
    char opcio = demanar_opcio();
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
    if (opcio == 'F') cout << endl << "PARTIDA ABANDONADA DESPRES DE " << joc.estacions() << " ESTACIONS I " << joc.torns_jugats() << " TORNS" << endl;
    else if (joc.es_final_partida()) joc.mostrar_resultat_final();
    return 0;
}