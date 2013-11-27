#include<iostream>
#include <typeinfo>
#include <cassert>
#include "holding.hh"

using namespace std;

int main()
{	
	
	typedef add_comp<Accountancy, Exchange_office>::type small_company;
	multiply_comp<Company<12, 34, 21>, 5>::type a;
	split_comp<Company<53, 65, 44>, 3>::type b;
	add_comp<small_company, Company<8, 5, 3> >::type c;
	remove_comp<Company<54,67,23>, Company<12,34,45> >::type d;
	additive_expand_comp<Company<54,67,23> >::type e;
	additive_rollup_comp<Company<54,67,23> >::type f;
	
	cout << a.acc() << " " << a.hs() << " " << a.exo() << endl;
	cout << b.acc() << " " << b.hs() << " " << b.exo() << endl;
	cout << c.acc() << " " << c.hs() << " " << c.exo() << endl;
	cout << d.acc() << " " << d.hs() << " " << d.exo() << endl;
	cout << e.acc() << " " << e.hs() << " " << e.exo() << endl;
	cout << f.acc() << " " << f.hs() << " " << f.exo() << endl;
	
	
	return 0;
}