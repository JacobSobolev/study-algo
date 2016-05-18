#include <iostream>
#include <vector>

using namespace std;

void lab9ex();
int** subsetSum(int n, vector<int> &s);
void printSubset(int **matrix, int i, int j, vector<int> &s);

void main() {
	
	lab9ex();
	system("pause");
}

void lab9ex()
{
	vector<int> s = { 2,1,13,5,3,21 };
	//int a[] = 
	int n = 9;
	int** matrix = subsetSum(n,s);
	int i1, j1;
	i1 = 5;
	j1 = 4;

	cout << "The  matrix is:" << endl;
	for (int i = 0; i < s.size()+1 ; i++) {

		for (int j = 0; j < n+1 ; j++)
			if (j == 0 || i==0) {
				if (j == 0 && i>0) {
					cout << s[i-1] << " \t|";
				}
				if (i == 0 && j>0) {
					cout << "("<< j-1<<")" << " \t";
				}
				if (i==0 && j==0) {
					cout <<" \t";
				}
			}
			
			else {
				cout << matrix[i - 1][j - 1] << "\t";
				
			}
			
		cout << endl;
	}
	cout << "The path for "<<i1 <<" ,"<< j1<< " :  "<< endl;
	if (i1 + 1 >s.size() || j1 + 1 > n) {
		cout << "invalid " << endl;
	}
	else {
		printSubset(matrix, i1, j1,s);
	}
	

}

int** subsetSum(int n, vector<int> &s)
{
	int** returnMatrix = new int*[s.size()];
	for (int i = 0; i < s.size(); ++i)
		returnMatrix[i] = new int[n];

	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j < n; j++)
			returnMatrix[i][j] = -1;

	for (int i = 0; i < s.size(); i++) {

		for (int j = 0; j < n; j++) {



			if (j == 0) {
				returnMatrix[i][j] = 0;
			}
			else if (j % s[i] == 0 && j / s[i] == 1) {
				returnMatrix[i][j] = 1;
			}
			else {
				returnMatrix[i][j] = 0;
			}


			if (i>0 && returnMatrix[i - 1][j ]>0) {
				returnMatrix[i][j] = returnMatrix[i - 1][j] ;
			}
			else {
				if (i>0 && j - s[i]>0 && returnMatrix[i - 1][j - s[i]]>0) {
					returnMatrix[i][j] = returnMatrix[i - 1][j - s[i]] + 1;
				}
				else if (i>0 && j - s[i]>0) {
					returnMatrix[i][j] = returnMatrix[i - 1][j];
				}
			}
			
		}
	}
		

	return returnMatrix;
}

void printSubset(int **matrix, int i, int j, vector<int> &s)
{
	if (matrix[i][j] > 0) {
		//cout << "yes" << endl;
		int tmp = matrix[i ][j ];
		while (tmp > 1) {
			while (i > 0 && matrix[i - 1][j]>0) {
				i--;
			}
			cout << s[i]<< " + ";
			j -= s[i];
			tmp = matrix[i ][j ];
			
		}

		while (i > 0 && matrix[i - 1][j]>0) {
			i--;
		}

		cout << s[i ] << endl;

		
	}
	else {
		cout << "none" << endl;
	}
}
