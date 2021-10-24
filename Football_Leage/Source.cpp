#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

struct Team {
	string name;
	float attack;
	float defence;
	int wins;
	int draws;
	int loses;
};
class Leage {
private:
	vector <Team> Teams;
public:
	Leage(int TeamsNumber = 14) {
		for (int i = 0; i < TeamsNumber; i++) {
			cin >> Teams[i];
		}
	}
	friend void bubbleSort(vector<Team> arrForSort);
	//friend int StatsComparing(vector<Team>  Teams);
	void getLeageInfo() {
		bubbleSort(Teams);
		for (int i = 0; i < Teams.size(); i++) {
			cout << Teams[i] << endl;
		}
	}
	void LeageSimulation() {
		
	}
	friend ostream& operator<<(ostream& out, Team elem);
	friend istream& operator>>(istream& in, Team elem);

};
//int StatsComparing(Team TeamOne, Team TeamTwo) {
//	float firstNum = TeamOne.attack;
//	float secondNum = TeamOne.defence;
//	cout << "fir " << firstNum << " sec " << secondNum << " ";
//	float sum1 = firstNum + secondNum; cout << sum1 << endl;
//	firstNum = TeamTwo.attack;
//	secondNum = TeamTwo.defence;
//	float sum2 = firstNum + secondNum;
//	cout << "fir " << firstNum << " sec " << secondNum << " " << sum2 << endl;
//	int per = sum1 / sum2;
//	if (per == 0) {
//		per = sum2 / sum1;
//	}
//	cout << per;
//}
void bubbleSort(vector<Team> arrForSort) {
	int buff = 0;
	for (int i = 0; i < arrForSort.size() - 1; i++) {
		for (int j = arrForSort.size() - 1; j > i; j--) {
			if (arrForSort[j].wins < arrForSort[j - 1].wins)
			{
				buff = arrForSort[j - 1].wins;
				arrForSort[j - 1].wins = arrForSort[j].wins;
				arrForSort[j].wins = buff;
			}
		}
	}
}
ostream& operator<<(ostream& out, Team elem) {
	out << elem.name << " | wins: " << elem.wins << " | draws: " << elem.draws << " | loses: ";
	return out;
}
istream& operator>>(istream& in, Team elem) {
	cout << "enter team name: ";  in >> elem.name;

	string UserAnswer;
	cout << "enter randomly? "; cin >> UserAnswer;
	if (UserAnswer == "yes") {
		int Ran = rand() % 99; elem.attack = Ran;
		Ran = rand() % 99;  elem.defence = Ran;
	}
	else{
		cout << "enter attack: "; in >> elem.attack;
		cout << "enter defence: "; in >> elem.defence;
	}
	return in;
}
int main() {
	/*cout << "test" << endl;
	vector<int> mass;
	mass.resize(4);
	for (int i = 0; i < 4; i++) {
		mass[i] = rand() % 10;
		cout << mass[i] << " ";
	}
	cout << endl;
	int j = 0;
	for (int i = 0; i < 8; i++) {
		if (j == mass.size()) {
			j -= mass.size();
		}
		cout << mass[j] << " ";
		j++;
	}
	cout << endl;*/     // leage match making

	/*float firstNum = rand() % 99;
	float secondNum = rand() % 99;
	cout << "fir " << firstNum << " sec " << secondNum << " ";
	float sum1 = firstNum + secondNum; cout << sum1 << endl;
	firstNum = rand() % 99;
	secondNum = rand() % 99;
	cout << "fir " << firstNum << " sec " << secondNum << " " << (firstNum + secondNum) << endl;
	int per = sum1 / (firstNum + secondNum);
	cout << per;*/  // power counting and comparing
}