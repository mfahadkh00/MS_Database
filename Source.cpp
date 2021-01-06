//#include"BST.h"
#include"FadiBST.h"
//#include"AVL.h"
#include"Person.h"
#include"DatabaseInterface.h"
#include<iostream>
using namespace std;

void main()
{
	BST<int, Person*> natTree;
	databaseGen(&natTree);
	dbaseInterface(&natTree);
	
}

