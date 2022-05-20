#include "Fitxa.h"
#include <iostream>
#include <iomanip>
using namespace std;

// CONSTRUCTORS
// CONSTRUCTOR PER DEFECTE
Fitxa::Fitxa()
{
	a_tipus = ' ';
	a_valor = 0;
}
// CONSTRUCTOR PER PARAMETRES
Fitxa::Fitxa(char element, int valor)
{
	a_tipus = element;
	a_valor = valor;
}
// OPERADORS
bool Fitxa::operator==(const Fitxa& f) const
{
	return a_tipus == f.a_tipus and a_valor == f.a_valor;
}
bool Fitxa::operator<(const Fitxa& f) const
{
	return a_tipus < f.a_tipus or (a_tipus == f.a_tipus and a_valor < f.a_valor);
}
bool Fitxa::operator>(const Fitxa& f) const
{
	return a_tipus > f.a_tipus or (a_tipus == f.a_tipus and a_valor > f.a_valor);
}
bool Fitxa::operator<=(const Fitxa& f) const
{
	return (*this) < f or (*this) == f;
}
bool Fitxa::operator>=(const Fitxa& f) const
{
	return not((*this) < f);
}

// METODES CONSULTORS
void Fitxa::mostra() const
{
	if (this->es_nula()) cout << "(   )";
	else cout << "(" << a_tipus << setw(2) << setfill('0') << a_valor << ")";
}
bool Fitxa::es_nula() const
{
	return a_tipus == ' ' and a_valor == 0;
}
char Fitxa::tipus_element() const
{
	return a_tipus;
}
// METODES MODIFICADORS
void Fitxa::llegeix()
{
	cin >> a_tipus >> a_valor;
}
