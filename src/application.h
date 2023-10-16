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
//  application.h
//  ---
//  Core Application class and program entry point.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef MW_APPLICATION_H_
#define MW_APPLICATION_H_

namespace mw
{
	class Application : public wxApp
	{
	private:
		Config config;
	public:
		virtual bool OnInit() override;
	};
}

#endif // MW_APPLICATION_H_
