#include "Optr.h"

void Optr::init(int size)
{
	maxsize = size;
	if (elems != NULL) delete[]elems;
	elems = new char[maxsize];
	count = 0;
}

bool Optr::Full() const
{
	if (count == maxsize)
		return true;
}

bool Optr::Empty() const
{
	if (count == 0)
		return true;
}

Optr::Optr(int size)
{
	elems = NULL;
	init(size);
}

void Optr::clearOpnd()
{
	count = 0;
}

Optr::~Optr()
{
	delete[]elems;
}

int Optr::push(char e)
{
	if (Full())
		return 0;
	else
	{
		elems[count++] = e;
		return 1;
	}
}

char Optr::pop()
{
	if (Empty())
		return 0;
	else
	{
		char e;
		e = elems[count - 1];
		count--;
		return e;
	}
}

char Optr::top()
{
	if (Empty())
	{
		return 0;
	}
	else
	{
		char e;
		e = elems[count - 1];
		return e;
	}
}
