#include <iostream>
using namespace std;

enum enAnimalType
{
	enDog = 0,
	enHuman = 1,
	enBlackMan = 2,
	enWhiteMan = 3,
};

class Animal
{
public:
	Animal() {}
	~Animal() {}
	virtual void SayHello() = 0;
};

class Dog : public Animal
{
public:
	Dog() {}
	~Dog() {}
	virtual void SayHello() { cout << "wang wang wang" << endl; };
};

class Human : public Animal
{
public:
	Human() {}
	~Human() {}
	virtual void SayHello() { cout << "hello" << endl; };
};

class BlackHuman : public Animal
{
public:
	BlackHuman() {}
	~BlackHuman() {}
	virtual void SayHello() { cout << "black hello" << endl; };
};

class WhiteHuman : public Animal
{
public:
	WhiteHuman() {}
	~WhiteHuman() {}
	virtual void SayHello() { cout << "white hello" << endl; };
};

class Shen
{
public:
	Shen() {}
	~Shen() {}
	virtual Animal* CreateAnimal(enAnimalType type) = 0;
};

class NvWa : public Shen
{
public:
	NvWa() {}
	~NvWa() {}
	Animal* CreateAnimal(enAnimalType type);
};

class ShenNong : public Shen
{
public:
	ShenNong() {}
	~ShenNong() {}
	Animal* CreateAnimal(enAnimalType type);
};

Animal* NvWa::CreateAnimal(enAnimalType type)
{
	Animal* pHuman = nullptr;
	do 
	{
		switch (type)
		{
		case enHuman:
			pHuman = new Human();
			break;
		case enBlackMan:
			pHuman = new BlackHuman();
			break;
		case enWhiteMan:
			pHuman = new WhiteHuman();
			break;
		default:
			break;
		}
	} while (false);
	return pHuman;
}

Animal* ShenNong::CreateAnimal(enAnimalType type)
{
	Animal* pRet = nullptr;
	do 
	{
		switch (type)
		{
		case enDog:
			pRet = new Dog();
			break;
		default:
			break;
		}
	} while (false);
	return pRet;
}

void main()
{
	Shen* pShen = new ShenNong;
	Animal* pAnimal = pShen->CreateAnimal(enDog);
	pAnimal->SayHello();
	system("pause");
}


