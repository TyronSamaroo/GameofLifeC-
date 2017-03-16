#include<fstream>
#include<iostream>
#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
using std::vector;
#include <string>
using namespace std;

vector<vector<bool> > old;

void printVecV(vector<vector<bool> > G);


	int check(int i, int j, vector<vector<bool> > g);
	void initFromFile(const string& fname);
	void update();


int main(){

 return 0;
}




	int check(int i, int j, vector<vector<bool> > g){
  int count=0;

		size_t r = g.size();
		size_t c = g[0].size();

	if (g[(i+r)%r][(j+1+c)%c])  				{count++;}		        //right

	if (g[(i+r)%r][(j-1+c)%c])  				{count++;}		  	   //left

	if (g[(i-1+r)%r][(j+c)%c])  				{count++;}			     //up

	if (g[(i+1+r)%r][(j+c)%c])					{count++;}		  	  //down

	if (g[(i-1+r)%r][(j-1+c)%c])  			{count++;}		     //up left

	if (g[(i-1+r)%r][(j+1+c)%c])  			{count++;}		    //up right

	if (g[(i+1+r)%r][(j-1+c)%c])   			{count++;}		   //down left

	if (g[(i+1+r)%r][(j+1+c)%c])    		{count++;}	    //down right

	return count;
}


	void printVecV(vector<vector<bool> > G){
		int count=0;
	for (int i = 0; i < G.size() ; i++) {
	for(int j = 0;j < G[i].size() ;j ++) {
		if(G[i][j]){
				cout<<'O';
			}else{
				cout<<'.';
			}
	}
	cout << endl;
}
}

void initFromFile(const string& fname){


	ifstream myfile(fname);
	if(myfile.is_open()){

		while(getline(myfile,fname)){
			vector<bool> b;

			for(int i = 0; i < fname.length(); i++){
						if(fname[i] == '.') {
							b.push_back(false);
						}else {
										b.push_back(true);
						}
					}
					old.push_back(b);}
				myfile.close();

				}else cout << "Unable to open file" << endl;

	}

	void update(){

		vector<vector<bool> > updated
		for(int i = 0; i < v.size(); i++){
		vector<bool> newrow;
			for(int j = 0; j < v[0].size(); j++){
				int count = check(i,j,v);
				if(count > 3 || count < 2) newrow.push_back(false);
				if(count == 3) newrow.push_back(true);
				else newrow.push_back(old[i][j]);
			}
			updated.push_back(newrow);
		}
		old = updated;
	}

	void writeToFile(const string & fname){
		ofstream myfile(fname);
		if(myfile.is_open()){
			for(size_t i = 0; i < old.size();i++){
			for(size_t j = 0; j < old[0].size();j++){
				}
				}
			}
		}