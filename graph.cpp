#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>      // std::pair, std::make_pair



//#include "graph.h"

using namespace std;

struct Vertex {
	char label;
};

bool notThere(char, char[50]);
void addEdge(Vertex*, Vertex*, bool);
Vertex* findVertex(char, Vertex**);
int vertexIndex(char, Vertex**);
void clear(int[20][20]);
void findPaths(Vertex*, Vertex*, pair<char[50], int>, vector<pair<char[50], int> >, int[20][20], Vertex**);


int main(){
	int matrix[20][20];
	Vertex* vertisies[20];
	vector<pair<char[50], int> > paths;
	int numVert = 0;
	//void printMatrix();
	char input[50];//cstring for input
	bool running = true;//is the program still running
	clear(matrix);
	while (running){//as long as it is still running
		cout << "Do you want to \"input\", \"print\", \"search\", \"delete\", or \"quit\"" << endl;//\"remove\",
		cin.get(input, 50);//get users input
		cin.clear();
		cin.ignore(10000, '\n');
		if (strcmp(input, "input") == 0){
			cout << "Name of vertex: ";
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
		else if (strcmp(input, "edge") == 0){//if input is eaqual to quit 
			char first[50];
			char second[50];
			char bi[50];
			cout << "First vertex: ";
			cin.get(first, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n'); 
			cout << "Second vertex: ";
			cin.get(second, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Bidirectional (y or n): ";
			cin.get(bi, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Length: ";
			cin.get(input, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			int inter = atoi(input);//convers the char to an int
			int y = vertexIndex(first[0], vertisies);
			int x = vertexIndex(second[0], vertisies);
			if(inter != NULL){
				matrix[x][y] = inter;
				if(bi[0] == 'y'){
					matrix[y][x] = inter;
				}
			}
		}
		else if (strcmp(input, "delete") == 0){//if input is eaqual to quit 
			cout << "Which vertex do you want to delete?: ";
			cin.get(input, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			int temp = vertexIndex(input[0], vertisies);
			if(temp != NULL){
				for(int y = 0; numVert > y; y++){
					matrix[temp][y] = NULL;
					matrix[y][temp] = NULL;
				}
				vertisies[temp] = NULL;
			}
			for(int x = temp + 1; numVert > x; x++){
				vertisies[x-1] = vertisies[x];
			}
			numVert--;
		}
		else if (strcmp(input, "remove") == 0){//if input is eaqual to quit 
			char first[50];
			char second[50];
			char bi[50];
			cout << "First vertex: ";
			cin.get(first, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n'); 
			cout << "Second vertex: ";
			cin.get(second, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Bidirectional (y or n): ";
			cin.get(bi, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			int y = vertexIndex(first[0], vertisies);
			int x = vertexIndex(second[0], vertisies);
			if(x != NULL || y != NULL){
				matrix[x][y] = NULL;
				if(bi[0] == 'y'){
					matrix[y][x] = NULL;
				}
			}
		}
		else if (strcmp(input, "path") == 0){//if input is eaqual to quit 
			char first[50];
			char second[50];
			cout << "First vertex: ";
			cin.get(first, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n'); 
			cout << "Second vertex: ";
			cin.get(second, 50);//get users input
			cin.clear();
			cin.ignore(10000, '\n');
			int start = vertexIndex(first[0], vertisies);
			int end = vertexIndex(second[0], vertisies);
			pair <char[50],int> path;
			path.first[0] = vertisies[start]->label;
			path.second = 0;
			findPaths(vertisies[start], vertisies[end], path, paths, matrix, vertisies);
		}
		else if (strcmp(input, "quit") == 0){//if input is eaqual to quit 
			running = false;//set running to false
		}
	}
}

int vertexIndex(char v, Vertex** vertisies){
	for(int i = 0; i < 20; i++){
		if(v == vertisies[i]->label){
			return i;
		}
	}	
	return NULL;
}

Vertex* findVertex(char v, Vertex** vertisies){
	for(int i = 0; i < 20; i++){
		if(v == vertisies[i]->label){
			return vertisies[i];
		}
	}	
	return NULL;
}

void findPaths(Vertex* start, Vertex* end, pair<char[50], int> path, vector<pair<char[50], int> > paths, int matrix[20][20], Vertex** vertisies){
	int x = vertexIndex(start->label, vertisies);
	bool anyConnections = false;
	for(int i = 0; i < 20; i++){
		if(matrix[x][i] != NULL){
			if(notThere(matrix[20][20], path.first)){
				strcat(path.first, vertisies[i]->label + "");
				path.second += matrix[x][i];
				if(vertisies[i] != end){
					findPaths(vertisies[i], end, path, paths, matrix, vertisies);
					anyConnections = true;
				}
				else{
					paths.push_back(path);
				}
			}
		}
	}
}

bool notThere(char path, char paths[50]){
	for(int i = 0; i < 50; i++){
		if(path == paths[i]){
			return false;
		}
	}
	return true;
}


void clear(int matrix[20][20]){
	for(int x = 0; 20 > x; x++){
		for(int y = 0; 20 > y; y++){
			matrix[x][y] = NULL;
		}
	}
}

