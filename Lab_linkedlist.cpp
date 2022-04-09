/*

Younghyun Kwon

Lab: Linked Lists with Pointers

Date 2-4-2022

Windows 10 Home/ MinGW 8.2.0

*/
#include <iostream>
using namespace std;

class Node
{
public:
  Node()
  {
    next = NULL;
  }
  Node(int value)
  {
    data = value;
    next = NULL;
  }

  int data;
  Node* next;
};

class linkedList
{
public:
  linkedList()
  {
    head = NULL;
  }
  void insertNode(int dataValue);
  void printList();
  void deleteNode(int index);

  Node* head;
};

void linkedList::insertNode(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void linkedList::printList()
{
  Node* temp = head;
  while(temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void linkedList::deleteNode(int index)
{
  Node* temp1 = head;
  Node* temp2 = NULL;
  if(index == 0)
  {
    head = head->next;
    delete temp1;
  }
  else
  {
    for(int i = 0; i < index; i++)
    {
      temp2 = temp1;
      temp1 = temp1->next;
    }

    temp2->next = temp1->next;

    delete temp1;
}

}

int main()
{
  linkedList* l = new linkedList();

  l->insertNode(1);
  l->insertNode(2);
  l->insertNode(4);
  for(int i = 0; i < 10; i++)
  {
    l->insertNode(i);
  }

  l->printList();
  l->deleteNode(0);
  l->deleteNode(4);
  l->printList();


}
