#include "FileManager.h"
#include <fstream>

void FileManager::SetFilename(String^ file)
{
    filename = file;
}

void FileManager::AppendSysToFile(int n, TableLayoutPanel^ tableLayout_gen)
{
    int size = n;

    System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(filename, true);

    writer->WriteLine("Коефіцієнти системи: ");
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size+1; col++)
        {
            TextBox^ textbox = dynamic_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * col, row));
            double value = Convert::ToDouble(textbox->Text);
            writer->Write(value.ToString());
            writer->Write(" ");
        }
        writer->WriteLine();
    }

    writer->Close();
}

void FileManager::AppendToFile(String^ content)
{
    System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(filename, true);

    writer->WriteLine(content);
    writer->Close();
}

