#include<vector>;
#include<random>;
#include "../../Models/helperModel.cpp"
#include "QAAPI.cpp"

using namespace std;
using namespace HelperModels;

ref class CompileSessionQuestions {
private:
	cliext::vector<QAModel^> sessionQuestions;

public:

	CompileSessionQuestions(QAAPI^ qaAPI) {
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

	void compileQuestions(cliext::vector<QAModel^> levelQuestions, string level) {
		int size = levelQuestions.size()-1;
		for (int i = 0; i <= 7; i++) {
			
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(0, size);
			int index = dis(gen);
			
			QAModel^ qaModel = levelQuestions.at(index);
			qaModel->setQuestionLevel(level);
			sessionQuestions.push_back(qaModel);
			levelQuestions.erase(levelQuestions.begin());
			size--;
		}
	}

	cliext::vector<QAModel^> getSessionQuestions() {
		return sessionQuestions;
	}
};