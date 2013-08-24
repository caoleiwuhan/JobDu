#include <iostream>

#include "7_QueueWithTwoStack.h"

using namespace std;

void MyQueue::push(int num)
{
	s1.push(num);
}

void MyQueue::pop()
{
	if (!s2.empty())
	{
		s2.pop();
		return;
	}
	if (!s1.empty())
	{
		while (!s1.empty())
		{
			int num = s1.top();
			s1.pop();
			s2.push(num);
		}
		s2.pop();
		return;
	}
	throw std::exception("The Queue is empty!");
}

int MyQueue::top()
{
	if (!s2.empty())
	{
		return s2.top();
	}
	if (!s1.empty())
	{
		while (!s1.empty())
		{
			int num = s1.top();
			s1.pop();
			s2.push(num);
		}
		return s2.top();
	}
	throw std::exception("The Queue is empty!");
}

int MyQueue::size()
{
	return (s1.size() + s2.size());
}

bool MyQueue::isEmpty()
{
	return (this->size() == 0);
}

void Test_7_QueueWithTwoStack()
{
	MyQueue q;
	try
	{
		cout << "top is " << q.top() << endl;
		cout << "size is " << q.size() << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	q.push(1);
	try
	{
		cout << "top is " << q.top() << endl;
		cout << "size is " << q.size() << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	q.push(2);
	q.push(3);
	try
	{
		cout << "top is " << q.top() << endl;
		cout << "size is " << q.size() << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	try
	{
		q.pop();
		cout << "top is " << q.top() << endl;
		cout << "size is " << q.size() << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	try
	{
		q.pop();
		cout << "top is " << q.top() << endl;
		cout << "size is " << q.size() << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	try
	{
		q.pop();
		cout << "top is " << q.top() << endl;
		cout << "size is " << q.size() << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	try
	{
		q.pop();
		cout << "top is " << q.top() << endl;
		cout << "size is " << q.size() << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}