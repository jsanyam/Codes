#include<cstdio>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

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

int find_height(struct node *root)
{
    if(!root)
        return 0;
    int left, right, max = INT_MIN;
    left = find_height(root->left);
    right = find_height(root->right);
    if(left > right)
        max = left + 1;
    else
        max = right + 1;
    return max;
}

int main()
{
    struct node *root = NULL;
    for(int i = 0; i < 8; i++)
        insert_node(&root);
    printf("%d\n", find_height(root));
    return 0;
}
