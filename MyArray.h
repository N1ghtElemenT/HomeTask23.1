#pragma once
#include <iostream>

class MyArray 
{
private:
    unsigned int size;
    int* arr;

public:
    MyArray();
    explicit MyArray(unsigned int size);
    MyArray(unsigned int size, int* arr);
    void printArray() const;
    void setSize(unsigned int size);
    unsigned int getSize() const;
    void sortArray();
    int findMin() const;
    int findMax() const;
    int& operator[](unsigned int index);
    MyArray(const MyArray& obj);
    ~MyArray();
};

