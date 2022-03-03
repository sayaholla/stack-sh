#ifndef STACK_H
#define STACK_H


#include "e_stack_exception.h"
#include "e_stack_empty.h"

template <class T>
class Stack
{
public:
	~Stack(); // деструктор

    void Push(const T &value); // Помещение объекта в стек
    const T Pop(); // Извлечение объекта из стека


    int Size(); // Получение размерности стека
    void Clear(); // Удаление из стека всех узлов

private:
    struct Node // звено (структура для динамического добавления элементов в стек)
	{
        const T value_; // храним константное значение

		Node *prev_ = nullptr; // указатель на предыдущее звено стека
	};

    Node *back_ = nullptr; // последний элемент стека (голова)

    int size_ = 0;
};


// деструктор
template <class T>
Stack<T>::~Stack()
{
	Clear();
}

//Помещение объекта в стек
template <class T>
void Stack<T>::Push(const T &value)
{
	Node *node = new Node{ value, back_ }; // создаем новое звено, предыдущее для которого - последнее на данный момент звено

	if (node == nullptr) // если память под новое звено не выделилась
	{
		throw EStackException("Lack of memory."); // возвращаем исключение, которое говорит о том что память закончилась
	}

    back_ = node; // делаем указатель головы на новое звено

    size_++; // увеличиваем размер стека на 1
}

// Извлечение объекта из стека
template <class T>
const T Stack<T>::Pop()
{
	if (back_ == nullptr) // если стек пуст, возвращаем исключение
	{
        throw EStackEmpty(); //возвращаем исключение
	}

	const T value = back_->value_; // сохраняем значение звена

	Node *tmp = back_; // сохраняем ссылку на звено

    back_ = back_->prev_; // перемещаем указатель стэка на предыдущий элемент
	delete tmp; // удаляем звено

    size_--; // уменьшаем размер стека на 1

	return value; // возвращаем сохраненое значение звена
}

//Получение размерности стека
template <class T>
int Stack<T>::Size()
{
	return size_; // размер стека
}

template <class T>
void Stack<T>::Clear()
{
	while (back_ != nullptr) // пока в стеке есть элементы
	{
		Node *tmp = back_; // сохраняем последний элемент

		back_ = back_->prev_; // делаем последним элементом предпоследний

		delete tmp; // удаляем сохраненный последний элемент
	}
}

#endif // STACK_H
