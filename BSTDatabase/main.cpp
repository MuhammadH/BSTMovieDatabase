//
//  main.cpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#include <iostream>
#include <string>

#include "NominationsDatabase.hpp"
#include "MenuDriver.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    // create thespian database
    ThespianDatabase mainThespianDatabase;
    mainThespianDatabase.createThespianDatabase();
    
    // create picture database
    PicturesDatabase mainPicturesDatabase;
    mainPicturesDatabase.createPictureDatabase();
    
    // create nomination database
    NominationsDatabase mainNomDatabase;
    mainNomDatabase.createNominationsDatabase();
    
    // menu driver drives menu and gets menu selection
    // funtions happen based on menu selection
    MenuDriver mainMenu;
    int menuSelection = -1;
    while (menuSelection != 9) {
        
        menuSelection = mainMenu.activateMenu();
        
        
        if (menuSelection == 11) {
            mainThespianDatabase.addARecord(true);
        }
        else if (menuSelection == 12) {
            mainPicturesDatabase.addARecord(true);
        }
        else if (menuSelection == 13) {
            mainNomDatabase.addARecord(true);
        }
        
        
        else if (menuSelection == 21) {
            mainThespianDatabase.modifyARecord();
        }
        else if (menuSelection == 22) {
            mainPicturesDatabase.modifyARecord();
        }
        else if (menuSelection == 23) {
            mainNomDatabase.modifyARecord();
        }
        
        
        else if (menuSelection == 31) {
            mainThespianDatabase.deleteARecord();
        }
        else if (menuSelection == 32) {
            mainPicturesDatabase.deleteARecord();
        }
        else if (menuSelection == 33) {
            mainNomDatabase.deleteARecord();
        }
        
        
        else if (menuSelection == 411) {
            mainThespianDatabase.resortDatabase(2);
        }
        else if (menuSelection == 412) {
            mainThespianDatabase.resortDatabase(1);
        }
        else if (menuSelection == 413) {
            mainThespianDatabase.resortDatabase(0);
        }
        else if (menuSelection == 414) {
            mainThespianDatabase.resortDatabase(3);
        }
        
        
        else if (menuSelection == 421) {
            mainPicturesDatabase.resortDatabase(0);
        }
        else if (menuSelection == 422) {
            mainPicturesDatabase.resortDatabase(1);
        }
        else if (menuSelection == 423) {
            mainPicturesDatabase.resortDatabase(3);
        }
        else if (menuSelection == 424) {
            mainPicturesDatabase.resortDatabase(4);
        }
        else if (menuSelection == 425) {
            mainPicturesDatabase.resortDatabase(5);
        }
        else if (menuSelection == 426) {
            mainPicturesDatabase.resortDatabase(6);
        }
        else if (menuSelection == 427) {
            mainPicturesDatabase.resortDatabase(7);
        }
        else if (menuSelection == 428) {
            mainPicturesDatabase.resortDatabase(8);
        }
        
        
        else if (menuSelection == 431) {
            mainNomDatabase.resortDatabase(1);
        }
        else if (menuSelection == 432) {
            mainNomDatabase.resortDatabase(2);
        }
        else if (menuSelection == 433) {
            mainNomDatabase.resortDatabase(0);
        }
        else if (menuSelection == 434) {
            mainNomDatabase.resortDatabase(3);
        }
        
        
        else if (menuSelection == 51) {
            mainThespianDatabase.completeSearch();
        }
        else if (menuSelection == 52) {
            mainPicturesDatabase.completeSearch();
        }
        else if (menuSelection == 53) {
            mainNomDatabase.completeSearch();
        }
        
        
        else if (menuSelection == 61) {
            mainThespianDatabase.partialSearch();
        }
        else if (menuSelection == 62) {
            mainPicturesDatabase.partialSearch();
        }
        else if (menuSelection == 63) {
            mainNomDatabase.partialSearch();
        }
        
        
        else if (menuSelection == 71) {
            mainThespianDatabase.outputFile();
        }
        else if (menuSelection == 72) {
            mainPicturesDatabase.outputFile();
        }
        else if (menuSelection == 73) {
            mainNomDatabase.outputFile();
        }
        
        else if (menuSelection == 81) {
            mainNomDatabase.getAllStats();
        }
    }
    
    return 0;
}
