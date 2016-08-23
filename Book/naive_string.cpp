#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void matching(char *text, char *pat)
{
    int m = strlen(text);
    int n = strlen(pat);
    int i, j;
    for(i = 0; i <= (m - n); i++)
    {
        for(j = 0; j < n; j++)
            if(text[i + j] != pat[j])
                break;
        if(j == n)
            printf("Pattern found at index = %d\n", i);
    }
}

int main()
{
    char text[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    matching(text, pat);
    return 0;
}
