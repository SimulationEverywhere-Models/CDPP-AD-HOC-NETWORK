#ifndef NODES_H_
#define NODES_H_

static const int maxNodes = 20; // maximum number of nodes in the network at a time
static const int xmax = 20;
static const int ymax = 50; //variables that define the limits of area of network in meters
static const double maxD = 3; //the maximum separation distance for nodes to communicate
class Node{

		public:	
				Node *next;
				int posx, posy, destx, desty, numLinx;
				bool status;	
				double speed;
					
		 
      		Node(int px, int py, int dx, int dy, double spd, bool sts){
      			next = NULL;
         		posx = px;
        		posy = py;
         		destx = dx;
         		desty = dy;
         		speed = spd;
         		status = sts;
         		numLinx = 0;
      			}// constructor
     		 //~Node(){}//destructor
    	void setSpeed(double speed){this->speed = speed;}
     	void setStatus(bool status){ this->status = status;}
    	void setPosition(int x, int y){
   			this->posx = x;
     		this->posy = y;
     	}
     	
     	void setDestination(int x, int y){
     		this->destx = x;
     		this->desty = y;
     	}
     	
     		
     	
	};


class Nodes{
public:

    Nodes();
    Nodes(int n);	
	~Nodes();
	void addNode(Node *n);
	void deleteNode(int i);
	void printNodes();
	int size(){return nodeCount;}
	void updatePositions(const double t);
	void updateLinks();
	int getLinks(){return numLinks;}
private:
   void positionNodes();
   
	
	Node *head;
	int nodeCount;
	int numLinks;
	int positions[maxNodes][maxNodes];// used herein to show graphically the location of nodes
	
	
	
};

#endif /*NODES_H_*/