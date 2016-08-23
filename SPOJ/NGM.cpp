#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long int t;
    scanf("%lld", &t);
    int n = t % 10;
    if(n)
        printf("1\n%d\n", n);
    else
        printf("2\n");
    return 0;
}
