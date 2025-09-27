#include <iostream>
#include <cmath>

using namespace std;

// Класс окружность
class Circle {
protected:
    double R;

public:
    // Конструктор
    Circle(double radius = 0) {
        R = radius;
        if (radius < 0) {
            R = 1.0;  // Исправлено: нужно присваивать R, а не radius
        }
    }

    // Поиск площади
    virtual double ploshad() const {
        return M_PI * R * R;
    }

    // Поиск длины окружности
    double lenghtCircle() const {
        return 2 * M_PI * R;
    }

    // Вывод информации
    void printInfoCircles() const {
        cout << "Окружность: радиус = " << R
             << ", Площадь = " << ploshad()
             << ", Длина = " << lenghtCircle() << endl;
    }

    // Геттер
    double getRadius() const {
        return R;
    }
};

class Cylinder : public Circle {
private:
    double h;
public:
    Cylinder(double radius = 0, double height = 0) : Circle(radius), h(height) {
        if (height < 0) {
            h = 1.0;
        }
    }

    double ploshad() const override {
        return 2 * M_PI * R * (R + h);
    }

    double volume() const {
        return M_PI * R * R * h;
    }

    void printInfoCylinders() const {
        cout << "Цилиндр: Радиус = " << R
             << ", Высота = " << h
             << ", Площадь поверхности = " << ploshad()
             << ", Объём = " << volume() << endl;  // Исправлено: добавлены ()
    }

    double getHeight() const {
        return h;
    }
};

// Поиск максимальной окружности
Circle maxPloshadCircle(Circle circles[], int N) {
    if (N == 0) {
        return Circle(0);
    }    
    
    Circle maxCircle = circles[0];
    for (int i = 1; i < N; i++) {
        if (circles[i].ploshad() > maxCircle.ploshad()) {
            maxCircle = circles[i];
        }
    }
    return maxCircle;
}

// средний объём цилиндров
double avgVolumeCylinder(Cylinder cylinders[], int M) {  // Исправлено: возвращаем double
    if (M == 0) {
        return 0;
    }

    double totalVolume = 0;
    for (int i = 0; i < M; i++) {
        totalVolume += cylinders[i].volume();
    }
    return totalVolume / M;
}

int main() {
    int N, M;
    
    cout << "Введите кол-во окружностей: ";
    cin >> N;
    if (N <= 0) {
        cout << "Количество окружностей должно быть больше 0. Завершение программы.\n";
        return 1;
    }

    Circle* circles = new Circle[N];  // Исправлено: динамическое выделение памяти

    for (int i = 0; i < N; ++i) {
        double radius;
        cout << "Введите радиус окружности " << (i + 1) << ": ";  // Исправлено
        cin >> radius;
        circles[i] = Circle(radius);
    }

    cout << "Введите кол-во цилиндров: ";  // Добавлено: запрос количества цилиндров
    cin >> M;
    if (M <= 0) {
        cout << "Количество цилиндров должно быть больше 0. Завершение программы.\n";
        delete[] circles;
        return 1;
    }

    Cylinder* cylinders = new Cylinder[M];  // Исправлено: динамическое выделение памяти

    for (int i = 0; i < M; ++i) {
        double radius, height;  // Исправлено порядок
        cout << "Введите радиус и высоту цилиндра " << (i + 1) << ": ";
        cin >> radius >> height;
        cylinders[i] = Cylinder(radius, height);  // Исправлено порядок
    }

    cout << "ИНФОРМАЦИЯ О ФИГУРАХ \n" << endl;

    cout << "Информация об окружностях:\n";
    for (int i = 0; i < N; ++i) {
        cout << "Окружность " << (i + 1) << ": ";
        circles[i].printInfoCircles();
    }

    cout << "Информация о цилиндрах:\n";  // Исправлено опечатка
    for (int i = 0; i < M; ++i) {  // Исправлено: должно быть M, а не N
        cout << "Цилиндр " << (i + 1) << ": ";
        cylinders[i].printInfoCylinders();
    }

    if (N > 0) {
        Circle maxCircle = maxPloshadCircle(circles, N);
        cout << "\nОкружность с максимальной площадью:\n";  // Исправлено
        maxCircle.printInfoCircles();
    }

    if (M > 0) {
        double avgVolume = avgVolumeCylinder(cylinders, M);  // Исправлено тип
        cout << "\nСредний объём цилиндров: " << avgVolume << endl;  // Исправлено
    }

    delete[] circles;
    delete[] cylinders;

    return 0;
}