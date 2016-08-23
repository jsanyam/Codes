#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
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

void vertical_sum(struct node *root, map<int, int> &m, int column)
{
    if(root == NULL)
        return;
    m[column] += root->data;
    vertical_sum(root->left, m, column - 1);
    vertical_sum(root->right, m, column + 1);
}

int main()
{
    struct node *root = NULL;
    for(int i = 0; i < 15; i++)
        insert_node(&root);
    map<int, int> m;
    vertical_sum(root, m, 0);
    for(map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++)
        printf("%d ", iter->second);
    return 0;
}
