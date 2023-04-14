#include<bits/stdc++.h>
using namespace std;
int ok = 0;
string a[100][100];
vector<pair<pair<long long,long long>,pair<long long,long long>>> ve;
vector<pair<long long,long long>> v;
vector<pair<long long,long long>> v1;
//Check for winner
void check(){
for(int n=0;n<v.size();n++){
	if( a[v[n].first][v[n].second] == "|X|" || a[v[n].first][v[n].second]== "|O|"){
for(int m=0;m<ve.size();m++){
	int ans=0;
if(a[ve[m].first.first+v[n].first][ve[m].first.second+v[n].second] == a[v[n].first][v[n].second]){
		ans++;
	}
if(a[ve[m].second.first+v[n].first][ve[m].second.second+v[n].second] == a[v[n].first][v[n].second]){
		ans++;
	}
if(ans==2 && a[v[n].first][v[n].second]=="|X|"){ 
	ok=1;
	return;
} else if(ans==2 && a[v[n].first][v[n].second]=="|O|"){
    ok=2;
	return;
}
} 
}
} 
}
void coutt(){
	system("cls");
	for(int i=1;i<=3;i++){
		cout <<setw(50);
		for(int j=1;j<=3;j++){
			cout<<a[i][j]<<" ";
		} cout<<endl;
	}
}
//if player1 go first
void process1(){
	int i,j;
	cout<<"Nhap vi tri muon danh:";cin>>i;
	a[v1[i-1].first][v1[i-1].second]="|X|";
	check();
	if(ok==1||ok==2||ok==3) {
	coutt(); return;
	}
 srand(time(NULL));
do{ i=rand()%3+1;
j=rand()%3+1;
} while(a[i][j]=="|X|"||a[i][j]=="|O|");
a[i][j]="|O|";
check();
	if(ok==1||ok==2||ok==3){
	coutt(); return;
}
coutt();
process1();
}
//if player2 go first
void process2(){
	int i,j;
	srand(time(NULL));
do{ i=rand()%3+1;
j=rand()%3+1;
} while(a[i][j]=="|X|"||a[i][j]=="|O|");
a[i][j]="|O|";
check();
	if(ok==1||ok==2||ok==3){
	coutt(); return;
}
coutt();
cout<<"Nhap vi tri muon danh:";cin>>i;
	a[v1[i-1].first][v1[i-1].second]="|X|";
	check();
	if(ok==1||ok==2||ok==3){
	coutt(); return;
	}
process2();
}
void start(){
	int k=1;
for(int i=1;i<=3;i++){
	for(int j=1;j<=3;j++){
		string res="";
		res+="|";
		res+=k++ + '0';
		res+="|";
	 a[i][j]=res;
	}
} int n;
cout<<"Chon player di truoc(1:Player first;2:Computer first):";
cin>>n; 
if(n==1){
coutt();
process1();
} else if(n==2){
	process2();
}

if(ok==1) cout<<setw(55)<<"YOU Win";
else if(ok==2) cout<<setw(55)<<"You Lose";
else  cout<<setw(55)<<"Draw";
}
void ktao(){
ve.push_back({{-1,-1},{1,1}});
ve.push_back({{-1,1},{1,-1}});
ve.push_back({{0,-1},{0,1}});
ve.push_back({{-1,0},{1,0}});
v.push_back({1,2});
v.push_back({2,1});
v.push_back({3,2});
v.push_back({2,3});
v.push_back({2,2});
v1.push_back({1,1});
v1.push_back({1,2});
v1.push_back({1,3});
v1.push_back({2,1});
v1.push_back({2,2});
v1.push_back({2,3});
v1.push_back({3,1});
v1.push_back({3,2});
v1.push_back({3,3});
ok=0;
}
int main(){
ktao();
	start();
	cout << endl;
    cout<<" "<<system("PAUSE");
    return 0;
}


	 
