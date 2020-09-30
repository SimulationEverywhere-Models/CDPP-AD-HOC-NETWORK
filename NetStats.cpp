/********************************************************
*	DESCRIPTION	: Atomic model Network statistics
* 
*	AUTHOR		: Monageng Kgwadi
* 
*	DATE		: 26-10-2007
* 
*
********************************************************/


/********** file includes ****************************/

#include "netstats.h"
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

NetStats::NetStats( const string &name) :
	Atomic(name),
	lin(addInputPort("lin")),
	nin(addInputPort("nin")),
	aout( addOutputPort("aout")){	
		nodes = 0;
		links = 0;
		reliability = 0;
	}
Model &NetStats::initFunction()
{
	                    
	    holdIn(Atomic::active, Time::Zero);
		return *this ; 
		};
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: external function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &NetStats::externalFunction(const ExternalMessage &msg ){
	
	if(msg.port() == lin){
		
		links = msg.value();
		if (nodes >1)reliability = 2*(double)links/((double)(nodes*(nodes-1)));
		else reliability = 0;
		holdIn(active, Time::Zero);
	}
	
	if(msg.port() == nin){
		
		nodes = msg.value();
		if (nodes >1)reliability = 2*(double)links/((double)(nodes*(nodes-1)));
		else reliability = 0;
		holdIn(active, Time::Zero);
	}
	return *this;
}
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: internal function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &NetStats::internalFunction(const InternalMessage & )
{
	
	double x = rand()/(double)RAND_MAX *15;
	//cout << " x :"<< x << endl;
	Time t(0,0,x,0) ;
	cout<<t <<endl;
	holdIn(active, t);
	return *this;
}
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: output function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &NetStats::outputFunction(const InternalMessage &msg)
{
	
	this->sendOutput(msg.time(),aout,reliability);
	return *this;
}
