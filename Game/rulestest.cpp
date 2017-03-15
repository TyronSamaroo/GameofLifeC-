#include<fstream>
#include<iostream>
#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
using std::vector;
#include <string>
#include <algorithm>
using namespace std;

void printVecV(vector<vector<bool> > G);

 bool rules(int count);
 int check(int i, int j, vector<vector<bool> >& g);



int main(){
	int x=0;
	int i = 0;
	int j = 0;
	int count=0;
 vector<vector<bool> > v;
	for(i = 0; i < 5; i++){

	vector<bool> temp;
		for(j = 0; j < 9; j++){
			cin >> x;
			temp.push_back(x);

			}
			v.push_back(temp);

		}

	check(i,j,v);
	rules(count);

		printVecV(v);

 return 0;
}

int check(int i, int j, vector<vector<bool> >& g){
	int count = 0;
	rotate(g.begin(), g.begin() + 3, g.end());

	if (g[i][j-1] == 1)  {count++;}
	if (g[i][j+1] == 1)  {count++;}
	if (g[i-1][j] == 1)  {count++;}
	if (g[i+1][j+1] == 1){count++;}
	if (g[i-1][j-1] == 1){count++;}
	if (g[i-1][j+1] == 1){count++;}
	if (g[i+1][j-1] == 1){count++;}
	if (g[i+1][j+1] == 1){count++;}
	return count;
}




bool rules(int count){
	if(count < 2){
		return false;
	}else if(count == 3){
		return true;
	}else if (count > 3){
		return false;
	}}

	void printVecV(vector<vector<bool> > G){
	for (int i = 0; i < G.size() ; i++) {
	for(int j = 0;j < G[i].size() ;j ++) {
		cout<< G[i][j];
	}
	cout << endl;
}
}