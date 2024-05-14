#include "data/dataSource/DataLoader.cpp"
#include "Models/Models.cpp"
#include "WriteQuiz.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Models;

class Homepage {

public:
	Homepage(UserAuthRequest *userauthrequest, bool *authMissionStatus) {
		UserProfileAPI^ userAPI = gcnew UserProfileAPI();
		DataLoader loader(&userAPI);
		if (userAPI->userAuthMission(*userauthrequest)) {
			*authMissionStatus = true;
		}
	}

	~Homepage() {

	}
};