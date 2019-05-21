#include <iostream>
#include <cstring>

//#include "graph.h"

using namespace std;

struct Vertex {
	char label;
};


int main(){
	int matrix[20][20];
	Vertex* vertisies[20];
	int numVert = 0;
	//void printMatrix();
	void addEdge(Vertex*, Vertex*, bool);
	Vertex* findVertex(char, Vertex**);
	char input[50];//cstring for input
	bool running = true;//is the program still running
	while (running){//as long as it is still running
		cout << "Do you want to \"input\", \"print\", \"search\", \"delete\", or \"quit\"" << endl;//\"remove\",
		cin.get(input, 50);//get users input
		cin.clear();
		cin.ignore(10000, '\n');
		if (strcmp(input, "input") == 0){
			cout << "Name of vector: ";
			Vertex* v = new Vertex();
			cin.get(input, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			v->label = input[0];
			cout << "You just inputed " << v->label << endl;
			vertisies[numVert] = v;
			numVert++;
		}
		else if (strcmp(input, "print") == 0){//if input is eaqual to quit 
			cout << " ";
			for(int x = 0; numVert > x; x++){
				cout << vertisies[x]->label << " ";
			}
			cout << endl;
			for(int x = 0; numVert > x; x++){
				cout << vertisies[x]->label;
				for(int y = 0; numVert > y; y++){
					if(matrix[x][y] != NULL)
						cout << matrix[x][y] << " ";
					else
						cout << "  ";
				}		
				cout << endl;
			}
		}
		else if (strcmp(input, "vertex") == 0){//if input is eaqual to quit 
			char first[1];
			char second[1];
			cout << "First vertex: ";
			cin.get(first, 1);//get users input
			cin.clear();
			cin.ignore(10000, '\n'); 
			cout << "Second vertex: ";
			cin.get(second, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Length: ";
			cin.get(input, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			
		}
		else if (strcmp(input, "delete") == 0){//if input is eaqual to quit 
			cout << "Which vertex do you want to delete?: ";
			cin.get(input, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			if(20 <= (int(*input) - 65)){
				for(int y = 0; numVert > y; y++){
					matrix[int(*input)-65][y] = NULL;
				}
				for(int x = 0; numVert > x; x++){
					matrix[x][int(*input)-65] = NULL;
				}
				vertisies[int(*input)-65] = NULL;
			}
		}
		else if (strcmp(input, "quit") == 0){//if input is eaqual to quit 
			running = false;//set running to false
		}
	}
}

Vertex* findVertex(char v, Vertex** vertisies){
	for(int i = 0; i < 20; i++){
		if(v == vertisies[i]->label){
			return vertisies[i];
		}
	}	
	return NULL;
}

