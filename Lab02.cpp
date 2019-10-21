#include<bits/stdc++.h>
using namespace std;

struct SinhVien
{
	long long mssv;
	string hotensv;
	float diemtb;
	string xeploai;
};

struct Node
{
	SinhVien data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct List
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

void CreateList(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

bool IsEmpty(LIST l)
{
	return (l.pHead == NULL);
}

NODE* CreateNode(SinhVien x) 
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

NODE* Search(LIST l, long long value) {
    for(NODE *p = l.pHead; p != NULL; p = p->pNext)
        if (p->data.mssv == value)
            return p;
    return NULL;
}

void AddFirst(LIST &l, NODE *p)
{
	if (IsEmpty(l))
	{
		l.pHead = l.pTail = p;
	} else {
		p->pNext = l.pHead; 
		l.pHead = p; 		 
	}
}

void AddLast(LIST &l, NODE *p)
{
	if (IsEmpty(l))
	{
		l.pHead = l.pTail = p;
	} else {
		l.pTail->pNext = p; 
		l.pTail = p; 		 
	}
}

void AddAfter(LIST &l, NODE *p, long long masv)
{
	NODE *svX = Search(l, masv);
	if (svX == NULL)
		return;
	p->pNext = svX->pNext;
	svX->pNext = p;	
}

void ProcessList(LIST &l)
{
	NODE *p = l.pHead;
	while(p != NULL)
	{
		float pointAverage = p->data.diemtb;
		string type;
	    if (pointAverage >= 9.0)
	    	type = "Xuat sac";
	    else if (pointAverage >= 8.0)
	    	type = "Gioi";
	    else if (pointAverage >= 6.5)
	    	type = "Kha";
	    else if (pointAverage >= 5.0)
	    	type = "Trung Binh";
	    else if (pointAverage >= 4.0)
	    	type = "Yeu";
	    else
	    	type = "Kem";
		p->data.xeploai = type;
		p = p->pNext;
	}
}

void DeleteFirst (LIST &l)
{
	NODE *p = l.pHead;
	l.pHead = p->pNext;
	delete p;
}

void DeleteX (LIST &l, long long masv)
{
	NODE *svX = Search(l, masv);
	if (svX == NULL)
		return;
	l.pHead = svX->pNext;
	delete svX;
}

void DeleteAfter (LIST &l, long long masv)
{
	NODE *svX = Search(l, masv);
	if (svX == NULL)
		return;
	
	NODE *p = svX->pNext;
	l.pHead = p->pNext;
	delete p;
}

void SortByMark (LIST &l) {
	// Sap xep chon truc tiep
	NODE *min, *p, *q;
	p = l.pHead;
	while (p->pNext != NULL) {
		q = p->pNext;
		min = p;
		while(q != NULL) {
			if (q->data.diemtb > min->data.diemtb)
				min = q;
		    q = q->pNext;
		}
		SinhVien temp = p->data;
		p->data = min->data;
		min->data = temp;
		p = p->pNext;
	}
}

void SampleData(LIST &l, int n)
{
	// Du lieu mau
	SinhVien danhsachsv[5];
	long long listMSSV[5] = {
		1824801030053,
		1824801030023,
		1824801030015,
		1824801030030,
		1824801030066
	};
	string listHoTenSV[5] = {
		"Duong Le Phuoc Trung",
		"Pham Minh Nghia",
		"Nguyen Ngoc Minh",
		"Tran Minh Hieu",
		"Ho Duy Khang"
	};
	float listDiem[5] = {
		10,
		8,
		7,
		5,
		4
	};
	
	
	for (int i = 0; i <= n; i++)
	{
		danhsachsv[i].mssv = listMSSV[i];
		danhsachsv[i].hotensv = listHoTenSV[i];
		danhsachsv[i].diemtb = listDiem[i];
	}
	
	
	
	CreateList(l);
	for(int i = 1; i <= n; i++)
	{
		NODE *p = CreateNode(danhsachsv[i - 1]); 
		AddLast(l, p);
	}
	
	// Chen sinh vien
	NODE *p = CreateNode(danhsachsv[n]); 
	AddAfter(l, p, 1824801030053);
}

void PrintList(LIST l)
{
	ProcessList(l);
	int i = 1;
	cout << "-------------------------------------------------" << endl;
	cout << "| STT |         Ho ten       | DTB |   Xep loai |" << endl;
	cout << "-------------------------------------------------" << endl;
	NODE *p = l.pHead;
	while(p != NULL)
	{
		cout << 
		"| " << setw(3) << i++ << 
		" | " << setw(20) << p->data.hotensv << 
		" | " << setw(3) << p->data.diemtb << 
		" | " << setw(10) << p->data.xeploai << " |" <<endl;
		p = p->pNext;
	}
	cout << "-------------------------------------------------" << endl;
}

int main()
{
	LIST l;
	int n = 4;
	SampleData(l, n);
	SortByMark(l);
	PrintList(l);
	
}
