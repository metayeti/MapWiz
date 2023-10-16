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
//  util.h
//  ---
//  Utility functions.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef MW_UTIL_H_
#define MW_UTIL_H_

namespace mw::Util
{
	/**
	 * Splits a string.
	 */
	std::vector<std::string> SplitStr(std::string str, std::string const& delimiter);

	/**
	 * Makes string lowercase.
	 */
	void StrToLower(std::string& str);

	/**
	 * Makes string uppercase.
	 */
	void StrToUpper(std::string& str);

	/**
	 * Trims whitespace from right-hand side of the string.
	 */
	void TrimStrR(std::string& str);

	/**
	 * Trims whitespace from left-hand side of the string.
	 */
	void TrimStrL(std::string& str);

	/**
	 * Trims whitespace from both sides of the string.
	 */
	void TrimStr(std::string& str);

	/**
	 * Returns whether or not the specified filename exists.
	 */
	bool FileExists(const std::string& filename);

	/**
	 * Splits an XPM resource into several bitmaps of varying sizes. Returns a bitmap bundle.
	 */
	wxBitmapBundle XPMToBitmapBundle(const char* const* data, int baseWidth, int baseHeight, wxImageResizeQuality quality = wxIMAGE_QUALITY_NORMAL);
}

#endif // MW_UTIL_H_