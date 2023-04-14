#include <bits/stdc++.h>
using namespace std;
map<pair<string,string>,string> mark;
map<int,string> sub;
void Create(){
	sub[1]="Rock";
	sub[2]="Scissors";
	sub[3]="Paper";
	mark[{"Rock","Scissors"}]="Rock";
	mark[{"Scissors","Rock"}]="Rock";
	mark[{"Scissors","Paper"}]="Scissors";
	mark[{"Paper","Scissors"}]="Scissors";
	mark[{"Rock","Paper"}]="Paper";
	mark[{"Paper","Rock"}]="Paper";
}
int main(){
Create();
srand(time(NULL));
cout << setw(65) <<"Rock, Paper, Scissors Game" << endl;
cout << setw(45) <<"1: Rock" <<" "<< "2: Scissors" << " " << "3: Paper" << endl;
while(1){
	cout << setw(57) <<endl;
	int choice;cin >> choice;
	int bot=rand()%3+1;
	if(sub[choice]!=sub[bot]){
			if(mark[{sub[choice],sub[bot]}]==sub[choice]) cout <<setw(57)<< "You Win" << endl;
		else cout <<setw(57)<<"You Lose"<<endl;
		cout << setw(45) << "Player" << setw(20) <<"Bot"<<endl;
		cout << setw(45) << sub[choice] << setw(20) << sub[bot] << endl;
	} else{
		cout <<setw(57)<< "Draw" << endl;
		cout << setw(45) << "Player" << setw(20) <<"Bot"<<endl;
		cout << setw(45) << sub[choice] << setw(20) << sub[bot] << endl;
		sleep(1);
		system("cls");
		cout << setw(65) <<"Rock, Paper, Scissors Game" << endl;
cout << setw(45) <<"1: Rock" <<" "<< "2: Scissors" << " " << "3: Paper" << endl;
		}
	}
}

