#include <string>
#include <vector>
#include <cctype>
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
			
			rowContent.Question = trim(disectedrow[0]);
			rowContent.CodeQuestion = trim(disectedrow[1]);
			rowContent.Options = Helpers::splitString(trim(disectedrow[2]), ';');
		}

		static void contentLoadLoader(UserProfileModel &rowContent, vector<string> disectedrow) {
			rowContent.Name = trim(disectedrow[0]);
			rowContent.Surname = trim(disectedrow[1]);
			rowContent.Passward= trim(disectedrow[2]);
			rowContent.EmailAddress = trim(disectedrow[3]);
		}

		static string trim(const string& str) {

			size_t start = str.find_first_not_of(" \t\n\r");
			size_t end = str.find_last_not_of(" \t\n\r");

			if (start == string::npos || end == string::npos) {

				return "";
			}
			return str.substr(start, end - start + 1);
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