/*
 * CSc103 Project 3: Game of Life
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:
 */

#include <iostream>

#include <fstream>
#include<iostream>

#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::cout;

using std::cin;


static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Text-based version of Conway's game of life.\n\n"
"   --seed,-s     FILE     read start state from FILE.\n"
"   --world,-w    FILE     store current world in FILE.\n"
"   --fast-fw,-f  NUM      evolve system for NUM generations and quit.\n"
"   --help,-h              show this message and exit.\n";

size_t max_gen = 0; /* if > 0, fast forward to this generation. */
string wfilename =  "/tmp/gol-world-current"; /* write state here */
FILE* fworld = 0; /* handle to file wfilename. */
string initfilename = "/tmp/gol-world-current"; /* read initial state from here. */

size_t nbrCount(size_t i, size_t j, const vector<vector<bool> >& g);
void update();
int initFromFile(const string& fname);
void mainLoop();
void dumpState(FILE* f);

char text[3] = ".O";

int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"seed",    required_argument, 0, 's'},
		{"world",   required_argument, 0, 'w'},
		{"fast-fw", required_argument, 0, 'f'},
		{"help",    no_argument,       0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "hs:w:f:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case 's':
				initfilename = optarg;
				break;
			case 'w':
				wfilename = optarg;
				break;
			case 'f':
				max_gen = atoi(optarg);
				break;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}


	mainLoop();
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



