#include <iostream>
#include <queue>
#include <pthread.h>
using namespace std;
pthread_mutex_t mu;
queue<int> q;
void *func(void *arg)
{
    int n = *((int *)arg);
    pthread_mutex_lock(&mu);
    if (!q.empty())
    {
        cout << q.front() << " " << n << endl;
        q.pop();
    }
    pthread_mutex_unlock(&mu);
    return 0;
}
int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        q.emplace(i);
        a[i] = i;
    }
    pthread_mutex_init(&mu, 0);
    pthread_t pids[5];
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&pids[i], 0, func, (void *)&(a[i]));
    }
    void *res;
    int fin = 0;
    for (int i = 0; i < 5; i++)
    {
        fin = pthread_join(pids[i], &res);
        if (fin != 0)
        {
            cout << "fail " << i << endl;
        }
    }
    pthread_mutex_destroy(&mu);
    return 0;
}