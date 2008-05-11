/***************************************************************
 * Name:      DiamondShape.h
 * Purpose:   Defines diamond shape class
 * Author:    Michal Bližňák (michal.bliznak@tiscali.cz)
 * Created:   2007-07-22
 * Copyright: Michal Bližňák
 * License:   wxWidgets license (www.wxwidgets.org)
 * Notes:
 **************************************************************/

#ifndef _WXSFDIAMONDSHAPE_H
#define _WXSFDIAMONDSHAPE_H

#include "PolygonShape.h"

/// <summary> Class encapsulating the diamond shape. It extends the basic polygon shape. </summary>
/// <seealso cref="wxSFPolygonShape"></seealso>
class WXDLLIMPEXP_SF wxSFDiamondShape : public wxSFPolygonShape
{
public:
    XS_DECLARE_CLONABLE_CLASS(wxSFDiamondShape);

    /// <summary> Default constructor </summary>
    wxSFDiamondShape();
    /// <summary> User constructor </summary>
    /// <param name="pos"> Initial position </param>
    /// <param name="manager"> Pointer to parent diagram manager </param>
	wxSFDiamondShape(const wxRealPoint& pos, wxSFDiagramManager* manager);
	/// <summary> Copy constructor </summary>
	/// <param name="obj"> Reference to the source object </param>
	wxSFDiamondShape(const wxSFDiamondShape& obj);
	/// <summary> Destructor </summary>
    virtual ~wxSFDiamondShape();

    // public virtual functions
    /// <summary> Test whether the given point is inside the shape. The function
    /// can be overrided if neccessary. </summary>
    /// <param name="pos"> Examined point </param>
    /// <returns> TRUE if the point is inside the shape area, otherwise FALSE </returns>
    virtual bool IsInside(const wxPoint& pos);
};

#endif //_WXSFDIAMONDSHAPE_H
