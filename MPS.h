#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
public :
	Graph();
	fstream fout;
	int parser (int argc,char **argv);
	int MPS(int a, int b);
	void Backtrace(int a,int b);
	int numChord;
	int ChordPartner(int a);
	bool ChordExist(int a,int b);
	/*int Getmps(int a,int b);
	bool mpsExist(int a,int b);
	class mps{
	public:
		mps();
		void insertmps(int a,int b,int c){
			m[0] = a;
			m[1] = b;
			m[2] = c;
		}
		int m[3];
	};*/
	class Chord{
	public :
		Chord();
		int i ;
		int j ;
	};		
private :
	vector<int> fgraph;//full graph
	vector<vector<int>> mgraph;
	vector<vector<Chord>> mtable;
};
