#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

typedef struct Opportunity
{
	char id[10];
	char name[40];
	char phone[11];
	char status[35];
	Opportunity* next = nullptr;
}Opportunity;

typedef struct
{
	Opportunity* head = nullptr;
	int size = 0;

}OpList;

/*returns true if the list is empty*/
bool ol_isEmpty(OpList ol)
{
	return !(ol.size > 0);
}
/*pushes a new object to the head of the list*/
void ol_prepend(Opportunity* op, OpList* ol)
{
	op->next = ol->head;
	ol->head = op;
	++ol->size;
}
/*pushes a new object to the tail of the list*/
void ol_append(Opportunity* o, OpList* ol)
{
	if (!ol_isEmpty(*ol))
	{
		Opportunity* last = ol->head;
		for (int i = 0; i < ol->size - 1; i++)
		{
			last = last->next;
		}
		last->next = o;
		++ol->size;
	}
	else
		ol_prepend(o, ol);

}
/*gets an object from the list by index*/
Opportunity* ol_get(int index, const OpList* ol)
{
	Opportunity* o = ol->head;
	while (o && index--) {
		o = o->next;
	}
	return o;
}
/*removes an object from the list by index*/
void ol_remove(int index, OpList* ol) {
	Opportunity* toDelete;

	if (index == 0) {
		toDelete = ol->head;
		ol->head = ol->head->next;
	}
	else {
		Opportunity* before = (ol_get(index - 1, ol));
		toDelete = before->next;
		before->next = toDelete->next;
	}

	ol->size--;
	delete toDelete;
}
/*return list's size*/
unsigned ol_length(const OpList* ol) {
	return ol->size;
}
/*transforms a clientlist to array and returns it*/
Opportunity* ol_toArray(OpList* ol)
{
	Opportunity* arr = new Opportunity[ol->size];
	for (int i = 0; i < ol->size; i++)
	{
		arr[i] = *(ol_get(i, ol));
	}

	return arr;
}

OpList* search(OpList ol, const char input[100])
{
	Opportunity* op = ol.head;
	OpList* newop = nullptr;
	while (op != NULL)
	{
		if (input == op->id || input == op->name || input == op->phone)
		{
			ol_append(op, newop);
		}
		op = op->next;
	}
	return newop;
}