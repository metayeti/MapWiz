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
//  config.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "config.h"
#include "const.h"

void mw::Config::GenerateDefaults() {
	data.clear();
	data["window"].set({
		{ "center", "yes" },
		{ "position", "0, 0" },
		{ "size", "800, 600" },
		{ "maximized", "no" }
	});
}

void mw::Config::Read() {
}

void mw::Config::Write() {
}
