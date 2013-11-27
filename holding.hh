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

template<class C>
class Group{
	private:
		int size, acc_val, hs_val, exo_val;
	public:
		Group();
		Group(unsigned int k);
		Group(const Group<C>& g);
		unsigned int get_size() const{return size;}
		void set_acc_val(unsigned int i);
		void set_hs_val(unsigned int i);
		void set_exo_val(unsigned int i);
		unsigned int get_acc_val() const{return acc_val;}
		unsigned int get_hs_val() const{return hs_val;}
		unsigned int get_exo_val() const{return exo_val;}
		unsigned int get_value() const{return size * (C::acc() * acc_val + C::hs() * hs_val + C::exo() * exo_val);}
		typedef C company_type;
		static company_type company;
		C operator+(C comp);
		C operator-(C comp);
		C operator+=(C comp);
		C operator-=(C comp);
		C operator*(unsigned int i);
		C operator/(unsigned int i);
		C operator*=(unsigned int i);
		C operator/=(unsigned int i);
		/*
		C operator==(C comp1, C comp2);
		C operator!=(C comp1, C comp2);
		C operator<(C comp1, C comp2);
		C operator>(C comp1, C comp2);
		C operator<=(C comp1, C comp2);
		C operator>=(C comp1, C comp2);
		* to chyba globalnie bo muszą być dwa różne typy żeby porównać
		*/
};

template<class C>
Group<C>::Group() : size(1), acc_val(15), hs_val(150), exo_val(50)
{	
}

template<class C>
Group<C>::Group(unsigned int k) : size(k), acc_val(15), hs_val(150), exo_val(50)
{	
}

template<class C>
Group<C>::Group(const Group<C>& g) : size(g.size), acc_val(g.acc_val),
hs_val(g.hs_val), exo_val(g.exo_val)
{	
}

template<class C>
void Group<C>::set_acc_val(unsigned int i)
{
	acc_val = i;
}

template<class C>
void Group<C>::set_hs_val(unsigned int i)
{
	hs_val = i;
}

template<class C>
void Group<C>::set_exo_val(unsigned int i)
{
	exo_val = i;
}



#endif












