#include "QuizInProgress.h"
#include "data/dataSource/QAAPI.cpp"
#include "data/dataSource/DataLoader.cpp"
#include "data/dataSource/CompileSessionQuestions.cpp"
#include "Models/Models.cpp"
#include <cliext/vector>
#include "Models/HelperModel.cpp"
#pragma once

using namespace QuizClient;
using namespace Models;
using namespace System;

class QuizInprogress {
private:

public:
    QuizInprogress(cliext::vector<DisplaySessionQuestionModel^>^ displaysessionquestions) {

        QAAPI qaAPI;
        DataLoader loader(&qaAPI);
        CompileSessionQuestions compilesessionquestions(&qaAPI);
        convertQAModelToSessionQuestionModel(&compilesessionquestions.getSessionQuestions(), displaysessionquestions);
    }

    void convertQAModelToSessionQuestionModel(vector<QAModel> *qasessionquestion, cliext::vector<DisplaySessionQuestionModel^>^ displaysessionquestions) {
        
        for (int i = 0; i < qasessionquestion->size(); i++) {

            DisplaySessionQuestionModel^ sessionquestionmodel = gcnew DisplaySessionQuestionModel();
            sessionquestionmodel->setQuestion(msclr::interop::marshal_as<String^>(qasessionquestion->at(i).Question));
            sessionquestionmodel->setCodeQuestion(msclr::interop::marshal_as<String^>(qasessionquestion->at(i).CodeQuestion));
            sessionquestionmodel->setQuestionLevel(msclr::interop::marshal_as<String^>(qasessionquestion->at(i).QuestionLevel));

            cliext::vector<String^> Options;
            for (int j = 0; j < qasessionquestion->at(i).Options.size(); j++) {
                Options.push_back(msclr::interop::marshal_as<String^>(qasessionquestion->at(i).Options.at(j)));
            }
            sessionquestionmodel->setUserAnswer("");
            sessionquestionmodel->setOptions(Options);
            displaysessionquestions->push_back(sessionquestionmodel);
        }
    }
};
