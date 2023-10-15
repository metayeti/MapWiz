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
//  dlg_about.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "../mapwiz.h"
#include "dlg_about.h"
#include "../util.h"
#include "../const.h"
#include "../res/svg_resources.h"

mw::DlgAbout::DlgAbout(wxWindow* parent)
: wxDialog(parent, wxID_ANY, "About MapWiz", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
	wxBoxSizer* outerVSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* innerHSizer = new wxBoxSizer(wxHORIZONTAL);

	const int borderSize = FromDIP(10);

	wxStaticBitmap* bmpLogo = new wxStaticBitmap(this, wxID_ANY, wxBitmapBundle::FromSVG(SVG_MAPWIZ_LOGO, wxSize(80, 80)));

	innerHSizer->Add(bmpLogo, 0, wxALL, borderSize);

	// text info
	innerHSizer->Add(
		CreateTextSizer(
			"MapWiz\n"
			"2D map editor\n\n"
			"v" + wxString(MAPWIZ_VERSION) + " "
#if defined(MW_SYSTEM_WINDOWS)
			"Windows"
#elif defined(MW_SYSTEM_LINUX)
			"Linux"
#elif defined(MW_SYSTEM_MACOS)
			"MacOS"
#endif
			" build"
#if defined(MW_DEBUG_BUILD)
			" (debug)"
#endif
			"\n\n"
			"Copyright © 2024 Danijel Durakovic\n"
			"Licensed under the terms of GPLv3"
		),
		0,
		wxALL,
		borderSize
	);

	outerVSizer->Add(innerHSizer);

	// ok button
	outerVSizer->Add(new wxButton(this, wxID_OK, "Okay", wxDefaultPosition, FromDIP(wxSize(110, 30))), 0, wxTOP | wxRIGHT | wxBOTTOM | wxALIGN_RIGHT, borderSize);

	SetSizerAndFit(outerVSizer);
}