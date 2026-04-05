#include "convert.h"

void checkAndDraw(Shape* s) {
    if (Circle* c = dynamic_cast<Circle*>(s)) {
        cout << "[ИНФО] Это круг! ";
        c->draw();
        return;
    }
    if (Rectangle* r = dynamic_cast<Rectangle*>(s)) {
        cout << "[ИНФО] Это прямоугольник! ";
        r->draw();
        return;
    }
    cout << " Неизвестный тип фигуры" << endl;
}

void demoDynamicCast() {
    cout << "\nЗадание 1.1: dynamic_cast\n";
    Shape* figures[] = {
        new Circle(2.5),
        new Rectangle(3.0, 4.0),
        new Circle(1.8),
        new Rectangle(5.0, 2.0)
    };
    for (auto fig : figures) checkAndDraw(fig);
    for (auto fig : figures) delete fig;
}

void unsafeButLegal(const DataHolder& holder) {
    DataHolder& mutableHolder = const_cast<DataHolder&>(holder);
    vector<int>& vec = const_cast<vector<int>&>(holder.getData());
    if (!vec.empty()) {
        vec[0] = 777;
        cout << "[ИЗМЕНЕНИЕ] Первый элемент установлен в 777" << endl;
    }
}

void demoConstCast() {
    cout << "\nЗадание 1.2: const_cast\n";
    vector<int> init = {1, 2, 3, 4, 5};
    DataHolder obj(init);
    cout << "До изменения: ";
    obj.print();
    unsafeButLegal(obj);
    cout << "После изменения: ";
    obj.print();
}

int main() {
    setlocale(LC_ALL, "ru");
    demoDynamicCast();
    demoConstCast();
    return 0;
}
