//
//  MyBST.hpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#ifndef MyBST_hpp
#define MyBST_hpp

#include <stdio.h>
#include <iostream>

#include "ThespianRecord.hpp"
#include <vector>
#include <string>

using namespace std;

template <class record>
class MyBST {
    record* head; // root of the BST
    int size; // not really used, but why not
    
    // get a list of values in the BST
    // private helper
    vector<record> getRecordListPrivate (record* currentPtr, vector<record>& recordList);
    
    // start delete stuff
    // private helpers
    void deleteHead () {
        // get highest value of left child
        record* replacement = deleteFullLegacyHelper(head->left, nullptr, false);
        
        // keep current head in temp
        record* tempPtr = head;
        
        // point head to new head
        head = replacement;
        // copy current head pointers to new head pointers
        head->left = tempPtr->left;
        head->right = tempPtr->right;
        
        // delete old head :(
        delete tempPtr;
    }
    bool deleteRecord (string deleteTarget, record* currentNode) { // size--
        
        // found node will become the record that needs deleting
        record* foundNode = nullptr;
        // direction tells us if the record to be deleted is the left
        // or right child of its parent
        bool direction = false;
        
        bool leftNodeFull = false;
        bool rightNodeFull = false;
        
        // check if there is a left node
        if (currentNode->left != nullptr) {
            leftNodeFull = true;
        }
        // check if there is a right node
        if (currentNode->right != nullptr) {
            rightNodeFull = true;
        }
        
        // check if left child of current node needs to be deleted
        if (leftNodeFull && deleteTarget == currentNode->left->getKey()) {
            foundNode = currentNode->left;
            direction = false;
        }
        // check if right child of current node needs to be deleted
        if (rightNodeFull && deleteTarget == currentNode->right->getKey()) {
            foundNode = currentNode->right;
            direction = true;
        }
        
        // if the node to be deleted has been found, delete it
        if (foundNode != nullptr) {
            // find delete type (no child, 1 child, 2 child)
            int deleteType = deleteGetDeleteType(foundNode);
            if (deleteType == 0) {
                deleteNoLegacy(currentNode, foundNode, direction);
                return true;
            }
            else if (deleteType == 1) {
                deleteSomeLegacy(currentNode, foundNode, direction);
                return true;
            }
            else if (deleteType == 2) {
                deleteFullLegacy(currentNode, foundNode, direction);
                return true;
            }
        }
        // else, keep looking recursively in children
        else {
            if (leftNodeFull && deleteTarget < currentNode->getKey()) {
                return deleteRecord (deleteTarget, currentNode->left);
            }
            if (rightNodeFull && deleteTarget > currentNode->getKey()) {
                return deleteRecord (deleteTarget, currentNode->right);
            }
        }
        
        // if no matching node was found, return false
        return false;
    }
    int deleteGetDeleteType (record* deleteTarget) {
        // returns 0 for end leaf delete (no children in target),
        // 1 for jump delete (one child in target)
        // 2 for complex delete (two children in target)
        
        int totalChildren = 0;
        
        if (deleteTarget->left != nullptr) {
            totalChildren += 1;
        }
        if (deleteTarget->right != nullptr) {
            totalChildren += 1;
        }
        
        return totalChildren;
    }
    void deleteNoLegacy (record* parentNode, record* targetNode, bool direction) {
        // delete the node
        delete targetNode;
        
        // set the parent node pointer to null depending of direction
        // (direction false = left)
        if (!direction) {
            parentNode->left = nullptr;
        } else {
            parentNode->right = nullptr;
        }
    }
    void deleteSomeLegacy (record* parentNode, record* targetNode, bool direction) {
        record* newChild = nullptr;
        
        // set new child to child of record to be deleted
        if (targetNode->left != nullptr) {
            newChild = targetNode->left;
        }
        else if (targetNode->right != nullptr) {
            newChild = targetNode->right;
        }
        
        // set appropriate parent pointer to this new child
        if (!direction) {
            parentNode->left = newChild;
        } else {
            parentNode->right = newChild;
        }
        
        // delete old record
        delete targetNode;
    }
    void deleteFullLegacy (record* parentNode, record* targetNode, bool direction) {
        // use helper to get replacement value
        record* replacement = deleteFullLegacyHelper(targetNode->left, nullptr, false);
        
        // set parent node to replacement based on direction
        // (direction false = left)
        if (!direction) {
            parentNode->left = replacement;
        } else {
            parentNode->right = replacement;
        }
        
        // if the address of replacement == adress of target's left
        // don't set left ptr of replacement or it'll create an infinite loop
        if (replacement != targetNode->left) {
            replacement->left = targetNode->left;
        }
        // set replacement right to deleted node's right
        replacement->right = targetNode->right;
        
        // delete node
        delete targetNode;
    }
    record* deleteFullLegacyHelper (record* currentNode, record* parent, bool direction) {
        record* finalReplacement = currentNode;
        
        // go down the right path to find highest value
        if (finalReplacement->right != nullptr) {
            return deleteFullLegacyHelper(finalReplacement->right, currentNode, true);
        } else {
            // set replacement's old parent to replacement's child or null
            if (parent != nullptr) {
                if (!direction) {
                    parent->left = nullptr;
                    if (currentNode->left != nullptr) {
                        parent->left = currentNode->left;
                    }
                } else {
                    parent->right = nullptr;
                    if (currentNode->left != nullptr) {
                        parent->right = currentNode->left;
                    }
                }
            }
            
            return currentNode;
        }
    }
    // end delete stuff
    
public:
    MyBST();
    ~MyBST() {
        if (head == nullptr) {
            return;
        }
        deleteNode(head);
    };
    void deleteNode (record* currentNode) {
        if (currentNode->left != nullptr) {
            deleteNode(currentNode->left);
        }
        if (currentNode->right != nullptr) {
            deleteNode(currentNode->right);
        }
        // cout << "did delete: " << currentNode->getKey() << endl;
        delete currentNode;
    }
    void clearThisBST () {
        if (head == nullptr) {
            return;
        }
        deleteNode(head);
        head = nullptr;
        size = 0;
    }
    
    // this creates the head
    bool createHead (record* newHead);
    bool insert (record* insertRecord); // size++
    
    // start a delete here
    bool deleteRecordPublic (string deleteTarget) {
        
        // head check
        if (head == nullptr) {
            cout << "This BST is empty." << endl;
            return false;
        }
        
        // if the target key matches the head
        if (deleteTarget == head->getKey()) {
            // delete head
            deleteHead();
            size--;
            cout << deleteTarget << " was deleted" << endl;
            return true;
        }
        
        // deleted tracks if the target record was found
        bool deleted = deleteRecord(deleteTarget, head);
        if (deleted) {
            cout << deleteTarget << " was deleted" << endl;
            size--;
            return true;
        } else {
            cout << deleteTarget << " was not found" << endl;
        }
        return false;
    }
    
    // get a list of values in the BST
    vector<record> getRecordListPublic ();
    
    // print out every record in sorted order in csv format
    friend ostream& operator << (ostream &out, MyBST &BST) {
        
        vector<record> newRecords = BST.getRecordListPublic();
        
        int vSize = (int)newRecords.size();
        for (int i = 0; i < vSize; i++) {
            out << newRecords.at(i);
        }
        
        return out;
    }
    
    int getSize (){return size;}
};

#endif /* MyBST_hpp */
