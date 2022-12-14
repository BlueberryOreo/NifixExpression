#include "utility.h"
#include "Expression.h"

// 向导
string wizard() {
	cout << "请输入一个表达式（只包含数字以及+-*/和()）：" << endl;
	string ret;
	getline(cin, ret);
	return ret;
}

// 主循环
void process(Expression &exp) {
	char ch;
	exp.showNowStp();
	while (ch = _getch()) {
		if (ch == 27) break; // 按下esc，退出
		if (ch == 13) {				 
			// 按下回车，向后进一步
			try {
				int ret = exp.next();
				if (ret) return; // 结束
			}
			catch (int error_code) {
				switch (error_code)
				{
				case OVERFLOW:
					cout << "上溢" << endl;
					return;
				case UNDERFLOW:
					cout << "运算符或数字不够" << endl;
					return;
				case SYNTAX_ERROR:
					cout << "语法错误" << endl;
					return;
				case OPERATOR_ERROR:
					cout << "不支持的运算符" << endl;
					return;
				case UNPAIR:
					cout << "括号不匹配" << endl;
					return;
				case MATH_ERROR:
					cout << "数学错误" << endl;
					return;
				default:
					cout << "其他错误" << endl;
					return;
				}
			}
			exp.showNowStp();		 
		}
	}	
}		

int main() {

	string input = wizard();
	Expression exp(input);
	//output(expression);

	//Stack<char> ops; // 存储运算符
	//Stack<double> nums; // 存储操作数

	process(exp);
	system("pause");

	return 0;
}