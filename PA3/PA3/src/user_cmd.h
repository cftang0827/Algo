// **************************************************************************
// File       [ test_cmd.h ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2012/04/10 created ]
// **************************************************************************

#ifndef _TEST_CMD_H_
#define _TEST_CMD_H_
#include "graph.h"
#include "../lib/cmd.h"

class TestCmd : public CommonNs::Cmd {
public:
         TestCmd(const char * const name);
         ~TestCmd();

    bool exec(int argc, char **argv);
};


class ReadGraph : public CommonNs::Cmd {
public:
		ReadGraph(const char * const name);
		~ReadGraph();
		bool check_num(char inp);
		
		bool exec(int argc, char **argv);
};

class WriteBFS : public CommonNs::Cmd {
public: 
		WriteBFS(const char * const name);
		~WriteBFS();
		bool exec(int argc, char** argv);
};

class WriteDFS : public CommonNs::Cmd
{
public: 
		WriteDFS(const char* const name);
		~WriteDFS();
		bool exec(int argc, char** argv);
		void DFS(Graph*,vector< vector<int> >&);
		void DFS_visit(Graph*,Node*,vector< vector<int> >&);
		
};

class Colorgraph : public CommonNs::Cmd{
public:
		Colorgraph(const char* const name);
		~Colorgraph();
		///bool myfunc(Node*,Node*);
		bool exec(int argc, char** argv);


};

#endif
