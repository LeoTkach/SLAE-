#pragma once

using namespace System;
using namespace System::Windows::Forms;

ref class EquationSystem
{
private:
    array<array<double>^>^ matrix;
    array<double>^ constants;
    array<double>^ solutions;
    int iterations;

private:
    double determinant(array<array<double>^>^% matrix);

public:
    EquationSystem(int n, TableLayoutPanel^ tableLayout_gen);
    void solveLinearEquations_Cram(void);
    void solveLinearEquations_Gaus_diag(void);
    void solveLinearEquations_Gaus_golov(void);
    array<double>^ GetSolutions(void);
    int GetIterations(void);
};

