#include "MPS.h"


int Graph::parser(int argc ,char **argv){
	//int A[10000][10000];
	
    if(argc != 3)
    {
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
    }

    // open the input file
    fstream fin;
    fin.open(argv[1], fstream::in);
    if(!fin.is_open())
    {
        cout << "Error: the input file is not opened!!" << endl;
        exit(1);
    }

    // parse the input file
   // cout << "======================" << endl;
   // cout << "        Parser        " << endl;
   // cout << "======================" << endl;

    char buffer[100];

    fin >> buffer;
    numChord = atoi(buffer);

   // cout << "#Chord:" << numChord << endl;
	fgraph.assign(numChord,0);
    for(int i = 0; i < numChord / 2; ++i)
    {
		fin >> buffer;
    	int point1 = atoi(buffer);
    	fin >> buffer;
    	int point2 = atoi(buffer);

		fgraph[point1] = point2 ;
		fgraph[point2] = point1 ;

    //	cout << "Chord(" << point1 << "," << point2 << ")" << endl;
    }
	fin.close();

	mgraph.assign(numChord,vector<int>(numChord,-1));
	mtable.assign(numChord,vector<Chord>(numChord,Chord()));

    /* open the output file
    fstream fout;
    fout.open(argv[2],fstream::out);
    if(!fout.is_open())
    {
        cout << "Error: the output file is not opened!!" << endl;
	    exit(1);
    }

	output something to the output file
    fout << "Hello world!" << endl;
    system("pause");
	fout.close();*/
    
	return 0;

}
