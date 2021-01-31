#pragma once
#include "wx\wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

	/* Declaration for variables/functions and event table */

public:
	int countingNum = 0;
	bool counting = false;
	bool restart;
	bool shutDown;
	int chose = -1;
	int increment = 0;
	wxString input;
	wxString countingString;
	wxString frameString;

	wxColor Yellow = wxColor(255, 255, 0, 255);
	wxColor Blue = wxColor(0, 185, 255, 255);
	wxColor Orange = wxColor(255, 153, 0, 255);

	wxMenuBar* menuBar = new wxMenuBar();
	wxMenu* menuHelp = new wxMenu();


	wxBoxSizer* firstRow = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* secondRow = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* thirdRow = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* fourthRow = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* bottomRow = new wxBoxSizer(wxHORIZONTAL);


	/* The vertical box sizer which will be used to organize the GUI with rows going top to bottom*/
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);

	wxString mainTextLabel = wxString("Enter an amount of time: ");
	wxString frameTextLabel = wxString("Choose a time frame: ");

	wxString shutdownBtnLabel = wxString("Shut Down");
	wxString restartBtnLabel = wxString("Restart");
	wxString cancelBtnLabel = wxString("Cancel");

	wxString shuttingDownString = wxString("Shutting Down in..");
	wxString restartingString = wxString("Restarting in..");
	

	wxStaticBox* timerBox = new wxStaticBox(this, 14, wxString("  Time Left  "), wxDefaultPosition, wxSize(170,75));
	wxStaticText* shutdownText = new wxStaticText(timerBox, 15, wxEmptyString, wxPoint(20,20), wxDefaultSize);
	wxStaticText* timerText = new wxStaticText(timerBox, 16, wxEmptyString, wxPoint(25, 45), wxDefaultSize);

	wxStaticText* mainText = new wxStaticText(this, 17, mainTextLabel, wxDefaultPosition, wxSize(wxDefaultSize.x, 20));
	wxTextCtrl* mainTextBox = new wxTextCtrl(this, 18, wxEmptyString, wxDefaultPosition, wxSize(140, 20));

	wxStaticText* frameText = new wxStaticText(this, 19, frameTextLabel, wxDefaultPosition, wxSize(wxDefaultSize.x, 28));
	wxChoice* choice = new wxChoice(this, 20, wxDefaultPosition, wxSize(280, 28));


	wxButton* shutdownBtn = new wxButton(this, 7, shutdownBtnLabel, wxDefaultPosition, wxSize(370,60));
	wxButton* restartBtn = new wxButton(this, 8, restartBtnLabel, wxDefaultPosition, wxDefaultSize);
	wxButton* cancelBtn = new wxButton(this, 9, cancelBtnLabel, wxDefaultPosition, wxDefaultSize);


	wxFont newTimerBoxFont = timerBox->GetFont();
	wxFont timerTextScaledFont = timerText->GetFont();
	wxFont newShutdownFont = shutdownText->GetFont();

	wxFont mainTextFont = mainText->GetFont();
	wxFont frameFont = frameText->GetFont();

	wxFont shutdownBtnFont = shutdownBtn->GetFont();
	wxFont restartBtnFont = restartBtn->GetFont();
	wxFont cancelBtnFont = cancelBtn->GetFont();

	wxDECLARE_EVENT_TABLE();

	void onAbout(wxCommandEvent &evt);
	void onExit(wxCommandEvent &evt);
	void mainFunc(wxCommandEvent& evt);
	void onCancel(wxCommandEvent& evt);
	void onTimerStart(wxTimerEvent &evt);
	void ResetVars();

	wxTimer* m_timer;
};
