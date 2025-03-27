#include "TableCreator.h"

TableCreator::TableCreator(TextBox^ textbox, TableLayoutPanel^ tableLayout, ComboBox^ comboBox, Button^ button, Button^ button2)
{
    textbox_rozm = textbox;
    tableLayout_gen = tableLayout;
    comboBox_meth = comboBox;
    button_poch_roz = button;
    button4= button2;
    tableSize = 0;
}

void TableCreator::CreateTable(Object^ sender, EventArgs^ e)
{
    // �������� �������� ����
    tableLayout_gen->Controls->Clear();
    tableLayout_gen->ColumnStyles->Clear();
    tableLayout_gen->RowStyles->Clear();


    int n = Convert::ToInt32(textbox_rozm->Text);
    tableSize = n;
    int cellWidth = 50;
    int cellHeight = 50;

    // ��������� ����� ����
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n + 1; col++)
        {
            TextBox^ textbox = gcnew TextBox();
            textbox->Width = 60;
            tableLayout_gen->Controls->Add(textbox, 2 * col, row);

            Label^ label = gcnew Label();
            if (col != n - 1 && col != n)
            {
                label->Text = "X" + (col + 1) + "  +";
                label->Width = 40;
                label->Margin = Padding(0, 5, 0, 0);
                tableLayout_gen->Controls->Add(label, 2 * col + 1, row);
            }
            else if (col == n - 1)
            {
                label->Text = "X" + (col + 1) + "  =";
                label->Width = 40;
                label->Margin = Padding(0, 5, 0, 0);
                tableLayout_gen->Controls->Add(label, 2 * col + 1, row);
            }

            textbox->KeyPress += gcnew KeyPressEventHandler(this, &TableCreator::textbox_KeyPress);
            textbox->KeyDown += gcnew KeyEventHandler(this, &TableCreator::textbox_KeyDown);
            textbox->TextChanged += gcnew EventHandler(this, &TableCreator::textbox_TextChanged);
        }
    }
}

int TableCreator::GetTableSize(void)
{
    return tableSize;
}

void TableCreator::textbox_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
    TextBox^ textBox = static_cast<TextBox^>(sender);
    String^ currentText = textBox->Text;
    int cursorPosition = textBox->SelectionStart;
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != '-' && e->KeyChar != '.' && e->KeyChar != ',')
    {
        e->Handled = true; // ��������� �������� 
    }
    else if (e->KeyChar == '-' && ((cursorPosition != 0 && currentText->Length != 0) || currentText->Contains("-")))
    {
        e->Handled = true; // ��������� �������� �����, ���� �� �� � ������ �������� ��� ��� �������� � �����
    }
    else if (e->KeyChar == ',' && (currentText == "-" || currentText->EndsWith("-") || currentText->IndexOf(",") > -1))
    {
        e->Handled = true; // ��������� �������� ����, ���� ���� ������������� ���� ���� ����� ��� ��� �������� � �����
    }
    else if ( (currentText->StartsWith("0") && currentText->Length == 1 ) || ( currentText->StartsWith("-0") && currentText->Length == 2) )
    {

        if (e->KeyChar != 8 && e->KeyChar != ',')
        {
            e->Handled = true; // ��������� ��������, ���� �������� ���������� � "0" ��� "-0" � ���� ���� ��� ������ ���� �����
        }
    }
    else if (currentText->IndexOf(',') > -1)
    {

        int commaIndex = currentText->IndexOf(',');
        if (cursorPosition <= commaIndex) // �������� ������� ������� ����� �����
        {
            int digitsBeforeComma = 0;

            for (int i = 0; i < commaIndex; i++)
            {
                if (Char::IsDigit(currentText[i]))
                {
                    digitsBeforeComma++;
                }
            }

            if (digitsBeforeComma >= 4 && e->KeyChar != 8 && e->KeyChar != '-')
            {
                e->Handled = true; // ��������� ��������, ���� ��� � 4 ����� ����� �����
            }
            if (e->KeyChar == 8 && commaIndex == cursorPosition)
            {

                int digitCountBeforeComma = 0;

                for (int i = commaIndex - 1; i >= 0; i--)
                {
                    if (Char::IsDigit(currentText[i]))
                    {
                        digitCountBeforeComma++;
                    }
                }

                if (digitCountBeforeComma <= 1)
                {
                    e->Handled = true; // ��������� ��������� �����, ���� � ���� ���� ����� ����� �����
                }

            }

        }
        else if (e->KeyChar == 8 && cursorPosition == commaIndex+1)
        {
            // �������� ����� ��� ����
            String^ numberWithoutComma = currentText->Substring(0, commaIndex) + currentText->Substring(commaIndex + 1);
            double value;

            if (Double::TryParse(numberWithoutComma, value) && System::Math::Abs(value) >= 10000)
            {
                e->Handled = true; // ��������� ��������� ����, ���� ����� ��� ���� ����� 10 000 �� �������
            }
        }
        else if (currentText->Substring(commaIndex + 1)->Length >= 6 && e->KeyChar != 8 )
        {
            e->Handled = true; // ��������� ��������, ���� ��� � 6 ��� ����� ���������� �����
        }
    }
    else
    {
        double value;
        if (Double::TryParse(currentText + e->KeyChar, value))
        {
            if (System::Math::Abs(value) >= 10000)
            {
                e->Handled = true; // ��������� ��������, ���� �������� �������� ����� 10 000 �� �������
            }
        }
    }
}

void TableCreator::textbox_KeyDown(Object^ sender, KeyEventArgs^ e)
{
    TextBox^ textBox = static_cast<TextBox^>(sender);
    String^ currentText = textBox->Text;
    int cursorPosition = textBox->SelectionStart; // ��������� ������� �������
    int commaIndex = currentText->IndexOf(','); // ����������� ������� ����

    if (e->KeyCode == Keys::Delete && commaIndex >= 0 && cursorPosition == commaIndex)
    {
        String^ numberWithoutComma = currentText->Remove(commaIndex, 1);

        double value;
        if (Double::TryParse(numberWithoutComma, value) && System::Math::Abs(value) > 10000)
        {
            e->Handled = true; // ��������� ��������� ����, ���� ����� ��� ���� ����� 10 000 
        }
    }
    // �������� ��� ��������� ����� ����� �����
    if (e->KeyCode == Keys::Delete && commaIndex >= 0 && cursorPosition == commaIndex-1)
    {
        int digitCountBeforeComma = 0;

        for (int i = commaIndex - 1; i >= 0; i--)
        {
            if (Char::IsDigit(currentText[i]))
            {
                digitCountBeforeComma++;
            }
        }

        if (digitCountBeforeComma <= 1)
        {
            e->Handled = true; // ���������� ��������� �����, ���� � ����� ���� ����� ����� �����
        }
    }
}

void TableCreator::textbox_TextChanged(Object^ sender, EventArgs^ e)
{
    bool isFieldsEmpty = false;
    int n;
    if (Int32::TryParse(textbox_rozm->Text, n))
    {
        if (n != tableSize)
        {
            textbox_rozm->Text = tableSize.ToString();
        }
    }
    else
    {
        textbox_rozm->Text = tableSize.ToString();
    }

    for (int row = 0; row < tableSize; row++)
    {
        for (int col = 0; col < tableSize + 1; col++)
        {
            TextBox^ textbox = safe_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * col, row));

            if (String::IsNullOrEmpty(textbox->Text) || textbox->Text == "-" || textbox->Text == "-0" || textbox->Text->EndsWith(","))
            {
                isFieldsEmpty = true;
                break;
            }
        }
        if (isFieldsEmpty)
            break;
    }

    button_poch_roz->Enabled = !isFieldsEmpty;
    button4->Enabled = !isFieldsEmpty;
}
