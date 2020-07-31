#pragma once
#include <vector>
// DM-like lists
//

// Forward declare the class template
template<typename T> class List;

// Declare the function
template <typename T> List<T> operator+=(List<T>& lhs, const T& rhs);
template <typename T> List<T> operator|=(List<T>& lhs, const T& rhs);
template <typename T> List<T> operator-=(List<T>& lhs, const T& rhs);
template <typename T> List<T> operator+(List<T>& lhs, const T& rhs);
template <typename T> List<T> operator-(List<T>& lhs, const T& rhs);
template <typename T> List<T> operator+(const List<T>& lhs, const List<T>& rhs);
template <typename T> List<T> operator|(const List<T>& lhs, const List<T>& rhs);
template <typename T> List<T> operator-(const List<T>& lhs, const List<T>& rhs);

// Declare the friend in the class definition
template <typename T>
class List
{
public:
    List() {};
    List(std::vector<T> vec);
    
    friend List operator+=<T>(List& lhs, const T& rhs);
    friend List operator|=<T>(List& lhs, const T& rhs);
    friend List operator-=<T>(List& lhs, const T& rhs);
    friend List operator+<T>(List& lhs, const T& rhs);
    friend List operator-<T>(List& lhs, const T& rhs);
    friend List operator+<T>(const List& lhs, const List& rhs);
    friend List operator|<T>(const List& lhs, const List& rhs);
    friend List operator-<T>(const List& lhs, const List& rhs);

    T operator[](size_t i);
    int find(T e);

    size_t size = 0;
    std::vector<T> contents;
};

template <typename T> 
inline List<T> operator+=(List<T>& lhs, const T& rhs)
{
    lhs.contents.push_back(rhs);
    lhs.size++;
    return lhs;
}

template <typename T>
inline List<T> operator|=(List<T>& lhs, const T& rhs)
{
    if (lhs.find(rhs) < 0)
    {
        lhs.contents.push_back(rhs);
        lhs.size++;
    }
    return lhs;
}

template <typename T>
inline List<T> operator-=(List<T>& lhs, const T& rhs)
{
    int i = lhs.find(rhs);
    if (i >= 0)
    {
        lhs.contents.erase(lhs.contents.begin() + i);
        lhs.size--;
    }
    return lhs;
}

template <typename T>
inline List<T> operator+(List<T>& lhs, const T& rhs)
{
    lhs += rhs;
    return lhs;
}

template <typename T>
inline List<T> operator-(List<T>& lhs, const T& rhs)
{
    lhs -= rhs;
    return lhs;
}

template <typename T>
inline List<T> operator+(const List<T>& lhs, const List<T>& rhs)
{
    List<T> res;
    for (auto& e : lhs.contents)
        res += e;
    for (auto& e : rhs.contents)
        res += e;
    return res;
}

template <typename T>
inline List<T> operator|(const List<T>& lhs, const List<T>& rhs)
{
    List<T> res;
    for (auto& e : lhs.contents)
        res |= e;
    for (auto& e : rhs.contents)
        res |= e;
    return res;
}

template <typename T>
inline List<T> operator-(const List<T>& lhs, const List<T>& rhs)
{
    List<T> res = lhs;
    for (auto& e : rhs.contents)
        res -= e;
    return res;
}

template<typename T>
inline List<T>::List(std::vector<T> vec)
{
    contents = vec;
    size = vec.size();
}

template<typename T>
inline T List<T>::operator[](size_t i)
{
    return contents[i];
}

template<typename T>
inline int List<T>::find(T e)
{
    for (size_t i = 0; i < contents.size(); ++i)
        if (contents[i] == e)
            return i;
    return -1;
}