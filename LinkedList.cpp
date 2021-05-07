#include "LinkedList.h"

LinkedList* Create()
{
	LinkedList* new_list = new LinkedList
	{
		0, //count
		nullptr, //head
		nullptr //tail
	};
	return new_list;
}

void Destroy(LinkedList* list) 
{
	Clear(list);
	delete list;
}

void Insert(LinkedList* list, int elem)
{								 //data, next
	struct Node* node = CreateNode(elem, list->head);
	if (IsEmpty(list))		//Verifica se está vazia
		list->tail = node;
	list->head = node;
	list->count++;
}

void Append(LinkedList* list, int elem)
{								// data, next
	struct Node* node = CreateNode(elem, nullptr);
	if (IsEmpty(list))
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->count++;
}

struct Node* RemoveHead(LinkedList* list)
{
	struct Node* toRemove = list->head;
	if (list->head == list->tail)
	{
		list->head = nullptr;
		list->tail = nullptr;
	}
	else 
	{
		list->head = list->head->next;
	}
	--list->count;
	toRemove->next = nullptr;
	return toRemove;
}

struct Node* RemoveTail(LinkedList* list)
{
	if (list->head == list->tail)
	{
		return RemoveHead(list);
	}
	struct Node* toRemove = list->head;
	struct Node* previous = nullptr;
	while (toRemove != list->tail)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}
	previous->next = nullptr;
	list->tail = previous;
	toRemove->next = nullptr;
	list->count--;
	return toRemove;
}

struct Node* RemoveNode(LinkedList* list, int value)
{
	struct Node* toRemove = list->head;
	struct Node* previous = nullptr;
	while (toRemove != nullptr && toRemove->data != value)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}
	if (toRemove == nullptr)
		return nullptr;
	else if (toRemove == list->head)
		return RemoveHead(list);
	else if (toRemove == list->tail)
		return RemoveTail(list);
	else
	{
		previous->next = toRemove->next;
		--list->count;
		toRemove->next = nullptr;
		return toRemove;
	}
}

struct Node* GetHead(LinkedList* list)
{
	return list->head;
}

struct Node* GetTail(LinkedList* list)
{
	return list->tail;
}

struct Node* GetNode(const LinkedList* list, int value)
{
	struct Node* node = list->head;
	while (node != nullptr)
	{
		if (node->data == value)
			return node;
		node = node->next;
	}
	return nullptr;
}

int Count(LinkedList* list)
{
	return list->count;
}

bool IsEmpty(const LinkedList* list)
{
	return ((list->head == nullptr) && (list->tail == nullptr)) || (list->count == 0);
}

bool Clear(LinkedList* list)
{
	struct Node* node = list->head;
	struct Node* next = nullptr;
	while (node != nullptr)
	{
		next = node->next;
		delete node;
		node = next;
	}
	list->count = 0;
	list->head = list->tail = nullptr;
	return IsEmpty(list);
}

struct Node* CreateNode(int data, struct Node* next)
{
	struct Node* node = new Node;
	node->data = data;
	node->next = next;
	return node;
}

void DestroyNode(struct Node* node)
{
	delete node;
}