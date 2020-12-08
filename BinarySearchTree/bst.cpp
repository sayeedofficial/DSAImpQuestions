#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;

public:
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
    node *insert(node *root, int key)
    {
        if (root == NULL)
            return new node(key);
        else if (key < root->data)
            root->left = insert(root->left, key);
        else if (key > root->data)
            root->right = insert(root->right, key);

        return root;
    }

    node *remove(node *root, int key)
    {
        if (!root)
            return NULL;
        if (key < root->data)
        {
            root->left = remove(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = remove(root->right, key);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            else if (root->left == NULL)
            {
                node *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {

                node *minNode = root->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                root->data = minNode->data;
                root->right = remove(root->right, minNode->data);
                return root;
            }
        }
        return root;
    }

    bool search(node *root, int key)
    {
        if (!root)
            return false;
        if (root->data == key)
            return true;
        if (key < root->data)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
    void inorder(node *root)
    {
        if (root)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    int min(node *root)
    {
        if (root)
        {
            while (root->left != NULL)
            {
                root = root->left;
            }
            return root->data;
        }
        return root->data;
    }
    int max(node *root)
    {
        if (root)
        {
            while (root->right != NULL)
            {
                root = root->right;
            }
            return root->data;
        }
        return root->data;
    }

    bool checkBST(node *root)
    {

        if (!root)
            return true;
        if (root->left->data <= root->data && root->right->data >= root->data)
        {
            return true;
        }
        return checkBST(root->left) && checkBST(root->right);
    }
    node *lca(node *root, int n1, int n2)
    {
        if (!root)
            return root;
        if (root->data > n1 && root->data > n2)
            return lca(root->left, n1, n2);
        if (root->data < n1 && root->data < n2)
            return lca(root->right, n1, n2);

        return root;
    }

    int internalNodes(node *root)
    {
        if (!root || !root->left && !root->right)
            return 0;
        else
            return 1 + internalNodes(root->left) + internalNodes(root->right);
    }

    int externalNodes(node *root)
    {
        if (!root)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;

        return 1 + externalNodes(root->left) + externalNodes(root->right);
    }
};

int main(int argc, char const *argv[])
{

    node *bst1 = new node(20);
    int ans;
    int t;
    cin >> t;
    while (t--)
    {
        int temp;
        cin >> temp;
        bst1 = bst1->insert(bst1, temp);
    }

    

    node *result = bst1->lca(bst1, 10, 14);
    cout << result->data << " ";

    return 0;
}
