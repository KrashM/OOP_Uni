#pragma once

#include "Converter.h"
#include <iostream>
#include <typeinfo>
#include <cstring>
#include <ostream>
#include <iterator>

using std::out_of_range;
using std::ostream;
using std::ostream_iterator;
using std::copy;
using std::swap;

template <typename T>
class Vector{

    private:
        T *V;
        size_t SIZE, CAPACITY;
        
        void resize();
    
    public:
        Vector();
        Vector(const Vector<T> &);
        ~Vector();

        T &operator [](const size_t &);
        const T &operator [](const size_t &) const;
        friend ostream &operator <<(ostream &out, const Vector<T> &vec);

        const bool isEmpty() const;
        const bool contains(const T &) const;
        const size_t capacity() const;
        const size_t size() const;
        const size_t getIndex(const T &) const;
        T getAt(const size_t &) const;
        T getFirst() const;
        T getLast() const;
        T popBack();
        T removeAt(size_t &);
        void pushBack(const T &);
        void insert(const size_t &, const T &);
        void erase(const T &);
        void sort();
        const char *toString() const;

};

template <typename T>
void Vector<T>::resize(){

    if(this -> SIZE < this -> CAPACITY / 4) this -> CAPACITY /= 2;
    else if(this -> SIZE == this -> CAPACITY) this -> CAPACITY *= 2;
    else return;

    T *temp = new T[this -> CAPACITY];
    copy(this -> V, this -> V + this -> SIZE, temp);
    delete[] this -> V;
    this -> V = temp;

}

template <typename T>
Vector<T>::Vector(): V(NULL), SIZE(0), CAPACITY(0){ 

    this -> SIZE = 0;
    this -> CAPACITY = 1;
    this -> V = new T[CAPACITY];
    
}


template <typename T>
Vector<T>::Vector(const Vector<T> &other){

    this -> V = new T[other.capacity()];
    copy(&other[0], &other[0] + other.size(), this -> V);
    this -> SIZE = other.size();
    this -> CAPACITY = other.capacity();

}

template <typename T>
Vector<T>::~Vector(){ delete[] this -> V; }

template <typename T>
T &Vector<T>::operator [](const size_t &index){
    
    if(index >= this -> SIZE) throw out_of_range("");
    return this -> V[index];
    
}

template <typename T>
const T &Vector<T>::operator [](const size_t &index) const{
    
    if(index >= this -> SIZE) throw out_of_range("");
    return this -> V[index];
    
}

template<typename T>
ostream &operator <<(ostream &out, const Vector<T> &vec){

    copy(&vec[0], &vec[0] + vec.size(), ostream_iterator<T>(out, " "));
    return out;

}

template <typename T>
const bool Vector<T>::isEmpty() const{ return this -> SIZE == 0; }

template <typename T>
const bool Vector<T>::contains(const T &search) const{

    for(size_t i = 0; i < this -> SIZE; i++)
        if(this -> V[i] == search) return true;
    return false;
    
}

template <typename T>
const size_t Vector<T>::capacity() const{ return this -> CAPACITY; }

template <typename T>
const size_t Vector<T>::size() const{ return this -> SIZE; }

template <typename T>
const size_t Vector<T>::getIndex(const T &element) const{

    for(int i = 0; i < this -> SIZE; i++)
        if(this -> V[i] == element)
            return i;

    return -1;

}

template <typename T>
T Vector<T>::getAt(const size_t &index) const{

    if(index < this -> SIZE) return this -> V[index];
    throw out_of_range("");

}

template <typename T>
T Vector<T>::getFirst() const{

    if(this -> isEmpty()) throw out_of_range("");
    return this -> V[0];

}

template <typename T>
T Vector<T>::getLast() const{
    
    if(isEmpty()) throw out_of_range("");
    return this -> V[SIZE - 1];
    
}

template <typename T>
T Vector<T>::popBack(){

    if(isEmpty()) throw out_of_range("");
    T result = this -> V[--this -> SIZE];
    this -> V[this -> SIZE].~T();
    this -> resize();

    return result;

}

template <typename T>
T Vector<T>::removeAt(size_t &index){

    if(index >= this -> SIZE) throw out_of_range("");
    T element = this -> V[index];
    --this -> SIZE;
    for(; index < this -> SIZE; index++) this -> V[index] = this -> V[index + 1];
    this -> V[this -> SIZE].~T();
    this -> resize();
    return element;

}

template <typename T>
void Vector<T>::pushBack(const T &element){

    std::cout << "Element to add is: " << element.toString() << '\n';
    // Does not recognize it as = operator for class Grade
    this -> V[this -> SIZE++] = element;
    this -> resize();
    std::cout << "Element added is: " << this -> V[this -> SIZE - 1].toString() << '\n';

}

template <typename T>
void Vector<T>::insert(const size_t &index, const T &element){

    if(index >= this -> SIZE) throw out_of_range("");
    for(size_t j = this -> SIZE++; j >= index; j--) this -> V[j + 1] = this -> V[j];
    this -> V[index] = element;
    resize();

}

template <typename T>
void Vector<T>::erase(const T &element){

    size_t offset = 0;

    for(size_t i = 0; i < this -> SIZE; i++){

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

    std::cout << "Vector size is: " << this -> SIZE << '\n';
    for(int i = 0; i < this -> SIZE; i++){

        // std::cout << typeid(T).name() << '\n' << (typeid(T).name() == typeid(int).name()) << '\n';
        if(i != 0) strcat(result, " ");
        std::cout << "Element is: " << this -> V[i].toString() << '\n';
        strcat(result, this -> V[i].toString());
        // Gives compile error that type T is undefined with Converter functions
        // if(typeid(T).name() == typeid(int).name()) strcat(result, Converter::intToString(this -> V[i]));
        // else if(typeid(T).name() == typeid(double).name()) strcat(result, Converter::doubleToString(this -> V[i]));
        // else if(typeid(T).name() == typeid(float).name()) strcat(result, Converter::floatToString(this -> V[i]));
        // else if(typeid(T).name() == typeid(char).name()) strcat(result, this -> V[i]);
        // else strcat(result, this -> V[i].toString());

    }

    return result;

}