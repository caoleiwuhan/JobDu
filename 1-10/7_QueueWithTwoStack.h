#ifndef __7_QUEUE_WITH_TWO_STACK__
#define __7_QUEUE_WITH_TWO_STACK__

#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
	MyQueue() {}
	~MyQueue() {}

	void push(int num);
	void pop();
	int top();
	int size();
	bool isEmpty();

private:
	stack<int> s1;
	stack<int> s2;
};

void Test_7_QueueWithTwoStack();





#endif