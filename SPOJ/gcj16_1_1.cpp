#include<iostream>
using namespace std;

 int main()
 {
     int t, iter = 0, start, end;
     string s;
     char arr[2001];
     cin>>t;
     while(t--)
     {
         iter++;
         cin>>s;
         start = end = s.length();
         arr[start] = s[0];
         for(int i = 1; i < s.length(); i++)
         {
             if(s[i] >= arr[start])
             {
                 arr[--start] = s[i];
             }
             else
             {
                 arr[++end] = s[i];
             }
         }
         cout<<"Case #"<<iter<<": ";
         for(int i = start; i <= end; i++)
            cout<<arr[i];
         cout<<endl;
     }
     return 0;
 }
