#pragma once


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace equationChecker2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	bool go = 0;
	std::ifstream accData;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxJ1Known;
	protected: 
	private: System::Windows::Forms::TextBox^  textBoxJ2Known;
	private: System::Windows::Forms::Label^  labelJ1Known;
	private: System::Windows::Forms::Label^  labelJ2Known;
	private: System::Windows::Forms::Label^  labelAccX;
	private: System::Windows::Forms::Label^  labelAccY;
	private: System::Windows::Forms::Label^  labelAccZ;
	private: System::Windows::Forms::TextBox^  textBoxAccX;
	private: System::Windows::Forms::TextBox^  textBoxAccY;
	private: System::Windows::Forms::TextBox^  textBoxAccZ;
	private: System::Windows::Forms::Label^  labelJ2Test;
	private: System::Windows::Forms::Label^  labelJ1Test;
	private: System::Windows::Forms::TextBox^  textBoxJ2Test;
	private: System::Windows::Forms::TextBox^  textBoxJ1Test;
	private: System::Windows::Forms::Button^  buttonGo;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBoxJ1Known = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ2Known = (gcnew System::Windows::Forms::TextBox());
			this->labelJ1Known = (gcnew System::Windows::Forms::Label());
			this->labelJ2Known = (gcnew System::Windows::Forms::Label());
			this->labelAccX = (gcnew System::Windows::Forms::Label());
			this->labelAccY = (gcnew System::Windows::Forms::Label());
			this->labelAccZ = (gcnew System::Windows::Forms::Label());
			this->textBoxAccX = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAccY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAccZ = (gcnew System::Windows::Forms::TextBox());
			this->labelJ2Test = (gcnew System::Windows::Forms::Label());
			this->labelJ1Test = (gcnew System::Windows::Forms::Label());
			this->textBoxJ2Test = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ1Test = (gcnew System::Windows::Forms::TextBox());
			this->buttonGo = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// textBoxJ1Known
			// 
			this->textBoxJ1Known->Location = System::Drawing::Point(82, 18);
			this->textBoxJ1Known->Name = L"textBoxJ1Known";
			this->textBoxJ1Known->Size = System::Drawing::Size(71, 20);
			this->textBoxJ1Known->TabIndex = 0;
			this->textBoxJ1Known->Text = L"J1 Known";
			// 
			// textBoxJ2Known
			// 
			this->textBoxJ2Known->Location = System::Drawing::Point(82, 44);
			this->textBoxJ2Known->Name = L"textBoxJ2Known";
			this->textBoxJ2Known->Size = System::Drawing::Size(71, 20);
			this->textBoxJ2Known->TabIndex = 1;
			this->textBoxJ2Known->Text = L"J2 Known";
			// 
			// labelJ1Known
			// 
			this->labelJ1Known->AutoSize = true;
			this->labelJ1Known->Location = System::Drawing::Point(22, 21);
			this->labelJ1Known->Name = L"labelJ1Known";
			this->labelJ1Known->Size = System::Drawing::Size(54, 13);
			this->labelJ1Known->TabIndex = 2;
			this->labelJ1Known->Text = L"J1 Known";
			// 
			// labelJ2Known
			// 
			this->labelJ2Known->AutoSize = true;
			this->labelJ2Known->Location = System::Drawing::Point(22, 47);
			this->labelJ2Known->Name = L"labelJ2Known";
			this->labelJ2Known->Size = System::Drawing::Size(54, 13);
			this->labelJ2Known->TabIndex = 3;
			this->labelJ2Known->Text = L"J2 Known";
			// 
			// labelAccX
			// 
			this->labelAccX->AutoSize = true;
			this->labelAccX->Location = System::Drawing::Point(23, 81);
			this->labelAccX->Name = L"labelAccX";
			this->labelAccX->Size = System::Drawing::Size(36, 13);
			this->labelAccX->TabIndex = 4;
			this->labelAccX->Text = L"Acc X";
			// 
			// labelAccY
			// 
			this->labelAccY->AutoSize = true;
			this->labelAccY->Location = System::Drawing::Point(23, 109);
			this->labelAccY->Name = L"labelAccY";
			this->labelAccY->Size = System::Drawing::Size(36, 13);
			this->labelAccY->TabIndex = 5;
			this->labelAccY->Text = L"Acc Y";
			// 
			// labelAccZ
			// 
			this->labelAccZ->AutoSize = true;
			this->labelAccZ->Location = System::Drawing::Point(23, 134);
			this->labelAccZ->Name = L"labelAccZ";
			this->labelAccZ->Size = System::Drawing::Size(36, 13);
			this->labelAccZ->TabIndex = 6;
			this->labelAccZ->Text = L"Acc Z";
			// 
			// textBoxAccX
			// 
			this->textBoxAccX->Location = System::Drawing::Point(82, 78);
			this->textBoxAccX->Name = L"textBoxAccX";
			this->textBoxAccX->Size = System::Drawing::Size(71, 20);
			this->textBoxAccX->TabIndex = 7;
			// 
			// textBoxAccY
			// 
			this->textBoxAccY->Location = System::Drawing::Point(82, 105);
			this->textBoxAccY->Name = L"textBoxAccY";
			this->textBoxAccY->Size = System::Drawing::Size(71, 20);
			this->textBoxAccY->TabIndex = 8;
			// 
			// textBoxAccZ
			// 
			this->textBoxAccZ->Location = System::Drawing::Point(82, 131);
			this->textBoxAccZ->Name = L"textBoxAccZ";
			this->textBoxAccZ->Size = System::Drawing::Size(71, 20);
			this->textBoxAccZ->TabIndex = 9;
			// 
			// labelJ2Test
			// 
			this->labelJ2Test->AutoSize = true;
			this->labelJ2Test->Location = System::Drawing::Point(22, 211);
			this->labelJ2Test->Name = L"labelJ2Test";
			this->labelJ2Test->Size = System::Drawing::Size(42, 13);
			this->labelJ2Test->TabIndex = 13;
			this->labelJ2Test->Text = L"J2 Test";
			// 
			// labelJ1Test
			// 
			this->labelJ1Test->AutoSize = true;
			this->labelJ1Test->Location = System::Drawing::Point(22, 185);
			this->labelJ1Test->Name = L"labelJ1Test";
			this->labelJ1Test->Size = System::Drawing::Size(38, 13);
			this->labelJ1Test->TabIndex = 12;
			this->labelJ1Test->Text = L"J1 test";
			// 
			// textBoxJ2Test
			// 
			this->textBoxJ2Test->Location = System::Drawing::Point(82, 208);
			this->textBoxJ2Test->Name = L"textBoxJ2Test";
			this->textBoxJ2Test->Size = System::Drawing::Size(100, 20);
			this->textBoxJ2Test->TabIndex = 11;
			this->textBoxJ2Test->Text = L"J2 Test";
			// 
			// textBoxJ1Test
			// 
			this->textBoxJ1Test->Location = System::Drawing::Point(82, 182);
			this->textBoxJ1Test->Name = L"textBoxJ1Test";
			this->textBoxJ1Test->Size = System::Drawing::Size(100, 20);
			this->textBoxJ1Test->TabIndex = 10;
			this->textBoxJ1Test->Text = L"J1 Test";
			// 
			// buttonGo
			// 
			this->buttonGo->Location = System::Drawing::Point(197, 21);
			this->buttonGo->Name = L"buttonGo";
			this->buttonGo->Size = System::Drawing::Size(75, 23);
			this->buttonGo->TabIndex = 14;
			this->buttonGo->Text = L"Go";
			this->buttonGo->UseVisualStyleBackColor = true;
			this->buttonGo->Click += gcnew System::EventHandler(this, &Form1::buttonGo_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 3000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->buttonGo);
			this->Controls->Add(this->labelJ2Test);
			this->Controls->Add(this->labelJ1Test);
			this->Controls->Add(this->textBoxJ2Test);
			this->Controls->Add(this->textBoxJ1Test);
			this->Controls->Add(this->textBoxAccZ);
			this->Controls->Add(this->textBoxAccY);
			this->Controls->Add(this->textBoxAccX);
			this->Controls->Add(this->labelAccZ);
			this->Controls->Add(this->labelAccY);
			this->Controls->Add(this->labelAccX);
			this->Controls->Add(this->labelJ2Known);
			this->Controls->Add(this->labelJ1Known);
			this->Controls->Add(this->textBoxJ2Known);
			this->Controls->Add(this->textBoxJ1Known);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void buttonGo_Click(System::Object^  sender, System::EventArgs^  e) {
				 accData.open("acc1.txt");
				 go = 1;
			 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(go)
			 {
				std::string line;
				if(accData.is_open())
				{
					double J1,J2,x,y,z;
					std::getline (accData,line);
					std::istringstream temp(line);
					temp >> J1 >> J2 >> x >> y >> z;
					this->textBoxJ1Known->Text = J1.ToString();
					this->textBoxJ2Known->Text = J2.ToString();
					this->textBoxAccX->Text = x.ToString();
					this->textBoxAccY->Text = y.ToString();
					this->textBoxAccZ->Text = z.ToString();



				}
				else
					go = 0;
			 }
		 }
};
}

