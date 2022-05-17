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

		// MOSTRAR ALGUNA COSA
		void mostrar_estat_actual() const;
		void mostrar_estat_jugadors() const;
		void mostrar_resultat_final() const;
		void mostrar_dispensador() const;
		void mostrar_pila_muntanya(int pos_i, int pos_j) const;

		// COMPROVACIO DE COSES
		bool es_final_partida() const;
		bool dades_valides(int pos_i, int pos_j) const;

		// METODES MODIFICADORS
		void inicialitzar_partida();
		void canvi_estacio();
		void incrementa_torn(char opcio);
		void fer_jugada();
		void intercanvi_gorinto_amb_sender();

	private:
		// ATRIBUTS
		Bossa a_bossa;
		Dispensador a_dispensador;
		Tauler a_tauler;

		int a_n_jugadors;
		Jugador* p;
		Jugador* a_taula_jugadors;

		int a_estaico;
		int a_torn;

		// METODES PRIVATS
		void buidar_senders();
		void emplenar_dispensador();
		void emplenar_tauler();
		void emplenar_nivell(int inici, int final);
};
#endif // !JOC_H