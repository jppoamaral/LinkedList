#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>

struct Node
{
	int data;
	struct Node* next;
};

struct LinkedList
{
	int count;
	Node* head;
	Node* tail;
};

LinkedList* Create();

void Destroy(LinkedList* list);

void Insert(LinkedList* list, int elem);

void Append(LinkedList* list, int elem);

struct Node* RemoveHead(LinkedList* list);

struct Node* RemoveTail(LinkedList* list);

struct Node* RemoveNode(LinkedList* list, int value);

struct Node* GetHead(LinkedList* list);

struct Node* GetTail(LinkedList* list);

struct Node* GetNode(const LinkedList* list, int value);

int Count(LinkedList* list);

bool IsEmpty(const LinkedList* list);

bool Clear(LinkedList* list);

struct Node* CreateNode(int data, struct Node* next);

void DestroyNode(struct Node* node);

#endif