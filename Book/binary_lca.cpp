#include<cstdio>
#include<iostream>
#include<queue>
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

struct node *lca(struct node *root, int first, int second)
{
    if(root == NULL)
        return root;
    if(root->data == first || root->data == second)
        return root;
    struct node *left = lca(root->left, first, second);
    struct node *right = lca(root->right, first, second);
    if(left && right)
        return root;
    return (left != NULL)?left:right;
};

int main()
{
    struct node *root = NULL;
    for(int i = 0; i < 7; i++)
        insert_node(&root);
    printf("LCA of given nodes is: %d", lca(root, 3, 4)->data);
    return 0;
}
