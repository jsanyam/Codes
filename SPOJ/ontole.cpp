#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n, i;
    scanf("%d", &n);
    long long int arr[n];
    for(i = 0; i<n; i++)
        scanf("%lld", &arr[i]);
    sort(arr, arr+n);
    for(i = 0; i<n-2; i= i+2)
        if(arr[i] != arr[i+1])
            break;
    printf("%lld\n", arr[i]);
    return 0;
}
