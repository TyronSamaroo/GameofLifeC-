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

size_t nbrCount(size_t i, size_t j, const vector<vector<bool> >&g);
void update();
int initFromFile(const string& fname);
void mainLoop();
void dumpState(FILE* f);
void vectorofvector(const vector<vector<char> >&v);

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

void mainLoop(){
	/* update, write, sleep */
}
#if 1

void dumpState(FILE* f){
	char c;
FILE * f=fopen("/home/csc103/project-game/Game/res/glider-40x20","rb");
	if(!f){
		printf("error \n");
	exit(1);}
	while(fread(&c,1,1,f)> 0){
		printf( "%c\n",c);}
    fclose(f);
return;
	}
#endif
#if 0
void vectorofvector(const vector<vector<char> >&v,){

dumpState(FILE* f);
	while(char){
		v.push_back(c);
	}
}

#endif
#if 1
}

size_t check(size_t i; size_t j; vector<vector<bool> >& g){
  size_t count=0;
	if (g[i][j-1])  {count++;}
	if (g[i][j+1])  {count++;}
	if (g[i-1][j])  {count++;}
	if (g[i+1][j+1]){count++;}
	if (g[i-1][j-1]){count++;}
	if (g[i-1][j+1]){count++;}
	if (g[i+1][j-1]){count++;}
	if (g[i+1][j+1]){count++;}
	return count;
}

void makegrid(const vector<vector<bool> >&grid)
{
  for(int x=0;  x< grid.size(); x++)
  {
    for(int y= 0; y< grid[x].size(); y++)
    {
      cout <<g[x][y];
    }
		cout<<endl;
	}
}//global values//



bool rules(int count){
	if(count < 2){
		return false;
	}else if(count == 3){
		return true;
	}else if (count > 3){
		return false;
	}
}
FILE* f;
f=fopen
("/home/csc103/project-game/Game/res/glider-40x20","rb");
if(f) {
	while((c=getc(f)) !=EOF)
    putchar(c);
    fclose(f);
#endif
