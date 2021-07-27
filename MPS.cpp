#include "MPS.h"
Graph::Graph(){
	mgraph.clear();
	fgraph.clear();	
	mtable.clear();
}
Graph::Chord::Chord(){
	i=0;
	j=0;
}
/*Graph::mps::mps(){
	for(int i=0;i<3;++i){
		m[i]=0;
	}
}
bool Graph::mpsExist(int a,int b){
	for(auto j:mgraph){
		if(a==j->m[0] && b==j->m[1])return true;
	}
	return false;
}
int Graph::Getmps(int a,int b){
	for(auto l:mgraph){
		if(a==l->m[0] && b==l->m[1])return l->m[2];
	}
}*/
bool Graph::ChordExist(int a,int b){
	if(fgraph[a]==b)return true;
	return false;
}
int Graph::ChordPartner(int a){
	return fgraph[a];
}
int Graph::MPS(int a,int b){
	int temp = 0;
		if(mgraph[a][b]!=-1){//mps(a,b)exist
		temp = mgraph[a][b];
		return temp;
	}
	else if(a>=b){//mps(a,b)doesn't exist & a=b(or invalid)
		mgraph[a][b] = 0;
		return 0;
	}
	else{
		int c = ChordPartner(a);
		if (c == b){
			temp = MPS(a+1,b-1)+1;
			mtable[a][b].i = a ;
			mtable[a][b].j = b ;
		}
		else if (c > b||c < b && c < a)temp = MPS(a+1,b);
		else if (c > a){
			if(MPS(a,c)+MPS(c+1,b) > MPS(a+1,b)){
				temp = MPS(a,c)+MPS(c+1,b);
				mtable[a][b].i = a;
				mtable[a][b].j = c;
			}
			else temp = MPS(a+1,b);
		}
	}
		
	/*	mps* m = new mps(
		m -> insertmps(a,b,temp);
		mgraph.push_back(m);*/
		mgraph[a][b] = temp;
		return temp;

}
void Graph::Backtrace(int a,int b){
	int i = mtable[a][b].i;
	int j = mtable[a][b].j;
	if (i > j)swap(i,j);
	if (a > b)swap(a,b);
	if (a==b)return;
	else if (i==j)Backtrace(a+1,b);
	else if ((i==a&&j==b)){
		this->fout << i << ' ' << j << endl ;
		Backtrace(a+1,b-1);
	}
	else {
		this->fout << i << ' ' << j << endl ;
		Backtrace(i+1,j-1);
		Backtrace(j+1,b);
	}
}
