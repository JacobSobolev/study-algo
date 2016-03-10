#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define N 10000
#define M 10
using namespace std;

void ex1();
void initArray(int *a);
void shuffleArray(int *a);
int minElement(int *a, int n);
void printArr(int *a,int n);

void ex2();
void initRandomArray(int *a);
void minMaxIteration(int *a,int n,int *max,int *min);
void minMaxRecursion(int *a,int n,int *max,int *min);


void main() {
	//ex1();
	ex2();
	system("pause");
	
}

void ex1()
{
	int k = 100;
	int arr[N] = { 0 };
	int sum = 0;

	initArray(arr);
	shuffleArray(arr);
	//printArr(arr, N);
	for (size_t i = 0; i < k; i++)
	{
		shuffleArray(arr);
		sum += minElement(arr, N);
	}
	cout << "the avg is:" << (float)sum / k;
}

void initArray(int * a)
{
	for (size_t i = 0; i < N; i++)
	{
		a[i] = i;
	}
}

void shuffleArray(int * a)
{
	srand(time(NULL));
	int j,n,temp;
	

	n = N-1;
	for (size_t i = n; i > 0; i--,n--)
	{
		j = rand() % n;

		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	

}

int minElement(int *a,int n)
{
	int min = a[0];
	int sum = 0;
	for (size_t i = 1; i < n-2; i++)
	{
		if (a[i] < min) {
			min = a[i];
			sum++;
		}
	}
	return sum;
		
}

void printArr(int * a, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void ex2()
{
	int arr[M] = { 0 };
	initRandomArray(arr);
	printArr(arr, M);
	int max, min;
	//minMaxIteration(arr,M,&max,&min);
	minMaxRecursion(arr, M, &max, &min);
	cout << "the min is: " << min << "the max is: " << max << endl; ;
}

void initRandomArray(int * a)
{
	srand(time(NULL));
	int n = M ;
	for (size_t i = 0; i < M; i++)
	{
		a[i] = rand() % (n * 100);
	}
	
}

void minMaxIteration(int * a, int n, int * max, int * min)
{
	if (a[0] > a[1]) {
		*max = a[0];
		*min = a[1];
	}
	else {
		*max = a[1];
		*min = a[0];
	}
	for (size_t i = 2; i < n-1; i+=2)
	{
		if (a[i] > a[i+1]) {
			if (a[i] > *max) {
				*max = a[i];
			}
			if (a[i + 1] < *min) {
				*min = a[i + 1];
			}
		}
		else  {
			if (a[i+1] > *max) {
				*max = a[i+1];
			}
			if (a[i ] < *min) {
				*min = a[i];
			}
		}
	}
}

void minMaxRecursion(int * a, int n, int * max, int * min)
{
	if (n == 2) {
		if (a[0] > a[1]) {
			*max = a[0];
			*min = a[1];
		}
		else {
			*max = a[1];
			*min = a[0];
		}
		return;
	}
	minMaxRecursion(a, n / 2, max, min);
	if (n>2) {
		if (a[n - 2] > a[n - 1]) {
			if (a[n - 2] > *max) {
				*max = a[n - 2];
			}
			if (a[n - 1] < *min) {
				*min = a[n - 1];
			}

		}
		else {
			if (a[n - 1] > *max) {
				*max = a[n - 1];
			}
			if (a[n - 2] < *min) {
				*min = a[n - 2];
			}
		}
		return;
	}
	minMaxRecursion(a + n / 2 + 1, n / 2, max, min);
	if (n>2) {
		if (a[n - 2] > a[n - 1]) {
			if (a[n - 2] > *max) {
				*max = a[n - 2];
			}
			if (a[n - 1] < *min) {
				*min = a[n - 1];
			}

		}
		else {
			if (a[n - 1] > *max) {
				*max = a[n - 1];
			}
			if (a[n - 2] < *min) {
				*min = a[n - 2];
			}
		}
		return;
	}

	
	



}


