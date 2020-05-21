//
//  PictureRecord.hpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#ifndef PictureRecord_hpp
#define PictureRecord_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class PictureRecord {
    
public:
    
    PictureRecord* left;
    PictureRecord* right;
    
    string name;
    int year;
    int nominations;
    double rating;
    int duration;
    string genre1;
    string genre2;
    string release;
    int metacritic;
    string synopsis;
    
    int returnType;
    
    PictureRecord();
    // records shouldn't delete themselves
    // that'll be handled by their tree
    
    // get current key
    string getKey ();
    
    // print in csv format
    friend ostream& operator << (ostream &out, PictureRecord &list);
    
};

#endif /* PictureRecord_hpp */
