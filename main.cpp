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

    Fular(const Fular& f) : brand(f.brand) {
        pret = f.pret;
        iarna = f.iarna;
        material = new string(*f.material);
        totalFulare++;
    }

    ~Fular() {
        delete material;
    }

    Fular& operator=(const Fular& f) {
        if (this != &f) {
            pret = f.pret;
            iarna = f.iarna;
            delete material;
            material = new string(*f.material);
        }
        return *this;
    }

    Fular operator+(float valoare) const {
        return Fular(pret + valoare, iarna, *material, brand);
    }

    Fular operator-(float valoare) const {
        return Fular(pret - valoare, iarna, *material, brand);
    }

    bool operator==(const Fular& f) const {
        return pret == f.pret && iarna == f.iarna && *material == *f.material;
    }

    Fular& operator++() {
        pret++;
        return *this;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float p) {
        pret = p;
    }

    bool getIarna() const {
        return iarna;
    }

    void setIarna(bool i) {
        iarna = i;
    }

    string getMaterial() const {
        return *material;
    }

    void setMaterial(string m) {
        *material = m;
    }

    string getBrand() const {
        return brand;
    }

    void afisare() const {
        cout << "Brand: " << brand << "\n";
        cout << "Pret: " << pret << "\n";
        cout << "De iarna: " << (iarna ? "Da" : "Nu") << "\n";
        cout << "Material: " << *material << "\n";
        cout << "-----------\n";
    }

    static int getTotalFulare() {
        return totalFulare;
    }

    friend void marirePret(Fular& f, float procent);
    friend void afisareMaterial(Fular& f);
};

int Fular::totalFulare = 0;

void marirePret(Fular& f, float procent) {
    f.pret += f.pret * procent / 100;
}

void afisareMaterial(Fular& f) {
    cout << "Materialul fularului " << f.getBrand() << " este: " << *f.material << "\n";
}

class Parfum {
private:
    float pret;
    int ml;
    static int totalParfumuri;
    const string brand;
    string* note;

public:
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

    Parfum(const Parfum& p) : brand(p.brand) {
        pret = p.pret;
        ml = p.ml;
        note = new string(*p.note);
        totalParfumuri++;
    }

    ~Parfum() {
        delete note;
    }

    Parfum& operator=(const Parfum& p) {
        if (this != &p) {
            pret = p.pret;
            ml = p.ml;
            delete note;
            note = new string(*p.note);
        }
        return *this;
    }

    Parfum operator+(float valoare) const {
        return Parfum(pret + valoare, ml, *note, brand);
    }

    Parfum operator-(float valoare) const {
        return Parfum(pret - valoare, ml, *note, brand);
    }

    bool operator==(const Parfum& p) const {
        return pret == p.pret && ml == p.ml && *note == *p.note;
    }

    Parfum& operator++() {
        pret++;
        return *this;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float p) {
        pret = p;
    }

    int getMl() const {
        return ml;
    }

    void setMl(int m) {
        ml = m;
    }

    string getNote() const {
        return *note;
    }

    void setNote(string n) {
        *note = n;
    }

    string getBrand() const {
        return brand;
    }

    void afisare() const {
        cout << "Brand: " << brand << "\n";
        cout << "Pret: " << pret << "\n";
        cout << "Cantitate (ml): " << ml << "\n";
        cout << "Note: " << *note << "\n";
        cout << "-------------------------\n";
    }

    static int getTotalParfumuri() {
        return totalParfumuri;
    }

    friend void marirePret(Parfum& p, float procent);
    friend void afisareNote(Parfum& p);
};

int Parfum::totalParfumuri = 0;

void marirePret(Parfum& p, float procent) {
    p.pret += p.pret * procent / 100;
}

void afisareNote(Parfum& p) {
    cout << "Notele parfumului " << p.getBrand() << " sunt: " << *p.note << "\n";
}

class Pantof {
private:
    float pret;
    int marime;
    static int totalPantofi;
    const string brand;
    string* culoare;

public:
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

    Pantof(const Pantof& p) : brand(p.brand) {
        pret = p.pret;
        marime = p.marime;
        culoare = new string(*p.culoare);
        totalPantofi++;
    }

    ~Pantof() {
        delete culoare;
    }

    Pantof& operator=(const Pantof& p) {
        if (this != &p) {
            pret = p.pret;
            marime = p.marime;
            delete culoare;
            culoare = new string(*p.culoare);
        }
        return *this;
    }

    Pantof operator+(float valoare) const {
        return Pantof(pret + valoare, marime, *culoare, brand);
    }

    Pantof operator-(float valoare) const {
        return Pantof(pret - valoare, marime, *culoare, brand);
    }

    bool operator==(const Pantof& p) const {
        return pret == p.pret && marime == p.marime && *culoare == *p.culoare;
    }

    Pantof& operator++() {
        pret++;
        return *this;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float p) {
        pret = p;
    }

    int getMarime() const {
        return marime;
    }

    void setMarime(int m) {
        marime = m;
    }

    string getCuloare() const {
        return *culoare;
    }

    void setCuloare(string c) {
        *culoare = c;
    }

    string getBrand() const {
        return brand;
    }

    void afisare() const {
        cout << "Brand: " << brand << "\n";
        cout << "Pret: " << pret << "\n";
        cout << "Marime: " << marime << "\n";
        cout << "Culoare: " << *culoare << "\n";
        cout << "-------------------------\n";
    }

    static int getTotalPantofi() {
        return totalPantofi;
    }

    friend void marirePret(Pantof& p, float procent);
    friend void afisareCuloare(Pantof& p);
};

int Pantof::totalPantofi = 0;

void marirePret(Pantof& p, float procent) {
    p.pret += p.pret * procent / 100;
}

void afisareCuloare(Pantof& p) {
    cout << "Culoarea pantofilor " << p.getBrand() << " este: " << *p.culoare << "\n";
}

int main() {
    cout << "===== FULARE =====\n\n";

    Fular f1(70.00, true, "bumbac", "Zara");
    Fular f2(50, "H&M");
    Fular f3;

    cout << "Afisare obiecte initiale:\n";
    f1.afisare();
    f2.afisare();
    f3.afisare();

    cout << "Aplicare operator = f3 = f1\n";
    f3 = f1;
    f3.afisare();

    cout << "Aplicare operator +: f1 + 10\n";
    Fular fPlus = f1 + 10;
    fPlus.afisare();

    cout << "Aplicare operator -: f2 - 5\n";
    Fular fMinus = f2 - 5;
    fMinus.afisare();

    cout << "Aplicare operator ++: ++f1\n";
    ++f1;
    f1.afisare();

    cout << "Aplicare operator ==: f1 == f2\n";
    bool egalFular = (f1 == f2);
    cout << "Rezultat: " << (egalFular ? "Adevarat" : "Fals") << "\n\n";

    cout << "Aplicare functie prietena marirePret(f1, 10%)\n";
    cout << "Pret initial f1: " << f1.getPret() << "\n";
    marirePret(f1, 10);
    cout << "Pret dupa marire 10%: " << f1.getPret() << "\n";

    cout << "Aplicare functie prietena afisareMaterial(f1)\n";
    afisareMaterial(f1);

    cout << "\n===== PARFUMURI =====\n\n";

    Parfum p1(300.00, 50, "citrice", "Replica");
    Parfum p2(150.00, "Tom Ford");
    Parfum p3;

    cout << "Afisare obiecte initiale:\n";
    p1.afisare();
    p2.afisare();
    p3.afisare();

    cout << "Aplicare operator = p3 = p2\n";
    p3 = p2;
    p3.afisare();

    cout << "Aplicare operator +: p1 + 50\n";
    Parfum pPlus = p1 + 50;
    pPlus.afisare();

    cout << "Aplicare operator -: p2 - 20\n";
    Parfum pMinus = p2 - 20;
    pMinus.afisare();

    cout << "Aplicare operator ++: ++p1\n";
    ++p1;
    p1.afisare();

    cout << "Aplicare operator ==: p1 == p2\n";
    bool egalParfum = (p1 == p2);
    cout << "Rezultat: " << (egalParfum ? "Adevarat" : "Fals") << "\n\n";

    cout << "Aplicare functie prietena marirePret(p1, 15%)\n";
    cout << "Pret initial p1: " << p1.getPret() << "\n";
    marirePret(p1, 15);
    cout << "Pret dupa marire 15%: " << p1.getPret() << "\n";

    cout << "Aplicare functie prietena afisareNote(p1)\n";
    afisareNote(p1);

    cout << "\n===== PANTOFI =====\n\n";

    Pantof pa1(400.00, 42, "Negru", "Nike");
    Pantof pa2(250.00, "Puma");
    Pantof pa3;

    cout << "Afisare obiecte initiale:\n";
    pa1.afisare();
    pa2.afisare();
    pa3.afisare();

    cout << "Aplicare operator = pa3 = pa2\n";
    pa3 = pa2;
    pa3.afisare();

    cout << "Aplicare operator +: pa1 + 100\n";
    Pantof paPlus = pa1 + 100;
    paPlus.afisare();

    cout << "Aplicare operator -: pa2 - 50\n";
    Pantof paMinus = pa2 - 50;
    paMinus.afisare();

    cout << "Aplicare operator ++: ++pa1\n";
    ++pa1;
    pa1.afisare();

    cout << "Aplicare operator ==: pa1 == pa2\n";
    bool egalPantof = (pa1 == pa2);
    cout << "Rezultat: " << (egalPantof ? "Adevarat" : "Fals") << "\n\n";

    cout << "Aplicare functie prietena marirePret(pa1, 10%)\n";
    cout << "Pret initial pa1: " << pa1.getPret() << "\n";
    marirePret(pa1, 10);
    cout << "Pret dupa marire 10%: " << pa1.getPret() << "\n";

    cout << "Aplicare functie prietena afisareCuloare(pa1)\n";
    afisareCuloare(pa1);

    return 0;
}

