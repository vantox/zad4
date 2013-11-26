#ifndef HOLDING_HH
#define HOLDING_HH


template<int a, int h, int e>
class Company{
	public:
		typedef Company<a, h, e> type;
		int accountings = a;
		int hunting_shops = h;
		int exchange_offices = e;
};

typedef Company<1, 0, 0> Accounting;
typedef Company<0, 1, 0> Hunting_shop;
typedef Company<0, 0, 1> Exchange_office;





#endif