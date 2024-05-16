#include "../HomePage.h"
#pragma once

using namespace QuizClient;


int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	HomePage^ homepage = gcnew HomePage();
	Application::Run(homepage);

	return 0;
}