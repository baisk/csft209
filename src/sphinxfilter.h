//
// $Id$
//

//
// Copyright (c) 2001-2013, Andrew Aksyonoff
// Copyright (c) 2008-2013, Sphinx Technologies Inc
// All rights reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License. You should have
// received a copy of the GPL license along with this program; if you
// did not, you can find it at http://www.gnu.org/
//

#ifndef _sphinxfilter_
#define _sphinxfilter_

#include "sphinx.h"

struct ISphFilter
{
	virtual void SetLocator ( const CSphAttrLocator & ) {}
	virtual void SetRange ( SphAttr_t, SphAttr_t ) {}
	virtual void SetRangeFloat ( float, float ) {}
	virtual void SetValues ( const SphAttr_t *, int ) {}
	virtual void SetMVAStorage ( const DWORD * ) {}

	virtual ~ISphFilter () {}

	/// evaluate filter for a given match
	/// returns true if match satisfies the filter critertia (i.e. in range, found in values list etc)
	virtual bool Eval ( const CSphMatch & tMatch ) const = 0;

	/// evaluate filter for a given block
	/// args are pMinDocinfo and pMaxDocinfo
	/// returns false if no document in block can possibly pass through the filter
	virtual bool EvalBlock ( const DWORD *, const DWORD * ) const
	{
		// if filter does not implement block-level evaluation we assume the block will pass
		return true;
	}

	virtual ISphFilter * Join ( ISphFilter * pFilter );

	bool UsesAttrs() const { return m_bUsesAttrs; }

	ISphFilter() : m_bUsesAttrs ( true ) {}

protected :

	bool m_bUsesAttrs;
};

ISphFilter * sphCreateFilter ( const CSphFilterSettings &, const CSphSchema &, const DWORD * pMva, CSphString & sError );
ISphFilter * sphJoinFilters ( ISphFilter *, ISphFilter * );

#endif // _sphinxfilter_

//
// $Id$
//
