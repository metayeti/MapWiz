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
//  frm_main.h
//  ---
//  Main application frame.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef MW_FRM_MAIN_H_
#define MW_FRM_MAIN_H_

namespace mw
{
	class FrmMain : public wxFrame
	{
	private:
		wxApp* owner = nullptr;

		// statusbar class
		class StatusBar : public wxStatusBar
		{
		private:
			wxComboBox* cmbZoomLevel;

			enum
			{
				Field_Text,
				Field_Zoom,
				Field_Max
			};

			void OnSize(wxSizeEvent& e);

		public:
			StatusBar(wxWindow* parent, long style = wxSTB_DEFAULT_STYLE);
			virtual ~StatusBar();
		};

		// menubar structure
		struct MenuBar
		{
			wxMenuBar* root;

			// -- File --
			struct MenuFile
			{
				wxMenu* root;
			} menuFile;

			// -- Edit --
			struct MenuEdit
			{
				wxMenu* root;
			} menuEdit;

			// -- View --
			struct MenuView
			{
				wxMenu* root;
			} menuView;

			// -- Map --
			struct MenuMap
			{
				wxMenu* root;
			} menuMap;

			// -- Layer --
			struct MenuLayer
			{
				wxMenu* root;
			} menuLayer;

			// -- Tools --
			struct MenuTools
			{
				wxMenu* root;
			} menuTools;

			// -- Help --
			struct MenuHelp
			{
				wxMenu* root;
				struct Members
				{
					wxMenuItem* menuUserManual;
					wxMenuItem* menuCheckForUpdates;
					wxMenuItem* menuAbout;
				} members;
			} menuHelp;

		} menuBar;

		// frame members
		StatusBar* statusBar;

		// menubar events
		void OnMenuHelpUserManual(wxCommandEvent& e);
		void OnMenuHelpCheckForUpdates(wxCommandEvent& e);
		void OnMenuHelpAbout(wxCommandEvent& e);

		// initialization
		void InitializeGlobalMenu();
		void InitializeStatusBar();

	public:
		FrmMain(wxApp* owner);
	};
}

#endif // MW_FRM_MAIN_H_
