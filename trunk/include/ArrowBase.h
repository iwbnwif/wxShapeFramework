#pragma once

#include "ShapeBase.h"

class wxSFLineShape;
/// <summary> Base class for a line arrows </summary>
class wxSFArrowBase :	public wxObject
{
public:
	friend class wxSFLineShape;

	DECLARE_DYNAMIC_CLASS(wxSFArrowBase);
    /// <summary> Default constructor </summary>
	wxSFArrowBase(void);
	/// <summary> Constructor </summary>
	/// <param name="parent"> Pointer to a parent shape </param>
	wxSFArrowBase(wxSFShapeBase* parent);
	/// <summary> Copy constructor </summary>
	/// <param name="obj"> Source base arrow shape </param>
	wxSFArrowBase(wxSFArrowBase& obj);
	/// <summary> Destructor </summary>
	~wxSFArrowBase(void);

	// public member data accessors
	/// <summary> Set a parent of the arrow shape </summary>
	/// <param name="parent"> Pointer to the parent shape </param>
	void SetParentShape(wxSFShapeBase* parent){m_pParentShape = parent;}
	/// <summary> Get pointer to a parent shape </summary>
	/// <returns> Pointer to a parent shape if exists, otherwise NULL </returns>
	wxSFShapeBase* GetParentShape(){return m_pParentShape;}

	// public functions
	/// <summary> Clone the arrow shape </summary>
	/// <returns> Pointer to a new instace of the arrow shape </returns>
	wxSFArrowBase* Clone(){return new wxSFArrowBase(*this);}

	// public virtual functions
	/// <summary> Draw arrow shape at the end of a virtual line </summary>
	/// <param name="from"> Start of the virtual line </param>
	/// <param name="to"> End of the virtual line </param>
	/// <param name="dc"> Device context for drawing </param>
	virtual void Draw(const wxRealPoint& from, const wxRealPoint& to, wxSFScaledPaintDC& dc);

protected:

	// protected member data
	/// <summary> Pointer to a parent shape </summary>
	wxSFShapeBase* m_pParentShape;

	// protected virtual functions
	/// <summary> Serialize shape's properties to the given XML node </summary>
	/// <param name="node"> Pointer to XML node where the shape's property nodes will be append to </param>
	/// <seealso cref="wxSFShapeBase::Serialize"></seealso>
	virtual wxXmlNode* Serialize(wxXmlNode* node);
	/// <summary> Deserialize shape's properties from the given XML node </summary>
	/// <param name="node"> Source XML node containig the shape's property nodes</param>
	/// <seealso cref="wxSFShapeBase::Deserialize"></seealso>
	virtual void Deserialize(wxXmlNode* node);
};

