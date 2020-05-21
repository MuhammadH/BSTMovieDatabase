//
//  PicturesDatabase.hpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#ifndef PicturesDatabase_hpp
#define PicturesDatabase_hpp

#include <stdio.h>
#include "ThespianDatabase.hpp"
#include "PictureRecord.hpp"

using namespace std;

class PicturesDatabase {
    MyBST<PictureRecord>* pictureData;
    
    // private helpers
    void completeSearchPrivate (string searchValue);
    void partialSearchPrivate (string searchValue);
    
public:
    PicturesDatabase(){pictureData = nullptr;}
    ~PicturesDatabase() {
        if (pictureData == nullptr) {
            return;
        }
        delete pictureData;
    }
    
    // ask the user for a file name, make a BST using file
    void createPictureDatabase ();
    
    // used for output to file
    friend ostream& operator << (ostream &out, PicturesDatabase &list);
    
    // below here are all the ways main can interact with a database
    void addARecord (bool ignore);
    void modifyARecord ();
    void deleteARecord ();
    void resortDatabase (int newSortValue);
    void completeSearch ();
    void partialSearch ();
    void outputFile ();
    
    // additional funtions
    void getAnInt (int& inputInt);
    void getADouble (double& inputDouble);
};

#endif /* PicturesDatabase_hpp */
