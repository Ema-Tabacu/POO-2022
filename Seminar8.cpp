#include<iostream>
#include <string>
using  std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
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


	float operator()() {
		float suma = 0;
		for (int i = 0; i < this->nrProduse; i++) {
			suma += (float)TVA * 0.01 * this->preturi[i];
		}
		return suma;
	}

	string getNume() {
		return this->nume;
	}

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

	Cafenea(const Cafenea& c) :anInfiintare(c.anInfiintare) {
		this->nume = c.nume;
		this->nrClientiZi = c.nrClientiZi;
		this->nrProduse = c.nrProduse;
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

	Cafenea& operator=(const Cafenea& c)
	{
		if (this != &c) { //verificare de autoasignare
			this->nume = c.nume;
			this->nrClientiZi = c.nrClientiZi;
			this->nrProduse = c.nrProduse;
			if (this->preturi != NULL) {
				delete[]this->preturi;
			}
			if (this->tipuri != NULL) {
				delete[]this->tipuri;
			}
			this->preturi = new float[nrProduse];
			this->tipuri = new TipCafea[nrProduse];
			for (int i = 0; i < nrProduse; i++)
			{
				this->preturi[i] = c.preturi[i];
				this->tipuri[i] = c.tipuri[i];
			}
		}
		return *this;

	}



	Cafenea(string nume,
		int nrProduse,
		float* preturi,
		TipCafea* tipuri,
		int nrClientiZi,
		int anNou) :anInfiintare(anNou) {

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
	Cafenea(string nume, int nrClientiZi) :anInfiintare(2010)
	{
		this->nume = nume;
		this->nrProduse = 0;
		this->preturi = NULL;
		this->tipuri = NULL;
		this->nrClientiZi = nrClientiZi;

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
		cout << " nume: " << this->nume
			<< "Numar produse: " << this->nrProduse << endl;

		for (int i = 0; i < this->nrProduse; i++) {
			cout << preturi[i] << "-";
			cout << getNumeTip(tipuri[i]) << ",";

		}
		cout << this->nrClientiZi;
		cout << endl;
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

	Cafenea operator+(const Cafenea& c) {
		Cafenea aux = *this;
		aux.nrClientiZi = this->nrClientiZi + c.nrClientiZi;
		return aux;
	}

	Cafenea operator+(int nrClienti) {
		Cafenea aux = *this;
		aux.nrClientiZi += nrClienti;
		return aux;
	}

	Cafenea operator+=(int nrClienti) {
		this->nrClientiZi += nrClienti;
		return *this;
	}


	friend ostream& operator<<(ostream& out, const Cafenea& c) {
		out << " nume: " << c.nume << endl;
		out << "Numar produse: " << c.nrProduse << endl;

		for (int i = 0; i < c.nrProduse; i++) {
			out << c.preturi[i] << "-";
			out << getNumeTip(c.tipuri[i]) << ",";

		}
		out << c.nrClientiZi;
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& iStream, Cafenea& c) {
		cout << "Nume: ";
		iStream >> c.nume;
		cout << "Nr. produse: ";
		iStream >> c.nrProduse;
		if (c.preturi != NULL)
			delete[] c.preturi;

		if (c.tipuri != NULL)
			delete[] c.tipuri;

		c.preturi = new float[c.nrProduse];
		c.tipuri = new TipCafea[c.nrProduse];

		for (int i = 0; i < c.nrProduse; i++) {
			cout << "Pretul";
			iStream >> c.preturi[i];

			int a;
			cout << "{expresso = 1, machiatto = 2, latte = 3, capuccino = 4}";
			iStream >> a;
			if (a == 1)
				c.tipuri[i] = expresso;
			if (a == 2)
				c.tipuri[i] = machiatto;
			if (a == 3)
				c.tipuri[i] = latte;
			if (a == 4)
				c.tipuri[i] = capuccino;

		}
		cout << "Nr clienti";
		iStream >> c.nrClientiZi;
		return iStream;

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
			else {
				return false;
			}
		}
		else {
			return false;
		}


	}

	
	Cafenea& operator++()
	{
		this->nrClientiZi = this->nrClientiZi + 1;
		return *this;
	}
	Cafenea operator++(int a)
	{
		Cafenea aux;
		aux = *this;
		this->nrClientiZi = this->nrClientiZi + 1;
		return aux;
	}
	//functie pt adagare o noua cafenea in vector,  ii trimitem si nr de obiecte
	static void adaugareCafeneaVector(Cafenea* &vCafenele, const Cafenea& c, int& nrCafenele) {
		Cafenea* aux = new Cafenea[nrCafenele + 1]; //+1 ppt cacrestem nr cafenele
		for (int i = 0; i < nrCafenele; i++) {
			aux[i] = vCafenele[i];
		}
		aux[nrCafenele] = c;
		//acum stergem vectorul de cafenele si noul vector sa pointeze catre noul v
		delete[]vCafenele;
		vCafenele = aux; //mi am mutat noul vector in vcafenele
		nrCafenele++;
		//parametru transmis prin valoare= modif se face doar pe stiva, deci punem referinta ca sa ramana modif
	}
	//nu returneaza nimic, nu am pus cacafenea= ceva deci ii dam void
	//vcafenele e 
	static void adaugareCafeneaPointer(Cafenea**& vpCafenele,  Cafenea& c, int& nr) {  //daca avem const avem automat referinta
		Cafenea** aux = new Cafenea * [nr + 1]; //aloc spatiu pt cei 3 pointeri si acum ii copiem
		for (int i = 0; i < nr; i++) {//facem shallow copy pt ca sunt aceleasi cafenele, nu mai alocam memorie, nu mai stergem
			aux[i] = vpCafenele[i];
		} //am copiat a1 si a2 in aux
			aux[nr] = new Cafenea(c); //am apelat constr de copiere ca sa mi creeze obiectul resp pe baza parametrului primit
		//	aux[nr] = &c; //c e deja o cafenea, il reerentiez ca sa ii obtin adresa, ii aloc spatiu
			delete[]vpCafenele;
			//trb sa iau adresa si sa ii zic unde sa pointeze
			vpCafenele = aux;
			nr++;
		}

		
	

};
int Cafenea::TVA = 5;



void main() {
	//vector de obiecte
	//vector de pointeri
	//are maimulte cafenele in interior
	/*int nCafenele;
	cout << "cate cafenele?";
	cin >> nCafenele;
	Cafenea* vCafenele = new Cafenea[nCafenele];
	for (int i = 0; i < nCafenele; i++) {
		cin >> vCafenele[i];
	}
	Cafenea c1("FiveToGo", 12);
	Cafenea::adaugareCafeneaVector(vCafenele, c1, nCafenele);
	for (int i = 0; i < nCafenele; i++) {
		cout << vCafenele[i];
	}
	
	delete[]vCafenele;
*/ int nr;
cout << " nr caf";
cin >> nr;
Cafenea** vpCafenele = new Cafenea * [nr];
	//avem 8octeti alocati, 2*4 int pointer
for (int i = 0; i < nr; i++)
{
	vpCafenele[i] = new Cafenea(); //apelam constr nostru explicit
	cin >> * (vpCafenele[i]);
}
Cafenea c1("FiveToGo", 12); //
Cafenea::adaugareCafeneaPointer(vpCafenele, c1, nr);  //c1 e pe stack, in functie avem referinta la c, daca ii dam adresa de pe stack adica cu &c, ii alocam spatiu in heap noii noastre cafenele

for (int i = 0; i < nr; i++) {
	cout << *(vpCafenele[i]);
}

for (int i = 0; i < nr; i++) {
	delete vpCafenele[i]; //aici stergem doar o cafenea, cea de la linia 359
	}
delete[]vpCafenele;
//deep copy - bagi cafeneaua in microunde,scoti farfuria (adresa), iei o alta farfurie, pui tot continutul din farf cealalta si acum ai tot o farfurie
//shallow copy - ie farfuria si mananci tt din ea



}