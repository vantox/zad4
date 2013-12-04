#ifndef HOLDING_HH
#define HOLDING_HH
#include<iostream>
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
class Group;  
template<class C>
std::ostream& operator<< (std::ostream& o, const Group<C>& g);

template<class C>
class Group{
	private:
		unsigned int size, acc_val, hs_val, exo_val;
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
		Group<C> operator+(Group<C> g);
		Group<C> operator-(Group<C> g);
		Group<C> operator+=(Group<C> g);
		Group<C> operator-=(Group<C> g);
		Group<C> operator*(unsigned int i);
		Group<C> operator/(unsigned int i);
		Group<C> operator*=(unsigned int i);
		Group<C> operator/=(unsigned int i);
		template<class C2>
		bool operator>(Group<C2> g) const;
		template<class C2>
		bool operator<(Group<C2> g) const;
		template<class C2>
		bool operator>=(Group<C2> g) const;
		template<class C2>
		bool operator<=(Group<C2> g) const;
		template<class C2>
		bool operator==(Group<C2> g) const;
		template<class C2>
		bool operator!=(Group<C2> g) const;
		friend std::ostream& operator<< <>(std::ostream& o, const Group<C>& g);
		
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

template<class C>
Group<C> Group<C>::operator+(Group<C> g)
{	
	Group<C> group(*this);
	group.size += g.size;
	if((group.size == 0 ) || (C::acc() == 0))
		group.acc_val = 0;
	else
		group.acc_val = (size * acc_val + g.size * g.acc_val) / group.size;
	if((group.size == 0 ) || (C::hs() == 0))
		group.hs_val = 0;
	else
		group.hs_val = (size * hs_val + g.size * g.hs_val) / group.size;
	if((group.size == 0 ) || (C::exo() == 0))
		group.exo_val = 0;
	else
		group.exo_val = (size * exo_val + g.size * g.exo_val) / group.size;	
	return group;
}

template<class C>
Group<C> Group<C>::operator-(Group<C> g)
{	
	Group<C> group(*this);
	if(group.size > g.size){
		group.size = group.size - g.size;
		if(C::acc() == 0)
			group.acc_val = 0;
		else
			group.acc_val = (size * acc_val - g.size * g.acc_val) / group.size;
		if(C::hs() == 0)
			group.hs_val = 0;
		else
			group.hs_val = (size * hs_val - g.size * g.hs_val) / group.size;
		if(C::exo() == 0)
			group.exo_val = 0;
		else
			group.exo_val = (size * exo_val - g.size * g.exo_val) / group.size;
	}
	else{	
		group.size = 0;
		group.acc_val = 0;
		group.hs_val = 0;
		group.exo_val = 0;
	}		
	return group;	
}

template<class C>
Group<C> Group<C>::operator+=(Group<C> g)
{	
	int new_size = size + g.size;
	if((new_size == 0) || (C::acc() == 0))
		acc_val = 0;
	else
		acc_val = (size * acc_val + g.size * g.acc_val) / new_size;
	if((new_size == 0) || (C::hs() == 0))
		hs_val = 0;
	else
		hs_val = (size * hs_val + g.size * g.hs_val) / new_size;
	if((new_size == 0) || (C::exo() == 0))
		exo_val = 0;
	else
		exo_val = (size * exo_val + g.size * g.exo_val) / new_size;
	size = new_size;
	return *this;
}

template<class C>
Group<C> Group<C>::operator-=(Group<C> g)
{	
	int new_size = (size - g.size) >= 0 ? (size - g.size) : 0;
	if(new_size > 0){
		if(C::acc() == 0)
			acc_val = 0;
		else
			acc_val = (size * acc_val - g.size * g.acc_val) / new_size;
		if(C::hs() == 0)
			hs_val = 0;
		else
			hs_val = (size * hs_val - g.size * g.hs_val) / new_size;
		if(C::exo() == 0)
			exo_val = 0;
		else
			exo_val = (size * exo_val - g.size * g.exo_val) / new_size;
	}
	else{
		acc_val = 0;
		hs_val = 0;
		exo_val = 0;
	}	
	size = new_size;
	return *this;
}

template<class C>
Group<C> Group<C>::operator*(unsigned int i)
{
	Group<C> group(*this);
	group.size *= i;
	if (group.size == 0){
		group.acc_val = 0;
		group.hs_val = 0;
		group.exo_val = 0;
	}
	else{
		group.acc_val /= i;
		group.hs_val /= i;
		group.exo_val /= i;
	}
	return group;	
}

template<class C>
Group<C> Group<C>::operator/(unsigned int i)
{
	Group<C> group(*this);
	if(i == 0)
		group.size = 0;
	else
		group.size /= i;
	group.acc_val *= i;
	group.hs_val *= i;
	group.exo_val *= i;
	
	return group;	
}

template<class C>
Group<C> Group<C>::operator*=(unsigned int i)
{
	size *= i;
	if (size == 0){
		acc_val = 0;
		hs_val = 0;
		exo_val = 0;
	}
	else{
		acc_val /= i;
		hs_val /= i;
		exo_val /= i;
	}
	return *this;	
}

template<class C>
Group<C> Group<C>::operator/=(unsigned int i)
{
	if(i == 0)
		size = 0;
	else
		size /= i;
	acc_val *= i;
	hs_val *= i;
	exo_val *= i;
	
	return *this;	
}

template<class C> template<class C2>
bool Group<C>::operator>(Group<C2> g) const
{
	return ((C::hs() * size) > (C2::hs() * g.get_size()) &&
	(C::exo() * size) > (C2::exo() * g.get_size()));
}

template<class C> template<class C2>
bool Group<C>::operator<(Group<C2> g) const
{
	return ((C::hs() * size) < (C2::hs() * g.get_size()) &&
	(C::exo() * size) < (C2::exo() * g.get_size()));
}

template<class C> template<class C2>
bool Group<C>::operator>=(Group<C2> g) const
{
	return ((C::hs() * size) >= (C2::hs() * g.get_size()) &&
	(C::exo() * size) >= (C2::exo() * g.get_size()));
}

template<class C> template<class C2>
bool Group<C>::operator<=(Group<C2> g) const
{
	return ((C::hs() * size) <= (C2::hs() * g.get_size()) &&
	(C::exo() * size) <= (C2::exo() * g.get_size()));
}

template<class C> template<class C2>
bool Group<C>::operator==(Group<C2> g) const
{
	return ((C::hs() * size) == (C2::hs() * g.get_size()) &&
	(C::exo() * size) == (C2::exo() * g.get_size()));
}

template<class C> template<class C2>
bool Group<C>::operator!=(Group<C2> g) const
{
	return ((C::hs() * size) != (C2::hs() * g.get_size()) ||
	(C::exo() * size) != (C2::exo() * g.get_size()));
}

template<class C>
std::ostream& operator<<(std::ostream& o, const Group<C>& g)	
{
	o << "Number of companies: " << g.size << "; Value: " << g.get_value() << std::endl;
	o << "Accountancies value: " << g.acc_val <<", Hunting shops value: " << g.hs_val << ", Exchange offices value: " << g.exo_val << std::endl;
	o << "Accountancies: " << C::acc() << ", Hunting shops: " << C::hs() << ", Exchange offices: " << C::exo() << std::endl;	
	return o;
}

template<class C>
Group<typename additive_expand_comp<C>::type> const
additive_expand_group(Group<C> const &s1)
{
	Group<typename additive_expand_comp<C>::type> g(s1.get_size());
	g.set_acc_val(s1.get_acc_val());
	g.set_hs_val(s1.get_hs_val());
	g.set_exo_val(s1.get_exo_val());	
	return g;
}

template<class C>
Group<typename additive_rollup_comp<C>::type> const
additive_rollup_group(Group<C> const &s1)
{
	Group<typename additive_rollup_comp<C>::type> g(s1.get_size());
	g.set_acc_val(s1.get_acc_val());
	g.set_hs_val(s1.get_hs_val());
	g.set_exo_val(s1.get_exo_val());	
	return g;
}

template<class C>
Group<typename multiply_comp<C, 10>::type> const
multiplicative_expand_group(Group<C> const &s1)
{
	Group<typename multiply_comp<C, 10>::type> g(s1.get_size());
	g.set_acc_val(s1.get_acc_val());
	g.set_hs_val(s1.get_hs_val());
	g.set_exo_val(s1.get_exo_val());	
	return g;
}

template<class C>
Group<typename split_comp<C, 10>::type> const
multiplicative_rollup_group(Group<C> const &s1)
{
	Group<typename split_comp<C, 10>::type> g(s1.get_size());
	g.set_acc_val(s1.get_acc_val());
	g.set_hs_val(s1.get_hs_val());
	g.set_exo_val(s1.get_exo_val());	
	return g;
}


template<class C1, class C2, class C3>
bool solve_auction(Group<C1> const &g1, Group<C2> const &g2, Group<C3> const &g3)
{	
	bool solve = false;
	if((g1 > g2) && (g1 > g3)) solve = true;
	if((g2 > g1) && (g2 > g3)) solve = true;
	if((g3 > g2) && (g3 > g1)) solve = true;
	return solve;
}

#endif












