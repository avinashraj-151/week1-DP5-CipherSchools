#include <bits/stdc++.h>
using namespace std;

double Power_ofnum(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else
    {
        double res = Power_ofnum(x, n / 2);
        if (n & 1)
        {
            return x * res * res;
        }
        else
        {
            return res * res;
        }
    }
}

double myPow(double x, int n)
{
    if (x == 1)
    {
        return x;
    }
    else if (x == -1)
    {
        return (n & 1 ? -1 : 1);
    }
    if (n < 0)
    {
        if (n == INT_MIN)
        {
            return 1 / (x * Power_ofnum(x, INT_MAX));
        }
        return 1 / Power_ofnum(x, -n);
    }
    else
    {
        return Power_ofnum(x, n);
    }
}


int main()
{
    double x;
    cin>>x;
    int n;
    cin>>n;
    cout<<myPow(x, n);
}