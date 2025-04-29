#ifndef TREE_HPP
#define TREE_HPP

class Tree
{
public:
  int val;
  Tree *left;
  Tree *right;
  Tree(int val) : val(val) {}
};

#endif