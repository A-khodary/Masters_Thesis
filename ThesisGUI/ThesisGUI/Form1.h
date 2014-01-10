#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "matrix.h"

namespace ThesisGUI {

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
	private: System::Windows::Forms::Button^  buttonConnect;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panelKnowns;
	private: System::Windows::Forms::TextBox^  textBoxAccZ;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxJ2Known;
	private: System::Windows::Forms::TextBox^  textBoxJ1Known;
	private: System::Windows::Forms::TextBox^  textBoxAccY;
	private: System::Windows::Forms::TextBox^  textBoxAccX;
	private: System::Windows::Forms::Label^  labelAccZ;
	private: System::Windows::Forms::Label^  labelAccY;
	private: System::Windows::Forms::Label^  labelAccX;
	private: System::Windows::Forms::Label^  labelJ2;
	private: System::Windows::Forms::Label^  labelJ1;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  textBoxJ2Unknown;

	private: System::Windows::Forms::TextBox^  textBoxJ1Unknown;

	private: System::Windows::Forms::Label^  labelUnknown;
	private: System::ComponentModel::IContainer^  components;
	protected: 

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
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelKnowns = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelAccZ = (gcnew System::Windows::Forms::Label());
			this->labelAccY = (gcnew System::Windows::Forms::Label());
			this->labelAccX = (gcnew System::Windows::Forms::Label());
			this->textBoxAccZ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAccY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAccX = (gcnew System::Windows::Forms::TextBox());
			this->labelJ2 = (gcnew System::Windows::Forms::Label());
			this->labelJ1 = (gcnew System::Windows::Forms::Label());
			this->textBoxJ2Known = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ1Known = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->labelUnknown = (gcnew System::Windows::Forms::Label());
			this->textBoxJ2Unknown = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ1Unknown = (gcnew System::Windows::Forms::TextBox());
			this->panelKnowns->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(178, 58);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(75, 23);
			this->buttonConnect->TabIndex = 0;
			this->buttonConnect->Text = L"Connect";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &Form1::buttonConnect_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 3000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// panelKnowns
			// 
			this->panelKnowns->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->panelKnowns->Controls->Add(this->textBoxAccZ);
			this->panelKnowns->Controls->Add(this->label1);
			this->panelKnowns->Controls->Add(this->textBoxJ2Known);
			this->panelKnowns->Controls->Add(this->textBoxJ1Known);
			this->panelKnowns->Controls->Add(this->textBoxAccY);
			this->panelKnowns->Controls->Add(this->textBoxAccX);
			this->panelKnowns->Location = System::Drawing::Point(80, 51);
			this->panelKnowns->Name = L"panelKnowns";
			this->panelKnowns->Size = System::Drawing::Size(77, 170);
			this->panelKnowns->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Knowns";
			// 
			// labelAccZ
			// 
			this->labelAccZ->AutoSize = true;
			this->labelAccZ->Location = System::Drawing::Point(9, 135);
			this->labelAccZ->Name = L"labelAccZ";
			this->labelAccZ->Size = System::Drawing::Size(36, 13);
			this->labelAccZ->TabIndex = 9;
			this->labelAccZ->Text = L"Acc Z";
			// 
			// labelAccY
			// 
			this->labelAccY->AutoSize = true;
			this->labelAccY->Location = System::Drawing::Point(9, 110);
			this->labelAccY->Name = L"labelAccY";
			this->labelAccY->Size = System::Drawing::Size(36, 13);
			this->labelAccY->TabIndex = 8;
			this->labelAccY->Text = L"Acc Y";
			// 
			// labelAccX
			// 
			this->labelAccX->AutoSize = true;
			this->labelAccX->Location = System::Drawing::Point(9, 82);
			this->labelAccX->Name = L"labelAccX";
			this->labelAccX->Size = System::Drawing::Size(36, 13);
			this->labelAccX->TabIndex = 7;
			this->labelAccX->Text = L"Acc X";
			// 
			// textBoxAccZ
			// 
			this->textBoxAccZ->Location = System::Drawing::Point(3, 81);
			this->textBoxAccZ->Name = L"textBoxAccZ";
			this->textBoxAccZ->Size = System::Drawing::Size(71, 20);
			this->textBoxAccZ->TabIndex = 12;
			this->textBoxAccZ->Text = L"Z";
			// 
			// textBoxAccY
			// 
			this->textBoxAccY->Location = System::Drawing::Point(3, 55);
			this->textBoxAccY->Name = L"textBoxAccY";
			this->textBoxAccY->Size = System::Drawing::Size(71, 20);
			this->textBoxAccY->TabIndex = 11;
			this->textBoxAccY->Text = L"Y";
			// 
			// textBoxAccX
			// 
			this->textBoxAccX->Location = System::Drawing::Point(3, 28);
			this->textBoxAccX->Name = L"textBoxAccX";
			this->textBoxAccX->Size = System::Drawing::Size(71, 20);
			this->textBoxAccX->TabIndex = 10;
			this->textBoxAccX->Text = L"X";
			// 
			// labelJ2
			// 
			this->labelJ2->AutoSize = true;
			this->labelJ2->Location = System::Drawing::Point(9, 192);
			this->labelJ2->Name = L"labelJ2";
			this->labelJ2->Size = System::Drawing::Size(18, 13);
			this->labelJ2->TabIndex = 13;
			this->labelJ2->Text = L"J2";
			// 
			// labelJ1
			// 
			this->labelJ1->AutoSize = true;
			this->labelJ1->Location = System::Drawing::Point(9, 166);
			this->labelJ1->Name = L"labelJ1";
			this->labelJ1->Size = System::Drawing::Size(18, 13);
			this->labelJ1->TabIndex = 12;
			this->labelJ1->Text = L"J1";
			// 
			// textBoxJ2Known
			// 
			this->textBoxJ2Known->Location = System::Drawing::Point(3, 138);
			this->textBoxJ2Known->Name = L"textBoxJ2Known";
			this->textBoxJ2Known->Size = System::Drawing::Size(71, 20);
			this->textBoxJ2Known->TabIndex = 11;
			this->textBoxJ2Known->Text = L"J2 Known";
			// 
			// textBoxJ1Known
			// 
			this->textBoxJ1Known->Location = System::Drawing::Point(3, 112);
			this->textBoxJ1Known->Name = L"textBoxJ1Known";
			this->textBoxJ1Known->Size = System::Drawing::Size(71, 20);
			this->textBoxJ1Known->TabIndex = 10;
			this->textBoxJ1Known->Text = L"J1 Known";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->panel1->Controls->Add(this->textBoxJ2Unknown);
			this->panel1->Controls->Add(this->textBoxJ1Unknown);
			this->panel1->Controls->Add(this->labelUnknown);
			this->panel1->Location = System::Drawing::Point(175, 135);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(78, 86);
			this->panel1->TabIndex = 14;
			// 
			// labelUnknown
			// 
			this->labelUnknown->AutoSize = true;
			this->labelUnknown->Location = System::Drawing::Point(13, 12);
			this->labelUnknown->Name = L"labelUnknown";
			this->labelUnknown->Size = System::Drawing::Size(53, 13);
			this->labelUnknown->TabIndex = 20;
			this->labelUnknown->Text = L"Unknown";
			// 
			// textBoxJ2Unknown
			// 
			this->textBoxJ2Unknown->Location = System::Drawing::Point(4, 54);
			this->textBoxJ2Unknown->Name = L"textBoxJ2Unknown";
			this->textBoxJ2Unknown->Size = System::Drawing::Size(71, 20);
			this->textBoxJ2Unknown->TabIndex = 22;
			this->textBoxJ2Unknown->Text = L"J2 Unknown";
			// 
			// textBoxJ1Unknown
			// 
			this->textBoxJ1Unknown->Location = System::Drawing::Point(4, 28);
			this->textBoxJ1Unknown->Name = L"textBoxJ1Unknown";
			this->textBoxJ1Unknown->Size = System::Drawing::Size(71, 20);
			this->textBoxJ1Unknown->TabIndex = 21;
			this->textBoxJ1Unknown->Text = L"J1 Unknown";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(272, 262);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->labelJ2);
			this->Controls->Add(this->labelJ1);
			this->Controls->Add(this->labelAccZ);
			this->Controls->Add(this->labelAccY);
			this->Controls->Add(this->labelAccX);
			this->Controls->Add(this->panelKnowns);
			this->Controls->Add(this->buttonConnect);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->panelKnowns->ResumeLayout(false);
			this->panelKnowns->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonConnect_Click(System::Object^  sender, System::EventArgs^  e) {
				 accData.open("acc1.txt");
				 go = 1;
			 }

	void normalize(double x, double y, double z)
	{
		double X,Y,Z;
		X = x;
		Y = y;
		Z = z;
	
		double norm = sqrt((X*X)+(Y*Y)+(Z*Z));
	
		x = X/norm;
		y = Y/norm;
		z = Z/norm;
	}

	void addCalibration(double x, double y, double z)
	{
		Matrix M = Matrix(3,3);
		Matrix B = Matrix(3,1);
		Matrix data = Matrix(3,1);
		Matrix temp = Matrix(3,1);
	
		B(1,1) = 0.0487;
		B(2,1) = 0.0358;
		B(3,1) = -0.0732;
	
		M(1,1) = 0.9724;
		M(2,1) = 0.0016;
		M(3,1) = -0.0049;
		M(1,2) = 0.0016;
		M(2,2) = 0.9681;
		M(3,2) = -0.0078;
		M(1,3) = -0.0049;
		M(2,3) = -0.0078;
		M(3,3) = 1.0447;
	
		data(1,1) = x;
		data(2,1) = y;
		data(3,1) = z;
		temp = data-B;
		data = M*temp;

		x = data(1,1);
		y = data(2,1);
		z = data(3,1);
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
					addCalibration(x, y, z);
					this->textBoxJ1Known->Text = J1.ToString();
					this->textBoxJ2Known->Text = J2.ToString();
					this->textBoxAccX->Text = x.ToString();
					this->textBoxAccY->Text = y.ToString();
					this->textBoxAccZ->Text = z.ToString();

					double J1_New, J2_New, var1, var2;

					J1_New = acos(y);
					var1 = (z*-1)/sin(J1_New);
					var2 = x/sin(J1_New);
					J2_New = atan2(var1,var2);

					this->textBoxJ1Unknown->Text = J1_New.ToString();
					this->textBoxJ2Unknown->Text = J2_New.ToString();

/*
					Matrix temp_z, J1J2_out;

					temp_z = Matrix(4,1);
					temp_z(1,1) = 0;
					temp_z(2,1) = 0;
					temp_z(3,1) = 1;
					temp_z(4,1) = 0;

					J1J2_out = rotAto2() * rot2to1(J2) * rot1to0(J1) * temp_z;
					
					this->textBoxUAccX->Text = J1J2_out(1,1).ToString();
					this->textBoxUAccY->Text = J1J2_out(2,1).ToString();
					this->textBoxUAccZ->Text = J1J2_out(3,1).ToString();
*/
					//J1J2_out.Print();
				}
				else
					go = 0;
			 }
		 }
};
}

