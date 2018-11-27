#include <iostream>
#include <string>

typedef struct Client
{
	char id[9];
	char name[30];
	char phone[10];
	char status[25];
	float sum = 0;
	Client* next = nullptr;
}Client;
typedef struct
{
	Client* head = nullptr;
	int size = 0;

}ClientList;
typedef struct Opportunity
{
	char id[9];
	char name[30];
	char phone[10];
	char status[25];
	Opportunity* next = nullptr;
}Opportunity;
typedef struct
{
	Opportunity* head = nullptr;
	int size = 0;

}OpList;
typedef struct Employee
{
	char id[9];
	char name[30];
	char password[10];
	bool isManager;
	Employee* next = nullptr;
}Employee;
typedef struct
{
	Employee* head = nullptr;
	int size = 0;
}EmpList;

/*returns true if the list is empty*/
bool cl_isEmpty(ClientList cl)
{
	return cl.size > 0;
}
/*pushes a new object to the head of the list*/
ClientList* cl_prepend(Client* c, ClientList* cl)
{
	c->next = cl->head;
	cl->head = c;
	++cl->size;
	return cl;
}
/*pushes a new object to the tail of the list*/
ClientList* cl_append(Client* c, ClientList* cl)
{
	if (!cl_isEmpty(*cl))
	{
		Client* last = cl->head;
		for (int i = 0; i < cl->size; i++)
		{
			last = last->next;
		}
		last = c;
		++cl->size;
		return cl;
	}
	return cl_prepend(c, cl);

}
/*gets an object from the list by index*/
Client cl_get(int index, const ClientList* cl)
{
	Client* c = cl->head;
	while (c && index--) {
		c = c->next;
	}
	return *c;
}
/*removes an object from the list by index*/
void cl_remove(int index, ClientList* cl) {
	Client* toDelete;

	if (index == 0) {
		toDelete = cl->head;
		cl->head = cl->head->next;
	}
	else {
		Client* before = &(cl_get(index - 1, cl));
		toDelete = before->next;
		before->next = toDelete->next;
	}

	cl->size--;
	delete toDelete;
}
/*return list's size*/
unsigned cl_length(const ClientList* cl) {
	return cl->size;
}
/*transforms a clientlist to array and returns it*/
Client* cl_toArray(ClientList* cl)
{
	Client* arr = new Client[cl->size];
	for (int i = 0; i < cl->size; i++)
	{
		arr[i] = cl_get(i, cl);
	}

	return arr;
}

/*returns true if the list is empty*/
bool ol_isEmpty(OpList ol)
{
	return ol.size > 0;
}
/*pushes a new object to the head of the list*/
OpList* ol_prepend(Opportunity* op, OpList* ol)
{
	op->next = ol->head;
	ol->head = op;
	++ol->size;
	return ol;
}
/*pushes a new object to the tail of the list*/
OpList* ol_append(Opportunity* o, OpList* ol)
{
	if (!ol_isEmpty(*ol))
	{
		Opportunity* last = ol->head;
		for (int i = 0; i < ol->size; i++)
		{
			last = last->next;
		}
		last = o;
		++ol->size;
		return ol;
	}
	return ol_prepend(o, ol);

}
/*gets an object from the list by index*/
Opportunity ol_get(int index, const OpList* ol)
{
	Opportunity* o = ol->head;
	while (o && index--) {
		o = o->next;
	}
	return *o;
}
/*removes an object from the list by index*/
void ol_remove(int index, OpList* ol) {
	Opportunity* toDelete;

	if (index == 0) {
		toDelete = ol->head;
		ol->head = ol->head->next;
	}
	else {
		Opportunity* before = &(ol_get(index - 1, ol));
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
		arr[i] = ol_get(i, ol);
	}

	return arr;
}

/*returns true if the list is empty*/
bool el_isEmpty(EmpList el)
{
	return el.size > 0;
}
/*pushes a new object to the head of the list*/
EmpList* el_prepend(Employee* e, EmpList* el)
{
	e->next = el->head;
	el->head = e;
	++el->size;
	return el;
}
/*pushes a new object to the tail of the list*/
EmpList* el_append(Employee* e, EmpList* el)
{
	if (!el_isEmpty(*el))
	{
		Employee* last = el->head;
		for (int i = 0; i < el->size; i++)
		{
			last = last->next;
		}
		last = e;
		++el->size;
		return el;
	}
	return el_prepend(e, el);
}
/*gets an object from the list by index*/
Employee el_get(int index, const EmpList* el)
{
	Employee* e = el->head;
	while (e && index--) {
		e = e->next;
	}
	return *e;
}
/*removes an object from the list by index*/
void el_remove(int index, EmpList* el) {
	Employee* toDelete;

	if (index == 0) {
		toDelete = el->head;
		el->head = el->head->next;
	}
	else {
		Employee* before = &(el_get(index - 1, el));
		toDelete = before->next;
		before->next = toDelete->next;
	}

	el->size--;
	delete toDelete;
}
/*return list's size*/
unsigned el_length(const EmpList* el) {
	return el->size;
}
/*transforms a clientlist to array and returns it*/
Employee* el_toArray(EmpList* el)
{
	Employee* arr = new Employee[el->size];
	for (int i = 0; i < el->size; i++)
	{
		arr[i] = el_get(i, el);
	}

	return arr;
}

int main()
{
	char temp[3] = { 'h','i','\0' };
	std::string s(temp);
	std::cout << s;
	system("pause");
	return 0;
}


