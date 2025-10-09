// clang-format off

#include "Eigen/Dense"

#include "ctup/typedefs.h"

#include "rla_fkcc_early_exit/runtime/typedefs.h"

#include "rla_fkcc_early_exit/runtime/collision.h"

#include <iostream>

namespace ctup_gen {

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

static int fkcc (vamp::collision::Environment<blaze::StaticVector<float, 8>> const& arg4, ctup_runtime::ConfigurationBlockRobot<ctup_runtime::robots::Baxter> const& arg5) {
  blaze::StaticVector<float, 8> var50[16];
  blaze::StaticVector<float, 8> var51;
  blaze::StaticVector<float, 8> var52;
  blaze::StaticVector<float, 8> var53[16];
  blaze::StaticVector<float, 8> var54;
  blaze::StaticVector<float, 8> var55;
  blaze::StaticVector<float, 8> var56[16];
  blaze::StaticVector<float, 8> var57;
  blaze::StaticVector<float, 8> var58;
  blaze::StaticVector<float, 8> var59[16];
  blaze::StaticVector<float, 8> var60;
  blaze::StaticVector<float, 8> var61;
  blaze::StaticVector<float, 8> var62[16];
  blaze::StaticVector<float, 8> var63;
  blaze::StaticVector<float, 8> var64;
  blaze::StaticVector<float, 8> var65[16];
  blaze::StaticVector<float, 8> var66;
  blaze::StaticVector<float, 8> var67;
  blaze::StaticVector<float, 8> var68[16];
  blaze::StaticVector<float, 8> var69;
  blaze::StaticVector<float, 8> var70;
  blaze::StaticVector<float, 8> var71[16];
  blaze::StaticVector<float, 8> var72;
  blaze::StaticVector<float, 8> var73;
  blaze::StaticVector<float, 8> var74[16];
  blaze::StaticVector<float, 8> var75;
  blaze::StaticVector<float, 8> var76;
  blaze::StaticVector<float, 8> var77[16];
  blaze::StaticVector<float, 8> var78;
  blaze::StaticVector<float, 8> var79;
  blaze::StaticVector<float, 8> var80[16];
  blaze::StaticVector<float, 8> var81;
  blaze::StaticVector<float, 8> var82;
  blaze::StaticVector<float, 8> var83[16];
  blaze::StaticVector<float, 8> var84;
  blaze::StaticVector<float, 8> var85;
  blaze::StaticVector<float, 8> var86[16];
  blaze::StaticVector<float, 8> var87;
  blaze::StaticVector<float, 8> var88;
  blaze::StaticVector<float, 8> var89[16];
  blaze::StaticVector<float, 8> var90;
  blaze::StaticVector<float, 8> var91;
  blaze::StaticVector<float, 8> var95[16];
  blaze::StaticVector<float, 8> var98[16];
  blaze::StaticVector<float, 8> var101[16];
  blaze::StaticVector<float, 8> var104[16];
  blaze::StaticVector<float, 8> var107[16];
  blaze::StaticVector<float, 8> var110[16];
  blaze::StaticVector<float, 8> var113[16];
  blaze::StaticVector<float, 8> var116[16];
  blaze::StaticVector<float, 8> var119[16];
  blaze::StaticVector<float, 8> var122[16];
  blaze::StaticVector<float, 8> var125[16];
  blaze::StaticVector<float, 8> var128[16];
  blaze::StaticVector<float, 8> var131[16];
  blaze::StaticVector<float, 8> var134[16];
  blaze::StaticVector<float, 8> var137[33];
  blaze::StaticVector<float, 8> var138[33];
  blaze::StaticVector<float, 8> var139[33];
  float var140[33];
  unsigned long int var141[33];
  std::array<blaze::StaticVector<float, 8>, 4> var142[33];
  std::array<blaze::StaticVector<float, 8>, 4> var143[33];
  std::array<blaze::StaticVector<float, 8>, 4> var144[33];
  std::array<float, 4> var145[33];
  blaze::StaticVector<float, 8> var146[16];
  var137[0ll] = ((1.0f * -0.0439999997615814f) + (0 * 0.0f)) + (0 * 0.222000002861023f);
  var138[0ll] = ((0 * -0.0439999997615814f) + (1.0f * 0.0f)) + (0 * 0.222000002861023f);
  var139[0ll] = ((0 * -0.0439999997615814f) + (0 * 0.0f)) + (1.0f * 0.222000002861023f);
  var137[0ll] = var137[0ll] + 0;
  var138[0ll] = var138[0ll] + 0;
  var139[0ll] = var139[0ll] + 0;
  var140[0ll] = 0.409000009298325f;
  var141[0ll] = 3ll;
  var142[0ll][0ll] = ((1.0f * -0.025000000372529f) + (0 * -0.100000001490116f)) + (0 * 0.100000001490116f);
  var143[0ll][0ll] = ((0 * -0.025000000372529f) + (1.0f * -0.100000001490116f)) + (0 * 0.100000001490116f);
  var144[0ll][0ll] = ((0 * -0.025000000372529f) + (0 * -0.100000001490116f)) + (1.0f * 0.100000001490116f);
  var142[0ll][0ll] = var142[0ll][0ll] + 0;
  var143[0ll][0ll] = var143[0ll][0ll] + 0;
  var144[0ll][0ll] = var144[0ll][0ll] + 0;
  var145[0ll][0ll] = 0.25f;
  var142[0ll][1ll] = ((1.0f * -0.025000000372529f) + (0 * 0.100000001490116f)) + (0 * 0.100000001490116f);
  var143[0ll][1ll] = ((0 * -0.025000000372529f) + (1.0f * 0.100000001490116f)) + (0 * 0.100000001490116f);
  var144[0ll][1ll] = ((0 * -0.025000000372529f) + (0 * 0.100000001490116f)) + (1.0f * 0.100000001490116f);
  var142[0ll][1ll] = var142[0ll][1ll] + 0;
  var143[0ll][1ll] = var143[0ll][1ll] + 0;
  var144[0ll][1ll] = var144[0ll][1ll] + 0;
  var145[0ll][1ll] = 0.25f;
  var142[0ll][2ll] = ((1.0f * -0.0649999976158142f) + (0 * 0.0f)) + (0 * 0.400000005960464f);
  var143[0ll][2ll] = ((0 * -0.0649999976158142f) + (1.0f * 0.0f)) + (0 * 0.400000005960464f);
  var144[0ll][2ll] = ((0 * -0.0649999976158142f) + (0 * 0.0f)) + (1.0f * 0.400000005960464f);
  var142[0ll][2ll] = var142[0ll][2ll] + 0;
  var143[0ll][2ll] = var143[0ll][2ll] + 0;
  var144[0ll][2ll] = var144[0ll][2ll] + 0;
  var145[0ll][2ll] = 0.230000004172325f;
  var137[1ll] = ((1.0f * 0.0399999991059303f) + (0 * 0.0f)) + (0 * 0.685999989509583f);
  var138[1ll] = ((0 * 0.0399999991059303f) + (1.0f * 0.0f)) + (0 * 0.685999989509583f);
  var139[1ll] = ((0 * 0.0399999991059303f) + (0 * 0.0f)) + (1.0f * 0.685999989509583f);
  var137[1ll] = var137[1ll] + 0;
  var138[1ll] = var138[1ll] + 0;
  var139[1ll] = var139[1ll] + 0;
  var140[1ll] = 0.200000002980232f;
  var141[1ll] = 1ll;
  var142[1ll][0ll] = ((1.0f * 0.0399999991059303f) + (0 * 0.0f)) + (0 * 0.685999989509583f);
  var143[1ll][0ll] = ((0 * 0.0399999991059303f) + (1.0f * 0.0f)) + (0 * 0.685999989509583f);
  var144[1ll][0ll] = ((0 * 0.0399999991059303f) + (0 * 0.0f)) + (1.0f * 0.685999989509583f);
  var142[1ll][0ll] = var142[1ll][0ll] + 0;
  var143[1ll][0ll] = var143[1ll][0ll] + 0;
  var144[1ll][0ll] = var144[1ll][0ll] + 0;
  var145[1ll][0ll] = 0.200000002980232f;
  var137[17ll] = ((1.0f * 0.0f) + (0 * 0.0f)) + (0 * -0.600000023841858f);
  var138[17ll] = ((0 * 0.0f) + (1.0f * 0.0f)) + (0 * -0.600000023841858f);
  var139[17ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * -0.600000023841858f);
  var137[17ll] = var137[17ll] + 0;
  var138[17ll] = var138[17ll] + 0;
  var139[17ll] = var139[17ll] + 0;
  var140[17ll] = 0.5f;
  var141[17ll] = 1ll;
  var142[17ll][0ll] = ((1.0f * 0.0f) + (0 * 0.0f)) + (0 * -0.600000023841858f);
  var143[17ll][0ll] = ((0 * 0.0f) + (1.0f * 0.0f)) + (0 * -0.600000023841858f);
  var144[17ll][0ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * -0.600000023841858f);
  var142[17ll][0ll] = var142[17ll][0ll] + 0;
  var143[17ll][0ll] = var143[17ll][0ll] + 0;
  var144[17ll][0ll] = var144[17ll][0ll] + 0;
  var145[17ll][0ll] = 0.5f;
  int var151;
  var151 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 2,17 : left_upper_shoulder_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 6,17 : left_upper_forearm_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 7,17 : left_lower_forearm_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 8,17 : left_wrist_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 9,17 : left_hand_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 10,17 : left_gripper_base_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 11,17 : l_gripper_l_finger_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 12,17 : l_gripper_l_finger_2_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 13,17 : l_gripper_l_finger_tip_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 14,17 : l_gripper_r_finger_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 15,17 : l_gripper_r_finger_2_0,pedestal_0
  var151 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll]);
  if (var151)
    return 0; //collision pair: 16,17 : l_gripper_r_finger_tip_0,pedestal_0
  blaze::StaticVector<float, 8> var152 = arg5[0ll];
  var51 = sin(var152);
  var52 = cos(var152);
  var50[0ll] = var52;
  var50[1ll] = -(var51);
  var50[2ll] = var51;
  var50[3ll] = var52;
  blaze::StaticVector<float, 8> var153;
  var153 = 0;
  var153 = var153 + (0.707105457782745f * var50[0ll]);
  var153 = var153 + (-0.707108080387115f * var50[2ll]);
  var153 = var153 + (0 * 0);
  var153 = var153 + (0.0640272423624992f * 0);
  var146[0ll] = var153;
  blaze::StaticVector<float, 8> var154;
  var154 = 0;
  var154 = var154 + (0.707105457782745f * var50[1ll]);
  var154 = var154 + (-0.707108080387115f * var50[3ll]);
  var154 = var154 + (0 * 0);
  var154 = var154 + (0.0640272423624992f * 0);
  var146[1ll] = var154;
  blaze::StaticVector<float, 8> var155;
  var155 = 0;
  var155 = var155 + (0.707108080387115f * var50[0ll]);
  var155 = var155 + (0.707105457782745f * var50[2ll]);
  var155 = var155 + (0 * 0);
  var155 = var155 + (0.259027391672134f * 0);
  var146[2ll] = var155;
  blaze::StaticVector<float, 8> var156;
  var156 = 0;
  var156 = var156 + (0.707108080387115f * var50[1ll]);
  var156 = var156 + (0.707105457782745f * var50[3ll]);
  var156 = var156 + (0 * 0);
  var156 = var156 + (0.259027391672134f * 0);
  var146[3ll] = var156;
  var95[0ll] = var146[0ll];
  var95[1ll] = var146[1ll];
  var95[2ll] = var146[2ll];
  var95[3ll] = var146[3ll];
  var137[2ll] = ((var95[0ll] * 0.0f) + (var95[1ll] * 0.0f)) + (0 * 0.174999997019768f);
  var138[2ll] = ((var95[2ll] * 0.0f) + (var95[3ll] * 0.0f)) + (0 * 0.174999997019768f);
  var139[2ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.174999997019768f);
  var137[2ll] = var137[2ll] + 0.0640272423624992f;
  var138[2ll] = var138[2ll] + 0.259027391672134f;
  var139[2ll] = var139[2ll] + 0.129626005887985f;
  var140[2ll] = 0.174999997019768f;
  var141[2ll] = 2ll;
  var142[2ll][0ll] = ((var95[0ll] * 0.0f) + (var95[1ll] * 0.0f)) + (0 * 0.25f);
  var143[2ll][0ll] = ((var95[2ll] * 0.0f) + (var95[3ll] * 0.0f)) + (0 * 0.25f);
  var144[2ll][0ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.25f);
  var142[2ll][0ll] = var142[2ll][0ll] + 0.0640272423624992f;
  var143[2ll][0ll] = var143[2ll][0ll] + 0.259027391672134f;
  var144[2ll][0ll] = var144[2ll][0ll] + 0.129626005887985f;
  var145[2ll][0ll] = 0.100000001490116f;
  var142[2ll][1ll] = ((var95[0ll] * 0.0f) + (var95[1ll] * 0.0f)) + (0 * 0.100000001490116f);
  var143[2ll][1ll] = ((var95[2ll] * 0.0f) + (var95[3ll] * 0.0f)) + (0 * 0.100000001490116f);
  var144[2ll][1ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.100000001490116f);
  var142[2ll][1ll] = var142[2ll][1ll] + 0.0640272423624992f;
  var143[2ll][1ll] = var143[2ll][1ll] + 0.259027391672134f;
  var144[2ll][1ll] = var144[2ll][1ll] + 0.129626005887985f;
  var145[2ll][1ll] = 0.100000001490116f;
  int var157;
  var157 = ctup_runtime::link_vs_environment_collision(var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], arg4);
  if (var157)
    return 0;
  blaze::StaticVector<float, 8> var158 = arg5[1ll];
  var54 = sin(var158);
  var55 = cos(var158);
  var53[0ll] = var55;
  var53[1ll] = -(var54);
  var53[2ll] = var54;
  var53[3ll] = var55;
  blaze::StaticVector<float, 8> var159;
  var159 = 0;
  var159 = var159 + (1.0f * var53[0ll]);
  var159 = var159 + (0 * var53[2ll]);
  var159 = var159 + (0 * 0);
  var159 = var159 + (0.0689999982714653f * 0);
  var146[0ll] = var159;
  blaze::StaticVector<float, 8> var160;
  var160 = 0;
  var160 = var160 + (1.0f * var53[1ll]);
  var160 = var160 + (0 * var53[3ll]);
  var160 = var160 + (0 * 0);
  var160 = var160 + (0.0689999982714653f * 0);
  var146[1ll] = var160;
  blaze::StaticVector<float, 8> var161;
  var161 = 0;
  var161 = var161 + (0 * var53[0ll]);
  var161 = var161 + (-1.0f * var53[2ll]);
  var161 = var161 + (0 * 0);
  var161 = var161 + (0.270350009202957f * 0);
  var146[2ll] = var161;
  blaze::StaticVector<float, 8> var162;
  var162 = 0;
  var162 = var162 + (0 * var53[1ll]);
  var162 = var162 + (-1.0f * var53[3ll]);
  var162 = var162 + (0 * 0);
  var162 = var162 + (0.270350009202957f * 0);
  var146[3ll] = var162;
  blaze::StaticVector<float, 8> var163;
  var163 = 0;
  var163 = var163 + (var95[0ll] * var146[0ll]);
  var163 = var163 + (var95[1ll] * 0);
  var163 = var163 + (0 * var146[2ll]);
  var163 = var163 + (0.0640272423624992f * 0);
  var98[0ll] = var163;
  blaze::StaticVector<float, 8> var164;
  var164 = 0;
  var164 = var164 + (var95[0ll] * var146[1ll]);
  var164 = var164 + (var95[1ll] * 0);
  var164 = var164 + (0 * var146[3ll]);
  var164 = var164 + (0.0640272423624992f * 0);
  var98[1ll] = var164;
  blaze::StaticVector<float, 8> var165;
  var165 = 0;
  var165 = var165 + (var95[0ll] * 0);
  var165 = var165 + (var95[1ll] * 1.0f);
  var165 = var165 + (0 * 0);
  var165 = var165 + (0.0640272423624992f * 0);
  var98[2ll] = var165;
  blaze::StaticVector<float, 8> var166;
  var166 = 0;
  var166 = var166 + (var95[0ll] * 0.0689999982714653f);
  var166 = var166 + (var95[1ll] * 0);
  var166 = var166 + (0 * 0.270350009202957f);
  var166 = var166 + (0.0640272423624992f * 1.0f);
  var98[3ll] = var166;
  blaze::StaticVector<float, 8> var167;
  var167 = 0;
  var167 = var167 + (var95[2ll] * var146[0ll]);
  var167 = var167 + (var95[3ll] * 0);
  var167 = var167 + (0 * var146[2ll]);
  var167 = var167 + (0.259027391672134f * 0);
  var98[4ll] = var167;
  blaze::StaticVector<float, 8> var168;
  var168 = 0;
  var168 = var168 + (var95[2ll] * var146[1ll]);
  var168 = var168 + (var95[3ll] * 0);
  var168 = var168 + (0 * var146[3ll]);
  var168 = var168 + (0.259027391672134f * 0);
  var98[5ll] = var168;
  blaze::StaticVector<float, 8> var169;
  var169 = 0;
  var169 = var169 + (var95[2ll] * 0);
  var169 = var169 + (var95[3ll] * 1.0f);
  var169 = var169 + (0 * 0);
  var169 = var169 + (0.259027391672134f * 0);
  var98[6ll] = var169;
  blaze::StaticVector<float, 8> var170;
  var170 = 0;
  var170 = var170 + (var95[2ll] * 0.0689999982714653f);
  var170 = var170 + (var95[3ll] * 0);
  var170 = var170 + (0 * 0.270350009202957f);
  var170 = var170 + (0.259027391672134f * 1.0f);
  var98[7ll] = var170;
  blaze::StaticVector<float, 8> var171;
  var171 = 0;
  var171 = var171 + (0 * var146[0ll]);
  var171 = var171 + (0 * 0);
  var171 = var171 + (1.0f * var146[2ll]);
  var171 = var171 + (0.129626005887985f * 0);
  var98[8ll] = var171;
  blaze::StaticVector<float, 8> var172;
  var172 = 0;
  var172 = var172 + (0 * var146[1ll]);
  var172 = var172 + (0 * 0);
  var172 = var172 + (1.0f * var146[3ll]);
  var172 = var172 + (0.129626005887985f * 0);
  var98[9ll] = var172;
  var137[3ll] = ((var98[0ll] * 0.0f) + (var98[1ll] * 0.0f)) + (var98[2ll] * 0.0f);
  var138[3ll] = ((var98[4ll] * 0.0f) + (var98[5ll] * 0.0f)) + (var98[6ll] * 0.0f);
  var139[3ll] = ((var98[8ll] * 0.0f) + (var98[9ll] * 0.0f)) + (0 * 0.0f);
  var137[3ll] = var137[3ll] + var98[3ll];
  var138[3ll] = var138[3ll] + var98[7ll];
  var139[3ll] = var139[3ll] + 0.399976015090942f;
  var140[3ll] = 0.100000001490116f;
  var141[3ll] = 0ll;
  int var173;
  var173 = ctup_runtime::link_vs_environment_collision(var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], arg4);
  if (var173)
    return 0;
  blaze::StaticVector<float, 8> var174 = arg5[2ll];
  var57 = sin(var174);
  var58 = cos(var174);
  var56[0ll] = var58;
  var56[1ll] = -(var57);
  var56[2ll] = var57;
  var56[3ll] = var58;
  blaze::StaticVector<float, 8> var175;
  var175 = 0;
  var175 = var175 + (1.0f * var56[0ll]);
  var175 = var175 + (0 * var56[2ll]);
  var175 = var175 + (0 * 0);
  var175 = var175 + (0 * 0);
  var146[0ll] = var175;
  blaze::StaticVector<float, 8> var176;
  var176 = 0;
  var176 = var176 + (1.0f * var56[1ll]);
  var176 = var176 + (0 * var56[3ll]);
  var176 = var176 + (0 * 0);
  var176 = var176 + (0 * 0);
  var146[1ll] = var176;
  blaze::StaticVector<float, 8> var177;
  var177 = 0;
  var177 = var177 + (0 * var56[0ll]);
  var177 = var177 + (1.0f * var56[2ll]);
  var177 = var177 + (0 * 0);
  var177 = var177 + (0 * 0);
  var146[2ll] = var177;
  blaze::StaticVector<float, 8> var178;
  var178 = 0;
  var178 = var178 + (0 * var56[1ll]);
  var178 = var178 + (1.0f * var56[3ll]);
  var178 = var178 + (0 * 0);
  var178 = var178 + (0 * 0);
  var146[3ll] = var178;
  blaze::StaticVector<float, 8> var179;
  var179 = 0;
  var179 = var179 + (var98[0ll] * 0);
  var179 = var179 + (var98[1ll] * var146[0ll]);
  var179 = var179 + (var98[2ll] * var146[2ll]);
  var179 = var179 + (var98[3ll] * 0);
  var101[0ll] = var179;
  blaze::StaticVector<float, 8> var180;
  var180 = 0;
  var180 = var180 + (var98[0ll] * 0);
  var180 = var180 + (var98[1ll] * var146[1ll]);
  var180 = var180 + (var98[2ll] * var146[3ll]);
  var180 = var180 + (var98[3ll] * 0);
  var101[1ll] = var180;
  blaze::StaticVector<float, 8> var181;
  var181 = 0;
  var181 = var181 + (var98[0ll] * 1.0f);
  var181 = var181 + (var98[1ll] * 0);
  var181 = var181 + (var98[2ll] * 0);
  var181 = var181 + (var98[3ll] * 0);
  var101[2ll] = var181;
  blaze::StaticVector<float, 8> var182;
  var182 = 0;
  var182 = var182 + (var98[0ll] * 0.101999998092651f);
  var182 = var182 + (var98[1ll] * 0);
  var182 = var182 + (var98[2ll] * 0);
  var182 = var182 + (var98[3ll] * 1.0f);
  var101[3ll] = var182;
  blaze::StaticVector<float, 8> var183;
  var183 = 0;
  var183 = var183 + (var98[4ll] * 0);
  var183 = var183 + (var98[5ll] * var146[0ll]);
  var183 = var183 + (var98[6ll] * var146[2ll]);
  var183 = var183 + (var98[7ll] * 0);
  var101[4ll] = var183;
  blaze::StaticVector<float, 8> var184;
  var184 = 0;
  var184 = var184 + (var98[4ll] * 0);
  var184 = var184 + (var98[5ll] * var146[1ll]);
  var184 = var184 + (var98[6ll] * var146[3ll]);
  var184 = var184 + (var98[7ll] * 0);
  var101[5ll] = var184;
  blaze::StaticVector<float, 8> var185;
  var185 = 0;
  var185 = var185 + (var98[4ll] * 1.0f);
  var185 = var185 + (var98[5ll] * 0);
  var185 = var185 + (var98[6ll] * 0);
  var185 = var185 + (var98[7ll] * 0);
  var101[6ll] = var185;
  blaze::StaticVector<float, 8> var186;
  var186 = 0;
  var186 = var186 + (var98[4ll] * 0.101999998092651f);
  var186 = var186 + (var98[5ll] * 0);
  var186 = var186 + (var98[6ll] * 0);
  var186 = var186 + (var98[7ll] * 1.0f);
  var101[7ll] = var186;
  blaze::StaticVector<float, 8> var187;
  var187 = 0;
  var187 = var187 + (var98[8ll] * 0);
  var187 = var187 + (var98[9ll] * var146[0ll]);
  var187 = var187 + (0 * var146[2ll]);
  var187 = var187 + (0.399976015090942f * 0);
  var101[8ll] = var187;
  blaze::StaticVector<float, 8> var188;
  var188 = 0;
  var188 = var188 + (var98[8ll] * 0);
  var188 = var188 + (var98[9ll] * var146[1ll]);
  var188 = var188 + (0 * var146[3ll]);
  var188 = var188 + (0.399976015090942f * 0);
  var101[9ll] = var188;
  blaze::StaticVector<float, 8> var189;
  var189 = 0;
  var189 = var189 + (var98[8ll] * 1.0f);
  var189 = var189 + (var98[9ll] * 0);
  var189 = var189 + (0 * 0);
  var189 = var189 + (0.399976015090942f * 0);
  var101[10ll] = var189;
  blaze::StaticVector<float, 8> var190;
  var190 = 0;
  var190 = var190 + (var98[8ll] * 0.101999998092651f);
  var190 = var190 + (var98[9ll] * 0);
  var190 = var190 + (0 * 0);
  var190 = var190 + (0.399976015090942f * 1.0f);
  var101[11ll] = var190;
  var137[4ll] = ((var101[0ll] * -0.00999999977648258f) + (var101[1ll] * 0.0f)) + (var101[2ll] * 0.109999999403954f);
  var138[4ll] = ((var101[4ll] * -0.00999999977648258f) + (var101[5ll] * 0.0f)) + (var101[6ll] * 0.109999999403954f);
  var139[4ll] = ((var101[8ll] * -0.00999999977648258f) + (var101[9ll] * 0.0f)) + (var101[10ll] * 0.109999999403954f);
  var137[4ll] = var137[4ll] + var101[3ll];
  var138[4ll] = var138[4ll] + var101[7ll];
  var139[4ll] = var139[4ll] + var101[11ll];
  var140[4ll] = 0.189999997615814f;
  var141[4ll] = 3ll;
  var142[4ll][0ll] = ((var101[0ll] * -0.0199999995529652f) + (var101[1ll] * 0.0f)) + (var101[2ll] * 0.219999998807907f);
  var143[4ll][0ll] = ((var101[4ll] * -0.0199999995529652f) + (var101[5ll] * 0.0f)) + (var101[6ll] * 0.219999998807907f);
  var144[4ll][0ll] = ((var101[8ll] * -0.0199999995529652f) + (var101[9ll] * 0.0f)) + (var101[10ll] * 0.219999998807907f);
  var142[4ll][0ll] = var142[4ll][0ll] + var101[3ll];
  var143[4ll][0ll] = var143[4ll][0ll] + var101[7ll];
  var144[4ll][0ll] = var144[4ll][0ll] + var101[11ll];
  var145[4ll][0ll] = 0.0799999982118607f;
  var142[4ll][1ll] = ((var101[0ll] * -0.00999999977648258f) + (var101[1ll] * 0.0f)) + (var101[2ll] * 0.109999999403954f);
  var143[4ll][1ll] = ((var101[4ll] * -0.00999999977648258f) + (var101[5ll] * 0.0f)) + (var101[6ll] * 0.109999999403954f);
  var144[4ll][1ll] = ((var101[8ll] * -0.00999999977648258f) + (var101[9ll] * 0.0f)) + (var101[10ll] * 0.109999999403954f);
  var142[4ll][1ll] = var142[4ll][1ll] + var101[3ll];
  var143[4ll][1ll] = var143[4ll][1ll] + var101[7ll];
  var144[4ll][1ll] = var144[4ll][1ll] + var101[11ll];
  var145[4ll][1ll] = 0.0799999982118607f;
  var142[4ll][2ll] = ((var101[0ll] * 0.0f) + (var101[1ll] * 0.0f)) + (var101[2ll] * 0.0f);
  var143[4ll][2ll] = ((var101[4ll] * 0.0f) + (var101[5ll] * 0.0f)) + (var101[6ll] * 0.0f);
  var144[4ll][2ll] = ((var101[8ll] * 0.0f) + (var101[9ll] * 0.0f)) + (var101[10ll] * 0.0f);
  var142[4ll][2ll] = var142[4ll][2ll] + var101[3ll];
  var143[4ll][2ll] = var143[4ll][2ll] + var101[7ll];
  var144[4ll][2ll] = var144[4ll][2ll] + var101[11ll];
  var145[4ll][2ll] = 0.0799999982118607f;
  int var191;
  var191 = ctup_runtime::link_vs_environment_collision(var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], arg4);
  if (var191)
    return 0;
  blaze::StaticVector<float, 8> var192 = arg5[3ll];
  var60 = sin(var192);
  var61 = cos(var192);
  var59[0ll] = var61;
  var59[1ll] = -(var60);
  var59[2ll] = var60;
  var59[3ll] = var61;
  blaze::StaticVector<float, 8> var193;
  var193 = 0;
  var193 = var193 + (0 * var59[0ll]);
  var193 = var193 + (1.0f * var59[2ll]);
  var193 = var193 + (0 * 0);
  var193 = var193 + (0.0689999982714653f * 0);
  var146[4ll] = var193;
  blaze::StaticVector<float, 8> var194;
  var194 = 0;
  var194 = var194 + (0 * var59[1ll]);
  var194 = var194 + (1.0f * var59[3ll]);
  var194 = var194 + (0 * 0);
  var194 = var194 + (0.0689999982714653f * 0);
  var146[5ll] = var194;
  blaze::StaticVector<float, 8> var195;
  var195 = 0;
  var195 = var195 + (1.0f * var59[0ll]);
  var195 = var195 + (0 * var59[2ll]);
  var195 = var195 + (0 * 0);
  var195 = var195 + (0.262419998645782f * 0);
  var146[2ll] = var195;
  blaze::StaticVector<float, 8> var196;
  var196 = 0;
  var196 = var196 + (1.0f * var59[1ll]);
  var196 = var196 + (0 * var59[3ll]);
  var196 = var196 + (0 * 0);
  var196 = var196 + (0.262419998645782f * 0);
  var146[3ll] = var196;
  blaze::StaticVector<float, 8> var197;
  var197 = 0;
  var197 = var197 + (var101[0ll] * var146[4ll]);
  var197 = var197 + (var101[1ll] * 0);
  var197 = var197 + (var101[2ll] * var146[2ll]);
  var197 = var197 + (var101[3ll] * 0);
  var104[0ll] = var197;
  blaze::StaticVector<float, 8> var198;
  var198 = 0;
  var198 = var198 + (var101[0ll] * var146[5ll]);
  var198 = var198 + (var101[1ll] * 0);
  var198 = var198 + (var101[2ll] * var146[3ll]);
  var198 = var198 + (var101[3ll] * 0);
  var104[1ll] = var198;
  blaze::StaticVector<float, 8> var199;
  var199 = 0;
  var199 = var199 + (var101[0ll] * 0);
  var199 = var199 + (var101[1ll] * 1.0f);
  var199 = var199 + (var101[2ll] * 0);
  var199 = var199 + (var101[3ll] * 0);
  var104[2ll] = var199;
  blaze::StaticVector<float, 8> var200;
  var200 = 0;
  var200 = var200 + (var101[0ll] * 0.0689999982714653f);
  var200 = var200 + (var101[1ll] * 0);
  var200 = var200 + (var101[2ll] * 0.262419998645782f);
  var200 = var200 + (var101[3ll] * 1.0f);
  var104[3ll] = var200;
  blaze::StaticVector<float, 8> var201;
  var201 = 0;
  var201 = var201 + (var101[4ll] * var146[4ll]);
  var201 = var201 + (var101[5ll] * 0);
  var201 = var201 + (var101[6ll] * var146[2ll]);
  var201 = var201 + (var101[7ll] * 0);
  var104[4ll] = var201;
  blaze::StaticVector<float, 8> var202;
  var202 = 0;
  var202 = var202 + (var101[4ll] * var146[5ll]);
  var202 = var202 + (var101[5ll] * 0);
  var202 = var202 + (var101[6ll] * var146[3ll]);
  var202 = var202 + (var101[7ll] * 0);
  var104[5ll] = var202;
  blaze::StaticVector<float, 8> var203;
  var203 = 0;
  var203 = var203 + (var101[4ll] * 0);
  var203 = var203 + (var101[5ll] * 1.0f);
  var203 = var203 + (var101[6ll] * 0);
  var203 = var203 + (var101[7ll] * 0);
  var104[6ll] = var203;
  blaze::StaticVector<float, 8> var204;
  var204 = 0;
  var204 = var204 + (var101[4ll] * 0.0689999982714653f);
  var204 = var204 + (var101[5ll] * 0);
  var204 = var204 + (var101[6ll] * 0.262419998645782f);
  var204 = var204 + (var101[7ll] * 1.0f);
  var104[7ll] = var204;
  blaze::StaticVector<float, 8> var205;
  var205 = 0;
  var205 = var205 + (var101[8ll] * var146[4ll]);
  var205 = var205 + (var101[9ll] * 0);
  var205 = var205 + (var101[10ll] * var146[2ll]);
  var205 = var205 + (var101[11ll] * 0);
  var104[8ll] = var205;
  blaze::StaticVector<float, 8> var206;
  var206 = 0;
  var206 = var206 + (var101[8ll] * var146[5ll]);
  var206 = var206 + (var101[9ll] * 0);
  var206 = var206 + (var101[10ll] * var146[3ll]);
  var206 = var206 + (var101[11ll] * 0);
  var104[9ll] = var206;
  blaze::StaticVector<float, 8> var207;
  var207 = 0;
  var207 = var207 + (var101[8ll] * 0);
  var207 = var207 + (var101[9ll] * 1.0f);
  var207 = var207 + (var101[10ll] * 0);
  var207 = var207 + (var101[11ll] * 0);
  var104[10ll] = var207;
  blaze::StaticVector<float, 8> var208;
  var208 = 0;
  var208 = var208 + (var101[8ll] * 0.0689999982714653f);
  var208 = var208 + (var101[9ll] * 0);
  var208 = var208 + (var101[10ll] * 0.262419998645782f);
  var208 = var208 + (var101[11ll] * 1.0f);
  var104[11ll] = var208;
  var137[5ll] = ((var104[0ll] * 0.0f) + (var104[1ll] * 0.0f)) + (var104[2ll] * 0.0f);
  var138[5ll] = ((var104[4ll] * 0.0f) + (var104[5ll] * 0.0f)) + (var104[6ll] * 0.0f);
  var139[5ll] = ((var104[8ll] * 0.0f) + (var104[9ll] * 0.0f)) + (var104[10ll] * 0.0f);
  var137[5ll] = var137[5ll] + var104[3ll];
  var138[5ll] = var138[5ll] + var104[7ll];
  var139[5ll] = var139[5ll] + var104[11ll];
  var140[5ll] = 0.100000001490116f;
  var141[5ll] = 0ll;
  int var209;
  var209 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll]);
  if (var209)
    return 0; //collision pair: 0,5 : torso_0,left_lower_elbow_0
  var209 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll]);
  if (var209)
    return 0; //collision pair: 1,5 : head_0,left_lower_elbow_0
  var209 = ctup_runtime::link_vs_environment_collision(var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], arg4);
  if (var209)
    return 0;
  blaze::StaticVector<float, 8> var210 = arg5[4ll];
  var63 = sin(var210);
  var64 = cos(var210);
  var62[0ll] = var64;
  var62[1ll] = -(var63);
  var62[2ll] = var63;
  var62[3ll] = var64;
  blaze::StaticVector<float, 8> var211;
  var211 = 0;
  var211 = var211 + (1.0f * var62[0ll]);
  var211 = var211 + (0 * var62[2ll]);
  var211 = var211 + (0 * 0);
  var211 = var211 + (0 * 0);
  var146[0ll] = var211;
  blaze::StaticVector<float, 8> var212;
  var212 = 0;
  var212 = var212 + (1.0f * var62[1ll]);
  var212 = var212 + (0 * var62[3ll]);
  var212 = var212 + (0 * 0);
  var212 = var212 + (0 * 0);
  var146[1ll] = var212;
  blaze::StaticVector<float, 8> var213;
  var213 = 0;
  var213 = var213 + (0 * var62[0ll]);
  var213 = var213 + (1.0f * var62[2ll]);
  var213 = var213 + (0 * 0);
  var213 = var213 + (0 * 0);
  var146[2ll] = var213;
  blaze::StaticVector<float, 8> var214;
  var214 = 0;
  var214 = var214 + (0 * var62[1ll]);
  var214 = var214 + (1.0f * var62[3ll]);
  var214 = var214 + (0 * 0);
  var214 = var214 + (0 * 0);
  var146[3ll] = var214;
  blaze::StaticVector<float, 8> var215;
  var215 = 0;
  var215 = var215 + (var104[0ll] * 0);
  var215 = var215 + (var104[1ll] * var146[0ll]);
  var215 = var215 + (var104[2ll] * var146[2ll]);
  var215 = var215 + (var104[3ll] * 0);
  var107[0ll] = var215;
  blaze::StaticVector<float, 8> var216;
  var216 = 0;
  var216 = var216 + (var104[0ll] * 0);
  var216 = var216 + (var104[1ll] * var146[1ll]);
  var216 = var216 + (var104[2ll] * var146[3ll]);
  var216 = var216 + (var104[3ll] * 0);
  var107[1ll] = var216;
  blaze::StaticVector<float, 8> var217;
  var217 = 0;
  var217 = var217 + (var104[0ll] * 1.0f);
  var217 = var217 + (var104[1ll] * 0);
  var217 = var217 + (var104[2ll] * 0);
  var217 = var217 + (var104[3ll] * 0);
  var107[2ll] = var217;
  blaze::StaticVector<float, 8> var218;
  var218 = 0;
  var218 = var218 + (var104[0ll] * 0.103589996695518f);
  var218 = var218 + (var104[1ll] * 0);
  var218 = var218 + (var104[2ll] * 0);
  var218 = var218 + (var104[3ll] * 1.0f);
  var107[3ll] = var218;
  blaze::StaticVector<float, 8> var219;
  var219 = 0;
  var219 = var219 + (var104[4ll] * 0);
  var219 = var219 + (var104[5ll] * var146[0ll]);
  var219 = var219 + (var104[6ll] * var146[2ll]);
  var219 = var219 + (var104[7ll] * 0);
  var107[4ll] = var219;
  blaze::StaticVector<float, 8> var220;
  var220 = 0;
  var220 = var220 + (var104[4ll] * 0);
  var220 = var220 + (var104[5ll] * var146[1ll]);
  var220 = var220 + (var104[6ll] * var146[3ll]);
  var220 = var220 + (var104[7ll] * 0);
  var107[5ll] = var220;
  blaze::StaticVector<float, 8> var221;
  var221 = 0;
  var221 = var221 + (var104[4ll] * 1.0f);
  var221 = var221 + (var104[5ll] * 0);
  var221 = var221 + (var104[6ll] * 0);
  var221 = var221 + (var104[7ll] * 0);
  var107[6ll] = var221;
  blaze::StaticVector<float, 8> var222;
  var222 = 0;
  var222 = var222 + (var104[4ll] * 0.103589996695518f);
  var222 = var222 + (var104[5ll] * 0);
  var222 = var222 + (var104[6ll] * 0);
  var222 = var222 + (var104[7ll] * 1.0f);
  var107[7ll] = var222;
  blaze::StaticVector<float, 8> var223;
  var223 = 0;
  var223 = var223 + (var104[8ll] * 0);
  var223 = var223 + (var104[9ll] * var146[0ll]);
  var223 = var223 + (var104[10ll] * var146[2ll]);
  var223 = var223 + (var104[11ll] * 0);
  var107[8ll] = var223;
  blaze::StaticVector<float, 8> var224;
  var224 = 0;
  var224 = var224 + (var104[8ll] * 0);
  var224 = var224 + (var104[9ll] * var146[1ll]);
  var224 = var224 + (var104[10ll] * var146[3ll]);
  var224 = var224 + (var104[11ll] * 0);
  var107[9ll] = var224;
  blaze::StaticVector<float, 8> var225;
  var225 = 0;
  var225 = var225 + (var104[8ll] * 1.0f);
  var225 = var225 + (var104[9ll] * 0);
  var225 = var225 + (var104[10ll] * 0);
  var225 = var225 + (var104[11ll] * 0);
  var107[10ll] = var225;
  blaze::StaticVector<float, 8> var226;
  var226 = 0;
  var226 = var226 + (var104[8ll] * 0.103589996695518f);
  var226 = var226 + (var104[9ll] * 0);
  var226 = var226 + (var104[10ll] * 0);
  var226 = var226 + (var104[11ll] * 1.0f);
  var107[11ll] = var226;
  var137[6ll] = ((var107[0ll] * 0.0f) + (var107[1ll] * 0.0f)) + (var107[2ll] * 0.109999999403954f);
  var138[6ll] = ((var107[4ll] * 0.0f) + (var107[5ll] * 0.0f)) + (var107[6ll] * 0.109999999403954f);
  var139[6ll] = ((var107[8ll] * 0.0f) + (var107[9ll] * 0.0f)) + (var107[10ll] * 0.109999999403954f);
  var137[6ll] = var137[6ll] + var107[3ll];
  var138[6ll] = var138[6ll] + var107[7ll];
  var139[6ll] = var139[6ll] + var107[11ll];
  var140[6ll] = 0.189999997615814f;
  var141[6ll] = 3ll;
  var142[6ll][0ll] = ((var107[0ll] * 0.0f) + (var107[1ll] * 0.0f)) + (var107[2ll] * 0.0f);
  var143[6ll][0ll] = ((var107[4ll] * 0.0f) + (var107[5ll] * 0.0f)) + (var107[6ll] * 0.0f);
  var144[6ll][0ll] = ((var107[8ll] * 0.0f) + (var107[9ll] * 0.0f)) + (var107[10ll] * 0.0f);
  var142[6ll][0ll] = var142[6ll][0ll] + var107[3ll];
  var143[6ll][0ll] = var143[6ll][0ll] + var107[7ll];
  var144[6ll][0ll] = var144[6ll][0ll] + var107[11ll];
  var145[6ll][0ll] = 0.0799999982118607f;
  var142[6ll][1ll] = ((var107[0ll] * 0.0f) + (var107[1ll] * 0.0f)) + (var107[2ll] * 0.219999998807907f);
  var143[6ll][1ll] = ((var107[4ll] * 0.0f) + (var107[5ll] * 0.0f)) + (var107[6ll] * 0.219999998807907f);
  var144[6ll][1ll] = ((var107[8ll] * 0.0f) + (var107[9ll] * 0.0f)) + (var107[10ll] * 0.219999998807907f);
  var142[6ll][1ll] = var142[6ll][1ll] + var107[3ll];
  var143[6ll][1ll] = var143[6ll][1ll] + var107[7ll];
  var144[6ll][1ll] = var144[6ll][1ll] + var107[11ll];
  var145[6ll][1ll] = 0.0799999982118607f;
  var142[6ll][2ll] = ((var107[0ll] * 0.0f) + (var107[1ll] * 0.0f)) + (var107[2ll] * 0.109999999403954f);
  var143[6ll][2ll] = ((var107[4ll] * 0.0f) + (var107[5ll] * 0.0f)) + (var107[6ll] * 0.109999999403954f);
  var144[6ll][2ll] = ((var107[8ll] * 0.0f) + (var107[9ll] * 0.0f)) + (var107[10ll] * 0.109999999403954f);
  var142[6ll][2ll] = var142[6ll][2ll] + var107[3ll];
  var143[6ll][2ll] = var143[6ll][2ll] + var107[7ll];
  var144[6ll][2ll] = var144[6ll][2ll] + var107[11ll];
  var145[6ll][2ll] = 0.0799999982118607f;
  int var227;
  var227 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll]);
  if (var227)
    return 0; //collision pair: 0,6 : torso_0,left_upper_forearm_0
  var227 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll]);
  if (var227)
    return 0; //collision pair: 1,6 : head_0,left_upper_forearm_0
  var227 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll]);
  if (var227)
    return 0; //collision pair: 2,6 : left_upper_shoulder_0,left_upper_forearm_0
  var227 = ctup_runtime::link_vs_environment_collision(var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], arg4);
  if (var227)
    return 0;
  blaze::StaticVector<float, 8> var228 = arg5[5ll];
  var66 = sin(var228);
  var67 = cos(var228);
  var65[0ll] = var67;
  var65[1ll] = -(var66);
  var65[2ll] = var66;
  var65[3ll] = var67;
  blaze::StaticVector<float, 8> var229;
  var229 = 0;
  var229 = var229 + (0 * var65[0ll]);
  var229 = var229 + (1.0f * var65[2ll]);
  var229 = var229 + (0 * 0);
  var229 = var229 + (0.00999999977648258f * 0);
  var146[4ll] = var229;
  blaze::StaticVector<float, 8> var230;
  var230 = 0;
  var230 = var230 + (0 * var65[1ll]);
  var230 = var230 + (1.0f * var65[3ll]);
  var230 = var230 + (0 * 0);
  var230 = var230 + (0.00999999977648258f * 0);
  var146[5ll] = var230;
  blaze::StaticVector<float, 8> var231;
  var231 = 0;
  var231 = var231 + (1.0f * var65[0ll]);
  var231 = var231 + (0 * var65[2ll]);
  var231 = var231 + (0 * 0);
  var231 = var231 + (0.270700007677078f * 0);
  var146[2ll] = var231;
  blaze::StaticVector<float, 8> var232;
  var232 = 0;
  var232 = var232 + (1.0f * var65[1ll]);
  var232 = var232 + (0 * var65[3ll]);
  var232 = var232 + (0 * 0);
  var232 = var232 + (0.270700007677078f * 0);
  var146[3ll] = var232;
  blaze::StaticVector<float, 8> var233;
  var233 = 0;
  var233 = var233 + (var107[0ll] * var146[4ll]);
  var233 = var233 + (var107[1ll] * 0);
  var233 = var233 + (var107[2ll] * var146[2ll]);
  var233 = var233 + (var107[3ll] * 0);
  var110[0ll] = var233;
  blaze::StaticVector<float, 8> var234;
  var234 = 0;
  var234 = var234 + (var107[0ll] * var146[5ll]);
  var234 = var234 + (var107[1ll] * 0);
  var234 = var234 + (var107[2ll] * var146[3ll]);
  var234 = var234 + (var107[3ll] * 0);
  var110[1ll] = var234;
  blaze::StaticVector<float, 8> var235;
  var235 = 0;
  var235 = var235 + (var107[0ll] * 0);
  var235 = var235 + (var107[1ll] * 1.0f);
  var235 = var235 + (var107[2ll] * 0);
  var235 = var235 + (var107[3ll] * 0);
  var110[2ll] = var235;
  blaze::StaticVector<float, 8> var236;
  var236 = 0;
  var236 = var236 + (var107[0ll] * 0.00999999977648258f);
  var236 = var236 + (var107[1ll] * 0);
  var236 = var236 + (var107[2ll] * 0.270700007677078f);
  var236 = var236 + (var107[3ll] * 1.0f);
  var110[3ll] = var236;
  blaze::StaticVector<float, 8> var237;
  var237 = 0;
  var237 = var237 + (var107[4ll] * var146[4ll]);
  var237 = var237 + (var107[5ll] * 0);
  var237 = var237 + (var107[6ll] * var146[2ll]);
  var237 = var237 + (var107[7ll] * 0);
  var110[4ll] = var237;
  blaze::StaticVector<float, 8> var238;
  var238 = 0;
  var238 = var238 + (var107[4ll] * var146[5ll]);
  var238 = var238 + (var107[5ll] * 0);
  var238 = var238 + (var107[6ll] * var146[3ll]);
  var238 = var238 + (var107[7ll] * 0);
  var110[5ll] = var238;
  blaze::StaticVector<float, 8> var239;
  var239 = 0;
  var239 = var239 + (var107[4ll] * 0);
  var239 = var239 + (var107[5ll] * 1.0f);
  var239 = var239 + (var107[6ll] * 0);
  var239 = var239 + (var107[7ll] * 0);
  var110[6ll] = var239;
  blaze::StaticVector<float, 8> var240;
  var240 = 0;
  var240 = var240 + (var107[4ll] * 0.00999999977648258f);
  var240 = var240 + (var107[5ll] * 0);
  var240 = var240 + (var107[6ll] * 0.270700007677078f);
  var240 = var240 + (var107[7ll] * 1.0f);
  var110[7ll] = var240;
  blaze::StaticVector<float, 8> var241;
  var241 = 0;
  var241 = var241 + (var107[8ll] * var146[4ll]);
  var241 = var241 + (var107[9ll] * 0);
  var241 = var241 + (var107[10ll] * var146[2ll]);
  var241 = var241 + (var107[11ll] * 0);
  var110[8ll] = var241;
  blaze::StaticVector<float, 8> var242;
  var242 = 0;
  var242 = var242 + (var107[8ll] * var146[5ll]);
  var242 = var242 + (var107[9ll] * 0);
  var242 = var242 + (var107[10ll] * var146[3ll]);
  var242 = var242 + (var107[11ll] * 0);
  var110[9ll] = var242;
  blaze::StaticVector<float, 8> var243;
  var243 = 0;
  var243 = var243 + (var107[8ll] * 0);
  var243 = var243 + (var107[9ll] * 1.0f);
  var243 = var243 + (var107[10ll] * 0);
  var243 = var243 + (var107[11ll] * 0);
  var110[10ll] = var243;
  blaze::StaticVector<float, 8> var244;
  var244 = 0;
  var244 = var244 + (var107[8ll] * 0.00999999977648258f);
  var244 = var244 + (var107[9ll] * 0);
  var244 = var244 + (var107[10ll] * 0.270700007677078f);
  var244 = var244 + (var107[11ll] * 1.0f);
  var110[11ll] = var244;
  var137[7ll] = ((var110[0ll] * 0.0f) + (var110[1ll] * 0.0f)) + (var110[2ll] * 0.0f);
  var138[7ll] = ((var110[4ll] * 0.0f) + (var110[5ll] * 0.0f)) + (var110[6ll] * 0.0f);
  var139[7ll] = ((var110[8ll] * 0.0f) + (var110[9ll] * 0.0f)) + (var110[10ll] * 0.0f);
  var137[7ll] = var137[7ll] + var110[3ll];
  var138[7ll] = var138[7ll] + var110[7ll];
  var139[7ll] = var139[7ll] + var110[11ll];
  var140[7ll] = 0.100000001490116f;
  var141[7ll] = 2ll;
  var142[7ll][0ll] = ((var110[0ll] * 0.0f) + (var110[1ll] * 0.0f)) + (var110[2ll] * 0.0299999993294477f);
  var143[7ll][0ll] = ((var110[4ll] * 0.0f) + (var110[5ll] * 0.0f)) + (var110[6ll] * 0.0299999993294477f);
  var144[7ll][0ll] = ((var110[8ll] * 0.0f) + (var110[9ll] * 0.0f)) + (var110[10ll] * 0.0299999993294477f);
  var142[7ll][0ll] = var142[7ll][0ll] + var110[3ll];
  var143[7ll][0ll] = var143[7ll][0ll] + var110[7ll];
  var144[7ll][0ll] = var144[7ll][0ll] + var110[11ll];
  var145[7ll][0ll] = 0.0700000002980232f;
  var142[7ll][1ll] = ((var110[0ll] * 0.0f) + (var110[1ll] * 0.0f)) + (var110[2ll] * -0.0299999993294477f);
  var143[7ll][1ll] = ((var110[4ll] * 0.0f) + (var110[5ll] * 0.0f)) + (var110[6ll] * -0.0299999993294477f);
  var144[7ll][1ll] = ((var110[8ll] * 0.0f) + (var110[9ll] * 0.0f)) + (var110[10ll] * -0.0299999993294477f);
  var142[7ll][1ll] = var142[7ll][1ll] + var110[3ll];
  var143[7ll][1ll] = var143[7ll][1ll] + var110[7ll];
  var144[7ll][1ll] = var144[7ll][1ll] + var110[11ll];
  var145[7ll][1ll] = 0.0700000002980232f;
  int var245;
  var245 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll]);
  if (var245)
    return 0; //collision pair: 0,7 : torso_0,left_lower_forearm_0
  var245 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll]);
  if (var245)
    return 0; //collision pair: 1,7 : head_0,left_lower_forearm_0
  var245 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll]);
  if (var245)
    return 0; //collision pair: 2,7 : left_upper_shoulder_0,left_lower_forearm_0
  var245 = ctup_runtime::link_vs_environment_collision(var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], arg4);
  if (var245)
    return 0;
  blaze::StaticVector<float, 8> var246 = arg5[6ll];
  var69 = sin(var246);
  var70 = cos(var246);
  var68[0ll] = var70;
  var68[1ll] = -(var69);
  var68[2ll] = var69;
  var68[3ll] = var70;
  blaze::StaticVector<float, 8> var247;
  var247 = 0;
  var247 = var247 + (1.0f * var68[0ll]);
  var247 = var247 + (0 * var68[2ll]);
  var247 = var247 + (0 * 0);
  var247 = var247 + (0 * 0);
  var146[0ll] = var247;
  blaze::StaticVector<float, 8> var248;
  var248 = 0;
  var248 = var248 + (1.0f * var68[1ll]);
  var248 = var248 + (0 * var68[3ll]);
  var248 = var248 + (0 * 0);
  var248 = var248 + (0 * 0);
  var146[1ll] = var248;
  blaze::StaticVector<float, 8> var249;
  var249 = 0;
  var249 = var249 + (0 * var68[0ll]);
  var249 = var249 + (1.0f * var68[2ll]);
  var249 = var249 + (0 * 0);
  var249 = var249 + (0 * 0);
  var146[2ll] = var249;
  blaze::StaticVector<float, 8> var250;
  var250 = 0;
  var250 = var250 + (0 * var68[1ll]);
  var250 = var250 + (1.0f * var68[3ll]);
  var250 = var250 + (0 * 0);
  var250 = var250 + (0 * 0);
  var146[3ll] = var250;
  blaze::StaticVector<float, 8> var251;
  var251 = 0;
  var251 = var251 + (var110[0ll] * 0);
  var251 = var251 + (var110[1ll] * var146[0ll]);
  var251 = var251 + (var110[2ll] * var146[2ll]);
  var251 = var251 + (var110[3ll] * 0);
  var113[0ll] = var251;
  blaze::StaticVector<float, 8> var252;
  var252 = 0;
  var252 = var252 + (var110[0ll] * 0);
  var252 = var252 + (var110[1ll] * var146[1ll]);
  var252 = var252 + (var110[2ll] * var146[3ll]);
  var252 = var252 + (var110[3ll] * 0);
  var113[1ll] = var252;
  blaze::StaticVector<float, 8> var253;
  var253 = 0;
  var253 = var253 + (var110[0ll] * 1.0f);
  var253 = var253 + (var110[1ll] * 0);
  var253 = var253 + (var110[2ll] * 0);
  var253 = var253 + (var110[3ll] * 0);
  var113[2ll] = var253;
  blaze::StaticVector<float, 8> var254;
  var254 = 0;
  var254 = var254 + (var110[0ll] * 0.115974999964237f);
  var254 = var254 + (var110[1ll] * 0);
  var254 = var254 + (var110[2ll] * 0);
  var254 = var254 + (var110[3ll] * 1.0f);
  var113[3ll] = var254;
  blaze::StaticVector<float, 8> var255;
  var255 = 0;
  var255 = var255 + (var110[4ll] * 0);
  var255 = var255 + (var110[5ll] * var146[0ll]);
  var255 = var255 + (var110[6ll] * var146[2ll]);
  var255 = var255 + (var110[7ll] * 0);
  var113[4ll] = var255;
  blaze::StaticVector<float, 8> var256;
  var256 = 0;
  var256 = var256 + (var110[4ll] * 0);
  var256 = var256 + (var110[5ll] * var146[1ll]);
  var256 = var256 + (var110[6ll] * var146[3ll]);
  var256 = var256 + (var110[7ll] * 0);
  var113[5ll] = var256;
  blaze::StaticVector<float, 8> var257;
  var257 = 0;
  var257 = var257 + (var110[4ll] * 1.0f);
  var257 = var257 + (var110[5ll] * 0);
  var257 = var257 + (var110[6ll] * 0);
  var257 = var257 + (var110[7ll] * 0);
  var113[6ll] = var257;
  blaze::StaticVector<float, 8> var258;
  var258 = 0;
  var258 = var258 + (var110[4ll] * 0.115974999964237f);
  var258 = var258 + (var110[5ll] * 0);
  var258 = var258 + (var110[6ll] * 0);
  var258 = var258 + (var110[7ll] * 1.0f);
  var113[7ll] = var258;
  blaze::StaticVector<float, 8> var259;
  var259 = 0;
  var259 = var259 + (var110[8ll] * 0);
  var259 = var259 + (var110[9ll] * var146[0ll]);
  var259 = var259 + (var110[10ll] * var146[2ll]);
  var259 = var259 + (var110[11ll] * 0);
  var113[8ll] = var259;
  blaze::StaticVector<float, 8> var260;
  var260 = 0;
  var260 = var260 + (var110[8ll] * 0);
  var260 = var260 + (var110[9ll] * var146[1ll]);
  var260 = var260 + (var110[10ll] * var146[3ll]);
  var260 = var260 + (var110[11ll] * 0);
  var113[9ll] = var260;
  blaze::StaticVector<float, 8> var261;
  var261 = 0;
  var261 = var261 + (var110[8ll] * 1.0f);
  var261 = var261 + (var110[9ll] * 0);
  var261 = var261 + (var110[10ll] * 0);
  var261 = var261 + (var110[11ll] * 0);
  var113[10ll] = var261;
  blaze::StaticVector<float, 8> var262;
  var262 = 0;
  var262 = var262 + (var110[8ll] * 0.115974999964237f);
  var262 = var262 + (var110[9ll] * 0);
  var262 = var262 + (var110[10ll] * 0);
  var262 = var262 + (var110[11ll] * 1.0f);
  var113[11ll] = var262;
  var137[8ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0f)) + (var113[2ll] * -0.0149999996647239f);
  var138[8ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * 0.0f)) + (var113[6ll] * -0.0149999996647239f);
  var139[8ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * 0.0f)) + (var113[10ll] * -0.0149999996647239f);
  var137[8ll] = var137[8ll] + var113[3ll];
  var138[8ll] = var138[8ll] + var113[7ll];
  var139[8ll] = var139[8ll] + var113[11ll];
  var140[8ll] = 0.104999996721745f;
  var141[8ll] = 2ll;
  var142[8ll][0ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0f)) + (var113[2ll] * 0.0199999995529652f);
  var143[8ll][0ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * 0.0f)) + (var113[6ll] * 0.0199999995529652f);
  var144[8ll][0ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * 0.0f)) + (var113[10ll] * 0.0199999995529652f);
  var142[8ll][0ll] = var142[8ll][0ll] + var113[3ll];
  var143[8ll][0ll] = var143[8ll][0ll] + var113[7ll];
  var144[8ll][0ll] = var144[8ll][0ll] + var113[11ll];
  var145[8ll][0ll] = 0.0700000002980232f;
  var142[8ll][1ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0f)) + (var113[2ll] * -0.0399999991059303f);
  var143[8ll][1ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * 0.0f)) + (var113[6ll] * -0.0399999991059303f);
  var144[8ll][1ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * 0.0f)) + (var113[10ll] * -0.0399999991059303f);
  var142[8ll][1ll] = var142[8ll][1ll] + var113[3ll];
  var143[8ll][1ll] = var143[8ll][1ll] + var113[7ll];
  var144[8ll][1ll] = var144[8ll][1ll] + var113[11ll];
  var145[8ll][1ll] = 0.0799999982118607f;
  int var263;
  var263 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll]);
  if (var263)
    return 0; //collision pair: 0,8 : torso_0,left_wrist_0
  var263 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll]);
  if (var263)
    return 0; //collision pair: 1,8 : head_0,left_wrist_0
  var263 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll]);
  if (var263)
    return 0; //collision pair: 2,8 : left_upper_shoulder_0,left_wrist_0
  var263 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll]);
  if (var263)
    return 0; //collision pair: 3,8 : left_lower_shoulder_0,left_wrist_0
  var263 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll]);
  if (var263)
    return 0; //collision pair: 4,8 : left_upper_elbow_0,left_wrist_0
  var263 = ctup_runtime::link_vs_environment_collision(var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], arg4);
  if (var263)
    return 0;
  var137[9ll] = ((var113[0ll] * 0.00999999977648258f) + (var113[1ll] * 0.0f)) + (var113[2ll] * 0.0935499966144562f);
  var138[9ll] = ((var113[4ll] * 0.00999999977648258f) + (var113[5ll] * 0.0f)) + (var113[6ll] * 0.0935499966144562f);
  var139[9ll] = ((var113[8ll] * 0.00999999977648258f) + (var113[9ll] * 0.0f)) + (var113[10ll] * 0.0935499966144562f);
  var137[9ll] = var137[9ll] + var113[3ll];
  var138[9ll] = var138[9ll] + var113[7ll];
  var139[9ll] = var139[9ll] + var113[11ll];
  var140[9ll] = 0.0500000007450581f;
  var141[9ll] = 1ll;
  var142[9ll][0ll] = ((var113[0ll] * 0.00999999977648258f) + (var113[1ll] * 0.0f)) + (var113[2ll] * 0.0935499966144562f);
  var143[9ll][0ll] = ((var113[4ll] * 0.00999999977648258f) + (var113[5ll] * 0.0f)) + (var113[6ll] * 0.0935499966144562f);
  var144[9ll][0ll] = ((var113[8ll] * 0.00999999977648258f) + (var113[9ll] * 0.0f)) + (var113[10ll] * 0.0935499966144562f);
  var142[9ll][0ll] = var142[9ll][0ll] + var113[3ll];
  var143[9ll][0ll] = var143[9ll][0ll] + var113[7ll];
  var144[9ll][0ll] = var144[9ll][0ll] + var113[11ll];
  var145[9ll][0ll] = 0.0500000007450581f;
  int var264;
  var264 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll]);
  if (var264)
    return 0; //collision pair: 0,9 : torso_0,left_hand_0
  var264 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll]);
  if (var264)
    return 0; //collision pair: 1,9 : head_0,left_hand_0
  var264 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll]);
  if (var264)
    return 0; //collision pair: 2,9 : left_upper_shoulder_0,left_hand_0
  var264 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll]);
  if (var264)
    return 0; //collision pair: 3,9 : left_lower_shoulder_0,left_hand_0
  var264 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll]);
  if (var264)
    return 0; //collision pair: 4,9 : left_upper_elbow_0,left_hand_0
  var264 = ctup_runtime::link_vs_environment_collision(var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], arg4);
  if (var264)
    return 0;
  var137[10ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0f)) + (var113[2ll] * 0.138549998402596f);
  var138[10ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * 0.0f)) + (var113[6ll] * 0.138549998402596f);
  var139[10ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * 0.0f)) + (var113[10ll] * 0.138549998402596f);
  var137[10ll] = var137[10ll] + var113[3ll];
  var138[10ll] = var138[10ll] + var113[7ll];
  var139[10ll] = var139[10ll] + var113[11ll];
  var140[10ll] = 0.0599999986588955f;
  var141[10ll] = 2ll;
  var142[10ll][0ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0199999995529652f)) + (var113[2ll] * 0.138549998402596f);
  var143[10ll][0ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * 0.0199999995529652f)) + (var113[6ll] * 0.138549998402596f);
  var144[10ll][0ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * 0.0199999995529652f)) + (var113[10ll] * 0.138549998402596f);
  var142[10ll][0ll] = var142[10ll][0ll] + var113[3ll];
  var143[10ll][0ll] = var143[10ll][0ll] + var113[7ll];
  var144[10ll][0ll] = var144[10ll][0ll] + var113[11ll];
  var145[10ll][0ll] = 0.0399999991059303f;
  var142[10ll][1ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * -0.0199999995529652f)) + (var113[2ll] * 0.138549998402596f);
  var143[10ll][1ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * -0.0199999995529652f)) + (var113[6ll] * 0.138549998402596f);
  var144[10ll][1ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * -0.0199999995529652f)) + (var113[10ll] * 0.138549998402596f);
  var142[10ll][1ll] = var142[10ll][1ll] + var113[3ll];
  var143[10ll][1ll] = var143[10ll][1ll] + var113[7ll];
  var144[10ll][1ll] = var144[10ll][1ll] + var113[11ll];
  var145[10ll][1ll] = 0.0399999991059303f;
  int var265;
  var265 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll]);
  if (var265)
    return 0; //collision pair: 0,10 : torso_0,left_gripper_base_0
  var265 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll]);
  if (var265)
    return 0; //collision pair: 1,10 : head_0,left_gripper_base_0
  var265 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll]);
  if (var265)
    return 0; //collision pair: 2,10 : left_upper_shoulder_0,left_gripper_base_0
  var265 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll]);
  if (var265)
    return 0; //collision pair: 3,10 : left_lower_shoulder_0,left_gripper_base_0
  var265 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll]);
  if (var265)
    return 0; //collision pair: 4,10 : left_upper_elbow_0,left_gripper_base_0
  var265 = ctup_runtime::link_vs_environment_collision(var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], arg4);
  if (var265)
    return 0;
  var137[11ll] = ((var113[0ll] * -0.00499999988824129f) + (var113[1ll] * 0.0693330019712448f)) + (var113[2ll] * 0.166549995541573f);
  var138[11ll] = ((var113[4ll] * -0.00499999988824129f) + (var113[5ll] * 0.0693330019712448f)) + (var113[6ll] * 0.166549995541573f);
  var139[11ll] = ((var113[8ll] * -0.00499999988824129f) + (var113[9ll] * 0.0693330019712448f)) + (var113[10ll] * 0.166549995541573f);
  var137[11ll] = var137[11ll] + var113[3ll];
  var138[11ll] = var138[11ll] + var113[7ll];
  var139[11ll] = var139[11ll] + var113[11ll];
  var140[11ll] = 0.0270000007003546f;
  var141[11ll] = 2ll;
  var142[11ll][0ll] = ((var113[0ll] * -0.00499999988824129f) + (var113[1ll] * 0.0813329964876175f)) + (var113[2ll] * 0.166549995541573f);
  var143[11ll][0ll] = ((var113[4ll] * -0.00499999988824129f) + (var113[5ll] * 0.0813329964876175f)) + (var113[6ll] * 0.166549995541573f);
  var144[11ll][0ll] = ((var113[8ll] * -0.00499999988824129f) + (var113[9ll] * 0.0813329964876175f)) + (var113[10ll] * 0.166549995541573f);
  var142[11ll][0ll] = var142[11ll][0ll] + var113[3ll];
  var143[11ll][0ll] = var143[11ll][0ll] + var113[7ll];
  var144[11ll][0ll] = var144[11ll][0ll] + var113[11ll];
  var145[11ll][0ll] = 0.0149999996647239f;
  var142[11ll][1ll] = ((var113[0ll] * -0.00499999988824129f) + (var113[1ll] * 0.0573330000042915f)) + (var113[2ll] * 0.166549995541573f);
  var143[11ll][1ll] = ((var113[4ll] * -0.00499999988824129f) + (var113[5ll] * 0.0573330000042915f)) + (var113[6ll] * 0.166549995541573f);
  var144[11ll][1ll] = ((var113[8ll] * -0.00499999988824129f) + (var113[9ll] * 0.0573330000042915f)) + (var113[10ll] * 0.166549995541573f);
  var142[11ll][1ll] = var142[11ll][1ll] + var113[3ll];
  var143[11ll][1ll] = var143[11ll][1ll] + var113[7ll];
  var144[11ll][1ll] = var144[11ll][1ll] + var113[11ll];
  var145[11ll][1ll] = 0.0149999996647239f;
  int var266;
  var266 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll]);
  if (var266)
    return 0; //collision pair: 0,11 : torso_0,l_gripper_l_finger_0
  var266 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll]);
  if (var266)
    return 0; //collision pair: 2,11 : left_upper_shoulder_0,l_gripper_l_finger_0
  var266 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll]);
  if (var266)
    return 0; //collision pair: 3,11 : left_lower_shoulder_0,l_gripper_l_finger_0
  var266 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll]);
  if (var266)
    return 0; //collision pair: 4,11 : left_upper_elbow_0,l_gripper_l_finger_0
  var266 = ctup_runtime::link_vs_environment_collision(var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], arg4);
  if (var266)
    return 0;
  var137[12ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0863329991698265f)) + (var113[2ll] * 0.208550006151199f);
  var138[12ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * 0.0863329991698265f)) + (var113[6ll] * 0.208550006151199f);
  var139[12ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * 0.0863329991698265f)) + (var113[10ll] * 0.208550006151199f);
  var137[12ll] = var137[12ll] + var113[3ll];
  var138[12ll] = var138[12ll] + var113[7ll];
  var139[12ll] = var139[12ll] + var113[11ll];
  var140[12ll] = 0.0320000015199184f;
  var141[12ll] = 3ll;
  var142[12ll][0ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0865830034017563f)) + (var113[2ll] * 0.188549995422363f);
  var143[12ll][0ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * 0.0865830034017563f)) + (var113[6ll] * 0.188549995422363f);
  var144[12ll][0ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * 0.0865830034017563f)) + (var113[10ll] * 0.188549995422363f);
  var142[12ll][0ll] = var142[12ll][0ll] + var113[3ll];
  var143[12ll][0ll] = var143[12ll][0ll] + var113[7ll];
  var144[12ll][0ll] = var144[12ll][0ll] + var113[11ll];
  var145[12ll][0ll] = 0.0120000001043081f;
  var142[12ll][1ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0865830034017563f)) + (var113[2ll] * 0.208550006151199f);
  var143[12ll][1ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * 0.0865830034017563f)) + (var113[6ll] * 0.208550006151199f);
  var144[12ll][1ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * 0.0865830034017563f)) + (var113[10ll] * 0.208550006151199f);
  var142[12ll][1ll] = var142[12ll][1ll] + var113[3ll];
  var143[12ll][1ll] = var143[12ll][1ll] + var113[7ll];
  var144[12ll][1ll] = var144[12ll][1ll] + var113[11ll];
  var145[12ll][1ll] = 0.0120000001043081f;
  var142[12ll][2ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0865830034017563f)) + (var113[2ll] * 0.228550001978874f);
  var143[12ll][2ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * 0.0865830034017563f)) + (var113[6ll] * 0.228550001978874f);
  var144[12ll][2ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * 0.0865830034017563f)) + (var113[10ll] * 0.228550001978874f);
  var142[12ll][2ll] = var142[12ll][2ll] + var113[3ll];
  var143[12ll][2ll] = var143[12ll][2ll] + var113[7ll];
  var144[12ll][2ll] = var144[12ll][2ll] + var113[11ll];
  var145[12ll][2ll] = 0.0120000001043081f;
  int var267;
  var267 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll]);
  if (var267)
    return 0; //collision pair: 0,12 : torso_0,l_gripper_l_finger_2_0
  var267 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll]);
  if (var267)
    return 0; //collision pair: 2,12 : left_upper_shoulder_0,l_gripper_l_finger_2_0
  var267 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll]);
  if (var267)
    return 0; //collision pair: 3,12 : left_lower_shoulder_0,l_gripper_l_finger_2_0
  var267 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll]);
  if (var267)
    return 0; //collision pair: 4,12 : left_upper_elbow_0,l_gripper_l_finger_2_0
  var267 = ctup_runtime::link_vs_environment_collision(var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], arg4);
  if (var267)
    return 0;
  var137[13ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * 0.0825830027461052f)) + (var113[2ll] * 0.256249994039536f);
  var138[13ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * 0.0825830027461052f)) + (var113[6ll] * 0.256249994039536f);
  var139[13ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * 0.0825830027461052f)) + (var113[10ll] * 0.256249994039536f);
  var137[13ll] = var137[13ll] + var113[3ll];
  var138[13ll] = var138[13ll] + var113[7ll];
  var139[13ll] = var139[13ll] + var113[11ll];
  var140[13ll] = 0.0280000008642673f;
  var141[13ll] = 4ll;
  var142[13ll][0ll] = ((var113[0ll] * 0.00999999977648258f) + (var113[1ll] * 0.0820830017328262f)) + (var113[2ll] * 0.266250014305115f);
  var143[13ll][0ll] = ((var113[4ll] * 0.00999999977648258f) + (var113[5ll] * 0.0820830017328262f)) + (var113[6ll] * 0.266250014305115f);
  var144[13ll][0ll] = ((var113[8ll] * 0.00999999977648258f) + (var113[9ll] * 0.0820830017328262f)) + (var113[10ll] * 0.266250014305115f);
  var142[13ll][0ll] = var142[13ll][0ll] + var113[3ll];
  var143[13ll][0ll] = var143[13ll][0ll] + var113[7ll];
  var144[13ll][0ll] = var144[13ll][0ll] + var113[11ll];
  var145[13ll][0ll] = 0.0140000004321337f;
  var142[13ll][1ll] = ((var113[0ll] * -0.00999999977648258f) + (var113[1ll] * 0.0820830017328262f)) + (var113[2ll] * 0.266250014305115f);
  var143[13ll][1ll] = ((var113[4ll] * -0.00999999977648258f) + (var113[5ll] * 0.0820830017328262f)) + (var113[6ll] * 0.266250014305115f);
  var144[13ll][1ll] = ((var113[8ll] * -0.00999999977648258f) + (var113[9ll] * 0.0820830017328262f)) + (var113[10ll] * 0.266250014305115f);
  var142[13ll][1ll] = var142[13ll][1ll] + var113[3ll];
  var143[13ll][1ll] = var143[13ll][1ll] + var113[7ll];
  var144[13ll][1ll] = var144[13ll][1ll] + var113[11ll];
  var145[13ll][1ll] = 0.0140000004321337f;
  var142[13ll][2ll] = ((var113[0ll] * -0.00999999977648258f) + (var113[1ll] * 0.0820830017328262f)) + (var113[2ll] * 0.246250003576279f);
  var143[13ll][2ll] = ((var113[4ll] * -0.00999999977648258f) + (var113[5ll] * 0.0820830017328262f)) + (var113[6ll] * 0.246250003576279f);
  var144[13ll][2ll] = ((var113[8ll] * -0.00999999977648258f) + (var113[9ll] * 0.0820830017328262f)) + (var113[10ll] * 0.246250003576279f);
  var142[13ll][2ll] = var142[13ll][2ll] + var113[3ll];
  var143[13ll][2ll] = var143[13ll][2ll] + var113[7ll];
  var144[13ll][2ll] = var144[13ll][2ll] + var113[11ll];
  var145[13ll][2ll] = 0.0140000004321337f;
  var142[13ll][3ll] = ((var113[0ll] * 0.00999999977648258f) + (var113[1ll] * 0.0820830017328262f)) + (var113[2ll] * 0.246250003576279f);
  var143[13ll][3ll] = ((var113[4ll] * 0.00999999977648258f) + (var113[5ll] * 0.0820830017328262f)) + (var113[6ll] * 0.246250003576279f);
  var144[13ll][3ll] = ((var113[8ll] * 0.00999999977648258f) + (var113[9ll] * 0.0820830017328262f)) + (var113[10ll] * 0.246250003576279f);
  var142[13ll][3ll] = var142[13ll][3ll] + var113[3ll];
  var143[13ll][3ll] = var143[13ll][3ll] + var113[7ll];
  var144[13ll][3ll] = var144[13ll][3ll] + var113[11ll];
  var145[13ll][3ll] = 0.0140000004321337f;
  int var268;
  var268 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll]);
  if (var268)
    return 0; //collision pair: 0,13 : torso_0,l_gripper_l_finger_tip_0
  var268 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll]);
  if (var268)
    return 0; //collision pair: 1,13 : head_0,l_gripper_l_finger_tip_0
  var268 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll]);
  if (var268)
    return 0; //collision pair: 2,13 : left_upper_shoulder_0,l_gripper_l_finger_tip_0
  var268 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll]);
  if (var268)
    return 0; //collision pair: 3,13 : left_lower_shoulder_0,l_gripper_l_finger_tip_0
  var268 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll]);
  if (var268)
    return 0; //collision pair: 4,13 : left_upper_elbow_0,l_gripper_l_finger_tip_0
  var268 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll]);
  if (var268)
    return 0; //collision pair: 5,13 : left_lower_elbow_0,l_gripper_l_finger_tip_0
  var268 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll]);
  if (var268)
    return 0; //collision pair: 6,13 : left_upper_forearm_0,l_gripper_l_finger_tip_0
  var268 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll]);
  if (var268)
    return 0; //collision pair: 7,13 : left_lower_forearm_0,l_gripper_l_finger_tip_0
  var268 = ctup_runtime::link_vs_environment_collision(var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], arg4);
  if (var268)
    return 0;
  var137[14ll] = ((var113[0ll] * 0.00499999988824129f) + (var113[1ll] * -0.0693330019712448f)) + (var113[2ll] * 0.166549995541573f);
  var138[14ll] = ((var113[4ll] * 0.00499999988824129f) + (var113[5ll] * -0.0693330019712448f)) + (var113[6ll] * 0.166549995541573f);
  var139[14ll] = ((var113[8ll] * 0.00499999988824129f) + (var113[9ll] * -0.0693330019712448f)) + (var113[10ll] * 0.166549995541573f);
  var137[14ll] = var137[14ll] + var113[3ll];
  var138[14ll] = var138[14ll] + var113[7ll];
  var139[14ll] = var139[14ll] + var113[11ll];
  var140[14ll] = 0.025000000372529f;
  var141[14ll] = 2ll;
  var142[14ll][0ll] = ((var113[0ll] * 0.00499999988824129f) + (var113[1ll] * -0.0593330003321171f)) + (var113[2ll] * 0.166549995541573f);
  var143[14ll][0ll] = ((var113[4ll] * 0.00499999988824129f) + (var113[5ll] * -0.0593330003321171f)) + (var113[6ll] * 0.166549995541573f);
  var144[14ll][0ll] = ((var113[8ll] * 0.00499999988824129f) + (var113[9ll] * -0.0593330003321171f)) + (var113[10ll] * 0.166549995541573f);
  var142[14ll][0ll] = var142[14ll][0ll] + var113[3ll];
  var143[14ll][0ll] = var143[14ll][0ll] + var113[7ll];
  var144[14ll][0ll] = var144[14ll][0ll] + var113[11ll];
  var145[14ll][0ll] = 0.0149999996647239f;
  var142[14ll][1ll] = ((var113[0ll] * 0.00499999988824129f) + (var113[1ll] * -0.0793329998850822f)) + (var113[2ll] * 0.166549995541573f);
  var143[14ll][1ll] = ((var113[4ll] * 0.00499999988824129f) + (var113[5ll] * -0.0793329998850822f)) + (var113[6ll] * 0.166549995541573f);
  var144[14ll][1ll] = ((var113[8ll] * 0.00499999988824129f) + (var113[9ll] * -0.0793329998850822f)) + (var113[10ll] * 0.166549995541573f);
  var142[14ll][1ll] = var142[14ll][1ll] + var113[3ll];
  var143[14ll][1ll] = var143[14ll][1ll] + var113[7ll];
  var144[14ll][1ll] = var144[14ll][1ll] + var113[11ll];
  var145[14ll][1ll] = 0.0149999996647239f;
  int var269;
  var269 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll]);
  if (var269)
    return 0; //collision pair: 0,14 : torso_0,l_gripper_r_finger_0
  var269 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll]);
  if (var269)
    return 0; //collision pair: 1,14 : head_0,l_gripper_r_finger_0
  var269 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll]);
  if (var269)
    return 0; //collision pair: 2,14 : left_upper_shoulder_0,l_gripper_r_finger_0
  var269 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll]);
  if (var269)
    return 0; //collision pair: 3,14 : left_lower_shoulder_0,l_gripper_r_finger_0
  var269 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll]);
  if (var269)
    return 0; //collision pair: 4,14 : left_upper_elbow_0,l_gripper_r_finger_0
  var269 = ctup_runtime::link_vs_environment_collision(var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], arg4);
  if (var269)
    return 0;
  var137[15ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * -0.0863329991698265f)) + (var113[2ll] * 0.208550006151199f);
  var138[15ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * -0.0863329991698265f)) + (var113[6ll] * 0.208550006151199f);
  var139[15ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * -0.0863329991698265f)) + (var113[10ll] * 0.208550006151199f);
  var137[15ll] = var137[15ll] + var113[3ll];
  var138[15ll] = var138[15ll] + var113[7ll];
  var139[15ll] = var139[15ll] + var113[11ll];
  var140[15ll] = 0.0320000015199184f;
  var141[15ll] = 3ll;
  var142[15ll][0ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * -0.0865830034017563f)) + (var113[2ll] * 0.188549995422363f);
  var143[15ll][0ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * -0.0865830034017563f)) + (var113[6ll] * 0.188549995422363f);
  var144[15ll][0ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * -0.0865830034017563f)) + (var113[10ll] * 0.188549995422363f);
  var142[15ll][0ll] = var142[15ll][0ll] + var113[3ll];
  var143[15ll][0ll] = var143[15ll][0ll] + var113[7ll];
  var144[15ll][0ll] = var144[15ll][0ll] + var113[11ll];
  var145[15ll][0ll] = 0.0120000001043081f;
  var142[15ll][1ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * -0.0865830034017563f)) + (var113[2ll] * 0.208550006151199f);
  var143[15ll][1ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * -0.0865830034017563f)) + (var113[6ll] * 0.208550006151199f);
  var144[15ll][1ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * -0.0865830034017563f)) + (var113[10ll] * 0.208550006151199f);
  var142[15ll][1ll] = var142[15ll][1ll] + var113[3ll];
  var143[15ll][1ll] = var143[15ll][1ll] + var113[7ll];
  var144[15ll][1ll] = var144[15ll][1ll] + var113[11ll];
  var145[15ll][1ll] = 0.0120000001043081f;
  var142[15ll][2ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * -0.0865830034017563f)) + (var113[2ll] * 0.228550001978874f);
  var143[15ll][2ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * -0.0865830034017563f)) + (var113[6ll] * 0.228550001978874f);
  var144[15ll][2ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * -0.0865830034017563f)) + (var113[10ll] * 0.228550001978874f);
  var142[15ll][2ll] = var142[15ll][2ll] + var113[3ll];
  var143[15ll][2ll] = var143[15ll][2ll] + var113[7ll];
  var144[15ll][2ll] = var144[15ll][2ll] + var113[11ll];
  var145[15ll][2ll] = 0.0120000001043081f;
  int var270;
  var270 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll]);
  if (var270)
    return 0; //collision pair: 0,15 : torso_0,l_gripper_r_finger_2_0
  var270 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll]);
  if (var270)
    return 0; //collision pair: 1,15 : head_0,l_gripper_r_finger_2_0
  var270 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll]);
  if (var270)
    return 0; //collision pair: 2,15 : left_upper_shoulder_0,l_gripper_r_finger_2_0
  var270 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll]);
  if (var270)
    return 0; //collision pair: 3,15 : left_lower_shoulder_0,l_gripper_r_finger_2_0
  var270 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll]);
  if (var270)
    return 0; //collision pair: 4,15 : left_upper_elbow_0,l_gripper_r_finger_2_0
  var270 = ctup_runtime::link_vs_environment_collision(var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], arg4);
  if (var270)
    return 0;
  var137[16ll] = ((var113[0ll] * 0.0f) + (var113[1ll] * -0.0825830027461052f)) + (var113[2ll] * 0.256249994039536f);
  var138[16ll] = ((var113[4ll] * 0.0f) + (var113[5ll] * -0.0825830027461052f)) + (var113[6ll] * 0.256249994039536f);
  var139[16ll] = ((var113[8ll] * 0.0f) + (var113[9ll] * -0.0825830027461052f)) + (var113[10ll] * 0.256249994039536f);
  var137[16ll] = var137[16ll] + var113[3ll];
  var138[16ll] = var138[16ll] + var113[7ll];
  var139[16ll] = var139[16ll] + var113[11ll];
  var140[16ll] = 0.0280000008642673f;
  var141[16ll] = 4ll;
  var142[16ll][0ll] = ((var113[0ll] * 0.00999999977648258f) + (var113[1ll] * -0.0820830017328262f)) + (var113[2ll] * 0.266250014305115f);
  var143[16ll][0ll] = ((var113[4ll] * 0.00999999977648258f) + (var113[5ll] * -0.0820830017328262f)) + (var113[6ll] * 0.266250014305115f);
  var144[16ll][0ll] = ((var113[8ll] * 0.00999999977648258f) + (var113[9ll] * -0.0820830017328262f)) + (var113[10ll] * 0.266250014305115f);
  var142[16ll][0ll] = var142[16ll][0ll] + var113[3ll];
  var143[16ll][0ll] = var143[16ll][0ll] + var113[7ll];
  var144[16ll][0ll] = var144[16ll][0ll] + var113[11ll];
  var145[16ll][0ll] = 0.0140000004321337f;
  var142[16ll][1ll] = ((var113[0ll] * -0.00999999977648258f) + (var113[1ll] * -0.0820830017328262f)) + (var113[2ll] * 0.266250014305115f);
  var143[16ll][1ll] = ((var113[4ll] * -0.00999999977648258f) + (var113[5ll] * -0.0820830017328262f)) + (var113[6ll] * 0.266250014305115f);
  var144[16ll][1ll] = ((var113[8ll] * -0.00999999977648258f) + (var113[9ll] * -0.0820830017328262f)) + (var113[10ll] * 0.266250014305115f);
  var142[16ll][1ll] = var142[16ll][1ll] + var113[3ll];
  var143[16ll][1ll] = var143[16ll][1ll] + var113[7ll];
  var144[16ll][1ll] = var144[16ll][1ll] + var113[11ll];
  var145[16ll][1ll] = 0.0140000004321337f;
  var142[16ll][2ll] = ((var113[0ll] * -0.00999999977648258f) + (var113[1ll] * -0.0820830017328262f)) + (var113[2ll] * 0.246250003576279f);
  var143[16ll][2ll] = ((var113[4ll] * -0.00999999977648258f) + (var113[5ll] * -0.0820830017328262f)) + (var113[6ll] * 0.246250003576279f);
  var144[16ll][2ll] = ((var113[8ll] * -0.00999999977648258f) + (var113[9ll] * -0.0820830017328262f)) + (var113[10ll] * 0.246250003576279f);
  var142[16ll][2ll] = var142[16ll][2ll] + var113[3ll];
  var143[16ll][2ll] = var143[16ll][2ll] + var113[7ll];
  var144[16ll][2ll] = var144[16ll][2ll] + var113[11ll];
  var145[16ll][2ll] = 0.0140000004321337f;
  var142[16ll][3ll] = ((var113[0ll] * 0.00999999977648258f) + (var113[1ll] * -0.0820830017328262f)) + (var113[2ll] * 0.246250003576279f);
  var143[16ll][3ll] = ((var113[4ll] * 0.00999999977648258f) + (var113[5ll] * -0.0820830017328262f)) + (var113[6ll] * 0.246250003576279f);
  var144[16ll][3ll] = ((var113[8ll] * 0.00999999977648258f) + (var113[9ll] * -0.0820830017328262f)) + (var113[10ll] * 0.246250003576279f);
  var142[16ll][3ll] = var142[16ll][3ll] + var113[3ll];
  var143[16ll][3ll] = var143[16ll][3ll] + var113[7ll];
  var144[16ll][3ll] = var144[16ll][3ll] + var113[11ll];
  var145[16ll][3ll] = 0.0140000004321337f;
  int var271;
  var271 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll]);
  if (var271)
    return 0; //collision pair: 0,16 : torso_0,l_gripper_r_finger_tip_0
  var271 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll]);
  if (var271)
    return 0; //collision pair: 1,16 : head_0,l_gripper_r_finger_tip_0
  var271 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll]);
  if (var271)
    return 0; //collision pair: 2,16 : left_upper_shoulder_0,l_gripper_r_finger_tip_0
  var271 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll]);
  if (var271)
    return 0; //collision pair: 3,16 : left_lower_shoulder_0,l_gripper_r_finger_tip_0
  var271 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll]);
  if (var271)
    return 0; //collision pair: 4,16 : left_upper_elbow_0,l_gripper_r_finger_tip_0
  var271 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll]);
  if (var271)
    return 0; //collision pair: 5,16 : left_lower_elbow_0,l_gripper_r_finger_tip_0
  var271 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll]);
  if (var271)
    return 0; //collision pair: 6,16 : left_upper_forearm_0,l_gripper_r_finger_tip_0
  var271 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll]);
  if (var271)
    return 0; //collision pair: 7,16 : left_lower_forearm_0,l_gripper_r_finger_tip_0
  var271 = ctup_runtime::link_vs_environment_collision(var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], arg4);
  if (var271)
    return 0;
  blaze::StaticVector<float, 8> var272 = arg5[7ll];
  var72 = sin(var272);
  var73 = cos(var272);
  var71[0ll] = var73;
  var71[1ll] = -(var72);
  var71[2ll] = var72;
  var71[3ll] = var73;
  blaze::StaticVector<float, 8> var273;
  var273 = 0;
  var273 = var273 + (0.707105457782745f * var71[0ll]);
  var273 = var273 + (0.707108080387115f * var71[2ll]);
  var273 = var273 + (0 * 0);
  var273 = var273 + (0.0640272423624992f * 0);
  var146[4ll] = var273;
  blaze::StaticVector<float, 8> var274;
  var274 = 0;
  var274 = var274 + (0.707105457782745f * var71[1ll]);
  var274 = var274 + (0.707108080387115f * var71[3ll]);
  var274 = var274 + (0 * 0);
  var274 = var274 + (0.0640272423624992f * 0);
  var146[5ll] = var274;
  blaze::StaticVector<float, 8> var275;
  var275 = 0;
  var275 = var275 + (-0.707108080387115f * var71[0ll]);
  var275 = var275 + (0.707105457782745f * var71[2ll]);
  var275 = var275 + (0 * 0);
  var275 = var275 + (-0.259027391672134f * 0);
  var146[0ll] = var275;
  blaze::StaticVector<float, 8> var276;
  var276 = 0;
  var276 = var276 + (-0.707108080387115f * var71[1ll]);
  var276 = var276 + (0.707105457782745f * var71[3ll]);
  var276 = var276 + (0 * 0);
  var276 = var276 + (-0.259027391672134f * 0);
  var146[1ll] = var276;
  var116[0ll] = var146[4ll];
  var116[1ll] = var146[5ll];
  var116[2ll] = var146[0ll];
  var116[3ll] = var146[1ll];
  var137[18ll] = ((var116[0ll] * 0.0f) + (var116[1ll] * 0.0f)) + (0 * 0.174999997019768f);
  var138[18ll] = ((var116[2ll] * 0.0f) + (var116[3ll] * 0.0f)) + (0 * 0.174999997019768f);
  var139[18ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.174999997019768f);
  var137[18ll] = var137[18ll] + 0.0640272423624992f;
  var138[18ll] = var138[18ll] + -0.259027391672134f;
  var139[18ll] = var139[18ll] + 0.129626005887985f;
  var140[18ll] = 0.174999997019768f;
  var141[18ll] = 2ll;
  var142[18ll][0ll] = ((var116[0ll] * 0.0f) + (var116[1ll] * 0.0f)) + (0 * 0.25f);
  var143[18ll][0ll] = ((var116[2ll] * 0.0f) + (var116[3ll] * 0.0f)) + (0 * 0.25f);
  var144[18ll][0ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.25f);
  var142[18ll][0ll] = var142[18ll][0ll] + 0.0640272423624992f;
  var143[18ll][0ll] = var143[18ll][0ll] + -0.259027391672134f;
  var144[18ll][0ll] = var144[18ll][0ll] + 0.129626005887985f;
  var145[18ll][0ll] = 0.100000001490116f;
  var142[18ll][1ll] = ((var116[0ll] * 0.0f) + (var116[1ll] * 0.0f)) + (0 * 0.100000001490116f);
  var143[18ll][1ll] = ((var116[2ll] * 0.0f) + (var116[3ll] * 0.0f)) + (0 * 0.100000001490116f);
  var144[18ll][1ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.100000001490116f);
  var142[18ll][1ll] = var142[18ll][1ll] + 0.0640272423624992f;
  var143[18ll][1ll] = var143[18ll][1ll] + -0.259027391672134f;
  var144[18ll][1ll] = var144[18ll][1ll] + 0.129626005887985f;
  var145[18ll][1ll] = 0.100000001490116f;
  int var277;
  var277 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll]);
  if (var277)
    return 0; //collision pair: 7,18 : left_lower_forearm_0,right_upper_shoulder_0
  var277 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll]);
  if (var277)
    return 0; //collision pair: 8,18 : left_wrist_0,right_upper_shoulder_0
  var277 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll]);
  if (var277)
    return 0; //collision pair: 9,18 : left_hand_0,right_upper_shoulder_0
  var277 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll]);
  if (var277)
    return 0; //collision pair: 10,18 : left_gripper_base_0,right_upper_shoulder_0
  var277 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll]);
  if (var277)
    return 0; //collision pair: 11,18 : l_gripper_l_finger_0,right_upper_shoulder_0
  var277 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll]);
  if (var277)
    return 0; //collision pair: 12,18 : l_gripper_l_finger_2_0,right_upper_shoulder_0
  var277 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll]);
  if (var277)
    return 0; //collision pair: 13,18 : l_gripper_l_finger_tip_0,right_upper_shoulder_0
  var277 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll]);
  if (var277)
    return 0; //collision pair: 14,18 : l_gripper_r_finger_0,right_upper_shoulder_0
  var277 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll]);
  if (var277)
    return 0; //collision pair: 15,18 : l_gripper_r_finger_2_0,right_upper_shoulder_0
  var277 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll]);
  if (var277)
    return 0; //collision pair: 16,18 : l_gripper_r_finger_tip_0,right_upper_shoulder_0
  var277 = ctup_runtime::link_vs_environment_collision(var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], arg4);
  if (var277)
    return 0;
  blaze::StaticVector<float, 8> var278 = arg5[8ll];
  var75 = sin(var278);
  var76 = cos(var278);
  var74[0ll] = var76;
  var74[1ll] = -(var75);
  var74[2ll] = var75;
  var74[3ll] = var76;
  blaze::StaticVector<float, 8> var279;
  var279 = 0;
  var279 = var279 + (1.0f * var74[0ll]);
  var279 = var279 + (0 * var74[2ll]);
  var279 = var279 + (0 * 0);
  var279 = var279 + (0.0689999982714653f * 0);
  var146[4ll] = var279;
  blaze::StaticVector<float, 8> var280;
  var280 = 0;
  var280 = var280 + (1.0f * var74[1ll]);
  var280 = var280 + (0 * var74[3ll]);
  var280 = var280 + (0 * 0);
  var280 = var280 + (0.0689999982714653f * 0);
  var146[5ll] = var280;
  blaze::StaticVector<float, 8> var281;
  var281 = 0;
  var281 = var281 + (0 * var74[0ll]);
  var281 = var281 + (-1.0f * var74[2ll]);
  var281 = var281 + (0 * 0);
  var281 = var281 + (0.270350009202957f * 0);
  var146[2ll] = var281;
  blaze::StaticVector<float, 8> var282;
  var282 = 0;
  var282 = var282 + (0 * var74[1ll]);
  var282 = var282 + (-1.0f * var74[3ll]);
  var282 = var282 + (0 * 0);
  var282 = var282 + (0.270350009202957f * 0);
  var146[3ll] = var282;
  blaze::StaticVector<float, 8> var283;
  var283 = 0;
  var283 = var283 + (var116[0ll] * var146[4ll]);
  var283 = var283 + (var116[1ll] * 0);
  var283 = var283 + (0 * var146[2ll]);
  var283 = var283 + (0.0640272423624992f * 0);
  var119[0ll] = var283;
  blaze::StaticVector<float, 8> var284;
  var284 = 0;
  var284 = var284 + (var116[0ll] * var146[5ll]);
  var284 = var284 + (var116[1ll] * 0);
  var284 = var284 + (0 * var146[3ll]);
  var284 = var284 + (0.0640272423624992f * 0);
  var119[1ll] = var284;
  blaze::StaticVector<float, 8> var285;
  var285 = 0;
  var285 = var285 + (var116[0ll] * 0);
  var285 = var285 + (var116[1ll] * 1.0f);
  var285 = var285 + (0 * 0);
  var285 = var285 + (0.0640272423624992f * 0);
  var119[2ll] = var285;
  blaze::StaticVector<float, 8> var286;
  var286 = 0;
  var286 = var286 + (var116[0ll] * 0.0689999982714653f);
  var286 = var286 + (var116[1ll] * 0);
  var286 = var286 + (0 * 0.270350009202957f);
  var286 = var286 + (0.0640272423624992f * 1.0f);
  var119[3ll] = var286;
  blaze::StaticVector<float, 8> var287;
  var287 = 0;
  var287 = var287 + (var116[2ll] * var146[4ll]);
  var287 = var287 + (var116[3ll] * 0);
  var287 = var287 + (0 * var146[2ll]);
  var287 = var287 + (-0.259027391672134f * 0);
  var119[4ll] = var287;
  blaze::StaticVector<float, 8> var288;
  var288 = 0;
  var288 = var288 + (var116[2ll] * var146[5ll]);
  var288 = var288 + (var116[3ll] * 0);
  var288 = var288 + (0 * var146[3ll]);
  var288 = var288 + (-0.259027391672134f * 0);
  var119[5ll] = var288;
  blaze::StaticVector<float, 8> var289;
  var289 = 0;
  var289 = var289 + (var116[2ll] * 0);
  var289 = var289 + (var116[3ll] * 1.0f);
  var289 = var289 + (0 * 0);
  var289 = var289 + (-0.259027391672134f * 0);
  var119[6ll] = var289;
  blaze::StaticVector<float, 8> var290;
  var290 = 0;
  var290 = var290 + (var116[2ll] * 0.0689999982714653f);
  var290 = var290 + (var116[3ll] * 0);
  var290 = var290 + (0 * 0.270350009202957f);
  var290 = var290 + (-0.259027391672134f * 1.0f);
  var119[7ll] = var290;
  blaze::StaticVector<float, 8> var291;
  var291 = 0;
  var291 = var291 + (0 * var146[4ll]);
  var291 = var291 + (0 * 0);
  var291 = var291 + (1.0f * var146[2ll]);
  var291 = var291 + (0.129626005887985f * 0);
  var119[8ll] = var291;
  blaze::StaticVector<float, 8> var292;
  var292 = 0;
  var292 = var292 + (0 * var146[5ll]);
  var292 = var292 + (0 * 0);
  var292 = var292 + (1.0f * var146[3ll]);
  var292 = var292 + (0.129626005887985f * 0);
  var119[9ll] = var292;
  var137[19ll] = ((var119[0ll] * 0.0f) + (var119[1ll] * 0.0f)) + (var119[2ll] * 0.0f);
  var138[19ll] = ((var119[4ll] * 0.0f) + (var119[5ll] * 0.0f)) + (var119[6ll] * 0.0f);
  var139[19ll] = ((var119[8ll] * 0.0f) + (var119[9ll] * 0.0f)) + (0 * 0.0f);
  var137[19ll] = var137[19ll] + var119[3ll];
  var138[19ll] = var138[19ll] + var119[7ll];
  var139[19ll] = var139[19ll] + 0.399976015090942f;
  var140[19ll] = 0.100000001490116f;
  var141[19ll] = 0ll;
  int var293;
  var293 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 5,19 : left_lower_elbow_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 6,19 : left_upper_forearm_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 7,19 : left_lower_forearm_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 8,19 : left_wrist_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 9,19 : left_hand_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 10,19 : left_gripper_base_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 11,19 : l_gripper_l_finger_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 12,19 : l_gripper_l_finger_2_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 13,19 : l_gripper_l_finger_tip_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 14,19 : l_gripper_r_finger_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 15,19 : l_gripper_r_finger_2_0,right_lower_shoulder_0
  var293 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll]);
  if (var293)
    return 0; //collision pair: 16,19 : l_gripper_r_finger_tip_0,right_lower_shoulder_0
  var293 = ctup_runtime::link_vs_environment_collision(var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll], arg4);
  if (var293)
    return 0;
  blaze::StaticVector<float, 8> var294 = arg5[9ll];
  var78 = sin(var294);
  var79 = cos(var294);
  var77[0ll] = var79;
  var77[1ll] = -(var78);
  var77[2ll] = var78;
  var77[3ll] = var79;
  blaze::StaticVector<float, 8> var295;
  var295 = 0;
  var295 = var295 + (1.0f * var77[0ll]);
  var295 = var295 + (0 * var77[2ll]);
  var295 = var295 + (0 * 0);
  var295 = var295 + (0 * 0);
  var146[0ll] = var295;
  blaze::StaticVector<float, 8> var296;
  var296 = 0;
  var296 = var296 + (1.0f * var77[1ll]);
  var296 = var296 + (0 * var77[3ll]);
  var296 = var296 + (0 * 0);
  var296 = var296 + (0 * 0);
  var146[1ll] = var296;
  blaze::StaticVector<float, 8> var297;
  var297 = 0;
  var297 = var297 + (0 * var77[0ll]);
  var297 = var297 + (1.0f * var77[2ll]);
  var297 = var297 + (0 * 0);
  var297 = var297 + (0 * 0);
  var146[2ll] = var297;
  blaze::StaticVector<float, 8> var298;
  var298 = 0;
  var298 = var298 + (0 * var77[1ll]);
  var298 = var298 + (1.0f * var77[3ll]);
  var298 = var298 + (0 * 0);
  var298 = var298 + (0 * 0);
  var146[3ll] = var298;
  blaze::StaticVector<float, 8> var299;
  var299 = 0;
  var299 = var299 + (var119[0ll] * 0);
  var299 = var299 + (var119[1ll] * var146[0ll]);
  var299 = var299 + (var119[2ll] * var146[2ll]);
  var299 = var299 + (var119[3ll] * 0);
  var122[0ll] = var299;
  blaze::StaticVector<float, 8> var300;
  var300 = 0;
  var300 = var300 + (var119[0ll] * 0);
  var300 = var300 + (var119[1ll] * var146[1ll]);
  var300 = var300 + (var119[2ll] * var146[3ll]);
  var300 = var300 + (var119[3ll] * 0);
  var122[1ll] = var300;
  blaze::StaticVector<float, 8> var301;
  var301 = 0;
  var301 = var301 + (var119[0ll] * 1.0f);
  var301 = var301 + (var119[1ll] * 0);
  var301 = var301 + (var119[2ll] * 0);
  var301 = var301 + (var119[3ll] * 0);
  var122[2ll] = var301;
  blaze::StaticVector<float, 8> var302;
  var302 = 0;
  var302 = var302 + (var119[0ll] * 0.101999998092651f);
  var302 = var302 + (var119[1ll] * 0);
  var302 = var302 + (var119[2ll] * 0);
  var302 = var302 + (var119[3ll] * 1.0f);
  var122[3ll] = var302;
  blaze::StaticVector<float, 8> var303;
  var303 = 0;
  var303 = var303 + (var119[4ll] * 0);
  var303 = var303 + (var119[5ll] * var146[0ll]);
  var303 = var303 + (var119[6ll] * var146[2ll]);
  var303 = var303 + (var119[7ll] * 0);
  var122[4ll] = var303;
  blaze::StaticVector<float, 8> var304;
  var304 = 0;
  var304 = var304 + (var119[4ll] * 0);
  var304 = var304 + (var119[5ll] * var146[1ll]);
  var304 = var304 + (var119[6ll] * var146[3ll]);
  var304 = var304 + (var119[7ll] * 0);
  var122[5ll] = var304;
  blaze::StaticVector<float, 8> var305;
  var305 = 0;
  var305 = var305 + (var119[4ll] * 1.0f);
  var305 = var305 + (var119[5ll] * 0);
  var305 = var305 + (var119[6ll] * 0);
  var305 = var305 + (var119[7ll] * 0);
  var122[6ll] = var305;
  blaze::StaticVector<float, 8> var306;
  var306 = 0;
  var306 = var306 + (var119[4ll] * 0.101999998092651f);
  var306 = var306 + (var119[5ll] * 0);
  var306 = var306 + (var119[6ll] * 0);
  var306 = var306 + (var119[7ll] * 1.0f);
  var122[7ll] = var306;
  blaze::StaticVector<float, 8> var307;
  var307 = 0;
  var307 = var307 + (var119[8ll] * 0);
  var307 = var307 + (var119[9ll] * var146[0ll]);
  var307 = var307 + (0 * var146[2ll]);
  var307 = var307 + (0.399976015090942f * 0);
  var122[8ll] = var307;
  blaze::StaticVector<float, 8> var308;
  var308 = 0;
  var308 = var308 + (var119[8ll] * 0);
  var308 = var308 + (var119[9ll] * var146[1ll]);
  var308 = var308 + (0 * var146[3ll]);
  var308 = var308 + (0.399976015090942f * 0);
  var122[9ll] = var308;
  blaze::StaticVector<float, 8> var309;
  var309 = 0;
  var309 = var309 + (var119[8ll] * 1.0f);
  var309 = var309 + (var119[9ll] * 0);
  var309 = var309 + (0 * 0);
  var309 = var309 + (0.399976015090942f * 0);
  var122[10ll] = var309;
  blaze::StaticVector<float, 8> var310;
  var310 = 0;
  var310 = var310 + (var119[8ll] * 0.101999998092651f);
  var310 = var310 + (var119[9ll] * 0);
  var310 = var310 + (0 * 0);
  var310 = var310 + (0.399976015090942f * 1.0f);
  var122[11ll] = var310;
  var137[20ll] = ((var122[0ll] * -0.00999999977648258f) + (var122[1ll] * 0.0f)) + (var122[2ll] * 0.109999999403954f);
  var138[20ll] = ((var122[4ll] * -0.00999999977648258f) + (var122[5ll] * 0.0f)) + (var122[6ll] * 0.109999999403954f);
  var139[20ll] = ((var122[8ll] * -0.00999999977648258f) + (var122[9ll] * 0.0f)) + (var122[10ll] * 0.109999999403954f);
  var137[20ll] = var137[20ll] + var122[3ll];
  var138[20ll] = var138[20ll] + var122[7ll];
  var139[20ll] = var139[20ll] + var122[11ll];
  var140[20ll] = 0.189999997615814f;
  var141[20ll] = 3ll;
  var142[20ll][0ll] = ((var122[0ll] * -0.0199999995529652f) + (var122[1ll] * 0.0f)) + (var122[2ll] * 0.219999998807907f);
  var143[20ll][0ll] = ((var122[4ll] * -0.0199999995529652f) + (var122[5ll] * 0.0f)) + (var122[6ll] * 0.219999998807907f);
  var144[20ll][0ll] = ((var122[8ll] * -0.0199999995529652f) + (var122[9ll] * 0.0f)) + (var122[10ll] * 0.219999998807907f);
  var142[20ll][0ll] = var142[20ll][0ll] + var122[3ll];
  var143[20ll][0ll] = var143[20ll][0ll] + var122[7ll];
  var144[20ll][0ll] = var144[20ll][0ll] + var122[11ll];
  var145[20ll][0ll] = 0.0799999982118607f;
  var142[20ll][1ll] = ((var122[0ll] * -0.00999999977648258f) + (var122[1ll] * 0.0f)) + (var122[2ll] * 0.109999999403954f);
  var143[20ll][1ll] = ((var122[4ll] * -0.00999999977648258f) + (var122[5ll] * 0.0f)) + (var122[6ll] * 0.109999999403954f);
  var144[20ll][1ll] = ((var122[8ll] * -0.00999999977648258f) + (var122[9ll] * 0.0f)) + (var122[10ll] * 0.109999999403954f);
  var142[20ll][1ll] = var142[20ll][1ll] + var122[3ll];
  var143[20ll][1ll] = var143[20ll][1ll] + var122[7ll];
  var144[20ll][1ll] = var144[20ll][1ll] + var122[11ll];
  var145[20ll][1ll] = 0.0799999982118607f;
  var142[20ll][2ll] = ((var122[0ll] * 0.0f) + (var122[1ll] * 0.0f)) + (var122[2ll] * 0.0f);
  var143[20ll][2ll] = ((var122[4ll] * 0.0f) + (var122[5ll] * 0.0f)) + (var122[6ll] * 0.0f);
  var144[20ll][2ll] = ((var122[8ll] * 0.0f) + (var122[9ll] * 0.0f)) + (var122[10ll] * 0.0f);
  var142[20ll][2ll] = var142[20ll][2ll] + var122[3ll];
  var143[20ll][2ll] = var143[20ll][2ll] + var122[7ll];
  var144[20ll][2ll] = var144[20ll][2ll] + var122[11ll];
  var145[20ll][2ll] = 0.0799999982118607f;
  int var311;
  var311 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 5,20 : left_lower_elbow_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 6,20 : left_upper_forearm_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 7,20 : left_lower_forearm_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 8,20 : left_wrist_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 9,20 : left_hand_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 10,20 : left_gripper_base_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 11,20 : l_gripper_l_finger_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 12,20 : l_gripper_l_finger_2_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 13,20 : l_gripper_l_finger_tip_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 14,20 : l_gripper_r_finger_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 15,20 : l_gripper_r_finger_2_0,right_upper_elbow_0
  var311 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll]);
  if (var311)
    return 0; //collision pair: 16,20 : l_gripper_r_finger_tip_0,right_upper_elbow_0
  var311 = ctup_runtime::link_vs_environment_collision(var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll], arg4);
  if (var311)
    return 0;
  blaze::StaticVector<float, 8> var312 = arg5[10ll];
  var81 = sin(var312);
  var82 = cos(var312);
  var80[0ll] = var82;
  var80[1ll] = -(var81);
  var80[2ll] = var81;
  var80[3ll] = var82;
  blaze::StaticVector<float, 8> var313;
  var313 = 0;
  var313 = var313 + (0 * var80[0ll]);
  var313 = var313 + (1.0f * var80[2ll]);
  var313 = var313 + (0 * 0);
  var313 = var313 + (0.0689999982714653f * 0);
  var146[4ll] = var313;
  blaze::StaticVector<float, 8> var314;
  var314 = 0;
  var314 = var314 + (0 * var80[1ll]);
  var314 = var314 + (1.0f * var80[3ll]);
  var314 = var314 + (0 * 0);
  var314 = var314 + (0.0689999982714653f * 0);
  var146[5ll] = var314;
  blaze::StaticVector<float, 8> var315;
  var315 = 0;
  var315 = var315 + (1.0f * var80[0ll]);
  var315 = var315 + (0 * var80[2ll]);
  var315 = var315 + (0 * 0);
  var315 = var315 + (0.262419998645782f * 0);
  var146[2ll] = var315;
  blaze::StaticVector<float, 8> var316;
  var316 = 0;
  var316 = var316 + (1.0f * var80[1ll]);
  var316 = var316 + (0 * var80[3ll]);
  var316 = var316 + (0 * 0);
  var316 = var316 + (0.262419998645782f * 0);
  var146[3ll] = var316;
  blaze::StaticVector<float, 8> var317;
  var317 = 0;
  var317 = var317 + (var122[0ll] * var146[4ll]);
  var317 = var317 + (var122[1ll] * 0);
  var317 = var317 + (var122[2ll] * var146[2ll]);
  var317 = var317 + (var122[3ll] * 0);
  var125[0ll] = var317;
  blaze::StaticVector<float, 8> var318;
  var318 = 0;
  var318 = var318 + (var122[0ll] * var146[5ll]);
  var318 = var318 + (var122[1ll] * 0);
  var318 = var318 + (var122[2ll] * var146[3ll]);
  var318 = var318 + (var122[3ll] * 0);
  var125[1ll] = var318;
  blaze::StaticVector<float, 8> var319;
  var319 = 0;
  var319 = var319 + (var122[0ll] * 0);
  var319 = var319 + (var122[1ll] * 1.0f);
  var319 = var319 + (var122[2ll] * 0);
  var319 = var319 + (var122[3ll] * 0);
  var125[2ll] = var319;
  blaze::StaticVector<float, 8> var320;
  var320 = 0;
  var320 = var320 + (var122[0ll] * 0.0689999982714653f);
  var320 = var320 + (var122[1ll] * 0);
  var320 = var320 + (var122[2ll] * 0.262419998645782f);
  var320 = var320 + (var122[3ll] * 1.0f);
  var125[3ll] = var320;
  blaze::StaticVector<float, 8> var321;
  var321 = 0;
  var321 = var321 + (var122[4ll] * var146[4ll]);
  var321 = var321 + (var122[5ll] * 0);
  var321 = var321 + (var122[6ll] * var146[2ll]);
  var321 = var321 + (var122[7ll] * 0);
  var125[4ll] = var321;
  blaze::StaticVector<float, 8> var322;
  var322 = 0;
  var322 = var322 + (var122[4ll] * var146[5ll]);
  var322 = var322 + (var122[5ll] * 0);
  var322 = var322 + (var122[6ll] * var146[3ll]);
  var322 = var322 + (var122[7ll] * 0);
  var125[5ll] = var322;
  blaze::StaticVector<float, 8> var323;
  var323 = 0;
  var323 = var323 + (var122[4ll] * 0);
  var323 = var323 + (var122[5ll] * 1.0f);
  var323 = var323 + (var122[6ll] * 0);
  var323 = var323 + (var122[7ll] * 0);
  var125[6ll] = var323;
  blaze::StaticVector<float, 8> var324;
  var324 = 0;
  var324 = var324 + (var122[4ll] * 0.0689999982714653f);
  var324 = var324 + (var122[5ll] * 0);
  var324 = var324 + (var122[6ll] * 0.262419998645782f);
  var324 = var324 + (var122[7ll] * 1.0f);
  var125[7ll] = var324;
  blaze::StaticVector<float, 8> var325;
  var325 = 0;
  var325 = var325 + (var122[8ll] * var146[4ll]);
  var325 = var325 + (var122[9ll] * 0);
  var325 = var325 + (var122[10ll] * var146[2ll]);
  var325 = var325 + (var122[11ll] * 0);
  var125[8ll] = var325;
  blaze::StaticVector<float, 8> var326;
  var326 = 0;
  var326 = var326 + (var122[8ll] * var146[5ll]);
  var326 = var326 + (var122[9ll] * 0);
  var326 = var326 + (var122[10ll] * var146[3ll]);
  var326 = var326 + (var122[11ll] * 0);
  var125[9ll] = var326;
  blaze::StaticVector<float, 8> var327;
  var327 = 0;
  var327 = var327 + (var122[8ll] * 0);
  var327 = var327 + (var122[9ll] * 1.0f);
  var327 = var327 + (var122[10ll] * 0);
  var327 = var327 + (var122[11ll] * 0);
  var125[10ll] = var327;
  blaze::StaticVector<float, 8> var328;
  var328 = 0;
  var328 = var328 + (var122[8ll] * 0.0689999982714653f);
  var328 = var328 + (var122[9ll] * 0);
  var328 = var328 + (var122[10ll] * 0.262419998645782f);
  var328 = var328 + (var122[11ll] * 1.0f);
  var125[11ll] = var328;
  var137[21ll] = ((var125[0ll] * 0.0f) + (var125[1ll] * 0.0f)) + (var125[2ll] * 0.0f);
  var138[21ll] = ((var125[4ll] * 0.0f) + (var125[5ll] * 0.0f)) + (var125[6ll] * 0.0f);
  var139[21ll] = ((var125[8ll] * 0.0f) + (var125[9ll] * 0.0f)) + (var125[10ll] * 0.0f);
  var137[21ll] = var137[21ll] + var125[3ll];
  var138[21ll] = var138[21ll] + var125[7ll];
  var139[21ll] = var139[21ll] + var125[11ll];
  var140[21ll] = 0.100000001490116f;
  var141[21ll] = 0ll;
  int var329;
  var329 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 0,21 : torso_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 1,21 : head_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 3,21 : left_lower_shoulder_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 4,21 : left_upper_elbow_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 5,21 : left_lower_elbow_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 6,21 : left_upper_forearm_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 7,21 : left_lower_forearm_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 8,21 : left_wrist_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 9,21 : left_hand_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 10,21 : left_gripper_base_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 11,21 : l_gripper_l_finger_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 12,21 : l_gripper_l_finger_2_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 13,21 : l_gripper_l_finger_tip_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 14,21 : l_gripper_r_finger_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 15,21 : l_gripper_r_finger_2_0,right_lower_elbow_0
  var329 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll]);
  if (var329)
    return 0; //collision pair: 16,21 : l_gripper_r_finger_tip_0,right_lower_elbow_0
  var329 = ctup_runtime::link_vs_environment_collision(var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll], arg4);
  if (var329)
    return 0;
  blaze::StaticVector<float, 8> var330 = arg5[11ll];
  var84 = sin(var330);
  var85 = cos(var330);
  var83[0ll] = var85;
  var83[1ll] = -(var84);
  var83[2ll] = var84;
  var83[3ll] = var85;
  blaze::StaticVector<float, 8> var331;
  var331 = 0;
  var331 = var331 + (1.0f * var83[0ll]);
  var331 = var331 + (0 * var83[2ll]);
  var331 = var331 + (0 * 0);
  var331 = var331 + (0 * 0);
  var146[0ll] = var331;
  blaze::StaticVector<float, 8> var332;
  var332 = 0;
  var332 = var332 + (1.0f * var83[1ll]);
  var332 = var332 + (0 * var83[3ll]);
  var332 = var332 + (0 * 0);
  var332 = var332 + (0 * 0);
  var146[1ll] = var332;
  blaze::StaticVector<float, 8> var333;
  var333 = 0;
  var333 = var333 + (0 * var83[0ll]);
  var333 = var333 + (1.0f * var83[2ll]);
  var333 = var333 + (0 * 0);
  var333 = var333 + (0 * 0);
  var146[2ll] = var333;
  blaze::StaticVector<float, 8> var334;
  var334 = 0;
  var334 = var334 + (0 * var83[1ll]);
  var334 = var334 + (1.0f * var83[3ll]);
  var334 = var334 + (0 * 0);
  var334 = var334 + (0 * 0);
  var146[3ll] = var334;
  blaze::StaticVector<float, 8> var335;
  var335 = 0;
  var335 = var335 + (var125[0ll] * 0);
  var335 = var335 + (var125[1ll] * var146[0ll]);
  var335 = var335 + (var125[2ll] * var146[2ll]);
  var335 = var335 + (var125[3ll] * 0);
  var128[0ll] = var335;
  blaze::StaticVector<float, 8> var336;
  var336 = 0;
  var336 = var336 + (var125[0ll] * 0);
  var336 = var336 + (var125[1ll] * var146[1ll]);
  var336 = var336 + (var125[2ll] * var146[3ll]);
  var336 = var336 + (var125[3ll] * 0);
  var128[1ll] = var336;
  blaze::StaticVector<float, 8> var337;
  var337 = 0;
  var337 = var337 + (var125[0ll] * 1.0f);
  var337 = var337 + (var125[1ll] * 0);
  var337 = var337 + (var125[2ll] * 0);
  var337 = var337 + (var125[3ll] * 0);
  var128[2ll] = var337;
  blaze::StaticVector<float, 8> var338;
  var338 = 0;
  var338 = var338 + (var125[0ll] * 0.103589996695518f);
  var338 = var338 + (var125[1ll] * 0);
  var338 = var338 + (var125[2ll] * 0);
  var338 = var338 + (var125[3ll] * 1.0f);
  var128[3ll] = var338;
  blaze::StaticVector<float, 8> var339;
  var339 = 0;
  var339 = var339 + (var125[4ll] * 0);
  var339 = var339 + (var125[5ll] * var146[0ll]);
  var339 = var339 + (var125[6ll] * var146[2ll]);
  var339 = var339 + (var125[7ll] * 0);
  var128[4ll] = var339;
  blaze::StaticVector<float, 8> var340;
  var340 = 0;
  var340 = var340 + (var125[4ll] * 0);
  var340 = var340 + (var125[5ll] * var146[1ll]);
  var340 = var340 + (var125[6ll] * var146[3ll]);
  var340 = var340 + (var125[7ll] * 0);
  var128[5ll] = var340;
  blaze::StaticVector<float, 8> var341;
  var341 = 0;
  var341 = var341 + (var125[4ll] * 1.0f);
  var341 = var341 + (var125[5ll] * 0);
  var341 = var341 + (var125[6ll] * 0);
  var341 = var341 + (var125[7ll] * 0);
  var128[6ll] = var341;
  blaze::StaticVector<float, 8> var342;
  var342 = 0;
  var342 = var342 + (var125[4ll] * 0.103589996695518f);
  var342 = var342 + (var125[5ll] * 0);
  var342 = var342 + (var125[6ll] * 0);
  var342 = var342 + (var125[7ll] * 1.0f);
  var128[7ll] = var342;
  blaze::StaticVector<float, 8> var343;
  var343 = 0;
  var343 = var343 + (var125[8ll] * 0);
  var343 = var343 + (var125[9ll] * var146[0ll]);
  var343 = var343 + (var125[10ll] * var146[2ll]);
  var343 = var343 + (var125[11ll] * 0);
  var128[8ll] = var343;
  blaze::StaticVector<float, 8> var344;
  var344 = 0;
  var344 = var344 + (var125[8ll] * 0);
  var344 = var344 + (var125[9ll] * var146[1ll]);
  var344 = var344 + (var125[10ll] * var146[3ll]);
  var344 = var344 + (var125[11ll] * 0);
  var128[9ll] = var344;
  blaze::StaticVector<float, 8> var345;
  var345 = 0;
  var345 = var345 + (var125[8ll] * 1.0f);
  var345 = var345 + (var125[9ll] * 0);
  var345 = var345 + (var125[10ll] * 0);
  var345 = var345 + (var125[11ll] * 0);
  var128[10ll] = var345;
  blaze::StaticVector<float, 8> var346;
  var346 = 0;
  var346 = var346 + (var125[8ll] * 0.103589996695518f);
  var346 = var346 + (var125[9ll] * 0);
  var346 = var346 + (var125[10ll] * 0);
  var346 = var346 + (var125[11ll] * 1.0f);
  var128[11ll] = var346;
  var137[22ll] = ((var128[0ll] * 0.0f) + (var128[1ll] * 0.0f)) + (var128[2ll] * 0.109999999403954f);
  var138[22ll] = ((var128[4ll] * 0.0f) + (var128[5ll] * 0.0f)) + (var128[6ll] * 0.109999999403954f);
  var139[22ll] = ((var128[8ll] * 0.0f) + (var128[9ll] * 0.0f)) + (var128[10ll] * 0.109999999403954f);
  var137[22ll] = var137[22ll] + var128[3ll];
  var138[22ll] = var138[22ll] + var128[7ll];
  var139[22ll] = var139[22ll] + var128[11ll];
  var140[22ll] = 0.189999997615814f;
  var141[22ll] = 3ll;
  var142[22ll][0ll] = ((var128[0ll] * 0.0f) + (var128[1ll] * 0.0f)) + (var128[2ll] * 0.0f);
  var143[22ll][0ll] = ((var128[4ll] * 0.0f) + (var128[5ll] * 0.0f)) + (var128[6ll] * 0.0f);
  var144[22ll][0ll] = ((var128[8ll] * 0.0f) + (var128[9ll] * 0.0f)) + (var128[10ll] * 0.0f);
  var142[22ll][0ll] = var142[22ll][0ll] + var128[3ll];
  var143[22ll][0ll] = var143[22ll][0ll] + var128[7ll];
  var144[22ll][0ll] = var144[22ll][0ll] + var128[11ll];
  var145[22ll][0ll] = 0.0799999982118607f;
  var142[22ll][1ll] = ((var128[0ll] * 0.0f) + (var128[1ll] * 0.0f)) + (var128[2ll] * 0.219999998807907f);
  var143[22ll][1ll] = ((var128[4ll] * 0.0f) + (var128[5ll] * 0.0f)) + (var128[6ll] * 0.219999998807907f);
  var144[22ll][1ll] = ((var128[8ll] * 0.0f) + (var128[9ll] * 0.0f)) + (var128[10ll] * 0.219999998807907f);
  var142[22ll][1ll] = var142[22ll][1ll] + var128[3ll];
  var143[22ll][1ll] = var143[22ll][1ll] + var128[7ll];
  var144[22ll][1ll] = var144[22ll][1ll] + var128[11ll];
  var145[22ll][1ll] = 0.0799999982118607f;
  var142[22ll][2ll] = ((var128[0ll] * 0.0f) + (var128[1ll] * 0.0f)) + (var128[2ll] * 0.109999999403954f);
  var143[22ll][2ll] = ((var128[4ll] * 0.0f) + (var128[5ll] * 0.0f)) + (var128[6ll] * 0.109999999403954f);
  var144[22ll][2ll] = ((var128[8ll] * 0.0f) + (var128[9ll] * 0.0f)) + (var128[10ll] * 0.109999999403954f);
  var142[22ll][2ll] = var142[22ll][2ll] + var128[3ll];
  var143[22ll][2ll] = var143[22ll][2ll] + var128[7ll];
  var144[22ll][2ll] = var144[22ll][2ll] + var128[11ll];
  var145[22ll][2ll] = 0.0799999982118607f;
  int var347;
  var347 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 0,22 : torso_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 1,22 : head_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 3,22 : left_lower_shoulder_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 4,22 : left_upper_elbow_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 5,22 : left_lower_elbow_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 6,22 : left_upper_forearm_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 7,22 : left_lower_forearm_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 8,22 : left_wrist_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 9,22 : left_hand_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 10,22 : left_gripper_base_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 11,22 : l_gripper_l_finger_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 12,22 : l_gripper_l_finger_2_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 13,22 : l_gripper_l_finger_tip_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 14,22 : l_gripper_r_finger_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 15,22 : l_gripper_r_finger_2_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 16,22 : l_gripper_r_finger_tip_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 17,22 : pedestal_0,right_upper_forearm_0
  var347 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll]);
  if (var347)
    return 0; //collision pair: 18,22 : right_upper_shoulder_0,right_upper_forearm_0
  var347 = ctup_runtime::link_vs_environment_collision(var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll], arg4);
  if (var347)
    return 0;
  blaze::StaticVector<float, 8> var348 = arg5[12ll];
  var87 = sin(var348);
  var88 = cos(var348);
  var86[0ll] = var88;
  var86[1ll] = -(var87);
  var86[2ll] = var87;
  var86[3ll] = var88;
  blaze::StaticVector<float, 8> var349;
  var349 = 0;
  var349 = var349 + (0 * var86[0ll]);
  var349 = var349 + (1.0f * var86[2ll]);
  var349 = var349 + (0 * 0);
  var349 = var349 + (0.00999999977648258f * 0);
  var146[4ll] = var349;
  blaze::StaticVector<float, 8> var350;
  var350 = 0;
  var350 = var350 + (0 * var86[1ll]);
  var350 = var350 + (1.0f * var86[3ll]);
  var350 = var350 + (0 * 0);
  var350 = var350 + (0.00999999977648258f * 0);
  var146[5ll] = var350;
  blaze::StaticVector<float, 8> var351;
  var351 = 0;
  var351 = var351 + (1.0f * var86[0ll]);
  var351 = var351 + (0 * var86[2ll]);
  var351 = var351 + (0 * 0);
  var351 = var351 + (0.270700007677078f * 0);
  var146[2ll] = var351;
  blaze::StaticVector<float, 8> var352;
  var352 = 0;
  var352 = var352 + (1.0f * var86[1ll]);
  var352 = var352 + (0 * var86[3ll]);
  var352 = var352 + (0 * 0);
  var352 = var352 + (0.270700007677078f * 0);
  var146[3ll] = var352;
  blaze::StaticVector<float, 8> var353;
  var353 = 0;
  var353 = var353 + (var128[0ll] * var146[4ll]);
  var353 = var353 + (var128[1ll] * 0);
  var353 = var353 + (var128[2ll] * var146[2ll]);
  var353 = var353 + (var128[3ll] * 0);
  var131[0ll] = var353;
  blaze::StaticVector<float, 8> var354;
  var354 = 0;
  var354 = var354 + (var128[0ll] * var146[5ll]);
  var354 = var354 + (var128[1ll] * 0);
  var354 = var354 + (var128[2ll] * var146[3ll]);
  var354 = var354 + (var128[3ll] * 0);
  var131[1ll] = var354;
  blaze::StaticVector<float, 8> var355;
  var355 = 0;
  var355 = var355 + (var128[0ll] * 0);
  var355 = var355 + (var128[1ll] * 1.0f);
  var355 = var355 + (var128[2ll] * 0);
  var355 = var355 + (var128[3ll] * 0);
  var131[2ll] = var355;
  blaze::StaticVector<float, 8> var356;
  var356 = 0;
  var356 = var356 + (var128[0ll] * 0.00999999977648258f);
  var356 = var356 + (var128[1ll] * 0);
  var356 = var356 + (var128[2ll] * 0.270700007677078f);
  var356 = var356 + (var128[3ll] * 1.0f);
  var131[3ll] = var356;
  blaze::StaticVector<float, 8> var357;
  var357 = 0;
  var357 = var357 + (var128[4ll] * var146[4ll]);
  var357 = var357 + (var128[5ll] * 0);
  var357 = var357 + (var128[6ll] * var146[2ll]);
  var357 = var357 + (var128[7ll] * 0);
  var131[4ll] = var357;
  blaze::StaticVector<float, 8> var358;
  var358 = 0;
  var358 = var358 + (var128[4ll] * var146[5ll]);
  var358 = var358 + (var128[5ll] * 0);
  var358 = var358 + (var128[6ll] * var146[3ll]);
  var358 = var358 + (var128[7ll] * 0);
  var131[5ll] = var358;
  blaze::StaticVector<float, 8> var359;
  var359 = 0;
  var359 = var359 + (var128[4ll] * 0);
  var359 = var359 + (var128[5ll] * 1.0f);
  var359 = var359 + (var128[6ll] * 0);
  var359 = var359 + (var128[7ll] * 0);
  var131[6ll] = var359;
  blaze::StaticVector<float, 8> var360;
  var360 = 0;
  var360 = var360 + (var128[4ll] * 0.00999999977648258f);
  var360 = var360 + (var128[5ll] * 0);
  var360 = var360 + (var128[6ll] * 0.270700007677078f);
  var360 = var360 + (var128[7ll] * 1.0f);
  var131[7ll] = var360;
  blaze::StaticVector<float, 8> var361;
  var361 = 0;
  var361 = var361 + (var128[8ll] * var146[4ll]);
  var361 = var361 + (var128[9ll] * 0);
  var361 = var361 + (var128[10ll] * var146[2ll]);
  var361 = var361 + (var128[11ll] * 0);
  var131[8ll] = var361;
  blaze::StaticVector<float, 8> var362;
  var362 = 0;
  var362 = var362 + (var128[8ll] * var146[5ll]);
  var362 = var362 + (var128[9ll] * 0);
  var362 = var362 + (var128[10ll] * var146[3ll]);
  var362 = var362 + (var128[11ll] * 0);
  var131[9ll] = var362;
  blaze::StaticVector<float, 8> var363;
  var363 = 0;
  var363 = var363 + (var128[8ll] * 0);
  var363 = var363 + (var128[9ll] * 1.0f);
  var363 = var363 + (var128[10ll] * 0);
  var363 = var363 + (var128[11ll] * 0);
  var131[10ll] = var363;
  blaze::StaticVector<float, 8> var364;
  var364 = 0;
  var364 = var364 + (var128[8ll] * 0.00999999977648258f);
  var364 = var364 + (var128[9ll] * 0);
  var364 = var364 + (var128[10ll] * 0.270700007677078f);
  var364 = var364 + (var128[11ll] * 1.0f);
  var131[11ll] = var364;
  var137[23ll] = ((var131[0ll] * 0.0f) + (var131[1ll] * 0.0f)) + (var131[2ll] * 0.0f);
  var138[23ll] = ((var131[4ll] * 0.0f) + (var131[5ll] * 0.0f)) + (var131[6ll] * 0.0f);
  var139[23ll] = ((var131[8ll] * 0.0f) + (var131[9ll] * 0.0f)) + (var131[10ll] * 0.0f);
  var137[23ll] = var137[23ll] + var131[3ll];
  var138[23ll] = var138[23ll] + var131[7ll];
  var139[23ll] = var139[23ll] + var131[11ll];
  var140[23ll] = 0.100000001490116f;
  var141[23ll] = 2ll;
  var142[23ll][0ll] = ((var131[0ll] * 0.0f) + (var131[1ll] * 0.0f)) + (var131[2ll] * 0.0299999993294477f);
  var143[23ll][0ll] = ((var131[4ll] * 0.0f) + (var131[5ll] * 0.0f)) + (var131[6ll] * 0.0299999993294477f);
  var144[23ll][0ll] = ((var131[8ll] * 0.0f) + (var131[9ll] * 0.0f)) + (var131[10ll] * 0.0299999993294477f);
  var142[23ll][0ll] = var142[23ll][0ll] + var131[3ll];
  var143[23ll][0ll] = var143[23ll][0ll] + var131[7ll];
  var144[23ll][0ll] = var144[23ll][0ll] + var131[11ll];
  var145[23ll][0ll] = 0.0700000002980232f;
  var142[23ll][1ll] = ((var131[0ll] * 0.0f) + (var131[1ll] * 0.0f)) + (var131[2ll] * -0.0299999993294477f);
  var143[23ll][1ll] = ((var131[4ll] * 0.0f) + (var131[5ll] * 0.0f)) + (var131[6ll] * -0.0299999993294477f);
  var144[23ll][1ll] = ((var131[8ll] * 0.0f) + (var131[9ll] * 0.0f)) + (var131[10ll] * -0.0299999993294477f);
  var142[23ll][1ll] = var142[23ll][1ll] + var131[3ll];
  var143[23ll][1ll] = var143[23ll][1ll] + var131[7ll];
  var144[23ll][1ll] = var144[23ll][1ll] + var131[11ll];
  var145[23ll][1ll] = 0.0700000002980232f;
  int var365;
  var365 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 0,23 : torso_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 1,23 : head_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 2,23 : left_upper_shoulder_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 3,23 : left_lower_shoulder_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 4,23 : left_upper_elbow_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 5,23 : left_lower_elbow_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 6,23 : left_upper_forearm_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 7,23 : left_lower_forearm_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 8,23 : left_wrist_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 9,23 : left_hand_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 10,23 : left_gripper_base_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 11,23 : l_gripper_l_finger_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 12,23 : l_gripper_l_finger_2_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 13,23 : l_gripper_l_finger_tip_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 14,23 : l_gripper_r_finger_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 15,23 : l_gripper_r_finger_2_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 16,23 : l_gripper_r_finger_tip_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 17,23 : pedestal_0,right_lower_forearm_0
  var365 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll]);
  if (var365)
    return 0; //collision pair: 18,23 : right_upper_shoulder_0,right_lower_forearm_0
  var365 = ctup_runtime::link_vs_environment_collision(var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll], arg4);
  if (var365)
    return 0;
  blaze::StaticVector<float, 8> var366 = arg5[13ll];
  var90 = sin(var366);
  var91 = cos(var366);
  var89[0ll] = var91;
  var89[1ll] = -(var90);
  var89[2ll] = var90;
  var89[3ll] = var91;
  blaze::StaticVector<float, 8> var367;
  var367 = 0;
  var367 = var367 + (1.0f * var89[0ll]);
  var367 = var367 + (0 * var89[2ll]);
  var367 = var367 + (0 * 0);
  var367 = var367 + (0 * 0);
  var146[0ll] = var367;
  blaze::StaticVector<float, 8> var368;
  var368 = 0;
  var368 = var368 + (1.0f * var89[1ll]);
  var368 = var368 + (0 * var89[3ll]);
  var368 = var368 + (0 * 0);
  var368 = var368 + (0 * 0);
  var146[1ll] = var368;
  blaze::StaticVector<float, 8> var369;
  var369 = 0;
  var369 = var369 + (0 * var89[0ll]);
  var369 = var369 + (1.0f * var89[2ll]);
  var369 = var369 + (0 * 0);
  var369 = var369 + (0 * 0);
  var146[2ll] = var369;
  blaze::StaticVector<float, 8> var370;
  var370 = 0;
  var370 = var370 + (0 * var89[1ll]);
  var370 = var370 + (1.0f * var89[3ll]);
  var370 = var370 + (0 * 0);
  var370 = var370 + (0 * 0);
  var146[3ll] = var370;
  blaze::StaticVector<float, 8> var371;
  var371 = 0;
  var371 = var371 + (var131[0ll] * 0);
  var371 = var371 + (var131[1ll] * var146[0ll]);
  var371 = var371 + (var131[2ll] * var146[2ll]);
  var371 = var371 + (var131[3ll] * 0);
  var134[0ll] = var371;
  blaze::StaticVector<float, 8> var372;
  var372 = 0;
  var372 = var372 + (var131[0ll] * 0);
  var372 = var372 + (var131[1ll] * var146[1ll]);
  var372 = var372 + (var131[2ll] * var146[3ll]);
  var372 = var372 + (var131[3ll] * 0);
  var134[1ll] = var372;
  blaze::StaticVector<float, 8> var373;
  var373 = 0;
  var373 = var373 + (var131[0ll] * 1.0f);
  var373 = var373 + (var131[1ll] * 0);
  var373 = var373 + (var131[2ll] * 0);
  var373 = var373 + (var131[3ll] * 0);
  var134[2ll] = var373;
  blaze::StaticVector<float, 8> var374;
  var374 = 0;
  var374 = var374 + (var131[0ll] * 0.115974999964237f);
  var374 = var374 + (var131[1ll] * 0);
  var374 = var374 + (var131[2ll] * 0);
  var374 = var374 + (var131[3ll] * 1.0f);
  var134[3ll] = var374;
  blaze::StaticVector<float, 8> var375;
  var375 = 0;
  var375 = var375 + (var131[4ll] * 0);
  var375 = var375 + (var131[5ll] * var146[0ll]);
  var375 = var375 + (var131[6ll] * var146[2ll]);
  var375 = var375 + (var131[7ll] * 0);
  var134[4ll] = var375;
  blaze::StaticVector<float, 8> var376;
  var376 = 0;
  var376 = var376 + (var131[4ll] * 0);
  var376 = var376 + (var131[5ll] * var146[1ll]);
  var376 = var376 + (var131[6ll] * var146[3ll]);
  var376 = var376 + (var131[7ll] * 0);
  var134[5ll] = var376;
  blaze::StaticVector<float, 8> var377;
  var377 = 0;
  var377 = var377 + (var131[4ll] * 1.0f);
  var377 = var377 + (var131[5ll] * 0);
  var377 = var377 + (var131[6ll] * 0);
  var377 = var377 + (var131[7ll] * 0);
  var134[6ll] = var377;
  blaze::StaticVector<float, 8> var378;
  var378 = 0;
  var378 = var378 + (var131[4ll] * 0.115974999964237f);
  var378 = var378 + (var131[5ll] * 0);
  var378 = var378 + (var131[6ll] * 0);
  var378 = var378 + (var131[7ll] * 1.0f);
  var134[7ll] = var378;
  blaze::StaticVector<float, 8> var379;
  var379 = 0;
  var379 = var379 + (var131[8ll] * 0);
  var379 = var379 + (var131[9ll] * var146[0ll]);
  var379 = var379 + (var131[10ll] * var146[2ll]);
  var379 = var379 + (var131[11ll] * 0);
  var134[8ll] = var379;
  blaze::StaticVector<float, 8> var380;
  var380 = 0;
  var380 = var380 + (var131[8ll] * 0);
  var380 = var380 + (var131[9ll] * var146[1ll]);
  var380 = var380 + (var131[10ll] * var146[3ll]);
  var380 = var380 + (var131[11ll] * 0);
  var134[9ll] = var380;
  blaze::StaticVector<float, 8> var381;
  var381 = 0;
  var381 = var381 + (var131[8ll] * 1.0f);
  var381 = var381 + (var131[9ll] * 0);
  var381 = var381 + (var131[10ll] * 0);
  var381 = var381 + (var131[11ll] * 0);
  var134[10ll] = var381;
  blaze::StaticVector<float, 8> var382;
  var382 = 0;
  var382 = var382 + (var131[8ll] * 0.115974999964237f);
  var382 = var382 + (var131[9ll] * 0);
  var382 = var382 + (var131[10ll] * 0);
  var382 = var382 + (var131[11ll] * 1.0f);
  var134[11ll] = var382;
  var137[24ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * 0.0f)) + (var134[2ll] * -0.0149999996647239f);
  var138[24ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * 0.0f)) + (var134[6ll] * -0.0149999996647239f);
  var139[24ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * 0.0f)) + (var134[10ll] * -0.0149999996647239f);
  var137[24ll] = var137[24ll] + var134[3ll];
  var138[24ll] = var138[24ll] + var134[7ll];
  var139[24ll] = var139[24ll] + var134[11ll];
  var140[24ll] = 0.104999996721745f;
  var141[24ll] = 2ll;
  var142[24ll][0ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * 0.0f)) + (var134[2ll] * 0.0199999995529652f);
  var143[24ll][0ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * 0.0f)) + (var134[6ll] * 0.0199999995529652f);
  var144[24ll][0ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * 0.0f)) + (var134[10ll] * 0.0199999995529652f);
  var142[24ll][0ll] = var142[24ll][0ll] + var134[3ll];
  var143[24ll][0ll] = var143[24ll][0ll] + var134[7ll];
  var144[24ll][0ll] = var144[24ll][0ll] + var134[11ll];
  var145[24ll][0ll] = 0.0700000002980232f;
  var142[24ll][1ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * 0.0f)) + (var134[2ll] * -0.0399999991059303f);
  var143[24ll][1ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * 0.0f)) + (var134[6ll] * -0.0399999991059303f);
  var144[24ll][1ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * 0.0f)) + (var134[10ll] * -0.0399999991059303f);
  var142[24ll][1ll] = var142[24ll][1ll] + var134[3ll];
  var143[24ll][1ll] = var143[24ll][1ll] + var134[7ll];
  var144[24ll][1ll] = var144[24ll][1ll] + var134[11ll];
  var145[24ll][1ll] = 0.0799999982118607f;
  int var383;
  var383 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 0,24 : torso_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 1,24 : head_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 2,24 : left_upper_shoulder_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 3,24 : left_lower_shoulder_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 4,24 : left_upper_elbow_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 5,24 : left_lower_elbow_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 6,24 : left_upper_forearm_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 7,24 : left_lower_forearm_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 8,24 : left_wrist_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 9,24 : left_hand_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 10,24 : left_gripper_base_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 11,24 : l_gripper_l_finger_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 12,24 : l_gripper_l_finger_2_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 13,24 : l_gripper_l_finger_tip_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 14,24 : l_gripper_r_finger_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 15,24 : l_gripper_r_finger_2_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 16,24 : l_gripper_r_finger_tip_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 17,24 : pedestal_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 18,24 : right_upper_shoulder_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 19,24 : right_lower_shoulder_0,right_wrist_0
  var383 = ctup_runtime::self_collision_link_vs_link(20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll], 24ll, var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll]);
  if (var383)
    return 0; //collision pair: 20,24 : right_upper_elbow_0,right_wrist_0
  var383 = ctup_runtime::link_vs_environment_collision(var137[24ll], var138[24ll], var139[24ll], var140[24ll], var141[24ll], var142[24ll], var143[24ll], var144[24ll], var145[24ll], arg4);
  if (var383)
    return 0;
  var137[25ll] = ((var134[0ll] * 0.00999999977648258f) + (var134[1ll] * 0.0f)) + (var134[2ll] * 0.0935499966144562f);
  var138[25ll] = ((var134[4ll] * 0.00999999977648258f) + (var134[5ll] * 0.0f)) + (var134[6ll] * 0.0935499966144562f);
  var139[25ll] = ((var134[8ll] * 0.00999999977648258f) + (var134[9ll] * 0.0f)) + (var134[10ll] * 0.0935499966144562f);
  var137[25ll] = var137[25ll] + var134[3ll];
  var138[25ll] = var138[25ll] + var134[7ll];
  var139[25ll] = var139[25ll] + var134[11ll];
  var140[25ll] = 0.0500000007450581f;
  var141[25ll] = 1ll;
  var142[25ll][0ll] = ((var134[0ll] * 0.00999999977648258f) + (var134[1ll] * 0.0f)) + (var134[2ll] * 0.0935499966144562f);
  var143[25ll][0ll] = ((var134[4ll] * 0.00999999977648258f) + (var134[5ll] * 0.0f)) + (var134[6ll] * 0.0935499966144562f);
  var144[25ll][0ll] = ((var134[8ll] * 0.00999999977648258f) + (var134[9ll] * 0.0f)) + (var134[10ll] * 0.0935499966144562f);
  var142[25ll][0ll] = var142[25ll][0ll] + var134[3ll];
  var143[25ll][0ll] = var143[25ll][0ll] + var134[7ll];
  var144[25ll][0ll] = var144[25ll][0ll] + var134[11ll];
  var145[25ll][0ll] = 0.0500000007450581f;
  int var384;
  var384 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 0,25 : torso_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 1,25 : head_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 2,25 : left_upper_shoulder_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 3,25 : left_lower_shoulder_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 4,25 : left_upper_elbow_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 5,25 : left_lower_elbow_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 6,25 : left_upper_forearm_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 7,25 : left_lower_forearm_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 8,25 : left_wrist_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 9,25 : left_hand_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 10,25 : left_gripper_base_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 11,25 : l_gripper_l_finger_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 12,25 : l_gripper_l_finger_2_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 13,25 : l_gripper_l_finger_tip_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 14,25 : l_gripper_r_finger_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 15,25 : l_gripper_r_finger_2_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 16,25 : l_gripper_r_finger_tip_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 17,25 : pedestal_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 18,25 : right_upper_shoulder_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 19,25 : right_lower_shoulder_0,right_hand_0
  var384 = ctup_runtime::self_collision_link_vs_link(20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll], 25ll, var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll]);
  if (var384)
    return 0; //collision pair: 20,25 : right_upper_elbow_0,right_hand_0
  var384 = ctup_runtime::link_vs_environment_collision(var137[25ll], var138[25ll], var139[25ll], var140[25ll], var141[25ll], var142[25ll], var143[25ll], var144[25ll], var145[25ll], arg4);
  if (var384)
    return 0;
  var137[26ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * 0.0f)) + (var134[2ll] * 0.138549998402596f);
  var138[26ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * 0.0f)) + (var134[6ll] * 0.138549998402596f);
  var139[26ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * 0.0f)) + (var134[10ll] * 0.138549998402596f);
  var137[26ll] = var137[26ll] + var134[3ll];
  var138[26ll] = var138[26ll] + var134[7ll];
  var139[26ll] = var139[26ll] + var134[11ll];
  var140[26ll] = 0.0599999986588955f;
  var141[26ll] = 2ll;
  var142[26ll][0ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * 0.0199999995529652f)) + (var134[2ll] * 0.138549998402596f);
  var143[26ll][0ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * 0.0199999995529652f)) + (var134[6ll] * 0.138549998402596f);
  var144[26ll][0ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * 0.0199999995529652f)) + (var134[10ll] * 0.138549998402596f);
  var142[26ll][0ll] = var142[26ll][0ll] + var134[3ll];
  var143[26ll][0ll] = var143[26ll][0ll] + var134[7ll];
  var144[26ll][0ll] = var144[26ll][0ll] + var134[11ll];
  var145[26ll][0ll] = 0.0399999991059303f;
  var142[26ll][1ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * -0.0199999995529652f)) + (var134[2ll] * 0.138549998402596f);
  var143[26ll][1ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * -0.0199999995529652f)) + (var134[6ll] * 0.138549998402596f);
  var144[26ll][1ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * -0.0199999995529652f)) + (var134[10ll] * 0.138549998402596f);
  var142[26ll][1ll] = var142[26ll][1ll] + var134[3ll];
  var143[26ll][1ll] = var143[26ll][1ll] + var134[7ll];
  var144[26ll][1ll] = var144[26ll][1ll] + var134[11ll];
  var145[26ll][1ll] = 0.0399999991059303f;
  int var385;
  var385 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 0,26 : torso_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 1,26 : head_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 2,26 : left_upper_shoulder_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 3,26 : left_lower_shoulder_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 4,26 : left_upper_elbow_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 5,26 : left_lower_elbow_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 6,26 : left_upper_forearm_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 7,26 : left_lower_forearm_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 8,26 : left_wrist_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 9,26 : left_hand_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 10,26 : left_gripper_base_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 11,26 : l_gripper_l_finger_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 12,26 : l_gripper_l_finger_2_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 13,26 : l_gripper_l_finger_tip_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 14,26 : l_gripper_r_finger_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 15,26 : l_gripper_r_finger_2_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 16,26 : l_gripper_r_finger_tip_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 17,26 : pedestal_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 18,26 : right_upper_shoulder_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 19,26 : right_lower_shoulder_0,right_gripper_base_0
  var385 = ctup_runtime::self_collision_link_vs_link(20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll], 26ll, var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll]);
  if (var385)
    return 0; //collision pair: 20,26 : right_upper_elbow_0,right_gripper_base_0
  var385 = ctup_runtime::link_vs_environment_collision(var137[26ll], var138[26ll], var139[26ll], var140[26ll], var141[26ll], var142[26ll], var143[26ll], var144[26ll], var145[26ll], arg4);
  if (var385)
    return 0;
  var137[27ll] = ((var134[0ll] * -0.00499999988824129f) + (var134[1ll] * 0.0693330019712448f)) + (var134[2ll] * 0.166549995541573f);
  var138[27ll] = ((var134[4ll] * -0.00499999988824129f) + (var134[5ll] * 0.0693330019712448f)) + (var134[6ll] * 0.166549995541573f);
  var139[27ll] = ((var134[8ll] * -0.00499999988824129f) + (var134[9ll] * 0.0693330019712448f)) + (var134[10ll] * 0.166549995541573f);
  var137[27ll] = var137[27ll] + var134[3ll];
  var138[27ll] = var138[27ll] + var134[7ll];
  var139[27ll] = var139[27ll] + var134[11ll];
  var140[27ll] = 0.0270000007003546f;
  var141[27ll] = 2ll;
  var142[27ll][0ll] = ((var134[0ll] * -0.00499999988824129f) + (var134[1ll] * 0.0813329964876175f)) + (var134[2ll] * 0.166549995541573f);
  var143[27ll][0ll] = ((var134[4ll] * -0.00499999988824129f) + (var134[5ll] * 0.0813329964876175f)) + (var134[6ll] * 0.166549995541573f);
  var144[27ll][0ll] = ((var134[8ll] * -0.00499999988824129f) + (var134[9ll] * 0.0813329964876175f)) + (var134[10ll] * 0.166549995541573f);
  var142[27ll][0ll] = var142[27ll][0ll] + var134[3ll];
  var143[27ll][0ll] = var143[27ll][0ll] + var134[7ll];
  var144[27ll][0ll] = var144[27ll][0ll] + var134[11ll];
  var145[27ll][0ll] = 0.0149999996647239f;
  var142[27ll][1ll] = ((var134[0ll] * -0.00499999988824129f) + (var134[1ll] * 0.0573330000042915f)) + (var134[2ll] * 0.166549995541573f);
  var143[27ll][1ll] = ((var134[4ll] * -0.00499999988824129f) + (var134[5ll] * 0.0573330000042915f)) + (var134[6ll] * 0.166549995541573f);
  var144[27ll][1ll] = ((var134[8ll] * -0.00499999988824129f) + (var134[9ll] * 0.0573330000042915f)) + (var134[10ll] * 0.166549995541573f);
  var142[27ll][1ll] = var142[27ll][1ll] + var134[3ll];
  var143[27ll][1ll] = var143[27ll][1ll] + var134[7ll];
  var144[27ll][1ll] = var144[27ll][1ll] + var134[11ll];
  var145[27ll][1ll] = 0.0149999996647239f;
  int var386;
  var386 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 0,27 : torso_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 2,27 : left_upper_shoulder_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 3,27 : left_lower_shoulder_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 4,27 : left_upper_elbow_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 5,27 : left_lower_elbow_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 6,27 : left_upper_forearm_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 7,27 : left_lower_forearm_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 8,27 : left_wrist_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 9,27 : left_hand_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 10,27 : left_gripper_base_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 11,27 : l_gripper_l_finger_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 12,27 : l_gripper_l_finger_2_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 13,27 : l_gripper_l_finger_tip_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 14,27 : l_gripper_r_finger_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 15,27 : l_gripper_r_finger_2_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 16,27 : l_gripper_r_finger_tip_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 17,27 : pedestal_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 18,27 : right_upper_shoulder_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 19,27 : right_lower_shoulder_0,r_gripper_l_finger_0
  var386 = ctup_runtime::self_collision_link_vs_link(20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll], 27ll, var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll]);
  if (var386)
    return 0; //collision pair: 20,27 : right_upper_elbow_0,r_gripper_l_finger_0
  var386 = ctup_runtime::link_vs_environment_collision(var137[27ll], var138[27ll], var139[27ll], var140[27ll], var141[27ll], var142[27ll], var143[27ll], var144[27ll], var145[27ll], arg4);
  if (var386)
    return 0;
  var137[28ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * 0.0863329991698265f)) + (var134[2ll] * 0.208550006151199f);
  var138[28ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * 0.0863329991698265f)) + (var134[6ll] * 0.208550006151199f);
  var139[28ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * 0.0863329991698265f)) + (var134[10ll] * 0.208550006151199f);
  var137[28ll] = var137[28ll] + var134[3ll];
  var138[28ll] = var138[28ll] + var134[7ll];
  var139[28ll] = var139[28ll] + var134[11ll];
  var140[28ll] = 0.0320000015199184f;
  var141[28ll] = 3ll;
  var142[28ll][0ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * 0.0865830034017563f)) + (var134[2ll] * 0.188549995422363f);
  var143[28ll][0ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * 0.0865830034017563f)) + (var134[6ll] * 0.188549995422363f);
  var144[28ll][0ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * 0.0865830034017563f)) + (var134[10ll] * 0.188549995422363f);
  var142[28ll][0ll] = var142[28ll][0ll] + var134[3ll];
  var143[28ll][0ll] = var143[28ll][0ll] + var134[7ll];
  var144[28ll][0ll] = var144[28ll][0ll] + var134[11ll];
  var145[28ll][0ll] = 0.0120000001043081f;
  var142[28ll][1ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * 0.0865830034017563f)) + (var134[2ll] * 0.208550006151199f);
  var143[28ll][1ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * 0.0865830034017563f)) + (var134[6ll] * 0.208550006151199f);
  var144[28ll][1ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * 0.0865830034017563f)) + (var134[10ll] * 0.208550006151199f);
  var142[28ll][1ll] = var142[28ll][1ll] + var134[3ll];
  var143[28ll][1ll] = var143[28ll][1ll] + var134[7ll];
  var144[28ll][1ll] = var144[28ll][1ll] + var134[11ll];
  var145[28ll][1ll] = 0.0120000001043081f;
  var142[28ll][2ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * 0.0865830034017563f)) + (var134[2ll] * 0.228550001978874f);
  var143[28ll][2ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * 0.0865830034017563f)) + (var134[6ll] * 0.228550001978874f);
  var144[28ll][2ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * 0.0865830034017563f)) + (var134[10ll] * 0.228550001978874f);
  var142[28ll][2ll] = var142[28ll][2ll] + var134[3ll];
  var143[28ll][2ll] = var143[28ll][2ll] + var134[7ll];
  var144[28ll][2ll] = var144[28ll][2ll] + var134[11ll];
  var145[28ll][2ll] = 0.0120000001043081f;
  int var387;
  var387 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 0,28 : torso_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 2,28 : left_upper_shoulder_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 3,28 : left_lower_shoulder_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 4,28 : left_upper_elbow_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 5,28 : left_lower_elbow_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 6,28 : left_upper_forearm_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 7,28 : left_lower_forearm_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 8,28 : left_wrist_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 9,28 : left_hand_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 10,28 : left_gripper_base_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 11,28 : l_gripper_l_finger_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 12,28 : l_gripper_l_finger_2_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 13,28 : l_gripper_l_finger_tip_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 14,28 : l_gripper_r_finger_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 15,28 : l_gripper_r_finger_2_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 16,28 : l_gripper_r_finger_tip_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 17,28 : pedestal_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 18,28 : right_upper_shoulder_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 19,28 : right_lower_shoulder_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::self_collision_link_vs_link(20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll], 28ll, var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll]);
  if (var387)
    return 0; //collision pair: 20,28 : right_upper_elbow_0,r_gripper_l_finger_2_0
  var387 = ctup_runtime::link_vs_environment_collision(var137[28ll], var138[28ll], var139[28ll], var140[28ll], var141[28ll], var142[28ll], var143[28ll], var144[28ll], var145[28ll], arg4);
  if (var387)
    return 0;
  var137[29ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * 0.0825830027461052f)) + (var134[2ll] * 0.256249994039536f);
  var138[29ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * 0.0825830027461052f)) + (var134[6ll] * 0.256249994039536f);
  var139[29ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * 0.0825830027461052f)) + (var134[10ll] * 0.256249994039536f);
  var137[29ll] = var137[29ll] + var134[3ll];
  var138[29ll] = var138[29ll] + var134[7ll];
  var139[29ll] = var139[29ll] + var134[11ll];
  var140[29ll] = 0.0280000008642673f;
  var141[29ll] = 4ll;
  var142[29ll][0ll] = ((var134[0ll] * 0.00999999977648258f) + (var134[1ll] * 0.0820830017328262f)) + (var134[2ll] * 0.266250014305115f);
  var143[29ll][0ll] = ((var134[4ll] * 0.00999999977648258f) + (var134[5ll] * 0.0820830017328262f)) + (var134[6ll] * 0.266250014305115f);
  var144[29ll][0ll] = ((var134[8ll] * 0.00999999977648258f) + (var134[9ll] * 0.0820830017328262f)) + (var134[10ll] * 0.266250014305115f);
  var142[29ll][0ll] = var142[29ll][0ll] + var134[3ll];
  var143[29ll][0ll] = var143[29ll][0ll] + var134[7ll];
  var144[29ll][0ll] = var144[29ll][0ll] + var134[11ll];
  var145[29ll][0ll] = 0.0140000004321337f;
  var142[29ll][1ll] = ((var134[0ll] * -0.00999999977648258f) + (var134[1ll] * 0.0820830017328262f)) + (var134[2ll] * 0.266250014305115f);
  var143[29ll][1ll] = ((var134[4ll] * -0.00999999977648258f) + (var134[5ll] * 0.0820830017328262f)) + (var134[6ll] * 0.266250014305115f);
  var144[29ll][1ll] = ((var134[8ll] * -0.00999999977648258f) + (var134[9ll] * 0.0820830017328262f)) + (var134[10ll] * 0.266250014305115f);
  var142[29ll][1ll] = var142[29ll][1ll] + var134[3ll];
  var143[29ll][1ll] = var143[29ll][1ll] + var134[7ll];
  var144[29ll][1ll] = var144[29ll][1ll] + var134[11ll];
  var145[29ll][1ll] = 0.0140000004321337f;
  var142[29ll][2ll] = ((var134[0ll] * -0.00999999977648258f) + (var134[1ll] * 0.0820830017328262f)) + (var134[2ll] * 0.246250003576279f);
  var143[29ll][2ll] = ((var134[4ll] * -0.00999999977648258f) + (var134[5ll] * 0.0820830017328262f)) + (var134[6ll] * 0.246250003576279f);
  var144[29ll][2ll] = ((var134[8ll] * -0.00999999977648258f) + (var134[9ll] * 0.0820830017328262f)) + (var134[10ll] * 0.246250003576279f);
  var142[29ll][2ll] = var142[29ll][2ll] + var134[3ll];
  var143[29ll][2ll] = var143[29ll][2ll] + var134[7ll];
  var144[29ll][2ll] = var144[29ll][2ll] + var134[11ll];
  var145[29ll][2ll] = 0.0140000004321337f;
  var142[29ll][3ll] = ((var134[0ll] * 0.00999999977648258f) + (var134[1ll] * 0.0820830017328262f)) + (var134[2ll] * 0.246250003576279f);
  var143[29ll][3ll] = ((var134[4ll] * 0.00999999977648258f) + (var134[5ll] * 0.0820830017328262f)) + (var134[6ll] * 0.246250003576279f);
  var144[29ll][3ll] = ((var134[8ll] * 0.00999999977648258f) + (var134[9ll] * 0.0820830017328262f)) + (var134[10ll] * 0.246250003576279f);
  var142[29ll][3ll] = var142[29ll][3ll] + var134[3ll];
  var143[29ll][3ll] = var143[29ll][3ll] + var134[7ll];
  var144[29ll][3ll] = var144[29ll][3ll] + var134[11ll];
  var145[29ll][3ll] = 0.0140000004321337f;
  int var388;
  var388 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 0,29 : torso_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 1,29 : head_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 2,29 : left_upper_shoulder_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 3,29 : left_lower_shoulder_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 4,29 : left_upper_elbow_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 5,29 : left_lower_elbow_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 6,29 : left_upper_forearm_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 7,29 : left_lower_forearm_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 8,29 : left_wrist_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 9,29 : left_hand_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 10,29 : left_gripper_base_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 11,29 : l_gripper_l_finger_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 12,29 : l_gripper_l_finger_2_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 13,29 : l_gripper_l_finger_tip_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 14,29 : l_gripper_r_finger_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 15,29 : l_gripper_r_finger_2_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 16,29 : l_gripper_r_finger_tip_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 17,29 : pedestal_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 18,29 : right_upper_shoulder_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 19,29 : right_lower_shoulder_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 20,29 : right_upper_elbow_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 21,29 : right_lower_elbow_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 22,29 : right_upper_forearm_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::self_collision_link_vs_link(23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll], 29ll, var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll]);
  if (var388)
    return 0; //collision pair: 23,29 : right_lower_forearm_0,r_gripper_l_finger_tip_0
  var388 = ctup_runtime::link_vs_environment_collision(var137[29ll], var138[29ll], var139[29ll], var140[29ll], var141[29ll], var142[29ll], var143[29ll], var144[29ll], var145[29ll], arg4);
  if (var388)
    return 0;
  var137[30ll] = ((var134[0ll] * 0.00499999988824129f) + (var134[1ll] * -0.0693330019712448f)) + (var134[2ll] * 0.166549995541573f);
  var138[30ll] = ((var134[4ll] * 0.00499999988824129f) + (var134[5ll] * -0.0693330019712448f)) + (var134[6ll] * 0.166549995541573f);
  var139[30ll] = ((var134[8ll] * 0.00499999988824129f) + (var134[9ll] * -0.0693330019712448f)) + (var134[10ll] * 0.166549995541573f);
  var137[30ll] = var137[30ll] + var134[3ll];
  var138[30ll] = var138[30ll] + var134[7ll];
  var139[30ll] = var139[30ll] + var134[11ll];
  var140[30ll] = 0.025000000372529f;
  var141[30ll] = 2ll;
  var142[30ll][0ll] = ((var134[0ll] * 0.00499999988824129f) + (var134[1ll] * -0.0593330003321171f)) + (var134[2ll] * 0.166549995541573f);
  var143[30ll][0ll] = ((var134[4ll] * 0.00499999988824129f) + (var134[5ll] * -0.0593330003321171f)) + (var134[6ll] * 0.166549995541573f);
  var144[30ll][0ll] = ((var134[8ll] * 0.00499999988824129f) + (var134[9ll] * -0.0593330003321171f)) + (var134[10ll] * 0.166549995541573f);
  var142[30ll][0ll] = var142[30ll][0ll] + var134[3ll];
  var143[30ll][0ll] = var143[30ll][0ll] + var134[7ll];
  var144[30ll][0ll] = var144[30ll][0ll] + var134[11ll];
  var145[30ll][0ll] = 0.0149999996647239f;
  var142[30ll][1ll] = ((var134[0ll] * 0.00499999988824129f) + (var134[1ll] * -0.0793329998850822f)) + (var134[2ll] * 0.166549995541573f);
  var143[30ll][1ll] = ((var134[4ll] * 0.00499999988824129f) + (var134[5ll] * -0.0793329998850822f)) + (var134[6ll] * 0.166549995541573f);
  var144[30ll][1ll] = ((var134[8ll] * 0.00499999988824129f) + (var134[9ll] * -0.0793329998850822f)) + (var134[10ll] * 0.166549995541573f);
  var142[30ll][1ll] = var142[30ll][1ll] + var134[3ll];
  var143[30ll][1ll] = var143[30ll][1ll] + var134[7ll];
  var144[30ll][1ll] = var144[30ll][1ll] + var134[11ll];
  var145[30ll][1ll] = 0.0149999996647239f;
  int var389;
  var389 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 0,30 : torso_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 1,30 : head_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 2,30 : left_upper_shoulder_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 3,30 : left_lower_shoulder_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 4,30 : left_upper_elbow_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 5,30 : left_lower_elbow_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 6,30 : left_upper_forearm_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 7,30 : left_lower_forearm_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 8,30 : left_wrist_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 9,30 : left_hand_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 10,30 : left_gripper_base_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 11,30 : l_gripper_l_finger_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 12,30 : l_gripper_l_finger_2_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 13,30 : l_gripper_l_finger_tip_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 14,30 : l_gripper_r_finger_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 15,30 : l_gripper_r_finger_2_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 16,30 : l_gripper_r_finger_tip_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 17,30 : pedestal_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 18,30 : right_upper_shoulder_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 19,30 : right_lower_shoulder_0,r_gripper_r_finger_0
  var389 = ctup_runtime::self_collision_link_vs_link(20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll], 30ll, var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll]);
  if (var389)
    return 0; //collision pair: 20,30 : right_upper_elbow_0,r_gripper_r_finger_0
  var389 = ctup_runtime::link_vs_environment_collision(var137[30ll], var138[30ll], var139[30ll], var140[30ll], var141[30ll], var142[30ll], var143[30ll], var144[30ll], var145[30ll], arg4);
  if (var389)
    return 0;
  var137[31ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * -0.0863329991698265f)) + (var134[2ll] * 0.208550006151199f);
  var138[31ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * -0.0863329991698265f)) + (var134[6ll] * 0.208550006151199f);
  var139[31ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * -0.0863329991698265f)) + (var134[10ll] * 0.208550006151199f);
  var137[31ll] = var137[31ll] + var134[3ll];
  var138[31ll] = var138[31ll] + var134[7ll];
  var139[31ll] = var139[31ll] + var134[11ll];
  var140[31ll] = 0.0320000015199184f;
  var141[31ll] = 3ll;
  var142[31ll][0ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * -0.0865830034017563f)) + (var134[2ll] * 0.188549995422363f);
  var143[31ll][0ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * -0.0865830034017563f)) + (var134[6ll] * 0.188549995422363f);
  var144[31ll][0ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * -0.0865830034017563f)) + (var134[10ll] * 0.188549995422363f);
  var142[31ll][0ll] = var142[31ll][0ll] + var134[3ll];
  var143[31ll][0ll] = var143[31ll][0ll] + var134[7ll];
  var144[31ll][0ll] = var144[31ll][0ll] + var134[11ll];
  var145[31ll][0ll] = 0.0120000001043081f;
  var142[31ll][1ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * -0.0865830034017563f)) + (var134[2ll] * 0.208550006151199f);
  var143[31ll][1ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * -0.0865830034017563f)) + (var134[6ll] * 0.208550006151199f);
  var144[31ll][1ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * -0.0865830034017563f)) + (var134[10ll] * 0.208550006151199f);
  var142[31ll][1ll] = var142[31ll][1ll] + var134[3ll];
  var143[31ll][1ll] = var143[31ll][1ll] + var134[7ll];
  var144[31ll][1ll] = var144[31ll][1ll] + var134[11ll];
  var145[31ll][1ll] = 0.0120000001043081f;
  var142[31ll][2ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * -0.0865830034017563f)) + (var134[2ll] * 0.228550001978874f);
  var143[31ll][2ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * -0.0865830034017563f)) + (var134[6ll] * 0.228550001978874f);
  var144[31ll][2ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * -0.0865830034017563f)) + (var134[10ll] * 0.228550001978874f);
  var142[31ll][2ll] = var142[31ll][2ll] + var134[3ll];
  var143[31ll][2ll] = var143[31ll][2ll] + var134[7ll];
  var144[31ll][2ll] = var144[31ll][2ll] + var134[11ll];
  var145[31ll][2ll] = 0.0120000001043081f;
  int var390;
  var390 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 0,31 : torso_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 1,31 : head_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 2,31 : left_upper_shoulder_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 3,31 : left_lower_shoulder_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 4,31 : left_upper_elbow_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 5,31 : left_lower_elbow_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 6,31 : left_upper_forearm_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 7,31 : left_lower_forearm_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 8,31 : left_wrist_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 9,31 : left_hand_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 10,31 : left_gripper_base_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 11,31 : l_gripper_l_finger_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 12,31 : l_gripper_l_finger_2_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 13,31 : l_gripper_l_finger_tip_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 14,31 : l_gripper_r_finger_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 15,31 : l_gripper_r_finger_2_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 16,31 : l_gripper_r_finger_tip_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 17,31 : pedestal_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 18,31 : right_upper_shoulder_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 19,31 : right_lower_shoulder_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::self_collision_link_vs_link(20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll], 31ll, var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll]);
  if (var390)
    return 0; //collision pair: 20,31 : right_upper_elbow_0,r_gripper_r_finger_2_0
  var390 = ctup_runtime::link_vs_environment_collision(var137[31ll], var138[31ll], var139[31ll], var140[31ll], var141[31ll], var142[31ll], var143[31ll], var144[31ll], var145[31ll], arg4);
  if (var390)
    return 0;
  var137[32ll] = ((var134[0ll] * 0.0f) + (var134[1ll] * -0.0825830027461052f)) + (var134[2ll] * 0.256249994039536f);
  var138[32ll] = ((var134[4ll] * 0.0f) + (var134[5ll] * -0.0825830027461052f)) + (var134[6ll] * 0.256249994039536f);
  var139[32ll] = ((var134[8ll] * 0.0f) + (var134[9ll] * -0.0825830027461052f)) + (var134[10ll] * 0.256249994039536f);
  var137[32ll] = var137[32ll] + var134[3ll];
  var138[32ll] = var138[32ll] + var134[7ll];
  var139[32ll] = var139[32ll] + var134[11ll];
  var140[32ll] = 0.0280000008642673f;
  var141[32ll] = 4ll;
  var142[32ll][0ll] = ((var134[0ll] * 0.00999999977648258f) + (var134[1ll] * -0.0820830017328262f)) + (var134[2ll] * 0.266250014305115f);
  var143[32ll][0ll] = ((var134[4ll] * 0.00999999977648258f) + (var134[5ll] * -0.0820830017328262f)) + (var134[6ll] * 0.266250014305115f);
  var144[32ll][0ll] = ((var134[8ll] * 0.00999999977648258f) + (var134[9ll] * -0.0820830017328262f)) + (var134[10ll] * 0.266250014305115f);
  var142[32ll][0ll] = var142[32ll][0ll] + var134[3ll];
  var143[32ll][0ll] = var143[32ll][0ll] + var134[7ll];
  var144[32ll][0ll] = var144[32ll][0ll] + var134[11ll];
  var145[32ll][0ll] = 0.0140000004321337f;
  var142[32ll][1ll] = ((var134[0ll] * -0.00999999977648258f) + (var134[1ll] * -0.0820830017328262f)) + (var134[2ll] * 0.266250014305115f);
  var143[32ll][1ll] = ((var134[4ll] * -0.00999999977648258f) + (var134[5ll] * -0.0820830017328262f)) + (var134[6ll] * 0.266250014305115f);
  var144[32ll][1ll] = ((var134[8ll] * -0.00999999977648258f) + (var134[9ll] * -0.0820830017328262f)) + (var134[10ll] * 0.266250014305115f);
  var142[32ll][1ll] = var142[32ll][1ll] + var134[3ll];
  var143[32ll][1ll] = var143[32ll][1ll] + var134[7ll];
  var144[32ll][1ll] = var144[32ll][1ll] + var134[11ll];
  var145[32ll][1ll] = 0.0140000004321337f;
  var142[32ll][2ll] = ((var134[0ll] * -0.00999999977648258f) + (var134[1ll] * -0.0820830017328262f)) + (var134[2ll] * 0.246250003576279f);
  var143[32ll][2ll] = ((var134[4ll] * -0.00999999977648258f) + (var134[5ll] * -0.0820830017328262f)) + (var134[6ll] * 0.246250003576279f);
  var144[32ll][2ll] = ((var134[8ll] * -0.00999999977648258f) + (var134[9ll] * -0.0820830017328262f)) + (var134[10ll] * 0.246250003576279f);
  var142[32ll][2ll] = var142[32ll][2ll] + var134[3ll];
  var143[32ll][2ll] = var143[32ll][2ll] + var134[7ll];
  var144[32ll][2ll] = var144[32ll][2ll] + var134[11ll];
  var145[32ll][2ll] = 0.0140000004321337f;
  var142[32ll][3ll] = ((var134[0ll] * 0.00999999977648258f) + (var134[1ll] * -0.0820830017328262f)) + (var134[2ll] * 0.246250003576279f);
  var143[32ll][3ll] = ((var134[4ll] * 0.00999999977648258f) + (var134[5ll] * -0.0820830017328262f)) + (var134[6ll] * 0.246250003576279f);
  var144[32ll][3ll] = ((var134[8ll] * 0.00999999977648258f) + (var134[9ll] * -0.0820830017328262f)) + (var134[10ll] * 0.246250003576279f);
  var142[32ll][3ll] = var142[32ll][3ll] + var134[3ll];
  var143[32ll][3ll] = var143[32ll][3ll] + var134[7ll];
  var144[32ll][3ll] = var144[32ll][3ll] + var134[11ll];
  var145[32ll][3ll] = 0.0140000004321337f;
  int var391;
  var391 = ctup_runtime::self_collision_link_vs_link(0ll, var137[0ll], var138[0ll], var139[0ll], var140[0ll], var141[0ll], var142[0ll], var143[0ll], var144[0ll], var145[0ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 0,32 : torso_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(1ll, var137[1ll], var138[1ll], var139[1ll], var140[1ll], var141[1ll], var142[1ll], var143[1ll], var144[1ll], var145[1ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 1,32 : head_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(2ll, var137[2ll], var138[2ll], var139[2ll], var140[2ll], var141[2ll], var142[2ll], var143[2ll], var144[2ll], var145[2ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 2,32 : left_upper_shoulder_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(3ll, var137[3ll], var138[3ll], var139[3ll], var140[3ll], var141[3ll], var142[3ll], var143[3ll], var144[3ll], var145[3ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 3,32 : left_lower_shoulder_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(4ll, var137[4ll], var138[4ll], var139[4ll], var140[4ll], var141[4ll], var142[4ll], var143[4ll], var144[4ll], var145[4ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 4,32 : left_upper_elbow_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(5ll, var137[5ll], var138[5ll], var139[5ll], var140[5ll], var141[5ll], var142[5ll], var143[5ll], var144[5ll], var145[5ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 5,32 : left_lower_elbow_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(6ll, var137[6ll], var138[6ll], var139[6ll], var140[6ll], var141[6ll], var142[6ll], var143[6ll], var144[6ll], var145[6ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 6,32 : left_upper_forearm_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(7ll, var137[7ll], var138[7ll], var139[7ll], var140[7ll], var141[7ll], var142[7ll], var143[7ll], var144[7ll], var145[7ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 7,32 : left_lower_forearm_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(8ll, var137[8ll], var138[8ll], var139[8ll], var140[8ll], var141[8ll], var142[8ll], var143[8ll], var144[8ll], var145[8ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 8,32 : left_wrist_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(9ll, var137[9ll], var138[9ll], var139[9ll], var140[9ll], var141[9ll], var142[9ll], var143[9ll], var144[9ll], var145[9ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 9,32 : left_hand_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(10ll, var137[10ll], var138[10ll], var139[10ll], var140[10ll], var141[10ll], var142[10ll], var143[10ll], var144[10ll], var145[10ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 10,32 : left_gripper_base_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(11ll, var137[11ll], var138[11ll], var139[11ll], var140[11ll], var141[11ll], var142[11ll], var143[11ll], var144[11ll], var145[11ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 11,32 : l_gripper_l_finger_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(12ll, var137[12ll], var138[12ll], var139[12ll], var140[12ll], var141[12ll], var142[12ll], var143[12ll], var144[12ll], var145[12ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 12,32 : l_gripper_l_finger_2_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(13ll, var137[13ll], var138[13ll], var139[13ll], var140[13ll], var141[13ll], var142[13ll], var143[13ll], var144[13ll], var145[13ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 13,32 : l_gripper_l_finger_tip_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(14ll, var137[14ll], var138[14ll], var139[14ll], var140[14ll], var141[14ll], var142[14ll], var143[14ll], var144[14ll], var145[14ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 14,32 : l_gripper_r_finger_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(15ll, var137[15ll], var138[15ll], var139[15ll], var140[15ll], var141[15ll], var142[15ll], var143[15ll], var144[15ll], var145[15ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 15,32 : l_gripper_r_finger_2_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(16ll, var137[16ll], var138[16ll], var139[16ll], var140[16ll], var141[16ll], var142[16ll], var143[16ll], var144[16ll], var145[16ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 16,32 : l_gripper_r_finger_tip_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(17ll, var137[17ll], var138[17ll], var139[17ll], var140[17ll], var141[17ll], var142[17ll], var143[17ll], var144[17ll], var145[17ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 17,32 : pedestal_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(18ll, var137[18ll], var138[18ll], var139[18ll], var140[18ll], var141[18ll], var142[18ll], var143[18ll], var144[18ll], var145[18ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 18,32 : right_upper_shoulder_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(19ll, var137[19ll], var138[19ll], var139[19ll], var140[19ll], var141[19ll], var142[19ll], var143[19ll], var144[19ll], var145[19ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 19,32 : right_lower_shoulder_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(20ll, var137[20ll], var138[20ll], var139[20ll], var140[20ll], var141[20ll], var142[20ll], var143[20ll], var144[20ll], var145[20ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 20,32 : right_upper_elbow_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(21ll, var137[21ll], var138[21ll], var139[21ll], var140[21ll], var141[21ll], var142[21ll], var143[21ll], var144[21ll], var145[21ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 21,32 : right_lower_elbow_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(22ll, var137[22ll], var138[22ll], var139[22ll], var140[22ll], var141[22ll], var142[22ll], var143[22ll], var144[22ll], var145[22ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 22,32 : right_upper_forearm_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::self_collision_link_vs_link(23ll, var137[23ll], var138[23ll], var139[23ll], var140[23ll], var141[23ll], var142[23ll], var143[23ll], var144[23ll], var145[23ll], 32ll, var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll]);
  if (var391)
    return 0; //collision pair: 23,32 : right_lower_forearm_0,r_gripper_r_finger_tip_0
  var391 = ctup_runtime::link_vs_environment_collision(var137[32ll], var138[32ll], var139[32ll], var140[32ll], var141[32ll], var142[32ll], var143[32ll], var144[32ll], var145[32ll], arg4);
  if (var391)
    return 0;
  return 1;
}

}
