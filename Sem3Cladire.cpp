#include <iostream>
#include <string>

using namespace std;

class Cladire {
public:
	string adresa;
	int etaje;
	float suprafata;

	void afisare() {
		cout << " Cladirea are " << etaje << " etaje si o suprafata de " << suprafata << " mp situata la adresa " << adresa << endl;
	}

	void modificareSuprafata(float x) {
		this->suprafata += 2;
	}
};

void main() {
	Cladire c;
	c.adresa = "Romana";
	c.etaje = 6;
	c.suprafata = 100.15;

	Cladire* pc;
	pc = new Cladire();
	(*pc).etaje = 10;
	pc->adresa = "Romana";
	pc->suprafata = 1000;
	Cladire* pc2 = pc;  
	c.afisare();
	pc->afisare();


	Cladire* vector;
	int n = 3;
	vector = new Cladire[n]; // se va apela de n ori constructorul fara parametrii
	for (int i = 0; i < n; i++)
	{
		vector[i].adresa = "Universitate";
		vector[i].etaje = (i + 1) * 2;
		vector[i].suprafata = 100 * (i + 1);
	}

	for (int i = 0; i < n; i++)
	{
		vector[i].afisare();
	}






}



