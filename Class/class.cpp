#include <iostream>
#include <string>

using namespace std;

class CD {
    private:
    string Man;
    int IPD;

public:

    CD(string M = "", int I = 0) {
        Man = M;
        IPD = I;
    }

    void inputTO() {
        cout<<"Введите производителя: ";
        cin.ignore(1, '\n');
        getline(cin, Man);
        cout<<"Введите время задержки: ";
        cin>>IPD;
    }

    void outputTO() {

        cout<<"\nПроизводитель: \n"<<Man<<endl;
        cout<<"\nЗадержка обработки данных: \n"<<IPD<<endl; 

    }

    string get_MAN() {
        return Man;
    }
    void set_MAN(string M) {
        Man = M;
    }

    int get_IPD() {
        return IPD;
    }

    void set_IPD(double I) {
        IPD = I;
    }

};

int main () {
    
    CD Eltex;
    CD *Yadro = new CD;

    cout<<"Данные первого производителя: \n";
    Eltex.inputTO();

    cout<<"\nДанные второго производителя: \n";
    Yadro->inputTO();

    Yadro->outputTO();
    Eltex.outputTO();

    Yadro->set_IPD(Yadro->get_IPD() + 50);
    Eltex.set_IPD(100);

    cout<<"Время задержки первого: "<< Yadro->get_IPD()<<"\n";
    cout<<"Время задержки второго: "<< Eltex.get_IPD()<<"\n";

    Yadro->inputTO();
    Eltex.outputTO();

    delete Yadro;
    return 0;
}

