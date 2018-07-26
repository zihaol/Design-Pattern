#include <iostream>
#include <list>
#include <string>

using namespace std;

class IFile
{
public:
	IFile(string strFile) : m_strName(strFile) {}
	~IFile() {}
	virtual void AddChild(IFile* pFile) {}
	virtual void DelChild(IFile* pFile) {}
	virtual void Show() { cout << m_strName << endl; }
private:
	string		m_strName;
};


class Folder : public IFile
{
public:
	Folder(string strFile) : IFile(strFile) {}
	~Folder() {}
	virtual void AddChild(IFile* pFile);
	virtual void DelChild(IFile* pFile);
	virtual void Show();
private:
	list<IFile*>		m_pListSubFile;
};


void Folder::AddChild(IFile* pFile)
{
	if (nullptr != pFile)
	{
		m_pListSubFile.push_back(pFile);
	}
}

void Folder::DelChild(IFile* pFile)
{
	if (nullptr != pFile)
	{
		m_pListSubFile.remove(pFile);
	}
}

void Folder::Show()
{
	cout << "Folder ";
	IFile::Show();
	for (list<IFile*>::iterator iter = m_pListSubFile.begin(); iter != m_pListSubFile.end(); iter++)
	{
		cout << "	-";
		(*iter)->Show();
	}
}

class File : public IFile
{
public:
	File(string strName) : IFile(strName) {}
	~File() {}
	virtual void Show();
};
void File::Show()
{
	cout << "File ";
	IFile::Show();
}


void main()
{
	Folder* pBooks = new Folder("Books");

	File* pDesign = new File("Design");
	pBooks->AddChild(pDesign);

	File* pPPT = new File("PPT");
	pBooks->AddChild(pPPT);

	pBooks->Show();

	delete pBooks;
	system("pause");
}


