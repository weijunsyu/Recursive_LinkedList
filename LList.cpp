#include <iostream>

 #include "LList.h"


 //constructor
 LList::LList() {
     head = nullptr;
 }

 //copy constructor
 LList::LList(const LList& list) {
	 head = recCopy(list.head);
 }

 //destructor
 LList::~LList() {
	#ifndef NDEBUG
		std::cerr << "the destructor is being called\n";
	#endif
	recDestruct(head);
 }

//assignment overload
LList& LList::operator = (const LList& rtSide) {
	if (this != &rtSide) {
		recDestruct(head);
		head = recCopy(rtSide.head);
	}
	return *this;
 }

bool LList::isEmpty() const {
    if (head == nullptr) {
        return true;
    }
    return false;
}

int LList::length() const {
	return length(head);
}

bool LList::cons(char ch){
	try {
		if (head == nullptr) {
			head = cons(ch, nullptr);
		}
		else {
			head = cons(ch, head);
		}
		return true;
	}
	catch (const std::bad_alloc&) {
		return false;
	}

}

bool LList::append(char ch) {
	try {
		head = recAppend(ch, head);
		return true;
	}
	catch (const std::bad_alloc&) {
		return false;
	}
}

bool LList::remove(char ch) {
	bool flag = false;
	head = recRemove(ch, head, flag);
	return flag;
}

bool LList::found(char ch) const {
	return recFound(ch, head);
}

char LList::getFirst(bool& hasFirst) const {
	if (head == nullptr) {
		hasFirst = false;
		return '\0';
	}
	hasFirst = true;
	return head->item;
}

void LList::reverse() {
	Node* current = head;
	Node* next = nullptr;
	Node* previous = nullptr;
	while (current != nullptr) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
}

void LList::print() const {
	std::cout << "[ ";
	recPrint(head);
	std::cout << "]\n";

}

int LList::length(Node *p) {
	if (p == nullptr) {
		return 0;
	}
	int counter = 1;
	Node* nextNode = p->next;
	while (nextNode != nullptr) {
		nextNode = nextNode->next;
		counter++;
	}
	return counter;
}

LList::Node* LList::cons(char ch, Node*p) {
	return new Node{ ch, p };
}

LList::Node* LList::recAppend(char ch, Node* p) {
	if (p == nullptr) {
		return cons(ch, p);
	}
	p->next = recAppend(ch, p->next);
	return p;
}

void LList::recPrint(const Node* p) {
	if (p != nullptr) {
		std::cout << p->item << " ";
		recPrint(p->next);
	}
}

//precondition: flag is false
LList::Node* LList::recRemove(char ch, Node* p, bool &flag) {
	if (p == nullptr) {
		return p;
	}
	else if (p->item == ch) {
		flag = true;
		Node* discard = p;
		p = p->next;
		delete discard;
		return p;
	}
	p->next = recRemove(ch, p->next, flag);
	return p;
}


void LList::recDestruct(Node* &p) {
	if (p == nullptr || p->next == nullptr) {
		delete p;
	}
	else {
		recDestruct(p->next);
		delete p;
	}
}

LList::Node* LList::recCopy(Node* p) {
	if (p == nullptr) {
		return nullptr;
	}
	Node* copy = cons(p->item, recCopy(p->next));
	return copy;
}

bool LList::recFound(char ch, Node* p) {
	if (p == nullptr) {
		return false;
	}
	else if (p->item == ch) {
		return true;
	}
	return recFound(ch, p->next);
}
