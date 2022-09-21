#include "utility.h"
#include "Expression.h"

// ��
string wizard() {
	cout << "������һ�����ʽ��ֻ���������Լ�+-*/��()����" << endl;
	string ret;
	getline(cin, ret);
	return ret;
}

// �ָ�����ı��ʽ
//void split(string& input, vector<string>& expression) {
//	string tmp = "";
//	for (int i = 0; i < input.size(); i++) {
//		if (input[i] == ' ') continue;
//		if (input[i] == '.' || ('0' <= input[i] && input[i] <= '9')) {
//			tmp.push_back(input[i]);
//		}
//		else {
//			if (!tmp.empty()) {
//				expression.push_back(tmp);
//				tmp.clear();
//			}
//			expression.push_back(string(1, input[i]));
//		}
//	}
//}

// ���һ������
//void output(vector<string>& v) {
//	for (auto s : v) {
//		cout << s << " ";
//	}
//	cout << endl;
//}

// ��^��ʾ��ǰ��
//void showNowStep(int step, vector<string>& expression) {
//	system("cls");
//	cout << "��ǰ����" << endl;
//	output(expression);
//	for (int i = 0; i < min(step, (int)expression.size()); i++) {
//		cout << string(expression[i].size() + 1, ' ');
//	}
//	cout << "^" << endl;
//}

// ��ѭ��
void process(Expression &exp) {
	char ch;
	exp.showNowStp();
	while (ch = _getch()) {
		if (ch == 27) break; // ����esc���˳�
		if (ch == 13) {				 
			// ���»س�������һ��
			try {
				int ret = exp.next();
				if (ret) return; // ����
			}
			catch (int error_code) {
				switch (error_code)
				{
				case OVERFLOW:
					cout << "����" << endl;
					return;
				case UNDERFLOW:
					cout << "����������ֲ���" << endl;
					return;
				case SYNTAX_ERROR:
					cout << "�﷨����" << endl;
					return;
				case OPERATOR_ERROR:
					cout << "��֧�ֵ������" << endl;
					return;
				case UNPAIR:
					cout << "���Ų�ƥ��" << endl;
					return;
				case MATH_ERROR:
					cout << "��ѧ����" << endl;
					return;
				default:
					cout << "��������" << endl;
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

	//Stack<char> ops; // �洢�����
	//Stack<double> nums; // �洢������

	process(exp);
	system("pause");

	return 0;
}