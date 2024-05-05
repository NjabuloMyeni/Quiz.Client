#include "../data/dataSource/DataLoader.cpp"
#include "../HomePage.h"
#pragma once

using namespace QuizClient;


int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	HomePage^ homepage = gcnew HomePage();
	Application::Run(homepage);
	//DataLoader loader(userAPI);

	return 0;
}