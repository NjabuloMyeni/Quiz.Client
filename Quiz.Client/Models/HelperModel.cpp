#include "Models.cpp";
#include <cliext/vector>
#include <msclr\marshal_cppstd.h>;

#pragma once
using namespace System;
using namespace Models;

namespace HelperModels {
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
        String^ getUserAnswer() {
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

    ref class QAModel
    {
    private:
        String^ QuestionLevel = gcnew String("");;
        String^ Question = gcnew String("");
        String^ CodeQuestion = gcnew String("");
        cliext::vector<String^> Options;

    public:
        /// <summary>
        ///Getting methods for Model properties////////////////////////////////////////////////////////
        /// </summary>
        String^ getQuestionLevel() {
            return QuestionLevel;
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

        /// <summary>
        ///Setting methods for Model properties////////////////////////////////////////////////////////
        /// </summary>
        void setQuestionLevel(string questionLevel) {
            this->QuestionLevel = msclr::interop::marshal_as<String^>(questionLevel);
        }
        void setQuestion(string question) {
            this->Question = msclr::interop::marshal_as<String^>(question);
        }
        void setCodeQuestion(string codequestion) {
            this->CodeQuestion = msclr::interop::marshal_as<String^>(codequestion);
        }
        void setOptions(vector<string> options) {
            for (int i = 0; i < options.size(); i++) {
                this->Options.push_back(msclr::interop::marshal_as<String^>(options.at(i)));
            }
        }
    };

    ref class UserProfileModel
    {
    private:
        String^ Name = gcnew String("");
        String^ Surname = gcnew String("");
        String^ Passward = gcnew String("");
        String^ EmailAddress = gcnew String("");

    public:
        /// <summary>
        ///Getting methods for Model properties////////////////////////////////////////////////////////
        /// </summary>
        String^ getName() {
            return Name;
        }
        String^ getSurname() {
            return Surname;
        }
        System::String^ getPassward() {
            return Passward;
        }
        String^ getEmailAddress() {
            return EmailAddress;
        }

        /// <summary>
        ///Setting methods for Model properties////////////////////////////////////////////////////////
        /// </summary>
        void setName(string Name) {
            this->Name = gcnew String(msclr::interop::marshal_as<String^>(Name));
        }
        void setSurname(string Surname) {
            this->Surname = msclr::interop::marshal_as<String^>(Surname);
        }
        void setPassward(string Passward) {
            this->Passward = msclr::interop::marshal_as<String^>(Passward);
        }
        void setEmailAddress(string EmailAddress) {
            this->EmailAddress = msclr::interop::marshal_as<String^>(EmailAddress);
        }
    };
};
