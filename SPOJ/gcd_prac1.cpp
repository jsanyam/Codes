#include<iostream>
#include<algorithm>
using namespace std;

struct arr
{
    int index, value;
};

bool comp(struct arr a, struct arr b)
{
    return (a.value < b.value);
}

int bin_search(struct arr items[], int first, int last, int val)
{
    while(first <= last)
    {
        int mid = first + (last - first)/2;
        if(items[mid].value == val)
            return mid;
        else if (items[mid].value < val)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}

int main()
{
    int n, c, i, result, iter = 0;
    cin>>n;
    while(n--)
    {
        iter++;
        cin>>c>>i;
        struct arr items[i];
        for(int j = 0; j < i; j++)
        {
            cin>>items[j].value;
            items[j].index = j + 1;
        }
        sort(items, items + i, comp);
        for(int j = i-1; j >= 0; j--)
            if(items[j].value < c)
            {
                result = bin_search(items, 0, j - 1, c - items[j].value);
                if(result > -1)
                {
                    if(items[result].index > items[j].index)
                        cout<<"Case #"<<iter<<": "<<items[j].index<<" "<<items[result].index<<endl;
                    else
                        cout<<"Case #"<<iter<<": "<<items[result].index<<" "<<items[j].index<<endl;
                    break;
                }
            }
    }
    return 0;
}
