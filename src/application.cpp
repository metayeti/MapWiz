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
	// load the application configuration
	config.Read();
	// fetch window parameters from config
	bool center = config.GetBool("startup", "center");
	Config::T_UnsignedIntPair position = config.GetUnsignedIntPair("startup", "position");
	Config::T_UnsignedIntPair size = config.GetUnsignedIntPair("startup", "size");
	bool maximize = config.GetBool("startup", "maximize");
	// setup the main application window
	FrmMain* window = new FrmMain(this);
	window->SetSize(window->FromDIP(wxSize(size.first, size.second)));
	window->SetPosition(wxPoint(position.first, position.second));
	if (center || maximize)
	{
		window->CenterOnScreen();
	}
	if (maximize)
	{
		window->Maximize();
	}
	// display the main application window
	window->Show(true);
	return true;
}

mw::Config* mw::Application::GetConfig()
{
	return &config;
}

wxIMPLEMENT_APP(mw::Application);
