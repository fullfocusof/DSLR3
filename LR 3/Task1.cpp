//#include <iostream>
//
//using namespace std;
//
//struct StackNode
//{
//	char data;
//	StackNode* next;
//};
//
//StackNode* push(StackNode*& first, char data)
//{
//	if (first == nullptr)
//	{
//		first = new StackNode;
//		first->data = data;
//		first->next = nullptr;
//	}
//	else
//	{
//		StackNode* temp = new StackNode;
//		temp->data = data;
//		temp->next = first;
//		first = temp;
//	}
//
//	return first;
//}
//
//bool isValid(string s, StackNode*& first)
//{
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')
//		{
//			first = push(first, s[i]);
//		}
//		else if (s[i] == ')' || s[i] == '}' || s[i] == ']' || s[i] == '>')
//		{
//			if (first != nullptr)
//			{
//				if (s[i] == ')' && first->data == '(')
//				{
//					StackNode* temp = first;
//					first = first->next;
//					delete temp;
//				}
//				else if (s[i] == '}' && first->data == '{')
//				{
//					StackNode* temp = first;
//					first = first->next;
//					delete temp;
//				}
//				else if (s[i] == ']' && first->data == '[')
//				{
//					StackNode* temp = first;
//					first = first->next;
//					delete temp;
//				}
//				else if (s[i] == '>' && first->data == '<')
//				{
//					StackNode* temp = first;
//					first = first->next;
//					delete temp;
//				}
//			}
//			else return false;
//		}
//	}
//
//	if (first == nullptr) return true;
//	else return false;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	StackNode* first = nullptr;
//	string str;
//
//	cout << "Введите строку" << endl;
//	cin >> str;
//	cout << endl;
//
//	if (isValid(str, first))
//	{
//		cout << "Корректная строка" << endl;
//	}
//	else
//	{
//		cout << "Некорректная строка" << endl;
//	}
//}