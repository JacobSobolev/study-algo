#include <iostream>


using namespace std;

bool srok( string &str1, string &str2, int &key);
int srokMax(string &str1, string &str2);

int main() {
	
	string s1 = "aaaeeeesssvvvvddd"; // 3 times
	string s2 = "asd";
	string s3 = "aaaaaaaaahuohingoengoosssssssssnibornbiornddddddddd"; // 9 times
	string s4 = "bvribraaaaanburnrusssssnuirnddddd"; // 5 times
	string s5 = "aaaaaaaanbirnbrossssssssnitnirtbdddddddd"; // 8 times
	

	//int key = 2;
	//if (srok(s1, s2, key))
	//{
	//	cout << "yes" << endl;
	//}
	//else {
	//	cout << "no" << endl;
	//}

	//int maxS = srokMax(s1,s2); // max 3 times
	//int maxS = srokMax(s3, s2); // max 9 times
	//int maxS = srokMax(s4, s2); // max 5 times
	int maxS = srokMax(s5, s2); // max 8 times
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
	while (srok(str1,str2, rangeMax) && rangeMax <= str1.size()/str2.size()) {
		rangeMax *= 2;
	}
	rangeMin = rangeMax/2;
	mid = rangeMin + (rangeMax - rangeMin )/2;
	while (rangeMin < rangeMax) {
		
		if (srok(str1, str2, mid)) {
			maxkey = mid;
			rangeMin = mid + 1;
		}
		else {
			rangeMax = mid;
		}
		mid = rangeMin + (rangeMax - rangeMin) / 2;

		
		
	}
	//cout << rangeMax << endl;
	return maxkey;
}
