/********************************************************
*	DESCRIPTION	: Atomic model Registryr
* 
*	AUTHOR		: Monageng Kgwadi
* 
*	DATE		: 26-10-2007
* 
*
********************************************************/


#ifndef REGISTRY_H
#define REGISTRY_H

//****    file includes    *********/
#include "atomic.h"
#include "nodes.h"



class Registry: public Atomic 
{

public: 
	
	
	Registry(const string &name = "Registry");
	
	
	virtual string className() const
		{return "Registry";}
		
protected:
	Model &initFunction();
	
	Model &externalFunction( const ExternalMessage & );
	
	Model &internalFunction( const InternalMessage & );
	
	Model &outputFunction( const InternalMessage &);
	
private:
	static const double smax = 5; //maximum speed in meters/s
	
	static const int defaultNodes =8; //the number of network nodes at the start of simulation
	static const double t = 1.0; //the time after which the nodes are to be updated in seconds
	Port &aout, &lout;
	Port  &deq, &gen;
	Port &pos;

	
	Nodes *nodes;  // list of network nodes implemented in a linkedlist(see nodes.h and nodes.cpp)
	
		
}; //Class Registry

#endif  //_REGISTRY_H