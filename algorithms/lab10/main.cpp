#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void lab10ex1();
vector<int> coinReturn(vector<int> &d, int k);
void printCoin(vector<int> &c,vector<int> &d,int i);

void lab10ex2();

void main() {
	lab10ex1();
	system("pause");
}

void lab10ex1()
{
	vector<int> d = {1,4,6};
	//vector<int> d = { 1,5,10,50,100 };
	vector<int> c;
	int index = 7;
	int k = 9;
	c = coinReturn(d, k);
	for (int i = 0; i < c.size(); i++)
	{
		cout << i << " ";

	}
	cout <<endl << "------------------------" << endl;
	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << " ";

	}
	cout << endl;
	cout << "The path is:" << endl;
	printCoin(c,d, index);
	cout << endl;

}

vector<int> coinReturn(vector<int>& d, int k)
{
	vector<int> returnVec;
	vector<int> sortV;
	for (int i = 0; i < k; i++){
		if (i == 0) {
			returnVec.push_back(0);
		}

		else if (find(d.begin(), d.end(), i) != d.end()) {
			returnVec.push_back(1);
		}
		else if (i >6){
			sortV.clear();
			for (int j = 0; j < d.size(); j++){
				if (i - d[j] >= 0) {
					sortV.push_back(i - d[j]);
				}
				
			}
			sort(sortV.begin(), sortV.end());
			returnVec.push_back(sortV[0] + 1);
			
		}
		else {
			returnVec.push_back(returnVec[i-1] + 1);
		}
	}


	return returnVec;
}

void printCoin(vector<int>& c, vector<int>& d, int i)
{
	vector<int> sortV;
	int index = c[i];
	
	
	if (i < d[0]) {
		if (i == index) {
			cout << i << " = " << index << endl;
		}
		else {
			cout << "can't add to this sum with the current coins value" << endl;
		}
	}
	else {
		cout << i << " = " ;
		while (index > 0)
		{
			sortV.clear();
			for (int j = 0; j < d.size(); j++) {
				if (i - d[j] >= 0) {
					sortV.push_back(d[j]);
				}

			}
			sort(sortV.begin(), sortV.end());
			int val = sortV[sortV.size() - 1];
			index -= c[val];
			i -= val;
			if (index > 0) {
				cout << val << " +";
			}
			else {
				cout << val ;
			}
		}
	}


	//while (index > 0)
	//{
	//	sortV.clear();
	//	for (int j = 0; j < d.size(); j++) {
	//		if (index - d[j] >= 0) {
	//			sortV.push_back(index - d[j]);
	//		}

	//	}
	//	sort(sortV.begin(), sortV.end());
	//	
	//	int val = sortV[sortV.size() - 1];
	//	index-= val;
	//	if (index > 0) {
	//		cout << val << " +";
	//	}
	//	else {
	//		cout << val ;
	//	}
	//	

	//	//vector<int>::iterator fit = find(d.begin(), d.end(), index);
	//	//if (fit != d.end()) {
	//	//	cout << d[*fit] << "+";
	//	//}
	//	
	//	
	//}
	

}

