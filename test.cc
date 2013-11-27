#include<iostream>
#include <typeinfo>
#include <cassert>
#include<cstdio>
#include "holding.hh"

using namespace std;

void type_test()
{
	typedef add_comp<Accountancy, Exchange_office>::type small_company;
	multiply_comp<Company<12, 34, 21>, 5>::type a;
	split_comp<Company<53, 65, 44>, 3>::type b;
	add_comp<small_company, Company<8, 5, 3> >::type c;
	remove_comp<Company<54,67,23>, Company<12,34,45> >::type d;
	additive_expand_comp<Company<54,67,0> >::type e;
	additive_rollup_comp<Company<54,67,0> >::type f;
	
	cout << a.acc() << " " << a.hs() << " " << a.exo() << endl;
	cout << b.acc() << " " << b.hs() << " " << b.exo() << endl;
	cout << c.acc() << " " << c.hs() << " " << c.exo() << endl;
	cout << d.acc() << " " << d.hs() << " " << d.exo() << endl;
	cout << e.acc() << " " << e.hs() << " " << e.exo() << endl;
	cout << f.acc() << " " << f.hs() << " " << f.exo() << endl;
}

void group_test()
{
	Group<Company<1, 2, 3> > e(2);
	Group<Company<1, 2, 3> > g(e);
	printf("value = %d, size = %d, acc_val = %d, hs_val = %d, exo_val = %d\n",
	g.get_value(), g.get_size(), g.get_acc_val(), g.get_hs_val(), g.get_exo_val());
	
	g.set_acc_val(50);
	g.set_hs_val(100);
	g.set_exo_val(250);
	printf("value = %d, size = %d, acc_val = %d, hs_val = %d, exo_val = %d\n",
	g.get_value(), g.get_size(), g.get_acc_val(), g.get_hs_val(), g.get_exo_val());
	
}
	

int main()
{	
	//type_test();
	group_test();
	return 0;
}