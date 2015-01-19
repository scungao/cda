#include "ast.h"
#include <iostream>
#include <string>

using namespace std;

ast::ast(symbol* s)
	:	head_symbol(s), terminal(true), 
		degree(0), height(0), parent(NULL)
{
	try{
		flatname = s -> get_name();
	}
	catch(exception& e){
		cout<<"AST: error on base. "<<e.what()<<endl;
	}
}

ast::ast(symbol* s, ast* l)
	:	head_symbol(s), terminal(false), degree(1), parent(NULL)
{
	flatname = s->get_name();
	children.push_back(l);
	flatname += "(";
	flatname += l->flatname;
	flatname += ")";
	height = (children[0]->height)+1;
}


ast::ast(symbol* s, ast* l1, ast* l2)
	:	head_symbol(s), terminal(false), degree(2), parent(NULL)
{
	flatname = s->get_name();

	children.push_back(l1);
	children.push_back(l2);

	flatname += "(";
	height = 0;
	for (int i=0; i<2; i++) {
		if ( children[i]->height > height ) 
			height = children[i]->height;
		flatname += children[i]->flatname;
		flatname += ",";
	}
	flatname.pop_back(); //delete trailing ","
	flatname += ")";
	height += 1;
}

ast::ast(symbol* s, ast* l1, ast* l2, ast* l3)
	:	head_symbol(s), terminal(false), degree(3), parent(NULL) 
{
	flatname = s->get_name();
	
	children.push_back(l1);
	children.push_back(l2);
	children.push_back(l3);

	flatname += "(";
	height = 0;
	for (int i=0; i<3; i++) {
		if ( children[i]->height > height ) 
			height = children[i]->height;
		flatname += children[i]->flatname;
		flatname += ",";
	}
	flatname.pop_back(); //delete trailing ","
	flatname += ")";
	height += 1;
}

ast::~ast() 
{
}