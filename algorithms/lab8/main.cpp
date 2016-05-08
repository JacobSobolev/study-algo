#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

#define N 4

using namespace std;

void lab8ex1();
int ** mountion(int matrix[][N], int &maxI, int&maxJ);
void printPathMountion(int originalMatrix[][N], int ** sumMatrix, int &maxI, int maxJ);

void lab8ex2();
int eDist(string &s1, string &s2,int **matrix);

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
	/*
				0		,	i=j=0
				s[i,j-1]+1	,	i=0, j>0
	s[i,j] =	s[i-1,j]+1	,	i>0, j=0
				min(s[i-1,j] + 1,s[i-1,j-1],s[i,j-1]+1 )	,	i>0,j>0 , st1[j]==st2[i]
				min(s[i-1,j],s[i-1,j-1],s[i,j-1])			,	i>0,j>0 , st1[j]!=st2[i]

	*/

	string s1 = "Saturday";
	string s2 = "Sunday";
	int** matrix = new int*[s2.size()+1];
	for (int i = 0; i < s2.size()+1; i++)
	{
		matrix[i] = new int[s1.size()+1];
	}

	for (int i = 0; i < s2.size()+1; i++)
	{
		for (int j = 0; j < s1.size()+1; j++)
		{
			matrix[i][j] = 0;
		}
	}


	int num = eDist(s1, s2, matrix);


	for (int i = 0; i < s2.size()+1; i++)
	{
		for (int j = 0; j < s1.size()+1; j++)
		{
			cout <<"\t"<< matrix[i][j] ;
		}
		cout << endl;
	}
}

int eDist(string & s1, string & s2, int ** matrix)
{
	int lowest = 0;
	vector<int> vSort;
	for (int i = 0; i < s2.size()+1; i++)
	{
		for (int j = 0; j < s1.size()+1; j++)
		{
			if (i == 0 && j==0) {
				matrix[i][j] = 0;
			}
			else if (i == 0 && j > 0 ) {
				matrix[i][j] = matrix[i][j-1] + 1 ;
			}
			else if (i > 0 && j == 0) {
				matrix[i][j] = matrix[i-1][j] + 1;
			}
			else {
				if (s1.at(j-1) == s2.at(i-1)) {
					vSort.clear();
					vSort.push_back(matrix[i-1][j]+1);
					vSort.push_back(matrix[i - 1][j-1]);
					vSort.push_back(matrix[i][j - 1]+1);
					sort(vSort.begin(), vSort.end());
					matrix[i][j] = vSort[0];
					
				}
				else {
					vSort.clear();
					vSort.push_back(matrix[i - 1][j]);
					vSort.push_back(matrix[i - 1][j - 1]);
					vSort.push_back(matrix[i][j - 1]);
					sort(vSort.begin(), vSort.end());
					matrix[i][j] = vSort[0] + 1;
				}
			}

			//matrix[i][j] = 0;
			
		}
	}
	return 0;
}

