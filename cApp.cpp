#include "cApp.h"

/* wxWidget documentation states that we have to call this for the GUI to start */
wxIMPLEMENT_APP(cApp);

/* On app start */
bool cApp::OnInit() {

	/* Construct the cMain class and show it on screen with the Show() function from wxWidget library */
	m_frame1 = new cMain();
	m_frame1->Show();

	return true;
}

