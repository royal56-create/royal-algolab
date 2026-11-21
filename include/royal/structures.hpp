#pragma once
#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>
namespace royal {
template<class T> class LinkedQueue {
 struct Node{T value;std::unique_ptr<Node> next;explicit Node(T v):value(std::move(v)){}};
 std::unique_ptr<Node> head_;Node* tail_=nullptr;std::size_t count_=0;
public:
 bool empty()const noexcept{return !head_;}std::size_t size()const noexcept{return count_;}
 void push(T v){auto n=std::make_unique<Node>(std::move(v));auto p=n.get();if(tail_)tail_->next=std::move(n);else head_=std::move(n);tail_=p;++count_;}
 T pop(){if(empty())throw std::out_of_range("Queue empty");T v=std::move(head_->value);head_=std::move(head_->next);if(!head_)tail_=nullptr;--count_;return v;}
};
template<class T> class BinarySearchTree {
 struct Node{T value;std::unique_ptr<Node> left,right;explicit Node(T v):value(std::move(v)){}};
 std::unique_ptr<Node> root_;
 static bool add(std::unique_ptr<Node>& n,T v){if(!n){n=std::make_unique<Node>(std::move(v));return true;}if(v==n->value)return false;return v<n->value?add(n->left,std::move(v)):add(n->right,std::move(v));}
 static void visit(const Node* n,std::vector<T>& out){if(!n)return;visit(n->left.get(),out);out.push_back(n->value);visit(n->right.get(),out);}
public:
 bool insert(T v){return add(root_,std::move(v));}
 bool contains(const T& v)const{auto n=root_.get();while(n){if(v==n->value)return true;n=v<n->value?n->left.get():n->right.get();}return false;}
 std::vector<T> inorder()const{std::vector<T> out;visit(root_.get(),out);return out;}
};
}
