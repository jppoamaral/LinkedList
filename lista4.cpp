//Nome: Joao Pedro de Paula Oliveira do Amaral / TIA: 32049390
//Nome: Nicolas de Barros / TIA: 32070837

#include <iostream>
#include <clocale>
#include "LinkedList.h"

using namespace std;

void Print(const LinkedList* list)
{
	struct Node* temp_ptr = list->head;

	//for (int i = 0; i < list->count; i++)
	while(temp_ptr != nullptr)
	{
		struct Node* aux = GetNode(list, temp_ptr->data);
		cout << aux->data << " ";
		temp_ptr = temp_ptr->next;
	}
	cout << "\n";
}

void PrintListInfo(const LinkedList* list)
{
	if (IsEmpty(list))
	{
		cout << "Lista vazia!\n";
	}
	else
	{
		cout << "Lista: ";
		Print(list);
	}
}

int main()
{
	setlocale(LC_ALL, "pt_BR");
	cout << "*** Lista Ligada/Encadeada (Linked List) ***\n";
	LinkedList* list = Create();
	PrintListInfo(list);
	Insert(list, 1);
	Insert(list, 2);
	Insert(list, 3);
	Append(list, 4);
	Append(list, 5);
	Append(list, 6);
	PrintListInfo(list);
	Clear(list);
	PrintListInfo(list);
	Insert(list, 77);
	Append(list, 88);
	Insert(list, 99);
	Append(list, 3);
	Insert(list, 2);
	Append(list, 1);
	Insert(list, 0);
	PrintListInfo(list);
	Node* temp = RemoveNode(list, 3);
	cout << "Nó removido: " << temp->data << '\n';
	DestroyNode(temp);
	PrintListInfo(list);
	temp = RemoveHead(list);
	cout << "Nó removido: " << temp->data << '\n';
	DestroyNode(temp);
	PrintListInfo(list);
	temp = RemoveTail(list);
	cout << "Nó removido: " << temp->data << '\n';
	DestroyNode(temp);
	PrintListInfo(list);
	Destroy(list);
	cout << "Fim.\n";
 }