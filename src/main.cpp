#include "royal/algorithms.hpp"
#include "royal/graph.hpp"
#include "royal/structures.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
static vector<int> readNumbers(){cout<<"Enter integers separated by spaces: ";string line;getline(cin,line);istringstream in(line);vector<int>a;int x;while(in>>x)a.push_back(x);return a;}
static void show(const vector<int>& a){for(auto x:a)cout<<x<<' ';cout<<'\n';}
static void sorting(){auto a=readNumbers();if(a.empty()){cout<<"No numbers supplied.\n";return;}cout<<"1 Bubble  2 Selection  3 Insertion  4 Merge  5 Quick\nChoice: ";int c;if(!(cin>>c)){cin.clear();cin.ignore(10000,'\n');return;}cin.ignore(10000,'\n');royal::SortStats s;switch(c){case 1:s=royal::bubbleSort(a);break;case 2:s=royal::selectionSort(a);break;case 3:s=royal::insertionSort(a);break;case 4:royal::mergeSort(a);break;case 5:royal::quickSort(a);break;default:cout<<"Invalid choice\n";return;}cout<<"Sorted: ";show(a);cout<<"Comparisons: "<<s.comparisons<<" | moves/swaps: "<<s.swaps<<"\n";}
static void searching(){auto a=readNumbers();cout<<"Target: ";int x;if(!(cin>>x)){cin.clear();cin.ignore(10000,'\n');return;}cin.ignore(10000,'\n');cout<<"1 Linear  2 Binary (sorted list): ";int c;if(!(cin>>c)){cin.clear();cin.ignore(10000,'\n');return;}cin.ignore(10000,'\n');try{int i=c==1?royal::linearSearch(a,x):c==2?royal::binarySearch(a,x):-1;cout<<(i<0?"Not found":"Found at index "+to_string(i))<<'\n';}catch(const exception&e){cout<<e.what()<<'\n';}}
static void structures(){royal::LinkedQueue<int>q;for(int x:{10,20,30})q.push(x);cout<<"Queue demo (FIFO): ";while(!q.empty())cout<<q.pop()<<' ';cout<<"\nBST demo (inorder): ";royal::BinarySearchTree<int>t;for(int x:{8,3,10,1,6,14,4,7,13})t.insert(x);show(t.inorder());}
static void graphs(){royal::Graph g(6);g.addEdge(0,1,4);g.addEdge(0,2,2);g.addEdge(1,2,1);g.addEdge(1,3,5);g.addEdge(2,3,8);g.addEdge(2,4,10);g.addEdge(3,4,2);g.addEdge(3,5,6);g.addEdge(4,5,3);cout<<"BFS from 0: ";show(g.bfs(0));cout<<"DFS from 0: ";show(g.dfs(0));cout<<"Dijkstra distances from 0: ";for(auto d:g.dijkstra(0))cout<<d<<' ';cout<<"\n";}
int main(){cout<<"=== ROYAL ALGOLAB | C++17 | OFFLINE ===\n";for(;;){cout<<"\n1 Sorting\n2 Searching\n3 Data structures demo\n4 Graph algorithms demo\n5 Complexity guide\n0 Exit\nChoice: ";int c;if(!(cin>>c)){if(cin.eof())break;cin.clear();cin.ignore(10000,'\n');cout<<"Enter a number.\n";continue;}cin.ignore(10000,'\n');switch(c){case 1:sorting();break;case 2:searching();break;case 3:structures();break;case 4:graphs();break;case 5:cout<<"Bubble/Selection/Insertion: O(n^2) worst; Merge: O(n log n); Quick: O(n log n) average, O(n^2) worst; Binary search: O(log n); BFS/DFS: O(V+E); Dijkstra: O((V+E) log V).\n";break;case 0:return 0;default:cout<<"Invalid choice.\n";}}return 0;}
