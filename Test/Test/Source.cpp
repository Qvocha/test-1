#include <iostream>

using namespace std;

struct compareInterface
{
	virtual bool operator<(compareInterface const & c2) const = 0;
	bool operator>(compareInterface const & c2) const
	{
		return c2 < (*this);
	}
	bool operator<=(compareInterface const & c2) const
	{
		return !((*this) > c2);
	}
	bool operator>=(compareInterface const & c2) const
	{
		return !((*this) < c2);
	}
	bool operator==(compareInterface const & c2) const
	{
		return ((*this) <= c2) && ((*this) >= c2);
	}
};

struct twoLetterWord : compareInterface
{
	char letter1;
	char letter2;
	twoLetterWord()
	{
	}
	twoLetterWord(char letter1, char letter2)
	{
		this->letter1 = letter1;
		this->letter2 = letter2;
	}
	bool operator<(compareInterface const & t2) const
	{
		int const w1l1 = (int)(this->letter1);
		int const w1l2 = (int)(this->letter2);
		int const w2l1 = (int)(t2.letter1);
		int const w2l2 = (int)(t2.letter2);
		if (w1l1 < w2l1)
		{
			return true;
		}
		if (w1l1 > w2l1)
		{
			return false;
		}
		if (w1l2 < w2l2)
		{
			return true;
		}
		return false;
	}
	friend ostream & operator<<(ostream & out, twoLetterWord const & word)
	{
		out << word.letter1 << word.letter2;
		return out;
	}
	friend istream & operator>>(istream & in, twoLetterWord & word)
	{
		in >> word.letter1 >> word.letter2;
		return in;
	}
};


int main()
{
	twoLetterWord w1;
	twoLetterWord w2;
	cin >> w1 >> w2;
	cout << w1 << "  " << w2 << "  " << (w1 > w2) << endl;
	system("pause");
	return 0;
}