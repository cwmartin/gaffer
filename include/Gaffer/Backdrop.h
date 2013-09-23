//////////////////////////////////////////////////////////////////////////
//  
//  Copyright (c) 2013, Image Engine Design Inc. All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//  
//      * Redistributions of source code must retain the above
//        copyright notice, this list of conditions and the following
//        disclaimer.
//  
//      * Redistributions in binary form must reproduce the above
//        copyright notice, this list of conditions and the following
//        disclaimer in the documentation and/or other materials provided with
//        the distribution.
//  
//      * Neither the name of John Haddon nor the names of
//        any other contributors to this software may be used to endorse or
//        promote products derived from this software without specific prior
//        written permission.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//  
//////////////////////////////////////////////////////////////////////////

#ifndef GAFFER_BACKDROP_H
#define GAFFER_BACKDROP_H

#include "Gaffer/Node.h"

namespace Gaffer
{

/// The Backdrop node has no computational purpose - it is merely a placeholder
/// for an organisation tool in the user interface, implemented in GafferUI::BackdropNodeGadget.
class Backdrop : public Node
{

	public :

		Backdrop( const std::string &name=defaultName<Backdrop>() );
		virtual ~Backdrop();

		IE_CORE_DECLARERUNTIMETYPEDEXTENSION( Gaffer::Backdrop, BackdropTypeId, Node );
		
		StringPlug *titlePlug();
		const StringPlug *titlePlug() const;
		
		StringPlug *descriptionPlug();
		const StringPlug *descriptionPlug() const;
		
	private :
	
		static size_t g_firstPlugIndex;		
	
};

IE_CORE_DECLAREPTR( Backdrop )

typedef FilteredChildIterator<TypePredicate<Backdrop> > BackdropIterator;
typedef FilteredRecursiveChildIterator<TypePredicate<Backdrop> > RecursiveBackdropIterator;

} // namespace Gaffer

#endif // GAFFER_BACKDROP_H