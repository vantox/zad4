#include<iostream>
#include <typeinfo>
#include <cassert>
#include "holding.hh"

using namespace std;

int main()
{	
	Company<23, 34, 15> a;
	Hunting_shop h;
	Exchange_office e;
	cout << a.accountings << " " << a.hunting_shops << " " << a.exchange_offices << endl;
	cout << h.accountings << " " << h.hunting_shops << " " << h.exchange_offices << endl;
	cout << e.accountings << " " << e.hunting_shops << " " << e.exchange_offices << endl;
	
	
	
	
	
	
	return 0;
}