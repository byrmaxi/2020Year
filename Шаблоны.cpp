#include <iostream>
using namespace std;

template<typename T>
class Garage
{
public:
	Garage();
	~Garage();

	void pop(int n);

	void push_back(T data);

	int GetSize() { return Size; }

	T& operator[](const int index);

	void pop_back(int n);

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T name;
		int countViezd;

		Node(T name = T(), Node* pNext = nullptr, int countViezd=0)
		{
			this->name = name;
			this->pNext = pNext;
			this->countViezd = countViezd;
		}
	};


	int Size;
	Node<T>* head;
	Node<T>* tempNode;

};


template<typename T>
Garage<T>::Garage()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
Garage<T>::~Garage()
{
	
}


template<typename T>
void Garage<T>::push_back(T name)
{
	if (head == nullptr)
	{
		head = new Node<T>(name);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(name);

	}

	Size++;
}



template<typename T>
T& Garage<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->name;
		}
		current = current->pNext;
		counter++;
	}
}



template<typename T>
void Garage<T>::pop(int n)
{
	if (n == 1)
	{
		
		cout << "Машина " << head->name << " выехала" << endl;
		head->name = "Пустое место";

		Size--;
		
	}
	else
	{
		pop_back(n);
		cout << "Машина " << tempNode->name << " выехала" << endl;
		Node<T>* previous = this->head;
		for (int i = 0; i < Size - 1; i++)
		{
			previous = previous->pNext;
		}

		tempNode->name = "Пустое место";
		previous->pNext = tempNode;
		Size--;
	}
	

}

template<typename T>
void Garage<T>::pop_back(int n)
{
	while (Size >= n)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < Size - 2; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		tempNode = new Node<T>(toDelete->name, tempNode, toDelete->countViezd);
		tempNode->countViezd++;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}


int main()
{

	setlocale(LC_ALL, "ru");

	int n;
	cout << "Введите количесство машин в гараже" << endl;
	cin >> n;
	Garage<string> gar;
	for (int i = 0; i < n; i++) {
		string name;
		cout << "Введите название " << i << " машины " << endl;
		cin >> name;
		gar.push_back(name);
	}

	
	int a = 0;
	while (a != 3)
	{
		cout << "Выбирите действие:" << endl << "Заезд машины - 1" << endl;
		cout << "Выезд машины - 2" << endl;
		cout << "Закончить работу- 3" << endl;

		cin >> a;
		string name;
		int nomer = 0;
		switch (a) {
		case 1:
			cout << "Введите зачение машины " << endl;
			cin >> name;
			gar.push_back(name);
			cout << "Машина заехала" << endl;
			break;
		case 2:
			cout << "Введите номер машины, которая должна выехать" << endl;
			cin >> nomer;
			gar.pop(nomer);
			break;
		default:
			break;
		}

	}

	for (int i = 0; i <= n; i++)
	{
		cout << gar[i] << endl;
	}

	return 0;
}