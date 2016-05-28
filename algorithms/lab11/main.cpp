#include <iostream>
#include <vector>

using namespace std;

void lab11ex1();
void makeTurn(vector<int> &arr,int &sum1,int &sum2,bool player1);
void printVector(vector<int> &arr);
void buildMatrix(vector<int> &arr, int **matrix);

void main() {
	lab11ex1();
	system("pause");
}

void lab11ex1()
{
	vector<int> arr = {3,6,10,5,7,2}; // one of them needs to be 17
	//vector<int> arr = { 3,6,10,5};
	int sum1, sum2;
	bool player1 = true;
	sum1 = sum2 = 0;
	printVector(arr);
	while (arr.size()> 0){
		if (player1) {
			cout << "player 1 turn" << endl;
		}
		else {
			cout << "player 2 turn" << endl;
		}
		makeTurn(arr, sum1, sum2, player1);
		player1 = !player1;
		printVector(arr);
		cout << endl;
	}
	cout << "player1:" << sum1 << "player2: " << sum2 << endl;
}

void makeTurn(vector<int> &arr, int &sum1, int &sum2, bool player1)
{
	int nextSumCur1 = 0;
	int nextSumCur2 = 0;
	int nextSumOps1=0;
	int nextSumOps2 = 0;
	int bestMove = 0;
	int dif = 0;
	if (player1) {
		nextSumCur1 = sum1;
		nextSumCur2 = sum1;
		nextSumOps1 = sum2;
		nextSumOps2 = sum2;

		if (arr.size() == 1) {
			sum1 += arr[0];
			arr.erase(arr.begin());
			return;
		}
		else if (arr.size() == 2) {
			if (arr[0] > arr[1]) {
				sum1 += arr[0];
				arr.erase(arr.begin());
				return;
			}
			else {
				sum1 += arr[1];
				arr.erase(arr.end());
				return;
			}
		}
		else {
			//left

			nextSumCur1 += arr[0];
			if (arr[1] > arr[arr.size() - 1]) {
				nextSumOps1 += arr[1];
			}
			else {
				nextSumOps1 += arr[arr.size() - 1];
			}
			
			dif = nextSumCur1 - nextSumOps1;
			bestMove = 0;

			
			//right

			nextSumCur2 += arr[arr.size() - 1];
			if (arr[0] > arr[arr.size() - 2]) {
				nextSumOps2 += arr[0];
			}
			else {
				nextSumOps2 += arr[arr.size() - 2];
			}

			//check the max diff

			if ((nextSumCur2 - nextSumOps2) > dif) {
				bestMove = arr.size() - 1;
			}

			if (bestMove == 0) {
				sum1 += arr[0];
				arr.erase(arr.begin());
				return;
			}
			else {
				sum1 += arr[arr.size()-1];
				arr.erase(arr.end());
				return;
			}
		}
	}
	else {
		nextSumCur1 = sum2;
		nextSumCur2 = sum2;
		nextSumOps1 = sum1;
		nextSumOps2 = sum1;

		if (arr.size() == 1) {
			sum2 += arr[0];
			arr.erase(arr.begin());
			return;
		}
		else if (arr.size() == 2) {
			if (arr[0] > arr[1]) {
				sum2 += arr[0];
				arr.erase(arr.begin());
				return;
			}
			else {
				sum2 += arr[1];
				arr.erase(arr.end());
				return;
			}
		}
		else {
			//left

			nextSumCur1 += arr[0];
			if (arr[1] > arr[arr.size() - 1]) {
				nextSumOps1 += arr[1];
			}
			else {
				nextSumOps1 += arr[arr.size() - 1];
			}

			dif = nextSumCur1 - nextSumOps1;
			bestMove = 0;


			//right

			nextSumCur2 += arr[arr.size() - 1];
			if (arr[0] > arr[arr.size() - 2]) {
				nextSumOps2 += arr[0];
			}
			else {
				nextSumOps2 += arr[arr.size() - 2];
			}

			//check the max diff

			if ((nextSumCur2 - nextSumOps2) > dif) {
				bestMove = arr.size() - 1;
			}

			if (bestMove == 0) {
				sum2 += arr[0];
				arr.erase(arr.begin());
				return;
			}
			else {
				sum2 += arr[arr.size() - 1];
				arr.erase(arr.end());
				return;
			}
		}
	}

}

void printVector(vector<int> &arr)
{
	cout << "The arr is : ";
	for (int i = 0; i < arr.size();i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
