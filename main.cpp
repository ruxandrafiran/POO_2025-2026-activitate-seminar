#include <iostream>
#include <cstring>
using namespace std;

class Fular {
private:
    float pret;
    bool iarna;
    static int totalFulare;
    const string brand;
    string* material;

public:
    Fular(float p, bool i, string m, string b) : brand(b) { pret = p; iarna = i; material = new string(m); totalFulare++; }
    Fular(float p, string b) : brand(b) { pret = p; iarna = false; material = new string("N/A"); totalFulare++; }
    Fular() : brand("N/A") { pret = 20; iarna = false; material = new string("N/A"); totalFulare++; }
    Fular(const Fular& f) : brand(f.brand) { pret = f.pret; iarna = f.iarna; material = new string(*f.material); totalFulare++; }
    ~Fular() { delete material; }

    float getPret() const { return pret; }
    void setPret(float p) { pret = p; }
    bool getIarna() const { return iarna; }
    void setIarna(bool i) { iarna = i; }
    string getMaterial() const { return *material; }
    void setMaterial(string m) { *material = m; }
    string getBrand() const { return brand; }

    void afisare() const {
        cout << "Brand: " << brand << "\n";
        cout << "Pret: " << pret << "\n";
        cout << "De iarna: " << (iarna ? "Da" : "Nu") << "\n";
        cout << "Material: " << *material << "\n";
        cout << "-----------\n";
    }

    static int getTotalFulare() { return totalFulare; }
    friend void marirePret(Fular& f, float procent);
    friend void afisareMaterial(Fular& f);
};

int Fular::totalFulare = 0;
void marirePret(Fular& f, float procent) { f.pret += f.pret * procent / 100; }
void afisareMaterial(Fular& f) { cout << "Materialul fularului " << f.getBrand() << " este: " << *f.material << "\n"; }

class Parfum {
private:
    float pret;
    int ml;
    static int totalParfumuri;
    const string brand;
    string* note;

public:
    Parfum(float p, int m, string n, string b) : brand(b) { pret = p; ml = m; note = new string(n); totalParfumuri++; }
    Parfum(float p, string b) : brand(b) { pret = p; ml = 100; note = new string("N/A"); totalParfumuri++; }
    Parfum() : brand("N/A") { pret = 100; ml = 100; note = new string("N/A"); totalParfumuri++; }
    Parfum(const Parfum& p) : brand(p.brand) { pret = p.pret; ml = p.ml; note = new string(*p.note); totalParfumuri++; }
    ~Parfum() { delete note; }

    float getPret() const { return pret; }
    void setPret(float p) { pret = p; }
    int getMl() const { return ml; }
    void setMl(int m) { ml = m; }
    string getNote() const { return *note; }
    void setNote(string n) { *note = n; }
    string getBrand() const { return brand; }

    void afisare() const {
        cout << "Brand: " << brand << "\n";
        cout << "Pret: " << pret << "\n";
        cout << "Cantitate (ml): " << ml << "\n";
        cout << "Note: " << *note << "\n";
        cout << "-------------------------\n";
    }

    static int getTotalParfumuri() { return totalParfumuri; }
    friend void marirePret(Parfum& p, float procent);
    friend void afisareNote(Parfum& p);
};

int Parfum::totalParfumuri = 0;
void marirePret(Parfum& p, float procent) { p.pret += p.pret * procent / 100; }
void afisareNote(Parfum& p) { cout << "Notele parfumului " << p.getBrand() << " sunt: " << *p.note << "\n"; }

class Pantof {
private:
    float pret;
    int marime;
    static int totalPantofi;
    const string brand;
    string* culoare;

public:
    Pantof(float p, int m, string c, string b) : brand(b) { pret = p; marime = m; culoare = new string(c); totalPantofi++; }
    Pantof(float p, string b) : brand(b) { pret = p; marime = 36; culoare = new string("N/A"); totalPantofi++; }
    Pantof() : brand("N/A") { pret = 200; marime = 36; culoare = new string("N/A"); totalPantofi++; }
    Pantof(const Pantof& p) : brand(p.brand) { pret = p.pret; marime = p.marime; culoare = new string(*p.culoare); totalPantofi++; }
    ~Pantof() { delete culoare; }

    float getPret() const { return pret; }
    void setPret(float p) { pret = p; }
    int getMarime() const { return marime; }
    void setMarime(int m) { marime = m; }
    string getCuloare() const { return *culoare; }
    void setCuloare(string c) { *culoare = c; }
    string getBrand() const { return brand; }

    void afisare() const {
        cout << "Brand: " << brand << "\n";
        cout << "Pret: " << pret << "\n";
        cout << "Marime: " << marime << "\n";
        cout << "Culoare: " << *culoare << "\n";
        cout << "-------------------------\n";
    }

    static int getTotalPantofi() { return totalPantofi; }
    friend void marirePret(Pantof& p, float procent);
    friend void afisareCuloare(Pantof& p);
};

int Pantof::totalPantofi = 0;
void marirePret(Pantof& p, float procent) { p.pret += p.pret * procent / 100; }
void afisareCuloare(Pantof& p) { cout << "Culoarea pantofilor " << p.getBrand() << " este: " << *p.culoare << "\n"; }

int main() {
    cout << "FULARE:\n\n";
    Fular f1(70.00, true, "bumbac", "Zara");
    Fular f2(50, "H&M");
    Fular f3;
    f1.afisare(); f2.afisare(); f3.afisare();

    cout << "Aplicare functie marirePret:\n";
    cout << "Pret initial fular " << f1.getBrand() << ": " << f1.getPret() << "\n";
    marirePret(f1, 10);
    cout << "Pret dupa aplicarea functiei marirePret 10%: " << f1.getPret() << "\n\n";

    cout << "Afisare materiale:\n";
    afisareMaterial(f1); 
    cout << "\nNumar total de fulare: " << Fular::getTotalFulare() << "\n\n";

    cout << "PARFFUMURI:\n\n";
    Parfum p1(300.00, 50, "citrice", "Replica");
    Parfum p2(150.00, "Tom Ford");
    Parfum p3;
    p1.afisare(); p2.afisare(); p3.afisare();

    cout << "Aplicare functie marirePret:\n";
    cout << "Pret initial parfum " << p1.getBrand() << ": " << p1.getPret() << "\n";
    marirePret(p1, 15);
    cout << "Pret dupa aplicarea functiei marirePret 15%: " << p1.getPret() << "\n\n";

    cout << "Afisare note:\n";
    afisareNote(p1); 
    cout << "\nNumar total de parfumuri: " << Parfum::getTotalParfumuri() << "\n\n";

    cout << "PANTOFI:\n\n";
    Pantof pa1(400.00, 42, "Negru", "Nike");
    Pantof pa2(250.00, "Puma");
    Pantof pa3;
    pa1.afisare(); pa2.afisare(); pa3.afisare();

    cout << "Aplicare functie marirePret:\n";
    cout << "Pret initial pantof " << pa1.getBrand() << ": " << pa1.getPret() << "\n";
    marirePret(pa1, 10);
    cout << "Pret dupa aplicarea functiei marirePret 10%: " << pa1.getPret() << "\n\n";

    cout << "Afisare culori:\n";
    afisareCuloare(pa1); 
    cout << "\nNumar total de pantofi: " << Pantof::getTotalPantofi() << "\n\n";

    return 0;
}
