//
// Created by macbook on 12/7/19.
//      1 2 444 3 2 6 6 456 0
#include<iostream>
#include"header.h"
int EnterList(List* first) {     //ввод
    List* f = first;		    //создание указателя на первый элемент списка
    TE x;
    int i = 1;
    cout << "Введите целые числа!" << endl;
    cin >> x;
    f->value = x;			//присваивание значения элемента переменной value списка
    f->number = i;
    i++;
    while (x != 0) {
        cin >> x;				//ввод элемента
        if (x != 0) {
            f->next = new List;   //создание указателя на следующий элемент
            f = f->next;		    //присваивание указателя на следующий элемент
            f->value = x;	    //присваивание значения элемента переменной value списка
            f->number = i;		    //индексация элементов
            i++;
        }
    }
    f->next = NULL;					//обнуление последнего элемента
    cout << "Ваш список:" << endl;
    OpenList(first);
}


int OpenList(List* first) {	//вывод элементов списка в консоль
    List* f = first;				//создание (внутри функции) указателя на первый элемент списка
    while (f) {
        cout << f->value << " ";	//вывод значения текущего элемента
        f = f->next;				//присваивание указателя на следующий элемент
    }
}


int ReverseList(List* first){
    List* f = NULL;				 //создание (внутри функции) указателя элемент списка
    int size = SizeList(first);  //создание переменной со значением последнего индекса
    while (size > 0)
    {
        f = first;					 //присваивание указателя на первый элемент списка
        for (int i = 1; i < size; i++) {
            f = f->next;
        }
        cout << f->value << " ";	 //вывод последнего элемента списка
        size--;				 //уменьшение количества итераций при переходе по элементам списка
    }
}

int SizeList(List* first)
{
    int size = 0;
    while (first) {
        size++;
        first = first->next;
    }
    return size;
}

int MaxX(List* first){
    List* f = first;			//создание (внутри функции) указателя на первый элемент списка
    int max = 0;				//инициализация переменной, которая будет содержать максимальное значение
    while (f) {
        if ((f->value) > max) { //нахождение максимального элемента списка
            max = f->value;
        }
        f = f->next;			//присваивание указателя на следующий элемент
    }
    return max;
}

int MaxIndex(List* first) {
    List* f = first;				  //создание (внутри функции) указателя на первый элемент списка
    int max = MaxX(first);		  //присваивание переменной максимального значения
    while (f) {
        if ((f->value) == max) {
            cout << f->number << " "; //вывод индексов наибольших членов последовательности
        }
        f = f->next;				  //присваивание указателя на следующий элемент
    }
}
List* SortList(List* first) {
    List *f = first;
    int size = SizeList(first);
    List **adress = new List*[size];   //массив адресов
    TE *value = new TE[size];      //массив значений элементов
    for(int i = 0;f != NULL;i++){    //запихиваем список в массивы
        value[i] = f->value;
        adress[i] = f;
        f = f->next;
    }
    TE temp;    //"буфер обмена"
    List* tempA;      //"буфер обмена для Адрессов"
    for (int i = 0; i < size - 1; i++) {    //сортирование пузырьков
        for (int j = 0; j < size - i - 1; j++) {
            if (value[j] > value[j + 1]) {
                temp = value[j];
                tempA = adress[j];
                value[j] = value[j + 1];
                adress[j] = adress[j + 1];
                value[j + 1] = temp;
                adress[j + 1] = tempA;
            }
        }
    }
    first = adress[0];
    f = first;
    for(int i = 0;i < size - 1;i++){      //зписть элементов масиива в список
        f->next = adress[i + 1];
        f = f->next;
    }
    f->next = NULL;
    delete[] adress;      //удаление
    delete[] value;
    return first;

}

int InFile(List* first) {
    List* f = first;
    ofstream output("output.txt");
    if (output){
        while (f != NULL){
            output << f->value << "  ";
            f = f->next;
        }
        output.close();
    }
}

int Max(List* first){
    List* f = first;
    int max = f->value;
    while (f) {
        if ((f->value) > max) {
            max = f->value;
        }
        f = f->next;
    }
    cout<< max<< endl;
}

int Min(List* first){
    List* f = first;
    int min;
    while (f) {
        if ((f->value) < min) {
            min = f->value;
        }
        f = f->next;
    }
    cout<< min << endl;
}