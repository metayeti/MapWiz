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
//  config_resources.h
//  ---
//  Hardcoded configuration file.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef MW_CONFIG_RESOURCES_H_
#define MW_CONFIG_RESOURCES_H_

namespace mw
{
	// the following entry HAS to exist on line 29 so that "inject_config" utility can propery update it
	const char* const CONFIG_INIDATA = "; MapWiz configuration\n\n; startup settings\n[startup]\n; if set to true, will center window on launch\ncenter = true\n; window position on launch.\nposition = 0, 0\n; window size on launch.\nsize = 640, 480\n; maximized state on launch.\nmaximized = false\n\n; default mapfile\n[default_map]\n; default grid size (in pixels)\ngrid_size = 50, 50\n; default map size (in cells)\nmap_size = 100, 100\n; default map type (0 = orthogonal, 1 = isometric, 2 = hexagonal)\nmap_type = 0\n\n; recent-files list\n[recent]\n";
}

#endif // MW_CONFIG_RESOURCES_H_