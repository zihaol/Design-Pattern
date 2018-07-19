#include "Observer.h"


Listener::Listener(string strName)
	: m_strName(strName)
{

}

Listener::~Listener()
{

}

void Listener::update(string strNotice)
{
	cout << m_strName << " get notice " << strNotice << endl;
}


