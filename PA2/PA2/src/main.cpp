// **************************************************************************
//  File       [main.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The main program of 2015 Spring Algorithm PA2]
//  Modify     [2015/03/20 Yu-Hao Ho]
// **************************************************************************

#include <cstring>
#include <iostream>
#include <fstream>
#include "../lib/tm_usage.h"
#include "WorkerAnt.h"

typedef vector< int > Data;
typedef vector< Data > DataList;


using namespace std;
//using namespace WorkerAnt;



void help_message() {
    cout << "usage: WorkerAnt -[GD|DP] <input_file> <output_file>" << endl;
    cout << "options:" << endl;
    cout << "   GD  - Greedy" << endl;
    cout << "   DP  - Dynamic Programming" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 4) {
       help_message();
       return 0;
    }
    CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;

    //////////// read the input file and make data structure/////////////

	int capacity;
	int NumOfFood;
    fstream fin(argv[2]);
    fstream fout;
    fout.open(argv[3],ios::out);
    fin>>capacity;
    fin>>NumOfFood;
    
   
	DataList FoodInfo;
	vector<int>first(4,0);
	FoodInfo.push_back(first);
	int x;
	int y;
	int weight;
	while(fin>>x>>y>>weight)
	{
		Data temp(3);
		temp[0] = x;
		temp[1] = y;
		temp[2] = weight;
		FoodInfo.push_back(temp);
	}
		
    //////////// find the solution to pick up the food ////
    tmusg.periodStart();
	WorkerAnt test;

    if(strcmp(argv[1], "-GD") == 0) {
		int distance = 0;
		Data position1;
		test.Greedy(FoodInfo,FoodInfo.size()-1,capacity,position1,distance);
	
		for(int i=0;i<position1.size();i++)
		{
			fout<<position1[i]<<endl;
		}
	
		fout<<distance<<endl;
       
    }
    else if(strcmp(argv[1], "-DP") == 0) {
		int* minimalDist = new int[FoodInfo.size()];
		//int* position = new int[FoodInfo.size()];
		Data position;
		
		//cout<<"asdfasdfasdfasdfasdf"<<endl;
		test.ShortestPath(NumOfFood,capacity,FoodInfo,minimalDist,position);
		
		for(int i=position.size()-1;i>=0;i--)
		{
			fout<<position[i]<<endl;
		}
		
		//fout<<FoodInfo.size()-1<<endl;
		fout<<minimalDist[FoodInfo.size()-1]<<endl;
		delete [] minimalDist;
		//delete [] position;
    }
    else {
        help_message();
        return 0;
    }

    tmusg.getPeriodUsage(stat);

    //////////// write the output file ///////////


    cout <<"# run time = " << (stat.uTime + stat.sTime) / 1000000.0 << "sec" << endl;
    cout <<"# memory =" << stat.vmPeak / 1000.0 << "MB" << endl;

    return 0;
}

