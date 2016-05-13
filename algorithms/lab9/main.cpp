#include <iostream>
#include <vector>

using namespace std;

void lab9ex();
int** subsetSum(vector<int> &v,int s);

void main() {
	
	lab9ex();
	system("pause");
}

void lab9ex()
{
	vector<int> v = { 2,1,13,5,3,21 };
	//int a[] = 
	int s = 9;
	int** matrix = subsetSum(v, s);

	cout << "The  matrix is:" << endl;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < s; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}


}

int** subsetSum(vector<int> &v, int s)
{
	int** returnMatrix = new int*[v.size()];
	for (int i = 0; i < v.size(); ++i)
		returnMatrix[i] = new int[s];

	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < s; j++)
			returnMatrix[i][j] = -1;

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < s; j++) {

			
			if (j == 0) {
				returnMatrix[i][j] = 0;
			}
			else if (j % v[i] == 0) {
				returnMatrix[i][j] = 1;
			}

			if (i>0 && j - v[i]>0 && returnMatrix[i - 1][j - v[i]]>0) {
				returnMatrix[i][j] = returnMatrix[i - 1][j - v[i]] + 1;
			}
			else if (i>0 && j - v[i]>0) {
				returnMatrix[i][j] = returnMatrix[i - 1][j];
			}
			

			if (i > 0 && returnMatrix[i][j] != -1 && returnMatrix[i - 1][j] > 0) {
				returnMatrix[i][j] = returnMatrix[i - 1][j];
			}
			
			
		}
	}
		

	return returnMatrix;
}
