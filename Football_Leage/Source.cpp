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
		Teams.resize(TeamsNumber);
		
	}

	friend ostream& operator<<(ostream& out, const Team elem);
	friend void bubbleSort(vector<Team> arrForSort);
	//friend int StatsComparing(vector<Team>  Teams);
	friend void MakeMatch(Team& team1, Team& team2);

	void setTeamsInfo() {
		for (int i = 0; i < Teams.size(); i++) {
			cin >> Teams[i].name;
			// add detailed info
		}
	}
	void getLeageInfo() {
		bubbleSort(Teams);
		for (int i = 0; i < Teams.size(); i++) {
			cout << Teams[i] << endl;
		}
	}
	void LeageSimulation() {
		int j = 0;
		for (int i = 0; i < Teams.size() - 2; i++) {
			if (j == Teams.size()) {
				j -= Teams.size();
			}
			MakeMatch(Teams[j], Teams[j + 1]);
			j++;
		}
	}
	
	

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
void MakeMatch(Team& team1, Team& team2) {
	int Result = rand() % 9;
	if (Result >= 0 && Result < 3) { team1.wins++; team2.loses++; }
	else if (Result >= 3 && Result < 6) { team1.draws++; team2.draws++; }
	else if (Result >= 6 && Result < 9) { team1.loses++; team2.wins++; }
}
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
ostream& operator<<(ostream& out, const Team elem) {
	out << elem.name;
	out << " | wins: ";
	out << elem.wins;
	out << " | draws: ";
	out << elem.draws;
	out << " | loses: ";
	return out;
}

int main() {
	Leage UkranianLeage;
	UkranianLeage.getLeageInfo(); cout << endl;
	UkranianLeage.LeageSimulation();
	UkranianLeage.getLeageInfo();
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