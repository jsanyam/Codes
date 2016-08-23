#include<iostream>
using namespace std;

int main()
{
    int t, i, j, length;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        i = 0;
        j = s.size()-1;
        while(i<j)
        {
            if(s[i] != s[j])
                break;
            i++;
            j--;
        }
        if(i<j)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
'facebook': {
        'id': '1508201969495385',
        'secret': '167e0183ff7392c43283e07bd95f5b83'
    }


"twitter_user_name": account,
    "twitter_access_token_key": "986776236-0S9XqKSH5mtXq9oRxwpy4IbSM6sVnDP63ifbUEKu",
    "twitter_consumer_key": "orVBG7irMKWuPZVE3EjzVMHmF",
    "twitter_consumer_secret": "iuujp0hKDAYNkK60C7FjxnAA7l5cn4z34lNyGiX686l2BvVtOA",
    "twitter_access_token_secret": "JkWIrlvCgpomr1hIcntKFMQ1OiAcxuOGuIw3xCDZmJcIq"

consumer_key = 'orVBG7irMKWuPZVE3EjzVMHmF'
            consumer_secret = 'iuujp0hKDAYNkK60C7FjxnAA7l5cn4z34lNyGiX686l2BvVtOA'
            access_token = '986776236-0S9XqKSH5mtXq9oRxwpy4IbSM6sVnDP63ifbUEKu'
            access_token_secret = 'JkWIrlvCgpomr1hIcntKFMQ1OiAcxuOGuIw3xCDZmJcIq'

def trend_search(hash_list):
                consumer_key = 'orVBG7irMKWuPZVE3EjzVMHmF'
                consumer_secret = 'iuujp0hKDAYNkK60C7FjxnAA7l5cn4z34lNyGiX686l2BvVtOA'
                access_token = '986776236-0S9XqKSH5mtXq9oRxwpy4IbSM6sVnDP63ifbUEKu'
                access_token_secret = 'JkWIrlvCgpomr1hIcntKFMQ1OiAcxuOGuIw3xCDZmJcIq'
                auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
                auth.set_access_token(access_token, access_token_secret)
                api = tweepy.API(auth)
