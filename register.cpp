/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "queue.h"                // class Queue
#include "generat.h"             // class Generator
#include "cpu.h"                 // class CPU
#include "nodegenerator.h"       // class NodeGenerator
#include "nodepositions.h" 
#include "registry.h" 
#include  "netstats.h"
#include "transduc.h"             // class Transducer ??
#include "trafico.h"              // class Trafico ??


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
    SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<NodeGenerator>() , "NodeGenerator" ) ;
    SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<NodePositions>() , "NodePositions" ) ;
    SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Registry>() , "Registry" ) ;
    SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<NetStats>() , "NetStats" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trafico>() , "Trafico" ) ;
}
