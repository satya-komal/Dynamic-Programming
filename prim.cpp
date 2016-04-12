#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int count =0;

int minKey(int minVal[], bool checkMST[])
{
   // Initialize min value
   int min = 999, min_index;
 
   for (int v = 0; v <count; v++)
     if (checkMST[v] == false && minVal[v] < min)
         min = minVal[v], min_index = v;
 
   return min_index;
}
 
void buildMST(int** &graph){

     // Array to store constructed MST
     int root[count]; 
     // To pick minimum weight edge in cut   
     int minVal[count]; 
    // To represent set of vertices not included in MST yet    
     bool checkMST[count];   

 for (int i = 0; i < count; i++){
        minVal[i] = 999, checkMST[i] = false;
        }
     minVal[0]=0;
     root[0]=0;
     
for (int j = 0; j <count; j++)
     {
        // Pick the minimum minVal vertex from the set of vertices not yet included in MST
        int u = minKey(minVal, checkMST);
 
        // Add the picked vertex to the MST Set
        checkMST[u] = true;
 
        // Update minVal value and root index of the adjacent vertices of the picked vertex. Consider only those vertices which are not yet included in MST
        for (int v = 0; v <count; v++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // checkMST[v] is false for vertices not yet included in MST
           // Update the minVal only if graph[u][v] is smaller than minVal[v]
          if (graph[u][v] && checkMST[v] == false && graph[u][v] <  minVal[v])
             root[v]  = u, minVal[v] = graph[u][v];
     }
 
     // print the constructed MST
   	for (int i = 1; i <count; i++)
    		cout<< "edge "<< root[i]+1<<","<< i+1<<endl;   
}

int main(int argc, char *argv[]){

if(argc ==2){
ifstream ab("graph.txt");
string s;
while(getline(ab,s)){
count++;
}

int n =count;
int** matrix = new int*[n];
for(int i = 0; i < n;i++){
    matrix[i] = new int[n];
}

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	  matrix[i][j]=0;
	}
}

ifstream is("graph.txt");
string a;
int x=0;
//to store the values present in the graph.txt into a matrix
while(getline(is,a)){
	stringstream ss(a);
	string d;
	int y=0;
	while(getline(ss,d,',')){
             matrix[x][y]=atoi(d.c_str());
	y++;
	}
	x++;
 }
 
 buildMST(matrix);
}
return 0;
}
