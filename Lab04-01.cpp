#include <bits/stdc++.h>
using namespace std;

/* Queue */
#define MaxQueue 1000

struct Queue {
    int First;
    int Last;
    int Element[MaxQueue];
};


void Create(Queue& Q)
{
    Q.First = 0;
    Q.Last = -1;
}

bool Empty(Queue Q)
{
    return Q.First > Q.Last;
}

void Add(Queue& Q, int x)
{
    if (Q.Last == MaxQueue - 1)
        return;
    else {
        Q.Last++;
        Q.Element[Q.Last] = x;
    }
}

void Remove(Queue& Q)
{
    if (Empty(Q))
        return;
    Q.Element[Q.First] = false;
    Q.First++;
}

int Front(Queue& Q)
{
	return Q.Element[Q.First];
}

int Back(Queue& Q)
{
	return Q.Element[Q.Last];
}
/* Queue End  */

int main()
{
	// Khoi tao queue
    Queue binaryList;
    Create(binaryList);
    // -------------
    
    float x;  cin >> x;
    int a; float b;
    do {
        x *= 2;
        a = (int)x;
        b = x - a;
        x = b;
        Add(binaryList, (a != 0)); // Them 1 phan tu vao queue
    } while (b != 0.0);

    cout << "0.";
    while (!Empty(binaryList)) { //Duyet toan bo queue
        cout << Front(binaryList); // Lay phan tu dau tien
        Remove(binaryList); // Xoa phan tu dau tien khoi queue
    }
}
