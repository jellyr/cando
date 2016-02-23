/*
    File: units.h
*/
/*
Open Source License
Copyright (c) 2016, Christian E. Schafmeister
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 
This is an open source license for the CANDO software from Temple University, but it is not the only one. Contact Temple University at mailto:techtransfer@temple.edu if you would like a different license.
*/
/* -^- */
#ifndef chem_units_H
#define chem_units_H

#if 0
#include <boost/mpl/list.hpp>
#include <boost/units/conversion.hpp>
#include <boost/units/io.hpp>
#include <boost/units/pow.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/prefixes.hpp>
using namespace boost::units;

#endif


namespace chem
{



    static const double Const_kJ_per_kCal = 4.1868;



inline double angstrom_to_nanometer(double val)
{
    return val/10.0;
}


inline double kCalPerAngstromSquared_to_kJPerNanometerSquared(double val)
{
	return val*Const_kJ_per_kCal*100.0;
}

inline double kJPerNanometerSquared_to_kCalPerAngstromSquared(double val)
{
    return val/100.0/Const_kJ_per_kCal;
}

inline double kCalPerRadianSquared_to_kJPerRadianSquared(double val)
{
    return val*Const_kJ_per_kCal;
}

inline double kJPerRadianSquared_to_kCalPerRadianSquared(double val)
{
    return val/Const_kJ_per_kCal;
}

inline double kCal_to_kJ(double val)
{
    return val*Const_kJ_per_kCal;
}

inline double kJ_to_kCal(double val)
{
    return val/Const_kJ_per_kCal;
}



};
#endif
