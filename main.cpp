#include<iostream>
#include<iomanip>
#include "citation.h"
#include<string>
#include<iomanip>
#include<cctype>
#include<unistd.h>
using namespace std;

struct apaRecord{
  int type;
  string date;
  string pages;
  string author;
  string title;
  string pubCity;
  string PubState;
  string publisher;
  string journalTitle;
  string journalVolume;
  string doiUrl;
};
void apaJournal(Citation list);
void apaMagazine(Citation list);
void apaBook(Citation list);
void apaNewspaper(Citation list);
void mlaJournal(Citation list);
void mlaMagazine(Citation list);
void mlaBook(Citation list);
void mlaNewspaper(Citation list);
void splash();
void apa();
void mla();
int menu();

int main(){


  splash();
  switch (menu()){
    case 1:
      apa();
      break;
    case 2:
      mla();
      break;
  }


  return 0;
}
//////////////////////////////////////////
//Menu Function                         //
//////////////////////////////////////////
//Displays the main menu and sub menus  //
//////////////////////////////////////////
//Parameters: none                      //
//////////////////////////////////////////
//return Type: int                      //
//selection-indicates the style and type//
//////////////////////////////////////////
int menu(){

  //menu function
  //cout << "\33[H\33[2J"; // clears the screen
  //variables for the user to enter menu choices
  int selection;
  //main menu with user input
  cout << endl << "-----------------Citation Machine------------------" << endl << endl;
  cout << endl;
  cout << "1. APA style" << endl << "2. MLA style" << endl << endl;
  cout << "Which citation format would you like to use to cite your work? " ;
  cin >> selection;
  cout << endl << "---------------------------------------------------" << endl << endl;
  //input validating loop
  while (selection != 1 && selection != 2)
  {
    cout << "INVALID ENTRY!" << endl;
    cout << "Which Format would you like to cite your work?" << endl;
    cout << "1. APA style" << endl << "2. MLA style" << endl;
    cin >> selection;
    cout << endl << "---------------------------------------------------" << endl << endl;
  }

  return selection;
}

void splash(){
  cout << "\33[H\33[2J"; // clears the screen
  cout<<"    ___          _ _                ___"<<endl;
  cout<<"   / __\\___   __| (_)_ __   __ _   / _| ___  _ __    __ _    ___ __ _ _   _ ___  ___ "<<endl;
  cout<<"  / /  / _ \\ / _  | | '_ \\ / _` | | |_ / _ \\| '__|  / _` |  / __/ _` | | | / __|/ _ \\  "<<endl;
  cout<<" / /__| (_) | (_| | | | | | (_| | |  _| (_) | |    | (_| | | (_| (_| | |_| \\__ \\  __/ "<<endl;
  cout<<" \\____/\\___/ \\__,_|_|_| |_|\\__, | |_|  \\___/|_|     \\__,_|  \\___\\__,_|\\__,_|___/\\___| "<<endl;
  cout<<"                           |___/                                                      "<<endl;
  cout<<"    ___ _ _        _   _                 ___                          _" <<endl;
  cout<<"   / __(_) |_ __ _| |_(_) ___  _ __     / _ \\___ _ __   ___ _ __ __ _| |_ ___  _ __" <<endl;
  cout<<"  / /  | | __/ _` | __| |/ _ \\| '_ \\   / /_\\/ _ \\ '_ \\ / _ \\ '__/ _` | __/ _ \\| '__|" <<endl;
  cout<<" / /___| | || (_| | |_| | (_) | | | | / /_\\\\  __/ | | |  __/ | | (_| | || (_) | |" <<endl;
  cout<<" \\____/|_|\\__\\__,_|\\__|_|\\___/|_| |_| \\____/\\___|_| |_|\\___|_|  \\__,_|\\__\\___/|_|" <<endl;
  usleep(1000000);
  usleep(1000000);

}

void apa(){
  int choice;
  string c;
  bool done = false;
  int type;
  Citation list;

  while (!done){
    cout << "\33[H\33[2J"; // clears the screen
    cout << "1. Journal" << endl
         << "2. Magazine Article" << endl
         << "3. Newspaper" << endl
         << "4. Book" << endl << endl;
    cout << "What type of source are you citing? ";
    cin >> type;

    while (type < 1 || type > 5){
      cout << "\33[H\33[2J"; // clears the screen
      cout << "1. Journal" << endl
           << "2. Magazine Article" << endl
           << "3. Newspaper" << endl
           << "4. Book" << endl << endl;
      cout << type << " is an invaild option.\n";
      cout << "What type of source are you citing? ";
      cin >> type;
    }

    switch (type) {
      case 1:
        apaJournal(list);
        break;
      case 2:
        apaMagazine(list);
        break;
      case 3:
        apaNewspaper(list);
        break;
      case 4:
        apaBook(list);
        break;
    }

    cout << "Is that all the refrences?(y/N) ";
    getline(cin,c);

    if (tolower(c.front())== 'y')
      done = true;
  }
  cout << "\33[H\33[2J"; // clears the screen
  list.display();

}

void apaJournal(Citation list){
  apaRecord record;
  int choice;
  char c;
  bool done = false;
  int type;
  cin.clear();
  cin.ignore();
  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the author: ";
  cin.clear();
  getline(cin, record.author);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the year of publication: ";
  cin.clear();
  getline(cin, record.date);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the title: ";
  cin.clear();
  getline(cin, record.title);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Journal's Title: ";
  cin.clear();
  getline(cin, record.journalTitle);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Journal's Volume: ";
  cin.clear();
  getline(cin, record.journalVolume);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the page numbers: ";
  cin.clear();
  getline(cin, record.pages);

   cout << "\33[H\33[2J"; // clears the screen
   cout << endl;
   cout << "1. Author: " << record.author << endl
        << "2. Year: " << record.date<< endl
        << "3. Title: " << record.title << endl
        << "4. Journal Title: "<< record.journalTitle << endl
        << "5. Journal Volume: " << record.journalVolume << endl
        << "6. Pages: " << record.pages << endl
        << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

   cout << "Enter the doi or URL: ";
   cin.clear();
   getline(cin, record.doiUrl);
  cout << "Correct? ";
  cin >> c;

  if (c == 'y'){
    list.insertNode(11,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
  }
  else
  {
    while(!done){
    cout << "\33[H\33[2J"; // clears the screen
    cout << endl;
    cout << "1. Author: " << record.author << endl
         << "2. Year: " << record.date<< endl
         << "3. Title: " << record.title << endl
         << "4. Journal Title: "<< record.journalTitle << endl
         << "5. Journal Volume: " << record.journalVolume << endl
         << "6. Pages: " << record.pages << endl
         << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

    cout << "Which field would you like to edit? ";
    cin.clear();
    cin >> choice;

    while (choice < 1 || choice > 7){
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Journal Title: "<< record.journalTitle << endl
           << "5. Journal Volume: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

      cout << choice << " is not a vaild option.\n";
      cout << "Which field would you like to edit? ";
          cin.clear();
      cin >> choice;
    }
    switch(choice){
      case 1:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Journal Title: "<< record.journalTitle << endl
             << "5. Journal Volume: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

        cout << "Enter the author: ";
        cin.ignore();
        getline(cin, record.author);
        break;
      case 2:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Journal Title: "<< record.journalTitle << endl
             << "5. Journal Volume: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

        cout << "Enter the year of publication: ";
        cin.ignore();
        getline(cin, record.date);
        break;
      case 3:
        cout << "\33[H\33[2J"; // clears the screen
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Journal Title: "<< record.journalTitle << endl
             << "5. Journal Volume: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

             cout << "Enter the title: ";
             cin.ignore();
             getline(cin, record.title);
        break;
      case 4:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Journal Title: "<< record.journalTitle << endl
           << "5. Journal Volume: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

               cout << "Enter the Journal's Title: ";
               cin.ignore();
               getline(cin, record.journalTitle);
               break;
      case 5:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Journal Title: "<< record.journalTitle << endl
             << "5. Journal Volume: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

                 cout << "Enter the journal's Volume: ";
                 cin.ignore();
                 getline(cin, record.journalVolume);
                 break;
      case 6:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Journal Title: "<< record.journalTitle << endl
           << "5. Journal Volume: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

               cout << "Enter the pages: ";
               cin.ignore();
               getline(cin, record.pages);
               break;
     case 7:
     cout << "\33[H\33[2J"; // clears the screen
     cout << endl;
     cout << "1. Author: " << record.author << endl
          << "2. Year: " << record.date<< endl
          << "3. Title: " << record.title << endl
          << "4. Journal Title: "<< record.journalTitle << endl
          << "5. Journal Volume: " << record.journalVolume << endl
          << "6. Pages: " << record.pages << endl
          << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

              cout << "Enter the doi or URL: ";
              cin.ignore();
              getline(cin, record.doiUrl);
              break;
      case 8:
        list.insertNode(11,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
        return;
        break;
    }
  }

  }
}
void apaMagazine(Citation list){
  apaRecord record;
  int choice;
  char c;
  bool done = false;
  int type;
  cin.clear();
  cin.ignore();
  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the author: ";
  cin.clear();
  getline(cin, record.author);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Year and month of publication(year,month): ";
  cin.clear();
  getline(cin, record.date);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the title: ";
  cin.clear();
  getline(cin, record.title);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Magazine's Title: ";
  cin.clear();
  getline(cin, record.journalTitle);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Magazine's Issue number: ";
  cin.clear();
  getline(cin, record.journalVolume);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the page numbers: ";
  cin.clear();
  getline(cin, record.pages);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the doi or URL: ";
  cin.clear();
  getline(cin, record.doiUrl);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Correct? ";
  cin >> c;

  if (c == 'y'){
        list.insertNode(12,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
  }
  else
  {
    while(!done){
    cout << "\33[H\33[2J"; // clears the screen
    cout << endl;
    cout << "1. Author: " << record.author << endl
         << "2. Year, Month of publication: " << record.date<< endl
         << "3. Title: " << record.title << endl
         << "4. Magazine Title: "<< record.journalTitle << endl
         << "5. Magazine issue: " << record.journalVolume << endl
         << "6. Pages: " << record.pages << endl
         << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

    cout << "Which field would you like to edit? ";
    cin.clear();
    cin >> choice;

    while (choice < 1 || choice > 8){
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year, Month of publication: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Magazine Title: "<< record.journalTitle << endl
           << "5. Magazine issue: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl<< endl
           << "8. Done" << endl << endl << endl;

      cout << choice << " is not a vaild option.\n";
      cout << "Which field would you like to edit? ";
          cin.clear();
      cin >> choice;
    }
    switch(choice){
      case 1:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year, Month of publication: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Magazine Title: "<< record.journalTitle << endl
             << "5. Magazine issue: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

        cout << "Enter the author: ";
        cin.ignore();
        getline(cin, record.author);
        break;
      case 2:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year, Month of publication: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Magazine Title: "<< record.journalTitle << endl
             << "5. Magazine issue: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

        cout << "Enter the year of publication: ";
        cin.ignore();
        getline(cin, record.date);
        break;
      case 3:
        cout << "\33[H\33[2J"; // clears the screen
        cout << "1. Author: " << record.author << endl
             << "2. Year, Month of publication: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Magazine Title: "<< record.journalTitle << endl
             << "5. Magazine issue: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

             cout << "Enter the title: ";
             cin.ignore();
             getline(cin, record.title);
        break;
      case 4:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year, Month of publication: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Magazine Title: "<< record.journalTitle << endl
           << "5. Magazine issue: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl<< endl
           << "8. Done" << endl << endl << endl;

               cout << "Enter the Magazine's Title: ";
               cin.ignore();
               getline(cin, record.journalTitle);
               break;
      case 5:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year, Month of publication: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Magazine Title: "<< record.journalTitle << endl
             << "5. Magazine issue: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

                 cout << "Enter the Magazine's Issue number: ";
                 cin.ignore();
                 getline(cin, record.journalVolume);
                 break;
      case 6:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year, Month of publication: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Magazine Title: "<< record.journalTitle << endl
           << "5. Magazine issue: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl<< endl
           << "8. Done" << endl << endl << endl;

               cout << "Enter the pages: ";
               cin.ignore();
               getline(cin, record.pages);
               break;
     case 7:
     cout << "\33[H\33[2J"; // clears the screen
     cout << endl;
     cout << "1. Author: " << record.author << endl
          << "2. Year, Month of publication: " << record.date<< endl
          << "3. Title: " << record.title << endl
          << "4. Magazine Title: "<< record.journalTitle << endl
          << "5. Magazine issue: " << record.journalVolume << endl
          << "6. Pages: " << record.pages << endl
          << "7. Doi or URL: " << record.doiUrl<< endl
          << "8. Done" << endl << endl << endl;

              cout << "Enter the doi or URL: ";
              cin.ignore();
              getline(cin, record.doiUrl);
              break;

      case 8:
          list.insertNode(12,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
        return;
        break;
    }
  }

  }
}
void apaBook(Citation list){
  apaRecord record;
  int choice;
  char c;
  bool done = false;
  int type;
  cin.clear();
  cin.ignore();
  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher City: " << record.pubCity << endl
       << "4. Publisher State: "<< record.PubState << endl
       << "5. Publisher: " << record.publisher << endl
       << "6. Title: " << record.title << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the author: ";
  cin.clear();
  getline(cin, record.author);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher City: " << record.pubCity << endl
       << "4. Publisher State: "<< record.PubState << endl
       << "5. Publisher: " << record.publisher << endl
       << "6. Title: " << record.title << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the year of publication: ";
  cin.clear();
  getline(cin, record.date);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher City: " << record.pubCity << endl
       << "4. Publisher State: "<< record.PubState << endl
       << "5. Publisher: " << record.publisher << endl
       << "6. Title: " << record.title << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the title: ";
  cin.clear();
  getline(cin, record.title);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher City: " << record.pubCity << endl
       << "4. Publisher State: "<< record.PubState << endl
       << "5. Publisher: " << record.publisher << endl
       << "6. Title: " << record.title << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Publisher's City: ";
  cin.clear();
  getline(cin, record.pubCity);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher City: " << record.pubCity << endl
       << "4. Publisher State: "<< record.PubState << endl
       << "5. Publisher: " << record.publisher << endl
       << "6. Title: " << record.title << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the publisher's state: ";
  cin.clear();
  getline(cin, record.PubState);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher City: " << record.pubCity << endl
       << "4. Publisher State: "<< record.PubState << endl
       << "5. Publisher: " << record.publisher << endl
       << "6. Title: " << record.title << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Publisher's Name: ";
  cin.clear();
  getline(cin, record.publisher);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher City: " << record.pubCity << endl
       << "4. Publisher State: "<< record.PubState << endl
       << "5. Publisher: " << record.publisher << endl
       << "6. Title: " << record.title << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Correct? ";
  cin >> c;

  if (c == 'y'){
      list.insertNode(13,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
  }
  else
  {
    while(!done){
    cout << "\33[H\33[2J"; // clears the screen
    cout << endl;
    cout << "1. Author: " << record.author << endl
         << "2. Year: " << record.date<< endl
         << "3. Publisher City: " << record.pubCity << endl
         << "4. Publisher State: "<< record.PubState << endl
         << "5. Publisher: " << record.publisher << endl
         << "6. Title: " << record.title << endl
         << "7. Doi or URL: " << record.doiUrl<< endl
         << "8. Done" << endl << endl << endl;

    cout << "Which field would you like to edit? ";
    cin.clear();
    cin >> choice;

    while (choice < 1 || choice > 7){
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Publisher City: " << record.pubCity << endl
           << "4. Publisher State: "<< record.PubState << endl
           << "5. Publisher: " << record.publisher << endl
           << "6. Title: " << record.title << endl
           << "7. Doi or URL: " << record.doiUrl<< endl
           << "8. Done" << endl << endl << endl;

      cout << choice << " is not a vaild option.\n";
      cout << "Which field would you like to edit? ";
          cin.clear();
      cin >> choice;
    }
    switch(choice){
      case 1:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Publisher City: " << record.pubCity << endl
             << "4. Publisher State: "<< record.PubState << endl
             << "5. Publisher: " << record.publisher << endl
             << "6. Title: " << record.title << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

        cout << "Enter the author: ";
        cin.ignore();
        getline(cin, record.author);
        break;
      case 2:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Publisher City: " << record.pubCity << endl
             << "4. Publisher State: "<< record.PubState << endl
             << "5. Publisher: " << record.publisher << endl
             << "6. Title: " << record.title << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

        cout << "Enter the year of publication: ";
        cin.ignore();
        getline(cin, record.date);
        break;
      case 3:
        cout << "\33[H\33[2J"; // clears the screen
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Publisher City: " << record.pubCity << endl
             << "4. Publisher State: "<< record.PubState << endl
             << "5. Publisher: " << record.publisher << endl
             << "6. Title: " << record.title << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

             cout << "Enter the Publisher's City: ";
             cin.ignore();
             getline(cin, record.pubCity);
        break;
      case 4:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Publisher City: " << record.pubCity << endl
           << "4. Publisher State: "<< record.PubState << endl
           << "5. Publisher: " << record.publisher << endl
           << "6. Title: " << record.title << endl
           << "7. Doi or URL: " << record.doiUrl<< endl
           << "8. Done" << endl << endl << endl;

               cout << "Enter the publisher's state: ";
               cin.ignore();
               getline(cin, record.PubState);
               break;
      case 5:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Publisher City: " << record.pubCity << endl
             << "4. Publisher State: "<< record.PubState << endl
             << "5. Publisher: " << record.publisher << endl
             << "6. Title: " << record.title << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

                 cout << "Enter the publisher's Name: ";
                 cin.ignore();
                 getline(cin, record.publisher);
                 break;
      case 6:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Publisher City: " << record.pubCity << endl
           << "4. Publisher State: "<< record.PubState << endl
           << "5. Publisher: " << record.publisher << endl
           << "6. Title: " << record.title << endl
           << "7. Doi or URL: " << record.doiUrl<< endl
           << "8. Done" << endl << endl << endl;

               cout << "Enter the Title: ";
               cin.ignore();
               getline(cin, record.title);
               break;
     case 7:
     cout << "\33[H\33[2J"; // clears the screen
     cout << endl;
     cout << "1. Author: " << record.author << endl
          << "2. Year: " << record.date<< endl
          << "3. Publisher City: " << record.pubCity << endl
          << "4. Publisher State: "<< record.PubState << endl
          << "5. Publisher: " << record.publisher << endl
          << "6. Title: " << record.title << endl
          << "7. Doi or URL: " << record.doiUrl<< endl
          << "8. Done" << endl << endl << endl;

              cout << "Enter the Title: ";
              cin.ignore();
              getline(cin, record.title);
              break;
      case 8:
          list.insertNode(13,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
        return;
        break;
    }
  }

  }
}
void apaNewspaper(Citation list){
  apaRecord record;
  int choice;
  char c;
  bool done = false;
  int type;
  cin.clear();
  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the author: ";
  getline(cin, record.author);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Date: ";
  getline(cin, record.date);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the pages: ";
  getline(cin, record.pages);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the title: ";
  getline(cin, record.title);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Newspaper Title: ";
  getline(cin, record.publisher);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the URL: ";
  getline(cin, record.doiUrl);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Correct? ";
  cin >> choice;

  if (choice == 'y'){
      list.insertNode(14,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
  }
  else
  {
    while(!done){
    cout << "\33[H\33[2J"; // clears the screen
    cout << endl;
    cout << "1. Author: " << record.author << endl
         << "2. Date: " << record.date<< endl
         << "3. Title: " << record.title << endl
         << "4. Newspaper Title: " << record.publisher << endl
         << "5. Pages: " << record.pages << endl
         << "6. URL: " << record.doiUrl << endl
         << "7. Done"<< endl << endl;


    cout << "Which field would you like to edit? ";
    cin.clear();
    cin >> choice;

    while (choice < 1 || choice > 7){
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Date: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Newspaper Title: " << record.publisher << endl
           << "5. Pages: " << record.pages << endl
           << "6. URL: " << record.doiUrl << endl
           << "7. Done"<< endl << endl;

      cout << choice << " is not a vaild option.\n";
      cout << "Which field would you like to edit? ";
          cin.clear();
      cin >> choice;
    }
    switch(choice){
      case 1:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Date: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Newspaper Title: " << record.publisher << endl
             << "5. Pages: " << record.pages << endl
             << "6. URL: " << record.doiUrl << endl
             << "7. Done"<< endl << endl;

        cout << "Enter the author: ";
        cin.ignore();
        getline(cin, record.author);
        break;
      case 2:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Date: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Newspaper Title: " << record.publisher << endl
             << "5. Pages: " << record.pages << endl
             << "6. URL: " << record.doiUrl << endl
             << "7. Done"<< endl << endl;

        cout << "Enter the year of publication: ";
        cin.ignore();
        getline(cin, record.date);
        break;
      case 3:
        cout << "\33[H\33[2J"; // clears the screen
        cout << "1. Author: " << record.author << endl
             << "2. Date: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Newspaper Title: " << record.publisher << endl
             << "5. Pages: " << record.pages << endl
             << "6. URL: " << record.doiUrl << endl
             << "7. Done"<< endl << endl;

             cout << "Enter the title: ";
             cin.ignore();
             getline(cin, record.title);
        break;
      case 4:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Date: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Newspaper Title: " << record.publisher << endl
           << "5. Pages: " << record.pages << endl
           << "6. URL: " << record.doiUrl << endl
           << "7. Done"<< endl << endl;

               cout << "Enter the Newspaper's Title: ";
               cin.ignore();
               getline(cin, record.journalTitle);
               break;
      case 5:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Date: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Newspaper Title: " << record.publisher << endl
             << "5. Pages: " << record.pages << endl
             << "6. URL: " << record.doiUrl << endl
             << "7. Done"<< endl << endl;

                 cout << "Enter the Newspaper's Issue Number: ";
                 cin.ignore();
                 getline(cin, record.journalVolume);
                 break;
      case 6:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Date: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Newspaper Title: " << record.publisher << endl
           << "5. Pages: " << record.pages << endl
           << "6. URL: " << record.doiUrl << endl
           << "7. Done"<< endl << endl;

               cout << "Enter the pages: ";
               cin.ignore();
               getline(cin, record.pages);
               break;
     case 7:
     cout << "\33[H\33[2J"; // clears the screen
     cout << endl;
     cout << "1. Author: " << record.author << endl
          << "2. Date: " << record.date<< endl
          << "3. Title: " << record.title << endl
          << "4. Newspaper Title: " << record.publisher << endl
          << "5. Pages: " << record.pages << endl
          << "6. URL: " << record.doiUrl << endl
          << "7. Done"<< endl << endl;

              cout << "Enter the URL: ";
              cin.ignore();
              getline(cin, record.doiUrl);
              break;
      case 8:
        list.insertNode(14,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
        return;
        break;
    }
  }

  }
}
void mla(){
  int choice;
  string c;
  bool done = false;
  int type;
  Citation list;

  while (!done){
    cout << "\33[H\33[2J"; // clears the screen
    cout << "1. Journal" << endl
         << "2. Magazine Article" << endl
         << "3. Newspaper" << endl
         << "4. Book" << endl << endl;
    cout << "What type of source are you citing? ";
    cin >> type;

    while (type < 1 || type > 5){
      cout << "\33[H\33[2J"; // clears the screen
      cout << "1. Journal" << endl
           << "2. Magazine Article" << endl
           << "3. Newspaper" << endl
           << "4. Book" << endl << endl;
      cout << type << " is an invaild option.\n";
      cout << "What type of source are you citing? ";
      cin >> type;
    }

    switch (type) {
      case 1:
        mlaJournal(list);
        break;
      case 2:
        mlaMagazine(list);
        break;
      case 3:
        mlaNewspaper(list);
        break;
      case 4:
        mlaBook(list);
        break;
    }

    cout << "Is that all the refrences?(y/N) ";
    getline(cin,c);

    if (tolower(c.front())== 'y')
      done = true;
  }
  cout << "\33[H\33[2J"; // clears the screen
  list.display();
}
void mlaJournal(Citation list){
  apaRecord record;
  int choice;
  char c;
  bool done = false;
  int type;
  cin.clear();
  cin.ignore();
  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the author: ";
  cin.clear();
  getline(cin, record.author);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the year of publication: ";
  cin.clear();
  getline(cin, record.date);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the title: ";
  cin.clear();
  getline(cin, record.title);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Journal's Title: ";
  cin.clear();
  getline(cin, record.journalTitle);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Journal's Volume: ";
  cin.clear();
  getline(cin, record.journalVolume);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Journal Title: "<< record.journalTitle << endl
       << "5. Journal Volume: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the page numbers: ";
  cin.clear();
  getline(cin, record.pages);

   cout << "\33[H\33[2J"; // clears the screen
   cout << endl;
   cout << "1. Author: " << record.author << endl
        << "2. Year: " << record.date<< endl
        << "3. Title: " << record.title << endl
        << "4. Journal Title: "<< record.journalTitle << endl
        << "5. Journal Volume: " << record.journalVolume << endl
        << "6. Pages: " << record.pages << endl
        << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

   cout << "Enter the doi or URL: ";
   cin.clear();
   getline(cin, record.doiUrl);
  cout << "Correct? ";
  cin >> c;

  if (c == 'y'){
    list.insertNode(21,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
  }
  else
  {
    while(!done){
    cout << "\33[H\33[2J"; // clears the screen
    cout << endl;
    cout << "1. Author: " << record.author << endl
         << "2. Year: " << record.date<< endl
         << "3. Title: " << record.title << endl
         << "4. Journal Title: "<< record.journalTitle << endl
         << "5. Journal Volume: " << record.journalVolume << endl
         << "6. Pages: " << record.pages << endl
         << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

    cout << "Which field would you like to edit? ";
    cin.clear();
    cin >> choice;

    while (choice < 1 || choice > 7){
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Journal Title: "<< record.journalTitle << endl
           << "5. Journal Volume: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

      cout << choice << " is not a vaild option.\n";
      cout << "Which field would you like to edit? ";
          cin.clear();
      cin >> choice;
    }
    switch(choice){
      case 1:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Journal Title: "<< record.journalTitle << endl
             << "5. Journal Volume: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

        cout << "Enter the author: ";
        cin.ignore();
        getline(cin, record.author);
        break;
      case 2:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Journal Title: "<< record.journalTitle << endl
             << "5. Journal Volume: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

        cout << "Enter the year of publication: ";
        cin.ignore();
        getline(cin, record.date);
        break;
      case 3:
        cout << "\33[H\33[2J"; // clears the screen
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Journal Title: "<< record.journalTitle << endl
             << "5. Journal Volume: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

             cout << "Enter the title: ";
             cin.ignore();
             getline(cin, record.title);
        break;
      case 4:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Journal Title: "<< record.journalTitle << endl
           << "5. Journal Volume: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

               cout << "Enter the Journal's Title: ";
               cin.ignore();
               getline(cin, record.journalTitle);
               break;
      case 5:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Journal Title: "<< record.journalTitle << endl
             << "5. Journal Volume: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

                 cout << "Enter the journal's Volume: ";
                 cin.ignore();
                 getline(cin, record.journalVolume);
                 break;
      case 6:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Journal Title: "<< record.journalTitle << endl
           << "5. Journal Volume: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

               cout << "Enter the pages: ";
               cin.ignore();
               getline(cin, record.pages);
               break;
     case 7:
     cout << "\33[H\33[2J"; // clears the screen
     cout << endl;
     cout << "1. Author: " << record.author << endl
          << "2. Year: " << record.date<< endl
          << "3. Title: " << record.title << endl
          << "4. Journal Title: "<< record.journalTitle << endl
          << "5. Journal Volume: " << record.journalVolume << endl
          << "6. Pages: " << record.pages << endl
          << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

              cout << "Enter the doi or URL: ";
              cin.ignore();
              getline(cin, record.doiUrl);
              break;
      case 8:
        list.insertNode(21,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
        return;
        break;
    }
  }

  }
}
void mlaMagazine(Citation list){
  apaRecord record;
  int choice;
  char c;
  bool done = false;
  int type;
  cin.clear();
  cin.ignore();
  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the author: ";
  cin.clear();
  getline(cin, record.author);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Year and month of publication(year,month): ";
  cin.clear();
  getline(cin, record.date);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the title: ";
  cin.clear();
  getline(cin, record.title);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Magazine's Title: ";
  cin.clear();
  getline(cin, record.journalTitle);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Magazine's Issue number: ";
  cin.clear();
  getline(cin, record.journalVolume);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the page numbers: ";
  cin.clear();
  getline(cin, record.pages);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the doi or URL: ";
  cin.clear();
  getline(cin, record.doiUrl);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year, Month of publication: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Magazine Title: "<< record.journalTitle << endl
       << "5. Magazine issue: " << record.journalVolume << endl
       << "6. Pages: " << record.pages << endl
       << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

  cout << "Correct? ";
  cin >> c;

  if (c == 'y'){
        list.insertNode(22,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
  }
  else
  {
    while(!done){
    cout << "\33[H\33[2J"; // clears the screen
    cout << endl;
    cout << "1. Author: " << record.author << endl
         << "2. Year, Month of publication: " << record.date<< endl
         << "3. Title: " << record.title << endl
         << "4. Magazine Title: "<< record.journalTitle << endl
         << "5. Magazine issue: " << record.journalVolume << endl
         << "6. Pages: " << record.pages << endl
         << "7. Doi or URL: " << record.doiUrl << endl << endl << endl;

    cout << "Which field would you like to edit? ";
    cin.clear();
    cin >> choice;

    while (choice < 1 || choice > 8){
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year, Month of publication: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Magazine Title: "<< record.journalTitle << endl
           << "5. Magazine issue: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl<< endl
           << "8. Done" << endl << endl << endl;

      cout << choice << " is not a vaild option.\n";
      cout << "Which field would you like to edit? ";
          cin.clear();
      cin >> choice;
    }
    switch(choice){
      case 1:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year, Month of publication: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Magazine Title: "<< record.journalTitle << endl
             << "5. Magazine issue: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

        cout << "Enter the author: ";
        cin.ignore();
        getline(cin, record.author);
        break;
      case 2:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year, Month of publication: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Magazine Title: "<< record.journalTitle << endl
             << "5. Magazine issue: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

        cout << "Enter the year of publication: ";
        cin.ignore();
        getline(cin, record.date);
        break;
      case 3:
        cout << "\33[H\33[2J"; // clears the screen
        cout << "1. Author: " << record.author << endl
             << "2. Year, Month of publication: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Magazine Title: "<< record.journalTitle << endl
             << "5. Magazine issue: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

             cout << "Enter the title: ";
             cin.ignore();
             getline(cin, record.title);
        break;
      case 4:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year, Month of publication: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Magazine Title: "<< record.journalTitle << endl
           << "5. Magazine issue: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl<< endl
           << "8. Done" << endl << endl << endl;

               cout << "Enter the Magazine's Title: ";
               cin.ignore();
               getline(cin, record.journalTitle);
               break;
      case 5:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year, Month of publication: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Magazine Title: "<< record.journalTitle << endl
             << "5. Magazine issue: " << record.journalVolume << endl
             << "6. Pages: " << record.pages << endl
             << "7. Doi or URL: " << record.doiUrl<< endl
             << "8. Done" << endl << endl << endl;

                 cout << "Enter the Magazine's Issue number: ";
                 cin.ignore();
                 getline(cin, record.journalVolume);
                 break;
      case 6:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year, Month of publication: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Magazine Title: "<< record.journalTitle << endl
           << "5. Magazine issue: " << record.journalVolume << endl
           << "6. Pages: " << record.pages << endl
           << "7. Doi or URL: " << record.doiUrl<< endl
           << "8. Done" << endl << endl << endl;

               cout << "Enter the pages: ";
               cin.ignore();
               getline(cin, record.pages);
               break;
     case 7:
     cout << "\33[H\33[2J"; // clears the screen
     cout << endl;
     cout << "1. Author: " << record.author << endl
          << "2. Year, Month of publication: " << record.date<< endl
          << "3. Title: " << record.title << endl
          << "4. Magazine Title: "<< record.journalTitle << endl
          << "5. Magazine issue: " << record.journalVolume << endl
          << "6. Pages: " << record.pages << endl
          << "7. Doi or URL: " << record.doiUrl<< endl
          << "8. Done" << endl << endl << endl;

              cout << "Enter the doi or URL: ";
              cin.ignore();
              getline(cin, record.doiUrl);
              break;

      case 8:
          list.insertNode(22,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
        return;
        break;
    }
  }

  }
}
void mlaBook(Citation list){
  apaRecord record;
  int choice;
  char c;
  bool done = false;
  int type;
  cin.clear();
  cin.ignore();
  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher: " << record.publisher << endl
       << "4. Title: " << record.title << endl << endl << endl;

  cout << "Enter the author: ";
  cin.clear();
  getline(cin, record.author);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher: " << record.publisher << endl
       << "4. Title: " << record.title << endl << endl << endl;

  cout << "Enter the year of publication: ";
  cin.clear();
  getline(cin, record.date);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher: " << record.publisher << endl
       << "4. Title: " << record.title << endl << endl << endl;

  cout << "Enter the title: ";
  cin.clear();
  getline(cin, record.title);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher: " << record.publisher << endl
       << "4. Title: " << record.title << endl << endl << endl;

  cout << "Enter the Publisher's Name: ";
  cin.clear();
  getline(cin, record.publisher);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Year: " << record.date<< endl
       << "3. Publisher: " << record.publisher << endl
       << "4. Title: " << record.title << endl << endl << endl;

  cout << "Correct? ";
  cin >> c;

  if (c == 'y'){
      list.insertNode(23,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
  }
  else
  {
    while(!done){
    cout << "\33[H\33[2J"; // clears the screen
    cout << endl;
    cout << "1. Author: " << record.author << endl
         << "2. Year: " << record.date<< endl
         << "3. Publisher: " << record.publisher << endl
         << "4. Title: " << record.title << endl
         << "5. Done" << endl << endl << endl;

    cout << "Which field would you like to edit? ";
    cin.clear();
    cin >> choice;

    while (choice < 1 || choice > 5){
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Publisher: " << record.publisher << endl
           << "4. Title: " << record.title << endl
           << "5. Done" << endl << endl << endl;

      cout << choice << " is not a vaild option.\n";
      cout << "Which field would you like to edit? ";
          cin.clear();
      cin >> choice;
    }
    switch(choice){
      case 1:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Publisher: " << record.publisher << endl
             << "4. Title: " << record.title << endl
             << "5. Done" << endl << endl << endl;

        cout << "Enter the author: ";
        cin.ignore();
        getline(cin, record.author);
        break;
      case 2:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Publisher: " << record.publisher << endl
             << "4. Title: " << record.title << endl
             << "5. Done" << endl << endl << endl;

        cout << "Enter the year of publication: ";
        cin.ignore();
        getline(cin, record.date);
        break;

      case 3:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Year: " << record.date<< endl
             << "3. Publisher: " << record.publisher << endl
             << "4. Title: " << record.title << endl
             << "5. Done" << endl << endl << endl;

                 cout << "Enter the publisher's Name: ";
                 cin.ignore();
                 getline(cin, record.publisher);
                 break;
      case 4:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Year: " << record.date<< endl
           << "3. Publisher: " << record.publisher << endl
           << "4. Title: " << record.title << endl
           << "5. Done" << endl << endl << endl;

               cout << "Enter the Title: ";
               cin.ignore();
               getline(cin, record.title);
               break;
      case 5:
          list.insertNode(23,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
        return;
        break;
    }
  }

  }
}
void mlaNewspaper(Citation list){
  apaRecord record;
  int choice;
  char c;
  bool done = false;
  int type;
  cin.clear();
  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the author: ";
  getline(cin, record.author);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Date: ";
  getline(cin, record.date);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the pages: ";
  getline(cin, record.pages);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the title: ";
  getline(cin, record.title);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the Newspaper Title: ";
  getline(cin, record.publisher);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Enter the URL: ";
  getline(cin, record.doiUrl);

  cout << "\33[H\33[2J"; // clears the screen
  cout << endl;
  cout << "1. Author: " << record.author << endl
       << "2. Date: " << record.date<< endl
       << "3. Title: " << record.title << endl
       << "4. Newspaper Title: " << record.publisher << endl
       << "5. Pages: " << record.pages << endl
       << "6. URL: " << record.doiUrl << endl << endl << endl;

  cout << "Correct? ";
  cin >> choice;

  if (choice == 'y'){
      list.insertNode(14,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
  }
  else
  {
    while(!done){
    cout << "\33[H\33[2J"; // clears the screen
    cout << endl;
    cout << "1. Author: " << record.author << endl
         << "2. Date: " << record.date<< endl
         << "3. Title: " << record.title << endl
         << "4. Newspaper Title: " << record.publisher << endl
         << "5. Pages: " << record.pages << endl
         << "6. URL: " << record.doiUrl << endl
         << "7. Done"<< endl << endl;


    cout << "Which field would you like to edit? ";
    cin.clear();
    cin >> choice;

    while (choice < 1 || choice > 7){
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Date: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Newspaper Title: " << record.publisher << endl
           << "5. Pages: " << record.pages << endl
           << "6. URL: " << record.doiUrl << endl
           << "7. Done"<< endl << endl;

      cout << choice << " is not a vaild option.\n";
      cout << "Which field would you like to edit? ";
          cin.clear();
      cin >> choice;
    }
    switch(choice){
      case 1:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Date: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Newspaper Title: " << record.publisher << endl
             << "5. Pages: " << record.pages << endl
             << "6. URL: " << record.doiUrl << endl
             << "7. Done"<< endl << endl;

        cout << "Enter the author: ";
        cin.ignore();
        getline(cin, record.author);
        break;
      case 2:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Date: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Newspaper Title: " << record.publisher << endl
             << "5. Pages: " << record.pages << endl
             << "6. URL: " << record.doiUrl << endl
             << "7. Done"<< endl << endl;

        cout << "Enter the year of publication: ";
        cin.ignore();
        getline(cin, record.date);
        break;
      case 3:
        cout << "\33[H\33[2J"; // clears the screen
        cout << "1. Author: " << record.author << endl
             << "2. Date: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Newspaper Title: " << record.publisher << endl
             << "5. Pages: " << record.pages << endl
             << "6. URL: " << record.doiUrl << endl
             << "7. Done"<< endl << endl;

             cout << "Enter the title: ";
             cin.ignore();
             getline(cin, record.title);
        break;
      case 4:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Date: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Newspaper Title: " << record.publisher << endl
           << "5. Pages: " << record.pages << endl
           << "6. URL: " << record.doiUrl << endl
           << "7. Done"<< endl << endl;

               cout << "Enter the Newspaper's Title: ";
               cin.ignore();
               getline(cin, record.journalTitle);
               break;
      case 5:
        cout << "\33[H\33[2J"; // clears the screen
        cout << endl;
        cout << "1. Author: " << record.author << endl
             << "2. Date: " << record.date<< endl
             << "3. Title: " << record.title << endl
             << "4. Newspaper Title: " << record.publisher << endl
             << "5. Pages: " << record.pages << endl
             << "6. URL: " << record.doiUrl << endl
             << "7. Done"<< endl << endl;

                 cout << "Enter the Newspaper's Issue Number: ";
                 cin.ignore();
                 getline(cin, record.journalVolume);
                 break;
      case 6:
      cout << "\33[H\33[2J"; // clears the screen
      cout << endl;
      cout << "1. Author: " << record.author << endl
           << "2. Date: " << record.date<< endl
           << "3. Title: " << record.title << endl
           << "4. Newspaper Title: " << record.publisher << endl
           << "5. Pages: " << record.pages << endl
           << "6. URL: " << record.doiUrl << endl
           << "7. Done"<< endl << endl;

               cout << "Enter the pages: ";
               cin.ignore();
               getline(cin, record.pages);
               break;
     case 7:
     cout << "\33[H\33[2J"; // clears the screen
     cout << endl;
     cout << "1. Author: " << record.author << endl
          << "2. Date: " << record.date<< endl
          << "3. Title: " << record.title << endl
          << "4. Newspaper Title: " << record.publisher << endl
          << "5. Pages: " << record.pages << endl
          << "6. URL: " << record.doiUrl << endl
          << "7. Done"<< endl << endl;

              cout << "Enter the URL: ";
              cin.ignore();
              getline(cin, record.doiUrl);
              break;
      case 8:
        list.insertNode(14,record.date,record.pages,record.author,record.title,record.pubCity,record.PubState,record.publisher,record.journalTitle,record.journalVolume,record.doiUrl);
        return;
        break;
    }
  }

  }
}
