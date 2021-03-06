/*
    File: _ImproperRestraint_debugFiniteDifference.cc
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
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
fx1,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
fy1,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
fz1,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
fx2,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
fy2,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
fz2,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
fx3,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
fy3,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
fz3,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
fx4,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
fy4,
index);
TEST_FORCE( _evaluateEnergyOnly_ImproperRestraint,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
fz4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
dhx1x1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(-delta2 + x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohx1y1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(-delta2 + x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohx1z1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(-delta2 + x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohx1x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(-delta2 + x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohx1y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(-delta2 + x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohx1z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(-delta2 + x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
ohx1x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
ohx1y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
ohx1z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
ohx1x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
ohx1y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
ohx1z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
dhy1y1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, -delta2 + y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, -delta2 + y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohy1z1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, -delta2 + y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohy1x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, -delta2 + y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohy1y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, -delta2 + y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohy1z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, -delta2 + y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
ohy1x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
ohy1y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
ohy1z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
ohy1x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
ohy1y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
ohy1z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
dhz1z1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, -delta2 + z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohz1x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, -delta2 + z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohz1y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, -delta2 + z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohz1z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, -delta2 + z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
ohz1x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
ohz1y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
ohz1z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
ohz1x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
ohz1y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
ohz1z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
dhx2x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, -delta2 + x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohx2y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, -delta2 + x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohx2z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, -delta2 + x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
ohx2x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
ohx2y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
ohx2z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
ohx2x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
ohx2y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
ohx2z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
dhy2y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, -delta2 + y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
ohy2z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, -delta2 + y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
ohy2x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
ohy2y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
ohy2z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
ohy2x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
ohy2y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
ohy2z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, z4, K, L, U),
dhz2z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, -delta2 + z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
ohz2x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
ohz2y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
ohz2z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
ohz2x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
ohz2y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
ohz2z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, z4, K, L, U),
dhx3x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
ohx3y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
ohx3z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
ohx3x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
ohx3y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
ohx3z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, z4, K, L, U),
dhy3y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, delta2 + z3, x4, y4, z4, K, L, U),
ohy3z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, delta2 + x4, y4, z4, K, L, U),
ohy3x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, delta2 + y4, z4, K, L, U),
ohy3y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, x4, y4, delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, x4, y4, delta2 + z4, K, L, U),
ohy3z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, z4, K, L, U),
dhz3z3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, delta2 + x4, y4, z4, K, L, U),
ohz3x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, delta2 + y4, z4, K, L, U),
ohz3y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, x4, y4, delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, x4, y4, delta2 + z4, K, L, U),
ohz3z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, z4, K, L, U),
dhx4x4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, delta2 + y4, z4, K, L, U),
ohx4y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, -delta2 + x4, y4, delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, delta2 + x4, y4, delta2 + z4, K, L, U),
ohx4z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, z4, K, L, U),
dhy4y4,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, -delta2 + y4, delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, delta2 + y4, delta2 + z4, K, L, U),
ohy4z4,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_ImproperRestraint, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, -delta2 + z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, K, L, U),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, delta2 + z4, K, L, U),
dhz4z4,
index);
