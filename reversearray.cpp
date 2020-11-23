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
        if (start == NULL)
            return new node(data);
        start->next = insertEnd(start->next, data);
        return start;
    }
    node *insertBeg(node *start, int data)
    {
        if (start == NULL)
            return new node(data);
        node *temp = new node(data);
        temp->next = start;
        start = temp;
        return start;
    }

    node *reverse(node *start)
    {

        node *ptr1 = start;
        node *prev = NULL;
        node *next = NULL;
        while (ptr1 != NULL)
        {
            next = ptr1->next;
            ptr1->next = prev;
            prev = ptr1;
            ptr1 = next;
        }
        return prev;
    }
    node *reverse(node *start, int k)
    {

        node *ptr1 = start;
        node *prev = NULL;
        node *next = NULL;
        int count = k;
        while (ptr1 != NULL && count--)
        {
            next = ptr1->next;
            ptr1->next = prev;
            prev = ptr1;
            ptr1 = next;
        }
        next->next = ptr1;
        return ptr1;
    }

    int length(node *start)
    {
        if (start == NULL)
            return 0;
        return 1 + length(start->next);
    }

   

    node *nthnodeFromLast(node *start, int n)
    {
        int listLen = length(start);
        int KthLength = listLen - n;
        node *ptr = start;

        while (KthLength--)
        {
            ptr = ptr->next;
        }
        return ptr;
    }

  

    bool detectLoop(node *root){
        node *slowPtr=root,*fastPtr=root;
        while (slowPtr && fastPtr && fastPtr->next)
        {   
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if(slowPtr == fastPtr)
                return true;
        }
        return false;
        
        
    }

    node * checkPallindrome(node *start){
        node *getSecondHead = getMid(start);
        getSecondHead = reverse(getSecondHead);
        while(start->next && getSecondHead->next){
            
        }
    }

    node * getMid(node *start){
        node *slowPtr = start;
        node *fastPtr = start;
        while(fastPtr->next != NULL){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            
        }
        return slowPtr;
    }

    void print(node *start)
    {
        if (!start)
            return;
        cout << start->data << " ";
        print(start->next);
    }
};

int main()
{
    node *list1 = new node(10);
    list1 = list1->insertEnd(list1, 12);
    list1 = list1->insertEnd(list1, 14);
    list1 = list1->insertEnd(list1, 16);
    list1 = list1->insertEnd(list1, 18);

    list1 = list1->checkPallindrome(list1);
    list1->print(list1);

    return 0;
}