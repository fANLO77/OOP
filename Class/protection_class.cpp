#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Circle {
private:
    double x0; // Координата центра по X
    double y0; // Координата центра по Y
    double r;  // Радиус

public:
    // Конструктор по умолчанию
    Circle(){
        
    }

    // Конструктор с параметрами
    Circle(double x, double y, double rad) {
        x0 = x;
        y0 = y;
        r = rad;
        if (r < 0) {
            r = 1.0; 
        }
    }
    void inputTO() {
        cout << "Введите координату X центра: ";
        cin >> x0;
        cout << "Введите координату Y центра: ";
        cin >> y0;
        cout << "Введите радиус: ";
        cin >> r;
        if (r < 0) {
            cout << "Радиус не может быть отрицательным! Установлен радиус по умолчанию = 1.0\n";
            r = 1.0;
        }
    }

    double getLength() {
        return 2 * M_PI * r;
    }

    bool intersectsOX() {
        return y0 >= -r && y0 <= r;
    }

    bool intersectsOY() {
        return x0 >= -r && x0 <= r;
    }

    void printInfo() {
        cout << "Центр: (" << x0 << ", " << y0 << "), Радиус: " << r << endl;
        cout << "Длина окружности: " << getLength() << endl;
        cout << "Пересекает OX: " << (intersectsOX() ? "Да" : "Нет") << endl;
        cout << "Пересекает OY: " << (intersectsOY() ? "Да" : "Нет") << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    int T;

    cout << "Введите количество окружностей: ";
    cin >> T;
    if (T <= 0) {
        cout << "Количество окружностей должно быть больше 0. Завершение программы.\n";
        return 1;
    }

    Circle* circles = new Circle[T];

    for (int i = 0; i < T; ++i) {
        cout << "Введите данные для окружности " << (i + 1) << ":\n";
        circles[i].inputTO();
        cout << endl;
    }

    cout << "Информация об окружностях:\n";
    for (int i = 0; i < T; ++i) {
        cout << "Окружность " << (i + 1) << ":\n";
        circles[i].printInfo();
    }

    delete[] circles;

    return 0;
}