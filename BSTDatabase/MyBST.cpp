//
//  MyBST.cpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#include "MyBST.hpp"

template <class record>
MyBST<record>::MyBST () {
    head = nullptr;
    size = 0;
}

template <class record>
bool MyBST<record>::createHead (record* newHead) {
    head = newHead;
    return true;
}

template <class record>
bool MyBST<record>::insert (record* insertThis) {
    size++;
    
    // if no head, make insertThis the head
    if (head == nullptr) {
        createHead(insertThis);
        return true;
    }
    
    // start at head
    record* currentNode = head;
    
    // search until an empty space is found
    bool setLeft = false;
    bool setRight = false;
    while (!setRight && !setLeft) {
        if (insertThis->getKey() > currentNode->getKey()) {
            if (currentNode->right != nullptr) {
                currentNode = currentNode->right;
            } else {
                setRight = true;
            }
        } else {
            if (currentNode->left != nullptr) {
                currentNode = currentNode->left;
            } else {
                setLeft = true;
            }
        }
    }
    
    // set appropriate pointer to new record
    if (setLeft) {
        currentNode->left = insertThis;
    }
    if (setRight) {
        currentNode->right = insertThis;
    }
    
    return true;
}

template <class record>
vector<record> MyBST<record>::getRecordListPrivate (record* currentPtr, vector<record>& recordList) {
    // go left
    if (currentPtr->left != nullptr) {
        getRecordListPrivate(currentPtr->left, recordList);
    }
    
    // push
    record newRec = *currentPtr;
    newRec.left = nullptr;
    newRec.right = nullptr;
    recordList.push_back(newRec);
    
    // go right
    if (currentPtr->right != nullptr) {
        getRecordListPrivate(currentPtr->right, recordList);
    }
    
    return recordList;
}

template <class record>
vector<record> MyBST<record>::getRecordListPublic() {
    vector<record> newVec;
    return getRecordListPrivate(head, newVec);
}
















