#include "FixedRectShape.h"

IMPLEMENT_DYNAMIC_CLASS(wxSFSquareShape, wxSFRectShape);

wxSFSquareShape::wxSFSquareShape(void)
: wxSFRectShape()
{
    SetRectSize(100, 100);
}

wxSFSquareShape::wxSFSquareShape(const wxRealPoint& pos, double size, long parentId, wxSFShapeCanvas* canvas)
: wxSFRectShape(pos, wxRealPoint(size, size), parentId, canvas)
{

}

wxSFSquareShape::wxSFSquareShape(wxSFSquareShape& obj)
: wxSFRectShape(obj)
{

}

wxSFSquareShape::~wxSFSquareShape()
{

}

//----------------------------------------------------------------------------------//
// public virtual functions
//----------------------------------------------------------------------------------//

void wxSFSquareShape::Scale(double x, double y)
{
	// HINT: overload it for custom actions...

	if((x > 0) && (y > 0))
	{
	    double s = 1;

        if(x == 1) s = y;
        else if (y == 1) s = x;
	    else if(x >= y) s = x;
	    else
            s = y;

		SetRectSize(m_nRectSize.x * s, m_nRectSize.y * s);
	}
}

void wxSFSquareShape::OnHandle(wxSFShapeHandle& handle)
{
    // HINT: overload it for custom actions...

    double maxsize = 0, dx = 0, dy = 0;

    wxRealPoint prevSize = m_nRectSize;

    // perform standard operations
	switch(handle.GetType())
	{
    case wxSFShapeHandle::hndLEFTTOP:
	case wxSFShapeHandle::hndLEFT:
	case wxSFShapeHandle::hndLEFTBOTTOM:
		OnLeftHandle(handle);
		break;

    case wxSFShapeHandle::hndRIGHTTOP:
	case wxSFShapeHandle::hndRIGHT:
	case wxSFShapeHandle::hndRIGHTBOTTOM:
		OnRightHandle(handle);
		break;

	case wxSFShapeHandle::hndTOP:
		OnTopHandle(handle);
		break;

	case wxSFShapeHandle::hndBOTTOM:
		OnBottomHandle(handle);
		break;

    default:
        break;
	}

    // calculate common size and some auxilary values
    if((prevSize.x < m_nRectSize.x) || (prevSize.y < m_nRectSize.y))
    {
        if(m_nRectSize.x >= m_nRectSize.y)maxsize = m_nRectSize.x;
        else
            maxsize = m_nRectSize.y;
    }
    else
    {
        if(m_nRectSize.x <= m_nRectSize.y)maxsize = m_nRectSize.x;
        else
            maxsize = m_nRectSize.y;
    }

    dx = maxsize - m_nRectSize.x;
    dy = maxsize - m_nRectSize.y;

    // normalize rect sizes
    m_nRectSize.x = m_nRectSize.y = maxsize;

    // move rect if neccessary
    switch(handle.GetType())
	{
	case wxSFShapeHandle::hndLEFT:
        MoveBy(-dx, -dy/2);
		break;

	case wxSFShapeHandle::hndLEFTTOP:
        MoveBy(-dx, -dy);
		break;

	case wxSFShapeHandle::hndLEFTBOTTOM:
        MoveBy(-dx, 0);
		break;

	case wxSFShapeHandle::hndRIGHT:
        MoveBy(0, -dy/2);
		break;

	case wxSFShapeHandle::hndRIGHTTOP:
        MoveBy(0, -dy);
		break;

	case wxSFShapeHandle::hndTOP:
        MoveBy(-dx/2, -dy);
		break;

	case wxSFShapeHandle::hndBOTTOM:
        MoveBy(-dx/2, 0);
		break;

    default:
        break;
	}
}
