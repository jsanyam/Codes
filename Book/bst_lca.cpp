#include<cstdio>
#include<iostream>
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
    else if(data > root->data)
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

struct node *bst_lca(struct node *root, int data1, int data2)
{
    if(root == NULL)
        return NULL;
    if((root->data >= data1 && root->data < data2) || (root->data < data1 && root->data >= data2))
        return root;
    if(root->data >= data1)
        return bst_lca(root->left, data1, data2);
    return bst_lca(root->right, data1, data2);
}

int main()
{
    struct node *root = NULL;
    int data;
    for(int i = 0; i < 7; i++)
    {
        scanf("%d", &data);
        root = insert_node(root, data);
    }
    print_inorder(root);
    printf("\nLeast Common Ancestor of given nodes is: %d", bst_lca(root, 1, 4)->data);
    return 0;
}
