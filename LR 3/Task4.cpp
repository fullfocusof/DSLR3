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
//	QueueNode* headRange = nullptr;
//	QueueNode* tailRange = nullptr;
//
//	QueueNode* headAbove = nullptr;
//	QueueNode* tailAbove = nullptr;
//
//	ifstream ifs("inputTask4.txt");
//	ofstream ofs("outputTask4.txt");
//
//	int limitA, limitB;
//
//	if (ifs.is_open())
//	{
//		cout << "Введите границу A" << endl;
//		cin >> limitA;
//		cout << endl;
//		cout << "Введите границу B" << endl;
//		cin >> limitB;
//		system("cls");
//
//		while (!ifs.eof())
//		{
//			int temp;
//			ifs >> temp;
//			if (temp < limitA)
//			{
//				ofs << temp << " ";
//			}
//			else if (temp >= limitA && temp <= limitB)
//			{
//				push(headRange, tailRange, temp);
//			}
//			else if (temp > limitB)
//			{
//				push(headAbove, tailAbove, temp);
//			}
//		}
//
//		while (headRange != nullptr)
//		{
//			ofs << pop(headRange, tailRange) << " ";
//		}
//		while (headAbove != nullptr)
//		{
//			ofs << pop(headAbove, tailAbove) << " ";
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