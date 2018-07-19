#include "Observer.h"
#include "Subject.h"


CQianTai::CQianTai()
{

}

CQianTai::~CQianTai()
{

}

void CQianTai::Notice()
{
	for (vector<Observer*>::iterator iter = m_vObserver.begin(); iter != m_vObserver.end(); iter++)
	{
		(*iter)->update(m_strNotice);
	}
}

void CQianTai::AddObserver(Observer* pObserver)
{
	m_vObserver.push_back(pObserver);
}

void CQianTai::DelObserver(Observer* pObserver)
{
	for (vector<Observer*>::iterator iter = m_vObserver.begin(); iter != m_vObserver.end(); iter++)
	{
		if ((*iter) == pObserver)
		{
			m_vObserver.erase(iter);
		}
	}
}

void CQianTai::setNotice(const char* szNotice)
{
	m_strNotice = szNotice;
}

const char* CQianTai::getNotice()
{
	return m_strNotice.c_str();
}

