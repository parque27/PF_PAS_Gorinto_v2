#ifndef FITXA_H
#define FITXA_H
class Fitxa
{
	// DESCRIPCCIO: Fitxa que te un element (aigua, foc, terra, vent i eter) i un valor.
	// INVARIABLE: Fitxa pren valors de 1 a 20. Caracters que pot ser una fitxa: a,f,t,v,e

public:
	// CONSTRUCTORS
	Fitxa();
	// Pre: --; Post: la fitxa te tipus buit i valor 0
	Fitxa(char tipus, int valor);
	// Pre: --; Post: la fitxa te els parametres passats per constructor

	// OPERADORS
	bool operator == (const Fitxa& f) const;
	// Pre: --; Post: retorna true si aquesta fitxa es igual que f, fals altrament
	bool operator < (const Fitxa& f) const;
	// Pre: --; Post: retorna true si aquesta fitxa es menor que f, fals altrament
	bool operator > (const Fitxa& f) const;
	// Pre: --; Post: retorna true si aquesta fitxa es major que f, fals altrament
	bool operator <= (const Fitxa& f) const;
	// Pre: --; Post: retorna true si aquesta fitxa es menor o igual que f, fals altrament
	bool operator >= (const Fitxa& f) const;
	// Pre: --; Post: retorna true si aquesta fitxa es major o igual que f, fals altrament

	// METODES CONSULTORS
	void mostra() const;
	// Pre: --: Post: mostra la fitxa per pantalla
	bool es_nula() const;
	// Pre: --; Post: retorna true si la fitxa es nula, fals altrament
	char tipus_element() const;
	// Pre: --; Post: retorna el tipus d'element de la fitxa ('a','t','f','v','e')

	// METODES MODIFICADORS
	void llegeix();
	// Pre: --; Post: llegeix els atributs de la fitxa per teclat

private:
	// ATRIBUTS
	char a_tipus;
	int a_valor;
};
#endif // !FITXA_H
