#include <iostream>
#include <cstring>
using namespace std;

class Fular {
public:
	float pret;
	bool iarna;
	static int totalFulare;
	const string brand;
	string* material;

	Fular(float p, bool i, string m, string b) : brand(b) {
		pret = p;
		iarna = i;
		material = new string(m);
		totalFulare++;
	}

	Fular(float p, string b) : brand(b) {
		pret = p;
		iarna = false;
		material = new string("N/A");
		totalFulare++;
	}

	Fular() : brand("N/A") {
		pret = 20;
		iarna = false;
		material = new string("N/A");
		totalFulare++;
	}

	~Fular() {
		delete material;
	}

	void afisare() {
		cout << "Pret: " << pret << "\n";
		cout << "Iarna: " << (iarna ? "Da" : "Nu") << "\n";
		cout << "Material: " << *material << "\n";
		cout << "Brand: " << brand << "\n\n";
	}

private:
};

int Fular::totalFulare = 0;

class Parfum {
public:
	float pret;
	int ml;
	static int totalParfumuri;
	const string brand;
	string* note;

	Parfum(float p, int m, string n, string b) : brand(b) {
		pret = p;
		ml = m;
		note = new string(n);
		totalParfumuri++;
	}

	Parfum(float p, string b) : brand(b) {
		pret = p;
		ml = 100;
		note = new string("N/A");
		totalParfumuri++;
	}

	Parfum() : brand("N/A") {
		pret = 100;
		ml = 100;
		note = new string("N/A");
		totalParfumuri++;
	}

	~Parfum() {
		delete note;
	}

	void afisare() {
		cout << "Pret: " << pret << "\n";
		cout << "Ml: " << ml << "\n";
		cout << "Note: " << *note << "\n";
		cout << "Brand: " << brand << "\n\n";
	}

private:
};

int Parfum::totalParfumuri = 0;

class Pantof {
public:
	float pret;
	int marime;
	static int totalPantofi;
	const string brand;
	string* culoare;

	Pantof(float p, int m, string c, string b) : brand(b) {
		pret = p;
		marime = m;
		culoare = new string(c);
		totalPantofi++;
	}

	Pantof(float p, string b) : brand(b) {
		pret = p;
		marime = 36;
		culoare = new string("N/A");
		totalPantofi++;
	}

	Pantof() : brand("N/A") {
		pret = 200;
		marime = 36;
		culoare = new string("N/A");
		totalPantofi++;
	}

	~Pantof() {
		delete culoare;
	}

	void afisare() {
		cout << "Pret: " << pret << "\n";
		cout << "Marime: " << marime << "\n";
		cout << "Culoare: " << *culoare << "\n";
		cout << "Brand: " << brand << "\n\n";
	}

private:
};

int Pantof::totalPantofi = 0;

int main() {
	Fular f1(70.00, true, "bumbac", "Zara");
	Fular f2(50, "H&M");
	Fular f3;

	cout << "Fulare: \n\n";
	f1.afisare();
	f2.afisare();
	f3.afisare();
	cout << "Numar total de fulare: " << Fular::totalFulare << "\n\n";

	Parfum p1(300.00, 50, "citrice", "Replica");
	Parfum p2(150.00, "Tom Ford");
	Parfum p3;

	cout << "Parfumuri: \n\n";
	p1.afisare();
	p2.afisare();	
	p3.afisare();
	cout << "Numar total de parfumuri: " << Parfum::totalParfumuri << "\n\n";

	Pantof pa1(400.00, 42, "Negru", "Nike");
	Pantof pa2(250.00, "Puma");
	Pantof pa3;

	cout << "Pantofi: \n\n";
	pa1.afisare();
	pa2.afisare();
	pa3.afisare();
	cout << "Numar total de pantofi: " << Pantof::totalPantofi << "\n\n";

	return 0;
}

