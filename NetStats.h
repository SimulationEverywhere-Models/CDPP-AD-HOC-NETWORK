/********************************************************
*	DESCRIPTION	: Atomic model Network statistics 
* 
*	AUTHOR		: Monageng Kgwadi
* 
*	DATE		: 26-10-2007
* 
*
********************************************************/


#ifndef NETSTATS_H
#define NETSTATS_H

//****    file includes    *********/
#include "atomic.h"



class NetStats: public Atomic 
{

public: 
	
	
	NetStats(const string &name = "NetStats");
	
	
	virtual string className() const
		{return "NetStats";}
		
protected:
	Model &initFunction();
	
	Model &externalFunction( const ExternalMessage & );
	
	Model &internalFunction( const InternalMessage & );
	
	Model &outputFunction( const InternalMessage &);
	
private:
	int nodes, links;
	double reliability;
	Port &aout;
	Port &lin, &nin;
	
		
}; //Class NetStats

#endif  //_NETSTATS_H