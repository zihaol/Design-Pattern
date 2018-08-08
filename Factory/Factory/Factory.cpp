#include <iostream>
using namespace std;

enum enHumanType
{
	enHTBlack = 0,
	enHTWhite = 1,
	enHTYellow = 2,
};

class Human
{
public:
	Human() {}
	~Human() {}
	virtual void SayHello() { cout << "i just a man" << endl; };
};

class NvWa
{
public:
	NvWa() {}
	~NvWa() {}
	Human* CreateHuman(enHumanType type);
private:
	
};

class BlackMan : public Human
{
public:
	BlackMan() {}
	~BlackMan() {}
	virtual void SayHello() { cout << "i am black" << endl; };
};

class WhiteMan : public Human
{
public:
	WhiteMan() {}
	~WhiteMan() {}
	virtual void SayHello() { cout << "i am white" << endl; };
};

class YellowMan : public Human
{
public:
	YellowMan() {}
	~YellowMan() {}
	virtual void SayHello() { cout << "i am yellow" << endl; };
};

Human* NvWa::CreateHuman(enHumanType type)
{
	Human* pHuman = nullptr;
	do 
	{
		switch (type)
		{
		case enHTBlack:
			pHuman = new BlackMan;
			break;
		case enHTWhite:
			pHuman = new WhiteMan;
			break;
		case enHTYellow:
			pHuman = new YellowMan;
			break;
		default:
			pHuman = new BlackMan;
			break;
		}
	} while (false);
	return pHuman;
}


//void main()
//{
//	NvWa nvwa;
//	Human* pYellow = nvwa.CreateHuman(enHTYellow);
//	pYellow->SayHello();
//	delete pYellow;
//	system("pause");
//}


