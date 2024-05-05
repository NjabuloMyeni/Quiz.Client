#include "QuizInProgress.h"
#include "data/dataSource/QAAPI.cpp"
#include "data/dataSource/DataLoader.cpp"
#include "data/dataSource/CompileSessionQuestions.cpp"
using namespace QuizClient;

class QuizInprogress {

public:
	QuizInprogress(vector<SessionQuestionsModel> *sessionquestions) {
		QAAPI qaAPI;
		DataLoader loader(&qaAPI);
		CompileSessionQuestions compilesessionquestions(qaAPI);
		*sessionquestions = getContextSessionQuestions(compilesessionquestions.getSessionQuestions());
	}

	vector<SessionQuestionsModel> getContextSessionQuestions(vector<QAModel> &sessionquestion) {
		vector<SessionQuestionsModel> contextSessionQuestions;
		for (int i = 0; i < sessionquestion.size(); i++) 
		{
			SessionQuestionsModel sessionquestionmodel;
			sessionquestionmodel.questionModel = sessionquestion[i];
			contextSessionQuestions.push_back(sessionquestionmodel);
		}
		return contextSessionQuestions;
	}

};