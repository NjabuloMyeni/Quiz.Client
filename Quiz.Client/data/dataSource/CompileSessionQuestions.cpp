#include<vector>;
#include<random>;
#include "../../Models/Models.cpp"
#include "QAAPI.cpp"
#include <list>

using namespace std;
using namespace Models;

class CompileSessionQuestions {
private:
	vector<QAModel> sessionQuestions;

public:

	CompileSessionQuestions(QAAPI* qaAPI) {
		int levelNum= 1;
		string level = "level "+ to_string(levelNum);
		for (int i = 0; i < 3; i++) {
			if (levelNum == 1) {
				compileQuestions(qaAPI->getQuestionBankOne(), level);
				levelNum++;
				level = "level " + to_string(levelNum);
			}
			else if (levelNum == 2) {
				compileQuestions(qaAPI->getQuestionBankTwo(), level);
				levelNum++;
				level = "level " + to_string(levelNum);
			}
			else { 
				compileQuestions(qaAPI->getQuestionBankThree(), level); 
			}
		}
	}
	~CompileSessionQuestions() {

	}

	void compileQuestions(vector<QAModel>& levelQuestions, string level) {
		
		for (int i = 0; i <= 7; i++) {

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(0, levelQuestions.size());
			int index = dis(gen);
			QAModel qaModel = levelQuestions[index];
			qaModel.QuestionLevel = level;
			sessionQuestions.push_back(qaModel);
			levelQuestions.pop_back();
		}
	}

	vector<QAModel> getSessionQuestions() {
		return sessionQuestions;
	}
};