//代理模式
#include <string>
#include <iostream>

using namespace std;

class Girl
{
public:
	Girl(string strName) : m_strName(strName) {}
	~Girl() {}
	string GetName() { return m_strName; }
private:
	string m_strName;
};

class ZhuiQiu
{
public:
	ZhuiQiu() {}
	~ZhuiQiu() {}
	virtual void SendGift() = 0;
	virtual void SayLove() = 0;
};


class Boy : public ZhuiQiu
{
public:
	Boy(Girl* pGirl) : m_pGirl(pGirl) {}
	~Boy() { delete m_pGirl; }
	virtual void SendGift() { cout << "here you are " << m_pGirl->GetName() << endl; }
	virtual void SayLove() { cout << "i love you " << m_pGirl->GetName() << endl; }
private:
	Girl* m_pGirl;
};

class Proxy : ZhuiQiu
{
public:
	Proxy(Girl* pGirl) { m_pBoy = new Boy(pGirl); }
	~Proxy() { delete m_pBoy; }

	virtual void SendGift() { m_pBoy->SendGift(); }
	virtual void SayLove() { m_pBoy->SayLove(); }
private:
	Boy*		m_pBoy;
};


void main()
{
	Girl* pXiaoMei = new Girl("XiaoMei");
	Proxy* pProxy = new Proxy(pXiaoMei);
	pProxy->SendGift();
	pProxy->SayLove();
	delete pProxy;
	system("pause");
}

