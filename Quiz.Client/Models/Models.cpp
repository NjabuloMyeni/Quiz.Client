#include <string>
#include <vector>
#pragma once

using namespace std;

namespace Models {

	struct QAModel
	{
		string QuestionLevel;
		string Question;
		string CodeQuestion;
		vector<string> Options;
	};

	struct  UserProfileModel
	{
		string UserType;
		string Name;
		string Surname;
		string Passward;
		string EmailAddress;
	};

	struct UserAuthRequest {
		
		string UserName;
		string Password;
	};
};