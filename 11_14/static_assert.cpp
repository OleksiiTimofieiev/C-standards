#include <iostream>
#include <vector>
#include <map>
#include <initializer_list>
#include <functional>

template<typename T, size_t size>
class Values
{
    static_assert(size > 1, "Use a scalar"); // check during the compile time
    T values[size];
};

template<typename T, typename U>
auto add(T t, U u)
{
    // type_traits;
    static_assert(std::is_integral<T>::value, "First value has to be integral"); // check during the compile time
    return t + u;
};

int		main(void)
{
	Values<int, 2> values;

    auto result = add(1,2);


	return (0);
}