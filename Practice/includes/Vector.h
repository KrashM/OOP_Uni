#pragma once

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