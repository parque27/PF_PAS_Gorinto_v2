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

	int mida() const;
	void mostrar() const;
	void mostrar_pila(int i, int j) const;
	void posar_fitxa(int pos_i, int pos_j, Fitxa f);
	void posar_sender(char tipus_sender, int pos, Fitxa f);
	bool existeix_posicio(int i, int j) const;

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

