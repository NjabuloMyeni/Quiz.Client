#include <vector>;
#include "../../Models/Models.cpp";
#include "DataSourceHelperFunctions.cpp"
using namespace HelperFuctions;
#pragma once

using namespace Models;

class UserProfileAPI {
	
private: 
	vector<UserProfileModel> userProfileData;

public:
	void setUserProfileData(vector<UserProfileModel> userProfileData) {
		if (this->userProfileData.size() == 0) {
			this->userProfileData = userProfileData;
		}
	}

	vector<UserProfileModel> getUserProfileData() {
		return userProfileData;
	}

	bool userAuthMission(UserAuthRequest &userauthrequest) {
		for (int i = 0; i < userProfileData.size();i++ ) {
			OperatorOverload username(userProfileData[i].EmailAddress);
			OperatorOverload password(userProfileData[i].Passward);
			if ( username == userauthrequest.UserName && password == userauthrequest.Password) {
				return true;
			}
		}
		return false;
	}
};