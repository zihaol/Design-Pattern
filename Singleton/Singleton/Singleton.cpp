#include <iostream>
using namespace std;

class SingletonCal
{
public:
	~SingletonCal() {}
	int Add(int a, int b) { return a + b; }
	static SingletonCal* GetInstance();
private:
	SingletonCal() {}
	static SingletonCal* s_pSingleCal;
};

SingletonCal* SingletonCal::s_pSingleCal = nullptr;

SingletonCal* SingletonCal::GetInstance()
{
	if (nullptr == s_pSingleCal)
	{
		s_pSingleCal = new SingletonCal;
	}
	return s_pSingleCal;
}

void main()
{
	int nA = 10;
	int nB = 12;

	cout << SingletonCal::GetInstance()->Add(nA, nB) << endl;

	system("pause");
}

