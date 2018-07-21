#include <iostream>
using namespace std;


class EarthAnimal
{
public:
	EarthAnimal() {}
	~EarthAnimal() {}
	virtual void SayEarthRun() { cout << "Run in the earth" << endl; }
};

class EarthDog : public EarthAnimal
{
public:
	EarthDog() {}
	~EarthDog() {}
	virtual void SayEarthRun() { cout << "Dog Run in the earth" << endl; }
};

class EarthCat : public EarthAnimal
{
public:
	EarthCat() {}
	~EarthCat() {}
	virtual void SayEarthRun() { cout << "Cat Run in the earth" << endl; }
};

class HuoXingPig
{
public:
	HuoXingPig() {}
	~HuoXingPig() {}
	void HuoxingRun() { cout << "Ping run" << endl; }
private:

};

class EarthAdapter : public EarthAnimal
{
public:
	EarthAdapter() { m_pHuoXingPig = new HuoXingPig; }
	~EarthAdapter() {}
	virtual void SayEarthRun() { m_pHuoXingPig->HuoxingRun(); }
private:
	HuoXingPig* m_pHuoXingPig;
};

//void EarthRun(EarthAnimal)
void main()
{
	EarthAnimal* pEDog = new EarthDog;
	pEDog->SayEarthRun();
	delete pEDog;
	system("pause");
}
