//#include <iostream>
//#include <cmath>
//#include <string>
//
//using namespace std;
//
//template <typename T>
//struct StackNode
//{
//	T data;
//	StackNode<T>* next;
//};
//
//template <typename T>
//StackNode<T>* push(StackNode<T>*& head, T data)
//{
//	if (head == nullptr)
//	{
//		head = new StackNode<T>;
//		head->data = data;
//		head->next = nullptr;
//	}
//	else
//	{
//		StackNode<T>* temp = new StackNode<T>;
//		temp->data = data;
//		temp->next = head;
//		head = temp;
//	}
//
//	return head;
//}
//
//template <typename T>
//StackNode<T>* pop(StackNode<T>*& head)
//{
//	StackNode<T>* temp = head;
//	head = head->next;
//	delete temp;
//
//	return head;
//}
//
//template <typename T>
//int solveExpression(StackNode<T>*& head, string ex)
//{
//	for (int i = 0; i < ex.size(); i++)
//	{
//		if (ex[i] == '+' || ex[i] == '-' || ex[i] == '*' || ex[i] == '/' || ex[i] == '%' || ex[i] == '^')
//		{
//			if (head != nullptr)
//			{
//				int num1 = head->data;
//				head = pop(head);
//				int num2 = head->data;
//				head = pop(head);
//
//				if (ex[i] == '+')
//				{
//					head = push(head, num2 + num1);
//				}
//				else if (ex[i] == '-')
//				{
//					head = push(head, num2 - num1);
//				}
//				else if (ex[i] == '*')
//				{
//					head = push(head, num2 * num1);
//				}
//				else if (ex[i] == '/')
//				{
//					head = push(head, num2 / num1);
//				}
//				else if (ex[i] == '%')
//				{
//					head = push(head, num2 % num1);
//				}
//				else if (ex[i] == '^')
//				{
//					head = push(head, (int)pow(num2, num1));
//				}
//			}
//			else
//			{
//				cerr << "Стэк был пуст" << endl;
//			}
//		}
//		else
//		{
//			head = push(head, ex[i] - '0');
//		}
//	}
//
//	if (head == nullptr)
//	{
//		cerr << "Стэк был пуст" << endl;
//	}
//	else
//	{
//		return head->data;
//	}
//}
//
//int getPriority(char operat)
//{
//	if (operat == '+' || operat == '-') return 1;
//	else if (operat == '*' || operat == '/' || operat == '%') return 2;
//	else if (operat == '^') return 3;
//	else return 0;
//}
//
//template <typename T>
//string postfixEx(string ex, StackNode<T>*& headCh)
//{
//	string postfix;
//
//	for (char c : ex)
//	{
//		if (isdigit(c))
//		{
//			postfix += c;
//		}
//		else if (c == '(')
//		{
//			headCh = push(headCh, c);
//		}
//		else if (c == ')')
//		{
//			while (headCh != nullptr && headCh->data != '(')
//			{
//				postfix += headCh->data;
//				headCh = pop(headCh);
//			}
//
//			if (headCh != nullptr)
//			{
//				headCh = pop(headCh);
//			}
//		}
//		else
//		{
//			while (headCh != nullptr && headCh->data != '(' && (getPriority(headCh->data) >= getPriority(c)))
//			{
//				postfix += headCh->data;
//				headCh = pop(headCh);
//			}
//
//			headCh = push(headCh, c);
//		}
//	}
//
//	while (headCh != nullptr)
//	{
//		postfix += headCh->data;
//		headCh = pop(headCh);
//	}
//
//	return postfix;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	StackNode<char>* headCh = nullptr;
//
//	StackNode<int>* head = nullptr;
//	string str;
//
//	cout << "Введите выражение" << endl;
//	cin >> str;
//	cout << endl;
//
//	string tempEx = postfixEx(str, headCh);
//	cout << "Постфиксная форма: " << tempEx << endl;
//
//	cout << "Ответ - " << solveExpression(head, tempEx) << endl;
//}