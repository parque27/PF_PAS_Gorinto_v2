#ifndef BOSSA_H
#define BOSSA_H
#include "Fitxa.h"
class Bossa
{
public:
	// CONSTRUCTORS
	Bossa();
	Bossa(unsigned llavor);
	Bossa(const Bossa& o);
	// DESTRUCTOR
	~Bossa();
	// OPERADORS
	Bossa& operator= (const Bossa& o);

	// METODES CONSULTORS
	void mostrar() const;
	bool es_buida() const;

	// METODES MODIFICADORS
	Fitxa robar_fitxa();
	void afegir_fitxa(const Fitxa& f);
	void barrejar();

private:
	// CONSTANTS DE CLASSE
	const int MAX_FITXES = 100;
	const int GENERADOR_A = 1103515245;
	const int GENERADOR_C = 12345;
	const int GENERADOR_M = 32768;

	// ATRIBUTS
	int a_n;
	int a_max;
	Fitxa* a_t;

	unsigned a_llavor;

	// METODES PRIVATS
	void intercanvi(Fitxa& f1, Fitxa& f2);
	int generar_aleatori(int n);
	void omplir_bossa();
	void copia(const Bossa& t);
	void allibera();
	void reserva();
	void expandeix();
};
#endif // !BOSSA_H