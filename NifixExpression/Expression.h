#pragma once
#include "utility.h"
#include "Stack.h"
class Expression
{
private:
	string exp_str;
	vector<string> exp;
	int nowstp;
	Stack<char> ops;
	Stack<double> nums;
	template<typename T>
	void output(vector<T> v); // 输出一个向量
	int greater(char o1, char o2);
public:
	Expression();
	Expression(string expression);
	int next();
	void showNowStp();
	void showOpStk();
	void showNumStk();
};

// template
template<typename T>
void Expression::output(vector<T> v) {
	for (auto c : v) {
		cout << c << " ";
	}
	cout << endl;
}