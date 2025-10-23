// clang-format off

#include "Eigen/Dense"

#include "ctup/typedefs.h"

#include "rla_grad_self_collision/runtime/utils.h"

#include <iostream>

namespace cg_sd_gen_panda_spherized {

static void print_string(const char* str) {
  std::cout << str << "\n";
}

template<typename MT>
static void print_matrix(const blaze::DenseMatrix<MT, blaze::rowMajor>& matrix) {
  std::cout << matrix << "\n";
}

template<typename Derived>
static void print_matrix(const Eigen::MatrixBase<Derived>& matrix) {
  std::cout << matrix << "\n";
}

static void self_collision_signed_distances_and_jacobians (cg_sd_runtime::ConfigurationBlockRobot<cg_sd_runtime::robots::Panda> const& arg2, Eigen::MatrixXd& arg3, Eigen::MatrixXd& arg4) {
  blaze::StaticVector<float, 8> var48[9];
  blaze::StaticVector<float, 8> var49;
  blaze::StaticVector<float, 8> var50;
  blaze::StaticVector<float, 8> var53[9];
  blaze::StaticVector<float, 8> var54;
  blaze::StaticVector<float, 8> var55;
  blaze::StaticVector<float, 8> var58[9];
  blaze::StaticVector<float, 8> var59;
  blaze::StaticVector<float, 8> var60;
  blaze::StaticVector<float, 8> var63[9];
  blaze::StaticVector<float, 8> var64;
  blaze::StaticVector<float, 8> var65;
  blaze::StaticVector<float, 8> var68[9];
  blaze::StaticVector<float, 8> var69;
  blaze::StaticVector<float, 8> var70;
  blaze::StaticVector<float, 8> var73[9];
  blaze::StaticVector<float, 8> var74;
  blaze::StaticVector<float, 8> var75;
  blaze::StaticVector<float, 8> var78[9];
  blaze::StaticVector<float, 8> var79;
  blaze::StaticVector<float, 8> var80;
  blaze::StaticVector<float, 8> var88[9];
  blaze::StaticVector<float, 8> var92;
  blaze::StaticVector<float, 8> var93[9];
  blaze::StaticVector<float, 8> var96[3];
  blaze::StaticVector<float, 8> var97;
  blaze::StaticVector<float, 8> var98[9];
  blaze::StaticVector<float, 8> var101[3];
  blaze::StaticVector<float, 8> var102;
  blaze::StaticVector<float, 8> var103[9];
  blaze::StaticVector<float, 8> var106[3];
  blaze::StaticVector<float, 8> var107;
  blaze::StaticVector<float, 8> var108[9];
  blaze::StaticVector<float, 8> var111[3];
  blaze::StaticVector<float, 8> var112;
  blaze::StaticVector<float, 8> var113[9];
  blaze::StaticVector<float, 8> var116[3];
  blaze::StaticVector<float, 8> var117;
  blaze::StaticVector<float, 8> var118[9];
  blaze::StaticVector<float, 8> var121[3];
  blaze::StaticVector<float, 8> var122;
  blaze::StaticVector<float, 8> var131[9];
  blaze::StaticVector<float, 8> var134[9];
  blaze::StaticVector<float, 8> var135[9];
  blaze::StaticVector<float, 8> var136[6];
  blaze::StaticMatrix<blaze::StaticVector<float, 8>, 6, 7> var137;
  blaze::StaticMatrix<blaze::StaticVector<float, 8>, 6, 7> var138;
  blaze::StaticMatrix<blaze::StaticVector<float, 8>, 6, 7> var139;
  blaze::StaticMatrix<blaze::StaticVector<float, 8>, 6, 7> var140;
  blaze::StaticMatrix<blaze::StaticVector<float, 8>, 6, 7> var141;
  blaze::StaticMatrix<blaze::StaticVector<float, 8>, 6, 7> var142;
  blaze::StaticMatrix<blaze::StaticVector<float, 8>, 6, 7> var143;
  blaze::StaticMatrix<blaze::StaticVector<float, 8>, 6, 7> var144;
  std::array<blaze::StaticVector<float, 8>, 59> var145;
  std::array<blaze::StaticVector<float, 8>, 59> var146;
  std::array<blaze::StaticVector<float, 8>, 59> var147;
  std::array<float, 59> var148;
  blaze::StaticVector<float, 8> var149[9];
  blaze::StaticVector<float, 8> var153;
  var145[0ll] = ((1.0f * 0.0f) + (0 * 0.0f)) + (0 * 0.0500000007450581f);
  var146[0ll] = ((0 * 0.0f) + (1.0f * 0.0f)) + (0 * 0.0500000007450581f);
  var147[0ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.0500000007450581f);
  var145[0ll] = var145[0ll] + 0;
  var146[0ll] = var146[0ll] + 0;
  var147[0ll] = var147[0ll] + 0;
  var148[0ll] = 0.0799999982118607f;
  blaze::StaticVector<float, 8> var154 = arg2[0ll];
  var49 = sin(var154);
  var50 = cos(var154);
  var48[0ll] = var50;
  var48[1ll] = -(var49);
  var48[2ll] = var49;
  var48[3ll] = var50;
  blaze::StaticVector<float, 8> var155;
  var155 = 0;
  var155 = var155 + (1.0f * var48[0ll]);
  var149[0ll] = var155;
  blaze::StaticVector<float, 8> var156;
  var156 = 0;
  var156 = var156 + (1.0f * var48[1ll]);
  var149[1ll] = var156;
  blaze::StaticVector<float, 8> var157;
  var157 = 0;
  var157 = var157 + (1.0f * var48[2ll]);
  var149[2ll] = var157;
  blaze::StaticVector<float, 8> var158;
  var158 = 0;
  var158 = var158 + (1.0f * var48[3ll]);
  var149[3ll] = var158;
  blaze::StaticVector<float, 8> var159;
  var159 = 0;
  var159 = var159 + (1.0f * 1.0f);
  var153 = var159;
  var88[0ll] = var149[0ll];
  var88[1ll] = var149[1ll];
  var88[2ll] = var149[2ll];
  var88[3ll] = var149[3ll];
  var92 = var153;
  var131[0ll] = var88[0ll];
  var131[1ll] = var88[1ll];
  var131[2ll] = var88[2ll];
  var131[3ll] = var88[3ll];
  blaze::StaticVector<float, 8> var160;
  var160 = 0;
  var160 = var160 + (-0.333000004291534f * var131[2ll]);
  var135[0ll] = var160;
  blaze::StaticVector<float, 8> var161;
  var161 = 0;
  var161 = var161 + (-0.333000004291534f * var131[3ll]);
  var135[1ll] = var161;
  blaze::StaticVector<float, 8> var162;
  var162 = 0;
  var162 = var162 + (0.333000004291534f * var131[0ll]);
  var135[2ll] = var162;
  blaze::StaticVector<float, 8> var163;
  var163 = 0;
  var163 = var163 + (0.333000004291534f * var131[1ll]);
  var135[3ll] = var163;
  blaze::StaticVector<float, 8> var164;
  var164 = 0;
  var136[0ll] = var164;
  blaze::StaticVector<float, 8> var165;
  var165 = 0;
  var136[1ll] = var165;
  blaze::StaticVector<float, 8> var166;
  var166 = 0;
  var166 = var166 + (1.0f * 1.0f);
  var136[2ll] = var166;
  blaze::StaticVector<float, 8> var167;
  var167 = 0;
  var136[3ll] = var167;
  blaze::StaticVector<float, 8> var168;
  var168 = 0;
  var136[4ll] = var168;
  blaze::StaticVector<float, 8> var169;
  var169 = 0;
  var136[5ll] = var169;
  var138(0ll, 0ll) = var136[0ll];
  var138(1ll, 0ll) = var136[1ll];
  var138(2ll, 0ll) = var136[2ll];
  var138(3ll, 0ll) = var136[3ll];
  var138(4ll, 0ll) = var136[4ll];
  var138(5ll, 0ll) = var136[5ll];
  var145[1ll] = ((var88[0ll] * 0.0f) + (var88[1ll] * -0.0799999982118607f)) + (0 * 0.0f);
  var146[1ll] = ((var88[2ll] * 0.0f) + (var88[3ll] * -0.0799999982118607f)) + (0 * 0.0f);
  var147[1ll] = ((0 * 0.0f) + (0 * -0.0799999982118607f)) + (1.0f * 0.0f);
  var145[1ll] = var145[1ll] + 0;
  var146[1ll] = var146[1ll] + 0;
  var147[1ll] = var147[1ll] + 0.333000004291534f;
  var148[1ll] = 0.0599999986588955f;
  var145[2ll] = ((var88[0ll] * 0.0f) + (var88[1ll] * -0.0299999993294477f)) + (0 * 0.0f);
  var146[2ll] = ((var88[2ll] * 0.0f) + (var88[3ll] * -0.0299999993294477f)) + (0 * 0.0f);
  var147[2ll] = ((0 * 0.0f) + (0 * -0.0299999993294477f)) + (1.0f * 0.0f);
  var145[2ll] = var145[2ll] + 0;
  var146[2ll] = var146[2ll] + 0;
  var147[2ll] = var147[2ll] + 0.333000004291534f;
  var148[2ll] = 0.0599999986588955f;
  var145[3ll] = ((var88[0ll] * 0.0f) + (var88[1ll] * 0.0f)) + (0 * -0.119999997317791f);
  var146[3ll] = ((var88[2ll] * 0.0f) + (var88[3ll] * 0.0f)) + (0 * -0.119999997317791f);
  var147[3ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * -0.119999997317791f);
  var145[3ll] = var145[3ll] + 0;
  var146[3ll] = var146[3ll] + 0;
  var147[3ll] = var147[3ll] + 0.333000004291534f;
  var148[3ll] = 0.0599999986588955f;
  var145[4ll] = ((var88[0ll] * 0.0f) + (var88[1ll] * 0.0f)) + (0 * -0.170000001788139f);
  var146[4ll] = ((var88[2ll] * 0.0f) + (var88[3ll] * 0.0f)) + (0 * -0.170000001788139f);
  var147[4ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * -0.170000001788139f);
  var145[4ll] = var145[4ll] + 0;
  var146[4ll] = var146[4ll] + 0;
  var147[4ll] = var147[4ll] + 0.333000004291534f;
  var148[4ll] = 0.0599999986588955f;
  blaze::StaticVector<float, 8> var170 = arg2[1ll];
  var54 = sin(var170);
  var55 = cos(var170);
  var53[0ll] = var55;
  var53[1ll] = -(var54);
  var53[2ll] = var54;
  var53[3ll] = var55;
  blaze::StaticVector<float, 8> var171;
  var171 = 0;
  var171 = var171 + (1.0f * var53[0ll]);
  var149[0ll] = var171;
  blaze::StaticVector<float, 8> var172;
  var172 = 0;
  var172 = var172 + (1.0f * var53[1ll]);
  var149[1ll] = var172;
  blaze::StaticVector<float, 8> var173;
  var173 = 0;
  var173 = var173 + (-1.0f * var53[2ll]);
  var149[2ll] = var173;
  blaze::StaticVector<float, 8> var174;
  var174 = 0;
  var174 = var174 + (-1.0f * var53[3ll]);
  var149[3ll] = var174;
  blaze::StaticVector<float, 8> var175;
  var175 = 0;
  var175 = var175 + (1.0f * 1.0f);
  var153 = var175;
  blaze::StaticVector<float, 8> var176;
  var176 = 0;
  var176 = var176 + (var88[0ll] * var149[0ll]);
  var93[0ll] = var176;
  blaze::StaticVector<float, 8> var177;
  var177 = 0;
  var177 = var177 + (var88[0ll] * var149[1ll]);
  var93[1ll] = var177;
  blaze::StaticVector<float, 8> var178;
  var178 = 0;
  var178 = var178 + (var88[1ll] * 1.0f);
  var93[2ll] = var178;
  blaze::StaticVector<float, 8> var179;
  var179 = 0;
  var179 = var179 + (var88[2ll] * var149[0ll]);
  var93[3ll] = var179;
  blaze::StaticVector<float, 8> var180;
  var180 = 0;
  var180 = var180 + (var88[2ll] * var149[1ll]);
  var93[4ll] = var180;
  blaze::StaticVector<float, 8> var181;
  var181 = 0;
  var181 = var181 + (var88[3ll] * 1.0f);
  var93[5ll] = var181;
  blaze::StaticVector<float, 8> var182;
  var182 = 0;
  var182 = var182 + (1.0f * var149[2ll]);
  var93[6ll] = var182;
  blaze::StaticVector<float, 8> var183;
  var183 = 0;
  var183 = var183 + (1.0f * var149[3ll]);
  var93[7ll] = var183;
  blaze::StaticVector<float, 8> var184;
  var184 = 0;
  var184 = var184 + (0.333000004291534f * var153);
  var96[0ll] = var184;
  blaze::StaticVector<float, 8> var185;
  var185 = 0;
  var185 = var185 + (var92 * var153);
  var97 = var185;
  var131[0ll] = var88[0ll];
  var131[1ll] = var88[1ll];
  var131[2ll] = var88[2ll];
  var131[3ll] = var88[3ll];
  blaze::StaticVector<float, 8> var186;
  var186 = 0;
  var186 = var186 + (-0.333000004291534f * var131[2ll]);
  var135[0ll] = var186;
  blaze::StaticVector<float, 8> var187;
  var187 = 0;
  var187 = var187 + (-0.333000004291534f * var131[3ll]);
  var135[1ll] = var187;
  blaze::StaticVector<float, 8> var188;
  var188 = 0;
  var188 = var188 + (0.333000004291534f * var131[0ll]);
  var135[2ll] = var188;
  blaze::StaticVector<float, 8> var189;
  var189 = 0;
  var189 = var189 + (0.333000004291534f * var131[1ll]);
  var135[3ll] = var189;
  blaze::StaticVector<float, 8> var190;
  var190 = 0;
  var136[0ll] = var190;
  blaze::StaticVector<float, 8> var191;
  var191 = 0;
  var136[1ll] = var191;
  blaze::StaticVector<float, 8> var192;
  var192 = 0;
  var192 = var192 + (1.0f * 1.0f);
  var136[2ll] = var192;
  blaze::StaticVector<float, 8> var193;
  var193 = 0;
  var136[3ll] = var193;
  blaze::StaticVector<float, 8> var194;
  var194 = 0;
  var136[4ll] = var194;
  blaze::StaticVector<float, 8> var195;
  var195 = 0;
  var136[5ll] = var195;
  var139(0ll, 0ll) = var136[0ll];
  var139(1ll, 0ll) = var136[1ll];
  var139(2ll, 0ll) = var136[2ll];
  var139(3ll, 0ll) = var136[3ll];
  var139(4ll, 0ll) = var136[4ll];
  var139(5ll, 0ll) = var136[5ll];
  var131[0ll] = var93[0ll];
  var131[1ll] = var93[1ll];
  var131[4ll] = var93[2ll];
  var131[2ll] = var93[3ll];
  var131[3ll] = var93[4ll];
  var131[5ll] = var93[5ll];
  var131[6ll] = var93[6ll];
  var131[7ll] = var93[7ll];
  var134[0ll] = -(var96[0ll]);
  var134[1ll] = var96[0ll];
  blaze::StaticVector<float, 8> var196;
  var196 = 0;
  var196 = var196 + (var134[0ll] * var131[2ll]);
  var135[0ll] = var196;
  blaze::StaticVector<float, 8> var197;
  var197 = 0;
  var197 = var197 + (var134[0ll] * var131[3ll]);
  var135[1ll] = var197;
  blaze::StaticVector<float, 8> var198;
  var198 = 0;
  var198 = var198 + (var134[0ll] * var131[5ll]);
  var135[4ll] = var198;
  blaze::StaticVector<float, 8> var199;
  var199 = 0;
  var199 = var199 + (var134[1ll] * var131[0ll]);
  var135[2ll] = var199;
  blaze::StaticVector<float, 8> var200;
  var200 = 0;
  var200 = var200 + (var134[1ll] * var131[1ll]);
  var135[3ll] = var200;
  blaze::StaticVector<float, 8> var201;
  var201 = 0;
  var201 = var201 + (var134[1ll] * var131[4ll]);
  var135[5ll] = var201;
  blaze::StaticVector<float, 8> var202;
  var202 = 0;
  var202 = var202 + (var131[4ll] * 1.0f);
  var136[0ll] = var202;
  blaze::StaticVector<float, 8> var203;
  var203 = 0;
  var203 = var203 + (var131[5ll] * 1.0f);
  var136[1ll] = var203;
  blaze::StaticVector<float, 8> var204;
  var204 = 0;
  var136[2ll] = var204;
  blaze::StaticVector<float, 8> var205;
  var205 = 0;
  var205 = var205 + (var135[4ll] * 1.0f);
  var136[3ll] = var205;
  blaze::StaticVector<float, 8> var206;
  var206 = 0;
  var206 = var206 + (var135[5ll] * 1.0f);
  var136[4ll] = var206;
  blaze::StaticVector<float, 8> var207;
  var207 = 0;
  var136[5ll] = var207;
  var139(0ll, 1ll) = var136[0ll];
  var139(1ll, 1ll) = var136[1ll];
  var139(2ll, 1ll) = var136[2ll];
  var139(3ll, 1ll) = var136[3ll];
  var139(4ll, 1ll) = var136[4ll];
  var139(5ll, 1ll) = var136[5ll];
  var145[5ll] = ((var93[0ll] * 0.0f) + (var93[1ll] * 0.0f)) + (var93[2ll] * 0.0299999993294477f);
  var146[5ll] = ((var93[3ll] * 0.0f) + (var93[4ll] * 0.0f)) + (var93[5ll] * 0.0299999993294477f);
  var147[5ll] = ((var93[6ll] * 0.0f) + (var93[7ll] * 0.0f)) + (0 * 0.0299999993294477f);
  var145[5ll] = var145[5ll] + 0;
  var146[5ll] = var146[5ll] + 0;
  var147[5ll] = var147[5ll] + var96[0ll];
  var148[5ll] = 0.0599999986588955f;
  var145[6ll] = ((var93[0ll] * 0.0f) + (var93[1ll] * 0.0f)) + (var93[2ll] * 0.0799999982118607f);
  var146[6ll] = ((var93[3ll] * 0.0f) + (var93[4ll] * 0.0f)) + (var93[5ll] * 0.0799999982118607f);
  var147[6ll] = ((var93[6ll] * 0.0f) + (var93[7ll] * 0.0f)) + (0 * 0.0799999982118607f);
  var145[6ll] = var145[6ll] + 0;
  var146[6ll] = var146[6ll] + 0;
  var147[6ll] = var147[6ll] + var96[0ll];
  var148[6ll] = 0.0599999986588955f;
  var145[7ll] = ((var93[0ll] * 0.0f) + (var93[1ll] * -0.119999997317791f)) + (var93[2ll] * 0.0f);
  var146[7ll] = ((var93[3ll] * 0.0f) + (var93[4ll] * -0.119999997317791f)) + (var93[5ll] * 0.0f);
  var147[7ll] = ((var93[6ll] * 0.0f) + (var93[7ll] * -0.119999997317791f)) + (0 * 0.0f);
  var145[7ll] = var145[7ll] + 0;
  var146[7ll] = var146[7ll] + 0;
  var147[7ll] = var147[7ll] + var96[0ll];
  var148[7ll] = 0.0599999986588955f;
  var145[8ll] = ((var93[0ll] * 0.0f) + (var93[1ll] * -0.170000001788139f)) + (var93[2ll] * 0.0f);
  var146[8ll] = ((var93[3ll] * 0.0f) + (var93[4ll] * -0.170000001788139f)) + (var93[5ll] * 0.0f);
  var147[8ll] = ((var93[6ll] * 0.0f) + (var93[7ll] * -0.170000001788139f)) + (0 * 0.0f);
  var145[8ll] = var145[8ll] + 0;
  var146[8ll] = var146[8ll] + 0;
  var147[8ll] = var147[8ll] + var96[0ll];
  var148[8ll] = 0.0599999986588955f;
  blaze::StaticVector<float, 8> var208 = arg2[2ll];
  var59 = sin(var208);
  var60 = cos(var208);
  var58[0ll] = var60;
  var58[1ll] = -(var59);
  var58[2ll] = var59;
  var58[3ll] = var60;
  blaze::StaticVector<float, 8> var209;
  var209 = 0;
  var209 = var209 + (1.0f * var58[0ll]);
  var149[0ll] = var209;
  blaze::StaticVector<float, 8> var210;
  var210 = 0;
  var210 = var210 + (1.0f * var58[1ll]);
  var149[1ll] = var210;
  blaze::StaticVector<float, 8> var211;
  var211 = 0;
  var211 = var211 + (1.0f * var58[2ll]);
  var149[2ll] = var211;
  blaze::StaticVector<float, 8> var212;
  var212 = 0;
  var212 = var212 + (1.0f * var58[3ll]);
  var149[3ll] = var212;
  blaze::StaticVector<float, 8> var213;
  var213 = 0;
  var213 = var213 + (1.0f * 1.0f);
  var153 = var213;
  blaze::StaticVector<float, 8> var214;
  var214 = 0;
  var214 = var214 + (var93[0ll] * var149[0ll]);
  var214 = var214 + (var93[2ll] * var149[2ll]);
  var98[0ll] = var214;
  blaze::StaticVector<float, 8> var215;
  var215 = 0;
  var215 = var215 + (var93[0ll] * var149[1ll]);
  var215 = var215 + (var93[2ll] * var149[3ll]);
  var98[1ll] = var215;
  blaze::StaticVector<float, 8> var216;
  var216 = 0;
  var216 = var216 + (var93[1ll] * -1.0f);
  var98[2ll] = var216;
  blaze::StaticVector<float, 8> var217;
  var217 = 0;
  var217 = var217 + (var93[3ll] * var149[0ll]);
  var217 = var217 + (var93[5ll] * var149[2ll]);
  var98[3ll] = var217;
  blaze::StaticVector<float, 8> var218;
  var218 = 0;
  var218 = var218 + (var93[3ll] * var149[1ll]);
  var218 = var218 + (var93[5ll] * var149[3ll]);
  var98[4ll] = var218;
  blaze::StaticVector<float, 8> var219;
  var219 = 0;
  var219 = var219 + (var93[4ll] * -1.0f);
  var98[5ll] = var219;
  blaze::StaticVector<float, 8> var220;
  var220 = 0;
  var220 = var220 + (var93[6ll] * var149[0ll]);
  var98[6ll] = var220;
  blaze::StaticVector<float, 8> var221;
  var221 = 0;
  var221 = var221 + (var93[6ll] * var149[1ll]);
  var98[7ll] = var221;
  blaze::StaticVector<float, 8> var222;
  var222 = 0;
  var222 = var222 + (var93[7ll] * -1.0f);
  var98[8ll] = var222;
  blaze::StaticVector<float, 8> var223;
  var223 = 0;
  blaze::StaticVector<float, 8> var224;
  var224 = 0;
  var224 = var224 + (var93[1ll] * -0.316000014543533f);
  var101[0ll] = var224 + var223;
  blaze::StaticVector<float, 8> var225;
  var225 = 0;
  blaze::StaticVector<float, 8> var226;
  var226 = 0;
  var226 = var226 + (var93[4ll] * -0.316000014543533f);
  var101[1ll] = var226 + var225;
  blaze::StaticVector<float, 8> var227;
  var227 = 0;
  var227 = var227 + (var96[0ll] * var153);
  blaze::StaticVector<float, 8> var228;
  var228 = 0;
  var228 = var228 + (var93[7ll] * -0.316000014543533f);
  var101[2ll] = var228 + var227;
  blaze::StaticVector<float, 8> var229;
  var229 = 0;
  var229 = var229 + (var97 * var153);
  var102 = var229;
  var131[0ll] = var88[0ll];
  var131[1ll] = var88[1ll];
  var131[2ll] = var88[2ll];
  var131[3ll] = var88[3ll];
  blaze::StaticVector<float, 8> var230;
  var230 = 0;
  var230 = var230 + (-0.333000004291534f * var131[2ll]);
  var135[0ll] = var230;
  blaze::StaticVector<float, 8> var231;
  var231 = 0;
  var231 = var231 + (-0.333000004291534f * var131[3ll]);
  var135[1ll] = var231;
  blaze::StaticVector<float, 8> var232;
  var232 = 0;
  var232 = var232 + (0.333000004291534f * var131[0ll]);
  var135[2ll] = var232;
  blaze::StaticVector<float, 8> var233;
  var233 = 0;
  var233 = var233 + (0.333000004291534f * var131[1ll]);
  var135[3ll] = var233;
  blaze::StaticVector<float, 8> var234;
  var234 = 0;
  var136[0ll] = var234;
  blaze::StaticVector<float, 8> var235;
  var235 = 0;
  var136[1ll] = var235;
  blaze::StaticVector<float, 8> var236;
  var236 = 0;
  var236 = var236 + (1.0f * 1.0f);
  var136[2ll] = var236;
  blaze::StaticVector<float, 8> var237;
  var237 = 0;
  var136[3ll] = var237;
  blaze::StaticVector<float, 8> var238;
  var238 = 0;
  var136[4ll] = var238;
  blaze::StaticVector<float, 8> var239;
  var239 = 0;
  var136[5ll] = var239;
  var140(0ll, 0ll) = var136[0ll];
  var140(1ll, 0ll) = var136[1ll];
  var140(2ll, 0ll) = var136[2ll];
  var140(3ll, 0ll) = var136[3ll];
  var140(4ll, 0ll) = var136[4ll];
  var140(5ll, 0ll) = var136[5ll];
  var131[0ll] = var93[0ll];
  var131[1ll] = var93[1ll];
  var131[4ll] = var93[2ll];
  var131[2ll] = var93[3ll];
  var131[3ll] = var93[4ll];
  var131[5ll] = var93[5ll];
  var131[6ll] = var93[6ll];
  var131[7ll] = var93[7ll];
  var134[0ll] = -(var96[0ll]);
  var134[1ll] = var96[0ll];
  blaze::StaticVector<float, 8> var240;
  var240 = 0;
  var240 = var240 + (var134[0ll] * var131[2ll]);
  var135[0ll] = var240;
  blaze::StaticVector<float, 8> var241;
  var241 = 0;
  var241 = var241 + (var134[0ll] * var131[3ll]);
  var135[1ll] = var241;
  blaze::StaticVector<float, 8> var242;
  var242 = 0;
  var242 = var242 + (var134[0ll] * var131[5ll]);
  var135[4ll] = var242;
  blaze::StaticVector<float, 8> var243;
  var243 = 0;
  var243 = var243 + (var134[1ll] * var131[0ll]);
  var135[2ll] = var243;
  blaze::StaticVector<float, 8> var244;
  var244 = 0;
  var244 = var244 + (var134[1ll] * var131[1ll]);
  var135[3ll] = var244;
  blaze::StaticVector<float, 8> var245;
  var245 = 0;
  var245 = var245 + (var134[1ll] * var131[4ll]);
  var135[5ll] = var245;
  blaze::StaticVector<float, 8> var246;
  var246 = 0;
  var246 = var246 + (var131[4ll] * 1.0f);
  var136[0ll] = var246;
  blaze::StaticVector<float, 8> var247;
  var247 = 0;
  var247 = var247 + (var131[5ll] * 1.0f);
  var136[1ll] = var247;
  blaze::StaticVector<float, 8> var248;
  var248 = 0;
  var136[2ll] = var248;
  blaze::StaticVector<float, 8> var249;
  var249 = 0;
  var249 = var249 + (var135[4ll] * 1.0f);
  var136[3ll] = var249;
  blaze::StaticVector<float, 8> var250;
  var250 = 0;
  var250 = var250 + (var135[5ll] * 1.0f);
  var136[4ll] = var250;
  blaze::StaticVector<float, 8> var251;
  var251 = 0;
  var136[5ll] = var251;
  var140(0ll, 1ll) = var136[0ll];
  var140(1ll, 1ll) = var136[1ll];
  var140(2ll, 1ll) = var136[2ll];
  var140(3ll, 1ll) = var136[3ll];
  var140(4ll, 1ll) = var136[4ll];
  var140(5ll, 1ll) = var136[5ll];
  var131[0ll] = var98[0ll];
  var131[1ll] = var98[1ll];
  var131[4ll] = var98[2ll];
  var131[2ll] = var98[3ll];
  var131[3ll] = var98[4ll];
  var131[5ll] = var98[5ll];
  var131[6ll] = var98[6ll];
  var131[7ll] = var98[7ll];
  var131[8ll] = var98[8ll];
  var134[2ll] = -(var101[0ll]);
  var134[3ll] = var101[0ll];
  var134[4ll] = -(var101[1ll]);
  var134[5ll] = var101[1ll];
  var134[0ll] = -(var101[2ll]);
  var134[1ll] = var101[2ll];
  blaze::StaticVector<float, 8> var252;
  var252 = 0;
  var252 = var252 + (var134[0ll] * var131[2ll]);
  var252 = var252 + (var134[5ll] * var131[6ll]);
  var135[0ll] = var252;
  blaze::StaticVector<float, 8> var253;
  var253 = 0;
  var253 = var253 + (var134[0ll] * var131[3ll]);
  var253 = var253 + (var134[5ll] * var131[7ll]);
  var135[1ll] = var253;
  blaze::StaticVector<float, 8> var254;
  var254 = 0;
  var254 = var254 + (var134[0ll] * var131[5ll]);
  var254 = var254 + (var134[5ll] * var131[8ll]);
  var135[4ll] = var254;
  blaze::StaticVector<float, 8> var255;
  var255 = 0;
  var255 = var255 + (var134[1ll] * var131[0ll]);
  var255 = var255 + (var134[2ll] * var131[6ll]);
  var135[2ll] = var255;
  blaze::StaticVector<float, 8> var256;
  var256 = 0;
  var256 = var256 + (var134[1ll] * var131[1ll]);
  var256 = var256 + (var134[2ll] * var131[7ll]);
  var135[3ll] = var256;
  blaze::StaticVector<float, 8> var257;
  var257 = 0;
  var257 = var257 + (var134[1ll] * var131[4ll]);
  var257 = var257 + (var134[2ll] * var131[8ll]);
  var135[5ll] = var257;
  blaze::StaticVector<float, 8> var258;
  var258 = 0;
  var258 = var258 + (var134[4ll] * var131[0ll]);
  var258 = var258 + (var134[3ll] * var131[2ll]);
  var135[6ll] = var258;
  blaze::StaticVector<float, 8> var259;
  var259 = 0;
  var259 = var259 + (var134[4ll] * var131[1ll]);
  var259 = var259 + (var134[3ll] * var131[3ll]);
  var135[7ll] = var259;
  blaze::StaticVector<float, 8> var260;
  var260 = 0;
  var260 = var260 + (var134[4ll] * var131[4ll]);
  var260 = var260 + (var134[3ll] * var131[5ll]);
  var135[8ll] = var260;
  blaze::StaticVector<float, 8> var261;
  var261 = 0;
  var261 = var261 + (var131[4ll] * 1.0f);
  var136[0ll] = var261;
  blaze::StaticVector<float, 8> var262;
  var262 = 0;
  var262 = var262 + (var131[5ll] * 1.0f);
  var136[1ll] = var262;
  blaze::StaticVector<float, 8> var263;
  var263 = 0;
  var263 = var263 + (var131[8ll] * 1.0f);
  var136[2ll] = var263;
  blaze::StaticVector<float, 8> var264;
  var264 = 0;
  var264 = var264 + (var135[4ll] * 1.0f);
  var136[3ll] = var264;
  blaze::StaticVector<float, 8> var265;
  var265 = 0;
  var265 = var265 + (var135[5ll] * 1.0f);
  var136[4ll] = var265;
  blaze::StaticVector<float, 8> var266;
  var266 = 0;
  var266 = var266 + (var135[8ll] * 1.0f);
  var136[5ll] = var266;
  var140(0ll, 2ll) = var136[0ll];
  var140(1ll, 2ll) = var136[1ll];
  var140(2ll, 2ll) = var136[2ll];
  var140(3ll, 2ll) = var136[3ll];
  var140(4ll, 2ll) = var136[4ll];
  var140(5ll, 2ll) = var136[5ll];
  var145[9ll] = ((var98[0ll] * 0.0f) + (var98[1ll] * 0.0f)) + (var98[2ll] * -0.100000001490116f);
  var146[9ll] = ((var98[3ll] * 0.0f) + (var98[4ll] * 0.0f)) + (var98[5ll] * -0.100000001490116f);
  var147[9ll] = ((var98[6ll] * 0.0f) + (var98[7ll] * 0.0f)) + (var98[8ll] * -0.100000001490116f);
  var145[9ll] = var145[9ll] + var101[0ll];
  var146[9ll] = var146[9ll] + var101[1ll];
  var147[9ll] = var147[9ll] + var101[2ll];
  var148[9ll] = 0.0599999986588955f;
  var145[10ll] = ((var98[0ll] * 0.0f) + (var98[1ll] * 0.0f)) + (var98[2ll] * -0.0599999986588955f);
  var146[10ll] = ((var98[3ll] * 0.0f) + (var98[4ll] * 0.0f)) + (var98[5ll] * -0.0599999986588955f);
  var147[10ll] = ((var98[6ll] * 0.0f) + (var98[7ll] * 0.0f)) + (var98[8ll] * -0.0599999986588955f);
  var145[10ll] = var145[10ll] + var101[0ll];
  var146[10ll] = var146[10ll] + var101[1ll];
  var147[10ll] = var147[10ll] + var101[2ll];
  var148[10ll] = 0.0500000007450581f;
  var145[11ll] = ((var98[0ll] * 0.0799999982118607f) + (var98[1ll] * 0.0599999986588955f)) + (var98[2ll] * 0.0f);
  var146[11ll] = ((var98[3ll] * 0.0799999982118607f) + (var98[4ll] * 0.0599999986588955f)) + (var98[5ll] * 0.0f);
  var147[11ll] = ((var98[6ll] * 0.0799999982118607f) + (var98[7ll] * 0.0599999986588955f)) + (var98[8ll] * 0.0f);
  var145[11ll] = var145[11ll] + var101[0ll];
  var146[11ll] = var146[11ll] + var101[1ll];
  var147[11ll] = var147[11ll] + var101[2ll];
  var148[11ll] = 0.0549999997019768f;
  var145[12ll] = ((var98[0ll] * 0.0799999982118607f) + (var98[1ll] * 0.0199999995529652f)) + (var98[2ll] * 0.0f);
  var146[12ll] = ((var98[3ll] * 0.0799999982118607f) + (var98[4ll] * 0.0199999995529652f)) + (var98[5ll] * 0.0f);
  var147[12ll] = ((var98[6ll] * 0.0799999982118607f) + (var98[7ll] * 0.0199999995529652f)) + (var98[8ll] * 0.0f);
  var145[12ll] = var145[12ll] + var101[0ll];
  var146[12ll] = var146[12ll] + var101[1ll];
  var147[12ll] = var147[12ll] + var101[2ll];
  var148[12ll] = 0.0549999997019768f;
  blaze::StaticVector<float, 8> var267 = arg2[3ll];
  var64 = sin(var267);
  var65 = cos(var267);
  var63[0ll] = var65;
  var63[1ll] = -(var64);
  var63[2ll] = var64;
  var63[3ll] = var65;
  blaze::StaticVector<float, 8> var268;
  var268 = 0;
  var268 = var268 + (1.0f * var63[0ll]);
  var149[0ll] = var268;
  blaze::StaticVector<float, 8> var269;
  var269 = 0;
  var269 = var269 + (1.0f * var63[1ll]);
  var149[1ll] = var269;
  blaze::StaticVector<float, 8> var270;
  var270 = 0;
  var270 = var270 + (1.0f * var63[2ll]);
  var149[2ll] = var270;
  blaze::StaticVector<float, 8> var271;
  var271 = 0;
  var271 = var271 + (1.0f * var63[3ll]);
  var149[3ll] = var271;
  blaze::StaticVector<float, 8> var272;
  var272 = 0;
  var272 = var272 + (1.0f * 1.0f);
  var153 = var272;
  blaze::StaticVector<float, 8> var273;
  var273 = 0;
  var273 = var273 + (var98[0ll] * var149[0ll]);
  var273 = var273 + (var98[2ll] * var149[2ll]);
  var103[0ll] = var273;
  blaze::StaticVector<float, 8> var274;
  var274 = 0;
  var274 = var274 + (var98[0ll] * var149[1ll]);
  var274 = var274 + (var98[2ll] * var149[3ll]);
  var103[1ll] = var274;
  blaze::StaticVector<float, 8> var275;
  var275 = 0;
  var275 = var275 + (var98[1ll] * -1.0f);
  var103[2ll] = var275;
  blaze::StaticVector<float, 8> var276;
  var276 = 0;
  var276 = var276 + (var98[3ll] * var149[0ll]);
  var276 = var276 + (var98[5ll] * var149[2ll]);
  var103[3ll] = var276;
  blaze::StaticVector<float, 8> var277;
  var277 = 0;
  var277 = var277 + (var98[3ll] * var149[1ll]);
  var277 = var277 + (var98[5ll] * var149[3ll]);
  var103[4ll] = var277;
  blaze::StaticVector<float, 8> var278;
  var278 = 0;
  var278 = var278 + (var98[4ll] * -1.0f);
  var103[5ll] = var278;
  blaze::StaticVector<float, 8> var279;
  var279 = 0;
  var279 = var279 + (var98[6ll] * var149[0ll]);
  var279 = var279 + (var98[8ll] * var149[2ll]);
  var103[6ll] = var279;
  blaze::StaticVector<float, 8> var280;
  var280 = 0;
  var280 = var280 + (var98[6ll] * var149[1ll]);
  var280 = var280 + (var98[8ll] * var149[3ll]);
  var103[7ll] = var280;
  blaze::StaticVector<float, 8> var281;
  var281 = 0;
  var281 = var281 + (var98[7ll] * -1.0f);
  var103[8ll] = var281;
  blaze::StaticVector<float, 8> var282;
  var282 = 0;
  var282 = var282 + (var101[0ll] * var153);
  blaze::StaticVector<float, 8> var283;
  var283 = 0;
  var283 = var283 + (var98[0ll] * 0.0825000032782555f);
  var106[0ll] = var283 + var282;
  blaze::StaticVector<float, 8> var284;
  var284 = 0;
  var284 = var284 + (var101[1ll] * var153);
  blaze::StaticVector<float, 8> var285;
  var285 = 0;
  var285 = var285 + (var98[3ll] * 0.0825000032782555f);
  var106[1ll] = var285 + var284;
  blaze::StaticVector<float, 8> var286;
  var286 = 0;
  var286 = var286 + (var101[2ll] * var153);
  blaze::StaticVector<float, 8> var287;
  var287 = 0;
  var287 = var287 + (var98[6ll] * 0.0825000032782555f);
  var106[2ll] = var287 + var286;
  blaze::StaticVector<float, 8> var288;
  var288 = 0;
  var288 = var288 + (var102 * var153);
  var107 = var288;
  var131[0ll] = var88[0ll];
  var131[1ll] = var88[1ll];
  var131[2ll] = var88[2ll];
  var131[3ll] = var88[3ll];
  blaze::StaticVector<float, 8> var289;
  var289 = 0;
  var289 = var289 + (-0.333000004291534f * var131[2ll]);
  var135[0ll] = var289;
  blaze::StaticVector<float, 8> var290;
  var290 = 0;
  var290 = var290 + (-0.333000004291534f * var131[3ll]);
  var135[1ll] = var290;
  blaze::StaticVector<float, 8> var291;
  var291 = 0;
  var291 = var291 + (0.333000004291534f * var131[0ll]);
  var135[2ll] = var291;
  blaze::StaticVector<float, 8> var292;
  var292 = 0;
  var292 = var292 + (0.333000004291534f * var131[1ll]);
  var135[3ll] = var292;
  blaze::StaticVector<float, 8> var293;
  var293 = 0;
  var136[0ll] = var293;
  blaze::StaticVector<float, 8> var294;
  var294 = 0;
  var136[1ll] = var294;
  blaze::StaticVector<float, 8> var295;
  var295 = 0;
  var295 = var295 + (1.0f * 1.0f);
  var136[2ll] = var295;
  blaze::StaticVector<float, 8> var296;
  var296 = 0;
  var136[3ll] = var296;
  blaze::StaticVector<float, 8> var297;
  var297 = 0;
  var136[4ll] = var297;
  blaze::StaticVector<float, 8> var298;
  var298 = 0;
  var136[5ll] = var298;
  var141(0ll, 0ll) = var136[0ll];
  var141(1ll, 0ll) = var136[1ll];
  var141(2ll, 0ll) = var136[2ll];
  var141(3ll, 0ll) = var136[3ll];
  var141(4ll, 0ll) = var136[4ll];
  var141(5ll, 0ll) = var136[5ll];
  var131[0ll] = var93[0ll];
  var131[1ll] = var93[1ll];
  var131[4ll] = var93[2ll];
  var131[2ll] = var93[3ll];
  var131[3ll] = var93[4ll];
  var131[5ll] = var93[5ll];
  var131[6ll] = var93[6ll];
  var131[7ll] = var93[7ll];
  var134[2ll] = -(var96[0ll]);
  var134[3ll] = var96[0ll];
  blaze::StaticVector<float, 8> var299;
  var299 = 0;
  var299 = var299 + (var134[2ll] * var131[2ll]);
  var135[0ll] = var299;
  blaze::StaticVector<float, 8> var300;
  var300 = 0;
  var300 = var300 + (var134[2ll] * var131[3ll]);
  var135[1ll] = var300;
  blaze::StaticVector<float, 8> var301;
  var301 = 0;
  var301 = var301 + (var134[2ll] * var131[5ll]);
  var135[4ll] = var301;
  blaze::StaticVector<float, 8> var302;
  var302 = 0;
  var302 = var302 + (var134[3ll] * var131[0ll]);
  var135[2ll] = var302;
  blaze::StaticVector<float, 8> var303;
  var303 = 0;
  var303 = var303 + (var134[3ll] * var131[1ll]);
  var135[3ll] = var303;
  blaze::StaticVector<float, 8> var304;
  var304 = 0;
  var304 = var304 + (var134[3ll] * var131[4ll]);
  var135[5ll] = var304;
  blaze::StaticVector<float, 8> var305;
  var305 = 0;
  var305 = var305 + (var131[4ll] * 1.0f);
  var136[0ll] = var305;
  blaze::StaticVector<float, 8> var306;
  var306 = 0;
  var306 = var306 + (var131[5ll] * 1.0f);
  var136[1ll] = var306;
  blaze::StaticVector<float, 8> var307;
  var307 = 0;
  var136[2ll] = var307;
  blaze::StaticVector<float, 8> var308;
  var308 = 0;
  var308 = var308 + (var135[4ll] * 1.0f);
  var136[3ll] = var308;
  blaze::StaticVector<float, 8> var309;
  var309 = 0;
  var309 = var309 + (var135[5ll] * 1.0f);
  var136[4ll] = var309;
  blaze::StaticVector<float, 8> var310;
  var310 = 0;
  var136[5ll] = var310;
  var141(0ll, 1ll) = var136[0ll];
  var141(1ll, 1ll) = var136[1ll];
  var141(2ll, 1ll) = var136[2ll];
  var141(3ll, 1ll) = var136[3ll];
  var141(4ll, 1ll) = var136[4ll];
  var141(5ll, 1ll) = var136[5ll];
  var131[0ll] = var98[0ll];
  var131[1ll] = var98[1ll];
  var131[4ll] = var98[2ll];
  var131[2ll] = var98[3ll];
  var131[3ll] = var98[4ll];
  var131[5ll] = var98[5ll];
  var131[6ll] = var98[6ll];
  var131[7ll] = var98[7ll];
  var131[8ll] = var98[8ll];
  var134[4ll] = -(var101[0ll]);
  var134[5ll] = var101[0ll];
  var134[0ll] = -(var101[1ll]);
  var134[1ll] = var101[1ll];
  var134[2ll] = -(var101[2ll]);
  var134[3ll] = var101[2ll];
  blaze::StaticVector<float, 8> var311;
  var311 = 0;
  var311 = var311 + (var134[2ll] * var131[2ll]);
  var311 = var311 + (var134[1ll] * var131[6ll]);
  var135[0ll] = var311;
  blaze::StaticVector<float, 8> var312;
  var312 = 0;
  var312 = var312 + (var134[2ll] * var131[3ll]);
  var312 = var312 + (var134[1ll] * var131[7ll]);
  var135[1ll] = var312;
  blaze::StaticVector<float, 8> var313;
  var313 = 0;
  var313 = var313 + (var134[2ll] * var131[5ll]);
  var313 = var313 + (var134[1ll] * var131[8ll]);
  var135[4ll] = var313;
  blaze::StaticVector<float, 8> var314;
  var314 = 0;
  var314 = var314 + (var134[3ll] * var131[0ll]);
  var314 = var314 + (var134[4ll] * var131[6ll]);
  var135[2ll] = var314;
  blaze::StaticVector<float, 8> var315;
  var315 = 0;
  var315 = var315 + (var134[3ll] * var131[1ll]);
  var315 = var315 + (var134[4ll] * var131[7ll]);
  var135[3ll] = var315;
  blaze::StaticVector<float, 8> var316;
  var316 = 0;
  var316 = var316 + (var134[3ll] * var131[4ll]);
  var316 = var316 + (var134[4ll] * var131[8ll]);
  var135[5ll] = var316;
  blaze::StaticVector<float, 8> var317;
  var317 = 0;
  var317 = var317 + (var134[0ll] * var131[0ll]);
  var317 = var317 + (var134[5ll] * var131[2ll]);
  var135[6ll] = var317;
  blaze::StaticVector<float, 8> var318;
  var318 = 0;
  var318 = var318 + (var134[0ll] * var131[1ll]);
  var318 = var318 + (var134[5ll] * var131[3ll]);
  var135[7ll] = var318;
  blaze::StaticVector<float, 8> var319;
  var319 = 0;
  var319 = var319 + (var134[0ll] * var131[4ll]);
  var319 = var319 + (var134[5ll] * var131[5ll]);
  var135[8ll] = var319;
  blaze::StaticVector<float, 8> var320;
  var320 = 0;
  var320 = var320 + (var131[4ll] * 1.0f);
  var136[0ll] = var320;
  blaze::StaticVector<float, 8> var321;
  var321 = 0;
  var321 = var321 + (var131[5ll] * 1.0f);
  var136[1ll] = var321;
  blaze::StaticVector<float, 8> var322;
  var322 = 0;
  var322 = var322 + (var131[8ll] * 1.0f);
  var136[2ll] = var322;
  blaze::StaticVector<float, 8> var323;
  var323 = 0;
  var323 = var323 + (var135[4ll] * 1.0f);
  var136[3ll] = var323;
  blaze::StaticVector<float, 8> var324;
  var324 = 0;
  var324 = var324 + (var135[5ll] * 1.0f);
  var136[4ll] = var324;
  blaze::StaticVector<float, 8> var325;
  var325 = 0;
  var325 = var325 + (var135[8ll] * 1.0f);
  var136[5ll] = var325;
  var141(0ll, 2ll) = var136[0ll];
  var141(1ll, 2ll) = var136[1ll];
  var141(2ll, 2ll) = var136[2ll];
  var141(3ll, 2ll) = var136[3ll];
  var141(4ll, 2ll) = var136[4ll];
  var141(5ll, 2ll) = var136[5ll];
  var131[0ll] = var103[0ll];
  var131[1ll] = var103[1ll];
  var131[4ll] = var103[2ll];
  var131[2ll] = var103[3ll];
  var131[3ll] = var103[4ll];
  var131[5ll] = var103[5ll];
  var131[6ll] = var103[6ll];
  var131[7ll] = var103[7ll];
  var131[8ll] = var103[8ll];
  var134[4ll] = -(var106[0ll]);
  var134[5ll] = var106[0ll];
  var134[0ll] = -(var106[1ll]);
  var134[1ll] = var106[1ll];
  var134[2ll] = -(var106[2ll]);
  var134[3ll] = var106[2ll];
  blaze::StaticVector<float, 8> var326;
  var326 = 0;
  var326 = var326 + (var134[2ll] * var131[2ll]);
  var326 = var326 + (var134[1ll] * var131[6ll]);
  var135[0ll] = var326;
  blaze::StaticVector<float, 8> var327;
  var327 = 0;
  var327 = var327 + (var134[2ll] * var131[3ll]);
  var327 = var327 + (var134[1ll] * var131[7ll]);
  var135[1ll] = var327;
  blaze::StaticVector<float, 8> var328;
  var328 = 0;
  var328 = var328 + (var134[2ll] * var131[5ll]);
  var328 = var328 + (var134[1ll] * var131[8ll]);
  var135[4ll] = var328;
  blaze::StaticVector<float, 8> var329;
  var329 = 0;
  var329 = var329 + (var134[3ll] * var131[0ll]);
  var329 = var329 + (var134[4ll] * var131[6ll]);
  var135[2ll] = var329;
  blaze::StaticVector<float, 8> var330;
  var330 = 0;
  var330 = var330 + (var134[3ll] * var131[1ll]);
  var330 = var330 + (var134[4ll] * var131[7ll]);
  var135[3ll] = var330;
  blaze::StaticVector<float, 8> var331;
  var331 = 0;
  var331 = var331 + (var134[3ll] * var131[4ll]);
  var331 = var331 + (var134[4ll] * var131[8ll]);
  var135[5ll] = var331;
  blaze::StaticVector<float, 8> var332;
  var332 = 0;
  var332 = var332 + (var134[0ll] * var131[0ll]);
  var332 = var332 + (var134[5ll] * var131[2ll]);
  var135[6ll] = var332;
  blaze::StaticVector<float, 8> var333;
  var333 = 0;
  var333 = var333 + (var134[0ll] * var131[1ll]);
  var333 = var333 + (var134[5ll] * var131[3ll]);
  var135[7ll] = var333;
  blaze::StaticVector<float, 8> var334;
  var334 = 0;
  var334 = var334 + (var134[0ll] * var131[4ll]);
  var334 = var334 + (var134[5ll] * var131[5ll]);
  var135[8ll] = var334;
  blaze::StaticVector<float, 8> var335;
  var335 = 0;
  var335 = var335 + (var131[4ll] * 1.0f);
  var136[0ll] = var335;
  blaze::StaticVector<float, 8> var336;
  var336 = 0;
  var336 = var336 + (var131[5ll] * 1.0f);
  var136[1ll] = var336;
  blaze::StaticVector<float, 8> var337;
  var337 = 0;
  var337 = var337 + (var131[8ll] * 1.0f);
  var136[2ll] = var337;
  blaze::StaticVector<float, 8> var338;
  var338 = 0;
  var338 = var338 + (var135[4ll] * 1.0f);
  var136[3ll] = var338;
  blaze::StaticVector<float, 8> var339;
  var339 = 0;
  var339 = var339 + (var135[5ll] * 1.0f);
  var136[4ll] = var339;
  blaze::StaticVector<float, 8> var340;
  var340 = 0;
  var340 = var340 + (var135[8ll] * 1.0f);
  var136[5ll] = var340;
  var141(0ll, 3ll) = var136[0ll];
  var141(1ll, 3ll) = var136[1ll];
  var141(2ll, 3ll) = var136[2ll];
  var141(3ll, 3ll) = var136[3ll];
  var141(4ll, 3ll) = var136[4ll];
  var141(5ll, 3ll) = var136[5ll];
  var145[13ll] = ((var103[0ll] * -0.0799999982118607f) + (var103[1ll] * 0.0949999988079071f)) + (var103[2ll] * 0.0f);
  var146[13ll] = ((var103[3ll] * -0.0799999982118607f) + (var103[4ll] * 0.0949999988079071f)) + (var103[5ll] * 0.0f);
  var147[13ll] = ((var103[6ll] * -0.0799999982118607f) + (var103[7ll] * 0.0949999988079071f)) + (var103[8ll] * 0.0f);
  var145[13ll] = var145[13ll] + var106[0ll];
  var146[13ll] = var146[13ll] + var106[1ll];
  var147[13ll] = var147[13ll] + var106[2ll];
  var148[13ll] = 0.0599999986588955f;
  var145[14ll] = ((var103[0ll] * 0.0f) + (var103[1ll] * 0.0f)) + (var103[2ll] * 0.0199999995529652f);
  var146[14ll] = ((var103[3ll] * 0.0f) + (var103[4ll] * 0.0f)) + (var103[5ll] * 0.0199999995529652f);
  var147[14ll] = ((var103[6ll] * 0.0f) + (var103[7ll] * 0.0f)) + (var103[8ll] * 0.0199999995529652f);
  var145[14ll] = var145[14ll] + var106[0ll];
  var146[14ll] = var146[14ll] + var106[1ll];
  var147[14ll] = var147[14ll] + var106[2ll];
  var148[14ll] = 0.0549999997019768f;
  var145[15ll] = ((var103[0ll] * 0.0f) + (var103[1ll] * 0.0f)) + (var103[2ll] * 0.0599999986588955f);
  var146[15ll] = ((var103[3ll] * 0.0f) + (var103[4ll] * 0.0f)) + (var103[5ll] * 0.0599999986588955f);
  var147[15ll] = ((var103[6ll] * 0.0f) + (var103[7ll] * 0.0f)) + (var103[8ll] * 0.0599999986588955f);
  var145[15ll] = var145[15ll] + var106[0ll];
  var146[15ll] = var146[15ll] + var106[1ll];
  var147[15ll] = var147[15ll] + var106[2ll];
  var148[15ll] = 0.0549999997019768f;
  var145[16ll] = ((var103[0ll] * -0.0799999982118607f) + (var103[1ll] * 0.0599999986588955f)) + (var103[2ll] * 0.0f);
  var146[16ll] = ((var103[3ll] * -0.0799999982118607f) + (var103[4ll] * 0.0599999986588955f)) + (var103[5ll] * 0.0f);
  var147[16ll] = ((var103[6ll] * -0.0799999982118607f) + (var103[7ll] * 0.0599999986588955f)) + (var103[8ll] * 0.0f);
  var145[16ll] = var145[16ll] + var106[0ll];
  var146[16ll] = var146[16ll] + var106[1ll];
  var147[16ll] = var147[16ll] + var106[2ll];
  var148[16ll] = 0.0549999997019768f;
  blaze::StaticVector<float, 8> var341 = arg2[4ll];
  var69 = sin(var341);
  var70 = cos(var341);
  var68[0ll] = var70;
  var68[1ll] = -(var69);
  var68[2ll] = var69;
  var68[3ll] = var70;
  blaze::StaticVector<float, 8> var342;
  var342 = 0;
  var342 = var342 + (1.0f * var68[0ll]);
  var149[0ll] = var342;
  blaze::StaticVector<float, 8> var343;
  var343 = 0;
  var343 = var343 + (1.0f * var68[1ll]);
  var149[1ll] = var343;
  blaze::StaticVector<float, 8> var344;
  var344 = 0;
  var344 = var344 + (-1.0f * var68[2ll]);
  var149[2ll] = var344;
  blaze::StaticVector<float, 8> var345;
  var345 = 0;
  var345 = var345 + (-1.0f * var68[3ll]);
  var149[3ll] = var345;
  blaze::StaticVector<float, 8> var346;
  var346 = 0;
  var346 = var346 + (1.0f * 1.0f);
  var153 = var346;
  blaze::StaticVector<float, 8> var347;
  var347 = 0;
  var347 = var347 + (var103[0ll] * var149[0ll]);
  var347 = var347 + (var103[2ll] * var149[2ll]);
  var108[0ll] = var347;
  blaze::StaticVector<float, 8> var348;
  var348 = 0;
  var348 = var348 + (var103[0ll] * var149[1ll]);
  var348 = var348 + (var103[2ll] * var149[3ll]);
  var108[1ll] = var348;
  blaze::StaticVector<float, 8> var349;
  var349 = 0;
  var349 = var349 + (var103[1ll] * 1.0f);
  var108[2ll] = var349;
  blaze::StaticVector<float, 8> var350;
  var350 = 0;
  var350 = var350 + (var103[3ll] * var149[0ll]);
  var350 = var350 + (var103[5ll] * var149[2ll]);
  var108[3ll] = var350;
  blaze::StaticVector<float, 8> var351;
  var351 = 0;
  var351 = var351 + (var103[3ll] * var149[1ll]);
  var351 = var351 + (var103[5ll] * var149[3ll]);
  var108[4ll] = var351;
  blaze::StaticVector<float, 8> var352;
  var352 = 0;
  var352 = var352 + (var103[4ll] * 1.0f);
  var108[5ll] = var352;
  blaze::StaticVector<float, 8> var353;
  var353 = 0;
  var353 = var353 + (var103[6ll] * var149[0ll]);
  var353 = var353 + (var103[8ll] * var149[2ll]);
  var108[6ll] = var353;
  blaze::StaticVector<float, 8> var354;
  var354 = 0;
  var354 = var354 + (var103[6ll] * var149[1ll]);
  var354 = var354 + (var103[8ll] * var149[3ll]);
  var108[7ll] = var354;
  blaze::StaticVector<float, 8> var355;
  var355 = 0;
  var355 = var355 + (var103[7ll] * 1.0f);
  var108[8ll] = var355;
  blaze::StaticVector<float, 8> var356;
  var356 = 0;
  var356 = var356 + (var106[0ll] * var153);
  blaze::StaticVector<float, 8> var357;
  var357 = 0;
  var357 = var357 + (var103[0ll] * -0.0825000032782555f);
  var357 = var357 + (var103[1ll] * 0.38400000333786f);
  var111[0ll] = var357 + var356;
  blaze::StaticVector<float, 8> var358;
  var358 = 0;
  var358 = var358 + (var106[1ll] * var153);
  blaze::StaticVector<float, 8> var359;
  var359 = 0;
  var359 = var359 + (var103[3ll] * -0.0825000032782555f);
  var359 = var359 + (var103[4ll] * 0.38400000333786f);
  var111[1ll] = var359 + var358;
  blaze::StaticVector<float, 8> var360;
  var360 = 0;
  var360 = var360 + (var106[2ll] * var153);
  blaze::StaticVector<float, 8> var361;
  var361 = 0;
  var361 = var361 + (var103[6ll] * -0.0825000032782555f);
  var361 = var361 + (var103[7ll] * 0.38400000333786f);
  var111[2ll] = var361 + var360;
  blaze::StaticVector<float, 8> var362;
  var362 = 0;
  var362 = var362 + (var107 * var153);
  var112 = var362;
  var131[0ll] = var88[0ll];
  var131[1ll] = var88[1ll];
  var131[2ll] = var88[2ll];
  var131[3ll] = var88[3ll];
  blaze::StaticVector<float, 8> var363;
  var363 = 0;
  var363 = var363 + (-0.333000004291534f * var131[2ll]);
  var135[0ll] = var363;
  blaze::StaticVector<float, 8> var364;
  var364 = 0;
  var364 = var364 + (-0.333000004291534f * var131[3ll]);
  var135[1ll] = var364;
  blaze::StaticVector<float, 8> var365;
  var365 = 0;
  var365 = var365 + (0.333000004291534f * var131[0ll]);
  var135[2ll] = var365;
  blaze::StaticVector<float, 8> var366;
  var366 = 0;
  var366 = var366 + (0.333000004291534f * var131[1ll]);
  var135[3ll] = var366;
  blaze::StaticVector<float, 8> var367;
  var367 = 0;
  var136[0ll] = var367;
  blaze::StaticVector<float, 8> var368;
  var368 = 0;
  var136[1ll] = var368;
  blaze::StaticVector<float, 8> var369;
  var369 = 0;
  var369 = var369 + (1.0f * 1.0f);
  var136[2ll] = var369;
  blaze::StaticVector<float, 8> var370;
  var370 = 0;
  var136[3ll] = var370;
  blaze::StaticVector<float, 8> var371;
  var371 = 0;
  var136[4ll] = var371;
  blaze::StaticVector<float, 8> var372;
  var372 = 0;
  var136[5ll] = var372;
  var142(0ll, 0ll) = var136[0ll];
  var142(1ll, 0ll) = var136[1ll];
  var142(2ll, 0ll) = var136[2ll];
  var142(3ll, 0ll) = var136[3ll];
  var142(4ll, 0ll) = var136[4ll];
  var142(5ll, 0ll) = var136[5ll];
  var131[0ll] = var93[0ll];
  var131[1ll] = var93[1ll];
  var131[4ll] = var93[2ll];
  var131[2ll] = var93[3ll];
  var131[3ll] = var93[4ll];
  var131[5ll] = var93[5ll];
  var131[6ll] = var93[6ll];
  var131[7ll] = var93[7ll];
  var134[4ll] = -(var96[0ll]);
  var134[5ll] = var96[0ll];
  blaze::StaticVector<float, 8> var373;
  var373 = 0;
  var373 = var373 + (var134[4ll] * var131[2ll]);
  var135[0ll] = var373;
  blaze::StaticVector<float, 8> var374;
  var374 = 0;
  var374 = var374 + (var134[4ll] * var131[3ll]);
  var135[1ll] = var374;
  blaze::StaticVector<float, 8> var375;
  var375 = 0;
  var375 = var375 + (var134[4ll] * var131[5ll]);
  var135[4ll] = var375;
  blaze::StaticVector<float, 8> var376;
  var376 = 0;
  var376 = var376 + (var134[5ll] * var131[0ll]);
  var135[2ll] = var376;
  blaze::StaticVector<float, 8> var377;
  var377 = 0;
  var377 = var377 + (var134[5ll] * var131[1ll]);
  var135[3ll] = var377;
  blaze::StaticVector<float, 8> var378;
  var378 = 0;
  var378 = var378 + (var134[5ll] * var131[4ll]);
  var135[5ll] = var378;
  blaze::StaticVector<float, 8> var379;
  var379 = 0;
  var379 = var379 + (var131[4ll] * 1.0f);
  var136[0ll] = var379;
  blaze::StaticVector<float, 8> var380;
  var380 = 0;
  var380 = var380 + (var131[5ll] * 1.0f);
  var136[1ll] = var380;
  blaze::StaticVector<float, 8> var381;
  var381 = 0;
  var136[2ll] = var381;
  blaze::StaticVector<float, 8> var382;
  var382 = 0;
  var382 = var382 + (var135[4ll] * 1.0f);
  var136[3ll] = var382;
  blaze::StaticVector<float, 8> var383;
  var383 = 0;
  var383 = var383 + (var135[5ll] * 1.0f);
  var136[4ll] = var383;
  blaze::StaticVector<float, 8> var384;
  var384 = 0;
  var136[5ll] = var384;
  var142(0ll, 1ll) = var136[0ll];
  var142(1ll, 1ll) = var136[1ll];
  var142(2ll, 1ll) = var136[2ll];
  var142(3ll, 1ll) = var136[3ll];
  var142(4ll, 1ll) = var136[4ll];
  var142(5ll, 1ll) = var136[5ll];
  var131[0ll] = var98[0ll];
  var131[1ll] = var98[1ll];
  var131[4ll] = var98[2ll];
  var131[2ll] = var98[3ll];
  var131[3ll] = var98[4ll];
  var131[5ll] = var98[5ll];
  var131[6ll] = var98[6ll];
  var131[7ll] = var98[7ll];
  var131[8ll] = var98[8ll];
  var134[0ll] = -(var101[0ll]);
  var134[1ll] = var101[0ll];
  var134[2ll] = -(var101[1ll]);
  var134[3ll] = var101[1ll];
  var134[4ll] = -(var101[2ll]);
  var134[5ll] = var101[2ll];
  blaze::StaticVector<float, 8> var385;
  var385 = 0;
  var385 = var385 + (var134[4ll] * var131[2ll]);
  var385 = var385 + (var134[3ll] * var131[6ll]);
  var135[0ll] = var385;
  blaze::StaticVector<float, 8> var386;
  var386 = 0;
  var386 = var386 + (var134[4ll] * var131[3ll]);
  var386 = var386 + (var134[3ll] * var131[7ll]);
  var135[1ll] = var386;
  blaze::StaticVector<float, 8> var387;
  var387 = 0;
  var387 = var387 + (var134[4ll] * var131[5ll]);
  var387 = var387 + (var134[3ll] * var131[8ll]);
  var135[4ll] = var387;
  blaze::StaticVector<float, 8> var388;
  var388 = 0;
  var388 = var388 + (var134[5ll] * var131[0ll]);
  var388 = var388 + (var134[0ll] * var131[6ll]);
  var135[2ll] = var388;
  blaze::StaticVector<float, 8> var389;
  var389 = 0;
  var389 = var389 + (var134[5ll] * var131[1ll]);
  var389 = var389 + (var134[0ll] * var131[7ll]);
  var135[3ll] = var389;
  blaze::StaticVector<float, 8> var390;
  var390 = 0;
  var390 = var390 + (var134[5ll] * var131[4ll]);
  var390 = var390 + (var134[0ll] * var131[8ll]);
  var135[5ll] = var390;
  blaze::StaticVector<float, 8> var391;
  var391 = 0;
  var391 = var391 + (var134[2ll] * var131[0ll]);
  var391 = var391 + (var134[1ll] * var131[2ll]);
  var135[6ll] = var391;
  blaze::StaticVector<float, 8> var392;
  var392 = 0;
  var392 = var392 + (var134[2ll] * var131[1ll]);
  var392 = var392 + (var134[1ll] * var131[3ll]);
  var135[7ll] = var392;
  blaze::StaticVector<float, 8> var393;
  var393 = 0;
  var393 = var393 + (var134[2ll] * var131[4ll]);
  var393 = var393 + (var134[1ll] * var131[5ll]);
  var135[8ll] = var393;
  blaze::StaticVector<float, 8> var394;
  var394 = 0;
  var394 = var394 + (var131[4ll] * 1.0f);
  var136[0ll] = var394;
  blaze::StaticVector<float, 8> var395;
  var395 = 0;
  var395 = var395 + (var131[5ll] * 1.0f);
  var136[1ll] = var395;
  blaze::StaticVector<float, 8> var396;
  var396 = 0;
  var396 = var396 + (var131[8ll] * 1.0f);
  var136[2ll] = var396;
  blaze::StaticVector<float, 8> var397;
  var397 = 0;
  var397 = var397 + (var135[4ll] * 1.0f);
  var136[3ll] = var397;
  blaze::StaticVector<float, 8> var398;
  var398 = 0;
  var398 = var398 + (var135[5ll] * 1.0f);
  var136[4ll] = var398;
  blaze::StaticVector<float, 8> var399;
  var399 = 0;
  var399 = var399 + (var135[8ll] * 1.0f);
  var136[5ll] = var399;
  var142(0ll, 2ll) = var136[0ll];
  var142(1ll, 2ll) = var136[1ll];
  var142(2ll, 2ll) = var136[2ll];
  var142(3ll, 2ll) = var136[3ll];
  var142(4ll, 2ll) = var136[4ll];
  var142(5ll, 2ll) = var136[5ll];
  var131[0ll] = var103[0ll];
  var131[1ll] = var103[1ll];
  var131[4ll] = var103[2ll];
  var131[2ll] = var103[3ll];
  var131[3ll] = var103[4ll];
  var131[5ll] = var103[5ll];
  var131[6ll] = var103[6ll];
  var131[7ll] = var103[7ll];
  var131[8ll] = var103[8ll];
  var134[0ll] = -(var106[0ll]);
  var134[1ll] = var106[0ll];
  var134[2ll] = -(var106[1ll]);
  var134[3ll] = var106[1ll];
  var134[4ll] = -(var106[2ll]);
  var134[5ll] = var106[2ll];
  blaze::StaticVector<float, 8> var400;
  var400 = 0;
  var400 = var400 + (var134[4ll] * var131[2ll]);
  var400 = var400 + (var134[3ll] * var131[6ll]);
  var135[0ll] = var400;
  blaze::StaticVector<float, 8> var401;
  var401 = 0;
  var401 = var401 + (var134[4ll] * var131[3ll]);
  var401 = var401 + (var134[3ll] * var131[7ll]);
  var135[1ll] = var401;
  blaze::StaticVector<float, 8> var402;
  var402 = 0;
  var402 = var402 + (var134[4ll] * var131[5ll]);
  var402 = var402 + (var134[3ll] * var131[8ll]);
  var135[4ll] = var402;
  blaze::StaticVector<float, 8> var403;
  var403 = 0;
  var403 = var403 + (var134[5ll] * var131[0ll]);
  var403 = var403 + (var134[0ll] * var131[6ll]);
  var135[2ll] = var403;
  blaze::StaticVector<float, 8> var404;
  var404 = 0;
  var404 = var404 + (var134[5ll] * var131[1ll]);
  var404 = var404 + (var134[0ll] * var131[7ll]);
  var135[3ll] = var404;
  blaze::StaticVector<float, 8> var405;
  var405 = 0;
  var405 = var405 + (var134[5ll] * var131[4ll]);
  var405 = var405 + (var134[0ll] * var131[8ll]);
  var135[5ll] = var405;
  blaze::StaticVector<float, 8> var406;
  var406 = 0;
  var406 = var406 + (var134[2ll] * var131[0ll]);
  var406 = var406 + (var134[1ll] * var131[2ll]);
  var135[6ll] = var406;
  blaze::StaticVector<float, 8> var407;
  var407 = 0;
  var407 = var407 + (var134[2ll] * var131[1ll]);
  var407 = var407 + (var134[1ll] * var131[3ll]);
  var135[7ll] = var407;
  blaze::StaticVector<float, 8> var408;
  var408 = 0;
  var408 = var408 + (var134[2ll] * var131[4ll]);
  var408 = var408 + (var134[1ll] * var131[5ll]);
  var135[8ll] = var408;
  blaze::StaticVector<float, 8> var409;
  var409 = 0;
  var409 = var409 + (var131[4ll] * 1.0f);
  var136[0ll] = var409;
  blaze::StaticVector<float, 8> var410;
  var410 = 0;
  var410 = var410 + (var131[5ll] * 1.0f);
  var136[1ll] = var410;
  blaze::StaticVector<float, 8> var411;
  var411 = 0;
  var411 = var411 + (var131[8ll] * 1.0f);
  var136[2ll] = var411;
  blaze::StaticVector<float, 8> var412;
  var412 = 0;
  var412 = var412 + (var135[4ll] * 1.0f);
  var136[3ll] = var412;
  blaze::StaticVector<float, 8> var413;
  var413 = 0;
  var413 = var413 + (var135[5ll] * 1.0f);
  var136[4ll] = var413;
  blaze::StaticVector<float, 8> var414;
  var414 = 0;
  var414 = var414 + (var135[8ll] * 1.0f);
  var136[5ll] = var414;
  var142(0ll, 3ll) = var136[0ll];
  var142(1ll, 3ll) = var136[1ll];
  var142(2ll, 3ll) = var136[2ll];
  var142(3ll, 3ll) = var136[3ll];
  var142(4ll, 3ll) = var136[4ll];
  var142(5ll, 3ll) = var136[5ll];
  var131[0ll] = var108[0ll];
  var131[1ll] = var108[1ll];
  var131[4ll] = var108[2ll];
  var131[2ll] = var108[3ll];
  var131[3ll] = var108[4ll];
  var131[5ll] = var108[5ll];
  var131[6ll] = var108[6ll];
  var131[7ll] = var108[7ll];
  var131[8ll] = var108[8ll];
  var134[0ll] = -(var111[0ll]);
  var134[1ll] = var111[0ll];
  var134[2ll] = -(var111[1ll]);
  var134[3ll] = var111[1ll];
  var134[4ll] = -(var111[2ll]);
  var134[5ll] = var111[2ll];
  blaze::StaticVector<float, 8> var415;
  var415 = 0;
  var415 = var415 + (var134[4ll] * var131[2ll]);
  var415 = var415 + (var134[3ll] * var131[6ll]);
  var135[0ll] = var415;
  blaze::StaticVector<float, 8> var416;
  var416 = 0;
  var416 = var416 + (var134[4ll] * var131[3ll]);
  var416 = var416 + (var134[3ll] * var131[7ll]);
  var135[1ll] = var416;
  blaze::StaticVector<float, 8> var417;
  var417 = 0;
  var417 = var417 + (var134[4ll] * var131[5ll]);
  var417 = var417 + (var134[3ll] * var131[8ll]);
  var135[4ll] = var417;
  blaze::StaticVector<float, 8> var418;
  var418 = 0;
  var418 = var418 + (var134[5ll] * var131[0ll]);
  var418 = var418 + (var134[0ll] * var131[6ll]);
  var135[2ll] = var418;
  blaze::StaticVector<float, 8> var419;
  var419 = 0;
  var419 = var419 + (var134[5ll] * var131[1ll]);
  var419 = var419 + (var134[0ll] * var131[7ll]);
  var135[3ll] = var419;
  blaze::StaticVector<float, 8> var420;
  var420 = 0;
  var420 = var420 + (var134[5ll] * var131[4ll]);
  var420 = var420 + (var134[0ll] * var131[8ll]);
  var135[5ll] = var420;
  blaze::StaticVector<float, 8> var421;
  var421 = 0;
  var421 = var421 + (var134[2ll] * var131[0ll]);
  var421 = var421 + (var134[1ll] * var131[2ll]);
  var135[6ll] = var421;
  blaze::StaticVector<float, 8> var422;
  var422 = 0;
  var422 = var422 + (var134[2ll] * var131[1ll]);
  var422 = var422 + (var134[1ll] * var131[3ll]);
  var135[7ll] = var422;
  blaze::StaticVector<float, 8> var423;
  var423 = 0;
  var423 = var423 + (var134[2ll] * var131[4ll]);
  var423 = var423 + (var134[1ll] * var131[5ll]);
  var135[8ll] = var423;
  blaze::StaticVector<float, 8> var424;
  var424 = 0;
  var424 = var424 + (var131[4ll] * 1.0f);
  var136[0ll] = var424;
  blaze::StaticVector<float, 8> var425;
  var425 = 0;
  var425 = var425 + (var131[5ll] * 1.0f);
  var136[1ll] = var425;
  blaze::StaticVector<float, 8> var426;
  var426 = 0;
  var426 = var426 + (var131[8ll] * 1.0f);
  var136[2ll] = var426;
  blaze::StaticVector<float, 8> var427;
  var427 = 0;
  var427 = var427 + (var135[4ll] * 1.0f);
  var136[3ll] = var427;
  blaze::StaticVector<float, 8> var428;
  var428 = 0;
  var428 = var428 + (var135[5ll] * 1.0f);
  var136[4ll] = var428;
  blaze::StaticVector<float, 8> var429;
  var429 = 0;
  var429 = var429 + (var135[8ll] * 1.0f);
  var136[5ll] = var429;
  var142(0ll, 4ll) = var136[0ll];
  var142(1ll, 4ll) = var136[1ll];
  var142(2ll, 4ll) = var136[2ll];
  var142(3ll, 4ll) = var136[3ll];
  var142(4ll, 4ll) = var136[4ll];
  var142(5ll, 4ll) = var136[5ll];
  var145[17ll] = ((var108[0ll] * 0.0f) + (var108[1ll] * 0.0549999997019768f)) + (var108[2ll] * 0.0f);
  var146[17ll] = ((var108[3ll] * 0.0f) + (var108[4ll] * 0.0549999997019768f)) + (var108[5ll] * 0.0f);
  var147[17ll] = ((var108[6ll] * 0.0f) + (var108[7ll] * 0.0549999997019768f)) + (var108[8ll] * 0.0f);
  var145[17ll] = var145[17ll] + var111[0ll];
  var146[17ll] = var146[17ll] + var111[1ll];
  var147[17ll] = var147[17ll] + var111[2ll];
  var148[17ll] = 0.0599999986588955f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(0ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[17ll], var146[17ll], var147[17ll], var148[17ll], arg3, arg4); //collision pair: 0,17 : panda_link0_0,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(42ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[17ll], var146[17ll], var147[17ll], var148[17ll], arg3, arg4); //collision pair: 1,17 : panda_link1_0,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(84ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[17ll], var146[17ll], var147[17ll], var148[17ll], arg3, arg4); //collision pair: 2,17 : panda_link1_1,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(126ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[17ll], var146[17ll], var147[17ll], var148[17ll], arg3, arg4); //collision pair: 3,17 : panda_link1_2,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(168ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[17ll], var146[17ll], var147[17ll], var148[17ll], arg3, arg4); //collision pair: 4,17 : panda_link1_3,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(210ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[17ll], var146[17ll], var147[17ll], var148[17ll], arg3, arg4); //collision pair: 5,17 : panda_link2_0,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(249ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[17ll], var146[17ll], var147[17ll], var148[17ll], arg3, arg4); //collision pair: 6,17 : panda_link2_1,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(288ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[17ll], var146[17ll], var147[17ll], var148[17ll], arg3, arg4); //collision pair: 7,17 : panda_link2_2,panda_link5_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(327ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[17ll], var146[17ll], var147[17ll], var148[17ll], arg3, arg4); //collision pair: 8,17 : panda_link2_3,panda_link5_0
  var145[18ll] = ((var108[0ll] * 0.0f) + (var108[1ll] * 0.0750000029802322f)) + (var108[2ll] * 0.0f);
  var146[18ll] = ((var108[3ll] * 0.0f) + (var108[4ll] * 0.0750000029802322f)) + (var108[5ll] * 0.0f);
  var147[18ll] = ((var108[6ll] * 0.0f) + (var108[7ll] * 0.0750000029802322f)) + (var108[8ll] * 0.0f);
  var145[18ll] = var145[18ll] + var111[0ll];
  var146[18ll] = var146[18ll] + var111[1ll];
  var147[18ll] = var147[18ll] + var111[2ll];
  var148[18ll] = 0.0599999986588955f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(1ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[18ll], var146[18ll], var147[18ll], var148[18ll], arg3, arg4); //collision pair: 0,18 : panda_link0_0,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(43ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[18ll], var146[18ll], var147[18ll], var148[18ll], arg3, arg4); //collision pair: 1,18 : panda_link1_0,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(85ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[18ll], var146[18ll], var147[18ll], var148[18ll], arg3, arg4); //collision pair: 2,18 : panda_link1_1,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(127ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[18ll], var146[18ll], var147[18ll], var148[18ll], arg3, arg4); //collision pair: 3,18 : panda_link1_2,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(169ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[18ll], var146[18ll], var147[18ll], var148[18ll], arg3, arg4); //collision pair: 4,18 : panda_link1_3,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(211ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[18ll], var146[18ll], var147[18ll], var148[18ll], arg3, arg4); //collision pair: 5,18 : panda_link2_0,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(250ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[18ll], var146[18ll], var147[18ll], var148[18ll], arg3, arg4); //collision pair: 6,18 : panda_link2_1,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(289ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[18ll], var146[18ll], var147[18ll], var148[18ll], arg3, arg4); //collision pair: 7,18 : panda_link2_2,panda_link5_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(328ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[18ll], var146[18ll], var147[18ll], var148[18ll], arg3, arg4); //collision pair: 8,18 : panda_link2_3,panda_link5_1
  var145[19ll] = ((var108[0ll] * 0.0f) + (var108[1ll] * 0.0f)) + (var108[2ll] * -0.219999998807907f);
  var146[19ll] = ((var108[3ll] * 0.0f) + (var108[4ll] * 0.0f)) + (var108[5ll] * -0.219999998807907f);
  var147[19ll] = ((var108[6ll] * 0.0f) + (var108[7ll] * 0.0f)) + (var108[8ll] * -0.219999998807907f);
  var145[19ll] = var145[19ll] + var111[0ll];
  var146[19ll] = var146[19ll] + var111[1ll];
  var147[19ll] = var147[19ll] + var111[2ll];
  var148[19ll] = 0.0599999986588955f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(2ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[19ll], var146[19ll], var147[19ll], var148[19ll], arg3, arg4); //collision pair: 0,19 : panda_link0_0,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(44ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[19ll], var146[19ll], var147[19ll], var148[19ll], arg3, arg4); //collision pair: 1,19 : panda_link1_0,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(86ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[19ll], var146[19ll], var147[19ll], var148[19ll], arg3, arg4); //collision pair: 2,19 : panda_link1_1,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(128ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[19ll], var146[19ll], var147[19ll], var148[19ll], arg3, arg4); //collision pair: 3,19 : panda_link1_2,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(170ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[19ll], var146[19ll], var147[19ll], var148[19ll], arg3, arg4); //collision pair: 4,19 : panda_link1_3,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(212ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[19ll], var146[19ll], var147[19ll], var148[19ll], arg3, arg4); //collision pair: 5,19 : panda_link2_0,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(251ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[19ll], var146[19ll], var147[19ll], var148[19ll], arg3, arg4); //collision pair: 6,19 : panda_link2_1,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(290ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[19ll], var146[19ll], var147[19ll], var148[19ll], arg3, arg4); //collision pair: 7,19 : panda_link2_2,panda_link5_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(329ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[19ll], var146[19ll], var147[19ll], var148[19ll], arg3, arg4); //collision pair: 8,19 : panda_link2_3,panda_link5_2
  var145[20ll] = ((var108[0ll] * 0.0f) + (var108[1ll] * 0.0500000007450581f)) + (var108[2ll] * -0.180000007152557f);
  var146[20ll] = ((var108[3ll] * 0.0f) + (var108[4ll] * 0.0500000007450581f)) + (var108[5ll] * -0.180000007152557f);
  var147[20ll] = ((var108[6ll] * 0.0f) + (var108[7ll] * 0.0500000007450581f)) + (var108[8ll] * -0.180000007152557f);
  var145[20ll] = var145[20ll] + var111[0ll];
  var146[20ll] = var146[20ll] + var111[1ll];
  var147[20ll] = var147[20ll] + var111[2ll];
  var148[20ll] = 0.0500000007450581f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(3ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[20ll], var146[20ll], var147[20ll], var148[20ll], arg3, arg4); //collision pair: 0,20 : panda_link0_0,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(45ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[20ll], var146[20ll], var147[20ll], var148[20ll], arg3, arg4); //collision pair: 1,20 : panda_link1_0,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(87ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[20ll], var146[20ll], var147[20ll], var148[20ll], arg3, arg4); //collision pair: 2,20 : panda_link1_1,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(129ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[20ll], var146[20ll], var147[20ll], var148[20ll], arg3, arg4); //collision pair: 3,20 : panda_link1_2,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(171ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[20ll], var146[20ll], var147[20ll], var148[20ll], arg3, arg4); //collision pair: 4,20 : panda_link1_3,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(213ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[20ll], var146[20ll], var147[20ll], var148[20ll], arg3, arg4); //collision pair: 5,20 : panda_link2_0,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(252ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[20ll], var146[20ll], var147[20ll], var148[20ll], arg3, arg4); //collision pair: 6,20 : panda_link2_1,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(291ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[20ll], var146[20ll], var147[20ll], var148[20ll], arg3, arg4); //collision pair: 7,20 : panda_link2_2,panda_link5_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(330ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[20ll], var146[20ll], var147[20ll], var148[20ll], arg3, arg4); //collision pair: 8,20 : panda_link2_3,panda_link5_3
  var145[21ll] = ((var108[0ll] * 0.00999999977648258f) + (var108[1ll] * 0.0799999982118607f)) + (var108[2ll] * -0.140000000596046f);
  var146[21ll] = ((var108[3ll] * 0.00999999977648258f) + (var108[4ll] * 0.0799999982118607f)) + (var108[5ll] * -0.140000000596046f);
  var147[21ll] = ((var108[6ll] * 0.00999999977648258f) + (var108[7ll] * 0.0799999982118607f)) + (var108[8ll] * -0.140000000596046f);
  var145[21ll] = var145[21ll] + var111[0ll];
  var146[21ll] = var146[21ll] + var111[1ll];
  var147[21ll] = var147[21ll] + var111[2ll];
  var148[21ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(4ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[21ll], var146[21ll], var147[21ll], var148[21ll], arg3, arg4); //collision pair: 0,21 : panda_link0_0,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(46ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[21ll], var146[21ll], var147[21ll], var148[21ll], arg3, arg4); //collision pair: 1,21 : panda_link1_0,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(88ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[21ll], var146[21ll], var147[21ll], var148[21ll], arg3, arg4); //collision pair: 2,21 : panda_link1_1,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(130ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[21ll], var146[21ll], var147[21ll], var148[21ll], arg3, arg4); //collision pair: 3,21 : panda_link1_2,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(172ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[21ll], var146[21ll], var147[21ll], var148[21ll], arg3, arg4); //collision pair: 4,21 : panda_link1_3,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(214ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[21ll], var146[21ll], var147[21ll], var148[21ll], arg3, arg4); //collision pair: 5,21 : panda_link2_0,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(253ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[21ll], var146[21ll], var147[21ll], var148[21ll], arg3, arg4); //collision pair: 6,21 : panda_link2_1,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(292ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[21ll], var146[21ll], var147[21ll], var148[21ll], arg3, arg4); //collision pair: 7,21 : panda_link2_2,panda_link5_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(331ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[21ll], var146[21ll], var147[21ll], var148[21ll], arg3, arg4); //collision pair: 8,21 : panda_link2_3,panda_link5_4
  var145[22ll] = ((var108[0ll] * 0.00999999977648258f) + (var108[1ll] * 0.0850000008940697f)) + (var108[2ll] * -0.109999999403954f);
  var146[22ll] = ((var108[3ll] * 0.00999999977648258f) + (var108[4ll] * 0.0850000008940697f)) + (var108[5ll] * -0.109999999403954f);
  var147[22ll] = ((var108[6ll] * 0.00999999977648258f) + (var108[7ll] * 0.0850000008940697f)) + (var108[8ll] * -0.109999999403954f);
  var145[22ll] = var145[22ll] + var111[0ll];
  var146[22ll] = var146[22ll] + var111[1ll];
  var147[22ll] = var147[22ll] + var111[2ll];
  var148[22ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(5ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[22ll], var146[22ll], var147[22ll], var148[22ll], arg3, arg4); //collision pair: 0,22 : panda_link0_0,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(47ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[22ll], var146[22ll], var147[22ll], var148[22ll], arg3, arg4); //collision pair: 1,22 : panda_link1_0,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(89ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[22ll], var146[22ll], var147[22ll], var148[22ll], arg3, arg4); //collision pair: 2,22 : panda_link1_1,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(131ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[22ll], var146[22ll], var147[22ll], var148[22ll], arg3, arg4); //collision pair: 3,22 : panda_link1_2,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(173ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[22ll], var146[22ll], var147[22ll], var148[22ll], arg3, arg4); //collision pair: 4,22 : panda_link1_3,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(215ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[22ll], var146[22ll], var147[22ll], var148[22ll], arg3, arg4); //collision pair: 5,22 : panda_link2_0,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(254ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[22ll], var146[22ll], var147[22ll], var148[22ll], arg3, arg4); //collision pair: 6,22 : panda_link2_1,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(293ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[22ll], var146[22ll], var147[22ll], var148[22ll], arg3, arg4); //collision pair: 7,22 : panda_link2_2,panda_link5_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(332ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[22ll], var146[22ll], var147[22ll], var148[22ll], arg3, arg4); //collision pair: 8,22 : panda_link2_3,panda_link5_5
  var145[23ll] = ((var108[0ll] * 0.00999999977648258f) + (var108[1ll] * 0.0900000035762787f)) + (var108[2ll] * -0.0799999982118607f);
  var146[23ll] = ((var108[3ll] * 0.00999999977648258f) + (var108[4ll] * 0.0900000035762787f)) + (var108[5ll] * -0.0799999982118607f);
  var147[23ll] = ((var108[6ll] * 0.00999999977648258f) + (var108[7ll] * 0.0900000035762787f)) + (var108[8ll] * -0.0799999982118607f);
  var145[23ll] = var145[23ll] + var111[0ll];
  var146[23ll] = var146[23ll] + var111[1ll];
  var147[23ll] = var147[23ll] + var111[2ll];
  var148[23ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(6ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[23ll], var146[23ll], var147[23ll], var148[23ll], arg3, arg4); //collision pair: 0,23 : panda_link0_0,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(48ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[23ll], var146[23ll], var147[23ll], var148[23ll], arg3, arg4); //collision pair: 1,23 : panda_link1_0,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(90ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[23ll], var146[23ll], var147[23ll], var148[23ll], arg3, arg4); //collision pair: 2,23 : panda_link1_1,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(132ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[23ll], var146[23ll], var147[23ll], var148[23ll], arg3, arg4); //collision pair: 3,23 : panda_link1_2,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(174ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[23ll], var146[23ll], var147[23ll], var148[23ll], arg3, arg4); //collision pair: 4,23 : panda_link1_3,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(216ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[23ll], var146[23ll], var147[23ll], var148[23ll], arg3, arg4); //collision pair: 5,23 : panda_link2_0,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(255ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[23ll], var146[23ll], var147[23ll], var148[23ll], arg3, arg4); //collision pair: 6,23 : panda_link2_1,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(294ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[23ll], var146[23ll], var147[23ll], var148[23ll], arg3, arg4); //collision pair: 7,23 : panda_link2_2,panda_link5_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(333ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[23ll], var146[23ll], var147[23ll], var148[23ll], arg3, arg4); //collision pair: 8,23 : panda_link2_3,panda_link5_6
  var145[24ll] = ((var108[0ll] * 0.00999999977648258f) + (var108[1ll] * 0.0949999988079071f)) + (var108[2ll] * -0.0500000007450581f);
  var146[24ll] = ((var108[3ll] * 0.00999999977648258f) + (var108[4ll] * 0.0949999988079071f)) + (var108[5ll] * -0.0500000007450581f);
  var147[24ll] = ((var108[6ll] * 0.00999999977648258f) + (var108[7ll] * 0.0949999988079071f)) + (var108[8ll] * -0.0500000007450581f);
  var145[24ll] = var145[24ll] + var111[0ll];
  var146[24ll] = var146[24ll] + var111[1ll];
  var147[24ll] = var147[24ll] + var111[2ll];
  var148[24ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(7ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[24ll], var146[24ll], var147[24ll], var148[24ll], arg3, arg4); //collision pair: 0,24 : panda_link0_0,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(49ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[24ll], var146[24ll], var147[24ll], var148[24ll], arg3, arg4); //collision pair: 1,24 : panda_link1_0,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(91ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[24ll], var146[24ll], var147[24ll], var148[24ll], arg3, arg4); //collision pair: 2,24 : panda_link1_1,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(133ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[24ll], var146[24ll], var147[24ll], var148[24ll], arg3, arg4); //collision pair: 3,24 : panda_link1_2,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(175ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[24ll], var146[24ll], var147[24ll], var148[24ll], arg3, arg4); //collision pair: 4,24 : panda_link1_3,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(217ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[24ll], var146[24ll], var147[24ll], var148[24ll], arg3, arg4); //collision pair: 5,24 : panda_link2_0,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(256ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[24ll], var146[24ll], var147[24ll], var148[24ll], arg3, arg4); //collision pair: 6,24 : panda_link2_1,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(295ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[24ll], var146[24ll], var147[24ll], var148[24ll], arg3, arg4); //collision pair: 7,24 : panda_link2_2,panda_link5_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(334ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[24ll], var146[24ll], var147[24ll], var148[24ll], arg3, arg4); //collision pair: 8,24 : panda_link2_3,panda_link5_7
  var145[25ll] = ((var108[0ll] * -0.00999999977648258f) + (var108[1ll] * 0.0799999982118607f)) + (var108[2ll] * -0.140000000596046f);
  var146[25ll] = ((var108[3ll] * -0.00999999977648258f) + (var108[4ll] * 0.0799999982118607f)) + (var108[5ll] * -0.140000000596046f);
  var147[25ll] = ((var108[6ll] * -0.00999999977648258f) + (var108[7ll] * 0.0799999982118607f)) + (var108[8ll] * -0.140000000596046f);
  var145[25ll] = var145[25ll] + var111[0ll];
  var146[25ll] = var146[25ll] + var111[1ll];
  var147[25ll] = var147[25ll] + var111[2ll];
  var148[25ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(8ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[25ll], var146[25ll], var147[25ll], var148[25ll], arg3, arg4); //collision pair: 0,25 : panda_link0_0,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(50ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[25ll], var146[25ll], var147[25ll], var148[25ll], arg3, arg4); //collision pair: 1,25 : panda_link1_0,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(92ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[25ll], var146[25ll], var147[25ll], var148[25ll], arg3, arg4); //collision pair: 2,25 : panda_link1_1,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(134ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[25ll], var146[25ll], var147[25ll], var148[25ll], arg3, arg4); //collision pair: 3,25 : panda_link1_2,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(176ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[25ll], var146[25ll], var147[25ll], var148[25ll], arg3, arg4); //collision pair: 4,25 : panda_link1_3,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(218ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[25ll], var146[25ll], var147[25ll], var148[25ll], arg3, arg4); //collision pair: 5,25 : panda_link2_0,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(257ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[25ll], var146[25ll], var147[25ll], var148[25ll], arg3, arg4); //collision pair: 6,25 : panda_link2_1,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(296ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[25ll], var146[25ll], var147[25ll], var148[25ll], arg3, arg4); //collision pair: 7,25 : panda_link2_2,panda_link5_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(335ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[25ll], var146[25ll], var147[25ll], var148[25ll], arg3, arg4); //collision pair: 8,25 : panda_link2_3,panda_link5_8
  var145[26ll] = ((var108[0ll] * -0.00999999977648258f) + (var108[1ll] * 0.0850000008940697f)) + (var108[2ll] * -0.109999999403954f);
  var146[26ll] = ((var108[3ll] * -0.00999999977648258f) + (var108[4ll] * 0.0850000008940697f)) + (var108[5ll] * -0.109999999403954f);
  var147[26ll] = ((var108[6ll] * -0.00999999977648258f) + (var108[7ll] * 0.0850000008940697f)) + (var108[8ll] * -0.109999999403954f);
  var145[26ll] = var145[26ll] + var111[0ll];
  var146[26ll] = var146[26ll] + var111[1ll];
  var147[26ll] = var147[26ll] + var111[2ll];
  var148[26ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(9ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[26ll], var146[26ll], var147[26ll], var148[26ll], arg3, arg4); //collision pair: 0,26 : panda_link0_0,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(51ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[26ll], var146[26ll], var147[26ll], var148[26ll], arg3, arg4); //collision pair: 1,26 : panda_link1_0,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(93ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[26ll], var146[26ll], var147[26ll], var148[26ll], arg3, arg4); //collision pair: 2,26 : panda_link1_1,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(135ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[26ll], var146[26ll], var147[26ll], var148[26ll], arg3, arg4); //collision pair: 3,26 : panda_link1_2,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(177ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[26ll], var146[26ll], var147[26ll], var148[26ll], arg3, arg4); //collision pair: 4,26 : panda_link1_3,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(219ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[26ll], var146[26ll], var147[26ll], var148[26ll], arg3, arg4); //collision pair: 5,26 : panda_link2_0,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(258ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[26ll], var146[26ll], var147[26ll], var148[26ll], arg3, arg4); //collision pair: 6,26 : panda_link2_1,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(297ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[26ll], var146[26ll], var147[26ll], var148[26ll], arg3, arg4); //collision pair: 7,26 : panda_link2_2,panda_link5_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(336ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[26ll], var146[26ll], var147[26ll], var148[26ll], arg3, arg4); //collision pair: 8,26 : panda_link2_3,panda_link5_9
  var145[27ll] = ((var108[0ll] * -0.00999999977648258f) + (var108[1ll] * 0.0900000035762787f)) + (var108[2ll] * -0.0799999982118607f);
  var146[27ll] = ((var108[3ll] * -0.00999999977648258f) + (var108[4ll] * 0.0900000035762787f)) + (var108[5ll] * -0.0799999982118607f);
  var147[27ll] = ((var108[6ll] * -0.00999999977648258f) + (var108[7ll] * 0.0900000035762787f)) + (var108[8ll] * -0.0799999982118607f);
  var145[27ll] = var145[27ll] + var111[0ll];
  var146[27ll] = var146[27ll] + var111[1ll];
  var147[27ll] = var147[27ll] + var111[2ll];
  var148[27ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(10ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[27ll], var146[27ll], var147[27ll], var148[27ll], arg3, arg4); //collision pair: 0,27 : panda_link0_0,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(52ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[27ll], var146[27ll], var147[27ll], var148[27ll], arg3, arg4); //collision pair: 1,27 : panda_link1_0,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(94ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[27ll], var146[27ll], var147[27ll], var148[27ll], arg3, arg4); //collision pair: 2,27 : panda_link1_1,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(136ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[27ll], var146[27ll], var147[27ll], var148[27ll], arg3, arg4); //collision pair: 3,27 : panda_link1_2,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(178ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[27ll], var146[27ll], var147[27ll], var148[27ll], arg3, arg4); //collision pair: 4,27 : panda_link1_3,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(220ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[27ll], var146[27ll], var147[27ll], var148[27ll], arg3, arg4); //collision pair: 5,27 : panda_link2_0,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(259ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[27ll], var146[27ll], var147[27ll], var148[27ll], arg3, arg4); //collision pair: 6,27 : panda_link2_1,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(298ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[27ll], var146[27ll], var147[27ll], var148[27ll], arg3, arg4); //collision pair: 7,27 : panda_link2_2,panda_link5_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(337ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[27ll], var146[27ll], var147[27ll], var148[27ll], arg3, arg4); //collision pair: 8,27 : panda_link2_3,panda_link5_10
  var145[28ll] = ((var108[0ll] * -0.00999999977648258f) + (var108[1ll] * 0.0949999988079071f)) + (var108[2ll] * -0.0500000007450581f);
  var146[28ll] = ((var108[3ll] * -0.00999999977648258f) + (var108[4ll] * 0.0949999988079071f)) + (var108[5ll] * -0.0500000007450581f);
  var147[28ll] = ((var108[6ll] * -0.00999999977648258f) + (var108[7ll] * 0.0949999988079071f)) + (var108[8ll] * -0.0500000007450581f);
  var145[28ll] = var145[28ll] + var111[0ll];
  var146[28ll] = var146[28ll] + var111[1ll];
  var147[28ll] = var147[28ll] + var111[2ll];
  var148[28ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(11ll, var137, var142, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[28ll], var146[28ll], var147[28ll], var148[28ll], arg3, arg4); //collision pair: 0,28 : panda_link0_0,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(53ll, var138, var142, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[28ll], var146[28ll], var147[28ll], var148[28ll], arg3, arg4); //collision pair: 1,28 : panda_link1_0,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(95ll, var138, var142, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[28ll], var146[28ll], var147[28ll], var148[28ll], arg3, arg4); //collision pair: 2,28 : panda_link1_1,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(137ll, var138, var142, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[28ll], var146[28ll], var147[28ll], var148[28ll], arg3, arg4); //collision pair: 3,28 : panda_link1_2,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(179ll, var138, var142, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[28ll], var146[28ll], var147[28ll], var148[28ll], arg3, arg4); //collision pair: 4,28 : panda_link1_3,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(221ll, var139, var142, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[28ll], var146[28ll], var147[28ll], var148[28ll], arg3, arg4); //collision pair: 5,28 : panda_link2_0,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(260ll, var139, var142, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[28ll], var146[28ll], var147[28ll], var148[28ll], arg3, arg4); //collision pair: 6,28 : panda_link2_1,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(299ll, var139, var142, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[28ll], var146[28ll], var147[28ll], var148[28ll], arg3, arg4); //collision pair: 7,28 : panda_link2_2,panda_link5_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(338ll, var139, var142, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[28ll], var146[28ll], var147[28ll], var148[28ll], arg3, arg4); //collision pair: 8,28 : panda_link2_3,panda_link5_11
  blaze::StaticVector<float, 8> var430 = arg2[5ll];
  var74 = sin(var430);
  var75 = cos(var430);
  var73[0ll] = var75;
  var73[1ll] = -(var74);
  var73[2ll] = var74;
  var73[3ll] = var75;
  blaze::StaticVector<float, 8> var431;
  var431 = 0;
  var431 = var431 + (1.0f * var73[0ll]);
  var149[0ll] = var431;
  blaze::StaticVector<float, 8> var432;
  var432 = 0;
  var432 = var432 + (1.0f * var73[1ll]);
  var149[1ll] = var432;
  blaze::StaticVector<float, 8> var433;
  var433 = 0;
  var433 = var433 + (1.0f * var73[2ll]);
  var149[2ll] = var433;
  blaze::StaticVector<float, 8> var434;
  var434 = 0;
  var434 = var434 + (1.0f * var73[3ll]);
  var149[3ll] = var434;
  blaze::StaticVector<float, 8> var435;
  var435 = 0;
  var435 = var435 + (1.0f * 1.0f);
  var153 = var435;
  blaze::StaticVector<float, 8> var436;
  var436 = 0;
  var436 = var436 + (var108[0ll] * var149[0ll]);
  var436 = var436 + (var108[2ll] * var149[2ll]);
  var113[0ll] = var436;
  blaze::StaticVector<float, 8> var437;
  var437 = 0;
  var437 = var437 + (var108[0ll] * var149[1ll]);
  var437 = var437 + (var108[2ll] * var149[3ll]);
  var113[1ll] = var437;
  blaze::StaticVector<float, 8> var438;
  var438 = 0;
  var438 = var438 + (var108[1ll] * -1.0f);
  var113[2ll] = var438;
  blaze::StaticVector<float, 8> var439;
  var439 = 0;
  var439 = var439 + (var108[3ll] * var149[0ll]);
  var439 = var439 + (var108[5ll] * var149[2ll]);
  var113[3ll] = var439;
  blaze::StaticVector<float, 8> var440;
  var440 = 0;
  var440 = var440 + (var108[3ll] * var149[1ll]);
  var440 = var440 + (var108[5ll] * var149[3ll]);
  var113[4ll] = var440;
  blaze::StaticVector<float, 8> var441;
  var441 = 0;
  var441 = var441 + (var108[4ll] * -1.0f);
  var113[5ll] = var441;
  blaze::StaticVector<float, 8> var442;
  var442 = 0;
  var442 = var442 + (var108[6ll] * var149[0ll]);
  var442 = var442 + (var108[8ll] * var149[2ll]);
  var113[6ll] = var442;
  blaze::StaticVector<float, 8> var443;
  var443 = 0;
  var443 = var443 + (var108[6ll] * var149[1ll]);
  var443 = var443 + (var108[8ll] * var149[3ll]);
  var113[7ll] = var443;
  blaze::StaticVector<float, 8> var444;
  var444 = 0;
  var444 = var444 + (var108[7ll] * -1.0f);
  var113[8ll] = var444;
  blaze::StaticVector<float, 8> var445;
  var445 = 0;
  var445 = var445 + (var111[0ll] * var153);
  var116[0ll] = var445;
  blaze::StaticVector<float, 8> var446;
  var446 = 0;
  var446 = var446 + (var111[1ll] * var153);
  var116[1ll] = var446;
  blaze::StaticVector<float, 8> var447;
  var447 = 0;
  var447 = var447 + (var111[2ll] * var153);
  var116[2ll] = var447;
  blaze::StaticVector<float, 8> var448;
  var448 = 0;
  var448 = var448 + (var112 * var153);
  var117 = var448;
  var131[0ll] = var88[0ll];
  var131[1ll] = var88[1ll];
  var131[2ll] = var88[2ll];
  var131[3ll] = var88[3ll];
  blaze::StaticVector<float, 8> var449;
  var449 = 0;
  var449 = var449 + (-0.333000004291534f * var131[2ll]);
  var135[0ll] = var449;
  blaze::StaticVector<float, 8> var450;
  var450 = 0;
  var450 = var450 + (-0.333000004291534f * var131[3ll]);
  var135[1ll] = var450;
  blaze::StaticVector<float, 8> var451;
  var451 = 0;
  var451 = var451 + (0.333000004291534f * var131[0ll]);
  var135[2ll] = var451;
  blaze::StaticVector<float, 8> var452;
  var452 = 0;
  var452 = var452 + (0.333000004291534f * var131[1ll]);
  var135[3ll] = var452;
  blaze::StaticVector<float, 8> var453;
  var453 = 0;
  var136[0ll] = var453;
  blaze::StaticVector<float, 8> var454;
  var454 = 0;
  var136[1ll] = var454;
  blaze::StaticVector<float, 8> var455;
  var455 = 0;
  var455 = var455 + (1.0f * 1.0f);
  var136[2ll] = var455;
  blaze::StaticVector<float, 8> var456;
  var456 = 0;
  var136[3ll] = var456;
  blaze::StaticVector<float, 8> var457;
  var457 = 0;
  var136[4ll] = var457;
  blaze::StaticVector<float, 8> var458;
  var458 = 0;
  var136[5ll] = var458;
  var143(0ll, 0ll) = var136[0ll];
  var143(1ll, 0ll) = var136[1ll];
  var143(2ll, 0ll) = var136[2ll];
  var143(3ll, 0ll) = var136[3ll];
  var143(4ll, 0ll) = var136[4ll];
  var143(5ll, 0ll) = var136[5ll];
  var131[0ll] = var93[0ll];
  var131[1ll] = var93[1ll];
  var131[4ll] = var93[2ll];
  var131[2ll] = var93[3ll];
  var131[3ll] = var93[4ll];
  var131[5ll] = var93[5ll];
  var131[6ll] = var93[6ll];
  var131[7ll] = var93[7ll];
  var134[0ll] = -(var96[0ll]);
  var134[1ll] = var96[0ll];
  blaze::StaticVector<float, 8> var459;
  var459 = 0;
  var459 = var459 + (var134[0ll] * var131[2ll]);
  var135[0ll] = var459;
  blaze::StaticVector<float, 8> var460;
  var460 = 0;
  var460 = var460 + (var134[0ll] * var131[3ll]);
  var135[1ll] = var460;
  blaze::StaticVector<float, 8> var461;
  var461 = 0;
  var461 = var461 + (var134[0ll] * var131[5ll]);
  var135[4ll] = var461;
  blaze::StaticVector<float, 8> var462;
  var462 = 0;
  var462 = var462 + (var134[1ll] * var131[0ll]);
  var135[2ll] = var462;
  blaze::StaticVector<float, 8> var463;
  var463 = 0;
  var463 = var463 + (var134[1ll] * var131[1ll]);
  var135[3ll] = var463;
  blaze::StaticVector<float, 8> var464;
  var464 = 0;
  var464 = var464 + (var134[1ll] * var131[4ll]);
  var135[5ll] = var464;
  blaze::StaticVector<float, 8> var465;
  var465 = 0;
  var465 = var465 + (var131[4ll] * 1.0f);
  var136[0ll] = var465;
  blaze::StaticVector<float, 8> var466;
  var466 = 0;
  var466 = var466 + (var131[5ll] * 1.0f);
  var136[1ll] = var466;
  blaze::StaticVector<float, 8> var467;
  var467 = 0;
  var136[2ll] = var467;
  blaze::StaticVector<float, 8> var468;
  var468 = 0;
  var468 = var468 + (var135[4ll] * 1.0f);
  var136[3ll] = var468;
  blaze::StaticVector<float, 8> var469;
  var469 = 0;
  var469 = var469 + (var135[5ll] * 1.0f);
  var136[4ll] = var469;
  blaze::StaticVector<float, 8> var470;
  var470 = 0;
  var136[5ll] = var470;
  var143(0ll, 1ll) = var136[0ll];
  var143(1ll, 1ll) = var136[1ll];
  var143(2ll, 1ll) = var136[2ll];
  var143(3ll, 1ll) = var136[3ll];
  var143(4ll, 1ll) = var136[4ll];
  var143(5ll, 1ll) = var136[5ll];
  var131[0ll] = var98[0ll];
  var131[1ll] = var98[1ll];
  var131[4ll] = var98[2ll];
  var131[2ll] = var98[3ll];
  var131[3ll] = var98[4ll];
  var131[5ll] = var98[5ll];
  var131[6ll] = var98[6ll];
  var131[7ll] = var98[7ll];
  var131[8ll] = var98[8ll];
  var134[2ll] = -(var101[0ll]);
  var134[3ll] = var101[0ll];
  var134[4ll] = -(var101[1ll]);
  var134[5ll] = var101[1ll];
  var134[0ll] = -(var101[2ll]);
  var134[1ll] = var101[2ll];
  blaze::StaticVector<float, 8> var471;
  var471 = 0;
  var471 = var471 + (var134[0ll] * var131[2ll]);
  var471 = var471 + (var134[5ll] * var131[6ll]);
  var135[0ll] = var471;
  blaze::StaticVector<float, 8> var472;
  var472 = 0;
  var472 = var472 + (var134[0ll] * var131[3ll]);
  var472 = var472 + (var134[5ll] * var131[7ll]);
  var135[1ll] = var472;
  blaze::StaticVector<float, 8> var473;
  var473 = 0;
  var473 = var473 + (var134[0ll] * var131[5ll]);
  var473 = var473 + (var134[5ll] * var131[8ll]);
  var135[4ll] = var473;
  blaze::StaticVector<float, 8> var474;
  var474 = 0;
  var474 = var474 + (var134[1ll] * var131[0ll]);
  var474 = var474 + (var134[2ll] * var131[6ll]);
  var135[2ll] = var474;
  blaze::StaticVector<float, 8> var475;
  var475 = 0;
  var475 = var475 + (var134[1ll] * var131[1ll]);
  var475 = var475 + (var134[2ll] * var131[7ll]);
  var135[3ll] = var475;
  blaze::StaticVector<float, 8> var476;
  var476 = 0;
  var476 = var476 + (var134[1ll] * var131[4ll]);
  var476 = var476 + (var134[2ll] * var131[8ll]);
  var135[5ll] = var476;
  blaze::StaticVector<float, 8> var477;
  var477 = 0;
  var477 = var477 + (var134[4ll] * var131[0ll]);
  var477 = var477 + (var134[3ll] * var131[2ll]);
  var135[6ll] = var477;
  blaze::StaticVector<float, 8> var478;
  var478 = 0;
  var478 = var478 + (var134[4ll] * var131[1ll]);
  var478 = var478 + (var134[3ll] * var131[3ll]);
  var135[7ll] = var478;
  blaze::StaticVector<float, 8> var479;
  var479 = 0;
  var479 = var479 + (var134[4ll] * var131[4ll]);
  var479 = var479 + (var134[3ll] * var131[5ll]);
  var135[8ll] = var479;
  blaze::StaticVector<float, 8> var480;
  var480 = 0;
  var480 = var480 + (var131[4ll] * 1.0f);
  var136[0ll] = var480;
  blaze::StaticVector<float, 8> var481;
  var481 = 0;
  var481 = var481 + (var131[5ll] * 1.0f);
  var136[1ll] = var481;
  blaze::StaticVector<float, 8> var482;
  var482 = 0;
  var482 = var482 + (var131[8ll] * 1.0f);
  var136[2ll] = var482;
  blaze::StaticVector<float, 8> var483;
  var483 = 0;
  var483 = var483 + (var135[4ll] * 1.0f);
  var136[3ll] = var483;
  blaze::StaticVector<float, 8> var484;
  var484 = 0;
  var484 = var484 + (var135[5ll] * 1.0f);
  var136[4ll] = var484;
  blaze::StaticVector<float, 8> var485;
  var485 = 0;
  var485 = var485 + (var135[8ll] * 1.0f);
  var136[5ll] = var485;
  var143(0ll, 2ll) = var136[0ll];
  var143(1ll, 2ll) = var136[1ll];
  var143(2ll, 2ll) = var136[2ll];
  var143(3ll, 2ll) = var136[3ll];
  var143(4ll, 2ll) = var136[4ll];
  var143(5ll, 2ll) = var136[5ll];
  var131[0ll] = var103[0ll];
  var131[1ll] = var103[1ll];
  var131[4ll] = var103[2ll];
  var131[2ll] = var103[3ll];
  var131[3ll] = var103[4ll];
  var131[5ll] = var103[5ll];
  var131[6ll] = var103[6ll];
  var131[7ll] = var103[7ll];
  var131[8ll] = var103[8ll];
  var134[2ll] = -(var106[0ll]);
  var134[3ll] = var106[0ll];
  var134[4ll] = -(var106[1ll]);
  var134[5ll] = var106[1ll];
  var134[0ll] = -(var106[2ll]);
  var134[1ll] = var106[2ll];
  blaze::StaticVector<float, 8> var486;
  var486 = 0;
  var486 = var486 + (var134[0ll] * var131[2ll]);
  var486 = var486 + (var134[5ll] * var131[6ll]);
  var135[0ll] = var486;
  blaze::StaticVector<float, 8> var487;
  var487 = 0;
  var487 = var487 + (var134[0ll] * var131[3ll]);
  var487 = var487 + (var134[5ll] * var131[7ll]);
  var135[1ll] = var487;
  blaze::StaticVector<float, 8> var488;
  var488 = 0;
  var488 = var488 + (var134[0ll] * var131[5ll]);
  var488 = var488 + (var134[5ll] * var131[8ll]);
  var135[4ll] = var488;
  blaze::StaticVector<float, 8> var489;
  var489 = 0;
  var489 = var489 + (var134[1ll] * var131[0ll]);
  var489 = var489 + (var134[2ll] * var131[6ll]);
  var135[2ll] = var489;
  blaze::StaticVector<float, 8> var490;
  var490 = 0;
  var490 = var490 + (var134[1ll] * var131[1ll]);
  var490 = var490 + (var134[2ll] * var131[7ll]);
  var135[3ll] = var490;
  blaze::StaticVector<float, 8> var491;
  var491 = 0;
  var491 = var491 + (var134[1ll] * var131[4ll]);
  var491 = var491 + (var134[2ll] * var131[8ll]);
  var135[5ll] = var491;
  blaze::StaticVector<float, 8> var492;
  var492 = 0;
  var492 = var492 + (var134[4ll] * var131[0ll]);
  var492 = var492 + (var134[3ll] * var131[2ll]);
  var135[6ll] = var492;
  blaze::StaticVector<float, 8> var493;
  var493 = 0;
  var493 = var493 + (var134[4ll] * var131[1ll]);
  var493 = var493 + (var134[3ll] * var131[3ll]);
  var135[7ll] = var493;
  blaze::StaticVector<float, 8> var494;
  var494 = 0;
  var494 = var494 + (var134[4ll] * var131[4ll]);
  var494 = var494 + (var134[3ll] * var131[5ll]);
  var135[8ll] = var494;
  blaze::StaticVector<float, 8> var495;
  var495 = 0;
  var495 = var495 + (var131[4ll] * 1.0f);
  var136[0ll] = var495;
  blaze::StaticVector<float, 8> var496;
  var496 = 0;
  var496 = var496 + (var131[5ll] * 1.0f);
  var136[1ll] = var496;
  blaze::StaticVector<float, 8> var497;
  var497 = 0;
  var497 = var497 + (var131[8ll] * 1.0f);
  var136[2ll] = var497;
  blaze::StaticVector<float, 8> var498;
  var498 = 0;
  var498 = var498 + (var135[4ll] * 1.0f);
  var136[3ll] = var498;
  blaze::StaticVector<float, 8> var499;
  var499 = 0;
  var499 = var499 + (var135[5ll] * 1.0f);
  var136[4ll] = var499;
  blaze::StaticVector<float, 8> var500;
  var500 = 0;
  var500 = var500 + (var135[8ll] * 1.0f);
  var136[5ll] = var500;
  var143(0ll, 3ll) = var136[0ll];
  var143(1ll, 3ll) = var136[1ll];
  var143(2ll, 3ll) = var136[2ll];
  var143(3ll, 3ll) = var136[3ll];
  var143(4ll, 3ll) = var136[4ll];
  var143(5ll, 3ll) = var136[5ll];
  var131[0ll] = var108[0ll];
  var131[1ll] = var108[1ll];
  var131[4ll] = var108[2ll];
  var131[2ll] = var108[3ll];
  var131[3ll] = var108[4ll];
  var131[5ll] = var108[5ll];
  var131[6ll] = var108[6ll];
  var131[7ll] = var108[7ll];
  var131[8ll] = var108[8ll];
  var134[2ll] = -(var111[0ll]);
  var134[3ll] = var111[0ll];
  var134[4ll] = -(var111[1ll]);
  var134[5ll] = var111[1ll];
  var134[0ll] = -(var111[2ll]);
  var134[1ll] = var111[2ll];
  blaze::StaticVector<float, 8> var501;
  var501 = 0;
  var501 = var501 + (var134[0ll] * var131[2ll]);
  var501 = var501 + (var134[5ll] * var131[6ll]);
  var135[0ll] = var501;
  blaze::StaticVector<float, 8> var502;
  var502 = 0;
  var502 = var502 + (var134[0ll] * var131[3ll]);
  var502 = var502 + (var134[5ll] * var131[7ll]);
  var135[1ll] = var502;
  blaze::StaticVector<float, 8> var503;
  var503 = 0;
  var503 = var503 + (var134[0ll] * var131[5ll]);
  var503 = var503 + (var134[5ll] * var131[8ll]);
  var135[4ll] = var503;
  blaze::StaticVector<float, 8> var504;
  var504 = 0;
  var504 = var504 + (var134[1ll] * var131[0ll]);
  var504 = var504 + (var134[2ll] * var131[6ll]);
  var135[2ll] = var504;
  blaze::StaticVector<float, 8> var505;
  var505 = 0;
  var505 = var505 + (var134[1ll] * var131[1ll]);
  var505 = var505 + (var134[2ll] * var131[7ll]);
  var135[3ll] = var505;
  blaze::StaticVector<float, 8> var506;
  var506 = 0;
  var506 = var506 + (var134[1ll] * var131[4ll]);
  var506 = var506 + (var134[2ll] * var131[8ll]);
  var135[5ll] = var506;
  blaze::StaticVector<float, 8> var507;
  var507 = 0;
  var507 = var507 + (var134[4ll] * var131[0ll]);
  var507 = var507 + (var134[3ll] * var131[2ll]);
  var135[6ll] = var507;
  blaze::StaticVector<float, 8> var508;
  var508 = 0;
  var508 = var508 + (var134[4ll] * var131[1ll]);
  var508 = var508 + (var134[3ll] * var131[3ll]);
  var135[7ll] = var508;
  blaze::StaticVector<float, 8> var509;
  var509 = 0;
  var509 = var509 + (var134[4ll] * var131[4ll]);
  var509 = var509 + (var134[3ll] * var131[5ll]);
  var135[8ll] = var509;
  blaze::StaticVector<float, 8> var510;
  var510 = 0;
  var510 = var510 + (var131[4ll] * 1.0f);
  var136[0ll] = var510;
  blaze::StaticVector<float, 8> var511;
  var511 = 0;
  var511 = var511 + (var131[5ll] * 1.0f);
  var136[1ll] = var511;
  blaze::StaticVector<float, 8> var512;
  var512 = 0;
  var512 = var512 + (var131[8ll] * 1.0f);
  var136[2ll] = var512;
  blaze::StaticVector<float, 8> var513;
  var513 = 0;
  var513 = var513 + (var135[4ll] * 1.0f);
  var136[3ll] = var513;
  blaze::StaticVector<float, 8> var514;
  var514 = 0;
  var514 = var514 + (var135[5ll] * 1.0f);
  var136[4ll] = var514;
  blaze::StaticVector<float, 8> var515;
  var515 = 0;
  var515 = var515 + (var135[8ll] * 1.0f);
  var136[5ll] = var515;
  var143(0ll, 4ll) = var136[0ll];
  var143(1ll, 4ll) = var136[1ll];
  var143(2ll, 4ll) = var136[2ll];
  var143(3ll, 4ll) = var136[3ll];
  var143(4ll, 4ll) = var136[4ll];
  var143(5ll, 4ll) = var136[5ll];
  var131[0ll] = var113[0ll];
  var131[1ll] = var113[1ll];
  var131[4ll] = var113[2ll];
  var131[2ll] = var113[3ll];
  var131[3ll] = var113[4ll];
  var131[5ll] = var113[5ll];
  var131[6ll] = var113[6ll];
  var131[7ll] = var113[7ll];
  var131[8ll] = var113[8ll];
  var134[2ll] = -(var116[0ll]);
  var134[3ll] = var116[0ll];
  var134[4ll] = -(var116[1ll]);
  var134[5ll] = var116[1ll];
  var134[0ll] = -(var116[2ll]);
  var134[1ll] = var116[2ll];
  blaze::StaticVector<float, 8> var516;
  var516 = 0;
  var516 = var516 + (var134[0ll] * var131[2ll]);
  var516 = var516 + (var134[5ll] * var131[6ll]);
  var135[0ll] = var516;
  blaze::StaticVector<float, 8> var517;
  var517 = 0;
  var517 = var517 + (var134[0ll] * var131[3ll]);
  var517 = var517 + (var134[5ll] * var131[7ll]);
  var135[1ll] = var517;
  blaze::StaticVector<float, 8> var518;
  var518 = 0;
  var518 = var518 + (var134[0ll] * var131[5ll]);
  var518 = var518 + (var134[5ll] * var131[8ll]);
  var135[4ll] = var518;
  blaze::StaticVector<float, 8> var519;
  var519 = 0;
  var519 = var519 + (var134[1ll] * var131[0ll]);
  var519 = var519 + (var134[2ll] * var131[6ll]);
  var135[2ll] = var519;
  blaze::StaticVector<float, 8> var520;
  var520 = 0;
  var520 = var520 + (var134[1ll] * var131[1ll]);
  var520 = var520 + (var134[2ll] * var131[7ll]);
  var135[3ll] = var520;
  blaze::StaticVector<float, 8> var521;
  var521 = 0;
  var521 = var521 + (var134[1ll] * var131[4ll]);
  var521 = var521 + (var134[2ll] * var131[8ll]);
  var135[5ll] = var521;
  blaze::StaticVector<float, 8> var522;
  var522 = 0;
  var522 = var522 + (var134[4ll] * var131[0ll]);
  var522 = var522 + (var134[3ll] * var131[2ll]);
  var135[6ll] = var522;
  blaze::StaticVector<float, 8> var523;
  var523 = 0;
  var523 = var523 + (var134[4ll] * var131[1ll]);
  var523 = var523 + (var134[3ll] * var131[3ll]);
  var135[7ll] = var523;
  blaze::StaticVector<float, 8> var524;
  var524 = 0;
  var524 = var524 + (var134[4ll] * var131[4ll]);
  var524 = var524 + (var134[3ll] * var131[5ll]);
  var135[8ll] = var524;
  blaze::StaticVector<float, 8> var525;
  var525 = 0;
  var525 = var525 + (var131[4ll] * 1.0f);
  var136[0ll] = var525;
  blaze::StaticVector<float, 8> var526;
  var526 = 0;
  var526 = var526 + (var131[5ll] * 1.0f);
  var136[1ll] = var526;
  blaze::StaticVector<float, 8> var527;
  var527 = 0;
  var527 = var527 + (var131[8ll] * 1.0f);
  var136[2ll] = var527;
  blaze::StaticVector<float, 8> var528;
  var528 = 0;
  var528 = var528 + (var135[4ll] * 1.0f);
  var136[3ll] = var528;
  blaze::StaticVector<float, 8> var529;
  var529 = 0;
  var529 = var529 + (var135[5ll] * 1.0f);
  var136[4ll] = var529;
  blaze::StaticVector<float, 8> var530;
  var530 = 0;
  var530 = var530 + (var135[8ll] * 1.0f);
  var136[5ll] = var530;
  var143(0ll, 5ll) = var136[0ll];
  var143(1ll, 5ll) = var136[1ll];
  var143(2ll, 5ll) = var136[2ll];
  var143(3ll, 5ll) = var136[3ll];
  var143(4ll, 5ll) = var136[4ll];
  var143(5ll, 5ll) = var136[5ll];
  var145[29ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0f)) + (var113[2ll] * 0.0f);
  var146[29ll] = ((var113[3ll] * 0.0f) + (var113[4ll] * 0.0f)) + (var113[5ll] * 0.0f);
  var147[29ll] = ((var113[6ll] * 0.0f) + (var113[7ll] * 0.0f)) + (var113[8ll] * 0.0f);
  var145[29ll] = var145[29ll] + var116[0ll];
  var146[29ll] = var146[29ll] + var116[1ll];
  var147[29ll] = var147[29ll] + var116[2ll];
  var148[29ll] = 0.0500000007450581f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(12ll, var137, var143, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[29ll], var146[29ll], var147[29ll], var148[29ll], arg3, arg4); //collision pair: 0,29 : panda_link0_0,panda_link6_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(54ll, var138, var143, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[29ll], var146[29ll], var147[29ll], var148[29ll], arg3, arg4); //collision pair: 1,29 : panda_link1_0,panda_link6_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(96ll, var138, var143, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[29ll], var146[29ll], var147[29ll], var148[29ll], arg3, arg4); //collision pair: 2,29 : panda_link1_1,panda_link6_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(138ll, var138, var143, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[29ll], var146[29ll], var147[29ll], var148[29ll], arg3, arg4); //collision pair: 3,29 : panda_link1_2,panda_link6_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(180ll, var138, var143, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[29ll], var146[29ll], var147[29ll], var148[29ll], arg3, arg4); //collision pair: 4,29 : panda_link1_3,panda_link6_0
  var145[30ll] = ((var113[0ll] * 0.0799999982118607f) + (var113[1ll] * -0.00999999977648258f)) + (var113[2ll] * 0.0f);
  var146[30ll] = ((var113[3ll] * 0.0799999982118607f) + (var113[4ll] * -0.00999999977648258f)) + (var113[5ll] * 0.0f);
  var147[30ll] = ((var113[6ll] * 0.0799999982118607f) + (var113[7ll] * -0.00999999977648258f)) + (var113[8ll] * 0.0f);
  var145[30ll] = var145[30ll] + var116[0ll];
  var146[30ll] = var146[30ll] + var116[1ll];
  var147[30ll] = var147[30ll] + var116[2ll];
  var148[30ll] = 0.0500000007450581f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(13ll, var137, var143, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[30ll], var146[30ll], var147[30ll], var148[30ll], arg3, arg4); //collision pair: 0,30 : panda_link0_0,panda_link6_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(55ll, var138, var143, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[30ll], var146[30ll], var147[30ll], var148[30ll], arg3, arg4); //collision pair: 1,30 : panda_link1_0,panda_link6_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(97ll, var138, var143, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[30ll], var146[30ll], var147[30ll], var148[30ll], arg3, arg4); //collision pair: 2,30 : panda_link1_1,panda_link6_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(139ll, var138, var143, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[30ll], var146[30ll], var147[30ll], var148[30ll], arg3, arg4); //collision pair: 3,30 : panda_link1_2,panda_link6_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(181ll, var138, var143, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[30ll], var146[30ll], var147[30ll], var148[30ll], arg3, arg4); //collision pair: 4,30 : panda_link1_3,panda_link6_1
  var145[31ll] = ((var113[0ll] * 0.0799999982118607f) + (var113[1ll] * 0.0350000001490116f)) + (var113[2ll] * 0.0f);
  var146[31ll] = ((var113[3ll] * 0.0799999982118607f) + (var113[4ll] * 0.0350000001490116f)) + (var113[5ll] * 0.0f);
  var147[31ll] = ((var113[6ll] * 0.0799999982118607f) + (var113[7ll] * 0.0350000001490116f)) + (var113[8ll] * 0.0f);
  var145[31ll] = var145[31ll] + var116[0ll];
  var146[31ll] = var146[31ll] + var116[1ll];
  var147[31ll] = var147[31ll] + var116[2ll];
  var148[31ll] = 0.0520000010728836f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(14ll, var137, var143, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[31ll], var146[31ll], var147[31ll], var148[31ll], arg3, arg4); //collision pair: 0,31 : panda_link0_0,panda_link6_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(56ll, var138, var143, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[31ll], var146[31ll], var147[31ll], var148[31ll], arg3, arg4); //collision pair: 1,31 : panda_link1_0,panda_link6_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(98ll, var138, var143, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[31ll], var146[31ll], var147[31ll], var148[31ll], arg3, arg4); //collision pair: 2,31 : panda_link1_1,panda_link6_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(140ll, var138, var143, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[31ll], var146[31ll], var147[31ll], var148[31ll], arg3, arg4); //collision pair: 3,31 : panda_link1_2,panda_link6_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(182ll, var138, var143, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[31ll], var146[31ll], var147[31ll], var148[31ll], arg3, arg4); //collision pair: 4,31 : panda_link1_3,panda_link6_2
  blaze::StaticVector<float, 8> var531 = arg2[6ll];
  var79 = sin(var531);
  var80 = cos(var531);
  var78[0ll] = var80;
  var78[1ll] = -(var79);
  var78[2ll] = var79;
  var78[3ll] = var80;
  blaze::StaticVector<float, 8> var532;
  var532 = 0;
  var532 = var532 + (1.0f * var78[0ll]);
  var149[0ll] = var532;
  blaze::StaticVector<float, 8> var533;
  var533 = 0;
  var533 = var533 + (1.0f * var78[1ll]);
  var149[1ll] = var533;
  blaze::StaticVector<float, 8> var534;
  var534 = 0;
  var534 = var534 + (1.0f * var78[2ll]);
  var149[2ll] = var534;
  blaze::StaticVector<float, 8> var535;
  var535 = 0;
  var535 = var535 + (1.0f * var78[3ll]);
  var149[3ll] = var535;
  blaze::StaticVector<float, 8> var536;
  var536 = 0;
  var536 = var536 + (1.0f * 1.0f);
  var153 = var536;
  blaze::StaticVector<float, 8> var537;
  var537 = 0;
  var537 = var537 + (var113[0ll] * var149[0ll]);
  var537 = var537 + (var113[2ll] * var149[2ll]);
  var118[0ll] = var537;
  blaze::StaticVector<float, 8> var538;
  var538 = 0;
  var538 = var538 + (var113[0ll] * var149[1ll]);
  var538 = var538 + (var113[2ll] * var149[3ll]);
  var118[1ll] = var538;
  blaze::StaticVector<float, 8> var539;
  var539 = 0;
  var539 = var539 + (var113[1ll] * -1.0f);
  var118[2ll] = var539;
  blaze::StaticVector<float, 8> var540;
  var540 = 0;
  var540 = var540 + (var113[3ll] * var149[0ll]);
  var540 = var540 + (var113[5ll] * var149[2ll]);
  var118[3ll] = var540;
  blaze::StaticVector<float, 8> var541;
  var541 = 0;
  var541 = var541 + (var113[3ll] * var149[1ll]);
  var541 = var541 + (var113[5ll] * var149[3ll]);
  var118[4ll] = var541;
  blaze::StaticVector<float, 8> var542;
  var542 = 0;
  var542 = var542 + (var113[4ll] * -1.0f);
  var118[5ll] = var542;
  blaze::StaticVector<float, 8> var543;
  var543 = 0;
  var543 = var543 + (var113[6ll] * var149[0ll]);
  var543 = var543 + (var113[8ll] * var149[2ll]);
  var118[6ll] = var543;
  blaze::StaticVector<float, 8> var544;
  var544 = 0;
  var544 = var544 + (var113[6ll] * var149[1ll]);
  var544 = var544 + (var113[8ll] * var149[3ll]);
  var118[7ll] = var544;
  blaze::StaticVector<float, 8> var545;
  var545 = 0;
  var545 = var545 + (var113[7ll] * -1.0f);
  var118[8ll] = var545;
  blaze::StaticVector<float, 8> var546;
  var546 = 0;
  var546 = var546 + (var116[0ll] * var153);
  blaze::StaticVector<float, 8> var547;
  var547 = 0;
  var547 = var547 + (var113[0ll] * 0.0879999995231628f);
  var121[0ll] = var547 + var546;
  blaze::StaticVector<float, 8> var548;
  var548 = 0;
  var548 = var548 + (var116[1ll] * var153);
  blaze::StaticVector<float, 8> var549;
  var549 = 0;
  var549 = var549 + (var113[3ll] * 0.0879999995231628f);
  var121[1ll] = var549 + var548;
  blaze::StaticVector<float, 8> var550;
  var550 = 0;
  var550 = var550 + (var116[2ll] * var153);
  blaze::StaticVector<float, 8> var551;
  var551 = 0;
  var551 = var551 + (var113[6ll] * 0.0879999995231628f);
  var121[2ll] = var551 + var550;
  blaze::StaticVector<float, 8> var552;
  var552 = 0;
  var552 = var552 + (var117 * var153);
  var122 = var552;
  var131[0ll] = var88[0ll];
  var131[1ll] = var88[1ll];
  var131[2ll] = var88[2ll];
  var131[3ll] = var88[3ll];
  blaze::StaticVector<float, 8> var553;
  var553 = 0;
  var553 = var553 + (-0.333000004291534f * var131[2ll]);
  var135[0ll] = var553;
  blaze::StaticVector<float, 8> var554;
  var554 = 0;
  var554 = var554 + (-0.333000004291534f * var131[3ll]);
  var135[1ll] = var554;
  blaze::StaticVector<float, 8> var555;
  var555 = 0;
  var555 = var555 + (0.333000004291534f * var131[0ll]);
  var135[2ll] = var555;
  blaze::StaticVector<float, 8> var556;
  var556 = 0;
  var556 = var556 + (0.333000004291534f * var131[1ll]);
  var135[3ll] = var556;
  blaze::StaticVector<float, 8> var557;
  var557 = 0;
  var136[0ll] = var557;
  blaze::StaticVector<float, 8> var558;
  var558 = 0;
  var136[1ll] = var558;
  blaze::StaticVector<float, 8> var559;
  var559 = 0;
  var559 = var559 + (1.0f * 1.0f);
  var136[2ll] = var559;
  blaze::StaticVector<float, 8> var560;
  var560 = 0;
  var136[3ll] = var560;
  blaze::StaticVector<float, 8> var561;
  var561 = 0;
  var136[4ll] = var561;
  blaze::StaticVector<float, 8> var562;
  var562 = 0;
  var136[5ll] = var562;
  var144(0ll, 0ll) = var136[0ll];
  var144(1ll, 0ll) = var136[1ll];
  var144(2ll, 0ll) = var136[2ll];
  var144(3ll, 0ll) = var136[3ll];
  var144(4ll, 0ll) = var136[4ll];
  var144(5ll, 0ll) = var136[5ll];
  var131[0ll] = var93[0ll];
  var131[1ll] = var93[1ll];
  var131[4ll] = var93[2ll];
  var131[2ll] = var93[3ll];
  var131[3ll] = var93[4ll];
  var131[5ll] = var93[5ll];
  var131[6ll] = var93[6ll];
  var131[7ll] = var93[7ll];
  var134[2ll] = -(var96[0ll]);
  var134[3ll] = var96[0ll];
  blaze::StaticVector<float, 8> var563;
  var563 = 0;
  var563 = var563 + (var134[2ll] * var131[2ll]);
  var135[0ll] = var563;
  blaze::StaticVector<float, 8> var564;
  var564 = 0;
  var564 = var564 + (var134[2ll] * var131[3ll]);
  var135[1ll] = var564;
  blaze::StaticVector<float, 8> var565;
  var565 = 0;
  var565 = var565 + (var134[2ll] * var131[5ll]);
  var135[4ll] = var565;
  blaze::StaticVector<float, 8> var566;
  var566 = 0;
  var566 = var566 + (var134[3ll] * var131[0ll]);
  var135[2ll] = var566;
  blaze::StaticVector<float, 8> var567;
  var567 = 0;
  var567 = var567 + (var134[3ll] * var131[1ll]);
  var135[3ll] = var567;
  blaze::StaticVector<float, 8> var568;
  var568 = 0;
  var568 = var568 + (var134[3ll] * var131[4ll]);
  var135[5ll] = var568;
  blaze::StaticVector<float, 8> var569;
  var569 = 0;
  var569 = var569 + (var131[4ll] * 1.0f);
  var136[0ll] = var569;
  blaze::StaticVector<float, 8> var570;
  var570 = 0;
  var570 = var570 + (var131[5ll] * 1.0f);
  var136[1ll] = var570;
  blaze::StaticVector<float, 8> var571;
  var571 = 0;
  var136[2ll] = var571;
  blaze::StaticVector<float, 8> var572;
  var572 = 0;
  var572 = var572 + (var135[4ll] * 1.0f);
  var136[3ll] = var572;
  blaze::StaticVector<float, 8> var573;
  var573 = 0;
  var573 = var573 + (var135[5ll] * 1.0f);
  var136[4ll] = var573;
  blaze::StaticVector<float, 8> var574;
  var574 = 0;
  var136[5ll] = var574;
  var144(0ll, 1ll) = var136[0ll];
  var144(1ll, 1ll) = var136[1ll];
  var144(2ll, 1ll) = var136[2ll];
  var144(3ll, 1ll) = var136[3ll];
  var144(4ll, 1ll) = var136[4ll];
  var144(5ll, 1ll) = var136[5ll];
  var131[0ll] = var98[0ll];
  var131[1ll] = var98[1ll];
  var131[4ll] = var98[2ll];
  var131[2ll] = var98[3ll];
  var131[3ll] = var98[4ll];
  var131[5ll] = var98[5ll];
  var131[6ll] = var98[6ll];
  var131[7ll] = var98[7ll];
  var131[8ll] = var98[8ll];
  var134[4ll] = -(var101[0ll]);
  var134[5ll] = var101[0ll];
  var134[0ll] = -(var101[1ll]);
  var134[1ll] = var101[1ll];
  var134[2ll] = -(var101[2ll]);
  var134[3ll] = var101[2ll];
  blaze::StaticVector<float, 8> var575;
  var575 = 0;
  var575 = var575 + (var134[2ll] * var131[2ll]);
  var575 = var575 + (var134[1ll] * var131[6ll]);
  var135[0ll] = var575;
  blaze::StaticVector<float, 8> var576;
  var576 = 0;
  var576 = var576 + (var134[2ll] * var131[3ll]);
  var576 = var576 + (var134[1ll] * var131[7ll]);
  var135[1ll] = var576;
  blaze::StaticVector<float, 8> var577;
  var577 = 0;
  var577 = var577 + (var134[2ll] * var131[5ll]);
  var577 = var577 + (var134[1ll] * var131[8ll]);
  var135[4ll] = var577;
  blaze::StaticVector<float, 8> var578;
  var578 = 0;
  var578 = var578 + (var134[3ll] * var131[0ll]);
  var578 = var578 + (var134[4ll] * var131[6ll]);
  var135[2ll] = var578;
  blaze::StaticVector<float, 8> var579;
  var579 = 0;
  var579 = var579 + (var134[3ll] * var131[1ll]);
  var579 = var579 + (var134[4ll] * var131[7ll]);
  var135[3ll] = var579;
  blaze::StaticVector<float, 8> var580;
  var580 = 0;
  var580 = var580 + (var134[3ll] * var131[4ll]);
  var580 = var580 + (var134[4ll] * var131[8ll]);
  var135[5ll] = var580;
  blaze::StaticVector<float, 8> var581;
  var581 = 0;
  var581 = var581 + (var134[0ll] * var131[0ll]);
  var581 = var581 + (var134[5ll] * var131[2ll]);
  var135[6ll] = var581;
  blaze::StaticVector<float, 8> var582;
  var582 = 0;
  var582 = var582 + (var134[0ll] * var131[1ll]);
  var582 = var582 + (var134[5ll] * var131[3ll]);
  var135[7ll] = var582;
  blaze::StaticVector<float, 8> var583;
  var583 = 0;
  var583 = var583 + (var134[0ll] * var131[4ll]);
  var583 = var583 + (var134[5ll] * var131[5ll]);
  var135[8ll] = var583;
  blaze::StaticVector<float, 8> var584;
  var584 = 0;
  var584 = var584 + (var131[4ll] * 1.0f);
  var136[0ll] = var584;
  blaze::StaticVector<float, 8> var585;
  var585 = 0;
  var585 = var585 + (var131[5ll] * 1.0f);
  var136[1ll] = var585;
  blaze::StaticVector<float, 8> var586;
  var586 = 0;
  var586 = var586 + (var131[8ll] * 1.0f);
  var136[2ll] = var586;
  blaze::StaticVector<float, 8> var587;
  var587 = 0;
  var587 = var587 + (var135[4ll] * 1.0f);
  var136[3ll] = var587;
  blaze::StaticVector<float, 8> var588;
  var588 = 0;
  var588 = var588 + (var135[5ll] * 1.0f);
  var136[4ll] = var588;
  blaze::StaticVector<float, 8> var589;
  var589 = 0;
  var589 = var589 + (var135[8ll] * 1.0f);
  var136[5ll] = var589;
  var144(0ll, 2ll) = var136[0ll];
  var144(1ll, 2ll) = var136[1ll];
  var144(2ll, 2ll) = var136[2ll];
  var144(3ll, 2ll) = var136[3ll];
  var144(4ll, 2ll) = var136[4ll];
  var144(5ll, 2ll) = var136[5ll];
  var131[0ll] = var103[0ll];
  var131[1ll] = var103[1ll];
  var131[4ll] = var103[2ll];
  var131[2ll] = var103[3ll];
  var131[3ll] = var103[4ll];
  var131[5ll] = var103[5ll];
  var131[6ll] = var103[6ll];
  var131[7ll] = var103[7ll];
  var131[8ll] = var103[8ll];
  var134[4ll] = -(var106[0ll]);
  var134[5ll] = var106[0ll];
  var134[0ll] = -(var106[1ll]);
  var134[1ll] = var106[1ll];
  var134[2ll] = -(var106[2ll]);
  var134[3ll] = var106[2ll];
  blaze::StaticVector<float, 8> var590;
  var590 = 0;
  var590 = var590 + (var134[2ll] * var131[2ll]);
  var590 = var590 + (var134[1ll] * var131[6ll]);
  var135[0ll] = var590;
  blaze::StaticVector<float, 8> var591;
  var591 = 0;
  var591 = var591 + (var134[2ll] * var131[3ll]);
  var591 = var591 + (var134[1ll] * var131[7ll]);
  var135[1ll] = var591;
  blaze::StaticVector<float, 8> var592;
  var592 = 0;
  var592 = var592 + (var134[2ll] * var131[5ll]);
  var592 = var592 + (var134[1ll] * var131[8ll]);
  var135[4ll] = var592;
  blaze::StaticVector<float, 8> var593;
  var593 = 0;
  var593 = var593 + (var134[3ll] * var131[0ll]);
  var593 = var593 + (var134[4ll] * var131[6ll]);
  var135[2ll] = var593;
  blaze::StaticVector<float, 8> var594;
  var594 = 0;
  var594 = var594 + (var134[3ll] * var131[1ll]);
  var594 = var594 + (var134[4ll] * var131[7ll]);
  var135[3ll] = var594;
  blaze::StaticVector<float, 8> var595;
  var595 = 0;
  var595 = var595 + (var134[3ll] * var131[4ll]);
  var595 = var595 + (var134[4ll] * var131[8ll]);
  var135[5ll] = var595;
  blaze::StaticVector<float, 8> var596;
  var596 = 0;
  var596 = var596 + (var134[0ll] * var131[0ll]);
  var596 = var596 + (var134[5ll] * var131[2ll]);
  var135[6ll] = var596;
  blaze::StaticVector<float, 8> var597;
  var597 = 0;
  var597 = var597 + (var134[0ll] * var131[1ll]);
  var597 = var597 + (var134[5ll] * var131[3ll]);
  var135[7ll] = var597;
  blaze::StaticVector<float, 8> var598;
  var598 = 0;
  var598 = var598 + (var134[0ll] * var131[4ll]);
  var598 = var598 + (var134[5ll] * var131[5ll]);
  var135[8ll] = var598;
  blaze::StaticVector<float, 8> var599;
  var599 = 0;
  var599 = var599 + (var131[4ll] * 1.0f);
  var136[0ll] = var599;
  blaze::StaticVector<float, 8> var600;
  var600 = 0;
  var600 = var600 + (var131[5ll] * 1.0f);
  var136[1ll] = var600;
  blaze::StaticVector<float, 8> var601;
  var601 = 0;
  var601 = var601 + (var131[8ll] * 1.0f);
  var136[2ll] = var601;
  blaze::StaticVector<float, 8> var602;
  var602 = 0;
  var602 = var602 + (var135[4ll] * 1.0f);
  var136[3ll] = var602;
  blaze::StaticVector<float, 8> var603;
  var603 = 0;
  var603 = var603 + (var135[5ll] * 1.0f);
  var136[4ll] = var603;
  blaze::StaticVector<float, 8> var604;
  var604 = 0;
  var604 = var604 + (var135[8ll] * 1.0f);
  var136[5ll] = var604;
  var144(0ll, 3ll) = var136[0ll];
  var144(1ll, 3ll) = var136[1ll];
  var144(2ll, 3ll) = var136[2ll];
  var144(3ll, 3ll) = var136[3ll];
  var144(4ll, 3ll) = var136[4ll];
  var144(5ll, 3ll) = var136[5ll];
  var131[0ll] = var108[0ll];
  var131[1ll] = var108[1ll];
  var131[4ll] = var108[2ll];
  var131[2ll] = var108[3ll];
  var131[3ll] = var108[4ll];
  var131[5ll] = var108[5ll];
  var131[6ll] = var108[6ll];
  var131[7ll] = var108[7ll];
  var131[8ll] = var108[8ll];
  var134[4ll] = -(var111[0ll]);
  var134[5ll] = var111[0ll];
  var134[0ll] = -(var111[1ll]);
  var134[1ll] = var111[1ll];
  var134[2ll] = -(var111[2ll]);
  var134[3ll] = var111[2ll];
  blaze::StaticVector<float, 8> var605;
  var605 = 0;
  var605 = var605 + (var134[2ll] * var131[2ll]);
  var605 = var605 + (var134[1ll] * var131[6ll]);
  var135[0ll] = var605;
  blaze::StaticVector<float, 8> var606;
  var606 = 0;
  var606 = var606 + (var134[2ll] * var131[3ll]);
  var606 = var606 + (var134[1ll] * var131[7ll]);
  var135[1ll] = var606;
  blaze::StaticVector<float, 8> var607;
  var607 = 0;
  var607 = var607 + (var134[2ll] * var131[5ll]);
  var607 = var607 + (var134[1ll] * var131[8ll]);
  var135[4ll] = var607;
  blaze::StaticVector<float, 8> var608;
  var608 = 0;
  var608 = var608 + (var134[3ll] * var131[0ll]);
  var608 = var608 + (var134[4ll] * var131[6ll]);
  var135[2ll] = var608;
  blaze::StaticVector<float, 8> var609;
  var609 = 0;
  var609 = var609 + (var134[3ll] * var131[1ll]);
  var609 = var609 + (var134[4ll] * var131[7ll]);
  var135[3ll] = var609;
  blaze::StaticVector<float, 8> var610;
  var610 = 0;
  var610 = var610 + (var134[3ll] * var131[4ll]);
  var610 = var610 + (var134[4ll] * var131[8ll]);
  var135[5ll] = var610;
  blaze::StaticVector<float, 8> var611;
  var611 = 0;
  var611 = var611 + (var134[0ll] * var131[0ll]);
  var611 = var611 + (var134[5ll] * var131[2ll]);
  var135[6ll] = var611;
  blaze::StaticVector<float, 8> var612;
  var612 = 0;
  var612 = var612 + (var134[0ll] * var131[1ll]);
  var612 = var612 + (var134[5ll] * var131[3ll]);
  var135[7ll] = var612;
  blaze::StaticVector<float, 8> var613;
  var613 = 0;
  var613 = var613 + (var134[0ll] * var131[4ll]);
  var613 = var613 + (var134[5ll] * var131[5ll]);
  var135[8ll] = var613;
  blaze::StaticVector<float, 8> var614;
  var614 = 0;
  var614 = var614 + (var131[4ll] * 1.0f);
  var136[0ll] = var614;
  blaze::StaticVector<float, 8> var615;
  var615 = 0;
  var615 = var615 + (var131[5ll] * 1.0f);
  var136[1ll] = var615;
  blaze::StaticVector<float, 8> var616;
  var616 = 0;
  var616 = var616 + (var131[8ll] * 1.0f);
  var136[2ll] = var616;
  blaze::StaticVector<float, 8> var617;
  var617 = 0;
  var617 = var617 + (var135[4ll] * 1.0f);
  var136[3ll] = var617;
  blaze::StaticVector<float, 8> var618;
  var618 = 0;
  var618 = var618 + (var135[5ll] * 1.0f);
  var136[4ll] = var618;
  blaze::StaticVector<float, 8> var619;
  var619 = 0;
  var619 = var619 + (var135[8ll] * 1.0f);
  var136[5ll] = var619;
  var144(0ll, 4ll) = var136[0ll];
  var144(1ll, 4ll) = var136[1ll];
  var144(2ll, 4ll) = var136[2ll];
  var144(3ll, 4ll) = var136[3ll];
  var144(4ll, 4ll) = var136[4ll];
  var144(5ll, 4ll) = var136[5ll];
  var131[0ll] = var113[0ll];
  var131[1ll] = var113[1ll];
  var131[4ll] = var113[2ll];
  var131[2ll] = var113[3ll];
  var131[3ll] = var113[4ll];
  var131[5ll] = var113[5ll];
  var131[6ll] = var113[6ll];
  var131[7ll] = var113[7ll];
  var131[8ll] = var113[8ll];
  var134[4ll] = -(var116[0ll]);
  var134[5ll] = var116[0ll];
  var134[0ll] = -(var116[1ll]);
  var134[1ll] = var116[1ll];
  var134[2ll] = -(var116[2ll]);
  var134[3ll] = var116[2ll];
  blaze::StaticVector<float, 8> var620;
  var620 = 0;
  var620 = var620 + (var134[2ll] * var131[2ll]);
  var620 = var620 + (var134[1ll] * var131[6ll]);
  var135[0ll] = var620;
  blaze::StaticVector<float, 8> var621;
  var621 = 0;
  var621 = var621 + (var134[2ll] * var131[3ll]);
  var621 = var621 + (var134[1ll] * var131[7ll]);
  var135[1ll] = var621;
  blaze::StaticVector<float, 8> var622;
  var622 = 0;
  var622 = var622 + (var134[2ll] * var131[5ll]);
  var622 = var622 + (var134[1ll] * var131[8ll]);
  var135[4ll] = var622;
  blaze::StaticVector<float, 8> var623;
  var623 = 0;
  var623 = var623 + (var134[3ll] * var131[0ll]);
  var623 = var623 + (var134[4ll] * var131[6ll]);
  var135[2ll] = var623;
  blaze::StaticVector<float, 8> var624;
  var624 = 0;
  var624 = var624 + (var134[3ll] * var131[1ll]);
  var624 = var624 + (var134[4ll] * var131[7ll]);
  var135[3ll] = var624;
  blaze::StaticVector<float, 8> var625;
  var625 = 0;
  var625 = var625 + (var134[3ll] * var131[4ll]);
  var625 = var625 + (var134[4ll] * var131[8ll]);
  var135[5ll] = var625;
  blaze::StaticVector<float, 8> var626;
  var626 = 0;
  var626 = var626 + (var134[0ll] * var131[0ll]);
  var626 = var626 + (var134[5ll] * var131[2ll]);
  var135[6ll] = var626;
  blaze::StaticVector<float, 8> var627;
  var627 = 0;
  var627 = var627 + (var134[0ll] * var131[1ll]);
  var627 = var627 + (var134[5ll] * var131[3ll]);
  var135[7ll] = var627;
  blaze::StaticVector<float, 8> var628;
  var628 = 0;
  var628 = var628 + (var134[0ll] * var131[4ll]);
  var628 = var628 + (var134[5ll] * var131[5ll]);
  var135[8ll] = var628;
  blaze::StaticVector<float, 8> var629;
  var629 = 0;
  var629 = var629 + (var131[4ll] * 1.0f);
  var136[0ll] = var629;
  blaze::StaticVector<float, 8> var630;
  var630 = 0;
  var630 = var630 + (var131[5ll] * 1.0f);
  var136[1ll] = var630;
  blaze::StaticVector<float, 8> var631;
  var631 = 0;
  var631 = var631 + (var131[8ll] * 1.0f);
  var136[2ll] = var631;
  blaze::StaticVector<float, 8> var632;
  var632 = 0;
  var632 = var632 + (var135[4ll] * 1.0f);
  var136[3ll] = var632;
  blaze::StaticVector<float, 8> var633;
  var633 = 0;
  var633 = var633 + (var135[5ll] * 1.0f);
  var136[4ll] = var633;
  blaze::StaticVector<float, 8> var634;
  var634 = 0;
  var634 = var634 + (var135[8ll] * 1.0f);
  var136[5ll] = var634;
  var144(0ll, 5ll) = var136[0ll];
  var144(1ll, 5ll) = var136[1ll];
  var144(2ll, 5ll) = var136[2ll];
  var144(3ll, 5ll) = var136[3ll];
  var144(4ll, 5ll) = var136[4ll];
  var144(5ll, 5ll) = var136[5ll];
  var131[0ll] = var118[0ll];
  var131[1ll] = var118[1ll];
  var131[4ll] = var118[2ll];
  var131[2ll] = var118[3ll];
  var131[3ll] = var118[4ll];
  var131[5ll] = var118[5ll];
  var131[6ll] = var118[6ll];
  var131[7ll] = var118[7ll];
  var131[8ll] = var118[8ll];
  var134[4ll] = -(var121[0ll]);
  var134[5ll] = var121[0ll];
  var134[0ll] = -(var121[1ll]);
  var134[1ll] = var121[1ll];
  var134[2ll] = -(var121[2ll]);
  var134[3ll] = var121[2ll];
  blaze::StaticVector<float, 8> var635;
  var635 = 0;
  var635 = var635 + (var134[2ll] * var131[2ll]);
  var635 = var635 + (var134[1ll] * var131[6ll]);
  var135[0ll] = var635;
  blaze::StaticVector<float, 8> var636;
  var636 = 0;
  var636 = var636 + (var134[2ll] * var131[3ll]);
  var636 = var636 + (var134[1ll] * var131[7ll]);
  var135[1ll] = var636;
  blaze::StaticVector<float, 8> var637;
  var637 = 0;
  var637 = var637 + (var134[2ll] * var131[5ll]);
  var637 = var637 + (var134[1ll] * var131[8ll]);
  var135[4ll] = var637;
  blaze::StaticVector<float, 8> var638;
  var638 = 0;
  var638 = var638 + (var134[3ll] * var131[0ll]);
  var638 = var638 + (var134[4ll] * var131[6ll]);
  var135[2ll] = var638;
  blaze::StaticVector<float, 8> var639;
  var639 = 0;
  var639 = var639 + (var134[3ll] * var131[1ll]);
  var639 = var639 + (var134[4ll] * var131[7ll]);
  var135[3ll] = var639;
  blaze::StaticVector<float, 8> var640;
  var640 = 0;
  var640 = var640 + (var134[3ll] * var131[4ll]);
  var640 = var640 + (var134[4ll] * var131[8ll]);
  var135[5ll] = var640;
  blaze::StaticVector<float, 8> var641;
  var641 = 0;
  var641 = var641 + (var134[0ll] * var131[0ll]);
  var641 = var641 + (var134[5ll] * var131[2ll]);
  var135[6ll] = var641;
  blaze::StaticVector<float, 8> var642;
  var642 = 0;
  var642 = var642 + (var134[0ll] * var131[1ll]);
  var642 = var642 + (var134[5ll] * var131[3ll]);
  var135[7ll] = var642;
  blaze::StaticVector<float, 8> var643;
  var643 = 0;
  var643 = var643 + (var134[0ll] * var131[4ll]);
  var643 = var643 + (var134[5ll] * var131[5ll]);
  var135[8ll] = var643;
  blaze::StaticVector<float, 8> var644;
  var644 = 0;
  var644 = var644 + (var131[4ll] * 1.0f);
  var136[0ll] = var644;
  blaze::StaticVector<float, 8> var645;
  var645 = 0;
  var645 = var645 + (var131[5ll] * 1.0f);
  var136[1ll] = var645;
  blaze::StaticVector<float, 8> var646;
  var646 = 0;
  var646 = var646 + (var131[8ll] * 1.0f);
  var136[2ll] = var646;
  blaze::StaticVector<float, 8> var647;
  var647 = 0;
  var647 = var647 + (var135[4ll] * 1.0f);
  var136[3ll] = var647;
  blaze::StaticVector<float, 8> var648;
  var648 = 0;
  var648 = var648 + (var135[5ll] * 1.0f);
  var136[4ll] = var648;
  blaze::StaticVector<float, 8> var649;
  var649 = 0;
  var649 = var649 + (var135[8ll] * 1.0f);
  var136[5ll] = var649;
  var144(0ll, 6ll) = var136[0ll];
  var144(1ll, 6ll) = var136[1ll];
  var144(2ll, 6ll) = var136[2ll];
  var144(3ll, 6ll) = var136[3ll];
  var144(4ll, 6ll) = var136[4ll];
  var144(5ll, 6ll) = var136[5ll];
  var145[32ll] = ((var118[0ll] * 0.0f) + (var118[1ll] * 0.0f)) + (var118[2ll] * 0.0700000002980232f);
  var146[32ll] = ((var118[3ll] * 0.0f) + (var118[4ll] * 0.0f)) + (var118[5ll] * 0.0700000002980232f);
  var147[32ll] = ((var118[6ll] * 0.0f) + (var118[7ll] * 0.0f)) + (var118[8ll] * 0.0700000002980232f);
  var145[32ll] = var145[32ll] + var121[0ll];
  var146[32ll] = var146[32ll] + var121[1ll];
  var147[32ll] = var147[32ll] + var121[2ll];
  var148[32ll] = 0.0500000007450581f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(15ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 0,32 : panda_link0_0,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(57ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 1,32 : panda_link1_0,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(99ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 2,32 : panda_link1_1,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(141ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 3,32 : panda_link1_2,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(183ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 4,32 : panda_link1_3,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(222ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 5,32 : panda_link2_0,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(261ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 6,32 : panda_link2_1,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(300ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 7,32 : panda_link2_2,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(339ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 8,32 : panda_link2_3,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(366ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 17,32 : panda_link5_0,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(393ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 18,32 : panda_link5_1,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(420ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 19,32 : panda_link5_2,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(447ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 20,32 : panda_link5_3,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(474ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 21,32 : panda_link5_4,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(501ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 22,32 : panda_link5_5,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(528ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 23,32 : panda_link5_6,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(555ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 24,32 : panda_link5_7,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(582ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 25,32 : panda_link5_8,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(609ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 26,32 : panda_link5_9,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(636ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 27,32 : panda_link5_10,panda_link7_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(663ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[32ll], var146[32ll], var147[32ll], var148[32ll], arg3, arg4); //collision pair: 28,32 : panda_link5_11,panda_link7_0
  var145[33ll] = ((var118[0ll] * 0.0199999995529652f) + (var118[1ll] * 0.0399999991059303f)) + (var118[2ll] * 0.0799999982118607f);
  var146[33ll] = ((var118[3ll] * 0.0199999995529652f) + (var118[4ll] * 0.0399999991059303f)) + (var118[5ll] * 0.0799999982118607f);
  var147[33ll] = ((var118[6ll] * 0.0199999995529652f) + (var118[7ll] * 0.0399999991059303f)) + (var118[8ll] * 0.0799999982118607f);
  var145[33ll] = var145[33ll] + var121[0ll];
  var146[33ll] = var146[33ll] + var121[1ll];
  var147[33ll] = var147[33ll] + var121[2ll];
  var148[33ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(16ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 0,33 : panda_link0_0,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(58ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 1,33 : panda_link1_0,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(100ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 2,33 : panda_link1_1,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(142ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 3,33 : panda_link1_2,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(184ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 4,33 : panda_link1_3,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(223ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 5,33 : panda_link2_0,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(262ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 6,33 : panda_link2_1,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(301ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 7,33 : panda_link2_2,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(340ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 8,33 : panda_link2_3,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(367ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 17,33 : panda_link5_0,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(394ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 18,33 : panda_link5_1,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(421ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 19,33 : panda_link5_2,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(448ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 20,33 : panda_link5_3,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(475ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 21,33 : panda_link5_4,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(502ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 22,33 : panda_link5_5,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(529ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 23,33 : panda_link5_6,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(556ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 24,33 : panda_link5_7,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(583ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 25,33 : panda_link5_8,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(610ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 26,33 : panda_link5_9,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(637ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 27,33 : panda_link5_10,panda_link7_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(664ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[33ll], var146[33ll], var147[33ll], var148[33ll], arg3, arg4); //collision pair: 28,33 : panda_link5_11,panda_link7_1
  var145[34ll] = ((var118[0ll] * 0.0399999991059303f) + (var118[1ll] * 0.0199999995529652f)) + (var118[2ll] * 0.0799999982118607f);
  var146[34ll] = ((var118[3ll] * 0.0399999991059303f) + (var118[4ll] * 0.0199999995529652f)) + (var118[5ll] * 0.0799999982118607f);
  var147[34ll] = ((var118[6ll] * 0.0399999991059303f) + (var118[7ll] * 0.0199999995529652f)) + (var118[8ll] * 0.0799999982118607f);
  var145[34ll] = var145[34ll] + var121[0ll];
  var146[34ll] = var146[34ll] + var121[1ll];
  var147[34ll] = var147[34ll] + var121[2ll];
  var148[34ll] = 0.025000000372529f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(17ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 0,34 : panda_link0_0,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(59ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 1,34 : panda_link1_0,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(101ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 2,34 : panda_link1_1,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(143ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 3,34 : panda_link1_2,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(185ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 4,34 : panda_link1_3,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(224ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 5,34 : panda_link2_0,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(263ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 6,34 : panda_link2_1,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(302ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 7,34 : panda_link2_2,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(341ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 8,34 : panda_link2_3,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(368ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 17,34 : panda_link5_0,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(395ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 18,34 : panda_link5_1,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(422ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 19,34 : panda_link5_2,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(449ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 20,34 : panda_link5_3,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(476ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 21,34 : panda_link5_4,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(503ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 22,34 : panda_link5_5,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(530ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 23,34 : panda_link5_6,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(557ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 24,34 : panda_link5_7,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(584ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 25,34 : panda_link5_8,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(611ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 26,34 : panda_link5_9,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(638ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 27,34 : panda_link5_10,panda_link7_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(665ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[34ll], var146[34ll], var147[34ll], var148[34ll], arg3, arg4); //collision pair: 28,34 : panda_link5_11,panda_link7_2
  var145[35ll] = ((var118[0ll] * 0.0399999991059303f) + (var118[1ll] * 0.0599999986588955f)) + (var118[2ll] * 0.0850000008940697f);
  var146[35ll] = ((var118[3ll] * 0.0399999991059303f) + (var118[4ll] * 0.0599999986588955f)) + (var118[5ll] * 0.0850000008940697f);
  var147[35ll] = ((var118[6ll] * 0.0399999991059303f) + (var118[7ll] * 0.0599999986588955f)) + (var118[8ll] * 0.0850000008940697f);
  var145[35ll] = var145[35ll] + var121[0ll];
  var146[35ll] = var146[35ll] + var121[1ll];
  var147[35ll] = var147[35ll] + var121[2ll];
  var148[35ll] = 0.0199999995529652f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(18ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 0,35 : panda_link0_0,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(60ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 1,35 : panda_link1_0,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(102ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 2,35 : panda_link1_1,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(144ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 3,35 : panda_link1_2,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(186ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 4,35 : panda_link1_3,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(225ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 5,35 : panda_link2_0,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(264ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 6,35 : panda_link2_1,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(303ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 7,35 : panda_link2_2,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(342ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 8,35 : panda_link2_3,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(369ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 17,35 : panda_link5_0,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(396ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 18,35 : panda_link5_1,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(423ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 19,35 : panda_link5_2,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(450ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 20,35 : panda_link5_3,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(477ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 21,35 : panda_link5_4,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(504ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 22,35 : panda_link5_5,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(531ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 23,35 : panda_link5_6,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(558ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 24,35 : panda_link5_7,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(585ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 25,35 : panda_link5_8,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(612ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 26,35 : panda_link5_9,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(639ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 27,35 : panda_link5_10,panda_link7_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(666ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[35ll], var146[35ll], var147[35ll], var148[35ll], arg3, arg4); //collision pair: 28,35 : panda_link5_11,panda_link7_3
  var145[36ll] = ((var118[0ll] * 0.0599999986588955f) + (var118[1ll] * 0.0399999991059303f)) + (var118[2ll] * 0.0850000008940697f);
  var146[36ll] = ((var118[3ll] * 0.0599999986588955f) + (var118[4ll] * 0.0399999991059303f)) + (var118[5ll] * 0.0850000008940697f);
  var147[36ll] = ((var118[6ll] * 0.0599999986588955f) + (var118[7ll] * 0.0399999991059303f)) + (var118[8ll] * 0.0850000008940697f);
  var145[36ll] = var145[36ll] + var121[0ll];
  var146[36ll] = var146[36ll] + var121[1ll];
  var147[36ll] = var147[36ll] + var121[2ll];
  var148[36ll] = 0.0199999995529652f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(19ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 0,36 : panda_link0_0,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(61ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 1,36 : panda_link1_0,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(103ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 2,36 : panda_link1_1,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(145ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 3,36 : panda_link1_2,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(187ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 4,36 : panda_link1_3,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(226ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 5,36 : panda_link2_0,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(265ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 6,36 : panda_link2_1,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(304ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 7,36 : panda_link2_2,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(343ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 8,36 : panda_link2_3,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(370ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 17,36 : panda_link5_0,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(397ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 18,36 : panda_link5_1,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(424ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 19,36 : panda_link5_2,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(451ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 20,36 : panda_link5_3,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(478ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 21,36 : panda_link5_4,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(505ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 22,36 : panda_link5_5,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(532ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 23,36 : panda_link5_6,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(559ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 24,36 : panda_link5_7,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(586ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 25,36 : panda_link5_8,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(613ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 26,36 : panda_link5_9,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(640ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 27,36 : panda_link5_10,panda_link7_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(667ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[36ll], var146[36ll], var147[36ll], var148[36ll], arg3, arg4); //collision pair: 28,36 : panda_link5_11,panda_link7_4
  var145[37ll] = ((var118[0ll] * -0.0530330091714859f) + (var118[1ll] * -0.0530330091714859f)) + (var118[2ll] * 0.116999998688698f);
  var146[37ll] = ((var118[3ll] * -0.0530330091714859f) + (var118[4ll] * -0.0530330091714859f)) + (var118[5ll] * 0.116999998688698f);
  var147[37ll] = ((var118[6ll] * -0.0530330091714859f) + (var118[7ll] * -0.0530330091714859f)) + (var118[8ll] * 0.116999998688698f);
  var145[37ll] = var145[37ll] + var121[0ll];
  var146[37ll] = var146[37ll] + var121[1ll];
  var147[37ll] = var147[37ll] + var121[2ll];
  var148[37ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(20ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 0,37 : panda_link0_0,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(62ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 1,37 : panda_link1_0,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(104ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 2,37 : panda_link1_1,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(146ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 3,37 : panda_link1_2,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(188ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 4,37 : panda_link1_3,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(227ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 5,37 : panda_link2_0,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(266ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 6,37 : panda_link2_1,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(305ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 7,37 : panda_link2_2,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(344ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 8,37 : panda_link2_3,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(371ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 17,37 : panda_link5_0,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(398ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 18,37 : panda_link5_1,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(425ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 19,37 : panda_link5_2,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(452ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 20,37 : panda_link5_3,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(479ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 21,37 : panda_link5_4,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(506ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 22,37 : panda_link5_5,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(533ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 23,37 : panda_link5_6,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(560ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 24,37 : panda_link5_7,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(587ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 25,37 : panda_link5_8,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(614ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 26,37 : panda_link5_9,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(641ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 27,37 : panda_link5_10,panda_hand_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(668ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[37ll], var146[37ll], var147[37ll], var148[37ll], arg3, arg4); //collision pair: 28,37 : panda_link5_11,panda_hand_0
  var145[38ll] = ((var118[0ll] * -0.0318198055028915f) + (var118[1ll] * -0.0318198055028915f)) + (var118[2ll] * 0.116999998688698f);
  var146[38ll] = ((var118[3ll] * -0.0318198055028915f) + (var118[4ll] * -0.0318198055028915f)) + (var118[5ll] * 0.116999998688698f);
  var147[38ll] = ((var118[6ll] * -0.0318198055028915f) + (var118[7ll] * -0.0318198055028915f)) + (var118[8ll] * 0.116999998688698f);
  var145[38ll] = var145[38ll] + var121[0ll];
  var146[38ll] = var146[38ll] + var121[1ll];
  var147[38ll] = var147[38ll] + var121[2ll];
  var148[38ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(21ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 0,38 : panda_link0_0,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(63ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 1,38 : panda_link1_0,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(105ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 2,38 : panda_link1_1,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(147ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 3,38 : panda_link1_2,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(189ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 4,38 : panda_link1_3,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(228ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 5,38 : panda_link2_0,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(267ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 6,38 : panda_link2_1,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(306ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 7,38 : panda_link2_2,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(345ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 8,38 : panda_link2_3,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(372ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 17,38 : panda_link5_0,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(399ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 18,38 : panda_link5_1,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(426ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 19,38 : panda_link5_2,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(453ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 20,38 : panda_link5_3,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(480ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 21,38 : panda_link5_4,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(507ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 22,38 : panda_link5_5,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(534ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 23,38 : panda_link5_6,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(561ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 24,38 : panda_link5_7,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(588ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 25,38 : panda_link5_8,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(615ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 26,38 : panda_link5_9,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(642ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 27,38 : panda_link5_10,panda_hand_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(669ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[38ll], var146[38ll], var147[38ll], var148[38ll], arg3, arg4); //collision pair: 28,38 : panda_link5_11,panda_hand_1
  var145[39ll] = ((var118[0ll] * -0.0106066018342972f) + (var118[1ll] * -0.0106066018342972f)) + (var118[2ll] * 0.116999998688698f);
  var146[39ll] = ((var118[3ll] * -0.0106066018342972f) + (var118[4ll] * -0.0106066018342972f)) + (var118[5ll] * 0.116999998688698f);
  var147[39ll] = ((var118[6ll] * -0.0106066018342972f) + (var118[7ll] * -0.0106066018342972f)) + (var118[8ll] * 0.116999998688698f);
  var145[39ll] = var145[39ll] + var121[0ll];
  var146[39ll] = var146[39ll] + var121[1ll];
  var147[39ll] = var147[39ll] + var121[2ll];
  var148[39ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(22ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 0,39 : panda_link0_0,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(64ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 1,39 : panda_link1_0,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(106ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 2,39 : panda_link1_1,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(148ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 3,39 : panda_link1_2,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(190ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 4,39 : panda_link1_3,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(229ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 5,39 : panda_link2_0,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(268ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 6,39 : panda_link2_1,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(307ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 7,39 : panda_link2_2,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(346ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 8,39 : panda_link2_3,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(373ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 17,39 : panda_link5_0,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(400ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 18,39 : panda_link5_1,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(427ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 19,39 : panda_link5_2,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(454ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 20,39 : panda_link5_3,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(481ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 21,39 : panda_link5_4,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(508ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 22,39 : panda_link5_5,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(535ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 23,39 : panda_link5_6,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(562ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 24,39 : panda_link5_7,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(589ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 25,39 : panda_link5_8,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(616ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 26,39 : panda_link5_9,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(643ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 27,39 : panda_link5_10,panda_hand_2
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(670ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[39ll], var146[39ll], var147[39ll], var148[39ll], arg3, arg4); //collision pair: 28,39 : panda_link5_11,panda_hand_2
  var145[40ll] = ((var118[0ll] * 0.0106066018342972f) + (var118[1ll] * 0.0106066018342972f)) + (var118[2ll] * 0.116999998688698f);
  var146[40ll] = ((var118[3ll] * 0.0106066018342972f) + (var118[4ll] * 0.0106066018342972f)) + (var118[5ll] * 0.116999998688698f);
  var147[40ll] = ((var118[6ll] * 0.0106066018342972f) + (var118[7ll] * 0.0106066018342972f)) + (var118[8ll] * 0.116999998688698f);
  var145[40ll] = var145[40ll] + var121[0ll];
  var146[40ll] = var146[40ll] + var121[1ll];
  var147[40ll] = var147[40ll] + var121[2ll];
  var148[40ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(23ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 0,40 : panda_link0_0,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(65ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 1,40 : panda_link1_0,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(107ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 2,40 : panda_link1_1,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(149ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 3,40 : panda_link1_2,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(191ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 4,40 : panda_link1_3,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(230ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 5,40 : panda_link2_0,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(269ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 6,40 : panda_link2_1,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(308ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 7,40 : panda_link2_2,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(347ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 8,40 : panda_link2_3,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(374ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 17,40 : panda_link5_0,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(401ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 18,40 : panda_link5_1,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(428ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 19,40 : panda_link5_2,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(455ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 20,40 : panda_link5_3,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(482ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 21,40 : panda_link5_4,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(509ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 22,40 : panda_link5_5,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(536ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 23,40 : panda_link5_6,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(563ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 24,40 : panda_link5_7,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(590ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 25,40 : panda_link5_8,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(617ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 26,40 : panda_link5_9,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(644ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 27,40 : panda_link5_10,panda_hand_3
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(671ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[40ll], var146[40ll], var147[40ll], var148[40ll], arg3, arg4); //collision pair: 28,40 : panda_link5_11,panda_hand_3
  var145[41ll] = ((var118[0ll] * 0.0318198055028915f) + (var118[1ll] * 0.0318198055028915f)) + (var118[2ll] * 0.116999998688698f);
  var146[41ll] = ((var118[3ll] * 0.0318198055028915f) + (var118[4ll] * 0.0318198055028915f)) + (var118[5ll] * 0.116999998688698f);
  var147[41ll] = ((var118[6ll] * 0.0318198055028915f) + (var118[7ll] * 0.0318198055028915f)) + (var118[8ll] * 0.116999998688698f);
  var145[41ll] = var145[41ll] + var121[0ll];
  var146[41ll] = var146[41ll] + var121[1ll];
  var147[41ll] = var147[41ll] + var121[2ll];
  var148[41ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(24ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 0,41 : panda_link0_0,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(66ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 1,41 : panda_link1_0,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(108ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 2,41 : panda_link1_1,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(150ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 3,41 : panda_link1_2,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(192ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 4,41 : panda_link1_3,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(231ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 5,41 : panda_link2_0,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(270ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 6,41 : panda_link2_1,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(309ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 7,41 : panda_link2_2,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(348ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 8,41 : panda_link2_3,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(375ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 17,41 : panda_link5_0,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(402ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 18,41 : panda_link5_1,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(429ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 19,41 : panda_link5_2,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(456ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 20,41 : panda_link5_3,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(483ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 21,41 : panda_link5_4,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(510ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 22,41 : panda_link5_5,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(537ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 23,41 : panda_link5_6,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(564ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 24,41 : panda_link5_7,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(591ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 25,41 : panda_link5_8,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(618ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 26,41 : panda_link5_9,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(645ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 27,41 : panda_link5_10,panda_hand_4
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(672ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[41ll], var146[41ll], var147[41ll], var148[41ll], arg3, arg4); //collision pair: 28,41 : panda_link5_11,panda_hand_4
  var145[42ll] = ((var118[0ll] * 0.0530330091714859f) + (var118[1ll] * 0.0530330091714859f)) + (var118[2ll] * 0.116999998688698f);
  var146[42ll] = ((var118[3ll] * 0.0530330091714859f) + (var118[4ll] * 0.0530330091714859f)) + (var118[5ll] * 0.116999998688698f);
  var147[42ll] = ((var118[6ll] * 0.0530330091714859f) + (var118[7ll] * 0.0530330091714859f)) + (var118[8ll] * 0.116999998688698f);
  var145[42ll] = var145[42ll] + var121[0ll];
  var146[42ll] = var146[42ll] + var121[1ll];
  var147[42ll] = var147[42ll] + var121[2ll];
  var148[42ll] = 0.0280000008642673f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(25ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 0,42 : panda_link0_0,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(67ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 1,42 : panda_link1_0,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(109ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 2,42 : panda_link1_1,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(151ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 3,42 : panda_link1_2,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(193ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 4,42 : panda_link1_3,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(232ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 5,42 : panda_link2_0,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(271ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 6,42 : panda_link2_1,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(310ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 7,42 : panda_link2_2,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(349ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 8,42 : panda_link2_3,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(376ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 17,42 : panda_link5_0,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(403ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 18,42 : panda_link5_1,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(430ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 19,42 : panda_link5_2,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(457ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 20,42 : panda_link5_3,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(484ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 21,42 : panda_link5_4,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(511ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 22,42 : panda_link5_5,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(538ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 23,42 : panda_link5_6,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(565ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 24,42 : panda_link5_7,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(592ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 25,42 : panda_link5_8,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(619ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 26,42 : panda_link5_9,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(646ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 27,42 : panda_link5_10,panda_hand_5
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(673ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[42ll], var146[42ll], var147[42ll], var148[42ll], arg3, arg4); //collision pair: 28,42 : panda_link5_11,panda_hand_5
  var145[43ll] = ((var118[0ll] * -0.0530330091714859f) + (var118[1ll] * -0.0530330091714859f)) + (var118[2ll] * 0.136999994516373f);
  var146[43ll] = ((var118[3ll] * -0.0530330091714859f) + (var118[4ll] * -0.0530330091714859f)) + (var118[5ll] * 0.136999994516373f);
  var147[43ll] = ((var118[6ll] * -0.0530330091714859f) + (var118[7ll] * -0.0530330091714859f)) + (var118[8ll] * 0.136999994516373f);
  var145[43ll] = var145[43ll] + var121[0ll];
  var146[43ll] = var146[43ll] + var121[1ll];
  var147[43ll] = var147[43ll] + var121[2ll];
  var148[43ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(26ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 0,43 : panda_link0_0,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(68ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 1,43 : panda_link1_0,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(110ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 2,43 : panda_link1_1,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(152ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 3,43 : panda_link1_2,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(194ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 4,43 : panda_link1_3,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(233ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 5,43 : panda_link2_0,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(272ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 6,43 : panda_link2_1,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(311ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 7,43 : panda_link2_2,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(350ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 8,43 : panda_link2_3,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(377ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 17,43 : panda_link5_0,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(404ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 18,43 : panda_link5_1,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(431ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 19,43 : panda_link5_2,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(458ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 20,43 : panda_link5_3,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(485ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 21,43 : panda_link5_4,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(512ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 22,43 : panda_link5_5,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(539ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 23,43 : panda_link5_6,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(566ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 24,43 : panda_link5_7,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(593ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 25,43 : panda_link5_8,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(620ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 26,43 : panda_link5_9,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(647ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 27,43 : panda_link5_10,panda_hand_6
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(674ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[43ll], var146[43ll], var147[43ll], var148[43ll], arg3, arg4); //collision pair: 28,43 : panda_link5_11,panda_hand_6
  var145[44ll] = ((var118[0ll] * -0.0318198055028915f) + (var118[1ll] * -0.0318198055028915f)) + (var118[2ll] * 0.136999994516373f);
  var146[44ll] = ((var118[3ll] * -0.0318198055028915f) + (var118[4ll] * -0.0318198055028915f)) + (var118[5ll] * 0.136999994516373f);
  var147[44ll] = ((var118[6ll] * -0.0318198055028915f) + (var118[7ll] * -0.0318198055028915f)) + (var118[8ll] * 0.136999994516373f);
  var145[44ll] = var145[44ll] + var121[0ll];
  var146[44ll] = var146[44ll] + var121[1ll];
  var147[44ll] = var147[44ll] + var121[2ll];
  var148[44ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(27ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 0,44 : panda_link0_0,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(69ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 1,44 : panda_link1_0,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(111ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 2,44 : panda_link1_1,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(153ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 3,44 : panda_link1_2,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(195ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 4,44 : panda_link1_3,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(234ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 5,44 : panda_link2_0,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(273ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 6,44 : panda_link2_1,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(312ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 7,44 : panda_link2_2,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(351ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 8,44 : panda_link2_3,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(378ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 17,44 : panda_link5_0,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(405ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 18,44 : panda_link5_1,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(432ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 19,44 : panda_link5_2,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(459ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 20,44 : panda_link5_3,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(486ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 21,44 : panda_link5_4,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(513ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 22,44 : panda_link5_5,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(540ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 23,44 : panda_link5_6,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(567ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 24,44 : panda_link5_7,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(594ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 25,44 : panda_link5_8,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(621ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 26,44 : panda_link5_9,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(648ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 27,44 : panda_link5_10,panda_hand_7
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(675ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[44ll], var146[44ll], var147[44ll], var148[44ll], arg3, arg4); //collision pair: 28,44 : panda_link5_11,panda_hand_7
  var145[45ll] = ((var118[0ll] * -0.0106066018342972f) + (var118[1ll] * -0.0106066018342972f)) + (var118[2ll] * 0.136999994516373f);
  var146[45ll] = ((var118[3ll] * -0.0106066018342972f) + (var118[4ll] * -0.0106066018342972f)) + (var118[5ll] * 0.136999994516373f);
  var147[45ll] = ((var118[6ll] * -0.0106066018342972f) + (var118[7ll] * -0.0106066018342972f)) + (var118[8ll] * 0.136999994516373f);
  var145[45ll] = var145[45ll] + var121[0ll];
  var146[45ll] = var146[45ll] + var121[1ll];
  var147[45ll] = var147[45ll] + var121[2ll];
  var148[45ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(28ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 0,45 : panda_link0_0,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(70ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 1,45 : panda_link1_0,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(112ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 2,45 : panda_link1_1,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(154ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 3,45 : panda_link1_2,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(196ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 4,45 : panda_link1_3,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(235ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 5,45 : panda_link2_0,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(274ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 6,45 : panda_link2_1,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(313ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 7,45 : panda_link2_2,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(352ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 8,45 : panda_link2_3,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(379ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 17,45 : panda_link5_0,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(406ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 18,45 : panda_link5_1,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(433ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 19,45 : panda_link5_2,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(460ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 20,45 : panda_link5_3,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(487ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 21,45 : panda_link5_4,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(514ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 22,45 : panda_link5_5,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(541ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 23,45 : panda_link5_6,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(568ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 24,45 : panda_link5_7,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(595ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 25,45 : panda_link5_8,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(622ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 26,45 : panda_link5_9,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(649ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 27,45 : panda_link5_10,panda_hand_8
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(676ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[45ll], var146[45ll], var147[45ll], var148[45ll], arg3, arg4); //collision pair: 28,45 : panda_link5_11,panda_hand_8
  var145[46ll] = ((var118[0ll] * 0.0106066018342972f) + (var118[1ll] * 0.0106066018342972f)) + (var118[2ll] * 0.136999994516373f);
  var146[46ll] = ((var118[3ll] * 0.0106066018342972f) + (var118[4ll] * 0.0106066018342972f)) + (var118[5ll] * 0.136999994516373f);
  var147[46ll] = ((var118[6ll] * 0.0106066018342972f) + (var118[7ll] * 0.0106066018342972f)) + (var118[8ll] * 0.136999994516373f);
  var145[46ll] = var145[46ll] + var121[0ll];
  var146[46ll] = var146[46ll] + var121[1ll];
  var147[46ll] = var147[46ll] + var121[2ll];
  var148[46ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(29ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 0,46 : panda_link0_0,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(71ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 1,46 : panda_link1_0,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(113ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 2,46 : panda_link1_1,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(155ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 3,46 : panda_link1_2,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(197ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 4,46 : panda_link1_3,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(236ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 5,46 : panda_link2_0,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(275ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 6,46 : panda_link2_1,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(314ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 7,46 : panda_link2_2,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(353ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 8,46 : panda_link2_3,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(380ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 17,46 : panda_link5_0,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(407ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 18,46 : panda_link5_1,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(434ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 19,46 : panda_link5_2,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(461ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 20,46 : panda_link5_3,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(488ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 21,46 : panda_link5_4,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(515ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 22,46 : panda_link5_5,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(542ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 23,46 : panda_link5_6,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(569ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 24,46 : panda_link5_7,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(596ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 25,46 : panda_link5_8,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(623ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 26,46 : panda_link5_9,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(650ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 27,46 : panda_link5_10,panda_hand_9
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(677ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[46ll], var146[46ll], var147[46ll], var148[46ll], arg3, arg4); //collision pair: 28,46 : panda_link5_11,panda_hand_9
  var145[47ll] = ((var118[0ll] * 0.0318198055028915f) + (var118[1ll] * 0.0318198055028915f)) + (var118[2ll] * 0.136999994516373f);
  var146[47ll] = ((var118[3ll] * 0.0318198055028915f) + (var118[4ll] * 0.0318198055028915f)) + (var118[5ll] * 0.136999994516373f);
  var147[47ll] = ((var118[6ll] * 0.0318198055028915f) + (var118[7ll] * 0.0318198055028915f)) + (var118[8ll] * 0.136999994516373f);
  var145[47ll] = var145[47ll] + var121[0ll];
  var146[47ll] = var146[47ll] + var121[1ll];
  var147[47ll] = var147[47ll] + var121[2ll];
  var148[47ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(30ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 0,47 : panda_link0_0,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(72ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 1,47 : panda_link1_0,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(114ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 2,47 : panda_link1_1,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(156ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 3,47 : panda_link1_2,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(198ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 4,47 : panda_link1_3,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(237ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 5,47 : panda_link2_0,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(276ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 6,47 : panda_link2_1,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(315ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 7,47 : panda_link2_2,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(354ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 8,47 : panda_link2_3,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(381ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 17,47 : panda_link5_0,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(408ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 18,47 : panda_link5_1,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(435ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 19,47 : panda_link5_2,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(462ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 20,47 : panda_link5_3,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(489ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 21,47 : panda_link5_4,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(516ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 22,47 : panda_link5_5,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(543ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 23,47 : panda_link5_6,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(570ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 24,47 : panda_link5_7,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(597ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 25,47 : panda_link5_8,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(624ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 26,47 : panda_link5_9,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(651ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 27,47 : panda_link5_10,panda_hand_10
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(678ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[47ll], var146[47ll], var147[47ll], var148[47ll], arg3, arg4); //collision pair: 28,47 : panda_link5_11,panda_hand_10
  var145[48ll] = ((var118[0ll] * 0.0530330091714859f) + (var118[1ll] * 0.0530330091714859f)) + (var118[2ll] * 0.136999994516373f);
  var146[48ll] = ((var118[3ll] * 0.0530330091714859f) + (var118[4ll] * 0.0530330091714859f)) + (var118[5ll] * 0.136999994516373f);
  var147[48ll] = ((var118[6ll] * 0.0530330091714859f) + (var118[7ll] * 0.0530330091714859f)) + (var118[8ll] * 0.136999994516373f);
  var145[48ll] = var145[48ll] + var121[0ll];
  var146[48ll] = var146[48ll] + var121[1ll];
  var147[48ll] = var147[48ll] + var121[2ll];
  var148[48ll] = 0.0260000005364418f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(31ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 0,48 : panda_link0_0,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(73ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 1,48 : panda_link1_0,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(115ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 2,48 : panda_link1_1,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(157ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 3,48 : panda_link1_2,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(199ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 4,48 : panda_link1_3,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(238ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 5,48 : panda_link2_0,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(277ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 6,48 : panda_link2_1,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(316ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 7,48 : panda_link2_2,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(355ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 8,48 : panda_link2_3,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(382ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 17,48 : panda_link5_0,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(409ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 18,48 : panda_link5_1,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(436ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 19,48 : panda_link5_2,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(463ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 20,48 : panda_link5_3,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(490ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 21,48 : panda_link5_4,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(517ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 22,48 : panda_link5_5,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(544ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 23,48 : panda_link5_6,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(571ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 24,48 : panda_link5_7,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(598ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 25,48 : panda_link5_8,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(625ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 26,48 : panda_link5_9,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(652ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 27,48 : panda_link5_10,panda_hand_11
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(679ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[48ll], var146[48ll], var147[48ll], var148[48ll], arg3, arg4); //collision pair: 28,48 : panda_link5_11,panda_hand_11
  var145[49ll] = ((var118[0ll] * -0.0530330091714859f) + (var118[1ll] * -0.0530330091714859f)) + (var118[2ll] * 0.157000005245209f);
  var146[49ll] = ((var118[3ll] * -0.0530330091714859f) + (var118[4ll] * -0.0530330091714859f)) + (var118[5ll] * 0.157000005245209f);
  var147[49ll] = ((var118[6ll] * -0.0530330091714859f) + (var118[7ll] * -0.0530330091714859f)) + (var118[8ll] * 0.157000005245209f);
  var145[49ll] = var145[49ll] + var121[0ll];
  var146[49ll] = var146[49ll] + var121[1ll];
  var147[49ll] = var147[49ll] + var121[2ll];
  var148[49ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(32ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 0,49 : panda_link0_0,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(74ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 1,49 : panda_link1_0,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(116ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 2,49 : panda_link1_1,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(158ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 3,49 : panda_link1_2,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(200ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 4,49 : panda_link1_3,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(239ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 5,49 : panda_link2_0,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(278ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 6,49 : panda_link2_1,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(317ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 7,49 : panda_link2_2,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(356ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 8,49 : panda_link2_3,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(383ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 17,49 : panda_link5_0,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(410ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 18,49 : panda_link5_1,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(437ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 19,49 : panda_link5_2,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(464ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 20,49 : panda_link5_3,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(491ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 21,49 : panda_link5_4,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(518ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 22,49 : panda_link5_5,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(545ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 23,49 : panda_link5_6,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(572ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 24,49 : panda_link5_7,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(599ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 25,49 : panda_link5_8,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(626ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 26,49 : panda_link5_9,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(653ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 27,49 : panda_link5_10,panda_hand_12
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(680ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[49ll], var146[49ll], var147[49ll], var148[49ll], arg3, arg4); //collision pair: 28,49 : panda_link5_11,panda_hand_12
  var145[50ll] = ((var118[0ll] * -0.0318198055028915f) + (var118[1ll] * -0.0318198055028915f)) + (var118[2ll] * 0.157000005245209f);
  var146[50ll] = ((var118[3ll] * -0.0318198055028915f) + (var118[4ll] * -0.0318198055028915f)) + (var118[5ll] * 0.157000005245209f);
  var147[50ll] = ((var118[6ll] * -0.0318198055028915f) + (var118[7ll] * -0.0318198055028915f)) + (var118[8ll] * 0.157000005245209f);
  var145[50ll] = var145[50ll] + var121[0ll];
  var146[50ll] = var146[50ll] + var121[1ll];
  var147[50ll] = var147[50ll] + var121[2ll];
  var148[50ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(33ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 0,50 : panda_link0_0,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(75ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 1,50 : panda_link1_0,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(117ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 2,50 : panda_link1_1,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(159ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 3,50 : panda_link1_2,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(201ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 4,50 : panda_link1_3,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(240ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 5,50 : panda_link2_0,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(279ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 6,50 : panda_link2_1,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(318ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 7,50 : panda_link2_2,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(357ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 8,50 : panda_link2_3,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(384ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 17,50 : panda_link5_0,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(411ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 18,50 : panda_link5_1,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(438ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 19,50 : panda_link5_2,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(465ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 20,50 : panda_link5_3,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(492ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 21,50 : panda_link5_4,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(519ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 22,50 : panda_link5_5,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(546ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 23,50 : panda_link5_6,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(573ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 24,50 : panda_link5_7,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(600ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 25,50 : panda_link5_8,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(627ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 26,50 : panda_link5_9,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(654ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 27,50 : panda_link5_10,panda_hand_13
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(681ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[50ll], var146[50ll], var147[50ll], var148[50ll], arg3, arg4); //collision pair: 28,50 : panda_link5_11,panda_hand_13
  var145[51ll] = ((var118[0ll] * -0.0106066018342972f) + (var118[1ll] * -0.0106066018342972f)) + (var118[2ll] * 0.157000005245209f);
  var146[51ll] = ((var118[3ll] * -0.0106066018342972f) + (var118[4ll] * -0.0106066018342972f)) + (var118[5ll] * 0.157000005245209f);
  var147[51ll] = ((var118[6ll] * -0.0106066018342972f) + (var118[7ll] * -0.0106066018342972f)) + (var118[8ll] * 0.157000005245209f);
  var145[51ll] = var145[51ll] + var121[0ll];
  var146[51ll] = var146[51ll] + var121[1ll];
  var147[51ll] = var147[51ll] + var121[2ll];
  var148[51ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(34ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 0,51 : panda_link0_0,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(76ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 1,51 : panda_link1_0,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(118ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 2,51 : panda_link1_1,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(160ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 3,51 : panda_link1_2,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(202ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 4,51 : panda_link1_3,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(241ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 5,51 : panda_link2_0,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(280ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 6,51 : panda_link2_1,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(319ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 7,51 : panda_link2_2,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(358ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 8,51 : panda_link2_3,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(385ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 17,51 : panda_link5_0,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(412ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 18,51 : panda_link5_1,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(439ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 19,51 : panda_link5_2,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(466ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 20,51 : panda_link5_3,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(493ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 21,51 : panda_link5_4,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(520ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 22,51 : panda_link5_5,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(547ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 23,51 : panda_link5_6,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(574ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 24,51 : panda_link5_7,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(601ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 25,51 : panda_link5_8,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(628ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 26,51 : panda_link5_9,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(655ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 27,51 : panda_link5_10,panda_hand_14
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(682ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[51ll], var146[51ll], var147[51ll], var148[51ll], arg3, arg4); //collision pair: 28,51 : panda_link5_11,panda_hand_14
  var145[52ll] = ((var118[0ll] * 0.0106066018342972f) + (var118[1ll] * 0.0106066018342972f)) + (var118[2ll] * 0.157000005245209f);
  var146[52ll] = ((var118[3ll] * 0.0106066018342972f) + (var118[4ll] * 0.0106066018342972f)) + (var118[5ll] * 0.157000005245209f);
  var147[52ll] = ((var118[6ll] * 0.0106066018342972f) + (var118[7ll] * 0.0106066018342972f)) + (var118[8ll] * 0.157000005245209f);
  var145[52ll] = var145[52ll] + var121[0ll];
  var146[52ll] = var146[52ll] + var121[1ll];
  var147[52ll] = var147[52ll] + var121[2ll];
  var148[52ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(35ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 0,52 : panda_link0_0,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(77ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 1,52 : panda_link1_0,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(119ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 2,52 : panda_link1_1,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(161ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 3,52 : panda_link1_2,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(203ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 4,52 : panda_link1_3,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(242ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 5,52 : panda_link2_0,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(281ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 6,52 : panda_link2_1,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(320ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 7,52 : panda_link2_2,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(359ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 8,52 : panda_link2_3,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(386ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 17,52 : panda_link5_0,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(413ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 18,52 : panda_link5_1,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(440ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 19,52 : panda_link5_2,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(467ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 20,52 : panda_link5_3,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(494ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 21,52 : panda_link5_4,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(521ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 22,52 : panda_link5_5,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(548ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 23,52 : panda_link5_6,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(575ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 24,52 : panda_link5_7,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(602ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 25,52 : panda_link5_8,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(629ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 26,52 : panda_link5_9,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(656ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 27,52 : panda_link5_10,panda_hand_15
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(683ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[52ll], var146[52ll], var147[52ll], var148[52ll], arg3, arg4); //collision pair: 28,52 : panda_link5_11,panda_hand_15
  var145[53ll] = ((var118[0ll] * 0.0318198055028915f) + (var118[1ll] * 0.0318198055028915f)) + (var118[2ll] * 0.157000005245209f);
  var146[53ll] = ((var118[3ll] * 0.0318198055028915f) + (var118[4ll] * 0.0318198055028915f)) + (var118[5ll] * 0.157000005245209f);
  var147[53ll] = ((var118[6ll] * 0.0318198055028915f) + (var118[7ll] * 0.0318198055028915f)) + (var118[8ll] * 0.157000005245209f);
  var145[53ll] = var145[53ll] + var121[0ll];
  var146[53ll] = var146[53ll] + var121[1ll];
  var147[53ll] = var147[53ll] + var121[2ll];
  var148[53ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(36ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 0,53 : panda_link0_0,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(78ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 1,53 : panda_link1_0,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(120ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 2,53 : panda_link1_1,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(162ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 3,53 : panda_link1_2,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(204ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 4,53 : panda_link1_3,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(243ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 5,53 : panda_link2_0,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(282ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 6,53 : panda_link2_1,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(321ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 7,53 : panda_link2_2,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(360ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 8,53 : panda_link2_3,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(387ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 17,53 : panda_link5_0,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(414ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 18,53 : panda_link5_1,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(441ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 19,53 : panda_link5_2,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(468ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 20,53 : panda_link5_3,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(495ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 21,53 : panda_link5_4,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(522ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 22,53 : panda_link5_5,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(549ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 23,53 : panda_link5_6,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(576ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 24,53 : panda_link5_7,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(603ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 25,53 : panda_link5_8,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(630ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 26,53 : panda_link5_9,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(657ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 27,53 : panda_link5_10,panda_hand_16
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(684ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[53ll], var146[53ll], var147[53ll], var148[53ll], arg3, arg4); //collision pair: 28,53 : panda_link5_11,panda_hand_16
  var145[54ll] = ((var118[0ll] * 0.0530330091714859f) + (var118[1ll] * 0.0530330091714859f)) + (var118[2ll] * 0.157000005245209f);
  var146[54ll] = ((var118[3ll] * 0.0530330091714859f) + (var118[4ll] * 0.0530330091714859f)) + (var118[5ll] * 0.157000005245209f);
  var147[54ll] = ((var118[6ll] * 0.0530330091714859f) + (var118[7ll] * 0.0530330091714859f)) + (var118[8ll] * 0.157000005245209f);
  var145[54ll] = var145[54ll] + var121[0ll];
  var146[54ll] = var146[54ll] + var121[1ll];
  var147[54ll] = var147[54ll] + var121[2ll];
  var148[54ll] = 0.0240000002086163f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(37ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 0,54 : panda_link0_0,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(79ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 1,54 : panda_link1_0,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(121ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 2,54 : panda_link1_1,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(163ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 3,54 : panda_link1_2,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(205ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 4,54 : panda_link1_3,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(244ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 5,54 : panda_link2_0,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(283ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 6,54 : panda_link2_1,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(322ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 7,54 : panda_link2_2,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(361ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 8,54 : panda_link2_3,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(388ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 17,54 : panda_link5_0,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(415ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 18,54 : panda_link5_1,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(442ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 19,54 : panda_link5_2,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(469ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 20,54 : panda_link5_3,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(496ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 21,54 : panda_link5_4,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(523ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 22,54 : panda_link5_5,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(550ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 23,54 : panda_link5_6,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(577ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 24,54 : panda_link5_7,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(604ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 25,54 : panda_link5_8,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(631ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 26,54 : panda_link5_9,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(658ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 27,54 : panda_link5_10,panda_hand_17
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(685ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[54ll], var146[54ll], var147[54ll], var148[54ll], arg3, arg4); //collision pair: 28,54 : panda_link5_11,panda_hand_17
  var145[55ll] = ((var118[0ll] * 0.0565685406327248f) + (var118[1ll] * 0.0565685406327248f)) + (var118[2ll] * 0.187399998307228f);
  var146[55ll] = ((var118[3ll] * 0.0565685406327248f) + (var118[4ll] * 0.0565685406327248f)) + (var118[5ll] * 0.187399998307228f);
  var147[55ll] = ((var118[6ll] * 0.0565685406327248f) + (var118[7ll] * 0.0565685406327248f)) + (var118[8ll] * 0.187399998307228f);
  var145[55ll] = var145[55ll] + var121[0ll];
  var146[55ll] = var146[55ll] + var121[1ll];
  var147[55ll] = var147[55ll] + var121[2ll];
  var148[55ll] = 0.0120000001043081f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(38ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 0,55 : panda_link0_0,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(80ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 1,55 : panda_link1_0,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(122ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 2,55 : panda_link1_1,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(164ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 3,55 : panda_link1_2,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(206ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 4,55 : panda_link1_3,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(245ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 5,55 : panda_link2_0,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(284ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 6,55 : panda_link2_1,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(323ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 7,55 : panda_link2_2,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(362ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 8,55 : panda_link2_3,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(389ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 17,55 : panda_link5_0,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(416ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 18,55 : panda_link5_1,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(443ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 19,55 : panda_link5_2,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(470ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 20,55 : panda_link5_3,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(497ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 21,55 : panda_link5_4,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(524ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 22,55 : panda_link5_5,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(551ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 23,55 : panda_link5_6,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(578ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 24,55 : panda_link5_7,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(605ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 25,55 : panda_link5_8,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(632ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 26,55 : panda_link5_9,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(659ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 27,55 : panda_link5_10,panda_leftfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(686ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[55ll], var146[55ll], var147[55ll], var148[55ll], arg3, arg4); //collision pair: 28,55 : panda_link5_11,panda_leftfinger_0
  var145[56ll] = ((var118[0ll] * 0.0516187958419323f) + (var118[1ll] * 0.0516187958419323f)) + (var118[2ll] * 0.209399998188019f);
  var146[56ll] = ((var118[3ll] * 0.0516187958419323f) + (var118[4ll] * 0.0516187958419323f)) + (var118[5ll] * 0.209399998188019f);
  var147[56ll] = ((var118[6ll] * 0.0516187958419323f) + (var118[7ll] * 0.0516187958419323f)) + (var118[8ll] * 0.209399998188019f);
  var145[56ll] = var145[56ll] + var121[0ll];
  var146[56ll] = var146[56ll] + var121[1ll];
  var147[56ll] = var147[56ll] + var121[2ll];
  var148[56ll] = 0.0120000001043081f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(39ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 0,56 : panda_link0_0,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(81ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 1,56 : panda_link1_0,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(123ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 2,56 : panda_link1_1,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(165ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 3,56 : panda_link1_2,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(207ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 4,56 : panda_link1_3,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(246ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 5,56 : panda_link2_0,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(285ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 6,56 : panda_link2_1,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(324ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 7,56 : panda_link2_2,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(363ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 8,56 : panda_link2_3,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(390ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 17,56 : panda_link5_0,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(417ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 18,56 : panda_link5_1,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(444ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 19,56 : panda_link5_2,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(471ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 20,56 : panda_link5_3,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(498ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 21,56 : panda_link5_4,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(525ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 22,56 : panda_link5_5,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(552ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 23,56 : panda_link5_6,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(579ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 24,56 : panda_link5_7,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(606ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 25,56 : panda_link5_8,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(633ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 26,56 : panda_link5_9,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(660ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 27,56 : panda_link5_10,panda_leftfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(687ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[56ll], var146[56ll], var147[56ll], var148[56ll], arg3, arg4); //collision pair: 28,56 : panda_link5_11,panda_leftfinger_1
  var145[57ll] = ((var118[0ll] * -0.0565685406327248f) + (var118[1ll] * -0.0565685406327248f)) + (var118[2ll] * 0.187399998307228f);
  var146[57ll] = ((var118[3ll] * -0.0565685406327248f) + (var118[4ll] * -0.0565685406327248f)) + (var118[5ll] * 0.187399998307228f);
  var147[57ll] = ((var118[6ll] * -0.0565685406327248f) + (var118[7ll] * -0.0565685406327248f)) + (var118[8ll] * 0.187399998307228f);
  var145[57ll] = var145[57ll] + var121[0ll];
  var146[57ll] = var146[57ll] + var121[1ll];
  var147[57ll] = var147[57ll] + var121[2ll];
  var148[57ll] = 0.0120000001043081f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(40ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 0,57 : panda_link0_0,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(82ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 1,57 : panda_link1_0,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(124ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 2,57 : panda_link1_1,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(166ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 3,57 : panda_link1_2,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(208ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 4,57 : panda_link1_3,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(247ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 5,57 : panda_link2_0,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(286ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 6,57 : panda_link2_1,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(325ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 7,57 : panda_link2_2,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(364ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 8,57 : panda_link2_3,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(391ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 17,57 : panda_link5_0,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(418ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 18,57 : panda_link5_1,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(445ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 19,57 : panda_link5_2,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(472ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 20,57 : panda_link5_3,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(499ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 21,57 : panda_link5_4,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(526ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 22,57 : panda_link5_5,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(553ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 23,57 : panda_link5_6,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(580ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 24,57 : panda_link5_7,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(607ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 25,57 : panda_link5_8,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(634ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 26,57 : panda_link5_9,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(661ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 27,57 : panda_link5_10,panda_rightfinger_0
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(688ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[57ll], var146[57ll], var147[57ll], var148[57ll], arg3, arg4); //collision pair: 28,57 : panda_link5_11,panda_rightfinger_0
  var145[58ll] = ((var118[0ll] * -0.0516187958419323f) + (var118[1ll] * -0.0516187958419323f)) + (var118[2ll] * 0.209399998188019f);
  var146[58ll] = ((var118[3ll] * -0.0516187958419323f) + (var118[4ll] * -0.0516187958419323f)) + (var118[5ll] * 0.209399998188019f);
  var147[58ll] = ((var118[6ll] * -0.0516187958419323f) + (var118[7ll] * -0.0516187958419323f)) + (var118[8ll] * 0.209399998188019f);
  var145[58ll] = var145[58ll] + var121[0ll];
  var146[58ll] = var146[58ll] + var121[1ll];
  var147[58ll] = var147[58ll] + var121[2ll];
  var148[58ll] = 0.0120000001043081f;
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(41ll, var137, var144, var145[0ll], var146[0ll], var147[0ll], var148[0ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 0,58 : panda_link0_0,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(83ll, var138, var144, var145[1ll], var146[1ll], var147[1ll], var148[1ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 1,58 : panda_link1_0,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(125ll, var138, var144, var145[2ll], var146[2ll], var147[2ll], var148[2ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 2,58 : panda_link1_1,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(167ll, var138, var144, var145[3ll], var146[3ll], var147[3ll], var148[3ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 3,58 : panda_link1_2,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(209ll, var138, var144, var145[4ll], var146[4ll], var147[4ll], var148[4ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 4,58 : panda_link1_3,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(248ll, var139, var144, var145[5ll], var146[5ll], var147[5ll], var148[5ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 5,58 : panda_link2_0,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(287ll, var139, var144, var145[6ll], var146[6ll], var147[6ll], var148[6ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 6,58 : panda_link2_1,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(326ll, var139, var144, var145[7ll], var146[7ll], var147[7ll], var148[7ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 7,58 : panda_link2_2,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(365ll, var139, var144, var145[8ll], var146[8ll], var147[8ll], var148[8ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 8,58 : panda_link2_3,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(392ll, var142, var144, var145[17ll], var146[17ll], var147[17ll], var148[17ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 17,58 : panda_link5_0,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(419ll, var142, var144, var145[18ll], var146[18ll], var147[18ll], var148[18ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 18,58 : panda_link5_1,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(446ll, var142, var144, var145[19ll], var146[19ll], var147[19ll], var148[19ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 19,58 : panda_link5_2,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(473ll, var142, var144, var145[20ll], var146[20ll], var147[20ll], var148[20ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 20,58 : panda_link5_3,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(500ll, var142, var144, var145[21ll], var146[21ll], var147[21ll], var148[21ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 21,58 : panda_link5_4,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(527ll, var142, var144, var145[22ll], var146[22ll], var147[22ll], var148[22ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 22,58 : panda_link5_5,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(554ll, var142, var144, var145[23ll], var146[23ll], var147[23ll], var148[23ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 23,58 : panda_link5_6,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(581ll, var142, var144, var145[24ll], var146[24ll], var147[24ll], var148[24ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 24,58 : panda_link5_7,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(608ll, var142, var144, var145[25ll], var146[25ll], var147[25ll], var148[25ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 25,58 : panda_link5_8,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(635ll, var142, var144, var145[26ll], var146[26ll], var147[26ll], var148[26ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 26,58 : panda_link5_9,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(662ll, var142, var144, var145[27ll], var146[27ll], var147[27ll], var148[27ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 27,58 : panda_link5_10,panda_rightfinger_1
  cg_sd_runtime::compute_sph_sph_cp_sd_grad(689ll, var142, var144, var145[28ll], var146[28ll], var147[28ll], var148[28ll], var145[58ll], var146[58ll], var147[58ll], var148[58ll], arg3, arg4); //collision pair: 28,58 : panda_link5_11,panda_rightfinger_1
}

}
