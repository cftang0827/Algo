// **************************************************************************
// File       [ test_cmd.cpp ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2012/04/10 created ]
// **************************************************************************

#include "user_cmd.h"
#include "graph.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include "../lib/tm_usage.h"
#include <queue>
#include <algorithm>
using namespace std;
using namespace CommonNs;
//using namespace Graph;
char G[30];
Graph *temp;
Graph* temp1;
Graph* temp2;
Graph* temp3;
int time1;
bool myfunc(Node* a, Node* b);
void draw_next(int,vector<int>);
void draw_rest(Graph* ,vector<int>);
int flag;
int color_num;
int diffColorNum(int,vector<int>);
bool finding(vector<int>& inp , int flag);
bool myfunc1(Node* a, Node* b);
vector<int> position_color;
fstream in1;
//vector< vector<string> > dot_overall;


TestCmd::TestCmd(const char * const name) : Cmd(name) {
	optMgr_.setShortDes("test");
	optMgr_.setDes("test");

	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);

	opt = new Opt(Opt::STR_REQ, "print the string of -s", "[string]");
	opt->addFlag("s");
	optMgr_.regOpt(opt);
}

TestCmd::~TestCmd() {}

bool TestCmd::exec(int argc, char **argv) {
	optMgr_.parse(argc, argv);

	if (optMgr_.getParsedOpt("h")) {
		optMgr_.usage();
		return true;
	}

	if (optMgr_.getParsedOpt("s")) {
		printf("%s\n", optMgr_.getParsedValue("s"));
	}
	else
	printf("hello world !!\n");


	return true;
}

ReadGraph::ReadGraph(const char * const name) : Cmd(name) {
	optMgr_.setShortDes("test");
	optMgr_.setDes("test");

	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);

	opt = new Opt(Opt::STR_REQ, "print the string of -s", "[string]");
	opt->addFlag("s");
	optMgr_.regOpt(opt);
}

ReadGraph::~ReadGraph() {}


bool ReadGraph::check_num(char inp)
{
	if(inp == '1' ||inp == '2' || inp == '3' ||inp == '4' ||inp == '5' ||inp == '6' ||inp == '7' ||inp == '8' ||inp == '9' ||inp == '0' )
	{
		return true;
	}else 
	return false;
}

bool ReadGraph::exec(int argc, char **argv)
{
	CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;
	optMgr_.parse(argc, argv);
	
	if (optMgr_.getParsedOpt("h")) {
		optMgr_.usage();
		return true;
	}

	if (optMgr_.getParsedOpt("s")) {
		printf("%s\n", optMgr_.getParsedValue("s"));
	}else{
		//temp->clear();
		//delete temp;
		temp = new Graph("temp");
		//in.clear();
		fstream in;
		in.open(argv[1],fstream::in);
		in1.open(argv[1],fstream::in);
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
				
				dot_overall.push_back(dot);
				dot.clear();
			}
			
		}/*
		for(int i=0; i<dot_overall.size();i++)
		{
			cout<<dot_overall[i][0]<<" ";
			cout<<dot_overall[i][1]<<endl;			
		}	*/
		
		for(int i=0; i<dot_overall.size();i++)
		{
			int a,b;
			stringstream temp_a;
			stringstream temp_b;
			temp_a<<dot_overall[i][0];
			temp_b<<dot_overall[i][1];
			temp_a>>a;
			temp_b>>b;
			temp->addEdge(a,b);
			temp_a.clear();
			temp_b.clear();
		}
		//cout<<"test!"<<endl;
		/*
		for(int i=0;i<temp->nodes.size();i++)
		{
			cout<<temp->nodes[i]->id<<" ";
		}*/
		//cout<<endl;
		//cout<<"edge!";
		//cout<<temp->getNodeById(2)->edge.size()<<endl;
		/*
		for(int i = 0; i<2;i++)
		{
			cout<<temp->getNodeById(2)->edge[i]->node[0]->id<<" "<<temp->getNodeById(2)->edge[i]->node[1]->id<<endl;
		}
		cout<<endl;
		*/
	}
	//fin.close();
	return true;
	
}

WriteBFS::WriteBFS(const char * const name) : Cmd(name) {
	optMgr_.setShortDes("test");
	optMgr_.setDes("test");

	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);

	opt = new Opt(Opt::STR_REQ, "print the string of -s", "[string]");
	opt->addFlag("s");
	optMgr_.regOpt(opt);
	
	opt = new Opt(Opt::STR_REQ, "print the string of -o", "[string]");
	opt->addFlag("o");
	optMgr_.regOpt(opt);
}

WriteBFS::~WriteBFS(){}

bool WriteBFS::exec(int argc, char **argv)
{

	CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;
	optMgr_.parse(argc, argv);
	
	if (optMgr_.getParsedOpt("h")) {
		optMgr_.usage();
		return true;
	}

	if (optMgr_.getParsedOpt("s") && optMgr_.getParsedOpt("o"))
	{
		//string outname(optMgr_.getParsedOpt("o"));
		//cout<<"1"<<endl;
		fstream output1(optMgr_.getParsedValue("o"),fstream::out);
		vector< vector<int> > out;

		temp1 = new Graph("temp1");
		for(int i=0;i<temp->edges.size();i++)
		{
			temp1->addEdge(temp->edges[i]->node[0]->id,temp->edges[i]->node[1]->id);
		}



		tmusg.periodStart();
		//cout<<"write to "<<optMgr_.getParsedValue("s")<<endl;
		//cout<<"start from"<<optMgr_.getParsedValue("o")<<endl;
		temp1->sortEdgesOfNode();
        temp1->sortNodesByDegree();
        temp1->sortNodesByID();

		string beginV(optMgr_.getParsedValue("s"));
		beginV.erase(beginV.begin());
		//cout<<"string beginV: "<<beginV<<endl;
		stringstream ss;
		int begin_point = 0;
		ss<<beginV;
		ss>>begin_point;
		//Graph *bfs = new Graph("BFS");

		//Node *begin = new Node(begin_point);

		//cout<<"begin_point "<<begin_point<<endl;
		//doing add edge
		/*
		for(int i=0 ;i< begin.edge.size(); i++)
		{
			bfs.addEdge(begin.edge[i].node[0],begin.edge[i].node[1]);
		}*/
		//cout<<"2"<<endl;
		temp1->init();
		/*
		for(int i=0;i<temp1->nodes.size();i++)
		{
			temp1->nodes[i]->color = -1;
			temp1->d = DIS_INF;
		}*/
		temp1->getNodeById(begin_point)->color = 1;
		temp1->getNodeById(begin_point)->d = 0;
		temp1->getNodeById(begin_point)->prev = 0;
		//cout<<"3"<<endl;
		queue<Node*> Q;
		//Q.clear();
		Q.push(temp1->getNodeById(begin_point));
		//cout<<"Q.push(begin) "<<endl;
		//cout<<"begin.id = "<<temp1->getNodeById(begin_point)->id<<endl;
		while(!Q.empty())
		{
			//cout<<"go into while!"<<endl;
			Node* u = Q.front();
			//cout<<"Q.front u->id"<<u->id<<endl;
			Q.pop();
			//cout<<"u->edge.size(): "<<u->edge.size()<<endl;
			for(int i=0; i<u->edge.size() ; i++)
			{
				if(u->edge[i]->getNeighbor(u)->color == -1)
				{
					u->edge[i]->getNeighbor(u)->color = 1;
					u->edge[i]->getNeighbor(u)->d = u->d +1;
					u->edge[i]->getNeighbor(u)->prev = u;
					//cout<<"bfs->addEdge(u->id,u->edge[i]->getNeighbor(u)->id) "<<u->id<<" "<<u->edge[i]->getNeighbor(u)->id<<endl;
					vector<int> temp12;
					temp12.push_back(u->id);
					temp12.push_back(u->edge[i]->getNeighbor(u)->id);
					out.push_back(temp12);
					//bfs->addEdge(u->id,u->edge[i]->getNeighbor(u)->id);
					Q.push(u->edge[i]->getNeighbor(u));
				}
			}
			u->color = 0;
			delete u;
		}
		//cout<<"4"<<endl;

		//bfs->sortEdgesOfNode();
        //bfs->sortNodesByDegree();
        //bfs->sortNodesByID();

		/*
		cout<<"bfs->edges.size() "<<bfs->edges.size()<<endl;
		
		for(int i=0;i<bfs->edges.size();i++)
		{
			cout<<"point: "<<bfs->edges[i]->node[0]->id<<" "<<bfs->edges[i]->node[1]->id<<endl;
		}

		cout<<"vertice: "<<bfs->nodes.size()<<endl;
		cout<<"edges: "<<bfs->edges.size()<<endl;
	*/
		int max = 0;
		for(int i=0;i<out.size();i++)
		{
			if(out[i][0] > max)
			{
				max = out[i][0];
			}
			if(out[i][1] > max)
			{
				max = out[i][1];
			}
			//cout<<out[i][0]<< " -- " <<out[i][1]<<endl;
		}
		//cout<<"5"<<endl;
		output1<<"// BFS tree produced by graphlab"<<endl;
		output1<<"graph gn"<<max+1<<"_bfs {"<<endl;
		for(int i=0;i<out.size();i++)
		{
			output1<<"v"<<out[i][0]<< " -- " <<"v"<<out[i][1]<<";"<<endl;
		}
		output1<<"}"<<endl;
		output1<<"// vertices = "<<max+1<<endl;
		output1<<"// edges = "<<out.size()<<endl;
		tmusg.getPeriodUsage(stat);
		output1<<"// runtime = "<<(double)(stat.uTime + stat.sTime)/(double)1000000<<" sec"<<endl;
		output1<<"// memory = " << stat.vmPeak/1000 << " MB" << endl;
		out.clear();
		//cout<<"6"<<endl;
			return true;
	
	}

	else{
		cout<<"input_error"<<endl;
		return true;
	}

}


WriteDFS::WriteDFS(const char * const name) : Cmd(name) {
	optMgr_.setShortDes("test");
	optMgr_.setDes("test");

	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);

	opt = new Opt(Opt::STR_REQ, "print the string of -s", "[string]");
	opt->addFlag("s");
	optMgr_.regOpt(opt);
	
	opt = new Opt(Opt::STR_REQ, "print the string of -o", "[string]");
	opt->addFlag("o");
	optMgr_.regOpt(opt);
}

WriteDFS::~WriteDFS(){}

bool WriteDFS::exec(int argc, char **argv)
{
	CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;
	optMgr_.parse(argc, argv);
	
	if (optMgr_.getParsedOpt("h")) {
		optMgr_.usage();
		return true;
	}

	if (optMgr_.getParsedOpt("s") && optMgr_.getParsedOpt("o"))
	{
		
		temp2 = new Graph("temp2");
		for(int i=0;i<temp->edges.size();i++)
		{
			temp2->addEdge(temp->edges[i]->node[0]->id,temp->edges[i]->node[1]->id);
		}
		
		
		fstream output1(optMgr_.getParsedValue("o"),fstream::out);
		tmusg.periodStart();
		//cout<<"1"<<endl;
		//Graph *dfs = new Graph("DFS");
		temp2->sortEdgesOfNode();
        temp2->sortNodesByDegree();
        temp2->sortNodesByID();
		string beginV(optMgr_.getParsedValue("s"));
		beginV.erase(beginV.begin());
		//cout<<"string beginV: "<<beginV<<endl;
		//cout<<"2"<<endl;
		stringstream ss;
		int begin_point = 0;
		ss<<beginV;
		ss>>begin_point;
		//Graph *dfs = new Graph("DFS");
		vector< vector<int> > dfs;
		//cout<<"3"<<endl;
		DFS(temp2,dfs);
		//cout<<"4"<<endl;
		time1 = 0;
		//dfs->sortEdgesOfNode();
        //dfs->sortNodesByDegree();
        //dfs->sortNodesByID();

		//cout<<"dfs->edges.size() "<<dfs->edges.size()<<endl;
		/*
		for(int i=0;i<dfs->edges.size();i++)
		{
			cout<<"point: "<<dfs->edges[i]->node[0]->id<<" "<<dfs->edges[i]->node[1]->id<<endl;
		}*/

		//cout<<"vertice: "<<dfs->nodes.size()<<endl;
		//cout<<"edges: "<<dfs->edges.size()<<endl;
		int max = 0;

		for(int i=0;i<dfs.size();i++)
		{
			if(dfs[i][0] > max)
			{
				max = dfs[i][0];
			}
			if(dfs[i][1] > max)
			{
				max = dfs[i][1];
			}
			//cout<<dfs[i][0]<< " -- " <<dfs[i][1]<<endl;
		}
		//cout<<"5"<<endl;
		output1<<"// DFS tree produced by graphlab"<<endl;
		output1<<"graph gn"<<max+1<<"_dfs {"<<endl;
		for(int i=0;i<dfs.size();i++)
		{
			output1<<"v"<<dfs[i][0]<< " -- " <<"v"<<dfs[i][1]<<";"<<endl;
		}
		output1<<"}"<<endl;



		output1<<"// vertices = "<<max+1<<endl;
		output1<<"// edges = "<<dfs.size()<<endl;
		tmusg.getPeriodUsage(stat);
		output1<<"// runtime = "<<(double)(stat.uTime + stat.sTime)/(double)1000000<<" sec"<<endl;
		output1<<"// memory = " << stat.vmPeak/1000 << " MB" << endl;
		dfs.clear();	



			return true;







	}

}




void WriteDFS::DFS(Graph* inp, vector< vector<int> >& oup)
{
	//cout<<"dfs goto!!"<<endl;

	for(int i=0 ;i<temp2->nodes.size();i++)
	{
		temp2->nodes[i]->color = -1;
		temp2->nodes[i]->prev = 0;
	}
	time1 = 0;
	for(int j = 0; j<temp2->nodes.size();j++)
	{
		if(temp2->nodes[j]->color == -1)
		{
			DFS_visit(inp,temp2->nodes[j],oup);
		}
	}
}




void WriteDFS::DFS_visit(Graph* inp, Node* u,vector< vector<int> >& oup)
{
	//cout<<"visit goto!!"<<endl;
	time1 = time1 + 1;
	u->d = time1;
	u->color = 1;
	for(int i=0; i<u->edge.size() ; i++)
	{
		if(u->edge[i]->getNeighbor(u)->color == -1)
		{
			u->edge[i]->getNeighbor(u)->prev = u;

			vector<int> temp123;
			temp123.push_back(u->id);
			temp123.push_back(u->edge[i]->getNeighbor(u)->id);

			oup.push_back(temp123);


			//oup->addEdge(u->edge[i]->getNeighbor(u)->id,u->id);

			WriteDFS::DFS_visit(inp,u->edge[i]->getNeighbor(u),oup);
		}
	}

	u->color = 0;
	time1 = time1 + 1;
	u->f = time1;
}




Colorgraph::Colorgraph(const char * const name) : Cmd(name) {
	optMgr_.setShortDes("test");
	optMgr_.setDes("test");

	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);

	opt = new Opt(Opt::STR_REQ, "print the string of -m", "[string]");
	opt->addFlag("m");
	optMgr_.regOpt(opt);
	
	opt = new Opt(Opt::STR_REQ, "print the string of -o", "[string]");
	opt->addFlag("o");
	optMgr_.regOpt(opt);
}

Colorgraph::~Colorgraph(){}

bool Colorgraph::exec(int argc, char **argv)
{
	//cout<<"1"<<endl;
	CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;
	optMgr_.parse(argc, argv);
	
	if (optMgr_.getParsedOpt("h")) {
		optMgr_.usage();
		return true;
	}
	//cout<<"2"<<endl;
	if (optMgr_.getParsedOpt("m") && optMgr_.getParsedOpt("o"))
	{
		temp3 = new Graph("temp3");
		for(int i=0;i<temp->edges.size();i++)
		{
			temp3->addEdge(temp->edges[i]->node[0]->id,temp->edges[i]->node[1]->id);
		}
		
		
		
		
		tmusg.periodStart();
		//cout<<"3"<<endl;
		fstream output1(optMgr_.getParsedValue("o"),fstream::out);
		string temp11(optMgr_.getParsedValue("m") );
		if(temp11 == "greedy")
		{

			int max_adj = 0;
			int max_id = 0;
			/*
			for(int i=0 ; i<temp->nodes.size(); i++)
			{
				if(temp->nodes[i]->edge.size() >max_adj)
				{
					max_adj = temp->nodes[i]->edge.size();
					//max_id = temp->nodes[i]->id;
				}else if(temp->nodes[i]->edge.size()  == max_adj && temp->nodes[i]->id < max_id)
				{
					max_adj = temp->nodes[i]->edge.size();
					max_id = temp->nodes[i]->id;
				}
			}*/

//cout<<"4"<<endl;
			sort(temp3->nodes.begin(),temp3->nodes.end(),myfunc );	
			//cout<<"5"<<endl;

/*
			for(int i=0 ;i<temp3->nodes.size(); i++)
			{
				cout<<temp3->nodes[i]->id<<" ";
			}
			cout<<endl;
			cout<<"max_id: "<<temp3->nodes[0]->id<<endl;
			cout<<"max_adj: "<<temp3->nodes[0]->edge.size()<<endl;
*/
			vector<int> level(temp3->nodes.size());
//cout<<"5.5"<<endl;
			for(int i=0 ;i<temp3->nodes.size();i++)
			{
				level[temp3->nodes[i]->id] = i;
			}
			//cout<<"5.6"<<endl;
/*
			for(int i=0;i<level.size();i++)
			{
				cout<<level[i]<<" ";
			}
			cout<<endl;
*/

			//coloring
			flag = 0;
			color_num = 1;
			//cout<<"5.77"<<endl;
			for(int i=0 ;i<temp3->nodes.size();i++)
			{
				temp3->nodes[i]->color = -1;
			}
			//cout<<"6"<<endl;
			temp3->nodes[0]->color = color_num;
			//cout<<"v"<<temp3->nodes[0]->id<<" color = "<<	temp3->nodes[0]->color <<endl;
			draw_next(0,level);
			draw_rest(temp3,level);

			sort(temp3->nodes.begin(),temp3->nodes.end(),myfunc1 );
			int howmuch = 0;
			output1<<"// Coloring produced by graphlab"<<endl;
			output1<<"graph gn"<<temp3->nodes.size()<<"_color {"<<endl;
			string all;
			//cout<<"7"<<endl;
			while(getline(in1,all))
			{
				if(all[0] == 'v')
				{
					output1<<all<<endl;
				}
			}



			for(int i = 0;i<temp3->nodes.size();i++)
			{
				if(temp3->nodes[i]->color > howmuch)
				{
					howmuch = temp3->nodes[i]->color;
				}
				output1<<"v"<<temp3->nodes[i]->id<<" [label = \"v"<<temp3->nodes[i]->id<<"_color"<<temp3->nodes[i]->color<<"\"];"<<endl;
			}
			output1<<"}"<<endl;
			output1<<"// vertices = "<<temp3->nodes.size()<<endl;
			output1<<"// edges = "<<temp3->edges.size()<<endl;
			output1<<"// number_of_colors = "<<howmuch<<endl;
			tmusg.getPeriodUsage(stat);
			output1<<"// runtime = "<<(double)(stat.uTime + stat.sTime)/(double)1000000<<" sec"<<endl;
			output1<<"// memory = " << stat.vmPeak/1000 << " MB" << endl;
			//cout<<"howmuch "<<howmuch<<endl;
		}

			return true;
			
		
	}else{
		cout<<"error input!"<<endl;
	}
}

bool myfunc(Node* a, Node* b)
{
	if(a->edge.size() == b->edge.size() )
	{

		return a->id < b->id ;
	}else
	{
		return a->edge.size() > b->edge.size();
	}
}

bool myfunc1(Node* a, Node* b)
{
	return a->id < b->id;
}
/*
void draw_next(Node* a,vector<int>& level)
{
	//u->edge[i]->getNeighbor(u)
	if(flag != level.size()-1)
	{
		int j;
		for(int i=0;i<a->edge.size();i++)
		{
			if(level[a->edge[i]->getNeighbor(a)->id] == flag && a->edge[i]->getNeighbor(a)->color == -1)
			{
				cout<<"draw: "<<a->edge[i]->getNeighbor(a)->id<<endl;
				j = i;
				break;

			}else{
				flag++;
			}
		}
		draw_next(a->edge[j]->getNeighbor(a),level);
	}else{
		cout<<"end"<<endl;
	}
}*/

void draw_next(int id1,vector<int> level)
{
	
	int min = 2147483647;
	//temp3->getNodeById(id1)
	for(int i=0;i<temp3->nodes[id1]->edge.size();i++)
	{
		//cout<<"aa"<<temp3->nodes[id1]->edge[i]->getNeighbor(temp3->nodes[id1])->id<<endl;
		if(temp3->nodes[id1]->edge[i]->getNeighbor(temp3->nodes[id1])->color == -1 && level[temp3->nodes[id1]->edge[i]->getNeighbor(temp3->nodes[id1])->id ] < min  )
		{
			min = level[temp3->nodes[id1]->edge[i]->getNeighbor(temp3->nodes[id1])->id ];
		}
	}

	if(min < 2147483647)
	{
		//cout<<"draw node"<< (temp3->nodes[min]->id)<<endl;

		temp3->nodes[min]->color = diffColorNum(temp3->nodes[min]->id,level);
		draw_next(temp3->nodes[level[min]]->id, level);
	}
	//cout<<endl;

	


}


int diffColorNum(int id2, vector<int>level)
{
	vector<int> colorNum;
	for(int i= 0 ;i<temp3->nodes[level[id2]]->edge.size();i++)
	{
		//cout<<"node"<<temp3->nodes[level[id2]]->edge[i]->getNeighbor(temp3->nodes[level[id2]])->id<<" color = "<<temp3->nodes[level[id2]]->edge[i]->getNeighbor(temp3->nodes[level[id2]])->color<<endl;
		if( temp3->nodes[level[id2]]->edge[i]->getNeighbor(temp3->nodes[level[id2]])->color != -1  )
		{
			colorNum.push_back(temp3->nodes[level[id2]]->edge[i]->getNeighbor(temp3->nodes[level[id2]])->color);
		}
	}


	int maxColor = 0;
	std::vector<int>::iterator it;
	//cout<<"colorNum:::"<<endl;
	for(int i = 0;i<colorNum.size();i++)
	{
		//cout<<colorNum[i]<<" ";
		if( colorNum[i] > maxColor  )
		{
			maxColor = colorNum[i];
		}
	}
	//cout<<endl;
	//cout<<"maxColor = "<<maxColor<<endl;
	int j = -100;
	for(int i=1;i<=maxColor;i++)
	{
		if(! finding(colorNum,i)  )
		{
			j = i;
			break;
		}else{
			continue;
		}
	}
	//cout<<"j = "<<j<<endl;

	if(j == -100)
	{
		return maxColor + 1;
	}else 
	{
		if(maxColor == 1)
		{
			return maxColor+1;
		}else{
			return j;
		}
	}


}

bool finding(vector<int>& inp , int flag)
{
	bool look = false;
	for(int i=0;i<inp.size();i++)
	{
		if(inp[i] == flag)
		{
			look = true;
		}
	}

	return look;
	
}
/*
	vector<int> colorNum;
	for(int i=0; i<temp3->nodes[level[id2]]->edge.size(); i++)
	{
		if(temp3->nodes[level[id2]]->edge[i]->getNeighbor(temp3->nodes[level[id2]])->color != -1)
		{
			colorNum.push_back(temp3->nodes[level[id2]]->edge[i]->getNeighbor(temp3->nodes[level[id2]])->color);
			//cout<<"1: "<<temp3->nodes[id2]->edge[i]->getNeighbor(temp3->nodes[id2])->color<<endl;
		}
	}

	

	sort(colorNum.begin(),colorNum.end());
	colorNum.erase(unique(colorNum.begin(),colorNum.end()),colorNum.end());

	//cout<<"colorNum.size() "<<colorNum.size()<<endl;
	
	for(int i=1 ;i<=*max_element(colorNum.begin(),colorNum.end());i++)
	{
		if(find(colorNum.begin(),colorNum.end(),i) >= colorNum.begin())
		{
			continue;

		}else 
		{
			return i;
			break;
		}
	}

	
	//return colorNum.size();




}*/

void draw_rest(Graph* a, vector<int> level)
{
	for(int i= 0; i<a->nodes.size(); i++)
	{
		if(a->nodes[i]->color == -1)
		{
			a->nodes[i]->color = diffColorNum(a->nodes[i]->id,level);
			//cout<<"v"<<(a->nodes[i]->id)<<" color = "<<a->nodes[i]->color<<endl;
		}
	}
}