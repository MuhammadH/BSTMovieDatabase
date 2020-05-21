//
//  NominationRecord.cpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#include "NominationRecord.hpp"

string NominationRecord::getKey() {
    if (returnType == 0) {
        return name;
    }
    else if (returnType == 1) {
        return to_string(year);
    }
    else if (returnType == 2) {
        return award;
    }
    else if (returnType == 3) {
        return film;
    }
    return name;
}

NominationRecord::NominationRecord () {
    left = nullptr;
    right = nullptr;
    
    year = 0;
    award = " ";
    winner = false;
    name = " ";
    film = " ";
    
    returnType = 0;
}

ostream& operator << (ostream &out, NominationRecord &record) {
    
    out
    << record.year << ","
    << record.award << ","
    << record.winner << ","
    << record.name << ","
    << record.film << ","
    << endl;
    
    return out;
}
