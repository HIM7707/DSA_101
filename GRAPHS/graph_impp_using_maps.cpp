#include <iostream>
#include <list>
#include <map>
using namespace std;
template <typename T>
class Graph{
    // define data types
    map<T,list<T>> adjList;
    // mamber function
public:    
    Graph(){
    }
    void addEdge(T u,T v, bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void print(){
        for(auto i:adjList){    // way to traverse a graph..
            cout<<i.first<<"->";
            for(T j:i.second){  // way to traverse a list.
                cout<<j<<",";
            }
            cout<<endl;
        }
        
    }
};




int main() {
	Graph<string> g;
	g.addEdge("putin","Trump",false);
	g.addEdge("putin","Mod",false);
	g.addEdge("putin","Pope",false);
	g.addEdge("Modi","Trump",true);
	g.addEdge("Modi","Yogi",true);
	g.addEdge("Yogi","Prabhu",false);
	g.addEdge("Prabhu","Modi",false);
	
	g.print();
	return 0;
      

    
}