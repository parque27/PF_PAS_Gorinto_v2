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
	bool existeix_posicio(int i, int j) const;

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
};
#endif // !TAULER_H

