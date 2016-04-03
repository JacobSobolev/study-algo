#include <iostream>
#include <vector>
using namespace std;



void printArr(int *a, int n);

void lab5ex1();
int findMember(int *arr,int size);

void lab5ex2();
void maxSum(int *a, int n);

void main() {

	//lab5ex1();
	lab5ex2();
	system("pause");
}

void printArr(int * a, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void lab5ex1()
{
	//int arr[] = {1,2,1,3,1,4,1,5,1,6};
	//int arr[] = { 2,1,3,1,4,1,5,1,6,1 };
	int arr[] = { 1,2,1,1,1,4,1,5,7,6};
	printArr(arr, sizeof(arr) / sizeof(int));
	int k = findMember(arr, sizeof(arr) / sizeof(int));
	cout << "the that is more than n times is:" << arr[k] << endl;
	

}

int findMember(int * arr, int size)
{
	int majI, count;
	majI = 0;
	count = 1;
	for (int i = 1; i < size; i++)
	{
		if (count == 0) {
			majI = i;
			count = 1;
		}
		else {
			if (arr[majI] == arr[i])
				count++;
			else
				count--;
			if (count > 1)
				return majI;
		}
	}
	if (arr[0] == arr[2])
		return 0;
	if (arr[1] == arr[3])
		return 1;
	
}

void lab5ex2()
{
	//int arr[] = {4,-6,5,-6,10,-5,3};
	int arr[] = { 1,7,-13,3,10,-8,3 };
	int sumArrSize = 0;
	printArr(arr, sizeof(arr) / sizeof(int));
	maxSum(arr, sizeof(arr) / sizeof(int));
	
	
}

void maxSum(int * a, int n)
{
	int *newArr = new int[n * 2];
	int j = 0;
	int firstNeg = -1;
	int maxSum, maxSuffix, iMax, jMax, iSuffix;
	maxSum = maxSuffix = iMax = jMax = iSuffix = 0;
	for (int i = 0; i <2*n; i++,j++)
	{
		if (j == n)
			j = 0;
		newArr[i] = a[j];
	}
	for (int i = 0; i < 2*n; i++)
	{
		
		maxSuffix += newArr[i];
		if (maxSuffix > maxSum) {
			maxSum = maxSuffix;
			iMax = iSuffix;
			jMax = i;
		}

		if (maxSuffix < 0) {
			if (firstNeg == -1) {
				firstNeg = i;
			}
			maxSuffix = 0;
			iSuffix = i + 1;
		}

		if (firstNeg!=-1 && i==n+firstNeg-1) {
			break;
		}

	}
	cout << "the max sum is:\n";
	for (int i = iMax; i <= jMax; i++)
	{
		cout << newArr[i] << " ";
		
	}
	cout << endl;
	
}
