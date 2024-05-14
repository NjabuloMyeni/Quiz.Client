#include <iostream>;
#include <vector>;
#include <fstream>;
#include <string>;
#include <cliext/vector>;
#include "QAAPI.cpp";
#include "DataSourceHelperFunctions.cpp";
#include "UserProfileAPI.cpp";
#include "../../Models/HelperModel.cpp"
#pragma once

using namespace std;
using namespace HelperFuctions;
using namespace HelperModels;

ref class DataLoader {

private:

    template<typename Model>
    cliext::vector<Model^> dataContentReader(string filename, string questionreq) {

        cliext::vector<Model^> contentLoad = gcnew cliext::vector<Model^>();
        string line;
        ifstream fileReader;

        fileReader.open(filename);

        if (!fileReader.is_open()) {
            cerr << "Error: Unable to open file" << filename << endl;
            return contentLoad;
        }

        char delim = '@';
        if (questionreq.empty()) {
            delim = '|';
        }

        while (getline(fileReader, line, delim)) {

            Model^ rowContent = gcnew Model();
            vector<string> disectedrow = Helpers::splitString(line, '~');
            Helpers::contentLoadLoader(rowContent, disectedrow);
            contentLoad.push_back(rowContent);
        }

        return contentLoad;
    }


    QAAPI^ populateQuestionBanks() {
        string path = "././data/dataFactory/";
        string fileName;
        QAAPI^ qaAPI = gcnew QAAPI();

        fileName = "QABankOne.txt";
        qaAPI->setQuestionBankOne(dataContentReader<QAModel>(path + fileName, "questionreq"));
        fileName = "QABankTwo.txt";
        qaAPI->setQuestionBankTwo(dataContentReader<QAModel>(path + fileName, "questionreq"));
        fileName = "QABankThree.txt";
        qaAPI->setQuestionBankThree(dataContentReader<QAModel>(path + fileName, "questionreq"));
        return qaAPI;
    }

    UserProfileAPI^ UserProfileReadIn() {

        string path = "././data/dataFactory/";
        string fileName = "UserProfiles.txt";
        UserProfileAPI^ userAPI = gcnew UserProfileAPI();

        userAPI->setUserProfileData(dataContentReader<UserProfileModel>(path + fileName,""));
        return userAPI;
    }
public:
    DataLoader(UserProfileAPI^ *APIPointer) {
        *APIPointer = UserProfileReadIn();
    }

    DataLoader(QAAPI^ *APIPointer) {
        *APIPointer = populateQuestionBanks();
    }

    ~DataLoader() {

    }

        
};


   