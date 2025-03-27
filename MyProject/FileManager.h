#pragma once

using namespace System;
using namespace System::Windows::Forms;

ref class FileManager
{
private:
    String^ filename;

public:
    void SetFilename(String^ file);
    void AppendSysToFile(int n, TableLayoutPanel^ tableLayout_gen);
    void AppendToFile(String^ content);
};
