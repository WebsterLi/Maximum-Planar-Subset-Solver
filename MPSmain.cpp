#include "MPS.h"

int main(int argc,char **argv){
	Graph G;
	G.parser(argc,argv);
	G.fout.open(argv[2],fstream::out);
	G.fout << G.MPS(0,G.numChord-1)<<endl;
	G.Backtrace(0,G.numChord-1);
	G.fout.close();
	return 0;
}
