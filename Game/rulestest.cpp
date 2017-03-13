
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

int main(){
  vector<vector<bool> > g;



 return 0;
}

size_t check(size_t i; size_t j; vector<vector<bool> >& g){
  size_t count=0;
	if (g[i][j-1])  {count++;}
	if (g[i][j+1])  {count++;}
	if (g[i-1][j])  {count++;}
	if (g[i+1][j+1]){count++;}
	if (g[i-1][j-1]){count++;}`
	if (g[i-1][j+1]){count++;}
	if (g[i+1][j-1]){count++;}
	if (g[i+1][j+1]){count++;}
	return count;
}
bool rules(int count){
	if(count < 2){
		return false;
	}else if(count == 3){
		return true;
	}else if (count > 3){
		return false;
	}