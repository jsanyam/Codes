#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t, n, mw, fw;
    long long int m, f;
    scanf("%d", &t);
    while(t--)
    {
        mw = 0;
        fw = 0;
        scanf("%d%lld%lld", &n, &m, &f);
        long long int a[n];
        float wp;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
            if(a[i] != 0 && a[i] % m == 0)
                mw++;
            else if(a[i] != 0 && a[i] % f == 0)
                fw++;
        }
        wp = (float)(mw + fw) / n;
        if(wp >= 0.7)
        {
            printf("Yes\n");
            if(mw > fw)
                printf("Multan\n");
            else if(mw < fw)
                printf("Fultan\n");
            else
                printf("Both\n");
        }
        else
            printf("No\n");
    }
    return 0;
}
