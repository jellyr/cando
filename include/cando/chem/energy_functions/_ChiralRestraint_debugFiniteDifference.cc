/*
    File: _ChiralRestraint_debugFiniteDifference.cc
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
// FINITE_DIFFERENCE_TEST 
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
fx1,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
fy1,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
fz1,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
fx2,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
fy2,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
fz2,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
fx3,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
fy3,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
fz3,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
fx4,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
fy4,
index);
TEST_FORCE( _evaluateEnergyOnly_ChiralRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
fz4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
dhx1x1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(-delta2 + x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
ohx1y1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(-delta2 + x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
ohx1z1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(-delta2 + x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
ohx1x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(-delta2 + x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
ohx1y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(-delta2 + x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
ohx1z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(-delta2 + x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
ohx1x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
ohx1y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
ohx1z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
ohx1x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
ohx1y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
ohx1z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
dhy1y1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, -delta2 + y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, -delta2 + y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
ohy1z1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, -delta2 + y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
ohy1x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, -delta2 + y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
ohy1y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, -delta2 + y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
ohy1z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, -delta2 + y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
ohy1x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
ohy1y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
ohy1z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
ohy1x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
ohy1y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
ohy1z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
dhz1z1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, -delta2 + z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
ohz1x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, -delta2 + z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
ohz1y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, -delta2 + z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
ohz1z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, -delta2 + z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
ohz1x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
ohz1y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
ohz1z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
ohz1x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
ohz1y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
ohz1z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
dhx2x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, -delta2 + x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
ohx2y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, -delta2 + x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
ohx2z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, -delta2 + x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
ohx2x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
ohx2y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
ohx2z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
ohx2x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
ohx2y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
ohx2z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
dhy2y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, -delta2 + y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
ohy2z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, -delta2 + y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
ohy2x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
ohy2y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
ohy2z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
ohy2x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
ohy2y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
ohy2z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, CO),
dhz2z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, -delta2 + z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
ohz2x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
ohz2y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
ohz2z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
ohz2x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
ohz2y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
ohz2z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, CO),
dhx3x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, delta2 + y3, z3, x4, y4, z4, K, CO),
ohx3y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, delta2 + z3, x4, y4, z4, K, CO),
ohx3z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, delta2 + x4, y4, z4, K, CO),
ohx3x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, delta2 + y4, z4, K, CO),
ohx3y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, delta2 + z4, K, CO),
ohx3z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, CO),
dhy3y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, delta2 + z3, x4, y4, z4, K, CO),
ohy3z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, delta2 + x4, y4, z4, K, CO),
ohy3x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, delta2 + y4, z4, K, CO),
ohy3y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, delta2 + z4, K, CO),
ohy3z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, CO),
dhz3z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, delta2 + x4, y4, z4, K, CO),
ohz3x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, delta2 + y4, z4, K, CO),
ohz3y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, delta2 + z4, K, CO),
ohz3z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, CO),
dhx4x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, delta2 + y4, z4, K, CO),
ohx4y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, delta2 + z4, K, CO),
ohx4z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, CO),
dhy4y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, delta2 + z4, K, CO),
ohy4z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ChiralRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, CO),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, CO),
dhz4z4,
index);
