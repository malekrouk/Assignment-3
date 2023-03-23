

#pragma once
#include<iostream>

using namespace std;

#define QUEUESIZE 100 

template <class T>
class Queue {

private:
	int front;		// front index
	int rear;		// rear index
	int counter;	// number of elements
	int maxSize;	// size of array queue
	T* values;	// element array

public:

	Queue(int size= QUEUESIZE);			// constructor
	~Queue();	// destructor
	bool IsEmpty(); /*checks if there is anything in the array inside the queue*/
	bool IsFull(); /*checks if there is space left in the array*/
	bool Enqueue(T x);  /*enter element of type T into the array*/
	bool Dequeue(T& x); /*remove element of type T out of the array*/
	void DisplayQueue();/* showcase the array*/

};

template <class T>
Queue<T>::Queue(int size) {
	values = new T[size];
	maxSize = size;
	front = 0;
	rear = -1;
	counter = 0;
}
template <class T>
Queue<T>::~Queue()
{
}
template <class T>
bool Queue<T>::IsEmpty() {
	if (counter)	return false;
	else			return true;
}

template <class T>
bool Queue<T>::IsFull()
{
	if (counter < maxSize)	return false;
	else				return true;
}
template <class T>
bool Queue<T>::Enqueue(T x) {
	if (IsFull()) {
		cout << "Error: the queue is full." << endl;
		return false;
	}
	else {
		// calculate the new rear position (circular)
		rear = (rear + 1) % maxSize;
		// insert new item		
		values[rear] = x;
		// update counter
		counter++;
		return true;
	}
}
template <class T>
bool Queue<T>::Dequeue(T& x) {
	if (IsEmpty()) {
		cout << "Error: the queue is empty." << endl;
		return false;
	}
	else {
		// retrieve the front item
		x = values[front];
		// move front 
		front = (front + 1) % maxSize;
		// update counter
		counter--;
		return true;
	}
}
template <class T>
void Queue<T>::DisplayQueue() {
	cout << "front -->";
	for (int i = 0; i < counter; i++) {
		if (i == 0) cout << "\t";
		else		cout << "\t\t";
		cout << values[(front + i) % maxSize].gethour()<<":"<< values[(front + i) % maxSize].getmin();
		if (i != counter - 1)
			cout << endl;
		else
			cout << "\t<-- rear" << endl;
	}
}


