//
//  PicturesDatabase.cpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#include "PicturesDatabase.hpp"
#include <ctype.h>

// helper for getting an int
void PicturesDatabase::getAnInt (int& inputInt) {
    string newValueString;
    getline(cin, newValueString);
    inputInt = atoi(newValueString.c_str());
}

// helper for getting an double
void PicturesDatabase::getADouble (double& inputDouble) {
    string newValueString;
    getline(cin, newValueString);
    try {
        inputDouble = stod(newValueString.c_str());
    } catch (...) {
        inputDouble = 0;
    }
}

void PicturesDatabase::deleteARecord() {
    cin.ignore();
    
    cout << "Please enter the key of the record you want to delete: " << endl;
    string delRecord;
    getline(cin, delRecord);
    
    // pass delete key into BST public delete funtion
    pictureData->deleteRecordPublic(delRecord);
}

void PicturesDatabase::addARecord(bool ignore) {
    PictureRecord* newRecord = new PictureRecord;
    
    if (ignore) {
        cin.ignore();
    }
    
    cout << "Youre now adding a new record to the Pictures Database" << endl;
    
    // ask for values one by one
    // convert to ints/ doubles when needed
    
    cout << "Please enter a name:" << endl;
    string newName;
    getline(cin, newName);
    newRecord->name = newName;
    cout << "You entered: " << newRecord->name << endl;
    
    cout << "Please enter a number for the year:" << endl;
    int newYear = 0;
    getAnInt(newYear);
    newRecord->year = newYear;
    cout << "You entered: " << newRecord->year << endl;
    
    cout << "Please enter a number for nominations:" << endl;
    int newNom = 0;
    getAnInt(newNom);
    newRecord->nominations = newNom;
    cout << "You entered: " << newRecord->nominations << endl;
    
    cout << "Please enter a number for rating:" << endl;
    double newRat = 0;
    getADouble(newRat);
    newRecord->rating = newRat;
    cout << "You entered: " << newRecord->rating << endl;
    
    cout << "Please enter a number for duration:" << endl;
    int newDur = 0;
    getAnInt(newDur);
    newRecord->duration = newDur;
    cout << "You entered: " << newRecord->duration << endl;
    
    cout << "Please enter a 1st genre:" << endl;
    string newGen1;
    getline(cin, newGen1);
    newRecord->genre1 = newGen1;
    cout << "You entered: " << newRecord->genre1 << endl;
    
    cout << "Please enter a 2nd genre:" << endl;
    string newGen2;
    getline(cin, newGen2);
    newRecord->genre2 = newGen2;
    cout << "You entered: " << newRecord->genre2 << endl;
    
    cout << "Please enter a release:" << endl;
    string newRel;
    getline(cin, newRel);
    newRecord->release = newRel;
    cout << "You entered: " << newRecord->release << endl;
    
    cout << "Please enter a number for metacritic:" << endl;
    int newMet = 0;
    getAnInt(newMet);
    newRecord->metacritic = newMet;
    cout << "You entered: " << newRecord->metacritic << endl;
    
    cout << "Please enter a synopsis:" << endl;
    string newSyn;
    getline(cin, newSyn);
    newRecord->synopsis = newSyn;
    cout << "You entered: " << newRecord->synopsis << endl;
    
    cout << "Added record" << endl;
    // insert this new record
    pictureData->insert(newRecord);
}

void PicturesDatabase::modifyARecord() {
    // head check
    if (pictureData == nullptr) {
        cout << "BST empty" << endl;
        return;
    }
    
    cout << "You are now modifying a record in Picture Database." << endl;
    
    cin.ignore();
    
    // get key for modified record
    cout << "Please enter the key of the record you want to modify: " << endl;
    string oldRecord;
    getline(cin, oldRecord);
    
    // find the record
    bool deleted = pictureData->deleteRecordPublic(oldRecord);
    
    // return in not found
    if (!deleted) {
        return;
    }
    
    // modify the fields of the record and insert
    addARecord(false);
}


void PicturesDatabase::createPictureDatabase() {
    cout << "Creating picture database" << endl;
    // open file
    fstream dataFile;
    dataFile.open("pictures.csv");
    
    if (pictureData != nullptr) {
        // clear old picture data if there is any
        delete pictureData;
    }
    // make a new BST for this database
    pictureData = new MyBST<PictureRecord>;
    
    // clear first line of csv
    string tempString;
    getline(dataFile, tempString, '\n');
    
    // cout << "temp string: " << tempString << endl;
    
    // until end of file
    while (!dataFile.eof()) {
        // make a new record
        PictureRecord* currentRecord = new PictureRecord;
        
        // get name
        string nameInput;
        getline(dataFile, nameInput, ',');
        // for some reason, every name in this file starts with a blank space
        // so delete them
        nameInput.erase(0, 1);
        currentRecord->name = nameInput;
        
        string yearInput;
        getline(dataFile, yearInput, ',');
        currentRecord->year = atoi(yearInput.c_str());
        
        string nominationsInput;
        getline(dataFile, nominationsInput, ',');
        currentRecord->nominations = atoi(nominationsInput.c_str());
        
        string ratingInput;
        getline(dataFile, ratingInput, ',');
        if (!currentRecord->name.empty()) {
            currentRecord->rating = stod(ratingInput.c_str());
        }
        
        string durationInput;
        getline(dataFile, durationInput, ',');
        currentRecord->duration = atoi(durationInput.c_str());
        
        string genre1Input;
        getline(dataFile, genre1Input, ',');
        currentRecord->genre1 = genre1Input;
        
        string genre2Input;
        getline(dataFile, genre2Input, ',');
        currentRecord->genre2 = genre2Input;
        
        string releaseInput;
        getline(dataFile, releaseInput, ',');
        currentRecord->release = releaseInput;
        
        string metaInput;
        getline(dataFile, metaInput, ',');
        currentRecord->metacritic = atoi(metaInput.c_str());
        
        string synopsisInput;
        getline(dataFile, synopsisInput, '\n');
        currentRecord->synopsis = synopsisInput;
        
        if (!currentRecord->name.empty()) {
            // add new record
            pictureData->insert(currentRecord);
        } else {
            // delete if blank
            delete currentRecord;
        }
    }
    
    // close file
    dataFile.close();
}


void PicturesDatabase::resortDatabase(int newSortValue) {
    // get a list of all the records in BST
    vector<PictureRecord> allRecords = pictureData->getRecordListPublic();
    
    // clear old data
    pictureData->clearThisBST();
    
    // copy old data but provide new return value
    // re sort by re inserting
    for (int i = 0; i < allRecords.size(); i++) {
        PictureRecord* newRecord = new PictureRecord;
        *newRecord = allRecords[i];
        newRecord->returnType = newSortValue;
        pictureData->insert(newRecord);
    }
    
    cout << "Sorted!" << endl;
}




void PicturesDatabase::completeSearch() {
    cout << "What key do you want to search for?" << endl;
    cout << "(This can be any value from any field)" << endl;
    
    cin.ignore();
    
    string searchKey;
    getline(cin, searchKey);
    
    // pass key into somplete search private helper
    completeSearchPrivate(searchKey);
    
    cout << "Search done" << endl;
}

void PicturesDatabase::completeSearchPrivate(string searchValue) {
    // get a list of all records
    vector<PictureRecord> allRecords = pictureData->getRecordListPublic();
    
    // search each field completely for searchValue
    // use to_string when needed
    for (int i = 0; i < allRecords.size(); i++) {
        if (allRecords[i].name == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (to_string(allRecords[i].year) == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (to_string(allRecords[i].nominations) == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (to_string(allRecords[i].rating) == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (to_string(allRecords[i].duration) == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].genre1 == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].genre2 == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].release == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (to_string(allRecords[i].metacritic) == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].synopsis == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
    }
    
}



void PicturesDatabase::partialSearch() {
    cout << "What key do you want to search for?" << endl;
    cout << "(This can be any value from any field)" << endl;
    
    cin.ignore();
    
    string searchKey;
    getline(cin, searchKey);
    
    // pass key into private helper
    partialSearchPrivate(searchKey);
    
    cout << "Search done" << endl;
}

void PicturesDatabase::partialSearchPrivate(string searchValue) {
    // get a list of all records
    vector<PictureRecord> allRecords = pictureData->getRecordListPublic();
    
    // search to see if any record contains the searchValue inside of it
    for (int i = 0; i < allRecords.size(); i++) {
        if (allRecords[i].name.find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (to_string(allRecords[i].year).find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (to_string(allRecords[i].nominations).find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (to_string(allRecords[i].rating).find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (to_string(allRecords[i].duration).find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].genre1.find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].genre2.find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].release.find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (to_string(allRecords[i].metacritic).find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].synopsis.find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
    }
}


ostream& operator << (ostream &out, PicturesDatabase &list) {
    // use BST output operator
    out << *list.pictureData;
    return out;
}


void PicturesDatabase::outputFile() {
    // open file
    ofstream outFile;
    outFile.open("PicturesOutput.txt");
    // output database
    outFile << *this;
    cout << "Created file: PicturesOutput.txt" << endl;
    // close file
    outFile.close();
}









