#pragma once

#include "PolygonShape.h"

/// <summary> Class encapsulating the diamond shape. It extends the basic polygon shape. </summary>
/// <seealso cref="wxSFPolygonShape"></seealso>
class wxSFDiamondShape : public wxSFPolygonShape
{
public:
    DECLARE_DYNAMIC_CLASS(wxSFDiamondShape);

    /// <summary> Default constructor </summary>
    wxSFDiamondShape();
    /// <summary> User constructor </summary>
    /// <param name="pos"> Initial position </param>
    /// <param name="parentId"> ID of the parent shape </param>
    /// <param name="canvas"> Pointer to the parent canvas </param>
	wxSFDiamondShape(const wxRealPoint& pos, long parentId, wxSFShapeCanvas* canvas);
	/// <summary> Copy constructor </summary>
	/// <param name="obj"> Reference to the source object </param>
	wxSFDiamondShape(wxSFDiamondShape& obj);
	/// <summary> Destructor </summary>
    virtual ~wxSFDiamondShape();

	/// <summary> Clone the object itself. </summary>
	/// <returns> Pointer to a new instace of the shape object</returns>
	wxSFDiamondShape* Clone(){return new wxSFDiamondShape(*this);}

    // public virtual functions
    /// <summary> Test whether the given point is inside the shape. The function
    /// can be overrided if neccessary. </summary>
    /// <param name="pos"> Examined point </param>
    /// <returns> TRUE if the point is inside the shape area, otherwise FALSE </returns>
    virtual bool IsInside(const wxPoint& pos);
};


