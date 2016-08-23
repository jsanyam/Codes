#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int t, ans, iter = 0, i;
    string s;
    cin>>t;
    while(t--)
    {
        ans = 0;
        i = 0;
        iter++;
        cin>>s;
        while(1)
        {
            if(s[0] == '-')
            {
                while(s[i] == '-')
                    i++;
                if(i == s.length())
                {
                    ans += 1;
                    break;
                }
                while(i != 0)
                    s[--i] = '+';
                ans += 1;
            }
            else if(s[0] == '+')
            {
                while(s[i] == '+')
                    i++;
                if(i == s.length())
                    break;
                while(i != 0)
                    s[--i] = '-';
                ans += 1;
            }
        }
        cout<<"Case #"<<iter<<": "<<ans<<endl;
    }
    return 0;
}
