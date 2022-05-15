#ifndef JOC_H
#define JOC_H
#include "Jugador.h"
#include "Bossa.h"
#include "Dispensador.h"
#include "Tauler.h"
class Joc
{
	// DEFINICIO: La classe joc gestiona els torns, els jugadors i els altres elements del joc
	// INVARIABLE:

	public:
		// CONSTRUCTORS
		Joc();
		Joc(int llavor, int n_jugadors, string* nom_jugadors);

		// METODES CONSULTORS
		void mostrar_resultat_final() const;
		void debug_mostrar_estat() const;

		// METODES MODIFICADORS
		void inicialitzar_partida();

	private:
		// ATRIBUTS
		Bossa a_bossa;
		Dispensador a_dispensador;
		Tauler a_tauler;

		int a_n_jugadors;
		int a_estaico;
		Jugador* a_taula_jugadors;

		// METODES PRIVATS
		void buidar_senders();
		void emplenar_dispensador();
		void emplenar_tauler();
		void emplenar_nivell(int inici, int final);
};
#endif // !JOC_H