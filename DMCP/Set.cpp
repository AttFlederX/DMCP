#include "Set.h"


/* Parameter constructor for Set class. Includes checking routine that eliminates repeating elements*/
Set::Set(vector<float> el, int l) 
{ 
	Elements = vector<float>();
	len = 0;
	
	for (int i = 0; i < l; i++)
	{
		bool isInSet = false;
		for (int j = 0; j < len; j++)
		{
			if (el[i] == Elements[j])
			{
				isInSet = true;
				break;
			}
		}

		if (!isInSet)
		{
			Elements.push_back(el[i]);
			len++;
		}
	}
}

/* Adds an element to the set */
void Set::Add(float X)
{
	bool isInSet = false;
	for (int i = 0; i < len; i++)
	{
		if (Elements[i] == X)
		{
			isInSet = true;
			break;
		}
	}

	if (!isInSet)
	{
		Elements.push_back(X);
		len++;
	}
}

/* Returns a union of two sets */
Set Set::Union(Set X)
{
	vector<float> R;
	int setLen = 0;
	int setXLen = X.Length();

	for (int i = 0; i < len; i++)
	{
		R.push_back(Elements[i]);
		setLen++;
	}

	for (int i = 0; i < setXLen; i++)
	{
		R.push_back(X.Elements[i]);
		setLen++;
	}
	return Set(R, setLen);
}

/* Returns an intersection of two sets */
Set Set::Intersection(Set X)
{
	vector<float> R;
	int setLen = 0;
	int setXLen = X.Length();

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < setXLen; j++)
		{
			if (Elements[i] == X.Elements[j])
			{
				R.push_back(Elements[i]);
				setLen++;
			}
		}
	}

	return Set(R, setLen);
}

/* Returns a difference between the calling set and the argument set (e.g. A.Difference(B) = A / B)*/
Set Set::Difference(Set X)
{
	vector<float> R;
	int setLen = 0;
	int setXLen = X.Length();

	for (int i = 0; i < len; i++)
	{
		bool isInX = false;
		for (int j = 0; j < setXLen; j++)
		{
			if (X.Elements[j] == Elements[i])
			{
				isInX = true;
				break;
			}
		}
		if (!isInX)
		{
			R.push_back(Elements[i]);
			setLen++;
		}
	}

	return Set(R, setLen);
}

/* Checks whether X is a subset of a calling set */
bool Set::IsSubset(Set X)
{
	int setXLen = X.Length();
	bool isSub = true;

	for (int i = 0; i < setXLen; i++)
	{
		bool isInSet = false;
		for (int j = 0; j < len; j++)
		{
			if (Elements[j] == X[i])
			{
				isInSet = true;
			}
		}
		if (!isInSet)
		{
			isSub = false;
			break;
		}
	}

	return isSub;
}


void Set::Input()
{
	cout << "Enter set length: ";
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		float el;
		cout << "Enter set element #" << i + 1 << ": ";
		cin >> el;

		Elements.push_back(el);
	}
}

void Set::Print()
{
	cout << "{";
	for (int i = 0; i < len; i++)
	{
		cout << Elements[i];
		(i == len - 1) ? (cout << "}\n") : (cout << ", ");
	}
}