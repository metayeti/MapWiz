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

#include "mapwiz.h"
#include "util.h"

wxBitmapBundle mw::Util::XPMToBitmapBundle(const char* const* data, int baseWidth, int baseHeight, wxImageResizeQuality quality)
{
	wxImage image(data);
	wxVector<wxBitmap> bitmaps;
	bitmaps.push_back(wxBitmap(image.Scale(baseWidth, baseHeight, quality))); // 100%
	bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 1.25, baseHeight * 1.25, quality))); // 125%
	bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 1.5, baseHeight * 1.5, quality))); // 150%
	bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 1.75, baseHeight * 1.75, quality))); // 175%
	bitmaps.push_back(wxBitmap(image.Scale(baseWidth * 2, baseHeight * 2, quality))); // 200%
	return wxBitmapBundle::FromBitmaps(bitmaps);
}