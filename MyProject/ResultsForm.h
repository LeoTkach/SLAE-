#pragma once

namespace MyProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ResultsForm
	/// </summary>
	public ref class ResultsForm : public System::Windows::Forms::Form
	{
	public:
		ResultsForm(String^ resultsText)
		{
			InitializeComponent();
			label1->Text = resultsText;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ResultsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ resultsBox;
	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::Label^ label1;
	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->resultsBox = (gcnew System::Windows::Forms::TextBox());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// resultsBox
			// 
			this->resultsBox->Location = System::Drawing::Point(50, 64);
			this->resultsBox->Multiline = true;
			this->resultsBox->Name = L"resultsBox";
			this->resultsBox->ReadOnly = true;
			this->resultsBox->Size = System::Drawing::Size(180, 82);
			this->resultsBox->TabIndex = 0;
			this->resultsBox->Visible = false;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(96, 167);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 1;
			this->okButton->Text = L"ОК";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &ResultsForm::okButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(62, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 16);
			this->label1->TabIndex = 2;
			// 
			// ResultsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 224);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->resultsBox);
			this->Name = L"ResultsForm";
			this->Text = L"Результати";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
