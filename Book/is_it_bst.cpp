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

int is_it_bst(struct node *root,  int min, int max)
{
    if(root == NULL)
        return 1;
    if(root->data >= min && root->data < max)
        return is_it_bst(root->left, min, root->data) && is_it_bst(root->right, root->data, max);
    return 0;
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
    printf("\n%s\n", is_it_bst(root, INT_MIN, INT_MAX)?"It is a bst":"It is not a bst");
    return 0;
}
