#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "ThreadingTools.h"

using namespace std;

// Длинная операция (3 секунды)
void longRunning() {
    cout << "  -> Долгий процесс начат" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "  <- Долгий процесс окончен" << endl;
}

// Средняя операция (1 секунда)
void mediumTask() {
    cout << "  -> Средний процесс начат" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "  <- Средний процесс окончен" << endl;
}

// Короткая операция (0.3 секунды)
void shortTask() {
    cout << "  -> Быстрый процесс начат" << endl;
    this_thread::sleep_for(chrono::milliseconds(300));
    cout << "  <- Быстрый процесс окончен" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    // Задание 2.1
    cout << "ТЕСТИРОВАНИЕ ОБЁРТКИ ПОТОКА" << endl;

    // Блок 1: три потока разной длительности
    {
        cout << "\n>> Запуск трёх параллельных задач" << endl;
        ThreadGuard g1(longRunning);
        ThreadGuard g2(mediumTask);
        ThreadGuard g3(shortTask);
        cout << "Все три потока активны" << endl;
        // здесь деструкторы вызовут join
    }
    cout << "\n>> Все потоки из блока 1 завершены\n" << endl;

    // Блок 2: лямбда, выводящая квадраты чисел
    {
        cout << ">> Запуск лямбды с вычислениями" << endl;
        ThreadGuard lambdaGuard([]() {
            for (int i = 1; i <= 4; ++i) {
                cout << "    Квадрат " << i << " = " << (i * i) << endl;
                this_thread::sleep_for(chrono::milliseconds(150));
            }
        });
    }
    cout << ">> Лямбда-поток завершён\n" << endl;

    cout << "ТЕСТИРОВАНИЕ ПОТОКОБЕЗОПАСНОГО СЧЁТЧИКА" << endl;

    // Тест 1: 20 потоков, каждый делает 5000 инкрементов и 5000 декрементов
    {
        AtomicCounter shared(100);   // начальное значение 100
        const int THREADS = 20;
        const int STEPS = 5000;
        vector<thread> workers;

        for (int i = 0; i < THREADS; ++i) {
            workers.emplace_back([&shared, STEPS]() {
                for (int j = 0; j < STEPS; ++j) {
                    shared.increment();
                    shared.decrement();
                }
            });
        }
        for (auto& t : workers) t.join();

        cout << "\nРезультат теста 1 (старт 100): " << shared.get()
             << " (ожидалось 100, если нет гонок)" << endl;
    }

    // Тест 2: два потока с неравным числом операций
    {
        AtomicCounter counter(0);
        vector<thread> workers;

        // Поток A: 7 инкрементов, 2 декремента
        workers.emplace_back([&counter]() {
            for (int i = 0; i < 7; ++i) counter.increment();
            for (int i = 0; i < 2; ++i) counter.decrement();
        });
        // Поток B: 3 инкремента, 8 декрементов
        workers.emplace_back([&counter]() {
            for (int i = 0; i < 3; ++i) counter.increment();
            for (int i = 0; i < 8; ++i) counter.decrement();
        });

        for (auto& t : workers) t.join();

        int totalInc = 7 + 3;
        int totalDec = 2 + 8;
        int expected = totalInc - totalDec; 
        cout << "\nРезультат теста 2: " << counter.get()
             << " (инкрементов " << totalInc << ", декрементов " << totalDec
             << ", ожидалось " << expected << ")" << endl;
    }

    //Тест 3: один поток делает много операций, другой – только инкременты
    {
        AtomicCounter c(50);
        vector<thread> workers;

        workers.emplace_back([&c]() {
            for (int i = 0; i < 1000; ++i) c.increment();
        });
        workers.emplace_back([&c]() {
            for (int i = 0; i < 500; ++i) c.decrement();
            for (int i = 0; i < 500; ++i) c.increment(); 
        });

        for (auto& t : workers) t.join();

        cout << "\nРезультат теста 3 (старт 50 + 1000 инкр. - 500 декр. + 500 инкр. = 1050): "
             << c.get() << endl;
    }

    cout << "\nТесты пройдены" << endl;
    return 0;
}
