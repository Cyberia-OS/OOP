#include "transport.h"

int main() {
    setlocale(LC_ALL, "RU");

    cout << "Демонстрация системы транспортных средств и гаражей\n";

    // 1. Точки: создание, сравнение, вывод
    cout << "[1] Работа с точками\n";
    Point a(3, 4);
    Point b(3, 4);
    Point c(0, 0);
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "a == b ? " << (a == b ? "да" : "нет") << endl;
    cout << "a != c ? " << (a != c ? "да" : "нет") << endl;
    cout << "Расстояние a от начала: " << a.distance() << endl;

    // 2. Создание транспортных средств и статический счётчик
    cout << "\n[2] Создание транспорта\n";
    Vehicle* arr[] = {
        new Car("BMW", 2021, Point(10,10), 4),
        new Bike("Trek", 2022, Point(20,20), "mountain"),
        new Car("Tesla", 2023, Point(30,30), 5),
        new Bike("Cannondale", 2020, Point(40,40), "road")
    };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Создано транспортных средств: " << Vehicle::getTotalVehicles() << endl;
    cout << "Всего точек: " << Point::getPointCount() << endl;

    // 3. Гараж с цепочкой add()
    cout << "\n[3] Гараж и цепочка добавления\n";
    Garage<Vehicle*> garage(2);
    garage.add(arr[0]).add(arr[1]).add(arr[2]).add(arr[3]);
    cout << "В гараже объектов: " << garage.getCount() << endl;

    // 4. Полиморфный вывод и максимальная скорость
    cout << "\n[4] Полиморфный вывод\n";
    for (int i = 0; i < garage.getCount(); ++i) {
        garage[i]->print();
        cout << "   --> Макс. скорость: " << garage[i]->getMaxSpeed() << " км/ч\n";
    }

    // 5. Перемещение и оператор ++ для Car
    cout << "\n[5] Перемещение и увеличение дверей\n";
    garage[0]->move(Point(100,100));
    cout << "Первый автомобиль после перемещения: ";
    garage[0]->print();

    Car* pCar = dynamic_cast<Car*>(garage[0]);
    if (pCar) {
        ++(*pCar);
        cout << "После префиксного ++ (увеличение дверей): ";
        pCar->print();
        (*pCar)++;
        cout << "После постфиксного ++: ";
        pCar->print();
    }

    // 6. Глубокое копирование гаража
    cout << "\n[6] Глубокое копирование\n";
    Garage<Vehicle*> garageCopy = garage;
    garage[0]->move(Point(999,999));
    cout << "Оригинал после изменения позиции: "; garage[0]->print();
    cout << "Копия (позиция не изменилась): "; garageCopy[0]->print();

    // 7. Объединение гаражей оператором +
    cout << "\n[7] Объединение гаражей\n";
    Garage<Vehicle*> otherGarage;
    otherGarage.add(new Bike("Specialized", 2024, Point(5,5), "sport"));
    Garage<Vehicle*> combined = garage + otherGarage;
    cout << "Размер объединённого гаража: " << combined.getCount() << endl;
    cout << "Содержимое:\n";
    for (int i = 0; i < combined.getCount(); ++i) combined[i]->print();

    // 8. Обработка исключений при неверном индексе
    cout << "\n[8] Проверка обработки исключений\n";
    try {
        cout << "Попытка доступа к индексу 100: ";
        combined[100]->getModel();
    } catch (const out_of_range& e) {
        cout << "Ошибка перехвачена: " << e.what() << endl;
    }

    cout << "\n[9] Статистика объектов\n";
    cout << "Осталось точек: " << Point::getPointCount() << endl;
    cout << "Осталось транспорта: " << Vehicle::getTotalVehicles() << endl;
    cout << "Всего создано гаражей: " << Garage<Vehicle*>::getTotalGarages() << endl;

    for (int i = 0; i < n; ++i) delete arr[i];

    cout << "\nЗавершение работы.\n";
    return 0;
}
