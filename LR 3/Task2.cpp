#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
struct StackNode
{
	T data;
	StackNode* next;
};

template <typename T>
StackNode<T>* push(StackNode<T>*& head, T data)
{
	if (head == nullptr)
	{
		head = new StackNode<T>;
		head->data = data;
		head->next = nullptr;
	}
	else
	{
		StackNode<T>* temp = new StackNode<T>;
		temp->data = data;
		temp->next = head;
		head = temp;
	}

	return head;
}

template <typename T>
StackNode<T>* pop(StackNode<T>*& head)
{
	StackNode<T>* temp = head;
	head = head->next;
	delete temp;

	return head;
}

int solveExpression(StackNode<int>*& head, string ex)
{
	for (int i = 0; i < ex.size(); i++)
	{
		if (ex[i] == '+' || ex[i] == '-' || ex[i] == '*' || ex[i] == '/' || ex[i] == '%' || ex[i] == '^')
		{
			if (head != nullptr)
			{
				int num1 = head->data;
				head = pop(head);
				int num2 = head->data;
				head = pop(head);

				if (ex[i] == '+')
				{
					head = push(head, num2 + num1);
				}
				else if (ex[i] == '-')
				{
					head = push(head, num2 - num1);
				}
				else if (ex[i] == '*')
				{
					head = push(head, num2 * num1);
				}
				else if (ex[i] == '/')
				{
					head = push(head, num2 / num1);
				}
				else if (ex[i] == '%')
				{
					head = push(head, num2 % num1);
				}
				else if (ex[i] == '^')
				{
					head = push(head, (int)pow(num2, num1));
				}
			}
			else
			{
				cerr << "Стэк был пуст" << endl;
			}
		}
		else
		{
			head = push(head, ex[i] - '0');
		}
	}

	if (head == nullptr)
	{
		cerr << "Стэк был пуст" << endl;
	}
	else
	{
		return head->data;
	}
}

float solveExpression(StackNode<float>*& head, string ex)
{
	istringstream iss(ex);
	string temp;
	while (iss >> temp)
	{
		if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
		{
			if (head != nullptr)
			{
				float num1 = head->data;
				head = pop(head);
				float num2 = head->data;
				head = pop(head);

				if (temp == "+")
				{
					head = push(head, num2 + num1);
				}
				else if (temp == "-")
				{
					head = push(head, num2 - num1);
				}
				else if (temp == "*")
				{
					head = push(head, num2 * num1);
				}
				else if (temp == "/")
				{
					head = push(head, num2 / num1);
				}
			}
			else
			{
				cerr << "Стэк был пуст" << endl;
			}
		}
		else
		{
			float value = stof(temp);
			head = push(head, value);
		}
	}

	if (head == nullptr)
	{
		cerr << "Стэк был пуст" << endl;
	}
	else
	{
		return head->data;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	StackNode<int>* head = nullptr;
	StackNode<float>* headF = nullptr;
	string str;

	cout << "Введите выражение" << endl;
	getline(cin, str);
	cout << endl;

	if (str.find_first_of(' ') == string::npos)
	{
		cout << "Ответ: " << solveExpression(head, str) << endl;
	}
	else
	{
		cout << "Ответ: " << solveExpression(headF, str) << endl;
	}
}