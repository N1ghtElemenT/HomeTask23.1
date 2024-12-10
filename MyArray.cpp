#include <iostream>
#include "MyArray.h"
using namespace std;

MyArray::MyArray()
{
    this->size = 0;
    this->arr = nullptr;
}

MyArray::MyArray(unsigned int size)
{
    this->size = size;
    if (size > 0)
    {
        this->arr = new int[size];
    }
    else
    {
        this->arr = nullptr;
    }
}

MyArray::MyArray(unsigned int size, int* arr)
{
    this->size = size;
    if (size > 0)
    {
        this->arr = new int[size];
        for (unsigned int i = 0; i < size; i++)
        {
            this->arr[i] = arr[i];
        }
    }
    else
    {
        this->arr = nullptr;
    }
}

void MyArray::printArray() const
{
    if (arr != nullptr)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void MyArray::setSize(unsigned int newSize)
{
    delete[] arr;
    size = newSize;
    arr = new int[size];
}

unsigned int MyArray::getSize() const
{
    return size;
}

void MyArray::sortArray()
{
    for (unsigned int i = 0; i < size - 1; i++)
    {
        for (unsigned int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int MyArray::findMin() const
{
    if (size == 0) throw "Array is empty!";
    int minValue = arr[0];
    for (unsigned int i = 1; i < size; i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
        }
    }
    return minValue;
}

int MyArray::findMax() const
{
    if (size == 0) throw "Array is empty!";
    int maxValue = arr[0];
    for (unsigned int i = 1; i < size; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int& MyArray::operator[](unsigned int index)
{
    if (index >= size) throw "Index out of bounds!";
    return arr[index];
}

MyArray::MyArray(const MyArray& obj)
{
    size = obj.size;
    arr = new int[size];
    for (unsigned int i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
}

MyArray::~MyArray()
{
    delete[] arr;
}