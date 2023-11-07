#include <concepts>
#include <iostream>
#include <string>

template <typename T>
concept ComplexConcept = !std::has_virtual_destructor_v<T> &&
    requires(const T val)
    {
        {val.hash()}->std::convertible_to<long>;
        { val.toString() } -> std::same_as<std::string>;
    };


struct A
{
    int _num{ 666 };

    A() {}

    std::string toString() const
    {
        std::string aaa = "AAA";
        return aaa;
        //return std::to_string(_num);
    }

    long hash() const
    {
        return (long)_num;
    }
};

struct B
{
    int _num{ 666 };

    B() {}

    std::string toString() const
    {
        std::string aaa = "AAA";
        return aaa;
    }

    long hash() const
    {
        return (long)_num;
    }

    virtual ~B() {}
};

struct C
{
    int _num{ 666 };

    C() {}

    std::string toString() const
    {
        std::string aaa = "AAA";
        return aaa;
    }
};


void PrintStruct(ComplexConcept auto& t)
{ 
    std::cout << t.toString() << " " << t.hash() << std::endl; 
};


int main()
{
    A aaa; // удовлетворяет концепту
    B bbb; // есть виртуальный деструктор
    C ccc; // нет метода hash()

    PrintStruct(aaa);
    //PrintStruct(bbb);
    //PrintStruct(ccc);
}

