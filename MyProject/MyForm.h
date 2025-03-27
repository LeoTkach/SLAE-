#pragma once
#include "EquationSystem.h"
#include "ChartManager.h"
#include "TableCreator.h"
#include "FileManager.h"
#include "NewForm1.h"
#include "ResultsForm.h"
#include "Zvorot_zv.h"
namespace MyProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Windows::Forms::DataVisualization::Charting;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public Form
    {
    private:
        TextBox^ textbox_rozm;
        Button^ Button_cre_table;
        TableLayoutPanel^ tableLayout_gen;
        Windows::Forms::Label^ label_vve_rozm;
        Button^ button_poch_roz;
        Windows::Forms::Label^ label_ober_meth;
        Chart^ chart;
        Windows::Forms::Label^ label_per_funcs;
        ComboBox^ comboBox_meth;
        Windows::Forms::Label^ label_rozv_sys;
        Windows::Forms::Label^ label_kil_iter;
        System::ComponentModel::Container^ components;
        TableCreator^ cr_table;
        ChartManager^ chartManager;
        EquationSystem^ system;
        Button^ button_vid_file;
    private: System::Windows::Forms::Button^ button_gen_table;
    private: System::Windows::Forms::Button^ button_zch_from_file;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button4;











           FileManager^ fileManager;

    public:
        MyForm(void);

    protected:
        ~MyForm(void);

    private:
        void InitializeComponent(void);
        void textbox_rozm_KeyPress(Object^ sender, KeyPressEventArgs^ e);
        void textbox_rozm_TextChanged(Object^ sender, EventArgs^ e);
        void comboBox_meth_SelectedIndexChanged(Object^ sender, EventArgs^ e);
        void button_poch_roz_Click(Object^ sender, EventArgs^ e);
        void Button_cre_table_Click(Object^ sender, EventArgs^ e);
        void button_vid_file_Click(Object^ sender, EventArgs^ e);
        void button_gen_table_Click(Object^ sender, EventArgs^ e);
        void button_zch_from_file_Click(Object^ sender, EventArgs^ e);
        void button1_Click(System::Object^ sender, System::EventArgs^ e);
        void button4_Click(System::Object^ sender, System::EventArgs^ e) {
            // ���������� ������ �� �����
            int size = cr_table->GetTableSize();
            array<array<double>^>^ matrix = gcnew array<array<double>^>(size);
            array<double>^ constants = gcnew array<double>(size);

            array<String^>^ combinedRows = gcnew array<String^>(size);

            for (int row = 0; row < size; row++) {
                matrix[row] = gcnew array<double>(size);
                String^ rowString = "";
                for (int col = 0; col < size + 1; col++) {
                    TextBox^ textbox = dynamic_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * col, row));
                    if (textbox != nullptr) {
                        double value = Convert::ToDouble(textbox->Text);
                        if (col != size) {
                            matrix[row][col] = value;
                            rowString += value.ToString() + " ";
                        }
                        else {
                            constants[row] = value;
                            rowString += value.ToString(); // ��������� ����������� ��� ������� � �����
                            rowString += " ";
                        }
                    }
                }
                combinedRows[row] = rowString;
            }

            // ����� combinedRows ��� ��������
            String^ debugMessage = "Combined Rows:\n";
            for each (String ^ row in combinedRows) {
                debugMessage += row + "�\n";
            }
            //MessageBox::Show(debugMessage, "��������", MessageBoxButtons::OK, MessageBoxIcon::Information);

            // ���������� ����� ��� ������ ����'����
            String^ filePath = "Data.txt";
            if (!System::IO::File::Exists(filePath)) {
                MessageBox::Show("���� Data.txt �� ��������!", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // ³������� ����� �� ����� ����'����
            System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filePath);
            bool isSolutionFound = false;
            String^ outputMessage = ""; // ����� ��� ������ ����������

            while (!reader->EndOfStream) {
                String^ line = reader->ReadLine();

                // ���������� ����� "����������� �������"
                if (line->StartsWith("����������� �������:")) {
                    // ������� ����������� ������� � �����
                    bool isMatch = true;
                    for (int i = 0; i < size; i++) {
                        if (reader->EndOfStream) {
                            isMatch = false;
                            break;
                        }

                        String^ fileRow = reader->ReadLine();
                        if (combinedRows[i] != fileRow) {
                            isMatch = false;
                            break;
                        }
                    }

                    // ���� �������, ������� ����� ��� ������
                    if (isMatch) {
                        isSolutionFound = true;
                        outputMessage += "����������� �������:\n";
                        for (int i = 0; i < size; i++) {
                            outputMessage += combinedRows[i] + "\n";
                        }

                        // ������� ����� ����� ��� ������ �� ����'����
                        outputMessage += reader->ReadLine() + "\n"; // �����
                        String^ solutionLine;
                        while ((solutionLine = reader->ReadLine()) != nullptr && !solutionLine->StartsWith("����������� �������:")) {
                            outputMessage += solutionLine + "\n";
                        }
                        break;
                    }
                }
            }

            reader->Close();

            // ���� ����'���� ��������, �������� ��, ������ �������� ����������� ��� ���������
            if (isSolutionFound) {
                MessageBox::Show(outputMessage, "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            else {
                MessageBox::Show("����'���� ��� ���� ������� �� �������� � ����!", "���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        MyProject::Zvorot_zv^ zvorotform = gcnew MyProject::Zvorot_zv();
        zvorotform->Show();
    }

    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
        // ���������� ������ �� �����
        int size = cr_table->GetTableSize();
        array<array<double>^>^ matrix = gcnew array<array<double>^>(size);
        array<double>^ constants = gcnew array<double>(size);

        array<String^>^ combinedRows = gcnew array<String^>(size);

        for (int row = 0; row < size; row++) {
            matrix[row] = gcnew array<double>(size);
            String^ rowString = "";
            for (int col = 0; col < size + 1; col++) {
                TextBox^ textbox = dynamic_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * col, row));
                if (textbox != nullptr) {
                    double value = Convert::ToDouble(textbox->Text);
                    if (col != size) {
                        matrix[row][col] = value;
                        rowString += value.ToString() + " ";
                    }
                    else {
                        constants[row] = value;
                        rowString += value.ToString(); // ��������� ����������� ��� ������� � �����
                        rowString += " ";
                    }
                }
            }
            combinedRows[row] = rowString;
        }

        // ����� combinedRows ��� ��������
        String^ debugMessage = "Combined Rows:\n";
        for each (String ^ row in combinedRows) {
            debugMessage += row + "�\n";
        }
        //MessageBox::Show(debugMessage, "��������", MessageBoxButtons::OK, MessageBoxIcon::Information);

        // ���������� ����� ��� ������ ����'����
        String^ filePath = "Data.txt";
        if (!System::IO::File::Exists(filePath)) {
            MessageBox::Show("���� Data.txt �� ��������!", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // ³������� ����� �� ����� ����'����
        System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filePath);
        bool isSolutionFound = false;
        String^ outputMessage = ""; // ����� ��� ������ ����������

        while (!reader->EndOfStream) {
            String^ line = reader->ReadLine();

            // ���������� ����� "����������� �������"
            if (line->StartsWith("����������� �������:")) {
                // ������� ����������� ������� � �����
                bool isMatch = true;
                for (int i = 0; i < size; i++) {
                    if (reader->EndOfStream) {
                        isMatch = false;
                        break;
                    }

                    String^ fileRow = reader->ReadLine();
                    if (combinedRows[i] != fileRow) {
                        isMatch = false;
                        break;
                    }
                }

                // ���� �������, ������� ����� ��� ������
                if (isMatch) {
                    isSolutionFound = true;
                    outputMessage += "����������� �������:\n";
                    for (int i = 0; i < size; i++) {
                        outputMessage += combinedRows[i] + "\n";
                    }

                    // ������� ����� ����� ��� ������ �� ����'����
                    outputMessage += reader->ReadLine() + "\n"; // �����
                    String^ solutionLine;
                    while ((solutionLine = reader->ReadLine()) != nullptr && !solutionLine->StartsWith("����������� �������:")) {
                        outputMessage += solutionLine + "\n";
                    }
                    break;
                }
            }
        }

        reader->Close();

        // ���� ����'���� ��������, �������� ��, ������ �������� ����������� ��� ���������
        if (isSolutionFound) {
            MessageBox::Show(outputMessage, "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            MessageBox::Show("����'���� ��� ���� ������� �� �������� � ����!", "���������", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }



    }

    private: System::Void Button_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
    {
        System::Windows::Forms::Button^ button = dynamic_cast<System::Windows::Forms::Button^>(sender);
        if (button != nullptr && !button->Enabled)
        {
            // ������ ������ ����� � �������������� ������������ ���� ������
            System::Drawing::StringFormat^ format = gcnew System::Drawing::StringFormat();
            format->Alignment = System::Drawing::StringAlignment::Center;
            format->LineAlignment = System::Drawing::StringAlignment::Center;

            // ���������� ����������� ���, �� ����� ���� ������
            e->Graphics->DrawString(
                button->Text,
                button->Font,
                gcnew System::Drawing::SolidBrush(System::Drawing::Color::White), // ����� ���� ������
                button->ClientRectangle,
                format
            );
        }
    }


};


}