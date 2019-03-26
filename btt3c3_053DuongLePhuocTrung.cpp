#include<bits/stdc++.h>
using namespace std;

/* Config student information */
const string fullname = "Duong Le Phuoc Trung";
const string className = "D18PM01";
const string studentCode =  "1824801030053";

string text;

void inputString();
void alertNotice();
bool validString();
void function3();
void clearWhiteSpace();
void tachChuoi();
void docso();
void exitProgram();

int main()
{
	int select; //Bien de chon chuc nang
	bool reload =  true; // Bien lap lai menu
	
	do {
		
		/* In giao dien nguoi dung */
		system("cls");
		system("color 3");  //Doi mau chu 
		cout << "\t" << fullname << " - " << className << " - " << studentCode << endl << endl;
		cout << "\t\t\tCHUONG TRINH CHUOI" << endl;
		cout << "------------------------------------"
			 << "------------------------------------" << endl;
		cout << "Moi chon chuc nang: " << endl;
		cout << "1. Nhap vao chuoi" << endl;
		cout << "2. Tach n ky tu tai vi tri pos cua chuoi" << endl;
		cout << "3. Xoa khoang trang trong chuoi" << endl;
		cout << "4. Xuat cac tu tren dong, dem so tu, tu co do dai lon nhat" << endl;
		cout << "5. Doc so bang Tieng Viet" << endl;
		
		cout << "..." << endl;
		cout << "0. Thoat" << endl;
		cout << endl;
		/* End UI */
		
		cin >> select; //Nguoi dung chon chuc nang
		
		
		/* Xu ly chuc nang nguoi dung da chon */
		switch (select) {
			/* Tung truong hop duoc dat trong case */
			case 1:
				inputString();
				system("pause");
				break;
			case 2:
				tachChuoi();
				system("pause");
				break;
			case 3:
				clearWhiteSpace();
				system("pause");
				break;
			case 4:
				function3();
				system("pause");
				break;
			case 5:
				docso();
				system("pause");
				break;
			case 0:
				exitProgram();
				break;
			
			// Neu nguoi dung chon sai thi bao loi	
			default:
				cout << "Khong tim thay chuc nang, vui long chon lai !!!" << endl;
				reload = true;
				system("pause");
		}
		/* End Select*/
		
	} while (reload);
	
}

// Nhap chuoi luu lai de xu ly nhieu tac vu
void inputString()
{
	cout << "Nhap chuoi can xu ly: " << endl;
	cin.ignore();
	getline(cin, text);
	cout << "Chuoi da duoc luu lai !!!" << endl;
}

// Kiem tra xem chuoi da duoc nhap chua
bool validString()
{
	if (text.size())
		return true;
	return false;
}

//Thong bao loi khi chuoi chua duoc nhap
void alertNotice()
{
	cout << "Ban chua nhap chuoi, vui long chon chuc nang so 1" << endl;
}

// Cau 3 trong bai tap
void function3 ()
{
	if (!validString())
	{
		alertNotice();
		return;
	}
	cout << "In cac chu tu tren moi dong: " << endl;
	int maxKiTu = 0, numTu = 0;
	stringstream ss (text);
	string word;
	// xu dung stringstream truyen vao buffer qua bien word, tu dong tach khoang trang
	while (ss >> word)
	{
		maxKiTu = word.size() > maxKiTu ? word.size() : maxKiTu;// Gan bien maxKiTu bang ki tu co ki tu lon nhat
		cout << word << endl;
		numTu++;// Dem xem co bao tu
	}
	
	cout << "Co " << numTu << " tu, tu co do dai len nhat la: " << maxKiTu << endl;
}

// Xoa khoang trang
void clearWhiteSpace()
{
	if (!validString())
	{
		alertNotice();
		return;
	}
	// Kiem tra xem, ky tu khoang trang thi xoa luon, du lieu bien text cung duoc cap nhat
	for(int i = 0; i < text.size(); i++)
		if (text[i] == ' ')
			text.erase(text.begin() + i);
	cout << "Chuoi duoc xoa het khoang trang la: " << endl;
	cout << text << endl;
}

// Tach n ky tu cua chuoi bat dau tu vi tri pos
void tachChuoi()
{
	if (!validString())
	{
		alertNotice();
		return;
	}
	
	int n = 0, pos = 0;
	// Kiem tra nhap dung du lieu chua
	bool errorInput = false;
	do {
		
		cout << "Nhap so luong tu can cach, vi tri bat dau: " << endl;
		cin >> n >> pos;
		
		if (n <= 0 || pos < 0) {
			cout << "Du lieu nhap chua chinh xac, vui long nhap lai !" << endl;
			errorInput = true;
		} else if (n + pos > text.size()) {
			cout << "Du lieu nhap chua chinh xac, vui long nhap lai !" << endl;
			errorInput = true;
		} else
			errorInput = false;
		
	} while (errorInput);
	
	// Bat dau tach va in ket qua
	cout << "Ket Qua: ";
	for(int i = pos; i < pos + n; i++)
		cout << text[i];
	cout << endl;
	
}

// Ham doc so Tieng Viet
void docso()
{
	int n;
	cout << "Moi nhap so can doc: ";
	cin >> n;
	cout << n << " doc la: "; 
	
	// Tach tung chu so bo vao bien
	long long x, f, e, d, c, b, a;
	x = n;
	f = n%10; n /= 10;
	e = n%10; n /= 10;
	d = n%10; n /= 10;
	c = n%10; n /= 10;
	b = n%10;
	a = n/=10;
	switch(a)
	{
		case 1: cout << "mot tram "; break;
		case 2: cout << "hai tram "; break;
		case 3: cout << "ba tram "; break;
		case 4: cout << "bon tram "; break;
		case 5: cout << "nam tram "; break;
		case 6: cout << "sau tram "; break;
		case 7: cout << "bay tram "; break;
		case 8: cout << "tam tram "; break;
		case 9: cout << "chin tram "; break;
		case 0: break;
	}
	switch(b)
	{
		case 1: cout << "muoi "; break;
		case 2: cout << "hai muoi "; break;
		case 3: cout << "ba muoi "; break;
		case 4: cout << "bon muoi "; break;
		case 5: cout << "nam muoi "; break;
		case 6: cout << "sau muoi "; break;
		case 7: cout << "bay muoi "; break;
		case 8: cout << "tam muoi "; break;
		case 9: cout << "chin muoi "; break;
		case 0: if (x>100000 && c>0) cout << " le"; break;
	}
	switch(c)
	{
		case 1: cout << "mot nghin "; break;
		case 2: cout << "hai nghin "; break;
		case 3: cout << "ba nghin "; break;
		case 4: cout << "bon nghin "; break;
		case 5: if (b==0) cout << "nam nghin "; 
					else cout << "lam nghin "; break;
		case 6: cout << "sau nghin "; break;
		case 7: cout << "bay nghin "; break;
		case 8: cout << "tam nghin "; break;
		case 9: cout << "chin nghin "; break;
		case 0: if (x>10000) cout << "nghin "; break;
	}
	switch(d)
	{
		case 1: cout << "mot tram "; break;
		case 2: cout << "hai tram "; break;
		case 3: cout << "ba tram "; break;
		case 4: cout << "bon tram "; break;
		case 5: cout << "nam tram "; break;
		case 6: cout << "sau tram "; break;
		case 7: cout << "bay tram "; break;
		case 8: cout << "tam tram "; break;
		case 9: cout << "chin tram "; break;
		case 0: if (x>1000 && (f>0 || e>0)) cout << "khong tram "; break;
	}
	switch(e)
	{
		case 1: cout << "muoi "; break;
		case 2: cout << "hai muoi "; break;
		case 3: cout << "ba muoi "; break;
		case 4: cout << "bon muoi "; break;
		case 5: cout << "nam muoi "; break;
		case 6: cout << "sau muoi "; break;
		case 7: cout << "bay muoi "; break;
		case 8: cout << "tam muoi "; break;
		case 9: cout << "chin muoi "; break;
		case 0: if (x>100 && f>0) cout << "le "; break;
	}
	switch(f)
	{
		case 1: cout << "mot "; break;
		case 2: cout << "hai "; break;
		case 3: cout << "ba "; break;
		case 4: cout << "bon "; break;
		case 5: if (e==0) cout << "nam "; 
					else cout<<"lam "; break;
		case 6: cout << "sau "; break;
		case 7: cout << "bay "; break;
		case 8: cout << "tam "; break;
		case 9: cout << "chin "; break;
	}
	if (x==0) cout << "khong";
	
	cout << endl;
	
	return;
}

// Thoat chuong trinh
void exitProgram()
{
	cout << "Cam on ban da su dung chuong trinh, xin chao tam biet va hen gap lai, an phim bat ky de thoat !" << endl;
	system("pause");
	exit(0);
}
