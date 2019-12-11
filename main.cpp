#include<iostream>
#include"header.h"
int main() {
    List* first = new List;
    EnterList(first);
    cout << endl;
    cout << "1 - Вывести числа в обратном порядке." << endl;
    cout << "2 - Показать номера максимальных элемента." << endl;
    cout << "3 - Вывести числа в порядке возрастания." << endl;
    cout << "4 - Записать последовательность в файл." << endl;
    cout << "5 - Завершить роботу программы." << endl;
        while (true){
            int choise;
            cout << "Что вы хотите сделать?" << endl;
            cin >> choise;
            switch (choise) {
                case 1:
                    cout << "В обратном порядке:"<< endl;
                    ReverseList(first);
                    cout<<endl;
                    break;
                case 2:
                    cout << "Номера максимальных элемента:"<< endl;
                    MaxIndex(first);
                    cout<<endl;
                    break;
                case 3:
                    cout << "Числа в порядке возрастания:"<< endl;
                    first = SortList(first);
                    OpenList(first);
                    cout<<endl;
                    break;
                case 4:
                    cout << "Записано в output.txt."<< endl;
                    InFile(first);
                    break;
                case 5:
                    cout << "Робота окончена!"<< endl;
                    return 0;
                case 6:
                    cout << "Минимальное значение элемента списка."<< endl;
                    Min(first);
                    break;
                case 7:
                    cout << "Миаксимальное значение элемента списка."<< endl;
                    Max(first);
                    break;
                default:
                    cout << "Я не владею такой функцией. Введите от 1 до 5!" << endl;
            }
        }
}