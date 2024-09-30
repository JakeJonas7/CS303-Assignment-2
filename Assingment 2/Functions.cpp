//#include <iostream>
//#include "LinkedList.h"
//using namespace std;
//template<typename Item_Type>
//
//void Linked_List<Item_Type>::push_front(const Item_Type& item) {
//    Node* new_node = new Node(item, head);
//    head = new_node;
//    if (tail == NULL)
//        tail = head;
//    num_items++;
//
//}
//
//template<typename Item_Type>
//void Linked_List<Item_Type>::push_back(const Item_Type& item) {
//    Node* new_node = new Node(item);
//    if (tail != NULL) {
//        tail->next = new_node(item);
//        tail = tail->next;
//        num_items++;
//    }
//    else {
//        push_front(item);
//    }
//
//}
//
//template<typename Item_Type>
//void Linked_List<Item_Type>::pop_front() {
//    if (head == NULL) {
//        throw invalid_argument("Attempt to call pop_front on an empty list");
//    }
//    Node* temp = head;
//    head = head->next;
//    delete temp;
//    if (head == NULL) {
//        tail = NULL;
//    }
//    num_items--;
//}
//
//template<typename Item_Type>
//void Linked_List<Item_Type>::pop_back() {
//    if (tail == NULL) {
//        throw invalid_argument("Attempt to call pop_back() on an empty list");
//    }
//    if (head == tail) {
//        delete tail;
//        head = NULL;
//        tail = NULL;
//    }
//    else {
//        Node* current = head;
//        while (current->next != tail) {
//            current = current->next;
//        }
//        delete tail;
//        tail = current;
//        tail->next = NULL;
//    }
//    num_items--;
//}
//
//template<typename Item_Type>
//Item_Type Linked_List<Item_Type>::front() const {
//    if (head == NULL) {
//        throw invalid_argument("Attempt to call front() on an empty list");
//    }
//    return head->data;
//}
//
//template<typename Item_Type>
//Item_Type Linked_List<Item_Type>::back() const {
//    if (tail == NULL) {
//        throw invalid_argument("Attempt to call back() on an empty list");
//    }
//    return tail->data;
//}
//
//template<typename Item_Type>
//bool Linked_List<Item_Type>::empty() const {
//    return num_items == 0;
//}
//
//template<typename Item_Type>
//void Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
//    if (index >= num_items) {
//        push_back(item);
//        return;
//    }
//    if (index == 0) {
//        push_front(item);
//        return;
//    }
//    Node* current = head;
//    for (size_t i = 0; i < index - 1; i++) {
//        current = current->next;
//    }
//    Node* new_node = new Node(item, current->next);
//    current->next = new_node;
//    num_items++;
//}
//
//template<typename Item_Type>
//bool Linked_List<Item_Type>::remove(size_t index) {
//    if (index >= num_items) {
//        return false;
//    }
//    if (index == 0) {
//        pop_front();
//        return true;
//    }
//    Node* current = head;
//    for (size_t i = 0; i < index - 1; i++) {
//        current = current->next;
//    }
//    Node* temp = current->next;
//    current->next = temp->next;
//    delete temp;
//    num_items--;
//    return true;
//}
//
//template<typename Item_Type>
//size_t Linked_List<Item_Type>::find(const Item_Type& item) {
//    Node* current = head;
//    size_t index = 0;
//    while (current != NULL) {
//        if (current->data == item) {
//            return index;
//        }
//        current = current->next;
//        index++;
//    }
//    return num_items;
//}



