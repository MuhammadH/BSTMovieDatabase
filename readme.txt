                 Read Me


*******************************************************
*  Description of the program
*******************************************************


This program makes a three databases for 3 datasets (historic Oscar nominations for 3 categories). The databases are based on custom binary search trees and have all the functionality of BSTs. 

This was a project for data structures. Good examples of templates use if I ever need to look back on it. 


*******************************************************
*  Issues
*******************************************************

Looking back on it, the biggest issue here is having 3 separate database classes for nominations, pictures, and thespians. There are good reasons for specializations for each type of database here, but it still could have been a more generalized and reusable database. 

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
Main program. Creates databases, tests functionality. 


Name:  MenuDriver
This class runs the menu system. 

Name:  MyBST
This is the custom BST which the databases are based on. 

Name:  NominationRecord
Data type for nomination records. 

Name:  NominationDatabase
Database encapsulating the nomination records BST. 

Name:  PictureRecord
Data type for picture records. 

Name:  PicturesDatabase
Database encapsulating the picture records BST. 

Name:  ThespianRecord
Data type for thespian records. 

Name:  ThespianDatabase
Database encapsulating the thespian records BST. 