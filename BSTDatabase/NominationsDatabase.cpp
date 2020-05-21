//
//  NominationsDatabase.cpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#include "NominationsDatabase.hpp"

// getting int input helper
void NominationsDatabase::getAnInt (int& inputInt) {
    string newValueString;
    getline(cin, newValueString);
    inputInt = atoi(newValueString.c_str());
}

void NominationsDatabase::modifyARecord() {
    // head check
    if (nominationData == nullptr) {
        cout << "BST empty" << endl;
        return;
    }
    
    cout << "You are now modifying a record in the Nominations Database." << endl;
    
    cin.ignore();
    
    // get record key
    cout << "Please enter the key of the record you want to modify: " << endl;
    string oldRecord;
    getline(cin, oldRecord);
    
    // pass key into delete
    bool deleted = nominationData->deleteRecordPublic(oldRecord);
    
    // if record not found, return
    if (!deleted) {
        return;
    }
    
    // ask for new field values and insert to BST
    addARecord(false);
}

void NominationsDatabase::deleteARecord() {
    cin.ignore();
    
    cout << "Please enter the key of the record you want to delete: " << endl;
    string delRecord;
    getline(cin, delRecord);
    
    // pass delete value into BST public delete funtion
    nominationData->deleteRecordPublic(delRecord);
}

void NominationsDatabase::addARecord(bool ignore) {
    // make a nre record
    NominationRecord* newRecord = new NominationRecord;
    
    if (ignore) {
        cin.ignore();
    }
    
    cout << "Youre now adding a new record to the Nominations Database" << endl;
    
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
    // insert new record into BST
    nominationData->insert(newRecord);
}





void NominationsDatabase::createNominationsDatabase() {
    cout << "Creating Nominations database" << endl;
    // open file
    fstream dataFile;
    dataFile.open("nominations.csv");
    
    if (nominationData != nullptr) {
        // clear old data if there is any
        delete nominationData;
    }
    // make new BST for database
    nominationData = new MyBST<NominationRecord>;
    
    // clear first line of file
    string tempString;
    getline(dataFile, tempString, '\n');
    
    // until end of file
    while (!dataFile.eof()) {
        // make a new record
        NominationRecord* currentRecord = new NominationRecord;
        
        // get values one by one
        
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
        // some of the names have blank spaces at the end in the csv file
        // delete trailing blanks if there are any
        if (nameInput.size() > 0 && nameInput[nameInput.size() - 1] == ' ') {
            nameInput.pop_back();
        }
        currentRecord->name = nameInput;
        
        // the lines in this csv file don't end a comma
        string filmInput;
        getline(dataFile, filmInput, ',');
        currentRecord->film = filmInput;
        
        // after last comma, get the newline
        getline(dataFile, filmInput, '\n');
        
        if (!currentRecord->name.empty()) {
            // insert record
            nominationData->insert(currentRecord);
        } else {
            // delete record if blank
            delete currentRecord;
        }
    }
    
    // close file
    dataFile.close();
}


void NominationsDatabase::resortDatabase(int newSortValue) {
    cout << "Starting sort..." << endl;
    
    // get a list of all records
    vector<NominationRecord> allRecords = nominationData->getRecordListPublic();
    
    // clear old data
    nominationData->clearThisBST();
    
    // copy old data but change return key
    // then re insert
    for (int i = 0; i < allRecords.size(); i++) {
        NominationRecord* newRecord = new NominationRecord;
        *newRecord = allRecords[i];
        newRecord->returnType = newSortValue;
        nominationData->insert(newRecord);
    }
    
    cout << "Sorted!" << endl;
}


void NominationsDatabase::completeSearch() {
    cout << "What key do you want to search for?" << endl;
    cout << "(This can be any value from any field)" << endl;
    
    cin.ignore();
    
    string searchKey;
    getline(cin, searchKey);
    
    cout << "Searching..." << endl;
    
    // pass key into private helper
    completeSearchPrivate(searchKey);
    
    cout << "Search done" << endl;
}

void NominationsDatabase::completeSearchPrivate(string searchValue) {
    // get a list of all records
    vector<NominationRecord> allRecords = nominationData->getRecordListPublic();
    
    // check each field to see if it matches input
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



void NominationsDatabase::partialSearch() {
    cout << "What key do you want to search for?" << endl;
    cout << "(This can be any value from any field)" << endl;
    
    cin.ignore();
    
    string searchKey;
    getline(cin, searchKey);
    
    cout << "Searching..." << endl;
    
    // pass key into private helper
    partialSearchPrivate(searchKey);
    
    cout << "Search done" << endl;
}

void NominationsDatabase::partialSearchPrivate(string searchValue) {
    // get a list of all records
    vector<NominationRecord> allRecords = nominationData->getRecordListPublic();
    
    // check if each field contains input
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

ostream& operator << (ostream &out, NominationsDatabase &list) {
    // use BST output operator
    out << *list.nominationData;
    return out;
}

void NominationsDatabase::outputFile() {
    cout << "Creating file..." << endl;
    // open file
    ofstream outFile;
    outFile.open("NominationOutput.txt");
    // output database
    outFile << *this;
    cout << "Created file: NominationOutput.txt" << endl;
    // close file
    outFile.close();
}

void NominationsDatabase::getAllStats() {
    cout << "Getting stats..." << endl;
    
    // get a list of records to pass into stats finder
    vector<NominationRecord> allRecords = nominationData->getRecordListPublic();
    
    cout << "getting stat 1:" << endl;
    getStat1(allRecords);
    cout << "getting stat 2:" << endl;
    getStat2(allRecords);
    cout << "getting stat 3:" << endl;
    getStat3(allRecords);
    cout << "getting stat 4:" << endl;
    getStat4(allRecords);
    cout << "getting stat 5:" << endl;
    getStat5(allRecords);
}

void NominationsDatabase::getStat1(vector<NominationRecord> allRecords) {
    // set search key
    string searchFor = "Mad Max: Fury Road";
    int count = 0;
    
    for (int i = 0; i < allRecords.size(); i++) {
        // check to see if mad max matches each field
        if (allRecords[i].film == searchFor) {
            count++;
        }
        else if (allRecords[i].name == searchFor) {
            count++;
        }
    }
    
    // output report
    cout << "Mad Max: Fury Road was nominated for " << count << " awards." << endl;
}

void NominationsDatabase::getStat2(vector<NominationRecord> allRecords) {
    // set search key
    string searchFor = "Rachel McAdams";
    int count = 0;
    
    // check to see if key matches name field
    for (int i = 0; i < allRecords.size(); i++) {
        if (allRecords[i].name == searchFor) {
            count++;
        }
    }
    
    // output report
    cout << "Rachel McAdams was nominated for " << count << " award." << endl;
}

void NominationsDatabase::getStat3(vector<NominationRecord> allRecords) {
    // set search key
    string searchFor = "1934";
    int count = 0;
    
    // check to see if key matches year field
    for (int i = 0; i < allRecords.size(); i++) {
        if (to_string(allRecords[i].year) == searchFor) {
            count++;
        }
    }
    
    // output report
    cout << "There were " << count << " awards awarded in 1934." << endl;
}

void NominationsDatabase::getStat4(vector<NominationRecord> allRecords) {
    // set search key
    string searchFor = "Actor in a Leading Role";
    int count = 0;
    
    // check to see if key matches award field
    for (int i = 0; i < allRecords.size(); i++) {
        if (allRecords[i].award == searchFor) {
            count++;
        }
    }
    
    // output report
    cout << "There have been " << count
    << " total nominations for Actor in a Leading Role so far." << endl;
}

void NominationsDatabase::getStat5(vector<NominationRecord> allRecords) {
    // set search key
    string searchFor = "Writing";
    int count = 0;
    
    // check to see if key is contained in award field
    for (int i = 0; i < allRecords.size(); i++) {
        if (allRecords[i].award.find(searchFor) != std::string::npos) {
            count++;
        }
    }
    
    // output report
    cout << "There have been " << count
    << " total awards given out for writing so far." << endl;
}







