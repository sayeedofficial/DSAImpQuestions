#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
    node *insert(node *start, int data)
    {
        node *temp;
        queue<node *> myqueue;
        myqueue.push(start);
        while (!myqueue.empty())
        {
            temp = myqueue.front();
            myqueue.pop();
            if (temp->left == NULL)
            {
                temp->left = new node(data);
                break;
            }
            else
            {
                myqueue.push(temp->left);
            }

            if (temp->right == NULL)
            {
                temp->right = new node(data);
                break;
            }
            else
            {
                myqueue.push(temp->right);
            }
        }
        return start;
    }
    bool search(node *root, int key)
    {
        if (root == NULL)
            return false;
        if (root->data == key)
            return true;

        return search(root->left, key) | search(root->right, key);
    }

    void preorder(node *start)
    {
        if (!start)
            return;

        cout << start->data << " ";
        preorder(start->left);
        preorder(start->right);
    }
    int height(node *start)
    {
        if (start == NULL)
            return 0;
        return 1 + max(height(start->left), height(start->right));
    }

    int sum(node *root)
    {
        if (!root)
            return 0;
        return root->data + sum(root->left) + sum(root->right);
    }
    node *removeLeafs(node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        root->left = removeLeafs(root->left);
        root->right = removeLeafs(root->right);
        return root;
    }
    void printNodesWithOutSibling(node *root)
    {

        if (root == NULL || root->left == NULL && root->right == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right != NULL)
        {
            cout << root->right->data << " ";
            printNodesWithOutSibling(root->right);
        }
        if (root->right == NULL && root->left != NULL)
        {
            cout << root->left->data << " ";
            printNodesWithOutSibling(root->left);
        }
        printNodesWithOutSibling(root->left);
        printNodesWithOutSibling(root->right);
    }
};

int main(int argc, char const *argv[])
{

    node *bt1 = new node(1);

    for (int i = 2; i <= 8; i++)
    {
        bt1 = bt1->insert(bt1, i);
    }

    bt1->printNodesWithOutSibling(bt1);

    return 0;
}
