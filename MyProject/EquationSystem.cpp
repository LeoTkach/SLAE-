#include "EquationSystem.h"

EquationSystem::EquationSystem(int n, TableLayoutPanel^ tableLayout_gen)
{
    int size = n;
    matrix = gcnew array<array<double>^>(size);
    constants = gcnew array<double>(size);
    solutions = gcnew array<double>(size);

    for (int row = 0; row < size; row++)
    {
        matrix[row] = gcnew array<double>(size);
        for (int col = 0; col < size + 1; col++)
        {
            TextBox^ textbox = dynamic_cast<TextBox^>(tableLayout_gen->GetControlFromPosition(2 * col, row));
            if (textbox != nullptr)
            {
                double value = Convert::ToDouble(textbox->Text);
                if (col != size)
                {
                    matrix[row][col] = value;
                }
                else
                {
                    constants[row] = value;
                }
            }
        }
    }
}

double EquationSystem::determinant(array<array<double>^>^% matrix) {
    int n = matrix->Length;
    if (n == 2) {
        iterations++;
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]; 
    }
    else {
        double det = 0.0;
        for (int i = 0; i < n; ++i) {
            array<array<double>^>^ submatrix = gcnew array<array<double>^>(n - 1);
            for (int j = 0; j < n - 1; ++j) {
                submatrix[j] = gcnew array<double>(n - 1);
                for (int k = 0; k < n - 1; ++k) {
                    iterations++;
                    if (j < i) {
                        submatrix[j][k] = matrix[j][k + 1];
                    }
                    else {
                        submatrix[j][k] = matrix[j + 1][k + 1];
                    }
                }
            }
            double dets = determinant(submatrix);
            det += matrix[i][0] * dets * (i % 2 == 0 ? 1 : -1);
        }
        return det;
    }
}

void EquationSystem::solveLinearEquations_Cram(void)
{
    int n = matrix->Length;
    iterations = 0;

    double det = determinant(matrix);

    if (det == 0)
    {
        solutions = gcnew array<double>(0);
        iterations = 0;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        array<array<double>^>^ modifiedMatrix = gcnew array<array<double>^>(n);
        
        for (int j = 0; j < n; j++)
        {
            modifiedMatrix[j] = gcnew array<double>(n);
            for (int k = 0; k < n; k++)
            {
                modifiedMatrix[j][k] = matrix[j][k];
                iterations++;
            }
            modifiedMatrix[j][i] = constants[j];
            
        }
        double detAi = determinant(modifiedMatrix);
        solutions[i] = detAi / det;
        
    }

    for (int i = 0; i < n; i++)
    {
        solutions[i] = System::Math::Round(solutions[i] * 100) / 100; 
    }
}

void EquationSystem::solveLinearEquations_Gaus_diag(void)
{
    int n = matrix->Length;
    iterations = 0;

    double det = determinant(matrix);

    if (det == 0)
    {
        solutions = gcnew array<double>(0);
        iterations = 0;
        return;
    }

    // Прямий хід, приведення матриці до трикутного вигляду
    for (int k = 0; k < n - 1; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            double factor = matrix[i][k] / matrix[k][k];
            for (int j = k; j < n; j++)
            {
                matrix[i][j] -= factor * matrix[k][j];
                iterations++;
            }
            constants[i] -= factor * constants[k];
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (matrix[i][i] == 0)
        {
            solutions = gcnew array<double>(0);
            iterations = 0;
            return;
        }
        // Створення одиничної діагоналі

        double diagonalEl = matrix[i][i];
        for (int j = i; j < n; j++)
        {
            iterations++;
            matrix[i][j] /= diagonalEl;
        }
        constants[i] /= diagonalEl;

    }

    // Зворотній хід, розв'язання сисстеми
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++)
        {
            sum += matrix[i][j] * solutions[j];
            iterations++;
        }
        solutions[i] = (constants[i] - sum);
    }

    for (int i = 0; i < n; i++)
    {
        solutions[i] = System::Math::Round(solutions[i] * 100) / 100;
    }
}

void EquationSystem::solveLinearEquations_Gaus_golov(void)
{
    int n = matrix->Length;
    iterations = 0;

    double det = determinant(matrix);

    if (det == 0)
    {
        solutions = gcnew array<double>(0);
        iterations = 0;
        return;
    }


    for (int i = 0; i < n; i++)
    {
        int maxRow = i;
        double maxVal = System::Math::Abs(matrix[i][i]);

        // Пошук рядка з максимальним абсолютним значенням в поточному стовпці
        for (int k = i + 1; k < n; k++)
        {
            iterations++;
            if (System::Math::Abs(matrix[k][i]) > maxVal)
            {
                maxRow = k;
                maxVal = System::Math::Abs(matrix[k][i]);
            }
        }
        // Зміна місцями рідків, якщо необзідно
        if (maxRow != i)
        {
            // Своп матриць
            for (int j = 0; j < n; j++)
            {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[maxRow][j];
                matrix[maxRow][j] = temp;
                iterations++;
            }

            // Своп вільних членів
            double temp = constants[i];
            constants[i] = constants[maxRow];
            constants[maxRow] = temp;
        }

        // Приведення матриці до трикутного вигляду
        for (int j = i + 1; j < n; j++)
        {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++)
            {
                matrix[j][k] -= factor * matrix[i][k];
                iterations++;
            }
            constants[j] -= factor * constants[i];
        }
    }   


    // Зворотній хід
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++)
        {
            sum += matrix[i][j] * solutions[j];
            iterations++;
        }
        solutions[i] = (constants[i] - sum) / matrix[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        solutions[i] = System::Math::Round(solutions[i] * 100) / 100; 
    }
}

array<double>^ EquationSystem::GetSolutions(void)
{
    return solutions;
}

int EquationSystem::GetIterations(void)
{
    return iterations;
}