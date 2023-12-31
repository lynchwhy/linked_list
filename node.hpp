/*
* Node.hpp
* Written by : Jo Lynch (c3200655)
* Modified   : 27/08/23
*
* This class represents the template implementation for a Node class.
* This file should be used in conjunction with Assignment 1 for SENG1120.
*/ 

template <typename T>
Node<T>::Node() 
{ 
    data = T();
}

template <typename T>
Node<T>::Node(const T& new_data)
{ 
    data = new_data;
}

template <typename T>
Node<T>::~Node() 
{
    //empty destructor
}


// ---- Mutators --------
template <typename T>
void Node<T>::set_data(T& new_data) 
{
    data = new_data;
}

template <typename T>
void Node<T>::set_next(Node<T>* const new_next) 
{
    if (new_next != nullptr) { 
    next = new_next;
    }
}

template <typename T>
void Node<T>::set_prev(Node<T>* const new_prev) 
{
    prev = new_prev;
}

// ---- Accessors --------
template <typename T>
Node<T>* Node<T>::get_next() 
{
    return next;
}

template <typename T>
Node<T>* Node<T>::get_prev() 
{
    return prev;
}

template <typename T>
T& Node<T>::get_data() 
{
    return data;
}

template <typename T>
const Node<T>* Node<T>::get_next() const 
{
    return next;
}

template <typename T>
const Node<T>* Node<T>::get_prev() const 
{
    return prev;
}

template <typename T>
const T& Node<T>::get_data() const 
{
    return data;
}