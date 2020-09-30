#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "randlib.h" 
#include "nodes.h"

Nodes::Nodes(){

	head = NULL;
	nodeCount = 0;
	numLinks = 0;
	
}


Nodes::~Nodes(){
	if(head == NULL) return;
	Node *n = head;
	Node *p;
	while(n != NULL){
	p = n;
	n = n->next;
	delete(p);
	}

}
void Nodes::positionNodes(){  // method refreshes the positions of the nodes
	Node *n = head;
	if(nodeCount == 0) return;
	
	for(int i = 0;i<maxNodes; i++){
		for(int j = 0;j<maxNodes; j++){
			positions[i][j]  = 0;	
		}
	}
	while(n != NULL){
	if(n->status)	
	  positions[n->posx][n->posy] = 1;
	if(!n->status) positions[n->posx][n->posy] = 2;
	
	n = n->next;
	
	}
		
}

void Nodes::updateLinks(){
	
	Node *n, *p;
	double dist;
	int j = 0;
	int i =0;
	int deltax, deltay;
	n=head;
	numLinks = 0;
	j = i = 0;
	while(n!= NULL){
		
		while(p!= NULL){
			
			deltax = n->posx - p->posx;
			deltay = n->posy - p->posy;
			dist = sqrt(fabs(deltax*deltax + deltay*deltay ));
			if(dist  <= maxD){
				numLinks++;
				}
			
			p=p->next;
			
		}
		
		n = n->next;
		p = head;
		
	}
	
}

void  Nodes::updatePositions(const double t){
	
	Node *n = head;
	double angl, sped;
	int nex,ney, oldx, oldy;
	int deltax, deltay;
	if(head == NULL) return;
	
	while(n!= NULL){	//posx, posy, destx, desty;
	oldx = n->posx;
	oldy = n->posy;
	sped = n->speed;
	deltax = n->destx - oldx;
	deltay = n->desty - oldy;
	if(deltax != 0)
	       angl = atan(deltay/deltax);
	else{ angl = 90;}
	nex = oldx + sped*cos(angl)* t;
	ney = oldy + sped*sin(angl)* t;
	
	if(nex > xmax) nex = xmax;
	if(ney >ymax) ney = ymax; // we confine node inside area
	
	
	n->setPosition(nex,ney);//assign a position for node
	
	if(nex == n->destx && ney == n->desty ){//node reached its destination
		nex= (int)(rand()/(double)RAND_MAX * xmax);
		ney = (int)(rand()/(double)RAND_MAX * ymax);
		n->setDestination(nex,ney);
	}
	if(nex == xmax && ney == xmax){//any node on the boarder gets a new destination
		nex= (int)(rand()/(double)RAND_MAX * xmax);
		ney = (int)(rand()/(double)RAND_MAX * ymax);
		n->setDestination(nex,ney);
	} 
	n = n->next;
	
	}
	positionNodes();
	
}

void Nodes::printNodes(){
	Node *n = head;
	
	if(nodeCount == 0) return;
	positionNodes();
	
	cout<<"===================Nodes========================="<<endl;
	for(int i = 0;i<maxNodes; i++){
		cout <<"|";
		for(int j = 0;j<maxNodes; j++){
			if (positions[i][j] == 1) cout <<"O";
			if (positions[i][j] == 2) cout <<"X";
			else cout <<"      ";
		}
		cout<<"|"<<endl;
	}
	cout<<"==============================================="<<endl;	
}

void Nodes::addNode(Node *node){
	
	if (head == NULL){
		head = node;
		node->next = NULL;
		nodeCount++;
		return;
	}
	node->next = head;
	head = node;
	nodeCount++;
	positionNodes();
	//printNodes();
	
}

void Nodes::deleteNode(int i){
	
	if(head == NULL) return;
	if (i > nodeCount || i < 0) return;
	int j=0;
	Node *n = head;
	Node *p;
	while(n!= NULL){
		if(j == i)break;
		p = n;
	    n = n->next;
	    j++;
		}
	p->next = n->next;
	delete(n);
	nodeCount--;
	positionNodes();
	
}
