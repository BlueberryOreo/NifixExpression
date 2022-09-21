#include "Expression.h"

// private
int Expression::greater(char o1, char o2)
{
	switch (o1) {
	case '+': case '-':
		if (o2 == '(' || o2 == '#') return 1;
		else return -1;
		break;
	case '*': case '/':
		if (o2 == '*' || o2 == '/') return -1;
		else return 1;
		break;
	case '(':
		return 1;
		break;
	case ')':
		if (o2 == '(') return 0;
		else return -1;
		break;
	case '#':
		if (o2 == '#') return 0;
		else return -1;
		break;
	default:
		break;
	}
}

//public
Expression::Expression()
{
	exp.push_back("#");
	nowstp = 0;
}

Expression::Expression(string expression)
{
	if(expression[0] != '#') exp_str = "#" + expression;
	nowstp = 0;

	string tmp = "";
	for (int i = 0; i < exp_str.size(); i++) {
		if (exp_str[i] == ' ') continue;
		if (exp_str[i] == '.' || ('0' <= exp_str[i] && exp_str[i] <= '9')) {
			tmp.push_back(exp_str[i]);
		}
		else {
			if (!tmp.empty()) {
				exp.push_back(tmp);
				tmp.clear();
			}
			exp.push_back(string(1, exp_str[i]));
		}
	}
	if (!tmp.empty()) {
		exp.push_back(tmp);
	}
	if(expression[expression.size() - 1] != '#') exp.push_back("#"); // ��β�ľ���
	ops.push('#'); // ��ͷ�ľ���
}

int Expression::next()
{
	if(nowstp < exp.size()) nowstp++;
	if (exp[nowstp][0] >= '0' && exp[nowstp][0] <= '9') {
		double num = stod(exp[nowstp]);
		nums.push(num);
	}
	else {
		char op = exp[nowstp][0];
		// ��������˼��ţ��������ֵ�stack�ǿյģ���ô��Ϊ��������Ǹ��ţ������ֵ�stack��ѹһ��0
		if (op == '-' && nums.empty()) nums.push(0);
		//cout << "now op:" << op << endl;
		if (nums.empty() && op != '(') throw SYNTAX_ERROR; // û�в�����ȴ�Ѿ�����������������������������
		try {
			int cmp = 1;
			while (!ops.empty() && (cmp = greater(op, ops.top())) < 0) {
				char lastop = ops.top();
				//cout << "lastop:" << lastop << endl;
				ops.pop();
				//ops.push(op);
				double num2 = nums.top();
				nums.pop();
				double num1 = nums.top();
				nums.pop();
				double ans = 0;
				switch (lastop) {
				case '+':
					ans = num1 + num2;
					break;
				case '-':
					ans = num1 - num2;
					break;
				case '*':
					ans = num1 * num2;
					break;
				case '/':
					if (num2 == 0) throw MATH_ERROR;
					ans = num1 / num2;
					break;
				case '(':
					throw UNPAIR;
				default:
					throw OPERATOR_ERROR; // ���Ϸ��������
				}
				nums.push(ans);
			}
			//if (ops.empty() || (cmp = greater(op, ops.top()) >= 0)) {
			//if (!ops.empty()) cout << "89 " << op << " " << ops.top() << endl;
			//cout << cmp << endl;
			if (cmp) {
				if (op != '+' && op != '-' && op != '*' && op != '/' 
					&& op != '(' && op != ')' && op != '#') throw OPERATOR_ERROR;
				//if (!ops.empty() && ops.top() == '(' && op != '(' && op != ')' && 
				//	(exp[nowstp - 1][0] > '9' || exp[nowstp - 1][0] < '0')) throw SYNTAX_ERROR; // ���ź�ֱ�Ӹ��������
				ops.push(op);
				//cout << "push here " << endl;
			}
			else {
				ops.pop();
				//cout << "pop here" << endl;
			}
			//}
		}
		catch (int error_code) {
			//cout << error_code << endl;
			throw error_code;
		}
	}
	if (ops.empty()) {
		double ans = nums.top();
		nums.pop();
		if (!nums.empty()) throw SYNTAX_ERROR;
		showNowStp();
		cout << "������ɣ���Ϊ��" << ans << endl;
		return 1;
	}
	else {
		return 0;
	}
}

void Expression::showNowStp()
{
	system("cls");
	cout << "��ǰ�������س���������esc��ֹ��" << endl;
	output(exp);
	for (int i = 0; i < min(nowstp, (int)exp.size()); i++) {
		cout << string(exp[i].size() + 1, ' ');
	}
	cout << "^" << endl;
	//cout << endl;
	cout << "Option stack: ";
	showOpStk();
	cout << "Number stack: ";
	showNumStk();
}

void Expression::showOpStk()
{
	ops.print();
}

void Expression::showNumStk()
{
	nums.print();
}