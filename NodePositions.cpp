/********************************************************
*	DESCRIPTION	: Atomic model Node positions
* 
*	AUTHOR		: Monageng Kgwadi
* 
*	DATE		: 26-10-2007
* 
*
********************************************************/


/********** file includes ****************************/

#include "NodePositions.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "randlib.h"         // Random numbers library
#include "message.h"         // InternalMessage 
#include "distri.h"          // class Distribution
#include "mainsimu.h"        // class MainSimulator
#include "strutil.h"   

  

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: NodePos
* 
* Description: Constructor
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

NodePositions::NodePositions( const string &name) :
	Atomic(name),
	advanceTime(0,0,0,500),
	out( addOutputPort("out")){	
		
	}
Model &NodePositions::initFunction()
{
	                
	    holdIn(Atomic::active, advanceTime);
		return *this ; 
		};
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: external function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &NodePositions::externalFunction(const ExternalMessage & ){
	/*
	if(msg.value() ==1 )
	  holdIn(active, preparationTime);*/
	  cout<< "we shouldnt see this message no inputs"<<endl;
return *this;
}
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: internal function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &NodePositions::internalFunction(const InternalMessage & )
{
	
	holdIn(active, advanceTime);
	return *this;
}
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*Function Name: output function
* 
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/	
Model &NodePositions::outputFunction(const InternalMessage &msg)
{
	
	this->sendOutput(msg.time(),out,1);
	return *this;
}
