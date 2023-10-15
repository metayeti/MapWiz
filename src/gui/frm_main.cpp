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
//  frm_main.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "../mapwiz.h"
#include "../const.h"
#include "frm_main.h"
#include "dlg_about.h"
#include "../res/svg_resources.h"
#include "../res/xpm_resources.h"

void mw::FrmMain::StatusBar::OnSize(wxSizeEvent& e)
{
	wxRect rect;
	if (!GetFieldRect(Field_Zoom, rect))
	{
		e.Skip();
		return;
	}

	wxRect rectCheck = rect;
	//rectCheck.Deflate(2);
	cmbZoomLevel->SetSize(rectCheck);

	e.Skip();
}

mw::FrmMain::StatusBar::StatusBar(wxWindow* parent, long style)
: wxStatusBar(parent, wxID_ANY, style, "MapWiz statusbar")
{
	int widths[Field_Max];
	widths[Field_Text] = -1; // growable
	widths[Field_Zoom] = 70;

	SetFieldsCount(Field_Max);
	SetStatusWidths(Field_Max, widths);

	cmbZoomLevel = new wxComboBox(this, wxID_ANY, wxEmptyString);
	cmbZoomLevel->Append(std::vector<wxString>{ "25%", "50%", "75%", "100%", "125%", "150%", "175%", "200%" });
	cmbZoomLevel->Select(3);

	SetMinHeight(cmbZoomLevel->GetMinHeight());

	Bind(wxEVT_SIZE, &FrmMain::StatusBar::OnSize, this);
}

mw::FrmMain::StatusBar::~StatusBar()
{
}

void mw::FrmMain::OnMenuHelpUserManual(wxCommandEvent& e)
{
	wxLaunchDefaultBrowser(URL_GH_MANUAL);
}

void mw::FrmMain::OnMenuHelpCheckForUpdates(wxCommandEvent& e)
{
	wxLaunchDefaultBrowser(URL_GH_RELEASES);
}

void mw::FrmMain::OnMenuHelpAbout(wxCommandEvent& e)
{
	DlgAbout* dlgAbout = new DlgAbout(this);
	dlgAbout->CenterOnParent();
	dlgAbout->ShowModal();
}

void mw::FrmMain::InitializeGlobalMenu()
{
	SetMenuBar(menuBar.root = new wxMenuBar());

	// -- File --
	auto& menuFile = menuBar.menuFile;
	menuBar.root->Append((menuFile.root = new wxMenu()), "&File");
	{
	}

	// -- Edit --
	auto& menuEdit = menuBar.menuEdit;
	menuBar.root->Append((menuEdit.root = new wxMenu()), "&Edit");
	{
	}

	// -- View --
	auto& menuView = menuBar.menuView;
	menuBar.root->Append((menuEdit.root = new wxMenu()), "&View");
	{
	}

	// -- Map --
	auto& menuMap = menuBar.menuMap;
	menuBar.root->Append((menuMap.root = new wxMenu()), "&Map");
	{
	}

	// -- Layer --
	auto& menuLayer = menuBar.menuLayer;
	menuBar.root->Append((menuLayer.root = new wxMenu()), "&Layer");
	{
	}

	// -- Tools --
	auto& menuTools = menuBar.menuTools;
	menuBar.root->Append((menuTools.root = new wxMenu()), "&Tools");
	{
	}

	// -- Help --
	auto& menuHelp = menuBar.menuHelp;
	menuBar.root->Append((menuHelp.root = new wxMenu()), "&Help");
	{
		auto& menuUserManual = menuHelp.members.menuUserManual;
		menuUserManual = new wxMenuItem(menuHelp.root, wxID_ANY, "User &Manual\tF1", QUICKHELP_ACTION_HELP_USER_MANUAL);
		menuHelp.root->Append(menuUserManual);
		Bind(wxEVT_MENU, &FrmMain::OnMenuHelpUserManual, this, menuUserManual->GetId());

		auto& menuCheckForUpdates = menuHelp.members.menuCheckForUpdates;
		menuCheckForUpdates = new wxMenuItem(menuHelp.root, wxID_ANY, "Check for &Updates", QUICKHELP_ACTION_HELP_CHECK_FOR_UPDATES);
		menuHelp.root->Append(menuCheckForUpdates);
		Bind(wxEVT_MENU, &FrmMain::OnMenuHelpCheckForUpdates, this, menuCheckForUpdates->GetId());

		menuHelp.root->AppendSeparator();

		auto& menuAbout = menuHelp.members.menuAbout;
		menuAbout = new wxMenuItem(menuHelp.root, wxID_ANY, "&About", QUICKHELP_ACTION_HELP_ABOUT);
		menuHelp.root->Append(menuAbout);
		Bind(wxEVT_MENU, &FrmMain::OnMenuHelpAbout, this, menuAbout->GetId());
	}
}

void mw::FrmMain::InitializeStatusBar()
{
	statusBar = new FrmMain::StatusBar(this);
	SetStatusBar(statusBar);
	PositionStatusBar();
}

mw::FrmMain::FrmMain(wxApp* owner)
: wxFrame(nullptr, wxID_ANY, MAIN_WINDOW_TITLE), owner(owner)
{
	// frame setup
	SetMinSize(FromDIP(wxSize(200, 200))); // set minimum frame size
	//SetIcon(wxIcon(MapWiz_xpm)); // set window icon
	//SetIcon(wxICON(MapWiz));
#ifdef MW_SYSTEM_WINDOWS
	SetIcon(wxIcon("MapWiz", wxBITMAP_TYPE_ICO_RESOURCE, 16, 16));
#else
	SetIcon(wxIcon(MapWiz_xpm));
#endif
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));

	// initialize components
	InitializeGlobalMenu();
	InitializeStatusBar();
}