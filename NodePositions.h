/********************************************************
*	DESCRIPTION	: Atomic model Node generator
* 
*	AUTHOR		: Monageng Kgwadi
* 
*	DATE		: 26-10-2007
* 
*
********************************************************/


#ifndef NODEPOSITIONS_H
#define NODEpOSITIONS_H

//****    file includes    *********/
#include "atomic.h"



class NodePositions: public Atomic 
{

public: 
	
	
	NodePositions(const string &name = "NodePositions");
	
	
	virtual string className() const
		{return "NodePositions";}
		
protected:
	Model &initFunction();
	
	Model &externalFunction( const ExternalMessage & );
	
	Model &internalFunction( const InternalMessage & );
	
	Model &outputFunction( const InternalMessage &);
	
private:
	
	Port &out;
	Time advanceTime;// The model generates an output  after 
								//every advanceTime minutes
						
		
}; //Class NodePositions

#endif  //_NODEPOSITIONS_H