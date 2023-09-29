#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int id;
    struct tree *left;
    struct tree *right;
} tree;

tree* alocNode()
{
    return (tree *)malloc(sizeof(tree));
}

tree *insertNode(tree *node, int id)
{
    if(node == NULL)
    {
        node = alocNode();
        node->id = id;
        node->left = NULL;
        node->right = NULL;
    }
    else
    {
        if(id > node->id)
        {
            node->right = insertNode(node->right, id);
        }

        if(id < node->id)
        {
            node->left = insertNode(node->left, id);
        }
    }

    return node;
}

tree *searchNode(tree *node, int id)
{
    if(node != NULL)
    {
        if(node->id == id)
        {
            return node;
        }
        else
        {
            if(id > node->id)
            {
                return searchNode(node->right, id);
            }

            if(id < node->id)
            {
                return searchNode(node->left, id);
            }
        }
    }

    return NULL;
}

tree *getBiggerNode(tree *node)
{
    if(node->right == NULL)
    {
        return node;
    }

    return getBiggerNode(node->right);   
}

tree *removeNode(tree *node, int id)
{
    if(node != NULL)
    {
        if(node->id == id)
        {
            if(node->left != NULL)
            {
                tree *aux = node->right;

                node = node->left;

                getBiggerNode(node)->right = aux;
                
            } 
            else if(node->right != NULL)
            {
                node = node->right;
            }
        }
        else
        {
            if(id < node->id)
            {
                node->left = removeNode(node->left, id);
            }
            if(id > node->id)
            {
                node->right = removeNode(node->right, id);
            }
        }
    }

    return node;
}

void printTree(tree *tree)
{
    if(tree != NULL){

        if(tree->left != NULL)
        {
            printTree(tree->left);
        }

        printf("%d ", tree->id);

        if(tree->right != NULL)
        {
            printTree(tree->right);
        }

    }
}

int main()
{
    tree *root;

    root = insertNode(root, 5);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 0);

    printTree(root);
    printf("\n");

    root = removeNode(root, 1);

    printTree(root);
    printf("\n");
    return 0;
}