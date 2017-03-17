#include <iostream>

#include <fstream>
#include<iostream>

#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
#include <string>
using namespace std;

 vector<vector<bool> > old;
 void printVecV(vector<vector<bool> > G);

  int main(){

  string line;
  string fname;
  cin >> fname;
	ifstream myfile(fname);
	if(myfile.is_open()){

		while(getline (myfile,line)){
			vector<bool> b;
			for(size_t i = 0; i < line.length(); i++){
						if(line[i] == '.') {
							b.push_back(false);
						}else {
										b.push_back(true);
						}
					}
					old.push_back(b);}
          printVecV(old);
				myfile.close();

				}else cout << "Unable to open file" << endl;

        return 0;
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