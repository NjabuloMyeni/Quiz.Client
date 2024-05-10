#pragma once
#include <cliext/vector>
#include "FinishQuiz.h"
#include "Models/HelperModel.cpp"

namespace QuizClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Grading
	/// </summary>
	public ref class Grading : public System::Windows::Forms::Form
	{
	public:
		Grading(cliext::vector<DisplaySessionQuestionModel^>^ displaysessionquestionmodel,String^ score)
		{
			this->displaysessionquestionmodelpointer = displaysessionquestionmodel;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Grading()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
		   cliext::vector<DisplaySessionQuestionModel^>^ displaysessionquestionmodelpointer;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Grading::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Ink Free", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(536, 391);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"EXIT";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Control;
			this->label1->Font = (gcnew System::Drawing::Font(L"Ink Free", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(200, 144);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 36);
			this->label1->TabIndex = 1;
			this->label1->Text = L"THANK YOU!!!";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Ink Free", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(536, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(93, 24);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Review";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Grading::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Ink Free", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(202, 204);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(171, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"YOUR SCORE IS :";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox1->Location = System::Drawing::Point(379, 204);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			// 
			// Grading
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(753, 426);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Grading";
			this->Text = L"Grading";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

			String^ review;
			for (int i = 0; i < this->displaysessionquestionmodelpointer->size(); i++) {

				if ( !this->displaysessionquestionmodelpointer->at(i)->getUserAnswer()->Empty ) {

					review->Concat(this->displaysessionquestionmodelpointer->at(i)->getQuestion() + "\n");
					review->Concat(this->displaysessionquestionmodelpointer->at(i)->getCodeQuestion() + "\n");
					review->Concat(this->displaysessionquestionmodelpointer->at(i)->getOptions().ToString() + "\n");
				}
			}
			FinishQuiz^ finishQuiz = gcnew FinishQuiz(review);
			finishQuiz->Show();
			this->Hide();
		}
};
}
