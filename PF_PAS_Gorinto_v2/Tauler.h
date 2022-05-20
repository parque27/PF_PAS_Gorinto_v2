#ifndef TAULER_H
#define TAULER_H
#include "PilaFitxes.h"
class Tauler
{
	// DESCRIPCCIO:
	// INVARIABLE:
public:
	Tauler();
	Tauler(int mida);
	Tauler(const Tauler& o);
	~Tauler();

	Tauler& operator=(const Tauler& o);

	// METODES ENTERS
	int mida() const;
	int recompte_fitxes_sender() const;
	// METODES MOSTRATIUS
	void mostrar() const;
	void mostrar_pila(int i, int j) const;

	// METODES BOOLEANS
	bool existeix_posicio_muntanya(int i, int j) const;
	bool existeix_posicio_sender(int i) const;

	bool es_buida_posicio_muntanya(int i, int j) const;
	bool es_buida_posicio_sender(char sender, int i) const;

	bool es_jugada_valida(char sender, int pos_fitxa_sender, int pos_i_deixar, int pos_j_deixar, int pos_i_agafar, int pos_j_agafar) const;
	bool es_valid_patro_seleccio(char sender, int pos_fitxa_sender, int pos_i_deixar, int pos_j_deixar, int pos_i_agafar, int pos_j_agafar) const;
	bool coincideixen_sender_muntanya(char sender, int pos_sender, int pos_i_deixar, int pos_j_deixar) const;

	// METODES MODIFICADORS
	void posar_fitxa(int pos_i, int pos_j, Fitxa f);
	Fitxa treure_fitxa_sender(char tipus_sender, int pos_i);
	void posar_sender(char tipus_sender, int pos, Fitxa f);
	void allibera_sender(char tipus_sender);

private:
	int a_mida;
	PilaFitxes** a_muntanya;
	Fitxa* a_sender_h;
	Fitxa* a_sender_v;

	void copia(const Tauler& o);
	void reserva();
	void allibera();
	// CANVIADES
	bool patro_seleccio_aigua(int pos_i_deixar, int pos_i_agafar, int distancia_j) const;
	bool patro_seleccio_foc(int pos_j_deixar, int pos_j_agafar, int distancia_i) const;

	// PER CANVIAR
	bool patro_seleccio_vent(int pos_i_agafar, int pos_j_agafar, int pos_i_deixar, int pos_j_deixar) const;
	bool patro_seleccio_terra(int pos_i_agafar, int pos_j_agafar, int pos_i_deixar, int pos_j_deixar) const;
	bool patro_seleccio_eter(int pos_i_deixar, int pos_j_deixar, int pos_i_agafar, int pos_j_agafar) const;
};
#endif // !TAULER_H

