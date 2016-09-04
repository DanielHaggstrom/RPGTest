#ifndef QUEST_H
#define QUEST_H

#include <fstream>
#include <string>



class Quest
{
private:

	std::string id;
    std::string description;
    bool avaiable = false;
    bool completed = false;

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
    void printQuest();
	void readQuest();
	void save();



};

#endif
