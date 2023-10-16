////////////////////////////////////////////////////////////////////////////////
//   _____         _ _ _
//  |     |___ ___| | | |_ ___   2D map editor
//  | | | | . | . | | | | |- _|  version 0.0.2 dev
//  |_|_|_|__,|  _|_____|_|___|  https://github.com/pulzed/MapWiz
//            |_|              
//
//  Licensed under GPL3 ( https://www.gnu.org/licenses/gpl-3.0.en.html )
//  Copyright (c) 2024-present Danijel Durakovic
//
//  Based on the wxWidgets library ( https://www.wxwidgets.org/ )
//
////////////////////////////////////////////////////////////////////////////////
//
//  application.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "mapwiz.h"
#include "config.h"
#include "application.h"
#include "gui/frm_main.h"

wxDECLARE_APP(mw::Application);

bool mw::Application::OnInit()
{
	// load configuration
	config.Read();
	bool centerWindow = config.GetBool("startup", "center");
	if (centerWindow)
	{
		// center first-time only
		config.SetBool("startup", "center", false);
	}
	Config::T_UnsignedIntPair windowPosition = config.GetUnsignedIntPair("startup", "position");
	Config::T_UnsignedIntPair windowSize = config.GetUnsignedIntPair("startup", "size");
	bool maximizeWindow = config.GetBool("startup", "maximized");
	// setup the main application window
	FrmMain* window = new FrmMain(this);
	window->SetSize(window->FromDIP(wxSize(windowSize.first, windowSize.second)));
	window->SetPosition(wxPoint(windowPosition.first, windowPosition.second));
	if (centerWindow || maximizeWindow)
	{
		window->CenterOnScreen();
	}
	if (maximizeWindow)
	{
		window->Maximize();
	}
	// display the main application window
	window->Show(true);
	return true;
}

wxIMPLEMENT_APP(mw::Application);
