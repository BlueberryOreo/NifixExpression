#pragma once
#include "utility.h"
//注：类模板的声明与实现必须放在同一个文件里面
template<typename T>
class Stack
{
private:
	T* stk;
	int idx;
public:
	Stack();
	~Stack();
	void push(T t);
	void pop();
	T top();
	bool empty();
	int size();
	void print();
};

template<typename T>
Stack<T>::Stack() {
	stk = new T[N];
	idx = -1;
}

template<typename T>
Stack<T>::~Stack() {
	if (stk != NULL) delete stk;
}

template<typename T>
void Stack<T>::push(T t) {
	// 抛出异常
	if (idx + 1 >= N) throw OVERFLOW;
	stk[++idx] = t;
}

template<typename T>
void Stack<T>::pop() {
	// 抛出异常
	if (empty()) throw UNDERFLOW;
	idx--;
}

template<typename T>
T Stack<T>::top() {
	// 抛出异常
	if (empty()) throw UNDERFLOW;
	return stk[idx];
}

template<typename T>
bool Stack<T>::empty() {
	return idx == -1;
}

template<typename T>
int Stack<T>::size()
{
	return stk + 1;
}

template<typename T>
void Stack<T>::print()
{
	if (empty()) cout << "Empty!" << endl;
	else {
		for (int i = 0; i <= idx; i++) {
			cout << stk[i] << " ";
		}
		cout << endl;
	}
}
