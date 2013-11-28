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
	
	Group<Company<1, 2, 3> > f;
	f = g + e;
	printf("value = %d, size = %d, acc_val = %d, hs_val = %d, exo_val = %d\n",
	f.get_value(), f.get_size(), f.get_acc_val(), f.get_hs_val(), f.get_exo_val());
	
}

void peczar_test1()
{
	typedef add_comp<Accountancy, Exchange_office>::type small_company;
typedef add_comp<multiply_comp<Hunting_shop, 10>::type, multiply_comp<Exchange_office, 20>::type>::type money;
typedef add_comp<multiply_comp<Hunting_shop, 30>::type, multiply_comp<Exchange_office, 10>::type>::type guns;


  Group<Accountancy> s1;
  Group<money> s2(20);
  Group<money> s3(20);
  Group<Exchange_office> s4;
  Group<guns> s5(20);

  assert((s2 + s3).get_size() == 40);
  assert((s2 += s2).get_size() == 40);
  assert(s2.get_size() == 40);
  assert((s2 - s3).get_size() == 20);
  assert((s3 - s2).get_size() == 0);

  s3.set_exo_val(25);

  std::cout << s2;
  std::cout << s3;
  std::cout << s2 + s3;
  std::cout << s2 - s3;
  std::cout << s2 * 4;
  std::cout << s2 / 2;

  assert((s2 + s3).get_value() == 139200);
  assert((s2 - s3).get_value() == 60000);
  assert((s2 * 4).get_value() == 97600);
  assert((s2 / 2).get_value() == 100000);

  assert(s2 > s3);
  assert(s1 != s4);
  assert(s1 == s1);

  assert(typeid(add_comp<Accountancy, Exchange_office>::type) == typeid(small_company));
  assert(typeid(remove_comp<small_company, Accountancy>::type) == typeid(Exchange_office));
  assert(typeid(split_comp<small_company, 2>::type) == typeid(Company<0, 0, 0>));
  assert(typeid(additive_rollup_comp<multiply_comp<small_company, 2>::type>::type) ==
         typeid(small_company));
  assert(typeid(additive_expand_comp<small_company>::type) ==
         typeid(add_comp<Hunting_shop, multiply_comp<small_company, 2>::type>::type));

  assert(typeid(Group<add_comp<Accountancy, Exchange_office>::type>::company_type) ==
         typeid(small_company));
  assert(typeid(additive_expand_group(s1).company) ==
         typeid(add_comp<multiply_comp<Accountancy, 2>::type,
                add_comp<Hunting_shop, Exchange_office>::type>::type));
  assert(typeid(additive_rollup_group(s1).company) == typeid(Company<0,0,0>));
  assert(typeid(multiplicative_expand_group(s1).company) ==
         typeid(multiply_comp<Accountancy, 10>::type));
  assert(typeid(multiplicative_rollup_group(s5).company) ==
         typeid(add_comp<multiply_comp<Hunting_shop, 3>::type, Exchange_office>::type));

  assert(solve_auction(s1, s2, s5) == false);
	
}

void group_operations_test()
{	
	typedef Company<1, 2, 3> small;
	Group<small > g;
	Group<additive_expand_comp<small>::type > g2 = additive_expand_group(g);
	cout << g << g2;
	
	
}

int main()
{	
	//type_test();
	//group_test();
	peczar_test1();
	//group_operations_test();
	return 0;
}