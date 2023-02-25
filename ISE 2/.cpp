#include <iostream>
using namespace std;
template <typename T>
class Stack
{
private:
	int top;
	T *arr;
	int size;

public:
	Stack(int s)
	{
		size = s;
		arr = new T[size];
		top = -1;
	}

	~Stack()
	{
		delete[] arr;
	}

	void push(T n)
	{
		if (top == size - 1)
		{
			cout << "Stack is full!\n";
			return;
		}
		cout << n << " has been pushed" << endl;
		arr[++top] = n;
	}

	void pop()
	{
		if (top == -1)
		{
			cout << "Stack is empty!\n";
			return;
		}
		cout << arr[top] << " has been popped" << endl;
		top--;
	}

	T peek()
	{
		return arr[top];
	}

	bool isEmpty()
	{
		return top == -1;
	}
};

template <typename T>
class Queue
{
private:
	int front;
	int rear;
	T *arr;
	int size;

public:
	Queue(int s)
	{
		size = s;
		arr = new T[size];
		front = rear = -1;
	}

	~Queue()
	{
		delete[] arr;
	}

	void enqueue(T n)
	{
		if (rear == size - 1)
		{
			cout << "Queue is full!\n";
			return;
		}
		cout << n << " has been enqueued" << endl;
		arr[++rear] = n;
	}

	void dequeue()
	{
		if (front == rear)
		{
			cout << "Queue is empty!\n";
			return;
		}
		front++;
		cout << arr[front] << " has been dequeued" << endl;
	}

	T peek()
	{
		return arr[front + 1];
	}

	bool isEmpty()
	{
		return front == rear;
	}
};

int main()
{
	Stack<int> s(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.pop();
	cout << "The TOS is " << s.peek() << "\n";
	s.pop();
	cout << "The TOS is " << s.peek() << "\n";

	cout << endl;

	Queue<int> q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.dequeue();
	q.dequeue();

	return 0;
}