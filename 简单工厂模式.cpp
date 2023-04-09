#include <bits/stdc++.h>
using namespace std;
class AbstractFruit
{
public:
    virtual void ShowName() = 0;
};
class Apple : public AbstractFruit
{
public:
    virtual void ShowName()
    {
        cout << "im apple" << endl;
    }
};
class Banana : public AbstractFruit
{
public:
    virtual void ShowName()
    {
        cout << "im banana" << endl;
    }
};
class Factory
{
public:
    static AbstractFruit *Createfruit(string fruit)
    {
        if (fruit == "apple")
        {
            return new Apple;
        }
        else if (fruit == "banana")
        {
            return new Banana;
        }
        return nullptr;
    }
};
int main()
{
    Factory *factory = new Factory;
    AbstractFruit *fruit = factory->Createfruit("apple");
    fruit->ShowName();
    delete fruit;
    delete factory;
    fruit = nullptr;
    factory = nullptr;
    return 0;
}
