//
//  PictureRecord.cpp
//  HussainMHW7
//
//  Created by Muhammad Hussain on 4/6/19.
//  Copyright © 2019 Muhammad Hussain. All rights reserved.
//

#include "PictureRecord.hpp"

string PictureRecord::getKey() {
    if (returnType == 0) {
        return name;
    }
    else if (returnType == 1) {
        return to_string(year);
    }
    else if (returnType == 2) {
        return to_string(nominations);
    }
    else if (returnType == 3) {
        return to_string(rating);
    }
    else if (returnType == 4) {
        return to_string(duration);
    }
    else if (returnType == 5) {
        return genre1;
    }
    else if (returnType == 6) {
        return genre2;
    }
    else if (returnType == 7) {
        return release;
    }
    else if (returnType == 8) {
        return to_string(metacritic);
    }
    else if (returnType == 9) {
        return synopsis;
    }
    return name;
}

PictureRecord::PictureRecord () {
    left = nullptr;
    right = nullptr;
    
    name = " ";
    year = 0;
    nominations = 0;
    rating = 0.0;
    duration = 0;
    genre1 = " ";
    genre2 = " ";
    release = " ";
    metacritic = 0;
    synopsis = " ";
    
    returnType = 0;
}

ostream& operator << (ostream &out, PictureRecord &record) {
    
    out << record.name << ","
    << record.year << ","
    << record.nominations << ","
    << record.rating << ","
    << record.duration << ","
    << record.genre1 << ","
    << record.genre2 << ","
    << record.release << ","
    << record.metacritic << ","
    << record.synopsis << ","
    << endl;
    
    return out;
}
