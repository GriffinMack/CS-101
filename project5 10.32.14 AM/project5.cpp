#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class MyNode{
  public:
    string name;
    int delayTime;
};


class MyEdge{
  string start, end;
  float distance, speed;
};

class MyGraph{
public:
  MyGraph(string node,string edge){

  }
};



int main(int argc,char** argv){
    string nodes = argv[1];
    string edges = argv[2];
  MyGraph graph(nodes, edges);
    char nodeSource;
    char nodeDestination;
    int flag = 0;
  while(flag == 0){
  cout<<"Please enter a pair of nodes for source and destination: ";
  cin>>nodeSource;
  cin>>nodeDestination;
  if(cin.peek() != EOF){

  cout<<endl<<endl<<"Shortest distance: "<<endl;
  cout<<"Path: "<<endl;
  cout<<endl<<"Shortest delay time: "<<endl;
  cout<<"Path: "<<endl;

  cout<<endl<<"Shortest expected traveling time: "<<endl;
  cout<<"Path: "<<endl;
  cout<<endl<<"Shortest expected total time: "<<endl;
  cout<<"Path: "<<endl;
  cout<<endl<<"Fewest hops: "<<endl;
  cout<<"Path: "<<endl<<endl;}
  else flag = 1;}
return 0;
}
