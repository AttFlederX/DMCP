#pragma once
#ifndef SET_H
#define SET_H
/* A class for representing sets(vector-like data type with no repeating elements) w/ standard operations. */
#include "lib.h"
//#include "Vector.h"

class Set
{
private:
	vector<float> Elements;
	int len = 0;
public:
	Set() { }
	Set(vector<float> el, int l);
	~Set() { Elements.clear(); }
	int Length() { return len; }
	void Add(float X);
	float & operator [] (int i)
	{
		return Elements[i];
	}
	Set Union(Set X);
	Set Intersection(Set X);
	Set Difference(Set X);
	bool IsSubset(Set X);
	void Input();
	void Print();
};


#endif