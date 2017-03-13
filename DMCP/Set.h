#pragma once
#include "Func.h"

class Set
{
private:
	int* Elements;
	int Len;
public:
	Set() { Elements = new int[1]; Len = 1; };
	Set(int n) { Elements = new int[n]; Len = n; }
	int getLen() { return Len; }
	Set Union(Set A, Set B);
	Set Intersection(Set A, Set B);
	Set Difference(Set A, Set B);
};