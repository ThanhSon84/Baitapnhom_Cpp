#pragma once

namespace BounsPoints {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmUserAdmin
	/// </summary>
	public ref class frmUserAdmin : public System::Windows::Forms::Form
	{
	public:
		frmUserAdmin(void)
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
		~frmUserAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbBounsStock;
	private: System::Windows::Forms::Label^ lbBounsTotal;
	private: System::Windows::Forms::DataGridView^ gridUser;
	private: System::Windows::Forms::Button^ btnNew;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnTrans;




	protected:


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
			this->lbBounsStock = (gcnew System::Windows::Forms::Label());
			this->lbBounsTotal = (gcnew System::Windows::Forms::Label());
			this->gridUser = (gcnew System::Windows::Forms::DataGridView());
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnTrans = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridUser))->BeginInit();
			this->SuspendLayout();
			// 
			// lbBounsStock
			// 
			this->lbBounsStock->AutoSize = true;
			this->lbBounsStock->Location = System::Drawing::Point(346, 40);
			this->lbBounsStock->Name = L"lbBounsStock";
			this->lbBounsStock->Size = System::Drawing::Size(128, 13);
			this->lbBounsStock->TabIndex = 0;
			this->lbBounsStock->Text = L"Tổng điểm thưởng còn lại";
			// 
			// lbBounsTotal
			// 
			this->lbBounsTotal->AutoSize = true;
			this->lbBounsTotal->Location = System::Drawing::Point(148, 40);
			this->lbBounsTotal->Name = L"lbBounsTotal";
			this->lbBounsTotal->Size = System::Drawing::Size(145, 13);
			this->lbBounsTotal->TabIndex = 1;
			this->lbBounsTotal->Text = L"Tổng điểm thưởng phát hành";
			// 
			// gridUser
			// 
			this->gridUser->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridUser->Location = System::Drawing::Point(35, 115);
			this->gridUser->Name = L"gridUser";
			this->gridUser->Size = System::Drawing::Size(740, 263);
			this->gridUser->TabIndex = 2;
			// 
			// btnNew
			// 
			this->btnNew->Location = System::Drawing::Point(457, 86);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(75, 23);
			this->btnNew->TabIndex = 3;
			this->btnNew->Text = L"Thêm";
			this->btnNew->UseVisualStyleBackColor = true;
			// 
			// btnUpdate
			// 
			this->btnUpdate->Location = System::Drawing::Point(538, 86);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(75, 23);
			this->btnUpdate->TabIndex = 4;
			this->btnUpdate->Text = L"Sửa";
			this->btnUpdate->UseVisualStyleBackColor = true;
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(619, 86);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 5;
			this->btnDelete->Text = L"Xóa";
			this->btnDelete->UseVisualStyleBackColor = true;
			// 
			// btnTrans
			// 
			this->btnTrans->Location = System::Drawing::Point(700, 86);
			this->btnTrans->Name = L"btnTrans";
			this->btnTrans->Size = System::Drawing::Size(75, 23);
			this->btnTrans->TabIndex = 6;
			this->btnTrans->Text = L"Chuyển điểm";
			this->btnTrans->UseVisualStyleBackColor = true;
			// 
			// frmUserAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(787, 390);
			this->Controls->Add(this->btnTrans);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->btnNew);
			this->Controls->Add(this->gridUser);
			this->Controls->Add(this->lbBounsTotal);
			this->Controls->Add(this->lbBounsStock);
			this->Name = L"frmUserAdmin";
			this->Text = L"frmUserAdmin";
			this->Load += gcnew System::EventHandler(this, &frmUserAdmin::frmUserAdmin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridUser))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmUserAdmin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
