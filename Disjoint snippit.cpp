#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
     vector<int> rank ,parent , size; 
     public: 

     //constructor
     DisjointSet(int n ){
        // N+1 because it will work for both 0 and 1 base indexing
         rank.resize(n+1,0);   
         parent.resize(n+1); 
         size.resize(n+1,1);
      
      for( int i = 0 ; i<=n; i++){
         parent[i]=i;
      } }

      // 1)parent store parent of the that node ( intially itself )
      // 2)size store size of node and and their all derviatives (include itself) ( intiallly 1 i.e. itself )
      // 3)rank show longest chain of derivates connected to  the node (not include itself) ( intially 0 ) after path compression it parnet change it not change help to connect 
      // future coming node it's correct position in disjoint set  


 //doing path compression and find the ultimate parent 
    int  findUltParent(int node){     
        if(node ==parent[node]){
            return node ;
        }
      int ultimateParent = findUltParent(parent[node]);
      parent[node]  = ultimateParent;
      return ultimateParent;
    }

// for join the two node in this disjoint data structure ( tree like structure )
//smaller rank parent node will attach into high node parent 
// for equal rank attach anyone to anyone 

   void unionByRank(int u ,int v){
        int parentU = findUltParent(u); 
         int parentV = findUltParent(v); 

         if( rank[parentU]> rank[parentV]){
            parent[parentV] = parentU;
         }
                                                    //if rank of both of them is not equal  then integrating the smaller  to bigger  will not affect rank of bigger 
         else if( rank[parentU]< rank[parentV]){
            parent[parentU] = parentV;
         }

         else{ 
            parent[parentV] = parentU;
            rank[parentU]++;
         }
       }

// using Bysize 
//smaller Size parent node will attach into high  Size node parent 
// for equal Size attach anyone to anyone

   void unionBySize(int u ,int v){
        int parentU = findUltParent(u); 
         int parentV = findUltParent(v); 

         if( size[parentU]> size[parentV]){
            parent[parentV] = parentU;
            size[parentU] += parentV;
         }
         
         else if( rank[parentU]< rank[parentV]){
            parent[parentU] = parentV;
              size[parentV] += parentU;
         }

         else{ 
            parent[parentV] = parentU;
          size[parentU] += parentV;
         }
         
   }


};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 
 
return 0;
}
