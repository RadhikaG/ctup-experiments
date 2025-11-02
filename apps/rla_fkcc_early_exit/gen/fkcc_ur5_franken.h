// clang-format off

#include "vamp/vector.hh"

#include "rla_fkcc_early_exit/runtime/typedefs.h"

#include "rla_fkcc_early_exit/runtime/vamp_collision.h"

namespace ctup_gen_ur5 {

static int fkcc_franken (vamp::collision::Environment<vamp::FloatVector<8, 1>> const& arg4, vamp::FloatVector<8, 6>& arg5) {
  vamp::FloatVector<8, 1> var146;
  vamp::FloatVector<8, 1> var147;
  vamp::FloatVector<8, 1> var150;
  vamp::FloatVector<8, 1> var151;
  vamp::FloatVector<8, 1> var162;
  vamp::FloatVector<8, 1> var163;
  vamp::FloatVector<8, 1> var164;
  vamp::FloatVector<8, 1> var166;
  vamp::FloatVector<8, 1> var172;
  vamp::FloatVector<8, 1> var174;
  vamp::FloatVector<8, 1> var180;
  vamp::FloatVector<8, 1> var181;
  vamp::FloatVector<8, 1> var182;
  vamp::FloatVector<8, 1> var184;
  vamp::FloatVector<8, 1> var190;
  vamp::FloatVector<8, 1> var192;
  vamp::FloatVector<8, 1> var198;
  vamp::FloatVector<8, 1> var199;
  vamp::FloatVector<8, 1> var200;
  vamp::FloatVector<8, 1> var202;
  vamp::FloatVector<8, 1> var208;
  vamp::FloatVector<8, 1> var210;
  vamp::FloatVector<8, 1> var216;
  vamp::FloatVector<8, 1> var217;
  vamp::FloatVector<8, 1> var218;
  vamp::FloatVector<8, 1> var219;
  vamp::FloatVector<8, 1> var222;
  vamp::FloatVector<8, 1> var223;
  vamp::FloatVector<8, 1> var234;
  vamp::FloatVector<8, 1> var235;
  vamp::FloatVector<8, 1> var236;
  vamp::FloatVector<8, 1> var238;
  vamp::FloatVector<8, 1> var244;
  vamp::FloatVector<8, 1> var246;
  vamp::FloatVector<8, 1> var252;
  vamp::FloatVector<8, 1> var253;
  vamp::FloatVector<8, 1> var272;
  vamp::FloatVector<8, 1> var273;
  vamp::FloatVector<8, 1> var276;
  vamp::FloatVector<8, 1> var277;
  vamp::FloatVector<8, 1> var290;
  vamp::FloatVector<8, 1> var291;
  vamp::FloatVector<8, 1> var292;
  vamp::FloatVector<8, 1> var293;
  vamp::FloatVector<8, 1> var294;
  vamp::FloatVector<8, 1> var295;
  vamp::FloatVector<8, 1> var296;
  vamp::FloatVector<8, 1> var297;
  vamp::FloatVector<8, 1> var298;
  vamp::FloatVector<8, 1> var300;
  vamp::FloatVector<8, 1> var308;
  vamp::FloatVector<8, 1> var309;
  vamp::FloatVector<8, 1> var310;
  vamp::FloatVector<8, 1> var311;
  vamp::FloatVector<8, 1> var312;
  vamp::FloatVector<8, 1> var313;
  vamp::FloatVector<8, 1> var314;
  vamp::FloatVector<8, 1> var315;
  vamp::FloatVector<8, 1> var316;
  vamp::FloatVector<8, 1> var318;
  vamp::FloatVector<8, 1> var319;
  vamp::FloatVector<8, 1> var326;
  vamp::FloatVector<8, 1> var327;
  vamp::FloatVector<8, 1> var328;
  vamp::FloatVector<8, 1> var329;
  vamp::FloatVector<8, 1> var330;
  vamp::FloatVector<8, 1> var331;
  vamp::FloatVector<8, 1> var332;
  vamp::FloatVector<8, 1> var333;
  vamp::FloatVector<8, 1> var334;
  vamp::FloatVector<8, 1> var336;
  vamp::FloatVector<8, 1> var337;
  vamp::FloatVector<8, 1> var344;
  vamp::FloatVector<8, 1> var345;
  vamp::FloatVector<8, 1> var346;
  vamp::FloatVector<8, 1> var347;
  vamp::FloatVector<8, 1> var348;
  vamp::FloatVector<8, 1> var349;
  vamp::FloatVector<8, 1> var350;
  vamp::FloatVector<8, 1> var351;
  vamp::FloatVector<8, 1> var352;
  vamp::FloatVector<8, 1> var353;
  vamp::FloatVector<8, 1> var354;
  vamp::FloatVector<8, 1> var355;
  vamp::FloatVector<8, 1> var362;
  vamp::FloatVector<8, 1> var363;
  vamp::FloatVector<8, 1> var364;
  vamp::FloatVector<8, 1> var365;
  vamp::FloatVector<8, 1> var366;
  vamp::FloatVector<8, 1> var367;
  vamp::FloatVector<8, 1> var368;
  vamp::FloatVector<8, 1> var369;
  vamp::FloatVector<8, 1> var370;
  vamp::FloatVector<8, 1> var371;
  vamp::FloatVector<8, 1> var372;
  vamp::FloatVector<8, 1> var373;
  vamp::FloatVector<8, 1> var380[17];
  vamp::FloatVector<8, 1> var381[17];
  vamp::FloatVector<8, 1> var382[17];
  float var383[17];
  unsigned long int var384[17];
  std::array<vamp::FloatVector<8, 1>, 1> var385;
  std::array<vamp::FloatVector<8, 1>, 0> var386;
  std::array<vamp::FloatVector<8, 1>, 5> var387;
  std::array<vamp::FloatVector<8, 1>, 5> var388;
  std::array<vamp::FloatVector<8, 1>, 3> var389;
  std::array<vamp::FloatVector<8, 1>, 3> var390;
  std::array<vamp::FloatVector<8, 1>, 1> var391;
  std::array<vamp::FloatVector<8, 1>, 1> var392;
  std::array<vamp::FloatVector<8, 1>, 2> var393;
  std::array<vamp::FloatVector<8, 1>, 1> var394;
  std::array<vamp::FloatVector<8, 1>, 2> var395;
  std::array<vamp::FloatVector<8, 1>, 1> var396;
  std::array<vamp::FloatVector<8, 1>, 3> var397;
  std::array<vamp::FloatVector<8, 1>, 1> var398;
  std::array<vamp::FloatVector<8, 1>, 2> var399;
  std::array<vamp::FloatVector<8, 1>, 1> var400;
  std::array<vamp::FloatVector<8, 1>, 3> var401;
  std::array<vamp::FloatVector<8, 1>, 1> var402;
  std::array<vamp::FloatVector<8, 1>, 0> var403;
  std::array<vamp::FloatVector<8, 1>, 5> var404;
  std::array<vamp::FloatVector<8, 1>, 5> var405;
  std::array<vamp::FloatVector<8, 1>, 3> var406;
  std::array<vamp::FloatVector<8, 1>, 3> var407;
  std::array<vamp::FloatVector<8, 1>, 1> var408;
  std::array<vamp::FloatVector<8, 1>, 1> var409;
  std::array<vamp::FloatVector<8, 1>, 2> var410;
  std::array<vamp::FloatVector<8, 1>, 1> var411;
  std::array<vamp::FloatVector<8, 1>, 2> var412;
  std::array<vamp::FloatVector<8, 1>, 1> var413;
  std::array<vamp::FloatVector<8, 1>, 3> var414;
  std::array<vamp::FloatVector<8, 1>, 1> var415;
  std::array<vamp::FloatVector<8, 1>, 2> var416;
  std::array<vamp::FloatVector<8, 1>, 1> var417;
  std::array<vamp::FloatVector<8, 1>, 3> var418;
  std::array<vamp::FloatVector<8, 1>, 1> var419;
  std::array<vamp::FloatVector<8, 1>, 0> var420;
  std::array<vamp::FloatVector<8, 1>, 5> var421;
  std::array<vamp::FloatVector<8, 1>, 5> var422;
  std::array<vamp::FloatVector<8, 1>, 3> var423;
  std::array<vamp::FloatVector<8, 1>, 3> var424;
  std::array<vamp::FloatVector<8, 1>, 1> var425;
  std::array<vamp::FloatVector<8, 1>, 1> var426;
  std::array<vamp::FloatVector<8, 1>, 2> var427;
  std::array<vamp::FloatVector<8, 1>, 1> var428;
  std::array<vamp::FloatVector<8, 1>, 2> var429;
  std::array<vamp::FloatVector<8, 1>, 1> var430;
  std::array<vamp::FloatVector<8, 1>, 3> var431;
  std::array<vamp::FloatVector<8, 1>, 1> var432;
  std::array<vamp::FloatVector<8, 1>, 2> var433;
  std::array<vamp::FloatVector<8, 1>, 1> var434;
  std::array<vamp::FloatVector<8, 1>, 3> var435;
  std::array<float, 1> var436;
  std::array<float, 0> var437;
  std::array<float, 5> var438;
  std::array<float, 5> var439;
  std::array<float, 3> var440;
  std::array<float, 3> var441;
  std::array<float, 1> var442;
  std::array<float, 1> var443;
  std::array<float, 2> var444;
  std::array<float, 1> var445;
  std::array<float, 2> var446;
  std::array<float, 1> var447;
  std::array<float, 3> var448;
  std::array<float, 1> var449;
  std::array<float, 2> var450;
  std::array<float, 1> var451;
  std::array<float, 3> var452;
  vamp::FloatVector<8, 1> var453;
  vamp::FloatVector<8, 1> var454;
  vamp::FloatVector<8, 1> var455;
  vamp::FloatVector<8, 1> var457;
  vamp::FloatVector<8, 1> var458;
  vamp::FloatVector<8, 1> var461;
  vamp::FloatVector<8, 1> var463;
  var380[0ll] = ((1.0f * 0.0f) + (0.0f * 0.0f)) + (0.0f * 0.914399981498718f);
  var381[0ll] = ((0.0f * 0.0f) + (1.0f * 0.0f)) + (0.0f * 0.914399981498718f);
  var382[0ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * 0.914399981498718f);
  var380[0ll] = var380[0ll] + 0.0f;
  var381[0ll] = var381[0ll] + 0.0f;
  var382[0ll] = var382[0ll] + 0.0f;
  var383[0ll] = 0.0799999982118607f;
  var384[0ll] = 1ll;
  var385[0ll] = ((1.0f * 0.0f) + (0.0f * 0.0f)) + (0.0f * 0.914399981498718f);
  var402[0ll] = ((0.0f * 0.0f) + (1.0f * 0.0f)) + (0.0f * 0.914399981498718f);
  var419[0ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * 0.914399981498718f);
  var385[0ll] = var385[0ll] + 0.0f;
  var402[0ll] = var402[0ll] + 0.0f;
  var419[0ll] = var419[0ll] + 0.0f;
  var436[0ll] = 0.0799999982118607f;
  vamp::FloatVector<8, 1> var472 = arg5[0ll];
  var162 = var472.sin();
  var163 = var472.cos();
  var146 = var163;
  var147 = -(var162);
  var150 = var162;
  var151 = var163;
  vamp::FloatVector<8, 1> var473;
  var473 = var473 + (0.000796326727140695f * var146);
  var473 = var473 + (-1.0f * var150);
  var453 = var473;
  vamp::FloatVector<8, 1> var475;
  var475 = var475 + (0.000796326727140695f * var147);
  var475 = var475 + (-1.0f * var151);
  var454 = var475;
  vamp::FloatVector<8, 1> var477;
  var477 = var477 + (1.0f * var146);
  var477 = var477 + (0.000796326727140695f * var150);
  var457 = var477;
  vamp::FloatVector<8, 1> var479;
  var479 = var479 + (1.0f * var147);
  var479 = var479 + (0.000796326727140695f * var151);
  var458 = var479;
  var272 = var453;
  var273 = var454;
  var276 = var457;
  var277 = var458;
  var380[1ll] = ((var272 * 0.0f) + (var273 * 0.0f)) + (0.0f * 0.0f);
  var381[1ll] = ((var276 * 0.0f) + (var277 * 0.0f)) + (0.0f * 0.0f);
  var382[1ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * 0.0f);
  var380[1ll] = var380[1ll] + 0.0f;
  var381[1ll] = var381[1ll] + 0.0f;
  var382[1ll] = var382[1ll] + 1.00355899333954f;
  var383[1ll] = 0.0799999982118607f;
  var384[1ll] = 0ll;
  int var481;
  var481 = ctup_runtime::link_vs_environment_collision(var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, arg4);
  if (var481)
    return 0;
  vamp::FloatVector<8, 1> var482 = arg5[1ll];
  var180 = var482.sin();
  var181 = var482.cos();
  var164 = var181;
  var166 = var180;
  var172 = -(var180);
  var174 = var181;
  vamp::FloatVector<8, 1> var483;
  var483 = var483 + (1.0f * var172);
  var453 = var483;
  vamp::FloatVector<8, 1> var485;
  var485 = var485 + (1.0f * var174);
  var455 = var485;
  vamp::FloatVector<8, 1> var487;
  var487 = var487 + (-1.0f * var164);
  var461 = var487;
  vamp::FloatVector<8, 1> var489;
  var489 = var489 + (-1.0f * var166);
  var463 = var489;
  vamp::FloatVector<8, 1> var491;
  var491 = var491 + (var272 * var453);
  var290 = var491;
  vamp::FloatVector<8, 1> var493;
  var493 = var493 + (var273 * 1.0f);
  var291 = var493;
  vamp::FloatVector<8, 1> var495;
  var495 = var495 + (var272 * var455);
  var292 = var495;
  vamp::FloatVector<8, 1> var497;
  var497 = var497 + (var273 * 0.135849997401237f);
  var293 = var497;
  vamp::FloatVector<8, 1> var499;
  var499 = var499 + (var276 * var453);
  var294 = var499;
  vamp::FloatVector<8, 1> var501;
  var501 = var501 + (var277 * 1.0f);
  var295 = var501;
  vamp::FloatVector<8, 1> var503;
  var503 = var503 + (var276 * var455);
  var296 = var503;
  vamp::FloatVector<8, 1> var505;
  var505 = var505 + (var277 * 0.135849997401237f);
  var297 = var505;
  vamp::FloatVector<8, 1> var507;
  var507 = var507 + (1.0f * var461);
  var298 = var507;
  vamp::FloatVector<8, 1> var509;
  var509 = var509 + (1.0f * var463);
  var300 = var509;
  var380[2ll] = ((var290 * 0.0f) + (var291 * 0.0f)) + (var292 * 0.209999993443489f);
  var381[2ll] = ((var294 * 0.0f) + (var295 * 0.0f)) + (var296 * 0.209999993443489f);
  var382[2ll] = ((var298 * 0.0f) + (0.0f * 0.0f)) + (var300 * 0.209999993443489f);
  var380[2ll] = var380[2ll] + var293;
  var381[2ll] = var381[2ll] + var297;
  var382[2ll] = var382[2ll] + 1.00355899333954f;
  var383[2ll] = 0.28999999165535f;
  var384[2ll] = 5ll;
  var387[0ll] = ((var290 * 0.0f) + (var291 * 0.0f)) + (var292 * 0.104999996721745f);
  var404[0ll] = ((var294 * 0.0f) + (var295 * 0.0f)) + (var296 * 0.104999996721745f);
  var421[0ll] = ((var298 * 0.0f) + (0.0f * 0.0f)) + (var300 * 0.104999996721745f);
  var387[0ll] = var387[0ll] + var293;
  var404[0ll] = var404[0ll] + var297;
  var421[0ll] = var421[0ll] + 1.00355899333954f;
  var438[0ll] = 0.0799999982118607f;
  var387[1ll] = ((var290 * 0.0f) + (var291 * 0.0f)) + (var292 * 0.209999993443489f);
  var404[1ll] = ((var294 * 0.0f) + (var295 * 0.0f)) + (var296 * 0.209999993443489f);
  var421[1ll] = ((var298 * 0.0f) + (0.0f * 0.0f)) + (var300 * 0.209999993443489f);
  var387[1ll] = var387[1ll] + var293;
  var404[1ll] = var404[1ll] + var297;
  var421[1ll] = var421[1ll] + 1.00355899333954f;
  var438[1ll] = 0.0799999982118607f;
  var387[2ll] = ((var290 * 0.0f) + (var291 * 0.0f)) + (var292 * 0.314999997615814f);
  var404[2ll] = ((var294 * 0.0f) + (var295 * 0.0f)) + (var296 * 0.314999997615814f);
  var421[2ll] = ((var298 * 0.0f) + (0.0f * 0.0f)) + (var300 * 0.314999997615814f);
  var387[2ll] = var387[2ll] + var293;
  var404[2ll] = var404[2ll] + var297;
  var421[2ll] = var421[2ll] + 1.00355899333954f;
  var438[2ll] = 0.0799999982118607f;
  var387[3ll] = ((var290 * 0.0f) + (var291 * 0.0f)) + (var292 * 0.419999986886978f);
  var404[3ll] = ((var294 * 0.0f) + (var295 * 0.0f)) + (var296 * 0.419999986886978f);
  var421[3ll] = ((var298 * 0.0f) + (0.0f * 0.0f)) + (var300 * 0.419999986886978f);
  var387[3ll] = var387[3ll] + var293;
  var404[3ll] = var404[3ll] + var297;
  var421[3ll] = var421[3ll] + 1.00355899333954f;
  var438[3ll] = 0.0799999982118607f;
  var387[4ll] = ((var290 * 0.0f) + (var291 * 0.0f)) + (var292 * 0.0f);
  var404[4ll] = ((var294 * 0.0f) + (var295 * 0.0f)) + (var296 * 0.0f);
  var421[4ll] = ((var298 * 0.0f) + (0.0f * 0.0f)) + (var300 * 0.0f);
  var387[4ll] = var387[4ll] + var293;
  var404[4ll] = var404[4ll] + var297;
  var421[4ll] = var421[4ll] + 1.00355899333954f;
  var438[4ll] = 0.0799999982118607f;
  int var511;
  var511 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438);
  if (var511)
    return 0; //collision pair: 0,2 : base_link_0,upper_arm_link_0
  var511 = ctup_runtime::link_vs_environment_collision(var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, arg4);
  if (var511)
    return 0;
  vamp::FloatVector<8, 1> var512 = arg5[2ll];
  var198 = var512.sin();
  var199 = var512.cos();
  var182 = var199;
  var184 = var198;
  var190 = -(var198);
  var192 = var199;
  vamp::FloatVector<8, 1> var513;
  var513 = var513 + (1.0f * var182);
  var453 = var513;
  vamp::FloatVector<8, 1> var515;
  var515 = var515 + (1.0f * var184);
  var455 = var515;
  vamp::FloatVector<8, 1> var517;
  var517 = var517 + (1.0f * var190);
  var461 = var517;
  vamp::FloatVector<8, 1> var519;
  var519 = var519 + (1.0f * var192);
  var463 = var519;
  vamp::FloatVector<8, 1> var521;
  var521 = var521 + (var290 * var453);
  var521 = var521 + (var292 * var461);
  var308 = var521;
  vamp::FloatVector<8, 1> var523;
  var523 = var523 + (var291 * 1.0f);
  var309 = var523;
  vamp::FloatVector<8, 1> var525;
  var525 = var525 + (var290 * var455);
  var525 = var525 + (var292 * var463);
  var310 = var525;
  vamp::FloatVector<8, 1> var527;
  var527 = var527 + (var291 * -0.119699999690056f);
  var527 = var527 + (var292 * 0.425000011920929f);
  var527 = var527 + (var293 * 1.0f);
  var311 = var527;
  vamp::FloatVector<8, 1> var529;
  var529 = var529 + (var294 * var453);
  var529 = var529 + (var296 * var461);
  var312 = var529;
  vamp::FloatVector<8, 1> var531;
  var531 = var531 + (var295 * 1.0f);
  var313 = var531;
  vamp::FloatVector<8, 1> var533;
  var533 = var533 + (var294 * var455);
  var533 = var533 + (var296 * var463);
  var314 = var533;
  vamp::FloatVector<8, 1> var535;
  var535 = var535 + (var295 * -0.119699999690056f);
  var535 = var535 + (var296 * 0.425000011920929f);
  var535 = var535 + (var297 * 1.0f);
  var315 = var535;
  vamp::FloatVector<8, 1> var537;
  var537 = var537 + (var298 * var453);
  var537 = var537 + (var300 * var461);
  var316 = var537;
  vamp::FloatVector<8, 1> var539;
  var539 = var539 + (var298 * var455);
  var539 = var539 + (var300 * var463);
  var318 = var539;
  vamp::FloatVector<8, 1> var541;
  var541 = var541 + (var300 * 0.425000011920929f);
  var541 = var541 + (1.00355899333954f * 1.0f);
  var319 = var541;
  var380[3ll] = ((var308 * 0.0020000000949949f) + (var309 * 0.00300000002607703f)) + (var310 * 0.185000002384186f);
  var381[3ll] = ((var312 * 0.0020000000949949f) + (var313 * 0.00300000002607703f)) + (var314 * 0.185000002384186f);
  var382[3ll] = ((var316 * 0.0020000000949949f) + (0.0f * 0.00300000002607703f)) + (var318 * 0.185000002384186f);
  var380[3ll] = var380[3ll] + var311;
  var381[3ll] = var381[3ll] + var315;
  var382[3ll] = var382[3ll] + var319;
  var383[3ll] = 0.264999985694885f;
  var384[3ll] = 5ll;
  var388[0ll] = ((var308 * 0.0f) + (var309 * 0.0f)) + (var310 * 0.0f);
  var405[0ll] = ((var312 * 0.0f) + (var313 * 0.0f)) + (var314 * 0.0f);
  var422[0ll] = ((var316 * 0.0f) + (0.0f * 0.0f)) + (var318 * 0.0f);
  var388[0ll] = var388[0ll] + var311;
  var405[0ll] = var405[0ll] + var315;
  var422[0ll] = var422[0ll] + var319;
  var439[0ll] = 0.0799999982118607f;
  var388[1ll] = ((var308 * 0.0f) + (var309 * 0.0f)) + (var310 * 0.0974999964237213f);
  var405[1ll] = ((var312 * 0.0f) + (var313 * 0.0f)) + (var314 * 0.0974999964237213f);
  var422[1ll] = ((var316 * 0.0f) + (0.0f * 0.0f)) + (var318 * 0.0974999964237213f);
  var388[1ll] = var388[1ll] + var311;
  var405[1ll] = var405[1ll] + var315;
  var422[1ll] = var422[1ll] + var319;
  var439[1ll] = 0.0599999986588955f;
  var388[2ll] = ((var308 * 0.0f) + (var309 * 0.0f)) + (var310 * 0.194999992847443f);
  var405[2ll] = ((var312 * 0.0f) + (var313 * 0.0f)) + (var314 * 0.194999992847443f);
  var422[2ll] = ((var316 * 0.0f) + (0.0f * 0.0f)) + (var318 * 0.194999992847443f);
  var388[2ll] = var388[2ll] + var311;
  var405[2ll] = var405[2ll] + var315;
  var422[2ll] = var422[2ll] + var319;
  var439[2ll] = 0.0599999986588955f;
  var388[3ll] = ((var308 * 0.0f) + (var309 * 0.0f)) + (var310 * 0.292499989271164f);
  var405[3ll] = ((var312 * 0.0f) + (var313 * 0.0f)) + (var314 * 0.292499989271164f);
  var422[3ll] = ((var316 * 0.0f) + (0.0f * 0.0f)) + (var318 * 0.292499989271164f);
  var388[3ll] = var388[3ll] + var311;
  var405[3ll] = var405[3ll] + var315;
  var422[3ll] = var422[3ll] + var319;
  var439[3ll] = 0.0599999986588955f;
  var388[4ll] = ((var308 * 0.0f) + (var309 * 0.0f)) + (var310 * 0.389999985694885f);
  var405[4ll] = ((var312 * 0.0f) + (var313 * 0.0f)) + (var314 * 0.389999985694885f);
  var422[4ll] = ((var316 * 0.0f) + (0.0f * 0.0f)) + (var318 * 0.389999985694885f);
  var388[4ll] = var388[4ll] + var311;
  var405[4ll] = var405[4ll] + var315;
  var422[4ll] = var422[4ll] + var319;
  var439[4ll] = 0.0599999986588955f;
  int var543;
  var543 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439);
  if (var543)
    return 0; //collision pair: 0,3 : base_link_0,forearm_link_0
  var543 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439);
  if (var543)
    return 0; //collision pair: 1,3 : shoulder_link_0,forearm_link_0
  var543 = ctup_runtime::link_vs_environment_collision(var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, arg4);
  if (var543)
    return 0;
  vamp::FloatVector<8, 1> var544 = arg5[3ll];
  var216 = var544.sin();
  var217 = var544.cos();
  var200 = var217;
  var202 = var216;
  var208 = -(var216);
  var210 = var217;
  vamp::FloatVector<8, 1> var545;
  var545 = var545 + (1.0f * var208);
  var453 = var545;
  vamp::FloatVector<8, 1> var547;
  var547 = var547 + (1.0f * var210);
  var455 = var547;
  vamp::FloatVector<8, 1> var549;
  var549 = var549 + (-1.0f * var200);
  var461 = var549;
  vamp::FloatVector<8, 1> var551;
  var551 = var551 + (-1.0f * var202);
  var463 = var551;
  vamp::FloatVector<8, 1> var553;
  var553 = var553 + (var308 * var453);
  var553 = var553 + (var310 * var461);
  var326 = var553;
  vamp::FloatVector<8, 1> var555;
  var555 = var555 + (var309 * 1.0f);
  var327 = var555;
  vamp::FloatVector<8, 1> var557;
  var557 = var557 + (var308 * var455);
  var557 = var557 + (var310 * var463);
  var328 = var557;
  vamp::FloatVector<8, 1> var559;
  var559 = var559 + (var310 * 0.392250001430511f);
  var559 = var559 + (var311 * 1.0f);
  var329 = var559;
  vamp::FloatVector<8, 1> var561;
  var561 = var561 + (var312 * var453);
  var561 = var561 + (var314 * var461);
  var330 = var561;
  vamp::FloatVector<8, 1> var563;
  var563 = var563 + (var313 * 1.0f);
  var331 = var563;
  vamp::FloatVector<8, 1> var565;
  var565 = var565 + (var312 * var455);
  var565 = var565 + (var314 * var463);
  var332 = var565;
  vamp::FloatVector<8, 1> var567;
  var567 = var567 + (var314 * 0.392250001430511f);
  var567 = var567 + (var315 * 1.0f);
  var333 = var567;
  vamp::FloatVector<8, 1> var569;
  var569 = var569 + (var316 * var453);
  var569 = var569 + (var318 * var461);
  var334 = var569;
  vamp::FloatVector<8, 1> var571;
  var571 = var571 + (var316 * var455);
  var571 = var571 + (var318 * var463);
  var336 = var571;
  vamp::FloatVector<8, 1> var573;
  var573 = var573 + (var318 * 0.392250001430511f);
  var573 = var573 + (var319 * 1.0f);
  var337 = var573;
  var380[4ll] = ((var326 * 0.0f) + (var327 * 0.0900000035762787f)) + (var328 * 0.0f);
  var381[4ll] = ((var330 * 0.0f) + (var331 * 0.0900000035762787f)) + (var332 * 0.0f);
  var382[4ll] = ((var334 * 0.0f) + (0.0f * 0.0900000035762787f)) + (var336 * 0.0f);
  var380[4ll] = var380[4ll] + var329;
  var381[4ll] = var381[4ll] + var333;
  var382[4ll] = var382[4ll] + var337;
  var383[4ll] = 0.0700000002980232f;
  var384[4ll] = 3ll;
  var389[0ll] = ((var326 * 0.0f) + (var327 * 0.0900000035762787f)) + (var328 * 0.0299999993294477f);
  var406[0ll] = ((var330 * 0.0f) + (var331 * 0.0900000035762787f)) + (var332 * 0.0299999993294477f);
  var423[0ll] = ((var334 * 0.0f) + (0.0f * 0.0900000035762787f)) + (var336 * 0.0299999993294477f);
  var389[0ll] = var389[0ll] + var329;
  var406[0ll] = var406[0ll] + var333;
  var423[0ll] = var423[0ll] + var337;
  var440[0ll] = 0.0399999991059303f;
  var389[1ll] = ((var326 * 0.0f) + (var327 * 0.0900000035762787f)) + (var328 * -0.0299999993294477f);
  var406[1ll] = ((var330 * 0.0f) + (var331 * 0.0900000035762787f)) + (var332 * -0.0299999993294477f);
  var423[1ll] = ((var334 * 0.0f) + (0.0f * 0.0900000035762787f)) + (var336 * -0.0299999993294477f);
  var389[1ll] = var389[1ll] + var329;
  var406[1ll] = var406[1ll] + var333;
  var423[1ll] = var423[1ll] + var337;
  var440[1ll] = 0.0399999991059303f;
  var389[2ll] = ((var326 * 0.0f) + (var327 * 0.0900000035762787f)) + (var328 * 0.0f);
  var406[2ll] = ((var330 * 0.0f) + (var331 * 0.0900000035762787f)) + (var332 * 0.0f);
  var423[2ll] = ((var334 * 0.0f) + (0.0f * 0.0900000035762787f)) + (var336 * 0.0f);
  var389[2ll] = var389[2ll] + var329;
  var406[2ll] = var406[2ll] + var333;
  var423[2ll] = var423[2ll] + var337;
  var440[2ll] = 0.0399999991059303f;
  int var575;
  var575 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 4ll, var380[4ll], var381[4ll], var382[4ll], var383[4ll], var384[4ll], var389, var406, var423, var440);
  if (var575)
    return 0; //collision pair: 0,4 : base_link_0,wrist_1_link_0
  var575 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 4ll, var380[4ll], var381[4ll], var382[4ll], var383[4ll], var384[4ll], var389, var406, var423, var440);
  if (var575)
    return 0; //collision pair: 1,4 : shoulder_link_0,wrist_1_link_0
  var575 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 4ll, var380[4ll], var381[4ll], var382[4ll], var383[4ll], var384[4ll], var389, var406, var423, var440);
  if (var575)
    return 0; //collision pair: 2,4 : upper_arm_link_0,wrist_1_link_0
  var575 = ctup_runtime::link_vs_environment_collision(var380[4ll], var381[4ll], var382[4ll], var383[4ll], var384[4ll], var389, var406, var423, var440, arg4);
  if (var575)
    return 0;
  vamp::FloatVector<8, 1> var576 = arg5[4ll];
  var234 = var576.sin();
  var235 = var576.cos();
  var218 = var235;
  var219 = -(var234);
  var222 = var234;
  var223 = var235;
  vamp::FloatVector<8, 1> var577;
  var577 = var577 + (1.0f * var218);
  var453 = var577;
  vamp::FloatVector<8, 1> var579;
  var579 = var579 + (1.0f * var219);
  var454 = var579;
  vamp::FloatVector<8, 1> var581;
  var581 = var581 + (1.0f * var222);
  var457 = var581;
  vamp::FloatVector<8, 1> var583;
  var583 = var583 + (1.0f * var223);
  var458 = var583;
  vamp::FloatVector<8, 1> var585;
  var585 = var585 + (var326 * var453);
  var585 = var585 + (var327 * var457);
  var344 = var585;
  vamp::FloatVector<8, 1> var587;
  var587 = var587 + (var326 * var454);
  var587 = var587 + (var327 * var458);
  var345 = var587;
  vamp::FloatVector<8, 1> var589;
  var589 = var589 + (var328 * 1.0f);
  var346 = var589;
  vamp::FloatVector<8, 1> var591;
  var591 = var591 + (var327 * 0.0930000022053719f);
  var591 = var591 + (var329 * 1.0f);
  var347 = var591;
  vamp::FloatVector<8, 1> var593;
  var593 = var593 + (var330 * var453);
  var593 = var593 + (var331 * var457);
  var348 = var593;
  vamp::FloatVector<8, 1> var595;
  var595 = var595 + (var330 * var454);
  var595 = var595 + (var331 * var458);
  var349 = var595;
  vamp::FloatVector<8, 1> var597;
  var597 = var597 + (var332 * 1.0f);
  var350 = var597;
  vamp::FloatVector<8, 1> var599;
  var599 = var599 + (var331 * 0.0930000022053719f);
  var599 = var599 + (var333 * 1.0f);
  var351 = var599;
  vamp::FloatVector<8, 1> var601;
  var601 = var601 + (var334 * var453);
  var352 = var601;
  vamp::FloatVector<8, 1> var603;
  var603 = var603 + (var334 * var454);
  var353 = var603;
  vamp::FloatVector<8, 1> var605;
  var605 = var605 + (var336 * 1.0f);
  var354 = var605;
  vamp::FloatVector<8, 1> var607;
  var607 = var607 + (var337 * 1.0f);
  var355 = var607;
  var380[5ll] = ((var344 * 0.0f) + (var345 * 0.0f)) + (var346 * 0.0900000035762787f);
  var381[5ll] = ((var348 * 0.0f) + (var349 * 0.0f)) + (var350 * 0.0900000035762787f);
  var382[5ll] = ((var352 * 0.0f) + (var353 * 0.0f)) + (var354 * 0.0900000035762787f);
  var380[5ll] = var380[5ll] + var347;
  var381[5ll] = var381[5ll] + var351;
  var382[5ll] = var382[5ll] + var355;
  var383[5ll] = 0.0700000002980232f;
  var384[5ll] = 3ll;
  var390[0ll] = ((var344 * 0.0f) + (var345 * 0.0299999993294477f)) + (var346 * 0.0900000035762787f);
  var407[0ll] = ((var348 * 0.0f) + (var349 * 0.0299999993294477f)) + (var350 * 0.0900000035762787f);
  var424[0ll] = ((var352 * 0.0f) + (var353 * 0.0299999993294477f)) + (var354 * 0.0900000035762787f);
  var390[0ll] = var390[0ll] + var347;
  var407[0ll] = var407[0ll] + var351;
  var424[0ll] = var424[0ll] + var355;
  var441[0ll] = 0.0399999991059303f;
  var390[1ll] = ((var344 * 0.0f) + (var345 * -0.0299999993294477f)) + (var346 * 0.0900000035762787f);
  var407[1ll] = ((var348 * 0.0f) + (var349 * -0.0299999993294477f)) + (var350 * 0.0900000035762787f);
  var424[1ll] = ((var352 * 0.0f) + (var353 * -0.0299999993294477f)) + (var354 * 0.0900000035762787f);
  var390[1ll] = var390[1ll] + var347;
  var407[1ll] = var407[1ll] + var351;
  var424[1ll] = var424[1ll] + var355;
  var441[1ll] = 0.0399999991059303f;
  var390[2ll] = ((var344 * 0.0f) + (var345 * 0.0f)) + (var346 * 0.0900000035762787f);
  var407[2ll] = ((var348 * 0.0f) + (var349 * 0.0f)) + (var350 * 0.0900000035762787f);
  var424[2ll] = ((var352 * 0.0f) + (var353 * 0.0f)) + (var354 * 0.0900000035762787f);
  var390[2ll] = var390[2ll] + var347;
  var407[2ll] = var407[2ll] + var351;
  var424[2ll] = var424[2ll] + var355;
  var441[2ll] = 0.0399999991059303f;
  int var609;
  var609 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 5ll, var380[5ll], var381[5ll], var382[5ll], var383[5ll], var384[5ll], var390, var407, var424, var441);
  if (var609)
    return 0; //collision pair: 0,5 : base_link_0,wrist_2_link_0
  var609 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 5ll, var380[5ll], var381[5ll], var382[5ll], var383[5ll], var384[5ll], var390, var407, var424, var441);
  if (var609)
    return 0; //collision pair: 1,5 : shoulder_link_0,wrist_2_link_0
  var609 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 5ll, var380[5ll], var381[5ll], var382[5ll], var383[5ll], var384[5ll], var390, var407, var424, var441);
  if (var609)
    return 0; //collision pair: 2,5 : upper_arm_link_0,wrist_2_link_0
  var609 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 5ll, var380[5ll], var381[5ll], var382[5ll], var383[5ll], var384[5ll], var390, var407, var424, var441);
  if (var609)
    return 0; //collision pair: 3,5 : forearm_link_0,wrist_2_link_0
  var609 = ctup_runtime::link_vs_environment_collision(var380[5ll], var381[5ll], var382[5ll], var383[5ll], var384[5ll], var390, var407, var424, var441, arg4);
  if (var609)
    return 0;
  vamp::FloatVector<8, 1> var610 = arg5[5ll];
  var252 = var610.sin();
  var253 = var610.cos();
  var236 = var253;
  var238 = var252;
  var244 = -(var252);
  var246 = var253;
  vamp::FloatVector<8, 1> var611;
  var611 = var611 + (1.0f * var236);
  var453 = var611;
  vamp::FloatVector<8, 1> var613;
  var613 = var613 + (1.0f * var238);
  var455 = var613;
  vamp::FloatVector<8, 1> var615;
  var615 = var615 + (1.0f * var244);
  var461 = var615;
  vamp::FloatVector<8, 1> var617;
  var617 = var617 + (1.0f * var246);
  var463 = var617;
  vamp::FloatVector<8, 1> var619;
  var619 = var619 + (var344 * var453);
  var619 = var619 + (var346 * var461);
  var362 = var619;
  vamp::FloatVector<8, 1> var621;
  var621 = var621 + (var345 * 1.0f);
  var363 = var621;
  vamp::FloatVector<8, 1> var623;
  var623 = var623 + (var344 * var455);
  var623 = var623 + (var346 * var463);
  var364 = var623;
  vamp::FloatVector<8, 1> var625;
  var625 = var625 + (var346 * 0.094650000333786f);
  var625 = var625 + (var347 * 1.0f);
  var365 = var625;
  vamp::FloatVector<8, 1> var627;
  var627 = var627 + (var348 * var453);
  var627 = var627 + (var350 * var461);
  var366 = var627;
  vamp::FloatVector<8, 1> var629;
  var629 = var629 + (var349 * 1.0f);
  var367 = var629;
  vamp::FloatVector<8, 1> var631;
  var631 = var631 + (var348 * var455);
  var631 = var631 + (var350 * var463);
  var368 = var631;
  vamp::FloatVector<8, 1> var633;
  var633 = var633 + (var350 * 0.094650000333786f);
  var633 = var633 + (var351 * 1.0f);
  var369 = var633;
  vamp::FloatVector<8, 1> var635;
  var635 = var635 + (var352 * var453);
  var635 = var635 + (var354 * var461);
  var370 = var635;
  vamp::FloatVector<8, 1> var637;
  var637 = var637 + (var353 * 1.0f);
  var371 = var637;
  vamp::FloatVector<8, 1> var639;
  var639 = var639 + (var352 * var455);
  var639 = var639 + (var354 * var463);
  var372 = var639;
  vamp::FloatVector<8, 1> var641;
  var641 = var641 + (var354 * 0.094650000333786f);
  var641 = var641 + (var355 * 1.0f);
  var373 = var641;
  var380[6ll] = ((var362 * 0.0f) + (var363 * 0.0599999986588955f)) + (var364 * 0.0f);
  var381[6ll] = ((var366 * 0.0f) + (var367 * 0.0599999986588955f)) + (var368 * 0.0f);
  var382[6ll] = ((var370 * 0.0f) + (var371 * 0.0599999986588955f)) + (var372 * 0.0f);
  var380[6ll] = var380[6ll] + var365;
  var381[6ll] = var381[6ll] + var369;
  var382[6ll] = var382[6ll] + var373;
  var383[6ll] = 0.0399999991059303f;
  var384[6ll] = 1ll;
  var391[0ll] = ((var362 * 0.0f) + (var363 * 0.0599999986588955f)) + (var364 * 0.0f);
  var408[0ll] = ((var366 * 0.0f) + (var367 * 0.0599999986588955f)) + (var368 * 0.0f);
  var425[0ll] = ((var370 * 0.0f) + (var371 * 0.0599999986588955f)) + (var372 * 0.0f);
  var391[0ll] = var391[0ll] + var365;
  var408[0ll] = var408[0ll] + var369;
  var425[0ll] = var425[0ll] + var373;
  var442[0ll] = 0.0399999991059303f;
  int var643;
  var643 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 6ll, var380[6ll], var381[6ll], var382[6ll], var383[6ll], var384[6ll], var391, var408, var425, var442);
  if (var643)
    return 0; //collision pair: 0,6 : base_link_0,wrist_3_link_0
  var643 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 6ll, var380[6ll], var381[6ll], var382[6ll], var383[6ll], var384[6ll], var391, var408, var425, var442);
  if (var643)
    return 0; //collision pair: 1,6 : shoulder_link_0,wrist_3_link_0
  var643 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 6ll, var380[6ll], var381[6ll], var382[6ll], var383[6ll], var384[6ll], var391, var408, var425, var442);
  if (var643)
    return 0; //collision pair: 2,6 : upper_arm_link_0,wrist_3_link_0
  var643 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 6ll, var380[6ll], var381[6ll], var382[6ll], var383[6ll], var384[6ll], var391, var408, var425, var442);
  if (var643)
    return 0; //collision pair: 3,6 : forearm_link_0,wrist_3_link_0
  var643 = ctup_runtime::link_vs_environment_collision(var380[6ll], var381[6ll], var382[6ll], var383[6ll], var384[6ll], var391, var408, var425, var442, arg4);
  if (var643)
    return 0;
  var380[7ll] = ((var362 * 1.59265619004145e-05f) + (var363 * 0.0973000079393387f)) + (var364 * 0.0f);
  var381[7ll] = ((var366 * 1.59265619004145e-05f) + (var367 * 0.0973000079393387f)) + (var368 * 0.0f);
  var382[7ll] = ((var370 * 1.59265619004145e-05f) + (var371 * 0.0973000079393387f)) + (var372 * 0.0f);
  var380[7ll] = var380[7ll] + var365;
  var381[7ll] = var381[7ll] + var369;
  var382[7ll] = var382[7ll] + var373;
  var383[7ll] = 0.0399999991059303f;
  var384[7ll] = 1ll;
  var392[0ll] = ((var362 * 1.59265619004145e-05f) + (var363 * 0.0973000079393387f)) + (var364 * 0.0f);
  var409[0ll] = ((var366 * 1.59265619004145e-05f) + (var367 * 0.0973000079393387f)) + (var368 * 0.0f);
  var426[0ll] = ((var370 * 1.59265619004145e-05f) + (var371 * 0.0973000079393387f)) + (var372 * 0.0f);
  var392[0ll] = var392[0ll] + var365;
  var409[0ll] = var409[0ll] + var369;
  var426[0ll] = var426[0ll] + var373;
  var443[0ll] = 0.0399999991059303f;
  int var644;
  var644 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 7ll, var380[7ll], var381[7ll], var382[7ll], var383[7ll], var384[7ll], var392, var409, var426, var443);
  if (var644)
    return 0; //collision pair: 0,7 : base_link_0,fts_robotside_0
  var644 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 7ll, var380[7ll], var381[7ll], var382[7ll], var383[7ll], var384[7ll], var392, var409, var426, var443);
  if (var644)
    return 0; //collision pair: 1,7 : shoulder_link_0,fts_robotside_0
  var644 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 7ll, var380[7ll], var381[7ll], var382[7ll], var383[7ll], var384[7ll], var392, var409, var426, var443);
  if (var644)
    return 0; //collision pair: 2,7 : upper_arm_link_0,fts_robotside_0
  var644 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 7ll, var380[7ll], var381[7ll], var382[7ll], var383[7ll], var384[7ll], var392, var409, var426, var443);
  if (var644)
    return 0; //collision pair: 3,7 : forearm_link_0,fts_robotside_0
  var644 = ctup_runtime::self_collision_link_vs_link(4ll, var380[4ll], var381[4ll], var382[4ll], var383[4ll], var384[4ll], var389, var406, var423, var440, 7ll, var380[7ll], var381[7ll], var382[7ll], var383[7ll], var384[7ll], var392, var409, var426, var443);
  if (var644)
    return 0; //collision pair: 4,7 : wrist_1_link_0,fts_robotside_0
  var644 = ctup_runtime::self_collision_link_vs_link(5ll, var380[5ll], var381[5ll], var382[5ll], var383[5ll], var384[5ll], var390, var407, var424, var441, 7ll, var380[7ll], var381[7ll], var382[7ll], var383[7ll], var384[7ll], var392, var409, var426, var443);
  if (var644)
    return 0; //collision pair: 5,7 : wrist_2_link_0,fts_robotside_0
  var644 = ctup_runtime::link_vs_environment_collision(var380[7ll], var381[7ll], var382[7ll], var383[7ll], var384[7ll], var392, var409, var426, var443, arg4);
  if (var644)
    return 0;
  var380[8ll] = ((var362 * -3.18529237119947e-05f) + (var363 * 0.157299980521202f)) + (var364 * 0.000531853060238063f);
  var381[8ll] = ((var366 * -3.18529237119947e-05f) + (var367 * 0.157299980521202f)) + (var368 * 0.000531853060238063f);
  var382[8ll] = ((var370 * -3.18529237119947e-05f) + (var371 * 0.157299980521202f)) + (var372 * 0.000531853060238063f);
  var380[8ll] = var380[8ll] + var365;
  var381[8ll] = var381[8ll] + var369;
  var382[8ll] = var382[8ll] + var373;
  var383[8ll] = 0.0599999986588955f;
  var384[8ll] = 2ll;
  var393[0ll] = ((var362 * -4.77794164908119e-05f) + (var363 * 0.177299961447716f)) + (var364 * 0.000547779607586563f);
  var410[0ll] = ((var366 * -4.77794164908119e-05f) + (var367 * 0.177299961447716f)) + (var368 * 0.000547779607586563f);
  var427[0ll] = ((var370 * -4.77794164908119e-05f) + (var371 * 0.177299961447716f)) + (var372 * 0.000547779607586563f);
  var393[0ll] = var393[0ll] + var365;
  var410[0ll] = var410[0ll] + var369;
  var427[0ll] = var427[0ll] + var373;
  var444[0ll] = 0.0399999991059303f;
  var393[1ll] = ((var362 * -1.59264309331775e-05f) + (var363 * 0.137299984693527f)) + (var364 * 0.000515926512889564f);
  var410[1ll] = ((var366 * -1.59264309331775e-05f) + (var367 * 0.137299984693527f)) + (var368 * 0.000515926512889564f);
  var427[1ll] = ((var370 * -1.59264309331775e-05f) + (var371 * 0.137299984693527f)) + (var372 * 0.000515926512889564f);
  var393[1ll] = var393[1ll] + var365;
  var410[1ll] = var410[1ll] + var369;
  var427[1ll] = var427[1ll] + var373;
  var444[1ll] = 0.0399999991059303f;
  int var645;
  var645 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 8ll, var380[8ll], var381[8ll], var382[8ll], var383[8ll], var384[8ll], var393, var410, var427, var444);
  if (var645)
    return 0; //collision pair: 0,8 : base_link_0,robotiq_85_base_link_0
  var645 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 8ll, var380[8ll], var381[8ll], var382[8ll], var383[8ll], var384[8ll], var393, var410, var427, var444);
  if (var645)
    return 0; //collision pair: 1,8 : shoulder_link_0,robotiq_85_base_link_0
  var645 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 8ll, var380[8ll], var381[8ll], var382[8ll], var383[8ll], var384[8ll], var393, var410, var427, var444);
  if (var645)
    return 0; //collision pair: 2,8 : upper_arm_link_0,robotiq_85_base_link_0
  var645 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 8ll, var380[8ll], var381[8ll], var382[8ll], var383[8ll], var384[8ll], var393, var410, var427, var444);
  if (var645)
    return 0; //collision pair: 3,8 : forearm_link_0,robotiq_85_base_link_0
  var645 = ctup_runtime::link_vs_environment_collision(var380[8ll], var381[8ll], var382[8ll], var383[8ll], var384[8ll], var393, var410, var427, var444, arg4);
  if (var645)
    return 0;
  var380[9ll] = ((var362 * 0.0326288715004921f) + (var363 * 0.206633478403091f)) + (var364 * 0.000571117969229817f);
  var381[9ll] = ((var366 * 0.0326288715004921f) + (var367 * 0.206633478403091f)) + (var368 * 0.000571117969229817f);
  var382[9ll] = ((var370 * 0.0326288715004921f) + (var371 * 0.206633478403091f)) + (var372 * 0.000571117969229817f);
  var380[9ll] = var380[9ll] + var365;
  var381[9ll] = var381[9ll] + var369;
  var382[9ll] = var382[9ll] + var373;
  var383[9ll] = 0.0199999995529652f;
  var384[9ll] = 1ll;
  var394[0ll] = ((var362 * 0.0326288715004921f) + (var363 * 0.206633478403091f)) + (var364 * 0.000571117969229817f);
  var411[0ll] = ((var366 * 0.0326288715004921f) + (var367 * 0.206633478403091f)) + (var368 * 0.000571117969229817f);
  var428[0ll] = ((var370 * 0.0326288715004921f) + (var371 * 0.206633478403091f)) + (var372 * 0.000571117969229817f);
  var394[0ll] = var394[0ll] + var365;
  var411[0ll] = var411[0ll] + var369;
  var428[0ll] = var428[0ll] + var373;
  var445[0ll] = 0.0199999995529652f;
  int var646;
  var646 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 9ll, var380[9ll], var381[9ll], var382[9ll], var383[9ll], var384[9ll], var394, var411, var428, var445);
  if (var646)
    return 0; //collision pair: 0,9 : base_link_0,robotiq_85_left_inner_knuckle_link_0
  var646 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 9ll, var380[9ll], var381[9ll], var382[9ll], var383[9ll], var384[9ll], var394, var411, var428, var445);
  if (var646)
    return 0; //collision pair: 1,9 : shoulder_link_0,robotiq_85_left_inner_knuckle_link_0
  var646 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 9ll, var380[9ll], var381[9ll], var382[9ll], var383[9ll], var384[9ll], var394, var411, var428, var445);
  if (var646)
    return 0; //collision pair: 2,9 : upper_arm_link_0,robotiq_85_left_inner_knuckle_link_0
  var646 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 9ll, var380[9ll], var381[9ll], var382[9ll], var383[9ll], var384[9ll], var394, var411, var428, var445);
  if (var646)
    return 0; //collision pair: 3,9 : forearm_link_0,robotiq_85_left_inner_knuckle_link_0
  var646 = ctup_runtime::link_vs_environment_collision(var380[9ll], var381[9ll], var382[9ll], var383[9ll], var384[9ll], var394, var411, var428, var445, arg4);
  if (var646)
    return 0;
  var380[10ll] = ((var362 * 0.047183521091938f) + (var363 * 0.245142087340355f)) + (var364 * 0.000601774139795452f);
  var381[10ll] = ((var366 * 0.047183521091938f) + (var367 * 0.245142087340355f)) + (var368 * 0.000601774139795452f);
  var382[10ll] = ((var370 * 0.047183521091938f) + (var371 * 0.245142087340355f)) + (var372 * 0.000601774139795452f);
  var380[10ll] = var380[10ll] + var365;
  var381[10ll] = var381[10ll] + var369;
  var382[10ll] = var382[10ll] + var373;
  var383[10ll] = 0.0329999998211861f;
  var384[10ll] = 2ll;
  var395[0ll] = ((var362 * 0.0471739657223225f) + (var363 * 0.257142096757889f)) + (var364 * 0.000611330091487616f);
  var412[0ll] = ((var366 * 0.0471739657223225f) + (var367 * 0.257142096757889f)) + (var368 * 0.000611330091487616f);
  var429[0ll] = ((var370 * 0.0471739657223225f) + (var371 * 0.257142096757889f)) + (var372 * 0.000611330091487616f);
  var395[0ll] = var395[0ll] + var365;
  var412[0ll] = var412[0ll] + var369;
  var429[0ll] = var429[0ll] + var373;
  var446[0ll] = 0.0199999995529652f;
  var395[1ll] = ((var362 * 0.0471938736736774f) + (var363 * 0.232142105698586f)) + (var364 * 0.000591421907301992f);
  var412[1ll] = ((var366 * 0.0471938736736774f) + (var367 * 0.232142105698586f)) + (var368 * 0.000591421907301992f);
  var429[1ll] = ((var370 * 0.0471938736736774f) + (var371 * 0.232142105698586f)) + (var372 * 0.000591421907301992f);
  var395[1ll] = var395[1ll] + var365;
  var412[1ll] = var412[1ll] + var369;
  var429[1ll] = var429[1ll] + var373;
  var446[1ll] = 0.0199999995529652f;
  int var647;
  var647 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 10ll, var380[10ll], var381[10ll], var382[10ll], var383[10ll], var384[10ll], var395, var412, var429, var446);
  if (var647)
    return 0; //collision pair: 0,10 : base_link_0,robotiq_85_left_finger_tip_link_0
  var647 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 10ll, var380[10ll], var381[10ll], var382[10ll], var383[10ll], var384[10ll], var395, var412, var429, var446);
  if (var647)
    return 0; //collision pair: 1,10 : shoulder_link_0,robotiq_85_left_finger_tip_link_0
  var647 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 10ll, var380[10ll], var381[10ll], var382[10ll], var383[10ll], var384[10ll], var395, var412, var429, var446);
  if (var647)
    return 0; //collision pair: 2,10 : upper_arm_link_0,robotiq_85_left_finger_tip_link_0
  var647 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 10ll, var380[10ll], var381[10ll], var382[10ll], var383[10ll], var384[10ll], var395, var412, var429, var446);
  if (var647)
    return 0; //collision pair: 3,10 : forearm_link_0,robotiq_85_left_finger_tip_link_0
  var647 = ctup_runtime::link_vs_environment_collision(var380[10ll], var381[10ll], var382[10ll], var383[10ll], var384[10ll], var395, var412, var429, var446, arg4);
  if (var647)
    return 0;
  var380[11ll] = ((var362 * 0.0305511318147182f) + (var363 * 0.180116340517998f)) + (var364 * 0.000550002965610474f);
  var381[11ll] = ((var366 * 0.0305511318147182f) + (var367 * 0.180116340517998f)) + (var368 * 0.000550002965610474f);
  var382[11ll] = ((var370 * 0.0305511318147182f) + (var371 * 0.180116340517998f)) + (var372 * 0.000550002965610474f);
  var380[11ll] = var380[11ll] + var365;
  var381[11ll] = var381[11ll] + var369;
  var382[11ll] = var382[11ll] + var373;
  var383[11ll] = 0.0199999995529652f;
  var384[11ll] = 1ll;
  var396[0ll] = ((var362 * 0.0305511318147182f) + (var363 * 0.180116340517998f)) + (var364 * 0.000550002965610474f);
  var413[0ll] = ((var366 * 0.0305511318147182f) + (var367 * 0.180116340517998f)) + (var368 * 0.000550002965610474f);
  var430[0ll] = ((var370 * 0.0305511318147182f) + (var371 * 0.180116340517998f)) + (var372 * 0.000550002965610474f);
  var396[0ll] = var396[0ll] + var365;
  var413[0ll] = var413[0ll] + var369;
  var430[0ll] = var430[0ll] + var373;
  var447[0ll] = 0.0199999995529652f;
  int var648;
  var648 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 11ll, var380[11ll], var381[11ll], var382[11ll], var383[11ll], var384[11ll], var396, var413, var430, var447);
  if (var648)
    return 0; //collision pair: 0,11 : base_link_0,robotiq_85_left_knuckle_link_0
  var648 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 11ll, var380[11ll], var381[11ll], var382[11ll], var383[11ll], var384[11ll], var396, var413, var430, var447);
  if (var648)
    return 0; //collision pair: 1,11 : shoulder_link_0,robotiq_85_left_knuckle_link_0
  var648 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 11ll, var380[11ll], var381[11ll], var382[11ll], var383[11ll], var384[11ll], var396, var413, var430, var447);
  if (var648)
    return 0; //collision pair: 2,11 : upper_arm_link_0,robotiq_85_left_knuckle_link_0
  var648 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 11ll, var380[11ll], var381[11ll], var382[11ll], var383[11ll], var384[11ll], var396, var413, var430, var447);
  if (var648)
    return 0; //collision pair: 3,11 : forearm_link_0,robotiq_85_left_knuckle_link_0
  var648 = ctup_runtime::link_vs_environment_collision(var380[11ll], var381[11ll], var382[11ll], var383[11ll], var384[11ll], var396, var413, var430, var447, arg4);
  if (var648)
    return 0;
  var380[12ll] = ((var362 * 0.0622277781367302f) + (var363 * 0.198207601904869f)) + (var364 * 0.000564389454666525f);
  var381[12ll] = ((var366 * 0.0622277781367302f) + (var367 * 0.198207601904869f)) + (var368 * 0.000564389454666525f);
  var382[12ll] = ((var370 * 0.0622277781367302f) + (var371 * 0.198207601904869f)) + (var372 * 0.000564389454666525f);
  var380[12ll] = var380[12ll] + var365;
  var381[12ll] = var381[12ll] + var369;
  var382[12ll] = var382[12ll] + var373;
  var383[12ll] = 0.0350000001490116f;
  var384[12ll] = 3ll;
  var397[0ll] = ((var362 * 0.0622118525207043f) + (var363 * 0.218207597732544f)) + (var364 * 0.000580315943807364f);
  var414[0ll] = ((var366 * 0.0622118525207043f) + (var367 * 0.218207597732544f)) + (var368 * 0.000580315943807364f);
  var431[0ll] = ((var370 * 0.0622118525207043f) + (var371 * 0.218207597732544f)) + (var372 * 0.000580315943807364f);
  var397[0ll] = var397[0ll] + var365;
  var414[0ll] = var414[0ll] + var369;
  var431[0ll] = var431[0ll] + var373;
  var448[0ll] = 0.0149999996647239f;
  var397[1ll] = ((var362 * 0.0622437074780464f) + (var363 * 0.178207620978355f)) + (var364 * 0.000548462907318026f);
  var414[1ll] = ((var366 * 0.0622437074780464f) + (var367 * 0.178207620978355f)) + (var368 * 0.000548462907318026f);
  var431[1ll] = ((var370 * 0.0622437074780464f) + (var371 * 0.178207620978355f)) + (var372 * 0.000548462907318026f);
  var397[1ll] = var397[1ll] + var365;
  var414[1ll] = var414[1ll] + var369;
  var431[1ll] = var431[1ll] + var373;
  var448[1ll] = 0.0149999996647239f;
  var397[2ll] = ((var362 * 0.0622277781367302f) + (var363 * 0.198207601904869f)) + (var364 * 0.000564389454666525f);
  var414[2ll] = ((var366 * 0.0622277781367302f) + (var367 * 0.198207601904869f)) + (var368 * 0.000564389454666525f);
  var431[2ll] = ((var370 * 0.0622277781367302f) + (var371 * 0.198207601904869f)) + (var372 * 0.000564389454666525f);
  var397[2ll] = var397[2ll] + var365;
  var414[2ll] = var414[2ll] + var369;
  var431[2ll] = var431[2ll] + var373;
  var448[2ll] = 0.0149999996647239f;
  int var649;
  var649 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 12ll, var380[12ll], var381[12ll], var382[12ll], var383[12ll], var384[12ll], var397, var414, var431, var448);
  if (var649)
    return 0; //collision pair: 0,12 : base_link_0,robotiq_85_left_finger_link_0
  var649 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 12ll, var380[12ll], var381[12ll], var382[12ll], var383[12ll], var384[12ll], var397, var414, var431, var448);
  if (var649)
    return 0; //collision pair: 1,12 : shoulder_link_0,robotiq_85_left_finger_link_0
  var649 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 12ll, var380[12ll], var381[12ll], var382[12ll], var383[12ll], var384[12ll], var397, var414, var431, var448);
  if (var649)
    return 0; //collision pair: 2,12 : upper_arm_link_0,robotiq_85_left_finger_link_0
  var649 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 12ll, var380[12ll], var381[12ll], var382[12ll], var383[12ll], var384[12ll], var397, var414, var431, var448);
  if (var649)
    return 0; //collision pair: 3,12 : forearm_link_0,robotiq_85_left_finger_link_0
  var649 = ctup_runtime::link_vs_environment_collision(var380[12ll], var381[12ll], var382[12ll], var383[12ll], var384[12ll], var397, var414, var431, var448, arg4);
  if (var649)
    return 0;
  var380[13ll] = ((var362 * -0.0327711068093777f) + (var363 * 0.206581398844719f)) + (var364 * 0.000571117969229817f);
  var381[13ll] = ((var366 * -0.0327711068093777f) + (var367 * 0.206581398844719f)) + (var368 * 0.000571117969229817f);
  var382[13ll] = ((var370 * -0.0327711068093777f) + (var371 * 0.206581398844719f)) + (var372 * 0.000571117969229817f);
  var380[13ll] = var380[13ll] + var365;
  var381[13ll] = var381[13ll] + var369;
  var382[13ll] = var382[13ll] + var373;
  var383[13ll] = 0.0199999995529652f;
  var384[13ll] = 1ll;
  var398[0ll] = ((var362 * -0.0327711068093777f) + (var363 * 0.206581398844719f)) + (var364 * 0.000571117969229817f);
  var415[0ll] = ((var366 * -0.0327711068093777f) + (var367 * 0.206581398844719f)) + (var368 * 0.000571117969229817f);
  var432[0ll] = ((var370 * -0.0327711068093777f) + (var371 * 0.206581398844719f)) + (var372 * 0.000571117969229817f);
  var398[0ll] = var398[0ll] + var365;
  var415[0ll] = var415[0ll] + var369;
  var432[0ll] = var432[0ll] + var373;
  var449[0ll] = 0.0199999995529652f;
  int var650;
  var650 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 13ll, var380[13ll], var381[13ll], var382[13ll], var383[13ll], var384[13ll], var398, var415, var432, var449);
  if (var650)
    return 0; //collision pair: 0,13 : base_link_0,robotiq_85_right_inner_knuckle_link_0
  var650 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 13ll, var380[13ll], var381[13ll], var382[13ll], var383[13ll], var384[13ll], var398, var415, var432, var449);
  if (var650)
    return 0; //collision pair: 1,13 : shoulder_link_0,robotiq_85_right_inner_knuckle_link_0
  var650 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 13ll, var380[13ll], var381[13ll], var382[13ll], var383[13ll], var384[13ll], var398, var415, var432, var449);
  if (var650)
    return 0; //collision pair: 2,13 : upper_arm_link_0,robotiq_85_right_inner_knuckle_link_0
  var650 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 13ll, var380[13ll], var381[13ll], var382[13ll], var383[13ll], var384[13ll], var398, var415, var432, var449);
  if (var650)
    return 0; //collision pair: 3,13 : forearm_link_0,robotiq_85_right_inner_knuckle_link_0
  var650 = ctup_runtime::link_vs_environment_collision(var380[13ll], var381[13ll], var382[13ll], var383[13ll], var384[13ll], var398, var415, var432, var449, arg4);
  if (var650)
    return 0;
  var380[14ll] = ((var362 * -0.0469080917537212f) + (var363 * 0.245427533984184f)) + (var364 * 0.000602061103563756f);
  var381[14ll] = ((var366 * -0.0469080917537212f) + (var367 * 0.245427533984184f)) + (var368 * 0.000602061103563756f);
  var382[14ll] = ((var370 * -0.0469080917537212f) + (var371 * 0.245427533984184f)) + (var372 * 0.000602061103563756f);
  var380[14ll] = var380[14ll] + var365;
  var381[14ll] = var381[14ll] + var369;
  var382[14ll] = var382[14ll] + var373;
  var383[14ll] = 0.0329999998211861f;
  var384[14ll] = 2ll;
  var399[0ll] = ((var362 * -0.0469176508486271f) + (var363 * 0.257427513599396f)) + (var364 * 0.00061161705525592f);
  var416[0ll] = ((var366 * -0.0469176508486271f) + (var367 * 0.257427513599396f)) + (var368 * 0.00061161705525592f);
  var433[0ll] = ((var370 * -0.0469176508486271f) + (var371 * 0.257427513599396f)) + (var372 * 0.00061161705525592f);
  var399[0ll] = var399[0ll] + var365;
  var416[0ll] = var416[0ll] + var369;
  var433[0ll] = var433[0ll] + var373;
  var450[0ll] = 0.0199999995529652f;
  var399[1ll] = ((var362 * -0.0468977428972721f) + (var363 * 0.232427537441254f)) + (var364 * 0.000591708871070296f);
  var416[1ll] = ((var366 * -0.0468977428972721f) + (var367 * 0.232427537441254f)) + (var368 * 0.000591708871070296f);
  var433[1ll] = ((var370 * -0.0468977428972721f) + (var371 * 0.232427537441254f)) + (var372 * 0.000591708871070296f);
  var399[1ll] = var399[1ll] + var365;
  var416[1ll] = var416[1ll] + var369;
  var433[1ll] = var433[1ll] + var373;
  var450[1ll] = 0.0199999995529652f;
  int var651;
  var651 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 14ll, var380[14ll], var381[14ll], var382[14ll], var383[14ll], var384[14ll], var399, var416, var433, var450);
  if (var651)
    return 0; //collision pair: 0,14 : base_link_0,robotiq_85_right_finger_tip_link_0
  var651 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 14ll, var380[14ll], var381[14ll], var382[14ll], var383[14ll], var384[14ll], var399, var416, var433, var450);
  if (var651)
    return 0; //collision pair: 1,14 : shoulder_link_0,robotiq_85_right_finger_tip_link_0
  var651 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 14ll, var380[14ll], var381[14ll], var382[14ll], var383[14ll], var384[14ll], var399, var416, var433, var450);
  if (var651)
    return 0; //collision pair: 2,14 : upper_arm_link_0,robotiq_85_right_finger_tip_link_0
  var651 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 14ll, var380[14ll], var381[14ll], var382[14ll], var383[14ll], var384[14ll], var399, var416, var433, var450);
  if (var651)
    return 0; //collision pair: 3,14 : forearm_link_0,robotiq_85_right_finger_tip_link_0
  var651 = ctup_runtime::link_vs_environment_collision(var380[14ll], var381[14ll], var382[14ll], var383[14ll], var384[14ll], var399, var416, var433, var450, arg4);
  if (var651)
    return 0;
  var380[15ll] = ((var362 * -0.0306511372327805f) + (var363 * 0.180067613720894f)) + (var364 * 0.000550002965610474f);
  var381[15ll] = ((var366 * -0.0306511372327805f) + (var367 * 0.180067613720894f)) + (var368 * 0.000550002965610474f);
  var382[15ll] = ((var370 * -0.0306511372327805f) + (var371 * 0.180067613720894f)) + (var372 * 0.000550002965610474f);
  var380[15ll] = var380[15ll] + var365;
  var381[15ll] = var381[15ll] + var369;
  var382[15ll] = var382[15ll] + var373;
  var383[15ll] = 0.0199999995529652f;
  var384[15ll] = 1ll;
  var400[0ll] = ((var362 * -0.0306511372327805f) + (var363 * 0.180067613720894f)) + (var364 * 0.000550002965610474f);
  var417[0ll] = ((var366 * -0.0306511372327805f) + (var367 * 0.180067613720894f)) + (var368 * 0.000550002965610474f);
  var434[0ll] = ((var370 * -0.0306511372327805f) + (var371 * 0.180067613720894f)) + (var372 * 0.000550002965610474f);
  var400[0ll] = var400[0ll] + var365;
  var417[0ll] = var417[0ll] + var369;
  var434[0ll] = var434[0ll] + var373;
  var451[0ll] = 0.0199999995529652f;
  int var652;
  var652 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 15ll, var380[15ll], var381[15ll], var382[15ll], var383[15ll], var384[15ll], var400, var417, var434, var451);
  if (var652)
    return 0; //collision pair: 0,15 : base_link_0,robotiq_85_right_knuckle_link_0
  var652 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 15ll, var380[15ll], var381[15ll], var382[15ll], var383[15ll], var384[15ll], var400, var417, var434, var451);
  if (var652)
    return 0; //collision pair: 1,15 : shoulder_link_0,robotiq_85_right_knuckle_link_0
  var652 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 15ll, var380[15ll], var381[15ll], var382[15ll], var383[15ll], var384[15ll], var400, var417, var434, var451);
  if (var652)
    return 0; //collision pair: 2,15 : upper_arm_link_0,robotiq_85_right_knuckle_link_0
  var652 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 15ll, var380[15ll], var381[15ll], var382[15ll], var383[15ll], var384[15ll], var400, var417, var434, var451);
  if (var652)
    return 0; //collision pair: 3,15 : forearm_link_0,robotiq_85_right_knuckle_link_0
  var652 = ctup_runtime::link_vs_environment_collision(var380[15ll], var381[15ll], var382[15ll], var383[15ll], var384[15ll], var400, var417, var434, var451, arg4);
  if (var652)
    return 0;
  var380[16ll] = ((var362 * -0.062375370413065f) + (var363 * 0.198440983891487f)) + (var364 * 0.000564654299523681f);
  var381[16ll] = ((var366 * -0.062375370413065f) + (var367 * 0.198440983891487f)) + (var368 * 0.000564654299523681f);
  var382[16ll] = ((var370 * -0.062375370413065f) + (var371 * 0.198440983891487f)) + (var372 * 0.000564654299523681f);
  var380[16ll] = var380[16ll] + var365;
  var381[16ll] = var381[16ll] + var369;
  var382[16ll] = var382[16ll] + var373;
  var383[16ll] = 0.0350000001490116f;
  var384[16ll] = 3ll;
  var401[0ll] = ((var362 * -0.0623912960290909f) + (var363 * 0.218440979719162f)) + (var364 * 0.000580580846872181f);
  var418[0ll] = ((var366 * -0.0623912960290909f) + (var367 * 0.218440979719162f)) + (var368 * 0.000580580846872181f);
  var435[0ll] = ((var370 * -0.0623912960290909f) + (var371 * 0.218440979719162f)) + (var372 * 0.000580580846872181f);
  var401[0ll] = var401[0ll] + var365;
  var418[0ll] = var418[0ll] + var369;
  var435[0ll] = var435[0ll] + var373;
  var452[0ll] = 0.0149999996647239f;
  var401[1ll] = ((var362 * -0.062359444797039f) + (var363 * 0.178441002964973f)) + (var364 * 0.000548727752175182f);
  var418[1ll] = ((var366 * -0.062359444797039f) + (var367 * 0.178441002964973f)) + (var368 * 0.000548727752175182f);
  var435[1ll] = ((var370 * -0.062359444797039f) + (var371 * 0.178441002964973f)) + (var372 * 0.000548727752175182f);
  var401[1ll] = var401[1ll] + var365;
  var418[1ll] = var418[1ll] + var369;
  var435[1ll] = var435[1ll] + var373;
  var452[1ll] = 0.0149999996647239f;
  var401[2ll] = ((var362 * -0.062375370413065f) + (var363 * 0.198440983891487f)) + (var364 * 0.000564654299523681f);
  var418[2ll] = ((var366 * -0.062375370413065f) + (var367 * 0.198440983891487f)) + (var368 * 0.000564654299523681f);
  var435[2ll] = ((var370 * -0.062375370413065f) + (var371 * 0.198440983891487f)) + (var372 * 0.000564654299523681f);
  var401[2ll] = var401[2ll] + var365;
  var418[2ll] = var418[2ll] + var369;
  var435[2ll] = var435[2ll] + var373;
  var452[2ll] = 0.0149999996647239f;
  int var653;
  var653 = ctup_runtime::self_collision_link_vs_link(0ll, var380[0ll], var381[0ll], var382[0ll], var383[0ll], var384[0ll], var385, var402, var419, var436, 16ll, var380[16ll], var381[16ll], var382[16ll], var383[16ll], var384[16ll], var401, var418, var435, var452);
  if (var653)
    return 0; //collision pair: 0,16 : base_link_0,robotiq_85_right_finger_link_0
  var653 = ctup_runtime::self_collision_link_vs_link(1ll, var380[1ll], var381[1ll], var382[1ll], var383[1ll], var384[1ll], var386, var403, var420, var437, 16ll, var380[16ll], var381[16ll], var382[16ll], var383[16ll], var384[16ll], var401, var418, var435, var452);
  if (var653)
    return 0; //collision pair: 1,16 : shoulder_link_0,robotiq_85_right_finger_link_0
  var653 = ctup_runtime::self_collision_link_vs_link(2ll, var380[2ll], var381[2ll], var382[2ll], var383[2ll], var384[2ll], var387, var404, var421, var438, 16ll, var380[16ll], var381[16ll], var382[16ll], var383[16ll], var384[16ll], var401, var418, var435, var452);
  if (var653)
    return 0; //collision pair: 2,16 : upper_arm_link_0,robotiq_85_right_finger_link_0
  var653 = ctup_runtime::self_collision_link_vs_link(3ll, var380[3ll], var381[3ll], var382[3ll], var383[3ll], var384[3ll], var388, var405, var422, var439, 16ll, var380[16ll], var381[16ll], var382[16ll], var383[16ll], var384[16ll], var401, var418, var435, var452);
  if (var653)
    return 0; //collision pair: 3,16 : forearm_link_0,robotiq_85_right_finger_link_0
  var653 = ctup_runtime::link_vs_environment_collision(var380[16ll], var381[16ll], var382[16ll], var383[16ll], var384[16ll], var401, var418, var435, var452, arg4);
  if (var653)
    return 0;
  return 1;
}

}
