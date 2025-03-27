#pragma once

using namespace System;
using namespace System::Windows::Forms;

ref class TableCreator
{
private:
    int tableSize;
    TextBox^ textbox_rozm;
    TableLayoutPanel^ tableLayout_gen;
    ComboBox^ comboBox_meth;
    Button^ button_poch_roz;
    Button^ button4;

public:
    TableCreator(TextBox^ textbox, TableLayoutPanel^ tableLayout, ComboBox^ comboBox, Button^ button, Button^ button2);
    void CreateTable(Object^ sender, EventArgs^ e);
    int GetTableSize(void);

private:
    void textbox_KeyPress(Object^ sender, KeyPressEventArgs^ e);
    void textbox_KeyDown(Object^ sender, KeyEventArgs^ e);
    void textbox_TextChanged(Object^ sender, EventArgs^ e);
};

