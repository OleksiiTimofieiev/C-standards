#include <iostream>
#include <vector>
#include <map>
#include <initializer_list>
#include <functional>
#include <memory>

std::string getName()
{
    return "Ivan";
}

int		main(void)
{
    std::string name1 = getName();

    // std::string & name2 = getName();
    std::string && name2 = getName();

    return (0);
}
