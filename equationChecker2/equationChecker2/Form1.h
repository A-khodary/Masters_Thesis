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




	private: System::Windows::Forms::Button^  buttonGo;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  textBoxUAccZ;

	private: System::Windows::Forms::TextBox^  textBoxUAccY;

	private: System::Windows::Forms::TextBox^  textBoxUAccX;



	private: System::Windows::Forms::Label^  labelKnown;
	private: System::Windows::Forms::Label^  labelUnknown;
	private: System::Windows::Forms::TextBox^  textBoxJ2Unknown;
	private: System::Windows::Forms::TextBox^  textBoxJ1Unknown;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::TextBox^  textBoxZDiff;

	private: System::Windows::Forms::TextBox^  textBoxXDiff;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxJ2Diff;

	private: System::Windows::Forms::TextBox^  textBoxJ1Diff;
	private: System::Windows::Forms::TextBox^  textBoxYDiff;


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
			this->buttonGo = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBoxUAccZ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUAccY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUAccX = (gcnew System::Windows::Forms::TextBox());
			this->labelKnown = (gcnew System::Windows::Forms::Label());
			this->labelUnknown = (gcnew System::Windows::Forms::Label());
			this->textBoxJ2Unknown = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ1Unknown = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBoxZDiff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxXDiff = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxJ2Diff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ1Diff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYDiff = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBoxJ1Known
			// 
			this->textBoxJ1Known->Location = System::Drawing::Point(3, 26);
			this->textBoxJ1Known->Name = L"textBoxJ1Known";
			this->textBoxJ1Known->Size = System::Drawing::Size(100, 20);
			this->textBoxJ1Known->TabIndex = 0;
			this->textBoxJ1Known->Text = L"J1 Known";
			// 
			// textBoxJ2Known
			// 
			this->textBoxJ2Known->Location = System::Drawing::Point(3, 52);
			this->textBoxJ2Known->Name = L"textBoxJ2Known";
			this->textBoxJ2Known->Size = System::Drawing::Size(100, 20);
			this->textBoxJ2Known->TabIndex = 1;
			this->textBoxJ2Known->Text = L"J2 Known";
			// 
			// labelJ1Known
			// 
			this->labelJ1Known->AutoSize = true;
			this->labelJ1Known->Location = System::Drawing::Point(23, 41);
			this->labelJ1Known->Name = L"labelJ1Known";
			this->labelJ1Known->Size = System::Drawing::Size(18, 13);
			this->labelJ1Known->TabIndex = 2;
			this->labelJ1Known->Text = L"J1";
			this->labelJ1Known->Click += gcnew System::EventHandler(this, &Form1::labelJ1Known_Click);
			// 
			// labelJ2Known
			// 
			this->labelJ2Known->AutoSize = true;
			this->labelJ2Known->Location = System::Drawing::Point(23, 67);
			this->labelJ2Known->Name = L"labelJ2Known";
			this->labelJ2Known->Size = System::Drawing::Size(18, 13);
			this->labelJ2Known->TabIndex = 3;
			this->labelJ2Known->Text = L"J2";
			this->labelJ2Known->Click += gcnew System::EventHandler(this, &Form1::labelJ2Known_Click);
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
			this->textBoxAccX->Location = System::Drawing::Point(3, 78);
			this->textBoxAccX->Name = L"textBoxAccX";
			this->textBoxAccX->Size = System::Drawing::Size(100, 20);
			this->textBoxAccX->TabIndex = 7;
			this->textBoxAccX->Text = L"X Known";
			// 
			// textBoxAccY
			// 
			this->textBoxAccY->Location = System::Drawing::Point(3, 105);
			this->textBoxAccY->Name = L"textBoxAccY";
			this->textBoxAccY->Size = System::Drawing::Size(100, 20);
			this->textBoxAccY->TabIndex = 8;
			this->textBoxAccY->Text = L"Y Known";
			// 
			// textBoxAccZ
			// 
			this->textBoxAccZ->Location = System::Drawing::Point(3, 131);
			this->textBoxAccZ->Name = L"textBoxAccZ";
			this->textBoxAccZ->Size = System::Drawing::Size(100, 20);
			this->textBoxAccZ->TabIndex = 9;
			this->textBoxAccZ->Text = L"Z Known";
			// 
			// buttonGo
			// 
			this->buttonGo->Location = System::Drawing::Point(210, 185);
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
			this->textBoxUAccZ->Location = System::Drawing::Point(3, 131);
			this->textBoxUAccZ->Name = L"textBoxUAccZ";
			this->textBoxUAccZ->Size = System::Drawing::Size(100, 20);
			this->textBoxUAccZ->TabIndex = 17;
			this->textBoxUAccZ->Text = L"Z Unknown";
			// 
			// textBoxUAccY
			// 
			this->textBoxUAccY->Location = System::Drawing::Point(3, 105);
			this->textBoxUAccY->Name = L"textBoxUAccY";
			this->textBoxUAccY->Size = System::Drawing::Size(100, 20);
			this->textBoxUAccY->TabIndex = 16;
			this->textBoxUAccY->Text = L"Y Unknown";
			// 
			// textBoxUAccX
			// 
			this->textBoxUAccX->Location = System::Drawing::Point(3, 78);
			this->textBoxUAccX->Name = L"textBoxUAccX";
			this->textBoxUAccX->Size = System::Drawing::Size(100, 20);
			this->textBoxUAccX->TabIndex = 15;
			this->textBoxUAccX->Text = L"X Unknown";
			// 
			// labelKnown
			// 
			this->labelKnown->AutoSize = true;
			this->labelKnown->Location = System::Drawing::Point(34, 8);
			this->labelKnown->Name = L"labelKnown";
			this->labelKnown->Size = System::Drawing::Size(40, 13);
			this->labelKnown->TabIndex = 18;
			this->labelKnown->Text = L"Known";
			// 
			// labelUnknown
			// 
			this->labelUnknown->AutoSize = true;
			this->labelUnknown->Location = System::Drawing::Point(28, 8);
			this->labelUnknown->Name = L"labelUnknown";
			this->labelUnknown->Size = System::Drawing::Size(53, 13);
			this->labelUnknown->TabIndex = 19;
			this->labelUnknown->Text = L"Unknown";
			// 
			// textBoxJ2Unknown
			// 
			this->textBoxJ2Unknown->Location = System::Drawing::Point(3, 52);
			this->textBoxJ2Unknown->Name = L"textBoxJ2Unknown";
			this->textBoxJ2Unknown->Size = System::Drawing::Size(100, 20);
			this->textBoxJ2Unknown->TabIndex = 21;
			this->textBoxJ2Unknown->Text = L"J2 Unknown";
			// 
			// textBoxJ1Unknown
			// 
			this->textBoxJ1Unknown->Location = System::Drawing::Point(3, 26);
			this->textBoxJ1Unknown->Name = L"textBoxJ1Unknown";
			this->textBoxJ1Unknown->Size = System::Drawing::Size(100, 20);
			this->textBoxJ1Unknown->TabIndex = 20;
			this->textBoxJ1Unknown->Text = L"J1 Unknown";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->textBoxAccX);
			this->panel1->Controls->Add(this->textBoxJ1Known);
			this->panel1->Controls->Add(this->textBoxJ2Known);
			this->panel1->Controls->Add(this->textBoxAccY);
			this->panel1->Controls->Add(this->labelKnown);
			this->panel1->Controls->Add(this->textBoxAccZ);
			this->panel1->Location = System::Drawing::Point(65, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(107, 158);
			this->panel1->TabIndex = 22;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->textBoxUAccZ);
			this->panel2->Controls->Add(this->textBoxUAccX);
			this->panel2->Controls->Add(this->labelUnknown);
			this->panel2->Controls->Add(this->textBoxJ2Unknown);
			this->panel2->Controls->Add(this->textBoxJ1Unknown);
			this->panel2->Controls->Add(this->textBoxUAccY);
			this->panel2->Location = System::Drawing::Point(178, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(107, 158);
			this->panel2->TabIndex = 23;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->textBoxZDiff);
			this->panel3->Controls->Add(this->textBoxXDiff);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->textBoxJ2Diff);
			this->panel3->Controls->Add(this->textBoxJ1Diff);
			this->panel3->Controls->Add(this->textBoxYDiff);
			this->panel3->Location = System::Drawing::Point(291, 12);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(166, 158);
			this->panel3->TabIndex = 24;
			// 
			// textBoxZDiff
			// 
			this->textBoxZDiff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxZDiff->Location = System::Drawing::Point(3, 131);
			this->textBoxZDiff->Name = L"textBoxZDiff";
			this->textBoxZDiff->Size = System::Drawing::Size(160, 20);
			this->textBoxZDiff->TabIndex = 17;
			this->textBoxZDiff->Text = L"Z Difference";
			// 
			// textBoxXDiff
			// 
			this->textBoxXDiff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxXDiff->Location = System::Drawing::Point(3, 78);
			this->textBoxXDiff->Name = L"textBoxXDiff";
			this->textBoxXDiff->Size = System::Drawing::Size(160, 20);
			this->textBoxXDiff->TabIndex = 15;
			this->textBoxXDiff->Text = L"X Difference";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Difference";
			// 
			// textBoxJ2Diff
			// 
			this->textBoxJ2Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxJ2Diff->Location = System::Drawing::Point(3, 52);
			this->textBoxJ2Diff->Name = L"textBoxJ2Diff";
			this->textBoxJ2Diff->Size = System::Drawing::Size(160, 20);
			this->textBoxJ2Diff->TabIndex = 21;
			this->textBoxJ2Diff->Text = L"J2 Difference";
			// 
			// textBoxJ1Diff
			// 
			this->textBoxJ1Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxJ1Diff->Location = System::Drawing::Point(3, 26);
			this->textBoxJ1Diff->Name = L"textBoxJ1Diff";
			this->textBoxJ1Diff->Size = System::Drawing::Size(160, 20);
			this->textBoxJ1Diff->TabIndex = 20;
			this->textBoxJ1Diff->Text = L"J1 Difference";
			// 
			// textBoxYDiff
			// 
			this->textBoxYDiff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxYDiff->Location = System::Drawing::Point(3, 105);
			this->textBoxYDiff->Name = L"textBoxYDiff";
			this->textBoxYDiff->Size = System::Drawing::Size(160, 20);
			this->textBoxYDiff->TabIndex = 16;
			this->textBoxYDiff->Text = L"Y Difference";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(469, 235);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->buttonGo);
			this->Controls->Add(this->labelAccZ);
			this->Controls->Add(this->labelAccY);
			this->Controls->Add(this->labelAccX);
			this->Controls->Add(this->labelJ2Known);
			this->Controls->Add(this->labelJ1Known);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
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

	private: void normalizeVector(double &X, double &Y, double &Z)
			 {
				 double temp1,temp2;
				 temp1 = (X*X) + (Y*Y) + (Z*Z);
				 temp2 = sqrt(temp1);
				 X = X/temp2;
				 Y = Y/temp2;
				 Z = Z/temp2;
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

					//normalizeVector(x, y, z);
					addCalibration(x, y, z);
					
					this->textBoxJ1Known->Text = J1.ToString();
					this->textBoxJ2Known->Text = J2.ToString();
					this->textBoxAccX->Text = x.ToString();
					this->textBoxAccY->Text = y.ToString();
					this->textBoxAccZ->Text = z.ToString();

					Matrix J1J2_out;

					double _x, _y, _z, _J1, _J2, _temp, _xDiff, _yDiff, _zDiff, _J1Diff, _J2Diff;

					//Test 3
					_z = -1*sin(J1)*cos(J2);
					_x = sin(J1)*sin(J2);
					_y = cos(J1);
					_x = -1*_x;
					_y = -1*_y;
					this->textBoxUAccX->Text = _x.ToString();
					this->textBoxUAccY->Text = _y.ToString();
					this->textBoxUAccZ->Text = _z.ToString();

					_J2 = atan(x/z);
					_temp = -1*x/sin(_J2);
					_J1 = atan2(_temp, (-1*y));
					this->textBoxJ1Unknown->Text = _J1.ToString();
					this->textBoxJ2Unknown->Text = _J2.ToString();
					

					_xDiff = abs(x - _x);
					_yDiff = abs(y - _y);
					_zDiff = abs(z - _z);
					_J1Diff = abs(J1 - _J1);
					_J2Diff = abs(J2 - _J2);
					this->textBoxXDiff->Text = _xDiff.ToString();
					this->textBoxYDiff->Text = _yDiff.ToString();
					this->textBoxZDiff->Text = _zDiff.ToString();
					this->textBoxJ1Diff->Text = _J1Diff.ToString();
					this->textBoxJ2Diff->Text = _J2Diff.ToString();

					this->textBoxXDiff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_xDiff*2000))));
					this->textBoxYDiff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_yDiff*2000))));
					this->textBoxZDiff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_zDiff*2000))));
					this->textBoxJ1Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_J1Diff*2000))));
					this->textBoxJ2Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_J2Diff*2000))));
					//J1J2_out.Print();
				}
				else
					go = 0;
			 }
		 }
private: System::Void labelJ2Known_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void labelJ1Known_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

