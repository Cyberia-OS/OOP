#include <iostream>
#include <utility>  // для move
using namespace std;

class Buffer {
private:
    char* data;
    size_t capacity;

public:
    //конструктор от размера
    Buffer(size_t cap) : capacity(cap), data(new char[cap]) {
        cout << "Buffer(size_t) – created buffer of size " << cap << "\n";
    }

    //деструктор
    ~Buffer() {
        cout << "~Buffer() – destroying buffer of size " << capacity << "\n";
        delete[] data;
    }

    //конструктор копирования
    Buffer(const Buffer& other) : capacity(other.capacity), data(new char[other.capacity]) {
        for (size_t i = 0; i < capacity; ++i)
            data[i] = other.data[i];
        cout << "Buffer(const Buffer&) – COPY of size " << capacity << "\n";
    }

    //конструктор перемещения
    Buffer(Buffer&& other) noexcept : data(other.data), capacity(other.capacity) {
        other.data = nullptr;
        other.capacity = 0;
        cout << "Buffer(Buffer&&) – MOVE of size " << capacity << "\n";
    }

    //оператор присваивания копированием (без swap, простой вариант)
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            data = new char[capacity];
            for (size_t i = 0; i < capacity; ++i)
                data[i] = other.data[i];
            cout << "operator=(const Buffer&) – COPY ASSIGNMENT\n";
        }
        return *this;
    }

    //оператор присваивания перемещением
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            capacity = other.capacity;
            other.data = nullptr;
            other.capacity = 0;
            cout << "operator=(Buffer&&) – MOVE ASSIGNMENT\n";
        }
        return *this;
    }
};

//функция возвращающая буфер
Buffer createBuffer(size_t n) {
    Buffer buf(n);
    return buf;
}

int main() {
    setlocale(LC_ALL, "RU");

    cout << "1. Создание b1\n";
    Buffer b1(100);

    cout << "\n2. Перемещение b1 в b2\n";
    Buffer b2 = move(b1);

    cout << "\n3. Создание b3 через createBuffer()\n";
    Buffer b3 = createBuffer(50);

    cout << "\n4. Перемещающее присваивание b3 = move(b2)\n";
    b3 = move(b2);

    cout << "\n5. Завершение (деструкторы)\n";
    return 0;
}
