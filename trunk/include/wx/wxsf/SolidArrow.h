/***************************************************************
 * Name:      SolidArrow.h
 * Purpose:   Defines solid arrow for line shapes
 * Author:    Michal Bližňák (michal.bliznak@tiscali.cz)
 * Created:   2007-07-22
 * Copyright: Michal Bližňák
 * License:   wxWidgets license (www.wxwidgets.org)
 * Notes:
 **************************************************************/

#ifndef _WXSFSOLIDARROW_H
#define _WXSFSOLIDARROW_H

#include "ArrowBase.h"

/*!
 * \brief Class extends the wxSFArrowBase class and encapsulates
 * arrow shape consisting of a solid triangle pointing to the end of the
 * parent line shape.
 */
class WXDLLIMPEXP_SF wxSFSolidArrow :	public wxSFArrowBase
{
public:
	XS_DECLARE_CLONABLE_CLASS(wxSFSolidArrow);

    /*! \brief Default constructor. */
	wxSFSolidArrow(void);
	/*!
     * \brief User constructor.
	 * \param parent Pointer to the parent shape
	 */
	wxSFSolidArrow(wxSFShapeBase* parent);
    /*!
     * \brief Copy constructor.
	 * \param obj Reference to the source object
	 */
	wxSFSolidArrow(const wxSFSolidArrow& obj);
	/*! \brief Destructor. */
	virtual ~wxSFSolidArrow(void);

	// public functions

	// public member data accessors
	/*!
     * \brief Set a brush filling the arrow's body.
	 * \param br Reference to the brush object
	 */
	void SetArrowFill(const wxBrush& br){m_Fill = br;}
	/*!
     * \brief Get current brush used for filling of the arrow's body.
	 * \return Used brush
	 */
	wxBrush GetArrowFill() const {return m_Fill;}
	
	// public virtual functions
	/*!
     * \brief Draw arrow shape at the end of a virtual line.
	 * \param from Start of the virtual line
	 * \param to End of the virtual line
	 * \param dc Device context for drawing
	 */
	virtual void Draw(const wxRealPoint& from, const wxRealPoint& to, wxDC& dc);

protected:
	// protected data members
	/*! \brief Arrows brush. */
	wxBrush m_Fill;
};

#endif //_WXSFSOLIDARROW_H
