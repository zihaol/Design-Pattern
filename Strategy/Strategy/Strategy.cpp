//策略模式实现面积计算
#include <iostream>
using namespace std;

const double PI = 3.1415;

class Startegy
{
public:
	Startegy() {}
	~Startegy() {}
	virtual double CalArea() = 0;
};

class CalAreaZhengFang : public Startegy
{
public:
	CalAreaZhengFang(double dLength) : m_dLength(dLength) {}
	~CalAreaZhengFang() {}
	virtual double CalArea() { return (m_dLength*m_dLength); }
private:
	double						m_dLength;
};


class CalAreaChangFang : public Startegy
{
public:
	CalAreaChangFang(double dChang, double dKuan) : m_dChang(dChang), m_dKuan(dKuan){}
	~CalAreaChangFang() {}
	virtual double CalArea() { return (m_dChang*m_dKuan); };
private:
	double						m_dChang;
	double						m_dKuan;
};

class CalAreaYuan : public Startegy
{
public:
	CalAreaYuan(double dR) : m_dR(dR) {}
	~CalAreaYuan() {}
	virtual double CalArea(double lLength) { return (m_dR*m_dR*PI); };
private:
	double						m_dR;
};

class Context
{
public:
	Context(Startegy* pCalArea) : m_pCalArea(pCalArea) {}
	~Context() {}
	double getArea() { return m_pCalArea->CalArea(); }
private:
	Startegy*				m_pCalArea;
};

void main()
{
	CalAreaChangFang* pCalChangFang = new CalAreaChangFang(10.0, 8.0);
	Context* pContext = new Context(pCalChangFang);
	cout << "Area is " << pContext->getArea() << endl;

	system("pause");
}

