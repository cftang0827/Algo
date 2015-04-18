// **************************************************************************
//  File       [WorkerAnt.h]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The header file of worker ant]
//  Modify     [2015/03/20 Yu-Hao Ho]
// **************************************************************************

#ifndef _WORKERANT_H
#define _WORKERANT_H
#include <vector>
#include <math.h>

using namespace std;
typedef vector< int > Data;
typedef vector< Data > DataList;	

class WorkerAnt
{
	public:
		WorkerAnt();

		void ShortestPath(int , int , DataList& , int[] , Data& );
		bool CapacityCheck(int, int, int, DataList& );
		int dist(int, int, DataList&);
		int dist2origin(int, DataList&);
		void Greedy(DataList& , int , int ,Data&  ,int& );
};
















#endif
