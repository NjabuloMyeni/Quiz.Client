#include "Models.cpp";
#include <cliext/vector>

using namespace System;
#pragma once

using namespace System;
using namespace Models;

ref class DisplaySessionQuestionModel {
private:
    String^ QuestionLevel;
    String^ Question;
    String^ CodeQuestion;
    cliext::vector<String^> Options;
    String^ UserAnswer;
    int correctAnswerIndex;


public:
    /// <summary>
    ///Getting methods for Model properties////////////////////////////////////////////////////////
    /// </summary>
    String^ getQuestionLevel() {
        return QuestionLevel;
    }
    String^getUserAnswer() {
        return UserAnswer;
    }
    String^ getQuestion() {
        return Question;
    }
    System::String^ getCodeQuestion() {
        return CodeQuestion;
    }
    cliext::vector<String^> getOptions() {
        return Options;
    }
    int getCorrectAnswerIndex() {
        return correctAnswerIndex;
    }


    /// <summary>
    ///Setting methods for Model properties////////////////////////////////////////////////////////
    /// </summary>
    void setQuestionLevel(String^ questionLevel) {
        this->QuestionLevel = questionLevel;
    }
    void setUserAnswer(String^ userAnswer) {
        this->UserAnswer = userAnswer;
    }
    void setQuestion(String^ question) {
        this->Question = question;
    }
    void setCodeQuestion(String^ codequestion) {
        this->CodeQuestion = codequestion;
    }
    void setOptions(cliext::vector<String^> options) {
        this->Options = options;
    }
    void setCorrectAnswerIndex(int index) {
        this->correctAnswerIndex = index;
    }
};