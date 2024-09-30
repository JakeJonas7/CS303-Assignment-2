#include <iostream>
#include "Stack.h" 
#include "LinkedList.h"
using namespace std;

int main() {
	//Q1 Solution
	Linked_List<int> list;
	
	//Inserting values into list

	list.push_back(100); 
	list.push_back(200);
	list.push_back(300);
	list.push_back(400);
	list.push_front(0);
	list.push_front(-100);
	list.insert(3, 150);
	
	
	cout << "Front of the list is: " << list.front() << endl;
	cout << "Back of the list is: " << list.back() << endl;
	cout << "150 is located at index: " << list.find(150) << endl;


	//Removing elements from list
	list.pop_front();
	list.pop_front();
	list.pop_back();

	//displaying front and back elements after removing
	cout << "Front of list after popping two elements from front: " << list.front() << endl;
	cout << "Back of list after popping one element from back: " << list.back() << endl;
	
	//attempt to remove index 1
	if (list.remove(1)) {
		cout << "Successfully Removed Index 1" << endl;;
	
	}
	else {
		cout << "Failed to Remove Index 1" << endl;;
	}

	//attempt to remove index 100
	if (list.remove(100)) {
		cout << "Successfully Removed Index 100" << endl;
	}
	else {
		cout << "Index 100 does not Exist to be removed" << endl;
	}
	
	//Q2 Solution
	cout << "\nQ2" << endl;
	Stack stack;
	//push values onto the stack
	stack.push(100);
	stack.push(200);
	stack.push(300);
	stack.push(400);

	//displaying top and average of stack
	cout << "Average of the stack is: " << stack.average() << endl;
	cout << "Top of the stack is: " << stack.top() << endl;
	//pop two elements off stack
	stack.pop();
	stack.pop();

	//displaying top element after popping and average
	cout << "Top of the stack after popping two elements is: " << stack.top() << endl;
	cout << "Average of the stack after popping two elements is: " << stack.average() << endl;
	return 0;


}



