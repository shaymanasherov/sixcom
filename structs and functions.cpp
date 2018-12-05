#include <iostream>
#include <string>

typedef struct Client
{
	char id[10];
	char name[40];
	char phone[11];
	char status[35];
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
typedef struct Employee
{
	char id[10];
	char name[40];
	char password[20];
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
void cl_prepend(Client* c, ClientList* cl)
{
	c->next = cl->head;
	cl->head = c;
	++cl->size
}
/*pushes a new object to the tail of the list*/
void cl_append(Client* c, ClientList* cl)
{
	if (!cl_isEmpty(*cl))
	{
		Client* last = cl->head;
		for (int i = 0; i < cl->size-1; i++)
		{
			last = last->next;
		}
		last->next = c;
		++cl->size;
		return cl;
	}
	else
		cl_prepend(c, cl);

}
/*gets an object from the list by index*/
Client* cl_get(int index, const ClientList* cl)
{
	Client* c = cl->head;
	while (c && index--) {
		c = c->next;
	}
	return c;
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
		arr[i] = *(cl_get(i, cl));
	}

	return arr;
}

/*returns true if the list is empty*/
bool ol_isEmpty(OpList ol)
{
	return ol.size > 0;
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
		for (int i = 0; i < ol->size-1; i++)
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
		arr[i] = *(ol_get(i, ol));
	}

	return arr;
}

/*returns true if the list is empty*/
bool el_isEmpty(EmpList el)
{
	return el.size > 0;
}
/*pushes a new object to the head of the list*/
void el_prepend(Employee* e, EmpList* el)
{
	e->next = el->head;
	el->head = e;
	++el->size;
}
/*pushes a new object to the tail of the list*/
void* el_append(Employee* e, EmpList* el)
{
	if (!el_isEmpty(*el))
	{
		Employee* last = el->head;
		for (int i = 0; i < el->size-1; i++)
		{
			last = last->next;
		}
		last->next = e;
		++el->size;
	}
	else
		el_prepend(e, el);
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
		arr[i] = *(el_get(i, el));
	}

	return arr;
}

int main()
{
	\\char to string
	char temp[3] = { 'h','i','\0' };
	std::string s(temp);
	std::cout << s;
	
	
	\\input eg
	ClientList* cl = new ClientList;
	Client* c = new Client;
	std::string id1 = "209239276";
	strcpy(c->id, id1.c_str());
	std::string name1 = "Ofek";
	strcpy(c->name, name1.c_str());
	std::string p1 = "0524771955";
	strcpy(c->phone, p1.c_str());
	std::string s1 = "won";
	strcpy(c->status, s1.c_str());
	c->sum = 100;
	cl_prepend(c,cl);
	Print(*cl);
	cl_remove(0, cl);
	Print(*cl);
	system("pause");
	return 0;
	
	
	
}


