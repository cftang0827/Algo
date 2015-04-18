#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
	typedef vector<int> Data;
    typedef vector< Data > DataList;
int* ShortestPath(int, int, DataList&,Data&);
bool CapacityCheck(int, int, int, DataList& );
int dist(int, int, DataList&);
int dist2origin(int, DataList&);

int dist(int point1, int point2, DataList& food)
{
	int x_path = 0;
	int y_path = 0;
	int all_path = 0;
	if(point1 == point2)
	{
		return 0;
	}else{
	for(int i = point1; i < point2; i++ )
	{
		int t = abs(food[i+1][1] - food[i][1])+abs(food[i+1][0] - food[i][0]);
		all_path = all_path + t;
		
	}
	//all_path = x_path + y_path;
	
	return all_path;
	}
}

int dist2origin(int last_point, DataList& food)
{
	int x_path = 0;
	int y_path = 0;
	int all_path = 0;
	
	x_path = abs(food[last_point][0] - 0);
	y_path = abs(food[last_point][1] - 0);
	all_path = x_path + y_path;
	
	return all_path;
}




void ShortestPath(int food_num, int capacity, DataList& food, int minimalDist[], vector<int>& position )
{
	
	//int *minimalDist = new int[food_num+1];
	int* position2 = new int[food_num+1];
	for(int i=0;i<food_num+1;i++)
		position2[i] = 0;
	minimalDist[0] = 0;
	
	int temp = 0;
	
	int last;
	
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
					cout<<"i"<<i<<endl;
					cout<<"j"<<j<<endl;				}
					
			}	
			//system("PAUSE");		
				
		}
			
			minimalDist[i] = q;
			//cout<<"1234"<<minimalDist[i]<<endl;
		
	}
	position.push_back(food_num);
	int temp1 = food_num;
	//cout<<"sdffffffffffff"<<temp1<<endl;
	while(position2[temp1] != 0 )
	{
		//cout<<"a"<<temp1<<endl;
		temp1 = position2[temp1];
		position.push_back(temp1);
	}
	
	//return minimalDist;	
}






bool CapacityCheck(int begin ,int end ,int capacity ,DataList& food)
{
	//cout<<"bp5"<<endl;
	int temp = 0;
	for(int i = begin; i <= end; i++)
	{
		//cout<<"food["<<i<<"][2]"<<food[i][2]<<endl;
		temp = temp+ food[i][2];
	}
	//cout<<"temp__"<<temp<<endl;
	if(temp <= capacity)
	{
		return true;
	}
	else if(temp > capacity){
		return false;
	}
}


void Greedy(DataList& food, int food_num, int capacity,Data& position ,int& distance)
{
	int weight = 0;
	int start = 1;
	//int distance = 0;
	
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





int main(int argc, char* argv[])
{
	
	int capacity;
	int NumOfFood;
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2],ios::out);
    fin>>capacity;
    fin>>NumOfFood;
    int x;
	int y;
	int weight;
	
	

	DataList FoodInfo;
	vector<int>aa(4,0);
	FoodInfo.push_back(aa);
	while(fin>>x>>y>>weight)
	{
		Data temp(3);
		temp[0] = x;
		temp[1] = y;
		temp[2] = weight;
		FoodInfo.push_back(temp);
	}
	//test
	cout<<capacity<<endl;
	cout<<NumOfFood<<endl;
	//cout<<x<<" "<<y<<" "<<weight<<endl;
	
	for(int i=0;i<FoodInfo.size();i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<FoodInfo[i][j]<<" ";
		}
		cout<<endl;
	}
	//cout<<"capacity="<<capacity<<endl;
	//cout<<"size:"<<FoodInfo.size()<<endl;
	int *minimalDist = new int[FoodInfo.size()];
	//int* position = new int[FoodInfo.size()];
	vector<int> position;
	
	ShortestPath(FoodInfo.size()-1,capacity,FoodInfo,minimalDist,position);
	for(int i=1;i<=NumOfFood;i++)
	{
		cout<<minimalDist[i]<<endl;
	}
	cout<<"postition"<<endl;
	for(int i=position.size()-1;i>=0;i--)
		{
			cout<<position[i]<<endl;
		}
	//cout<<FoodInfo.size()-1<<endl;
	
	
	cout<<"GREEDY!"<<endl;
	
	int distance = 0;
	Data position1;
	Greedy(FoodInfo,FoodInfo.size()-1,capacity,position1,distance);
	
	for(int i=0;i<position1.size();i++)
	{
		cout<<position1[i]<<endl;
	}
	
	cout<<"distance"<<distance<<endl;
	
	
	
	
	
	
	
	cout<<"end"<<endl;
	
	/*
	cout<<CapacityCheck(0 , 3 , capacity ,FoodInfo);
	cout<<CapacityCheck(1 , 3 , capacity ,FoodInfo);
	cout<<CapacityCheck(2 , 3 , capacity ,FoodInfo);
	cout<<CapacityCheck(3 , 3 , capacity ,FoodInfo);
	
	cout<<endl;
	cout<<dist2origin(0, FoodInfo)<<endl;
	cout<<dist2origin(1, FoodInfo)<<endl;
	cout<<dist2origin(2, FoodInfo)<<endl;
	cout<<dist2origin(3, FoodInfo)<<endl;
	
	cout<<endl;
	
	//cout<<dist(0, 0, FoodInfo)<<endl;
	//c//out<<dist(0, 1, FoodInfo)<<endl;
	//cout<<dist(1, 2, FoodInfo)<<endl;
	
	//cout<<"asd"<<dist(0, 1, FoodInfo)+dist(1, 2, FoodInfo)+dist(2, 3, FoodInfo)<<endl;
	
	
	*/
	//cout<<dist2origin(1, FoodInfo);
	
}