#pragma 
#include <vector>;
#include <msclr\marshal_cppstd.h>;
#include "Models/Models.cpp";

namespace QuizClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace Models;

	/// <summary>
	/// Summary for QuizInProgress
	/// </summary>
	public ref class QuizInProgress : public System::Windows::Forms::Form
	{

	public:
		QuizInProgress(const vector<SessionQuestionsModel> *sessionquestions)
		{
			this->sessionquestionspointer = sessionquestions;
			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~QuizInProgress()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1 ;;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: const vector<SessionQuestionsModel> *sessionquestionspointer;
	private: int currentIndex = 0;
	private: System::String^ question;
	private: System::String^ codequestion;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuizInProgress::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			//this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			//this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			//this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			//this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			//this->Question = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button1->Font = (gcnew System::Drawing::Font(L"Ink Free", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(643, 447);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Next";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkGray;
			this->button2->Font = (gcnew System::Drawing::Font(L"Ink Free", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(36, 447);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(193, 94);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"uifa";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(193, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"uifa";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(185, 287);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(185, 310);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(80, 17);
			this->checkBox2->TabIndex = 4;
			this->checkBox2->Text = L"checkBox2";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(185, 333);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(80, 17);
			this->checkBox3->TabIndex = 5;
			this->checkBox3->Text = L"checkBox3";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(185, 356);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(80, 17);
			this->checkBox4->TabIndex = 6;
			this->checkBox4->Text = L"checkBox4";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// QuizInProgress
			// 
			QuestionWork();
			OptionWork();

			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(730, 482);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"QuizInProgress";
			this->Text = L"QuizInProgress";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		private:void QuestionWork() {
			this->question = (gcnew System::String(msclr::interop::marshal_as<String^>(this->sessionquestionspointer->at(currentIndex).questionModel.Question)));
			this->codequestion = "CodeQuestion";// (gcnew System::String(msclr::interop::marshal_as<String^>(this->sessionquestionspointer->at(currentIndex).questionModel.CodeQuestion)));
			this->label1->Text = question;
			this->label2->Text = codequestion;
		}

		private:void OptionWork() {

			for (int i = 0; i < this->sessionquestionspointer->at(currentIndex).questionModel.Options.size(); i++) {
				String^ option = gcnew System::String(msclr::interop::marshal_as<String^>(this->sessionquestionspointer->at(currentIndex).questionModel.Options.at(i)));
				if (option->StartsWith("Correct")) {
					option = option->Substring(option->IndexOf('t') + 1);
				}

				if (i == 0) {
					this->checkBox1->Text = option;
					this->checkBox1->Show();
				}
				else if (i == 1) {
					this->checkBox2->Text = option;
					this->checkBox2->Show();
				}
				else if (i == 2) {
					this->checkBox3->Text = option;
					this->checkBox3->Show();
				}
				else {
					this->checkBox4->Text = option;
					this->checkBox4->Show();
				}
			}
		}
#pragma endregion
	};
}
