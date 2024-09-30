#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
//#include "Functions.cpp"
using namespace std;


template <typename Item_Type>
class Linked_List {
private:
    //Node structure for each element in list
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& data_item, Node* next_ptr = NULL) :
            data(data_item), next(next_ptr) {}
    };

    Node* head; //first node pointer
    Node* tail; //last node pointer
    size_t num_items; // num of elements

public:
    Linked_List() : head(NULL), tail(NULL), num_items(0) {} //construct empty list
    
    void push_front(const Item_Type& item); //insert item at front of list
    void push_back(const Item_Type& item); //insert item at back of list
    void pop_front(); //remove first element of list
    void pop_back(); //remove last element of list
    Item_Type front() const; //return data from first element
    Item_Type back() const; //return data from last element
    bool empty() const; //check if list is empty
    void insert(size_t index, const Item_Type& item); //insert element at specific index
    bool remove(size_t index); //remove element at specified index
    size_t find(const Item_Type& item); //find index of element, return list size if not found


};
template<typename Item_Type>
void Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node* new_node = new Node(item, head); //new node with item pointing to current head
    head = new_node; //set new node as head of list
    if (tail == NULL) //if list was empty, set new node as tail
        tail = head;
    num_items++; 

}

template<typename Item_Type>
void Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node* new_node = new Node(item); //create new node with item
    if (tail != NULL) {
        tail->next = new_node; //set current tail next to new node
        tail = tail->next; //move tail to new node
        num_items++;
    }
    else {
        push_front(item); //if empty, use push_front to insert item into list
    }

}

template<typename Item_Type>
void Linked_List<Item_Type>::pop_front() {
    if (head == NULL) { //if list is empty, throw an error
        throw invalid_argument("Attempt to call pop_front on an empty list");
    }
    Node* temp = head; //store head temporarily
    head = head->next; //move head to next node
    delete temp; //delete old head
    if (head == NULL) { //if list is empty, set tail to null
        tail = NULL;
    }
    num_items--;
}

template<typename Item_Type>
void Linked_List<Item_Type>::pop_back() {
    if (tail == NULL) {
        throw invalid_argument("Attempt to call pop_back() on an empty list");
    }
    if (head == tail) { //if list only has one element
        delete tail; //delete and set head and tail to null
        head = NULL;
        tail = NULL;
    }
    else {
        Node* current = head; //traverse list to find second to last node
        while (current->next != tail) {
            current = current->next;
        }
        delete tail; //delete last node
        tail = current; //set second last node as new tail
        tail->next = NULL;
    }
    num_items--;
}

template<typename Item_Type>
Item_Type Linked_List<Item_Type>::front() const {
    if (head == NULL) {
        throw invalid_argument("Attempt to call front() on an empty list");
    }
    return head->data; //return data of head node
}

template<typename Item_Type>
Item_Type Linked_List<Item_Type>::back() const {
    if (tail == NULL) {
        throw invalid_argument("Attempt to call back() on an empty list");
    }
    return tail->data; //return data of tail node
}

template<typename Item_Type>
bool Linked_List<Item_Type>::empty() const {
    return num_items == 0; //return true if list is empty
}

template<typename Item_Type>
void Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index >= num_items) { //if index is out of bounds, insert at end
        push_back(item);
        return;
    }
    if (index == 0) { //if inserting at front, use push_front
        push_front(item);
        return;
    }
    Node* current = head;
    for (size_t i = 0; i < index - 1; i++) { //iterate through list to find the node before insertion point
        current = current->next;
    }
    Node* new_node = new Node(item, current->next); //create new node
    current->next = new_node; //insert new node in list
    num_items++;
}

template<typename Item_Type>
bool Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) { //if index out of list, return false
        return false;
    }
    if (index == 0) { //if removing first element, use pop_front
        pop_front();
        return true;
    }
    Node* current = head;
    for (size_t i = 0; i < index - 1; i++) { //iterate through list to find node before removal point
        current = current->next;
    }
    Node* temp = current->next; //store node to be removed temporarily
    current->next = temp->next; //pass over node to be removed from one before to one after
    delete temp; //delete the node
    num_items--;
    return true;
}

template<typename Item_Type>
size_t Linked_List<Item_Type>::find(const Item_Type& item) {
    Node* current = head;
    size_t index = 0;
    while (current != NULL) { //iterate through list to find item
        if (current->data == item) { //if item is found, return index
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items; //return number of items if item is not found in list.
}


#endif 