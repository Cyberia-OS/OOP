#include <iostream>
#include <thread>
#include <memory>
#include <chrono>
#include <string>

using namespace std;

class Timer {
private:
    chrono::steady_clock::time_point started;
    string label;

public:
    Timer(const string& name = "Timer")
        : label(name), started(chrono::steady_clock::now())
    {
        cout << label << " создан" << endl;
    }

    ~Timer() {
        auto ended = chrono::steady_clock::now();
        auto ms = chrono::duration_cast<chrono::milliseconds>(ended - started).count();
        cout << label << " уничтожен" << endl;
        cout << "Прошло: " << ms << " мс" << endl;
    }
};

unique_ptr<Timer> createTimer(const string& id = "Timer") {
    return make_unique<Timer>(id);
}

void demoInFunction() {
    cout << "\n--- Таймер внутри функции ---" << endl;
    auto local = createTimer("Функциональный");
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Выполнение работы..." << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    cout << "Тест 1: блок видимости" << endl;
    {
        auto first = createTimer("A");
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    cout << "\nТест 2: вызов функции" << endl;
    demoInFunction();

    cout << "\nТест 3: перемещение unique_ptr" << endl;
    {
        auto second = createTimer("B");
        auto third = move(second);

        if (!second) cout << "second пуст" << endl;
        if (third) cout << "third владеет" << endl;

        this_thread::sleep_for(chrono::milliseconds(75));
    }

    cout << "\nТест 4: массив таймеров" << endl;
    {
        unique_ptr<Timer> timers[3];
        for (int i = 0; i < 3; ++i) {
            timers[i] = createTimer("Timer" + to_string(i));
        }
        this_thread::sleep_for(chrono::milliseconds(30));
    }

    cout << "\nПрограмма завершена" << endl;
    return 0;
}
