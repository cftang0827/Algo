 // **************************************************************************
//  File       [main.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of worker ant function]
//  Modify     [2015/03/20 Yu-Hao Ho]
// **************************************************************************

#include "WorkerAnt.h"
#include <cmath>
#include <iostream>
typedef vector< int > Data;
typedef vector< Data > DataList;


WorkerAnt::WorkerAnt(){}

int WorkerAnt::dist(int point1, int point2, DataList& food)
{
	int x_path = 0;
	int y_path = 0;
	int all_path = 0;
	if(point1 == point2)
	{
		return 0;
	}
	else
	{
		for(int i = point1; i < point2; i++ )
		{
			int t = abs(food[i+1][1] - food[i][1])+abs(food[i+1][0] - food[i][0]);
			all_path = all_path + t;
		}
	
		return all_path;
	}
}

int WorkerAnt::dist2origin(int last_point, DataList& food)
{
	int x_path = 0;
	int y_path = 0;
	int all_path = 0;
	
	x_path = abs(food[last_point][0] - 0);
	y_path = abs(food[last_point][1] - 0);
	all_path = x_path + y_path;
	
	return all_path;
}

void WorkerAnt::ShortestPath(int food_num, int capacity, DataList& food, int minimalDist[], Data& position )
{
	minimalDist[0] = 0;	
	int temp = 0;
	int* position2 = new int[food_num+1];
	for(int i=1; i<= food_num;i++)
	{
		int q = 2147483647;	
		for(int j=0;j<i;j++)
		{
			if(CapacityCheck(j+1,i,capacity,food))
			{
				temp = minimalDist[j]+ dist2origin(j+1, food) + dist(j+1, i, food) + dist2origin(i, food);
				if(q>temp)
				{
					q = temp;
					position2[i] = j;
				}		
			}		
		}
			minimalDist[i] = q;
	}
	
	position.push_back(food_num);
	int temp1 = food_num;
	//cout<<"asdfasdfasdf"<<endl;
	while(position2[temp1] > 0 )
	{
		temp1 = position2[temp1];
		position.push_back(temp1);
		//cout<<"i";
	}
	
	
	
}


bool WorkerAnt::CapacityCheck(int begin ,int end ,int capacity ,DataList& food)
{
	int temp = 0;
	for(int i = begin; i <= end; i++)
	{
		temp = temp+ food[i][2];
	}
	if(temp <= capacity)
	{
		return true;
	}
	else if(temp > capacity){
		return false;
	}
}

void WorkerAnt::Greedy(DataList& food, int food_num, int capacity,Data& position ,int& distance)
{
	int weight = 0;
	int start = 1;
	
	for(int i = start;i<= food_num;i++)
	{
		if(!CapacityCheck(start,i,capacity,food))
		{
			distance = distance + dist2origin(start, food) + dist(start, i-1, food) + dist2origin(i-1, food);
			start = i;
			position.push_back(--i);
		}
		
		if(i == food_num)
		{
			distance = distance + dist2origin(start, food) + dist(start, i, food) + dist2origin(i, food);
		}
	}
	position.push_back(food_num);
}