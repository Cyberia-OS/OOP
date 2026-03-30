#include "namespaces.h"

namespace {
    int counter = 0;
    void normalize(double& value) {
        if (value < 0.0) value = 0.0;
        if (value > 1.0) value = 1.0;
        counter++;
    }
}

namespace Utils {
    double clamp(double val, double min, double max) {
        double norm = val;
        normalize(norm);
        return min + norm * (max - min);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int task;
    cout << "выберите задание:" << endl;
    cout << "1 - геометрические фигуры" << endl;
    cout << "2 - логирование" << endl;
    cout << "3 - анонимное пространство имён" << endl;
    cout << "0 - выход" << endl;
    cout << "> ";
    cin >> task;

    if (task == 1) {
        cout << "\nгеометрические фигуры" << endl;
        double radius, width, height;
        cout << "введите радиус круга: ";
        cin >> radius;
        cout << "площадь круга (полная квалификация): " << Geometry::circleArea(radius) << endl;

        using Geometry::rectangleArea;
        cout << "введите ширину и высоту прямоугольника: ";
        cin >> width >> height;
        cout << "площадь прямоугольника (using-объявление): " << rectangleArea(width, height) << endl;

        {
            using namespace Geometry::Shapes;
            cout << "введите радиус для круга (класс): ";
            cin >> radius;
            Circle c(radius);
            cout << "площадь круга через класс (using namespace): " << c.area() << endl;
        }
    }
    else if (task == 2) {
        cout << "\nлогирование" << endl;
        using namespace Logger;
        string msg;
        cout << "введите сообщение для INFO: ";
        cin.ignore();
        getline(cin, msg);
        log(INFO, msg);
        cout << "введите сообщение для WARNING: ";
        getline(cin, msg);
        log(WARNING, msg);
        cout << "введите сообщение для ERROR: ";
        getline(cin, msg);
        log(ERROR, msg);
        cout << "введите имя файла: ";
        string fname;
        getline(cin, fname);
        cout << "введите сообщение для записи в файл: ";
        getline(cin, msg);
        FileLogger::logToFile(fname, msg);
    }
    else if (task == 3) {
        cout << "\nанонимное пространство имён" << endl;
        double val, minv, maxv;
        cout << "введите значение, min, max: ";
        cin >> val >> minv >> maxv;
        double result = Utils::clamp(val, minv, maxv);
        cout << "clamp(" << val << ", " << minv << ", " << maxv << ") = " << result << endl;
        cout << "(функция normalize и переменная counter находятся в анонимном пространстве\n"
            << "и недоступны из main, но Utils::clamp их использует. counter увеличен на 1.)" << endl;
    }
    else if (task != 0) {
        cout << "неверный выбор." << endl;
    }
    return 0;
}