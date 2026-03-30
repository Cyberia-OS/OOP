#pragma once
#include <iostream>
using namespace std;

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* head;
    size_t listSize;

    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

public:
    SinglyLinkedList() : head(nullptr), listSize(0) {}
    ~SinglyLinkedList() { clear(); }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        listSize++;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
        listSize++;
    }

    void pop_front() {
        if (!head) {
            cout << "Ошибка: список пуст, удаление невозможно" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        listSize--;
    }

    void pop_back() {
        if (!head) {
            cout << "Ошибка: список пуст, удаление невозможно" << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
        }
        else {
            Node* cur = head;
            while (cur->next->next) cur = cur->next;
            delete cur->next;
            cur->next = nullptr;
        }
        listSize--;
    }

    T& front() {
        if (!head) {
            cout << "Ошибка: список пуст." << endl;
            exit(1);
        }
        return head->data;
    }

    T& back() {
        if (!head) {
            cout << "Ошибка: список пуст." << endl;
            exit(1);
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        return cur->data;
    }

    bool empty() const { return head == nullptr; }
    size_t size() const { return listSize; }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        listSize = 0;
    }
};

template <typename T>
class Stack {
private:
    T* data;
    size_t capacity;
    size_t topIdx;

    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < topIdx; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    Stack(size_t initCapacity = 10) : capacity(initCapacity), topIdx(0) {
        data = new T[capacity];
    }
    ~Stack() { delete[] data; }

    void push(const T& value) {
        if (topIdx == capacity) resize();
        data[topIdx++] = value;
    }

    void pop() {
        if (empty()) {
            cout << "Ошибка: стек пуст, удаление невозможно." << endl;
            return;
        }
        topIdx--;
    }

    T& top() {
        if (empty()) {
            cout << "Ошибка: стек пуст." << endl;
            exit(1);
        }
        return data[topIdx - 1];
    }

    bool empty() const { return topIdx == 0; }
    size_t size() const { return topIdx; }
};

template <typename T>
class Queue {
private:
    T* data;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t count;

    void resize() {
        size_t newCap = capacity * 2;
        T* newData = new T[newCap];
        for (size_t i = 0; i < count; i++) {
            newData[i] = data[(head + i) % capacity];
        }
        delete[] data;
        data = newData;
        head = 0;
        tail = count;
        capacity = newCap;
    }

public:
    Queue(size_t initCapacity = 10) : capacity(initCapacity), head(0), tail(0), count(0) {
        data = new T[capacity];
    }
    ~Queue() { delete[] data; }

    void enqueue(const T& value) {
        if (count == capacity) resize();
        data[tail] = value;
        tail = (tail + 1) % capacity;
        count++;
    }

    void dequeue() {
        if (empty()) {
            cout << "Ошибка: очередь пуста, удаление невозможно." << endl;
            return;
        }
        head = (head + 1) % capacity;
        count--;
    }

    T& front() {
        if (empty()) {
            cout << "Ошибка: очередь пуста." << endl;
            exit(1);
        }
        return data[head];
    }

    bool empty() const { return count == 0; }
    size_t size() const { return count; }
};