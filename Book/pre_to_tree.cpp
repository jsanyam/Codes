#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

struct node
{
    char data;
    struct node *left, *right;
};

struct node *pre_to_tree(char arr[])
{
    static int i = 0;
    struct node *temp = new struct node;
    temp->data = arr[i];
    temp->left = NULL;
    temp->right = NULL;
    if(arr[i] == 'L')
        return temp;
    i++;
    temp->left = pre_to_tree(arr);
    i++;
    temp->right = pre_to_tree(arr);
    return temp;
}

int main()
{
    char arr[5] = {'I', 'I', 'L', 'L', 'L'};
    struct node *root = pre_to_tree(arr);
    printf("%c ", root->data);
    return 0;
}
