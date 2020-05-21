//
//  MenuDriver.cpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/23/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#include "MenuDriver.hpp"

//    1.    Add a record.
//    a.    Add a record to ThespianDatabase.
//    b.    Add a record to PictureDatabase.
//    c.    Add a record to NominationDatabase.
//    2.    Modify a record.
//    a.    Modify a record in ThespianDatabase.
//    b.    Modify a record in PictureDatabase.
//    c.    Modify a record in NominationDatabase.
//    d.    Nevermind, go back.
//    3.    Delete a record.
//    a.    Delete a record in ThespianDatabase.
//    b.    Delete a record in PictureDatabase.
//    c.    Delete a record in NominationDatabase.
//    d.    Nevermind, go back.
//    4.    Sort a database.
//    a.    Sort ThespianDatabase.
//    i.    Sort by year.
//    ii.    Sort by award.
//    iii.    Sort by name.
//    iv.    Sort by film.
//    b.    Sort PictureDatabase.
//    i.    Sort by name.
//    ii.    Sort by year.
//    iii.    Sort by nominations.
//    iv.    Sort by rating.
//    v.    Sort by duration.
//    vi.    Sort by genre1.
//    vii.    Sort by genre2.
//    viii.    Sort by release.
//    ix.    Sort by Metacritic.
//    c.    Sort NominationDatabase.
//    i.    Sort by year.
//    ii.    Sort by award.
//    iii.    Sort by name.
//    d.    Nevermind, go back.
//    5.    Do a complete search.
//    a.    Search ThespianDatabase.
//    b.    Search PictureDatabase.
//    c.    Search NominationDatabase.
//    6.    Do a partial search.
//    a.    Search ThespianDatabase.
//    b.    Search PictureDatabase.
//    c.    Search NominationDatabase.
//    7.    Output file.
//    a.    Output ThespianDatabase.
//    b.    Output PictureDatabase.
//    c.    Output NominationDatabase.
//    8.    Print 5 statistics for Nominations.
//    9.    Exit.


int MenuDriver::activateMenu() {
    return offerTopMenu();
}

int MenuDriver::offerTopMenu() {
    
    cout << "Please select an option:" << endl;
    cout << "1.    Add a record." << endl;
    cout << "2.    Modify a record." << endl;
    cout << "3.    Delete a record." << endl;
    cout << "4.    Sort a database." << endl;
    cout << "5.    Do a complete search." << endl;
    cout << "6.    Do a partial search." << endl;
    cout << "7.    Output file." << endl;
    cout << "8.    Print 5 statistics for Nominations." << endl;
    cout << "9.    Exit." << endl;
    
    int returnValue = 10;
    
    char selection = '-';
    cin >> selection;
    
    switch (selection) {
        case '1':
            returnValue = offerSubMenu1();
            break;
        case '2':
            returnValue = offerSubMenu2();
            break;
        case '3':
            returnValue = offerSubMenu3();
            break;
        case '4':
            returnValue = offerSubMenu4();
            break;
        case '5':
            returnValue = offerSubMenu5();
            break;
        case '6':
            returnValue = offerSubMenu6();
            break;
        case '7':
            returnValue = offerSubMenu7();
            break;
        case '8':
            returnValue = 81;
            break;
        case '9':
            returnValue = 9;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    return returnValue;
}

int MenuDriver::offerSubMenu1() {
    int returnValue = 10;
    
    cout << "Please select an option:" << endl;
    cout << "1.    Add a record to ThespianDatabase." << endl;
    cout << "2.    Add a record to PictureDatabase." << endl;
    cout << "3.    Add a record to NominationDatabase." << endl;
    cout << "4.    Nevermind. Go to top menu." << endl;
    
    char selection = '-';
    cin >> selection;
    
    switch (selection) {
        case '1':
            returnValue = 11;
            break;
        case '2':
            returnValue = 12;
            break;
        case '3':
            returnValue = 13;
            break;
        case '4':
            returnValue = 10;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    
    return returnValue;
}

int MenuDriver::offerSubMenu2() {
    int returnValue = 10;
    
    cout << "Please select an option:" << endl;
    cout << "1.    Modify a record in ThespianDatabase." << endl;
    cout << "2.    Modify a record in PictureDatabase." << endl;
    cout << "3.    Modify a record in NominationDatabase." << endl;
    cout << "4.    Nevermind. Go to top menu." << endl;
    
    char selection = '-';
    cin >> selection;
    switch (selection) {
        case '1':
            returnValue = 21;
            break;
        case '2':
            returnValue = 22;
            break;
        case '3':
            returnValue = 23;
            break;
        case '4':
            returnValue = 10;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    
    return returnValue;
}

int MenuDriver::offerSubMenu3() {
    int returnValue = 10;
    
    cout << "Please select an option:" << endl;
    cout << "1.    Delete a record in ThespianDatabase." << endl;
    cout << "2.    Delete a record in PictureDatabase." << endl;
    cout << "3.    Delete a record in NominationDatabase." << endl;
    cout << "4.    Nevermind. Go to top menu." << endl;
    
    char selection = '-';
    cin >> selection;
    switch (selection) {
        case '1':
            returnValue = 31;
            break;
        case '2':
            returnValue = 32;
            break;
        case '3':
            returnValue = 33;
            break;
        case '4':
            returnValue = 10;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    
    return returnValue;
}

int MenuDriver::offerSubMenu4() {
    int returnValue = 10;
    
    cout << "Please select an option:" << endl;
    cout << "1.    Sort ThespianDatabase." << endl;
    cout << "2.    Sort PictureDatabase." << endl;
    cout << "3.    Sort NominationDatabase." << endl;
    cout << "4.    Nevermind. Go to top menu." << endl;
    
    char selection = '-';
    cin >> selection;
    switch (selection) {
        case '1':
            returnValue = offerSubMenu41();
            break;
        case '2':
            returnValue = offerSubMenu42();
            break;
        case '3':
            returnValue = offerSubMenu43();
            break;
        case '4':
            returnValue = 10;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    
    return returnValue;
}

int MenuDriver::offerSubMenu41() {
    int returnValue = 10;
    
    cout << "Please select an option:" << endl;
    cout << "1.    Sort by year." << endl;
    cout << "2.    Sort by award." << endl;
    cout << "3.    Sort by name." << endl;
    cout << "4.    Sort by film." << endl;
    
    char selection = '-';
    cin >> selection;
    switch (selection) {
        case '1':
            returnValue = 411;
            break;
        case '2':
            returnValue = 412;
            break;
        case '3':
            returnValue = 413;
            break;
        case '4':
            returnValue = 414;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    
    return returnValue;
}

int MenuDriver::offerSubMenu42() {
    int returnValue = 10;
    
    cout << "Please select an option:" << endl;
    cout << "1.    Sort by name." << endl;
    cout << "2.    Sort by year." << endl;
    cout << "3.    Sort by nominations." << endl;
    cout << "4.    Sort by rating." << endl;
    
    cout << "5.    Sort by duration." << endl;
    cout << "6.    Sort by genre1." << endl;
    cout << "7.    Sort by genre2." << endl;
    cout << "8.    Sort by Metacritic." << endl;
    
    char selection = '-';
    cin >> selection;
    switch (selection) {
        case '1':
            returnValue = 421;
            break;
        case '2':
            returnValue = 422;
            break;
        case '3':
            returnValue = 423;
            break;
        case '4':
            returnValue = 424;
            break;
            
        case '5':
            returnValue = 425;
            break;
        case '6':
            returnValue = 426;
            break;
        case '7':
            returnValue = 427;
            break;
        case '8':
            returnValue = 428;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    
    return returnValue;
}

int MenuDriver::offerSubMenu43() {
    int returnValue = 10;
    
    cout << "Please select an option:" << endl;
    cout << "1.    Sort by year." << endl;
    cout << "2.    Sort by award." << endl;
    cout << "3.    Sort by name." << endl;
    cout << "4.    Sort by film." << endl;
    
    char selection = '-';
    cin >> selection;
    switch (selection) {
        case '1':
            returnValue = 431;
            break;
        case '2':
            returnValue = 432;
            break;
        case '3':
            returnValue = 433;
            break;
        case '4':
            returnValue = 434;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    
    return returnValue;
}






int MenuDriver::offerSubMenu5() {
    int returnValue = 10;
    
    cout << "Please select an option:" << endl;
    cout << "1.    Search ThespianDatabase." << endl;
    cout << "2.    Search PictureDatabase." << endl;
    cout << "3.    Search NominationDatabase." << endl;
    cout << "4.    Nevermind. Go to top menu." << endl;
    
    char selection = '-';
    cin >> selection;
    switch (selection) {
        case '1':
            returnValue = 51;
            break;
        case '2':
            returnValue = 52;
            break;
        case '3':
            returnValue = 53;
            break;
        case '4':
            returnValue = 10;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    
    return returnValue;
}

int MenuDriver::offerSubMenu6() {
    int returnValue = 10;
    
    cout << "Please select an option:" << endl;
    cout << "1.    Search ThespianDatabase." << endl;
    cout << "2.    Search PictureDatabase." << endl;
    cout << "3.    Search NominationDatabase." << endl;
    cout << "4.    Nevermind. Go to top menu." << endl;
    
    char selection = '-';
    cin >> selection;
    switch (selection) {
        case '1':
            returnValue = 61;
            break;
        case '2':
            returnValue = 62;
            break;
        case '3':
            returnValue = 63;
            break;
        case '4':
            returnValue = 10;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    
    return returnValue;
}

int MenuDriver::offerSubMenu7() {
    int returnValue = 10;
    
    cout << "Please select an option:" << endl;
    cout << "1.    Output ThespianDatabase." << endl;
    cout << "2.    Output PictureDatabase." << endl;
    cout << "3.    Output NominationDatabase." << endl;
    cout << "4.    Nevermind. Go to top menu." << endl;
    
    char selection = '-';
    cin >> selection;
    switch (selection) {
        case '1':
            returnValue = 71;
            break;
        case '2':
            returnValue = 72;
            break;
        case '3':
            returnValue = 73;
            break;
        case '4':
            returnValue = 10;
            break;
            
        default:
            cout << "please enter a valid input" << endl;
            returnValue = 10;
            break;
    }
    
    return returnValue;
}
