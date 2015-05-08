#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> dot1;
vector<string> dot2;
vector< vector<string> > dot;
vector<int> position;

bool check_num(char inp)
{
	if(inp == '1' ||inp == '2' || inp == '3' ||inp == '4' ||inp == '5' ||inp == '6' ||inp == '7' ||inp == '8' ||inp == '9' ||inp == '0' )
	{
		return true;
	}else 
	return false;
}





int main(int argc, char**argv)
{
	fstream in(argv[1],fstream::in);
	//string dot1_t,dot2_t,mid;
	string all;
	int count = 1;
	vector<string> dot;
	vector< vector<string> > dot_overall;
	string dot_temp;
	while(getline(in,all))
	{
		if(all[0] == 'v')
		{
			all.erase(all.end()-1);
			//cout<<all<<endl;
			for(int i=0 ;i<all.size();i++)
			{
				if(all[i] == 'v')
				{
					
					int count = i+1;
					while(check_num(all[count]))
					{
						dot_temp = dot_temp + all[count];
						count++;
					}
					dot.push_back(dot_temp);
					//cout<<dot_temp<<endl;
					dot_temp.clear();
					
					
					

				}
			}
			
			//cout<<"print!"<<endl;
			
			
			
			dot_overall.push_back(dot);
			dot.clear();
			
			
		}
		
		//cout<<"size: "<<endl;
		//cout<<"dot_overall size: "<<dot_overall.size();
		/*
		if(dot1_t[0] == 'v')
		{
			dot1.push_back(dot1_t);
		}
		if(dot2_t[0] == 'v')
		{
			dot2.push_back(dot1_t);
		}*/
		
		
		
		//system("PAUSE");
		
		
		
		
	}
	//cout<<"dot: "<<endl;
	for(int i=0; i<dot_overall.size();i++)
	{
		
			cout<<dot_overall[i][0]<<" ";
			cout<<dot_overall[i][1]<<endl;
		
	}
	
	
	
	
	
}