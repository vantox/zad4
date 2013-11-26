zad4
====
W trakcie rozwiązywania tego zadania musisz wczuć się w rolę menedżera korporacji zarządzającej małymi firmami. W skład każdej firmy może wchodzić pewna nieujemna liczba przedsiębiorstw takich jak: kantory, sklepy myśliwskie oraz biura rachunkowe. W celu ułatwienia przyszłego zarządzania tego typu firmami musisz napisać odpowiednie oprogramowanie, które pomoże Ci dokonywać przeróżnych operacji.

Dwie firmy, które posiadają dokładnie taką samą strukturę (tj. identyczną liczbę kantorów, sklepów myśliwskich oraz biur rachunkowych), uważamy za równoważne. Zbiór równoważnych firm możemy połączyć w grupę firm.

Rozwiązywanie zadania powinieneś zacząć od stworzenia typu szablonowego Company, reprezentującego strukturę firmy. Następnie, używając Company, zdefiniuj typy: Accountancy, Hunting_shop oraz Exchange_office, które odpowiadają małym firmom składającym się odpowiednio z pojedynczego kantoru, sklepu myśliwskiego oraz biura rachunkowego.

W celu ułatwienia opisywania struktury firm definiujemy dodatkowo typy:

+ template<class C1, class C2> struct add_comp;
Firmy łączą się w jedną większą i taką operację powinien opisywać ten typ. Odpowiednia struktura powinna zawierać publiczną definicję type, opisującą strukturę firmy, która powstaje poprzez połączenie C1 oraz C2.

+ template<class C1, class C2> struct remove_comp;
Czasami trzeba pomniejszyć firmę C1 o firmę C2. Zwróć szczególną uwagę na to, że w wyniku pomniejszania ilości przedsiębiorstw konkretnego typu ich liczba nie może być mniejsza od zera. Odpowiednia struktura powinna zawierać publiczną definicję type, opisującą strukturę firmy, która powstaje poprzez "odjęcie" jednej firmy od drugiej.

+ template<class C1, int n> struct multiply_comp;
Utwórz strukturę, która będzie reprezentować strukturę (nie mówimy tutaj o strukturze z języka C++, ale o liczbie konkretnych przedsiębiorstw) Twojej firmy, w której liczba wszystkich przedsiębiorstw zwiększyła się dokładnie n razy.

+ template<class C1, unsigned int n> struct split_comp;
Potrzebny jest również typ, który ułatwi podział firmy na n mniejszych. Niestety często zdarza się tak, że w wyniku podziału na n mniejszych firm niektóre przedsiębiorstwa muszą zostać zamknięte -- dzielimy całkowitoliczbowo, ewentualna reszta z dzielenia przepada.

+ template<class C> struct additive_expand_comp;
Bardzo przydatną operacją jest zwiększenie o jeden liczby wszystkich przedsiębiorstw wchodzących w skład firmy. Napisz typ opisujący efekt takiej operacji.

+ template<class C> struct additive_rollup_comp;
Czasami zdarza się, że musimy zamknąć po jednym przedsiębiorstwie każdego typu, dlatego przygotuj strukturę, która będzie opisywać efekt takiej operacji.

Firmy mogą łączyć się w grupy. W tym celu stwórz szablon klasy Group<Company>, który jest parametryzowany strukturą pojedynczej firmy -- wszystkie firmy tworzące grupę są równoważne (definicja na początku zadania).

Klasa Group<Company> powinna udostępniać następujące metody:

+ Group();
Przygotuj konstruktor domyślny, który tworzy grupę składającą się tylko z jednej firmy.

+ Group(int k);
Utwórz knstruktor, który tworzy grupę składającą się dokładnie z k firm o identycznej strukturze.

+ Group(Group<Gear> const &);
Potrzebny nam będzie również konstruktor tworzący nową grupę, która jest identyczna z tą podaną jako argument.

+ unsigned int const& get_size() const;
Często będziemy korzystać z metody, która zwraca liczbę firm wchodzących w skład grupy.

+ void set_acc_val(unsigned int i);
+ void set_hs_val(unsigned int i);
+ void set_exo_val(unsigned int i);
Napisz również metody pozwalające ustalać nową wartość biura rachunkowego, sklepu myśliwskiego oraz kantoru. Początkowa wartość pojedynczego kantoru to 50, sklepu myśliwskiego to 150, a biura rachunkowego to 15.

+ unsigned int const& get_value() const;
W celu szybkiej wyceny grupy przyda Ci się metoda zwracające wartość danej grupy. 

Wszystkie błędy, które niefortunnie mogłyby się znaleźć w przygotowanym przez Ciebie programie mogłyby kosztować nas bardzo dużo pieniędzy, dlatego w celu ułatwienia testowania klasa Group<Company> powinna zawierać publiczną definicję typu reprezentującego strukturę pojedynczej firmy o nazwie company_type oraz zmienną statyczną company typu company_type.

Oczekujemy również, że zaimplementujesz następujące operatory:

Operatory dodawania i odejmowania na grupach firm: +, -, +=, -=. Pamiętaj o tym, że nie możemy mieć ujemnej liczby firm.

Operatory mnożenia i dzielenia grupy przez liczbę całkowitą: *, /, *=, /=. Naturalnie te operacje modyfikują liczność grupy. Liczność grupy ma pozostać całkowita i nieujemna.

Operatory porównywania grup firm: ==, !=, <, >, <=, >=. Pamiętaj, że w krytycznych sytuacjach nie jest istotne, ile mamy biur rachunkowych. Liczy się tylko liczba kantorów (czyli kasa) oraz sklepów myśliwskich (broń). Posiadanie większej liczby przedsiębiorstw tych dwóch typów czyni nas silniejszymi od przeciwnika.

Operator << wypisuje na strumień opis grupy w formacie: (przykład)
Number of companies: 20; Value: 2650; Structure of group: Accountancies: 10, Hunting_shops: 15, Exchange_offices: 5

Bardzo liczymy również na to, że napiszesz funkcje globalne:

+ template<class C1, class C2> Group<typename add_comp<C1, C2>::type> const join_groups(Group<C1> const &s1, Group<C2> const &s2)
Operacja łączenia grup zdarza się rzadko, ale mimo wszystko musimy być gotowi na tę operację.

+ template<class C> Group<typename additive_expand_comp<C>::type> const additive_expand_group(Group<C> const &s1);
Napisz metodę, która zwiększa o jeden liczbę przedsiębiorstw (wszystkich typów) wchodzących w skład każdej firmy należącej do grupy s1.

+ template<class C> Group<typename multiply_comp<C, 10>::type> const multiplicative_expand_group(Group<C> const &s1);
Napisz metodę, która zwiększa dziesięciokrotnie liczbę przedsiębiorstw (wszystkich typów) wchodzących w skład każdej firmy należącej do grupy s1.

+ template<class C> Group<typename additive_rollup_comp<C>::type> const additive_rollup_group(Group<C> const &s1);
Napisz metodę, która zmniejsza o jeden liczbę przedsiębiorstw (wszystkich typów) wchodzących w skład każdej firmy należącej do grupy s1.

template<class C> Group<typename split_comp<C, 10>::type> const multiplicative_rollup_group(Group<C> const &s1);
Napisz metodę, która zmniejsza dziesięciokrotnie liczbę przedsiębiorstw (wszystkich typów) wchodzących w skład każdej firmy należącej do grupy s1.

+ bool solve_auction(Group<C1> const & g1, Group<C2> const & g2, Group<C3> const & g3)
Napisz funkcję, która pomoże nam określać, czy możliwe jest wyłonienie zwycięzcy przetargu (nie zawsze jest to możliwe) w przypadku, gdy startują w nim grupy g1, g2 oraz g3.

Przykład użycia niektórych konstrukcji:

#include <typeinfo>
#include <cassert>
#include <iostream>
#include <vector>

#include "holding.hh"

typedef add_comp<Accountancy, Exchange_office>::type small_company;
typedef add_comp<multiply_comp<Hunting_shop, 10>::type, multiply_comp<Exchange_office, 20>::type>::type money;
typedef add_comp<multiply_comp<Hunting_shop, 30>::type, multiply_comp<Exchange_office, 10>::type>::type guns;
typedef add_comp<add_comp<multiply_comp<Accountancy, 2>::type, Exchange_office>::type, Hunting_shop>::type tmp;
typedef multiply_comp<Accountancy, 10>::type tmp2;

int main() {
    Group<Accountancy> s1;
    Group<money> s2(20);
    Group<money> s3(20);
    Group<Exchange_office> s4;
    Group<guns> s5(20);

    // Dodanie dwóch przedsiębiorstw w celu utworzenia większej firmy, która następnie zostaje przekształcona w grupę.
    assert(typeid(Group<add_comp<Accountancy, Exchange_office>::type>::company_type) == typeid(small_company));

    // łączenie grup s1 oraz s4, oraz sprawdzanie rozmiaru utworzonej grupy
    assert(join_groups(s1, s4).get_size() == 1);

    // porównywanie typów dwóch firm
    assert(typeid(join_groups(s1, s4).company) == typeid(small_company));

    // sprawdzanie rozmiaru utworzonych grup
    assert((s2 + s3).get_size() == 40);
    assert((s2 += s2).get_size() == 40);
    assert(s2.get_size() == 40);

    // porównywanie dwóch grup
    assert(s2 > s3);

    // porównywanie typów dwóch firm powstałych w wyniku bardzej złożonych operacji
    assert(typeid(split(s3).company) == typeid(add_comp<multiply_comp<Hunting_shop, 5>::type,multiply_comp<Exchange_office, 10>::type>::type));

    // sprawdzanie rozmiaru
    assert(split(s3).get_size() == 20);

    // porównywanie typów dwóch firm
    assert(typeid(split(split(s3)).company)
        == typeid(add_comp<multiply_comp<Hunting_shop, 2>::type,
                           multiply_comp<Exchange_office, 5>::type>::type));

    // sprawdzanie rozmiarów
    assert(split(split(s3)).get_size() == 20);
    assert((s2 - s3).get_size() == 20);
    assert((s3 - s2).get_size() == 0);

    // Przykład na to, że aukcja może nie mieć zwycięzcy.
    assert(solve_auction(s1, s2, s5) == false);

    std::cout << "Gra gitara!" << std::endl;
}

-----------------------------------------------------------------

Rozwiązanie powinno składać się z pliku holding.hh.
Plik ten należy umieścić w repozytorium w katalogu

grupaN/zadanie4/ab123456+cd123456

lub

grupaN/zadanie4/ab123456+cd123456+ef123456

gdzie N jest numerem grupy, a ab123456, cd123456, ef123456 są identyfikatorami
członków zespołu umieszczającego to rozwiązanie. Katalog z rozwiązaniem nie
powinien zawierać innych plików, ale może zawierać podkatalog private, gdzie
można umieszczać różne pliki, np. swoje testy. Pliki umieszczone w tym
podkatalogu nie będą oceniane.