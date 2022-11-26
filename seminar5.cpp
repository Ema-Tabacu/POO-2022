#include<iostream>
#include<string>
using namespace std;


enum TipCafea { expresso, machiatto, latte, capuccino };
class Cafenea {
	string nume;
	int nrProduse;
	float* preturi;
	TipCafea* tipuri;
	int nrClientiZi;
	static int TVA;
	const int anInfiintare;

	static string getNumeTip(TipCafea tip) {

		if (tip == expresso)
			return "expresso";
		if (tip == machiatto)
			return "machiatto";
		if (tip == latte)
			return "latte";
		if (tip == capuccino)
			return "capuccino";
	}


public:
	//constructor fara parametri
	Cafenea() : anInfiintare(2022) {
		this->nume = "Teds";
		this->nrProduse = 5;
		this->preturi = new float[nrProduse];
		this->tipuri = new TipCafea[nrProduse];
		preturi[0] = 10;
		preturi[1] = 8;
		preturi[2] = 6;
		preturi[3] = 7;
		preturi[4] = 9;
		tipuri[0] = expresso;
		tipuri[1] = latte;
		tipuri[2] = latte;
		tipuri[3] = capuccino;
		tipuri[4] = machiatto;
		this->nrClientiZi = 10;

	}

	//constructor cu parametri
	Cafenea(string nume, int nrProduse, float* preturi, TipCafea* tipuri, int nrClientiZi, int anNou) :anInfiintare(anNou) {

		this->nume = nume;
		this->nrProduse = nrProduse;
		this->preturi = new float[nrProduse];
		this->tipuri = new TipCafea[nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->preturi[i] = preturi[i];
			this->tipuri[i] = tipuri[i];
		}
		this->nrClientiZi = nrClientiZi;


	}
	Cafenea(string nume, int nrClientiZi) :anInfiintare(2010) //cafenea3
	{
		this->nume = nume;
		this->nrProduse = 0;
		this->preturi = NULL;
		this->tipuri = NULL;
		this->nrClientiZi = nrClientiZi;

	}

	//constr copiere
	Cafenea(const Cafenea& c) :anInfiintare(c.anInfiintare) {
		this->nume = c.nume;
		this->nrClientiZi = c.nrClientiZi;
		this->nrProduse = c.nrProduse;
		//trebuie sa verificam daca nr de produse e mai mare decat 0 pentru ca daca nu sunt produse, nu mai are rost sa alocam spatiu, vectorul e null
		if (this->nrProduse > 0) {
			this->preturi = new float[nrProduse];
			this->tipuri = new TipCafea[nrProduse];
			for (int i = 0; i < nrProduse; i++) {
				this->preturi[i] = c.preturi[i];
				this->tipuri[i] = c.tipuri[i];
			}
		}
		else
		{
			this->preturi = NULL;
			this->tipuri = NULL;
		}
	}

	//supraincarcare operator = egal
	Cafenea& operator=(const Cafenea& c) { //pot evita apelul la tipul returnat? da-transmitem prin referinta!! si nu se mai apeleaza
		//cpy constr-- el copiaza doar adresa obiectului, nu obiectul in sine , ci trece mai departe de constr
		//pot returna prin ref pt ca obiectul this exista de dinainte
		if (this != &c) { //verificare de autoasignare
			this->nume = c.nume;
			this->nrClientiZi = c.nrClientiZi;
			this->nrProduse = c.nrProduse;
			//daca pointerii au valori alocate, ii stergem si alocam din nou spatiu pt ei 
			if (this->preturi != NULL) {
				delete[]this->preturi;
			}
			if (this->tipuri != NULL) {
				delete[]this->tipuri;
			}
			this->preturi = new float[nrProduse];
			this->tipuri = new TipCafea[nrProduse];
			for (int i = 0; i < nrProduse; i++) {

				this->preturi[i] = c.preturi[i];
				this->tipuri[i] = c.tipuri[i];
			}
			return *this;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}

	}

	//operator+ care aduna doua cafenele
	Cafenea operator+(const Cafenea& c) {
		Cafenea aux = *this; //se apeleaza constr copiere pt ca se apeleaza un ob in baza unuia existent(this e existent)
		aux.nrClientiZi = this->nrClientiZi + c.nrClientiZi; //se aduna clientii
		return aux;

		//nu punem referinta pt ca aux va fi distrus!
	
	}

	//operator+ care aduna o cafenea si un int
	Cafenea operator+(int nrClienti) {
		Cafenea aux = *this; //se apeleaza constr copiere pt ca se apeleaza un ob in baza unuia existent(this e existent)
		aux.nrClientiZi = this->nrClientiZi + nrClienti; //se aduna clientii
		aux.nrClientiZi += nrClienti;
		return aux;
	}



	Cafenea operator+=(int nrClienti) {
		this->nrClientiZi += nrClienti; //putem transmite prin referinta
		return *this;
	}
	//i:-
	//o:int
	int getNrClientiZi()
	{
		return nrClientiZi;
	}
	void setNrClientiZi(int nrClientiZi)
	{
		if (nrClientiZi >= 0)
		{
			this->nrClientiZi = nrClientiZi;
		}

	}


	void afisareCafenea() {
		cout << "Nume: " << this->nume << endl
			<< "Numar produse: " << this->nrProduse << endl;
		cout << "Preturi si tipuri cafea: ";
		for (int i = 0; i < this->nrProduse; i++) {
			cout << preturi[i] << "-";
			cout << getNumeTip(tipuri[i]) << ",";
		}
		cout << endl << "Nr clienti pe zi: " << this->nrClientiZi;
		cout << endl << "----------------------------------------------" << endl;
	}

	~Cafenea() {
		if (this->preturi != NULL) {
			delete[] this->preturi;
		}
		if (this->tipuri != NULL) {
			delete[]this->tipuri;
		}
	}

	int getNrProduse() {
		return nrProduse;
	}

	void setNrProduse(int nrProduse, float* preturi, TipCafea* tipuri) {
		if (nrProduse > 0) {
			this->nrProduse = nrProduse;
			if (this->preturi != NULL) {
				delete[] this->preturi;
			}
			if (this->tipuri != NULL) {
				delete[]this->tipuri;
			}
			this->preturi = new float[nrProduse];
			this->tipuri = new TipCafea[nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = preturi[i];
				this->tipuri[i] = tipuri[i];
			}
		}
	}

	float* getPreturi() {
		return this->preturi;
	}

	string getNume() {
		return this->nume;
	}



	friend ostream& operator<<(ostream& out, const Cafenea& c) {
		out << "Nume: " << c.nume << endl
			<< "Numar produse: " << c.nrProduse << endl;
		out << "Preturi si tipuri cafea: ";
		for (int i = 0; i < c.nrProduse; i++) {
			out << c.preturi[i] << "-";
			out << getNumeTip(c.tipuri[i]) << ",";
		}
		out << endl << "Nr clienti pe zi: " << c.nrClientiZi;
		out << endl << "----------------------------------------------" << endl;
		return out;
	}

	//aici nu punem referinta constanta
	friend istream& operator>>(istream& iStream, Cafenea& c) {
		cout << "Nume: ";
		iStream >> c.nume;
		cout << "Nr produse: ";
		iStream >> c.nrProduse;
		cout << "Preturi: ";
		//VERIFICAM DACA AVEM CEVA ALOCAT
		if (c.preturi != NULL) {
			delete[]c.preturi;
		}
		if (c.tipuri != NULL) {
			delete[]c.tipuri;
		}

		//ALOCAM SPATIU VECTORI
		c.preturi = new float[c.nrProduse];
		c.tipuri = new TipCafea[c.nrProduse];
		for (int i = 0; i < c.nrProduse; i++) {
			cout << "Preturi:";
			iStream >> c.preturi[i];
			//citim enumurile //cu coduri
			int a;
			cout << "1 expresso, 2 machiatto, 3 latte, 4 capuccino";
			iStream >> a; //citim ce a introdus omul de la tastatura
			if (a == 1) {
				c.tipuri[i] = expresso;
			}
			if (a == 2) {
				c.tipuri[i] = machiatto;
			}

			if (a == 3) {
				c.tipuri[i] = latte;
			}
			if (a == 4) {
				c.tipuri[i] = capuccino;
			} 
		}
		cout << "Nr clienti: ";
		iStream >> c.nrClientiZi;
		return iStream;

	}
	//returnam prin valoare, apelam constr copiere -- nu primim parametri //sa creasca nr clienti
	Cafenea& operator++() {
		this->nrClientiZi++;
		//this->nrClientiZi=this->nrClientiZi+1;
		return *this; //FORMA PREFIXATA -- ca n are parametrii, returnezi valoarea modificata deci prefixat
		//this exista dejja, deci nu se pierde, deci putem pune referinta

	}
	//intotdeauna parametru int ca sa asiguram polimorfismul
	Cafenea operator++(int a) {
		Cafenea aux=*this; //ne facem o copie 
		//modificam this, nu aux
		this->nrClientiZi++;
		return aux; //starea initiala, nemodificata

		//nu mai punem referinta pt ca aux va fi sters, deci apelam constr de copiere

	}

	//operator functie()
	float operator()() {
		float suma = 0;
		for (int i = 0; i < this->nrProduse; i++) {
			suma += (float)TVA *0,01 * this->preturi[i];
		}
		return suma;
	}

	bool operator<= (const Cafenea& c) {
		if (this->nrClientiZi <= c.nrClientiZi)
			return true;
		else {
			return false;
		}

	}

	bool operator==(const Cafenea& c) {
		if (this->nrClientiZi == c.nrClientiZi) {
			if (this->nrProduse == c.nrProduse) {
				return true;
			}
			else return false;
		}
		else
			return false;
	}
};

int Cafenea::TVA = 5;



void main() {

}
