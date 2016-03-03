#include <iostream>


using namespace std;

bool srok( string &str1, string &str2, int &key);
int srokMax(string &str1, string &str2);

int main() {
	
	string s1 = "aaaeeeesssvvvvddd";
	string s2 = "asd";
	//int key = 2;
	//if (srok(s1, s2, key))
	//{
	//	cout << "yes" << endl;
	//}
	//else {
	//	cout << "no" << endl;
	//}
	int maxS = srokMax(s1,s2);
	cout << "the max is: " <<maxS << endl;
	system("pause");
	return 0;
}

bool srok( string & str1,  string & str2, int & key)
{
	int j = 0;
	int countTotal = 0;
	int countChar = 0;
	for (int i = 0; i < str1.size(); i++)
	{
		
		if (str1[i] == str2[j]) {
			countChar++;
			
		}
		if (countChar == key) {
			countChar = 0;
			j++;
		}
		
		if (j + 1 == str2.size() ) {
			return true;
		}
		
	}

	return false;
}

int srokMax(string & str1, string & str2)
{
	int maxkey = 0;
	int rangeMin = 1;
	int rangeMax = 1;
	int mid = 0;
	while (srok(str1,str2, rangeMax) ) {
		rangeMax *= 2;
	}
	rangeMin = rangeMax/2;
	mid = rangeMax - rangeMin ;
	while ( mid >0) {
		
		if (srok(str1, str2, mid)) {
			maxkey = mid;
			rangeMin = mid + 1;
		}
		else {
			rangeMax = mid;
		}
		mid = (rangeMax - rangeMin) / 2;

		
		
	}
	//cout << rangeMax << endl;
	return maxkey;
}
