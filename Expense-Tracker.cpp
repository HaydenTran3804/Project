#include <bits/stdc++.h>
using namespace std;
class Tracker{
private:
string card,name,date;
float amount;
public:
friend istream& operator >> (istream &in,Tracker &a);
friend ostream& operator << (ostream &out,Tracker a);
};
istream& operator >>(istream &in,Tracker &a){
	cout << "Type: ";
	getline(in,a.card);cout << endl;
	cout << "Name: ";
	getline(in,a.name);cout << endl;
	cout << "Date: ";
	getline(in,a.date); cout << endl;
	cout << "Amount: ";
	in >> a.amount;cout << endl;
	return in;
}
ostream& operator <<(ostream &out,Tracker a){
	out <<setw(17)<< a.card <<setw(30)<< a.name <<setw(30)<<a.date << setw(28) << a.amount << endl;
	return out;
}
void del(vector<Tracker> &s,int pos){
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
cout << setw(65) << "Expense Tracker"<< endl;
cout << setw(53) <<"1: Add" << " " << "2: Delete" << " " << "3: Logout"<<endl;
cout << setw(17) <<"Type" <<setw(30)<<"Name" <<setw(30)<<"Date"<<setw(28)<<"Amount"<<endl;
vector<Tracker> list;
int choice=1;
while(1){
	if(choice==1){
		Tracker s; cin >> s;
		list.push_back(s);
	} else if(choice==2){
		int pos;cin >> pos;
		del(list,pos);
	} else break;
	system("cls");
		cout << setw(65) << "Expense Tracker"<< endl;
cout << setw(53) <<"1: Add" << " " << "2: Delete" << " " << "3: Logout"<<endl;
cout << setw(17) <<"Type" <<setw(30)<<"Name" <<setw(30)<<"Date"<<setw(28)<<"Amount"<<endl;
	for(int i=0;i<list.size();i++){
		cout <<list[i];
	}
cin >> choice;
cin.ignore();
}
}
