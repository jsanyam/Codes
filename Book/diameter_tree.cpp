#include<cstdio>
#include<climits>
#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

int max_dia = INT_MIN;

void insert_node(struct node **root)
{
    //struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp = new struct node;
    scanf("%d", &temp->data);
    temp->left =NULL;
    temp->right = NULL;
    if(!(*root))
    {
        *root = temp;
        return;
    }
    queue<struct node *> q;
    q.push(*root);
    struct node *current;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        if(current->left)
            q.push(current->left);
        else
        {
            current->left = temp;
            return;
        }
        if(current->right)
            q.push(current->right);
        else
        {
            current->right = temp;
            return;
        }
    }
}

int diameter_tree(struct node *root)
{
    if(root == NULL)
        return 0;
    int left = diameter_tree(root->left);
    int right = diameter_tree(root->right);
    if(left + right + 1 > max_dia)
        max_dia = left + right + 1;
    return ((left > right)?left + 1:right + 1);
}

int main()
{
    struct node *root = NULL;
    for(int i = 0; i < 6; i++)
        insert_node(&root);
    diameter_tree(root);
    printf("%d\n", max_dia);
    return 0;
}
