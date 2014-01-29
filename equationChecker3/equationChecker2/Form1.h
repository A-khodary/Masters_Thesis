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
	std::ifstream acc1Data, acc2Data, jointData;

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
	private: System::Windows::Forms::Label^  labelAccX1;
	private: System::Windows::Forms::Label^  labelAccY1;
	private: System::Windows::Forms::Label^  labelAccZ1;



	private: System::Windows::Forms::TextBox^  textBoxAccX1;
	private: System::Windows::Forms::TextBox^  textBoxAccY1;
	private: System::Windows::Forms::TextBox^  textBoxAccZ1;







	private: System::Windows::Forms::Button^  buttonGo;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  textBoxUAccZ1;

	private: System::Windows::Forms::TextBox^  textBoxUAccY1;


	private: System::Windows::Forms::TextBox^  textBoxUAccX1;





	private: System::Windows::Forms::Label^  labelKnown;
	private: System::Windows::Forms::Label^  labelUnknown;
	private: System::Windows::Forms::TextBox^  textBoxJ2Unknown;
	private: System::Windows::Forms::TextBox^  textBoxJ1Unknown;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::TextBox^  textBoxZ1Diff;

	private: System::Windows::Forms::TextBox^  textBoxX1Diff;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxJ2Diff;

	private: System::Windows::Forms::TextBox^  textBoxJ1Diff;
	private: System::Windows::Forms::TextBox^  textBoxY1Diff;

	private: System::Windows::Forms::TextBox^  textBoxJ3Known;
	private: System::Windows::Forms::TextBox^  textBoxJ4Known;
	private: System::Windows::Forms::TextBox^  textBoxJ4Unknown;




	private: System::Windows::Forms::TextBox^  textBoxJ3Unknown;

	private: System::Windows::Forms::Label^  labelJ4;

	private: System::Windows::Forms::Label^  labelJ3;
	private: System::Windows::Forms::TextBox^  textBoxJ4Diff;

	private: System::Windows::Forms::TextBox^  textBoxJ3Diff;
	private: System::Windows::Forms::TextBox^  textBoxAccX2;
	private: System::Windows::Forms::TextBox^  textBoxAccY2;
	private: System::Windows::Forms::TextBox^  textBoxAccZ2;




	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBoxUAccZ2;

	private: System::Windows::Forms::TextBox^  textBoxUAccX2;
private: System::Windows::Forms::TextBox^  textBoxUAccY2;
private: System::Windows::Forms::TextBox^  textBoxZ2Diff;





private: System::Windows::Forms::TextBox^  textBoxX2Diff;
private: System::Windows::Forms::TextBox^  textBoxY2Diff;







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
			this->labelAccX1 = (gcnew System::Windows::Forms::Label());
			this->labelAccY1 = (gcnew System::Windows::Forms::Label());
			this->labelAccZ1 = (gcnew System::Windows::Forms::Label());
			this->textBoxAccX1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAccY1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAccZ1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonGo = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBoxUAccZ1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUAccY1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUAccX1 = (gcnew System::Windows::Forms::TextBox());
			this->labelKnown = (gcnew System::Windows::Forms::Label());
			this->labelUnknown = (gcnew System::Windows::Forms::Label());
			this->textBoxJ2Unknown = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ1Unknown = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBoxAccX2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAccY2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAccZ2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ3Known = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ4Known = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBoxUAccZ2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUAccX2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxUAccY2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ4Unknown = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ3Unknown = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBoxZ2Diff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX2Diff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxY2Diff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ4Diff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ3Diff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxZ1Diff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxX1Diff = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxJ2Diff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ1Diff = (gcnew System::Windows::Forms::TextBox());
			this->textBoxY1Diff = (gcnew System::Windows::Forms::TextBox());
			this->labelJ4 = (gcnew System::Windows::Forms::Label());
			this->labelJ3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			// labelAccX1
			// 
			this->labelAccX1->AutoSize = true;
			this->labelAccX1->Location = System::Drawing::Point(23, 142);
			this->labelAccX1->Name = L"labelAccX1";
			this->labelAccX1->Size = System::Drawing::Size(42, 13);
			this->labelAccX1->TabIndex = 4;
			this->labelAccX1->Text = L"Acc1 X";
			// 
			// labelAccY1
			// 
			this->labelAccY1->AutoSize = true;
			this->labelAccY1->Location = System::Drawing::Point(23, 170);
			this->labelAccY1->Name = L"labelAccY1";
			this->labelAccY1->Size = System::Drawing::Size(42, 13);
			this->labelAccY1->TabIndex = 5;
			this->labelAccY1->Text = L"Acc1 Y";
			// 
			// labelAccZ1
			// 
			this->labelAccZ1->AutoSize = true;
			this->labelAccZ1->Location = System::Drawing::Point(23, 195);
			this->labelAccZ1->Name = L"labelAccZ1";
			this->labelAccZ1->Size = System::Drawing::Size(42, 13);
			this->labelAccZ1->TabIndex = 6;
			this->labelAccZ1->Text = L"Acc1 Z";
			// 
			// textBoxAccX1
			// 
			this->textBoxAccX1->Location = System::Drawing::Point(4, 131);
			this->textBoxAccX1->Name = L"textBoxAccX1";
			this->textBoxAccX1->Size = System::Drawing::Size(100, 20);
			this->textBoxAccX1->TabIndex = 7;
			this->textBoxAccX1->Text = L"X1 Known";
			// 
			// textBoxAccY1
			// 
			this->textBoxAccY1->Location = System::Drawing::Point(4, 158);
			this->textBoxAccY1->Name = L"textBoxAccY1";
			this->textBoxAccY1->Size = System::Drawing::Size(100, 20);
			this->textBoxAccY1->TabIndex = 8;
			this->textBoxAccY1->Text = L"Y1 Known";
			// 
			// textBoxAccZ1
			// 
			this->textBoxAccZ1->Location = System::Drawing::Point(4, 184);
			this->textBoxAccZ1->Name = L"textBoxAccZ1";
			this->textBoxAccZ1->Size = System::Drawing::Size(100, 20);
			this->textBoxAccZ1->TabIndex = 9;
			this->textBoxAccZ1->Text = L"Z1 Known";
			// 
			// buttonGo
			// 
			this->buttonGo->Location = System::Drawing::Point(69, 329);
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
			this->timer1->Interval = 5000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// textBoxUAccZ1
			// 
			this->textBoxUAccZ1->Location = System::Drawing::Point(3, 184);
			this->textBoxUAccZ1->Name = L"textBoxUAccZ1";
			this->textBoxUAccZ1->Size = System::Drawing::Size(100, 20);
			this->textBoxUAccZ1->TabIndex = 17;
			this->textBoxUAccZ1->Text = L"Z1 Unknown";
			// 
			// textBoxUAccY1
			// 
			this->textBoxUAccY1->Location = System::Drawing::Point(3, 158);
			this->textBoxUAccY1->Name = L"textBoxUAccY1";
			this->textBoxUAccY1->Size = System::Drawing::Size(100, 20);
			this->textBoxUAccY1->TabIndex = 16;
			this->textBoxUAccY1->Text = L"Y1 Unknown";
			// 
			// textBoxUAccX1
			// 
			this->textBoxUAccX1->Location = System::Drawing::Point(3, 131);
			this->textBoxUAccX1->Name = L"textBoxUAccX1";
			this->textBoxUAccX1->Size = System::Drawing::Size(100, 20);
			this->textBoxUAccX1->TabIndex = 15;
			this->textBoxUAccX1->Text = L"X1 Unknown";
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
			this->panel1->Controls->Add(this->textBoxAccX2);
			this->panel1->Controls->Add(this->textBoxAccY2);
			this->panel1->Controls->Add(this->textBoxAccZ2);
			this->panel1->Controls->Add(this->textBoxJ3Known);
			this->panel1->Controls->Add(this->textBoxJ4Known);
			this->panel1->Controls->Add(this->textBoxAccX1);
			this->panel1->Controls->Add(this->textBoxJ1Known);
			this->panel1->Controls->Add(this->textBoxJ2Known);
			this->panel1->Controls->Add(this->textBoxAccY1);
			this->panel1->Controls->Add(this->labelKnown);
			this->panel1->Controls->Add(this->textBoxAccZ1);
			this->panel1->Location = System::Drawing::Point(65, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(107, 289);
			this->panel1->TabIndex = 22;
			// 
			// textBoxAccX2
			// 
			this->textBoxAccX2->Location = System::Drawing::Point(3, 210);
			this->textBoxAccX2->Name = L"textBoxAccX2";
			this->textBoxAccX2->Size = System::Drawing::Size(100, 20);
			this->textBoxAccX2->TabIndex = 21;
			this->textBoxAccX2->Text = L"X2 Known";
			// 
			// textBoxAccY2
			// 
			this->textBoxAccY2->Location = System::Drawing::Point(3, 237);
			this->textBoxAccY2->Name = L"textBoxAccY2";
			this->textBoxAccY2->Size = System::Drawing::Size(100, 20);
			this->textBoxAccY2->TabIndex = 22;
			this->textBoxAccY2->Text = L"Y2 Known";
			// 
			// textBoxAccZ2
			// 
			this->textBoxAccZ2->Location = System::Drawing::Point(3, 263);
			this->textBoxAccZ2->Name = L"textBoxAccZ2";
			this->textBoxAccZ2->Size = System::Drawing::Size(100, 20);
			this->textBoxAccZ2->TabIndex = 23;
			this->textBoxAccZ2->Text = L"Z2 Known";
			// 
			// textBoxJ3Known
			// 
			this->textBoxJ3Known->Location = System::Drawing::Point(3, 78);
			this->textBoxJ3Known->Name = L"textBoxJ3Known";
			this->textBoxJ3Known->Size = System::Drawing::Size(100, 20);
			this->textBoxJ3Known->TabIndex = 19;
			this->textBoxJ3Known->Text = L"J3 Known";
			// 
			// textBoxJ4Known
			// 
			this->textBoxJ4Known->Location = System::Drawing::Point(3, 104);
			this->textBoxJ4Known->Name = L"textBoxJ4Known";
			this->textBoxJ4Known->Size = System::Drawing::Size(100, 20);
			this->textBoxJ4Known->TabIndex = 20;
			this->textBoxJ4Known->Text = L"J4 Known";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->textBoxUAccZ2);
			this->panel2->Controls->Add(this->textBoxUAccX2);
			this->panel2->Controls->Add(this->textBoxUAccY2);
			this->panel2->Controls->Add(this->textBoxJ4Unknown);
			this->panel2->Controls->Add(this->textBoxJ3Unknown);
			this->panel2->Controls->Add(this->textBoxUAccZ1);
			this->panel2->Controls->Add(this->textBoxUAccX1);
			this->panel2->Controls->Add(this->labelUnknown);
			this->panel2->Controls->Add(this->textBoxJ2Unknown);
			this->panel2->Controls->Add(this->textBoxJ1Unknown);
			this->panel2->Controls->Add(this->textBoxUAccY1);
			this->panel2->Location = System::Drawing::Point(178, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(107, 289);
			this->panel2->TabIndex = 23;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel2_Paint);
			// 
			// textBoxUAccZ2
			// 
			this->textBoxUAccZ2->Location = System::Drawing::Point(4, 263);
			this->textBoxUAccZ2->Name = L"textBoxUAccZ2";
			this->textBoxUAccZ2->Size = System::Drawing::Size(100, 20);
			this->textBoxUAccZ2->TabIndex = 26;
			this->textBoxUAccZ2->Text = L"Z2 Unknown";
			// 
			// textBoxUAccX2
			// 
			this->textBoxUAccX2->Location = System::Drawing::Point(4, 210);
			this->textBoxUAccX2->Name = L"textBoxUAccX2";
			this->textBoxUAccX2->Size = System::Drawing::Size(100, 20);
			this->textBoxUAccX2->TabIndex = 24;
			this->textBoxUAccX2->Text = L"X2 Unknown";
			// 
			// textBoxUAccY2
			// 
			this->textBoxUAccY2->Location = System::Drawing::Point(4, 237);
			this->textBoxUAccY2->Name = L"textBoxUAccY2";
			this->textBoxUAccY2->Size = System::Drawing::Size(100, 20);
			this->textBoxUAccY2->TabIndex = 25;
			this->textBoxUAccY2->Text = L"Y2 Unknown";
			// 
			// textBoxJ4Unknown
			// 
			this->textBoxJ4Unknown->Location = System::Drawing::Point(4, 104);
			this->textBoxJ4Unknown->Name = L"textBoxJ4Unknown";
			this->textBoxJ4Unknown->Size = System::Drawing::Size(100, 20);
			this->textBoxJ4Unknown->TabIndex = 23;
			this->textBoxJ4Unknown->Text = L"J4 Unknown";
			// 
			// textBoxJ3Unknown
			// 
			this->textBoxJ3Unknown->Location = System::Drawing::Point(4, 78);
			this->textBoxJ3Unknown->Name = L"textBoxJ3Unknown";
			this->textBoxJ3Unknown->Size = System::Drawing::Size(100, 20);
			this->textBoxJ3Unknown->TabIndex = 22;
			this->textBoxJ3Unknown->Text = L"J3 Unknown";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->textBoxZ2Diff);
			this->panel3->Controls->Add(this->textBoxX2Diff);
			this->panel3->Controls->Add(this->textBoxY2Diff);
			this->panel3->Controls->Add(this->textBoxJ4Diff);
			this->panel3->Controls->Add(this->textBoxJ3Diff);
			this->panel3->Controls->Add(this->textBoxZ1Diff);
			this->panel3->Controls->Add(this->textBoxX1Diff);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->textBoxJ2Diff);
			this->panel3->Controls->Add(this->textBoxJ1Diff);
			this->panel3->Controls->Add(this->textBoxY1Diff);
			this->panel3->Location = System::Drawing::Point(291, 12);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(107, 289);
			this->panel3->TabIndex = 24;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel3_Paint);
			// 
			// textBoxZ2Diff
			// 
			this->textBoxZ2Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxZ2Diff->Location = System::Drawing::Point(4, 263);
			this->textBoxZ2Diff->Name = L"textBoxZ2Diff";
			this->textBoxZ2Diff->Size = System::Drawing::Size(100, 20);
			this->textBoxZ2Diff->TabIndex = 26;
			this->textBoxZ2Diff->Text = L"Z2 Difference";
			// 
			// textBoxX2Diff
			// 
			this->textBoxX2Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxX2Diff->Location = System::Drawing::Point(4, 210);
			this->textBoxX2Diff->Name = L"textBoxX2Diff";
			this->textBoxX2Diff->Size = System::Drawing::Size(100, 20);
			this->textBoxX2Diff->TabIndex = 24;
			this->textBoxX2Diff->Text = L"X2 Difference";
			// 
			// textBoxY2Diff
			// 
			this->textBoxY2Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxY2Diff->Location = System::Drawing::Point(4, 237);
			this->textBoxY2Diff->Name = L"textBoxY2Diff";
			this->textBoxY2Diff->Size = System::Drawing::Size(100, 20);
			this->textBoxY2Diff->TabIndex = 25;
			this->textBoxY2Diff->Text = L"Y2 Difference";
			// 
			// textBoxJ4Diff
			// 
			this->textBoxJ4Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxJ4Diff->Location = System::Drawing::Point(3, 104);
			this->textBoxJ4Diff->Name = L"textBoxJ4Diff";
			this->textBoxJ4Diff->Size = System::Drawing::Size(100, 20);
			this->textBoxJ4Diff->TabIndex = 23;
			this->textBoxJ4Diff->Text = L"J4 Difference";
			// 
			// textBoxJ3Diff
			// 
			this->textBoxJ3Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxJ3Diff->Location = System::Drawing::Point(3, 78);
			this->textBoxJ3Diff->Name = L"textBoxJ3Diff";
			this->textBoxJ3Diff->Size = System::Drawing::Size(100, 20);
			this->textBoxJ3Diff->TabIndex = 22;
			this->textBoxJ3Diff->Text = L"J3 Difference";
			// 
			// textBoxZ1Diff
			// 
			this->textBoxZ1Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxZ1Diff->Location = System::Drawing::Point(4, 184);
			this->textBoxZ1Diff->Name = L"textBoxZ1Diff";
			this->textBoxZ1Diff->Size = System::Drawing::Size(100, 20);
			this->textBoxZ1Diff->TabIndex = 17;
			this->textBoxZ1Diff->Text = L"Z1 Difference";
			// 
			// textBoxX1Diff
			// 
			this->textBoxX1Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxX1Diff->Location = System::Drawing::Point(4, 131);
			this->textBoxX1Diff->Name = L"textBoxX1Diff";
			this->textBoxX1Diff->Size = System::Drawing::Size(100, 20);
			this->textBoxX1Diff->TabIndex = 15;
			this->textBoxX1Diff->Text = L"X1 Difference";
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
			this->textBoxJ2Diff->Size = System::Drawing::Size(100, 20);
			this->textBoxJ2Diff->TabIndex = 21;
			this->textBoxJ2Diff->Text = L"J2 Difference";
			// 
			// textBoxJ1Diff
			// 
			this->textBoxJ1Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxJ1Diff->Location = System::Drawing::Point(3, 26);
			this->textBoxJ1Diff->Name = L"textBoxJ1Diff";
			this->textBoxJ1Diff->Size = System::Drawing::Size(100, 20);
			this->textBoxJ1Diff->TabIndex = 20;
			this->textBoxJ1Diff->Text = L"J1 Difference";
			// 
			// textBoxY1Diff
			// 
			this->textBoxY1Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBoxY1Diff->Location = System::Drawing::Point(4, 158);
			this->textBoxY1Diff->Name = L"textBoxY1Diff";
			this->textBoxY1Diff->Size = System::Drawing::Size(100, 20);
			this->textBoxY1Diff->TabIndex = 16;
			this->textBoxY1Diff->Text = L"Y1 Difference";
			// 
			// labelJ4
			// 
			this->labelJ4->AutoSize = true;
			this->labelJ4->Location = System::Drawing::Point(23, 119);
			this->labelJ4->Name = L"labelJ4";
			this->labelJ4->Size = System::Drawing::Size(18, 13);
			this->labelJ4->TabIndex = 26;
			this->labelJ4->Text = L"J4";
			// 
			// labelJ3
			// 
			this->labelJ3->AutoSize = true;
			this->labelJ3->Location = System::Drawing::Point(23, 93);
			this->labelJ3->Name = L"labelJ3";
			this->labelJ3->Size = System::Drawing::Size(18, 13);
			this->labelJ3->TabIndex = 25;
			this->labelJ3->Text = L"J3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 278);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 29;
			this->label2->Text = L"Acc2 Z";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 253);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 13);
			this->label3->TabIndex = 28;
			this->label3->Text = L"Acc2 Y";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 225);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 13);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Acc2 X";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(406, 364);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->labelJ4);
			this->Controls->Add(this->labelJ3);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->buttonGo);
			this->Controls->Add(this->labelAccZ1);
			this->Controls->Add(this->labelAccY1);
			this->Controls->Add(this->labelAccX1);
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
				 acc1Data.open("acc1.csv");
				 acc2Data.open("acc2.csv");
				 jointData.open("armValues.csv");
				 go = 1;
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(go)
			 {
				std::string line;
				if(acc1Data.is_open())
				{
					double J1,J2,J3,J4,x1,y1,z1,x2,y2,z2;
					std::getline (acc1Data,line);
					std::istringstream temp(line);
					temp >> x1 >>  y1  >> z1;

					std::getline (acc2Data,line);
					std::istringstream temp2(line);
					temp2 >> x2 >> y2 >> z2;

					std::getline (jointData,line);
					std::istringstream temp3(line);
					temp3 >> J1 >> J2 >> J3 >> J4;

					//normalizeVector(x, y, z);
					addCalibration(x1, y1, z1);
					// NEED TO RECALIBRATE ALL ACCEREMOTERS - DEBUG


					this->textBoxJ1Known->Text = J1.ToString();
					this->textBoxJ2Known->Text = J2.ToString();
					this->textBoxJ3Known->Text = J3.ToString();
					this->textBoxJ4Known->Text = J4.ToString();
					this->textBoxAccX1->Text = x1.ToString();
					this->textBoxAccY1->Text = y1.ToString();
					this->textBoxAccZ1->Text = z1.ToString();
					this->textBoxAccX2->Text = x2.ToString();
					this->textBoxAccY2->Text = y2.ToString();
					this->textBoxAccZ2->Text = z2.ToString();

					Matrix J1J2_out;

					double _x1, _y1, _z1, _x2, _y2, _z2, _J1, _J2, _J3, _J4, _temp, _x1Diff, _y1Diff, _z1Diff, _x2Diff, _y2Diff, _z2Diff, _J1Diff, _J2Diff, _J3Diff, _J4Diff;

					//Check J1 and J2
					_z1 = -1*sin(J1)*cos(J2);
					_x1 = sin(J1)*sin(J2);
					_y1 = cos(J1);
					_x1 = -1*_x1;
					_y1 = -1*_y1;
					this->textBoxUAccX1->Text = _x1.ToString();
					this->textBoxUAccY1->Text = _y1.ToString();
					this->textBoxUAccZ1->Text = _z1.ToString();

					_J2 = atan(x1/z1);
					_temp = -1*x1/sin(_J2);
					_J1 = atan2(_temp, (-1*y1));
					this->textBoxJ1Unknown->Text = _J1.ToString();
					this->textBoxJ2Unknown->Text = _J2.ToString();

					//Check J3 and J4
					_z2 = -1*sin(J3)*cos(J4);
					_x2 = sin(J3)*sin(J4);
					_y2 = cos(J3);
					_z2 = -1*_z2;
					this->textBoxUAccX2->Text = _x2.ToString();
					this->textBoxUAccY2->Text = _y2.ToString();
					this->textBoxUAccZ2->Text = _z2.ToString();

					_J4 = atan(y2/z2);
					_temp = y2*cos(_J1)/cos(_J4);
					_J3 = atan2(_temp, (x2*cos(_J1)));
					this->textBoxJ3Unknown->Text = _J3.ToString();
					this->textBoxJ4Unknown->Text = _J4.ToString();


					
					_x1Diff = abs(x1 - _x1);
					_y1Diff = abs(y1 - _y1);
					_z1Diff = abs(z1 - _z1);
					_x2Diff = abs(x2 - _x2);
					_y2Diff = abs(y2 - _y2);
					_z2Diff = abs(z2 - _z2);
					_J1Diff = abs(J1 - _J1);
					_J2Diff = abs(J2 - _J2);
					_J3Diff = abs(J3 - _J3);
					_J4Diff = abs(J4 - _J4);
					this->textBoxX1Diff->Text = _x1Diff.ToString();
					this->textBoxY1Diff->Text = _y1Diff.ToString();
					this->textBoxZ1Diff->Text = _z1Diff.ToString();
					this->textBoxX2Diff->Text = _x2Diff.ToString();
					this->textBoxY2Diff->Text = _y2Diff.ToString();
					this->textBoxZ2Diff->Text = _z2Diff.ToString();
					this->textBoxJ1Diff->Text = _J1Diff.ToString();
					this->textBoxJ2Diff->Text = _J2Diff.ToString();
					this->textBoxJ3Diff->Text = _J3Diff.ToString();
					this->textBoxJ4Diff->Text = _J4Diff.ToString();

					this->textBoxX1Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_x1Diff*3000))));
					this->textBoxY1Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_y1Diff*3000))));
					this->textBoxZ1Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_z1Diff*3000))));
					this->textBoxX2Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_x2Diff*3000))));
					this->textBoxY2Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_y2Diff*3000))));
					this->textBoxZ2Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_z2Diff*3000))));
					this->textBoxJ1Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_J1Diff*3000))));
					this->textBoxJ2Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_J2Diff*3000))));
					this->textBoxJ3Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_J3Diff*3000))));
					this->textBoxJ4Diff->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255-(_J4Diff*3000))));
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
private: System::Void panel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};
}

