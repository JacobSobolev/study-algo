#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define N 10
using namespace std;

void exe1();
int randPartition(int *a,int left,int right);
void swap(int *a, int *b);
void printArr(int *a, int n);
void initRandomArray(int *a,int n);
int randSelect(int *a,int low,int high,int i );
int randSelectIteration(int *a, int low, int high, int i);

void main() {
	exe1();
	system("pause");
}

void exe1()
{
	int index = 3;
	int arr[N] = { 0 };
	initRandomArray(arr, N);
	printArr(arr, N);
	int val = randSelectIteration(arr, 0, N-1, index);
	cout << "the value is: "<<val <<"of index  "<<index << endl;
	//printArr(arr, N);


}

int randPartition(int * a, int left, int right)
{
	int i, last = left;
	srand(time(NULL));
	i = rand() % (right-left+1) + left;
	if (left < right) {
		for ( i = left+1; i <= right; i++)
		{
			if (a[i] <= a[left])
				swap(a+(++last),a+i);

		}
		swap(a + left, a + last);
	}
	return last;
}

void swap(int * a, int * b)
{
	//if (&*a != &*b) {
	//	*a ^= *b;
	//	*b ^= *a;
	//	*a ^= *b;
	//}
	int temp = *b;
	*b = *a;
	*a = temp;
}

void printArr(int * a, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void initRandomArray(int * a,int n)
{
	srand(time(NULL));

	for (size_t i = 0; i < n; i++)
	{
		a[i] = rand() % (n * 100);
	}

}

int randSelect(int * a, int low, int high, int i)
{
	if (low == high)
		return a[low];
	int r = randPartition(a, low, high);
	int k = r - low + 1;
	if (i == k)
		return a[r];
	if (i < k)
		return randSelect(a, low, r - 1, i);
	else
		return randSelect(a, r+1, high, i - k);
	
}

int randSelectIteration(int * a, int low, int high, int i)
{
	int r= 0;
	int k = 0;
	while (low<= high) {
		if (low == high)
			return a[low];
		r = randPartition(a, low, high);
		int k = r - low + 1;
		if (i == k)
			return a[r];
		if (i < k) {
			high = r - 1;
		}
		else {
			low = r + 1;
			i = i - k;
		}
	}
}
