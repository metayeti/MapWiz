////////////////////////////////////////////////////////////////////////////////
//   _____         _ _ _
//  |     |___ ___| | | |_ ___   2D map editor
//  | | | | . | . | | | | |- _|  version 0.0.1
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
//  dlg_about.h
//  ---
//  About dialog.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef MW_DLG_ABOUT_H_
#define MW_DLG_ABOUT_H_

namespace mw
{
	class DlgAbout : public wxDialog
	{
	public:
		DlgAbout(wxWindow* parent);
	};
}

#endif // MW_DLG_ABOUT_H_