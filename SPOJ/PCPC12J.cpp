#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
    int t, n, num, max, max_ind;
    scanf("%d", &t);
    while(t--)
    {
        max = -1;
        max_ind = -1;
        scanf("%d", &n);
        map<int, int> freq;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num);
            freq[num]++;
        }
        for(map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++)
        {
            if(((*iter).second % (*iter).first) == 0 && (*iter).second > max)
            {
                max = (*iter).second;
                max_ind = (*iter).first;
            }
        }
        printf("%d\n", max_ind);
    }
    return 0;
}
