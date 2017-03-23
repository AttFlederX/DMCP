#pragma once
/* (REDUNDANT) Vector class for arrays with changeable size 
	Was substituted for a built-in vector class due to deletion issues */

#ifndef VECTOR_H
#define VECTOR_H
#include "Func.h"

template <class T>
class Vector
{
private:
	T* Elements;
	int len;
public:
	Vector() { Elements = new T; len = 0; }
	Vector(int n) { Elements = new T[n]; len = n; }
	~Vector() { delete[] Elements; }
	T & operator [] (int i)
	{
		return Elements[i];
	}
	void Add(T X);
	void RemoveAt(int idx);
	void Clear();
	int Length() { return len; };
	void Print();
};


/* Function implementaions
Since it is a template class, implementations have to be in the same file as the declarations */

/* Adds an element at the end of the vector */
template <class T>
void Vector<T>::Add(T X)
{
	T* newEl = new T[len];

	for (int i = 0; i < len; i++)
	{
		newEl[i] = Elements[i];
	}

	len++;
	Elements = new T[len];

	for (int i = 0; i < len - 1; i++)
	{
		Elements[i] = newEl[i];
	}

	Elements[len - 1] = X;
	delete[] newEl;
}

/* Removes an element at a specified position */
template <class T>
void Vector<T>::RemoveAt(int n)
{
	if (n >= 0 && n < Length())
	{
		T* newEl = new T[len - 1];
		for (int i = 0; i < len; i++)
		{
			if (i < n)
			{
				newEl[i] = Elements[i];
			}
			if (i >= n)
			{
				newEl[i] = Elements[i + 1];
			}
		}

		len--;
		Elements = new T[len];
		for (int i = 0; i < len; i++)
		{
			Elements[i] = newEl[i];
		}

		delete[] newEl;
	}
}


/* Clears the vector contents */
template <class T>
void Vector<T>::Clear()
{
	Elements = new T;
	len = 0;
}


/* Prints the vector contents */
template <class T>
void Vector<T>::Print()
{
	cout << "{";
	for (int i = 0; i < len; i++)
	{
		cout << Elements[i];
		(i == len - 1) ? (cout << "}\n") : (cout << ", ");
	}
}

#endif
