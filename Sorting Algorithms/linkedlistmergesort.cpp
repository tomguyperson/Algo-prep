#include <iostream>
#include <math.h>

using namespace std;

struct node
{
    node* next;
    int key;
};

node* merge_sort(node* head);
node* merge(node* left, node* right);

int main()
{
    node* newNode = new node; 
    newNode->key = floor(rand() % 10) + 1;
    node* prevNode = newNode; 
    node* head = newNode;

    for(int i = 0; i < 10; i++)
    {
        newNode = new node; 
        newNode->key = floor(rand() % 10) + 1;
        prevNode->next = newNode;
        prevNode = newNode;
    }
    newNode->next = nullptr;

    //print pre sort
    newNode = head;
    while(newNode->next != nullptr)
    {
        cout << newNode->key << ", ";
        newNode = newNode->next;
    }
    cout << endl;

    newNode = merge_sort(head);

    //print after sort
    // newNode = head;
    while(newNode->next != nullptr)
    {
        cout << newNode->key << ", ";
        newNode = newNode->next;
    }
    cout << endl;

    return 1;
}

node* merge_sort(node* head)
{
    if(head->next != nullptr)
    {
        node* lead = head, *lag = head;

        while(lead->next != nullptr)
        {
            lead = lead->next;
            if(lead->next != nullptr)
            {
                lead = lead->next;
                lag = lag->next;
            }
        }

        node* right = lag->next;
        lag->next = nullptr;         

        node* left = merge_sort(head);
        right = merge_sort(right);
        return merge(left, right);
    }
    else
    {
        return head;
    }

}

node* merge(node* left, node* right)
{
    node* listHead = nullptr; 
    node* curList;

    while(left != nullptr && right != nullptr)
    {
        if(left->key < right->key)
        {
            if(listHead == nullptr)
            {
                listHead = left;
                left = left->next;
                curList = listHead;
            }
            else
            {
                curList->next = left;
                left = left->next;
                curList = curList->next;
            }
        }
        else
        {
            if(listHead == nullptr)
            {
                listHead = right;
                right = right->next;
                curList = listHead;
            }
            else
            {
                curList->next = right;
                right = right->next;
                curList = curList->next;
            }
        }
    }

    if(right != nullptr)
        curList->next = right;


    if(left != nullptr)
        curList->next = left;


    return listHead;
}