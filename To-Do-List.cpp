#include <bits/stdc++.h>
using namespace std;
void del(vector<string> &s,int pos){
	if(pos==s.size()){
		s.pop_back();
	} else {
		for(int i=pos-1;i<s.size()-1;i++){
			s[i]=s[i+1];
		}
		s.pop_back();
	}
}
int main(){
	vector<string> list;
	string s;
cout <<setw(65) <<"To Do List" << endl;
cout <<setw(55) <<"1: Add" <<" " << "2: Delete" << " " << "3: Logout"<< endl;
int choice; cin >> choice;
cin.ignore();
while(1){
	if(choice==1){
		getline(cin,s);
		list.push_back(s);
	}else if(choice==2){
		int pos;cin >> pos;
		del(list,pos);
	} else break;
	system("cls");
	cout <<setw(65) <<"To Do List" << endl;
cout <<setw(55) <<"1: Add" <<" " << "2: Delete" << " " << "3: Logout"<< endl;
	for(int i=0;i<list.size();i++){
		cout << setw(50) <<i+1<<") "<<list[i]<<endl; 
	}
	cin >> choice;
	cin.ignore();
}
}
