/********************************************************
*	DESCRIPTION	: Atomic model Registry
* 
*	AUTHOR		: Monageng Kgwadi
* 
*	DATE		: 26-10-2007
* 
*
********************************************************/


/********** file includes ****************************/

#include "registry.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "randlib.h"         // Random numbers library
#include "message.h"         // InternalMessage 
#include "distri.h"          // class Distribution
#include "mainsimu.h"        // class MainSimulator
#include "strutil.h"   

  

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: NodeGenerator
* 
* Description: Constructor
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

Registry::Registry( const string &name) :
	Atomic(name),
	gen(addInputPort("gen")),
	deq(addInputPort("deq")),
	pos(addInputPort("pos")),
	lout(addOutputPort("lout")),
	aout( addOutputPort("aout")){
		
		
		nodes = new Nodes();	
		
	}
Model &Registry::initFunction()
{		
	int x,y,dsx,dsy;
	double s;
	Node *n;
		for(int i=0;i<defaultNodes;i++){
			
			 x = (int)(rand()/(double)RAND_MAX * xmax);
			 y = (int)(rand()/(double)RAND_MAX * ymax);
			 dsx = (int)(rand()/(double)RAND_MAX * xmax);
			 dsy = (int)(rand()/(double)RAND_MAX * ymax);
			 s = (double)(rand()/(double)RAND_MAX * smax);
			n = new Node(x,y,dsx,dsy,s,true);
	   		nodes->addNode(n); 
	    }
	   
	    //nodes->printNodes();
	    holdIn(Atomic::active, Time::Zero);
		return *this ; 
	};
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: external function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &Registry::externalFunction(const ExternalMessage &msg ){
	
	int x,y,dsx,dsy;
	double s;
	if(msg.port() == gen && msg.value() == 1) {
		 x = (int)(rand()/(double)RAND_MAX * xmax);
		 y = (int)(rand()/(double)RAND_MAX * ymax);
		 dsx = (int)(rand()/(double)RAND_MAX * xmax);
		 dsy = (int)(rand()/(double)RAND_MAX * ymax);
		 s = (double)(rand()/(double)RAND_MAX * smax);
		nodes->addNode(new Node(x,y,dsx,dsy,s,true));
		nodes->updateLinks();
		nodes->printNodes();
		//cout<<"Add"<<endl;
		}
		
	if(msg.port() == deq &&  msg.value() == 1){
		int r = (int)(rand()/(double)RAND_MAX *nodes->size());
		nodes->deleteNode(r);
		nodes->updateLinks();
		nodes->printNodes();
		
		//cout<< "delete"<< endl;
		}
	if(msg.port() == pos &&  msg.value() == 1){
		
		nodes->updatePositions(t);
		nodes->updateLinks();
		nodes->printNodes();
		//cout <<" positions "<<endl;
	}
	holdIn(active, Time::Zero);
	return *this;
}
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: internal function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &Registry::internalFunction(const InternalMessage & )
{
	
	passivate();
	return *this;
}
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: output function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &Registry::outputFunction(const InternalMessage &msg)
{
	
	this->sendOutput(msg.time(),aout,nodes->size());
	sendOutput(msg.time(), lout, nodes->getLinks());
	return *this;
}


	





