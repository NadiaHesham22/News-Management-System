#pragma once
#pragma warning(disable : 4996)
#include<queue>
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<ctime>
#include<msclr\marshal_cppstd.h>
#include<vector>
#include <Windows.h>
#include<deque>
#include<unordered_map>
#include<map>
#include<set>
#include <sstream>


using std::endl;
using std::ofstream;
using std::string;
using std::ifstream;
using std::fstream;
using std::vector;
using std::getline;
using std::queue;
using::std::deque;
using::std::unordered_map;
std::fstream myFile;
using::std::map;
using::std::set;

struct personInfo
{
	string name;
	string password;
};
struct News
{
	string title;
	string category;
	string desccription;
	string date;
	float avg = 0;
	int rate = 0;
	int usersRated = 0;
};



deque<News> news_deque;
unordered_map<string, deque<News>> category_map;
map <float, deque<News>> avgRate_map;
News news_object;
unordered_map<string,personInfo> info_map;
personInfo info_object;
deque <News>::iterator dqit;





void ReadFromSignup() {
	std::ifstream thefile("signup.txt");
	std::string username, password;
	while (thefile >> username >> password) {
		personInfo info_object;
		info_object.name = username;
		info_object.password = password;
		info_map[username] = info_object;
	}
	thefile.close();
}



void ReadNews()
{
	ifstream thefile("News.txt");
	string title, description, date, category;
	int rate, userRated;
	float avg;
	//std::set<std::string> categories;
	while (getline(thefile, title))
	{
		getline(thefile, category);
		getline(thefile, description);
		getline(thefile, date);
		thefile >> avg >> rate >> userRated;
		News news_object{ title, category, description, date, avg, rate, userRated };
		news_deque.push_back(news_object);
		category_map[category].push_back(news_object);
		avgRate_map[avg].push_back(news_object);
		thefile.ignore();
		//categories.insert(category);
	}
	thefile.close();
}


void writenews()
{
	ofstream thefile_out("News.txt");
	for (const auto& news_obj : news_deque) {
		thefile_out << news_obj.title << endl << news_obj.category << endl << news_obj.desccription << endl;
		for (char c : news_obj.date) {
			if (c != ' ') {
				thefile_out.put(c);
			}
		}
		thefile_out << endl << news_obj.avg << endl << news_obj.rate << endl << news_obj.usersRated;
		//<< " " << news_obj.category
		thefile_out << endl;
	}
	thefile_out.close();
}


void writesignup() {
	ofstream thefile("signup.txt");
	if (thefile.is_open())
	{
		for (const auto& entry : info_map)
		{
			thefile << entry.second.name << ' ' << entry.second.password << '\n';
		}
	}
	thefile.close();
}

namespace news1 {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ TitleHeader;
	protected:

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;







	private: System::Windows::Forms::Panel^ LoginSignup;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ passwordLogin;

	private: System::Windows::Forms::TextBox^ usernameLogin;

	private: System::Windows::Forms::Panel^ Signup;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ passwordSignup;

	private: System::Windows::Forms::TextBox^ usernameSignup;

	private: System::Windows::Forms::Panel^ HomepageAdmin;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Panel^ HomePageUser;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ AddNews;

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Label^ titlenewslabel;
	private: System::Windows::Forms::Label^ descriptionnewslabel;


	private: System::Windows::Forms::RichTextBox^ titlerichtextbox;
	private: System::Windows::Forms::RichTextBox^ descriptionrichtextbox;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ datelabel;
	private: System::Windows::Forms::Button^ addnewsbutton;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Panel^ newsfeed;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button21;

	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Panel^ Ratenews;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::TextBox^ indexrate;



	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ removenews;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button28;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::TextBox^ indexewmovebox;

	private: System::Windows::Forms::Panel^ addcategory;
	private: System::Windows::Forms::TextBox^ addcategorytextbox;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button34;




	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::Button^ button36;
	private: System::Windows::Forms::Button^ button37;
	private: System::Windows::Forms::Button^ button38;
	private: System::Windows::Forms::Button^ button39;
	private: System::Windows::Forms::Panel^ updatenews;
	private: System::Windows::Forms::TextBox^ indexnewsupdate;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Button^ button40;




	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Button^ button41;
	private: System::Windows::Forms::Button^ button42;
	private: System::Windows::Forms::Button^ button43;
	private: System::Windows::Forms::Button^ button44;
	private: System::Windows::Forms::Button^ button45;
	private: System::Windows::Forms::TextBox^ updatedDescription;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::TextBox^ updatedTitle;
	private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Button^ button46;
private: System::Windows::Forms::Button^ button47;
private: System::Windows::Forms::Panel^ showratednews;
private: System::Windows::Forms::RichTextBox^ richTextBox2;
private: System::Windows::Forms::Button^ button48;
private: System::Windows::Forms::Panel^ panel10;
private: System::Windows::Forms::Button^ button49;
private: System::Windows::Forms::Button^ button50;
private: System::Windows::Forms::Button^ button51;
private: System::Windows::Forms::Button^ button52;
private: System::Windows::Forms::Button^ button53;
private: System::Windows::Forms::Button^ button54;
private: System::Windows::Forms::Panel^ displaycategory;
private: System::Windows::Forms::Panel^ panel11;
private: System::Windows::Forms::Button^ button55;
private: System::Windows::Forms::Button^ button56;
private: System::Windows::Forms::Button^ button57;
private: System::Windows::Forms::Button^ button58;
private: System::Windows::Forms::Button^ button59;
private: System::Windows::Forms::Label^ label21;


private: System::Windows::Forms::Button^ button60;
private: System::Windows::Forms::RichTextBox^ richTextBox3;






private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::Button^ button61;


























	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->TitleHeader = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->LoginSignup = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->passwordLogin = (gcnew System::Windows::Forms::TextBox());
			this->usernameLogin = (gcnew System::Windows::Forms::TextBox());
			this->Signup = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->passwordSignup = (gcnew System::Windows::Forms::TextBox());
			this->usernameSignup = (gcnew System::Windows::Forms::TextBox());
			this->HomepageAdmin = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->HomePageUser = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button46 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->AddNews = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->addnewsbutton = (gcnew System::Windows::Forms::Button());
			this->datelabel = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->descriptionrichtextbox = (gcnew System::Windows::Forms::RichTextBox());
			this->descriptionnewslabel = (gcnew System::Windows::Forms::Label());
			this->titlerichtextbox = (gcnew System::Windows::Forms::RichTextBox());
			this->titlenewslabel = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->newsfeed = (gcnew System::Windows::Forms::Panel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button54 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->Ratenews = (gcnew System::Windows::Forms::Panel());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->indexrate = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button47 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->removenews = (gcnew System::Windows::Forms::Panel());
			this->indexewmovebox = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->addcategory = (gcnew System::Windows::Forms::Panel());
			this->addcategorytextbox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->updatenews = (gcnew System::Windows::Forms::Panel());
			this->updatedDescription = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->updatedTitle = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->indexnewsupdate = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->button43 = (gcnew System::Windows::Forms::Button());
			this->button44 = (gcnew System::Windows::Forms::Button());
			this->button45 = (gcnew System::Windows::Forms::Button());
			this->showratednews = (gcnew System::Windows::Forms::Panel());
			this->button61 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button48 = (gcnew System::Windows::Forms::Button());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->button49 = (gcnew System::Windows::Forms::Button());
			this->button50 = (gcnew System::Windows::Forms::Button());
			this->button51 = (gcnew System::Windows::Forms::Button());
			this->button52 = (gcnew System::Windows::Forms::Button());
			this->button53 = (gcnew System::Windows::Forms::Button());
			this->displaycategory = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->button60 = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->button55 = (gcnew System::Windows::Forms::Button());
			this->button56 = (gcnew System::Windows::Forms::Button());
			this->button57 = (gcnew System::Windows::Forms::Button());
			this->button58 = (gcnew System::Windows::Forms::Button());
			this->button59 = (gcnew System::Windows::Forms::Button());
			this->TitleHeader->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->LoginSignup->SuspendLayout();
			this->Signup->SuspendLayout();
			this->HomepageAdmin->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			this->HomePageUser->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel3->SuspendLayout();
			this->AddNews->SuspendLayout();
			this->panel4->SuspendLayout();
			this->newsfeed->SuspendLayout();
			this->panel5->SuspendLayout();
			this->Ratenews->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->panel6->SuspendLayout();
			this->removenews->SuspendLayout();
			this->panel7->SuspendLayout();
			this->addcategory->SuspendLayout();
			this->panel8->SuspendLayout();
			this->updatenews->SuspendLayout();
			this->panel9->SuspendLayout();
			this->showratednews->SuspendLayout();
			this->panel10->SuspendLayout();
			this->displaycategory->SuspendLayout();
			this->panel11->SuspendLayout();
			this->SuspendLayout();
			// 
			// TitleHeader
			// 
			this->TitleHeader->BackColor = System::Drawing::Color::Maroon;
			this->TitleHeader->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->TitleHeader->Controls->Add(this->label1);
			this->TitleHeader->Controls->Add(this->pictureBox1);
			this->TitleHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->TitleHeader->Location = System::Drawing::Point(0, 0);
			this->TitleHeader->Name = L"TitleHeader";
			this->TitleHeader->Size = System::Drawing::Size(1182, 103);
			this->TitleHeader->TabIndex = 0;
			this->TitleHeader->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::TitleHeader_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Agency FB", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Linen;
			this->label1->Location = System::Drawing::Point(269, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(289, 52);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Events Newspaper";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(170, 17);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(87, 69);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// LoginSignup
			// 
			this->LoginSignup->Controls->Add(this->label6);
			this->LoginSignup->Controls->Add(this->button2);
			this->LoginSignup->Controls->Add(this->button1);
			this->LoginSignup->Controls->Add(this->label3);
			this->LoginSignup->Controls->Add(this->label2);
			this->LoginSignup->Controls->Add(this->passwordLogin);
			this->LoginSignup->Controls->Add(this->usernameLogin);
			this->LoginSignup->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LoginSignup->Location = System::Drawing::Point(0, 103);
			this->LoginSignup->Name = L"LoginSignup";
			this->LoginSignup->Size = System::Drawing::Size(1182, 650);
			this->LoginSignup->TabIndex = 10;
			this->LoginSignup->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(406, 306);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 29);
			this->label6->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(699, 409);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(181, 109);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Signup";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(247, 403);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 115);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(179, 215);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(155, 36);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Password:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(176, 111);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(158, 36);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Username:";
			// 
			// passwordLogin
			// 
			this->passwordLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordLogin->Location = System::Drawing::Point(530, 228);
			this->passwordLogin->Name = L"passwordLogin";
			this->passwordLogin->Size = System::Drawing::Size(226, 30);
			this->passwordLogin->TabIndex = 1;
			// 
			// usernameLogin
			// 
			this->usernameLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameLogin->Location = System::Drawing::Point(530, 123);
			this->usernameLogin->Name = L"usernameLogin";
			this->usernameLogin->Size = System::Drawing::Size(226, 30);
			this->usernameLogin->TabIndex = 0;
			// 
			// Signup
			// 
			this->Signup->Controls->Add(this->button3);
			this->Signup->Controls->Add(this->label4);
			this->Signup->Controls->Add(this->label5);
			this->Signup->Controls->Add(this->passwordSignup);
			this->Signup->Controls->Add(this->usernameSignup);
			this->Signup->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Signup->Location = System::Drawing::Point(0, 103);
			this->Signup->Name = L"Signup";
			this->Signup->Size = System::Drawing::Size(1182, 650);
			this->Signup->TabIndex = 11;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(506, 477);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(164, 64);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Signup";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(251, 317);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(155, 36);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Password:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(251, 181);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(158, 36);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Username:";
			// 
			// passwordSignup
			// 
			this->passwordSignup->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordSignup->Location = System::Drawing::Point(576, 331);
			this->passwordSignup->Name = L"passwordSignup";
			this->passwordSignup->Size = System::Drawing::Size(201, 30);
			this->passwordSignup->TabIndex = 1;
			// 
			// usernameSignup
			// 
			this->usernameSignup->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameSignup->Location = System::Drawing::Point(576, 181);
			this->usernameSignup->Name = L"usernameSignup";
			this->usernameSignup->Size = System::Drawing::Size(201, 30);
			this->usernameSignup->TabIndex = 0;
			// 
			// HomepageAdmin
			// 
			this->HomepageAdmin->Controls->Add(this->pictureBox2);
			this->HomepageAdmin->Controls->Add(this->panel1);
			this->HomepageAdmin->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HomepageAdmin->Location = System::Drawing::Point(0, 103);
			this->HomepageAdmin->Name = L"HomepageAdmin";
			this->HomepageAdmin->Size = System::Drawing::Size(1182, 650);
			this->HomepageAdmin->TabIndex = 12;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1182, 541);
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click_1);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Maroon;
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 541);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1182, 109);
			this->panel1->TabIndex = 5;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint_1);
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::Linen;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.Image")));
			this->button8->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button8->Location = System::Drawing::Point(676, 1);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(246, 104);
			this->button8->TabIndex = 4;
			this->button8->Text = L"Update News";
			this->button8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::Linen;
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			this->button7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->Location = System::Drawing::Point(428, 3);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(242, 102);
			this->button7->TabIndex = 3;
			this->button7->Text = L"Remove News";
			this->button7->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::Linen;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->Location = System::Drawing::Point(928, 0);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(251, 105);
			this->button6->TabIndex = 2;
			this->button6->Text = L"Add categories";
			this->button6->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Linen;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->Location = System::Drawing::Point(211, 1);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(211, 104);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Add News";
			this->button5->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Linen;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(3, 1);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(202, 104);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Logout";
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// HomePageUser
			// 
			this->HomePageUser->Controls->Add(this->pictureBox3);
			this->HomePageUser->Controls->Add(this->panel3);
			this->HomePageUser->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HomePageUser->Location = System::Drawing::Point(0, 103);
			this->HomePageUser->Name = L"HomePageUser";
			this->HomePageUser->Size = System::Drawing::Size(1182, 650);
			this->HomePageUser->TabIndex = 13;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox3->Location = System::Drawing::Point(0, 0);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(1182, 541);
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Maroon;
			this->panel3->Controls->Add(this->button46);
			this->panel3->Controls->Add(this->button10);
			this->panel3->Controls->Add(this->button11);
			this->panel3->Controls->Add(this->button12);
			this->panel3->Controls->Add(this->button13);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 541);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1182, 109);
			this->panel3->TabIndex = 5;
			// 
			// button46
			// 
			this->button46->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button46->ForeColor = System::Drawing::Color::Linen;
			this->button46->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button46.Image")));
			this->button46->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button46->Location = System::Drawing::Point(1, 3);
			this->button46->Name = L"button46";
			this->button46->Size = System::Drawing::Size(197, 104);
			this->button46->TabIndex = 4;
			this->button46->Text = L"Log out";
			this->button46->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button46->UseVisualStyleBackColor = true;
			this->button46->Click += gcnew System::EventHandler(this, &MyForm::button46_Click);
			// 
			// button10
			// 
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::Color::Linen;
			this->button10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button10.Image")));
			this->button10->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button10->Location = System::Drawing::Point(665, 5);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(271, 102);
			this->button10->TabIndex = 3;
			this->button10->Text = L"Show rated News";
			this->button10->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::Color::Linen;
			this->button11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button11.Image")));
			this->button11->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button11->Location = System::Drawing::Point(932, 2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(251, 105);
			this->button11->TabIndex = 2;
			this->button11->Text = L"Categories";
			this->button11->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::Color::Linen;
			this->button12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button12.Image")));
			this->button12->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button12->Location = System::Drawing::Point(416, 3);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(249, 104);
			this->button12->TabIndex = 1;
			this->button12->Text = L" News Feed";
			this->button12->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::Color::Linen;
			this->button13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button13.Image")));
			this->button13->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button13->Location = System::Drawing::Point(196, 2);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(222, 104);
			this->button13->TabIndex = 0;
			this->button13->Text = L"Rate News";
			this->button13->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// AddNews
			// 
			this->AddNews->Controls->Add(this->textBox1);
			this->AddNews->Controls->Add(this->label8);
			this->AddNews->Controls->Add(this->label7);
			this->AddNews->Controls->Add(this->addnewsbutton);
			this->AddNews->Controls->Add(this->datelabel);
			this->AddNews->Controls->Add(this->dateTimePicker1);
			this->AddNews->Controls->Add(this->descriptionrichtextbox);
			this->AddNews->Controls->Add(this->descriptionnewslabel);
			this->AddNews->Controls->Add(this->titlerichtextbox);
			this->AddNews->Controls->Add(this->titlenewslabel);
			this->AddNews->Controls->Add(this->panel4);
			this->AddNews->Dock = System::Windows::Forms::DockStyle::Fill;
			this->AddNews->Location = System::Drawing::Point(0, 103);
			this->AddNews->Name = L"AddNews";
			this->AddNews->Size = System::Drawing::Size(1182, 650);
			this->AddNews->TabIndex = 14;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(304, 358);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(278, 41);
			this->textBox1->TabIndex = 17;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(74, 364);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(152, 36);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Category:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(480, 403);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 29);
			this->label7->TabIndex = 13;
			// 
			// addnewsbutton
			// 
			this->addnewsbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addnewsbutton->Location = System::Drawing::Point(428, 443);
			this->addnewsbutton->Name = L"addnewsbutton";
			this->addnewsbutton->Size = System::Drawing::Size(269, 75);
			this->addnewsbutton->TabIndex = 12;
			this->addnewsbutton->Text = L"Add News";
			this->addnewsbutton->UseVisualStyleBackColor = true;
			this->addnewsbutton->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// datelabel
			// 
			this->datelabel->AutoSize = true;
			this->datelabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datelabel->Location = System::Drawing::Point(67, 281);
			this->datelabel->Name = L"datelabel";
			this->datelabel->Size = System::Drawing::Size(89, 36);
			this->datelabel->TabIndex = 11;
			this->datelabel->Text = L"Date:";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(314, 290);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(246, 22);
			this->dateTimePicker1->TabIndex = 10;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker1_ValueChanged);
			// 
			// descriptionrichtextbox
			// 
			this->descriptionrichtextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->descriptionrichtextbox->Location = System::Drawing::Point(312, 104);
			this->descriptionrichtextbox->Name = L"descriptionrichtextbox";
			this->descriptionrichtextbox->Size = System::Drawing::Size(838, 147);
			this->descriptionrichtextbox->TabIndex = 9;
			this->descriptionrichtextbox->Text = L"";
			// 
			// descriptionnewslabel
			// 
			this->descriptionnewslabel->AutoSize = true;
			this->descriptionnewslabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descriptionnewslabel->Location = System::Drawing::Point(60, 152);
			this->descriptionnewslabel->Name = L"descriptionnewslabel";
			this->descriptionnewslabel->Size = System::Drawing::Size(185, 36);
			this->descriptionnewslabel->TabIndex = 8;
			this->descriptionnewslabel->Text = L"Description:";
			// 
			// titlerichtextbox
			// 
			this->titlerichtextbox->Font = (gcnew System::Drawing::Font(L"Cambria", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titlerichtextbox->Location = System::Drawing::Point(312, 33);
			this->titlerichtextbox->Name = L"titlerichtextbox";
			this->titlerichtextbox->Size = System::Drawing::Size(839, 41);
			this->titlerichtextbox->TabIndex = 7;
			this->titlerichtextbox->Text = L"";
			// 
			// titlenewslabel
			// 
			this->titlenewslabel->AutoSize = true;
			this->titlenewslabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titlenewslabel->Location = System::Drawing::Point(74, 28);
			this->titlenewslabel->Name = L"titlenewslabel";
			this->titlenewslabel->Size = System::Drawing::Size(85, 36);
			this->titlenewslabel->TabIndex = 6;
			this->titlenewslabel->Text = L"Title:";
			this->titlenewslabel->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Maroon;
			this->panel4->Controls->Add(this->button9);
			this->panel4->Controls->Add(this->button14);
			this->panel4->Controls->Add(this->button15);
			this->panel4->Controls->Add(this->button16);
			this->panel4->Controls->Add(this->button17);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel4->Location = System::Drawing::Point(0, 541);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1182, 109);
			this->panel4->TabIndex = 5;
			// 
			// button9
			// 
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::Linen;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->Location = System::Drawing::Point(676, 1);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(246, 104);
			this->button9->TabIndex = 4;
			this->button9->Text = L"Update News";
			this->button9->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button14
			// 
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::Color::Linen;
			this->button14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button14.Image")));
			this->button14->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button14->Location = System::Drawing::Point(428, 3);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(242, 102);
			this->button14->TabIndex = 3;
			this->button14->Text = L"Remove News";
			this->button14->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::Color::Linen;
			this->button15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.Image")));
			this->button15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button15->Location = System::Drawing::Point(928, 0);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(251, 105);
			this->button15->TabIndex = 2;
			this->button15->Text = L"Add categories";
			this->button15->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->ForeColor = System::Drawing::Color::Linen;
			this->button16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button16.Image")));
			this->button16->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button16->Location = System::Drawing::Point(211, 1);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(211, 104);
			this->button16->TabIndex = 1;
			this->button16->Text = L"Add News";
			this->button16->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->ForeColor = System::Drawing::Color::Linen;
			this->button17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button17.Image")));
			this->button17->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button17->Location = System::Drawing::Point(3, 1);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(207, 104);
			this->button17->TabIndex = 0;
			this->button17->Text = L"Logout";
			this->button17->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// newsfeed
			// 
			this->newsfeed->Controls->Add(this->richTextBox1);
			this->newsfeed->Controls->Add(this->button22);
			this->newsfeed->Controls->Add(this->panel5);
			this->newsfeed->Dock = System::Windows::Forms::DockStyle::Fill;
			this->newsfeed->Location = System::Drawing::Point(0, 103);
			this->newsfeed->Name = L"newsfeed";
			this->newsfeed->Size = System::Drawing::Size(1182, 650);
			this->newsfeed->TabIndex = 15;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(129, 58);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(904, 364);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged_1);
			// 
			// button22
			// 
			this->button22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button22->Location = System::Drawing::Point(440, 459);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(260, 58);
			this->button22->TabIndex = 7;
			this->button22->Text = L"Display";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Maroon;
			this->panel5->Controls->Add(this->button54);
			this->panel5->Controls->Add(this->button18);
			this->panel5->Controls->Add(this->button19);
			this->panel5->Controls->Add(this->button20);
			this->panel5->Controls->Add(this->button21);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel5->Location = System::Drawing::Point(0, 541);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(1182, 109);
			this->panel5->TabIndex = 5;
			// 
			// button54
			// 
			this->button54->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button54->ForeColor = System::Drawing::Color::Linen;
			this->button54->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button54.Image")));
			this->button54->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button54->Location = System::Drawing::Point(-3, 2);
			this->button54->Name = L"button54";
			this->button54->Size = System::Drawing::Size(201, 104);
			this->button54->TabIndex = 4;
			this->button54->Text = L"Log out";
			this->button54->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button54->UseVisualStyleBackColor = true;
			this->button54->Click += gcnew System::EventHandler(this, &MyForm::button54_Click);
			// 
			// button18
			// 
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button18->ForeColor = System::Drawing::Color::Linen;
			this->button18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button18.Image")));
			this->button18->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button18->Location = System::Drawing::Point(669, 5);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(261, 102);
			this->button18->TabIndex = 3;
			this->button18->Text = L"Show rated News";
			this->button18->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click_1);
			// 
			// button19
			// 
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button19->ForeColor = System::Drawing::Color::Linen;
			this->button19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button19.Image")));
			this->button19->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button19->Location = System::Drawing::Point(929, 1);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(251, 105);
			this->button19->TabIndex = 2;
			this->button19->Text = L"Categories";
			this->button19->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// button20
			// 
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->ForeColor = System::Drawing::Color::Linen;
			this->button20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button20.Image")));
			this->button20->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button20->Location = System::Drawing::Point(422, 3);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(248, 104);
			this->button20->TabIndex = 1;
			this->button20->Text = L" News Feed";
			this->button20->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// button21
			// 
			this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button21->ForeColor = System::Drawing::Color::Linen;
			this->button21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button21.Image")));
			this->button21->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button21->Location = System::Drawing::Point(196, 4);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(227, 104);
			this->button21->TabIndex = 0;
			this->button21->Text = L"Rate News";
			this->button21->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// Ratenews
			// 
			this->Ratenews->Controls->Add(this->button27);
			this->Ratenews->Controls->Add(this->label10);
			this->Ratenews->Controls->Add(this->label9);
			this->Ratenews->Controls->Add(this->indexrate);
			this->Ratenews->Controls->Add(this->numericUpDown1);
			this->Ratenews->Controls->Add(this->panel6);
			this->Ratenews->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Ratenews->Location = System::Drawing::Point(0, 103);
			this->Ratenews->Name = L"Ratenews";
			this->Ratenews->Size = System::Drawing::Size(1182, 650);
			this->Ratenews->TabIndex = 16;
			// 
			// button27
			// 
			this->button27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button27->Location = System::Drawing::Point(401, 425);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(302, 67);
			this->button27->TabIndex = 10;
			this->button27->Text = L"Save your rate";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(219, 307);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(138, 32);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Your rate:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(111, 109);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(402, 32);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Index of news you want to rate:";
			// 
			// indexrate
			// 
			this->indexrate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->indexrate->Location = System::Drawing::Point(586, 109);
			this->indexrate->Name = L"indexrate";
			this->indexrate->Size = System::Drawing::Size(84, 38);
			this->indexrate->TabIndex = 7;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown1->Location = System::Drawing::Point(586, 301);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(132, 38);
			this->numericUpDown1->TabIndex = 6;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Maroon;
			this->panel6->Controls->Add(this->button47);
			this->panel6->Controls->Add(this->button23);
			this->panel6->Controls->Add(this->button24);
			this->panel6->Controls->Add(this->button25);
			this->panel6->Controls->Add(this->button26);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel6->Location = System::Drawing::Point(0, 541);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(1182, 109);
			this->panel6->TabIndex = 5;
			// 
			// button47
			// 
			this->button47->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button47->ForeColor = System::Drawing::Color::Linen;
			this->button47->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button47.Image")));
			this->button47->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button47->Location = System::Drawing::Point(-1, 4);
			this->button47->Name = L"button47";
			this->button47->Size = System::Drawing::Size(223, 104);
			this->button47->TabIndex = 4;
			this->button47->Text = L"Log out";
			this->button47->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button47->UseVisualStyleBackColor = true;
			this->button47->Click += gcnew System::EventHandler(this, &MyForm::button47_Click);
			// 
			// button23
			// 
			this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button23->ForeColor = System::Drawing::Color::Linen;
			this->button23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button23.Image")));
			this->button23->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button23->Location = System::Drawing::Point(674, 4);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(255, 102);
			this->button23->TabIndex = 3;
			this->button23->Text = L"Show rated News";
			this->button23->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click_1);
			// 
			// button24
			// 
			this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button24->ForeColor = System::Drawing::Color::Linen;
			this->button24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button24.Image")));
			this->button24->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button24->Location = System::Drawing::Point(929, 2);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(251, 105);
			this->button24->TabIndex = 2;
			this->button24->Text = L"Categories";
			this->button24->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			// 
			// button25
			// 
			this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button25->ForeColor = System::Drawing::Color::Linen;
			this->button25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button25.Image")));
			this->button25->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button25->Location = System::Drawing::Point(437, 2);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(237, 104);
			this->button25->TabIndex = 1;
			this->button25->Text = L" News Feed";
			this->button25->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			// 
			// button26
			// 
			this->button26->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button26->ForeColor = System::Drawing::Color::Linen;
			this->button26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button26.Image")));
			this->button26->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button26->Location = System::Drawing::Point(216, 2);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(223, 104);
			this->button26->TabIndex = 0;
			this->button26->Text = L"Rate News";
			this->button26->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			// 
			// removenews
			// 
			this->removenews->Controls->Add(this->indexewmovebox);
			this->removenews->Controls->Add(this->label12);
			this->removenews->Controls->Add(this->button28);
			this->removenews->Controls->Add(this->label15);
			this->removenews->Controls->Add(this->panel7);
			this->removenews->Dock = System::Windows::Forms::DockStyle::Fill;
			this->removenews->Location = System::Drawing::Point(0, 103);
			this->removenews->Name = L"removenews";
			this->removenews->Size = System::Drawing::Size(1182, 650);
			this->removenews->TabIndex = 17;
			// 
			// indexewmovebox
			// 
			this->indexewmovebox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->indexewmovebox->ForeColor = System::Drawing::Color::Black;
			this->indexewmovebox->Location = System::Drawing::Point(847, 123);
			this->indexewmovebox->Name = L"indexewmovebox";
			this->indexewmovebox->Size = System::Drawing::Size(69, 38);
			this->indexewmovebox->TabIndex = 14;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(480, 403);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 29);
			this->label12->TabIndex = 13;
			// 
			// button28
			// 
			this->button28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button28->Location = System::Drawing::Point(428, 443);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(269, 75);
			this->button28->TabIndex = 12;
			this->button28->Text = L"Remove News";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(101, 123);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(554, 29);
			this->label15->TabIndex = 6;
			this->label15->Text = L"Enter the index of the news you want to delete:";
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Maroon;
			this->panel7->Controls->Add(this->button29);
			this->panel7->Controls->Add(this->button30);
			this->panel7->Controls->Add(this->button31);
			this->panel7->Controls->Add(this->button32);
			this->panel7->Controls->Add(this->button33);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel7->Location = System::Drawing::Point(0, 541);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(1182, 109);
			this->panel7->TabIndex = 5;
			// 
			// button29
			// 
			this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button29->ForeColor = System::Drawing::Color::Linen;
			this->button29->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button29.Image")));
			this->button29->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button29->Location = System::Drawing::Point(676, 1);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(246, 104);
			this->button29->TabIndex = 4;
			this->button29->Text = L"Update News";
			this->button29->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
			// 
			// button30
			// 
			this->button30->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button30->ForeColor = System::Drawing::Color::Linen;
			this->button30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button30.Image")));
			this->button30->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button30->Location = System::Drawing::Point(428, 3);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(242, 102);
			this->button30->TabIndex = 3;
			this->button30->Text = L"Remove News";
			this->button30->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button30->UseVisualStyleBackColor = true;
			this->button30->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
			// 
			// button31
			// 
			this->button31->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button31->ForeColor = System::Drawing::Color::Linen;
			this->button31->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button31.Image")));
			this->button31->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button31->Location = System::Drawing::Point(928, 0);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(251, 105);
			this->button31->TabIndex = 2;
			this->button31->Text = L"Add categories";
			this->button31->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button31->UseVisualStyleBackColor = true;
			this->button31->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
			// 
			// button32
			// 
			this->button32->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button32->ForeColor = System::Drawing::Color::Linen;
			this->button32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button32.Image")));
			this->button32->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button32->Location = System::Drawing::Point(211, 1);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(211, 104);
			this->button32->TabIndex = 1;
			this->button32->Text = L"Add News";
			this->button32->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button32->UseVisualStyleBackColor = true;
			this->button32->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
			// 
			// button33
			// 
			this->button33->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button33->ForeColor = System::Drawing::Color::Linen;
			this->button33->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button33.Image")));
			this->button33->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button33->Location = System::Drawing::Point(3, 1);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(207, 104);
			this->button33->TabIndex = 0;
			this->button33->Text = L"Logout";
			this->button33->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
			// 
			// addcategory
			// 
			this->addcategory->Controls->Add(this->addcategorytextbox);
			this->addcategory->Controls->Add(this->label11);
			this->addcategory->Controls->Add(this->label13);
			this->addcategory->Controls->Add(this->button34);
			this->addcategory->Controls->Add(this->panel8);
			this->addcategory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addcategory->Location = System::Drawing::Point(0, 103);
			this->addcategory->Name = L"addcategory";
			this->addcategory->Size = System::Drawing::Size(1182, 650);
			this->addcategory->TabIndex = 18;
			// 
			// addcategorytextbox
			// 
			this->addcategorytextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addcategorytextbox->Location = System::Drawing::Point(586, 253);
			this->addcategorytextbox->Name = L"addcategorytextbox";
			this->addcategorytextbox->Size = System::Drawing::Size(359, 30);
			this->addcategorytextbox->TabIndex = 15;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(100, 237);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(152, 36);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Category:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(480, 403);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 29);
			this->label13->TabIndex = 13;
			// 
			// button34
			// 
			this->button34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button34->Location = System::Drawing::Point(428, 435);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(269, 75);
			this->button34->TabIndex = 12;
			this->button34->Text = L"Add category";
			this->button34->UseVisualStyleBackColor = true;
			this->button34->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Maroon;
			this->panel8->Controls->Add(this->button35);
			this->panel8->Controls->Add(this->button36);
			this->panel8->Controls->Add(this->button37);
			this->panel8->Controls->Add(this->button38);
			this->panel8->Controls->Add(this->button39);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel8->Location = System::Drawing::Point(0, 541);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(1182, 109);
			this->panel8->TabIndex = 5;
			// 
			// button35
			// 
			this->button35->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button35->ForeColor = System::Drawing::Color::Linen;
			this->button35->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button35.Image")));
			this->button35->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button35->Location = System::Drawing::Point(676, 1);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(246, 104);
			this->button35->TabIndex = 4;
			this->button35->Text = L"Update News";
			this->button35->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button35->UseVisualStyleBackColor = true;
			this->button35->Click += gcnew System::EventHandler(this, &MyForm::button35_Click);
			// 
			// button36
			// 
			this->button36->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button36->ForeColor = System::Drawing::Color::Linen;
			this->button36->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button36.Image")));
			this->button36->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button36->Location = System::Drawing::Point(428, 3);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(242, 102);
			this->button36->TabIndex = 3;
			this->button36->Text = L"Remove News";
			this->button36->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button36->UseVisualStyleBackColor = true;
			this->button36->Click += gcnew System::EventHandler(this, &MyForm::button36_Click);
			// 
			// button37
			// 
			this->button37->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button37->ForeColor = System::Drawing::Color::Linen;
			this->button37->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button37.Image")));
			this->button37->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button37->Location = System::Drawing::Point(928, 0);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(251, 105);
			this->button37->TabIndex = 2;
			this->button37->Text = L"Add categories";
			this->button37->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button37->UseVisualStyleBackColor = true;
			this->button37->Click += gcnew System::EventHandler(this, &MyForm::button37_Click);
			// 
			// button38
			// 
			this->button38->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button38->ForeColor = System::Drawing::Color::Linen;
			this->button38->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button38.Image")));
			this->button38->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button38->Location = System::Drawing::Point(211, 1);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(211, 104);
			this->button38->TabIndex = 1;
			this->button38->Text = L"Add News";
			this->button38->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button38->UseVisualStyleBackColor = true;
			this->button38->Click += gcnew System::EventHandler(this, &MyForm::button38_Click);
			// 
			// button39
			// 
			this->button39->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button39->ForeColor = System::Drawing::Color::Linen;
			this->button39->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button39.Image")));
			this->button39->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button39->Location = System::Drawing::Point(3, 1);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(202, 104);
			this->button39->TabIndex = 0;
			this->button39->Text = L"Logout";
			this->button39->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button39->UseVisualStyleBackColor = true;
			this->button39->Click += gcnew System::EventHandler(this, &MyForm::button39_Click);
			// 
			// updatenews
			// 
			this->updatenews->Controls->Add(this->updatedDescription);
			this->updatenews->Controls->Add(this->label20);
			this->updatenews->Controls->Add(this->updatedTitle);
			this->updatenews->Controls->Add(this->label19);
			this->updatenews->Controls->Add(this->indexnewsupdate);
			this->updatenews->Controls->Add(this->label14);
			this->updatenews->Controls->Add(this->label18);
			this->updatenews->Controls->Add(this->button40);
			this->updatenews->Controls->Add(this->panel9);
			this->updatenews->Dock = System::Windows::Forms::DockStyle::Fill;
			this->updatenews->Location = System::Drawing::Point(0, 103);
			this->updatenews->Name = L"updatenews";
			this->updatenews->Size = System::Drawing::Size(1182, 650);
			this->updatenews->TabIndex = 19;
			// 
			// updatedDescription
			// 
			this->updatedDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->updatedDescription->Location = System::Drawing::Point(730, 336);
			this->updatedDescription->Name = L"updatedDescription";
			this->updatedDescription->Size = System::Drawing::Size(374, 41);
			this->updatedDescription->TabIndex = 19;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(46, 332);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(372, 36);
			this->label20->TabIndex = 18;
			this->label20->Text = L"The updated Description:";
			// 
			// updatedTitle
			// 
			this->updatedTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->updatedTitle->Location = System::Drawing::Point(730, 212);
			this->updatedTitle->Name = L"updatedTitle";
			this->updatedTitle->Size = System::Drawing::Size(374, 41);
			this->updatedTitle->TabIndex = 17;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(44, 201);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(262, 36);
			this->label19->TabIndex = 16;
			this->label19->Text = L"The updated title:";
			// 
			// indexnewsupdate
			// 
			this->indexnewsupdate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->indexnewsupdate->Location = System::Drawing::Point(860, 73);
			this->indexnewsupdate->Name = L"indexnewsupdate";
			this->indexnewsupdate->Size = System::Drawing::Size(101, 41);
			this->indexnewsupdate->TabIndex = 15;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(33, 70);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(690, 36);
			this->label14->TabIndex = 14;
			this->label14->Text = L"Enter the index of the news you want to update:";
			this->label14->Click += gcnew System::EventHandler(this, &MyForm::label14_Click);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(480, 403);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(0, 29);
			this->label18->TabIndex = 13;
			// 
			// button40
			// 
			this->button40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button40->Location = System::Drawing::Point(428, 443);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(269, 75);
			this->button40->TabIndex = 12;
			this->button40->Text = L"Update News";
			this->button40->UseVisualStyleBackColor = true;
			this->button40->Click += gcnew System::EventHandler(this, &MyForm::button40_Click);
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::Maroon;
			this->panel9->Controls->Add(this->button41);
			this->panel9->Controls->Add(this->button42);
			this->panel9->Controls->Add(this->button43);
			this->panel9->Controls->Add(this->button44);
			this->panel9->Controls->Add(this->button45);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel9->Location = System::Drawing::Point(0, 541);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(1182, 109);
			this->panel9->TabIndex = 5;
			// 
			// button41
			// 
			this->button41->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button41->ForeColor = System::Drawing::Color::Linen;
			this->button41->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button41.Image")));
			this->button41->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button41->Location = System::Drawing::Point(676, 1);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(246, 104);
			this->button41->TabIndex = 4;
			this->button41->Text = L"Update News";
			this->button41->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button41->UseVisualStyleBackColor = true;
			// 
			// button42
			// 
			this->button42->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button42->ForeColor = System::Drawing::Color::Linen;
			this->button42->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button42.Image")));
			this->button42->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button42->Location = System::Drawing::Point(428, 3);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(242, 102);
			this->button42->TabIndex = 3;
			this->button42->Text = L"Remove News";
			this->button42->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button42->UseVisualStyleBackColor = true;
			this->button42->Click += gcnew System::EventHandler(this, &MyForm::button42_Click);
			// 
			// button43
			// 
			this->button43->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button43->ForeColor = System::Drawing::Color::Linen;
			this->button43->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button43.Image")));
			this->button43->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button43->Location = System::Drawing::Point(928, 0);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(251, 105);
			this->button43->TabIndex = 2;
			this->button43->Text = L"Add categories";
			this->button43->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button43->UseVisualStyleBackColor = true;
			this->button43->Click += gcnew System::EventHandler(this, &MyForm::button43_Click);
			// 
			// button44
			// 
			this->button44->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button44->ForeColor = System::Drawing::Color::Linen;
			this->button44->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button44.Image")));
			this->button44->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button44->Location = System::Drawing::Point(211, 1);
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(211, 104);
			this->button44->TabIndex = 1;
			this->button44->Text = L"Add News";
			this->button44->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button44->UseVisualStyleBackColor = true;
			this->button44->Click += gcnew System::EventHandler(this, &MyForm::button44_Click);
			// 
			// button45
			// 
			this->button45->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button45->ForeColor = System::Drawing::Color::Linen;
			this->button45->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button45.Image")));
			this->button45->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button45->Location = System::Drawing::Point(3, 1);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(202, 104);
			this->button45->TabIndex = 0;
			this->button45->Text = L"Logout";
			this->button45->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button45->UseVisualStyleBackColor = true;
			this->button45->Click += gcnew System::EventHandler(this, &MyForm::button45_Click);
			// 
			// showratednews
			// 
			this->showratednews->Controls->Add(this->button61);
			this->showratednews->Controls->Add(this->richTextBox2);
			this->showratednews->Controls->Add(this->button48);
			this->showratednews->Controls->Add(this->panel10);
			this->showratednews->Dock = System::Windows::Forms::DockStyle::Fill;
			this->showratednews->Location = System::Drawing::Point(0, 103);
			this->showratednews->Name = L"showratednews";
			this->showratednews->Size = System::Drawing::Size(1182, 650);
			this->showratednews->TabIndex = 20;
			// 
			// button61
			// 
			this->button61->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button61->Location = System::Drawing::Point(674, 435);
			this->button61->Name = L"button61";
			this->button61->Size = System::Drawing::Size(399, 69);
			this->button61->TabIndex = 12;
			this->button61->Text = L"Hide incorrect news";
			this->button61->UseVisualStyleBackColor = true;
			this->button61->Click += gcnew System::EventHandler(this, &MyForm::button61_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(97, 46);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(960, 370);
			this->richTextBox2->TabIndex = 11;
			this->richTextBox2->Text = L"";
			// 
			// button48
			// 
			this->button48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button48->Location = System::Drawing::Point(129, 437);
			this->button48->Name = L"button48";
			this->button48->Size = System::Drawing::Size(302, 67);
			this->button48->TabIndex = 10;
			this->button48->Text = L"Display";
			this->button48->UseVisualStyleBackColor = true;
			this->button48->Click += gcnew System::EventHandler(this, &MyForm::button48_Click);
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::Maroon;
			this->panel10->Controls->Add(this->button49);
			this->panel10->Controls->Add(this->button50);
			this->panel10->Controls->Add(this->button51);
			this->panel10->Controls->Add(this->button52);
			this->panel10->Controls->Add(this->button53);
			this->panel10->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel10->Location = System::Drawing::Point(0, 541);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(1182, 109);
			this->panel10->TabIndex = 5;
			// 
			// button49
			// 
			this->button49->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button49->ForeColor = System::Drawing::Color::Linen;
			this->button49->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button49.Image")));
			this->button49->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button49->Location = System::Drawing::Point(-1, 4);
			this->button49->Name = L"button49";
			this->button49->Size = System::Drawing::Size(223, 104);
			this->button49->TabIndex = 4;
			this->button49->Text = L"Log out";
			this->button49->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button49->UseVisualStyleBackColor = true;
			this->button49->Click += gcnew System::EventHandler(this, &MyForm::button49_Click);
			// 
			// button50
			// 
			this->button50->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button50->ForeColor = System::Drawing::Color::Linen;
			this->button50->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button50.Image")));
			this->button50->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button50->Location = System::Drawing::Point(674, 4);
			this->button50->Name = L"button50";
			this->button50->Size = System::Drawing::Size(255, 102);
			this->button50->TabIndex = 3;
			this->button50->Text = L"Show rated News";
			this->button50->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button50->UseVisualStyleBackColor = true;
			// 
			// button51
			// 
			this->button51->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button51->ForeColor = System::Drawing::Color::Linen;
			this->button51->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button51.Image")));
			this->button51->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button51->Location = System::Drawing::Point(929, 2);
			this->button51->Name = L"button51";
			this->button51->Size = System::Drawing::Size(251, 105);
			this->button51->TabIndex = 2;
			this->button51->Text = L"Categories";
			this->button51->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button51->UseVisualStyleBackColor = true;
			this->button51->Click += gcnew System::EventHandler(this, &MyForm::button51_Click);
			// 
			// button52
			// 
			this->button52->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button52->ForeColor = System::Drawing::Color::Linen;
			this->button52->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button52.Image")));
			this->button52->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button52->Location = System::Drawing::Point(437, 2);
			this->button52->Name = L"button52";
			this->button52->Size = System::Drawing::Size(237, 104);
			this->button52->TabIndex = 1;
			this->button52->Text = L" News Feed";
			this->button52->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button52->UseVisualStyleBackColor = true;
			this->button52->Click += gcnew System::EventHandler(this, &MyForm::button52_Click);
			// 
			// button53
			// 
			this->button53->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button53->ForeColor = System::Drawing::Color::Linen;
			this->button53->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button53.Image")));
			this->button53->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button53->Location = System::Drawing::Point(216, 2);
			this->button53->Name = L"button53";
			this->button53->Size = System::Drawing::Size(223, 104);
			this->button53->TabIndex = 0;
			this->button53->Text = L"Rate News";
			this->button53->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button53->UseVisualStyleBackColor = true;
			this->button53->Click += gcnew System::EventHandler(this, &MyForm::button53_Click);
			// 
			// displaycategory
			// 
			this->displaycategory->Controls->Add(this->textBox2);
			this->displaycategory->Controls->Add(this->label21);
			this->displaycategory->Controls->Add(this->button60);
			this->displaycategory->Controls->Add(this->richTextBox3);
			this->displaycategory->Controls->Add(this->panel11);
			this->displaycategory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->displaycategory->Location = System::Drawing::Point(0, 103);
			this->displaycategory->Name = L"displaycategory";
			this->displaycategory->Size = System::Drawing::Size(1182, 650);
			this->displaycategory->TabIndex = 21;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(498, 35);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(205, 41);
			this->textBox2->TabIndex = 11;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(253, 35);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(227, 29);
			this->label21->TabIndex = 9;
			this->label21->Text = L"Search for category:";
			// 
			// button60
			// 
			this->button60->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button60->Location = System::Drawing::Point(446, 464);
			this->button60->Name = L"button60";
			this->button60->Size = System::Drawing::Size(254, 61);
			this->button60->TabIndex = 7;
			this->button60->Text = L"Display by category";
			this->button60->UseVisualStyleBackColor = true;
			this->button60->Click += gcnew System::EventHandler(this, &MyForm::button60_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox3->Location = System::Drawing::Point(247, 107);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(669, 338);
			this->richTextBox3->TabIndex = 6;
			this->richTextBox3->Text = L"";
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::Maroon;
			this->panel11->Controls->Add(this->button55);
			this->panel11->Controls->Add(this->button56);
			this->panel11->Controls->Add(this->button57);
			this->panel11->Controls->Add(this->button58);
			this->panel11->Controls->Add(this->button59);
			this->panel11->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel11->Location = System::Drawing::Point(0, 541);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(1182, 109);
			this->panel11->TabIndex = 5;
			// 
			// button55
			// 
			this->button55->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button55->ForeColor = System::Drawing::Color::Linen;
			this->button55->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button55.Image")));
			this->button55->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button55->Location = System::Drawing::Point(1, 3);
			this->button55->Name = L"button55";
			this->button55->Size = System::Drawing::Size(197, 104);
			this->button55->TabIndex = 4;
			this->button55->Text = L"Log out";
			this->button55->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button55->UseVisualStyleBackColor = true;
			this->button55->Click += gcnew System::EventHandler(this, &MyForm::button55_Click);
			// 
			// button56
			// 
			this->button56->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button56->ForeColor = System::Drawing::Color::Linen;
			this->button56->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button56.Image")));
			this->button56->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button56->Location = System::Drawing::Point(665, 5);
			this->button56->Name = L"button56";
			this->button56->Size = System::Drawing::Size(271, 102);
			this->button56->TabIndex = 3;
			this->button56->Text = L"Show rated News";
			this->button56->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button56->UseVisualStyleBackColor = true;
			this->button56->Click += gcnew System::EventHandler(this, &MyForm::button56_Click);
			// 
			// button57
			// 
			this->button57->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button57->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button57->ForeColor = System::Drawing::Color::Linen;
			this->button57->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button57.Image")));
			this->button57->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button57->Location = System::Drawing::Point(932, 2);
			this->button57->Name = L"button57";
			this->button57->Size = System::Drawing::Size(251, 105);
			this->button57->TabIndex = 2;
			this->button57->Text = L"Categories";
			this->button57->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button57->UseVisualStyleBackColor = true;
			// 
			// button58
			// 
			this->button58->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button58->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button58->ForeColor = System::Drawing::Color::Linen;
			this->button58->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button58.Image")));
			this->button58->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button58->Location = System::Drawing::Point(416, 3);
			this->button58->Name = L"button58";
			this->button58->Size = System::Drawing::Size(249, 104);
			this->button58->TabIndex = 1;
			this->button58->Text = L" News Feed";
			this->button58->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button58->UseVisualStyleBackColor = true;
			this->button58->Click += gcnew System::EventHandler(this, &MyForm::button58_Click);
			// 
			// button59
			// 
			this->button59->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button59->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button59->ForeColor = System::Drawing::Color::Linen;
			this->button59->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button59.Image")));
			this->button59->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button59->Location = System::Drawing::Point(196, 2);
			this->button59->Name = L"button59";
			this->button59->Size = System::Drawing::Size(222, 104);
			this->button59->TabIndex = 0;
			this->button59->Text = L"Rate News";
			this->button59->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button59->UseVisualStyleBackColor = true;
			this->button59->Click += gcnew System::EventHandler(this, &MyForm::button59_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Linen;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1182, 753);
			this->Controls->Add(this->showratednews);
			this->Controls->Add(this->displaycategory);
			this->Controls->Add(this->Ratenews);
			this->Controls->Add(this->AddNews);
			this->Controls->Add(this->removenews);
			this->Controls->Add(this->updatenews);
			this->Controls->Add(this->addcategory);
			this->Controls->Add(this->HomePageUser);
			this->Controls->Add(this->newsfeed);
			this->Controls->Add(this->LoginSignup);
			this->Controls->Add(this->Signup);
			this->Controls->Add(this->HomepageAdmin);
			this->Controls->Add(this->TitleHeader);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Event News";
			this->TitleHeader->ResumeLayout(false);
			this->TitleHeader->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->LoginSignup->ResumeLayout(false);
			this->LoginSignup->PerformLayout();
			this->Signup->ResumeLayout(false);
			this->Signup->PerformLayout();
			this->HomepageAdmin->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->HomePageUser->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel3->ResumeLayout(false);
			this->AddNews->ResumeLayout(false);
			this->AddNews->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->newsfeed->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->Ratenews->ResumeLayout(false);
			this->Ratenews->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->panel6->ResumeLayout(false);
			this->removenews->ResumeLayout(false);
			this->removenews->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->addcategory->ResumeLayout(false);
			this->addcategory->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->updatenews->ResumeLayout(false);
			this->updatenews->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->showratednews->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->displaycategory->ResumeLayout(false);
			this->displaycategory->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void TitleHeader_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		Signup->BringToFront();
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void pictureBox2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		AddNews->BringToFront();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		bool namecheck = false, passwordcheck = false;
		msclr::interop::marshal_context context;
		std::string usernamesignup = context.marshal_as<std::string>(usernameSignup->Text);
		std::string passwordsignup = context.marshal_as<std::string>(passwordSignup->Text);

		if (usernamesignup[0] == 'A' || usernamesignup[0] == 'U') {
			namecheck = true;
		}
		else {
			MessageBox::Show("The username must start with a chr A for admin and U for user");
		}

		if (passwordsignup.length() < 8) {
			passwordcheck = false;
			MessageBox::Show("Password must be at least 8 digits");

		}
		else {
			passwordcheck = true;
		}

		
		if (info_map.find(usernamesignup) != info_map.end()) {
			MessageBox::Show("This username already exists. Please choose a different username.");
			namecheck = false;
		}

		if (namecheck==true && passwordcheck==true) {
			info_object.name = usernamesignup;
			info_object.password = passwordsignup;
			info_map[usernamesignup] = info_object;
			MessageBox::Show("Signup completed");
			LoginSignup->BringToFront();
		}
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		bool InfoCorrectCheck = false;
		msclr::interop::marshal_context context;
		std::string usernamelogin = context.marshal_as<std::string>(usernameLogin->Text);
		std::string passwordlogin = context.marshal_as<std::string>(passwordLogin->Text);

		auto search = info_map.find(usernamelogin);
		if (search != info_map.end() && search->second.password == passwordlogin) {
			if (usernamelogin[0] == 'A') {
				InfoCorrectCheck = true;
				HomepageAdmin->BringToFront();
			}
			else if (usernamelogin[0] == 'U') {
				InfoCorrectCheck = true;
				HomePageUser->BringToFront();
			}
		}

		if (!InfoCorrectCheck) {
			label6->Text = "Incorrect info.TRY AGAIN";
		}
	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {

		msclr::interop::marshal_context context;
		std::string titlenews = context.marshal_as<std::string>(titlerichtextbox->Text);
		std::string descriptionnews = context.marshal_as<std::string>(descriptionrichtextbox->Text);
		std::string datenews = context.marshal_as<std::string>(dateTimePicker1->Text);
		std::string addcategory = context.marshal_as<std::string>(textBox1->Text);
		if (category_map.find(addcategory) == category_map.end()) {
			MessageBox::Show("Category not found");
		}
		else {
			news_object.title = titlenews;
			news_object.desccription = descriptionnews;
			news_object.date = datenews;
			news_object.category = addcategory;
			news_deque.push_back(news_object);
			category_map[addcategory].push_back(news_object);
			MessageBox::Show("News added");
		}
		titlerichtextbox->Clear();
		descriptionrichtextbox->Clear();
		textBox1->Clear();
		
	
	}
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
		newsfeed->BringToFront();
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
		newsfeed->BringToFront();
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {



	}
	private: System::Void listView1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Clear();
		int index = news_deque.size();
		for (auto it = news_deque.rbegin(); it != news_deque.rend(); ++it) {
			String^ newsString = gcnew String(std::to_string(index).c_str())+"_"+gcnew String(it->title.c_str()) + "\n" + gcnew String(it->desccription.c_str()) + "\n" + gcnew String(it->date.c_str()) + "\n\n";
			richTextBox1->AppendText(newsString);
			index--;
		}
	}
	private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void richTextBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
		Ratenews->BringToFront();
	}
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
		Ratenews->BringToFront();
	}
	private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
		newsfeed->BringToFront();
	}
	private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
		int index = System::Convert::ToInt16(indexrate->Text);
		int ratevalue = System::Convert::ToInt16(numericUpDown1->Text);
		index--;

		if (index >= 0 && index < news_deque.size()) {
			float oldRate = news_deque.at(index).avg;
			news_deque.at(index).usersRated++;
			news_deque.at(index).rate += ratevalue;
			news_deque.at(index).avg = float(news_deque.at(index).rate) / float(news_deque.at(index).usersRated);
			float averagerate = news_deque.at(index).avg;
			News n = news_deque.at(index);
			for (dqit = avgRate_map[oldRate].begin(); dqit != avgRate_map[oldRate].end(); dqit++) {
				if (dqit->title == news_deque.at(index).title) {
					avgRate_map[oldRate].erase(dqit);
					break;
				}
			}
			if (avgRate_map[oldRate].empty()) {
				avgRate_map.erase(oldRate);
			}

			avgRate_map[averagerate].push_back(n);
			MessageBox::Show("News rated successfully");
		}
		else {
			MessageBox::Show("Invalid index value");
		}
		indexrate->Clear();
	}
	private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
		int indexremove = System::Int32::Parse(indexewmovebox->Text);
		msclr::interop::marshal_context context;
		//std::string interedCategory = context.marshal_as<std::string>(categorySearch->Text);
		indexremove--;
		if (indexremove >= 0 && indexremove < news_deque.size()) {
			std::string Title = news_deque.at(indexremove).title;
			float thisRate = news_deque.at(indexremove).avg;
			string interedCategory = news_deque.at(indexremove).category;
			news_deque.erase(news_deque.begin() + indexremove);
			auto dqit = category_map[interedCategory].begin();
			while (dqit != category_map[interedCategory].end()) {
				if (dqit->title == Title) {
					dqit = category_map[interedCategory].erase(dqit);
				}
				else {
					++dqit;
				}
			}
		    auto avgit = avgRate_map[thisRate].begin();
			while (avgit != avgRate_map[thisRate].end()) {
				if (avgit->title == Title) {
					avgit = avgRate_map[thisRate].erase(avgit);
				}
				else {
					++avgit;
				}
			}

			MessageBox::Show("News deleted");
		}
		else {
			MessageBox::Show("Invalid index value");
		}
		indexewmovebox->Clear();
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
		removenews->BringToFront();
	}
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
		LoginSignup->BringToFront();
	}
	private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
		LoginSignup->BringToFront();
	}
	private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
		LoginSignup->BringToFront();
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		removenews->BringToFront();
	}
	private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
	
		bool checkExists = false;
		msclr::interop::marshal_context context;
		std::string inputcategory = context.marshal_as<std::string>(addcategorytextbox->Text);

		for (const auto& category : category_map) {
			if (category.first == inputcategory) {
				MessageBox::Show("Category already exists");
				checkExists = true;
				break;
			}
		}
		if (checkExists == false) {
			category_map[inputcategory];
			MessageBox::Show("Category added");
		}
		addcategorytextbox->Clear();
	}
	private: System::Void richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button40_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		std::string updatedtitle = context.marshal_as<std::string>(updatedTitle->Text);
		std::string updateddescription = context.marshal_as<std::string>(updatedDescription->Text);
		//std::string searchCategory = context.marshal_as<std::string>(categoryUpdate->Text);
		int input = System::Convert::ToInt16(indexnewsupdate->Text);
		string oldTitle;
		input--;

		if (input >= 0 && input < news_deque.size()) {
			oldTitle = news_deque.at(input).title;
			float thisRate = news_deque.at(input).avg;
			string searchCategory = news_deque.at(input).category;
			news_deque.at(input).title = updatedtitle;
			news_deque.at(input).desccription = updateddescription;

			auto dqit = category_map[searchCategory].begin();
			while (dqit != category_map[searchCategory].end()) {
				if (dqit->title == oldTitle)
				{
					dqit->title = updatedtitle;
					dqit->desccription = updateddescription;
				}
				else {
					++dqit;
				}
			}
			
			auto avgit = avgRate_map[thisRate].begin();
			while (avgit != avgRate_map[thisRate].end()) {
				if (avgit->title == oldTitle)
				{
					avgit->title = updatedtitle;
					avgit->desccription = updateddescription;
				}
				else {
					++avgit;
				}
			}

			MessageBox::Show("News updated");

		}
		else {
			MessageBox::Show("Invalid index value");
		}
		updatedTitle->Clear();
		updatedDescription->Clear();
		indexnewsupdate->Clear();
	}
	private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		updatenews->BringToFront();
	}
	private: System::Void button46_Click(System::Object^ sender, System::EventArgs^ e) {
		LoginSignup->BringToFront();
	}
private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button47_Click(System::Object^ sender, System::EventArgs^ e) {
	LoginSignup->BringToFront();
}
private: System::Void button48_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBox2->Clear();
	for (auto it = avgRate_map.rbegin(); it != avgRate_map.rend(); ++it)
	{
		for (dqit = it->second.begin();dqit != it->second.end();dqit++)
		{
				String^ titleString = gcnew String(dqit->title.c_str());
				String^ descriptionString = gcnew String(dqit->desccription.c_str());
				String^ rateString = gcnew String(std::to_string(dqit->avg).c_str());
				String^ newsString = titleString + "\n" + descriptionString + "\n" + rateString+"\n"+ "\n\n";
				richTextBox2->AppendText(newsString);
			}
		
	}
}
private: System::Void button23_Click_1(System::Object^ sender, System::EventArgs^ e) {
	showratednews->BringToFront();
}
private: System::Void button49_Click(System::Object^ sender, System::EventArgs^ e) {
	LoginSignup->BringToFront();
}
private: System::Void button53_Click(System::Object^ sender, System::EventArgs^ e) {
	Ratenews->BringToFront();
}
private: System::Void button52_Click(System::Object^ sender, System::EventArgs^ e) {
	newsfeed->BringToFront();
}
private: System::Void button54_Click(System::Object^ sender, System::EventArgs^ e) {
	LoginSignup->BringToFront();
}
private: System::Void button18_Click_1(System::Object^ sender, System::EventArgs^ e) {
	showratednews->BringToFront();
}
private: System::Void button45_Click(System::Object^ sender, System::EventArgs^ e) {
	LoginSignup->BringToFront();
}
private: System::Void button44_Click(System::Object^ sender, System::EventArgs^ e) {
	AddNews->BringToFront();
}
private: System::Void button42_Click(System::Object^ sender, System::EventArgs^ e) {
	removenews->BringToFront();
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	updatenews->BringToFront();
}
private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
	AddNews->BringToFront();
}
private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
	removenews->BringToFront();
}
private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
	updatenews->BringToFront();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	addcategory->BringToFront();
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	addcategory->BringToFront();
}
private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
	addcategory->BringToFront();
}
private: System::Void button43_Click(System::Object^ sender, System::EventArgs^ e) {
	addcategory->BringToFront();
}
private: System::Void button55_Click(System::Object^ sender, System::EventArgs^ e) {
	LoginSignup->BringToFront();
}
private: System::Void button59_Click(System::Object^ sender, System::EventArgs^ e) {
	Ratenews->BringToFront();
}
private: System::Void button58_Click(System::Object^ sender, System::EventArgs^ e) {
	newsfeed->BringToFront();
}
private: System::Void button56_Click(System::Object^ sender, System::EventArgs^ e) {
	showratednews->BringToFront();
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	displaycategory->BringToFront();
}
private: System::Void button60_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBox3->Clear();
	msclr::interop::marshal_context context;
	std::string addcategory = context.marshal_as<std::string>(textBox2->Text);
	if (category_map.find(addcategory) == category_map.end()) {
		MessageBox::Show("Category not found");
	}else {
		for (const auto& news_object : category_map[addcategory]) {
			String^ newsString = gcnew String(news_object.title.c_str()) + "\n" + gcnew String(news_object.desccription.c_str()) + "\n\n";
			richTextBox3->AppendText(newsString);
		}
	}
}
private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button39_Click(System::Object^ sender, System::EventArgs^ e) {
	LoginSignup->BringToFront();
}
private: System::Void button38_Click(System::Object^ sender, System::EventArgs^ e) {
	AddNews->BringToFront();
}
private: System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
	removenews->BringToFront();
}
private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
	updatenews->BringToFront();
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
	displaycategory->BringToFront();
}
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
	displaycategory->BringToFront();
}
private: System::Void button51_Click(System::Object^ sender, System::EventArgs^ e) {
	displaycategory->BringToFront();
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	showratednews->BringToFront();
}
private: System::Void button61_Click(System::Object^ sender, System::EventArgs^ e) {
	richTextBox2->Clear();
	for (auto it = avgRate_map.rbegin(); it != avgRate_map.rend(); it++)
	{
		if (it->first >= 2)
		{
			for (dqit = it->second.begin(); dqit != it->second.end(); dqit++)
			{
				String^ titleString = gcnew String(dqit->title.c_str());
				String^ descriptionString = gcnew String(dqit->desccription.c_str());
				String^ rateString = gcnew String(std::to_string(dqit->avg).c_str());
				String^ newsString = titleString + "\n" + descriptionString + "\n" + rateString + "\n" + "\n\n";
				richTextBox2->AppendText(newsString);
				
			}
		}
	}
}
};
}
