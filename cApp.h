#pragma once
#include "wx\wx.h"
#include "cMain.h"

class cApp : public wxApp
{

	/* Declaring pointer for cMain class constructer (which has the wxFrame inside) */
private:
	cMain* m_frame1 = nullptr;

	/* Declaring the override of the init function  */
public:
	virtual bool OnInit();
};

