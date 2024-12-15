#include <bits/stdc++.h>
using namespace std;

void fun(int *&p)
{
    cout << "In Fun: " << &p << " " << *p << endl;
}

int main()
{
    int x = 10;
    int *p = &x;
    fun(p);
    cout << "In Main: " << &p << " " << *p << endl;
    return 0;
}