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
    // Очищення існуючих полів
    tableLayout_gen->Controls->Clear();
    tableLayout_gen->ColumnStyles->Clear();
    tableLayout_gen->RowStyles->Clear();


    int n = Convert::ToInt32(textbox_rozm->Text);
    tableSize = n;
    int cellWidth = 50;
    int cellHeight = 50;

    // Створення нових полів
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
        e->Handled = true; // Скасувати введення 
    }
    else if (e->KeyChar == '-' && ((cursorPosition != 0 && currentText->Length != 0) || currentText->Contains("-")))
    {
        e->Handled = true; // Скасувати введення мінусу, якщо він не є першим символом або вже присутній у рядку
    }
    else if (e->KeyChar == ',' && (currentText == "-" || currentText->EndsWith("-") || currentText->IndexOf(",") > -1))
    {
        e->Handled = true; // Скасувати введення коми, якщо вона безпосередньо слідує після мінусу або вже присутня у рядку
    }
    else if ( (currentText->StartsWith("0") && currentText->Length == 1 ) || ( currentText->StartsWith("-0") && currentText->Length == 2) )
    {

        if (e->KeyChar != 8 && e->KeyChar != ',')
        {
            e->Handled = true; // Скасувати введення, якщо значення починається з "0" або "-0" і немає коми або крапки після нього
        }
    }
    else if (currentText->IndexOf(',') > -1)
    {

        int commaIndex = currentText->IndexOf(',');
        if (cursorPosition <= commaIndex) // Перевірка позиції курсора перед комою
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
                e->Handled = true; // Скасувати введення, якщо вже є 4 цифри перед комою
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
                    e->Handled = true; // Скасувати видалення цифри, якщо є лише одна цифра перед комою
                }

            }

        }
        else if (e->KeyChar == 8 && cursorPosition == commaIndex+1)
        {
            // Отримати число без коми
            String^ numberWithoutComma = currentText->Substring(0, commaIndex) + currentText->Substring(commaIndex + 1);
            double value;

            if (Double::TryParse(numberWithoutComma, value) && System::Math::Abs(value) >= 10000)
            {
                e->Handled = true; // Скасувати видалення коми, якщо число без коми більше 10 000 за модулем
            }
        }
        else if (currentText->Substring(commaIndex + 1)->Length >= 6 && e->KeyChar != 8 )
        {
            e->Handled = true; // Скасувати введення, якщо вже є 6 або більше десяткових знаків
        }
    }
    else
    {
        double value;
        if (Double::TryParse(currentText + e->KeyChar, value))
        {
            if (System::Math::Abs(value) >= 10000)
            {
                e->Handled = true; // Скасувати введення, якщо отримане значення більше 10 000 за модулем
            }
        }
    }
}

void TableCreator::textbox_KeyDown(Object^ sender, KeyEventArgs^ e)
{
    TextBox^ textBox = static_cast<TextBox^>(sender);
    String^ currentText = textBox->Text;
    int cursorPosition = textBox->SelectionStart; // Отримання позиції курсора
    int commaIndex = currentText->IndexOf(','); // Знаходження індексу коми

    if (e->KeyCode == Keys::Delete && commaIndex >= 0 && cursorPosition == commaIndex)
    {
        String^ numberWithoutComma = currentText->Remove(commaIndex, 1);

        double value;
        if (Double::TryParse(numberWithoutComma, value) && System::Math::Abs(value) > 10000)
        {
            e->Handled = true; // Скасувати видалення коми, якщо число без коми більше 10 000 
        }
    }
    // Перевірка для видалення цифри перед комою
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
            e->Handled = true; // Скасування видалення цифри, якщо є тільки одна цифра перед комою
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
