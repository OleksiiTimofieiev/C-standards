#include <iostream>
#include <vector>
#include <map>
#include <initializer_list>
#include <functional>

auto sum() {return 0;}

template<typename H, typename... T>
auto sum(H h, T... t) /*-> decltype(h + sum(t..))*/
{
    return h + sum(t...); // recursive call
};

auto sum_product(double a, double b)
{
    return std::make_pair(a+b, a*b);
}

int		main(void)
{
    std::cout << sum (1, 2.4) << std::endl;

    float s;
    std::tie(s, std::ignore) = sum_product(3, 4);
    std::cout << s << std::endl;

	return (0);
}