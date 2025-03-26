#pragma once
#include "frmUserAdmin1.h"
#include "frmCreateUser.h"
#include "frmForgotPassword.h"

namespace BounsPoints {

	using namespace System;

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class frmLogin : public System::Windows::Forms::Form
	{
		public:
			frmLogin(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~frmLogin()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::TextBox^ txtUsername;
		private: System::Windows::Forms::TextBox^ txtPassword;
		private: System::Windows::Forms::Button^ btSignin;



		private: System::Windows::Forms::Button^ btExit;

		private: System::Windows::Forms::Label^ lbCreateAccount;
		private: System::Windows::Forms::Label^ lbForgotPassword;


		protected:

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
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->txtUsername = (gcnew System::Windows::Forms::TextBox());
				this->txtPassword = (gcnew System::Windows::Forms::TextBox());
				this->btSignin = (gcnew System::Windows::Forms::Button());
				this->btExit = (gcnew System::Windows::Forms::Button());
				this->lbCreateAccount = (gcnew System::Windows::Forms::Label());
				this->lbForgotPassword = (gcnew System::Windows::Forms::Label());
				this->SuspendLayout();
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->label1->Location = System::Drawing::Point(145, 52);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(128, 42);
				this->label1->TabIndex = 0;
				this->label1->Text = L"Sign in";
				this->label1->UseMnemonic = false;
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label2->Location = System::Drawing::Point(105, 119);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(85, 18);
				this->label2->TabIndex = 1;
				this->label2->Text = L"Username";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label3->Location = System::Drawing::Point(105, 178);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(93, 18);
				this->label3->TabIndex = 2;
				this->label3->Text = L"Passoword";
				// 
				// txtUsername
				// 
				this->txtUsername->Location = System::Drawing::Point(108, 142);
				this->txtUsername->Name = L"txtUsername";
				this->txtUsername->Size = System::Drawing::Size(244, 20);
				this->txtUsername->TabIndex = 3;
				// 
				// txtPassword
				// 
				this->txtPassword->Location = System::Drawing::Point(108, 201);
				this->txtPassword->Name = L"txtPassword";
				this->txtPassword->Size = System::Drawing::Size(244, 20);
				this->txtPassword->TabIndex = 4;
				this->txtPassword->UseSystemPasswordChar = true;
				// 
				// btSignin
				// 
				this->btSignin->Location = System::Drawing::Point(123, 242);
				this->btSignin->Name = L"btSignin";
				this->btSignin->Size = System::Drawing::Size(75, 23);
				this->btSignin->TabIndex = 5;
				this->btSignin->Text = L"Sign in";
				this->btSignin->UseVisualStyleBackColor = true;
				this->btSignin->Click += gcnew System::EventHandler(this, &frmLogin::btSignin_Click);
				// 
				// btExit
				// 
				this->btExit->Location = System::Drawing::Point(254, 242);
				this->btExit->Name = L"btExit";
				this->btExit->Size = System::Drawing::Size(75, 23);
				this->btExit->TabIndex = 6;
				this->btExit->Text = L"Exit";
				this->btExit->UseVisualStyleBackColor = true;
				this->btExit->Click += gcnew System::EventHandler(this, &frmLogin::btExit_Click);
				// 
				// lbCreateAccount
				// 
				this->lbCreateAccount->AutoSize = true;
				this->lbCreateAccount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->lbCreateAccount->ForeColor = System::Drawing::Color::Coral;
				this->lbCreateAccount->Location = System::Drawing::Point(105, 279);
				this->lbCreateAccount->Name = L"lbCreateAccount";
				this->lbCreateAccount->Size = System::Drawing::Size(128, 18);
				this->lbCreateAccount->TabIndex = 7;
				this->lbCreateAccount->Text = L"Create a accout";
				this->lbCreateAccount->Click += gcnew System::EventHandler(this, &frmLogin::lbCreateAccount_Click);
				// 
				// lbForgotPassword
				// 
				this->lbForgotPassword->AutoSize = true;
				this->lbForgotPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->lbForgotPassword->ForeColor = System::Drawing::Color::Coral;
				this->lbForgotPassword->Location = System::Drawing::Point(105, 306);
				this->lbForgotPassword->Name = L"lbForgotPassword";
				this->lbForgotPassword->Size = System::Drawing::Size(138, 18);
				this->lbForgotPassword->TabIndex = 8;
				this->lbForgotPassword->Text = L"Forgot Password";
				this->lbForgotPassword->Click += gcnew System::EventHandler(this, &frmLogin::lbForgotPassword_Click);
				// 
				// frmLogin
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(688, 361);
				this->Controls->Add(this->lbForgotPassword);
				this->Controls->Add(this->lbCreateAccount);
				this->Controls->Add(this->btExit);
				this->Controls->Add(this->btSignin);
				this->Controls->Add(this->txtPassword);
				this->Controls->Add(this->txtUsername);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->label1);
				this->Name = L"frmLogin";
				this->Text = L"LOG IN";
				this->Load += gcnew System::EventHandler(this, &frmLogin::MyForm_Load);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion


		private: System::Void btExit_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
		private: System::Void btSignin_Click(System::Object^ sender, System::EventArgs^ e) {
			if (txtUsername->Text == "admin" && txtPassword->Text == "123456")
			{
				frmUserAdmin^ frm = gcnew frmUserAdmin();
				frm->ShowDialog();

			}
			else
			{
				MessageBox::Show("Inconrect Username/Password", "MessageBox", MessageBoxButtons::OK, MessageBoxIcon::Question);

			}
		}
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void lbCreateAccount_Click(System::Object^ sender, System::EventArgs^ e) {
			frmCreateUser^ frm = gcnew frmCreateUser();
			frm->ShowDialog();
		};
		private: System::Void lbForgotPassword_Click(System::Object^ sender, System::EventArgs^ e) {
			frmForgotPassword^ frm = gcnew frmForgotPassword();
			frm->ShowDialog();
		}
	};
}
