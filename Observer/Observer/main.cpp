#include "Observer.h"
#include "Subject.h"

void main()
{
	CQianTai* pQianTai = new CQianTai();
	pQianTai->setNotice("boss come!");
	Listener XiaoZhi("XiaoZhi");
	Listener XiaoGang("XiaoGang");
	pQianTai->AddObserver(&XiaoZhi);
	pQianTai->AddObserver(&XiaoGang);
	pQianTai->Notice();

	delete pQianTai;
}

