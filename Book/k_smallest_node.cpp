#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *insert_node(struct node *root, int data)
{
    if(root == NULL)
    {
        root = new struct node;
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    if(data < root->data)
        root->left = insert_node(root->left, data);
    else if(data >= root->data)
        root->right = insert_node(root->right, data);
    return root;
}

void print_inorder(struct node *root)
{
    if(root == NULL)
        return;
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

struct node *k_largest(struct node *root, int k, int &count)
{
    if(root == NULL)
        return NULL;
    struct node *k_root = k_largest(root->left, k, count);
    if(k_root)
        return k_root;
    if(++count == k)
        return root;
    return k_largest(root->right, k, count);
}

int main()
{
    struct node *root = NULL, *k_large;
    int data;
    for(int i = 0; i < 7; i++)
    {
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    print_inorder(root);
    int count = 0;
    k_large = k_largest(root, 2, count);
    printf("\nThe k-th largest node data is: %d", k_large->data);
    return 0;
}
