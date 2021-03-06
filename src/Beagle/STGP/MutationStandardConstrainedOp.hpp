/*
 *  Open BEAGLE
 *  Copyright (C) 2001-2007 by Christian Gagne and Marc Parizeau
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact:
 *  Laboratoire de Vision et Systemes Numeriques
 *  Departement de genie electrique et de genie informatique
 *  Universite Laval, Quebec, Canada, G1K 7P4
 *  http://vision.gel.ulaval.ca
 *
 */

/*!
 *  \file   beagle/GP/MutationStandardConstrainedOp.hpp
 *  \brief  Definition of the class GP::MutationStandardConstrainedOp.
 *  \author Christian Gagne
 *  \author Marc Parizeau
 *  $Revision: 1.13 $
 *  $Date: 2007/08/08 19:26:35 $
 */

#ifndef Beagle_STGP_MutationStandardConstrainedOp_hpp
#define Beagle_STGP_MutationStandardConstrainedOp_hpp

#include <string>

#include "Beagle/config.hpp"
#include "Beagle/macros.hpp"
#include "Beagle/Core/Object.hpp"
#include "Beagle/EC/MutationOp.hpp"
#include "Beagle/Core/UInt.hpp"
#include "Beagle/Core/Float.hpp"
#include "Beagle/Core/Bool.hpp"
#include "Beagle/GP/Context.hpp"
#include "Beagle/GP/Individual.hpp"
#include "Beagle/GP/MutationStandardOp.hpp"
#include "Beagle/STGP/InitGrowConstrainedOp.hpp"

namespace Beagle
{
namespace STGP
{

/*!
 *  \class MutationStandardConstrainedOp
 *    beagle/GP/MutationStandardConstrainedOp.hpp "beagle/GP/MutationStandardConstrainedOp.hpp"
 *  \brief GP standard mutation operator class, as described in Genetic Programming I.
 *  \ingroup GPF
 *  \ingroup GPOp
 */
class MutationStandardConstrainedOp : public GP::MutationStandardOp
{

public:

	//! GP::MutationStandardConstrainedOp allocator type.
	typedef AllocatorT<MutationStandardConstrainedOp,GP::MutationStandardOp::Alloc>
	Alloc;
	//! GP::MutationStandardConstrainedOp handle type.
	typedef PointerT<MutationStandardConstrainedOp,GP::MutationStandardOp::Handle>
	Handle;
	//! GP::MutationStandardConstrainedOp bag type.
	typedef ContainerT<MutationStandardConstrainedOp,GP::MutationStandardOp::Bag>
	Bag;

	explicit MutationStandardConstrainedOp(GP::InitializationOp::Handle inInitOp=
	                                           new Beagle::STGP::InitGrowConstrainedOp,
	                                       std::string inMutationPbName="gp.mutstd.indpb",
	                                       std::string inMaxRegenDepthName="gp.mutstd.maxdepth",
	                                       std::string inName="GP-MutationStandardConstrainedOp");
	virtual ~MutationStandardConstrainedOp()
	{ }

	virtual void registerParams(Beagle::System& ioSystem);
	virtual bool mutate(Beagle::Individual& ioIndividual, Beagle::Context& ioContext);

protected:

	UInt::Handle  mNumberAttempts;  //!< Number of attempts in each initialization.

};

}
}

#endif // Beagle_GP_MutationStandardConstrainedOp_hpp
