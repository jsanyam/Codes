#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define d 256

void rk_matching(char *text, char *pat, int q)
{
    int m = strlen(text);
    int n = strlen(pat);
    int pat_hash = 0, text_hash = 0;
    int h = 1, i, j;
    for(i = 0; i < (n - 1); i++)
        h = (h * d) % q;
    for(i = 0; i < n; i++)
    {
        pat_hash = (pat_hash * d + pat[i]) % q;
        text_hash = (text_hash * d + text[i]) % q;
    }
    for(i = 0; i <= m - n; i++)
    {
        if(text_hash == pat_hash)
        {
            for(j = 0; j < n; j++)
                if(text[i + j] != pat[j])
                    break;
            if(j == n)
                printf("Pattern found at index = %d\n", i);
        }
        if(i < (m - n))
        {
            text_hash = (d * (text_hash - (h * text[i])) + text[i + n]) % q;
            if(text_hash < 0)
                text_hash += q;
        }
    }
}

int main()
{
char text[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEKS";
    rk_matching(text, pat, 101);
    return 0;
}
