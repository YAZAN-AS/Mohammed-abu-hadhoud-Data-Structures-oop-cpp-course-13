#pragma once
#include <iostream>
using namespace std;

template<class T>
class clsDblLinkedList
{
protected:
    int _Size = 0;

public:

    class Node
    {
    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T value) {

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        _Size++;
    }

    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == Value)
                return Current;


            Current = Current->next;
        }

        return NULL;


    }

    void InsertAfter(Node* current, T value) {

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        _Size++;
    }

    void InsertAtEnd(T value) {

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        _Size++;
    }

    void DeleteNode(Node*& NodeToDelete) {

        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;
        _Size--;
    }

    void DeleteFirstNode() {

        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        _Size--;
    }

    void DeleteLastNode() {

        if (head == NULL) {
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _Size--;
    }

    void PrintNodeDetails()
    {

        if (head->prev != NULL)
            cout << head->prev->value;
        else
            cout << "NULL";

        cout << " <--> " << head->value << " <--> ";

        if (head->next != NULL)
            cout << head->next->value << "\n";
        else
            cout << "NULL";

    }

    void PrintListDetails()

    {
        Node* Current = head;
        cout << "\n\n";
        while (head != NULL) {
            PrintNodeDetails();
            Current = Current->next;
        }
    }

    void PrintList()

    {
        Node* Current = head;
        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }


    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        if (_Size == 0)
            return 1;
        else
            return 0;
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        Node* Current = head;
        Node* temp = nullptr;
        while (Current != nullptr)
        {
            temp = Current->prev;
            Current->prev = Current->next;
            Current->next = temp;
            Current = Current->prev;
        }

        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }

    Node* GetNode(int I)
    {
        int Counter = 0;

        if (I > _Size - 1 || I < 0)
        {
            return NULL;
        }

        Node* Current = head;
        while (Current != NULL && (Current->next != NULL))
        {
            if (Counter == I)
                break;

            Current = Current->next;
            Counter++;
        }
        return Current;
    }

    T GetItem(int I)
    {
        Node* ItemNode = GetNode(I);
        if (ItemNode == NULL)
            return NULL;
        else
            return ItemNode->value;
    }

    bool UpdateItem(int I, T Value)
    {
        Node* ItemNode = GetNode(I);
        if (ItemNode == NULL)
            return 0;
        else
            ItemNode->value = Value;
        return 1;
    }

    bool InsertAfter(int I, T Value)
    {
        Node* ItemNode = GetNode(I);
        if (ItemNode == NULL)
        {
            return 0;
        }
        else {
            InsertAfter(ItemNode, Value);
            return 1;
        }
    }
};
