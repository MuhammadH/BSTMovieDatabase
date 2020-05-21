//
//  ThespianDatabase.cpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#include "ThespianDatabase.hpp"

void ThespianDatabase::getAnInt (int& inputInt) {
    string newValueString;
    getline(cin, newValueString);
    inputInt = atoi(newValueString.c_str());
}


void ThespianDatabase::modifyARecord() {
    // empty data check
    if (thespianData == nullptr) {
        cout << "BST empty" << endl;
        return;
    }
    
    cout << "You are now modifying a record in Thespian Database." << endl;
    
    cin.ignore();
    
    cout << "Please enter the key of the record you want to modify: " << endl;
    string oldRecord;
    getline(cin, oldRecord);
    
    // delete the record we're now modifying
    bool deleted = thespianData->deleteRecordPublic(oldRecord);
    
    // if that record was not found, return
    if (!deleted) {
        return;
    }
    
    // add a record will let user modify all values
    addARecord(false);
}


void ThespianDatabase::deleteARecord() {
    cin.ignore();
    
    // get a delete key value
    cout << "Please enter the key of the record you want to delete: " << endl;
    string delRecord;
    getline(cin, delRecord);
    
    // pass value into BST delete function
    thespianData->deleteRecordPublic(delRecord);
}



void ThespianDatabase::createThespianDatabase() {
    cout << "Creating actor-actress database" << endl;
    // open file
    fstream dataFile;
    dataFile.open("actor-actress.csv");
    
    if (thespianData != nullptr) {
        // if thespian data is already filled, clear the old one
        delete thespianData;
    }
    // make a new bst for thespian data
    thespianData = new MyBST<ThespianRecord>;
    
    // clear first line
    string tempString;
    getline(dataFile, tempString, '\n');
    
    while (!dataFile.eof()) {
        // make a new record
        ThespianRecord* currentRecord = new ThespianRecord;
        
        // get new values one by one
        
        string yearInput;
        getline(dataFile, yearInput, ',');
        currentRecord->year = atoi(yearInput.c_str());
        
        string awardInput;
        getline(dataFile, awardInput, ',');
        currentRecord->award = awardInput;
        
        string winnerInput;
        getline(dataFile, winnerInput, ',');
        currentRecord->winner = atoi(winnerInput.c_str());
        
        string nameInput;
        getline(dataFile, nameInput, ',');
        currentRecord->name = nameInput;
        
        string filmInput;
        getline(dataFile, filmInput, '\n');
        currentRecord->film = filmInput;
        
        if (!currentRecord->name.empty()) {
            // insert new record
            thespianData->insert(currentRecord);
        } else {
            // if the name is empty, that means it was an empty line
            // which we can delete
            delete currentRecord;
        }
    }
    
    // close file
    dataFile.close();
}

void ThespianDatabase::addARecord(bool ignore) {
    // make a new record
    ThespianRecord* newRecord = new ThespianRecord;
    
    // ignore based on the argument bool
    if (ignore) {
        cin.ignore();
    }
    
    cout << "Youre now adding a new record to the Thespian Database" << endl;
    
    // get values one by one
    // convert to int when needed
    
    cout << "Please enter a number for the year:" << endl;
    int newYear = 0;
    getAnInt(newYear);
    newRecord->year = newYear;
    cout << "You entered: " << newRecord->year << endl;
    
    cout << "Please enter an award:" << endl;
    string newAward;
    getline(cin, newAward);
    newRecord->award = newAward;
    cout << "You entered: " << newRecord->award << endl;
    
    cout << "Please enter 1 or 0 for winner:" << endl;
    int newWin = 0;
    getAnInt(newWin);
    if (newWin == 0 || newWin == 1) {
        newRecord->winner = newWin;
    }
    cout << "You entered: " << newRecord->winner << endl;
    
    cout << "Please enter a name:" << endl;
    string newName;
    getline(cin, newName);
    newRecord->name = newName;
    cout << "You entered: " << newRecord->name << endl;
    
    cout << "Please enter a film:" << endl;
    string newFilm;
    getline(cin, newFilm);
    newRecord->film = newFilm;
    cout << "You entered: " << newRecord->film << endl;
    
    cout << "Added record" << endl;
    // insert the record
    thespianData->insert(newRecord);
}


void ThespianDatabase::resortDatabase(int newSortValue) {
    // get a vector of all records
    vector<ThespianRecord> allRecords = thespianData->getRecordListPublic();
    
    // clear current BST
    thespianData->clearThisBST();
    
    // copy old records, change return value for each record, then resort
    // by passing everything back into insert
    for (int i = 0; i < allRecords.size(); i++) {
        ThespianRecord* newRecord = new ThespianRecord;
        *newRecord = allRecords[i];
        newRecord->returnType = newSortValue;
        thespianData->insert(newRecord);
    }
    
    cout << "Sorted!" << endl;
}

void ThespianDatabase::completeSearch() {
    cout << "What key do you want to search for?" << endl;
    cout << "(This can be any value from any field)" << endl;
    
    cin.ignore();
    
    // get key
    string searchKey;
    getline(cin, searchKey);
    
    // pass to private search
    completeSearchPrivate(searchKey);
    
    cout << "Search done" << endl;
}

void ThespianDatabase::completeSearchPrivate(string searchValue) {
    // get a list of all records
    vector<ThespianRecord> allRecords = thespianData->getRecordListPublic();
    
    // do complete checks on all searchable fields
    for (int i = 0; i < allRecords.size(); i++) {
        if (to_string(allRecords[i].year) == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].award == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].name == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].film == searchValue) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
    }
}

void ThespianDatabase::partialSearch() {
    cout << "What key do you want to search for?" << endl;
    cout << "(This can be any value from any field)" << endl;
    
    cin.ignore();
    
    // get key
    string searchKey;
    getline(cin, searchKey);
    
    // pass key into private helper
    partialSearchPrivate(searchKey);
    
    cout << "Search done" << endl;
}

void ThespianDatabase::partialSearchPrivate(string searchValue) {
    // get a list of all records
    vector<ThespianRecord> allRecords = thespianData->getRecordListPublic();
    
    // partial search all fields
    for (int i = 0; i < allRecords.size(); i++) {
        if (to_string(allRecords[i].year).find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].award.find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].name.find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
        else if (allRecords[i].film.find(searchValue) != std::string::npos) {
            cout << "Found this:" << endl;
            cout << allRecords[i];
        }
    }
}

ostream& operator << (ostream &out, ThespianDatabase &list) {
    // use outstream operator for BST
    out << *list.thespianData;
    return out;
}

void ThespianDatabase::outputFile() {
    // open file
    ofstream outFile;
    outFile.open("ThespianOutput.txt");
    // use database outstream operator
    outFile << *this;
    cout << "Created file: ThespianOutput.txt" << endl;
    // close file
    outFile.close();
}





