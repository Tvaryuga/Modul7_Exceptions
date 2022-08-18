#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H
#include <exception>
#include <iostream>

using std::exception;

class bad_length : public exception
{
public:
    virtual const char* what() const noexcept override;
};
class bad_range : public exception
{
public:
    virtual const char* what() const noexcept override;
};

class IntegerArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntegerArray() = default;
    IntegerArray(int length);
    IntegerArray(IntegerArray& copy);
    ~IntegerArray();
    void erase();
    int& operator[](int index);
    void resize(int newLength);
    void findElement(const int index) const;                      // поиск элемента по индексу
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    int getLength() const;
    void copyContainerTo(IntegerArray& to);                       // Вызывающий объект копируется в контейнер переданный в параметре
    friend std::ostream& operator<<(std::ostream& os, IntegerArray& container);
};

#endif