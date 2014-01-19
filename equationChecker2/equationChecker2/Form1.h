#pragma once


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "matrix.h"

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
	private: System::Windows::Forms::TextBox^  textBoxUAccZ;

	private: System::Windows::Forms::TextBox^  textBoxUAccY;

	private: System::Windows::Forms::TextBox^  textBoxUAccX;



	private: System::Windows::Forms::Label^  labelKnown;
	private: System::Windows::Forms::Label^  labelUnknown;
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
			this->textBoxUAccZ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUAccY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUAccX = (gcnew System::Windows::Forms::TextBox());
			this->labelKnown = (gcnew System::Windows::Forms::Label());
			this->labelUnknown = (gcnew System::Windows::Forms::Label());
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
			this->labelAccX->Location = System::Drawing::Point(23, 93);
			this->labelAccX->Name = L"labelAccX";
			this->labelAccX->Size = System::Drawing::Size(36, 13);
			this->labelAccX->TabIndex = 4;
			this->labelAccX->Text = L"Acc X";
			// 
			// labelAccY
			// 
			this->labelAccY->AutoSize = true;
			this->labelAccY->Location = System::Drawing::Point(23, 121);
			this->labelAccY->Name = L"labelAccY";
			this->labelAccY->Size = System::Drawing::Size(36, 13);
			this->labelAccY->TabIndex = 5;
			this->labelAccY->Text = L"Acc Y";
			// 
			// labelAccZ
			// 
			this->labelAccZ->AutoSize = true;
			this->labelAccZ->Location = System::Drawing::Point(23, 146);
			this->labelAccZ->Name = L"labelAccZ";
			this->labelAccZ->Size = System::Drawing::Size(36, 13);
			this->labelAccZ->TabIndex = 6;
			this->labelAccZ->Text = L"Acc Z";
			// 
			// textBoxAccX
			// 
			this->textBoxAccX->Location = System::Drawing::Point(82, 90);
			this->textBoxAccX->Name = L"textBoxAccX";
			this->textBoxAccX->Size = System::Drawing::Size(71, 20);
			this->textBoxAccX->TabIndex = 7;
			this->textBoxAccX->Text = L"X";
			// 
			// textBoxAccY
			// 
			this->textBoxAccY->Location = System::Drawing::Point(82, 117);
			this->textBoxAccY->Name = L"textBoxAccY";
			this->textBoxAccY->Size = System::Drawing::Size(71, 20);
			this->textBoxAccY->TabIndex = 8;
			this->textBoxAccY->Text = L"Y";
			// 
			// textBoxAccZ
			// 
			this->textBoxAccZ->Location = System::Drawing::Point(82, 143);
			this->textBoxAccZ->Name = L"textBoxAccZ";
			this->textBoxAccZ->Size = System::Drawing::Size(71, 20);
			this->textBoxAccZ->TabIndex = 9;
			this->textBoxAccZ->Text = L"Z";
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
			// textBoxUAccZ
			// 
			this->textBoxUAccZ->Location = System::Drawing::Point(201, 143);
			this->textBoxUAccZ->Name = L"textBoxUAccZ";
			this->textBoxUAccZ->Size = System::Drawing::Size(71, 20);
			this->textBoxUAccZ->TabIndex = 17;
			this->textBoxUAccZ->Text = L"Z";
			// 
			// textBoxUAccY
			// 
			this->textBoxUAccY->Location = System::Drawing::Point(201, 117);
			this->textBoxUAccY->Name = L"textBoxUAccY";
			this->textBoxUAccY->Size = System::Drawing::Size(71, 20);
			this->textBoxUAccY->TabIndex = 16;
			this->textBoxUAccY->Text = L"Y";
			// 
			// textBoxUAccX
			// 
			this->textBoxUAccX->Location = System::Drawing::Point(201, 90);
			this->textBoxUAccX->Name = L"textBoxUAccX";
			this->textBoxUAccX->Size = System::Drawing::Size(71, 20);
			this->textBoxUAccX->TabIndex = 15;
			this->textBoxUAccX->Text = L"X";
			// 
			// labelKnown
			// 
			this->labelKnown->AutoSize = true;
			this->labelKnown->Location = System::Drawing::Point(97, 74);
			this->labelKnown->Name = L"labelKnown";
			this->labelKnown->Size = System::Drawing::Size(40, 13);
			this->labelKnown->TabIndex = 18;
			this->labelKnown->Text = L"Known";
			// 
			// labelUnknown
			// 
			this->labelUnknown->AutoSize = true;
			this->labelUnknown->Location = System::Drawing::Point(210, 74);
			this->labelUnknown->Name = L"labelUnknown";
			this->labelUnknown->Size = System::Drawing::Size(53, 13);
			this->labelUnknown->TabIndex = 19;
			this->labelUnknown->Text = L"Unknown";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->labelUnknown);
			this->Controls->Add(this->labelKnown);
			this->Controls->Add(this->textBoxUAccZ);
			this->Controls->Add(this->textBoxUAccY);
			this->Controls->Add(this->textBoxUAccX);
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

	private: bool testEquation(double X, double Y, double Z, double &J1, double &J2){
				 return true;
			 }

	private: Matrix rotAto2()
	{
		Matrix rtn;
		rtn = rotX(1.57) * rotZ(1.57);
		return rtn;
	}

	private: Matrix rotX(double rad)
	{
		Matrix T = Matrix(4,4);
		T(1,1) = 1;
		T(2,1) = 0;
		T(3,1) = 0;
		T(4,1) = 0;
		T(1,2) = 0;
		T(2,2) = cos(rad);
		T(3,2) = sin(rad);
		T(4,2) = 0;
		T(1,3) = 0;
		T(2,3) = (-1)*sin(rad);
		T(3,3) = cos(rad);
		T(4,3) = 0;
		T(1,4) = 0;
		T(2,4) = 0;
		T(3,4) = 0;
		T(4,4) = 1;
		return T;
	}

	private: Matrix rot2to1(double ang)
	{
		Matrix rtn = Diag(4);
		rtn(1,1) = cos(ang);
		rtn(1,2) = -1*sin(ang);
		rtn(1,3) = 0;
		rtn(2,1) = 0;
		rtn(2,2) = 0;
		rtn(2,3) = -1;
		rtn(3,1) = sin(ang);
		rtn(3,2) = cos(ang);
		rtn(3,3) = 0;
	
		Matrix tgt = Inv(rtn);
 	
		return tgt;
	}

	private: Matrix rot1to0(double ang)
	{
		Matrix rtn = Diag(4);
		rtn(1,1) = cos(ang);
		rtn(1,2) = -1*sin(ang);
		rtn(1,3) = 0;
		rtn(2,1) = 0;
		rtn(2,2) = 0;
		rtn(2,3) = 1;
		rtn(3,1) = -1*sin(ang);
		rtn(3,2) = -1*cos(ang);
		rtn(3,3) = 0;
	
		Matrix tgt = Inv(rtn);
 	
		return tgt;
	}

	private: Matrix rotZ(double rad)
	{
		Matrix T = Matrix(4,4);
		T(1,1) = cos(rad);
		T(2,1) = sin(rad);
		T(3,1) = 0;
		T(4,1) = 0;
		T(1,2) = (-1)*sin(rad);
		T(2,2) = cos(rad);
		T(3,2) = 0;
		T(4,2) = 0;
		T(1,3) = 0;
		T(2,3) = 0;
		T(3,3) = 1;
		T(4,3) = 0;
		T(1,4) = 0;
		T(2,4) = 0;
		T(3,4) = 0;
		T(4,4) = 1;
		return T;
	}

	private: void addCalibration(double &X, double &Y, double &Z)
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
	
		data(1,1) = X;
		data(2,1) = Y;
		data(3,1) = Z;
		temp = data-B;
		data = M*temp;

		X = data(1,1);
		Y = data(2,1);
		Z = data(3,1);
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
					addCalibration(x, y, z);
					this->textBoxJ1Known->Text = J1.ToString();
					this->textBoxJ2Known->Text = J2.ToString();
					this->textBoxAccX->Text = x.ToString();
					this->textBoxAccY->Text = y.ToString();
					this->textBoxAccZ->Text = z.ToString();

					Matrix temp_z, J1J2_out;

					temp_z = Matrix(4,1);
					temp_z(1,1) = 0;
					temp_z(2,1) = 0;
					temp_z(3,1) = 1;
					temp_z(4,1) = 0;

					double _x, _y, _z;

					_z = -1*sin(J1)*cos(J2);
					_x = sin(J1)*sin(J2);
					_y = cos(J1);
					this->textBoxUAccX->Text = _x.ToString();
					this->textBoxUAccY->Text = _y.ToString();
					this->textBoxUAccZ->Text = _z.ToString();
					
/*					
					_z = cos(J2)*cos(J1) + sin(J2) - cos(J2)*sin(J1);
					_x = -sin(J2)*cos(J2) + cos(J2) + sin(J2)*sin(J1);
					_y = sin(J1) + cos(J1);
					this->textBoxUAccX->Text = _x.ToString();
					this->textBoxUAccY->Text = _y.ToString();
					this->textBoxUAccZ->Text = _z.ToString();


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

