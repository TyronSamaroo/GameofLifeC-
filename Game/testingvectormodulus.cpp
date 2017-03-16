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

void telltime(vector<int> v, int x);

int main(){
 vector <int> v;
  for(int i = 1; i < 13; i++){
    v.push_back(i);
    }

  cout << "What time is it?" << endl;
  int time=0, y;
    cin >> time;

  telltime(v,time);

  cout << "Enter shifting hours \n";
  cin >> y;
  y += time;
  cout << "The new time is: \n";
  telltime(v,y);

  return 0;
  }

  void telltime(vector<int> v, int x){

    if(x > 12 || x < 1 ) x %= v.size();
    if(x == 0) x = 12;

    cout << v[x-1] << endl;}