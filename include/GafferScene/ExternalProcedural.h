//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2014, Image Engine Design Inc. All rights reserved.
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

#ifndef GAFFERSCENE_EXTERNALPROCEDURAL_H
#define GAFFERSCENE_EXTERNALPROCEDURAL_H

#include "Gaffer/CompoundDataPlug.h"

#include "GafferScene/ObjectSourceBase.h"

namespace GafferScene
{

class ExternalProcedural : public ObjectSource
{

	public :

		IE_CORE_DECLARERUNTIMETYPEDEXTENSION( GafferScene::ExternalProcedural, ExternalProceduralTypeId, ObjectSource );

		ExternalProcedural( const std::string &name=defaultName<ExternalProcedural>() );
		virtual ~ExternalProcedural();

		Gaffer::StringPlug *fileNamePlug();
		const Gaffer::StringPlug *fileNamePlug() const;

		Gaffer::Box3fPlug *boundPlug();
		const Gaffer::Box3fPlug *boundPlug() const;

		Gaffer::CompoundDataPlug *parametersPlug();
		const Gaffer::CompoundDataPlug *parametersPlug() const;

		virtual void affects( const Gaffer::Plug *input, AffectedPlugsContainer &outputs ) const;

	protected :

		virtual void hashSource( const Gaffer::Context *context, IECore::MurmurHash &h ) const;
		virtual IECore::ConstObjectPtr computeSource( const Gaffer::Context *context ) const;

	private :

		static size_t g_firstPlugIndex;

};

IE_CORE_DECLAREPTR( ExternalProcedural )

} // namespace GafferScene

#endif // GAFFERSCENE_EXTERNALPROCEDURAL_H
