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
//  mapwiz.h
//  ---
//  Main headerfile for MapWiz. Defines system-level globals.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef MAPWIZ_H_
#define MAPWIZ_H_

#if defined(_WIN32) || defined(__CYGWIN__)
	#define MW_SYSTEM_WINDOWS
#elif defined(__linux__)
	#define MW_SYSTEM_LINUX
#elif defined(__APPLE__)
	#define MW_SYSTEM_MACOS
#endif

#if defined(DEBUG) || defined(_DEBUG)
	#define MW_DEBUG_BUILD
#endif

#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

// ~~~ VLD ~~~ uncomment to enable leak detection
//#include "vld.h"

#endif
