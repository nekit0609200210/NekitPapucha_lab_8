//
// Created by macbook on 12/7/19.
//

#ifndef UNTITLED1_HEADER_H
#define UNTITLED1_HEADER_H
#endif //UNTITLED1_HEADER_H
#include<fstream>
using namespace std;
typedef int TE;
struct List{
    TE value;    //значение
    TE number;   //номер элемента
    List* next;  //указатель на следующий элемент
};

int EnterList(List* first);    //
int OpenList(List* first);
int ReverseList(List* first);
int SizeList(List* first);
int MaxX(List* first);
int MaxIndex(List* first);
List* SortList(List* first);
int InFile(List* first);
int Max(List* first);
int Min(List* first);
