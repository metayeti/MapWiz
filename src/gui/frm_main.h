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
		Application* application = nullptr;

		// most recent window geometry pre-maximization
		wxPoint lastWindowPosition;
		wxSize lastWindowSize;

		////////////////////////////////////////////////////////////////////////
		// 
		//  Statusbar class
		// 
		////////////////////////////////////////////////////////////////////////

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

		//////////////////////////////////////////////////////////////////////////////
		// 
		//  Menubar structure
		// 
		//////////////////////////////////////////////////////////////////////////////

		struct MenuBar
		{
			wxMenuBar* root;

			// -- File --
			struct MenuFile
			{
				wxMenu* root;
				struct Members
				{
					wxMenuItem* menuNew;
					wxMenuItem* menuOpen;
					struct MenuOpenRecent
					{
						wxMenu* root;
						struct MEMBERS
						{
							wxMenuItem* menuNoRecentItems;
							wxMenuItem* menuRecent[10];
						} members;
					} menuOpenRecent;
					wxMenuItem* menuSave;
					wxMenuItem* menuSaveAs;
					wxMenuItem* menuSaveCopy;
					wxMenuItem* menuSaveAll;
					wxMenuItem* menuSaveTemplate;
					wxMenuItem* menuExport;
					wxMenuItem* menuExportAs;
					wxMenuItem* menuClose;
					wxMenuItem* menuCloseAll;
					wxMenuItem* menuQuit;
				} members;
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


		//////////////////////////////////////////////////////////////////////////////
		// 
		//  Frame members
		// 
		//////////////////////////////////////////////////////////////////////////////
		
		StatusBar* statusBar;

		// editor actions

		//void ActionUndo();
		//void ActionRedo();


		//////////////////////////////////////////////////////////////////////////////
		// 
		//  Events
		// 
		//////////////////////////////////////////////////////////////////////////////

		// menubar events
		void OnMenuFileNew(wxCommandEvent& e);
		void OnMenuFileQuit(wxCommandEvent& e);

		void OnMenuHelpUserManual(wxCommandEvent& e);
		void OnMenuHelpCheckForUpdates(wxCommandEvent& e);
		void OnMenuHelpAbout(wxCommandEvent& e);

		// window events
		void OnWindowMove(wxMoveEvent& e);
		void OnWindowSize(wxSizeEvent& e);
		void OnWindowClose(wxCloseEvent& e);

		// initialization
		void InitializeGlobalMenu();
		void InitializeStatusBar();

	public:
		FrmMain(Application* application);
	};
}

#endif // MW_FRM_MAIN_H_
