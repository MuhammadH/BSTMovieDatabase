//
//  ThespianRecord.hpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#ifndef ThespianRecord_hpp
#define ThespianRecord_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class ThespianRecord {
    
public:
    ThespianRecord* left;
    ThespianRecord* right;
    
    // Note to self -
    // maybe I don't even need different data types?
    // everything could be strings
    
    int year;
    string award;
    bool winner;
    string name;
    string film;
    
    int returnType;
    
    ThespianRecord();
    // records shouldn't delete their children
    // that'll be handled by their tree
    
    // print in csv format
    friend ostream& operator << (ostream &out, ThespianRecord &record);
    
    // get current key
    string getKey ();
};

#endif /* ThespianRecord_hpp */
