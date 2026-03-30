#include "simple_containers.h"
#include <string>

using namespace std;

void demoList() {
    SinglyLinkedList<int> list;
    int choice, value;
    cout << endl << "список" << endl;
    cout << "1 - добавить в начало, 2 - добавить в конец, 3 - удалить первый," << endl;
    cout << "4 - удалить последний, 5 - показать первый/последний, 6 - очистить," << endl;
    cout << "7 - показать размер, 0 - выход" << endl;
    do {
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введите число: ";
            cin >> value;
            list.push_front(value);
            break;
        case 2:
            cout << "Введите число: ";
            cin >> value;
            list.push_back(value);
            break;
        case 3:
            list.pop_front();
            break;
        case 4:
            list.pop_back();
            break;
        case 5:
            if (!list.empty())
                cout << "Первый: " << list.front() << ", последний: " << list.back() << endl;
            else
                cout << "Список пуст." << endl;
            break;
        case 6:
            list.clear();
            cout << "Список очищен." << endl;
            break;
        case 7:
            cout << "Размер: " << list.size() << endl;
            break;
        }
    } while (choice != 0);
}

void demoStack() {
    string word;
    cout << endl << "Стек: проверка палиндрома" << endl;
    cout << "Введите слово: ";
    cin >> word;
    Stack<char> st;
    for (char c : word) st.push(c);
    bool isPalindrome = true;
    for (char c : word) {
        if (c != st.top()) {
            isPalindrome = false;
            break;
        }
        st.pop();
    }
    cout << "Слово \"" << word << "\" " << (isPalindrome ? "" : "НЕ ") << "является палиндромом." << endl;
}

void demoQueue() {
    Queue<int> q;
    int choice, value;
    cout << "1 - добавить задачу, 2 - обработать задачу, 3 - показать текущую задачу," << endl;
    cout << "4 - показать размер очереди, 0 - выход" << endl;
    do {
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введите номер задачи: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            if (!q.empty()) {
                cout << "Обработана задача " << q.front() << endl;
                q.dequeue();
            }
            else {
                cout << "Очередь пуста, нечего обрабатывать." << endl;
            }
            break;
        case 3:
            if (!q.empty())
                cout << "Текущая задача: " << q.front() << endl;
            else
                cout << "Очередь пуста." << endl;
            break;
        case 4:
            cout << "Задач в очереди: " << q.size() << endl;
            break;
        }
    } while (choice != 0);
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Выберите, что хотите протестировать:" << endl;
    cout << "1 - Односвязный список" << endl;
    cout << "2 - Стек (палиндром)" << endl;
    cout << "3 - Очередь (задачи)" << endl;
    cout << "0 - Выход" << endl;
    int mode;
    cin >> mode;
    switch (mode) {
    case 1: demoList(); break;
    case 2: demoStack(); break;
    case 3: demoQueue(); break;
    default: cout << "До свидания." << endl;
    }
    return 0;
}