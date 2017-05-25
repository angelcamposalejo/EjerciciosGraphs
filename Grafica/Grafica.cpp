#include "stdafx.h"  //________________________________________ Grafica.cpp
#include "Grafica.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	Grafica app;
	return app.BeginDialog(IDI_Grafica, hInstance);
}

void Grafica::Window_Open(Win::Event& e)
{
	//________________________________________________________ xy1
	xy1.CaptionX = L"Axis X";
	xy1.CaptionY = L"Axis Y";
	xy1.MinX = 0.0;
	xy1.MaxX = 10.0;
	xy1.MinY = -1.0;
	xy1.MaxY = 1.0;
	xy1.Graphs.Add(100);
	for (int i = 0; i<100; i++)
	{
		xy1.Graphs[0][i].x = 0.0;
		xy1.Graphs[0][i].y = 0.0;
	}
	//xy1.Graphs[0].Color = RGB(0, 0, 255);
	//xy1.Graphs[0].Type = Win::Graph::circle;
	//xy1.Graphs[0].Caption = L"My Function";
	xy1.RefreshAll();
}



void Grafica::btPlot_Click(Win::Event& e)
{
	const double minX = this->tbxMinimo.DoubleValue;
	const double maxX = this->tbxMaximo.DoubleValue;
	if (minX >= maxX)return;
	xy1.MinX = minX;
	xy1.MaxX = maxX;
	const double deltaX = (maxX - minX) / 100;
	double x= 0.0;
	for (int i = 0; i < 100; i++)
	{
		x = minX + i*deltaX;
		xy1.Graphs[0][i].x = x;
		xy1.Graphs[0][i].y = ComputeY(x);
	}
	xy1.AutoScaleY();
	xy1.RefreshAll();
}
double Grafica::ComputeY(double x)
{
	wstring sourceCode;
	Sys::Format(sourceCode, L"double x=%g;double y=%s;", x, tbxEntrada.Text.c_str());
	vector<Cpl::Compiler::Instruction>machineCode;
	Cpl::Compiler compiler;
	compiler.Compile(sourceCode.c_str(), machineCode);
	Cpl::VirtualMachine virtualMachine;
	Mt::BoolTs running;
	Mt::DoubleTs progress;
	Mt::BoolTs resetTime;
	virtualMachine.Setup(compiler.variableInfo, machineCode, L"dummy");
	running.Set(true);
	virtualMachine.ThreadFunc(running, progress, resetTime);
	return virtualMachine.memDouble[1];

}

