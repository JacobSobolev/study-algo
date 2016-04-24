#include <iostream>
#include <stack>


#define N 3
using namespace std;

void lab7ex4();
int** turtle(int matrix[][N] ,int &maxSum);
void printPath(int originalMat[][N],int **matrix);


void main() {
	lab7ex4();
	system("pause");
}

void lab7ex4()
{
	/*

	An={

		An = a[0][0]   , i=j=0;

		An = max {a[i][j-1] , a[i-1][j]} , i>0 , j>0

	}

	*/
	
	int matrix[N][N] = { {1,7,10},{5,5,2},{8,15,3} };
	int maxSum = 0;
	cout << "The matrix is:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	int **newMatrix = turtle(matrix,maxSum);
	cout << "The sum matrix is:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << newMatrix[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	cout << "the max sum is:" << maxSum << endl << endl;
	printPath(matrix,newMatrix);


}

int** turtle(int matrix[][N], int &maxSum)
{

	/*
		complexity = O(n^2)
		
	*/
	int** returnMatrix = new int*[N];
	int maxRight = 0;
	int maxDown = 0;
	for (int i = 0; i < N; ++i)
		returnMatrix[i] = new int[N];


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			returnMatrix[i][j] = 0;
		
	
	returnMatrix[0][0] = matrix[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0 && j>0) {
				returnMatrix[i][j] = returnMatrix[i][j-1] + matrix[i][j];
			}
			else if (i > 0 && j == 0) {
				returnMatrix[i][j] = returnMatrix[i-1][j] + matrix[i][j];
			}
			else if (i>0 && j >0) {
				maxRight = returnMatrix[i][j - 1] + matrix[i][j];
				maxDown = returnMatrix[i - 1][j] + matrix[i][j];
				if (maxRight > maxDown) 
					returnMatrix[i][j] = maxRight;
				else 
					returnMatrix[i][j] = maxDown;
				
			}
		}
	}
	maxSum = returnMatrix[N-1][N-1];
	return returnMatrix;
}



void printPath(int originalMat[][N], int **matrix)
{
	stack<int> s1;
	int i, j;
	int maxUp, maxLeft;
	i = j = N - 1;
	maxUp = maxLeft = 0;

	s1.push(originalMat[N - 1][N - 1]);
	while (i > 0 || j > 0) {
		if (i == 0) {
			s1.push(originalMat[i][j - 1]);
			j--;
		}
		else if (j == 0) {
			s1.push(originalMat[i - 1][j]);
			i--;
		}
		else {
			maxUp = matrix[i - 1][j];
			maxLeft = matrix[i][j - 1];
			if (maxUp > maxLeft) {
				s1.push(originalMat[i-1][j]);
				i--;
			}
			else {
				s1.push(originalMat[i][j-1]);
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
