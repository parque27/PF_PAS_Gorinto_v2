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
		Joc(unsigned& llavor, int n_jugadors, string* nom_jugadors);

		// MOSTRAR ALGUNA COSA
		void mostrar_estat_actual() const;
		void mostrar_estat_jugadors() const;
		void mostrar_resultat_final() const;
		void mostrar_dispensador() const;
		void mostrar_pila_muntanya(int pos_i, int pos_j) const;
		int torns_jugats() const;
		int estacions() const;

		// COMPROVACIO DE COSES
		bool es_final_partida() const;
		bool es_final_estacio() const;
		// VALIDACIO DE DADES
		bool validar_posicions_muntanya(int pos_i, int pos_j) const;
		bool validar_posicio_sender(int pos_i) const;
		bool validar_tipus_sender(char sender) const;
		bool validar_jugada(char sender, int pos_fitxa_sender, int pos_i_deixar, int pos_j_deixar, int pos_i_agafar, int pos_j_agafar) const;

		// METODES MODIFICADORS
		void inicialitzar_partida();
		void canvi_estacio();
		void incrementa_torn(char opcio);
		void posar_fitxa_muntanya();
		void intercanvi_gorinto_amb_sender();
		void realitzar_jugada(char sender, int pos_fitxa_sender, int pos_i_deixar, int pos_j_deixar, int pos_i_agafar, int pos_j_agafar);
	private:
		// ATRIBUTS
		Bossa *a_bossa;
		Dispensador a_dispensador;
		Tauler a_tauler;

		int a_n_jugadors;
		Jugador* a_jugador_actual;
		Jugador* a_taula_jugadors;

		int a_estaico;
		int a_torn;

		// METODES PRIVATS
		void buidar_senders();
		void emplenar_dispensador();
		void emplenar_tauler();
		void emplenar_sender(char tipus_sender);
		void emplenar_nivell(int inici, int final);

		bool comprovar_concordancia_sender_muntanya(char sender, int pos_sender, int pos_i_deixar, int pos_j_deixar);

};
#endif // !JOC_H