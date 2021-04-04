#pragma once

namespace Culculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ plus;
	private: System::Windows::Forms::Button^ minus;
	private: System::Windows::Forms::Button^ Num_9;
	protected:



	private: System::Windows::Forms::Button^ Num_8;

	private: System::Windows::Forms::Button^ Num_7;

	private: System::Windows::Forms::Button^ Num_4;
	private: System::Windows::Forms::Button^ Num_5;
	private: System::Windows::Forms::Button^ Num_0;



	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ Num_2;

	private: System::Windows::Forms::Button^ Num_1;

	private: System::Windows::Forms::Button^ mult;
	private: System::Windows::Forms::Button^ Num_3;
	private: System::Windows::Forms::Button^ Num_6;



	private: System::Windows::Forms::Button^ result;

	private: System::Windows::Forms::Button^ dis;

	private: System::Windows::Forms::TextBox^ TextBox;
	private: System::Windows::Forms::Button^ del;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->plus = (gcnew System::Windows::Forms::Button());
			this->minus = (gcnew System::Windows::Forms::Button());
			this->Num_9 = (gcnew System::Windows::Forms::Button());
			this->Num_8 = (gcnew System::Windows::Forms::Button());
			this->Num_7 = (gcnew System::Windows::Forms::Button());
			this->Num_4 = (gcnew System::Windows::Forms::Button());
			this->Num_5 = (gcnew System::Windows::Forms::Button());
			this->Num_0 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->Num_2 = (gcnew System::Windows::Forms::Button());
			this->Num_1 = (gcnew System::Windows::Forms::Button());
			this->mult = (gcnew System::Windows::Forms::Button());
			this->Num_3 = (gcnew System::Windows::Forms::Button());
			this->Num_6 = (gcnew System::Windows::Forms::Button());
			this->result = (gcnew System::Windows::Forms::Button());
			this->dis = (gcnew System::Windows::Forms::Button());
			this->TextBox = (gcnew System::Windows::Forms::TextBox());
			this->del = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// plus
			// 
			this->plus->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->plus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->plus->Location = System::Drawing::Point(12, 84);
			this->plus->Name = L"plus";
			this->plus->Size = System::Drawing::Size(108, 95);
			this->plus->TabIndex = 0;
			this->plus->Text = L"+";
			this->plus->UseVisualStyleBackColor = false;
			this->plus->Click += gcnew System::EventHandler(this, &MyForm::plus_Click);
			// 
			// minus
			// 
			this->minus->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->minus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->minus->Location = System::Drawing::Point(12, 185);
			this->minus->Name = L"minus";
			this->minus->Size = System::Drawing::Size(108, 95);
			this->minus->TabIndex = 1;
			this->minus->Text = L"-";
			this->minus->UseVisualStyleBackColor = false;
			this->minus->Click += gcnew System::EventHandler(this, &MyForm::minus_Click);
			// 
			// Num_9
			// 
			this->Num_9->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Num_9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Num_9->Location = System::Drawing::Point(354, 84);
			this->Num_9->Name = L"Num_9";
			this->Num_9->Size = System::Drawing::Size(108, 95);
			this->Num_9->TabIndex = 2;
			this->Num_9->Text = L"9";
			this->Num_9->UseVisualStyleBackColor = false;
			this->Num_9->Click += gcnew System::EventHandler(this, &MyForm::Num_9_Click);
			// 
			// Num_8
			// 
			this->Num_8->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Num_8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Num_8->Location = System::Drawing::Point(240, 84);
			this->Num_8->Name = L"Num_8";
			this->Num_8->Size = System::Drawing::Size(108, 95);
			this->Num_8->TabIndex = 3;
			this->Num_8->Text = L"8";
			this->Num_8->UseVisualStyleBackColor = false;
			this->Num_8->Click += gcnew System::EventHandler(this, &MyForm::Num_8_Click);
			// 
			// Num_7
			// 
			this->Num_7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Num_7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Num_7->Location = System::Drawing::Point(126, 84);
			this->Num_7->Name = L"Num_7";
			this->Num_7->Size = System::Drawing::Size(108, 95);
			this->Num_7->TabIndex = 4;
			this->Num_7->Text = L"7";
			this->Num_7->UseVisualStyleBackColor = false;
			this->Num_7->Click += gcnew System::EventHandler(this, &MyForm::Num_7_Click);
			// 
			// Num_4
			// 
			this->Num_4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Num_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Num_4->Location = System::Drawing::Point(126, 185);
			this->Num_4->Name = L"Num_4";
			this->Num_4->Size = System::Drawing::Size(108, 95);
			this->Num_4->TabIndex = 5;
			this->Num_4->Text = L"4";
			this->Num_4->UseVisualStyleBackColor = false;
			this->Num_4->Click += gcnew System::EventHandler(this, &MyForm::Num_4_Click);
			// 
			// Num_5
			// 
			this->Num_5->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Num_5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Num_5->Location = System::Drawing::Point(240, 185);
			this->Num_5->Name = L"Num_5";
			this->Num_5->Size = System::Drawing::Size(108, 95);
			this->Num_5->TabIndex = 6;
			this->Num_5->Text = L"5";
			this->Num_5->UseVisualStyleBackColor = false;
			this->Num_5->Click += gcnew System::EventHandler(this, &MyForm::Num_5_Click);
			// 
			// Num_0
			// 
			this->Num_0->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Num_0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Num_0->Location = System::Drawing::Point(240, 387);
			this->Num_0->Name = L"Num_0";
			this->Num_0->Size = System::Drawing::Size(108, 95);
			this->Num_0->TabIndex = 7;
			this->Num_0->Text = L"0";
			this->Num_0->UseVisualStyleBackColor = false;
			this->Num_0->Click += gcnew System::EventHandler(this, &MyForm::Num_0_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(354, 387);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(108, 95);
			this->button9->TabIndex = 8;
			this->button9->Text = L".";
			this->button9->UseVisualStyleBackColor = false;
			// 
			// Num_2
			// 
			this->Num_2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Num_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Num_2->Location = System::Drawing::Point(240, 286);
			this->Num_2->Name = L"Num_2";
			this->Num_2->Size = System::Drawing::Size(108, 95);
			this->Num_2->TabIndex = 9;
			this->Num_2->Text = L"2";
			this->Num_2->UseVisualStyleBackColor = false;
			this->Num_2->Click += gcnew System::EventHandler(this, &MyForm::Num_2_Click);
			// 
			// Num_1
			// 
			this->Num_1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Num_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Num_1->Location = System::Drawing::Point(126, 286);
			this->Num_1->Name = L"Num_1";
			this->Num_1->Size = System::Drawing::Size(108, 95);
			this->Num_1->TabIndex = 10;
			this->Num_1->Text = L"1";
			this->Num_1->UseVisualStyleBackColor = false;
			this->Num_1->Click += gcnew System::EventHandler(this, &MyForm::Num_1_Click);
			// 
			// mult
			// 
			this->mult->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->mult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mult->Location = System::Drawing::Point(12, 286);
			this->mult->Name = L"mult";
			this->mult->Size = System::Drawing::Size(108, 95);
			this->mult->TabIndex = 11;
			this->mult->Text = L"*";
			this->mult->UseVisualStyleBackColor = false;
			this->mult->Click += gcnew System::EventHandler(this, &MyForm::mult_Click);
			// 
			// Num_3
			// 
			this->Num_3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Num_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Num_3->Location = System::Drawing::Point(354, 286);
			this->Num_3->Name = L"Num_3";
			this->Num_3->Size = System::Drawing::Size(108, 95);
			this->Num_3->TabIndex = 12;
			this->Num_3->Text = L"3";
			this->Num_3->UseVisualStyleBackColor = false;
			this->Num_3->Click += gcnew System::EventHandler(this, &MyForm::Num_3_Click);
			// 
			// Num_6
			// 
			this->Num_6->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Num_6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Num_6->Location = System::Drawing::Point(354, 185);
			this->Num_6->Name = L"Num_6";
			this->Num_6->Size = System::Drawing::Size(108, 95);
			this->Num_6->TabIndex = 13;
			this->Num_6->Text = L"6";
			this->Num_6->UseVisualStyleBackColor = false;
			this->Num_6->Click += gcnew System::EventHandler(this, &MyForm::Num_6_Click);
			// 
			// result
			// 
			this->result->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result->Location = System::Drawing::Point(126, 387);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(108, 95);
			this->result->TabIndex = 14;
			this->result->Text = L"=";
			this->result->UseVisualStyleBackColor = false;
			this->result->Click += gcnew System::EventHandler(this, &MyForm::result_Click);
			// 
			// dis
			// 
			this->dis->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->dis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dis->Location = System::Drawing::Point(12, 387);
			this->dis->Name = L"dis";
			this->dis->Size = System::Drawing::Size(108, 95);
			this->dis->TabIndex = 15;
			this->dis->Text = L"/";
			this->dis->UseVisualStyleBackColor = false;
			this->dis->Click += gcnew System::EventHandler(this, &MyForm::dis_Click);
			// 
			// TextBox
			// 
			this->TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBox->Location = System::Drawing::Point(12, 12);
			this->TextBox->Name = L"TextBox";
			this->TextBox->ReadOnly = true;
			this->TextBox->Size = System::Drawing::Size(336, 53);
			this->TextBox->TabIndex = 16;
			this->TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// del
			// 
			this->del->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->del->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->del->Location = System::Drawing::Point(354, 12);
			this->del->Name = L"del";
			this->del->Size = System::Drawing::Size(108, 53);
			this->del->TabIndex = 17;
			this->del->Text = L"Del";
			this->del->UseVisualStyleBackColor = false;
			this->del->Click += gcnew System::EventHandler(this, &MyForm::del_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 502);
			this->Controls->Add(this->del);
			this->Controls->Add(this->TextBox);
			this->Controls->Add(this->dis);
			this->Controls->Add(this->result);
			this->Controls->Add(this->Num_6);
			this->Controls->Add(this->Num_3);
			this->Controls->Add(this->mult);
			this->Controls->Add(this->Num_1);
			this->Controls->Add(this->Num_2);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->Num_0);
			this->Controls->Add(this->Num_5);
			this->Controls->Add(this->Num_4);
			this->Controls->Add(this->Num_7);
			this->Controls->Add(this->Num_8);
			this->Controls->Add(this->Num_9);
			this->Controls->Add(this->minus);
			this->Controls->Add(this->plus);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void Num_1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Num_2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Num_3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Num_4_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Num_5_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Num_6_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Num_7_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Num_8_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Num_9_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Num_0_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void del_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void plus_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void minus_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void mult_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dis_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void result_Click(System::Object^ sender, System::EventArgs^ e);
};
}
