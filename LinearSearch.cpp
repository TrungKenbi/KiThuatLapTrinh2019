#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int x) 
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i; 
    return -1; 
}

int main()
{
	int n, x, res; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> x;
	res = linearSearch(arr, n, x);
	if (res == -1)
		cout << "Khong tim thay";
	else
		cout << "Tim thay o vi tri thu: " << (res + 1);
	return 0;
}
