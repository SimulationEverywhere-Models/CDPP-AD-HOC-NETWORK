/********************************************************
*	DESCRIPTION	: Atomic model Node generator
* 
*	AUTHOR		: Monageng Kgwadi
* 
*	DATE		: 26-10-2007
* 
*
********************************************************/


/********** file includes ****************************/

#include "NodeGenerator.h"
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

NodeGenerator::NodeGenerator( const string &name) :
	Atomic(name),
	aout( addOutputPort("aout")){	
		
	}
Model &NodeGenerator::initFunction()
{
	                    
	    holdIn(Atomic::active, Time::Zero);
		return *this ; 
		};
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: external function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &NodeGenerator::externalFunction(const ExternalMessage & ){
	
	  cout<< "we shouldnt see this message no inputs"<<endl;
return *this;
}
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: internal function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &NodeGenerator::internalFunction(const InternalMessage & )
{
	
	double x = rand()/(double)RAND_MAX *5;

	Time t(0,0,x,0) ;
	
	holdIn(active, t);
	return *this;
}
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: output function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &NodeGenerator::outputFunction(const InternalMessage &msg)
{
	
	this->sendOutput(msg.time(),aout,1);
	return *this;
}
