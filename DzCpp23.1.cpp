#include <iostream>
#include "MyArray.h"
using namespace std;

int main()
{
    unsigned int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    MyArray arr(size);

    cout << "Enter " << size << " elements of the array:" << endl;
    for (unsigned int i = 0; i < size; i++)
    {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }

    bool exitProgram = false;
    MyArray newArr(size);

    while (!exitProgram)
    {
        cout << "\nMenu:\n";
        cout << "1. Print array\n";
        cout << "2. Sort array\n";
        cout << "3. Find minimum value\n";
        cout << "4. Find maximum value\n";
        cout << "5. Change array size\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Array: ";
            arr.printArray();
            break;
        case 2:
            arr.sortArray();
            cout << "Array after sorting: ";
            arr.printArray();
            break;
        case 3:
            try
            {
                cout << "Minimum value: " << arr.findMin() << endl;
            }
            catch (const char* msg)
            {
                cout << msg << endl;
            }
            break;
        case 4:
            try
            {
                cout << "Maximum value: " << arr.findMax() << endl;
            }
            catch (const char* msg)
            {
                cout << msg << endl;
            }
            break;
        case 5:
            cout << "Enter new size of the array: ";
            cin >> size;

            newArr.setSize(size);

            cout << "Enter " << size << " new elements for the array:" << endl;
            for (unsigned int i = 0; i < size; i++)
            {
                cout << "Element " << (i + 1) << ": ";
                cin >> newArr[i];
            }

            arr = newArr;

            cout << "New array after resizing:\n";
            arr.printArray();
            break;
        case 0:
            exitProgram = true;
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}