#include <iostream>
#include <string>

using namespace std;

void lab6Ex1();

int findPermu(string  &text,string & sub);

void lab6Ex2();
int* preFixFunc(string &str);

void lab6Ex3();
int KMP(string &text, string &sub);

void lab6Ex4();
bool isRotationText(string &text1, string &text2);

void main() {
	//lab6Ex1();
	//lab6Ex2();
	lab6Ex3();
	lab6Ex4();
	system("pause");
}

void lab6Ex1()
{
	//string text = "ababababab";
	//string sub = "abb";
	string text = "aaabababab";
	string sub = "abb";
	int index = findPermu(text, sub);
	cout << "The text is: " << text << endl;
	cout << "The sub is: " << sub << endl << endl;

	if (index != -1) {
		cout << "the permutation found on index: " << index << endl;
	}
	else {
		cout << "the permutation not found in text"<< endl;
	}
}

int findPermu(string & text, string & sub)
{
	if (text.size() < sub.size())
		return -1;
	int arrText[26] = { 0 };
	int arrSub[26] = { 0 };

	for (int i = 0; i < sub.size(); i++)
	{
		arrText[text[i] - 97] ++;
		arrSub[sub[i] - 97] ++;
	}
	/*for (int i = 0; i < 26; i++)
	{
		cout << arrText[i] << " " << arrSub[i] << " " << endl;
	}*/

	bool flag = true;
	for (int i = 0; i < 26 && flag; i++)
	{
		if (arrText[i] != arrSub[i])
			flag = false;
	}
	if (flag)
		return 0;
	


	for (int i = sub.size(); i < text.size()-sub.size(); i++)
	{
		arrText[text[i-sub.size()] - 97] --;
		arrText[text[i] - 97] ++;
		flag = true;
		for (int i = 0; i < 26 && flag; i++)
		{
			if (arrText[i] != arrSub[i])
				flag = false;
		}
		if (flag)
			return i-sub.size()+1;
		
	}
	return -1;
}

void lab6Ex2()
{
//	string str = "ababbabbababbababbabb";
	string str = "abaaa";
	int * arr = preFixFunc(str);
	cout << "The string is: " << str << endl;
	cout << "the prefix arr is: " << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int * preFixFunc(string & str)
{
	int* arr = new int[str.size()];
	arr[0] = 0;
	int k = 0;
	for (int i = 1; i < str.size(); i++)
	{
		while (k>0 && str[k]!=str[i])
			k = arr[k-1];
		if (str[k] == str[i])
			k += 1;
		arr[i] = k;

	}
	return arr;
}

void lab6Ex3()
{
	
	string text = "ababbabbababbababbabb";
	string sub = "babab";
	int index = KMP(text, sub);
	cout << "The text is: " << text << endl;
	cout << "The sub is: " << sub << endl << endl;

	if (index != -1) {
		cout << "the kmp found on index: " << index << endl << endl;
	}
	else {
		cout << "the kmp didn't found in text" << endl << endl;
	}
}

int KMP(string & text, string & sub)
{
	if (text.size() < sub.size())
		return -1;

	int * pieArr = preFixFunc(sub);
	int q = 0;
	for (int i = 0; i < text.size(); i++)
	{
		while (q > 0 && sub[q] != text[i])
			q = pieArr[q-1];
		if (sub[q] == text[i])
			q++;
		if (q == sub.size())
			return i - q + 1;
	}

	return -1;
}

void lab6Ex4()
{
	string text1 = "car";
	string text2 = "arc";

	
	cout << "The text1 is: " << text1 << endl;
	cout << "The text2 is: " << text2 << endl << endl;
	if (isRotationText(text1,text2)) {
		cout << "text1 is rotation of text2 "   << endl;
	}
	else {
		cout << "text1 isn't rotation of text2 "  << endl;
	}
}

bool isRotationText(string & text1, string & text2)
{
	text1 += text1;
	if (KMP(text1, text2)!=-1) {
		return true;
	}
	return false;
}
