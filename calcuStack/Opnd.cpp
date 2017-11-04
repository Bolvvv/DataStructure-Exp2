#include "Opnd.h"

void Opnd::init(int size)
{
	maxsize = size;
	if (elems != NULL) delete[]elems;
	elems = new double[maxsize];
	count = 0;
}

bool Opnd::Full() const
{
	if(count == maxsize)
	return true;
}

bool Opnd::Empty() const
{
	if(count == 0)
	return true;
}

Opnd::Opnd(int size)
{
	elems = NULL;
	init(size);
}

void Opnd::clearOpnd()
{
	count = 0;
}

Opnd::~Opnd()
{
	delete[]elems;
}

int Opnd::push(double e)
{
	if (Full())
		return 0;
	else
	{
		elems[count++] = e;
		return 1;
	}
}

double Opnd::pop()
{
	if (Empty())
		return 0;
	else
	{
		double e;
		e = elems[count - 1];
		count--;
		return e;
	}
}

double Opnd::top()
{
	if (Empty())
	{
		return 0;
	}
	else
	{
		double e;
		e = elems[count - 1];
		return e;
	}
}
