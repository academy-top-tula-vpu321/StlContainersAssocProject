#include <iostream>
#include <set>
#include <string>
#include <map>
#include <unordered_set>

template <typename T1, typename T2>
struct MyPair
{
    T1 first;
    T2 second;
};



class Person
{
    std::string name;
    int age;
public:
    Person(std::string name, int age) 
        : name{ name }, age{ age } {};

    std::string& Name() { return name; }
    int& Age() { return age; }

    std::string ToString()
    {
        return "Name: " + name + ", Age: " + std::to_string(age);
    }

    friend bool operator<(const Person& p1, const Person& p2)
    {
        return p1.name < p2.name;
    }
};

class PersonAgeComparer
{
public:
    bool operator()(Person p1, Person p2) const
    {
        return p1.Age() < p2.Age();
    }
};

int main()
{
    std::set<int> set1{ 75, 11, 61, 21, 35 };
    set1.insert(33);
    set1.insert(61);

    for (auto item : set1)
        std::cout << item << " ";
    std::cout << "\n";

    set1.insert(33);

    auto it = set1.find(21);
    std::cout << *it << "\n";

    std::set <Person, PersonAgeComparer> persons{
        Person("Tom", 25),
        Person("Leo", 33),
        Person("Joe", 21),
        Person("Bill", 39)
    };

    for (auto item : persons)
        std::cout << item.ToString() << "\n";
    std::cout << "\n";

    std::pair<std::string, int> p1;
    p1.first = "One";
    p1.second = 1;


    std::map<std::string, int> numbers;
    numbers.insert({ "two", 2 });
    numbers.insert({ "three", 3 });
    numbers.insert({ "one", 1 });

    numbers.insert({ "one", 100 });
    numbers["one"] = 100;

    for (auto item : numbers)
        std::cout << item.first << " -> " << item.second << "\n";


    try
    {
        auto it = numbers.find("five");
        if(it != numbers.end())
            std::cout << "find!: " << it->first << " -> " << it->second << "\n";
    }
    catch (std::exception e)
    {
        std::cout << e.what() << "\n";
    }

    std::map<Person, std::string> pers;
    pers.insert(std::pair{ Person("Peat", 34), "manager" });



    std::unordered_set<int> unset{ 4, 5, 7, 9, 11, 23 };
    std::cout << "Set: ";
    for (auto item : unset)
        std::cout << item << " ";

}
