#include "MyForm.h"
#include <Windows.h>
#include <string>



using namespace Culculator; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

std::string operand;
int operandA, operandB, operat = -1;
bool isFirstOp = true;

void save(int& dist, std::string& source) {
	dist = atoi(operand.c_str());
}

char* intToChar(int num) {
	char* dist = NULL;
	if (num == 0) {
		dist = new char[2]();
		dist[0] = '0';
		return dist;
	}
	int len = 0;
	int copy = num;
	for (int i = 0; i < 6; i++) {
		if (copy % 10 != 0) len = i + 1;
		copy /= 10;
	}
	if (num < 0) {
		dist = new char[++len + 1]();
		dist[0] = '-';
		num = -num;
		for (int i = 0; i < len - 1; i++) {
			dist[len - 1 - i] = num % 10 + 48;
			num /= 10;
		}
	}
	else {
		dist = new char[len + 1]();
		for (int i = 0; i < len; i++) {
			dist[len - 1 - i] = num % 10 + 48;
			num /= 10;
		}
	}
	return dist;
}

System::Void Culculator::MyForm::Num_1_Click(System::Object^ sender, System::EventArgs^ e)
{
	operand += "1";
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::Num_2_Click(System::Object^ sender, System::EventArgs^ e)
{
	operand += "2";
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::Num_3_Click(System::Object^ sender, System::EventArgs^ e)
{
	operand += "3";
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::Num_4_Click(System::Object^ sender, System::EventArgs^ e)
{
	operand += "4";
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::Num_5_Click(System::Object^ sender, System::EventArgs^ e)
{
	operand += "5";
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::Num_6_Click(System::Object^ sender, System::EventArgs^ e)
{
	operand += "6";
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::Num_7_Click(System::Object^ sender, System::EventArgs^ e)
{
	operand += "7";
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::Num_8_Click(System::Object^ sender, System::EventArgs^ e)
{
	operand += "8";
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::Num_9_Click(System::Object^ sender, System::EventArgs^ e)
{
	operand += "9";
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::Num_0_Click(System::Object^ sender, System::EventArgs^ e)
{
	operand += "0";
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::del_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!operand.empty()) operand.erase(operand.size() - 1);
	TextBox->Text = gcnew System::String(operand.c_str());
	return System::Void();
}

System::Void Culculator::MyForm::plus_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (isFirstOp && !operand.empty() && operand != "-") {
		save(operandA, operand);
		operand.clear();
		operat = 0;
		isFirstOp = false;
	}
	return System::Void();
}

System::Void Culculator::MyForm::minus_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (operand.empty()) {
		operand += '-';
		TextBox->Text = gcnew System::String(operand.c_str());
	}
	else if (isFirstOp && operand != "-") {
		save(operandA, operand);
		operand.clear();
		operat = 1;
		isFirstOp = false;
	}
	return System::Void();
}

System::Void Culculator::MyForm::mult_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (isFirstOp && !operand.empty() && operand != "-") {
		save(operandA, operand);
		operand.clear();
		operat = 2;
		isFirstOp = false;
	}
	return System::Void();
}

System::Void Culculator::MyForm::dis_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (isFirstOp && !operand.empty() && operand != "-") {
		save(operandA, operand);
		operand.clear();
		operat = 3;
		isFirstOp = false;
	}
	return System::Void();
}

System::Void Culculator::MyForm::result_Click(System::Object^ sender, System::EventArgs^ e)
{
	save(operandB, operand);
	operand.clear();
	// Заменять от сюда
	std::string out;
	switch (operat) {
	case 0:
		out = std::string(intToChar(operandA + operandB));
		break;
	case 1:
		out = std::string(intToChar(operandA - operandB));
		break;
	case 2:
		out = std::string(intToChar(operandA * operandB));
		break;
	case 3:
		if (operandB != 0) {
			out = std::string(intToChar(operandA / operandB));
		}
		else {
			out = "Error";
		}
		break;
	}
	TextBox->Text = gcnew System::String(out.c_str());
	if (operandB != 0 && operat < 3) operand = out;
	else operand.clear();
	// До сюда
	isFirstOp = true;
	return System::Void();
}

