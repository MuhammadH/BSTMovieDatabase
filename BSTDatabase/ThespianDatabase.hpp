//
//  ThespianDatabase.hpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#ifndef ThespianDatabase_hpp
#define ThespianDatabase_hpp

#include <stdio.h>
// include both .cpp and .hpp because template class
#include "MyBST.hpp"
#include "MyBST.cpp"
#include <fstream>

using namespace std;

class ThespianDatabase {
    MyBST<ThespianRecord>* thespianData;
    
    // private helpers
    void completeSearchPrivate (string searchValue);
    void partialSearchPrivate (string searchValue);
    
public:
    ThespianDatabase(){thespianData = nullptr;}
    ~ThespianDatabase() {
        if (thespianData == nullptr) {
            return;
        }
        delete thespianData;
    };
    
    // ask the user for a file name, make a BST using file
    void createThespianDatabase ();
    
    // used for output to file
    friend ostream& operator << (ostream &out, ThespianDatabase &list);
    
    // below here are all the ways main can interact with a database
    void addARecord (bool ignore);
    void modifyARecord ();
    void deleteARecord ();
    void resortDatabase (int newSortValue);
    void completeSearch ();
    void partialSearch ();
    void outputFile ();
    
    // additional functions
    void getAnInt(int& inputInt);
};

#endif /* ThespianDatabase_hpp */
