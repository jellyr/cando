/*
    File: _ImproperRestraint_debugEvalSerialize.cc
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
// XML_EVAL
	node->attributeIfNotDefault("evalx1", this->eval.x1, 0.0 );
 	node->attributeIfNotDefault("evaly1", this->eval.y1, 0.0 );
 	node->attributeIfNotDefault("evalz1", this->eval.z1, 0.0 );
 	node->attributeIfNotDefault("evalx2", this->eval.x2, 0.0 );
 	node->attributeIfNotDefault("evaly2", this->eval.y2, 0.0 );
 	node->attributeIfNotDefault("evalz2", this->eval.z2, 0.0 );
 	node->attributeIfNotDefault("evalx3", this->eval.x3, 0.0 );
 	node->attributeIfNotDefault("evaly3", this->eval.y3, 0.0 );
 	node->attributeIfNotDefault("evalz3", this->eval.z3, 0.0 );
 	node->attributeIfNotDefault("evalx4", this->eval.x4, 0.0 );
 	node->attributeIfNotDefault("evaly4", this->eval.y4, 0.0 );
 	node->attributeIfNotDefault("evalz4", this->eval.z4, 0.0 );
 	node->attributeIfNotDefault("evalK", this->eval.K, 0.0 );
 	node->attributeIfNotDefault("evalL", this->eval.L, 0.0 );
 	node->attributeIfNotDefault("evalU", this->eval.U, 0.0 );
 	node->attributeIfNotDefault("evalEnergy", this->eval.Energy, 0.0 );
 	node->attributeIfNotDefault("evalfx1", this->eval.fx1, 0.0 );
 	node->attributeIfNotDefault("evalfy1", this->eval.fy1, 0.0 );
 	node->attributeIfNotDefault("evalfz1", this->eval.fz1, 0.0 );
 	node->attributeIfNotDefault("evalfx2", this->eval.fx2, 0.0 );
 	node->attributeIfNotDefault("evalfy2", this->eval.fy2, 0.0 );
 	node->attributeIfNotDefault("evalfz2", this->eval.fz2, 0.0 );
 	node->attributeIfNotDefault("evalfx3", this->eval.fx3, 0.0 );
 	node->attributeIfNotDefault("evalfy3", this->eval.fy3, 0.0 );
 	node->attributeIfNotDefault("evalfz3", this->eval.fz3, 0.0 );
 	node->attributeIfNotDefault("evalfx4", this->eval.fx4, 0.0 );
 	node->attributeIfNotDefault("evalfy4", this->eval.fy4, 0.0 );
 	node->attributeIfNotDefault("evalfz4", this->eval.fz4, 0.0 );
 	node->attributeIfNotDefault("evaldhx1x1", this->eval.dhx1x1, 0.0 );
 	node->attributeIfNotDefault("evaldhy1y1", this->eval.dhy1y1, 0.0 );
 	node->attributeIfNotDefault("evaldhz1z1", this->eval.dhz1z1, 0.0 );
 	node->attributeIfNotDefault("evaldhx2x2", this->eval.dhx2x2, 0.0 );
 	node->attributeIfNotDefault("evaldhy2y2", this->eval.dhy2y2, 0.0 );
 	node->attributeIfNotDefault("evaldhz2z2", this->eval.dhz2z2, 0.0 );
 	node->attributeIfNotDefault("evaldhx3x3", this->eval.dhx3x3, 0.0 );
 	node->attributeIfNotDefault("evaldhy3y3", this->eval.dhy3y3, 0.0 );
 	node->attributeIfNotDefault("evaldhz3z3", this->eval.dhz3z3, 0.0 );
 	node->attributeIfNotDefault("evaldhx4x4", this->eval.dhx4x4, 0.0 );
 	node->attributeIfNotDefault("evaldhy4y4", this->eval.dhy4y4, 0.0 );
 	node->attributeIfNotDefault("evaldhz4z4", this->eval.dhz4z4, 0.0 );
 	node->attributeIfNotDefault("evalohx1y1", this->eval.ohx1y1, 0.0 );
 	node->attributeIfNotDefault("evalohx1z1", this->eval.ohx1z1, 0.0 );
 	node->attributeIfNotDefault("evalohx1x2", this->eval.ohx1x2, 0.0 );
 	node->attributeIfNotDefault("evalohx1y2", this->eval.ohx1y2, 0.0 );
 	node->attributeIfNotDefault("evalohx1z2", this->eval.ohx1z2, 0.0 );
 	node->attributeIfNotDefault("evalohx1x3", this->eval.ohx1x3, 0.0 );
 	node->attributeIfNotDefault("evalohx1y3", this->eval.ohx1y3, 0.0 );
 	node->attributeIfNotDefault("evalohx1z3", this->eval.ohx1z3, 0.0 );
 	node->attributeIfNotDefault("evalohx1x4", this->eval.ohx1x4, 0.0 );
 	node->attributeIfNotDefault("evalohx1y4", this->eval.ohx1y4, 0.0 );
 	node->attributeIfNotDefault("evalohx1z4", this->eval.ohx1z4, 0.0 );
 	node->attributeIfNotDefault("evalohy1z1", this->eval.ohy1z1, 0.0 );
 	node->attributeIfNotDefault("evalohy1x2", this->eval.ohy1x2, 0.0 );
 	node->attributeIfNotDefault("evalohy1y2", this->eval.ohy1y2, 0.0 );
 	node->attributeIfNotDefault("evalohy1z2", this->eval.ohy1z2, 0.0 );
 	node->attributeIfNotDefault("evalohy1x3", this->eval.ohy1x3, 0.0 );
 	node->attributeIfNotDefault("evalohy1y3", this->eval.ohy1y3, 0.0 );
 	node->attributeIfNotDefault("evalohy1z3", this->eval.ohy1z3, 0.0 );
 	node->attributeIfNotDefault("evalohy1x4", this->eval.ohy1x4, 0.0 );
 	node->attributeIfNotDefault("evalohy1y4", this->eval.ohy1y4, 0.0 );
 	node->attributeIfNotDefault("evalohy1z4", this->eval.ohy1z4, 0.0 );
 	node->attributeIfNotDefault("evalohz1x2", this->eval.ohz1x2, 0.0 );
 	node->attributeIfNotDefault("evalohz1y2", this->eval.ohz1y2, 0.0 );
 	node->attributeIfNotDefault("evalohz1z2", this->eval.ohz1z2, 0.0 );
 	node->attributeIfNotDefault("evalohz1x3", this->eval.ohz1x3, 0.0 );
 	node->attributeIfNotDefault("evalohz1y3", this->eval.ohz1y3, 0.0 );
 	node->attributeIfNotDefault("evalohz1z3", this->eval.ohz1z3, 0.0 );
 	node->attributeIfNotDefault("evalohz1x4", this->eval.ohz1x4, 0.0 );
 	node->attributeIfNotDefault("evalohz1y4", this->eval.ohz1y4, 0.0 );
 	node->attributeIfNotDefault("evalohz1z4", this->eval.ohz1z4, 0.0 );
 	node->attributeIfNotDefault("evalohx2y2", this->eval.ohx2y2, 0.0 );
 	node->attributeIfNotDefault("evalohx2z2", this->eval.ohx2z2, 0.0 );
 	node->attributeIfNotDefault("evalohx2x3", this->eval.ohx2x3, 0.0 );
 	node->attributeIfNotDefault("evalohx2y3", this->eval.ohx2y3, 0.0 );
 	node->attributeIfNotDefault("evalohx2z3", this->eval.ohx2z3, 0.0 );
 	node->attributeIfNotDefault("evalohx2x4", this->eval.ohx2x4, 0.0 );
 	node->attributeIfNotDefault("evalohx2y4", this->eval.ohx2y4, 0.0 );
 	node->attributeIfNotDefault("evalohx2z4", this->eval.ohx2z4, 0.0 );
 	node->attributeIfNotDefault("evalohy2z2", this->eval.ohy2z2, 0.0 );
 	node->attributeIfNotDefault("evalohy2x3", this->eval.ohy2x3, 0.0 );
 	node->attributeIfNotDefault("evalohy2y3", this->eval.ohy2y3, 0.0 );
 	node->attributeIfNotDefault("evalohy2z3", this->eval.ohy2z3, 0.0 );
 	node->attributeIfNotDefault("evalohy2x4", this->eval.ohy2x4, 0.0 );
 	node->attributeIfNotDefault("evalohy2y4", this->eval.ohy2y4, 0.0 );
 	node->attributeIfNotDefault("evalohy2z4", this->eval.ohy2z4, 0.0 );
 	node->attributeIfNotDefault("evalohz2x3", this->eval.ohz2x3, 0.0 );
 	node->attributeIfNotDefault("evalohz2y3", this->eval.ohz2y3, 0.0 );
 	node->attributeIfNotDefault("evalohz2z3", this->eval.ohz2z3, 0.0 );
 	node->attributeIfNotDefault("evalohz2x4", this->eval.ohz2x4, 0.0 );
 	node->attributeIfNotDefault("evalohz2y4", this->eval.ohz2y4, 0.0 );
 	node->attributeIfNotDefault("evalohz2z4", this->eval.ohz2z4, 0.0 );
 	node->attributeIfNotDefault("evalohx3y3", this->eval.ohx3y3, 0.0 );
 	node->attributeIfNotDefault("evalohx3z3", this->eval.ohx3z3, 0.0 );
 	node->attributeIfNotDefault("evalohx3x4", this->eval.ohx3x4, 0.0 );
 	node->attributeIfNotDefault("evalohx3y4", this->eval.ohx3y4, 0.0 );
 	node->attributeIfNotDefault("evalohx3z4", this->eval.ohx3z4, 0.0 );
 	node->attributeIfNotDefault("evalohy3z3", this->eval.ohy3z3, 0.0 );
 	node->attributeIfNotDefault("evalohy3x4", this->eval.ohy3x4, 0.0 );
 	node->attributeIfNotDefault("evalohy3y4", this->eval.ohy3y4, 0.0 );
 	node->attributeIfNotDefault("evalohy3z4", this->eval.ohy3z4, 0.0 );
 	node->attributeIfNotDefault("evalohz3x4", this->eval.ohz3x4, 0.0 );
 	node->attributeIfNotDefault("evalohz3y4", this->eval.ohz3y4, 0.0 );
 	node->attributeIfNotDefault("evalohz3z4", this->eval.ohz3z4, 0.0 );
 	node->attributeIfNotDefault("evalohx4y4", this->eval.ohx4y4, 0.0 );
 	node->attributeIfNotDefault("evalohx4z4", this->eval.ohx4z4, 0.0 );
 	node->attributeIfNotDefault("evalohy4z4", this->eval.ohy4z4, 0.0 );
 	node->attributeIfNotDefault("evalPhi", this->eval.Phi, 0.0 );
