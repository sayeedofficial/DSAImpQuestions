#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }

    node *insertEnd(node *start, int data)
    {
        if (!start)
            return new node(data);
        start->next = insertEnd(start->next, data);
        return start;
    }
    node *insertBeg(node *start, int data)
    {
        if (!start)
            return new node(data);
        node *newnode = new node(data);

        newnode->next = start;
        start = newnode;
        return start;
    }
    void print(node *start)
    {
        if (!start)
            return;
        cout << start->data << " ";
        print(start->next);
    }
   
   
        
    
    
};

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    node *list1 = new node(1);

    while (t--)
    {
        for (int i = 2; i < 6; i++)
        {
            list1 = list1->insertEnd(list1,i);
        }
    }
    
    list1->print(list1);

    return 0;
}
