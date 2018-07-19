#pragma once

#include <string>
#include <vector>

using namespace std;

class Observer;
class Subject
{
public:
	virtual void Notice() = 0;
	virtual void AddObserver(Observer* pObserver) = 0;
	virtual void DelObserver(Observer* pObserver) = 0;
};

class CQianTai : public Subject
{
public:
	CQianTai();
	~CQianTai();
	virtual void Notice();
	virtual void AddObserver(Observer* pObserver);
	virtual void DelObserver(Observer* pObserver);
	void setNotice(const char* szNotice);
	const char* getNotice();
private:
	string				m_strNotice;
	vector<Observer*>	m_vObserver;
};


