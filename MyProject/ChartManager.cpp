#include "ChartManager.h"

ChartManager::ChartManager(Chart^ chartC)
{
    chart = chartC;
}

void ChartManager::ClearChart(void)
{
    chart->Series[0]->Points->Clear();
    chart->Series[1]->Points->Clear();
    chart->Annotations->Clear();
}

void ChartManager::PlotChart(double a, double b, double c, double d, double eValue, double f)
{
    double x, y1, y2;
    double h = 1;

    ClearChart();

    // Знаходження точку перетину
    double minX, maxX, minY, maxY, r;
    double xIntersect, yIntersect;
    if (a * eValue - b * d != 0) {
        if (b == 0) {
            xIntersect = (b * f - eValue * c) / (d * b - eValue * a);
            yIntersect = (f - d * xIntersect) / eValue;
        }
        else {
            xIntersect = (eValue * c - b * f) / (a * eValue - b * d);
            yIntersect = (c - a * xIntersect) / b;
        }
        // Обчислення меж графіка на основі координат точки перетину
        minX = System::Math::Round((xIntersect - 100.0) / 100.0) * 100.0;
        maxX = minX + 200.0;
        minY = System::Math::Round((yIntersect - 100.0) / 100.0) * 100.0;
        maxY = minY + 200.0;
        r = minX - minY;
    }
    else {
        double left_down, right_up;
        if (a == 0 && d == 0) {
            double lineDistance = System::Math::Abs(f / eValue - c / b);
            left_down = 0;
            right_up = System::Math::Min(c / b, f / eValue);

            // Обчислення меж графіка  
            minX = System::Math::Round((0- 100.0) / 100.0) * 100.0;
            maxX = minX  + 200.0;
            minY = System::Math::Round((System::Math::Min(c / b, f / eValue) - 100.0) / 100.0) * 100.0;
            maxY = minY + lineDistance + 200.0;
        }
        else if (b == 0 && eValue == 0) {
            double lineDistance = System::Math::Abs(f/d-c/a);
            left_down = System::Math::Min(c / a, f / d);
            right_up = 0;

            minX = System::Math::Round((System::Math::Min(c / a, f / d) - 100.0) / 100.0) * 100.0;
            maxX = minX + lineDistance + 200.0;
            minY = System::Math::Round((0 - 100.0) / 100.0) * 100.0;
            maxY = minY + 200.0;
        }
        else {
            // Обчислення відстані між прямими за висотою і шириною
            double heightDistance = System::Math::Abs((f - eValue * c / b) / d);
            double widthDistance = System::Math::Abs((f - d * c / a) / eValue);

            // Вибір мінімального значення з відстаней
            double minDistance = System::Math::Min(heightDistance, widthDistance);

            // Обчислення меж графіка з урахуванням мінімальної відстані
            if ((a < 0 && d < 0) ^ (b < 0 && eValue < 0)) {
                minX = System::Math::Round((System::Math::Max(c / a, f / d) - 100.0) / 100.0) * 100.0;
            }
            else {
                minX = System::Math::Round((System::Math::Min(c / a, f / d) - 100.0) / 100.0) * 100.0;
            }
            
            maxX = System::Math::Round((minX + minDistance + 200.0) / 100.0) * 100.0;
            minY = System::Math::Round((0.0 - 100.0) / 100.0) * 100.0;
            maxY = System::Math::Round((minY + minDistance + 200.0) / 100.0) * 100.0;

        }
        r = minX - minY;
    }

    x = minX;

    while (x < maxX)
    {
        if (b == 0 && eValue != 0) {
            y2 = (f - d * x) / eValue;
            chart->Series[0]->Points->AddXY(xIntersect, x - r);
            chart->Series[1]->Points->AddXY(x, y2);
        }
        else if (b != 0 && eValue == 0) {
            y1 = (c - a * x) / b;
            chart->Series[1]->Points->AddXY(xIntersect, x - r);
            chart->Series[0]->Points->AddXY(x, y1);
        }
        else if (b == 0 && eValue == 0) {
            chart->Series[0]->Points->AddXY(c / a, x - r);
            chart->Series[1]->Points->AddXY(f / d, x - r);
        }
        else {
            y1 = (c - a * x) / b;
            y2 = (f - d * x) / eValue;
            chart->Series[0]->Points->AddXY(x, y1);
            chart->Series[1]->Points->AddXY(x, y2);
        }

        x += h;
    }

    // Встановлення меж графіка
    chart->ChartAreas[0]->AxisX->Minimum = minX;
    chart->ChartAreas[0]->AxisX->Maximum = maxX;
    chart->ChartAreas[0]->AxisY->Minimum = minY;
    chart->ChartAreas[0]->AxisY->Maximum = maxY;

    if (!(a == 0 && d == 0) && !(b == 0 && eValue == 0)) {
        // Обчислення інтервалів графіка
        double intervalX = (maxX - minX) / 10.0; 
        double intervalY = (maxY - minY) / 10.0; 

        chart->ChartAreas[0]->AxisX->Interval = intervalX;
        chart->ChartAreas[0]->AxisY->Interval = intervalY;
    }
    else if (a == 0 && d == 0){
        chart->ChartAreas[0]->AxisX->Interval = 20;
        chart->ChartAreas[0]->AxisY->Interval = (maxY - minY) / 10.0;
    }
    else if (b == 0 && eValue == 0) {
        chart->ChartAreas[0]->AxisY->Interval = 20;
        chart->ChartAreas[0]->AxisX->Interval = (maxX - minX) / 10.0;
    }
}
