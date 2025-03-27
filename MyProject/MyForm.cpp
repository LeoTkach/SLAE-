#include "MyForm.h"
#include "NewForm1.h"
#include "Spravka.h"
#include <Random>
void MyProject::MyForm::InitializeComponent(void)
{
    System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
    System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
    System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
    System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
    this->comboBox_meth = (gcnew System::Windows::Forms::ComboBox());
    this->label_vve_rozm = (gcnew System::Windows::Forms::Label());
    this->textbox_rozm = (gcnew System::Windows::Forms::TextBox());
    this->Button_cre_table = (gcnew System::Windows::Forms::Button());
    this->tableLayout_gen = (gcnew System::Windows::Forms::TableLayoutPanel());
    this->button_poch_roz = (gcnew System::Windows::Forms::Button());
    this->label_ober_meth = (gcnew System::Windows::Forms::Label());
    this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
    this->label_per_funcs = (gcnew System::Windows::Forms::Label());
    this->label_rozv_sys = (gcnew System::Windows::Forms::Label());
    this->label_kil_iter = (gcnew System::Windows::Forms::Label());
    this->button_vid_file = (gcnew System::Windows::Forms::Button());
    this->button_gen_table = (gcnew System::Windows::Forms::Button());
    this->button_zch_from_file = (gcnew System::Windows::Forms::Button());
    this->button1 = (gcnew System::Windows::Forms::Button());
    this->button2 = (gcnew System::Windows::Forms::Button());
    this->button4 = (gcnew System::Windows::Forms::Button());
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
    this->SuspendLayout();
    // 
    // comboBox_meth
    // 
    this->comboBox_meth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
        static_cast<System::Int32>(static_cast<System::Byte>(252)));
    this->comboBox_meth->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->comboBox_meth->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->comboBox_meth->ImeMode = System::Windows::Forms::ImeMode::NoControl;
    this->comboBox_meth->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
        L"Метод Крамера", L"Метод Гауса з одиничною діагоналлю",
            L"Метод Гауса з вибором головн. ел.", L"Графічне розв\'язання"
    });
    this->comboBox_meth->Location = System::Drawing::Point(12, 32);
    this->comboBox_meth->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->comboBox_meth->Name = L"comboBox_meth";
    this->comboBox_meth->Size = System::Drawing::Size(232, 24);
    this->comboBox_meth->TabIndex = 6;
    this->comboBox_meth->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_meth_SelectedIndexChanged);
    // 
    // label_vve_rozm
    // 
    this->label_vve_rozm->AutoSize = true;
    this->label_vve_rozm->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label_vve_rozm->Location = System::Drawing::Point(17, 72);
    this->label_vve_rozm->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->label_vve_rozm->Name = L"label_vve_rozm";
    this->label_vve_rozm->Size = System::Drawing::Size(156, 18);
    this->label_vve_rozm->TabIndex = 12;
    this->label_vve_rozm->Text = L"Введіть розмірність";
    // 
    // textbox_rozm
    // 
    this->textbox_rozm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
        static_cast<System::Int32>(static_cast<System::Byte>(252)));
    this->textbox_rozm->Location = System::Drawing::Point(12, 93);
    this->textbox_rozm->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->textbox_rozm->Name = L"textbox_rozm";
    this->textbox_rozm->Size = System::Drawing::Size(164, 20);
    this->textbox_rozm->TabIndex = 8;
    this->textbox_rozm->TextChanged += gcnew System::EventHandler(this, &MyForm::textbox_rozm_TextChanged);
    this->textbox_rozm->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textbox_rozm_KeyPress);
    // 
    // Button_cre_table
    // 
    this->Button_cre_table->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(170)),
        static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
    this->Button_cre_table->Enabled = false;
    this->Button_cre_table->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->Button_cre_table->Location = System::Drawing::Point(12, 129);
    this->Button_cre_table->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->Button_cre_table->Name = L"Button_cre_table";
    this->Button_cre_table->Size = System::Drawing::Size(153, 45);
    this->Button_cre_table->TabIndex = 9;
    this->Button_cre_table->Text = L"Створити нову таблицю";
    this->Button_cre_table->UseVisualStyleBackColor = false;
    this->Button_cre_table->Click += gcnew System::EventHandler(this, &MyForm::Button_cre_table_Click);
    // 
    // tableLayout_gen
    // 
    this->tableLayout_gen->AutoSize = true;
    this->tableLayout_gen->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
        485)));
    this->tableLayout_gen->Location = System::Drawing::Point(12, 182);
    this->tableLayout_gen->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->tableLayout_gen->Name = L"tableLayout_gen";
    this->tableLayout_gen->Size = System::Drawing::Size(485, 265);
    this->tableLayout_gen->TabIndex = 10;
    // 
    // button_poch_roz
    // 
    this->button_poch_roz->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(56)),
        static_cast<System::Int32>(static_cast<System::Byte>(150)));
    this->button_poch_roz->Enabled = false;
    this->button_poch_roz->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button_poch_roz->ForeColor = System::Drawing::Color::White;
    this->button_poch_roz->Location = System::Drawing::Point(12, 539);
    this->button_poch_roz->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->button_poch_roz->Name = L"button_poch_roz";
    this->button_poch_roz->Size = System::Drawing::Size(153, 45);
    this->button_poch_roz->TabIndex = 11;
    this->button_poch_roz->Text = L"Почати розв\'язання";
    this->button_poch_roz->UseVisualStyleBackColor = false;
    this->button_poch_roz->Click += gcnew System::EventHandler(this, &MyForm::button_poch_roz_Click);
    this->button_poch_roz->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Button_Paint);
    // 
    // label_ober_meth
    // 
    this->label_ober_meth->AutoSize = true;
    this->label_ober_meth->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label_ober_meth->Location = System::Drawing::Point(12, 11);
    this->label_ober_meth->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->label_ober_meth->Name = L"label_ober_meth";
    this->label_ober_meth->Size = System::Drawing::Size(211, 18);
    this->label_ober_meth->TabIndex = 2;
    this->label_ober_meth->Text = L"Оберіть метод розв\'язання";
    // 
    // chart
    // 
    this->chart->BackColor = System::Drawing::SystemColors::InactiveCaption;
    this->chart->BorderSkin->PageColor = System::Drawing::Color::IndianRed;
    chartArea2->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
    chartArea2->AxisX->LabelStyle->Format = L"F2";
    chartArea2->AxisY->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
    chartArea2->AxisY->LabelStyle->Format = L"F2";
    chartArea2->BackColor = System::Drawing::SystemColors::InactiveCaption;
    chartArea2->BackSecondaryColor = System::Drawing::SystemColors::InactiveCaption;
    chartArea2->Name = L"ChartArea1";
    chartArea2->Position->Auto = false;
    chartArea2->Position->Height = 100;
    chartArea2->Position->Width = 100;
    this->chart->ChartAreas->Add(chartArea2);
    this->chart->Location = System::Drawing::Point(565, 11);
    this->chart->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->chart->Name = L"chart";
    series3->BorderWidth = 3;
    series3->ChartArea = L"ChartArea1";
    series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
    series3->Color = System::Drawing::Color::Red;
    series3->Name = L"Series1";
    series4->BorderWidth = 3;
    series4->ChartArea = L"ChartArea1";
    series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
    series4->Color = System::Drawing::Color::Blue;
    series4->Name = L"Series2";
    this->chart->Series->Add(series3);
    this->chart->Series->Add(series4);
    this->chart->Size = System::Drawing::Size(475, 424);
    this->chart->TabIndex = 13;
    // 
    // label_per_funcs
    // 
    this->label_per_funcs->AutoSize = true;
    this->label_per_funcs->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label_per_funcs->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
        static_cast<System::Int32>(static_cast<System::Byte>(7)));
    this->label_per_funcs->Location = System::Drawing::Point(698, 452);
    this->label_per_funcs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->label_per_funcs->Name = L"label_per_funcs";
    this->label_per_funcs->Size = System::Drawing::Size(0, 18);
    this->label_per_funcs->TabIndex = 14;
    // 
    // label_rozv_sys
    // 
    this->label_rozv_sys->AutoSize = true;
    this->label_rozv_sys->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label_rozv_sys->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
        static_cast<System::Int32>(static_cast<System::Byte>(7)));
    this->label_rozv_sys->Location = System::Drawing::Point(70, 457);
    this->label_rozv_sys->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->label_rozv_sys->Name = L"label_rozv_sys";
    this->label_rozv_sys->Size = System::Drawing::Size(0, 18);
    this->label_rozv_sys->TabIndex = 1;
    // 
    // label_kil_iter
    // 
    this->label_kil_iter->AutoSize = true;
    this->label_kil_iter->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label_kil_iter->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(88)),
        static_cast<System::Int32>(static_cast<System::Byte>(7)));
    this->label_kil_iter->Location = System::Drawing::Point(70, 496);
    this->label_kil_iter->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
    this->label_kil_iter->Name = L"label_kil_iter";
    this->label_kil_iter->Size = System::Drawing::Size(0, 18);
    this->label_kil_iter->TabIndex = 0;
    // 
    // button_vid_file
    // 
    this->button_vid_file->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(59)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
        static_cast<System::Int32>(static_cast<System::Byte>(120)));
    this->button_vid_file->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button_vid_file->ForeColor = System::Drawing::Color::White;
    this->button_vid_file->Location = System::Drawing::Point(334, 539);
    this->button_vid_file->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->button_vid_file->Name = L"button_vid_file";
    this->button_vid_file->Size = System::Drawing::Size(153, 45);
    this->button_vid_file->TabIndex = 15;
    this->button_vid_file->Text = L"Відкрити файл з розв\'язками";
    this->button_vid_file->UseVisualStyleBackColor = false;
    this->button_vid_file->Click += gcnew System::EventHandler(this, &MyForm::button_vid_file_Click);
    // 
    // button_gen_table
    // 
    this->button_gen_table->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(140)),
        static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
    this->button_gen_table->Enabled = false;
    this->button_gen_table->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button_gen_table->ForeColor = System::Drawing::SystemColors::ControlText;
    this->button_gen_table->Location = System::Drawing::Point(173, 129);
    this->button_gen_table->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->button_gen_table->Name = L"button_gen_table";
    this->button_gen_table->Size = System::Drawing::Size(153, 45);
    this->button_gen_table->TabIndex = 16;
    this->button_gen_table->Text = L"Згенерувати таблицю";
    this->button_gen_table->UseVisualStyleBackColor = false;
    this->button_gen_table->Click += gcnew System::EventHandler(this, &MyForm::button_gen_table_Click);
    // 
    // button_zch_from_file
    // 
    this->button_zch_from_file->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
        static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
    this->button_zch_from_file->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
    this->button_zch_from_file->ForeColor = System::Drawing::SystemColors::ControlText;
    this->button_zch_from_file->Location = System::Drawing::Point(334, 129);
    this->button_zch_from_file->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->button_zch_from_file->Name = L"button_zch_from_file";
    this->button_zch_from_file->Size = System::Drawing::Size(153, 45);
    this->button_zch_from_file->TabIndex = 17;
    this->button_zch_from_file->Text = L"Зчитати таблицю з файлу";
    this->button_zch_from_file->UseVisualStyleBackColor = false;
    this->button_zch_from_file->Click += gcnew System::EventHandler(this, &MyForm::button_zch_from_file_Click);
    // 
    // button1
    // 
    this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
    this->button1->Location = System::Drawing::Point(955, 545);
    this->button1->Name = L"button1";
    this->button1->Size = System::Drawing::Size(32, 32);
    this->button1->TabIndex = 18;
    this->button1->UseVisualStyleBackColor = true;
    this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
    // 
    // button2
    // 
    this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
    this->button2->Location = System::Drawing::Point(1008, 545);
    this->button2->Name = L"button2";
    this->button2->Size = System::Drawing::Size(32, 32);
    this->button2->TabIndex = 19;
    this->button2->UseVisualStyleBackColor = true;
    this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
    // 
    // button4
    // 
    this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(79)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
        static_cast<System::Int32>(static_cast<System::Byte>(150)));
    this->button4->Enabled = false;
    this->button4->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button4->ForeColor = System::Drawing::Color::White;
    this->button4->Location = System::Drawing::Point(173, 539);
    this->button4->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->button4->Name = L"button4";
    this->button4->Size = System::Drawing::Size(153, 45);
    this->button4->TabIndex = 21;
    this->button4->Text = L"Пошук розв\'язків у файлі";
    this->button4->UseVisualStyleBackColor = false;
    this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
    this->button4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Button_Paint);
    // 
    // MyForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::SystemColors::InactiveCaption;
    this->ClientSize = System::Drawing::Size(1080, 595);
    this->Controls->Add(this->button4);
    this->Controls->Add(this->button2);
    this->Controls->Add(this->button1);
    this->Controls->Add(this->button_zch_from_file);
    this->Controls->Add(this->button_gen_table);
    this->Controls->Add(this->button_vid_file);
    this->Controls->Add(this->label_kil_iter);
    this->Controls->Add(this->label_rozv_sys);
    this->Controls->Add(this->label_ober_meth);
    this->Controls->Add(this->button_poch_roz);
    this->Controls->Add(this->label_vve_rozm);
    this->Controls->Add(this->comboBox_meth);
    this->Controls->Add(this->textbox_rozm);
    this->Controls->Add(this->Button_cre_table);
    this->Controls->Add(this->tableLayout_gen);
    this->Controls->Add(this->chart);
    this->Controls->Add(this->label_per_funcs);
    this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
    this->HelpButton = true;
    this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
    this->Name = L"MyForm";
    this->Text = L"Розв\'язання СЛАР";
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
    this->ResumeLayout(false);
    this->PerformLayout();

}

MyProject::MyForm::MyForm(void)
{
    InitializeComponent();
    cr_table = gcnew TableCreator(textbox_rozm, tableLayout_gen, comboBox_meth, button_poch_roz, button4);
    chartManager = gcnew ChartManager(this->chart);
    comboBox_meth->SelectedIndex = 0;
}

MyProject::MyForm::~MyForm()
{
    if (components)
    {
        delete components;
    }
}

void MyProject::MyForm::textbox_rozm_KeyPress(Object^ sender, KeyPressEventArgs^ e) {
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8)
    {
        e->Handled = true; // Скасування введення символу
    }
}

void MyProject::MyForm::textbox_rozm_TextChanged(Object^ sender, EventArgs^ e) {

    if (!String::IsNullOrEmpty(textbox_rozm->Text)) {
        Button_cre_table->Enabled = true;
        button_gen_table->Enabled = true;
        int number = Int32::Parse(textbox_rozm->Text);

        if (number < 2 || number > 9) {
            if (textbox_rozm->SelectionStart > 1) {
                //Якщо перша цифра підходить, але все число більше за 9,
                // то видаляєм усі символи, окрім першого
                textbox_rozm->Text = textbox_rozm->Text[0].ToString();
                textbox_rozm->SelectionStart = 1; // Встановлення позиції курсора після першой цифри
            }
            else {
                textbox_rozm->Text = "";
            }
        }
    }
    else {
        Button_cre_table->Enabled = false;
        button_gen_table->Enabled = false;
    }
}

void MyProject::MyForm::comboBox_meth_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
    if (comboBox_meth->SelectedIndex == 3) {
        textbox_rozm->Text = "2";
        if (cr_table->GetTableSize() != 2) {
            Button_cre_table->PerformClick();
        }

        textbox_rozm->Enabled = false;
        label_rozv_sys->Text = "";
        label_kil_iter->Text = "";
    }
    else if (comboBox_meth->SelectedIndex == 1 || comboBox_meth->SelectedIndex == 0 || comboBox_meth->SelectedIndex == 2) {
        textbox_rozm->Enabled = true;
        int n;
        if (Int32::TryParse(textbox_rozm->Text, n)) {
            if (n != cr_table->GetTableSize()) {
                textbox_rozm->Text = cr_table->GetTableSize().ToString();
            }
        }
        else {
            textbox_rozm->Text = cr_table->GetTableSize().ToString();
        }

        chartManager->ClearChart();
        label_per_funcs->Text = "";
        label_rozv_sys->Text = "";
        label_kil_iter->Text = "";
    }
}

void MyProject::MyForm::button_poch_roz_Click(Object^ sender, EventArgs^ e) {
    int n;
    fileManager = gcnew FileManager();
    fileManager->SetFilename("Data.txt");
    
    if (Int32::TryParse(textbox_rozm->Text, n)) {
        if (n != cr_table->GetTableSize()) {
            textbox_rozm->Text = cr_table->GetTableSize().ToString();
        }
    }
    else
    {
        textbox_rozm->Text = cr_table->GetTableSize().ToString();
    }
    fileManager->AppendSysToFile(n, tableLayout_gen);

    if (comboBox_meth->SelectedIndex == 3)
    {

        double a = Double::Parse(safe_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * 0, 0))->Text);
        double b = Double::Parse(safe_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * 1, 0))->Text);
        double c = Double::Parse(safe_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * 2, 0))->Text);
        double d = Double::Parse(safe_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * 0, 1))->Text);
        double eValue = Double::Parse(safe_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * 1, 1))->Text);
        double f = Double::Parse(safe_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * 2, 1))->Text);

        // Перевірка чи правильні коефіцієнти
        if (!((a == 0 && b == 0) || (d == 0 && eValue == 0))) {

            chartManager->PlotChart(a, b, c, d, eValue, f);

            // Перевірка чи перетинаються функції
            if (a * eValue - b * d != 0) {

                double xIntersect, yIntersect;
                if (b == 0) {
                    xIntersect = (b * f - eValue * c) / (d * b - eValue * a);
                    yIntersect = (f - d * xIntersect) / eValue;
                }
                else {
                    xIntersect = (eValue * c - b * f) / (a * eValue - b * d);
                    yIntersect = (c - a * xIntersect) / b;
                }

                xIntersect = System::Math::Round(xIntersect * 100) / 100;
                yIntersect = System::Math::Round(yIntersect * 100) / 100;

                label_per_funcs->Text = "Точка перетину: (" + xIntersect.ToString() + "; " + yIntersect.ToString() + ")";

                fileManager->AppendToFile("Графічне розв'язання");
                System::String^ valueString1 = xIntersect.ToString();
                System::String^ valueString2 = yIntersect.ToString();
                fileManager->AppendToFile(String::Concat("Точка перетину: (", valueString1, "; ", valueString2, ")"));
            }
            else {
                label_per_funcs->Text = "Функції не перетинаються";
                fileManager->AppendToFile("Графічне розв'язання");
                fileManager->AppendToFile("Функції не перетинаються");
            }
        }
        else {
            chartManager->ClearChart();
            label_per_funcs->Text = "Невірно введені коефіцієнти";
            fileManager->AppendToFile("Графічне розв'язання");
            fileManager->AppendToFile("Невірно введені коефіцієнти");
        }
    }
    else {
        int selectedIndex = comboBox_meth->SelectedIndex;
        int n = cr_table->GetTableSize();
        system = gcnew EquationSystem(n, tableLayout_gen);

        // Обирання методу розв'язування в залежності від значення selectedIndex
        if (selectedIndex == 0) {
            system->solveLinearEquations_Cram();
            fileManager->AppendToFile("Метод Крамера");
        }
        else if (selectedIndex == 1) {
            system->solveLinearEquations_Gaus_diag();
            fileManager->AppendToFile("Метод Гауса з одиничною діагоналлю");
        }
        else if (selectedIndex == 2) {
            system->solveLinearEquations_Gaus_golov();
            fileManager->AppendToFile("Метод Гауса з вибором головного елементу");
        }

        cli::array<double>^ solutions = system->GetSolutions();
        int iterations = system->GetIterations();

        if (solutions->Length == 0) {
            label_rozv_sys->Text = "Немає або нескінченна кількість розв'язків";
            label_kil_iter->Text = "Кількість ітерацій: " + iterations;
            fileManager->AppendToFile("Немає або нескінченна кількість розв'язків");
            fileManager->AppendToFile(String::Concat("Кількість ітерацій: ", iterations.ToString()));
        }
        else {
            label_rozv_sys->Text = "Розв'язки: ";
            for (int i = 0; i < cr_table->GetTableSize(); i++) {
                label_rozv_sys->Text += "X" + (i + 1) + ": " + solutions[i] + "  ";
                System::String^ valueString = solutions[i].ToString();
                fileManager->AppendToFile(String::Concat("X", (i + 1).ToString(), ": ", valueString));

            }

            label_kil_iter->Text = "Кількість ітерацій: " + iterations;
            fileManager->AppendToFile(String::Concat("Кількість ітерацій: ", iterations.ToString()));

        }
    }
}

void MyProject::MyForm::Button_cre_table_Click(Object^ sender, EventArgs^ e) {
    label_rozv_sys->Text = "";
    label_kil_iter->Text = "";
    button_poch_roz->Enabled = false;
    button4->Enabled = false;
    cr_table->CreateTable(sender, e);
}

void MyProject::MyForm::button_vid_file_Click(Object^ sender, EventArgs^ e) {
    String^ filePath = "Data.txt";

    // Відкриття файлу в блокноті
    System::Diagnostics::Process::Start("notepad.exe", filePath);
}

void MyProject::MyForm::button_gen_table_Click(System::Object^ sender, System::EventArgs^ e) {
    label_rozv_sys->Text = "";
    label_kil_iter->Text = "";
    button_poch_roz->Enabled = false;
    button4->Enabled = false;
    cr_table->CreateTable(sender, e);



    int n = Convert::ToInt32(textbox_rozm->Text);
    Random^ random = gcnew Random();


    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n + 1; col++)
        {

            double value = random->Next(-100000000, 100000001) / 10000.0;

            TextBox^ textbox = dynamic_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * col, row));


            textbox->Text = value.ToString();

        }
    }
}

void MyProject::MyForm::button_zch_from_file_Click(System::Object^ sender, System::EventArgs^ e) {

    label_rozv_sys->Text = "";
    label_kil_iter->Text = "";
    button_poch_roz->Enabled = false;
    button4->Enabled = false;
    // Перевірка наявності файлу
    if (!System::IO::File::Exists("Input_file.txt")) {
        try {
            // Спробуйте створити новий файл
            System::IO::FileStream^ fs = System::IO::File::Create("Input_file.txt");
            fs->Close();

            // Заповнення файлу стандартними значеннями
            System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter("Input_file.txt");
            writer->WriteLine("2");   // Записати розмір
            writer->WriteLine("1 2 3"); // Записати стандартні значення
            writer->WriteLine("5 6 7"); // Записати стандартні значення
            writer->Close();
            MessageBox::Show("Файл не існує. Створено файл \"Input_file.txt\" та заповнено стандартними значеннями", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (Exception^ ex) {
            // Обробити виняток, якщо сталася помилка при створенні файлу
            MessageBox::Show("Помилка при створенні файлу: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return; // вихід з функції
        }
        
       
    }
    System::IO::StreamReader^ reader = gcnew System::IO::StreamReader("Input_file.txt");


    try {
        int n;
        String^ line = reader->ReadLine();
        if (!Int32::TryParse(line, n)) {
            MessageBox::Show("Некоректне значення 'n' у файлі.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            reader->Close();
            this->Refresh();
            return; // вихід з функції
        }

        textbox_rozm->Text = n.ToString();
        cr_table->CreateTable(sender, e);

        for (int row = 0; row < n; row++) {
            String^ line = reader->ReadLine();
            array<String^>^ values = line->Split(' ');

            if (values->Length != n + 1) {
                MessageBox::Show("Некоректна кількість значень у файлі.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                reader->Close();
                this->Refresh();
                return; // вихід з функції
            }

            for (int col = 0; col < n + 1; col++) {
                double value;
                if (!Double::TryParse(values[col], value)) {
                    MessageBox::Show("Некоректне значення й файллі.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    reader->Close();
                    this->Refresh();
                    return; // вихід з функції
                }

                TextBox^ textbox = dynamic_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * col, row));
                textbox->Text = value.ToString();
            }
        }
        reader->Close();
    }
    catch (System::IO::IOException^ ex) {
        MessageBox::Show("Сталася помилка введення/виведення: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        this->Refresh();
        this->Close();
        MyForm^ newForm = gcnew MyForm();
        newForm->Show();
    }
    
}
void MyProject::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    MyProject::Spravka^ helpForm = gcnew MyProject::Spravka();
    helpForm->Show();

}