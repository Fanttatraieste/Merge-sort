#include <iostream>
using namespace std;

int tmp[100001];

void interclasare(int v[], int st, int dr, int m)
{
	int i = st, j = m + 1, k = 0;
	while (i <= m && j <= dr)
		if (v[i] < v[j])
			tmp[++k] = v[i++];
		else
			tmp[++k] = v[j++];
	while (i <= m)
		tmp[++k] = v[i++];
	while (j <= dr)
		tmp[++k] = v[j++];
	for (i = st, j = 1; i <= dr; i++, j++)
		v[i] = tmp[j];
}



void MergeSort(int v[], int st, int dr)
{
	if (st < dr)
	{
		int mij = (st + dr) / 2;
		MergeSort(v, st, mij);
		MergeSort(v, mij + 1, dr);
		interclasare(v, st, dr,mij);
	}
}

int main()
{
	int n, v[100001], i;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> v[i];
	MergeSort(v, 1, n);
	for (i = 1; i <= n; i++)
		cout << v[i] << " ";

	return 0;
}