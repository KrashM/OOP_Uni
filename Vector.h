#pragma once

#include <cstring>
#include <iostream>
#include <typeinfo>
#include "Converter.h"

template <typename T>
class Vector{

    private:
        T *V;
        unsigned SIZE, CAPACITY;

        void reset();
        void resize();
        void swap(T &A, T &B);
    
    public:
        Vector();
        ~Vector();

        T &operator [](const unsigned index);

        const bool isEmpty() const;
        const bool contains(const T &search) const;
        const unsigned getCapacity() const;
        const unsigned getSize() const;
        const unsigned getIndex(const T &element) const;
        T getAt(unsigned index) const;
        T getFirst() const;
        T getLast() const;
        T popBack();
        T removeAt(unsigned index);
        void assign(unsigned size, T element);
        void pushBack(T element);
        void insert(unsigned index, T element);
        void erase(T element);
        void sort();
        const char *toString() const;

};

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
void Vector<T>::swap(T &A, T &B){

    T temp = A;
    A = B;
    B = temp;

}

template <typename T>
Vector<T>::Vector(){ reset(); }
template <typename T>
Vector<T>::~Vector(){ delete[] this -> V; }

template <typename T>
T &Vector<T>::operator [](const unsigned index){ return this -> V[index]; }

template <typename T>
const bool Vector<T>::isEmpty() const{ return this -> SIZE == 0; }
template <typename T>
const bool Vector<T>::contains(const T &search) const{

    for(size_t i = 0; i < this -> SIZE; i++)
        if(this -> V[i] == search) return true;
    return false;
    
}
template <typename T>
const unsigned Vector<T>::getCapacity() const{ return this -> CAPACITY; }
template <typename T>
const unsigned Vector<T>::getSize() const{ return this -> SIZE; }
template <typename T>
const unsigned Vector<T>::getIndex(const T &element) const{

    for(int i = 0; i < this -> SIZE; i++)
        if(this -> V[i] == element)
            return i;

    return -1;

}

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
    T element = this -> V[index];
    --SIZE;
    for(; index < this -> SIZE; index++) this -> V[index] = this -> V[index + 1];
    this -> resize();
    return element;

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
void Vector<T>::sort(){

    for(int i = 0; i < this -> SIZE - 1; i++)
        for(int j = i + 1; j < this -> SIZE; j++)
            if(this -> V[i] > this -> V[j])
                swap(this -> V[i], this -> V[j]);

}

template <typename T>
const char *Vector<T>::toString() const{

    char *result = new char[1024];
    result[0] = '\0';

    std::cout << typeid(int).name() << '\n';

    return result;

}