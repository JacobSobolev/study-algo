#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <time.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>  

using namespace std;

typedef struct record {
	int  data;
	stack<int> *stack;
	
}record;


vector<record*> * parseFile(ifstream *readFile);
record* convertToArray(vector<record*> *v);
list<record*> *convertToList (vector<record*> *v);
void writeOut(ofstream *file,char* funcName,record *max, clock_t);

void pushLoser(record * src, record * des);
record* maxMax1(record * a, int low, int high);
record* maxMax2(list<record*> *l);
record* maxMax3(vector<record*> *v);


int main(int argc, char *argv[]){

	
	if (argc == 1) {
		cout << "please input the input file to the program's first argument " << endl;
	}
	else {
		ifstream readFile;
		//cout << argv[1];
		readFile.open(argv[1]);
		if (readFile.is_open()) {

			vector<record*> *v = parseFile(&readFile);
			
			if (v != nullptr && v->size()>0) {
				ofstream outFile;
				outFile.open("Out.txt");
				outFile << "3168898162 307802769\n";
				record *max1;				
				/* Do your stuff here */
				//ex1
				clock_t tStart1 = clock();
				record * arr = convertToArray(v);
				max1 = maxMax1(arr,0, v->size()-1);
				writeOut(&outFile,"maxMax1", max1, tStart1);

				//ex2
				clock_t tStart2 = clock();
				list<record*> *l = convertToList(v);
				max1 = maxMax2(l);
				writeOut(&outFile,"maxMax2", max1, tStart2);

				clock_t tStart3 = clock();
				
				max1 = maxMax3(v);
				writeOut(&outFile, "maxMax3", max1, tStart3);

				outFile.close();
				cout << "the results were written to Out.txt " << endl;
			}
			
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

vector<record*>* parseFile(ifstream *readFile)
{
	vector<record*> *v = new vector<record*>();
	vector<int> numbers;
	int num;
	int n;
	string line;
	
	getline(*readFile, line);
	n = atoi(line.c_str());

	getline(*readFile, line);
	stringstream lineStream(line);
	while (lineStream >> num) numbers.push_back(num);
	if (numbers.size() != n) {
		cout << "incorrect structure input file" << endl;
		return nullptr;
	}

	for (int i = 0; i < n; i++)
	{
		record* tempRec = new record;
		tempRec->data = numbers[i];
		tempRec->stack = new stack<int>();
		v->push_back(tempRec);
	}

	return v;
}

record * convertToArray(vector<record*>* v)
{
	record *arr = new record[v->size()];
	for (int i = 0; i < v->size(); i++)
	{
		arr[i].data = (*v)[i]->data;
		arr[i].stack = new stack<int>();
	}


	return arr;
}

list<record*>* convertToList(vector<record*>* v)
{
	list<record*> *l = new list<record*>();
	for (int i = 0; i < v->size(); i++)
	{
		record *tempRec = new record;
		tempRec->data = (*v)[i]->data;
		tempRec->stack = new stack<int>();
		l->push_back(tempRec);
	}
	return l;
}

void writeOut(ofstream *file, char * funcName, record * max, clock_t time)
{
	
	(*file) << funcName << "\n";
	(*file) << "Max1=" << max->data << "\n";
	(*file) << "Max2=" << max->stack->top() << "\n";
	(*file) << "Time=" << std::fixed<< std::setprecision(3) << (clock() - time) / (double)(CLOCKS_PER_SEC )<<"\n";
	
}



record* maxMax1(record * a, int low,int high)
{
	int mid = (high + low) / 2;

	if (high == low) {
		return a + low;
	}
	if ((high - low) == 1)
	{
		if (a[low].data >= a[high].data)
		{
			pushLoser(a + high, a +low);
			return a+low;
		}
		else
		{
			pushLoser(a + low, a + high);
			return a + high;
			
		}
	}
	record *max1 = maxMax1(a, low, mid);
	record *max2 = maxMax1(a, mid + 1, high);
	
	if (max1->data > max2->data)
	{
		pushLoser(max2, max1);
		return max1;
	}
	else
	{
		pushLoser(max1, max2);
		return max2;
	}
}



void pushLoser(record * src, record * des)
{
	//des is the new max
	
	if (!des->stack->empty()) {
		if (des->stack->top() < src->data) {
			des->stack->pop();
			des->stack->push(src->data);
		}
		
	}
	else
		des->stack->push(src->data);
	

}


record * maxMax2(list<record*>* l)
{
	record *max ;
	record *tempRec;
	list<record*>::iterator it = l->begin();;
	
	max = (*it);
	it++;

	while (it != l->end()) {
		tempRec = *it;
		it++;
		if (it != l->end()) {

			if ((*it)->data > tempRec->data) {
				pushLoser(tempRec, *it);
				if ((*it)->data > max->data) {
					pushLoser( max, *it );
					max = *it;
					
					
				}
				else {
					pushLoser( *it,max);
				}
			}
			else {
				pushLoser( *it, tempRec);
				if (tempRec->data > max->data) {
					pushLoser(max,tempRec);
					max = tempRec;

				}
				else {
					pushLoser( tempRec,max);
				}
				
			}
			it++;
		}
		else {
			if (tempRec->data > max->data) {
				pushLoser(max, tempRec);
				max = tempRec;
			}
			else {
				pushLoser(tempRec, max);
			}
			
		}
	}

	return max;
}

record * maxMax3(vector<record*>* v)
{
	record *max = new record;
	max->stack = new stack<int>();
	vector<int> tempV;
	for (int i = 0; i < v->size(); i++)
	{
		tempV.push_back((*v)[i]->data);
	}

	make_heap(tempV.begin(), tempV.end());

	max->data = tempV.front();

	pop_heap(tempV.begin(), tempV.end());
	max->stack->push(tempV.front());

	return max;
}




