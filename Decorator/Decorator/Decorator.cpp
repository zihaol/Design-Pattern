#include <string>
#include <iostream>
using namespace std;

//公共抽象类
class Phone
{
public:
	Phone() {}
	virtual ~Phone() {}
	virtual void showDecorate() {}

};

//具体手机类
class iPhone : public Phone
{
public:
	iPhone(string strName): m_strName(strName){}
	~iPhone() {}
	void showDecorate() { cout << m_strName << "的装饰" << endl; }
private:
	string m_strName;
};

class NokiaPhone : public Phone
{
public:
	NokiaPhone(string strName) : m_strName(strName) {}
	~NokiaPhone() {}

	void showDecorate() { cout << m_strName << "的装饰" << endl; }
private:
	string m_strName;
};

//装饰类
class DecoratorPhone : public Phone
{
public:
	DecoratorPhone(Phone* pPhone) : m_pPhone(pPhone) {}
	~DecoratorPhone() {}
	virtual void showDecorate() { m_pPhone->showDecorate(); }
private:
	Phone* m_pPhone;
};

//具体装饰类
class DecoratorPhoneA : public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone* pPhone) : DecoratorPhone(pPhone){}
	~DecoratorPhoneA() {}

	virtual void showDecorate() { DecoratorPhone::showDecorate(); addDecorate(); }
private:
	void addDecorate() { cout << "增加挂件" << endl; }
};

class DecoratorPhoneB : public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone* pPhone) : DecoratorPhone(pPhone) {}
	~DecoratorPhoneB() {}

	virtual void showDecorate() { DecoratorPhone::showDecorate(); addDecorate(); }
private:
	void addDecorate() { cout << "增加贴膜" << endl; }

};

//int main()
//{
//	Phone* pPhone = new NokiaPhone("6300");
//	Phone* pGuaJian = new DecoratorPhoneA(pPhone);
//	Phone* pTieMo = new DecoratorPhoneB(pGuaJian);
//	pTieMo->showDecorate();
//	delete pPhone;
//	delete pGuaJian;
//	delete pTieMo;
//}



