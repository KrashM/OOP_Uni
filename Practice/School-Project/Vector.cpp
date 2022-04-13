#include "Vector.h"
#include "Converter.h"
#include <cstring>
#include <iostream>
#include <typeinfo>

template <typename T>
void Vector<T>::reset(){

    this -> SIZE = 0;
    this -> CAPACITY = 1;
    this -> V = new T[CAPACITY];

}

template <typename T>
void Vector<T>::resize(){

    if(SIZE < CAPACITY / 2) this -> CAPACITY /= 2;
    else if(SIZE == CAPACITY) this -> CAPACITY *= 2;
    else return;

    T *temp = new T[this -> CAPACITY];
    for(unsigned i = 0; i < this -> SIZE; i++) temp[i] = this -> V[i];
    delete[] this -> V;
    this -> V = temp;

}

template <typename T>
Vector<T>::Vector(){ reset(); }
template <typename T>
Vector<T>::~Vector(){ delete[] this -> V; }

template <typename T>
T &Vector<T>::operator [](const unsigned index){ return *this -> V[index]; }

template <typename T>
const bool Vector<T>::isEmpty() const{ return this -> SIZE == 0; }
template <typename T>
const unsigned Vector<T>::getCapacity() const{ return this -> CAPACITY; }
template <typename T>
const unsigned Vector<T>::getSize() const{ return this -> SIZE; }

template <typename T>
T Vector<T>::getAt(unsigned index) const{

    if(!isEmpty() && index < this -> SIZE) return this -> V[index];
    throw -1;

}

template <typename T>
T Vector<T>::getFirst() const{

    if(!isEmpty()) return this -> V[0];
    throw -1;

}

template <typename T>
T Vector<T>::getLast() const{
    
    if(!isEmpty()) return this -> V[SIZE - 1];
    throw -1;
    
}

template <typename T>
T Vector<T>::popBack(){

    if(isEmpty()) throw -1;
    T result = this -> V[--this -> SIZE];
    this -> resize();

    return result;

}

template <typename T>
T Vector<T>::removeAt(unsigned index){

    if(isEmpty() || index >= SIZE) throw -1;
    --SIZE;
    for(; index < this -> SIZE; index++) this -> V[index] = this -> V[index + 1];
    this -> resize();

}

template <typename T>
void Vector<T>::assign(unsigned size, T element){

    reset();
    for(int i = 0; i < size; i++) this -> pushBack(element);

}

template <typename T>
void Vector<T>::pushBack(T element){

    this -> resize();
    this -> V[this -> SIZE++] = element;

}

template <typename T>
void Vector<T>::insert(unsigned index, T element){

    if(index >= this -> SIZE) throw -1;
    for(unsigned j = this -> SIZE++; j >= index; j--) this -> V[j + 1] = this -> V[j];
    this -> V[index] = element;
    resize();

}

template <typename T>
void Vector<T>::erase(T element){

    unsigned offset = 0;

    for(unsigned i = 0; i < this -> SIZE; i++){

        while(this -> V[i + offset] == element) offset++;
        this -> V[i] = this -> V[i + offset];

    }

    this -> SIZE -= offset;

    this -> resize();

}

template <typename T>
const char *Vector<T>::toString() const{

    char *result = new char[1024];
    result[0] = '\0';

    std::cout << typeid(int).name() << '\n';

    return result;

}