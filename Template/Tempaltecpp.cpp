#include<iostream>
#include <string>
#include <vector>
using namespace std;


bool groesser_Funktion(int a, int b) {

	cout << "Normale Funktion ohne Template fuer int" << endl;
	return a > b;

}

bool groesser_Funktion(string a, string b) {

	//Zeichenketten anhand ihres Dezimalwertes verglichen( lexigografisch) -> ASCI - Tabelle
	// Leerzeichen , Sonderzeichen, Zahlen,Großebuchstabe, Kleinbuchstaben
	cout << "Normale Funktion ohne Template fuer int" << endl;
	return a > b;

}

// Verwendung von Funktion Templates, damit wir verschiedene Datentypen erstellen können
// Definition einer Template Funktion , die für alle Datentypen gültig ist
// beide Parameter müssen vom selben Datentype sein
// syntax: template <typename typkuerze> Rückgabetyp Funktionname (TypKuerze a, Typkuerze b)
template<typename t> 
	bool groesser(t a, t b) {

		cout << "Template -Funkton " << endl;
		return a > b;
	}

	// Spezialiiserte Template
	// Verwendet, um die Typesicherheit zu gewährleiste
	// gewünschte Datentypen vom Vergeleich ausschliessen
	// Ohne Standardtemplate kein spezialisiertes Template möglich
	// Rückgabetyp sowie Anzahl und Datentypen der Parameter müssen identisch sein 

template<>
	bool groesser(bool a, bool b) {
		cout << "Spezialisierte Template fuer bool" << endl;
		cout << "Verlgleich von bool - Werten nicht sinnvoll" << endl;
		return false;
	}

int addieren1(int a, int b = 0, int c= 0, int d=0)
{
	return a + b + c, d;

}
string addieren1(string a, string b = "", string c = "", string d = "")
{
	return a + b + c + d;

}


// Variabic Templates//
// Verwendet , um eine Funktion zu erstellen , der beliebige Viele Parameter übergeben werden können

template<typename T, typename ...LISTE>  // ... bedeutet viele Parameter eingeben

T addieren(T a, LISTE ...rest)
{
	cout << "Anzahl der Parameter:" << sizeof ...(rest) + 1 << endl;
	// Erzeugenu einer Vektor vom Typ T, der a und rest speichert

	vector<T> werte{ a, rest... };
	//Variable vom Typ T erzeugen und mit Ihren Standarwert initialen
	T ergebnis{};
	//DUrchlaufen des Vektors

	for (T wert : werte)
	{
		ergebnis += wert;
		
	}
	cout << ergebnis << endl;
	return ergebnis;
}

// Spezialisiert Template für Datentypen, di ausgeschlossen werden sollen
//Spezialisiertes Template für char

template<typename ...LISTE>
bool addiern(char a, LISTE ...rest) {
	cout << "bool koennen nicht verkettet werden" << endl;
	return a;
}

//speziallisierte Template für bool
template<typename ...LISTE>
bool addieren(bool a, LISTE ...rest) {
	cout << "Bool-WErte konnen nicht verketter werden" << endl;
	return a;
}

int main() {

	cout << boolalpha;
	cout << groesser_Funktion(6, 7) << endl;
	string s1 = "Zimmermann";
	string s2 = "Mustermann";

	string ergebnis = groesser_Funktion(s1, s2) ? s1 : s2;
	cout << ergebnis << endl;

	cout << groesser(5, 6) << endl;
	cout << (groesser_Funktion(3.3, 3.1) ? "3.3" : "3.1") << endl;
	cout << (groesser(3.3, 3.1) ? "3.3" : "3.1") << endl;
	cout << groesser(s1, s2) << endl;
	cout << groesser(true, false) << endl;

	cout << addieren1(23, 7.5) << endl;
	// verursacht einen Compilerfehler, da double und int verwendet werden
	// cout << addieren(23, 7.5) << endl;

	cout << addieren(true, false, true) << endl;
	cout << addieren(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15) << endl;
	cout << addieren(3.3, 4.4, 5.5) << endl;
	cout << addieren('A', 'B', 'C') << endl;
	cout << ('A' + 'B' + 'C') << endl;
	return 0;
}