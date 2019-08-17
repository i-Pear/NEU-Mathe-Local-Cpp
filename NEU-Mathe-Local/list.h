#pragma once
template<class T>
struct ListNode
{
	T data;
	ListNode<T>* prev;
	ListNode<T>* next;

	ListNode(const T& x = T()) 
		:data(x)
		, next(nullptr)
		, prev(nullptr)
	{}

};

//迭代器的构造
template<class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	Node*  node;

	ListIterator(Node* node)
		: node(node)
	{}

	Ref operator*()
	{
		return  node->data;
	}
	Ptr operator->()
	{
		return & node->data;
		//return &(operator*());
	}

	//++it; --> it.operator++(&it)
	Self& operator--()
	{
		 node =  node->prev;
		return *this;
	}
	Self operator--(int)
	{
		Self tmp(*this);
		 node =  node->prev;
		return tmp;
	}
	Self& operator++()
	{
		 node =  node->next;
		return *this;
	}
	Self operator++(int)
	{
		Self tmp(*this);
		 node =  node->next;
		return tmp;
	}
	bool operator != (const Self& s)
	{
		return  node != s. node;
	}
	bool operator == (const Self& s)
	{
		return  node == s. node;
	}
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;


	iterator begin()
	{
		return iterator(head->next);
	}

	iterator end()
	{
		return iterator(head);
	}

	const_iterator begin() const
	{
		return const_iterator(head->next);
	}

	const_iterator end() const
	{
		return const_iterator(head);
	}
	List()
	{
		head = new Node;
		head->next = head;
		head->prev = head;
	}

	List(const List<T>& l)
	{
		head = new Node;
		head->next = head;
		head->prev = head;
		List<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			PushFront(*(it++));
		}
	}
	//List<T>& operator=(const List<T>& l);
	List<T>& operator=(List<int> l)
	{
		swap(head, l.head);
		return *this;
	}

	~List()
	{
		Clear();
		delete head;
		head = nullptr;
	}

	size_t Size()
	{
		size_t size = 0;
		for (const auto& e : *this)
		{
			++size;
		}
		return size;
	}

	bool Empty()
	{
		return head->next == head;
		//return begin() == end();
	}
	void Clear()
	{
		Node* cur = head->next;
		while (cur != head)
		{
			Node* next = cur->next;
			delete cur;

			cur = next;
		}
		head->next = head;
		head->prev = head;
	}

	void PushBack(const T& x)
	{
		//Insert(end(),x); 

		Node* newnode = new Node(x);
		Node* tail = head->prev;
		tail->next = newnode;
		newnode->prev = tail;
		newnode->next = head;
		head->prev = newnode;

	}
	void PopBack()
	{
		Erase(end());
	}
	void PushFront(const T& x)
	{
		Insert(begin(), x);
	}
	void PopFront()
	{
		Erase(begin());
	}
	void Insert(iterator pos, const T& x)
	{
		Node* cur = pos. node;
		Node* prev = cur->prev;
		Node* newnode = new Node(x);
		prev->next = newnode;
		newnode->next = cur;
		newnode->prev = prev;
		cur->prev = newnode;
	}
	void Erase(iterator pos)
	{
		Node* cur = pos. node;
		Node* prev = cur->prev;
		Node* next = cur->next;

		prev->next = next;
		next->prev = prev;
		delete cur;
	}
private:
	Node* head;
};

#define list List