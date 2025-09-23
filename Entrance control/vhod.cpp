#include <iostream>

using namespace std;

struct Parallelogram {
    double a;
    double b;
    double alpha;
};

int main () {
    int k;

    cout << "Введите число фигур (k): ";
    cin >> k;

    Parallelogram figs[100];

    for (int i = 0; i < k; i++) {
        cout << "Фигура" << i + 1 << "Введите длину(a), ширину(b) и угол между ними(alpha): ";
        if (!(cin >> figs[i].a >> figs[i].b >> figs[i].alpha)) {
            cout << "Ошибка: введи три числа через пробел" << endl;
            return 1;
        }

    }

    int k1 = 0;
    int k2 = 0;

    for(int i = 0; i < k; i++) {
        if (figs[i].a == figs[i].b && figs[i].alpha == 90.0) {
            k1++;
        }

        if (figs[i].a != figs[i].b && figs[i].alpha == 90.0) {
            k2++;
        }
    }

    cout << "Количество квадратов(k1): " << k1 << endl;
    cout << "Количество параллелограмов(k2): " << k2 << endl;

    return 0;

}

