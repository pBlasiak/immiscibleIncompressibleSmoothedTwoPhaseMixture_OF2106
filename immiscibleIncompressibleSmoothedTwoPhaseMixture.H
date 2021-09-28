/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2014-2015 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::immiscibleIncompressibleSmoothedTwoPhaseMixture

Description
    An immiscible incompressible two-phase mixture transport model

SourceFiles
    immiscibleIncompressibleSmoothedTwoPhaseMixture.C

\*---------------------------------------------------------------------------*/

#ifndef immiscibleIncompressibleSmoothedTwoPhaseMixture_H
#define immiscibleIncompressibleSmoothedTwoPhaseMixture_H

#include "incompressibleTwoPhaseMixture.H"
#include "smoothedInterfaceProperties.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
           Class immiscibleIncompressibleSmoothedTwoPhaseMixture Declaration
\*---------------------------------------------------------------------------*/

class immiscibleIncompressibleSmoothedTwoPhaseMixture
:
    public incompressibleTwoPhaseMixture,
    public smoothedInterfaceProperties
{

public:

    // Constructors

        //- Construct from components
        immiscibleIncompressibleSmoothedTwoPhaseMixture
        (
            const volVectorField& U,
            const surfaceScalarField& phi
        );


    //- Destructor
    virtual ~immiscibleIncompressibleSmoothedTwoPhaseMixture()
    {}


    // Member Functions

        //- Correct the transport and interface properties
        virtual void correct()
        {
            incompressibleTwoPhaseMixture::correct();
            smoothedInterfaceProperties::correct();
        }

        //- Read base transportProperties dictionary
        virtual bool read()
        {
            return
                incompressibleTwoPhaseMixture::read()
             && smoothedInterfaceProperties::read();
        }
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
