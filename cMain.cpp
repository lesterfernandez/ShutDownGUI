#include "cMain.h"
#include <stdlib.h>
/* Event macros which bind to the ID number of elements in GUI */
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_MENU(wxID_ABOUT, onAbout)
	EVT_MENU(wxID_EXIT, onExit)
	EVT_BUTTON(7, mainFunc)
	EVT_BUTTON(8, mainFunc)
	EVT_BUTTON(9, onCancel)
	EVT_TIMER(21, onTimerStart)
wxEND_EVENT_TABLE();


cMain::cMain() : wxFrame(nullptr, wxID_ANY, wxString("Lester's Shut Down GUI 2.0"),
	wxPoint(400,400), wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {

	m_timer = new wxTimer(this, 21);

	/* Setting up the menu bar and status bar */
	menuHelp->Append(wxID_ABOUT);
	menuHelp->AppendSeparator();
	menuHelp->Append(wxID_EXIT);
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to the ShutDownGUI 2.0");

	/* Adding strings to choices from header file */
	choice->AppendString("Seconds");
	choice->AppendString("Minutes");
	choice->AppendString("Hours");


	/* Decorating Section */
	SetBackgroundColour(wxColor(0, 102, 0, 230));
	
	
	timerTextScaledFont.Scale(1.2f);
	timerTextScaledFont.SetFamily(wxFONTFAMILY_DECORATIVE);
	timerTextScaledFont.SetNumericWeight(470);
	timerText->SetOwnFont(timerTextScaledFont);

	newTimerBoxFont.SetNumericWeight(600);
	newTimerBoxFont.Scale(1.1f);
	timerBox->SetOwnFont(newTimerBoxFont);
	timerBox->SetOwnForegroundColour(Blue);
	
	newShutdownFont.Scale(1.1f);
	newShutdownFont.SetNumericWeight(415);
	shutdownText->SetForegroundColour(Orange);
	shutdownText->SetFont(newShutdownFont);

	mainTextFont.SetNumericWeight(442);
	mainTextFont.Scale(1.2f);
	frameFont.SetNumericWeight(442);
	frameFont.Scale(1.2f);

	mainText->SetFont(mainTextFont);
	mainText->SetForegroundColour(*wxWHITE);
	frameText->SetFont(frameFont);
	frameText->SetForegroundColour(*wxWHITE);

	shutdownBtnFont.SetNumericWeight(548);
	shutdownBtnFont.Scale(1.4f);
	shutdownBtnFont.SetStyle(wxFONTSTYLE_SLANT);
	restartBtnFont.SetNumericWeight(548);
	restartBtnFont.Scale(1.4f);
	restartBtnFont.SetStyle(wxFONTSTYLE_SLANT);
	cancelBtnFont.SetNumericWeight(548);
	cancelBtnFont.Scale(1.4f);
	cancelBtnFont.SetStyle(wxFONTSTYLE_SLANT);

	shutdownBtn->SetOwnBackgroundColour(Yellow);
	shutdownBtn->SetFont(shutdownBtnFont);
	restartBtn->SetOwnBackgroundColour(Yellow);
	restartBtn->SetFont(restartBtnFont);
	cancelBtn->SetOwnBackgroundColour(Yellow);
	cancelBtn->SetFont(cancelBtnFont);

	mainTextBox->SetMaxLength(7);


	/* Organizing elements in horizontal rows */
	firstRow->AddSpacer(7);
	firstRow->Add(mainText, wxSizerFlags(0).Center());
	firstRow->AddSpacer(7);
	firstRow->Add(mainTextBox, wxSizerFlags(0).Center());
	firstRow->AddSpacer(7);

	secondRow->AddSpacer(7);
	secondRow->Add(frameText, wxSizerFlags(0).Center());
	secondRow->AddSpacer(7);
	secondRow->Add(choice, wxSizerFlags(0).Center());
	secondRow->AddSpacer(7);
	
	thirdRow->AddSpacer(14);
	thirdRow->Add(shutdownBtn, wxSizerFlags(1).Expand().Border(wxALL, 7));
	thirdRow->AddSpacer(14);
	
	fourthRow->AddSpacer(14);
	fourthRow->Add(restartBtn, wxSizerFlags(1).Expand().Border(wxALL, 7));
	fourthRow->AddSpacer(14);

	bottomRow->AddSpacer(14);
	bottomRow->Add(cancelBtn, wxSizerFlags(1).Expand().Border(wxALL, 7));
	bottomRow->AddSpacer(14);

	/* Organizing the horizontal rows vertically in the vertical box sizer */
	topSizer->Add(timerBox, wxSizerFlags(0).Center().Border(wxALL, 7));
	topSizer->Add(firstRow, wxSizerFlags(0).Center().Border(wxALL, 7));
	topSizer->Add(secondRow, wxSizerFlags(0).Center().Border(wxALL, 7));
	topSizer->AddSpacer(21);
	topSizer->Add(thirdRow, wxSizerFlags(1).Expand());
	topSizer->Add(fourthRow, wxSizerFlags(1).Expand());
	topSizer->Add(bottomRow, wxSizerFlags(1).Expand().Border(wxDOWN | wxWEST | wxEAST, 7));

	/* Using the vertical box sizer to organize the GUI */
	this->SetSizerAndFit(topSizer);
	topSizer->Layout();


}

cMain::~cMain() {
	delete m_timer;
}



/* Functions */
void cMain::onAbout(wxCommandEvent &evt) {

	/* This is version 2.0 because my first app was accidentally deleted lol so this is version 2 
	(I learned the hard way I should back up my files frequently)*/
	wxMessageBox("Thank you for using ShutDownGUI 2.0","About ShutDownGUI 2.0", wxOK | wxICON_INFORMATION);

}

void cMain::onExit(wxCommandEvent &evt) {

	Close(true);
}

void cMain::mainFunc(wxCommandEvent& evt) {
	/* ID #7 = Shutdown Button
	ID #8 = RestartButton */

	int spot = -1;
	input = mainTextBox->GetLineText(0);
	chose = choice->GetSelection();

	/* remove decimal point if there is any because wxWidgets has a bug where the decimal point returns false
	 when inserted in the IsNumber() function */

	if (input.Contains(".")) {
		spot = input.Find(".");
		input.Remove(spot, 1);
	}


	if (input.Len() == 0 || !input.IsNumber()) {
		wxMessageBox(wxString("Please input a valid number"), wxString("Invalid Input Entered"));
	}
	else if (chose == -1) {
		wxMessageBox(wxString("Please choose a time frime"), wxString("No time frame selected"));
	}
	else if (input.IsNumber()) {
		/* put back decimal point if needed */
		if (spot > -1)
			input.insert(spot, ".");


		// round number to integer
		double num;
		input.ToDouble(&num);
		num += 0.5f;
		countingNum = (int)num;


		// start countdown
		counting = true;
		countingString << countingNum;
		mainTextBox->Clear();


		// if shutting down
		if (evt.GetId() == 7) {
			restart = false;
			shutDown = true;
			shutdownText->SetLabel(shuttingDownString);
		}

		// if restarting
		if (evt.GetId() == 8) {
			shutDown = false;
			restart = true;
			shutdownText->SetLabel(restartingString);
		}
		/* display time frame in the timerBox ( seconds , minutes , hours label ) */
		choice->SetSelection(wxNOT_FOUND);
		frameString = choice->GetString(chose).MakeLower();
		timerText->SetLabel(countingString << " " << frameString);


		switch (chose)
		{
		case 0:
			increment = 1;
			break;
		case 1:
			increment = 60;
			break;
		case 2:
			increment = 3600;
			break;
		default:
			break;
		}

		m_timer->Start(1000*increment);

	}
	evt.Skip();
}

void cMain::onCancel(wxCommandEvent& evt) {
	ResetVars();
	evt.Skip();
}

void cMain::onTimerStart(wxTimerEvent &evt) {

	if (counting) {


		if (countingNum <= 1) {
			/* shutdown or restart */
			if (shutDown) {
				system("C:\\windows\\system32\\shutdown /s /t 0");
			}
			else if (restart){
				system("C:\\windows\\system32\\shutdown /r /t 0");
			}
			else {
				ResetVars();
			}


		}

		/* Countdown Effect */
		countingNum--;
		countingString = wxEmptyString;
		countingString << countingNum;
		timerText->SetLabel(countingString << " " << frameString);

	}

}

void cMain::ResetVars() {
	restart = false;
	shutDown = false;
	input = wxEmptyString;
	countingString = wxEmptyString;
	frameString = wxEmptyString;
	m_timer->Stop();
	increment = 0;
	shutdownText->SetLabel(wxEmptyString);
	timerText->SetLabel(wxEmptyString);
	chose = -1;
	counting = false;
	countingNum = 0;
	mainTextBox->Clear();
	choice->SetSelection(wxNOT_FOUND);

}