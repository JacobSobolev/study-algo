//316898162 307802769

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
bool parseData(ifstream * readFile, vector< vector<int> > &mat);
vector< vector<int> > buildSubSqr(vector< vector<int> > &mat);
vector<int> findMaxCount(vector< vector<int> > &sq);


int main(int argc, char *argv[]) {

	ofstream outFile;
	outFile.open("Out.txt");
	ofstream idFile;
	idFile.open("ID.txt");
	idFile << "3168898162 307802769\n";


	if (argc == 1) {
		outFile << "please input the input file to the program's first argument ";
	}
	else {
		ifstream readFile;
		readFile.open(argv[1]);
		if (readFile.is_open()) {

			vector< vector<int> > mat;
			if (parseData(&readFile, mat)) {
				vector< vector<int> > sq = buildSubSqr(mat);
				vector<int> maxNcount = findMaxCount(sq);
				//for (int i = 0; i < sq.size(); i++) {
				//	for (int j = 0; j < sq[i].size(); j++) {
				//		cout << sq[i][j] << " ";
				//	}
				//	cout << endl;
				//}
				//cout << maxNcount[0] << " " << maxNcount[1] << endl;
				outFile << maxNcount[0] << ", " << maxNcount[1];
				
			}
			else {
				outFile << "incorrent file structer ";
			}
			readFile.close();

		}
		else {
			outFile << "input file doesn't exists ";
		}
	}
	//system("pause");
	idFile.close();
	outFile.close();
	return 0;
}

bool parseData(ifstream * readFile, vector< vector<int> > &mat)
{

	

	int num;
	int n;
	int m;
	string line;

	//first line
	getline(*readFile, line);
	n = atoi(line.c_str());

	//second line
	getline(*readFile, line);
	m = atoi(line.c_str());

	vector< vector<int> > mat1(n, vector<int>(m));
	mat = mat1;

	for (int i = 0; i < n; i++){
		
		getline(*readFile, line);
		if (m != 0) {
			stringstream lineStream(line);
			int j = 0;
			while (lineStream >> num) {
				if (j >= m) {
					return false;
				}
				else {
					mat[i][j] = num;
					j++;
				}
				
			}

			
		}
	}
	//for (int i = 0; i < mat.size(); i++) {
	//	for (int j = 0; j < mat[i].size(); j++) {
	//		cout << mat[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return true;
}

vector<vector<int>> buildSubSqr(vector<vector<int>>& mat)
{
	
	vector< vector<int> > matRetrun(mat.size(), vector<int>(mat[0].size()));
	vector<int> sortV;

	for (int i = 0; i < mat.size(); i++){
		for (int j = 0; j < mat[0].size(); j++){
			//cout << mat[i][j] << " ";
			if (i == 0 || j == 0) {
				matRetrun[i][j] = mat[i][j];
			}
			else {
				if (mat[i][j] == 1) {
					sortV.clear();
					sortV.push_back(matRetrun[i][j - 1]);
					sortV.push_back(matRetrun[i - 1][j]);
					sortV.push_back(matRetrun[i - 1][j - 1]);
					sort(sortV.begin(), sortV.end());
					matRetrun[i][j] = sortV[0] + 1;
				}
				else {
					matRetrun[i][j] = 0;
				}
			}
			
		}
		//cout << endl;
	}
	return matRetrun;
}

vector<int> findMaxCount(vector<vector<int>>& sq)
{

	vector<int> returnVec(2);
	
	for (int i = 0; i < sq.size(); i++) {
		for (int j = 0; j < sq[0].size(); j++) {
			if (sq[i][j] != 0) {
				if (sq[i][j] > returnVec[0]) {
					returnVec[0] = sq[i][j];
					returnVec[1] = 1;
				}
				else if (sq[i][j] == returnVec[0]) {
					returnVec[1] ++;
				}
			}
			
		}
	}
	return returnVec;
}
