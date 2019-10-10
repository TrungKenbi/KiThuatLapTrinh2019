#include<bits/stdc++.h>
using namespace std;

/*
*	Kiem tra mang da duoc sap xep tang dan hay chua ?
*/
bool checkArrayIsSort(int arr[], int n)
{
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1])
			return false;
	}
	return true;
}

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

int main()
{
	try {
		int n, x, res; cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		
		if (!checkArrayIsSort(arr, n))
			throw "Mang chua duoc sap xep tang dan !";
		
		cin >> x;
		
		res = binarySearch(arr, 0, n - 1, x);
		
		if (res == -1)
			cout << "Khong tim thay";
		else
			cout << "Tim thay o vi tri thu: " << (res + 1);
	} catch (const char* exception) {
		cerr << "[ERROR]: " << exception << endl;
	}
		
	return 0;
}
