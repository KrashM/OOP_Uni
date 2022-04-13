#ifndef VECTOR
#define VECTOR

template <typename T>
class Vector{

    private:
        T *V;
        unsigned SIZE, CAPACITY;

        void reset();
        void resize();

    
    public:
        Vector();
        ~Vector();

        T &operator [](const unsigned index);

        const bool isEmpty() const;
        const unsigned getCapacity() const;
        const unsigned getSize() const;
        T getAt(unsigned index) const;
        T getFirst() const;
        T getLast() const;
        T popBack();
        T removeAt(unsigned index);
        void assign(unsigned size, T element);
        void pushBack(T element);
        void insert(unsigned index, T element);
        void erase(T element);
        const char *toString() const;

};

#endif