#include <iostream>
#include <string>
#include <ctime>
#include <cstddef>
#include <iomanip>

#define rows 30 //Number of generated rows
#define columns 20 //Length of columns

template<class T, std::size_t N>
class Tuple
{
	template<class U>
	struct tag { };
public:
	T *p;
	int n;
	Tuple()
		: p(new T[N])
	{
		n = N;
		fill(tag<T>());
	}
	bool operator<(const Tuple &t) const
	{
		int it = 0;
		while (it != n)
		{
			if (it == n || t.p[it] < p[it])
				return false;
			else if (p[it] < t.p[it])
				return true;
			it++;
		}
		return (it != n);
	}
	bool operator>(const Tuple &t) const
	{
		int it = 0;
		while (it != n)
		{
			if (it == n || t.p[it] > p[it])
				return false;
			else if (p[it] > t.p[it])
				return true;
			it++;
		}
		return (it != n);
	}

private:
	void fill(const tag<int>&)
	{
		for (std::size_t i = 0; i < N; i++)
		{
			p[i] = rand() % 9 + 1;
		}
	}
	void fill(const tag<double>&)
	{
		for (std::size_t i = 0; i < N; i++)
		{
			//random for double
			//p[i] = 
		}
	}
	void fill(const tag<float>&)
	{
		for (std::size_t i = 0; i < N; i++)
		{
			//random for float
			//p[i] = 
		}
	}
	void fill(const tag<std::string>&)
	{
		static const char s[] =
		{
			'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
			'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
			'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
			'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y', 'Z',
			'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
		};
		for (std::size_t i = 0; i < N; ++i) {
			p[i] = s[rand() % sizeof s];
		}
	}
};

template<class T>
void sort(T *x, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (x[j] > x[j + 1])
			{
				T temp = x[j + 1];
				x[j + 1] = x[j];
				x[j] = temp;
			}
		}
	}
}

template<class T>
void print(T *t, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (std::is_same<decltype(t[i].p), std::string*>())
		{
			for (int j = 0; j < t->n; j++)
				std::cout << t[i].p[j];
			std::cout << std::endl;
		}
		else
		{
			for (int j = 0; j < t->n; j++)
				std::cout << std::setw(1) << t[i].p[j] << " ";
			std::cout << std::endl;
		}
	}
}

template<class T>
void logic()
{
	Tuple<T, columns> t[rows];
	srand(time(NULL));
	for (int i = 0; i < rows; i++)
		t[i] = Tuple<T, columns>();

	print(t, rows);
	sort(t, rows);
	std::cout <<"\nSorted\n" << std::endl;
	print(t, rows);

}
int main()
{
	std::cout << "\nExample with integers\n" << std::endl;
	logic<int>();
	std::cout << "\nExample with strings\n" << std::endl;
	logic<std::string>();
	system("PAUSE");
}