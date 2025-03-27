#pragma once
//#include "Resources.resx"
//#include "resource1.h"
//#include "NewForm1.resx"
namespace MyProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для NewForm
	/// </summary>
	public ref class NewForm : public System::Windows::Forms::Form
	{
	public:
		NewForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~NewForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(41, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(331, 52);
			this->label1->TabIndex = 0;
			this->label1->Text = L"1.Необхідно обрати метод розв’язання СЛАР. Для цього треба натиснути на розкривни"
				L"й список та обрати відповідний метод";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox1
			// 
			
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject((L"button1.Image"))));
			this->pictureBox1->Location = System::Drawing::Point(76, 97);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(228, 112);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(41, 221);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(331, 101);
			this->label2->TabIndex = 2;
			//System::Resources::ResourceManager^ resourceManager1 = gcnew System::Resources::ResourceManager("MyProject.NewForm1", this->GetType()->Assembly);
			//this->label2->Text = resourceManager1->GetString(L"label2.Text");

			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox2
			// 
			//System::Resources::ResourceManager^ resourceManager2 = gcnew System::Resources::ResourceManager("MyProject.NewForm1", this->GetType()->Assembly);
			//this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager2->GetObject(L"pictureBox1.Image")));
			this->pictureBox2->Location = System::Drawing::Point(90, 338);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(214, 101);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(41, 465);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(331, 101);
			this->label3->TabIndex = 5;
			//System::Resources::ResourceManager^ resourceManager3 = gcnew System::Resources::ResourceManager("MyProject.NewForm1", this->GetType()->Assembly);
			//this->label2->Text = resourceManager3->GetString(L"label3.Text");
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox4
			// 
			//System::Resources::ResourceManager^ resourceManager4 = gcnew System::Resources::ResourceManager("MyProject.NewForm1", this->GetType()->Assembly);
			//this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager4->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(44, 569);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(330, 96);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 6;
			this->pictureBox4->TabStop = false;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(444, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(331, 101);
			this->label4->TabIndex = 7;
			this->label4->Text = L"4.Після введення коректних коефіцієнтів кнопка початку розв’язку стає активною, о"
				L"тже можна почати розв’язок системи, натиснувши на цю кнопку";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox3
			// 
			//System::Resources::ResourceManager^ resourceManager5 = gcnew System::Resources::ResourceManager("MyProject.NewForm1", this->GetType()->Assembly);
			//this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager5->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(508, 97);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(215, 44);
			this->pictureBox3->TabIndex = 8;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox5
			// 
			//System::Resources::ResourceManager^ resourceManager6 = gcnew System::Resources::ResourceManager("MyProject.NewForm1", this->GetType()->Assembly);
			//this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager6->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(479, 231);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(279, 82);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 10;
			this->pictureBox5->TabStop = false;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(444, 164);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(331, 101);
			this->label5->TabIndex = 9;
			this->label5->Text = L"5.Тепер вивелось відповідне повідомлення з розв’язками системи рівнянь та кількіс"
				L"ть ітерацій роботи алгоритму під час розв’язання";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox6
			// 
			//System::Resources::ResourceManager^ resourceManager7 = gcnew System::Resources::ResourceManager("MyProject.NewForm1", this->GetType()->Assembly);
			//this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager7->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(508, 408);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(215, 54);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 12;
			this->pictureBox6->TabStop = false;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(444, 343);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(331, 101);
			this->label6->TabIndex = 11;
			this->label6->Text = L"6.В кінці після розв’язання системи можна подивитись на відповідні записи у файлі"
				L", натиснувши на кнопку відкриття файлу";
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox7
			// 
			//System::Resources::ResourceManager^ resourceManager8 = gcnew System::Resources::ResourceManager("MyProject.NewForm1", this->GetType()->Assembly);
			//this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager8->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(483, 468);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(275, 223);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 13;
			this->pictureBox7->TabStop = false;
			// 
			// NewForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(817, 715);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			//System::Resources::ResourceManager^ resourceManager9 = gcnew System::Resources::ResourceManager("MyProject.NewForm1", this->GetType()->Assembly);
			//this->label2->Text = resourceManager1->GetString(L"label2.Text");

			//resourceManager1 = gcnew System::Resources::ResourceManager("MyProject.NewForm1", this->GetType()->Assembly);

			// Установка иконки из ресурсов
			//this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resourceManager9->GetObject(L"$this.Icon")));

			//this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"NewForm";
			this->Text = L"Справка";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
