#include <iostream>
using namespace std;

class CObject
{
public:
	CObject() {}
	~CObject() {}
	virtual void Operator() = 0;
private:

};


class Phone : public CObject
{
public:
	Phone() {}
	~Phone() {}
	virtual void Operator() { cout << "this is a phone, i can call"; }
};

class AIPhone : public CObject
{
public:
	AIPhone(CObject* pObject) : m_pObject(pObject) {}
	~AIPhone() {}
	virtual void Operator() { m_pObject->Operator(); }
private:
	CObject* m_pObject;
};


class IPhone : public AIPhone
{
public:
	IPhone(CObject* pObject) : AIPhone(pObject){}
	~IPhone() {}
	virtual void Operator() { AIPhone::Operator(); cout << ", i can touched"; }
};

void main()
{
	Phone* pPhone = new Phone;
	IPhone* pIphone = new IPhone(pPhone);
	pIphone->Operator();
	delete pIphone;
	delete pPhone;
	//IPhone* pIphone = new IPhone;
	//pIphone->Operator();

	//delete pIphone;
	system("pause");
}


