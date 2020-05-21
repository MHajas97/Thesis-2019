#pragma once
#include <string>
#include <iostream>
#include <fstream>


#include <msclr\marshal_cppstd.h>
namespace JSONtoHTML {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^  tableBtn;
	protected:
	private: System::Windows::Forms::RadioButton^  htmlBtn;
	private: System::Windows::Forms::Button^  browseBtn;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textOut;
	private: System::Windows::Forms::Button^  browse2;
	private: System::Windows::Forms::RadioButton^  singleFile;
	private: System::Windows::Forms::RadioButton^  directoryOpen;
	private: System::Windows::Forms::Button^  okBtn;
			 void startProgram(std::vector<std::string>* input);
			 void startTable(std::vector<std::string>* input);
			 std::ifstream* in;
			 std::ofstream* out;
			 std::vector<std::string>* files;
			 
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::TextBox^  textIn;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->okBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textIn = (gcnew System::Windows::Forms::TextBox());
			this->tableBtn = (gcnew System::Windows::Forms::RadioButton());
			this->htmlBtn = (gcnew System::Windows::Forms::RadioButton());
			this->browseBtn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textOut = (gcnew System::Windows::Forms::TextBox());
			this->browse2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// okBtn
			// 
			this->okBtn->Location = System::Drawing::Point(188, 141);
			this->okBtn->Margin = System::Windows::Forms::Padding(4);
			this->okBtn->Name = L"okBtn";
			this->okBtn->Size = System::Drawing::Size(100, 28);
			this->okBtn->TabIndex = 0;
			this->okBtn->Text = L"translate";
			this->okBtn->UseVisualStyleBackColor = true;
			this->okBtn->Click += gcnew System::EventHandler(this, &MainWindow::okBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 56);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Input";
			// 
			// textIn
			// 
			this->textIn->Location = System::Drawing::Point(74, 53);
			this->textIn->Margin = System::Windows::Forms::Padding(4);
			this->textIn->Name = L"textIn";
			this->textIn->Size = System::Drawing::Size(311, 22);
			this->textIn->TabIndex = 3;
			// 
			// tableBtn
			// 
			this->tableBtn->AutoSize = true;
			this->tableBtn->Location = System::Drawing::Point(190, 83);
			this->tableBtn->Margin = System::Windows::Forms::Padding(4);
			this->tableBtn->Name = L"tableBtn";
			this->tableBtn->Size = System::Drawing::Size(98, 21);
			this->tableBtn->TabIndex = 4;
			this->tableBtn->TabStop = true;
			this->tableBtn->Text = L"Table View";
			this->tableBtn->UseVisualStyleBackColor = true;
			// 
			// htmlBtn
			// 
			this->htmlBtn->AutoSize = true;
			this->htmlBtn->Location = System::Drawing::Point(188, 112);
			this->htmlBtn->Margin = System::Windows::Forms::Padding(4);
			this->htmlBtn->Name = L"htmlBtn";
			this->htmlBtn->Size = System::Drawing::Size(100, 21);
			this->htmlBtn->TabIndex = 5;
			this->htmlBtn->TabStop = true;
			this->htmlBtn->Text = L"HTML View";
			this->htmlBtn->UseVisualStyleBackColor = true;
			// 
			// browseBtn
			// 
			this->browseBtn->Location = System::Drawing::Point(390, 53);
			this->browseBtn->Name = L"browseBtn";
			this->browseBtn->Size = System::Drawing::Size(75, 23);
			this->browseBtn->TabIndex = 6;
			this->browseBtn->Text = L"Browse";
			this->browseBtn->UseVisualStyleBackColor = true;
			this->browseBtn->Click += gcnew System::EventHandler(this, &MainWindow::browseBtn_Click);
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(0, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 23);
			this->label2->TabIndex = 0;
			// 
			// textOut
			// 
			this->textOut->Location = System::Drawing::Point(0, 0);
			this->textOut->Name = L"textOut";
			this->textOut->Size = System::Drawing::Size(100, 22);
			this->textOut->TabIndex = 0;
			// 
			// browse2
			// 
			this->browse2->Location = System::Drawing::Point(0, 0);
			this->browse2->Name = L"browse2";
			this->browse2->Size = System::Drawing::Size(75, 23);
			this->browse2->TabIndex = 0;

			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 182);
			this->Controls->Add(this->directoryOpen);
			this->Controls->Add(this->singleFile);
			this->Controls->Add(this->browseBtn);
			this->Controls->Add(this->htmlBtn);
			this->Controls->Add(this->tableBtn);
			this->Controls->Add(this->textIn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->okBtn);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainWindow";
			this->Text = L"Json to HTML";
			this->ResumeLayout(false);
			this->PerformLayout();
			this->files = new std::vector<std::string>();
		}

#pragma 
	private: System::Void okBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);

		if (textIn->TextLength == 0)
			MessageBox::Show("Please select input File");
		else
		{
				if (htmlBtn->Checked == true)
					startProgram(files);
				else if (tableBtn->Checked == true)
				{
					startTable(files);
				}
				else
					MessageBox::Show("Please select translation mode");
		}
	}


private: System::Void browseBtn_Click(System::Object^  sender, System::EventArgs^  e) 
{	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	{
		msclr::interop::marshal_context context;
		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Multiselect = true;
		openFileDialog1->Filter = "json files (*.json)|*.json|All files (*.*)|*.*";
		openFileDialog1->RestoreDirectory = true;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{

			for each (System::String^ file in openFileDialog1->FileNames)
			{
				std::string standardString = context.marshal_as<std::string>(file);
				if (standardString.empty())
					MessageBox::Show("string null");
				else
				{
					files->push_back(standardString);
					if (openFileDialog1->FileNames->Length > 1)
						textIn->Text = "Multiple Files";
					else
						textIn->Text = file;
				}
			}

		}

	}
}

};

}
