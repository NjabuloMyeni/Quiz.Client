#include <string>;
#include <vector>;
#include <cliext/vector>;
#include <iostream>;
#include "..\..\Models\HelperModel.cpp";
#pragma once

using namespace std;
using namespace HelperModels;

ref class QAAPI
{

private:
    //Dynamic Question Bank, to allow all question in the backstorage to be loaded into the respective question bank levels
    cliext::vector<QAModel^> questionBankOne;
    cliext::vector<QAModel^> questionBankTwo;
    cliext::vector<QAModel^> questionBankThree;

public:
    // Setter method for loading the question vector
    void setQuestionBankOne(cliext::vector<QAModel^> questionBankOne) {
        for (int i = 0; i < questionBankOne.size(); i++ ) {
            this->questionBankOne.push_back(questionBankOne.at(i));
        }
    }
    void setQuestionBankTwo(cliext::vector<QAModel^> questionBankTwo) {
        for (int i = 0; i < questionBankOne.size(); i++) {
            this->questionBankTwo.push_back(questionBankTwo.at(i));
        }
    }
    void setQuestionBankThree(cliext::vector<QAModel^> questionBankThree) {
        for (int i = 0; i < questionBankOne.size(); i++) {
            this->questionBankThree.push_back(questionBankThree.at(i));
        }
    }

    // Getter method for accessing the questions vector
    cliext::vector<QAModel^> getQuestionBankOne() {
        return questionBankOne;
    }
    cliext::vector<QAModel^> getQuestionBankTwo() {
        return questionBankTwo;
    }
    cliext::vector<QAModel^> getQuestionBankThree() {
        return questionBankThree;
    }

    //class Constructor
    QAAPI() {

    };
    //class distructor
    ~QAAPI() {
    };

};