#pragma once
#include <string>
#include <iostream>
using namespace std;

class Subject;
class Observer
{
public:
	virtual void update(string strNotice) = 0;
};

class Listener : public Observer
{
public:
	Listener(string strName);
	~Listener();
	virtual void update(string strNotice);
private:
	string				m_strName;
};

