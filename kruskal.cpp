#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "time.h"
using namespace std;

int count=0,count1=0,count2=0,count3=0;
 
 //structure to store the edge weights, source and destination edges 
 struct Edge{
 int start,end,weight;
 };

struct solution{
int src,dest, length;
};

//function to detect the cycles
int find3(int a,int * vertexArray ){
	int root ,node,parent;
	root =a;
	while (root!= vertexArray[root])
		root= vertexArray[root];
	node = a;
	while(node!=root) {
	 parent = vertexArray[node];
	 vertexArray[node]= root;
	 node = parent;
	 }
  return root;
}

//function to join the edges to form a mst
int union3(int a, int b,int * vertexArray,int *h){
	if(h[a]==h[b]) {
	      h[a]++;
              vertexArray[b]=a;
	}
	else {
		if (h[a]>h[b]) vertexArray[b]=a;
		else vertexArray[a]=b;
	}
}

void kruskal(struct Edge *edgeArray,int no_edge,int no_vert){

	struct solution output[no_edge];
	int * height = new int[no_vert];
	int * vertices = new int[no_vert];
	for(int i=0;i< no_vert;i++){
	vertices[i]= i;
	height[i]=0;
	}

	for(int i=0;i<no_edge;i++){
	int u = find3(edgeArray[i].start,vertices);
	int v = find3(edgeArray[i].end,vertices);
	if(u!=v){
	output[count3].src =edgeArray[i].start;
	output[count3].dest =edgeArray[i].end;
	count3++;
	union3(u,v,vertices,height);
	}
   }
   //print the mst edges
   for(int i=0;i<count3;i++) cout<<"edge "<<output[i].src+1<<","<<output[i].dest+1 <<endl;
}


//Randomized Quick  sort 
int r_PARTITION(struct Edge * edgeArray, int,int,int);
int pARTITION(struct Edge * input, int,int,int);

void RandomizedQuick_Sort(struct Edge* edgeArray,int p,int r,int n)
    {
        int q;
        if(p<r)
        {
         q=r_PARTITION(edgeArray,p,r,n);
         RandomizedQuick_Sort(edgeArray,p,q-1,n);
         RandomizedQuick_Sort(edgeArray,q+1,r,n);
        }
    }

 int r_PARTITION(struct Edge *input,int p,int r,int n)
 {
        int i=p+rand()%(r-p+1);
        struct Edge temp;
        
        temp.start=input[r].start;
        temp.end=input[r].end;
        temp.weight=input[r].weight;
        
        input[r].start=input[i].start;
        input[r].end=input[i].end;
        input[r].weight=input[i].weight;
        
        input[i].start=temp.start;
        input[i].end=temp.end;
        input[i].weight=temp.weight;
        
        return pARTITION(input,p,r,n);
  }

 int pARTITION(struct Edge *a,int p,int r,int n)
 {
        struct Edge temp,temp1;
        
        int x=a[r].weight;
        
        int i=p-1;
        for(int j=p;j<=r-1;j++)
        {
            if(a[j].weight<=x)
            {

                i=i+1;
                temp.start=a[i].start;
                temp.end=a[i].end;
                temp.weight=a[i].weight;
                
                a[i].start=a[j].start;
                a[i].end=a[j].end;
                a[i].weight=a[j].weight;
                
                a[j].start=temp.start;
                a[j].end=temp.end;
                a[j].weight=temp.weight;
            }
        }
        
        temp1.start=a[i+1].start;
        temp1.end=a[i+1].end;
        temp1.weight=a[i+1].weight;
        
        a[i+1].start=a[r].start;
        a[i+1].end=a[r].end;
        a[i+1].weight=a[r].weight;
        
        a[r].start=temp1.start;
        a[r].end=temp1.end;
        a[r].weight=temp1.weight;
        
        return i+1;
  }

int main(int argc,char*argv[]){
srand(time(NULL));
if(argc ==2){
ifstream ab("graph.txt");
string s;
while(getline(ab,s)){
count++;
}

int r =count;  // r is the no of vertices
int** matrix = new int*[r];
for(int i = 0; i < r;i++){
    matrix[i] = new int[r];
}

for(int i=0;i<r;i++){
	for(int j=0;j<r;j++){
	  matrix[i][j]=0;
	}
}

ifstream is("graph.txt");
string a;
int x=0;
// store the values in graph.txt into a 2-d matrix
while(getline(is,a)){
	stringstream ss(a);
	string d;
	int y=0;
	while(getline(ss,d,',')){
             matrix[x][y]=atoi(d.c_str());
            // cout<<matrix[x][y]<<",";
	y++;
	}
	x++;
 }
 
 //To find no of edges
 for(int i=0;i<r;i++){
	for(int j=i+1;j<r;j++){
	  if ( matrix[i][j]!=999 ) count1++;
	}
}
 int e= count1;
 //cout<<"No of edges are "<<e<<endl;
 
 struct Edge edgeArray[e];
 
 //Extract the edges
 for(int i=0;i<r;i++){
 	for(int j=i+1;j<r;j++){
 	   if (matrix[i][j]!=999){
 	   //cout<< matrix[i][j]<<",";
 	   edgeArray[count2].start = i;
 	   edgeArray[count2].end =j;
 	   edgeArray[count2].weight = matrix[i][j];
 	   count2++;
 	   //cout<<edgeArray[count2].start<<"->"<<edgeArray[count2].end<<"="<<edgeArray[count2].weight<<",";
 	   } 
      }
 }

 //print the valuesin edge Array
//for(int i=0;i<e;i++) cout<<edgeArray[i].start<<"->"<<edgeArray[i].end<<"="<<edgeArray[i].weight<<",";

//Sort edge weights 

RandomizedQuick_Sort(edgeArray,0,e-1,e );

//cout<<"After sorting"<<endl;
//for(int i=0;i<e;i++) cout<<edgeArray[i].weight<<","<<"Edges"<<edgeArray[i].start<<"->"<<edgeArray[i].end<<endl; 

//calling the kruskal function to build the mst 
kruskal(edgeArray,e,r);
}
return 0;
}
