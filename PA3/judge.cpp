#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc,char* argv[])
{
	string line1;
	string line2;
	ifstream in1(argv[1],ios::in);
	ifstream in2(argv[2],ios::in);
	bool right = true;
	int iter = 1;
    if (in1.is_open() && in2.is_open())
	{
		while ( getline (in1,line1) && getline(in2,line2))
		{
			if(line1 == line2)
			{
				iter++;
				continue;
			}else{
					right = false;
					cout<<"some where fail at "<<iter<<"!!!!"<<endl;
					break;
				}
		}
	}
	if(right == true)
	{
		cout<<"file same!!!YA"<<endl;
	}
	system("PAUSE");
    in1.close();
	in2.close();
  }
	
	
	
	
	
	

