#include <bits/stdc++.h>
#define MaxQueue 10000
#define MaxN 100
using namespace std;

struct Queue {
    int F, L;
    int E[MaxQueue];
};

Queue Q;
int N, U, V;
int A[MaxN][MaxN];
int Checked[MaxQueue];


void Init(Queue& Q)
{
    Q.F = 0;
    Q.L = -1;
}

int Empty(Queue Q)
{
    return Q.F > Q.L;
}

void Add(int x, Queue& Q)
{
    if (Q.L == MaxQueue) {
        return;
    }
    Q.L++;
    Q.E[Q.L] = x;
}

void Remove(int& x, Queue& Q)
{
    if (Empty(Q)) {
        return;
    }
    x = Q.E[Q.F];
    Q.F++;
}

void Read_File()
{
	cin >> N >> U >> V;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			cin >> A[i][j];
}

void Process()
{
    int i, j;
    int Pre[MaxQueue], P[MaxQueue];
    Init(Q);
	
    for (i = 1; i <= N; i++) {
        Checked[i] = 0;
        Pre[i] = U;
    }
	
    Add(U, Q);
    Checked[U] = 1;
	
    while (!Empty(Q) && !Checked[V]) {
        Remove(i, Q);
        for (j = 1; j <= N; j++)
			if (!Checked[j] && A[i][j] == 1)
			{
				Add(j, Q);
				Checked[j] = 1;
				Pre[j] = i;
				if (j == V)
					break;
			}
    }
	
    if (!Checked[V])
        cout <<"NO PATH";
    else {
        i = 0;
        P[0] = V;
        while (P[i] != U) {
            i++;
            P[i] = Pre[P[i - 1]];
        }
        for (int j = i; j > 0; j--)
            cout << P[j] << "=>";
        cout << V;
    }
}

int main()
{
	freopen("MAZE.INP", "r", stdin);
	freopen("MAZE.OUT", "w", stdout);
    Read_File();
    Process();
}
