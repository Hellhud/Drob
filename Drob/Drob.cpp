#include <iostream>
#include <string>
using namespace std;

class Drob {
private:
	int chisl;
	int znamen;
	int NOD(int x, int y)
	{
		if (y == 0) return x;
		return NOD(y, x % y);
	}
public:
	void input(int c, int z)
	{
		chisl = c;
		znamen = z;
	}
	void mult(int x)
	{
		chisl *= x;
		cout << "drob:  " << chisl << '/' << znamen << endl;
	}
	void div(int x)
	{
		znamen *= x;
		cout << "drob:  " << chisl << '/' << znamen << endl;

	}

	void sum(int x)
	{
		chisl += (x * znamen);
		cout << "drob:  " << chisl << '/' << znamen << endl;
	}
	void sub(int x)
	{
		chisl -= (x * znamen);
		cout << "drob:  " << chisl << '/' << znamen << endl;

	}
	void show()
	{
		cout << "tekushaya drob:  " << chisl << '/' << znamen << endl;
	}
	int peredacha()
	{
		return NOD(chisl, znamen);
	}
	void reduct(int x)
	{
		chisl /= x;
		znamen /= x;
	}

};



int main() {
	int a, b, m;
	char c = 'y';
	cout << "vvedite cheslitel:" << endl;
	cin >> a;
	cout << "vvedite znamenatel:" << endl;
	cin >> b;
	Drob obj;
	obj.input(a, b);
	do {
		obj.reduct(obj.peredacha());
		obj.show();
		cout << "1:Pribavit k drobi chislo" << endl;
		cout << "2:Otniatb ot drobi chislo" << endl;
		cout << "3:Ymnojitb  drobna  chislo" << endl;
		cout << "4:Razdelitb  drob na chislo" << endl;
		cout << "Viberite deystvie" << '\n';
		cin >> m;
		switch (m)
		{
		case 1:
			cout << "Vvedite slagaemoe" << endl;
			cin >> a;
			obj.sum(a);
			break;
		case 2:
			cout << "Vvedite vichitaemoe" << endl;
			cin >> a;
			obj.sub(a);
			break;
		case 3:
			cout << "Vvedite mnojitel" << endl;
			cin >> a;
			obj.mult(a);
			break;
		case 4:
			cout << "Vvedite delitel" << endl;
			cin >> a;
			obj.div(a);
			break;
		default:
			cout << "Viberite pravilno" << endl;
		}
		cout << "prodoljit raboty?(y/n)" << endl;
		cin >> c;
	} while (c != 'n');
	return 0;
}