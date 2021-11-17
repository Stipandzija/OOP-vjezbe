#include "vector.hpp"
#include <iostream>
using namespace std;
MyVector MyVector::vector_new (size_t sz)
{
    MyVector m;
    m.arr = new int[sz];
    m.capacity = sz;
    m.size = sz;
    return m;
}
void MyVector::vector_delete()
{
    delete[] arr;
}
void MyVector::vector_push_back(int n)
{
    if (size == capacity)
    {
        capacity *= 2;
        int* arr_novi = new int[capacity];
        for (int i = 0;i < (capacity - 1);i++)
        {
            arr_novi[i] = arr[i];
        }
        delete[] arr;
        arr = arr_novi;
    }
    arr[size]=n;
    size++;
}
int& MyVector::vector_front()
{
    return arr[(size+1)-size];
}
int& MyVector::vector_back()
{
    return arr[size - 1];
}
void MyVector::vector_pop_back()
{
    size -= 1;
}
size_t MyVector::vector_size() 
{
    return size;
}


void MyVector::print_vector()
{
    for (size_t i = (size+1)-size; i < vector_size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}