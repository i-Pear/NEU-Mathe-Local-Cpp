#pragma once

template<class T>
class ListNode {
public:
	T data;
	ListNode<T>* prev;
	ListNode<T>* next;

	ListNode(const T& x = T()) : data(x), next(nullptr), prev(nullptr) {}
};

template<class T, class Ref, class Ptr>
class ListIterator {
public:
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	Node* node;

	ListIterator(Node* node)
		: node(node) {}

	Ref operator*() {
		return node->data;
	}

	Ptr operator->() {
		return &node->data;
	}

	Self& operator--() {
		node = node->prev;
		return *this;
	}

	Self operator--(int) {
		Self tmp(*this);
		node = node->prev;
		return tmp;
	}

	Self& operator++() {
		node = node->next;
		return *this;
	}

	Self operator++(int) {
		Self tmp(*this);
		node = node->next;
		return tmp;
	}

	bool operator!=(const Self& s) {
		return node != s.node;
	}

	bool operator==(const Self& s) {
		return node == s.node;
	}
};

template<class T>
class List {
	typedef ListNode<T> Node;
public:
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;

	iterator begin() {
		return iterator(head->next);
	}

	iterator end() {
		return iterator(head);
	}

	const_iterator begin() const {
		return const_iterator(head->next);
	}

	const_iterator end() const {
		return const_iterator(head);
	}

	List() {
		head = new Node;
		head->next = head;
		head->prev = head;
	}

	List(const List<T>& l) {
		head = new Node;
		head->next = head;
		head->prev = head;
		for (auto& i : l) {
			PushBack(i);
		}
	}

	List<T>& operator=(List<T> l) {
		Clear();
		for (auto& i : l) {
			PushBack(i);
		}
	}

	~List() {
		Clear();
		delete head;
		head = nullptr;
	}

	long Size() {
		long size = 0;
		for (const auto& e : *this) {
			++size;
		}
		return size;
	}

	bool Empty() {
		return head->next == head;
	}

	void Clear() {
		Node* cur = head->next;
		while (cur != head) {
			Node* next = cur->next;
			delete cur;

			cur = next;
		}
		head->next = head;
		head->prev = head;
	}

	void PushBack(const T& x) {
		Node* newnode = new Node(x);
		Node* tail = head->prev;
		tail->next = newnode;
		newnode->prev = tail;
		newnode->next = head;
		head->prev = newnode;
	}

	void PopBack() {
		Erase(--end());
	}

	void PushFront(const T& x) {
		Insert(begin(), x);
	}

	void PopFront() {
		Erase(begin());
	}

	void Insert(iterator pos, const T& x) {
		Node* cur = pos.node;
		Node* prev = cur->prev;
		Node* newnode = new Node(x);
		prev->next = newnode;
		newnode->next = cur;
		newnode->prev = prev;
		cur->prev = newnode;
	}

	void Erase(iterator pos) {
		Node* cur = pos.node;
		Node* prev = cur->prev;
		Node* next = cur->next;

		prev->next = next;
		next->prev = prev;
		delete cur;
	}

	void MoveFront(iterator pos) {
		Node* cur = pos.node;
		Node* delprev = cur->prev;
		Node* delnext = cur->next;

		delprev->next = delnext;
		delnext->prev = delprev;

		Node* newcur = begin().node;
		Node* prev = newcur->prev;
		Node* newnode = cur;
		prev->next = newnode;
		newnode->next = newcur;
		newnode->prev = prev;
		newcur->prev = newnode;
	}

private:
	Node* head;
};

#define list List