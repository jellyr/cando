// FINITE_DIFFERENCE_TEST 
TEST_FORCE( _evaluateEnergyOnly_Angle,  delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
fx1,
index);
TEST_FORCE( _evaluateEnergyOnly_Angle,  delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
fy1,
index);
TEST_FORCE( _evaluateEnergyOnly_Angle,  delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
fz1,
index);
TEST_FORCE( _evaluateEnergyOnly_Angle,  delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
fx2,
index);
TEST_FORCE( _evaluateEnergyOnly_Angle,  delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, t0, kt),
fy2,
index);
TEST_FORCE( _evaluateEnergyOnly_Angle,  delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, t0, kt),
fz2,
index);
TEST_FORCE( _evaluateEnergyOnly_Angle,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, t0, kt),
fx3,
index);
TEST_FORCE( _evaluateEnergyOnly_Angle,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, t0, kt),
fy3,
index);
TEST_FORCE( _evaluateEnergyOnly_Angle,  delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, t0, kt),
fz3,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle, delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
dhx1x1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(-delta2 + x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(delta2 + x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(-delta2 + x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(delta2 + x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
ohx1y1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(-delta2 + x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
(delta2 + x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
(-delta2 + x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
(delta2 + x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
ohx1z1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(-delta2 + x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(delta2 + x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(-delta2 + x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(delta2 + x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
ohx1x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, t0, kt),
(delta2 + x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, t0, kt),
(-delta2 + x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, t0, kt),
(delta2 + x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, t0, kt),
ohx1y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, t0, kt),
(delta2 + x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, t0, kt),
(-delta2 + x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, t0, kt),
(delta2 + x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, t0, kt),
ohx1z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, t0, kt),
(delta2 + x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, t0, kt),
(-delta2 + x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, t0, kt),
(delta2 + x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, t0, kt),
ohx1x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, t0, kt),
(delta2 + x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, t0, kt),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, t0, kt),
(delta2 + x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, t0, kt),
ohx1y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, t0, kt),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, t0, kt),
(-delta2 + x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, t0, kt),
(delta2 + x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, t0, kt),
ohx1z3,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle, delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
dhy1y1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, -delta2 + y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, delta2 + y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, -delta2 + y1, delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, delta2 + y1, delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
ohy1z1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, -delta2 + y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(x1, delta2 + y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(x1, -delta2 + y1, z1, delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(x1, delta2 + y1, z1, delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
ohy1x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, delta2 + y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, -delta2 + y1, z1, x2, delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, delta2 + y1, z1, x2, delta2 + y2, z2, x3, y3, z3, t0, kt),
ohy1y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, t0, kt),
(x1, delta2 + y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, t0, kt),
(x1, -delta2 + y1, z1, x2, y2, delta2 + z2, x3, y3, z3, t0, kt),
(x1, delta2 + y1, z1, x2, y2, delta2 + z2, x3, y3, z3, t0, kt),
ohy1z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, t0, kt),
(x1, delta2 + y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, t0, kt),
(x1, -delta2 + y1, z1, x2, y2, z2, delta2 + x3, y3, z3, t0, kt),
(x1, delta2 + y1, z1, x2, y2, z2, delta2 + x3, y3, z3, t0, kt),
ohy1x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, t0, kt),
(x1, delta2 + y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, t0, kt),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, delta2 + y3, z3, t0, kt),
(x1, delta2 + y1, z1, x2, y2, z2, x3, delta2 + y3, z3, t0, kt),
ohy1y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, t0, kt),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, t0, kt),
(x1, -delta2 + y1, z1, x2, y2, z2, x3, y3, delta2 + z3, t0, kt),
(x1, delta2 + y1, z1, x2, y2, z2, x3, y3, delta2 + z3, t0, kt),
ohy1z3,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle, delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, z3, t0, kt),
dhz1z1,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, -delta2 + z1, -delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, delta2 + z1, -delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, -delta2 + z1, delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, delta2 + z1, delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
ohz1x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, -delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, y1, delta2 + z1, x2, -delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, y1, -delta2 + z1, x2, delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, y1, delta2 + z1, x2, delta2 + y2, z2, x3, y3, z3, t0, kt),
ohz1y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, -delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, delta2 + z1, x2, y2, -delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, -delta2 + z1, x2, y2, delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, delta2 + z1, x2, y2, delta2 + z2, x3, y3, z3, t0, kt),
ohz1z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, -delta2 + x3, y3, z3, t0, kt),
(x1, y1, delta2 + z1, x2, y2, z2, -delta2 + x3, y3, z3, t0, kt),
(x1, y1, -delta2 + z1, x2, y2, z2, delta2 + x3, y3, z3, t0, kt),
(x1, y1, delta2 + z1, x2, y2, z2, delta2 + x3, y3, z3, t0, kt),
ohz1x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, -delta2 + y3, z3, t0, kt),
(x1, y1, delta2 + z1, x2, y2, z2, x3, -delta2 + y3, z3, t0, kt),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, delta2 + y3, z3, t0, kt),
(x1, y1, delta2 + z1, x2, y2, z2, x3, delta2 + y3, z3, t0, kt),
ohz1y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, -delta2 + z3, t0, kt),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, -delta2 + z3, t0, kt),
(x1, y1, -delta2 + z1, x2, y2, z2, x3, y3, delta2 + z3, t0, kt),
(x1, y1, delta2 + z1, x2, y2, z2, x3, y3, delta2 + z3, t0, kt),
ohz1z3,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle, delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, z3, t0, kt),
dhx2x2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, -delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, delta2 + x2, -delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, -delta2 + x2, delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, delta2 + x2, delta2 + y2, z2, x3, y3, z3, t0, kt),
ohx2y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, -delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, z1, delta2 + x2, y2, -delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, z1, -delta2 + x2, y2, delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, z1, delta2 + x2, y2, delta2 + z2, x3, y3, z3, t0, kt),
ohx2z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, -delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, delta2 + x2, y2, z2, -delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, -delta2 + x2, y2, z2, delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, delta2 + x2, y2, z2, delta2 + x3, y3, z3, t0, kt),
ohx2x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, -delta2 + y3, z3, t0, kt),
(x1, y1, z1, delta2 + x2, y2, z2, x3, -delta2 + y3, z3, t0, kt),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, delta2 + y3, z3, t0, kt),
(x1, y1, z1, delta2 + x2, y2, z2, x3, delta2 + y3, z3, t0, kt),
ohx2y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, -delta2 + z3, t0, kt),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, -delta2 + z3, t0, kt),
(x1, y1, z1, -delta2 + x2, y2, z2, x3, y3, delta2 + z3, t0, kt),
(x1, y1, z1, delta2 + x2, y2, z2, x3, y3, delta2 + z3, t0, kt),
ohx2z3,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle, delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, z3, t0, kt),
dhy2y2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, -delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, delta2 + y2, -delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, -delta2 + y2, delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, delta2 + y2, delta2 + z2, x3, y3, z3, t0, kt),
ohy2z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, -delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, x2, delta2 + y2, z2, -delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, x2, -delta2 + y2, z2, delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, x2, delta2 + y2, z2, delta2 + x3, y3, z3, t0, kt),
ohy2x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, -delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, delta2 + y2, z2, x3, -delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, delta2 + y2, z2, x3, delta2 + y3, z3, t0, kt),
ohy2y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, -delta2 + z3, t0, kt),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, -delta2 + z3, t0, kt),
(x1, y1, z1, x2, -delta2 + y2, z2, x3, y3, delta2 + z3, t0, kt),
(x1, y1, z1, x2, delta2 + y2, z2, x3, y3, delta2 + z3, t0, kt),
ohy2z3,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle, delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, z3, t0, kt),
dhz2z2,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, -delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, delta2 + z2, -delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, -delta2 + z2, delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, delta2 + z2, delta2 + x3, y3, z3, t0, kt),
ohz2x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, -delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, y2, delta2 + z2, x3, -delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, y2, delta2 + z2, x3, delta2 + y3, z3, t0, kt),
ohz2y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, -delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, -delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, -delta2 + z2, x3, y3, delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, delta2 + z2, x3, y3, delta2 + z3, t0, kt),
ohz2z3,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle, delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, z3, t0, kt),
dhx3x3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, -delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, delta2 + x3, -delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, delta2 + x3, delta2 + y3, z3, t0, kt),
ohx3y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, -delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, -delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, z2, -delta2 + x3, y3, delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, z2, delta2 + x3, y3, delta2 + z3, t0, kt),
ohx3z3,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, z3, t0, kt),
dhy3y3,
index);
TEST_OFF_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle,
delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, -delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, -delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, -delta2 + y3, delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, delta2 + y3, delta2 + z3, t0, kt),
ohy3z3,
index);
TEST_DIAGONAL_HESSIAN( _evaluateEnergyOnly_Angle, delta2*2.0,
(x1, y1, z1, x2, y2, z2, x3, y3, -delta2 + z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, z3, t0, kt),
(x1, y1, z1, x2, y2, z2, x3, y3, delta2 + z3, t0, kt),
dhz3z3,
index);
