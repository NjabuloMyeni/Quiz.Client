#include<vector>;
#include<random>;
#include "../../Models/Models.cpp"
#include "QAAPI.cpp"

using namespace std;
using namespace Models;

class CompileSessionQuestions {
private:
	vector<QAModel>sessionQuestions;

public:

	CompileSessionQuestions(QAAPI& qaAPI) {
		compileQuestions(qaAPI.getQuestionBankOne());
		compileQuestions(qaAPI.getQuestionBankTwo());
		compileQuestions(qaAPI.getQuestionBankThree());

	}
	~CompileSessionQuestions() {

	}

	void compileQuestions(const vector<QAModel>& levelQuestions) {
		for (int i = 0; i <= 4; i++) {
			int index = rand() % levelQuestions.size();
			sessionQuestions.push_back(levelQuestions[index]);
		}
	}

	vector<QAModel> getSessionQuestions() {
		return sessionQuestions;
	}
};