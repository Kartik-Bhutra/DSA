// https://leetcode.com/problems/maximum-frequency-stack/
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
    Node(int val, Node* after){
        data = val;
        next = after;
    }
};
class FreqStack {
    unordered_map<int,int> num;
    unordered_map<int,Node*> mp;
    Node* head;
public:
    FreqStack() {
        head = nullptr;
    }

    void push(int val) {
        num[val]++;
        if(mp.find(num[val]) == mp.end()){
            head = new Node(val,head);
            if(mp.find(num[val]-1) == mp.end()){
                mp[num[val]-1] = head;
            }
            return;
        }
        Node* newNode = new Node(val,mp[num[val]]->next);
        mp[num[val]]->next = newNode;
    }

    int pop() {
        int val = head->data;
        Node* newHead = head->next;
        num[val]--;
        if(mp[num[val]] == head){
            mp.erase(num[val]);
        }
        delete head;
        head = newHead;
        return val;
    }
};
int main(){
  
  return 0;
}