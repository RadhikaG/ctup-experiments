// clang-format off

#include "Eigen/Dense"

#include "ctup/typedefs.h"

#include "ctup_fkcc/runtime/collision.h"

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

static int fkcc (vamp::collision::Environment<blaze::StaticVector<float, 8>> const& arg4, ctup_runtime::AlignedVec<blaze::StaticVector<float, 8>> const& arg5) {
  blaze::StaticVector<float, 8> var26[16];
  blaze::StaticVector<float, 8> var27;
  blaze::StaticVector<float, 8> var28;
  blaze::StaticVector<float, 8> var29[16];
  blaze::StaticVector<float, 8> var30;
  blaze::StaticVector<float, 8> var31;
  blaze::StaticVector<float, 8> var32[16];
  blaze::StaticVector<float, 8> var33;
  blaze::StaticVector<float, 8> var34;
  blaze::StaticVector<float, 8> var35[16];
  blaze::StaticVector<float, 8> var36;
  blaze::StaticVector<float, 8> var37;
  blaze::StaticVector<float, 8> var38[16];
  blaze::StaticVector<float, 8> var39;
  blaze::StaticVector<float, 8> var40;
  blaze::StaticVector<float, 8> var41[16];
  blaze::StaticVector<float, 8> var42;
  blaze::StaticVector<float, 8> var43;
  blaze::StaticVector<float, 8> var47[16];
  blaze::StaticVector<float, 8> var50[16];
  blaze::StaticVector<float, 8> var53[16];
  blaze::StaticVector<float, 8> var56[16];
  blaze::StaticVector<float, 8> var59[16];
  blaze::StaticVector<float, 8> var62[16];
  blaze::StaticVector<float, 8> var65[17];
  blaze::StaticVector<float, 8> var66[17];
  blaze::StaticVector<float, 8> var67[17];
  float var68[17];
  unsigned long int var69[17];
  ctup_runtime::AlignedVec<blaze::StaticVector<float, 8>> var70;
  ctup_runtime::AlignedVec<blaze::StaticVector<float, 8>> var71;
  ctup_runtime::AlignedVec<blaze::StaticVector<float, 8>> var72;
  std::vector<float> var73;
  var70.resize(5ll);
  var71.resize(5ll);
  var72.resize(5ll);
  var73.resize(5ll);
  ctup_runtime::AlignedVec<blaze::StaticVector<float, 8>> var74[17];
  ctup_runtime::AlignedVec<blaze::StaticVector<float, 8>> var75[17];
  ctup_runtime::AlignedVec<blaze::StaticVector<float, 8>> var76[17];
  std::vector<float> var77[17];
  blaze::StaticVector<float, 8> var78[16];
  var65[0ll] = ((1.0f * 0.0f) + (0 * 0.0f)) + (0 * 0.914399981498718f);
  var66[0ll] = ((0 * 0.0f) + (1.0f * 0.0f)) + (0 * 0.914399981498718f);
  var67[0ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.914399981498718f);
  var65[0ll] = var65[0ll] + 0;
  var66[0ll] = var66[0ll] + 0;
  var67[0ll] = var67[0ll] + 0;
  var68[0ll] = 0.0799999982118607f;
  var69[0ll] = 1ll;
  var70[0ll] = ((1.0f * 0.0f) + (0 * 0.0f)) + (0 * 0.914399981498718f);
  var71[0ll] = ((0 * 0.0f) + (1.0f * 0.0f)) + (0 * 0.914399981498718f);
  var72[0ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.914399981498718f);
  var70[0ll] = var70[0ll] + 0;
  var71[0ll] = var71[0ll] + 0;
  var72[0ll] = var72[0ll] + 0;
  var73[0ll] = 0.0799999982118607f;
  var74[0ll] = var70;
  var75[0ll] = var71;
  var76[0ll] = var72;
  var77[0ll] = var73;
  blaze::StaticVector<float, 8> var82 = arg5[0ll];
  var27 = sin(var82);
  var28 = cos(var82);
  var26[0ll] = var28;
  var26[1ll] = -(var27);
  var26[2ll] = var27;
  var26[3ll] = var28;
  blaze::StaticVector<float, 8> var83;
  var83 = 0;
  var83 = var83 + (0.000796326727140695f * var26[0ll]);
  var83 = var83 + (-0.999999701976776f * var26[2ll]);
  var83 = var83 + (0 * 0);
  var83 = var83 + (0 * 0);
  var78[0ll] = var83;
  blaze::StaticVector<float, 8> var84;
  var84 = 0;
  var84 = var84 + (0.000796326727140695f * var26[1ll]);
  var84 = var84 + (-0.999999701976776f * var26[3ll]);
  var84 = var84 + (0 * 0);
  var84 = var84 + (0 * 0);
  var78[1ll] = var84;
  blaze::StaticVector<float, 8> var85;
  var85 = 0;
  var85 = var85 + (0.999999701976776f * var26[0ll]);
  var85 = var85 + (0.000796326727140695f * var26[2ll]);
  var85 = var85 + (0 * 0);
  var85 = var85 + (0 * 0);
  var78[2ll] = var85;
  blaze::StaticVector<float, 8> var86;
  var86 = 0;
  var86 = var86 + (0.999999701976776f * var26[1ll]);
  var86 = var86 + (0.000796326727140695f * var26[3ll]);
  var86 = var86 + (0 * 0);
  var86 = var86 + (0 * 0);
  var78[3ll] = var86;
  var47[0ll] = var78[0ll];
  var47[1ll] = var78[1ll];
  var47[2ll] = var78[2ll];
  var47[3ll] = var78[3ll];
  var65[1ll] = ((var47[0ll] * 0.0f) + (var47[1ll] * 0.0f)) + (0 * 0.0f);
  var66[1ll] = ((var47[2ll] * 0.0f) + (var47[3ll] * 0.0f)) + (0 * 0.0f);
  var67[1ll] = ((0 * 0.0f) + (0 * 0.0f)) + (1.0f * 0.0f);
  var65[1ll] = var65[1ll] + 0;
  var66[1ll] = var66[1ll] + 0;
  var67[1ll] = var67[1ll] + 1.00355899333954f;
  var68[1ll] = 0.0799999982118607f;
  var69[1ll] = 0ll;
  int var87;
  var87 = ctup_runtime::link_vs_environment_collision(var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var70, var71, var72, var73, arg4);
  if (var87)
    return 0;
  var74[1ll] = var70;
  var75[1ll] = var71;
  var76[1ll] = var72;
  var77[1ll] = var73;
  blaze::StaticVector<float, 8> var88 = arg5[1ll];
  var30 = sin(var88);
  var31 = cos(var88);
  var29[0ll] = var31;
  var29[1ll] = var30;
  var29[2ll] = -(var30);
  var29[3ll] = var31;
  blaze::StaticVector<float, 8> var89;
  var89 = 0;
  var89 = var89 + (0 * var29[0ll]);
  var89 = var89 + (0 * 0);
  var89 = var89 + (1.0f * var29[2ll]);
  var89 = var89 + (0 * 0);
  var78[0ll] = var89;
  blaze::StaticVector<float, 8> var90;
  var90 = 0;
  var90 = var90 + (0 * var29[1ll]);
  var90 = var90 + (0 * 0);
  var90 = var90 + (1.0f * var29[3ll]);
  var90 = var90 + (0 * 0);
  var78[1ll] = var90;
  blaze::StaticVector<float, 8> var91;
  var91 = 0;
  var91 = var91 + (-1.0f * var29[0ll]);
  var91 = var91 + (0 * 0);
  var91 = var91 + (0 * var29[2ll]);
  var91 = var91 + (0 * 0);
  var78[2ll] = var91;
  blaze::StaticVector<float, 8> var92;
  var92 = 0;
  var92 = var92 + (-1.0f * var29[1ll]);
  var92 = var92 + (0 * 0);
  var92 = var92 + (0 * var29[3ll]);
  var92 = var92 + (0 * 0);
  var78[3ll] = var92;
  blaze::StaticVector<float, 8> var93;
  var93 = 0;
  var93 = var93 + (var47[0ll] * var78[0ll]);
  var93 = var93 + (var47[1ll] * 0);
  var93 = var93 + (0 * var78[2ll]);
  var93 = var93 + (0 * 0);
  var50[0ll] = var93;
  blaze::StaticVector<float, 8> var94;
  var94 = 0;
  var94 = var94 + (var47[0ll] * 0);
  var94 = var94 + (var47[1ll] * 1.0f);
  var94 = var94 + (0 * 0);
  var94 = var94 + (0 * 0);
  var50[1ll] = var94;
  blaze::StaticVector<float, 8> var95;
  var95 = 0;
  var95 = var95 + (var47[0ll] * var78[1ll]);
  var95 = var95 + (var47[1ll] * 0);
  var95 = var95 + (0 * var78[3ll]);
  var95 = var95 + (0 * 0);
  var50[2ll] = var95;
  blaze::StaticVector<float, 8> var96;
  var96 = 0;
  var96 = var96 + (var47[0ll] * 0);
  var96 = var96 + (var47[1ll] * 0.135849997401237f);
  var96 = var96 + (0 * 0);
  var96 = var96 + (0 * 1.0f);
  var50[3ll] = var96;
  blaze::StaticVector<float, 8> var97;
  var97 = 0;
  var97 = var97 + (var47[2ll] * var78[0ll]);
  var97 = var97 + (var47[3ll] * 0);
  var97 = var97 + (0 * var78[2ll]);
  var97 = var97 + (0 * 0);
  var50[4ll] = var97;
  blaze::StaticVector<float, 8> var98;
  var98 = 0;
  var98 = var98 + (var47[2ll] * 0);
  var98 = var98 + (var47[3ll] * 1.0f);
  var98 = var98 + (0 * 0);
  var98 = var98 + (0 * 0);
  var50[5ll] = var98;
  blaze::StaticVector<float, 8> var99;
  var99 = 0;
  var99 = var99 + (var47[2ll] * var78[1ll]);
  var99 = var99 + (var47[3ll] * 0);
  var99 = var99 + (0 * var78[3ll]);
  var99 = var99 + (0 * 0);
  var50[6ll] = var99;
  blaze::StaticVector<float, 8> var100;
  var100 = 0;
  var100 = var100 + (var47[2ll] * 0);
  var100 = var100 + (var47[3ll] * 0.135849997401237f);
  var100 = var100 + (0 * 0);
  var100 = var100 + (0 * 1.0f);
  var50[7ll] = var100;
  blaze::StaticVector<float, 8> var101;
  var101 = 0;
  var101 = var101 + (0 * var78[0ll]);
  var101 = var101 + (0 * 0);
  var101 = var101 + (1.0f * var78[2ll]);
  var101 = var101 + (1.00355899333954f * 0);
  var50[8ll] = var101;
  blaze::StaticVector<float, 8> var102;
  var102 = 0;
  var102 = var102 + (0 * var78[1ll]);
  var102 = var102 + (0 * 0);
  var102 = var102 + (1.0f * var78[3ll]);
  var102 = var102 + (1.00355899333954f * 0);
  var50[9ll] = var102;
  var65[2ll] = ((var50[0ll] * 0.0f) + (var50[1ll] * 0.0f)) + (var50[2ll] * 0.209999993443489f);
  var66[2ll] = ((var50[4ll] * 0.0f) + (var50[5ll] * 0.0f)) + (var50[6ll] * 0.209999993443489f);
  var67[2ll] = ((var50[8ll] * 0.0f) + (0 * 0.0f)) + (var50[9ll] * 0.209999993443489f);
  var65[2ll] = var65[2ll] + var50[3ll];
  var66[2ll] = var66[2ll] + var50[7ll];
  var67[2ll] = var67[2ll] + 1.00355899333954f;
  var68[2ll] = 0.28999999165535f;
  var69[2ll] = 5ll;
  var70[0ll] = ((var50[0ll] * 0.0f) + (var50[1ll] * 0.0f)) + (var50[2ll] * 0.104999996721745f);
  var71[0ll] = ((var50[4ll] * 0.0f) + (var50[5ll] * 0.0f)) + (var50[6ll] * 0.104999996721745f);
  var72[0ll] = ((var50[8ll] * 0.0f) + (0 * 0.0f)) + (var50[9ll] * 0.104999996721745f);
  var70[0ll] = var70[0ll] + var50[3ll];
  var71[0ll] = var71[0ll] + var50[7ll];
  var72[0ll] = var72[0ll] + 1.00355899333954f;
  var73[0ll] = 0.0799999982118607f;
  var70[1ll] = ((var50[0ll] * 0.0f) + (var50[1ll] * 0.0f)) + (var50[2ll] * 0.209999993443489f);
  var71[1ll] = ((var50[4ll] * 0.0f) + (var50[5ll] * 0.0f)) + (var50[6ll] * 0.209999993443489f);
  var72[1ll] = ((var50[8ll] * 0.0f) + (0 * 0.0f)) + (var50[9ll] * 0.209999993443489f);
  var70[1ll] = var70[1ll] + var50[3ll];
  var71[1ll] = var71[1ll] + var50[7ll];
  var72[1ll] = var72[1ll] + 1.00355899333954f;
  var73[1ll] = 0.0799999982118607f;
  var70[2ll] = ((var50[0ll] * 0.0f) + (var50[1ll] * 0.0f)) + (var50[2ll] * 0.314999997615814f);
  var71[2ll] = ((var50[4ll] * 0.0f) + (var50[5ll] * 0.0f)) + (var50[6ll] * 0.314999997615814f);
  var72[2ll] = ((var50[8ll] * 0.0f) + (0 * 0.0f)) + (var50[9ll] * 0.314999997615814f);
  var70[2ll] = var70[2ll] + var50[3ll];
  var71[2ll] = var71[2ll] + var50[7ll];
  var72[2ll] = var72[2ll] + 1.00355899333954f;
  var73[2ll] = 0.0799999982118607f;
  var70[3ll] = ((var50[0ll] * 0.0f) + (var50[1ll] * 0.0f)) + (var50[2ll] * 0.419999986886978f);
  var71[3ll] = ((var50[4ll] * 0.0f) + (var50[5ll] * 0.0f)) + (var50[6ll] * 0.419999986886978f);
  var72[3ll] = ((var50[8ll] * 0.0f) + (0 * 0.0f)) + (var50[9ll] * 0.419999986886978f);
  var70[3ll] = var70[3ll] + var50[3ll];
  var71[3ll] = var71[3ll] + var50[7ll];
  var72[3ll] = var72[3ll] + 1.00355899333954f;
  var73[3ll] = 0.0799999982118607f;
  var70[4ll] = ((var50[0ll] * 0.0f) + (var50[1ll] * 0.0f)) + (var50[2ll] * 0.0f);
  var71[4ll] = ((var50[4ll] * 0.0f) + (var50[5ll] * 0.0f)) + (var50[6ll] * 0.0f);
  var72[4ll] = ((var50[8ll] * 0.0f) + (0 * 0.0f)) + (var50[9ll] * 0.0f);
  var70[4ll] = var70[4ll] + var50[3ll];
  var71[4ll] = var71[4ll] + var50[7ll];
  var72[4ll] = var72[4ll] + 1.00355899333954f;
  var73[4ll] = 0.0799999982118607f;
  int var103;
  var103 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var70, var71, var72, var73);
  if (var103)
    return 0; //collision pair: 0,2
  var103 = ctup_runtime::link_vs_environment_collision(var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var70, var71, var72, var73, arg4);
  if (var103)
    return 0;
  var74[2ll] = var70;
  var75[2ll] = var71;
  var76[2ll] = var72;
  var77[2ll] = var73;
  blaze::StaticVector<float, 8> var104 = arg5[2ll];
  var33 = sin(var104);
  var34 = cos(var104);
  var32[0ll] = var34;
  var32[1ll] = var33;
  var32[2ll] = -(var33);
  var32[3ll] = var34;
  blaze::StaticVector<float, 8> var105;
  var105 = 0;
  var105 = var105 + (1.0f * var32[0ll]);
  var105 = var105 + (0 * 0);
  var105 = var105 + (0 * var32[2ll]);
  var105 = var105 + (0 * 0);
  var78[0ll] = var105;
  blaze::StaticVector<float, 8> var106;
  var106 = 0;
  var106 = var106 + (1.0f * var32[1ll]);
  var106 = var106 + (0 * 0);
  var106 = var106 + (0 * var32[3ll]);
  var106 = var106 + (0 * 0);
  var78[1ll] = var106;
  blaze::StaticVector<float, 8> var107;
  var107 = 0;
  var107 = var107 + (0 * var32[0ll]);
  var107 = var107 + (0 * 0);
  var107 = var107 + (1.0f * var32[2ll]);
  var107 = var107 + (0.425000011920929f * 0);
  var78[2ll] = var107;
  blaze::StaticVector<float, 8> var108;
  var108 = 0;
  var108 = var108 + (0 * var32[1ll]);
  var108 = var108 + (0 * 0);
  var108 = var108 + (1.0f * var32[3ll]);
  var108 = var108 + (0.425000011920929f * 0);
  var78[3ll] = var108;
  blaze::StaticVector<float, 8> var109;
  var109 = 0;
  var109 = var109 + (var50[0ll] * var78[0ll]);
  var109 = var109 + (var50[1ll] * 0);
  var109 = var109 + (var50[2ll] * var78[2ll]);
  var109 = var109 + (var50[3ll] * 0);
  var53[0ll] = var109;
  blaze::StaticVector<float, 8> var110;
  var110 = 0;
  var110 = var110 + (var50[0ll] * 0);
  var110 = var110 + (var50[1ll] * 1.0f);
  var110 = var110 + (var50[2ll] * 0);
  var110 = var110 + (var50[3ll] * 0);
  var53[1ll] = var110;
  blaze::StaticVector<float, 8> var111;
  var111 = 0;
  var111 = var111 + (var50[0ll] * var78[1ll]);
  var111 = var111 + (var50[1ll] * 0);
  var111 = var111 + (var50[2ll] * var78[3ll]);
  var111 = var111 + (var50[3ll] * 0);
  var53[2ll] = var111;
  blaze::StaticVector<float, 8> var112;
  var112 = 0;
  var112 = var112 + (var50[0ll] * 0);
  var112 = var112 + (var50[1ll] * -0.119699999690056f);
  var112 = var112 + (var50[2ll] * 0.425000011920929f);
  var112 = var112 + (var50[3ll] * 1.0f);
  var53[3ll] = var112;
  blaze::StaticVector<float, 8> var113;
  var113 = 0;
  var113 = var113 + (var50[4ll] * var78[0ll]);
  var113 = var113 + (var50[5ll] * 0);
  var113 = var113 + (var50[6ll] * var78[2ll]);
  var113 = var113 + (var50[7ll] * 0);
  var53[4ll] = var113;
  blaze::StaticVector<float, 8> var114;
  var114 = 0;
  var114 = var114 + (var50[4ll] * 0);
  var114 = var114 + (var50[5ll] * 1.0f);
  var114 = var114 + (var50[6ll] * 0);
  var114 = var114 + (var50[7ll] * 0);
  var53[5ll] = var114;
  blaze::StaticVector<float, 8> var115;
  var115 = 0;
  var115 = var115 + (var50[4ll] * var78[1ll]);
  var115 = var115 + (var50[5ll] * 0);
  var115 = var115 + (var50[6ll] * var78[3ll]);
  var115 = var115 + (var50[7ll] * 0);
  var53[6ll] = var115;
  blaze::StaticVector<float, 8> var116;
  var116 = 0;
  var116 = var116 + (var50[4ll] * 0);
  var116 = var116 + (var50[5ll] * -0.119699999690056f);
  var116 = var116 + (var50[6ll] * 0.425000011920929f);
  var116 = var116 + (var50[7ll] * 1.0f);
  var53[7ll] = var116;
  blaze::StaticVector<float, 8> var117;
  var117 = 0;
  var117 = var117 + (var50[8ll] * var78[0ll]);
  var117 = var117 + (0 * 0);
  var117 = var117 + (var50[9ll] * var78[2ll]);
  var117 = var117 + (1.00355899333954f * 0);
  var53[8ll] = var117;
  blaze::StaticVector<float, 8> var118;
  var118 = 0;
  var118 = var118 + (var50[8ll] * var78[1ll]);
  var118 = var118 + (0 * 0);
  var118 = var118 + (var50[9ll] * var78[3ll]);
  var118 = var118 + (1.00355899333954f * 0);
  var53[9ll] = var118;
  blaze::StaticVector<float, 8> var119;
  var119 = 0;
  var119 = var119 + (var50[8ll] * 0);
  var119 = var119 + (0 * -0.119699999690056f);
  var119 = var119 + (var50[9ll] * 0.425000011920929f);
  var119 = var119 + (1.00355899333954f * 1.0f);
  var53[10ll] = var119;
  var65[3ll] = ((var53[0ll] * 0.0020000000949949f) + (var53[1ll] * 0.00300000002607703f)) + (var53[2ll] * 0.185000002384186f);
  var66[3ll] = ((var53[4ll] * 0.0020000000949949f) + (var53[5ll] * 0.00300000002607703f)) + (var53[6ll] * 0.185000002384186f);
  var67[3ll] = ((var53[8ll] * 0.0020000000949949f) + (0 * 0.00300000002607703f)) + (var53[9ll] * 0.185000002384186f);
  var65[3ll] = var65[3ll] + var53[3ll];
  var66[3ll] = var66[3ll] + var53[7ll];
  var67[3ll] = var67[3ll] + var53[10ll];
  var68[3ll] = 0.264999985694885f;
  var69[3ll] = 5ll;
  var70[0ll] = ((var53[0ll] * 0.0f) + (var53[1ll] * 0.0f)) + (var53[2ll] * 0.0f);
  var71[0ll] = ((var53[4ll] * 0.0f) + (var53[5ll] * 0.0f)) + (var53[6ll] * 0.0f);
  var72[0ll] = ((var53[8ll] * 0.0f) + (0 * 0.0f)) + (var53[9ll] * 0.0f);
  var70[0ll] = var70[0ll] + var53[3ll];
  var71[0ll] = var71[0ll] + var53[7ll];
  var72[0ll] = var72[0ll] + var53[10ll];
  var73[0ll] = 0.0799999982118607f;
  var70[1ll] = ((var53[0ll] * 0.0f) + (var53[1ll] * 0.0f)) + (var53[2ll] * 0.0974999964237213f);
  var71[1ll] = ((var53[4ll] * 0.0f) + (var53[5ll] * 0.0f)) + (var53[6ll] * 0.0974999964237213f);
  var72[1ll] = ((var53[8ll] * 0.0f) + (0 * 0.0f)) + (var53[9ll] * 0.0974999964237213f);
  var70[1ll] = var70[1ll] + var53[3ll];
  var71[1ll] = var71[1ll] + var53[7ll];
  var72[1ll] = var72[1ll] + var53[10ll];
  var73[1ll] = 0.0599999986588955f;
  var70[2ll] = ((var53[0ll] * 0.0f) + (var53[1ll] * 0.0f)) + (var53[2ll] * 0.194999992847443f);
  var71[2ll] = ((var53[4ll] * 0.0f) + (var53[5ll] * 0.0f)) + (var53[6ll] * 0.194999992847443f);
  var72[2ll] = ((var53[8ll] * 0.0f) + (0 * 0.0f)) + (var53[9ll] * 0.194999992847443f);
  var70[2ll] = var70[2ll] + var53[3ll];
  var71[2ll] = var71[2ll] + var53[7ll];
  var72[2ll] = var72[2ll] + var53[10ll];
  var73[2ll] = 0.0599999986588955f;
  var70[3ll] = ((var53[0ll] * 0.0f) + (var53[1ll] * 0.0f)) + (var53[2ll] * 0.292499989271164f);
  var71[3ll] = ((var53[4ll] * 0.0f) + (var53[5ll] * 0.0f)) + (var53[6ll] * 0.292499989271164f);
  var72[3ll] = ((var53[8ll] * 0.0f) + (0 * 0.0f)) + (var53[9ll] * 0.292499989271164f);
  var70[3ll] = var70[3ll] + var53[3ll];
  var71[3ll] = var71[3ll] + var53[7ll];
  var72[3ll] = var72[3ll] + var53[10ll];
  var73[3ll] = 0.0599999986588955f;
  var70[4ll] = ((var53[0ll] * 0.0f) + (var53[1ll] * 0.0f)) + (var53[2ll] * 0.389999985694885f);
  var71[4ll] = ((var53[4ll] * 0.0f) + (var53[5ll] * 0.0f)) + (var53[6ll] * 0.389999985694885f);
  var72[4ll] = ((var53[8ll] * 0.0f) + (0 * 0.0f)) + (var53[9ll] * 0.389999985694885f);
  var70[4ll] = var70[4ll] + var53[3ll];
  var71[4ll] = var71[4ll] + var53[7ll];
  var72[4ll] = var72[4ll] + var53[10ll];
  var73[4ll] = 0.0599999986588955f;
  int var120;
  var120 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var70, var71, var72, var73);
  if (var120)
    return 0; //collision pair: 0,3
  var120 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var70, var71, var72, var73);
  if (var120)
    return 0; //collision pair: 1,3
  var120 = ctup_runtime::link_vs_environment_collision(var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var70, var71, var72, var73, arg4);
  if (var120)
    return 0;
  var74[3ll] = var70;
  var75[3ll] = var71;
  var76[3ll] = var72;
  var77[3ll] = var73;
  blaze::StaticVector<float, 8> var121 = arg5[3ll];
  var36 = sin(var121);
  var37 = cos(var121);
  var35[0ll] = var37;
  var35[1ll] = var36;
  var35[2ll] = -(var36);
  var35[3ll] = var37;
  blaze::StaticVector<float, 8> var122;
  var122 = 0;
  var122 = var122 + (0 * var35[0ll]);
  var122 = var122 + (0 * 0);
  var122 = var122 + (1.0f * var35[2ll]);
  var122 = var122 + (0 * 0);
  var78[0ll] = var122;
  blaze::StaticVector<float, 8> var123;
  var123 = 0;
  var123 = var123 + (0 * var35[1ll]);
  var123 = var123 + (0 * 0);
  var123 = var123 + (1.0f * var35[3ll]);
  var123 = var123 + (0 * 0);
  var78[1ll] = var123;
  blaze::StaticVector<float, 8> var124;
  var124 = 0;
  var124 = var124 + (-1.0f * var35[0ll]);
  var124 = var124 + (0 * 0);
  var124 = var124 + (0 * var35[2ll]);
  var124 = var124 + (0.392250001430511f * 0);
  var78[2ll] = var124;
  blaze::StaticVector<float, 8> var125;
  var125 = 0;
  var125 = var125 + (-1.0f * var35[1ll]);
  var125 = var125 + (0 * 0);
  var125 = var125 + (0 * var35[3ll]);
  var125 = var125 + (0.392250001430511f * 0);
  var78[3ll] = var125;
  blaze::StaticVector<float, 8> var126;
  var126 = 0;
  var126 = var126 + (var53[0ll] * var78[0ll]);
  var126 = var126 + (var53[1ll] * 0);
  var126 = var126 + (var53[2ll] * var78[2ll]);
  var126 = var126 + (var53[3ll] * 0);
  var56[0ll] = var126;
  blaze::StaticVector<float, 8> var127;
  var127 = 0;
  var127 = var127 + (var53[0ll] * 0);
  var127 = var127 + (var53[1ll] * 1.0f);
  var127 = var127 + (var53[2ll] * 0);
  var127 = var127 + (var53[3ll] * 0);
  var56[1ll] = var127;
  blaze::StaticVector<float, 8> var128;
  var128 = 0;
  var128 = var128 + (var53[0ll] * var78[1ll]);
  var128 = var128 + (var53[1ll] * 0);
  var128 = var128 + (var53[2ll] * var78[3ll]);
  var128 = var128 + (var53[3ll] * 0);
  var56[2ll] = var128;
  blaze::StaticVector<float, 8> var129;
  var129 = 0;
  var129 = var129 + (var53[0ll] * 0);
  var129 = var129 + (var53[1ll] * 0);
  var129 = var129 + (var53[2ll] * 0.392250001430511f);
  var129 = var129 + (var53[3ll] * 1.0f);
  var56[3ll] = var129;
  blaze::StaticVector<float, 8> var130;
  var130 = 0;
  var130 = var130 + (var53[4ll] * var78[0ll]);
  var130 = var130 + (var53[5ll] * 0);
  var130 = var130 + (var53[6ll] * var78[2ll]);
  var130 = var130 + (var53[7ll] * 0);
  var56[4ll] = var130;
  blaze::StaticVector<float, 8> var131;
  var131 = 0;
  var131 = var131 + (var53[4ll] * 0);
  var131 = var131 + (var53[5ll] * 1.0f);
  var131 = var131 + (var53[6ll] * 0);
  var131 = var131 + (var53[7ll] * 0);
  var56[5ll] = var131;
  blaze::StaticVector<float, 8> var132;
  var132 = 0;
  var132 = var132 + (var53[4ll] * var78[1ll]);
  var132 = var132 + (var53[5ll] * 0);
  var132 = var132 + (var53[6ll] * var78[3ll]);
  var132 = var132 + (var53[7ll] * 0);
  var56[6ll] = var132;
  blaze::StaticVector<float, 8> var133;
  var133 = 0;
  var133 = var133 + (var53[4ll] * 0);
  var133 = var133 + (var53[5ll] * 0);
  var133 = var133 + (var53[6ll] * 0.392250001430511f);
  var133 = var133 + (var53[7ll] * 1.0f);
  var56[7ll] = var133;
  blaze::StaticVector<float, 8> var134;
  var134 = 0;
  var134 = var134 + (var53[8ll] * var78[0ll]);
  var134 = var134 + (0 * 0);
  var134 = var134 + (var53[9ll] * var78[2ll]);
  var134 = var134 + (var53[10ll] * 0);
  var56[8ll] = var134;
  blaze::StaticVector<float, 8> var135;
  var135 = 0;
  var135 = var135 + (var53[8ll] * var78[1ll]);
  var135 = var135 + (0 * 0);
  var135 = var135 + (var53[9ll] * var78[3ll]);
  var135 = var135 + (var53[10ll] * 0);
  var56[9ll] = var135;
  blaze::StaticVector<float, 8> var136;
  var136 = 0;
  var136 = var136 + (var53[8ll] * 0);
  var136 = var136 + (0 * 0);
  var136 = var136 + (var53[9ll] * 0.392250001430511f);
  var136 = var136 + (var53[10ll] * 1.0f);
  var56[10ll] = var136;
  var65[4ll] = ((var56[0ll] * 0.0f) + (var56[1ll] * 0.0900000035762787f)) + (var56[2ll] * 0.0f);
  var66[4ll] = ((var56[4ll] * 0.0f) + (var56[5ll] * 0.0900000035762787f)) + (var56[6ll] * 0.0f);
  var67[4ll] = ((var56[8ll] * 0.0f) + (0 * 0.0900000035762787f)) + (var56[9ll] * 0.0f);
  var65[4ll] = var65[4ll] + var56[3ll];
  var66[4ll] = var66[4ll] + var56[7ll];
  var67[4ll] = var67[4ll] + var56[10ll];
  var68[4ll] = 0.0700000002980232f;
  var69[4ll] = 3ll;
  var70[0ll] = ((var56[0ll] * 0.0f) + (var56[1ll] * 0.0900000035762787f)) + (var56[2ll] * 0.0299999993294477f);
  var71[0ll] = ((var56[4ll] * 0.0f) + (var56[5ll] * 0.0900000035762787f)) + (var56[6ll] * 0.0299999993294477f);
  var72[0ll] = ((var56[8ll] * 0.0f) + (0 * 0.0900000035762787f)) + (var56[9ll] * 0.0299999993294477f);
  var70[0ll] = var70[0ll] + var56[3ll];
  var71[0ll] = var71[0ll] + var56[7ll];
  var72[0ll] = var72[0ll] + var56[10ll];
  var73[0ll] = 0.0399999991059303f;
  var70[1ll] = ((var56[0ll] * 0.0f) + (var56[1ll] * 0.0900000035762787f)) + (var56[2ll] * -0.0299999993294477f);
  var71[1ll] = ((var56[4ll] * 0.0f) + (var56[5ll] * 0.0900000035762787f)) + (var56[6ll] * -0.0299999993294477f);
  var72[1ll] = ((var56[8ll] * 0.0f) + (0 * 0.0900000035762787f)) + (var56[9ll] * -0.0299999993294477f);
  var70[1ll] = var70[1ll] + var56[3ll];
  var71[1ll] = var71[1ll] + var56[7ll];
  var72[1ll] = var72[1ll] + var56[10ll];
  var73[1ll] = 0.0399999991059303f;
  var70[2ll] = ((var56[0ll] * 0.0f) + (var56[1ll] * 0.0900000035762787f)) + (var56[2ll] * 0.0f);
  var71[2ll] = ((var56[4ll] * 0.0f) + (var56[5ll] * 0.0900000035762787f)) + (var56[6ll] * 0.0f);
  var72[2ll] = ((var56[8ll] * 0.0f) + (0 * 0.0900000035762787f)) + (var56[9ll] * 0.0f);
  var70[2ll] = var70[2ll] + var56[3ll];
  var71[2ll] = var71[2ll] + var56[7ll];
  var72[2ll] = var72[2ll] + var56[10ll];
  var73[2ll] = 0.0399999991059303f;
  int var137;
  var137 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 4ll, var65[4ll], var66[4ll], var67[4ll], var68[4ll], var69[4ll], var70, var71, var72, var73);
  if (var137)
    return 0; //collision pair: 0,4
  var137 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 4ll, var65[4ll], var66[4ll], var67[4ll], var68[4ll], var69[4ll], var70, var71, var72, var73);
  if (var137)
    return 0; //collision pair: 1,4
  var137 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 4ll, var65[4ll], var66[4ll], var67[4ll], var68[4ll], var69[4ll], var70, var71, var72, var73);
  if (var137)
    return 0; //collision pair: 2,4
  var137 = ctup_runtime::link_vs_environment_collision(var65[4ll], var66[4ll], var67[4ll], var68[4ll], var69[4ll], var70, var71, var72, var73, arg4);
  if (var137)
    return 0;
  var74[4ll] = var70;
  var75[4ll] = var71;
  var76[4ll] = var72;
  var77[4ll] = var73;
  blaze::StaticVector<float, 8> var138 = arg5[4ll];
  var39 = sin(var138);
  var40 = cos(var138);
  var38[0ll] = var40;
  var38[1ll] = -(var39);
  var38[2ll] = var39;
  var38[3ll] = var40;
  blaze::StaticVector<float, 8> var139;
  var139 = 0;
  var139 = var139 + (1.0f * var38[0ll]);
  var139 = var139 + (0 * var38[2ll]);
  var139 = var139 + (0 * 0);
  var139 = var139 + (0 * 0);
  var78[0ll] = var139;
  blaze::StaticVector<float, 8> var140;
  var140 = 0;
  var140 = var140 + (1.0f * var38[1ll]);
  var140 = var140 + (0 * var38[3ll]);
  var140 = var140 + (0 * 0);
  var140 = var140 + (0 * 0);
  var78[4ll] = var140;
  blaze::StaticVector<float, 8> var141;
  var141 = 0;
  var141 = var141 + (0 * var38[0ll]);
  var141 = var141 + (1.0f * var38[2ll]);
  var141 = var141 + (0 * 0);
  var141 = var141 + (0.0930000022053719f * 0);
  var78[1ll] = var141;
  blaze::StaticVector<float, 8> var142;
  var142 = 0;
  var142 = var142 + (0 * var38[1ll]);
  var142 = var142 + (1.0f * var38[3ll]);
  var142 = var142 + (0 * 0);
  var142 = var142 + (0.0930000022053719f * 0);
  var78[5ll] = var142;
  blaze::StaticVector<float, 8> var143;
  var143 = 0;
  var143 = var143 + (var56[0ll] * var78[0ll]);
  var143 = var143 + (var56[1ll] * var78[1ll]);
  var143 = var143 + (var56[2ll] * 0);
  var143 = var143 + (var56[3ll] * 0);
  var59[0ll] = var143;
  blaze::StaticVector<float, 8> var144;
  var144 = 0;
  var144 = var144 + (var56[0ll] * var78[4ll]);
  var144 = var144 + (var56[1ll] * var78[5ll]);
  var144 = var144 + (var56[2ll] * 0);
  var144 = var144 + (var56[3ll] * 0);
  var59[1ll] = var144;
  blaze::StaticVector<float, 8> var145;
  var145 = 0;
  var145 = var145 + (var56[0ll] * 0);
  var145 = var145 + (var56[1ll] * 0);
  var145 = var145 + (var56[2ll] * 1.0f);
  var145 = var145 + (var56[3ll] * 0);
  var59[2ll] = var145;
  blaze::StaticVector<float, 8> var146;
  var146 = 0;
  var146 = var146 + (var56[0ll] * 0);
  var146 = var146 + (var56[1ll] * 0.0930000022053719f);
  var146 = var146 + (var56[2ll] * 0);
  var146 = var146 + (var56[3ll] * 1.0f);
  var59[3ll] = var146;
  blaze::StaticVector<float, 8> var147;
  var147 = 0;
  var147 = var147 + (var56[4ll] * var78[0ll]);
  var147 = var147 + (var56[5ll] * var78[1ll]);
  var147 = var147 + (var56[6ll] * 0);
  var147 = var147 + (var56[7ll] * 0);
  var59[4ll] = var147;
  blaze::StaticVector<float, 8> var148;
  var148 = 0;
  var148 = var148 + (var56[4ll] * var78[4ll]);
  var148 = var148 + (var56[5ll] * var78[5ll]);
  var148 = var148 + (var56[6ll] * 0);
  var148 = var148 + (var56[7ll] * 0);
  var59[5ll] = var148;
  blaze::StaticVector<float, 8> var149;
  var149 = 0;
  var149 = var149 + (var56[4ll] * 0);
  var149 = var149 + (var56[5ll] * 0);
  var149 = var149 + (var56[6ll] * 1.0f);
  var149 = var149 + (var56[7ll] * 0);
  var59[6ll] = var149;
  blaze::StaticVector<float, 8> var150;
  var150 = 0;
  var150 = var150 + (var56[4ll] * 0);
  var150 = var150 + (var56[5ll] * 0.0930000022053719f);
  var150 = var150 + (var56[6ll] * 0);
  var150 = var150 + (var56[7ll] * 1.0f);
  var59[7ll] = var150;
  blaze::StaticVector<float, 8> var151;
  var151 = 0;
  var151 = var151 + (var56[8ll] * var78[0ll]);
  var151 = var151 + (0 * var78[1ll]);
  var151 = var151 + (var56[9ll] * 0);
  var151 = var151 + (var56[10ll] * 0);
  var59[8ll] = var151;
  blaze::StaticVector<float, 8> var152;
  var152 = 0;
  var152 = var152 + (var56[8ll] * var78[4ll]);
  var152 = var152 + (0 * var78[5ll]);
  var152 = var152 + (var56[9ll] * 0);
  var152 = var152 + (var56[10ll] * 0);
  var59[9ll] = var152;
  blaze::StaticVector<float, 8> var153;
  var153 = 0;
  var153 = var153 + (var56[8ll] * 0);
  var153 = var153 + (0 * 0);
  var153 = var153 + (var56[9ll] * 1.0f);
  var153 = var153 + (var56[10ll] * 0);
  var59[10ll] = var153;
  blaze::StaticVector<float, 8> var154;
  var154 = 0;
  var154 = var154 + (var56[8ll] * 0);
  var154 = var154 + (0 * 0.0930000022053719f);
  var154 = var154 + (var56[9ll] * 0);
  var154 = var154 + (var56[10ll] * 1.0f);
  var59[11ll] = var154;
  var65[5ll] = ((var59[0ll] * 0.0f) + (var59[1ll] * 0.0f)) + (var59[2ll] * 0.0900000035762787f);
  var66[5ll] = ((var59[4ll] * 0.0f) + (var59[5ll] * 0.0f)) + (var59[6ll] * 0.0900000035762787f);
  var67[5ll] = ((var59[8ll] * 0.0f) + (var59[9ll] * 0.0f)) + (var59[10ll] * 0.0900000035762787f);
  var65[5ll] = var65[5ll] + var59[3ll];
  var66[5ll] = var66[5ll] + var59[7ll];
  var67[5ll] = var67[5ll] + var59[11ll];
  var68[5ll] = 0.0700000002980232f;
  var69[5ll] = 3ll;
  var70[0ll] = ((var59[0ll] * 0.0f) + (var59[1ll] * 0.0299999993294477f)) + (var59[2ll] * 0.0900000035762787f);
  var71[0ll] = ((var59[4ll] * 0.0f) + (var59[5ll] * 0.0299999993294477f)) + (var59[6ll] * 0.0900000035762787f);
  var72[0ll] = ((var59[8ll] * 0.0f) + (var59[9ll] * 0.0299999993294477f)) + (var59[10ll] * 0.0900000035762787f);
  var70[0ll] = var70[0ll] + var59[3ll];
  var71[0ll] = var71[0ll] + var59[7ll];
  var72[0ll] = var72[0ll] + var59[11ll];
  var73[0ll] = 0.0399999991059303f;
  var70[1ll] = ((var59[0ll] * 0.0f) + (var59[1ll] * -0.0299999993294477f)) + (var59[2ll] * 0.0900000035762787f);
  var71[1ll] = ((var59[4ll] * 0.0f) + (var59[5ll] * -0.0299999993294477f)) + (var59[6ll] * 0.0900000035762787f);
  var72[1ll] = ((var59[8ll] * 0.0f) + (var59[9ll] * -0.0299999993294477f)) + (var59[10ll] * 0.0900000035762787f);
  var70[1ll] = var70[1ll] + var59[3ll];
  var71[1ll] = var71[1ll] + var59[7ll];
  var72[1ll] = var72[1ll] + var59[11ll];
  var73[1ll] = 0.0399999991059303f;
  var70[2ll] = ((var59[0ll] * 0.0f) + (var59[1ll] * 0.0f)) + (var59[2ll] * 0.0900000035762787f);
  var71[2ll] = ((var59[4ll] * 0.0f) + (var59[5ll] * 0.0f)) + (var59[6ll] * 0.0900000035762787f);
  var72[2ll] = ((var59[8ll] * 0.0f) + (var59[9ll] * 0.0f)) + (var59[10ll] * 0.0900000035762787f);
  var70[2ll] = var70[2ll] + var59[3ll];
  var71[2ll] = var71[2ll] + var59[7ll];
  var72[2ll] = var72[2ll] + var59[11ll];
  var73[2ll] = 0.0399999991059303f;
  int var155;
  var155 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 5ll, var65[5ll], var66[5ll], var67[5ll], var68[5ll], var69[5ll], var70, var71, var72, var73);
  if (var155)
    return 0; //collision pair: 0,5
  var155 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 5ll, var65[5ll], var66[5ll], var67[5ll], var68[5ll], var69[5ll], var70, var71, var72, var73);
  if (var155)
    return 0; //collision pair: 1,5
  var155 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 5ll, var65[5ll], var66[5ll], var67[5ll], var68[5ll], var69[5ll], var70, var71, var72, var73);
  if (var155)
    return 0; //collision pair: 2,5
  var155 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 5ll, var65[5ll], var66[5ll], var67[5ll], var68[5ll], var69[5ll], var70, var71, var72, var73);
  if (var155)
    return 0; //collision pair: 3,5
  var155 = ctup_runtime::link_vs_environment_collision(var65[5ll], var66[5ll], var67[5ll], var68[5ll], var69[5ll], var70, var71, var72, var73, arg4);
  if (var155)
    return 0;
  var74[5ll] = var70;
  var75[5ll] = var71;
  var76[5ll] = var72;
  var77[5ll] = var73;
  blaze::StaticVector<float, 8> var156 = arg5[5ll];
  var42 = sin(var156);
  var43 = cos(var156);
  var41[0ll] = var43;
  var41[1ll] = var42;
  var41[2ll] = -(var42);
  var41[3ll] = var43;
  blaze::StaticVector<float, 8> var157;
  var157 = 0;
  var157 = var157 + (1.0f * var41[0ll]);
  var157 = var157 + (0 * 0);
  var157 = var157 + (0 * var41[2ll]);
  var157 = var157 + (0 * 0);
  var78[0ll] = var157;
  blaze::StaticVector<float, 8> var158;
  var158 = 0;
  var158 = var158 + (1.0f * var41[1ll]);
  var158 = var158 + (0 * 0);
  var158 = var158 + (0 * var41[3ll]);
  var158 = var158 + (0 * 0);
  var78[2ll] = var158;
  blaze::StaticVector<float, 8> var159;
  var159 = 0;
  var159 = var159 + (0 * var41[0ll]);
  var159 = var159 + (0 * 0);
  var159 = var159 + (1.0f * var41[2ll]);
  var159 = var159 + (0.094650000333786f * 0);
  var78[3ll] = var159;
  blaze::StaticVector<float, 8> var160;
  var160 = 0;
  var160 = var160 + (0 * var41[1ll]);
  var160 = var160 + (0 * 0);
  var160 = var160 + (1.0f * var41[3ll]);
  var160 = var160 + (0.094650000333786f * 0);
  var78[4ll] = var160;
  blaze::StaticVector<float, 8> var161;
  var161 = 0;
  var161 = var161 + (var59[0ll] * var78[0ll]);
  var161 = var161 + (var59[1ll] * 0);
  var161 = var161 + (var59[2ll] * var78[3ll]);
  var161 = var161 + (var59[3ll] * 0);
  var62[0ll] = var161;
  blaze::StaticVector<float, 8> var162;
  var162 = 0;
  var162 = var162 + (var59[0ll] * 0);
  var162 = var162 + (var59[1ll] * 1.0f);
  var162 = var162 + (var59[2ll] * 0);
  var162 = var162 + (var59[3ll] * 0);
  var62[1ll] = var162;
  blaze::StaticVector<float, 8> var163;
  var163 = 0;
  var163 = var163 + (var59[0ll] * var78[2ll]);
  var163 = var163 + (var59[1ll] * 0);
  var163 = var163 + (var59[2ll] * var78[4ll]);
  var163 = var163 + (var59[3ll] * 0);
  var62[2ll] = var163;
  blaze::StaticVector<float, 8> var164;
  var164 = 0;
  var164 = var164 + (var59[0ll] * 0);
  var164 = var164 + (var59[1ll] * 0);
  var164 = var164 + (var59[2ll] * 0.094650000333786f);
  var164 = var164 + (var59[3ll] * 1.0f);
  var62[3ll] = var164;
  blaze::StaticVector<float, 8> var165;
  var165 = 0;
  var165 = var165 + (var59[4ll] * var78[0ll]);
  var165 = var165 + (var59[5ll] * 0);
  var165 = var165 + (var59[6ll] * var78[3ll]);
  var165 = var165 + (var59[7ll] * 0);
  var62[4ll] = var165;
  blaze::StaticVector<float, 8> var166;
  var166 = 0;
  var166 = var166 + (var59[4ll] * 0);
  var166 = var166 + (var59[5ll] * 1.0f);
  var166 = var166 + (var59[6ll] * 0);
  var166 = var166 + (var59[7ll] * 0);
  var62[5ll] = var166;
  blaze::StaticVector<float, 8> var167;
  var167 = 0;
  var167 = var167 + (var59[4ll] * var78[2ll]);
  var167 = var167 + (var59[5ll] * 0);
  var167 = var167 + (var59[6ll] * var78[4ll]);
  var167 = var167 + (var59[7ll] * 0);
  var62[6ll] = var167;
  blaze::StaticVector<float, 8> var168;
  var168 = 0;
  var168 = var168 + (var59[4ll] * 0);
  var168 = var168 + (var59[5ll] * 0);
  var168 = var168 + (var59[6ll] * 0.094650000333786f);
  var168 = var168 + (var59[7ll] * 1.0f);
  var62[7ll] = var168;
  blaze::StaticVector<float, 8> var169;
  var169 = 0;
  var169 = var169 + (var59[8ll] * var78[0ll]);
  var169 = var169 + (var59[9ll] * 0);
  var169 = var169 + (var59[10ll] * var78[3ll]);
  var169 = var169 + (var59[11ll] * 0);
  var62[8ll] = var169;
  blaze::StaticVector<float, 8> var170;
  var170 = 0;
  var170 = var170 + (var59[8ll] * 0);
  var170 = var170 + (var59[9ll] * 1.0f);
  var170 = var170 + (var59[10ll] * 0);
  var170 = var170 + (var59[11ll] * 0);
  var62[9ll] = var170;
  blaze::StaticVector<float, 8> var171;
  var171 = 0;
  var171 = var171 + (var59[8ll] * var78[2ll]);
  var171 = var171 + (var59[9ll] * 0);
  var171 = var171 + (var59[10ll] * var78[4ll]);
  var171 = var171 + (var59[11ll] * 0);
  var62[10ll] = var171;
  blaze::StaticVector<float, 8> var172;
  var172 = 0;
  var172 = var172 + (var59[8ll] * 0);
  var172 = var172 + (var59[9ll] * 0);
  var172 = var172 + (var59[10ll] * 0.094650000333786f);
  var172 = var172 + (var59[11ll] * 1.0f);
  var62[11ll] = var172;
  var65[6ll] = ((var62[0ll] * 0.0f) + (var62[1ll] * 0.0599999986588955f)) + (var62[2ll] * 0.0f);
  var66[6ll] = ((var62[4ll] * 0.0f) + (var62[5ll] * 0.0599999986588955f)) + (var62[6ll] * 0.0f);
  var67[6ll] = ((var62[8ll] * 0.0f) + (var62[9ll] * 0.0599999986588955f)) + (var62[10ll] * 0.0f);
  var65[6ll] = var65[6ll] + var62[3ll];
  var66[6ll] = var66[6ll] + var62[7ll];
  var67[6ll] = var67[6ll] + var62[11ll];
  var68[6ll] = 0.0399999991059303f;
  var69[6ll] = 1ll;
  var70[0ll] = ((var62[0ll] * 0.0f) + (var62[1ll] * 0.0599999986588955f)) + (var62[2ll] * 0.0f);
  var71[0ll] = ((var62[4ll] * 0.0f) + (var62[5ll] * 0.0599999986588955f)) + (var62[6ll] * 0.0f);
  var72[0ll] = ((var62[8ll] * 0.0f) + (var62[9ll] * 0.0599999986588955f)) + (var62[10ll] * 0.0f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0399999991059303f;
  int var173;
  var173 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 6ll, var65[6ll], var66[6ll], var67[6ll], var68[6ll], var69[6ll], var70, var71, var72, var73);
  if (var173)
    return 0; //collision pair: 0,6
  var173 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 6ll, var65[6ll], var66[6ll], var67[6ll], var68[6ll], var69[6ll], var70, var71, var72, var73);
  if (var173)
    return 0; //collision pair: 1,6
  var173 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 6ll, var65[6ll], var66[6ll], var67[6ll], var68[6ll], var69[6ll], var70, var71, var72, var73);
  if (var173)
    return 0; //collision pair: 2,6
  var173 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 6ll, var65[6ll], var66[6ll], var67[6ll], var68[6ll], var69[6ll], var70, var71, var72, var73);
  if (var173)
    return 0; //collision pair: 3,6
  var173 = ctup_runtime::link_vs_environment_collision(var65[6ll], var66[6ll], var67[6ll], var68[6ll], var69[6ll], var70, var71, var72, var73, arg4);
  if (var173)
    return 0;
  var74[6ll] = var70;
  var75[6ll] = var71;
  var76[6ll] = var72;
  var77[6ll] = var73;
  var65[7ll] = ((var62[0ll] * 1.59265619004145e-05f) + (var62[1ll] * 0.0973000079393387f)) + (var62[2ll] * 0.0f);
  var66[7ll] = ((var62[4ll] * 1.59265619004145e-05f) + (var62[5ll] * 0.0973000079393387f)) + (var62[6ll] * 0.0f);
  var67[7ll] = ((var62[8ll] * 1.59265619004145e-05f) + (var62[9ll] * 0.0973000079393387f)) + (var62[10ll] * 0.0f);
  var65[7ll] = var65[7ll] + var62[3ll];
  var66[7ll] = var66[7ll] + var62[7ll];
  var67[7ll] = var67[7ll] + var62[11ll];
  var68[7ll] = 0.0399999991059303f;
  var69[7ll] = 1ll;
  var70[0ll] = ((var62[0ll] * 1.59265619004145e-05f) + (var62[1ll] * 0.0973000079393387f)) + (var62[2ll] * 0.0f);
  var71[0ll] = ((var62[4ll] * 1.59265619004145e-05f) + (var62[5ll] * 0.0973000079393387f)) + (var62[6ll] * 0.0f);
  var72[0ll] = ((var62[8ll] * 1.59265619004145e-05f) + (var62[9ll] * 0.0973000079393387f)) + (var62[10ll] * 0.0f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0399999991059303f;
  int var174;
  var174 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 7ll, var65[7ll], var66[7ll], var67[7ll], var68[7ll], var69[7ll], var70, var71, var72, var73);
  if (var174)
    return 0; //collision pair: 0,7
  var174 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 7ll, var65[7ll], var66[7ll], var67[7ll], var68[7ll], var69[7ll], var70, var71, var72, var73);
  if (var174)
    return 0; //collision pair: 1,7
  var174 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 7ll, var65[7ll], var66[7ll], var67[7ll], var68[7ll], var69[7ll], var70, var71, var72, var73);
  if (var174)
    return 0; //collision pair: 2,7
  var174 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 7ll, var65[7ll], var66[7ll], var67[7ll], var68[7ll], var69[7ll], var70, var71, var72, var73);
  if (var174)
    return 0; //collision pair: 3,7
  var174 = ctup_runtime::self_collision_link_vs_link(4ll, var65[4ll], var66[4ll], var67[4ll], var68[4ll], var69[4ll], var74[4ll], var75[4ll], var76[4ll], var77[4ll], 7ll, var65[7ll], var66[7ll], var67[7ll], var68[7ll], var69[7ll], var70, var71, var72, var73);
  if (var174)
    return 0; //collision pair: 4,7
  var174 = ctup_runtime::self_collision_link_vs_link(5ll, var65[5ll], var66[5ll], var67[5ll], var68[5ll], var69[5ll], var74[5ll], var75[5ll], var76[5ll], var77[5ll], 7ll, var65[7ll], var66[7ll], var67[7ll], var68[7ll], var69[7ll], var70, var71, var72, var73);
  if (var174)
    return 0; //collision pair: 5,7
  var174 = ctup_runtime::link_vs_environment_collision(var65[7ll], var66[7ll], var67[7ll], var68[7ll], var69[7ll], var70, var71, var72, var73, arg4);
  if (var174)
    return 0;
  var74[7ll] = var70;
  var75[7ll] = var71;
  var76[7ll] = var72;
  var77[7ll] = var73;
  var65[8ll] = ((var62[0ll] * -3.18529237119947e-05f) + (var62[1ll] * 0.157299980521202f)) + (var62[2ll] * 0.000531853060238063f);
  var66[8ll] = ((var62[4ll] * -3.18529237119947e-05f) + (var62[5ll] * 0.157299980521202f)) + (var62[6ll] * 0.000531853060238063f);
  var67[8ll] = ((var62[8ll] * -3.18529237119947e-05f) + (var62[9ll] * 0.157299980521202f)) + (var62[10ll] * 0.000531853060238063f);
  var65[8ll] = var65[8ll] + var62[3ll];
  var66[8ll] = var66[8ll] + var62[7ll];
  var67[8ll] = var67[8ll] + var62[11ll];
  var68[8ll] = 0.0599999986588955f;
  var69[8ll] = 2ll;
  var70[0ll] = ((var62[0ll] * -4.77794164908119e-05f) + (var62[1ll] * 0.177299961447716f)) + (var62[2ll] * 0.000547779607586563f);
  var71[0ll] = ((var62[4ll] * -4.77794164908119e-05f) + (var62[5ll] * 0.177299961447716f)) + (var62[6ll] * 0.000547779607586563f);
  var72[0ll] = ((var62[8ll] * -4.77794164908119e-05f) + (var62[9ll] * 0.177299961447716f)) + (var62[10ll] * 0.000547779607586563f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0399999991059303f;
  var70[1ll] = ((var62[0ll] * -1.59264309331775e-05f) + (var62[1ll] * 0.137299984693527f)) + (var62[2ll] * 0.000515926512889564f);
  var71[1ll] = ((var62[4ll] * -1.59264309331775e-05f) + (var62[5ll] * 0.137299984693527f)) + (var62[6ll] * 0.000515926512889564f);
  var72[1ll] = ((var62[8ll] * -1.59264309331775e-05f) + (var62[9ll] * 0.137299984693527f)) + (var62[10ll] * 0.000515926512889564f);
  var70[1ll] = var70[1ll] + var62[3ll];
  var71[1ll] = var71[1ll] + var62[7ll];
  var72[1ll] = var72[1ll] + var62[11ll];
  var73[1ll] = 0.0399999991059303f;
  int var175;
  var175 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 8ll, var65[8ll], var66[8ll], var67[8ll], var68[8ll], var69[8ll], var70, var71, var72, var73);
  if (var175)
    return 0; //collision pair: 0,8
  var175 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 8ll, var65[8ll], var66[8ll], var67[8ll], var68[8ll], var69[8ll], var70, var71, var72, var73);
  if (var175)
    return 0; //collision pair: 1,8
  var175 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 8ll, var65[8ll], var66[8ll], var67[8ll], var68[8ll], var69[8ll], var70, var71, var72, var73);
  if (var175)
    return 0; //collision pair: 2,8
  var175 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 8ll, var65[8ll], var66[8ll], var67[8ll], var68[8ll], var69[8ll], var70, var71, var72, var73);
  if (var175)
    return 0; //collision pair: 3,8
  var175 = ctup_runtime::link_vs_environment_collision(var65[8ll], var66[8ll], var67[8ll], var68[8ll], var69[8ll], var70, var71, var72, var73, arg4);
  if (var175)
    return 0;
  var74[8ll] = var70;
  var75[8ll] = var71;
  var76[8ll] = var72;
  var77[8ll] = var73;
  var65[9ll] = ((var62[0ll] * 0.0326288715004921f) + (var62[1ll] * 0.206633478403091f)) + (var62[2ll] * 0.000571117969229817f);
  var66[9ll] = ((var62[4ll] * 0.0326288715004921f) + (var62[5ll] * 0.206633478403091f)) + (var62[6ll] * 0.000571117969229817f);
  var67[9ll] = ((var62[8ll] * 0.0326288715004921f) + (var62[9ll] * 0.206633478403091f)) + (var62[10ll] * 0.000571117969229817f);
  var65[9ll] = var65[9ll] + var62[3ll];
  var66[9ll] = var66[9ll] + var62[7ll];
  var67[9ll] = var67[9ll] + var62[11ll];
  var68[9ll] = 0.0199999995529652f;
  var69[9ll] = 1ll;
  var70[0ll] = ((var62[0ll] * 0.0326288715004921f) + (var62[1ll] * 0.206633478403091f)) + (var62[2ll] * 0.000571117969229817f);
  var71[0ll] = ((var62[4ll] * 0.0326288715004921f) + (var62[5ll] * 0.206633478403091f)) + (var62[6ll] * 0.000571117969229817f);
  var72[0ll] = ((var62[8ll] * 0.0326288715004921f) + (var62[9ll] * 0.206633478403091f)) + (var62[10ll] * 0.000571117969229817f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0199999995529652f;
  int var176;
  var176 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 9ll, var65[9ll], var66[9ll], var67[9ll], var68[9ll], var69[9ll], var70, var71, var72, var73);
  if (var176)
    return 0; //collision pair: 0,9
  var176 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 9ll, var65[9ll], var66[9ll], var67[9ll], var68[9ll], var69[9ll], var70, var71, var72, var73);
  if (var176)
    return 0; //collision pair: 1,9
  var176 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 9ll, var65[9ll], var66[9ll], var67[9ll], var68[9ll], var69[9ll], var70, var71, var72, var73);
  if (var176)
    return 0; //collision pair: 2,9
  var176 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 9ll, var65[9ll], var66[9ll], var67[9ll], var68[9ll], var69[9ll], var70, var71, var72, var73);
  if (var176)
    return 0; //collision pair: 3,9
  var176 = ctup_runtime::link_vs_environment_collision(var65[9ll], var66[9ll], var67[9ll], var68[9ll], var69[9ll], var70, var71, var72, var73, arg4);
  if (var176)
    return 0;
  var74[9ll] = var70;
  var75[9ll] = var71;
  var76[9ll] = var72;
  var77[9ll] = var73;
  var65[10ll] = ((var62[0ll] * 0.047183521091938f) + (var62[1ll] * 0.245142087340355f)) + (var62[2ll] * 0.000601774139795452f);
  var66[10ll] = ((var62[4ll] * 0.047183521091938f) + (var62[5ll] * 0.245142087340355f)) + (var62[6ll] * 0.000601774139795452f);
  var67[10ll] = ((var62[8ll] * 0.047183521091938f) + (var62[9ll] * 0.245142087340355f)) + (var62[10ll] * 0.000601774139795452f);
  var65[10ll] = var65[10ll] + var62[3ll];
  var66[10ll] = var66[10ll] + var62[7ll];
  var67[10ll] = var67[10ll] + var62[11ll];
  var68[10ll] = 0.0329999998211861f;
  var69[10ll] = 2ll;
  var70[0ll] = ((var62[0ll] * 0.0471739657223225f) + (var62[1ll] * 0.257142096757889f)) + (var62[2ll] * 0.000611330091487616f);
  var71[0ll] = ((var62[4ll] * 0.0471739657223225f) + (var62[5ll] * 0.257142096757889f)) + (var62[6ll] * 0.000611330091487616f);
  var72[0ll] = ((var62[8ll] * 0.0471739657223225f) + (var62[9ll] * 0.257142096757889f)) + (var62[10ll] * 0.000611330091487616f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0199999995529652f;
  var70[1ll] = ((var62[0ll] * 0.0471938736736774f) + (var62[1ll] * 0.232142105698586f)) + (var62[2ll] * 0.000591421907301992f);
  var71[1ll] = ((var62[4ll] * 0.0471938736736774f) + (var62[5ll] * 0.232142105698586f)) + (var62[6ll] * 0.000591421907301992f);
  var72[1ll] = ((var62[8ll] * 0.0471938736736774f) + (var62[9ll] * 0.232142105698586f)) + (var62[10ll] * 0.000591421907301992f);
  var70[1ll] = var70[1ll] + var62[3ll];
  var71[1ll] = var71[1ll] + var62[7ll];
  var72[1ll] = var72[1ll] + var62[11ll];
  var73[1ll] = 0.0199999995529652f;
  int var177;
  var177 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 10ll, var65[10ll], var66[10ll], var67[10ll], var68[10ll], var69[10ll], var70, var71, var72, var73);
  if (var177)
    return 0; //collision pair: 0,10
  var177 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 10ll, var65[10ll], var66[10ll], var67[10ll], var68[10ll], var69[10ll], var70, var71, var72, var73);
  if (var177)
    return 0; //collision pair: 1,10
  var177 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 10ll, var65[10ll], var66[10ll], var67[10ll], var68[10ll], var69[10ll], var70, var71, var72, var73);
  if (var177)
    return 0; //collision pair: 2,10
  var177 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 10ll, var65[10ll], var66[10ll], var67[10ll], var68[10ll], var69[10ll], var70, var71, var72, var73);
  if (var177)
    return 0; //collision pair: 3,10
  var177 = ctup_runtime::link_vs_environment_collision(var65[10ll], var66[10ll], var67[10ll], var68[10ll], var69[10ll], var70, var71, var72, var73, arg4);
  if (var177)
    return 0;
  var74[10ll] = var70;
  var75[10ll] = var71;
  var76[10ll] = var72;
  var77[10ll] = var73;
  var65[11ll] = ((var62[0ll] * 0.0305511318147182f) + (var62[1ll] * 0.180116340517998f)) + (var62[2ll] * 0.000550002965610474f);
  var66[11ll] = ((var62[4ll] * 0.0305511318147182f) + (var62[5ll] * 0.180116340517998f)) + (var62[6ll] * 0.000550002965610474f);
  var67[11ll] = ((var62[8ll] * 0.0305511318147182f) + (var62[9ll] * 0.180116340517998f)) + (var62[10ll] * 0.000550002965610474f);
  var65[11ll] = var65[11ll] + var62[3ll];
  var66[11ll] = var66[11ll] + var62[7ll];
  var67[11ll] = var67[11ll] + var62[11ll];
  var68[11ll] = 0.0199999995529652f;
  var69[11ll] = 1ll;
  var70[0ll] = ((var62[0ll] * 0.0305511318147182f) + (var62[1ll] * 0.180116340517998f)) + (var62[2ll] * 0.000550002965610474f);
  var71[0ll] = ((var62[4ll] * 0.0305511318147182f) + (var62[5ll] * 0.180116340517998f)) + (var62[6ll] * 0.000550002965610474f);
  var72[0ll] = ((var62[8ll] * 0.0305511318147182f) + (var62[9ll] * 0.180116340517998f)) + (var62[10ll] * 0.000550002965610474f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0199999995529652f;
  int var178;
  var178 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 11ll, var65[11ll], var66[11ll], var67[11ll], var68[11ll], var69[11ll], var70, var71, var72, var73);
  if (var178)
    return 0; //collision pair: 0,11
  var178 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 11ll, var65[11ll], var66[11ll], var67[11ll], var68[11ll], var69[11ll], var70, var71, var72, var73);
  if (var178)
    return 0; //collision pair: 1,11
  var178 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 11ll, var65[11ll], var66[11ll], var67[11ll], var68[11ll], var69[11ll], var70, var71, var72, var73);
  if (var178)
    return 0; //collision pair: 2,11
  var178 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 11ll, var65[11ll], var66[11ll], var67[11ll], var68[11ll], var69[11ll], var70, var71, var72, var73);
  if (var178)
    return 0; //collision pair: 3,11
  var178 = ctup_runtime::link_vs_environment_collision(var65[11ll], var66[11ll], var67[11ll], var68[11ll], var69[11ll], var70, var71, var72, var73, arg4);
  if (var178)
    return 0;
  var74[11ll] = var70;
  var75[11ll] = var71;
  var76[11ll] = var72;
  var77[11ll] = var73;
  var65[12ll] = ((var62[0ll] * 0.0622277781367302f) + (var62[1ll] * 0.198207601904869f)) + (var62[2ll] * 0.000564389454666525f);
  var66[12ll] = ((var62[4ll] * 0.0622277781367302f) + (var62[5ll] * 0.198207601904869f)) + (var62[6ll] * 0.000564389454666525f);
  var67[12ll] = ((var62[8ll] * 0.0622277781367302f) + (var62[9ll] * 0.198207601904869f)) + (var62[10ll] * 0.000564389454666525f);
  var65[12ll] = var65[12ll] + var62[3ll];
  var66[12ll] = var66[12ll] + var62[7ll];
  var67[12ll] = var67[12ll] + var62[11ll];
  var68[12ll] = 0.0350000001490116f;
  var69[12ll] = 3ll;
  var70[0ll] = ((var62[0ll] * 0.0622118525207043f) + (var62[1ll] * 0.218207597732544f)) + (var62[2ll] * 0.000580315943807364f);
  var71[0ll] = ((var62[4ll] * 0.0622118525207043f) + (var62[5ll] * 0.218207597732544f)) + (var62[6ll] * 0.000580315943807364f);
  var72[0ll] = ((var62[8ll] * 0.0622118525207043f) + (var62[9ll] * 0.218207597732544f)) + (var62[10ll] * 0.000580315943807364f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0149999996647239f;
  var70[1ll] = ((var62[0ll] * 0.0622437074780464f) + (var62[1ll] * 0.178207620978355f)) + (var62[2ll] * 0.000548462907318026f);
  var71[1ll] = ((var62[4ll] * 0.0622437074780464f) + (var62[5ll] * 0.178207620978355f)) + (var62[6ll] * 0.000548462907318026f);
  var72[1ll] = ((var62[8ll] * 0.0622437074780464f) + (var62[9ll] * 0.178207620978355f)) + (var62[10ll] * 0.000548462907318026f);
  var70[1ll] = var70[1ll] + var62[3ll];
  var71[1ll] = var71[1ll] + var62[7ll];
  var72[1ll] = var72[1ll] + var62[11ll];
  var73[1ll] = 0.0149999996647239f;
  var70[2ll] = ((var62[0ll] * 0.0622277781367302f) + (var62[1ll] * 0.198207601904869f)) + (var62[2ll] * 0.000564389454666525f);
  var71[2ll] = ((var62[4ll] * 0.0622277781367302f) + (var62[5ll] * 0.198207601904869f)) + (var62[6ll] * 0.000564389454666525f);
  var72[2ll] = ((var62[8ll] * 0.0622277781367302f) + (var62[9ll] * 0.198207601904869f)) + (var62[10ll] * 0.000564389454666525f);
  var70[2ll] = var70[2ll] + var62[3ll];
  var71[2ll] = var71[2ll] + var62[7ll];
  var72[2ll] = var72[2ll] + var62[11ll];
  var73[2ll] = 0.0149999996647239f;
  int var179;
  var179 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 12ll, var65[12ll], var66[12ll], var67[12ll], var68[12ll], var69[12ll], var70, var71, var72, var73);
  if (var179)
    return 0; //collision pair: 0,12
  var179 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 12ll, var65[12ll], var66[12ll], var67[12ll], var68[12ll], var69[12ll], var70, var71, var72, var73);
  if (var179)
    return 0; //collision pair: 1,12
  var179 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 12ll, var65[12ll], var66[12ll], var67[12ll], var68[12ll], var69[12ll], var70, var71, var72, var73);
  if (var179)
    return 0; //collision pair: 2,12
  var179 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 12ll, var65[12ll], var66[12ll], var67[12ll], var68[12ll], var69[12ll], var70, var71, var72, var73);
  if (var179)
    return 0; //collision pair: 3,12
  var179 = ctup_runtime::link_vs_environment_collision(var65[12ll], var66[12ll], var67[12ll], var68[12ll], var69[12ll], var70, var71, var72, var73, arg4);
  if (var179)
    return 0;
  var74[12ll] = var70;
  var75[12ll] = var71;
  var76[12ll] = var72;
  var77[12ll] = var73;
  var65[13ll] = ((var62[0ll] * -0.0327711068093777f) + (var62[1ll] * 0.206581398844719f)) + (var62[2ll] * 0.000571117969229817f);
  var66[13ll] = ((var62[4ll] * -0.0327711068093777f) + (var62[5ll] * 0.206581398844719f)) + (var62[6ll] * 0.000571117969229817f);
  var67[13ll] = ((var62[8ll] * -0.0327711068093777f) + (var62[9ll] * 0.206581398844719f)) + (var62[10ll] * 0.000571117969229817f);
  var65[13ll] = var65[13ll] + var62[3ll];
  var66[13ll] = var66[13ll] + var62[7ll];
  var67[13ll] = var67[13ll] + var62[11ll];
  var68[13ll] = 0.0199999995529652f;
  var69[13ll] = 1ll;
  var70[0ll] = ((var62[0ll] * -0.0327711068093777f) + (var62[1ll] * 0.206581398844719f)) + (var62[2ll] * 0.000571117969229817f);
  var71[0ll] = ((var62[4ll] * -0.0327711068093777f) + (var62[5ll] * 0.206581398844719f)) + (var62[6ll] * 0.000571117969229817f);
  var72[0ll] = ((var62[8ll] * -0.0327711068093777f) + (var62[9ll] * 0.206581398844719f)) + (var62[10ll] * 0.000571117969229817f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0199999995529652f;
  int var180;
  var180 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 13ll, var65[13ll], var66[13ll], var67[13ll], var68[13ll], var69[13ll], var70, var71, var72, var73);
  if (var180)
    return 0; //collision pair: 0,13
  var180 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 13ll, var65[13ll], var66[13ll], var67[13ll], var68[13ll], var69[13ll], var70, var71, var72, var73);
  if (var180)
    return 0; //collision pair: 1,13
  var180 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 13ll, var65[13ll], var66[13ll], var67[13ll], var68[13ll], var69[13ll], var70, var71, var72, var73);
  if (var180)
    return 0; //collision pair: 2,13
  var180 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 13ll, var65[13ll], var66[13ll], var67[13ll], var68[13ll], var69[13ll], var70, var71, var72, var73);
  if (var180)
    return 0; //collision pair: 3,13
  var180 = ctup_runtime::link_vs_environment_collision(var65[13ll], var66[13ll], var67[13ll], var68[13ll], var69[13ll], var70, var71, var72, var73, arg4);
  if (var180)
    return 0;
  var74[13ll] = var70;
  var75[13ll] = var71;
  var76[13ll] = var72;
  var77[13ll] = var73;
  var65[14ll] = ((var62[0ll] * -0.0469080917537212f) + (var62[1ll] * 0.245427533984184f)) + (var62[2ll] * 0.000602061103563756f);
  var66[14ll] = ((var62[4ll] * -0.0469080917537212f) + (var62[5ll] * 0.245427533984184f)) + (var62[6ll] * 0.000602061103563756f);
  var67[14ll] = ((var62[8ll] * -0.0469080917537212f) + (var62[9ll] * 0.245427533984184f)) + (var62[10ll] * 0.000602061103563756f);
  var65[14ll] = var65[14ll] + var62[3ll];
  var66[14ll] = var66[14ll] + var62[7ll];
  var67[14ll] = var67[14ll] + var62[11ll];
  var68[14ll] = 0.0329999998211861f;
  var69[14ll] = 2ll;
  var70[0ll] = ((var62[0ll] * -0.0469176508486271f) + (var62[1ll] * 0.257427513599396f)) + (var62[2ll] * 0.00061161705525592f);
  var71[0ll] = ((var62[4ll] * -0.0469176508486271f) + (var62[5ll] * 0.257427513599396f)) + (var62[6ll] * 0.00061161705525592f);
  var72[0ll] = ((var62[8ll] * -0.0469176508486271f) + (var62[9ll] * 0.257427513599396f)) + (var62[10ll] * 0.00061161705525592f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0199999995529652f;
  var70[1ll] = ((var62[0ll] * -0.0468977428972721f) + (var62[1ll] * 0.232427537441254f)) + (var62[2ll] * 0.000591708871070296f);
  var71[1ll] = ((var62[4ll] * -0.0468977428972721f) + (var62[5ll] * 0.232427537441254f)) + (var62[6ll] * 0.000591708871070296f);
  var72[1ll] = ((var62[8ll] * -0.0468977428972721f) + (var62[9ll] * 0.232427537441254f)) + (var62[10ll] * 0.000591708871070296f);
  var70[1ll] = var70[1ll] + var62[3ll];
  var71[1ll] = var71[1ll] + var62[7ll];
  var72[1ll] = var72[1ll] + var62[11ll];
  var73[1ll] = 0.0199999995529652f;
  int var181;
  var181 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 14ll, var65[14ll], var66[14ll], var67[14ll], var68[14ll], var69[14ll], var70, var71, var72, var73);
  if (var181)
    return 0; //collision pair: 0,14
  var181 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 14ll, var65[14ll], var66[14ll], var67[14ll], var68[14ll], var69[14ll], var70, var71, var72, var73);
  if (var181)
    return 0; //collision pair: 1,14
  var181 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 14ll, var65[14ll], var66[14ll], var67[14ll], var68[14ll], var69[14ll], var70, var71, var72, var73);
  if (var181)
    return 0; //collision pair: 2,14
  var181 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 14ll, var65[14ll], var66[14ll], var67[14ll], var68[14ll], var69[14ll], var70, var71, var72, var73);
  if (var181)
    return 0; //collision pair: 3,14
  var181 = ctup_runtime::link_vs_environment_collision(var65[14ll], var66[14ll], var67[14ll], var68[14ll], var69[14ll], var70, var71, var72, var73, arg4);
  if (var181)
    return 0;
  var74[14ll] = var70;
  var75[14ll] = var71;
  var76[14ll] = var72;
  var77[14ll] = var73;
  var65[15ll] = ((var62[0ll] * -0.0306511372327805f) + (var62[1ll] * 0.180067613720894f)) + (var62[2ll] * 0.000550002965610474f);
  var66[15ll] = ((var62[4ll] * -0.0306511372327805f) + (var62[5ll] * 0.180067613720894f)) + (var62[6ll] * 0.000550002965610474f);
  var67[15ll] = ((var62[8ll] * -0.0306511372327805f) + (var62[9ll] * 0.180067613720894f)) + (var62[10ll] * 0.000550002965610474f);
  var65[15ll] = var65[15ll] + var62[3ll];
  var66[15ll] = var66[15ll] + var62[7ll];
  var67[15ll] = var67[15ll] + var62[11ll];
  var68[15ll] = 0.0199999995529652f;
  var69[15ll] = 1ll;
  var70[0ll] = ((var62[0ll] * -0.0306511372327805f) + (var62[1ll] * 0.180067613720894f)) + (var62[2ll] * 0.000550002965610474f);
  var71[0ll] = ((var62[4ll] * -0.0306511372327805f) + (var62[5ll] * 0.180067613720894f)) + (var62[6ll] * 0.000550002965610474f);
  var72[0ll] = ((var62[8ll] * -0.0306511372327805f) + (var62[9ll] * 0.180067613720894f)) + (var62[10ll] * 0.000550002965610474f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0199999995529652f;
  int var182;
  var182 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 15ll, var65[15ll], var66[15ll], var67[15ll], var68[15ll], var69[15ll], var70, var71, var72, var73);
  if (var182)
    return 0; //collision pair: 0,15
  var182 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 15ll, var65[15ll], var66[15ll], var67[15ll], var68[15ll], var69[15ll], var70, var71, var72, var73);
  if (var182)
    return 0; //collision pair: 1,15
  var182 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 15ll, var65[15ll], var66[15ll], var67[15ll], var68[15ll], var69[15ll], var70, var71, var72, var73);
  if (var182)
    return 0; //collision pair: 2,15
  var182 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 15ll, var65[15ll], var66[15ll], var67[15ll], var68[15ll], var69[15ll], var70, var71, var72, var73);
  if (var182)
    return 0; //collision pair: 3,15
  var182 = ctup_runtime::link_vs_environment_collision(var65[15ll], var66[15ll], var67[15ll], var68[15ll], var69[15ll], var70, var71, var72, var73, arg4);
  if (var182)
    return 0;
  var74[15ll] = var70;
  var75[15ll] = var71;
  var76[15ll] = var72;
  var77[15ll] = var73;
  var65[16ll] = ((var62[0ll] * -0.062375370413065f) + (var62[1ll] * 0.198440983891487f)) + (var62[2ll] * 0.000564654299523681f);
  var66[16ll] = ((var62[4ll] * -0.062375370413065f) + (var62[5ll] * 0.198440983891487f)) + (var62[6ll] * 0.000564654299523681f);
  var67[16ll] = ((var62[8ll] * -0.062375370413065f) + (var62[9ll] * 0.198440983891487f)) + (var62[10ll] * 0.000564654299523681f);
  var65[16ll] = var65[16ll] + var62[3ll];
  var66[16ll] = var66[16ll] + var62[7ll];
  var67[16ll] = var67[16ll] + var62[11ll];
  var68[16ll] = 0.0350000001490116f;
  var69[16ll] = 3ll;
  var70[0ll] = ((var62[0ll] * -0.0623912960290909f) + (var62[1ll] * 0.218440979719162f)) + (var62[2ll] * 0.000580580846872181f);
  var71[0ll] = ((var62[4ll] * -0.0623912960290909f) + (var62[5ll] * 0.218440979719162f)) + (var62[6ll] * 0.000580580846872181f);
  var72[0ll] = ((var62[8ll] * -0.0623912960290909f) + (var62[9ll] * 0.218440979719162f)) + (var62[10ll] * 0.000580580846872181f);
  var70[0ll] = var70[0ll] + var62[3ll];
  var71[0ll] = var71[0ll] + var62[7ll];
  var72[0ll] = var72[0ll] + var62[11ll];
  var73[0ll] = 0.0149999996647239f;
  var70[1ll] = ((var62[0ll] * -0.062359444797039f) + (var62[1ll] * 0.178441002964973f)) + (var62[2ll] * 0.000548727752175182f);
  var71[1ll] = ((var62[4ll] * -0.062359444797039f) + (var62[5ll] * 0.178441002964973f)) + (var62[6ll] * 0.000548727752175182f);
  var72[1ll] = ((var62[8ll] * -0.062359444797039f) + (var62[9ll] * 0.178441002964973f)) + (var62[10ll] * 0.000548727752175182f);
  var70[1ll] = var70[1ll] + var62[3ll];
  var71[1ll] = var71[1ll] + var62[7ll];
  var72[1ll] = var72[1ll] + var62[11ll];
  var73[1ll] = 0.0149999996647239f;
  var70[2ll] = ((var62[0ll] * -0.062375370413065f) + (var62[1ll] * 0.198440983891487f)) + (var62[2ll] * 0.000564654299523681f);
  var71[2ll] = ((var62[4ll] * -0.062375370413065f) + (var62[5ll] * 0.198440983891487f)) + (var62[6ll] * 0.000564654299523681f);
  var72[2ll] = ((var62[8ll] * -0.062375370413065f) + (var62[9ll] * 0.198440983891487f)) + (var62[10ll] * 0.000564654299523681f);
  var70[2ll] = var70[2ll] + var62[3ll];
  var71[2ll] = var71[2ll] + var62[7ll];
  var72[2ll] = var72[2ll] + var62[11ll];
  var73[2ll] = 0.0149999996647239f;
  int var183;
  var183 = ctup_runtime::self_collision_link_vs_link(0ll, var65[0ll], var66[0ll], var67[0ll], var68[0ll], var69[0ll], var74[0ll], var75[0ll], var76[0ll], var77[0ll], 16ll, var65[16ll], var66[16ll], var67[16ll], var68[16ll], var69[16ll], var70, var71, var72, var73);
  if (var183)
    return 0; //collision pair: 0,16
  var183 = ctup_runtime::self_collision_link_vs_link(1ll, var65[1ll], var66[1ll], var67[1ll], var68[1ll], var69[1ll], var74[1ll], var75[1ll], var76[1ll], var77[1ll], 16ll, var65[16ll], var66[16ll], var67[16ll], var68[16ll], var69[16ll], var70, var71, var72, var73);
  if (var183)
    return 0; //collision pair: 1,16
  var183 = ctup_runtime::self_collision_link_vs_link(2ll, var65[2ll], var66[2ll], var67[2ll], var68[2ll], var69[2ll], var74[2ll], var75[2ll], var76[2ll], var77[2ll], 16ll, var65[16ll], var66[16ll], var67[16ll], var68[16ll], var69[16ll], var70, var71, var72, var73);
  if (var183)
    return 0; //collision pair: 2,16
  var183 = ctup_runtime::self_collision_link_vs_link(3ll, var65[3ll], var66[3ll], var67[3ll], var68[3ll], var69[3ll], var74[3ll], var75[3ll], var76[3ll], var77[3ll], 16ll, var65[16ll], var66[16ll], var67[16ll], var68[16ll], var69[16ll], var70, var71, var72, var73);
  if (var183)
    return 0; //collision pair: 3,16
  var183 = ctup_runtime::link_vs_environment_collision(var65[16ll], var66[16ll], var67[16ll], var68[16ll], var69[16ll], var70, var71, var72, var73, arg4);
  if (var183)
    return 0;
  var74[16ll] = var70;
  var75[16ll] = var71;
  var76[16ll] = var72;
  var77[16ll] = var73;
  return 1;
}

}
