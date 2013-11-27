#ifndef HOLDING_HH
#define HOLDING_HH

constexpr int add(int a, int b)
{
	return a + b;
}

constexpr int remove(int a, int b)
{
	return (a - b) > 0 ? (a - b) : 0;
}

constexpr int multiply(int a, int b)
{
	return a * b;
}

constexpr int split(int a, int b)
{
	return a / b;
}


template<int a, int h, int e>
class Company{
	public:
		typedef Company<a, h, e> type;
		constexpr static int acc(){return a;}
		constexpr static int hs(){return h;}
		constexpr static int exo(){return e;}
		
};

typedef Company<1, 0, 0> Accountancy;
typedef Company<0, 1, 0> Hunting_shop;
typedef Company<0, 0, 1> Exchange_office;

template<class C1, class C2> 
struct add_comp{
	typedef Company<add(C1::acc(), C2::acc()), add(C1::hs(), C2::hs()), add(C1::exo(), C2::exo())> type;	
};

template<class C1, class C2> 
struct remove_comp{
	typedef Company<remove(C1::acc(), C2::acc()), remove(C1::hs(), C2::hs()), remove(C1::exo(), C2::exo())> type;	
};

template<class C, unsigned int n> 
struct multiply_comp{
	typedef Company<multiply(C::acc(), n), multiply(C::hs(), n), multiply(C::exo(), n)> type;	
};

template<class C, unsigned int n> 
struct split_comp{
	typedef Company<split(C::acc(), n), split(C::hs(), n), split(C::exo(), n)> type;	
};

template<class C>
struct additive_expand_comp{
	typedef typename add_comp<C, Company<1, 1, 1> >::type type;
};

template<class C>
struct additive_rollup_comp{
	typedef typename remove_comp<C, Company<1, 1, 1> >::type type;
};

#endif












