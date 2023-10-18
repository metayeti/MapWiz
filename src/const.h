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
//  const.h
//  ---
//  Global constants.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef MW_CONST_H_
#define MW_CONST_H_

namespace mw
{
	// current MapWiz version
	// the following entry HAS to exist on line 30 so that "update_versions" utility can propery update it
	const char* const MAPWIZ_VERSION = "0.0.2 dev";

	// filenames
	const char* const FILENAME_CONFIG_INI = "MapWiz.ini";

	// github URLs
	const char* const URL_GH_MANUAL = "https://github.com/pulzed/MapWiz/tree/main/manual/";
	const char* const URL_GH_RELEASES = "https://github.com/pulzed/MapWiz/releases";

	// main window
	const char* const MAIN_WINDOW_TITLE = "MapWiz";

	// map constraints
	const size_t MAP_MIN_W = 1;
	const size_t MAP_MIN_H_ = 1;
	const size_t MAP_MAX_W = 1000;
	const size_t MAP_MAX_H = 1000;
	
	// help strings
	const char* const QUICKHELP_ACTION_FILE_NEW = "Create a new map";
	const char* const QUICKHELP_ACTION_FILE_OPEN = "Open an existing map";
	const char* const QUICKHELP_ACTION_FILE_SAVE = "Save this map";
	const char* const QUICKHELP_ACTION_FILE_SAVE_AS = "Save this map as";
	const char* const QUICKHELP_ACTION_FILE_SAVE_COPY = "Save a copy of this map";
	const char* const QUICKHELP_ACTION_FILE_SAVE_ALL = "Save all open maps";
	const char* const QUICKHELP_ACTION_FILE_SAVE_TEMPLATE = "Save this map as template";
	const char* const QUICKHELP_ACTION_FILE_EXPORT = "Export this map";
	const char* const QUICKHELP_ACTION_FILE_EXPORT_AS = "Export this map as";
	const char* const QUICKHELP_ACTION_FILE_CLOSE = "Close this map";
	const char* const QUICKHELP_ACTION_FILE_CLOSE_ALL = "Close all open maps";
	const char* const QUICKHELP_ACTION_FILE_QUIT = "Quit the program";

	const char* const QUICKHELP_ACTION_EDIT_UNDO = "Undo last action";
	const char* const QUICKHELP_ACTION_EDIT_REDO = "Redo previous undo";
	const char* const QUICKHELP_ACTION_EDIT_CUT = "Cut selection";
	const char* const QUICKHELP_ACTION_EDIT_COPY = "Copy selection";
	const char* const QUICKHELP_ACTION_EDIT_PASTE = "Paste from clipboard";
	const char* const QUICKHELP_ACTION_EDIT_DELETE = "Delete selection";

	const char* const QUICKHELP_ACTION_TOOLS_SETTINGS = "Show the settigs dialog";

	const char* const QUICKHELP_ACTION_HELP_USER_MANUAL = "Open online help";
	const char* const QUICKHELP_ACTION_HELP_CHECK_FOR_UPDATES = "Check online repository for updates";
	const char* const QUICKHELP_ACTION_HELP_ABOUT = "Show the about dialog";
}

#endif // MW_CONST_H_
