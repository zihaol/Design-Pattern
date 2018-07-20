#include <string>
#include <iostream>
using namespace std;

//����������
class Phone
{
public:
	Phone() {}
	virtual ~Phone() {}
	virtual void showDecorate() {}

};

//�����ֻ���
class iPhone : public Phone
{
public:
	iPhone(string strName): m_strName(strName){}
	~iPhone() {}
	void showDecorate() { cout << m_strName << "��װ��" << endl; }
private:
	string m_strName;
};

class NokiaPhone : public Phone
{
public:
	NokiaPhone(string strName) : m_strName(strName) {}
	~NokiaPhone() {}

	void showDecorate() { cout << m_strName << "��װ��" << endl; }
private:
	string m_strName;
};

//װ����
class DecoratorPhone : public Phone
{
public:
	DecoratorPhone(Phone* pPhone) : m_pPhone(pPhone) {}
	~DecoratorPhone() {}
	virtual void showDecorate() { m_pPhone->showDecorate(); }
private:
	Phone* m_pPhone;
};

//����װ����
class DecoratorPhoneA : public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone* pPhone) : DecoratorPhone(pPhone){}
	~DecoratorPhoneA() {}

	virtual void showDecorate() { DecoratorPhone::showDecorate(); addDecorate(); }
private:
	void addDecorate() { cout << "���ӹҼ�" << endl; }
};

class DecoratorPhoneB : public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone* pPhone) : DecoratorPhone(pPhone) {}
	~DecoratorPhoneB() {}

	virtual void showDecorate() { DecoratorPhone::showDecorate(); addDecorate(); }
private:
	void addDecorate() { cout << "������Ĥ" << endl; }

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



