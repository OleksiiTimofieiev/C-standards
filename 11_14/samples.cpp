#include <iostream>
#include <vector>
#include <map>
#include <initializer_list>
#include <functional>

/* 1. uniform initialization */

struct Address
{
};

struct Person
{
	std::string name;
	int age;
	Address adress_var;

	Person(const std::string & name, int age) : name(name), age(age) {};

	explicit Person(const Address & address) : adress_var(address){}
};

struct Exchange
{
	int count;
	float rates[2];

	Exchange(std::initializer_list<float> r)
	{
		if (r.size() < 2)
			return ;
		auto i = r.begin();
		rates[0] = *i;
		i++;
		rates[1] = *i; 
	}
};

/* 2. use of auto */

auto a = 0; // int
auto b = 123.f; //float
auto c = L"hello";
auto d = {1,2,3}; // init list;

auto	meaning_of_life() -> int // C++ 11, not necessary for C++ 14
{
	return 42;
}

template<typename T, typename U>
auto add(T t, U u) -> decltype(t+u) // C++ 11, not necessary for C++ 14
{
	return t+u;
}

/* override, final */

class Animal
{
	protected:
		int legs = 4;
	public:
		explicit Animal(int legs):legs(legs) {}
	
	virtual int walk(int steps) /* final */ //=> ban overriding
	{
		return steps * 20;
	}
};

class Human : public Animal
{
	public:
		Human(): Animal(2) {}
		Human (const Human&) = delete; // forbid copy constructor;
	int walk(int steps) override // override => to be clear what to be overrided;
	{
		return steps * 10;
	};
};

/* stongly typed enums */
enum oldColor
{
	Red, Green, Blue
};

oldColor oc = Green;
int g = oc;

enum class NewColor
{
	Red, Green, Blue, Magenta
};

NewColor nc = NewColor::Magenta;
// int m = nc; // not works;

int		main(void)
{
	/* 1. uniform initialization */

	Exchange e{1,2,3};
	Exchange j{1,2}; // initializer list sample;
	int n{4};
	std::vector<int> values1{1,2,3,4,5};
	std::map<std::string, std::string> capitals = {
		{"UK", "London"}
	};
	Person person{"Ivan", 42};
	Person person2{Address()};

	/* 2. use of auto */
	std::map<std::string, std::vector<double>> ticks;
	auto it = ticks.begin();
	std::cout << add(3, 4.5) << std::endl;
	std::cout << add(std::string("Hello, "), "world.") << std::endl;
	std::vector<double> values2;
	// basically declare a type;
	typedef decltype(values2.begin()) dvi; // whatever type of iterator from values.begin();
	typedef decltype(42) myInt;

	/* 3. override, final */
	Human h;
	// Human h2{h}; forbidden

	/* 4. lambdas */
	std::vector<int> scores{8,2,4,1};

	for_each(begin(scores), end(scores), [](int n) -> float{
		std::cout << n << std::endl;
		return n;
	});

	auto zero = 0;
	auto is_positive = [=/* =,  & */](int n) {return n > 0;};
	std::cout << std::boolalpha << is_positive(-2) << std::endl;

	std::function<int(int)> fib = [&fib](int x) {return x < 2 ? 1: fib(x - 1) + fib(x - 2);};
	std::cout << fib(8) << std::endl;

	/* 5. strongly typed enums */
	NewColor nc = NewColor::Magenta;

	/* 6. range base loop */
	std::vector<int> v{1,2,3};

	for (int & a : v)
	{
		a *= a;
	}

	// for (int & x : {1 , 2, 3}) // iterator_list
	// {

	// }

	std::map<std::string, int> histogram;
	for (const auto & kvp : histogram)
	{
		std::cout << kvp.first;
	}




	return (0);
}