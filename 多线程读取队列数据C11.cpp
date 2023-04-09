// #include <bits/stdc++.h>
#include <iostream>
#include <mutex>
#include <thread>
#include <queue>
using namespace std;
mutex mu;
queue<int> q;
void func(int n)
{
    mu.lock();
    if (!q.empty())
    {
        cout << n << " " << q.front() << endl;
        q.pop();
    }
    mu.unlock();
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        q.emplace(i);
    }
    for (int i = 0; i < 5; i++)
    {
        thread t(func, i);
        t.join();
    }
    return 0;
}
