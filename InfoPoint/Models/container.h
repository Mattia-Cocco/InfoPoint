#ifndef CONTAINER_H
#define CONTAINER_H

#include<iostream>


template <class T>

class  Container
{
private:
    T* V;

    unsigned int capacity;
    unsigned int size;
    void doubleCapacity ();

    static T* copia(T* t, int sz, int cap);

public:
    class iterator {
        friend class Container <T>;
    private:
        T* ptr;
        iterator(T*);
    public:
        iterator& operator++();
        iterator operator++(int);
        iterator& operator --();
        iterator operator --(int);
        iterator& operator +(unsigned int );
        iterator& operator -(unsigned int );
        iterator& operator +=(unsigned int);
        iterator& operator -=(unsigned int);

        T& operator*();
        T*operator->();
        bool operator ==(const iterator&)const;
        bool operator !=(const iterator&)const;

    };

    class const_iterator{
        friend class Container<T>;
    private:
        const T*cptr;
        const_iterator(T*);

    public:
        bool operator ==(const const_iterator&)const;
        bool operator !=(const const_iterator&)const;

        const_iterator& operator++();
        const_iterator operator ++(int);
        const_iterator &operator--();
        const_iterator operator --(int);
        const_iterator &operator +(unsigned int);
        const_iterator &operator -(unsigned int);
        const_iterator &operator+=(unsigned int);
        const_iterator &operator -=(unsigned int);

        const T&operator *()const;
        const T*operator ->() const;
    };

    // costruttori
    Container(const Container <T>&);
    Container(unsigned int=0);
    Container(const T&, unsigned int);
    Container& operator=(const Container&); //assegnazione

    // distruttore
    ~Container();

    unsigned int getVsize() const; // elementi presenti nel vector
    unsigned int getVcapacity()const;// capacità del vector
    void clear() ; // liberare il vector;
    bool empty()const; // vector  non contiene alcun elemento
    T& front() ; // il primo element nel vector
    T& back();   // ultimo elemento nel vector

    void push_back(const T&); //mettere un elemento alla fine
    void pop_back(); //togliere un elemento dalla fine
    void erase(unsigned int=0); // rimuove singolo elemento
    void erase(unsigned int, unsigned int);
    void erase(T);
    void printAll()const;


    iterator begin() const;
    iterator end() const;
    const_iterator cbegin()const;
    const_iterator cend() const;
    bool operator==(const Container<T>&) const;
    bool operator<=(const Container&) const;
    bool operator>=(const Container&) const;
    T& operator[](unsigned int );
    T&atPos(unsigned int);

};

// Implementazione della classe vector
template <typename T>
Container<T>::Container(unsigned int s): V(new T[s]), capacity(s),size(0){}
template <typename T>
Container<T>::Container(const T&t, unsigned int s): size(0), capacity(s), V(new T [s]){
    int n=0;
    while(n<capacity){
        V[n]=t;
        n++;
    }
}
template <typename T>
Container<T>::Container(const Container<T>& t):size(t.size), capacity(t.capacity), V(new T[t.capacity]){
    int n=0;
    while(n<size){
        V[n]=t.V[n];
        n++;
    }
}

template <typename T>
Container<T>& Container<T>::operator=(const Container<T>&t){
    if(this!=&t){
        delete[] V;
        size=t.size;
        capacity=t.capacity;
        V=new T[capacity];
        unsigned int n=0;
        while(n<size){
            V[n]=t.V[n];
            n++;
        }
    }
    return *this;
}
template<typename T>
T& Container<T>::operator[](unsigned int i){ return V[i];}

template<class T>
bool Container<T>::operator ==(const Container<T>&t)const{
                bool equal=t.size==size && t.capacity==capacity;
                for(auto iter1=cbegin(), iter2=t.cbegin(); iter1!=cend() && equal; ++iter1, ++iter2)
                {
                    if(*iter1!=*iter2)
                    {
                        equal=false;
                    }
                }return equal;
}


template <typename T>
Container<T>::~Container<T>(){
    if(V)
        delete[] V;
}

template <typename T>
unsigned int Container<T>::getVsize()const{
    return size;
}
template <typename T>
unsigned int Container<T>::getVcapacity()const{
    return capacity;
}

template <typename T>
bool Container<T>::empty()const{
    return size==0;
}

template <typename T>
T&Container<T>::front(){
    return V[0];
}
template <typename T>
T&Container<T>::back(){
    return V[size-1];
}


template <typename T>
void Container<T>::push_back(const T&t){
    if(!(size<capacity))
        doubleCapacity();
    V[size]=t;
    size++;
}



template <typename T>
void Container<T>::erase(unsigned int first, unsigned int last){
    if(first <0 || last<0 || first>size-1 || last>size-1 || first>last)
        throw std::out_of_range(" ");

    unsigned int f=first;
    unsigned int l=1;

    for(; f<size; f++,l++)
        V[f]=V[last+l];

    size-=(last-first)+1;

}


template <typename T>
void Container<T>::erase(unsigned int i){
    if(i>size-1)
        throw std::out_of_range("");


    unsigned int  n=i;
    for(; n<size-1; n++)
         V[n]=V[n+1];

    size--;

}




template<class T>
void Container<T>::erase(T t){
    unsigned int i=0U;
    for(auto it=begin(); (*it)!=t && it!=end(); i++,++it);
    return erase(i);
}


// Copia profonda
template<class T>
T* Container<T>::copia(T *t, int sz, int cap) {
    T* a = new T[cap];
    for (int i = 0; i < sz; ++i)
        a[i] = t[i];
    return a;
}


template  <typename T>
void Container<T>::doubleCapacity(){

    if (capacity==0) ++capacity;
    V=copia(V, size, capacity*2);
    capacity=capacity*2;
}

template <typename T>
void Container<T>::clear(){
    delete [] V;
    V=new T[2];
    capacity=2;
    size=0;
}


//+++++++++++++++++



// Iterator
template <typename T>
typename Container<T>::iterator Container<T>::begin()const{
    return iterator(V);
}
template <typename T>
typename Container<T>::iterator Container<T>::end()const{
    return iterator(V+size);
}

template <typename T>
typename Container<T>::const_iterator Container<T>::cbegin()const{
    return const_iterator(V);
}

template <typename T>
typename Container<T>::const_iterator Container<T>::cend()const{
    return const_iterator(V+size);
}

template <typename T>
void Container<T>::printAll() const {
    if(size==0) std::cout<<"Vector e' vuoto "<<std::endl;
    for( unsigned int i=0; i< size; i++)
        std::cout<<V[i]<<" ";
    std::cout<<std::endl;
}


// iterator
template<class T>
Container<T>::iterator::iterator(T*t):ptr(t){}

template<typename T>
bool Container<T>::iterator::operator!=(const iterator& iter) const{
    return ptr !=iter.ptr;
}
template<typename T>
bool Container<T>::iterator::operator ==(const iterator& iter) const {
    return ptr==iter.ptr;
}

template<typename T>
typename Container<T> ::iterator& Container<T>::iterator::operator ++(){
    if(ptr)
        ptr++;
    return *this;
}

template<typename T>
typename Container<T>::iterator Container<T>::iterator::operator++(int) {
    iterator temp=*this;
    if(ptr)
        ptr++;
    return temp;
}


template<typename T>
T&Container<T>::iterator::operator*(){
    return *ptr;
}

template<typename T>
T* Container<T>::iterator::operator->(){
        return ptr;
}

template<typename T>
typename Container<T>::iterator& Container<T>::iterator::operator --(){
    if(ptr)
        ptr--;
    return *this;
}


template<typename T>   /*++++++++++++++++++++++*/
typename Container<T>::iterator Container<T>::iterator::operator--(int){
    iterator temp=*ptr;
    if(ptr)
        ptr--;
    return temp;
}


template <typename T>
typename Container<T>::iterator& Container<T>::iterator::operator +(unsigned int iter){
    if(ptr)
        ptr+=iter;
    return *this;
}

template <typename T>
typename Container<T>::iterator& Container<T>::iterator::operator -(unsigned int iter){
    if(ptr)
         ptr-=iter;
    return *this;
}
template <typename T>
typename Container<T>::iterator& Container<T>::iterator::operator -=(unsigned int iter){
    if(ptr)
        ptr-=iter;
    return *this;
}

template <typename T>
typename Container<T>::iterator& Container<T>::iterator::operator +=(unsigned int iter){
    if(ptr)
        ptr+=iter;
    return *this;
}

template <typename T>
T& Container<T>::atPos(unsigned int i){
    if(i<0 || i > size-1){
        throw std::out_of_range("The index is out of bound");

    }
    return V[i];
}

//const_iterator
template<class T>
Container<T>::const_iterator::const_iterator(T*t):cptr(t){}
template<typename T>
bool Container<T>::const_iterator::operator==(const const_iterator& iter)const{
    return cptr=iter.cptr;
}
template<typename T>
bool Container<T>::const_iterator::operator!=(const const_iterator&iter)const{
    return cptr!=iter.cptr;
}


template< typename T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator++() {
    if(cptr)
        cptr++;
    return *this;
}

template< typename T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator++(int) {
    const_iterator temp=*this;
    if(cptr)
        cptr++;
    return temp;
}

template  <typename T>
const T& Container<T>::const_iterator::operator*()const{
    return *cptr;
}

template  <typename T>
const T* Container<T>::const_iterator::operator->()const{
    return cptr;
}


template <typename T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator --(){
    if(cptr)
        cptr--;
    return *this;
}

template <typename T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator --(int){
    const_iterator temp=cptr;
    if(cptr)
        cptr--;
    return temp;
}


template <typename T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator +(unsigned int iter){
    if(cptr) cptr+=iter;
    return *this;
}

template <typename T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator -(unsigned int iter){
    if(cptr)
        cptr-=iter;
    return *this;
}

template <typename T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator -=(unsigned int iter){
    if(cptr)
        cptr-=iter;
    return *this;
}

template <typename T>
typename Container<T>::const_iterator& Container<T>::const_iterator::operator +=(unsigned int iter){
    if(cptr)
        cptr+=iter;
    return *this;
}

#endif // CONTAINER_H
