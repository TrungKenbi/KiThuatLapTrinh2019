#include <bits/stdc++.h>
using namespace std;

// Tim kiem tuan tu
int linearSearch(int arr[], int n, int x);

// Tim kiem tuan tu cai tien
int linearSearchPro(int arr[], int n, int x);

// Kiem tra mang tang dan
bool checkArrayIsSort(int arr[], int n);

// Tim kiem nhi phan
int binarySearch(int arr[], int left, int right, int x);

// Sap xep chon
void selectionSort(int arr[], int n);

// Sap xep chen
void insertionSort(int arr[], int n);

// Sap xep doi cho truc tiep
void interchangeSort(int arr[], int n);

// Sap xep noi bot
void bubbleSort(int arr[], int n) ;

// Sap xep tron
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

// Sap xep nhanh
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

// In mang da nhap vao
void printArray(int arr[], int n);

void exitProgram();

int main()
{
	
	int select; //Bien de chon chuc nang
	bool reload =  true; // Bien lap lai menu
	
	system("color 3");  //Doi mau chu 
	
	cout << "Nhap so phan tu cua mang: ";
	int n, x, res; cin >> n;
	int arr[n + 1];
	cout << "Nhap cac phan tu cua mang:" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	do {
		
		/* In giao dien nguoi dung */
		system("cls");
		cout << "\t\t\tCHUONG TRINH TIM KIEM, SAP XEP MANG" << endl;
		cout << "------------------------------------"
			 << "------------------------------------" << endl;
		cout << "Mang la nhap la: ";
		printArray(arr, n);
		cout << endl;	
		cout << "Moi chon chuc nang: " << endl;
		
		cout << "1. Tim kiem tuan tu" << endl;
		cout << "2. Tim kiem tuan tu cai tien" << endl;
		cout << "3. Tim kiem nhi phan" << endl;
		
		cout << "4. Sap xep chon" << endl;
		cout << "5. Sap xep chen" << endl;
		cout << "6. Sap xep doi cho" << endl;
		cout << "7. Sap xep noi bot" << endl;
		cout << "8. Sap xep tron" << endl;
		cout << "9. Sap xep nhanh" << endl;
		
		cout << "..." << endl;
		cout << "0. Thoat" << endl;
		cout << endl;
		/* End UI */
		
		cin >> select; //Nguoi dung chon chuc nang
		
		/* Xu ly chuc nang nguoi dung da chon */
		switch (select) {
			/* Tung truong hop duoc dat trong case */
			case 1:
				cout << "Moi nhap so can tim kiem: ";
				cin >> x;
				res = linearSearch(arr, n, x);
				if (res == -1)
					cout << "Khong tim thay";
				else
					cout << "Tim thay o vi tri thu: " << (res + 1);
				cout << endl;
				system("pause");
				break;
			case 2:
				cout << "Moi nhap so can tim kiem: ";
				cin >> x;
				res = linearSearchPro(arr, n, x);
				if (res == -1)
					cout << "Khong tim thay";
				else
					cout << "Tim thay o vi tri thu: " << (res + 1);
				cout << endl;
				system("pause");
				break;
			case 3:
				if (!checkArrayIsSort(arr, n)) {
					cout << "Mang chua duoc sap xep tang dan !";
					break;
				}
				cout << "Moi nhap so can tim kiem: ";
				cin >> x;
				res = binarySearch(arr, 0, n - 1, x);
				if (res == -1)
					cout << "Khong tim thay";
				else
					cout << "Tim thay o vi tri thu: " << (res + 1);
				cout << endl;
				system("pause");
				break;
			
			case 4:
				selectionSort(arr, n);
				cout << "Mang da sap xep la: ";
				printArray(arr, n);
				cout << endl;
				system("pause");
				break;
			case 5:
				insertionSort(arr, n);
				cout << "Mang da sap xep la: ";
				printArray(arr, n);
				cout << endl;
				system("pause");
				break;
			
			case 6:
				interchangeSort(arr, n);
				cout << "Mang da sap xep la: ";
				printArray(arr, n);
				cout << endl;
				system("pause");
				break;
			
			case 7:
				bubbleSort(arr, n);
				cout << "Mang da sap xep la: ";
				printArray(arr, n);
				cout << endl;
				system("pause");
				break;
			
			case 8:
				mergeSort(arr, 0, n - 1);
				cout << "Mang da sap xep la: ";
				printArray(arr, n);
				cout << endl;
				system("pause");
				break;
				
			case 9:
				quickSort(arr, 0, n - 1);
				cout << "Mang da sap xep la: ";
				printArray(arr, n);
				cout << endl;
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

// Tim kiem tuan tu
int linearSearch(int arr[], int n, int x) 
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i; 
    return -1; 
}

// Tim kiem tuan tu cai tien
int linearSearchPro(int arr[], int n, int x) 
{
	int k = 0;
	arr[n] = x;
	while(arr[k] != x)
		k++;
	if (k < n)
		return k;
	return -1;
}

// Kiem tra mang tang dan
bool checkArrayIsSort(int arr[], int n)
{
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1])
			return false;
	}
	return true;
}

// Tim kiem nhi phan
int binarySearch(int arr[], int left, int right, int x)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

// Sap xep chon
void selectionSort(int arr[], int n)  
{
    int i, j, minIndex;
    for (i = 0; i < n-1; i++)  
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[minIndex]) 
            minIndex = j;
        swap(arr[minIndex], arr[i]);
    }  
}

// Sap xep chen
void insertionSort(int arr[], int n)  
{
    int i, key, j;  
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; 
    }
}

// Sap xep doi cho truc tiep
void interchangeSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
}

// Sap xep noi bot
void bubbleSort(int arr[], int n) 
{
   bool swapped;
   for (int i = 0; i < n - 1; i++) 
   {
    	swapped = false; 
    	for (int j = 0; j < n - i - 1; j++) 
    	{
    		if (arr[j] > arr[j + 1]) 
        	{
        		swap(arr[j], arr[j + 1]); 
        		swapped = true; 
        	}
    	}
		if (swapped == false)
			break; 
   }
}

// Tron mang
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    int L[n1], R[n2]; 
  

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 

    i = 0;
    j = 0; 
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    {
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

// Sap xep tron
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    {
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    }
}

// Sap xep nhanh
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)  
    {
        if (arr[j] < pivot)  
        {  
            i++;
            swap(arr[i], arr[j]);  
        }  
    }  
    swap(arr[i + 1], arr[high]);  
    return (i + 1);  
}

// Sap xep nhanh
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {
        int pi = partition(arr, low, high);  
 
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
} 

// In mang da nhap vao
void printArray(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void exitProgram()
{
	cout << "Cam on ban da su dung chuong trinh, xin chao tam biet va hen gap lai, an phim bat ky de thoat !" << endl;
	system("pause");
	exit(0);
}
