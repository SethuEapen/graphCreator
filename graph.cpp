#include <iostream>
#include "graph.h"

int main(){
	char input[50];//cstring for input
	bool running = true;//is the program still running
	while (running){//as long as it is still running
		cout << "Do you want to \"input\", \"print\", \"search\", \"delete\", or \"quit\"" << endl;//\"remove\",
		cin.get(input, 50);//get users input
		cin.clear();
		cin.ignore(10000, '\n');
		
		else if (strcmp(input, "quit") == 0){//if input is eaqual to quit 
			running = false;//set running to false
		}
	}
}

Graph::Graph(){
	//initialize stuff
}

Vertex* Graph::findVertex(char v){
	for(int x = 0; x < 20; x++){
		if(v = )
	}	
}

