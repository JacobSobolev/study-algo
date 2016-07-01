#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <stack>


using namespace std;
HANDLE hCon;



enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

void SetColor(Color c) {
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}

int** calcMat(string &x,string &y,string &z);
void printCalcMat(int **mat,string &x,string &y);
bool ifMerge(int **mat,int i,int j);
void printPossibleZ(int **mat,int i,int j, string &x, string &y);

void main() {
	string x = "ab";
	string y = "saba";
	string z = "sababa";
	int i = x.size();
	int j = y.size();
	//int i = 2;
	//int j = 3;
	int** matrix = calcMat(x,y,z);
	bool res;

	cout << "The String are: " << endl;
	cout << "x: " << x <<endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl <<endl;
	cout << "The matrix is: " << endl;

	printCalcMat(matrix,x,y);
	res = ifMerge(matrix, i, j);
	cout << endl;
	cout << "check if merge i= " << i << " j= " << j << "  the answer: ";
	if (res) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	cout << "The possible z : " << endl;
	if (res) {
		printPossibleZ(matrix, i, j, x, y);
	}
	else {
		cout << "not merge" << endl;;
	}
	
	system("pause");
}

int ** calcMat(string & x, string & y, string & z)
{
	vector<int> vSort;
	int n = x.size() + 1;
	int m = y.size() + 1;
	int** returnMatrix = new int*[n];
	for (int i = 0; i < n; ++i)
		returnMatrix[i] = new int[m];

	for (int i = 0; i <n; i++)
		for (int j = 0; j < m; j++)
			returnMatrix[i][j] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) {
				returnMatrix[i][j] = 0;
			}
			else if (i == 0) {
				if (z[j-1] == y[j-1]) {
					returnMatrix[i][j] = returnMatrix[i][j-1] + 1;
				}
				else {
					returnMatrix[i][j] = returnMatrix[i][j - 1];
				}
			}
			else if (j == 0) {
				if (z[i - 1] == x[i - 1]) {
					returnMatrix[i][j] = returnMatrix[i-1][j] + 1;
				}
				else {
					returnMatrix[i][j] = returnMatrix[i - 1][j];
				}
			}
			else {


				if (z[i + j - 1] == x[i - 1] || z[i + j - 1] == y[j - 1]){
					
					vSort.clear();
					vSort.push_back(returnMatrix[i - 1][j]);
					vSort.push_back(returnMatrix[i][j - 1]);
					sort(vSort.begin(), vSort.end());
					returnMatrix[i][j] = vSort[1] + 1;
					
				}
				else {
					vSort.clear();
					vSort.push_back(returnMatrix[i - 1][j]);
					vSort.push_back(returnMatrix[i][j - 1]);
					sort(vSort.begin(), vSort.end());
					returnMatrix[i][j] = vSort[1];
					
				}
			}
		}
	}
		
			

		

	return returnMatrix;
}

void printCalcMat(int ** mat, string & x, string & y)
{
	int n = x.size() + 1;
	int m = y.size() + 1;

	for (int i = -1; i < n; i++) {
		for (int j = -1; j < m; j++) {
			if (i == -1 && j == -1) {
				cout << "\t\t";
			}
			else if (i == -1 && j >0) {
				cout << y[j - 1] << "\t";
			}
			else if (j == -1 && i > 0) {
				cout << x[i - 1] << "\t";
			}
			else if (i>-1 && j>-1) {
				if (i == 0 && j == 0)
					cout << "\t";
				cout << mat[i][j] << "\t";
			}


		}
		cout << endl;
	}
}

bool ifMerge(int ** mat, int i, int j)
{
	if (mat[i][j] == i + j)
		return true;
	return false;
}

void printPossibleZ(int ** mat, int i, int j, string & x, string & y)
{
	//2 stacks s1 for possible z and s2 for type latter bold or not
	stack<char> s1;
	stack<int> s2;
	int type;
	char c;
	while (i > 0 || j>0){
		if (i == 0) {
			s1.push(y[j - 1]);
			s2.push(0);
			j--;
		}
		else if (j == 0) {
			s1.push(x[i - 1]);
			s2.push(1);
			i--;
		}
		else {
			//check if x is higher
			if (mat[i - 1][j] > mat[i][j - 1]) {
				s1.push(x[i - 1]);
				s2.push(1);
				i--;
			}
			else {
				s1.push(y[j - 1]);
				s2.push(0);
				j--;
			}
		}

		
	}
	

	while (!s1.empty()) {
		c = s1.top();
		type = s2.top();
		if (type == 0) {
			SetColor(WHITE);
			
			
		}
		else {
			SetColor(RED);
			//cout <<"*"; 
		}
		cout << c;


		s1.pop();
		s2.pop();

	}

	SetColor(WHITE);
	cout << endl;
}


