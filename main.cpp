#include <iostream>
#include <Windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	friend void common_denominator(Fraction& left, Fraction& right);
	friend bool operator== (Fraction left, Fraction right);
	friend bool operator!= (Fraction left, Fraction right);
	friend bool operator< (Fraction left, Fraction right);
	friend bool operator> (Fraction left, Fraction right);
	friend bool operator<= (Fraction left, Fraction right);
	friend bool operator>= (Fraction left, Fraction right);
};


void common_denominator(Fraction& left, Fraction& right)
{
	Fraction nLeft = left;
	left.numerator_ *= right.denominator_;
	left.denominator_ *= right.denominator_;
	right.numerator_ *= nLeft.denominator_;
	right.denominator_ *= nLeft.denominator_;
}

bool operator== (Fraction left, Fraction right)
{
	common_denominator(left, right);
	if (left.numerator_ == right.numerator_)
	{
		return true;
	}
	else return false;
}

bool operator!= (Fraction left, Fraction right)
{
	common_denominator(left, right);
	if (left.numerator_ != right.numerator_)
	{
		return true;
	}
	else return false;
}

bool operator< (Fraction left, Fraction right)
{
	common_denominator(left, right);
	if (left.numerator_ < right.numerator_)
	{
		return true;
	}
	else return false;
}

bool operator> (Fraction left, Fraction right)
{
	common_denominator(left, right);
	if (left.numerator_ > right.numerator_)
	{
		return true;
	}
	else return false;
}

bool operator<= (Fraction left, Fraction right)
{
	common_denominator(left, right);
	if (left.numerator_ <= right.numerator_)
	{
		return true;
	}
	else return false;
}

bool operator>= (Fraction left, Fraction right)
{
	common_denominator(left, right);
	if (left.numerator_ >= right.numerator_)
	{
		return true;
	}
	else return false;
}

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}