/*
#include <bits/stdc++.h>
using namespace std;

void findPostOrderUtil(int pre[], int n, int minval, int maxval, int& preIndex)
{
	if (preIndex == n)
		return;

	if (pre[preIndex] < minval || pre[preIndex] > maxval) 
    {
		return;
	}

	int val = pre[preIndex];
	preIndex++;

	findPostOrderUtil(pre, n, minval, val, preIndex);

	findPostOrderUtil(pre, n, val, maxval, preIndex);

	cout << val << " ";
}

void findPostOrder(int pre[], int n)
{
	int preIndex = 0;

	findPostOrderUtil(pre, n, INT_MIN, INT_MAX, preIndex);
}

int main()
{
	int pre[] = { 40, 30, 35, 80, 100 };

	int n = sizeof(pre) / sizeof(pre[0]);

	findPostOrder(pre, n);
	return 0;
}
*/

#include <iostream>
using namespace std;

void getPostOrderBST(int pre[], int N)
{
	int pivotPoint = 0;

	for(int i = 1; i < N; i++)
	{
		if (pre[0] <= pre[i])
		{
			pivotPoint = i;
			break;
		}
	}

	for(int i = pivotPoint - 1; i > 0; i--)
	{
		cout << pre[i] << " ";
	}

	for(int i = N - 1; i >= pivotPoint; i--)
	{
		cout << pre[i] << " ";
	}
	cout << pre[0];
}

int main()
{
	int pre[] = { 40, 30, 32, 35, 80, 90, 100, 120 };
	int N = 8;
	
	getPostOrderBST(pre, N);
	
	return 0;
}
