#pragma once

using namespace System::Windows::Forms::DataVisualization::Charting;

ref class ChartManager
{
private:
    Chart^ chart;

public:
    ChartManager(Chart^ chartC);
    void ClearChart(void);
    void PlotChart(double a, double b, double c, double d, double eValue, double f);
};

