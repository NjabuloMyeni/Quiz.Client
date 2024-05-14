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
using namespace HelperModels;

ref class QuizInprogress {
private:

public:
    QuizInprogress(cliext::vector<DisplaySessionQuestionModel^>^ displaysessionquestions) {

        QAAPI^ qaAPI;
        DataLoader loader(&qaAPI);
        CompileSessionQuestions compilesessionquestions(qaAPI);
        convertQAModelToSessionQuestionModel(compilesessionquestions.getSessionQuestions(), displaysessionquestions);
    }

    void convertQAModelToSessionQuestionModel(cliext::vector<QAModel^> qasessionquestion, cliext::vector<DisplaySessionQuestionModel^>^ displaysessionquestions) {
        
        for (int i = 0; i < qasessionquestion.size(); i++) {
            if (qasessionquestion.at(i) != nullptr) {

                DisplaySessionQuestionModel^ sessionquestionmodel = gcnew DisplaySessionQuestionModel();
                sessionquestionmodel->setQuestion(qasessionquestion.at(i)->getQuestion());
                sessionquestionmodel->setCodeQuestion(qasessionquestion.at(i)->getCodeQuestion());
                sessionquestionmodel->setQuestionLevel(qasessionquestion.at(i)->getQuestionLevel());

                cliext::vector<String^> Options;
                for (int j = 0; j < qasessionquestion.at(i)->getOptions().size(); j++) {
                    Options.push_back(qasessionquestion.at(i)->getOptions().at(j));
                }

                sessionquestionmodel->setUserAnswer("");
                sessionquestionmodel->setOptions(Options);
                displaysessionquestions->push_back(sessionquestionmodel);
            }
        }
    }
};
