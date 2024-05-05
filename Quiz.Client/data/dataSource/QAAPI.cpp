#include <string>;
#include <vector>;
#include <iostream>;
#include "..\..\Models\Models.cpp";
#pragma once

using namespace std;
using namespace Models;

class QAAPI
{

private:
    //Dynamic Question Bank, to allow all question in the backstorage to be loaded into the respective question bank levels
    vector<QAModel> questionBankOne;
	vector<QAModel> questionBankTwo;
	vector<QAModel> questionBankThree;

public:
    // Setter method for loading the question vector
    void setQuestionBankOne(vector<QAModel> questionBankOne) {
        if (this->questionBankOne.size()==0) {
            this->questionBankOne = questionBankOne;
        }
    }
    void setQuestionBankTwo(vector<QAModel> questionBankTwo) {
        if (this->questionBankTwo.size() == 0) {
            this->questionBankTwo = questionBankTwo;
        }
    }
    void setQuestionBankThree(vector<QAModel> questionBankThree) {
        if (this->questionBankThree.size() == 0) {
            this->questionBankThree = questionBankThree;
        }
    }

    // Getter method for accessing the questions vector
    vector<QAModel> getQuestionBankOne() {
        return questionBankOne;
    }
    vector<QAModel> getQuestionBankTwo() {
        return questionBankTwo;
    }
    vector<QAModel> getQuestionBankThree() {
        return questionBankThree;
    }
    //class Constructor
    QAAPI() {

    };
    //class distructor
    ~QAAPI() {
    };

};