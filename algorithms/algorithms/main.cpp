#include <iostream>

using namespace std;

template <class T>
struct Node
{
	T data;
	Node *next;
	Node *prev;
	Node(T data) : data(data), next(nullptr), prev(nullptr) {};
};


template <class T>
class CircularList {
public:
	CircularList() : head(nullptr) {};
	~CircularList();
	void addNode(T data);
	bool findData(T data,int &dis);
	template <class U>
	friend std::ostream & operator<<(std::ostream & os, const CircularList<U> & cll);
private:
	Node<T> *head;
	int size;
};


template <class T>
CircularList<T>::~CircularList()
{
	if (head)
	{
		Node<T> * tmp = head;
		while (tmp->next != head)
		{
			Node<T> * t = tmp;
			tmp = tmp->next;
			delete(t);
		}
		delete tmp;
		head = nullptr;
	}
}

template<class T>
void CircularList<T>::addNode(T data)
{
	Node<T> * t = new Node<T>(data);

	if (head == nullptr)
	{
		t->next = t;
		t->prev = t;
		head = t;
		size = 1;
		return;
	}

	Node<T> * tmp = head;
	while (tmp->next != head)
	{
		tmp = tmp->next;
	}

	tmp->next = t;
	t->prev = tmp;
	t->next = head;
	size++;
}


template<class U>
inline std::ostream & operator<<(std::ostream & os, const CircularList<U>& cll)
{
	Node<U> * head = cll.head;
	if (head)
	{
		Node<U> * tmp = head;
		while (tmp->next != head)
		{
			os << tmp->data << " ";
			tmp = tmp->next;
		}
		os << tmp->data;
	}
	return os;
}



template<class T>
bool CircularList<T>::findData(T data, int &dis)
{
	if (head == nullptr)
		return  false;

	Node<T> * tmp;
	int run = 1;
	dis = 0;
	
	while ((run <=  size*2))
	{
		tmp = head;
		dis = 0;
		for (int i = 0; i <= run; i++)
		{
			if (tmp->data == data)
				return true;

			tmp = tmp->next;
			dis++;
			
		}

		tmp = head;
		dis = 0;
		run *= 2;
		for (int i = 0; i <= run; i++)
		{
			if (tmp->data == data)
				return true;

			tmp = tmp->prev;
			dis--;
			
		}
		run *= 2;	
	}

	return false;
}


void main() {

	CircularList<int> cl;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int num;
	int dis=0;
	
	for (size_t i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		cl.addNode(arr[i]);
	}

	cout << cl << endl;

	cout << "Please enter node for the search:  ";
	cin >> num;

	if (cl.findData(num, dis)) {
		cout << "The distance of node = " << num << " is:  " << dis  << endl;
	}
	else {
		cout << "The node = " << num << " not found" << endl;;
	}
	
	system("pause");
	



}

