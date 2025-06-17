#include "blaze/Math.h"

#include "self_collision.h"

#include <iostream>

namespace ctup_gen {

static void print_string(const char* str) {
  std::cout << str << "\n";
}

template<typename MT>
static void print_matrix(const blaze::DenseMatrix<MT, blaze::rowMajor>& matrix) {
  std::cout << matrix << "\n";
}

static int fkcc (AlignedSVd8Vector& arg4) {
  blaze::StaticVector<double, 8> var25[16];
  blaze::StaticVector<double, 8> var26;
  blaze::StaticVector<double, 8> var27;
  blaze::StaticVector<double, 8> var28[16];
  blaze::StaticVector<double, 8> var29;
  blaze::StaticVector<double, 8> var30;
  blaze::StaticVector<double, 8> var31[16];
  blaze::StaticVector<double, 8> var32;
  blaze::StaticVector<double, 8> var33;
  blaze::StaticVector<double, 8> var34[16];
  blaze::StaticVector<double, 8> var35;
  blaze::StaticVector<double, 8> var36;
  blaze::StaticVector<double, 8> var37[16];
  blaze::StaticVector<double, 8> var38;
  blaze::StaticVector<double, 8> var39;
  blaze::StaticVector<double, 8> var40[16];
  blaze::StaticVector<double, 8> var41;
  blaze::StaticVector<double, 8> var42;
  blaze::StaticVector<double, 8> var46[16];
  blaze::StaticVector<double, 8> var49[16];
  blaze::StaticVector<double, 8> var52[16];
  blaze::StaticVector<double, 8> var55[16];
  blaze::StaticVector<double, 8> var58[16];
  blaze::StaticVector<double, 8> var61[16];
  blaze::StaticVector<double, 8> var64[17];
  blaze::StaticVector<double, 8> var65[17];
  blaze::StaticVector<double, 8> var66[17];
  double var67[17];
  AlignedSVd8Vector var68;
  AlignedSVd8Vector var69;
  AlignedSVd8Vector var70;
  std::vector<double> var71;
  var68.resize(5ll);
  var69.resize(5ll);
  var70.resize(5ll);
  var71.resize(5ll);
  AlignedSVd8Vector var72[17];
  AlignedSVd8Vector var73[17];
  AlignedSVd8Vector var74[17];
  std::vector<double> var75[17];
  blaze::StaticVector<double, 8> var76[16];
  var64[0ll] = ((1.0 * 0.0) + (0 * 0.0)) + (0 * 0.9144);
  var65[0ll] = ((0 * 0.0) + (1.0 * 0.0)) + (0 * 0.9144);
  var66[0ll] = ((0 * 0.0) + (0 * 0.0)) + (1.0 * 0.9144);
  var64[0ll] = var64[0ll] + 0;
  var65[0ll] = var65[0ll] + 0;
  var66[0ll] = var66[0ll] + 0;
  var67[0ll] = 0.08;
  var72[0ll] = var68;
  var73[0ll] = var69;
  var74[0ll] = var70;
  var75[0ll] = var71;
  blaze::StaticVector<double, 8> var80 = arg4[0ll];
  var26 = sin(var80);
  var27 = cos(var80);
  var25[0ll] = var27;
  var25[1ll] = var26;
  var25[2ll] = -(var26);
  var25[3ll] = var27;
  blaze::StaticVector<double, 8> var81;
  var81 = 0;
  var81 = var81 + (var25[0ll] * 0.000796326710733264);
  var81 = var81 + (var25[1ll] * -0.999999682931835);
  var81 = var81 + (0 * 0);
  var81 = var81 + (0 * 0);
  var76[0ll] = var81;
  blaze::StaticVector<double, 8> var82;
  var82 = 0;
  var82 = var82 + (var25[0ll] * 0.999999682931835);
  var82 = var82 + (var25[1ll] * 0.000796326710733264);
  var82 = var82 + (0 * 0);
  var82 = var82 + (0 * 0);
  var76[1ll] = var82;
  blaze::StaticVector<double, 8> var83;
  var83 = 0;
  var83 = var83 + (var25[2ll] * 0.000796326710733264);
  var83 = var83 + (var25[3ll] * -0.999999682931835);
  var83 = var83 + (0 * 0);
  var83 = var83 + (0 * 0);
  var76[2ll] = var83;
  blaze::StaticVector<double, 8> var84;
  var84 = 0;
  var84 = var84 + (var25[2ll] * 0.999999682931835);
  var84 = var84 + (var25[3ll] * 0.000796326710733264);
  var84 = var84 + (0 * 0);
  var84 = var84 + (0 * 0);
  var76[3ll] = var84;
  var46[0ll] = var76[0ll];
  var46[1ll] = var76[1ll];
  var46[2ll] = var76[2ll];
  var46[3ll] = var76[3ll];
  var64[1ll] = ((var46[0ll] * 0.0) + (var46[2ll] * 0.0)) + (0 * 0.0);
  var65[1ll] = ((var46[1ll] * 0.0) + (var46[3ll] * 0.0)) + (0 * 0.0);
  var66[1ll] = ((0 * 0.0) + (0 * 0.0)) + (1.0 * 0.0);
  var64[1ll] = var64[1ll] + 0;
  var65[1ll] = var65[1ll] + 0;
  var66[1ll] = var66[1ll] + 0;
  var67[1ll] = 0.08;
  var72[1ll] = var68;
  var73[1ll] = var69;
  var74[1ll] = var70;
  var75[1ll] = var71;
  blaze::StaticVector<double, 8> var86 = arg4[1ll];
  var29 = sin(var86);
  var30 = cos(var86);
  var28[0ll] = var30;
  var28[1ll] = -(var29);
  var28[2ll] = var29;
  var28[3ll] = var30;
  blaze::StaticVector<double, 8> var87;
  var87 = 0;
  var87 = var87 + (var28[0ll] * 0);
  var87 = var87 + (0 * 0);
  var87 = var87 + (var28[1ll] * 1.0);
  var87 = var87 + (0 * 0);
  var76[0ll] = var87;
  blaze::StaticVector<double, 8> var88;
  var88 = 0;
  var88 = var88 + (var28[0ll] * -1.0);
  var88 = var88 + (0 * 0);
  var88 = var88 + (var28[1ll] * 0);
  var88 = var88 + (0 * 0);
  var76[1ll] = var88;
  blaze::StaticVector<double, 8> var89;
  var89 = 0;
  var89 = var89 + (var28[2ll] * 0);
  var89 = var89 + (0 * 0);
  var89 = var89 + (var28[3ll] * 1.0);
  var89 = var89 + (0 * 0);
  var76[2ll] = var89;
  blaze::StaticVector<double, 8> var90;
  var90 = 0;
  var90 = var90 + (var28[2ll] * -1.0);
  var90 = var90 + (0 * 0);
  var90 = var90 + (var28[3ll] * 0);
  var90 = var90 + (0 * 0);
  var76[3ll] = var90;
  blaze::StaticVector<double, 8> var91;
  var91 = 0;
  var91 = var91 + (var76[0ll] * var46[0ll]);
  var91 = var91 + (0 * var46[2ll]);
  var91 = var91 + (var76[1ll] * 0);
  var91 = var91 + (0 * 0);
  var49[0ll] = var91;
  blaze::StaticVector<double, 8> var92;
  var92 = 0;
  var92 = var92 + (var76[0ll] * var46[1ll]);
  var92 = var92 + (0 * var46[3ll]);
  var92 = var92 + (var76[1ll] * 0);
  var92 = var92 + (0 * 0);
  var49[1ll] = var92;
  blaze::StaticVector<double, 8> var93;
  var93 = 0;
  var93 = var93 + (var76[0ll] * 0);
  var93 = var93 + (0 * 0);
  var93 = var93 + (var76[1ll] * 1.0);
  var93 = var93 + (0 * 1.003559);
  var49[2ll] = var93;
  blaze::StaticVector<double, 8> var94;
  var94 = 0;
  var94 = var94 + (0 * var46[0ll]);
  var94 = var94 + (1.0 * var46[2ll]);
  var94 = var94 + (0 * 0);
  var94 = var94 + (0 * 0);
  var49[3ll] = var94;
  blaze::StaticVector<double, 8> var95;
  var95 = 0;
  var95 = var95 + (0 * var46[1ll]);
  var95 = var95 + (1.0 * var46[3ll]);
  var95 = var95 + (0 * 0);
  var95 = var95 + (0 * 0);
  var49[4ll] = var95;
  blaze::StaticVector<double, 8> var96;
  var96 = 0;
  var96 = var96 + (var76[2ll] * var46[0ll]);
  var96 = var96 + (0 * var46[2ll]);
  var96 = var96 + (var76[3ll] * 0);
  var96 = var96 + (0 * 0);
  var49[5ll] = var96;
  blaze::StaticVector<double, 8> var97;
  var97 = 0;
  var97 = var97 + (var76[2ll] * var46[1ll]);
  var97 = var97 + (0 * var46[3ll]);
  var97 = var97 + (var76[3ll] * 0);
  var97 = var97 + (0 * 0);
  var49[6ll] = var97;
  blaze::StaticVector<double, 8> var98;
  var98 = 0;
  var98 = var98 + (var76[2ll] * 0);
  var98 = var98 + (0 * 0);
  var98 = var98 + (var76[3ll] * 1.0);
  var98 = var98 + (0 * 1.003559);
  var49[7ll] = var98;
  blaze::StaticVector<double, 8> var99;
  var99 = 0;
  var99 = var99 + (0 * var46[0ll]);
  var99 = var99 + (0.13585 * var46[2ll]);
  var99 = var99 + (0 * 0);
  var99 = var99 + (1.0 * 0);
  var49[8ll] = var99;
  blaze::StaticVector<double, 8> var100;
  var100 = 0;
  var100 = var100 + (0 * var46[1ll]);
  var100 = var100 + (0.13585 * var46[3ll]);
  var100 = var100 + (0 * 0);
  var100 = var100 + (1.0 * 0);
  var49[9ll] = var100;
  var64[2ll] = ((var49[0ll] * 0.0) + (var49[3ll] * 0.0)) + (var49[5ll] * 0.21);
  var65[2ll] = ((var49[1ll] * 0.0) + (var49[4ll] * 0.0)) + (var49[6ll] * 0.21);
  var66[2ll] = ((var49[2ll] * 0.0) + (0 * 0.0)) + (var49[7ll] * 0.21);
  var64[2ll] = var64[2ll] + 0;
  var65[2ll] = var65[2ll] + 0;
  var66[2ll] = var66[2ll] + 0;
  var67[2ll] = 0.29;
  var68[0ll] = ((var49[0ll] * 0.0) + (var49[3ll] * 0.0)) + (var49[5ll] * 0.105);
  var69[0ll] = ((var49[1ll] * 0.0) + (var49[4ll] * 0.0)) + (var49[6ll] * 0.105);
  var70[0ll] = ((var49[2ll] * 0.0) + (0 * 0.0)) + (var49[7ll] * 0.105);
  var68[0ll] = var68[0ll] + 0;
  var69[0ll] = var69[0ll] + 0;
  var70[0ll] = var70[0ll] + 0;
  var71[0ll] = 0.08;
  var68[1ll] = ((var49[0ll] * 0.0) + (var49[3ll] * 0.0)) + (var49[5ll] * 0.21);
  var69[1ll] = ((var49[1ll] * 0.0) + (var49[4ll] * 0.0)) + (var49[6ll] * 0.21);
  var70[1ll] = ((var49[2ll] * 0.0) + (0 * 0.0)) + (var49[7ll] * 0.21);
  var68[1ll] = var68[1ll] + 0;
  var69[1ll] = var69[1ll] + 0;
  var70[1ll] = var70[1ll] + 0;
  var71[1ll] = 0.08;
  var68[2ll] = ((var49[0ll] * 0.0) + (var49[3ll] * 0.0)) + (var49[5ll] * 0.315);
  var69[2ll] = ((var49[1ll] * 0.0) + (var49[4ll] * 0.0)) + (var49[6ll] * 0.315);
  var70[2ll] = ((var49[2ll] * 0.0) + (0 * 0.0)) + (var49[7ll] * 0.315);
  var68[2ll] = var68[2ll] + 0;
  var69[2ll] = var69[2ll] + 0;
  var70[2ll] = var70[2ll] + 0;
  var71[2ll] = 0.08;
  var68[3ll] = ((var49[0ll] * 0.0) + (var49[3ll] * 0.0)) + (var49[5ll] * 0.42);
  var69[3ll] = ((var49[1ll] * 0.0) + (var49[4ll] * 0.0)) + (var49[6ll] * 0.42);
  var70[3ll] = ((var49[2ll] * 0.0) + (0 * 0.0)) + (var49[7ll] * 0.42);
  var68[3ll] = var68[3ll] + 0;
  var69[3ll] = var69[3ll] + 0;
  var70[3ll] = var70[3ll] + 0;
  var71[3ll] = 0.08;
  var68[4ll] = ((var49[0ll] * 0.0) + (var49[3ll] * 0.0)) + (var49[5ll] * 0.0);
  var69[4ll] = ((var49[1ll] * 0.0) + (var49[4ll] * 0.0)) + (var49[6ll] * 0.0);
  var70[4ll] = ((var49[2ll] * 0.0) + (0 * 0.0)) + (var49[7ll] * 0.0);
  var68[4ll] = var68[4ll] + 0;
  var69[4ll] = var69[4ll] + 0;
  var70[4ll] = var70[4ll] + 0;
  var71[4ll] = 0.08;
  int var101;
  var101 = runtime::self_collision_link_vs_link(var64[2ll], var65[2ll], var66[2ll], var67[2ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var101)
    return 1; //collision pair: 0,2
  var72[2ll] = var68;
  var73[2ll] = var69;
  var74[2ll] = var70;
  var75[2ll] = var71;
  blaze::StaticVector<double, 8> var102 = arg4[2ll];
  var32 = sin(var102);
  var33 = cos(var102);
  var31[0ll] = var33;
  var31[1ll] = -(var32);
  var31[2ll] = var32;
  var31[3ll] = var33;
  blaze::StaticVector<double, 8> var103;
  var103 = 0;
  var103 = var103 + (var31[0ll] * 1.0);
  var103 = var103 + (0 * 0);
  var103 = var103 + (var31[1ll] * 0);
  var103 = var103 + (0 * 0);
  var76[0ll] = var103;
  blaze::StaticVector<double, 8> var104;
  var104 = 0;
  var104 = var104 + (var31[0ll] * 0);
  var104 = var104 + (0 * 0);
  var104 = var104 + (var31[1ll] * 1.0);
  var104 = var104 + (0 * 0.425);
  var76[1ll] = var104;
  blaze::StaticVector<double, 8> var105;
  var105 = 0;
  var105 = var105 + (var31[2ll] * 1.0);
  var105 = var105 + (0 * 0);
  var105 = var105 + (var31[3ll] * 0);
  var105 = var105 + (0 * 0);
  var76[2ll] = var105;
  blaze::StaticVector<double, 8> var106;
  var106 = 0;
  var106 = var106 + (var31[2ll] * 0);
  var106 = var106 + (0 * 0);
  var106 = var106 + (var31[3ll] * 1.0);
  var106 = var106 + (0 * 0.425);
  var76[3ll] = var106;
  blaze::StaticVector<double, 8> var107;
  var107 = 0;
  var107 = var107 + (var76[0ll] * var49[0ll]);
  var107 = var107 + (0 * var49[3ll]);
  var107 = var107 + (var76[1ll] * var49[5ll]);
  var107 = var107 + (0 * var49[8ll]);
  var52[0ll] = var107;
  blaze::StaticVector<double, 8> var108;
  var108 = 0;
  var108 = var108 + (var76[0ll] * var49[1ll]);
  var108 = var108 + (0 * var49[4ll]);
  var108 = var108 + (var76[1ll] * var49[6ll]);
  var108 = var108 + (0 * var49[9ll]);
  var52[1ll] = var108;
  blaze::StaticVector<double, 8> var109;
  var109 = 0;
  var109 = var109 + (var76[0ll] * var49[2ll]);
  var109 = var109 + (0 * 0);
  var109 = var109 + (var76[1ll] * var49[7ll]);
  var109 = var109 + (0 * 1.003559);
  var52[2ll] = var109;
  blaze::StaticVector<double, 8> var110;
  var110 = 0;
  var110 = var110 + (0 * var49[0ll]);
  var110 = var110 + (1.0 * var49[3ll]);
  var110 = var110 + (0 * var49[5ll]);
  var110 = var110 + (0 * var49[8ll]);
  var52[3ll] = var110;
  blaze::StaticVector<double, 8> var111;
  var111 = 0;
  var111 = var111 + (0 * var49[1ll]);
  var111 = var111 + (1.0 * var49[4ll]);
  var111 = var111 + (0 * var49[6ll]);
  var111 = var111 + (0 * var49[9ll]);
  var52[4ll] = var111;
  blaze::StaticVector<double, 8> var112;
  var112 = 0;
  var112 = var112 + (var76[2ll] * var49[0ll]);
  var112 = var112 + (0 * var49[3ll]);
  var112 = var112 + (var76[3ll] * var49[5ll]);
  var112 = var112 + (0 * var49[8ll]);
  var52[5ll] = var112;
  blaze::StaticVector<double, 8> var113;
  var113 = 0;
  var113 = var113 + (var76[2ll] * var49[1ll]);
  var113 = var113 + (0 * var49[4ll]);
  var113 = var113 + (var76[3ll] * var49[6ll]);
  var113 = var113 + (0 * var49[9ll]);
  var52[6ll] = var113;
  blaze::StaticVector<double, 8> var114;
  var114 = 0;
  var114 = var114 + (var76[2ll] * var49[2ll]);
  var114 = var114 + (0 * 0);
  var114 = var114 + (var76[3ll] * var49[7ll]);
  var114 = var114 + (0 * 1.003559);
  var52[7ll] = var114;
  blaze::StaticVector<double, 8> var115;
  var115 = 0;
  var115 = var115 + (0 * var49[0ll]);
  var115 = var115 + (-0.1197 * var49[3ll]);
  var115 = var115 + (0.425 * var49[5ll]);
  var115 = var115 + (1.0 * var49[8ll]);
  var52[8ll] = var115;
  blaze::StaticVector<double, 8> var116;
  var116 = 0;
  var116 = var116 + (0 * var49[1ll]);
  var116 = var116 + (-0.1197 * var49[4ll]);
  var116 = var116 + (0.425 * var49[6ll]);
  var116 = var116 + (1.0 * var49[9ll]);
  var52[9ll] = var116;
  blaze::StaticVector<double, 8> var117;
  var117 = 0;
  var117 = var117 + (0 * var49[2ll]);
  var117 = var117 + (-0.1197 * 0);
  var117 = var117 + (0.425 * var49[7ll]);
  var117 = var117 + (1.0 * 1.003559);
  var52[10ll] = var117;
  var64[3ll] = ((var52[0ll] * 0.002) + (var52[3ll] * 0.003)) + (var52[5ll] * 0.185);
  var65[3ll] = ((var52[1ll] * 0.002) + (var52[4ll] * 0.003)) + (var52[6ll] * 0.185);
  var66[3ll] = ((var52[2ll] * 0.002) + (0 * 0.003)) + (var52[7ll] * 0.185);
  var64[3ll] = var64[3ll] + 0;
  var65[3ll] = var65[3ll] + 0;
  var66[3ll] = var66[3ll] + 0;
  var67[3ll] = 0.265;
  var68[0ll] = ((var52[0ll] * 0.0) + (var52[3ll] * 0.0)) + (var52[5ll] * 0.0);
  var69[0ll] = ((var52[1ll] * 0.0) + (var52[4ll] * 0.0)) + (var52[6ll] * 0.0);
  var70[0ll] = ((var52[2ll] * 0.0) + (0 * 0.0)) + (var52[7ll] * 0.0);
  var68[0ll] = var68[0ll] + 0;
  var69[0ll] = var69[0ll] + 0;
  var70[0ll] = var70[0ll] + 0;
  var71[0ll] = 0.08;
  var68[1ll] = ((var52[0ll] * 0.0) + (var52[3ll] * 0.0)) + (var52[5ll] * 0.0975);
  var69[1ll] = ((var52[1ll] * 0.0) + (var52[4ll] * 0.0)) + (var52[6ll] * 0.0975);
  var70[1ll] = ((var52[2ll] * 0.0) + (0 * 0.0)) + (var52[7ll] * 0.0975);
  var68[1ll] = var68[1ll] + 0;
  var69[1ll] = var69[1ll] + 0;
  var70[1ll] = var70[1ll] + 0;
  var71[1ll] = 0.06;
  var68[2ll] = ((var52[0ll] * 0.0) + (var52[3ll] * 0.0)) + (var52[5ll] * 0.195);
  var69[2ll] = ((var52[1ll] * 0.0) + (var52[4ll] * 0.0)) + (var52[6ll] * 0.195);
  var70[2ll] = ((var52[2ll] * 0.0) + (0 * 0.0)) + (var52[7ll] * 0.195);
  var68[2ll] = var68[2ll] + 0;
  var69[2ll] = var69[2ll] + 0;
  var70[2ll] = var70[2ll] + 0;
  var71[2ll] = 0.06;
  var68[3ll] = ((var52[0ll] * 0.0) + (var52[3ll] * 0.0)) + (var52[5ll] * 0.2925);
  var69[3ll] = ((var52[1ll] * 0.0) + (var52[4ll] * 0.0)) + (var52[6ll] * 0.2925);
  var70[3ll] = ((var52[2ll] * 0.0) + (0 * 0.0)) + (var52[7ll] * 0.2925);
  var68[3ll] = var68[3ll] + 0;
  var69[3ll] = var69[3ll] + 0;
  var70[3ll] = var70[3ll] + 0;
  var71[3ll] = 0.06;
  var68[4ll] = ((var52[0ll] * 0.0) + (var52[3ll] * 0.0)) + (var52[5ll] * 0.39);
  var69[4ll] = ((var52[1ll] * 0.0) + (var52[4ll] * 0.0)) + (var52[6ll] * 0.39);
  var70[4ll] = ((var52[2ll] * 0.0) + (0 * 0.0)) + (var52[7ll] * 0.39);
  var68[4ll] = var68[4ll] + 0;
  var69[4ll] = var69[4ll] + 0;
  var70[4ll] = var70[4ll] + 0;
  var71[4ll] = 0.06;
  int var118;
  var118 = runtime::self_collision_link_vs_link(var64[3ll], var65[3ll], var66[3ll], var67[3ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var118)
    return 1; //collision pair: 0,3
  var118 = runtime::self_collision_link_vs_link(var64[3ll], var65[3ll], var66[3ll], var67[3ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var118)
    return 1; //collision pair: 1,3
  var72[3ll] = var68;
  var73[3ll] = var69;
  var74[3ll] = var70;
  var75[3ll] = var71;
  blaze::StaticVector<double, 8> var119 = arg4[3ll];
  var35 = sin(var119);
  var36 = cos(var119);
  var34[0ll] = var36;
  var34[1ll] = -(var35);
  var34[2ll] = var35;
  var34[3ll] = var36;
  blaze::StaticVector<double, 8> var120;
  var120 = 0;
  var120 = var120 + (var34[0ll] * 0);
  var120 = var120 + (0 * 0);
  var120 = var120 + (var34[1ll] * 1.0);
  var120 = var120 + (0 * 0);
  var76[0ll] = var120;
  blaze::StaticVector<double, 8> var121;
  var121 = 0;
  var121 = var121 + (var34[0ll] * -1.0);
  var121 = var121 + (0 * 0);
  var121 = var121 + (var34[1ll] * 0);
  var121 = var121 + (0 * 0.39225);
  var76[1ll] = var121;
  blaze::StaticVector<double, 8> var122;
  var122 = 0;
  var122 = var122 + (var34[2ll] * 0);
  var122 = var122 + (0 * 0);
  var122 = var122 + (var34[3ll] * 1.0);
  var122 = var122 + (0 * 0);
  var76[2ll] = var122;
  blaze::StaticVector<double, 8> var123;
  var123 = 0;
  var123 = var123 + (var34[2ll] * -1.0);
  var123 = var123 + (0 * 0);
  var123 = var123 + (var34[3ll] * 0);
  var123 = var123 + (0 * 0.39225);
  var76[3ll] = var123;
  blaze::StaticVector<double, 8> var124;
  var124 = 0;
  var124 = var124 + (var76[0ll] * var52[0ll]);
  var124 = var124 + (0 * var52[3ll]);
  var124 = var124 + (var76[1ll] * var52[5ll]);
  var124 = var124 + (0 * var52[8ll]);
  var55[0ll] = var124;
  blaze::StaticVector<double, 8> var125;
  var125 = 0;
  var125 = var125 + (var76[0ll] * var52[1ll]);
  var125 = var125 + (0 * var52[4ll]);
  var125 = var125 + (var76[1ll] * var52[6ll]);
  var125 = var125 + (0 * var52[9ll]);
  var55[1ll] = var125;
  blaze::StaticVector<double, 8> var126;
  var126 = 0;
  var126 = var126 + (var76[0ll] * var52[2ll]);
  var126 = var126 + (0 * 0);
  var126 = var126 + (var76[1ll] * var52[7ll]);
  var126 = var126 + (0 * var52[10ll]);
  var55[2ll] = var126;
  blaze::StaticVector<double, 8> var127;
  var127 = 0;
  var127 = var127 + (0 * var52[0ll]);
  var127 = var127 + (1.0 * var52[3ll]);
  var127 = var127 + (0 * var52[5ll]);
  var127 = var127 + (0 * var52[8ll]);
  var55[3ll] = var127;
  blaze::StaticVector<double, 8> var128;
  var128 = 0;
  var128 = var128 + (0 * var52[1ll]);
  var128 = var128 + (1.0 * var52[4ll]);
  var128 = var128 + (0 * var52[6ll]);
  var128 = var128 + (0 * var52[9ll]);
  var55[4ll] = var128;
  blaze::StaticVector<double, 8> var129;
  var129 = 0;
  var129 = var129 + (var76[2ll] * var52[0ll]);
  var129 = var129 + (0 * var52[3ll]);
  var129 = var129 + (var76[3ll] * var52[5ll]);
  var129 = var129 + (0 * var52[8ll]);
  var55[5ll] = var129;
  blaze::StaticVector<double, 8> var130;
  var130 = 0;
  var130 = var130 + (var76[2ll] * var52[1ll]);
  var130 = var130 + (0 * var52[4ll]);
  var130 = var130 + (var76[3ll] * var52[6ll]);
  var130 = var130 + (0 * var52[9ll]);
  var55[6ll] = var130;
  blaze::StaticVector<double, 8> var131;
  var131 = 0;
  var131 = var131 + (var76[2ll] * var52[2ll]);
  var131 = var131 + (0 * 0);
  var131 = var131 + (var76[3ll] * var52[7ll]);
  var131 = var131 + (0 * var52[10ll]);
  var55[7ll] = var131;
  blaze::StaticVector<double, 8> var132;
  var132 = 0;
  var132 = var132 + (0 * var52[0ll]);
  var132 = var132 + (0 * var52[3ll]);
  var132 = var132 + (0.39225 * var52[5ll]);
  var132 = var132 + (1.0 * var52[8ll]);
  var55[8ll] = var132;
  blaze::StaticVector<double, 8> var133;
  var133 = 0;
  var133 = var133 + (0 * var52[1ll]);
  var133 = var133 + (0 * var52[4ll]);
  var133 = var133 + (0.39225 * var52[6ll]);
  var133 = var133 + (1.0 * var52[9ll]);
  var55[9ll] = var133;
  blaze::StaticVector<double, 8> var134;
  var134 = 0;
  var134 = var134 + (0 * var52[2ll]);
  var134 = var134 + (0 * 0);
  var134 = var134 + (0.39225 * var52[7ll]);
  var134 = var134 + (1.0 * var52[10ll]);
  var55[10ll] = var134;
  var64[4ll] = ((var55[0ll] * 0.0) + (var55[3ll] * 0.09)) + (var55[5ll] * 0.0);
  var65[4ll] = ((var55[1ll] * 0.0) + (var55[4ll] * 0.09)) + (var55[6ll] * 0.0);
  var66[4ll] = ((var55[2ll] * 0.0) + (0 * 0.09)) + (var55[7ll] * 0.0);
  var64[4ll] = var64[4ll] + 0;
  var65[4ll] = var65[4ll] + 0;
  var66[4ll] = var66[4ll] + 0;
  var67[4ll] = 0.07;
  var68[0ll] = ((var55[0ll] * 0.0) + (var55[3ll] * 0.09)) + (var55[5ll] * 0.03);
  var69[0ll] = ((var55[1ll] * 0.0) + (var55[4ll] * 0.09)) + (var55[6ll] * 0.03);
  var70[0ll] = ((var55[2ll] * 0.0) + (0 * 0.09)) + (var55[7ll] * 0.03);
  var68[0ll] = var68[0ll] + 0;
  var69[0ll] = var69[0ll] + 0;
  var70[0ll] = var70[0ll] + 0;
  var71[0ll] = 0.04;
  var68[1ll] = ((var55[0ll] * 0.0) + (var55[3ll] * 0.09)) + (var55[5ll] * -0.03);
  var69[1ll] = ((var55[1ll] * 0.0) + (var55[4ll] * 0.09)) + (var55[6ll] * -0.03);
  var70[1ll] = ((var55[2ll] * 0.0) + (0 * 0.09)) + (var55[7ll] * -0.03);
  var68[1ll] = var68[1ll] + 0;
  var69[1ll] = var69[1ll] + 0;
  var70[1ll] = var70[1ll] + 0;
  var71[1ll] = 0.04;
  var68[2ll] = ((var55[0ll] * 0.0) + (var55[3ll] * 0.09)) + (var55[5ll] * 0.0);
  var69[2ll] = ((var55[1ll] * 0.0) + (var55[4ll] * 0.09)) + (var55[6ll] * 0.0);
  var70[2ll] = ((var55[2ll] * 0.0) + (0 * 0.09)) + (var55[7ll] * 0.0);
  var68[2ll] = var68[2ll] + 0;
  var69[2ll] = var69[2ll] + 0;
  var70[2ll] = var70[2ll] + 0;
  var71[2ll] = 0.04;
  int var135;
  var135 = runtime::self_collision_link_vs_link(var64[4ll], var65[4ll], var66[4ll], var67[4ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var135)
    return 1; //collision pair: 0,4
  var135 = runtime::self_collision_link_vs_link(var64[4ll], var65[4ll], var66[4ll], var67[4ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var135)
    return 1; //collision pair: 1,4
  var135 = runtime::self_collision_link_vs_link(var64[4ll], var65[4ll], var66[4ll], var67[4ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var135)
    return 1; //collision pair: 2,4
  var72[4ll] = var68;
  var73[4ll] = var69;
  var74[4ll] = var70;
  var75[4ll] = var71;
  blaze::StaticVector<double, 8> var136 = arg4[4ll];
  var38 = sin(var136);
  var39 = cos(var136);
  var37[0ll] = var39;
  var37[1ll] = var38;
  var37[2ll] = -(var38);
  var37[3ll] = var39;
  blaze::StaticVector<double, 8> var137;
  var137 = 0;
  var137 = var137 + (var37[0ll] * 1.0);
  var137 = var137 + (var37[1ll] * 0);
  var137 = var137 + (0 * 0);
  var137 = var137 + (0 * 0);
  var76[0ll] = var137;
  blaze::StaticVector<double, 8> var138;
  var138 = 0;
  var138 = var138 + (var37[0ll] * 0);
  var138 = var138 + (var37[1ll] * 1.0);
  var138 = var138 + (0 * 0);
  var138 = var138 + (0 * 0.093);
  var76[4ll] = var138;
  blaze::StaticVector<double, 8> var139;
  var139 = 0;
  var139 = var139 + (var37[2ll] * 1.0);
  var139 = var139 + (var37[3ll] * 0);
  var139 = var139 + (0 * 0);
  var139 = var139 + (0 * 0);
  var76[1ll] = var139;
  blaze::StaticVector<double, 8> var140;
  var140 = 0;
  var140 = var140 + (var37[2ll] * 0);
  var140 = var140 + (var37[3ll] * 1.0);
  var140 = var140 + (0 * 0);
  var140 = var140 + (0 * 0.093);
  var76[5ll] = var140;
  blaze::StaticVector<double, 8> var141;
  var141 = 0;
  var141 = var141 + (var76[0ll] * var55[0ll]);
  var141 = var141 + (var76[4ll] * var55[3ll]);
  var141 = var141 + (0 * var55[5ll]);
  var141 = var141 + (0 * var55[8ll]);
  var58[0ll] = var141;
  blaze::StaticVector<double, 8> var142;
  var142 = 0;
  var142 = var142 + (var76[0ll] * var55[1ll]);
  var142 = var142 + (var76[4ll] * var55[4ll]);
  var142 = var142 + (0 * var55[6ll]);
  var142 = var142 + (0 * var55[9ll]);
  var58[1ll] = var142;
  blaze::StaticVector<double, 8> var143;
  var143 = 0;
  var143 = var143 + (var76[0ll] * var55[2ll]);
  var143 = var143 + (var76[4ll] * 0);
  var143 = var143 + (0 * var55[7ll]);
  var143 = var143 + (0 * var55[10ll]);
  var58[2ll] = var143;
  blaze::StaticVector<double, 8> var144;
  var144 = 0;
  var144 = var144 + (var76[1ll] * var55[0ll]);
  var144 = var144 + (var76[5ll] * var55[3ll]);
  var144 = var144 + (0 * var55[5ll]);
  var144 = var144 + (0 * var55[8ll]);
  var58[3ll] = var144;
  blaze::StaticVector<double, 8> var145;
  var145 = 0;
  var145 = var145 + (var76[1ll] * var55[1ll]);
  var145 = var145 + (var76[5ll] * var55[4ll]);
  var145 = var145 + (0 * var55[6ll]);
  var145 = var145 + (0 * var55[9ll]);
  var58[4ll] = var145;
  blaze::StaticVector<double, 8> var146;
  var146 = 0;
  var146 = var146 + (var76[1ll] * var55[2ll]);
  var146 = var146 + (var76[5ll] * 0);
  var146 = var146 + (0 * var55[7ll]);
  var146 = var146 + (0 * var55[10ll]);
  var58[5ll] = var146;
  blaze::StaticVector<double, 8> var147;
  var147 = 0;
  var147 = var147 + (0 * var55[0ll]);
  var147 = var147 + (0 * var55[3ll]);
  var147 = var147 + (1.0 * var55[5ll]);
  var147 = var147 + (0 * var55[8ll]);
  var58[6ll] = var147;
  blaze::StaticVector<double, 8> var148;
  var148 = 0;
  var148 = var148 + (0 * var55[1ll]);
  var148 = var148 + (0 * var55[4ll]);
  var148 = var148 + (1.0 * var55[6ll]);
  var148 = var148 + (0 * var55[9ll]);
  var58[7ll] = var148;
  blaze::StaticVector<double, 8> var149;
  var149 = 0;
  var149 = var149 + (0 * var55[2ll]);
  var149 = var149 + (0 * 0);
  var149 = var149 + (1.0 * var55[7ll]);
  var149 = var149 + (0 * var55[10ll]);
  var58[8ll] = var149;
  blaze::StaticVector<double, 8> var150;
  var150 = 0;
  var150 = var150 + (0 * var55[0ll]);
  var150 = var150 + (0.093 * var55[3ll]);
  var150 = var150 + (0 * var55[5ll]);
  var150 = var150 + (1.0 * var55[8ll]);
  var58[9ll] = var150;
  blaze::StaticVector<double, 8> var151;
  var151 = 0;
  var151 = var151 + (0 * var55[1ll]);
  var151 = var151 + (0.093 * var55[4ll]);
  var151 = var151 + (0 * var55[6ll]);
  var151 = var151 + (1.0 * var55[9ll]);
  var58[10ll] = var151;
  blaze::StaticVector<double, 8> var152;
  var152 = 0;
  var152 = var152 + (0 * var55[2ll]);
  var152 = var152 + (0.093 * 0);
  var152 = var152 + (0 * var55[7ll]);
  var152 = var152 + (1.0 * var55[10ll]);
  var58[11ll] = var152;
  var64[5ll] = ((var58[0ll] * 0.0) + (var58[3ll] * 0.0)) + (var58[6ll] * 0.09);
  var65[5ll] = ((var58[1ll] * 0.0) + (var58[4ll] * 0.0)) + (var58[7ll] * 0.09);
  var66[5ll] = ((var58[2ll] * 0.0) + (var58[5ll] * 0.0)) + (var58[8ll] * 0.09);
  var64[5ll] = var64[5ll] + 0;
  var65[5ll] = var65[5ll] + 0;
  var66[5ll] = var66[5ll] + 0;
  var67[5ll] = 0.07;
  var68[0ll] = ((var58[0ll] * 0.0) + (var58[3ll] * 0.03)) + (var58[6ll] * 0.09);
  var69[0ll] = ((var58[1ll] * 0.0) + (var58[4ll] * 0.03)) + (var58[7ll] * 0.09);
  var70[0ll] = ((var58[2ll] * 0.0) + (var58[5ll] * 0.03)) + (var58[8ll] * 0.09);
  var68[0ll] = var68[0ll] + 0;
  var69[0ll] = var69[0ll] + 0;
  var70[0ll] = var70[0ll] + 0;
  var71[0ll] = 0.04;
  var68[1ll] = ((var58[0ll] * 0.0) + (var58[3ll] * -0.03)) + (var58[6ll] * 0.09);
  var69[1ll] = ((var58[1ll] * 0.0) + (var58[4ll] * -0.03)) + (var58[7ll] * 0.09);
  var70[1ll] = ((var58[2ll] * 0.0) + (var58[5ll] * -0.03)) + (var58[8ll] * 0.09);
  var68[1ll] = var68[1ll] + 0;
  var69[1ll] = var69[1ll] + 0;
  var70[1ll] = var70[1ll] + 0;
  var71[1ll] = 0.04;
  var68[2ll] = ((var58[0ll] * 0.0) + (var58[3ll] * 0.0)) + (var58[6ll] * 0.09);
  var69[2ll] = ((var58[1ll] * 0.0) + (var58[4ll] * 0.0)) + (var58[7ll] * 0.09);
  var70[2ll] = ((var58[2ll] * 0.0) + (var58[5ll] * 0.0)) + (var58[8ll] * 0.09);
  var68[2ll] = var68[2ll] + 0;
  var69[2ll] = var69[2ll] + 0;
  var70[2ll] = var70[2ll] + 0;
  var71[2ll] = 0.04;
  int var153;
  var153 = runtime::self_collision_link_vs_link(var64[5ll], var65[5ll], var66[5ll], var67[5ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var153)
    return 1; //collision pair: 0,5
  var153 = runtime::self_collision_link_vs_link(var64[5ll], var65[5ll], var66[5ll], var67[5ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var153)
    return 1; //collision pair: 1,5
  var153 = runtime::self_collision_link_vs_link(var64[5ll], var65[5ll], var66[5ll], var67[5ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var153)
    return 1; //collision pair: 2,5
  var153 = runtime::self_collision_link_vs_link(var64[5ll], var65[5ll], var66[5ll], var67[5ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var153)
    return 1; //collision pair: 3,5
  var72[5ll] = var68;
  var73[5ll] = var69;
  var74[5ll] = var70;
  var75[5ll] = var71;
  blaze::StaticVector<double, 8> var154 = arg4[5ll];
  var41 = sin(var154);
  var42 = cos(var154);
  var40[0ll] = var42;
  var40[1ll] = -(var41);
  var40[2ll] = var41;
  var40[3ll] = var42;
  blaze::StaticVector<double, 8> var155;
  var155 = 0;
  var155 = var155 + (var40[0ll] * 1.0);
  var155 = var155 + (0 * 0);
  var155 = var155 + (var40[1ll] * 0);
  var155 = var155 + (0 * 0);
  var76[0ll] = var155;
  blaze::StaticVector<double, 8> var156;
  var156 = 0;
  var156 = var156 + (var40[0ll] * 0);
  var156 = var156 + (0 * 0);
  var156 = var156 + (var40[1ll] * 1.0);
  var156 = var156 + (0 * 0.09465);
  var76[2ll] = var156;
  blaze::StaticVector<double, 8> var157;
  var157 = 0;
  var157 = var157 + (var40[2ll] * 1.0);
  var157 = var157 + (0 * 0);
  var157 = var157 + (var40[3ll] * 0);
  var157 = var157 + (0 * 0);
  var76[3ll] = var157;
  blaze::StaticVector<double, 8> var158;
  var158 = 0;
  var158 = var158 + (var40[2ll] * 0);
  var158 = var158 + (0 * 0);
  var158 = var158 + (var40[3ll] * 1.0);
  var158 = var158 + (0 * 0.09465);
  var76[4ll] = var158;
  blaze::StaticVector<double, 8> var159;
  var159 = 0;
  var159 = var159 + (var76[0ll] * var58[0ll]);
  var159 = var159 + (0 * var58[3ll]);
  var159 = var159 + (var76[2ll] * var58[6ll]);
  var159 = var159 + (0 * var58[9ll]);
  var61[0ll] = var159;
  blaze::StaticVector<double, 8> var160;
  var160 = 0;
  var160 = var160 + (var76[0ll] * var58[1ll]);
  var160 = var160 + (0 * var58[4ll]);
  var160 = var160 + (var76[2ll] * var58[7ll]);
  var160 = var160 + (0 * var58[10ll]);
  var61[1ll] = var160;
  blaze::StaticVector<double, 8> var161;
  var161 = 0;
  var161 = var161 + (var76[0ll] * var58[2ll]);
  var161 = var161 + (0 * var58[5ll]);
  var161 = var161 + (var76[2ll] * var58[8ll]);
  var161 = var161 + (0 * var58[11ll]);
  var61[2ll] = var161;
  blaze::StaticVector<double, 8> var162;
  var162 = 0;
  var162 = var162 + (0 * var58[0ll]);
  var162 = var162 + (1.0 * var58[3ll]);
  var162 = var162 + (0 * var58[6ll]);
  var162 = var162 + (0 * var58[9ll]);
  var61[3ll] = var162;
  blaze::StaticVector<double, 8> var163;
  var163 = 0;
  var163 = var163 + (0 * var58[1ll]);
  var163 = var163 + (1.0 * var58[4ll]);
  var163 = var163 + (0 * var58[7ll]);
  var163 = var163 + (0 * var58[10ll]);
  var61[4ll] = var163;
  blaze::StaticVector<double, 8> var164;
  var164 = 0;
  var164 = var164 + (0 * var58[2ll]);
  var164 = var164 + (1.0 * var58[5ll]);
  var164 = var164 + (0 * var58[8ll]);
  var164 = var164 + (0 * var58[11ll]);
  var61[5ll] = var164;
  blaze::StaticVector<double, 8> var165;
  var165 = 0;
  var165 = var165 + (var76[3ll] * var58[0ll]);
  var165 = var165 + (0 * var58[3ll]);
  var165 = var165 + (var76[4ll] * var58[6ll]);
  var165 = var165 + (0 * var58[9ll]);
  var61[6ll] = var165;
  blaze::StaticVector<double, 8> var166;
  var166 = 0;
  var166 = var166 + (var76[3ll] * var58[1ll]);
  var166 = var166 + (0 * var58[4ll]);
  var166 = var166 + (var76[4ll] * var58[7ll]);
  var166 = var166 + (0 * var58[10ll]);
  var61[7ll] = var166;
  blaze::StaticVector<double, 8> var167;
  var167 = 0;
  var167 = var167 + (var76[3ll] * var58[2ll]);
  var167 = var167 + (0 * var58[5ll]);
  var167 = var167 + (var76[4ll] * var58[8ll]);
  var167 = var167 + (0 * var58[11ll]);
  var61[8ll] = var167;
  blaze::StaticVector<double, 8> var168;
  var168 = 0;
  var168 = var168 + (0 * var58[0ll]);
  var168 = var168 + (0 * var58[3ll]);
  var168 = var168 + (0.09465 * var58[6ll]);
  var168 = var168 + (1.0 * var58[9ll]);
  var61[9ll] = var168;
  blaze::StaticVector<double, 8> var169;
  var169 = 0;
  var169 = var169 + (0 * var58[1ll]);
  var169 = var169 + (0 * var58[4ll]);
  var169 = var169 + (0.09465 * var58[7ll]);
  var169 = var169 + (1.0 * var58[10ll]);
  var61[10ll] = var169;
  blaze::StaticVector<double, 8> var170;
  var170 = 0;
  var170 = var170 + (0 * var58[2ll]);
  var170 = var170 + (0 * var58[5ll]);
  var170 = var170 + (0.09465 * var58[8ll]);
  var170 = var170 + (1.0 * var58[11ll]);
  var61[11ll] = var170;
  var64[6ll] = ((var61[0ll] * 0.0) + (var61[3ll] * 0.06)) + (var61[6ll] * 0.0);
  var65[6ll] = ((var61[1ll] * 0.0) + (var61[4ll] * 0.06)) + (var61[7ll] * 0.0);
  var66[6ll] = ((var61[2ll] * 0.0) + (var61[5ll] * 0.06)) + (var61[8ll] * 0.0);
  var64[6ll] = var64[6ll] + 0;
  var65[6ll] = var65[6ll] + 0;
  var66[6ll] = var66[6ll] + 0;
  var67[6ll] = 0.04;
  int var171;
  var171 = runtime::self_collision_link_vs_link(var64[6ll], var65[6ll], var66[6ll], var67[6ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var171)
    return 1; //collision pair: 0,6
  var171 = runtime::self_collision_link_vs_link(var64[6ll], var65[6ll], var66[6ll], var67[6ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var171)
    return 1; //collision pair: 1,6
  var171 = runtime::self_collision_link_vs_link(var64[6ll], var65[6ll], var66[6ll], var67[6ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var171)
    return 1; //collision pair: 2,6
  var171 = runtime::self_collision_link_vs_link(var64[6ll], var65[6ll], var66[6ll], var67[6ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var171)
    return 1; //collision pair: 3,6
  var72[6ll] = var68;
  var73[6ll] = var69;
  var74[6ll] = var70;
  var75[6ll] = var71;
  var64[7ll] = ((var61[0ll] * 1.59265611381251e-05) + (var61[3ll] * 0.0973000063413347)) + (var61[6ll] * 0.0);
  var65[7ll] = ((var61[1ll] * 1.59265611381251e-05) + (var61[4ll] * 0.0973000063413347)) + (var61[7ll] * 0.0);
  var66[7ll] = ((var61[2ll] * 1.59265611381251e-05) + (var61[5ll] * 0.0973000063413347)) + (var61[8ll] * 0.0);
  var64[7ll] = var64[7ll] + 0;
  var65[7ll] = var65[7ll] + 0;
  var66[7ll] = var66[7ll] + 0;
  var67[7ll] = 0.04;
  int var172;
  var172 = runtime::self_collision_link_vs_link(var64[7ll], var65[7ll], var66[7ll], var67[7ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var172)
    return 1; //collision pair: 0,7
  var172 = runtime::self_collision_link_vs_link(var64[7ll], var65[7ll], var66[7ll], var67[7ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var172)
    return 1; //collision pair: 1,7
  var172 = runtime::self_collision_link_vs_link(var64[7ll], var65[7ll], var66[7ll], var67[7ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var172)
    return 1; //collision pair: 2,7
  var172 = runtime::self_collision_link_vs_link(var64[7ll], var65[7ll], var66[7ll], var67[7ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var172)
    return 1; //collision pair: 3,7
  var172 = runtime::self_collision_link_vs_link(var64[7ll], var65[7ll], var66[7ll], var67[7ll], var68, var69, var70, var71, var64[4ll], var65[4ll], var66[4ll], var67[4ll], var72[4ll], var73[4ll], var74[4ll], var75[4ll]);
  if (var172)
    return 1; //collision pair: 4,7
  var172 = runtime::self_collision_link_vs_link(var64[7ll], var65[7ll], var66[7ll], var67[7ll], var68, var69, var70, var71, var64[5ll], var65[5ll], var66[5ll], var67[5ll], var72[5ll], var73[5ll], var74[5ll], var75[5ll]);
  if (var172)
    return 1; //collision pair: 5,7
  var72[7ll] = var68;
  var73[7ll] = var69;
  var74[7ll] = var70;
  var75[7ll] = var71;
  var64[8ll] = ((var61[0ll] * -3.18529237125398e-05) + (var61[3ll] * 0.157299974634608)) + (var61[6ll] * 0.000531853068429331);
  var65[8ll] = ((var61[1ll] * -3.18529237125398e-05) + (var61[4ll] * 0.157299974634608)) + (var61[7ll] * 0.000531853068429331);
  var66[8ll] = ((var61[2ll] * -3.18529237125398e-05) + (var61[5ll] * 0.157299974634608)) + (var61[8ll] * 0.000531853068429331);
  var64[8ll] = var64[8ll] + 0;
  var65[8ll] = var65[8ll] + 0;
  var66[8ll] = var66[8ll] + 0;
  var67[8ll] = 0.06;
  var68[0ll] = ((var61[0ll] * -4.77794169794995e-05) + (var61[3ll] * 0.177299961951912)) + (var61[6ll] * 0.000547779602643996);
  var69[0ll] = ((var61[1ll] * -4.77794169794995e-05) + (var61[4ll] * 0.177299961951912)) + (var61[7ll] * 0.000547779602643996);
  var70[0ll] = ((var61[2ll] * -4.77794169794995e-05) + (var61[5ll] * 0.177299961951912)) + (var61[8ll] * 0.000547779602643996);
  var68[0ll] = var68[0ll] + 0;
  var69[0ll] = var69[0ll] + 0;
  var70[0ll] = var70[0ll] + 0;
  var71[0ll] = 0.04;
  var68[1ll] = ((var61[0ll] * -1.592643044558e-05) + (var61[3ll] * 0.137299987317304)) + (var61[6ll] * 0.000515926534214666);
  var69[1ll] = ((var61[1ll] * -1.592643044558e-05) + (var61[4ll] * 0.137299987317304)) + (var61[7ll] * 0.000515926534214666);
  var70[1ll] = ((var61[2ll] * -1.592643044558e-05) + (var61[5ll] * 0.137299987317304)) + (var61[8ll] * 0.000515926534214666);
  var68[1ll] = var68[1ll] + 0;
  var69[1ll] = var69[1ll] + 0;
  var70[1ll] = var70[1ll] + 0;
  var71[1ll] = 0.04;
  int var173;
  var173 = runtime::self_collision_link_vs_link(var64[8ll], var65[8ll], var66[8ll], var67[8ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var173)
    return 1; //collision pair: 0,8
  var173 = runtime::self_collision_link_vs_link(var64[8ll], var65[8ll], var66[8ll], var67[8ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var173)
    return 1; //collision pair: 1,8
  var173 = runtime::self_collision_link_vs_link(var64[8ll], var65[8ll], var66[8ll], var67[8ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var173)
    return 1; //collision pair: 2,8
  var173 = runtime::self_collision_link_vs_link(var64[8ll], var65[8ll], var66[8ll], var67[8ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var173)
    return 1; //collision pair: 3,8
  var72[8ll] = var68;
  var73[8ll] = var69;
  var74[8ll] = var70;
  var75[8ll] = var71;
  var64[9ll] = ((var61[0ll] * 0.0326288719300173) + (var61[3ll] * 0.206633483191718)) + (var61[6ll] * 0.000571117947718783);
  var65[9ll] = ((var61[1ll] * 0.0326288719300173) + (var61[4ll] * 0.206633483191718)) + (var61[7ll] * 0.000571117947718783);
  var66[9ll] = ((var61[2ll] * 0.0326288719300173) + (var61[5ll] * 0.206633483191718)) + (var61[8ll] * 0.000571117947718783);
  var64[9ll] = var64[9ll] + 0;
  var65[9ll] = var65[9ll] + 0;
  var66[9ll] = var66[9ll] + 0;
  var67[9ll] = 0.02;
  int var174;
  var174 = runtime::self_collision_link_vs_link(var64[9ll], var65[9ll], var66[9ll], var67[9ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var174)
    return 1; //collision pair: 0,9
  var174 = runtime::self_collision_link_vs_link(var64[9ll], var65[9ll], var66[9ll], var67[9ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var174)
    return 1; //collision pair: 1,9
  var174 = runtime::self_collision_link_vs_link(var64[9ll], var65[9ll], var66[9ll], var67[9ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var174)
    return 1; //collision pair: 2,9
  var174 = runtime::self_collision_link_vs_link(var64[9ll], var65[9ll], var66[9ll], var67[9ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var174)
    return 1; //collision pair: 3,9
  var72[9ll] = var68;
  var73[9ll] = var69;
  var74[9ll] = var70;
  var75[9ll] = var71;
  var64[10ll] = ((var61[0ll] * 0.0471835220407953) + (var61[3ll] * 0.24514209280766)) + (var61[6ll] * 0.000601774152536124);
  var65[10ll] = ((var61[1ll] * 0.0471835220407953) + (var61[4ll] * 0.24514209280766)) + (var61[7ll] * 0.000601774152536124);
  var66[10ll] = ((var61[2ll] * 0.0471835220407953) + (var61[5ll] * 0.24514209280766)) + (var61[8ll] * 0.000601774152536124);
  var64[10ll] = var64[10ll] + 0;
  var65[10ll] = var65[10ll] + 0;
  var66[10ll] = var66[10ll] + 0;
  var67[10ll] = 0.033;
  var68[0ll] = ((var61[0ll] * 0.0471739661448351) + (var61[3ll] * 0.257142085198042)) + (var61[6ll] * 0.000611330073064923);
  var69[0ll] = ((var61[1ll] * 0.0471739661448351) + (var61[4ll] * 0.257142085198042)) + (var61[7ll] * 0.000611330073064923);
  var70[0ll] = ((var61[2ll] * 0.0471739661448351) + (var61[5ll] * 0.257142085198042)) + (var61[8ll] * 0.000611330073064923);
  var68[0ll] = var68[0ll] + 0;
  var69[0ll] = var69[0ll] + 0;
  var70[0ll] = var70[0ll] + 0;
  var71[0ll] = 0.02;
  var68[1ll] = ((var61[0ll] * 0.0471938742614188) + (var61[3ll] * 0.232142101051412)) + (var61[6ll] * 0.000591421905296592);
  var69[1ll] = ((var61[1ll] * 0.0471938742614188) + (var61[4ll] * 0.232142101051412)) + (var61[7ll] * 0.000591421905296592);
  var70[1ll] = ((var61[2ll] * 0.0471938742614188) + (var61[5ll] * 0.232142101051412)) + (var61[8ll] * 0.000591421905296592);
  var68[1ll] = var68[1ll] + 0;
  var69[1ll] = var69[1ll] + 0;
  var70[1ll] = var70[1ll] + 0;
  var71[1ll] = 0.02;
  int var175;
  var175 = runtime::self_collision_link_vs_link(var64[10ll], var65[10ll], var66[10ll], var67[10ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var175)
    return 1; //collision pair: 0,10
  var175 = runtime::self_collision_link_vs_link(var64[10ll], var65[10ll], var66[10ll], var67[10ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var175)
    return 1; //collision pair: 1,10
  var175 = runtime::self_collision_link_vs_link(var64[10ll], var65[10ll], var66[10ll], var67[10ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var175)
    return 1; //collision pair: 2,10
  var175 = runtime::self_collision_link_vs_link(var64[10ll], var65[10ll], var66[10ll], var67[10ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var175)
    return 1; //collision pair: 3,10
  var72[10ll] = var68;
  var73[10ll] = var69;
  var74[10ll] = var70;
  var75[10ll] = var71;
  var64[11ll] = ((var61[0ll] * 0.0305511319550535) + (var61[3ll] * 0.180116344904696)) + (var61[6ll] * 0.000550002959776232);
  var65[11ll] = ((var61[1ll] * 0.0305511319550535) + (var61[4ll] * 0.180116344904696)) + (var61[7ll] * 0.000550002959776232);
  var66[11ll] = ((var61[2ll] * 0.0305511319550535) + (var61[5ll] * 0.180116344904696)) + (var61[8ll] * 0.000550002959776232);
  var64[11ll] = var64[11ll] + 0;
  var65[11ll] = var65[11ll] + 0;
  var66[11ll] = var66[11ll] + 0;
  var67[11ll] = 0.02;
  int var176;
  var176 = runtime::self_collision_link_vs_link(var64[11ll], var65[11ll], var66[11ll], var67[11ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var176)
    return 1; //collision pair: 0,11
  var176 = runtime::self_collision_link_vs_link(var64[11ll], var65[11ll], var66[11ll], var67[11ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var176)
    return 1; //collision pair: 1,11
  var176 = runtime::self_collision_link_vs_link(var64[11ll], var65[11ll], var66[11ll], var67[11ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var176)
    return 1; //collision pair: 2,11
  var176 = runtime::self_collision_link_vs_link(var64[11ll], var65[11ll], var66[11ll], var67[11ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var176)
    return 1; //collision pair: 3,11
  var72[11ll] = var68;
  var73[11ll] = var69;
  var74[11ll] = var70;
  var75[11ll] = var71;
  var64[12ll] = ((var61[0ll] * 0.0622277797033028) + (var61[3ll] * 0.198207606059275)) + (var61[6ll] * 0.000564389426993413);
  var65[12ll] = ((var61[1ll] * 0.0622277797033028) + (var61[4ll] * 0.198207606059275)) + (var61[7ll] * 0.000564389426993413);
  var66[12ll] = ((var61[2ll] * 0.0622277797033028) + (var61[5ll] * 0.198207606059275)) + (var61[8ll] * 0.000564389426993413);
  var64[12ll] = var64[12ll] + 0;
  var65[12ll] = var65[12ll] + 0;
  var66[12ll] = var66[12ll] + 0;
  var67[12ll] = 0.035;
  var68[0ll] = ((var61[0ll] * 0.0622118532100359) + (var61[3ll] * 0.218207593376579)) + (var61[6ll] * 0.000580315961208078);
  var69[0ll] = ((var61[1ll] * 0.0622118532100359) + (var61[4ll] * 0.218207593376579)) + (var61[7ll] * 0.000580315961208078);
  var70[0ll] = ((var61[2ll] * 0.0622118532100359) + (var61[5ll] * 0.218207593376579)) + (var61[8ll] * 0.000580315961208078);
  var68[0ll] = var68[0ll] + 0;
  var69[0ll] = var69[0ll] + 0;
  var70[0ll] = var70[0ll] + 0;
  var71[0ll] = 0.015;
  var68[1ll] = ((var61[0ll] * 0.0622437061965698) + (var61[3ll] * 0.178207618741971)) + (var61[6ll] * 0.000548462892778747);
  var69[1ll] = ((var61[1ll] * 0.0622437061965698) + (var61[4ll] * 0.178207618741971)) + (var61[7ll] * 0.000548462892778747);
  var70[1ll] = ((var61[2ll] * 0.0622437061965698) + (var61[5ll] * 0.178207618741971)) + (var61[8ll] * 0.000548462892778747);
  var68[1ll] = var68[1ll] + 0;
  var69[1ll] = var69[1ll] + 0;
  var70[1ll] = var70[1ll] + 0;
  var71[1ll] = 0.015;
  var68[2ll] = ((var61[0ll] * 0.0622277797033028) + (var61[3ll] * 0.198207606059275)) + (var61[6ll] * 0.000564389426993413);
  var69[2ll] = ((var61[1ll] * 0.0622277797033028) + (var61[4ll] * 0.198207606059275)) + (var61[7ll] * 0.000564389426993413);
  var70[2ll] = ((var61[2ll] * 0.0622277797033028) + (var61[5ll] * 0.198207606059275)) + (var61[8ll] * 0.000564389426993413);
  var68[2ll] = var68[2ll] + 0;
  var69[2ll] = var69[2ll] + 0;
  var70[2ll] = var70[2ll] + 0;
  var71[2ll] = 0.015;
  int var177;
  var177 = runtime::self_collision_link_vs_link(var64[12ll], var65[12ll], var66[12ll], var67[12ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var177)
    return 1; //collision pair: 0,12
  var177 = runtime::self_collision_link_vs_link(var64[12ll], var65[12ll], var66[12ll], var67[12ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var177)
    return 1; //collision pair: 1,12
  var177 = runtime::self_collision_link_vs_link(var64[12ll], var65[12ll], var66[12ll], var67[12ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var177)
    return 1; //collision pair: 2,12
  var177 = runtime::self_collision_link_vs_link(var64[12ll], var65[12ll], var66[12ll], var67[12ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var177)
    return 1; //collision pair: 3,12
  var72[12ll] = var68;
  var73[12ll] = var69;
  var74[12ll] = var70;
  var75[12ll] = var71;
  var64[13ll] = ((var61[0ll] * -0.0327711073338182) + (var61[3ll] * 0.206581403542295)) + (var61[6ll] * 0.000571117947718776);
  var65[13ll] = ((var61[1ll] * -0.0327711073338182) + (var61[4ll] * 0.206581403542295)) + (var61[7ll] * 0.000571117947718776);
  var66[13ll] = ((var61[2ll] * -0.0327711073338182) + (var61[5ll] * 0.206581403542295)) + (var61[8ll] * 0.000571117947718776);
  var64[13ll] = var64[13ll] + 0;
  var65[13ll] = var65[13ll] + 0;
  var66[13ll] = var66[13ll] + 0;
  var67[13ll] = 0.02;
  int var178;
  var178 = runtime::self_collision_link_vs_link(var64[13ll], var65[13ll], var66[13ll], var67[13ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var178)
    return 1; //collision pair: 0,13
  var178 = runtime::self_collision_link_vs_link(var64[13ll], var65[13ll], var66[13ll], var67[13ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var178)
    return 1; //collision pair: 1,13
  var178 = runtime::self_collision_link_vs_link(var64[13ll], var65[13ll], var66[13ll], var67[13ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var178)
    return 1; //collision pair: 2,13
  var178 = runtime::self_collision_link_vs_link(var64[13ll], var65[13ll], var66[13ll], var67[13ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var178)
    return 1; //collision pair: 3,13
  var72[13ll] = var68;
  var73[13ll] = var69;
  var74[13ll] = var70;
  var75[13ll] = var71;
  var64[14ll] = ((var61[0ll] * -0.0469080935033019) + (var61[3ll] * 0.245427533758517)) + (var61[6ll] * 0.000602061123576327);
  var65[14ll] = ((var61[1ll] * -0.0469080935033019) + (var61[4ll] * 0.245427533758517)) + (var61[7ll] * 0.000602061123576327);
  var66[14ll] = ((var61[2ll] * -0.0469080935033019) + (var61[5ll] * 0.245427533758517)) + (var61[8ll] * 0.000602061123576327);
  var64[14ll] = var64[14ll] + 0;
  var65[14ll] = var65[14ll] + 0;
  var66[14ll] = var66[14ll] + 0;
  var67[14ll] = 0.033;
  var68[0ll] = ((var61[0ll] * -0.0469176493992621) + (var61[3ll] * 0.257427526148899)) + (var61[6ll] * 0.000611617044105126);
  var69[0ll] = ((var61[1ll] * -0.0469176493992621) + (var61[4ll] * 0.257427526148899)) + (var61[7ll] * 0.000611617044105126);
  var70[0ll] = ((var61[2ll] * -0.0469176493992621) + (var61[5ll] * 0.257427526148899)) + (var61[8ll] * 0.000611617044105126);
  var68[0ll] = var68[0ll] + 0;
  var69[0ll] = var69[0ll] + 0;
  var70[0ll] = var70[0ll] + 0;
  var71[0ll] = 0.02;
  var68[1ll] = ((var61[0ll] * -0.0468977412826784) + (var61[3ll] * 0.232427542002269)) + (var61[6ll] * 0.000591708876336795);
  var69[1ll] = ((var61[1ll] * -0.0468977412826784) + (var61[4ll] * 0.232427542002269)) + (var61[7ll] * 0.000591708876336795);
  var70[1ll] = ((var61[2ll] * -0.0468977412826784) + (var61[5ll] * 0.232427542002269)) + (var61[8ll] * 0.000591708876336795);
  var68[1ll] = var68[1ll] + 0;
  var69[1ll] = var69[1ll] + 0;
  var70[1ll] = var70[1ll] + 0;
  var71[1ll] = 0.02;
  int var179;
  var179 = runtime::self_collision_link_vs_link(var64[14ll], var65[14ll], var66[14ll], var67[14ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var179)
    return 1; //collision pair: 0,14
  var179 = runtime::self_collision_link_vs_link(var64[14ll], var65[14ll], var66[14ll], var67[14ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var179)
    return 1; //collision pair: 1,14
  var179 = runtime::self_collision_link_vs_link(var64[14ll], var65[14ll], var66[14ll], var67[14ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var179)
    return 1; //collision pair: 2,14
  var179 = runtime::self_collision_link_vs_link(var64[14ll], var65[14ll], var66[14ll], var67[14ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var179)
    return 1; //collision pair: 3,14
  var72[14ll] = var68;
  var73[14ll] = var69;
  var74[14ll] = var70;
  var75[14ll] = var71;
  var64[15ll] = ((var61[0ll] * -0.0306511374916797) + (var61[3ll] * 0.180067607997177)) + (var61[6ll] * 0.000550002959776232);
  var65[15ll] = ((var61[1ll] * -0.0306511374916797) + (var61[4ll] * 0.180067607997177)) + (var61[7ll] * 0.000550002959776232);
  var66[15ll] = ((var61[2ll] * -0.0306511374916797) + (var61[5ll] * 0.180067607997177)) + (var61[8ll] * 0.000550002959776232);
  var64[15ll] = var64[15ll] + 0;
  var65[15ll] = var65[15ll] + 0;
  var66[15ll] = var66[15ll] + 0;
  var67[15ll] = 0.02;
  int var180;
  var180 = runtime::self_collision_link_vs_link(var64[15ll], var65[15ll], var66[15ll], var67[15ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var180)
    return 1; //collision pair: 0,15
  var180 = runtime::self_collision_link_vs_link(var64[15ll], var65[15ll], var66[15ll], var67[15ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var180)
    return 1; //collision pair: 1,15
  var180 = runtime::self_collision_link_vs_link(var64[15ll], var65[15ll], var66[15ll], var67[15ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var180)
    return 1; //collision pair: 2,15
  var180 = runtime::self_collision_link_vs_link(var64[15ll], var65[15ll], var66[15ll], var67[15ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var180)
    return 1; //collision pair: 3,15
  var72[15ll] = var68;
  var73[15ll] = var69;
  var74[15ll] = var70;
  var75[15ll] = var71;
  var64[16ll] = ((var61[0ll] * -0.0623753696679426) + (var61[3ll] * 0.198440988697155)) + (var61[6ll] * 0.000564654291040047);
  var65[16ll] = ((var61[1ll] * -0.0623753696679426) + (var61[4ll] * 0.198440988697155)) + (var61[7ll] * 0.000564654291040047);
  var66[16ll] = ((var61[2ll] * -0.0623753696679426) + (var61[5ll] * 0.198440988697155)) + (var61[8ll] * 0.000564654291040047);
  var64[16ll] = var64[16ll] + 0;
  var65[16ll] = var65[16ll] + 0;
  var66[16ll] = var66[16ll] + 0;
  var67[16ll] = 0.035;
  var68[0ll] = ((var61[0ll] * -0.0623912961612096) + (var61[3ll] * 0.218440976014459)) + (var61[6ll] * 0.000580580825254713);
  var69[0ll] = ((var61[1ll] * -0.0623912961612096) + (var61[4ll] * 0.218440976014459)) + (var61[7ll] * 0.000580580825254713);
  var70[0ll] = ((var61[2ll] * -0.0623912961612096) + (var61[5ll] * 0.218440976014459)) + (var61[8ll] * 0.000580580825254713);
  var68[0ll] = var68[0ll] + 0;
  var69[0ll] = var69[0ll] + 0;
  var70[0ll] = var70[0ll] + 0;
  var71[0ll] = 0.015;
  var68[1ll] = ((var61[0ll] * -0.0623594431746757) + (var61[3ll] * 0.178441001379851)) + (var61[6ll] * 0.000548727756825382);
  var69[1ll] = ((var61[1ll] * -0.0623594431746757) + (var61[4ll] * 0.178441001379851)) + (var61[7ll] * 0.000548727756825382);
  var70[1ll] = ((var61[2ll] * -0.0623594431746757) + (var61[5ll] * 0.178441001379851)) + (var61[8ll] * 0.000548727756825382);
  var68[1ll] = var68[1ll] + 0;
  var69[1ll] = var69[1ll] + 0;
  var70[1ll] = var70[1ll] + 0;
  var71[1ll] = 0.015;
  var68[2ll] = ((var61[0ll] * -0.0623753696679426) + (var61[3ll] * 0.198440988697155)) + (var61[6ll] * 0.000564654291040047);
  var69[2ll] = ((var61[1ll] * -0.0623753696679426) + (var61[4ll] * 0.198440988697155)) + (var61[7ll] * 0.000564654291040047);
  var70[2ll] = ((var61[2ll] * -0.0623753696679426) + (var61[5ll] * 0.198440988697155)) + (var61[8ll] * 0.000564654291040047);
  var68[2ll] = var68[2ll] + 0;
  var69[2ll] = var69[2ll] + 0;
  var70[2ll] = var70[2ll] + 0;
  var71[2ll] = 0.015;
  int var181;
  var181 = runtime::self_collision_link_vs_link(var64[16ll], var65[16ll], var66[16ll], var67[16ll], var68, var69, var70, var71, var64[0ll], var65[0ll], var66[0ll], var67[0ll], var72[0ll], var73[0ll], var74[0ll], var75[0ll]);
  if (var181)
    return 1; //collision pair: 0,16
  var181 = runtime::self_collision_link_vs_link(var64[16ll], var65[16ll], var66[16ll], var67[16ll], var68, var69, var70, var71, var64[1ll], var65[1ll], var66[1ll], var67[1ll], var72[1ll], var73[1ll], var74[1ll], var75[1ll]);
  if (var181)
    return 1; //collision pair: 1,16
  var181 = runtime::self_collision_link_vs_link(var64[16ll], var65[16ll], var66[16ll], var67[16ll], var68, var69, var70, var71, var64[2ll], var65[2ll], var66[2ll], var67[2ll], var72[2ll], var73[2ll], var74[2ll], var75[2ll]);
  if (var181)
    return 1; //collision pair: 2,16
  var181 = runtime::self_collision_link_vs_link(var64[16ll], var65[16ll], var66[16ll], var67[16ll], var68, var69, var70, var71, var64[3ll], var65[3ll], var66[3ll], var67[3ll], var72[3ll], var73[3ll], var74[3ll], var75[3ll]);
  if (var181)
    return 1; //collision pair: 3,16
  var72[16ll] = var68;
  var73[16ll] = var69;
  var74[16ll] = var70;
  var75[16ll] = var71;
  return 0;
}

}
