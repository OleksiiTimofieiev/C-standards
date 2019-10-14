#include <iostream>
#include <vector>
#include <map>
#include <initializer_list>
#include <functional>
#include <memory>

class Address
{
    public:
        Address(){}
        Address(const Address &) {std::cout << "copied";};
        int house_number;
        std::string city;
        std::string postcode;
};

Address create_address(int house, std::string postcode)
{
    Address address{};
    address.house_number = house;

    return address;
};

std::unique_ptr<Address> create_address_smart(int house, std::string postcode)
{
    auto a = std::make_unique<Address>();
    a->house_number = house;

    return a;
};

class Person
{
    public:
        // std::unique_ptr<Address> address;
        std::shared_ptr<Address> address;

    Person()
    {
        address = std::make_unique<Address>();
    }
};


int		main(void)
{
   auto my_address = create_address(25, "654654");
   auto my_address_smart = create_address_smart(25, "654654");

    // std::unique_ptr<Address> a;
    std::shared_ptr<Address> a; // no copy constructor; 

    {
        Person p;
        p.address->city = "London";
        a = p.address; // will not compile with unique_ptr;
    }

    return (0);
}
