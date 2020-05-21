//
//  NominationsDatabase.hpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#ifndef NominationsDatabase_hpp
#define NominationsDatabase_hpp

#include <stdio.h>
#include "PicturesDatabase.hpp"
#include "NominationRecord.hpp"

using namespace std;

class NominationsDatabase {
    MyBST<NominationRecord>* nominationData;
    
    // private helpers
    void completeSearchPrivate (string searchValue);
    void partialSearchPrivate (string searchValue);
    void getStat1 (vector<NominationRecord> allRecords);
    void getStat2 (vector<NominationRecord> allRecords);
    void getStat3 (vector<NominationRecord> allRecords);
    void getStat4 (vector<NominationRecord> allRecords);
    void getStat5 (vector<NominationRecord> allRecords);
    
public:
    NominationsDatabase(){nominationData = nullptr;}
    ~NominationsDatabase() {
        if (nominationData == nullptr) {
            return;
        }
        delete nominationData;
    }
    
    // ask the user for a file name, make a BST using file
    void createNominationsDatabase ();
    
    // a bunch of stats
    void getAllStats ();
    
    // used for output to file
    friend ostream& operator << (ostream &out, NominationsDatabase &list);
    
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

#endif /* NominationsDatabase_hpp */
