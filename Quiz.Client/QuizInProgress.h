#pragma 
#include <array>;
#include <msclr\marshal_cppstd.h>;
#include "Models/Models.cpp";
#include <cliext/vector>
#include "Models/HelperModel.cpp"
#include "data/dataSource/DataSourcehelperFunctions.cpp"
#include "Grading.h"

namespace QuizClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Models;
	using namespace HelperFuctions;

	/// <summary>
	/// Summary for QuizInProgress
	/// </summary>
	public ref class QuizInProgress : public System::Windows::Forms::Form
	{

	public:
		QuizInProgress(cliext::vector<DisplaySessionQuestionModel^>^ displaysessionquestions)
		{
			this->displaysessionquestionspointer = displaysessionquestions;
			
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
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button3;
	private: cliext::vector<DisplaySessionQuestionModel^>^ displaysessionquestionspointer;
	private: int currentIndex = 0;
	private: System::String^ question;
	private: System::String^ codequestion;
	private: System::Windows::Forms::Label^ label4;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(QuizInProgress::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			this->button1->Click += gcnew System::EventHandler(this, &QuizInProgress::button1_Click);
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
			this->button2->Click += gcnew System::EventHandler(this, &QuizInProgress::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(158, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(157, 127);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 2;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(161, 290);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(85, 17);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &QuizInProgress::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(161, 325);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(85, 17);
			this->radioButton2->TabIndex = 4;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &QuizInProgress::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(161, 358);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(85, 17);
			this->radioButton3->TabIndex = 5;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &QuizInProgress::radioButton3_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(160, 391);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(85, 17);
			this->radioButton4->TabIndex = 6;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"radioButton4";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &QuizInProgress::radioButton4_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(573, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"label3";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(325, 451);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Submit Test";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &QuizInProgress::button3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(92, 50);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"label4";
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
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
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
			
			this->question = this->displaysessionquestionspointer->at(currentIndex)->getQuestion();
			this->codequestion = this->displaysessionquestionspointer->at(currentIndex)->getCodeQuestion();
			this->label1->Text = question;
			this->label2->Text = codequestion;
			this->label3->Text = L"Question " + ( currentIndex + 1 )+ " of " + System::Convert::ToString(displaysessionquestionspointer->size());
			this->label4->Text = this->displaysessionquestionspointer->at(currentIndex)->getQuestionLevel();
		}

		private:void OptionWork() {

			for (int i = 0; i < this->displaysessionquestionspointer->at(currentIndex)->getOptions().size(); i++) {

				String^ option = this->displaysessionquestionspointer->at(currentIndex)->getOptions().at(i);
				if (option->StartsWith("Correct")) {
					option = option->Substring(option->IndexOf('t') + 1);
					this->displaysessionquestionspointer->at(currentIndex)->setCorrectAnswerIndex(i);
				}

				OperatorOverload op(msclr::interop::marshal_as<std::string>(option));
				if (i == 0) {
					this->radioButton1->Text = option;
					op == msclr::interop::marshal_as<std::string>(this->displaysessionquestionspointer->at(i)->getUserAnswer()) ? radioButton1->Checked = true : radioButton1->Checked = false;
					this->radioButton1->Show();
				}
				else if (i == 1) {
					this->radioButton2->Text = option;
					op == msclr::interop::marshal_as<std::string>(this->displaysessionquestionspointer->at(i)->getUserAnswer()) ? radioButton2->Checked = true : radioButton2->Checked = false;
					this->radioButton2->Show();
				}
				else if (i == 2) {
					this->radioButton3->Text = option;
					op == msclr::interop::marshal_as<std::string>(this->displaysessionquestionspointer->at(i)->getUserAnswer()) ? radioButton3->Checked = true : radioButton3->Checked = false;
					this->radioButton3->Show();
				}
				else {
					this->radioButton4->Text = option;
					op == msclr::interop::marshal_as<std::string>(this->displaysessionquestionspointer->at(i)->getUserAnswer()) ? radioButton4->Checked = true : radioButton4->Checked = false;
					this->radioButton4->Show();
				}
			}
		}


#pragma endregion

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			if (currentIndex + 1 < this->displaysessionquestionspointer->size()) {
				currentIndex++;
				QuestionWork();
				OptionWork();
				this->ResumeLayout(false);
				this->PerformLayout();
			}
		}

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			if (currentIndex - 1 >= 0 ) {
				currentIndex--;
				QuestionWork();
				OptionWork();
				this->ResumeLayout(false);
				this->PerformLayout();
			}
		}
		private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			this->displaysessionquestionspointer->at(currentIndex)->setUserAnswer(radioButton1->Text);
		}
		private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			this->displaysessionquestionspointer->at(currentIndex)->setUserAnswer(radioButton2->Text);
		}
		private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			this->displaysessionquestionspointer->at(currentIndex)->setUserAnswer(radioButton3->Text);
		}
		private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			this->displaysessionquestionspointer->at(currentIndex)->setUserAnswer(radioButton4->Text);
		}
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			int score = 0;

			for (int i = 0; i < this->displaysessionquestionspointer->size(); i ++) {
				
				OperatorOverload op( msclr::interop::marshal_as<std::string>( "Correct" + this->displaysessionquestionspointer->at(i)->getUserAnswer()));
				int index = this->displaysessionquestionspointer->at(i)->getCorrectAnswerIndex();
				if (op == msclr::interop::marshal_as<std::string>(this->displaysessionquestionspointer->at(i)->getOptions()[index])) {
					score++;
				}
			}

			String^ usergrade = score + "/" + this->displaysessionquestionspointer->size();
			Grading^ gradeComp = gcnew Grading(usergrade);
			gradeComp->Show();
			this->Hide();
		}
	};
}
