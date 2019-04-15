#ifndef CITATION_H
#define CITATION_H
#include<string>
class Citation{
private:


  struct ListNode{
    struct ListNode *next;
    int type;
    std::string date;
    std::string pages;
    std::string author;
    std::string title;
    std::string pubCity;
    std::string PubState;
    std::string publisher;
    std::string journalTitle;
    std::string journalVolume;
    std::string doiUrl;
  };

  ListNode *head;

public:
  Citation();
  ~Citation();
  void insertNode(int type,std::string date, std::string pg, std::string auth,
          std::string title, std::string pubCity, std::string PubState, std::string publisher,std::string journalTitle, std::string journalVolume, std::string doiUrl);
  void deleteNode(std::string);
  void display();
  void save();
  void load();
  void printToFile();
  void setType(std::string value);
  void setAuthor(std::string value);
  void setDate(std::string value);
  void setTitle(std::string value);
  void setPages(std::string value);
};

#endif
