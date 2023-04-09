#include <bits/stdc++.h>
using namespace std;
class Lazy
{
public:
    static Lazy *getInstance()
    {
        if (lazy == nullptr)
        {
            lazy = new Lazy;
        }
        return lazy;
    }

private:
    Lazy() {}
    static Lazy *lazy;
};
Lazy *Lazy::lazy = nullptr;
int main()
{
    Lazy *lazy = Lazy::getInstance();
    Lazy *lazy2 = Lazy::getInstance();
    if (lazy2 == lazy)
    {
        cout << 1 << endl;
    }
    return 0;
}
