#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;
System::Windows::Forms::Form;
[STAThread]


void main(array<String^>^ ags) {
	
	ReadNews();
	ReadFromSignup();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew news1::MyForm);

	writesignup();
	writenews();
}