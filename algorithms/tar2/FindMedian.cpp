//316898162 307802769

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

bool parseData(ifstream *readFile, vector<int> &v1, vector<int> &v2);
int findMedian(vector<int> &v1, vector<int> &v2,int low1,int high1,int low2,int high2);


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

			vector<int> v1, v2;

			if (parseData(&readFile, v1, v2)) {
				

				

				cout << endl;

				if (v1.size()  == 0 || v2.size() == 0) {
					if (v1.size() == 0 && v2.size() == 0) {
						outFile << -1;


					}
					else if (v1.size()  == 0 ){
						int med = (v2.size() - 1) / 2;
						outFile << med;
					}
					else {
						int med = (v1.size() - 1) / 2;
						outFile << med;
					}
					
				}
				else {
					int med = findMedian(v1, v2, 0, v1.size() - 1, 0, v2.size() - 1);
					outFile << med;
					//cout << med << endl;
				}	
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

bool parseData(ifstream * readFile, vector<int>& v1, vector<int>& v2)
{
	vector<int> numbers;
	int num;
	int n;
	string line;

	//first arr
	getline(*readFile, line);
	n = atoi(line.c_str());
	getline(*readFile, line);
	if (n != 0) {
		stringstream lineStream(line);
		while (lineStream >> num) v1.push_back(num);
		if (v1.size() != n) {
			cout << "incorrect structure input file" << endl;
			return false;
		}
	}
	

	//second arr
	getline(*readFile, line);
	n = atoi(line.c_str());

	getline(*readFile, line);
	if (n != 0) {
		stringstream lineStream2(line);
		while (lineStream2 >> num) v2.push_back(num);
		if (v2.size() != n) {
			cout << "incorrect structure input file" << endl;
			return false;
		}
	}
	

	return true;

	
}

void printVector(vector<int>& v1)
{
	for (int i = 0; i < v1.size(); i++){
		cout << v1[i] << " ";
	}
	cout << endl;
}

int findMedian(vector<int>& v1, vector<int>& v2, int low1, int high1, int low2, int high2)
{


	//cout << endl;
	
	int size1 = high1 - low1 + 1;
	int size2 = high2 - low2 + 1;
	if (v1[high1] < v2[low2] || v2[high2] < v1[low1]) {
		
		int med = (size1 + size2 - 1) / 2;

		if (v1[high1] < v2[low2]) {
			if (med < size1) {
				return v1[med + low1];
			}
			else {
				return v2[med - high1 -1];
			}
		}
		else if (v2[high2] < v1[low1]) {
			if (med < size2) {
				return v2[med + low2];
			}
			else {
				return v1[med - high2 -1];
			}
		}
		
	}

	int med1 = (high1 + low1) / 2;
	int med2 = (high2 + low2) / 2;

	if (v1[med1] > v2[med2]) {
		int itemsDropV1 = high1 - med1;
		int itemsDropV2 = med2 - low2;


		if (itemsDropV1 == 0 && size1!=1) {
			med1--;
		}
		if (itemsDropV2 == 0 && size2!=1) {
			med2++;
		}

		return findMedian(v1, v2, low1, med1, med2, high2);
	}
	else {
		int itemsDropV1 = med1 - low1;
		int itemsDropV2 = high2 - med2;


		if (itemsDropV1 == 0 && size1!=1) {
			med1++;
		}
		if (itemsDropV2 == 0 && size2!=1) {
			med2--;
		}

		return findMedian(v1, v2, med1, high1, low2, med2);
	}
	
}

