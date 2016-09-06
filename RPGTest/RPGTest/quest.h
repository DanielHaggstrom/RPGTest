#ifndef QUEST_H
#define QUEST_H

#include <fstream>
#include <string>



class Quest
{
private:

	std::string id;
    std::string description;
    bool avaiable;
    bool completed;
	bool fisnished;

public:

    Quest();
    Quest(std::string id);
    ~Quest();

    void setAvaiable(bool avaiable){this->avaiable = avaiable;}
    void setCompleted(bool completed){this->completed = completed;}
    void setId(std::string id){this->id = id;}
    void setDescription(std::string description){this->description = description;}
    bool getAvaiable(){return avaiable;}
    bool getCompleted(){return completed;}
    std::string getId(){return id;}
    std::string getDescription(){return description;}

	void setFisnished(bool fisnished){ this->fisnished = fisnished; }
	bool getFisnished(){ return fisnished; }

    void printQuest();
	void readQuest();
	void save();
	void loadQuest();


};

#endif
