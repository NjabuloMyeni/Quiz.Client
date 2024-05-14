#include <cliext/vector>
#include <msclr\marshal_cppstd.h>;
#include "DataSourceHelperFunctions.cpp"
#include "../../Models/HelperModel.cpp"
#include "../../Models/Models.cpp"
#pragma once

using namespace HelperFuctions;
using namespace HelperModels;
using namespace Models;

ref class UserProfileAPI {
	
private: 
	cliext::vector<UserProfileModel^> userProfileData ;

public:
	void setUserProfileData(cliext::vector<UserProfileModel^> userProfileData) {
		for (int i = 0; i < userProfileData.size(); i++) {
			this->userProfileData.push_back(userProfileData.at(i));
		}
	}

	cliext::vector<UserProfileModel^> getUserProfileData() {
		return userProfileData;
	}

	bool userAuthMission(UserAuthRequest &userauthrequest) {
		for (int i = 0; i < userProfileData.size();i++ ) {
			OperatorOverload username(msclr::interop::marshal_as<string>(userProfileData.at(i)->getEmailAddress()));
			OperatorOverload password(msclr::interop::marshal_as<string>(userProfileData.at(i)->getPassward()));
			if ( username == userauthrequest.UserName && password == userauthrequest.Password) {
				return true;
			}
		}
		return false;
	}
};