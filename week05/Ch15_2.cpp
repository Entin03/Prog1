#include "std_lib_facilities.h"

struct Person{
	Person() { };
	Person(string f_name, string l_name, int age);


	string name() const {return first_name + " " + last_name; }
	string f_name() const { return first_name; }
	string l_name() const { return last_name; }
	int age() const {return m_age; } 


private:
	string first_name;
	string last_name;
	int m_age = 0;
};


Person::Person(string f_name, string l_name, int age){
	if(age < 0 || age > 150)
		error("Helytelen életkor!");
	else
		m_age = age;

	
	string test_name = f_name + l_name;
	for(char c : test_name)
		switch(c){
			case ';' :
			case ':' :
			case '"' :
			case '\'' :
			case '[' :
			case ']' :
			case '*' :
			case '&' :
			case '^' :
			case '%' :
			case '$' :
			case '#' :
			case '@' :
			case '!' :
				error("Helytelen név(csak az abc-t és számokat használhat)!");
				break;
			default:
				
				first_name = f_name;
				last_name = l_name;
				break;
			}

}

istream& operator>>(istream &is, Person &p)
{
	string isf,isl;
	int isa;

	is >> isf >> isl >> isa;
	p = Person{isf, isl, isa};
	
	return is;
}

ostream& operator<<(ostream &os, Person &p)
{
	os << "Name: " << p.name() << ", age:  " << p.age() << endl;
	
	return os;
}

int main()
{
	Person valaki{"Goofy", "Foka", 63};
	cout << valaki;
	cin >> valaki;
	cout << valaki;
	
	cout << "Adjon meg neveket!\n";
	vector <Person> v;
	while(cin >> valaki)
		v.push_back(valaki);

	for(Person p : v)
		cout << p << endl;
		
	return 0;
}
