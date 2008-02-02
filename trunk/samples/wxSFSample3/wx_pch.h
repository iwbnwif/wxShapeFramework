/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:    Michal Bližňák ()
 * Created:   2007-03-04
 * Copyright: Michal Bližňák ()
 * License:
 **************************************************************/

#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

#ifdef _DISWARNINGS_MSVC
#pragma warning( disable : 4100 )
#pragma warning( disable : 4251 )
#pragma warning( disable : 4275 )
#endif

// basic wxWidgets headers
#include <wx/wxprec.h>

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#ifdef WX_PRECOMP
	// put here all your rarely-changing header files
#endif // WX_PRECOMP

#endif // WX_PCH_H_INCLUDED