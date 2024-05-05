#include <string>
#include <vector>
#include "../../Models/Models.cpp"
#pragma once
using namespace Models;
using namespace std;

namespace HelperFuctions {
	class Helpers 
	{
	public:	
		static vector<string> splitString(string &line, const char &delimeter) {
			vector<string>splitedString;
			string temp;
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == delimeter || line.length() - i == 1) {
					splitedString.push_back(temp);
					temp = "";
				}
				else {
					temp += line[i];
				}
			}
			return splitedString;
		}

		static void contentLoadLoader(QAModel &rowContent, vector<string> disectedrow) {
			//rowContent.QuestionLevel = level;
			rowContent.Question = disectedrow[0];
			rowContent.CodeQuestion = disectedrow[1];
			rowContent.Options = Helpers::splitString(disectedrow[2], ';');
		}

		static void contentLoadLoader(UserProfileModel &rowContent, vector<string> disectedrow) {
			rowContent.Name = disectedrow[0];
			rowContent.Surname = disectedrow[1];
			rowContent.Passward= disectedrow[2];
			rowContent.EmailAddress = disectedrow[3];
		}
	};

	class OperatorOverload
	{
		string primary;
	public:
		OperatorOverload(string &primary) {
			this->primary = primary;
		}
		~OperatorOverload() {

		}

		bool operator==(const string &secondary ) {
			if (primary.size() != secondary.size()) return false;

			for (int i = 0; i < primary.size(); i++) {
				if (primary.at(i) != secondary.at(i)) {
					return false;
				}
			}
			return true;
		}
	};

}