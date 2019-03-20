#include <iostream>
#include <vector> 
#include <malloc.h>
using namespace std;

/* Config student information */
const string fullname = "Duong Le Phuoc Trung";
const string className = "D18PM01";
const string studentCode =  "1824801030053";

/* Khoi tao con tro va bien dong, cot*/
int **p,
	row,
	col;

void nhapMaTran();
void xuatMaTran();
void tongTrenHang();
void phanTuChan();
bool checkMaTran();
void showError();
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
		cout << "\t\t\tCHUONG TRINH MA TRAN" << endl;
		cout << "------------------------------------"
			 << "------------------------------------" << endl;
		cout << "Moi chon chuc nang: " << endl;
		cout << "1. Nhap ma tran" << endl;
		cout << "2. Xuat ma tran" << endl;
		cout << "3. Tinh tong phan tu tren moi hang" << endl;
		cout << "4. In ra cac phan tu chan tren moi hang" << endl;
		cout << "..." << endl;
		cout << "0. Thoat" << endl;
		cout << endl;
		/* End UI */
		
		cin >> select; //Nguoi dung chon chuc nang
		
		
		/* Xu ly chuc nang nguoi dung da chon */
		switch (select) {
			/* Tung truong hop duoc dat trong case */
			case 1:
				nhapMaTran();
				system("pause");
				break;
			case 2:
				xuatMaTran();
				system("pause");
				break;
			case 3:
				tongTrenHang();
				system("pause");
				break;
			case 4:
				phanTuChan();
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

void nhapMaTran()
{
	/* Nhap va kiem tra du lieu dau vao */
	bool checkInput[2] = {true, true};
	string nameInput[2] = {"dong", "cot"};
	
	// Nhap cot va hang, kiem tra
	for(int i = 0; i < 2; i++)
	{
		int *input = i == 0 ? &row : &col; // Con tro, tro den bien cot hoac hang
		
		do {
			if (!checkInput[i]) // Neu nhap du lieu sai thi bao loi
				cout << "Xin loi, ban nhap so " << nameInput[i] << " khong hop le, vui long nhap lai: ";
			else
				cout << "Moi nhap so " << nameInput[i] << ": ";
			cin >> (*input);
			if (*input <= 0) // Du lieu sai thi gan bien bao loi
				checkInput[i] = false;
		} while (*input <= 0); // Lap lai khi du lieu bi sai
	}
	/* End */
	
	
	cout << "Moi nhap cac phan tu trong ma tran: " << endl;
	
	/* Khoi tao so luong o nho cho con tro */
	p = (int**)malloc(row * sizeof(int));

	for (int i = 0; i < row; i++) {
		p[i] = (int*)malloc(col * sizeof(int));
	}
	/* End khoi tao */
	
	/* Nhap phan tu thong qua con tro */
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << "Nhap phan tu a[" << i << "][" << j << "] = ";
			cin >> *(*(p + i) + j);
		}
	}
	/* End poiter */
	
	cout << "Nhap mang thanh cong !!!" << endl;
}

void xuatMaTran()
{
	// Kiem tra ma tran da duoc nhap chua ?
	if (!checkMaTran())
	{
		showError();
		return;
	}
	
	cout << "Ma tran da nhap la: " << endl;
	for (int i = 1; i < col * 2 + 2; i++) 
		cout << "-";
	cout << endl;
	// Lap qua toan bo ma tran
	for (int i = 0; i < row; i++) {
		cout << " ";
		for (int j = 0; j < col; j++) {
			cout << *(*(p + i) + j) << " "; // Xuat mang bang con tro, tang dan dia chi cua con tro.
		}
		cout << endl;
	}
	for (int i = 1; i < col * 2 + 2; i++) 
		cout << "-";
	cout << endl;
}

void tongTrenHang()
{
	// Kiem tra ma tran da duoc nhap chua ?
	if (!checkMaTran())
	{
		showError();
		return;
	}
	
	for (int i = 0; i < row; i++) {
		int s = 0;
		for (int j = 0; j < col; j++) {
			s += *(*(p + i) + j);
		}
		printf("Tong tren hang %d la: %d \n", i, s);
	}	
}

void phanTuChan()
{
	// Kiem tra ma tran da duoc nhap chua ?
	if (!checkMaTran())
	{
		showError();
		return;
	}
	
	for (int i = 0; i < row; i++) {
		vector<int> arrayChan;
		for (int j = 0; j < col; j++) {
			if ((*(*(p + i) + j)) % 2 == 0) //Neu a[i][j] la so chan thi them vao arrayChan
				arrayChan.push_back(*(*(p + i) + j));
		}
		// Kiem tra xem hang co phan tu chan nao hay khong
		if (arrayChan.size())
		{
			cout << "Phan tu chan tren hang " << i << " la: ";
			/* In ra tat ca cac phan tu da duoc luu truoc do */
			for(vector<int>::iterator it = arrayChan.begin(); it != arrayChan.end(); it++)
				cout << *it << " ";
			cout << endl;
		} else
			// Neu khong co phan tu chan nao thi in ra: 
			cout << "Hang " << i << " khong co phan tu chan nao !" << endl;
	}
}

// Kiem tra ma tran da duoc nhap chua ?
bool checkMaTran() 
{
	if (row == 0 || col == 0) // Neu cot hoac hang bang khong thi ma tran loi
		return false;
	return true;
}

void showError() 
{
	cout << "Ma tran chua co du lieu, vui long quay lai menu va nhap ma tran !" << endl;
}

void exitProgram()
{
	cout << "Cam on ban da su dung chuong trinh, xin chao tam biet va hen gap lai, an phim bat ky de thoat !" << endl;
	system("pause");
	exit(0);
}
