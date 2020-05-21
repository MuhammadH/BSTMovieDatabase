//
//  NominationRecord.hpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#ifndef NominationRecord_hpp
#define NominationRecord_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class NominationRecord {
    
public:
    
    NominationRecord* left;
    NominationRecord* right;
    
    int year;
    string award;
    bool winner;
    string name;
    string film;
    
    int returnType;
    
    NominationRecord();
    // records shouldn't delete themselves
    // that'll be handled by their tree
    
    // get current key
    string getKey ();
    
    // print in csv format
    friend ostream& operator << (ostream &out, NominationRecord &list);

};

#endif /* NominationRecord_hpp */
