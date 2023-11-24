//#include <iostream>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//struct QueueNode
//{
//	int data;
//	QueueNode* next;
//};
//
//void push(QueueNode*& head, QueueNode*& tail, int data)
//{
//	QueueNode* temp = new QueueNode;
//	temp->data = data;
//	temp->next = nullptr;
//	if (head == nullptr)
//	{
//		head = temp;
//	}
//	else
//	{
//		tail->next = temp;
//	}
//	tail = temp;
//}
//
//int pop(QueueNode*& head, QueueNode*& tail)
//{
//	int result = head->data;
//
//	QueueNode* temp = head;
//	head = head->next;
//	delete temp;
//
//	if (head == nullptr)
//	{
//		tail = nullptr;
//	}
//
//	return result;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	QueueNode* head = nullptr;
//	QueueNode* tail = nullptr;
//
//	ifstream ifs("inputTask5.txt");
//	ofstream ofs("outputTask5.txt");
//
//	char c;
//
//	if (ifs.is_open())
//	{
//		while (ifs.get(c))
//		{
//			if (isdigit(c))
//			{
//				push(head, tail, c - '0');
//			}
//			else if (c == '\n')
//			{
//				while (head != nullptr)
//				{
//					ofs << pop(head, tail);
//				}
//				ofs << endl;
//			}
//			else
//			{
//				ofs << c;
//			}
//		}
//
//		while (head != nullptr)
//		{
//			ofs << pop(head, tail);
//		}
//
//		cout << "Данные перезаписаны" << endl;
//
//		ifs.close();
//		ofs.close();
//	}
//	else
//	{
//		cerr << "Ошибка открытия файла" << endl;
//	}
//}