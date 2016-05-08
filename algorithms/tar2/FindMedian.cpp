//316898162 otherid

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

void parseData(ifstream *readFile, vector<int> &v1, vector<int> &v2);
void printVector(vector<int> &v1);
int findMedian(vector<int> &v1, vector<int> &v2,int low1,int high1,int low2,int high2);
void printV(vector<int> &v, int low, int high);

int findMedian2(vector<int> &v1, vector<int> &v2);

int main(int argc, char *argv[]) {

	if (argc == 1) {
		cout << "please input the input file to the program's first argument " << endl;
	}
	else {
		ifstream readFile;
		//cout << argv[1];
		readFile.open(argv[1]);
		if (readFile.is_open()) {

			vector<int> v1, v2;

			parseData(&readFile, v1, v2);

			printVector(v1);
			printVector(v2);

			int med = findMedian(v1, v2, 0, v1.size()-1 , 0, v2.size()-1 );
			//int med = findMedian2(v1,v2);

			cout << "The med: " << med << endl;

			readFile.close();

			//cout << "yes " << endl;
		}
		else {
			cout << "input file doesn't exists " << endl;
		}
	}
	system("pause");
	return 0;
}

void parseData(ifstream * readFile, vector<int>& v1, vector<int>& v2)
{
	vector<int> numbers;
	int num;
	int n;
	string line;

	//first arr
	getline(*readFile, line);
	n = atoi(line.c_str());
	getline(*readFile, line);
	stringstream lineStream(line);
	while (lineStream >> num) v1.push_back(num);
	if (v1.size() != n) {
		cout << "incorrect structure input file" << endl;
		return ;
	}

	//second arr
	getline(*readFile, line);
	n = atoi(line.c_str());

	getline(*readFile, line);
	stringstream lineStream2(line);
	while (lineStream2 >> num) v2.push_back(num);
	if (v2.size() != n) {
		cout << "incorrect structure input file" << endl;
		return;
	}



	
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
	//bool size = false;
	//if ((low1 + high1) % 2 == 0)
	//	size = true;

	static int count = 0;
	cout << "iterration: " << count << endl;
	printV(v1, low1, high1);
	printV(v2, low2, high2);

	//cout << endl;
	
	if (high1 == low1 && high2 == low2 ) {
		if (v1[high1] < v2[high2])
			return v1[high1];
		else
			return v2[high2];
	}
	//int med1 = (high1 - low1 + 1) / 2;
	//int med2 = (high2 - low2 + 1) / 2;

	int med1 = (high1 + low1 ) / 2;
	int med2 = (high2 + low2 ) / 2;
	count++;
	cout << "med1: " << v1[med1] << " med2: " << v2[med2] << endl;

	cout << endl;
	cout << endl;

	if (v1[med1] > v2[med2]) {

		int itemsDropV1 = high1 - med1 ;
		int itemsDropV2 = med2 - low2 ;
		
		
		if (itemsDropV2 != itemsDropV1 && med2 <= high2 - abs(itemsDropV2 - itemsDropV1))
			med2 += abs(itemsDropV2 - itemsDropV1);

		if (itemsDropV1 == itemsDropV2)
			med2 += 1;

		return findMedian(v1, v2, low1, med1, med2 , high2);



		/*if (itemsDropV2 > itemsDropV1 && high2 >= med2 + (itemsDropV2 - itemsDropV1))
			high2 -= itemsDropV2 - itemsDropV1;
		if (itemsDropV1 > itemsDropV2 && low1 <= med1 -(itemsDropV1 - itemsDropV2))
			low1 += itemsDropV1 - itemsDropV2;
		if (itemsDropV1 == itemsDropV2)
			med2 += 1;

		return findMedian(v1, v2, low1, med1, med2 , high2);*/


		//int size1 = high1 - low1 + 1;
		//int size2 = high2 - low2 + 1;

		//if (size1>size2)
		//	return findMedian(v1, v2, low1+size1-size2, med1, med2, high2);
		//if (size2>size1)
		//	return findMedian(v1, v2, low1, med1, med2, high2 - size2+size1);

		


		//return findMedian(v1, v2, low1, med1, med2, high2);

		//if (itemsDropV1 < itemsDropV2)
		//	return findMedian(v1, v2, low1, med1, med2 + 1, high2 - itemsDropV2);
		//else
		//	return findMedian(v1, v2, low1, med1, med2 + 1, high2 - itemsDropV2);

		//return findMedian(v1, v2, low1, med1 , med2 , high2);

		

		/*if (size)
			return findMedian(v1, v2, low1, med1, med2 + 1, high2);
		else
			return findMedian(v1, v2, low1 , med1 , med2 , high2 );*/

		//return findMedian(v1, v2, low1, med1 -1, med2 + 1, high2);

		/*if (itemsDropV1 >= itemsDropV2)
			return findMedian(v1, v2, low1, med1 - itemsDropV1, med2 + itemsDropV2, high2);
		else
			return findMedian(v1, v2, low1 + itemsDropV1, med1 , med2 , high2 - +itemsDropV2);*/





		/*if (itemsDropV2 == 0 && itemsDropV1 == 0)
			return findMedian(v1, v2, low1, high1-1, low2+1, high2 );
		if (itemsDropV1 == itemsDropV2)
			return findMedian(v1, v2, low1, med1 - 1, med2 + 1, high2);
		else
			return findMedian(v1, v2, low1+itemsDropV1- itemsDropV2, high1 , low2 , high2 - itemsDropV2 );*/

		//return findMedian(v1, v2, low1, v1.size()-1, low2, v2.size()-1);
	}
	else {



		int itemsDropV1 = med1 - low1; 
		int itemsDropV2 = high2 - med2 ;


		if (itemsDropV2 != itemsDropV1 && med1<= high1 - abs(itemsDropV2 - itemsDropV1))
			med1 += abs(itemsDropV2 - itemsDropV1);
		if (itemsDropV1 == itemsDropV2)
			med1 += 1;

		return findMedian(v1, v2, med1, high1, low2, med2);

		//if (itemsDropV2 > itemsDropV1 && low2<=med2 - (itemsDropV2-itemsDropV1))
		//	low2 += itemsDropV2 - itemsDropV1;
		//if (itemsDropV1 > itemsDropV2 && high1 >= med1 + (itemsDropV1 - itemsDropV2))
		//	high1 -= itemsDropV1 - itemsDropV2;
		//if (itemsDropV1 == itemsDropV2)
		//	med1 += 1;

		//return findMedian(v1, v2, med1 , high1, low2, med2);
	
		//int size1 = high1 - low1 + 1;
		//int size2 = high2 - low2 + 1;

		//
		//if (size1 > size2)
		//	return findMedian(v1, v2, med1 + size1 - size2, high1, low2, med2);
		//if (size2 > size1)
		//	return findMedian(v1, v2, med1 , high1, low2, med2 - size2 + size1);


		/*return findMedian(v1, v2, med1, high1, low2, med2);*/

		//int itemsDropV1 = med1 - low1; 
		//int itemsDropV2 = high2 - med2 ;


		//if (itemsDropV2 < itemsDropV1)
		//	return findMedian(v1, v2, med1 + 1, high1 - itemsDropV2, low2, med2);

		//return findMedian(v1, v2, med1 + 1, high1, low2, med2);


		//if (size)
		//	return findMedian(v1, v2, med1 +1 , high1, low2, med2 );
		//else
		//	return findMedian(v1, v2, med1 , high1 , low2 , med2 );

		

		/*if (itemsDropV1 >= itemsDropV2)
			return findMedian(v1, v2, med1 + itemsDropV1, high1, low2, med2 - itemsDropV2);
		else
			return findMedian(v1, v2, med1 , high1 - itemsDropV1, low2+ itemsDropV2, med2 );*/

		/*if (itemsDropV2 == 0 && itemsDropV1 == 0)
			return findMedian(v1, v2, low1+1, high1, low2, high2-1);
		else if (itemsDropV1 == itemsDropV2)
			return findMedian(v1, v2, med1 + 1 , high1, low2, med2 - 1);	
		else
			return findMedian(v1, v2, low1  , high1 - itemsDropV1, low2 + itemsDropV2, high2 );
		*/


	}

	
}

void printV(vector<int>& v, int low, int high)
{
	for (int i = low; i <= high; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int findMedian2(vector<int>& v1, vector<int>& v2)
{
	if (v1.size() == 0 && v2.size() == 0) {
		if (v1[0] < v2[0])
			return v1[0];
		else
			return v2[0];
	}
	int med1 = (v1.size() ) / 2;
	int med2 = (v2.size() ) / 2;
	if (v1[med1] > v2[med2]) {
		

		int itemsDropV1 = med1 ;
		int itemsDropV2 = v2.size() - med2 -1 ;



		//if (itemsDropV1 == itemsDropV2) {
		//	for (int i = 0; i < itemsDropV1; i++){
		//		v1.pop_back();
		//		v2.erase(v2.begin());
		//	}
		//}

		//else {
		//	for (int i = 0; i < itemsDropV1; i++){
		//		v1.erase(v1.begin());
		//	}
		//	for (int i = 0; i < itemsDropV2; i++){
		//		v2.pop_back();
		//	}
		//}

		for (int i = 0; i < itemsDropV1; i++) {
			v1.pop_back();
			//v1.erase(v1.begin());
		}
		for (int i = 0; i < itemsDropV2; i++) {
			//v2.pop_back();
			v2.erase(v2.begin());

		}

		return findMedian2(v1, v2);

	}
	else {



	}
	
}

