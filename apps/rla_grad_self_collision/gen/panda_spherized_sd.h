// clang-format off

#include "Eigen/Dense"
#include "blaze/Math.h"
#include <iostream>

namespace ctup_gen_panda {

static void self_collision_signed_distances (cg_sd_runtime::ConfigurationBlockRobot<cg_sd_runtime::robots::Panda> const& arg2, Eigen::MatrixXd& arg3) {
  blaze::StaticVector<float, 8> var47[9];
  blaze::StaticVector<float, 8> var48;
  blaze::StaticVector<float, 8> var49;
  blaze::StaticVector<float, 8> var52[9];
  blaze::StaticVector<float, 8> var53;
  blaze::StaticVector<float, 8> var54;
  blaze::StaticVector<float, 8> var57[9];
  blaze::StaticVector<float, 8> var58;
  blaze::StaticVector<float, 8> var59;
  blaze::StaticVector<float, 8> var62[9];
  blaze::StaticVector<float, 8> var63;
  blaze::StaticVector<float, 8> var64;
  blaze::StaticVector<float, 8> var67[9];
  blaze::StaticVector<float, 8> var68;
  blaze::StaticVector<float, 8> var69;
  blaze::StaticVector<float, 8> var72[9];
  blaze::StaticVector<float, 8> var73;
  blaze::StaticVector<float, 8> var74;
  blaze::StaticVector<float, 8> var77[9];
  blaze::StaticVector<float, 8> var78;
  blaze::StaticVector<float, 8> var79;
  blaze::StaticVector<float, 8> var87[9];
  blaze::StaticVector<float, 8> var91;
  blaze::StaticVector<float, 8> var92[9];
  blaze::StaticVector<float, 8> var95[3];
  blaze::StaticVector<float, 8> var96;
  blaze::StaticVector<float, 8> var97[9];
  blaze::StaticVector<float, 8> var100[3];
  blaze::StaticVector<float, 8> var101;
  blaze::StaticVector<float, 8> var102[9];
  blaze::StaticVector<float, 8> var105[3];
  blaze::StaticVector<float, 8> var106;
  blaze::StaticVector<float, 8> var107[9];
  blaze::StaticVector<float, 8> var110[3];
  blaze::StaticVector<float, 8> var111;
  blaze::StaticVector<float, 8> var112[9];
  blaze::StaticVector<float, 8> var115[3];
  blaze::StaticVector<float, 8> var116;
  blaze::StaticVector<float, 8> var117[9];
  blaze::StaticVector<float, 8> var120[3];
  blaze::StaticVector<float, 8> var121;
  std::array<blaze::StaticVector<float, 8>, 59> var122;
  std::array<blaze::StaticVector<float, 8>, 59> var123;
  std::array<blaze::StaticVector<float, 8>, 59> var124;
  std::array<float, 59> var125;
  blaze::StaticVector<float, 8> var126[9];
  blaze::StaticVector<float, 8> var130;
  var122[0ll] = ((1.0f * 0.0f) + (0 * 0.0f)) + (0 * 0.0500000007450581f);
  var123[0ll] = ((0 * 0.0f) + (1.0f * 0.0f)) + (0 * 0.0500000007450581f);
  var124[0ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.0500000007450581f);
  var122[0ll] = var122[0ll] + 0;
  var123[0ll] = var123[0ll] + 0;
  var124[0ll] = var124[0ll] + 0;
  var125[0ll] = 0.0799999982118607f;
  blaze::StaticVector<float, 8> var131 = arg2[0ll];
  var48 = sin(var131);
  var49 = cos(var131);
  var47[0ll] = var49;
  var47[1ll] = -(var48);
  var47[2ll] = var48;
  var47[3ll] = var49;
  blaze::StaticVector<float, 8> var132;
  var132 = 0;
  var132 = var132 + (1.0f * var47[0ll]);
  var126[0ll] = var132;
  blaze::StaticVector<float, 8> var133;
  var133 = 0;
  var133 = var133 + (1.0f * var47[1ll]);
  var126[1ll] = var133;
  blaze::StaticVector<float, 8> var134;
  var134 = 0;
  var134 = var134 + (1.0f * var47[2ll]);
  var126[2ll] = var134;
  blaze::StaticVector<float, 8> var135;
  var135 = 0;
  var135 = var135 + (1.0f * var47[3ll]);
  var126[3ll] = var135;
  blaze::StaticVector<float, 8> var136;
  var136 = 0;
  var136 = var136 + (1.0f * 1.0f);
  var130 = var136;
  var87[0ll] = var126[0ll];
  var87[1ll] = var126[1ll];
  var87[2ll] = var126[2ll];
  var87[3ll] = var126[3ll];
  var91 = var130;
  var122[1ll] = ((var87[0ll] * 0.0f) + (var87[1ll] * -0.0799999982118607f)) + (0 * 0.0f);
  var123[1ll] = ((var87[2ll] * 0.0f) + (var87[3ll] * -0.0799999982118607f)) + (0 * 0.0f);
  var124[1ll] = ((0 * 0.0f) + (0 * -0.0799999982118607f)) + (1.0f * 0.0f);
  var122[1ll] = var122[1ll] + 0;
  var123[1ll] = var123[1ll] + 0;
  var124[1ll] = var124[1ll] + 0.333000004291534f;
  var125[1ll] = 0.0599999986588955f;
  var122[2ll] = ((var87[0ll] * 0.0f) + (var87[1ll] * -0.0299999993294477f)) + (0 * 0.0f);
  var123[2ll] = ((var87[2ll] * 0.0f) + (var87[3ll] * -0.0299999993294477f)) + (0 * 0.0f);
  var124[2ll] = ((0 * 0.0f) + (0 * -0.0299999993294477f)) + (1.0f * 0.0f);
  var122[2ll] = var122[2ll] + 0;
  var123[2ll] = var123[2ll] + 0;
  var124[2ll] = var124[2ll] + 0.333000004291534f;
  var125[2ll] = 0.0599999986588955f;
  var122[3ll] = ((var87[0ll] * 0.0f) + (var87[1ll] * 0.0f)) + (0 * -0.119999997317791f);
  var123[3ll] = ((var87[2ll] * 0.0f) + (var87[3ll] * 0.0f)) + (0 * -0.119999997317791f);
  var124[3ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * -0.119999997317791f);
  var122[3ll] = var122[3ll] + 0;
  var123[3ll] = var123[3ll] + 0;
  var124[3ll] = var124[3ll] + 0.333000004291534f;
  var125[3ll] = 0.0599999986588955f;
  var122[4ll] = ((var87[0ll] * 0.0f) + (var87[1ll] * 0.0f)) + (0 * -0.170000001788139f);
  var123[4ll] = ((var87[2ll] * 0.0f) + (var87[3ll] * 0.0f)) + (0 * -0.170000001788139f);
  var124[4ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * -0.170000001788139f);
  var122[4ll] = var122[4ll] + 0;
  var123[4ll] = var123[4ll] + 0;
  var124[4ll] = var124[4ll] + 0.333000004291534f;
  var125[4ll] = 0.0599999986588955f;
  blaze::StaticVector<float, 8> var137 = arg2[1ll];
  var53 = sin(var137);
  var54 = cos(var137);
  var52[0ll] = var54;
  var52[1ll] = -(var53);
  var52[2ll] = var53;
  var52[3ll] = var54;
  blaze::StaticVector<float, 8> var138;
  var138 = 0;
  var138 = var138 + (1.0f * var52[0ll]);
  var126[0ll] = var138;
  blaze::StaticVector<float, 8> var139;
  var139 = 0;
  var139 = var139 + (1.0f * var52[1ll]);
  var126[1ll] = var139;
  blaze::StaticVector<float, 8> var140;
  var140 = 0;
  var140 = var140 + (-1.0f * var52[2ll]);
  var126[2ll] = var140;
  blaze::StaticVector<float, 8> var141;
  var141 = 0;
  var141 = var141 + (-1.0f * var52[3ll]);
  var126[3ll] = var141;
  blaze::StaticVector<float, 8> var142;
  var142 = 0;
  var142 = var142 + (1.0f * 1.0f);
  var130 = var142;
  blaze::StaticVector<float, 8> var143;
  var143 = 0;
  var143 = var143 + (var87[0ll] * var126[0ll]);
  var92[0ll] = var143;
  blaze::StaticVector<float, 8> var144;
  var144 = 0;
  var144 = var144 + (var87[0ll] * var126[1ll]);
  var92[1ll] = var144;
  blaze::StaticVector<float, 8> var145;
  var145 = 0;
  var145 = var145 + (var87[1ll] * 1.0f);
  var92[2ll] = var145;
  blaze::StaticVector<float, 8> var146;
  var146 = 0;
  var146 = var146 + (var87[2ll] * var126[0ll]);
  var92[3ll] = var146;
  blaze::StaticVector<float, 8> var147;
  var147 = 0;
  var147 = var147 + (var87[2ll] * var126[1ll]);
  var92[4ll] = var147;
  blaze::StaticVector<float, 8> var148;
  var148 = 0;
  var148 = var148 + (var87[3ll] * 1.0f);
  var92[5ll] = var148;
  blaze::StaticVector<float, 8> var149;
  var149 = 0;
  var149 = var149 + (1.0f * var126[2ll]);
  var92[6ll] = var149;
  blaze::StaticVector<float, 8> var150;
  var150 = 0;
  var150 = var150 + (1.0f * var126[3ll]);
  var92[7ll] = var150;
  blaze::StaticVector<float, 8> var151;
  var151 = 0;
  var151 = var151 + (0.333000004291534f * var130);
  var95[0ll] = var151;
  blaze::StaticVector<float, 8> var152;
  var152 = 0;
  var152 = var152 + (var91 * var130);
  var96 = var152;
  var122[5ll] = ((var92[0ll] * 0.0f) + (var92[1ll] * 0.0f)) + (var92[2ll] * 0.0299999993294477f);
  var123[5ll] = ((var92[3ll] * 0.0f) + (var92[4ll] * 0.0f)) + (var92[5ll] * 0.0299999993294477f);
  var124[5ll] = ((var92[6ll] * 0.0f) + (var92[7ll] * 0.0f)) + (0 * 0.0299999993294477f);
  var122[5ll] = var122[5ll] + 0;
  var123[5ll] = var123[5ll] + 0;
  var124[5ll] = var124[5ll] + var95[0ll];
  var125[5ll] = 0.0599999986588955f;
  var122[6ll] = ((var92[0ll] * 0.0f) + (var92[1ll] * 0.0f)) + (var92[2ll] * 0.0799999982118607f);
  var123[6ll] = ((var92[3ll] * 0.0f) + (var92[4ll] * 0.0f)) + (var92[5ll] * 0.0799999982118607f);
  var124[6ll] = ((var92[6ll] * 0.0f) + (var92[7ll] * 0.0f)) + (0 * 0.0799999982118607f);
  var122[6ll] = var122[6ll] + 0;
  var123[6ll] = var123[6ll] + 0;
  var124[6ll] = var124[6ll] + var95[0ll];
  var125[6ll] = 0.0599999986588955f;
  var122[7ll] = ((var92[0ll] * 0.0f) + (var92[1ll] * -0.119999997317791f)) + (var92[2ll] * 0.0f);
  var123[7ll] = ((var92[3ll] * 0.0f) + (var92[4ll] * -0.119999997317791f)) + (var92[5ll] * 0.0f);
  var124[7ll] = ((var92[6ll] * 0.0f) + (var92[7ll] * -0.119999997317791f)) + (0 * 0.0f);
  var122[7ll] = var122[7ll] + 0;
  var123[7ll] = var123[7ll] + 0;
  var124[7ll] = var124[7ll] + var95[0ll];
  var125[7ll] = 0.0599999986588955f;
  var122[8ll] = ((var92[0ll] * 0.0f) + (var92[1ll] * -0.170000001788139f)) + (var92[2ll] * 0.0f);
  var123[8ll] = ((var92[3ll] * 0.0f) + (var92[4ll] * -0.170000001788139f)) + (var92[5ll] * 0.0f);
  var124[8ll] = ((var92[6ll] * 0.0f) + (var92[7ll] * -0.170000001788139f)) + (0 * 0.0f);
  var122[8ll] = var122[8ll] + 0;
  var123[8ll] = var123[8ll] + 0;
  var124[8ll] = var124[8ll] + var95[0ll];
  var125[8ll] = 0.0599999986588955f;
  blaze::StaticVector<float, 8> var153 = arg2[2ll];
  var58 = sin(var153);
  var59 = cos(var153);
  var57[0ll] = var59;
  var57[1ll] = -(var58);
  var57[2ll] = var58;
  var57[3ll] = var59;
  blaze::StaticVector<float, 8> var154;
  var154 = 0;
  var154 = var154 + (1.0f * var57[0ll]);
  var126[0ll] = var154;
  blaze::StaticVector<float, 8> var155;
  var155 = 0;
  var155 = var155 + (1.0f * var57[1ll]);
  var126[1ll] = var155;
  blaze::StaticVector<float, 8> var156;
  var156 = 0;
  var156 = var156 + (1.0f * var57[2ll]);
  var126[2ll] = var156;
  blaze::StaticVector<float, 8> var157;
  var157 = 0;
  var157 = var157 + (1.0f * var57[3ll]);
  var126[3ll] = var157;
  blaze::StaticVector<float, 8> var158;
  var158 = 0;
  var158 = var158 + (1.0f * 1.0f);
  var130 = var158;
  blaze::StaticVector<float, 8> var159;
  var159 = 0;
  var159 = var159 + (var92[0ll] * var126[0ll]);
  var159 = var159 + (var92[2ll] * var126[2ll]);
  var97[0ll] = var159;
  blaze::StaticVector<float, 8> var160;
  var160 = 0;
  var160 = var160 + (var92[0ll] * var126[1ll]);
  var160 = var160 + (var92[2ll] * var126[3ll]);
  var97[1ll] = var160;
  blaze::StaticVector<float, 8> var161;
  var161 = 0;
  var161 = var161 + (var92[1ll] * -1.0f);
  var97[2ll] = var161;
  blaze::StaticVector<float, 8> var162;
  var162 = 0;
  var162 = var162 + (var92[3ll] * var126[0ll]);
  var162 = var162 + (var92[5ll] * var126[2ll]);
  var97[3ll] = var162;
  blaze::StaticVector<float, 8> var163;
  var163 = 0;
  var163 = var163 + (var92[3ll] * var126[1ll]);
  var163 = var163 + (var92[5ll] * var126[3ll]);
  var97[4ll] = var163;
  blaze::StaticVector<float, 8> var164;
  var164 = 0;
  var164 = var164 + (var92[4ll] * -1.0f);
  var97[5ll] = var164;
  blaze::StaticVector<float, 8> var165;
  var165 = 0;
  var165 = var165 + (var92[6ll] * var126[0ll]);
  var97[6ll] = var165;
  blaze::StaticVector<float, 8> var166;
  var166 = 0;
  var166 = var166 + (var92[6ll] * var126[1ll]);
  var97[7ll] = var166;
  blaze::StaticVector<float, 8> var167;
  var167 = 0;
  var167 = var167 + (var92[7ll] * -1.0f);
  var97[8ll] = var167;
  blaze::StaticVector<float, 8> var168;
  var168 = 0;
  blaze::StaticVector<float, 8> var169;
  var169 = 0;
  var169 = var169 + (var92[1ll] * -0.316000014543533f);
  var100[0ll] = var169 + var168;
  blaze::StaticVector<float, 8> var170;
  var170 = 0;
  blaze::StaticVector<float, 8> var171;
  var171 = 0;
  var171 = var171 + (var92[4ll] * -0.316000014543533f);
  var100[1ll] = var171 + var170;
  blaze::StaticVector<float, 8> var172;
  var172 = 0;
  var172 = var172 + (var95[0ll] * var130);
  blaze::StaticVector<float, 8> var173;
  var173 = 0;
  var173 = var173 + (var92[7ll] * -0.316000014543533f);
  var100[2ll] = var173 + var172;
  blaze::StaticVector<float, 8> var174;
  var174 = 0;
  var174 = var174 + (var96 * var130);
  var101 = var174;
  var122[9ll] = ((var97[0ll] * 0.0f) + (var97[1ll] * 0.0f)) + (var97[2ll] * -0.100000001490116f);
  var123[9ll] = ((var97[3ll] * 0.0f) + (var97[4ll] * 0.0f)) + (var97[5ll] * -0.100000001490116f);
  var124[9ll] = ((var97[6ll] * 0.0f) + (var97[7ll] * 0.0f)) + (var97[8ll] * -0.100000001490116f);
  var122[9ll] = var122[9ll] + var100[0ll];
  var123[9ll] = var123[9ll] + var100[1ll];
  var124[9ll] = var124[9ll] + var100[2ll];
  var125[9ll] = 0.0599999986588955f;
  var122[10ll] = ((var97[0ll] * 0.0f) + (var97[1ll] * 0.0f)) + (var97[2ll] * -0.0599999986588955f);
  var123[10ll] = ((var97[3ll] * 0.0f) + (var97[4ll] * 0.0f)) + (var97[5ll] * -0.0599999986588955f);
  var124[10ll] = ((var97[6ll] * 0.0f) + (var97[7ll] * 0.0f)) + (var97[8ll] * -0.0599999986588955f);
  var122[10ll] = var122[10ll] + var100[0ll];
  var123[10ll] = var123[10ll] + var100[1ll];
  var124[10ll] = var124[10ll] + var100[2ll];
  var125[10ll] = 0.0500000007450581f;
  var122[11ll] = ((var97[0ll] * 0.0799999982118607f) + (var97[1ll] * 0.0599999986588955f)) + (var97[2ll] * 0.0f);
  var123[11ll] = ((var97[3ll] * 0.0799999982118607f) + (var97[4ll] * 0.0599999986588955f)) + (var97[5ll] * 0.0f);
  var124[11ll] = ((var97[6ll] * 0.0799999982118607f) + (var97[7ll] * 0.0599999986588955f)) + (var97[8ll] * 0.0f);
  var122[11ll] = var122[11ll] + var100[0ll];
  var123[11ll] = var123[11ll] + var100[1ll];
  var124[11ll] = var124[11ll] + var100[2ll];
  var125[11ll] = 0.0549999997019768f;
  var122[12ll] = ((var97[0ll] * 0.0799999982118607f) + (var97[1ll] * 0.0199999995529652f)) + (var97[2ll] * 0.0f);
  var123[12ll] = ((var97[3ll] * 0.0799999982118607f) + (var97[4ll] * 0.0199999995529652f)) + (var97[5ll] * 0.0f);
  var124[12ll] = ((var97[6ll] * 0.0799999982118607f) + (var97[7ll] * 0.0199999995529652f)) + (var97[8ll] * 0.0f);
  var122[12ll] = var122[12ll] + var100[0ll];
  var123[12ll] = var123[12ll] + var100[1ll];
  var124[12ll] = var124[12ll] + var100[2ll];
  var125[12ll] = 0.0549999997019768f;
  blaze::StaticVector<float, 8> var175 = arg2[3ll];
  var63 = sin(var175);
  var64 = cos(var175);
  var62[0ll] = var64;
  var62[1ll] = -(var63);
  var62[2ll] = var63;
  var62[3ll] = var64;
  blaze::StaticVector<float, 8> var176;
  var176 = 0;
  var176 = var176 + (1.0f * var62[0ll]);
  var126[0ll] = var176;
  blaze::StaticVector<float, 8> var177;
  var177 = 0;
  var177 = var177 + (1.0f * var62[1ll]);
  var126[1ll] = var177;
  blaze::StaticVector<float, 8> var178;
  var178 = 0;
  var178 = var178 + (1.0f * var62[2ll]);
  var126[2ll] = var178;
  blaze::StaticVector<float, 8> var179;
  var179 = 0;
  var179 = var179 + (1.0f * var62[3ll]);
  var126[3ll] = var179;
  blaze::StaticVector<float, 8> var180;
  var180 = 0;
  var180 = var180 + (1.0f * 1.0f);
  var130 = var180;
  blaze::StaticVector<float, 8> var181;
  var181 = 0;
  var181 = var181 + (var97[0ll] * var126[0ll]);
  var181 = var181 + (var97[2ll] * var126[2ll]);
  var102[0ll] = var181;
  blaze::StaticVector<float, 8> var182;
  var182 = 0;
  var182 = var182 + (var97[0ll] * var126[1ll]);
  var182 = var182 + (var97[2ll] * var126[3ll]);
  var102[1ll] = var182;
  blaze::StaticVector<float, 8> var183;
  var183 = 0;
  var183 = var183 + (var97[1ll] * -1.0f);
  var102[2ll] = var183;
  blaze::StaticVector<float, 8> var184;
  var184 = 0;
  var184 = var184 + (var97[3ll] * var126[0ll]);
  var184 = var184 + (var97[5ll] * var126[2ll]);
  var102[3ll] = var184;
  blaze::StaticVector<float, 8> var185;
  var185 = 0;
  var185 = var185 + (var97[3ll] * var126[1ll]);
  var185 = var185 + (var97[5ll] * var126[3ll]);
  var102[4ll] = var185;
  blaze::StaticVector<float, 8> var186;
  var186 = 0;
  var186 = var186 + (var97[4ll] * -1.0f);
  var102[5ll] = var186;
  blaze::StaticVector<float, 8> var187;
  var187 = 0;
  var187 = var187 + (var97[6ll] * var126[0ll]);
  var187 = var187 + (var97[8ll] * var126[2ll]);
  var102[6ll] = var187;
  blaze::StaticVector<float, 8> var188;
  var188 = 0;
  var188 = var188 + (var97[6ll] * var126[1ll]);
  var188 = var188 + (var97[8ll] * var126[3ll]);
  var102[7ll] = var188;
  blaze::StaticVector<float, 8> var189;
  var189 = 0;
  var189 = var189 + (var97[7ll] * -1.0f);
  var102[8ll] = var189;
  blaze::StaticVector<float, 8> var190;
  var190 = 0;
  var190 = var190 + (var100[0ll] * var130);
  blaze::StaticVector<float, 8> var191;
  var191 = 0;
  var191 = var191 + (var97[0ll] * 0.0825000032782555f);
  var105[0ll] = var191 + var190;
  blaze::StaticVector<float, 8> var192;
  var192 = 0;
  var192 = var192 + (var100[1ll] * var130);
  blaze::StaticVector<float, 8> var193;
  var193 = 0;
  var193 = var193 + (var97[3ll] * 0.0825000032782555f);
  var105[1ll] = var193 + var192;
  blaze::StaticVector<float, 8> var194;
  var194 = 0;
  var194 = var194 + (var100[2ll] * var130);
  blaze::StaticVector<float, 8> var195;
  var195 = 0;
  var195 = var195 + (var97[6ll] * 0.0825000032782555f);
  var105[2ll] = var195 + var194;
  blaze::StaticVector<float, 8> var196;
  var196 = 0;
  var196 = var196 + (var101 * var130);
  var106 = var196;
  var122[13ll] = ((var102[0ll] * -0.0799999982118607f) + (var102[1ll] * 0.0949999988079071f)) + (var102[2ll] * 0.0f);
  var123[13ll] = ((var102[3ll] * -0.0799999982118607f) + (var102[4ll] * 0.0949999988079071f)) + (var102[5ll] * 0.0f);
  var124[13ll] = ((var102[6ll] * -0.0799999982118607f) + (var102[7ll] * 0.0949999988079071f)) + (var102[8ll] * 0.0f);
  var122[13ll] = var122[13ll] + var105[0ll];
  var123[13ll] = var123[13ll] + var105[1ll];
  var124[13ll] = var124[13ll] + var105[2ll];
  var125[13ll] = 0.0599999986588955f;
  var122[14ll] = ((var102[0ll] * 0.0f) + (var102[1ll] * 0.0f)) + (var102[2ll] * 0.0199999995529652f);
  var123[14ll] = ((var102[3ll] * 0.0f) + (var102[4ll] * 0.0f)) + (var102[5ll] * 0.0199999995529652f);
  var124[14ll] = ((var102[6ll] * 0.0f) + (var102[7ll] * 0.0f)) + (var102[8ll] * 0.0199999995529652f);
  var122[14ll] = var122[14ll] + var105[0ll];
  var123[14ll] = var123[14ll] + var105[1ll];
  var124[14ll] = var124[14ll] + var105[2ll];
  var125[14ll] = 0.0549999997019768f;
  var122[15ll] = ((var102[0ll] * 0.0f) + (var102[1ll] * 0.0f)) + (var102[2ll] * 0.0599999986588955f);
  var123[15ll] = ((var102[3ll] * 0.0f) + (var102[4ll] * 0.0f)) + (var102[5ll] * 0.0599999986588955f);
  var124[15ll] = ((var102[6ll] * 0.0f) + (var102[7ll] * 0.0f)) + (var102[8ll] * 0.0599999986588955f);
  var122[15ll] = var122[15ll] + var105[0ll];
  var123[15ll] = var123[15ll] + var105[1ll];
  var124[15ll] = var124[15ll] + var105[2ll];
  var125[15ll] = 0.0549999997019768f;
  var122[16ll] = ((var102[0ll] * -0.0799999982118607f) + (var102[1ll] * 0.0599999986588955f)) + (var102[2ll] * 0.0f);
  var123[16ll] = ((var102[3ll] * -0.0799999982118607f) + (var102[4ll] * 0.0599999986588955f)) + (var102[5ll] * 0.0f);
  var124[16ll] = ((var102[6ll] * -0.0799999982118607f) + (var102[7ll] * 0.0599999986588955f)) + (var102[8ll] * 0.0f);
  var122[16ll] = var122[16ll] + var105[0ll];
  var123[16ll] = var123[16ll] + var105[1ll];
  var124[16ll] = var124[16ll] + var105[2ll];
  var125[16ll] = 0.0549999997019768f;
  blaze::StaticVector<float, 8> var197 = arg2[4ll];
  var68 = sin(var197);
  var69 = cos(var197);
  var67[0ll] = var69;
  var67[1ll] = -(var68);
  var67[2ll] = var68;
  var67[3ll] = var69;
  blaze::StaticVector<float, 8> var198;
  var198 = 0;
  var198 = var198 + (1.0f * var67[0ll]);
  var126[0ll] = var198;
  blaze::StaticVector<float, 8> var199;
  var199 = 0;
  var199 = var199 + (1.0f * var67[1ll]);
  var126[1ll] = var199;
  blaze::StaticVector<float, 8> var200;
  var200 = 0;
  var200 = var200 + (-1.0f * var67[2ll]);
  var126[2ll] = var200;
  blaze::StaticVector<float, 8> var201;
  var201 = 0;
  var201 = var201 + (-1.0f * var67[3ll]);
  var126[3ll] = var201;
  blaze::StaticVector<float, 8> var202;
  var202 = 0;
  var202 = var202 + (1.0f * 1.0f);
  var130 = var202;
  blaze::StaticVector<float, 8> var203;
  var203 = 0;
  var203 = var203 + (var102[0ll] * var126[0ll]);
  var203 = var203 + (var102[2ll] * var126[2ll]);
  var107[0ll] = var203;
  blaze::StaticVector<float, 8> var204;
  var204 = 0;
  var204 = var204 + (var102[0ll] * var126[1ll]);
  var204 = var204 + (var102[2ll] * var126[3ll]);
  var107[1ll] = var204;
  blaze::StaticVector<float, 8> var205;
  var205 = 0;
  var205 = var205 + (var102[1ll] * 1.0f);
  var107[2ll] = var205;
  blaze::StaticVector<float, 8> var206;
  var206 = 0;
  var206 = var206 + (var102[3ll] * var126[0ll]);
  var206 = var206 + (var102[5ll] * var126[2ll]);
  var107[3ll] = var206;
  blaze::StaticVector<float, 8> var207;
  var207 = 0;
  var207 = var207 + (var102[3ll] * var126[1ll]);
  var207 = var207 + (var102[5ll] * var126[3ll]);
  var107[4ll] = var207;
  blaze::StaticVector<float, 8> var208;
  var208 = 0;
  var208 = var208 + (var102[4ll] * 1.0f);
  var107[5ll] = var208;
  blaze::StaticVector<float, 8> var209;
  var209 = 0;
  var209 = var209 + (var102[6ll] * var126[0ll]);
  var209 = var209 + (var102[8ll] * var126[2ll]);
  var107[6ll] = var209;
  blaze::StaticVector<float, 8> var210;
  var210 = 0;
  var210 = var210 + (var102[6ll] * var126[1ll]);
  var210 = var210 + (var102[8ll] * var126[3ll]);
  var107[7ll] = var210;
  blaze::StaticVector<float, 8> var211;
  var211 = 0;
  var211 = var211 + (var102[7ll] * 1.0f);
  var107[8ll] = var211;
  blaze::StaticVector<float, 8> var212;
  var212 = 0;
  var212 = var212 + (var105[0ll] * var130);
  blaze::StaticVector<float, 8> var213;
  var213 = 0;
  var213 = var213 + (var102[0ll] * -0.0825000032782555f);
  var213 = var213 + (var102[1ll] * 0.38400000333786f);
  var110[0ll] = var213 + var212;
  blaze::StaticVector<float, 8> var214;
  var214 = 0;
  var214 = var214 + (var105[1ll] * var130);
  blaze::StaticVector<float, 8> var215;
  var215 = 0;
  var215 = var215 + (var102[3ll] * -0.0825000032782555f);
  var215 = var215 + (var102[4ll] * 0.38400000333786f);
  var110[1ll] = var215 + var214;
  blaze::StaticVector<float, 8> var216;
  var216 = 0;
  var216 = var216 + (var105[2ll] * var130);
  blaze::StaticVector<float, 8> var217;
  var217 = 0;
  var217 = var217 + (var102[6ll] * -0.0825000032782555f);
  var217 = var217 + (var102[7ll] * 0.38400000333786f);
  var110[2ll] = var217 + var216;
  blaze::StaticVector<float, 8> var218;
  var218 = 0;
  var218 = var218 + (var106 * var130);
  var111 = var218;
  var122[17ll] = ((var107[0ll] * 0.0f) + (var107[1ll] * 0.0549999997019768f)) + (var107[2ll] * 0.0f);
  var123[17ll] = ((var107[3ll] * 0.0f) + (var107[4ll] * 0.0549999997019768f)) + (var107[5ll] * 0.0f);
  var124[17ll] = ((var107[6ll] * 0.0f) + (var107[7ll] * 0.0549999997019768f)) + (var107[8ll] * 0.0f);
  var122[17ll] = var122[17ll] + var110[0ll];
  var123[17ll] = var123[17ll] + var110[1ll];
  var124[17ll] = var124[17ll] + var110[2ll];
  var125[17ll] = 0.0599999986588955f;
  cg_sd_runtime::compute_sph_sph_cp_sd(0ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[17ll], var123[17ll], var124[17ll], var125[17ll], arg3); //collision pair: 0,17 : panda_link0_0,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd(42ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[17ll], var123[17ll], var124[17ll], var125[17ll], arg3); //collision pair: 1,17 : panda_link1_0,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd(84ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[17ll], var123[17ll], var124[17ll], var125[17ll], arg3); //collision pair: 2,17 : panda_link1_1,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd(126ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[17ll], var123[17ll], var124[17ll], var125[17ll], arg3); //collision pair: 3,17 : panda_link1_2,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd(168ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[17ll], var123[17ll], var124[17ll], var125[17ll], arg3); //collision pair: 4,17 : panda_link1_3,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd(210ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[17ll], var123[17ll], var124[17ll], var125[17ll], arg3); //collision pair: 5,17 : panda_link2_0,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd(249ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[17ll], var123[17ll], var124[17ll], var125[17ll], arg3); //collision pair: 6,17 : panda_link2_1,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd(288ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[17ll], var123[17ll], var124[17ll], var125[17ll], arg3); //collision pair: 7,17 : panda_link2_2,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd(327ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[17ll], var123[17ll], var124[17ll], var125[17ll], arg3); //collision pair: 8,17 : panda_link2_3,panda_link5_0
  var122[18ll] = ((var107[0ll] * 0.0f) + (var107[1ll] * 0.0750000029802322f)) + (var107[2ll] * 0.0f);
  var123[18ll] = ((var107[3ll] * 0.0f) + (var107[4ll] * 0.0750000029802322f)) + (var107[5ll] * 0.0f);
  var124[18ll] = ((var107[6ll] * 0.0f) + (var107[7ll] * 0.0750000029802322f)) + (var107[8ll] * 0.0f);
  var122[18ll] = var122[18ll] + var110[0ll];
  var123[18ll] = var123[18ll] + var110[1ll];
  var124[18ll] = var124[18ll] + var110[2ll];
  var125[18ll] = 0.0599999986588955f;
  cg_sd_runtime::compute_sph_sph_cp_sd(1ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[18ll], var123[18ll], var124[18ll], var125[18ll], arg3); //collision pair: 0,18 : panda_link0_0,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd(43ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[18ll], var123[18ll], var124[18ll], var125[18ll], arg3); //collision pair: 1,18 : panda_link1_0,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd(85ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[18ll], var123[18ll], var124[18ll], var125[18ll], arg3); //collision pair: 2,18 : panda_link1_1,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd(127ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[18ll], var123[18ll], var124[18ll], var125[18ll], arg3); //collision pair: 3,18 : panda_link1_2,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd(169ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[18ll], var123[18ll], var124[18ll], var125[18ll], arg3); //collision pair: 4,18 : panda_link1_3,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd(211ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[18ll], var123[18ll], var124[18ll], var125[18ll], arg3); //collision pair: 5,18 : panda_link2_0,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd(250ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[18ll], var123[18ll], var124[18ll], var125[18ll], arg3); //collision pair: 6,18 : panda_link2_1,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd(289ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[18ll], var123[18ll], var124[18ll], var125[18ll], arg3); //collision pair: 7,18 : panda_link2_2,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd(328ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[18ll], var123[18ll], var124[18ll], var125[18ll], arg3); //collision pair: 8,18 : panda_link2_3,panda_link5_1
  var122[19ll] = ((var107[0ll] * 0.0f) + (var107[1ll] * 0.0f)) + (var107[2ll] * -0.219999998807907f);
  var123[19ll] = ((var107[3ll] * 0.0f) + (var107[4ll] * 0.0f)) + (var107[5ll] * -0.219999998807907f);
  var124[19ll] = ((var107[6ll] * 0.0f) + (var107[7ll] * 0.0f)) + (var107[8ll] * -0.219999998807907f);
  var122[19ll] = var122[19ll] + var110[0ll];
  var123[19ll] = var123[19ll] + var110[1ll];
  var124[19ll] = var124[19ll] + var110[2ll];
  var125[19ll] = 0.0599999986588955f;
  cg_sd_runtime::compute_sph_sph_cp_sd(2ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[19ll], var123[19ll], var124[19ll], var125[19ll], arg3); //collision pair: 0,19 : panda_link0_0,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd(44ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[19ll], var123[19ll], var124[19ll], var125[19ll], arg3); //collision pair: 1,19 : panda_link1_0,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd(86ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[19ll], var123[19ll], var124[19ll], var125[19ll], arg3); //collision pair: 2,19 : panda_link1_1,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd(128ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[19ll], var123[19ll], var124[19ll], var125[19ll], arg3); //collision pair: 3,19 : panda_link1_2,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd(170ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[19ll], var123[19ll], var124[19ll], var125[19ll], arg3); //collision pair: 4,19 : panda_link1_3,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd(212ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[19ll], var123[19ll], var124[19ll], var125[19ll], arg3); //collision pair: 5,19 : panda_link2_0,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd(251ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[19ll], var123[19ll], var124[19ll], var125[19ll], arg3); //collision pair: 6,19 : panda_link2_1,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd(290ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[19ll], var123[19ll], var124[19ll], var125[19ll], arg3); //collision pair: 7,19 : panda_link2_2,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd(329ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[19ll], var123[19ll], var124[19ll], var125[19ll], arg3); //collision pair: 8,19 : panda_link2_3,panda_link5_2
  var122[20ll] = ((var107[0ll] * 0.0f) + (var107[1ll] * 0.0500000007450581f)) + (var107[2ll] * -0.180000007152557f);
  var123[20ll] = ((var107[3ll] * 0.0f) + (var107[4ll] * 0.0500000007450581f)) + (var107[5ll] * -0.180000007152557f);
  var124[20ll] = ((var107[6ll] * 0.0f) + (var107[7ll] * 0.0500000007450581f)) + (var107[8ll] * -0.180000007152557f);
  var122[20ll] = var122[20ll] + var110[0ll];
  var123[20ll] = var123[20ll] + var110[1ll];
  var124[20ll] = var124[20ll] + var110[2ll];
  var125[20ll] = 0.0500000007450581f;
  cg_sd_runtime::compute_sph_sph_cp_sd(3ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[20ll], var123[20ll], var124[20ll], var125[20ll], arg3); //collision pair: 0,20 : panda_link0_0,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd(45ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[20ll], var123[20ll], var124[20ll], var125[20ll], arg3); //collision pair: 1,20 : panda_link1_0,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd(87ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[20ll], var123[20ll], var124[20ll], var125[20ll], arg3); //collision pair: 2,20 : panda_link1_1,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd(129ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[20ll], var123[20ll], var124[20ll], var125[20ll], arg3); //collision pair: 3,20 : panda_link1_2,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd(171ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[20ll], var123[20ll], var124[20ll], var125[20ll], arg3); //collision pair: 4,20 : panda_link1_3,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd(213ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[20ll], var123[20ll], var124[20ll], var125[20ll], arg3); //collision pair: 5,20 : panda_link2_0,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd(252ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[20ll], var123[20ll], var124[20ll], var125[20ll], arg3); //collision pair: 6,20 : panda_link2_1,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd(291ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[20ll], var123[20ll], var124[20ll], var125[20ll], arg3); //collision pair: 7,20 : panda_link2_2,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd(330ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[20ll], var123[20ll], var124[20ll], var125[20ll], arg3); //collision pair: 8,20 : panda_link2_3,panda_link5_3
  var122[21ll] = ((var107[0ll] * 0.00999999977648258f) + (var107[1ll] * 0.0799999982118607f)) + (var107[2ll] * -0.140000000596046f);
  var123[21ll] = ((var107[3ll] * 0.00999999977648258f) + (var107[4ll] * 0.0799999982118607f)) + (var107[5ll] * -0.140000000596046f);
  var124[21ll] = ((var107[6ll] * 0.00999999977648258f) + (var107[7ll] * 0.0799999982118607f)) + (var107[8ll] * -0.140000000596046f);
  var122[21ll] = var122[21ll] + var110[0ll];
  var123[21ll] = var123[21ll] + var110[1ll];
  var124[21ll] = var124[21ll] + var110[2ll];
  var125[21ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd(4ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[21ll], var123[21ll], var124[21ll], var125[21ll], arg3); //collision pair: 0,21 : panda_link0_0,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd(46ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[21ll], var123[21ll], var124[21ll], var125[21ll], arg3); //collision pair: 1,21 : panda_link1_0,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd(88ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[21ll], var123[21ll], var124[21ll], var125[21ll], arg3); //collision pair: 2,21 : panda_link1_1,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd(130ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[21ll], var123[21ll], var124[21ll], var125[21ll], arg3); //collision pair: 3,21 : panda_link1_2,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd(172ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[21ll], var123[21ll], var124[21ll], var125[21ll], arg3); //collision pair: 4,21 : panda_link1_3,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd(214ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[21ll], var123[21ll], var124[21ll], var125[21ll], arg3); //collision pair: 5,21 : panda_link2_0,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd(253ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[21ll], var123[21ll], var124[21ll], var125[21ll], arg3); //collision pair: 6,21 : panda_link2_1,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd(292ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[21ll], var123[21ll], var124[21ll], var125[21ll], arg3); //collision pair: 7,21 : panda_link2_2,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd(331ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[21ll], var123[21ll], var124[21ll], var125[21ll], arg3); //collision pair: 8,21 : panda_link2_3,panda_link5_4
  var122[22ll] = ((var107[0ll] * 0.00999999977648258f) + (var107[1ll] * 0.0850000008940697f)) + (var107[2ll] * -0.109999999403954f);
  var123[22ll] = ((var107[3ll] * 0.00999999977648258f) + (var107[4ll] * 0.0850000008940697f)) + (var107[5ll] * -0.109999999403954f);
  var124[22ll] = ((var107[6ll] * 0.00999999977648258f) + (var107[7ll] * 0.0850000008940697f)) + (var107[8ll] * -0.109999999403954f);
  var122[22ll] = var122[22ll] + var110[0ll];
  var123[22ll] = var123[22ll] + var110[1ll];
  var124[22ll] = var124[22ll] + var110[2ll];
  var125[22ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd(5ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[22ll], var123[22ll], var124[22ll], var125[22ll], arg3); //collision pair: 0,22 : panda_link0_0,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd(47ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[22ll], var123[22ll], var124[22ll], var125[22ll], arg3); //collision pair: 1,22 : panda_link1_0,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd(89ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[22ll], var123[22ll], var124[22ll], var125[22ll], arg3); //collision pair: 2,22 : panda_link1_1,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd(131ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[22ll], var123[22ll], var124[22ll], var125[22ll], arg3); //collision pair: 3,22 : panda_link1_2,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd(173ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[22ll], var123[22ll], var124[22ll], var125[22ll], arg3); //collision pair: 4,22 : panda_link1_3,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd(215ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[22ll], var123[22ll], var124[22ll], var125[22ll], arg3); //collision pair: 5,22 : panda_link2_0,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd(254ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[22ll], var123[22ll], var124[22ll], var125[22ll], arg3); //collision pair: 6,22 : panda_link2_1,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd(293ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[22ll], var123[22ll], var124[22ll], var125[22ll], arg3); //collision pair: 7,22 : panda_link2_2,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd(332ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[22ll], var123[22ll], var124[22ll], var125[22ll], arg3); //collision pair: 8,22 : panda_link2_3,panda_link5_5
  var122[23ll] = ((var107[0ll] * 0.00999999977648258f) + (var107[1ll] * 0.0900000035762787f)) + (var107[2ll] * -0.0799999982118607f);
  var123[23ll] = ((var107[3ll] * 0.00999999977648258f) + (var107[4ll] * 0.0900000035762787f)) + (var107[5ll] * -0.0799999982118607f);
  var124[23ll] = ((var107[6ll] * 0.00999999977648258f) + (var107[7ll] * 0.0900000035762787f)) + (var107[8ll] * -0.0799999982118607f);
  var122[23ll] = var122[23ll] + var110[0ll];
  var123[23ll] = var123[23ll] + var110[1ll];
  var124[23ll] = var124[23ll] + var110[2ll];
  var125[23ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd(6ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[23ll], var123[23ll], var124[23ll], var125[23ll], arg3); //collision pair: 0,23 : panda_link0_0,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd(48ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[23ll], var123[23ll], var124[23ll], var125[23ll], arg3); //collision pair: 1,23 : panda_link1_0,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd(90ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[23ll], var123[23ll], var124[23ll], var125[23ll], arg3); //collision pair: 2,23 : panda_link1_1,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd(132ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[23ll], var123[23ll], var124[23ll], var125[23ll], arg3); //collision pair: 3,23 : panda_link1_2,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd(174ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[23ll], var123[23ll], var124[23ll], var125[23ll], arg3); //collision pair: 4,23 : panda_link1_3,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd(216ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[23ll], var123[23ll], var124[23ll], var125[23ll], arg3); //collision pair: 5,23 : panda_link2_0,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd(255ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[23ll], var123[23ll], var124[23ll], var125[23ll], arg3); //collision pair: 6,23 : panda_link2_1,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd(294ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[23ll], var123[23ll], var124[23ll], var125[23ll], arg3); //collision pair: 7,23 : panda_link2_2,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd(333ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[23ll], var123[23ll], var124[23ll], var125[23ll], arg3); //collision pair: 8,23 : panda_link2_3,panda_link5_6
  var122[24ll] = ((var107[0ll] * 0.00999999977648258f) + (var107[1ll] * 0.0949999988079071f)) + (var107[2ll] * -0.0500000007450581f);
  var123[24ll] = ((var107[3ll] * 0.00999999977648258f) + (var107[4ll] * 0.0949999988079071f)) + (var107[5ll] * -0.0500000007450581f);
  var124[24ll] = ((var107[6ll] * 0.00999999977648258f) + (var107[7ll] * 0.0949999988079071f)) + (var107[8ll] * -0.0500000007450581f);
  var122[24ll] = var122[24ll] + var110[0ll];
  var123[24ll] = var123[24ll] + var110[1ll];
  var124[24ll] = var124[24ll] + var110[2ll];
  var125[24ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd(7ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[24ll], var123[24ll], var124[24ll], var125[24ll], arg3); //collision pair: 0,24 : panda_link0_0,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd(49ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[24ll], var123[24ll], var124[24ll], var125[24ll], arg3); //collision pair: 1,24 : panda_link1_0,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd(91ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[24ll], var123[24ll], var124[24ll], var125[24ll], arg3); //collision pair: 2,24 : panda_link1_1,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd(133ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[24ll], var123[24ll], var124[24ll], var125[24ll], arg3); //collision pair: 3,24 : panda_link1_2,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd(175ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[24ll], var123[24ll], var124[24ll], var125[24ll], arg3); //collision pair: 4,24 : panda_link1_3,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd(217ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[24ll], var123[24ll], var124[24ll], var125[24ll], arg3); //collision pair: 5,24 : panda_link2_0,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd(256ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[24ll], var123[24ll], var124[24ll], var125[24ll], arg3); //collision pair: 6,24 : panda_link2_1,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd(295ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[24ll], var123[24ll], var124[24ll], var125[24ll], arg3); //collision pair: 7,24 : panda_link2_2,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd(334ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[24ll], var123[24ll], var124[24ll], var125[24ll], arg3); //collision pair: 8,24 : panda_link2_3,panda_link5_7
  var122[25ll] = ((var107[0ll] * -0.00999999977648258f) + (var107[1ll] * 0.0799999982118607f)) + (var107[2ll] * -0.140000000596046f);
  var123[25ll] = ((var107[3ll] * -0.00999999977648258f) + (var107[4ll] * 0.0799999982118607f)) + (var107[5ll] * -0.140000000596046f);
  var124[25ll] = ((var107[6ll] * -0.00999999977648258f) + (var107[7ll] * 0.0799999982118607f)) + (var107[8ll] * -0.140000000596046f);
  var122[25ll] = var122[25ll] + var110[0ll];
  var123[25ll] = var123[25ll] + var110[1ll];
  var124[25ll] = var124[25ll] + var110[2ll];
  var125[25ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd(8ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[25ll], var123[25ll], var124[25ll], var125[25ll], arg3); //collision pair: 0,25 : panda_link0_0,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd(50ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[25ll], var123[25ll], var124[25ll], var125[25ll], arg3); //collision pair: 1,25 : panda_link1_0,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd(92ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[25ll], var123[25ll], var124[25ll], var125[25ll], arg3); //collision pair: 2,25 : panda_link1_1,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd(134ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[25ll], var123[25ll], var124[25ll], var125[25ll], arg3); //collision pair: 3,25 : panda_link1_2,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd(176ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[25ll], var123[25ll], var124[25ll], var125[25ll], arg3); //collision pair: 4,25 : panda_link1_3,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd(218ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[25ll], var123[25ll], var124[25ll], var125[25ll], arg3); //collision pair: 5,25 : panda_link2_0,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd(257ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[25ll], var123[25ll], var124[25ll], var125[25ll], arg3); //collision pair: 6,25 : panda_link2_1,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd(296ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[25ll], var123[25ll], var124[25ll], var125[25ll], arg3); //collision pair: 7,25 : panda_link2_2,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd(335ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[25ll], var123[25ll], var124[25ll], var125[25ll], arg3); //collision pair: 8,25 : panda_link2_3,panda_link5_8
  var122[26ll] = ((var107[0ll] * -0.00999999977648258f) + (var107[1ll] * 0.0850000008940697f)) + (var107[2ll] * -0.109999999403954f);
  var123[26ll] = ((var107[3ll] * -0.00999999977648258f) + (var107[4ll] * 0.0850000008940697f)) + (var107[5ll] * -0.109999999403954f);
  var124[26ll] = ((var107[6ll] * -0.00999999977648258f) + (var107[7ll] * 0.0850000008940697f)) + (var107[8ll] * -0.109999999403954f);
  var122[26ll] = var122[26ll] + var110[0ll];
  var123[26ll] = var123[26ll] + var110[1ll];
  var124[26ll] = var124[26ll] + var110[2ll];
  var125[26ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd(9ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[26ll], var123[26ll], var124[26ll], var125[26ll], arg3); //collision pair: 0,26 : panda_link0_0,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd(51ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[26ll], var123[26ll], var124[26ll], var125[26ll], arg3); //collision pair: 1,26 : panda_link1_0,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd(93ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[26ll], var123[26ll], var124[26ll], var125[26ll], arg3); //collision pair: 2,26 : panda_link1_1,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd(135ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[26ll], var123[26ll], var124[26ll], var125[26ll], arg3); //collision pair: 3,26 : panda_link1_2,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd(177ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[26ll], var123[26ll], var124[26ll], var125[26ll], arg3); //collision pair: 4,26 : panda_link1_3,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd(219ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[26ll], var123[26ll], var124[26ll], var125[26ll], arg3); //collision pair: 5,26 : panda_link2_0,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd(258ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[26ll], var123[26ll], var124[26ll], var125[26ll], arg3); //collision pair: 6,26 : panda_link2_1,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd(297ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[26ll], var123[26ll], var124[26ll], var125[26ll], arg3); //collision pair: 7,26 : panda_link2_2,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd(336ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[26ll], var123[26ll], var124[26ll], var125[26ll], arg3); //collision pair: 8,26 : panda_link2_3,panda_link5_9
  var122[27ll] = ((var107[0ll] * -0.00999999977648258f) + (var107[1ll] * 0.0900000035762787f)) + (var107[2ll] * -0.0799999982118607f);
  var123[27ll] = ((var107[3ll] * -0.00999999977648258f) + (var107[4ll] * 0.0900000035762787f)) + (var107[5ll] * -0.0799999982118607f);
  var124[27ll] = ((var107[6ll] * -0.00999999977648258f) + (var107[7ll] * 0.0900000035762787f)) + (var107[8ll] * -0.0799999982118607f);
  var122[27ll] = var122[27ll] + var110[0ll];
  var123[27ll] = var123[27ll] + var110[1ll];
  var124[27ll] = var124[27ll] + var110[2ll];
  var125[27ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd(10ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[27ll], var123[27ll], var124[27ll], var125[27ll], arg3); //collision pair: 0,27 : panda_link0_0,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd(52ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[27ll], var123[27ll], var124[27ll], var125[27ll], arg3); //collision pair: 1,27 : panda_link1_0,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd(94ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[27ll], var123[27ll], var124[27ll], var125[27ll], arg3); //collision pair: 2,27 : panda_link1_1,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd(136ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[27ll], var123[27ll], var124[27ll], var125[27ll], arg3); //collision pair: 3,27 : panda_link1_2,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd(178ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[27ll], var123[27ll], var124[27ll], var125[27ll], arg3); //collision pair: 4,27 : panda_link1_3,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd(220ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[27ll], var123[27ll], var124[27ll], var125[27ll], arg3); //collision pair: 5,27 : panda_link2_0,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd(259ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[27ll], var123[27ll], var124[27ll], var125[27ll], arg3); //collision pair: 6,27 : panda_link2_1,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd(298ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[27ll], var123[27ll], var124[27ll], var125[27ll], arg3); //collision pair: 7,27 : panda_link2_2,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd(337ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[27ll], var123[27ll], var124[27ll], var125[27ll], arg3); //collision pair: 8,27 : panda_link2_3,panda_link5_10
  var122[28ll] = ((var107[0ll] * -0.00999999977648258f) + (var107[1ll] * 0.0949999988079071f)) + (var107[2ll] * -0.0500000007450581f);
  var123[28ll] = ((var107[3ll] * -0.00999999977648258f) + (var107[4ll] * 0.0949999988079071f)) + (var107[5ll] * -0.0500000007450581f);
  var124[28ll] = ((var107[6ll] * -0.00999999977648258f) + (var107[7ll] * 0.0949999988079071f)) + (var107[8ll] * -0.0500000007450581f);
  var122[28ll] = var122[28ll] + var110[0ll];
  var123[28ll] = var123[28ll] + var110[1ll];
  var124[28ll] = var124[28ll] + var110[2ll];
  var125[28ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd(11ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[28ll], var123[28ll], var124[28ll], var125[28ll], arg3); //collision pair: 0,28 : panda_link0_0,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd(53ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[28ll], var123[28ll], var124[28ll], var125[28ll], arg3); //collision pair: 1,28 : panda_link1_0,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd(95ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[28ll], var123[28ll], var124[28ll], var125[28ll], arg3); //collision pair: 2,28 : panda_link1_1,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd(137ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[28ll], var123[28ll], var124[28ll], var125[28ll], arg3); //collision pair: 3,28 : panda_link1_2,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd(179ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[28ll], var123[28ll], var124[28ll], var125[28ll], arg3); //collision pair: 4,28 : panda_link1_3,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd(221ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[28ll], var123[28ll], var124[28ll], var125[28ll], arg3); //collision pair: 5,28 : panda_link2_0,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd(260ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[28ll], var123[28ll], var124[28ll], var125[28ll], arg3); //collision pair: 6,28 : panda_link2_1,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd(299ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[28ll], var123[28ll], var124[28ll], var125[28ll], arg3); //collision pair: 7,28 : panda_link2_2,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd(338ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[28ll], var123[28ll], var124[28ll], var125[28ll], arg3); //collision pair: 8,28 : panda_link2_3,panda_link5_11
  blaze::StaticVector<float, 8> var219 = arg2[5ll];
  var73 = sin(var219);
  var74 = cos(var219);
  var72[0ll] = var74;
  var72[1ll] = -(var73);
  var72[2ll] = var73;
  var72[3ll] = var74;
  blaze::StaticVector<float, 8> var220;
  var220 = 0;
  var220 = var220 + (1.0f * var72[0ll]);
  var126[0ll] = var220;
  blaze::StaticVector<float, 8> var221;
  var221 = 0;
  var221 = var221 + (1.0f * var72[1ll]);
  var126[1ll] = var221;
  blaze::StaticVector<float, 8> var222;
  var222 = 0;
  var222 = var222 + (1.0f * var72[2ll]);
  var126[2ll] = var222;
  blaze::StaticVector<float, 8> var223;
  var223 = 0;
  var223 = var223 + (1.0f * var72[3ll]);
  var126[3ll] = var223;
  blaze::StaticVector<float, 8> var224;
  var224 = 0;
  var224 = var224 + (1.0f * 1.0f);
  var130 = var224;
  blaze::StaticVector<float, 8> var225;
  var225 = 0;
  var225 = var225 + (var107[0ll] * var126[0ll]);
  var225 = var225 + (var107[2ll] * var126[2ll]);
  var112[0ll] = var225;
  blaze::StaticVector<float, 8> var226;
  var226 = 0;
  var226 = var226 + (var107[0ll] * var126[1ll]);
  var226 = var226 + (var107[2ll] * var126[3ll]);
  var112[1ll] = var226;
  blaze::StaticVector<float, 8> var227;
  var227 = 0;
  var227 = var227 + (var107[1ll] * -1.0f);
  var112[2ll] = var227;
  blaze::StaticVector<float, 8> var228;
  var228 = 0;
  var228 = var228 + (var107[3ll] * var126[0ll]);
  var228 = var228 + (var107[5ll] * var126[2ll]);
  var112[3ll] = var228;
  blaze::StaticVector<float, 8> var229;
  var229 = 0;
  var229 = var229 + (var107[3ll] * var126[1ll]);
  var229 = var229 + (var107[5ll] * var126[3ll]);
  var112[4ll] = var229;
  blaze::StaticVector<float, 8> var230;
  var230 = 0;
  var230 = var230 + (var107[4ll] * -1.0f);
  var112[5ll] = var230;
  blaze::StaticVector<float, 8> var231;
  var231 = 0;
  var231 = var231 + (var107[6ll] * var126[0ll]);
  var231 = var231 + (var107[8ll] * var126[2ll]);
  var112[6ll] = var231;
  blaze::StaticVector<float, 8> var232;
  var232 = 0;
  var232 = var232 + (var107[6ll] * var126[1ll]);
  var232 = var232 + (var107[8ll] * var126[3ll]);
  var112[7ll] = var232;
  blaze::StaticVector<float, 8> var233;
  var233 = 0;
  var233 = var233 + (var107[7ll] * -1.0f);
  var112[8ll] = var233;
  blaze::StaticVector<float, 8> var234;
  var234 = 0;
  var234 = var234 + (var110[0ll] * var130);
  var115[0ll] = var234;
  blaze::StaticVector<float, 8> var235;
  var235 = 0;
  var235 = var235 + (var110[1ll] * var130);
  var115[1ll] = var235;
  blaze::StaticVector<float, 8> var236;
  var236 = 0;
  var236 = var236 + (var110[2ll] * var130);
  var115[2ll] = var236;
  blaze::StaticVector<float, 8> var237;
  var237 = 0;
  var237 = var237 + (var111 * var130);
  var116 = var237;
  var122[29ll] = ((var112[0ll] * 0.0f) + (var112[1ll] * 0.0f)) + (var112[2ll] * 0.0f);
  var123[29ll] = ((var112[3ll] * 0.0f) + (var112[4ll] * 0.0f)) + (var112[5ll] * 0.0f);
  var124[29ll] = ((var112[6ll] * 0.0f) + (var112[7ll] * 0.0f)) + (var112[8ll] * 0.0f);
  var122[29ll] = var122[29ll] + var115[0ll];
  var123[29ll] = var123[29ll] + var115[1ll];
  var124[29ll] = var124[29ll] + var115[2ll];
  var125[29ll] = 0.0500000007450581f;
  cg_sd_runtime::compute_sph_sph_cp_sd(12ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[29ll], var123[29ll], var124[29ll], var125[29ll], arg3); //collision pair: 0,29 : panda_link0_0,panda_link6_0
  cg_sd_runtime::compute_sph_sph_cp_sd(54ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[29ll], var123[29ll], var124[29ll], var125[29ll], arg3); //collision pair: 1,29 : panda_link1_0,panda_link6_0
  cg_sd_runtime::compute_sph_sph_cp_sd(96ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[29ll], var123[29ll], var124[29ll], var125[29ll], arg3); //collision pair: 2,29 : panda_link1_1,panda_link6_0
  cg_sd_runtime::compute_sph_sph_cp_sd(138ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[29ll], var123[29ll], var124[29ll], var125[29ll], arg3); //collision pair: 3,29 : panda_link1_2,panda_link6_0
  cg_sd_runtime::compute_sph_sph_cp_sd(180ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[29ll], var123[29ll], var124[29ll], var125[29ll], arg3); //collision pair: 4,29 : panda_link1_3,panda_link6_0
  var122[30ll] = ((var112[0ll] * 0.0799999982118607f) + (var112[1ll] * -0.00999999977648258f)) + (var112[2ll] * 0.0f);
  var123[30ll] = ((var112[3ll] * 0.0799999982118607f) + (var112[4ll] * -0.00999999977648258f)) + (var112[5ll] * 0.0f);
  var124[30ll] = ((var112[6ll] * 0.0799999982118607f) + (var112[7ll] * -0.00999999977648258f)) + (var112[8ll] * 0.0f);
  var122[30ll] = var122[30ll] + var115[0ll];
  var123[30ll] = var123[30ll] + var115[1ll];
  var124[30ll] = var124[30ll] + var115[2ll];
  var125[30ll] = 0.0500000007450581f;
  cg_sd_runtime::compute_sph_sph_cp_sd(13ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[30ll], var123[30ll], var124[30ll], var125[30ll], arg3); //collision pair: 0,30 : panda_link0_0,panda_link6_1
  cg_sd_runtime::compute_sph_sph_cp_sd(55ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[30ll], var123[30ll], var124[30ll], var125[30ll], arg3); //collision pair: 1,30 : panda_link1_0,panda_link6_1
  cg_sd_runtime::compute_sph_sph_cp_sd(97ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[30ll], var123[30ll], var124[30ll], var125[30ll], arg3); //collision pair: 2,30 : panda_link1_1,panda_link6_1
  cg_sd_runtime::compute_sph_sph_cp_sd(139ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[30ll], var123[30ll], var124[30ll], var125[30ll], arg3); //collision pair: 3,30 : panda_link1_2,panda_link6_1
  cg_sd_runtime::compute_sph_sph_cp_sd(181ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[30ll], var123[30ll], var124[30ll], var125[30ll], arg3); //collision pair: 4,30 : panda_link1_3,panda_link6_1
  var122[31ll] = ((var112[0ll] * 0.0799999982118607f) + (var112[1ll] * 0.0350000001490116f)) + (var112[2ll] * 0.0f);
  var123[31ll] = ((var112[3ll] * 0.0799999982118607f) + (var112[4ll] * 0.0350000001490116f)) + (var112[5ll] * 0.0f);
  var124[31ll] = ((var112[6ll] * 0.0799999982118607f) + (var112[7ll] * 0.0350000001490116f)) + (var112[8ll] * 0.0f);
  var122[31ll] = var122[31ll] + var115[0ll];
  var123[31ll] = var123[31ll] + var115[1ll];
  var124[31ll] = var124[31ll] + var115[2ll];
  var125[31ll] = 0.0520000010728836f;
  cg_sd_runtime::compute_sph_sph_cp_sd(14ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[31ll], var123[31ll], var124[31ll], var125[31ll], arg3); //collision pair: 0,31 : panda_link0_0,panda_link6_2
  cg_sd_runtime::compute_sph_sph_cp_sd(56ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[31ll], var123[31ll], var124[31ll], var125[31ll], arg3); //collision pair: 1,31 : panda_link1_0,panda_link6_2
  cg_sd_runtime::compute_sph_sph_cp_sd(98ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[31ll], var123[31ll], var124[31ll], var125[31ll], arg3); //collision pair: 2,31 : panda_link1_1,panda_link6_2
  cg_sd_runtime::compute_sph_sph_cp_sd(140ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[31ll], var123[31ll], var124[31ll], var125[31ll], arg3); //collision pair: 3,31 : panda_link1_2,panda_link6_2
  cg_sd_runtime::compute_sph_sph_cp_sd(182ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[31ll], var123[31ll], var124[31ll], var125[31ll], arg3); //collision pair: 4,31 : panda_link1_3,panda_link6_2
  blaze::StaticVector<float, 8> var238 = arg2[6ll];
  var78 = sin(var238);
  var79 = cos(var238);
  var77[0ll] = var79;
  var77[1ll] = -(var78);
  var77[2ll] = var78;
  var77[3ll] = var79;
  blaze::StaticVector<float, 8> var239;
  var239 = 0;
  var239 = var239 + (1.0f * var77[0ll]);
  var126[0ll] = var239;
  blaze::StaticVector<float, 8> var240;
  var240 = 0;
  var240 = var240 + (1.0f * var77[1ll]);
  var126[1ll] = var240;
  blaze::StaticVector<float, 8> var241;
  var241 = 0;
  var241 = var241 + (1.0f * var77[2ll]);
  var126[2ll] = var241;
  blaze::StaticVector<float, 8> var242;
  var242 = 0;
  var242 = var242 + (1.0f * var77[3ll]);
  var126[3ll] = var242;
  blaze::StaticVector<float, 8> var243;
  var243 = 0;
  var243 = var243 + (1.0f * 1.0f);
  var130 = var243;
  blaze::StaticVector<float, 8> var244;
  var244 = 0;
  var244 = var244 + (var112[0ll] * var126[0ll]);
  var244 = var244 + (var112[2ll] * var126[2ll]);
  var117[0ll] = var244;
  blaze::StaticVector<float, 8> var245;
  var245 = 0;
  var245 = var245 + (var112[0ll] * var126[1ll]);
  var245 = var245 + (var112[2ll] * var126[3ll]);
  var117[1ll] = var245;
  blaze::StaticVector<float, 8> var246;
  var246 = 0;
  var246 = var246 + (var112[1ll] * -1.0f);
  var117[2ll] = var246;
  blaze::StaticVector<float, 8> var247;
  var247 = 0;
  var247 = var247 + (var112[3ll] * var126[0ll]);
  var247 = var247 + (var112[5ll] * var126[2ll]);
  var117[3ll] = var247;
  blaze::StaticVector<float, 8> var248;
  var248 = 0;
  var248 = var248 + (var112[3ll] * var126[1ll]);
  var248 = var248 + (var112[5ll] * var126[3ll]);
  var117[4ll] = var248;
  blaze::StaticVector<float, 8> var249;
  var249 = 0;
  var249 = var249 + (var112[4ll] * -1.0f);
  var117[5ll] = var249;
  blaze::StaticVector<float, 8> var250;
  var250 = 0;
  var250 = var250 + (var112[6ll] * var126[0ll]);
  var250 = var250 + (var112[8ll] * var126[2ll]);
  var117[6ll] = var250;
  blaze::StaticVector<float, 8> var251;
  var251 = 0;
  var251 = var251 + (var112[6ll] * var126[1ll]);
  var251 = var251 + (var112[8ll] * var126[3ll]);
  var117[7ll] = var251;
  blaze::StaticVector<float, 8> var252;
  var252 = 0;
  var252 = var252 + (var112[7ll] * -1.0f);
  var117[8ll] = var252;
  blaze::StaticVector<float, 8> var253;
  var253 = 0;
  var253 = var253 + (var115[0ll] * var130);
  blaze::StaticVector<float, 8> var254;
  var254 = 0;
  var254 = var254 + (var112[0ll] * 0.0879999995231628f);
  var120[0ll] = var254 + var253;
  blaze::StaticVector<float, 8> var255;
  var255 = 0;
  var255 = var255 + (var115[1ll] * var130);
  blaze::StaticVector<float, 8> var256;
  var256 = 0;
  var256 = var256 + (var112[3ll] * 0.0879999995231628f);
  var120[1ll] = var256 + var255;
  blaze::StaticVector<float, 8> var257;
  var257 = 0;
  var257 = var257 + (var115[2ll] * var130);
  blaze::StaticVector<float, 8> var258;
  var258 = 0;
  var258 = var258 + (var112[6ll] * 0.0879999995231628f);
  var120[2ll] = var258 + var257;
  blaze::StaticVector<float, 8> var259;
  var259 = 0;
  var259 = var259 + (var116 * var130);
  var121 = var259;
  var122[32ll] = ((var117[0ll] * 0.0f) + (var117[1ll] * 0.0f)) + (var117[2ll] * 0.0700000002980232f);
  var123[32ll] = ((var117[3ll] * 0.0f) + (var117[4ll] * 0.0f)) + (var117[5ll] * 0.0700000002980232f);
  var124[32ll] = ((var117[6ll] * 0.0f) + (var117[7ll] * 0.0f)) + (var117[8ll] * 0.0700000002980232f);
  var122[32ll] = var122[32ll] + var120[0ll];
  var123[32ll] = var123[32ll] + var120[1ll];
  var124[32ll] = var124[32ll] + var120[2ll];
  var125[32ll] = 0.0500000007450581f;
  cg_sd_runtime::compute_sph_sph_cp_sd(15ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 0,32 : panda_link0_0,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(57ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 1,32 : panda_link1_0,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(99ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 2,32 : panda_link1_1,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(141ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 3,32 : panda_link1_2,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(183ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 4,32 : panda_link1_3,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(222ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 5,32 : panda_link2_0,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(261ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 6,32 : panda_link2_1,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(300ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 7,32 : panda_link2_2,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(339ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 8,32 : panda_link2_3,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(366ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 17,32 : panda_link5_0,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(393ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 18,32 : panda_link5_1,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(420ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 19,32 : panda_link5_2,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(447ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 20,32 : panda_link5_3,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(474ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 21,32 : panda_link5_4,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(501ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 22,32 : panda_link5_5,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(528ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 23,32 : panda_link5_6,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(555ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 24,32 : panda_link5_7,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(582ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 25,32 : panda_link5_8,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(609ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 26,32 : panda_link5_9,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(636ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 27,32 : panda_link5_10,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd(663ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[32ll], var123[32ll], var124[32ll], var125[32ll], arg3); //collision pair: 28,32 : panda_link5_11,panda_link7_0
  var122[33ll] = ((var117[0ll] * 0.0199999995529652f) + (var117[1ll] * 0.0399999991059303f)) + (var117[2ll] * 0.0799999982118607f);
  var123[33ll] = ((var117[3ll] * 0.0199999995529652f) + (var117[4ll] * 0.0399999991059303f)) + (var117[5ll] * 0.0799999982118607f);
  var124[33ll] = ((var117[6ll] * 0.0199999995529652f) + (var117[7ll] * 0.0399999991059303f)) + (var117[8ll] * 0.0799999982118607f);
  var122[33ll] = var122[33ll] + var120[0ll];
  var123[33ll] = var123[33ll] + var120[1ll];
  var124[33ll] = var124[33ll] + var120[2ll];
  var125[33ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd(16ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 0,33 : panda_link0_0,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(58ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 1,33 : panda_link1_0,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(100ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 2,33 : panda_link1_1,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(142ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 3,33 : panda_link1_2,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(184ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 4,33 : panda_link1_3,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(223ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 5,33 : panda_link2_0,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(262ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 6,33 : panda_link2_1,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(301ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 7,33 : panda_link2_2,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(340ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 8,33 : panda_link2_3,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(367ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 17,33 : panda_link5_0,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(394ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 18,33 : panda_link5_1,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(421ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 19,33 : panda_link5_2,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(448ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 20,33 : panda_link5_3,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(475ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 21,33 : panda_link5_4,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(502ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 22,33 : panda_link5_5,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(529ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 23,33 : panda_link5_6,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(556ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 24,33 : panda_link5_7,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(583ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 25,33 : panda_link5_8,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(610ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 26,33 : panda_link5_9,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(637ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 27,33 : panda_link5_10,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd(664ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[33ll], var123[33ll], var124[33ll], var125[33ll], arg3); //collision pair: 28,33 : panda_link5_11,panda_link7_1
  var122[34ll] = ((var117[0ll] * 0.0399999991059303f) + (var117[1ll] * 0.0199999995529652f)) + (var117[2ll] * 0.0799999982118607f);
  var123[34ll] = ((var117[3ll] * 0.0399999991059303f) + (var117[4ll] * 0.0199999995529652f)) + (var117[5ll] * 0.0799999982118607f);
  var124[34ll] = ((var117[6ll] * 0.0399999991059303f) + (var117[7ll] * 0.0199999995529652f)) + (var117[8ll] * 0.0799999982118607f);
  var122[34ll] = var122[34ll] + var120[0ll];
  var123[34ll] = var123[34ll] + var120[1ll];
  var124[34ll] = var124[34ll] + var120[2ll];
  var125[34ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd(17ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 0,34 : panda_link0_0,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(59ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 1,34 : panda_link1_0,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(101ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 2,34 : panda_link1_1,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(143ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 3,34 : panda_link1_2,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(185ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 4,34 : panda_link1_3,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(224ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 5,34 : panda_link2_0,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(263ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 6,34 : panda_link2_1,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(302ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 7,34 : panda_link2_2,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(341ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 8,34 : panda_link2_3,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(368ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 17,34 : panda_link5_0,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(395ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 18,34 : panda_link5_1,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(422ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 19,34 : panda_link5_2,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(449ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 20,34 : panda_link5_3,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(476ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 21,34 : panda_link5_4,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(503ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 22,34 : panda_link5_5,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(530ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 23,34 : panda_link5_6,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(557ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 24,34 : panda_link5_7,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(584ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 25,34 : panda_link5_8,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(611ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 26,34 : panda_link5_9,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(638ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 27,34 : panda_link5_10,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd(665ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[34ll], var123[34ll], var124[34ll], var125[34ll], arg3); //collision pair: 28,34 : panda_link5_11,panda_link7_2
  var122[35ll] = ((var117[0ll] * 0.0399999991059303f) + (var117[1ll] * 0.0599999986588955f)) + (var117[2ll] * 0.0850000008940697f);
  var123[35ll] = ((var117[3ll] * 0.0399999991059303f) + (var117[4ll] * 0.0599999986588955f)) + (var117[5ll] * 0.0850000008940697f);
  var124[35ll] = ((var117[6ll] * 0.0399999991059303f) + (var117[7ll] * 0.0599999986588955f)) + (var117[8ll] * 0.0850000008940697f);
  var122[35ll] = var122[35ll] + var120[0ll];
  var123[35ll] = var123[35ll] + var120[1ll];
  var124[35ll] = var124[35ll] + var120[2ll];
  var125[35ll] = 0.0199999995529652f;
  cg_sd_runtime::compute_sph_sph_cp_sd(18ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 0,35 : panda_link0_0,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(60ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 1,35 : panda_link1_0,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(102ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 2,35 : panda_link1_1,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(144ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 3,35 : panda_link1_2,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(186ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 4,35 : panda_link1_3,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(225ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 5,35 : panda_link2_0,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(264ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 6,35 : panda_link2_1,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(303ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 7,35 : panda_link2_2,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(342ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 8,35 : panda_link2_3,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(369ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 17,35 : panda_link5_0,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(396ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 18,35 : panda_link5_1,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(423ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 19,35 : panda_link5_2,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(450ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 20,35 : panda_link5_3,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(477ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 21,35 : panda_link5_4,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(504ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 22,35 : panda_link5_5,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(531ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 23,35 : panda_link5_6,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(558ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 24,35 : panda_link5_7,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(585ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 25,35 : panda_link5_8,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(612ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 26,35 : panda_link5_9,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(639ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 27,35 : panda_link5_10,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd(666ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[35ll], var123[35ll], var124[35ll], var125[35ll], arg3); //collision pair: 28,35 : panda_link5_11,panda_link7_3
  var122[36ll] = ((var117[0ll] * 0.0599999986588955f) + (var117[1ll] * 0.0399999991059303f)) + (var117[2ll] * 0.0850000008940697f);
  var123[36ll] = ((var117[3ll] * 0.0599999986588955f) + (var117[4ll] * 0.0399999991059303f)) + (var117[5ll] * 0.0850000008940697f);
  var124[36ll] = ((var117[6ll] * 0.0599999986588955f) + (var117[7ll] * 0.0399999991059303f)) + (var117[8ll] * 0.0850000008940697f);
  var122[36ll] = var122[36ll] + var120[0ll];
  var123[36ll] = var123[36ll] + var120[1ll];
  var124[36ll] = var124[36ll] + var120[2ll];
  var125[36ll] = 0.0199999995529652f;
  cg_sd_runtime::compute_sph_sph_cp_sd(19ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 0,36 : panda_link0_0,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(61ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 1,36 : panda_link1_0,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(103ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 2,36 : panda_link1_1,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(145ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 3,36 : panda_link1_2,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(187ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 4,36 : panda_link1_3,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(226ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 5,36 : panda_link2_0,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(265ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 6,36 : panda_link2_1,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(304ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 7,36 : panda_link2_2,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(343ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 8,36 : panda_link2_3,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(370ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 17,36 : panda_link5_0,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(397ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 18,36 : panda_link5_1,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(424ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 19,36 : panda_link5_2,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(451ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 20,36 : panda_link5_3,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(478ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 21,36 : panda_link5_4,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(505ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 22,36 : panda_link5_5,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(532ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 23,36 : panda_link5_6,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(559ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 24,36 : panda_link5_7,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(586ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 25,36 : panda_link5_8,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(613ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 26,36 : panda_link5_9,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(640ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 27,36 : panda_link5_10,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd(667ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[36ll], var123[36ll], var124[36ll], var125[36ll], arg3); //collision pair: 28,36 : panda_link5_11,panda_link7_4
  var122[37ll] = ((var117[0ll] * -0.0530330091714859f) + (var117[1ll] * -0.0530330091714859f)) + (var117[2ll] * 0.116999998688698f);
  var123[37ll] = ((var117[3ll] * -0.0530330091714859f) + (var117[4ll] * -0.0530330091714859f)) + (var117[5ll] * 0.116999998688698f);
  var124[37ll] = ((var117[6ll] * -0.0530330091714859f) + (var117[7ll] * -0.0530330091714859f)) + (var117[8ll] * 0.116999998688698f);
  var122[37ll] = var122[37ll] + var120[0ll];
  var123[37ll] = var123[37ll] + var120[1ll];
  var124[37ll] = var124[37ll] + var120[2ll];
  var125[37ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd(20ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 0,37 : panda_link0_0,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(62ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 1,37 : panda_link1_0,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(104ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 2,37 : panda_link1_1,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(146ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 3,37 : panda_link1_2,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(188ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 4,37 : panda_link1_3,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(227ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 5,37 : panda_link2_0,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(266ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 6,37 : panda_link2_1,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(305ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 7,37 : panda_link2_2,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(344ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 8,37 : panda_link2_3,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(371ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 17,37 : panda_link5_0,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(398ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 18,37 : panda_link5_1,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(425ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 19,37 : panda_link5_2,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(452ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 20,37 : panda_link5_3,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(479ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 21,37 : panda_link5_4,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(506ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 22,37 : panda_link5_5,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(533ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 23,37 : panda_link5_6,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(560ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 24,37 : panda_link5_7,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(587ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 25,37 : panda_link5_8,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(614ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 26,37 : panda_link5_9,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(641ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 27,37 : panda_link5_10,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd(668ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[37ll], var123[37ll], var124[37ll], var125[37ll], arg3); //collision pair: 28,37 : panda_link5_11,panda_hand_0
  var122[38ll] = ((var117[0ll] * -0.0318198055028915f) + (var117[1ll] * -0.0318198055028915f)) + (var117[2ll] * 0.116999998688698f);
  var123[38ll] = ((var117[3ll] * -0.0318198055028915f) + (var117[4ll] * -0.0318198055028915f)) + (var117[5ll] * 0.116999998688698f);
  var124[38ll] = ((var117[6ll] * -0.0318198055028915f) + (var117[7ll] * -0.0318198055028915f)) + (var117[8ll] * 0.116999998688698f);
  var122[38ll] = var122[38ll] + var120[0ll];
  var123[38ll] = var123[38ll] + var120[1ll];
  var124[38ll] = var124[38ll] + var120[2ll];
  var125[38ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd(21ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 0,38 : panda_link0_0,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(63ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 1,38 : panda_link1_0,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(105ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 2,38 : panda_link1_1,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(147ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 3,38 : panda_link1_2,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(189ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 4,38 : panda_link1_3,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(228ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 5,38 : panda_link2_0,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(267ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 6,38 : panda_link2_1,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(306ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 7,38 : panda_link2_2,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(345ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 8,38 : panda_link2_3,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(372ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 17,38 : panda_link5_0,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(399ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 18,38 : panda_link5_1,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(426ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 19,38 : panda_link5_2,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(453ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 20,38 : panda_link5_3,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(480ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 21,38 : panda_link5_4,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(507ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 22,38 : panda_link5_5,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(534ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 23,38 : panda_link5_6,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(561ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 24,38 : panda_link5_7,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(588ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 25,38 : panda_link5_8,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(615ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 26,38 : panda_link5_9,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(642ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 27,38 : panda_link5_10,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd(669ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[38ll], var123[38ll], var124[38ll], var125[38ll], arg3); //collision pair: 28,38 : panda_link5_11,panda_hand_1
  var122[39ll] = ((var117[0ll] * -0.0106066018342972f) + (var117[1ll] * -0.0106066018342972f)) + (var117[2ll] * 0.116999998688698f);
  var123[39ll] = ((var117[3ll] * -0.0106066018342972f) + (var117[4ll] * -0.0106066018342972f)) + (var117[5ll] * 0.116999998688698f);
  var124[39ll] = ((var117[6ll] * -0.0106066018342972f) + (var117[7ll] * -0.0106066018342972f)) + (var117[8ll] * 0.116999998688698f);
  var122[39ll] = var122[39ll] + var120[0ll];
  var123[39ll] = var123[39ll] + var120[1ll];
  var124[39ll] = var124[39ll] + var120[2ll];
  var125[39ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd(22ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 0,39 : panda_link0_0,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(64ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 1,39 : panda_link1_0,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(106ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 2,39 : panda_link1_1,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(148ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 3,39 : panda_link1_2,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(190ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 4,39 : panda_link1_3,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(229ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 5,39 : panda_link2_0,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(268ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 6,39 : panda_link2_1,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(307ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 7,39 : panda_link2_2,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(346ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 8,39 : panda_link2_3,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(373ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 17,39 : panda_link5_0,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(400ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 18,39 : panda_link5_1,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(427ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 19,39 : panda_link5_2,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(454ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 20,39 : panda_link5_3,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(481ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 21,39 : panda_link5_4,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(508ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 22,39 : panda_link5_5,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(535ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 23,39 : panda_link5_6,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(562ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 24,39 : panda_link5_7,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(589ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 25,39 : panda_link5_8,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(616ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 26,39 : panda_link5_9,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(643ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 27,39 : panda_link5_10,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd(670ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[39ll], var123[39ll], var124[39ll], var125[39ll], arg3); //collision pair: 28,39 : panda_link5_11,panda_hand_2
  var122[40ll] = ((var117[0ll] * 0.0106066018342972f) + (var117[1ll] * 0.0106066018342972f)) + (var117[2ll] * 0.116999998688698f);
  var123[40ll] = ((var117[3ll] * 0.0106066018342972f) + (var117[4ll] * 0.0106066018342972f)) + (var117[5ll] * 0.116999998688698f);
  var124[40ll] = ((var117[6ll] * 0.0106066018342972f) + (var117[7ll] * 0.0106066018342972f)) + (var117[8ll] * 0.116999998688698f);
  var122[40ll] = var122[40ll] + var120[0ll];
  var123[40ll] = var123[40ll] + var120[1ll];
  var124[40ll] = var124[40ll] + var120[2ll];
  var125[40ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd(23ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 0,40 : panda_link0_0,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(65ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 1,40 : panda_link1_0,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(107ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 2,40 : panda_link1_1,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(149ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 3,40 : panda_link1_2,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(191ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 4,40 : panda_link1_3,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(230ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 5,40 : panda_link2_0,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(269ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 6,40 : panda_link2_1,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(308ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 7,40 : panda_link2_2,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(347ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 8,40 : panda_link2_3,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(374ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 17,40 : panda_link5_0,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(401ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 18,40 : panda_link5_1,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(428ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 19,40 : panda_link5_2,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(455ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 20,40 : panda_link5_3,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(482ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 21,40 : panda_link5_4,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(509ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 22,40 : panda_link5_5,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(536ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 23,40 : panda_link5_6,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(563ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 24,40 : panda_link5_7,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(590ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 25,40 : panda_link5_8,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(617ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 26,40 : panda_link5_9,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(644ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 27,40 : panda_link5_10,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd(671ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[40ll], var123[40ll], var124[40ll], var125[40ll], arg3); //collision pair: 28,40 : panda_link5_11,panda_hand_3
  var122[41ll] = ((var117[0ll] * 0.0318198055028915f) + (var117[1ll] * 0.0318198055028915f)) + (var117[2ll] * 0.116999998688698f);
  var123[41ll] = ((var117[3ll] * 0.0318198055028915f) + (var117[4ll] * 0.0318198055028915f)) + (var117[5ll] * 0.116999998688698f);
  var124[41ll] = ((var117[6ll] * 0.0318198055028915f) + (var117[7ll] * 0.0318198055028915f)) + (var117[8ll] * 0.116999998688698f);
  var122[41ll] = var122[41ll] + var120[0ll];
  var123[41ll] = var123[41ll] + var120[1ll];
  var124[41ll] = var124[41ll] + var120[2ll];
  var125[41ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd(24ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 0,41 : panda_link0_0,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(66ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 1,41 : panda_link1_0,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(108ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 2,41 : panda_link1_1,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(150ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 3,41 : panda_link1_2,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(192ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 4,41 : panda_link1_3,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(231ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 5,41 : panda_link2_0,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(270ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 6,41 : panda_link2_1,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(309ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 7,41 : panda_link2_2,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(348ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 8,41 : panda_link2_3,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(375ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 17,41 : panda_link5_0,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(402ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 18,41 : panda_link5_1,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(429ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 19,41 : panda_link5_2,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(456ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 20,41 : panda_link5_3,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(483ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 21,41 : panda_link5_4,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(510ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 22,41 : panda_link5_5,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(537ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 23,41 : panda_link5_6,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(564ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 24,41 : panda_link5_7,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(591ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 25,41 : panda_link5_8,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(618ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 26,41 : panda_link5_9,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(645ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 27,41 : panda_link5_10,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd(672ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[41ll], var123[41ll], var124[41ll], var125[41ll], arg3); //collision pair: 28,41 : panda_link5_11,panda_hand_4
  var122[42ll] = ((var117[0ll] * 0.0530330091714859f) + (var117[1ll] * 0.0530330091714859f)) + (var117[2ll] * 0.116999998688698f);
  var123[42ll] = ((var117[3ll] * 0.0530330091714859f) + (var117[4ll] * 0.0530330091714859f)) + (var117[5ll] * 0.116999998688698f);
  var124[42ll] = ((var117[6ll] * 0.0530330091714859f) + (var117[7ll] * 0.0530330091714859f)) + (var117[8ll] * 0.116999998688698f);
  var122[42ll] = var122[42ll] + var120[0ll];
  var123[42ll] = var123[42ll] + var120[1ll];
  var124[42ll] = var124[42ll] + var120[2ll];
  var125[42ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd(25ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 0,42 : panda_link0_0,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(67ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 1,42 : panda_link1_0,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(109ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 2,42 : panda_link1_1,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(151ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 3,42 : panda_link1_2,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(193ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 4,42 : panda_link1_3,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(232ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 5,42 : panda_link2_0,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(271ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 6,42 : panda_link2_1,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(310ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 7,42 : panda_link2_2,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(349ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 8,42 : panda_link2_3,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(376ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 17,42 : panda_link5_0,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(403ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 18,42 : panda_link5_1,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(430ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 19,42 : panda_link5_2,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(457ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 20,42 : panda_link5_3,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(484ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 21,42 : panda_link5_4,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(511ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 22,42 : panda_link5_5,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(538ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 23,42 : panda_link5_6,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(565ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 24,42 : panda_link5_7,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(592ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 25,42 : panda_link5_8,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(619ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 26,42 : panda_link5_9,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(646ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 27,42 : panda_link5_10,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd(673ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[42ll], var123[42ll], var124[42ll], var125[42ll], arg3); //collision pair: 28,42 : panda_link5_11,panda_hand_5
  var122[43ll] = ((var117[0ll] * -0.0530330091714859f) + (var117[1ll] * -0.0530330091714859f)) + (var117[2ll] * 0.136999994516373f);
  var123[43ll] = ((var117[3ll] * -0.0530330091714859f) + (var117[4ll] * -0.0530330091714859f)) + (var117[5ll] * 0.136999994516373f);
  var124[43ll] = ((var117[6ll] * -0.0530330091714859f) + (var117[7ll] * -0.0530330091714859f)) + (var117[8ll] * 0.136999994516373f);
  var122[43ll] = var122[43ll] + var120[0ll];
  var123[43ll] = var123[43ll] + var120[1ll];
  var124[43ll] = var124[43ll] + var120[2ll];
  var125[43ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd(26ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 0,43 : panda_link0_0,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(68ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 1,43 : panda_link1_0,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(110ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 2,43 : panda_link1_1,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(152ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 3,43 : panda_link1_2,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(194ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 4,43 : panda_link1_3,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(233ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 5,43 : panda_link2_0,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(272ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 6,43 : panda_link2_1,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(311ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 7,43 : panda_link2_2,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(350ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 8,43 : panda_link2_3,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(377ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 17,43 : panda_link5_0,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(404ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 18,43 : panda_link5_1,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(431ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 19,43 : panda_link5_2,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(458ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 20,43 : panda_link5_3,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(485ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 21,43 : panda_link5_4,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(512ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 22,43 : panda_link5_5,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(539ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 23,43 : panda_link5_6,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(566ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 24,43 : panda_link5_7,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(593ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 25,43 : panda_link5_8,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(620ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 26,43 : panda_link5_9,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(647ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 27,43 : panda_link5_10,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd(674ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[43ll], var123[43ll], var124[43ll], var125[43ll], arg3); //collision pair: 28,43 : panda_link5_11,panda_hand_6
  var122[44ll] = ((var117[0ll] * -0.0318198055028915f) + (var117[1ll] * -0.0318198055028915f)) + (var117[2ll] * 0.136999994516373f);
  var123[44ll] = ((var117[3ll] * -0.0318198055028915f) + (var117[4ll] * -0.0318198055028915f)) + (var117[5ll] * 0.136999994516373f);
  var124[44ll] = ((var117[6ll] * -0.0318198055028915f) + (var117[7ll] * -0.0318198055028915f)) + (var117[8ll] * 0.136999994516373f);
  var122[44ll] = var122[44ll] + var120[0ll];
  var123[44ll] = var123[44ll] + var120[1ll];
  var124[44ll] = var124[44ll] + var120[2ll];
  var125[44ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd(27ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 0,44 : panda_link0_0,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(69ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 1,44 : panda_link1_0,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(111ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 2,44 : panda_link1_1,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(153ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 3,44 : panda_link1_2,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(195ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 4,44 : panda_link1_3,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(234ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 5,44 : panda_link2_0,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(273ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 6,44 : panda_link2_1,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(312ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 7,44 : panda_link2_2,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(351ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 8,44 : panda_link2_3,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(378ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 17,44 : panda_link5_0,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(405ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 18,44 : panda_link5_1,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(432ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 19,44 : panda_link5_2,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(459ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 20,44 : panda_link5_3,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(486ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 21,44 : panda_link5_4,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(513ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 22,44 : panda_link5_5,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(540ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 23,44 : panda_link5_6,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(567ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 24,44 : panda_link5_7,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(594ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 25,44 : panda_link5_8,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(621ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 26,44 : panda_link5_9,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(648ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 27,44 : panda_link5_10,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd(675ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[44ll], var123[44ll], var124[44ll], var125[44ll], arg3); //collision pair: 28,44 : panda_link5_11,panda_hand_7
  var122[45ll] = ((var117[0ll] * -0.0106066018342972f) + (var117[1ll] * -0.0106066018342972f)) + (var117[2ll] * 0.136999994516373f);
  var123[45ll] = ((var117[3ll] * -0.0106066018342972f) + (var117[4ll] * -0.0106066018342972f)) + (var117[5ll] * 0.136999994516373f);
  var124[45ll] = ((var117[6ll] * -0.0106066018342972f) + (var117[7ll] * -0.0106066018342972f)) + (var117[8ll] * 0.136999994516373f);
  var122[45ll] = var122[45ll] + var120[0ll];
  var123[45ll] = var123[45ll] + var120[1ll];
  var124[45ll] = var124[45ll] + var120[2ll];
  var125[45ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd(28ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 0,45 : panda_link0_0,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(70ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 1,45 : panda_link1_0,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(112ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 2,45 : panda_link1_1,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(154ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 3,45 : panda_link1_2,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(196ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 4,45 : panda_link1_3,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(235ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 5,45 : panda_link2_0,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(274ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 6,45 : panda_link2_1,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(313ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 7,45 : panda_link2_2,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(352ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 8,45 : panda_link2_3,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(379ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 17,45 : panda_link5_0,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(406ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 18,45 : panda_link5_1,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(433ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 19,45 : panda_link5_2,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(460ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 20,45 : panda_link5_3,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(487ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 21,45 : panda_link5_4,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(514ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 22,45 : panda_link5_5,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(541ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 23,45 : panda_link5_6,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(568ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 24,45 : panda_link5_7,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(595ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 25,45 : panda_link5_8,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(622ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 26,45 : panda_link5_9,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(649ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 27,45 : panda_link5_10,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd(676ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[45ll], var123[45ll], var124[45ll], var125[45ll], arg3); //collision pair: 28,45 : panda_link5_11,panda_hand_8
  var122[46ll] = ((var117[0ll] * 0.0106066018342972f) + (var117[1ll] * 0.0106066018342972f)) + (var117[2ll] * 0.136999994516373f);
  var123[46ll] = ((var117[3ll] * 0.0106066018342972f) + (var117[4ll] * 0.0106066018342972f)) + (var117[5ll] * 0.136999994516373f);
  var124[46ll] = ((var117[6ll] * 0.0106066018342972f) + (var117[7ll] * 0.0106066018342972f)) + (var117[8ll] * 0.136999994516373f);
  var122[46ll] = var122[46ll] + var120[0ll];
  var123[46ll] = var123[46ll] + var120[1ll];
  var124[46ll] = var124[46ll] + var120[2ll];
  var125[46ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd(29ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 0,46 : panda_link0_0,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(71ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 1,46 : panda_link1_0,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(113ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 2,46 : panda_link1_1,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(155ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 3,46 : panda_link1_2,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(197ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 4,46 : panda_link1_3,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(236ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 5,46 : panda_link2_0,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(275ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 6,46 : panda_link2_1,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(314ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 7,46 : panda_link2_2,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(353ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 8,46 : panda_link2_3,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(380ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 17,46 : panda_link5_0,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(407ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 18,46 : panda_link5_1,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(434ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 19,46 : panda_link5_2,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(461ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 20,46 : panda_link5_3,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(488ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 21,46 : panda_link5_4,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(515ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 22,46 : panda_link5_5,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(542ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 23,46 : panda_link5_6,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(569ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 24,46 : panda_link5_7,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(596ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 25,46 : panda_link5_8,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(623ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 26,46 : panda_link5_9,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(650ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 27,46 : panda_link5_10,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd(677ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[46ll], var123[46ll], var124[46ll], var125[46ll], arg3); //collision pair: 28,46 : panda_link5_11,panda_hand_9
  var122[47ll] = ((var117[0ll] * 0.0318198055028915f) + (var117[1ll] * 0.0318198055028915f)) + (var117[2ll] * 0.136999994516373f);
  var123[47ll] = ((var117[3ll] * 0.0318198055028915f) + (var117[4ll] * 0.0318198055028915f)) + (var117[5ll] * 0.136999994516373f);
  var124[47ll] = ((var117[6ll] * 0.0318198055028915f) + (var117[7ll] * 0.0318198055028915f)) + (var117[8ll] * 0.136999994516373f);
  var122[47ll] = var122[47ll] + var120[0ll];
  var123[47ll] = var123[47ll] + var120[1ll];
  var124[47ll] = var124[47ll] + var120[2ll];
  var125[47ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd(30ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 0,47 : panda_link0_0,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(72ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 1,47 : panda_link1_0,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(114ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 2,47 : panda_link1_1,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(156ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 3,47 : panda_link1_2,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(198ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 4,47 : panda_link1_3,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(237ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 5,47 : panda_link2_0,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(276ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 6,47 : panda_link2_1,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(315ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 7,47 : panda_link2_2,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(354ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 8,47 : panda_link2_3,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(381ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 17,47 : panda_link5_0,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(408ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 18,47 : panda_link5_1,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(435ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 19,47 : panda_link5_2,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(462ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 20,47 : panda_link5_3,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(489ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 21,47 : panda_link5_4,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(516ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 22,47 : panda_link5_5,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(543ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 23,47 : panda_link5_6,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(570ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 24,47 : panda_link5_7,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(597ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 25,47 : panda_link5_8,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(624ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 26,47 : panda_link5_9,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(651ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 27,47 : panda_link5_10,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd(678ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[47ll], var123[47ll], var124[47ll], var125[47ll], arg3); //collision pair: 28,47 : panda_link5_11,panda_hand_10
  var122[48ll] = ((var117[0ll] * 0.0530330091714859f) + (var117[1ll] * 0.0530330091714859f)) + (var117[2ll] * 0.136999994516373f);
  var123[48ll] = ((var117[3ll] * 0.0530330091714859f) + (var117[4ll] * 0.0530330091714859f)) + (var117[5ll] * 0.136999994516373f);
  var124[48ll] = ((var117[6ll] * 0.0530330091714859f) + (var117[7ll] * 0.0530330091714859f)) + (var117[8ll] * 0.136999994516373f);
  var122[48ll] = var122[48ll] + var120[0ll];
  var123[48ll] = var123[48ll] + var120[1ll];
  var124[48ll] = var124[48ll] + var120[2ll];
  var125[48ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd(31ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 0,48 : panda_link0_0,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(73ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 1,48 : panda_link1_0,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(115ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 2,48 : panda_link1_1,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(157ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 3,48 : panda_link1_2,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(199ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 4,48 : panda_link1_3,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(238ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 5,48 : panda_link2_0,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(277ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 6,48 : panda_link2_1,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(316ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 7,48 : panda_link2_2,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(355ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 8,48 : panda_link2_3,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(382ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 17,48 : panda_link5_0,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(409ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 18,48 : panda_link5_1,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(436ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 19,48 : panda_link5_2,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(463ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 20,48 : panda_link5_3,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(490ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 21,48 : panda_link5_4,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(517ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 22,48 : panda_link5_5,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(544ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 23,48 : panda_link5_6,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(571ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 24,48 : panda_link5_7,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(598ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 25,48 : panda_link5_8,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(625ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 26,48 : panda_link5_9,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(652ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 27,48 : panda_link5_10,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd(679ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[48ll], var123[48ll], var124[48ll], var125[48ll], arg3); //collision pair: 28,48 : panda_link5_11,panda_hand_11
  var122[49ll] = ((var117[0ll] * -0.0530330091714859f) + (var117[1ll] * -0.0530330091714859f)) + (var117[2ll] * 0.157000005245209f);
  var123[49ll] = ((var117[3ll] * -0.0530330091714859f) + (var117[4ll] * -0.0530330091714859f)) + (var117[5ll] * 0.157000005245209f);
  var124[49ll] = ((var117[6ll] * -0.0530330091714859f) + (var117[7ll] * -0.0530330091714859f)) + (var117[8ll] * 0.157000005245209f);
  var122[49ll] = var122[49ll] + var120[0ll];
  var123[49ll] = var123[49ll] + var120[1ll];
  var124[49ll] = var124[49ll] + var120[2ll];
  var125[49ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd(32ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 0,49 : panda_link0_0,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(74ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 1,49 : panda_link1_0,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(116ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 2,49 : panda_link1_1,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(158ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 3,49 : panda_link1_2,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(200ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 4,49 : panda_link1_3,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(239ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 5,49 : panda_link2_0,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(278ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 6,49 : panda_link2_1,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(317ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 7,49 : panda_link2_2,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(356ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 8,49 : panda_link2_3,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(383ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 17,49 : panda_link5_0,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(410ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 18,49 : panda_link5_1,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(437ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 19,49 : panda_link5_2,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(464ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 20,49 : panda_link5_3,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(491ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 21,49 : panda_link5_4,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(518ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 22,49 : panda_link5_5,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(545ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 23,49 : panda_link5_6,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(572ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 24,49 : panda_link5_7,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(599ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 25,49 : panda_link5_8,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(626ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 26,49 : panda_link5_9,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(653ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 27,49 : panda_link5_10,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd(680ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[49ll], var123[49ll], var124[49ll], var125[49ll], arg3); //collision pair: 28,49 : panda_link5_11,panda_hand_12
  var122[50ll] = ((var117[0ll] * -0.0318198055028915f) + (var117[1ll] * -0.0318198055028915f)) + (var117[2ll] * 0.157000005245209f);
  var123[50ll] = ((var117[3ll] * -0.0318198055028915f) + (var117[4ll] * -0.0318198055028915f)) + (var117[5ll] * 0.157000005245209f);
  var124[50ll] = ((var117[6ll] * -0.0318198055028915f) + (var117[7ll] * -0.0318198055028915f)) + (var117[8ll] * 0.157000005245209f);
  var122[50ll] = var122[50ll] + var120[0ll];
  var123[50ll] = var123[50ll] + var120[1ll];
  var124[50ll] = var124[50ll] + var120[2ll];
  var125[50ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd(33ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 0,50 : panda_link0_0,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(75ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 1,50 : panda_link1_0,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(117ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 2,50 : panda_link1_1,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(159ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 3,50 : panda_link1_2,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(201ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 4,50 : panda_link1_3,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(240ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 5,50 : panda_link2_0,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(279ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 6,50 : panda_link2_1,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(318ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 7,50 : panda_link2_2,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(357ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 8,50 : panda_link2_3,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(384ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 17,50 : panda_link5_0,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(411ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 18,50 : panda_link5_1,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(438ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 19,50 : panda_link5_2,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(465ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 20,50 : panda_link5_3,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(492ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 21,50 : panda_link5_4,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(519ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 22,50 : panda_link5_5,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(546ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 23,50 : panda_link5_6,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(573ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 24,50 : panda_link5_7,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(600ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 25,50 : panda_link5_8,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(627ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 26,50 : panda_link5_9,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(654ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 27,50 : panda_link5_10,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd(681ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[50ll], var123[50ll], var124[50ll], var125[50ll], arg3); //collision pair: 28,50 : panda_link5_11,panda_hand_13
  var122[51ll] = ((var117[0ll] * -0.0106066018342972f) + (var117[1ll] * -0.0106066018342972f)) + (var117[2ll] * 0.157000005245209f);
  var123[51ll] = ((var117[3ll] * -0.0106066018342972f) + (var117[4ll] * -0.0106066018342972f)) + (var117[5ll] * 0.157000005245209f);
  var124[51ll] = ((var117[6ll] * -0.0106066018342972f) + (var117[7ll] * -0.0106066018342972f)) + (var117[8ll] * 0.157000005245209f);
  var122[51ll] = var122[51ll] + var120[0ll];
  var123[51ll] = var123[51ll] + var120[1ll];
  var124[51ll] = var124[51ll] + var120[2ll];
  var125[51ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd(34ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 0,51 : panda_link0_0,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(76ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 1,51 : panda_link1_0,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(118ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 2,51 : panda_link1_1,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(160ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 3,51 : panda_link1_2,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(202ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 4,51 : panda_link1_3,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(241ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 5,51 : panda_link2_0,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(280ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 6,51 : panda_link2_1,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(319ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 7,51 : panda_link2_2,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(358ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 8,51 : panda_link2_3,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(385ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 17,51 : panda_link5_0,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(412ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 18,51 : panda_link5_1,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(439ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 19,51 : panda_link5_2,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(466ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 20,51 : panda_link5_3,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(493ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 21,51 : panda_link5_4,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(520ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 22,51 : panda_link5_5,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(547ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 23,51 : panda_link5_6,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(574ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 24,51 : panda_link5_7,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(601ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 25,51 : panda_link5_8,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(628ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 26,51 : panda_link5_9,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(655ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 27,51 : panda_link5_10,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd(682ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[51ll], var123[51ll], var124[51ll], var125[51ll], arg3); //collision pair: 28,51 : panda_link5_11,panda_hand_14
  var122[52ll] = ((var117[0ll] * 0.0106066018342972f) + (var117[1ll] * 0.0106066018342972f)) + (var117[2ll] * 0.157000005245209f);
  var123[52ll] = ((var117[3ll] * 0.0106066018342972f) + (var117[4ll] * 0.0106066018342972f)) + (var117[5ll] * 0.157000005245209f);
  var124[52ll] = ((var117[6ll] * 0.0106066018342972f) + (var117[7ll] * 0.0106066018342972f)) + (var117[8ll] * 0.157000005245209f);
  var122[52ll] = var122[52ll] + var120[0ll];
  var123[52ll] = var123[52ll] + var120[1ll];
  var124[52ll] = var124[52ll] + var120[2ll];
  var125[52ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd(35ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 0,52 : panda_link0_0,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(77ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 1,52 : panda_link1_0,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(119ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 2,52 : panda_link1_1,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(161ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 3,52 : panda_link1_2,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(203ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 4,52 : panda_link1_3,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(242ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 5,52 : panda_link2_0,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(281ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 6,52 : panda_link2_1,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(320ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 7,52 : panda_link2_2,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(359ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 8,52 : panda_link2_3,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(386ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 17,52 : panda_link5_0,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(413ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 18,52 : panda_link5_1,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(440ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 19,52 : panda_link5_2,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(467ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 20,52 : panda_link5_3,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(494ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 21,52 : panda_link5_4,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(521ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 22,52 : panda_link5_5,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(548ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 23,52 : panda_link5_6,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(575ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 24,52 : panda_link5_7,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(602ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 25,52 : panda_link5_8,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(629ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 26,52 : panda_link5_9,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(656ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 27,52 : panda_link5_10,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd(683ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[52ll], var123[52ll], var124[52ll], var125[52ll], arg3); //collision pair: 28,52 : panda_link5_11,panda_hand_15
  var122[53ll] = ((var117[0ll] * 0.0318198055028915f) + (var117[1ll] * 0.0318198055028915f)) + (var117[2ll] * 0.157000005245209f);
  var123[53ll] = ((var117[3ll] * 0.0318198055028915f) + (var117[4ll] * 0.0318198055028915f)) + (var117[5ll] * 0.157000005245209f);
  var124[53ll] = ((var117[6ll] * 0.0318198055028915f) + (var117[7ll] * 0.0318198055028915f)) + (var117[8ll] * 0.157000005245209f);
  var122[53ll] = var122[53ll] + var120[0ll];
  var123[53ll] = var123[53ll] + var120[1ll];
  var124[53ll] = var124[53ll] + var120[2ll];
  var125[53ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd(36ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 0,53 : panda_link0_0,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(78ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 1,53 : panda_link1_0,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(120ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 2,53 : panda_link1_1,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(162ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 3,53 : panda_link1_2,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(204ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 4,53 : panda_link1_3,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(243ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 5,53 : panda_link2_0,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(282ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 6,53 : panda_link2_1,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(321ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 7,53 : panda_link2_2,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(360ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 8,53 : panda_link2_3,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(387ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 17,53 : panda_link5_0,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(414ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 18,53 : panda_link5_1,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(441ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 19,53 : panda_link5_2,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(468ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 20,53 : panda_link5_3,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(495ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 21,53 : panda_link5_4,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(522ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 22,53 : panda_link5_5,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(549ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 23,53 : panda_link5_6,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(576ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 24,53 : panda_link5_7,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(603ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 25,53 : panda_link5_8,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(630ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 26,53 : panda_link5_9,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(657ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 27,53 : panda_link5_10,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd(684ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[53ll], var123[53ll], var124[53ll], var125[53ll], arg3); //collision pair: 28,53 : panda_link5_11,panda_hand_16
  var122[54ll] = ((var117[0ll] * 0.0530330091714859f) + (var117[1ll] * 0.0530330091714859f)) + (var117[2ll] * 0.157000005245209f);
  var123[54ll] = ((var117[3ll] * 0.0530330091714859f) + (var117[4ll] * 0.0530330091714859f)) + (var117[5ll] * 0.157000005245209f);
  var124[54ll] = ((var117[6ll] * 0.0530330091714859f) + (var117[7ll] * 0.0530330091714859f)) + (var117[8ll] * 0.157000005245209f);
  var122[54ll] = var122[54ll] + var120[0ll];
  var123[54ll] = var123[54ll] + var120[1ll];
  var124[54ll] = var124[54ll] + var120[2ll];
  var125[54ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd(37ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 0,54 : panda_link0_0,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(79ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 1,54 : panda_link1_0,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(121ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 2,54 : panda_link1_1,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(163ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 3,54 : panda_link1_2,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(205ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 4,54 : panda_link1_3,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(244ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 5,54 : panda_link2_0,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(283ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 6,54 : panda_link2_1,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(322ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 7,54 : panda_link2_2,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(361ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 8,54 : panda_link2_3,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(388ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 17,54 : panda_link5_0,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(415ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 18,54 : panda_link5_1,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(442ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 19,54 : panda_link5_2,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(469ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 20,54 : panda_link5_3,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(496ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 21,54 : panda_link5_4,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(523ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 22,54 : panda_link5_5,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(550ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 23,54 : panda_link5_6,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(577ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 24,54 : panda_link5_7,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(604ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 25,54 : panda_link5_8,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(631ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 26,54 : panda_link5_9,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(658ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 27,54 : panda_link5_10,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd(685ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[54ll], var123[54ll], var124[54ll], var125[54ll], arg3); //collision pair: 28,54 : panda_link5_11,panda_hand_17
  var122[55ll] = ((var117[0ll] * 0.0565685406327248f) + (var117[1ll] * 0.0565685406327248f)) + (var117[2ll] * 0.187399998307228f);
  var123[55ll] = ((var117[3ll] * 0.0565685406327248f) + (var117[4ll] * 0.0565685406327248f)) + (var117[5ll] * 0.187399998307228f);
  var124[55ll] = ((var117[6ll] * 0.0565685406327248f) + (var117[7ll] * 0.0565685406327248f)) + (var117[8ll] * 0.187399998307228f);
  var122[55ll] = var122[55ll] + var120[0ll];
  var123[55ll] = var123[55ll] + var120[1ll];
  var124[55ll] = var124[55ll] + var120[2ll];
  var125[55ll] = 0.0120000001043081f;
  cg_sd_runtime::compute_sph_sph_cp_sd(38ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 0,55 : panda_link0_0,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(80ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 1,55 : panda_link1_0,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(122ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 2,55 : panda_link1_1,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(164ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 3,55 : panda_link1_2,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(206ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 4,55 : panda_link1_3,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(245ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 5,55 : panda_link2_0,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(284ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 6,55 : panda_link2_1,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(323ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 7,55 : panda_link2_2,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(362ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 8,55 : panda_link2_3,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(389ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 17,55 : panda_link5_0,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(416ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 18,55 : panda_link5_1,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(443ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 19,55 : panda_link5_2,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(470ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 20,55 : panda_link5_3,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(497ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 21,55 : panda_link5_4,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(524ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 22,55 : panda_link5_5,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(551ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 23,55 : panda_link5_6,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(578ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 24,55 : panda_link5_7,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(605ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 25,55 : panda_link5_8,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(632ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 26,55 : panda_link5_9,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(659ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 27,55 : panda_link5_10,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(686ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[55ll], var123[55ll], var124[55ll], var125[55ll], arg3); //collision pair: 28,55 : panda_link5_11,panda_leftfinger_0
  var122[56ll] = ((var117[0ll] * 0.0516187958419323f) + (var117[1ll] * 0.0516187958419323f)) + (var117[2ll] * 0.209399998188019f);
  var123[56ll] = ((var117[3ll] * 0.0516187958419323f) + (var117[4ll] * 0.0516187958419323f)) + (var117[5ll] * 0.209399998188019f);
  var124[56ll] = ((var117[6ll] * 0.0516187958419323f) + (var117[7ll] * 0.0516187958419323f)) + (var117[8ll] * 0.209399998188019f);
  var122[56ll] = var122[56ll] + var120[0ll];
  var123[56ll] = var123[56ll] + var120[1ll];
  var124[56ll] = var124[56ll] + var120[2ll];
  var125[56ll] = 0.0120000001043081f;
  cg_sd_runtime::compute_sph_sph_cp_sd(39ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 0,56 : panda_link0_0,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(81ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 1,56 : panda_link1_0,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(123ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 2,56 : panda_link1_1,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(165ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 3,56 : panda_link1_2,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(207ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 4,56 : panda_link1_3,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(246ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 5,56 : panda_link2_0,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(285ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 6,56 : panda_link2_1,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(324ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 7,56 : panda_link2_2,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(363ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 8,56 : panda_link2_3,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(390ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 17,56 : panda_link5_0,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(417ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 18,56 : panda_link5_1,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(444ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 19,56 : panda_link5_2,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(471ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 20,56 : panda_link5_3,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(498ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 21,56 : panda_link5_4,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(525ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 22,56 : panda_link5_5,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(552ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 23,56 : panda_link5_6,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(579ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 24,56 : panda_link5_7,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(606ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 25,56 : panda_link5_8,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(633ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 26,56 : panda_link5_9,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(660ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 27,56 : panda_link5_10,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(687ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[56ll], var123[56ll], var124[56ll], var125[56ll], arg3); //collision pair: 28,56 : panda_link5_11,panda_leftfinger_1
  var122[57ll] = ((var117[0ll] * -0.0565685406327248f) + (var117[1ll] * -0.0565685406327248f)) + (var117[2ll] * 0.187399998307228f);
  var123[57ll] = ((var117[3ll] * -0.0565685406327248f) + (var117[4ll] * -0.0565685406327248f)) + (var117[5ll] * 0.187399998307228f);
  var124[57ll] = ((var117[6ll] * -0.0565685406327248f) + (var117[7ll] * -0.0565685406327248f)) + (var117[8ll] * 0.187399998307228f);
  var122[57ll] = var122[57ll] + var120[0ll];
  var123[57ll] = var123[57ll] + var120[1ll];
  var124[57ll] = var124[57ll] + var120[2ll];
  var125[57ll] = 0.0120000001043081f;
  cg_sd_runtime::compute_sph_sph_cp_sd(40ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 0,57 : panda_link0_0,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(82ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 1,57 : panda_link1_0,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(124ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 2,57 : panda_link1_1,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(166ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 3,57 : panda_link1_2,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(208ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 4,57 : panda_link1_3,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(247ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 5,57 : panda_link2_0,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(286ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 6,57 : panda_link2_1,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(325ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 7,57 : panda_link2_2,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(364ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 8,57 : panda_link2_3,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(391ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 17,57 : panda_link5_0,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(418ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 18,57 : panda_link5_1,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(445ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 19,57 : panda_link5_2,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(472ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 20,57 : panda_link5_3,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(499ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 21,57 : panda_link5_4,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(526ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 22,57 : panda_link5_5,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(553ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 23,57 : panda_link5_6,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(580ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 24,57 : panda_link5_7,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(607ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 25,57 : panda_link5_8,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(634ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 26,57 : panda_link5_9,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(661ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 27,57 : panda_link5_10,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd(688ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[57ll], var123[57ll], var124[57ll], var125[57ll], arg3); //collision pair: 28,57 : panda_link5_11,panda_rightfinger_0
  var122[58ll] = ((var117[0ll] * -0.0516187958419323f) + (var117[1ll] * -0.0516187958419323f)) + (var117[2ll] * 0.209399998188019f);
  var123[58ll] = ((var117[3ll] * -0.0516187958419323f) + (var117[4ll] * -0.0516187958419323f)) + (var117[5ll] * 0.209399998188019f);
  var124[58ll] = ((var117[6ll] * -0.0516187958419323f) + (var117[7ll] * -0.0516187958419323f)) + (var117[8ll] * 0.209399998188019f);
  var122[58ll] = var122[58ll] + var120[0ll];
  var123[58ll] = var123[58ll] + var120[1ll];
  var124[58ll] = var124[58ll] + var120[2ll];
  var125[58ll] = 0.0120000001043081f;
  cg_sd_runtime::compute_sph_sph_cp_sd(41ll, var122[0ll], var123[0ll], var124[0ll], var125[0ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 0,58 : panda_link0_0,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(83ll, var122[1ll], var123[1ll], var124[1ll], var125[1ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 1,58 : panda_link1_0,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(125ll, var122[2ll], var123[2ll], var124[2ll], var125[2ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 2,58 : panda_link1_1,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(167ll, var122[3ll], var123[3ll], var124[3ll], var125[3ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 3,58 : panda_link1_2,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(209ll, var122[4ll], var123[4ll], var124[4ll], var125[4ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 4,58 : panda_link1_3,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(248ll, var122[5ll], var123[5ll], var124[5ll], var125[5ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 5,58 : panda_link2_0,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(287ll, var122[6ll], var123[6ll], var124[6ll], var125[6ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 6,58 : panda_link2_1,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(326ll, var122[7ll], var123[7ll], var124[7ll], var125[7ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 7,58 : panda_link2_2,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(365ll, var122[8ll], var123[8ll], var124[8ll], var125[8ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 8,58 : panda_link2_3,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(392ll, var122[17ll], var123[17ll], var124[17ll], var125[17ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 17,58 : panda_link5_0,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(419ll, var122[18ll], var123[18ll], var124[18ll], var125[18ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 18,58 : panda_link5_1,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(446ll, var122[19ll], var123[19ll], var124[19ll], var125[19ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 19,58 : panda_link5_2,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(473ll, var122[20ll], var123[20ll], var124[20ll], var125[20ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 20,58 : panda_link5_3,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(500ll, var122[21ll], var123[21ll], var124[21ll], var125[21ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 21,58 : panda_link5_4,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(527ll, var122[22ll], var123[22ll], var124[22ll], var125[22ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 22,58 : panda_link5_5,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(554ll, var122[23ll], var123[23ll], var124[23ll], var125[23ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 23,58 : panda_link5_6,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(581ll, var122[24ll], var123[24ll], var124[24ll], var125[24ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 24,58 : panda_link5_7,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(608ll, var122[25ll], var123[25ll], var124[25ll], var125[25ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 25,58 : panda_link5_8,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(635ll, var122[26ll], var123[26ll], var124[26ll], var125[26ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 26,58 : panda_link5_9,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(662ll, var122[27ll], var123[27ll], var124[27ll], var125[27ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 27,58 : panda_link5_10,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd(689ll, var122[28ll], var123[28ll], var124[28ll], var125[28ll], var122[58ll], var123[58ll], var124[58ll], var125[58ll], arg3); //collision pair: 28,58 : panda_link5_11,panda_rightfinger_1
}

}
