#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Ancestor {
private:
	string Aname;
	string Agender;
public:
	void displayAncestor() { cout << "The information of my ancestor is: " << setw(5) << Aname << setw(5) << Agender << endl; }
	Ancestor(string An, string Ag) :Aname(An), Agender(Ag) {
		cout << "The Ancestor is constructed!" << endl;
	}
	~Ancestor() { cout << "The Ancestor is unconstructed!" << endl; }
};

class Grandfather : public Ancestor {
private:
	string Gname;
	string Ggender;
public:
	void displayGrandfather() { cout << "The information of my grandfather is: " << setw(5) << Gname << setw(5) << Ggender << endl; }
	Grandfather(string An, string Ag, string Gn, string Gg) :
		Ancestor(An, Ag), Gname(Gn), Ggender(Gg) {
		cout << "The Grandfather is constructed!" << endl;
	}
	~Grandfather() { cout << "The Grandfather is unconstructed!" << endl; }
};

class Father :public Grandfather {
private:
	string Fname;
	string Fgender;
public:
	void displayFather() { cout << "The information of my father is: " << setw(5) << Fname << setw(5) << Fgender << endl; }
	Father(string An, string Ag, string Gn, string Gg, string Fn, string Fg) :
		Grandfather(An, Ag, Gn, Gg), Fname(Fn), Fgender(Fg) {
		cout << "The Father is constructed!" << endl;
	}
	~Father() { cout << "The Father is unconstructed!" << endl; }
};

class Brother :public Father {
private:
	string Bname;
	string Bgender;
public:
	void displayBrother() { cout << "The information of my brother is: " << setw(5) << Bname << setw(5) << Bgender << endl; }
	Brother(string An, string Ag, string Gn, string Gg, string Fn, string Fg, string Bn, string Bg) :
		Father(An, Ag, Gn, Gg, Fn, Fg), Bname(Bn), Bgender(Bg) {
		cout << "The Brother is constructed!" << endl;
	}
	~Brother() { cout << "The Brother is unconstructed!" << endl; }
};

class Sister :public Father {
private:
	string Sname;
	string Sgender;
public:
	void displaySister() { cout << "The information of my sister is: " << setw(5) << Sname << setw(5) << Sgender << endl; }
	Sister(string An, string Ag, string Gn, string Gg, string Fn, string Fg, string Sn, string Sg) :
		Father(An, Ag, Gn, Gg, Fn, Fg), Sname(Sn), Sgender(Sg) {
		cout << "The Sister is constructed!" << endl;
	}
	~Sister() { cout << "The Sister is unconstructed!" << endl; }
};

class Me :public Father {
private:
	string Mname;
	string Mgender;
	class Brother Mbro;
	class Sister Msis;
public:
	void displayMe() { 
		Mbro.displayBrother();
		Msis.displaySister();
		cout << "The information of me is: " << setw(5) << Mname << setw(5) << Mgender << endl;
	}
	Me(string An, string Ag, string Gn, string Gg, string Fn, string Fg, string Mn, string Mg, Brother bro, Sister sis) :
		Father(An, Ag, Gn, Gg, Fn, Fg), Mname(Mn), Mgender(Mg), Mbro(bro), Msis(sis) {
		cout << "The Me is constructed!" << endl;
	}
	~Me() { cout << "The Me is unconstructed!" << endl; }
};

int main()
{
	Brother b("AAA", "M", "BBB", "M", "CCC", "M", "DDD", "M");
	Sister s("AAA", "M", "BBB", "M", "CCC", "M", "EEE", "F");
	Me m("AAA", "M", "BBB", "M", "CCC", "M", "FFF", "M", b, s);
	m.displayAncestor();
	m.displayGrandfather();
	m.displayFather();
	m.displayMe();
	return 0;
}