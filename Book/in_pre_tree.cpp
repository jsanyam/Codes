#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

void print_node(struct node *root)
{
    queue<struct node *> q;
    q.push(root);
    struct node *current;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        printf("%d ", current->data);
        if(current->left)
            q.push(current->left);
        if(current->right)
            q.push(current->right);
    }
}

struct node *in_pre_tree(int in[], int pre[], int in_start, int in_end)
{
    static int pre_iter = 0;
    if(in_start > in_end)
        return NULL;
    struct node *root = new struct node;
    root->data = pre[pre_iter];
    root->left = NULL;
    root->right =NULL;
    pre_iter++;
    if(in_start == in_end)
        return root;
    int i;
    for(i = in_start; i <= in_end; i++)
        if(in[i] == root->data)
                break;
    root->left = in_pre_tree(in, pre, in_start, i - 1);
    root->right = in_pre_tree(in, pre, i + 1, in_end);
    return root;
}

int main()
{
    struct node *root;
    int pre[] = {0, 1, 3, 4, 2, 5};
    int in[] = {3, 1, 4, 0, 5, 2};
    root = in_pre_tree(in, pre, 0, 5);
    print_node(root);
    return 0;
}
