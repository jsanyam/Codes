#include<cstdio>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct ll_node
{
    int val;
    struct ll_node *next;
};

void insert_ll(struct ll_node **head, int val)
{
    if(*head == NULL)
    {
        *head = new struct ll_node;
        (*head)->val = val;
        (*head)->next = NULL;
    }
    else
    {
        struct ll_node *temp = new struct ll_node;
        temp->val = val;
        temp->next = *head;
        (*head) = temp;
    }
}

struct node *ll_to_bst(struct ll_node *&head, int first, int last)
{
    if(first > last)
        return NULL;
    int mid = first + (last - first) / 2;
    struct node *left = ll_to_bst(head, first, mid - 1);
    struct node *root = new struct node;
    root->data = head->val;
    head = head->next;
    root->left = left;
    root->right = ll_to_bst(head, mid + 1, last);
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

int main()
{
    struct ll_node *head= NULL;
    for(int i = 6; i >= 0; i--)
        insert_ll(&head, i);
    struct node *root = ll_to_bst(head, 0, 6);
    print_inorder(root);
    return 0;
}
