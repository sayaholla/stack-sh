#include <iostream>
#include "stack.h"


using namespace std;

int main()
{
    Stack <int> A;
    int a = 5;
    A.Push(a);
    A.Push(10);
    cout << "size stack = " <<A.Size() << endl;// выводи размерность стека
    // проверяем работу извлечения обьекта из стека и работу исключения
    cout << "pop stack: " <<  A.Pop() << " " << A.Pop() << " " << A.Pop() << endl;

    A.Clear();

return 0;
}
