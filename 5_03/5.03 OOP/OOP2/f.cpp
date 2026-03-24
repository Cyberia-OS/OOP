#include <iostream>
#include <algorithm>

using namespace std;

class IntArray {
private:
    int* data;
    size_t size;

public:
    //конструктор по умолчанию: создаёт пустой массив
    IntArray() : data(nullptr), size(0) {
        cout << "default constructor (empty)\n";
    }

    //конструктор от размера: выделяет память и заполняет нулями
    explicit IntArray(size_t n) : size(n), data(new int[n]) {
        fill(data, data + size, 0);
        cout << "constructor with size " << n << '\n';
    }

    //конструктор копирования: глубокое копирование
    IntArray(const IntArray& other) : size(other.size), data(new int[other.size]) {
        copy(other.data, other.data + size, data);
        cout << "copy constructor\n";
    }

    //конструктор перемещения: передача владения ресурсом, обнуление источника
    IntArray(IntArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "move constructor\n";
    }

    //деструктор: освобождает память
    ~IntArray() {
        delete[] data;
        cout << "destructor\n";
    }

    //оператор присваивания копированием
    IntArray& operator=(const IntArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            copy(other.data, other.data + size, data);
            cout << "copy assignment\n";
        }
        else {
            cout << "copy assignment (self-assignment)\n";
        }
        return *this;
    }

    //оператор присваивания перемещением
    IntArray& operator=(IntArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            cout << "move assignment\n";
        }
        else {
            cout << "move assignment (self-assignment)\n";
        }
        return *this;
    }

    //метод для вывода элементов массива 
    void print() const {
        cout << "[";
        for (size_t i = 0; i < size; ++i) {
            if (i > 0) cout << ", ";
            cout << data[i];
        }
        cout << "]\n";
    }
};

int main() {
    setlocale(LC_ALL, "RU"); 
    cout << "1. создание объектов\n";
    IntArray a; // default
    IntArray b(5); //конструктор от размера
    IntArray c(b); //copy constructor

    cout << "\n2. перемещение из временного объекта\n";
    IntArray d = IntArray(3);  

    cout << "\n3. явное перемещение с std::move\n";
    IntArray e = move(c);     

    cout << "\n4. присваивание копированием\n";
    IntArray f;
    f = a;                  

    cout << "\n5. присваивание перемещением\n";
    IntArray g;
    g = move(b);           

    cout << "\n6. состояние объектов после перемещения\n";
    cout << "c (источник после move): ";
    c.print();                
    cout << "b (источник после move): ";
    b.print();              

    cout << "\n7. завершение программы (деструкторы)\n";
    return 0;
}