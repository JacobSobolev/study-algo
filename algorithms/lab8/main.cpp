#include <iostream>
#include <stack>

#define N 4

using namespace std;

void lab8ex1();
int ** mountion(int matrix[][N], int &maxI, int&maxJ);
void printPathMountion(int originalMatrix[][N], int ** sumMatrix, int &maxI, int maxJ);

void lab8ex2();

void main() {

	//lab8ex1();
	lab8ex2();
	system("pause");

}

void lab8ex1()
{
	/*

	An={

	An = a[0][0]   , i=j=0;

	An = max {a[i][j-1] , a[i-1][j]} , i>0 , j>0

	}

	*/

	int matrix[][N] = { { 5,0,0,0 },
						{ 6,4,0,0 }, 
						{ 5,1,9,0 }, 
						{ 3,5,4,3 }, };
	int maxI = 0;
	int maxJ = 0;
	cout << "The matrix is:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	int **newMatrix = mountion(matrix, maxI,maxJ);
	cout << "The sum matrix is:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
			cout << newMatrix[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	cout << "the max sum is:" << newMatrix[maxI][maxJ] << endl << endl;
	
	printPathMountion(matrix, newMatrix,maxI,maxJ);


}

int ** mountion(int matrix[][N], int &maxI, int&maxJ)
{

	/*
	complexity = O(n^2)

	*/

	int** returnMatrix = new int*[N];
	int sumParentRight = 0;
	int sumParentLeft = 0;
	for (int i = 0; i < N; ++i)
		returnMatrix[i] = new int[N];


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			returnMatrix[i][j] = 0;

	if (N > 0) {
		returnMatrix[0][0] = matrix[0][0];
		maxI = 0;
		maxJ = 0;
		if (N > 1) {

			returnMatrix[1][0] = returnMatrix[0][0] + matrix[1][0];
			returnMatrix[1][1] = returnMatrix[0][0] + matrix[1][1];

			for (int i = 2; i < N; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					
					if (j == i ) {
						returnMatrix[i][j] = returnMatrix[i - 1][j - 1] + matrix[i][j];
					}
					else {
						sumParentRight = returnMatrix[i - 1][j] + matrix[i][j];
						sumParentLeft = returnMatrix[i - 1][j - 1] + matrix[i][j];
						if (sumParentRight > sumParentLeft) {
							returnMatrix[i][j] = sumParentRight;
						}
						else {
							returnMatrix[i][j] = sumParentLeft;
						}
					}

				}
			}

			for (int i = 0; i < N; i++)
			{
				if (returnMatrix[N - 1][i] > returnMatrix[maxI][maxJ]) {
					maxI = N - 1;
					maxJ = i;
				}
			}
		}
	}

	return returnMatrix;
}

void printPathMountion(int originalMatrix[][N], int ** sumMatrix,int &maxI,int maxJ)
{
	stack<int> s1;
	int i, j;
	int maxRight, maxLeft;
	i = maxI;
	j = maxJ;
	maxRight = maxLeft = 0;


	s1.push(originalMatrix[maxI][maxJ]);
	while (i > 0 || j > 0) {
		if (i == j) {
			s1.push(originalMatrix[i-1][j - 1]);
			j--;
			i--;
		}
		else if (j == 0) {
			s1.push(originalMatrix[i - 1][j]);
			i--;
		}
		else {


			maxRight = sumMatrix[i - 1][j];
			maxLeft = sumMatrix[i-1][j - 1];
			if (maxRight > maxLeft) {
				s1.push(originalMatrix[i - 1][j]);
				i--;
			}
			else {
				s1.push(originalMatrix[i-1][j - 1]);
				j--;
			}
		}

	}


	cout << "The path is:" << endl;
	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}


	cout << endl;

}

void lab8ex2()
{

}
