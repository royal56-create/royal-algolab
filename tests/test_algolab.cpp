#include "royal/algorithms.hpp"
#include "royal/graph.hpp"
#include "royal/structures.hpp"
#include <cassert>
#include <stdexcept>
#include <vector>
int main(){
 std::vector<int>a{5,1,4,2,8};royal::bubbleSort(a);assert((a==std::vector<int>{1,2,4,5,8}));
 std::vector<int>b{9,3,7,1};royal::selectionSort(b);assert((b==std::vector<int>{1,3,7,9}));
 std::vector<int>c{4,2,3,1};royal::insertionSort(c);assert((c==std::vector<int>{1,2,3,4}));
 std::vector<int>d{8,2,6,1};royal::mergeSort(d);assert((d==std::vector<int>{1,2,6,8}));
 std::vector<int>e{7,4,9,2};royal::quickSort(e);assert((e==std::vector<int>{2,4,7,9}));
 assert(royal::linearSearch(e,7)==2);assert(royal::binarySearch(e,9)==3);
 bool threw=false;try{royal::binarySearch(std::vector<int>{3,1},1);}catch(const std::invalid_argument&){threw=true;}assert(threw);
 royal::LinkedQueue<int>q;q.push(1);q.push(2);assert(q.pop()==1&&q.pop()==2&&q.empty());
 royal::BinarySearchTree<int>t;for(int x:{5,3,7,2,4})t.insert(x);assert(t.contains(4));assert((t.inorder()==std::vector<int>{2,3,4,5,7}));
 royal::Graph g(3);g.addEdge(0,1,2);g.addEdge(1,2,3);assert((g.bfs(0)==std::vector<int>{0,1,2}));assert(g.dijkstra(0)[2]==5);
}
