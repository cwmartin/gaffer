//////////////////////////////////////////////////////////////////////////
//  
//  Copyright (c) 2011-2012, John Haddon. All rights reserved.
//  Copyright (c) 2011, Image Engine Design Inc. All rights reserved.
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

#ifndef GAFFERBINDINGS_NODEBINDING_H
#define GAFFERBINDINGS_NODEBINDING_H

#include "boost/python.hpp"
#include "boost/python/suite/indexing/container_utils.hpp"

#include "IECorePython/ScopedGILLock.h"

#include "Gaffer/Node.h"
#include "Gaffer/Context.h"
#include "Gaffer/ValuePlug.h"

#include "GafferBindings/GraphComponentBinding.h"

namespace GafferBindings
{

void bindNode();

template<typename T, typename Ptr=IECore::IntrusivePtr<T> >
class NodeClass : public IECorePython::RunTimeTypedClass<T, Ptr>
{
	public :
	
		NodeClass( const char *docString = 0 );
		
};

#define GAFFERBINDINGS_NODEWRAPPERFNS( CLASSNAME )\
	GAFFERBINDINGS_GRAPHCOMPONENTWRAPPERFNS( CLASSNAME )\
\
	virtual void affects( const Gaffer::ValuePlug *input, AffectedPlugsContainer &outputs ) const\
	{\
		IECorePython::ScopedGILLock gilLock;\
		if( PyObject_HasAttrString( m_pyObject, "affects" ) )\
		{\
			boost::python::override f = this->get_override( "affects" );\
			if( f )\
			{\
				boost::python::list pythonOutputs = f( Gaffer::ValuePlugPtr( const_cast<Gaffer::ValuePlug *>( input ) ) );\
				boost::python::container_utils::extend_container( outputs, pythonOutputs );\
				return;\
			}\
		}\
		CLASSNAME::affects( input, outputs );\
	}\
\
	virtual void compute( Gaffer::ValuePlug *output, const Gaffer::Context *context ) const\
	{\
		IECorePython::ScopedGILLock gilLock;\
		if( PyObject_HasAttrString( m_pyObject, "compute" ) )\
		{\
			boost::python::override f = this->get_override( "compute" );\
			if( f )\
			{\
				f( Gaffer::ValuePlugPtr( output ), Gaffer::ContextPtr( const_cast<Gaffer::Context *>( context ) ) );\
				return;\
			}\
		}\
		CLASSNAME::compute( output, context );\
	}

void initNode( Gaffer::Node *node, const boost::python::dict &inputs, const boost::python::tuple &dynamicPlugs );

} // namespace GafferBindings

#include "GafferBindings/NodeBinding.inl"

#endif // GAFFERBINDINGS_NODEBINDING_H