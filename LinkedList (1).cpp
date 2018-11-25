#include <sstream>
#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::LinkedList(const LinkedList& other) : LinkedList() {
    Node* head = other.head;

    while (head) {
        this->append(head->data);
        head = head->next;
    }
}

LinkedList::LinkedList(int* values, int length) : LinkedList() {
    for (int i = 0; i < length; i++) {
        this->append(values[i]);
    }
}

LinkedList::~LinkedList() {
    while (!this->isEmpty()) {
        this->remove(0);
    }
}

void LinkedList::prepend(int data) {
    if (this->isEmpty()) {
        this->append(data);
        return;
    }

    this->head = this->createNode(data, this->head);
}

void LinkedList::append(int data) {
    if (this->isEmpty()) {
        this->head = this->tail = this->createNode(data);
        return;
    }

    this->tail->next = this->createNode(data);
    this->tail = this->tail->next;
}

void LinkedList::insert(int data, int index) {
    if (index == 0) {
        this->prepend(data);
        return;
    }

    Node* before = this->get(index - 1);
    before->next = this->createNode(data, before->next);
}

void LinkedList::remove(int index) {
    Node* toDelete;

    if (index == 0) {
        toDelete = this->head;
        this->head = this->head->next;
    } else {
        Node* before = this->get(index - 1);
        toDelete = before->next;
        before->next = toDelete->next;
    }

    this->size--;
    delete toDelete;
}

bool LinkedList::contains(int value) const {
    Node* head = this->head;

    while (head) {
        if (head->data == value) {
            return true;
        }

        head = head->next;
    }

    return false;
}

unsigned LinkedList::length() const {
    return this->size;
}

bool LinkedList::isEmpty() const {
    return this->head == nullptr;
}

std::string LinkedList::print() const {
    std::ostringstream stream;
    Node* head = this->head;

    while (head) {
        stream << head->data << " ";
        head = head->next;
    }

    return stream.str();
}

Node* LinkedList::createNode(int data, Node* next) {
    this->size++;
    return new Node(data, next);
}

Node* LinkedList::get(int index) const {
    Node* head = this->head;

    while (head && index--) {
        head = head->next;
    }

    return head;
}

int LinkedList::at(int index) const {
    return this->get(index)->data;
}

bool LinkedList::operator==(const LinkedList& other) const {
    Node* head = this->head;
    Node* otherHead = other.head;

    if (this->length() != other.length()) {
        return false;
    }

    while (head && otherHead && head->data == otherHead->data) {
        otherHead = otherHead->next;
        head = head->next;
    }

    return head == nullptr && otherHead == nullptr;
}
