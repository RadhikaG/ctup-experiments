// clang-format off

#include "vamp/vector.hh"

#include "rla_fkcc_early_exit/runtime/typedefs.h"

#include "rla_fkcc_early_exit/runtime/vamp_collision.h"

namespace ctup_gen_baxter {

static int fkcc_franken (vamp::collision::Environment<vamp::FloatVector<8, 1>> const& arg4, vamp::FloatVector<8, 14>& arg5) {
  vamp::FloatVector<8, 1> var290;
  vamp::FloatVector<8, 1> var291;
  vamp::FloatVector<8, 1> var294;
  vamp::FloatVector<8, 1> var295;
  vamp::FloatVector<8, 1> var306;
  vamp::FloatVector<8, 1> var307;
  vamp::FloatVector<8, 1> var308;
  vamp::FloatVector<8, 1> var309;
  vamp::FloatVector<8, 1> var312;
  vamp::FloatVector<8, 1> var313;
  vamp::FloatVector<8, 1> var324;
  vamp::FloatVector<8, 1> var325;
  vamp::FloatVector<8, 1> var326;
  vamp::FloatVector<8, 1> var327;
  vamp::FloatVector<8, 1> var330;
  vamp::FloatVector<8, 1> var331;
  vamp::FloatVector<8, 1> var342;
  vamp::FloatVector<8, 1> var343;
  vamp::FloatVector<8, 1> var344;
  vamp::FloatVector<8, 1> var345;
  vamp::FloatVector<8, 1> var348;
  vamp::FloatVector<8, 1> var349;
  vamp::FloatVector<8, 1> var360;
  vamp::FloatVector<8, 1> var361;
  vamp::FloatVector<8, 1> var362;
  vamp::FloatVector<8, 1> var363;
  vamp::FloatVector<8, 1> var366;
  vamp::FloatVector<8, 1> var367;
  vamp::FloatVector<8, 1> var378;
  vamp::FloatVector<8, 1> var379;
  vamp::FloatVector<8, 1> var380;
  vamp::FloatVector<8, 1> var381;
  vamp::FloatVector<8, 1> var384;
  vamp::FloatVector<8, 1> var385;
  vamp::FloatVector<8, 1> var396;
  vamp::FloatVector<8, 1> var397;
  vamp::FloatVector<8, 1> var398;
  vamp::FloatVector<8, 1> var399;
  vamp::FloatVector<8, 1> var402;
  vamp::FloatVector<8, 1> var403;
  vamp::FloatVector<8, 1> var414;
  vamp::FloatVector<8, 1> var415;
  vamp::FloatVector<8, 1> var416;
  vamp::FloatVector<8, 1> var417;
  vamp::FloatVector<8, 1> var420;
  vamp::FloatVector<8, 1> var421;
  vamp::FloatVector<8, 1> var432;
  vamp::FloatVector<8, 1> var433;
  vamp::FloatVector<8, 1> var434;
  vamp::FloatVector<8, 1> var435;
  vamp::FloatVector<8, 1> var438;
  vamp::FloatVector<8, 1> var439;
  vamp::FloatVector<8, 1> var450;
  vamp::FloatVector<8, 1> var451;
  vamp::FloatVector<8, 1> var452;
  vamp::FloatVector<8, 1> var453;
  vamp::FloatVector<8, 1> var456;
  vamp::FloatVector<8, 1> var457;
  vamp::FloatVector<8, 1> var468;
  vamp::FloatVector<8, 1> var469;
  vamp::FloatVector<8, 1> var470;
  vamp::FloatVector<8, 1> var471;
  vamp::FloatVector<8, 1> var474;
  vamp::FloatVector<8, 1> var475;
  vamp::FloatVector<8, 1> var486;
  vamp::FloatVector<8, 1> var487;
  vamp::FloatVector<8, 1> var488;
  vamp::FloatVector<8, 1> var489;
  vamp::FloatVector<8, 1> var492;
  vamp::FloatVector<8, 1> var493;
  vamp::FloatVector<8, 1> var504;
  vamp::FloatVector<8, 1> var505;
  vamp::FloatVector<8, 1> var506;
  vamp::FloatVector<8, 1> var507;
  vamp::FloatVector<8, 1> var510;
  vamp::FloatVector<8, 1> var511;
  vamp::FloatVector<8, 1> var522;
  vamp::FloatVector<8, 1> var523;
  vamp::FloatVector<8, 1> var524;
  vamp::FloatVector<8, 1> var525;
  vamp::FloatVector<8, 1> var528;
  vamp::FloatVector<8, 1> var529;
  vamp::FloatVector<8, 1> var540;
  vamp::FloatVector<8, 1> var541;
  vamp::FloatVector<8, 1> var560;
  vamp::FloatVector<8, 1> var561;
  vamp::FloatVector<8, 1> var564;
  vamp::FloatVector<8, 1> var565;
  vamp::FloatVector<8, 1> var578;
  vamp::FloatVector<8, 1> var579;
  vamp::FloatVector<8, 1> var580;
  vamp::FloatVector<8, 1> var581;
  vamp::FloatVector<8, 1> var582;
  vamp::FloatVector<8, 1> var583;
  vamp::FloatVector<8, 1> var584;
  vamp::FloatVector<8, 1> var585;
  vamp::FloatVector<8, 1> var586;
  vamp::FloatVector<8, 1> var587;
  vamp::FloatVector<8, 1> var596;
  vamp::FloatVector<8, 1> var597;
  vamp::FloatVector<8, 1> var598;
  vamp::FloatVector<8, 1> var599;
  vamp::FloatVector<8, 1> var600;
  vamp::FloatVector<8, 1> var601;
  vamp::FloatVector<8, 1> var602;
  vamp::FloatVector<8, 1> var603;
  vamp::FloatVector<8, 1> var604;
  vamp::FloatVector<8, 1> var605;
  vamp::FloatVector<8, 1> var606;
  vamp::FloatVector<8, 1> var607;
  vamp::FloatVector<8, 1> var614;
  vamp::FloatVector<8, 1> var615;
  vamp::FloatVector<8, 1> var616;
  vamp::FloatVector<8, 1> var617;
  vamp::FloatVector<8, 1> var618;
  vamp::FloatVector<8, 1> var619;
  vamp::FloatVector<8, 1> var620;
  vamp::FloatVector<8, 1> var621;
  vamp::FloatVector<8, 1> var622;
  vamp::FloatVector<8, 1> var623;
  vamp::FloatVector<8, 1> var624;
  vamp::FloatVector<8, 1> var625;
  vamp::FloatVector<8, 1> var632;
  vamp::FloatVector<8, 1> var633;
  vamp::FloatVector<8, 1> var634;
  vamp::FloatVector<8, 1> var635;
  vamp::FloatVector<8, 1> var636;
  vamp::FloatVector<8, 1> var637;
  vamp::FloatVector<8, 1> var638;
  vamp::FloatVector<8, 1> var639;
  vamp::FloatVector<8, 1> var640;
  vamp::FloatVector<8, 1> var641;
  vamp::FloatVector<8, 1> var642;
  vamp::FloatVector<8, 1> var643;
  vamp::FloatVector<8, 1> var650;
  vamp::FloatVector<8, 1> var651;
  vamp::FloatVector<8, 1> var652;
  vamp::FloatVector<8, 1> var653;
  vamp::FloatVector<8, 1> var654;
  vamp::FloatVector<8, 1> var655;
  vamp::FloatVector<8, 1> var656;
  vamp::FloatVector<8, 1> var657;
  vamp::FloatVector<8, 1> var658;
  vamp::FloatVector<8, 1> var659;
  vamp::FloatVector<8, 1> var660;
  vamp::FloatVector<8, 1> var661;
  vamp::FloatVector<8, 1> var668;
  vamp::FloatVector<8, 1> var669;
  vamp::FloatVector<8, 1> var670;
  vamp::FloatVector<8, 1> var671;
  vamp::FloatVector<8, 1> var672;
  vamp::FloatVector<8, 1> var673;
  vamp::FloatVector<8, 1> var674;
  vamp::FloatVector<8, 1> var675;
  vamp::FloatVector<8, 1> var676;
  vamp::FloatVector<8, 1> var677;
  vamp::FloatVector<8, 1> var678;
  vamp::FloatVector<8, 1> var679;
  vamp::FloatVector<8, 1> var686;
  vamp::FloatVector<8, 1> var687;
  vamp::FloatVector<8, 1> var690;
  vamp::FloatVector<8, 1> var691;
  vamp::FloatVector<8, 1> var704;
  vamp::FloatVector<8, 1> var705;
  vamp::FloatVector<8, 1> var706;
  vamp::FloatVector<8, 1> var707;
  vamp::FloatVector<8, 1> var708;
  vamp::FloatVector<8, 1> var709;
  vamp::FloatVector<8, 1> var710;
  vamp::FloatVector<8, 1> var711;
  vamp::FloatVector<8, 1> var712;
  vamp::FloatVector<8, 1> var713;
  vamp::FloatVector<8, 1> var722;
  vamp::FloatVector<8, 1> var723;
  vamp::FloatVector<8, 1> var724;
  vamp::FloatVector<8, 1> var725;
  vamp::FloatVector<8, 1> var726;
  vamp::FloatVector<8, 1> var727;
  vamp::FloatVector<8, 1> var728;
  vamp::FloatVector<8, 1> var729;
  vamp::FloatVector<8, 1> var730;
  vamp::FloatVector<8, 1> var731;
  vamp::FloatVector<8, 1> var732;
  vamp::FloatVector<8, 1> var733;
  vamp::FloatVector<8, 1> var740;
  vamp::FloatVector<8, 1> var741;
  vamp::FloatVector<8, 1> var742;
  vamp::FloatVector<8, 1> var743;
  vamp::FloatVector<8, 1> var744;
  vamp::FloatVector<8, 1> var745;
  vamp::FloatVector<8, 1> var746;
  vamp::FloatVector<8, 1> var747;
  vamp::FloatVector<8, 1> var748;
  vamp::FloatVector<8, 1> var749;
  vamp::FloatVector<8, 1> var750;
  vamp::FloatVector<8, 1> var751;
  vamp::FloatVector<8, 1> var758;
  vamp::FloatVector<8, 1> var759;
  vamp::FloatVector<8, 1> var760;
  vamp::FloatVector<8, 1> var761;
  vamp::FloatVector<8, 1> var762;
  vamp::FloatVector<8, 1> var763;
  vamp::FloatVector<8, 1> var764;
  vamp::FloatVector<8, 1> var765;
  vamp::FloatVector<8, 1> var766;
  vamp::FloatVector<8, 1> var767;
  vamp::FloatVector<8, 1> var768;
  vamp::FloatVector<8, 1> var769;
  vamp::FloatVector<8, 1> var776;
  vamp::FloatVector<8, 1> var777;
  vamp::FloatVector<8, 1> var778;
  vamp::FloatVector<8, 1> var779;
  vamp::FloatVector<8, 1> var780;
  vamp::FloatVector<8, 1> var781;
  vamp::FloatVector<8, 1> var782;
  vamp::FloatVector<8, 1> var783;
  vamp::FloatVector<8, 1> var784;
  vamp::FloatVector<8, 1> var785;
  vamp::FloatVector<8, 1> var786;
  vamp::FloatVector<8, 1> var787;
  vamp::FloatVector<8, 1> var794;
  vamp::FloatVector<8, 1> var795;
  vamp::FloatVector<8, 1> var796;
  vamp::FloatVector<8, 1> var797;
  vamp::FloatVector<8, 1> var798;
  vamp::FloatVector<8, 1> var799;
  vamp::FloatVector<8, 1> var800;
  vamp::FloatVector<8, 1> var801;
  vamp::FloatVector<8, 1> var802;
  vamp::FloatVector<8, 1> var803;
  vamp::FloatVector<8, 1> var804;
  vamp::FloatVector<8, 1> var805;
  vamp::FloatVector<8, 1> var812[33];
  vamp::FloatVector<8, 1> var813[33];
  vamp::FloatVector<8, 1> var814[33];
  float var815[33];
  unsigned long int var816[33];
  std::array<vamp::FloatVector<8, 1>, 3> var817;
  std::array<vamp::FloatVector<8, 1>, 1> var818;
  std::array<vamp::FloatVector<8, 1>, 2> var819;
  std::array<vamp::FloatVector<8, 1>, 0> var820;
  std::array<vamp::FloatVector<8, 1>, 3> var821;
  std::array<vamp::FloatVector<8, 1>, 0> var822;
  std::array<vamp::FloatVector<8, 1>, 3> var823;
  std::array<vamp::FloatVector<8, 1>, 2> var824;
  std::array<vamp::FloatVector<8, 1>, 2> var825;
  std::array<vamp::FloatVector<8, 1>, 1> var826;
  std::array<vamp::FloatVector<8, 1>, 2> var827;
  std::array<vamp::FloatVector<8, 1>, 2> var828;
  std::array<vamp::FloatVector<8, 1>, 3> var829;
  std::array<vamp::FloatVector<8, 1>, 4> var830;
  std::array<vamp::FloatVector<8, 1>, 2> var831;
  std::array<vamp::FloatVector<8, 1>, 3> var832;
  std::array<vamp::FloatVector<8, 1>, 4> var833;
  std::array<vamp::FloatVector<8, 1>, 1> var834;
  std::array<vamp::FloatVector<8, 1>, 2> var835;
  std::array<vamp::FloatVector<8, 1>, 0> var836;
  std::array<vamp::FloatVector<8, 1>, 3> var837;
  std::array<vamp::FloatVector<8, 1>, 0> var838;
  std::array<vamp::FloatVector<8, 1>, 3> var839;
  std::array<vamp::FloatVector<8, 1>, 2> var840;
  std::array<vamp::FloatVector<8, 1>, 2> var841;
  std::array<vamp::FloatVector<8, 1>, 1> var842;
  std::array<vamp::FloatVector<8, 1>, 2> var843;
  std::array<vamp::FloatVector<8, 1>, 2> var844;
  std::array<vamp::FloatVector<8, 1>, 3> var845;
  std::array<vamp::FloatVector<8, 1>, 4> var846;
  std::array<vamp::FloatVector<8, 1>, 2> var847;
  std::array<vamp::FloatVector<8, 1>, 3> var848;
  std::array<vamp::FloatVector<8, 1>, 4> var849;
  std::array<vamp::FloatVector<8, 1>, 3> var850;
  std::array<vamp::FloatVector<8, 1>, 1> var851;
  std::array<vamp::FloatVector<8, 1>, 2> var852;
  std::array<vamp::FloatVector<8, 1>, 0> var853;
  std::array<vamp::FloatVector<8, 1>, 3> var854;
  std::array<vamp::FloatVector<8, 1>, 0> var855;
  std::array<vamp::FloatVector<8, 1>, 3> var856;
  std::array<vamp::FloatVector<8, 1>, 2> var857;
  std::array<vamp::FloatVector<8, 1>, 2> var858;
  std::array<vamp::FloatVector<8, 1>, 1> var859;
  std::array<vamp::FloatVector<8, 1>, 2> var860;
  std::array<vamp::FloatVector<8, 1>, 2> var861;
  std::array<vamp::FloatVector<8, 1>, 3> var862;
  std::array<vamp::FloatVector<8, 1>, 4> var863;
  std::array<vamp::FloatVector<8, 1>, 2> var864;
  std::array<vamp::FloatVector<8, 1>, 3> var865;
  std::array<vamp::FloatVector<8, 1>, 4> var866;
  std::array<vamp::FloatVector<8, 1>, 1> var867;
  std::array<vamp::FloatVector<8, 1>, 2> var868;
  std::array<vamp::FloatVector<8, 1>, 0> var869;
  std::array<vamp::FloatVector<8, 1>, 3> var870;
  std::array<vamp::FloatVector<8, 1>, 0> var871;
  std::array<vamp::FloatVector<8, 1>, 3> var872;
  std::array<vamp::FloatVector<8, 1>, 2> var873;
  std::array<vamp::FloatVector<8, 1>, 2> var874;
  std::array<vamp::FloatVector<8, 1>, 1> var875;
  std::array<vamp::FloatVector<8, 1>, 2> var876;
  std::array<vamp::FloatVector<8, 1>, 2> var877;
  std::array<vamp::FloatVector<8, 1>, 3> var878;
  std::array<vamp::FloatVector<8, 1>, 4> var879;
  std::array<vamp::FloatVector<8, 1>, 2> var880;
  std::array<vamp::FloatVector<8, 1>, 3> var881;
  std::array<vamp::FloatVector<8, 1>, 4> var882;
  std::array<vamp::FloatVector<8, 1>, 3> var883;
  std::array<vamp::FloatVector<8, 1>, 1> var884;
  std::array<vamp::FloatVector<8, 1>, 2> var885;
  std::array<vamp::FloatVector<8, 1>, 0> var886;
  std::array<vamp::FloatVector<8, 1>, 3> var887;
  std::array<vamp::FloatVector<8, 1>, 0> var888;
  std::array<vamp::FloatVector<8, 1>, 3> var889;
  std::array<vamp::FloatVector<8, 1>, 2> var890;
  std::array<vamp::FloatVector<8, 1>, 2> var891;
  std::array<vamp::FloatVector<8, 1>, 1> var892;
  std::array<vamp::FloatVector<8, 1>, 2> var893;
  std::array<vamp::FloatVector<8, 1>, 2> var894;
  std::array<vamp::FloatVector<8, 1>, 3> var895;
  std::array<vamp::FloatVector<8, 1>, 4> var896;
  std::array<vamp::FloatVector<8, 1>, 2> var897;
  std::array<vamp::FloatVector<8, 1>, 3> var898;
  std::array<vamp::FloatVector<8, 1>, 4> var899;
  std::array<vamp::FloatVector<8, 1>, 1> var900;
  std::array<vamp::FloatVector<8, 1>, 2> var901;
  std::array<vamp::FloatVector<8, 1>, 0> var902;
  std::array<vamp::FloatVector<8, 1>, 3> var903;
  std::array<vamp::FloatVector<8, 1>, 0> var904;
  std::array<vamp::FloatVector<8, 1>, 3> var905;
  std::array<vamp::FloatVector<8, 1>, 2> var906;
  std::array<vamp::FloatVector<8, 1>, 2> var907;
  std::array<vamp::FloatVector<8, 1>, 1> var908;
  std::array<vamp::FloatVector<8, 1>, 2> var909;
  std::array<vamp::FloatVector<8, 1>, 2> var910;
  std::array<vamp::FloatVector<8, 1>, 3> var911;
  std::array<vamp::FloatVector<8, 1>, 4> var912;
  std::array<vamp::FloatVector<8, 1>, 2> var913;
  std::array<vamp::FloatVector<8, 1>, 3> var914;
  std::array<vamp::FloatVector<8, 1>, 4> var915;
  std::array<float, 3> var916;
  std::array<float, 1> var917;
  std::array<float, 2> var918;
  std::array<float, 0> var919;
  std::array<float, 3> var920;
  std::array<float, 0> var921;
  std::array<float, 3> var922;
  std::array<float, 2> var923;
  std::array<float, 2> var924;
  std::array<float, 1> var925;
  std::array<float, 2> var926;
  std::array<float, 2> var927;
  std::array<float, 3> var928;
  std::array<float, 4> var929;
  std::array<float, 2> var930;
  std::array<float, 3> var931;
  std::array<float, 4> var932;
  std::array<float, 1> var933;
  std::array<float, 2> var934;
  std::array<float, 0> var935;
  std::array<float, 3> var936;
  std::array<float, 0> var937;
  std::array<float, 3> var938;
  std::array<float, 2> var939;
  std::array<float, 2> var940;
  std::array<float, 1> var941;
  std::array<float, 2> var942;
  std::array<float, 2> var943;
  std::array<float, 3> var944;
  std::array<float, 4> var945;
  std::array<float, 2> var946;
  std::array<float, 3> var947;
  std::array<float, 4> var948;
  vamp::FloatVector<8, 1> var949;
  vamp::FloatVector<8, 1> var950;
  vamp::FloatVector<8, 1> var953;
  vamp::FloatVector<8, 1> var954;
  vamp::FloatVector<8, 1> var957;
  vamp::FloatVector<8, 1> var958;
  var812[0ll] = ((1.0f * -0.0439999997615814f) + (0.0f * 0.0f)) + (0.0f * 0.222000002861023f);
  var813[0ll] = ((0.0f * -0.0439999997615814f) + (1.0f * 0.0f)) + (0.0f * 0.222000002861023f);
  var814[0ll] = ((0.0f * -0.0439999997615814f) + (0.0f * 0.0f)) + (1.0f * 0.222000002861023f);
  var812[0ll] = var812[0ll] + 0.0f;
  var813[0ll] = var813[0ll] + 0.0f;
  var814[0ll] = var814[0ll] + 0.0f;
  var815[0ll] = 0.409000009298325f;
  var816[0ll] = 3ll;
  var817[0ll] = ((1.0f * -0.025000000372529f) + (0.0f * -0.100000001490116f)) + (0.0f * 0.100000001490116f);
  var850[0ll] = ((0.0f * -0.025000000372529f) + (1.0f * -0.100000001490116f)) + (0.0f * 0.100000001490116f);
  var883[0ll] = ((0.0f * -0.025000000372529f) + (0.0f * -0.100000001490116f)) + (1.0f * 0.100000001490116f);
  var817[0ll] = var817[0ll] + 0.0f;
  var850[0ll] = var850[0ll] + 0.0f;
  var883[0ll] = var883[0ll] + 0.0f;
  var916[0ll] = 0.25f;
  var817[1ll] = ((1.0f * -0.025000000372529f) + (0.0f * 0.100000001490116f)) + (0.0f * 0.100000001490116f);
  var850[1ll] = ((0.0f * -0.025000000372529f) + (1.0f * 0.100000001490116f)) + (0.0f * 0.100000001490116f);
  var883[1ll] = ((0.0f * -0.025000000372529f) + (0.0f * 0.100000001490116f)) + (1.0f * 0.100000001490116f);
  var817[1ll] = var817[1ll] + 0.0f;
  var850[1ll] = var850[1ll] + 0.0f;
  var883[1ll] = var883[1ll] + 0.0f;
  var916[1ll] = 0.25f;
  var817[2ll] = ((1.0f * -0.0649999976158142f) + (0.0f * 0.0f)) + (0.0f * 0.400000005960464f);
  var850[2ll] = ((0.0f * -0.0649999976158142f) + (1.0f * 0.0f)) + (0.0f * 0.400000005960464f);
  var883[2ll] = ((0.0f * -0.0649999976158142f) + (0.0f * 0.0f)) + (1.0f * 0.400000005960464f);
  var817[2ll] = var817[2ll] + 0.0f;
  var850[2ll] = var850[2ll] + 0.0f;
  var883[2ll] = var883[2ll] + 0.0f;
  var916[2ll] = 0.230000004172325f;
  var812[1ll] = ((1.0f * 0.0399999991059303f) + (0.0f * 0.0f)) + (0.0f * 0.685999989509583f);
  var813[1ll] = ((0.0f * 0.0399999991059303f) + (1.0f * 0.0f)) + (0.0f * 0.685999989509583f);
  var814[1ll] = ((0.0f * 0.0399999991059303f) + (0.0f * 0.0f)) + (1.0f * 0.685999989509583f);
  var812[1ll] = var812[1ll] + 0.0f;
  var813[1ll] = var813[1ll] + 0.0f;
  var814[1ll] = var814[1ll] + 0.0f;
  var815[1ll] = 0.200000002980232f;
  var816[1ll] = 1ll;
  var818[0ll] = ((1.0f * 0.0399999991059303f) + (0.0f * 0.0f)) + (0.0f * 0.685999989509583f);
  var851[0ll] = ((0.0f * 0.0399999991059303f) + (1.0f * 0.0f)) + (0.0f * 0.685999989509583f);
  var884[0ll] = ((0.0f * 0.0399999991059303f) + (0.0f * 0.0f)) + (1.0f * 0.685999989509583f);
  var818[0ll] = var818[0ll] + 0.0f;
  var851[0ll] = var851[0ll] + 0.0f;
  var884[0ll] = var884[0ll] + 0.0f;
  var917[0ll] = 0.200000002980232f;
  var812[17ll] = ((1.0f * 0.0f) + (0.0f * 0.0f)) + (0.0f * -0.600000023841858f);
  var813[17ll] = ((0.0f * 0.0f) + (1.0f * 0.0f)) + (0.0f * -0.600000023841858f);
  var814[17ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * -0.600000023841858f);
  var812[17ll] = var812[17ll] + 0.0f;
  var813[17ll] = var813[17ll] + 0.0f;
  var814[17ll] = var814[17ll] + 0.0f;
  var815[17ll] = 0.5f;
  var816[17ll] = 1ll;
  var834[0ll] = ((1.0f * 0.0f) + (0.0f * 0.0f)) + (0.0f * -0.600000023841858f);
  var867[0ll] = ((0.0f * 0.0f) + (1.0f * 0.0f)) + (0.0f * -0.600000023841858f);
  var900[0ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * -0.600000023841858f);
  var834[0ll] = var834[0ll] + 0.0f;
  var867[0ll] = var867[0ll] + 0.0f;
  var900[0ll] = var900[0ll] + 0.0f;
  var933[0ll] = 0.5f;
  int var969;
  var969 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 2,17 : left_upper_shoulder_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 6,17 : left_upper_forearm_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 7,17 : left_lower_forearm_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 8,17 : left_wrist_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 9,17 : left_hand_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 10,17 : left_gripper_base_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 11,17 : l_gripper_l_finger_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 12,17 : l_gripper_l_finger_2_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 13,17 : l_gripper_l_finger_tip_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 14,17 : l_gripper_r_finger_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 15,17 : l_gripper_r_finger_2_0,pedestal_0
  var969 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933);
  if (var969)
    return 0; //collision pair: 16,17 : l_gripper_r_finger_tip_0,pedestal_0
  vamp::FloatVector<8, 1> var970 = arg5[0ll];
  var306 = var970.sin();
  var307 = var970.cos();
  var290 = var307;
  var291 = -(var306);
  var294 = var306;
  var295 = var307;
  vamp::FloatVector<8, 1> var971;
  var971 = var971 + (0.707105457782745f * var290);
  var971 = var971 + (-0.707108080387115f * var294);
  var949 = var971;
  vamp::FloatVector<8, 1> var973;
  var973 = var973 + (0.707105457782745f * var291);
  var973 = var973 + (-0.707108080387115f * var295);
  var950 = var973;
  vamp::FloatVector<8, 1> var975;
  var975 = var975 + (0.707108080387115f * var290);
  var975 = var975 + (0.707105457782745f * var294);
  var953 = var975;
  vamp::FloatVector<8, 1> var977;
  var977 = var977 + (0.707108080387115f * var291);
  var977 = var977 + (0.707105457782745f * var295);
  var954 = var977;
  var560 = var949;
  var561 = var950;
  var564 = var953;
  var565 = var954;
  var812[2ll] = ((var560 * 0.0f) + (var561 * 0.0f)) + (0.0f * 0.174999997019768f);
  var813[2ll] = ((var564 * 0.0f) + (var565 * 0.0f)) + (0.0f * 0.174999997019768f);
  var814[2ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * 0.174999997019768f);
  var812[2ll] = var812[2ll] + 0.0640272423624992f;
  var813[2ll] = var813[2ll] + 0.259027391672134f;
  var814[2ll] = var814[2ll] + 0.129626005887985f;
  var815[2ll] = 0.174999997019768f;
  var816[2ll] = 2ll;
  var819[0ll] = ((var560 * 0.0f) + (var561 * 0.0f)) + (0.0f * 0.25f);
  var852[0ll] = ((var564 * 0.0f) + (var565 * 0.0f)) + (0.0f * 0.25f);
  var885[0ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * 0.25f);
  var819[0ll] = var819[0ll] + 0.0640272423624992f;
  var852[0ll] = var852[0ll] + 0.259027391672134f;
  var885[0ll] = var885[0ll] + 0.129626005887985f;
  var918[0ll] = 0.100000001490116f;
  var819[1ll] = ((var560 * 0.0f) + (var561 * 0.0f)) + (0.0f * 0.100000001490116f);
  var852[1ll] = ((var564 * 0.0f) + (var565 * 0.0f)) + (0.0f * 0.100000001490116f);
  var885[1ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * 0.100000001490116f);
  var819[1ll] = var819[1ll] + 0.0640272423624992f;
  var852[1ll] = var852[1ll] + 0.259027391672134f;
  var885[1ll] = var885[1ll] + 0.129626005887985f;
  var918[1ll] = 0.100000001490116f;
  int var979;
  var979 = ctup_runtime::link_vs_environment_collision(var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, arg4);
  if (var979)
    return 0;
  vamp::FloatVector<8, 1> var980 = arg5[1ll];
  var324 = var980.sin();
  var325 = var980.cos();
  var308 = var325;
  var309 = -(var324);
  var312 = var324;
  var313 = var325;
  vamp::FloatVector<8, 1> var981;
  var981 = var981 + (1.0f * var308);
  var949 = var981;
  vamp::FloatVector<8, 1> var983;
  var983 = var983 + (1.0f * var309);
  var950 = var983;
  vamp::FloatVector<8, 1> var985;
  var985 = var985 + (-1.0f * var312);
  var957 = var985;
  vamp::FloatVector<8, 1> var987;
  var987 = var987 + (-1.0f * var313);
  var958 = var987;
  vamp::FloatVector<8, 1> var989;
  var989 = var989 + (var560 * var949);
  var578 = var989;
  vamp::FloatVector<8, 1> var991;
  var991 = var991 + (var560 * var950);
  var579 = var991;
  vamp::FloatVector<8, 1> var993;
  var993 = var993 + (var561 * 1.0f);
  var580 = var993;
  vamp::FloatVector<8, 1> var995;
  var995 = var995 + (var560 * 0.0689999982714653f);
  var995 = var995 + (0.0640272423624992f * 1.0f);
  var581 = var995;
  vamp::FloatVector<8, 1> var997;
  var997 = var997 + (var564 * var949);
  var582 = var997;
  vamp::FloatVector<8, 1> var999;
  var999 = var999 + (var564 * var950);
  var583 = var999;
  vamp::FloatVector<8, 1> var1001;
  var1001 = var1001 + (var565 * 1.0f);
  var584 = var1001;
  vamp::FloatVector<8, 1> var1003;
  var1003 = var1003 + (var564 * 0.0689999982714653f);
  var1003 = var1003 + (0.259027391672134f * 1.0f);
  var585 = var1003;
  vamp::FloatVector<8, 1> var1005;
  var1005 = var1005 + (1.0f * var957);
  var586 = var1005;
  vamp::FloatVector<8, 1> var1007;
  var1007 = var1007 + (1.0f * var958);
  var587 = var1007;
  var812[3ll] = ((var578 * 0.0f) + (var579 * 0.0f)) + (var580 * 0.0f);
  var813[3ll] = ((var582 * 0.0f) + (var583 * 0.0f)) + (var584 * 0.0f);
  var814[3ll] = ((var586 * 0.0f) + (var587 * 0.0f)) + (0.0f * 0.0f);
  var812[3ll] = var812[3ll] + var581;
  var813[3ll] = var813[3ll] + var585;
  var814[3ll] = var814[3ll] + 0.399976015090942f;
  var815[3ll] = 0.100000001490116f;
  var816[3ll] = 0ll;
  int var1009;
  var1009 = ctup_runtime::link_vs_environment_collision(var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, arg4);
  if (var1009)
    return 0;
  vamp::FloatVector<8, 1> var1010 = arg5[2ll];
  var342 = var1010.sin();
  var343 = var1010.cos();
  var326 = var343;
  var327 = -(var342);
  var330 = var342;
  var331 = var343;
  vamp::FloatVector<8, 1> var1011;
  var1011 = var1011 + (1.0f * var326);
  var953 = var1011;
  vamp::FloatVector<8, 1> var1013;
  var1013 = var1013 + (1.0f * var327);
  var954 = var1013;
  vamp::FloatVector<8, 1> var1015;
  var1015 = var1015 + (1.0f * var330);
  var957 = var1015;
  vamp::FloatVector<8, 1> var1017;
  var1017 = var1017 + (1.0f * var331);
  var958 = var1017;
  vamp::FloatVector<8, 1> var1019;
  var1019 = var1019 + (var579 * var953);
  var1019 = var1019 + (var580 * var957);
  var596 = var1019;
  vamp::FloatVector<8, 1> var1021;
  var1021 = var1021 + (var579 * var954);
  var1021 = var1021 + (var580 * var958);
  var597 = var1021;
  vamp::FloatVector<8, 1> var1023;
  var1023 = var1023 + (var578 * 1.0f);
  var598 = var1023;
  vamp::FloatVector<8, 1> var1025;
  var1025 = var1025 + (var578 * 0.101999998092651f);
  var1025 = var1025 + (var581 * 1.0f);
  var599 = var1025;
  vamp::FloatVector<8, 1> var1027;
  var1027 = var1027 + (var583 * var953);
  var1027 = var1027 + (var584 * var957);
  var600 = var1027;
  vamp::FloatVector<8, 1> var1029;
  var1029 = var1029 + (var583 * var954);
  var1029 = var1029 + (var584 * var958);
  var601 = var1029;
  vamp::FloatVector<8, 1> var1031;
  var1031 = var1031 + (var582 * 1.0f);
  var602 = var1031;
  vamp::FloatVector<8, 1> var1033;
  var1033 = var1033 + (var582 * 0.101999998092651f);
  var1033 = var1033 + (var585 * 1.0f);
  var603 = var1033;
  vamp::FloatVector<8, 1> var1035;
  var1035 = var1035 + (var587 * var953);
  var604 = var1035;
  vamp::FloatVector<8, 1> var1037;
  var1037 = var1037 + (var587 * var954);
  var605 = var1037;
  vamp::FloatVector<8, 1> var1039;
  var1039 = var1039 + (var586 * 1.0f);
  var606 = var1039;
  vamp::FloatVector<8, 1> var1041;
  var1041 = var1041 + (var586 * 0.101999998092651f);
  var1041 = var1041 + (0.399976015090942f * 1.0f);
  var607 = var1041;
  var812[4ll] = ((var596 * -0.00999999977648258f) + (var597 * 0.0f)) + (var598 * 0.109999999403954f);
  var813[4ll] = ((var600 * -0.00999999977648258f) + (var601 * 0.0f)) + (var602 * 0.109999999403954f);
  var814[4ll] = ((var604 * -0.00999999977648258f) + (var605 * 0.0f)) + (var606 * 0.109999999403954f);
  var812[4ll] = var812[4ll] + var599;
  var813[4ll] = var813[4ll] + var603;
  var814[4ll] = var814[4ll] + var607;
  var815[4ll] = 0.189999997615814f;
  var816[4ll] = 3ll;
  var821[0ll] = ((var596 * -0.0199999995529652f) + (var597 * 0.0f)) + (var598 * 0.219999998807907f);
  var854[0ll] = ((var600 * -0.0199999995529652f) + (var601 * 0.0f)) + (var602 * 0.219999998807907f);
  var887[0ll] = ((var604 * -0.0199999995529652f) + (var605 * 0.0f)) + (var606 * 0.219999998807907f);
  var821[0ll] = var821[0ll] + var599;
  var854[0ll] = var854[0ll] + var603;
  var887[0ll] = var887[0ll] + var607;
  var920[0ll] = 0.0799999982118607f;
  var821[1ll] = ((var596 * -0.00999999977648258f) + (var597 * 0.0f)) + (var598 * 0.109999999403954f);
  var854[1ll] = ((var600 * -0.00999999977648258f) + (var601 * 0.0f)) + (var602 * 0.109999999403954f);
  var887[1ll] = ((var604 * -0.00999999977648258f) + (var605 * 0.0f)) + (var606 * 0.109999999403954f);
  var821[1ll] = var821[1ll] + var599;
  var854[1ll] = var854[1ll] + var603;
  var887[1ll] = var887[1ll] + var607;
  var920[1ll] = 0.0799999982118607f;
  var821[2ll] = ((var596 * 0.0f) + (var597 * 0.0f)) + (var598 * 0.0f);
  var854[2ll] = ((var600 * 0.0f) + (var601 * 0.0f)) + (var602 * 0.0f);
  var887[2ll] = ((var604 * 0.0f) + (var605 * 0.0f)) + (var606 * 0.0f);
  var821[2ll] = var821[2ll] + var599;
  var854[2ll] = var854[2ll] + var603;
  var887[2ll] = var887[2ll] + var607;
  var920[2ll] = 0.0799999982118607f;
  int var1043;
  var1043 = ctup_runtime::link_vs_environment_collision(var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, arg4);
  if (var1043)
    return 0;
  vamp::FloatVector<8, 1> var1044 = arg5[3ll];
  var360 = var1044.sin();
  var361 = var1044.cos();
  var344 = var361;
  var345 = -(var360);
  var348 = var360;
  var349 = var361;
  vamp::FloatVector<8, 1> var1045;
  var1045 = var1045 + (1.0f * var348);
  var949 = var1045;
  vamp::FloatVector<8, 1> var1047;
  var1047 = var1047 + (1.0f * var349);
  var950 = var1047;
  vamp::FloatVector<8, 1> var1049;
  var1049 = var1049 + (1.0f * var344);
  var957 = var1049;
  vamp::FloatVector<8, 1> var1051;
  var1051 = var1051 + (1.0f * var345);
  var958 = var1051;
  vamp::FloatVector<8, 1> var1053;
  var1053 = var1053 + (var596 * var949);
  var1053 = var1053 + (var598 * var957);
  var614 = var1053;
  vamp::FloatVector<8, 1> var1055;
  var1055 = var1055 + (var596 * var950);
  var1055 = var1055 + (var598 * var958);
  var615 = var1055;
  vamp::FloatVector<8, 1> var1057;
  var1057 = var1057 + (var597 * 1.0f);
  var616 = var1057;
  vamp::FloatVector<8, 1> var1059;
  var1059 = var1059 + (var596 * 0.0689999982714653f);
  var1059 = var1059 + (var598 * 0.262419998645782f);
  var1059 = var1059 + (var599 * 1.0f);
  var617 = var1059;
  vamp::FloatVector<8, 1> var1061;
  var1061 = var1061 + (var600 * var949);
  var1061 = var1061 + (var602 * var957);
  var618 = var1061;
  vamp::FloatVector<8, 1> var1063;
  var1063 = var1063 + (var600 * var950);
  var1063 = var1063 + (var602 * var958);
  var619 = var1063;
  vamp::FloatVector<8, 1> var1065;
  var1065 = var1065 + (var601 * 1.0f);
  var620 = var1065;
  vamp::FloatVector<8, 1> var1067;
  var1067 = var1067 + (var600 * 0.0689999982714653f);
  var1067 = var1067 + (var602 * 0.262419998645782f);
  var1067 = var1067 + (var603 * 1.0f);
  var621 = var1067;
  vamp::FloatVector<8, 1> var1069;
  var1069 = var1069 + (var604 * var949);
  var1069 = var1069 + (var606 * var957);
  var622 = var1069;
  vamp::FloatVector<8, 1> var1071;
  var1071 = var1071 + (var604 * var950);
  var1071 = var1071 + (var606 * var958);
  var623 = var1071;
  vamp::FloatVector<8, 1> var1073;
  var1073 = var1073 + (var605 * 1.0f);
  var624 = var1073;
  vamp::FloatVector<8, 1> var1075;
  var1075 = var1075 + (var604 * 0.0689999982714653f);
  var1075 = var1075 + (var606 * 0.262419998645782f);
  var1075 = var1075 + (var607 * 1.0f);
  var625 = var1075;
  var812[5ll] = ((var614 * 0.0f) + (var615 * 0.0f)) + (var616 * 0.0f);
  var813[5ll] = ((var618 * 0.0f) + (var619 * 0.0f)) + (var620 * 0.0f);
  var814[5ll] = ((var622 * 0.0f) + (var623 * 0.0f)) + (var624 * 0.0f);
  var812[5ll] = var812[5ll] + var617;
  var813[5ll] = var813[5ll] + var621;
  var814[5ll] = var814[5ll] + var625;
  var815[5ll] = 0.100000001490116f;
  var816[5ll] = 0ll;
  int var1077;
  var1077 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921);
  if (var1077)
    return 0; //collision pair: 0,5 : torso_0,left_lower_elbow_0
  var1077 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921);
  if (var1077)
    return 0; //collision pair: 1,5 : head_0,left_lower_elbow_0
  var1077 = ctup_runtime::link_vs_environment_collision(var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, arg4);
  if (var1077)
    return 0;
  vamp::FloatVector<8, 1> var1078 = arg5[4ll];
  var378 = var1078.sin();
  var379 = var1078.cos();
  var362 = var379;
  var363 = -(var378);
  var366 = var378;
  var367 = var379;
  vamp::FloatVector<8, 1> var1079;
  var1079 = var1079 + (1.0f * var362);
  var953 = var1079;
  vamp::FloatVector<8, 1> var1081;
  var1081 = var1081 + (1.0f * var363);
  var954 = var1081;
  vamp::FloatVector<8, 1> var1083;
  var1083 = var1083 + (1.0f * var366);
  var957 = var1083;
  vamp::FloatVector<8, 1> var1085;
  var1085 = var1085 + (1.0f * var367);
  var958 = var1085;
  vamp::FloatVector<8, 1> var1087;
  var1087 = var1087 + (var615 * var953);
  var1087 = var1087 + (var616 * var957);
  var632 = var1087;
  vamp::FloatVector<8, 1> var1089;
  var1089 = var1089 + (var615 * var954);
  var1089 = var1089 + (var616 * var958);
  var633 = var1089;
  vamp::FloatVector<8, 1> var1091;
  var1091 = var1091 + (var614 * 1.0f);
  var634 = var1091;
  vamp::FloatVector<8, 1> var1093;
  var1093 = var1093 + (var614 * 0.103589996695518f);
  var1093 = var1093 + (var617 * 1.0f);
  var635 = var1093;
  vamp::FloatVector<8, 1> var1095;
  var1095 = var1095 + (var619 * var953);
  var1095 = var1095 + (var620 * var957);
  var636 = var1095;
  vamp::FloatVector<8, 1> var1097;
  var1097 = var1097 + (var619 * var954);
  var1097 = var1097 + (var620 * var958);
  var637 = var1097;
  vamp::FloatVector<8, 1> var1099;
  var1099 = var1099 + (var618 * 1.0f);
  var638 = var1099;
  vamp::FloatVector<8, 1> var1101;
  var1101 = var1101 + (var618 * 0.103589996695518f);
  var1101 = var1101 + (var621 * 1.0f);
  var639 = var1101;
  vamp::FloatVector<8, 1> var1103;
  var1103 = var1103 + (var623 * var953);
  var1103 = var1103 + (var624 * var957);
  var640 = var1103;
  vamp::FloatVector<8, 1> var1105;
  var1105 = var1105 + (var623 * var954);
  var1105 = var1105 + (var624 * var958);
  var641 = var1105;
  vamp::FloatVector<8, 1> var1107;
  var1107 = var1107 + (var622 * 1.0f);
  var642 = var1107;
  vamp::FloatVector<8, 1> var1109;
  var1109 = var1109 + (var622 * 0.103589996695518f);
  var1109 = var1109 + (var625 * 1.0f);
  var643 = var1109;
  var812[6ll] = ((var632 * 0.0f) + (var633 * 0.0f)) + (var634 * 0.109999999403954f);
  var813[6ll] = ((var636 * 0.0f) + (var637 * 0.0f)) + (var638 * 0.109999999403954f);
  var814[6ll] = ((var640 * 0.0f) + (var641 * 0.0f)) + (var642 * 0.109999999403954f);
  var812[6ll] = var812[6ll] + var635;
  var813[6ll] = var813[6ll] + var639;
  var814[6ll] = var814[6ll] + var643;
  var815[6ll] = 0.189999997615814f;
  var816[6ll] = 3ll;
  var823[0ll] = ((var632 * 0.0f) + (var633 * 0.0f)) + (var634 * 0.0f);
  var856[0ll] = ((var636 * 0.0f) + (var637 * 0.0f)) + (var638 * 0.0f);
  var889[0ll] = ((var640 * 0.0f) + (var641 * 0.0f)) + (var642 * 0.0f);
  var823[0ll] = var823[0ll] + var635;
  var856[0ll] = var856[0ll] + var639;
  var889[0ll] = var889[0ll] + var643;
  var922[0ll] = 0.0799999982118607f;
  var823[1ll] = ((var632 * 0.0f) + (var633 * 0.0f)) + (var634 * 0.219999998807907f);
  var856[1ll] = ((var636 * 0.0f) + (var637 * 0.0f)) + (var638 * 0.219999998807907f);
  var889[1ll] = ((var640 * 0.0f) + (var641 * 0.0f)) + (var642 * 0.219999998807907f);
  var823[1ll] = var823[1ll] + var635;
  var856[1ll] = var856[1ll] + var639;
  var889[1ll] = var889[1ll] + var643;
  var922[1ll] = 0.0799999982118607f;
  var823[2ll] = ((var632 * 0.0f) + (var633 * 0.0f)) + (var634 * 0.109999999403954f);
  var856[2ll] = ((var636 * 0.0f) + (var637 * 0.0f)) + (var638 * 0.109999999403954f);
  var889[2ll] = ((var640 * 0.0f) + (var641 * 0.0f)) + (var642 * 0.109999999403954f);
  var823[2ll] = var823[2ll] + var635;
  var856[2ll] = var856[2ll] + var639;
  var889[2ll] = var889[2ll] + var643;
  var922[2ll] = 0.0799999982118607f;
  int var1111;
  var1111 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922);
  if (var1111)
    return 0; //collision pair: 0,6 : torso_0,left_upper_forearm_0
  var1111 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922);
  if (var1111)
    return 0; //collision pair: 1,6 : head_0,left_upper_forearm_0
  var1111 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922);
  if (var1111)
    return 0; //collision pair: 2,6 : left_upper_shoulder_0,left_upper_forearm_0
  var1111 = ctup_runtime::link_vs_environment_collision(var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, arg4);
  if (var1111)
    return 0;
  vamp::FloatVector<8, 1> var1112 = arg5[5ll];
  var396 = var1112.sin();
  var397 = var1112.cos();
  var380 = var397;
  var381 = -(var396);
  var384 = var396;
  var385 = var397;
  vamp::FloatVector<8, 1> var1113;
  var1113 = var1113 + (1.0f * var384);
  var949 = var1113;
  vamp::FloatVector<8, 1> var1115;
  var1115 = var1115 + (1.0f * var385);
  var950 = var1115;
  vamp::FloatVector<8, 1> var1117;
  var1117 = var1117 + (1.0f * var380);
  var957 = var1117;
  vamp::FloatVector<8, 1> var1119;
  var1119 = var1119 + (1.0f * var381);
  var958 = var1119;
  vamp::FloatVector<8, 1> var1121;
  var1121 = var1121 + (var632 * var949);
  var1121 = var1121 + (var634 * var957);
  var650 = var1121;
  vamp::FloatVector<8, 1> var1123;
  var1123 = var1123 + (var632 * var950);
  var1123 = var1123 + (var634 * var958);
  var651 = var1123;
  vamp::FloatVector<8, 1> var1125;
  var1125 = var1125 + (var633 * 1.0f);
  var652 = var1125;
  vamp::FloatVector<8, 1> var1127;
  var1127 = var1127 + (var632 * 0.00999999977648258f);
  var1127 = var1127 + (var634 * 0.270700007677078f);
  var1127 = var1127 + (var635 * 1.0f);
  var653 = var1127;
  vamp::FloatVector<8, 1> var1129;
  var1129 = var1129 + (var636 * var949);
  var1129 = var1129 + (var638 * var957);
  var654 = var1129;
  vamp::FloatVector<8, 1> var1131;
  var1131 = var1131 + (var636 * var950);
  var1131 = var1131 + (var638 * var958);
  var655 = var1131;
  vamp::FloatVector<8, 1> var1133;
  var1133 = var1133 + (var637 * 1.0f);
  var656 = var1133;
  vamp::FloatVector<8, 1> var1135;
  var1135 = var1135 + (var636 * 0.00999999977648258f);
  var1135 = var1135 + (var638 * 0.270700007677078f);
  var1135 = var1135 + (var639 * 1.0f);
  var657 = var1135;
  vamp::FloatVector<8, 1> var1137;
  var1137 = var1137 + (var640 * var949);
  var1137 = var1137 + (var642 * var957);
  var658 = var1137;
  vamp::FloatVector<8, 1> var1139;
  var1139 = var1139 + (var640 * var950);
  var1139 = var1139 + (var642 * var958);
  var659 = var1139;
  vamp::FloatVector<8, 1> var1141;
  var1141 = var1141 + (var641 * 1.0f);
  var660 = var1141;
  vamp::FloatVector<8, 1> var1143;
  var1143 = var1143 + (var640 * 0.00999999977648258f);
  var1143 = var1143 + (var642 * 0.270700007677078f);
  var1143 = var1143 + (var643 * 1.0f);
  var661 = var1143;
  var812[7ll] = ((var650 * 0.0f) + (var651 * 0.0f)) + (var652 * 0.0f);
  var813[7ll] = ((var654 * 0.0f) + (var655 * 0.0f)) + (var656 * 0.0f);
  var814[7ll] = ((var658 * 0.0f) + (var659 * 0.0f)) + (var660 * 0.0f);
  var812[7ll] = var812[7ll] + var653;
  var813[7ll] = var813[7ll] + var657;
  var814[7ll] = var814[7ll] + var661;
  var815[7ll] = 0.100000001490116f;
  var816[7ll] = 2ll;
  var824[0ll] = ((var650 * 0.0f) + (var651 * 0.0f)) + (var652 * 0.0299999993294477f);
  var857[0ll] = ((var654 * 0.0f) + (var655 * 0.0f)) + (var656 * 0.0299999993294477f);
  var890[0ll] = ((var658 * 0.0f) + (var659 * 0.0f)) + (var660 * 0.0299999993294477f);
  var824[0ll] = var824[0ll] + var653;
  var857[0ll] = var857[0ll] + var657;
  var890[0ll] = var890[0ll] + var661;
  var923[0ll] = 0.0700000002980232f;
  var824[1ll] = ((var650 * 0.0f) + (var651 * 0.0f)) + (var652 * -0.0299999993294477f);
  var857[1ll] = ((var654 * 0.0f) + (var655 * 0.0f)) + (var656 * -0.0299999993294477f);
  var890[1ll] = ((var658 * 0.0f) + (var659 * 0.0f)) + (var660 * -0.0299999993294477f);
  var824[1ll] = var824[1ll] + var653;
  var857[1ll] = var857[1ll] + var657;
  var890[1ll] = var890[1ll] + var661;
  var923[1ll] = 0.0700000002980232f;
  int var1145;
  var1145 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923);
  if (var1145)
    return 0; //collision pair: 0,7 : torso_0,left_lower_forearm_0
  var1145 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923);
  if (var1145)
    return 0; //collision pair: 1,7 : head_0,left_lower_forearm_0
  var1145 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923);
  if (var1145)
    return 0; //collision pair: 2,7 : left_upper_shoulder_0,left_lower_forearm_0
  var1145 = ctup_runtime::link_vs_environment_collision(var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, arg4);
  if (var1145)
    return 0;
  vamp::FloatVector<8, 1> var1146 = arg5[6ll];
  var414 = var1146.sin();
  var415 = var1146.cos();
  var398 = var415;
  var399 = -(var414);
  var402 = var414;
  var403 = var415;
  vamp::FloatVector<8, 1> var1147;
  var1147 = var1147 + (1.0f * var398);
  var953 = var1147;
  vamp::FloatVector<8, 1> var1149;
  var1149 = var1149 + (1.0f * var399);
  var954 = var1149;
  vamp::FloatVector<8, 1> var1151;
  var1151 = var1151 + (1.0f * var402);
  var957 = var1151;
  vamp::FloatVector<8, 1> var1153;
  var1153 = var1153 + (1.0f * var403);
  var958 = var1153;
  vamp::FloatVector<8, 1> var1155;
  var1155 = var1155 + (var651 * var953);
  var1155 = var1155 + (var652 * var957);
  var668 = var1155;
  vamp::FloatVector<8, 1> var1157;
  var1157 = var1157 + (var651 * var954);
  var1157 = var1157 + (var652 * var958);
  var669 = var1157;
  vamp::FloatVector<8, 1> var1159;
  var1159 = var1159 + (var650 * 1.0f);
  var670 = var1159;
  vamp::FloatVector<8, 1> var1161;
  var1161 = var1161 + (var650 * 0.115974999964237f);
  var1161 = var1161 + (var653 * 1.0f);
  var671 = var1161;
  vamp::FloatVector<8, 1> var1163;
  var1163 = var1163 + (var655 * var953);
  var1163 = var1163 + (var656 * var957);
  var672 = var1163;
  vamp::FloatVector<8, 1> var1165;
  var1165 = var1165 + (var655 * var954);
  var1165 = var1165 + (var656 * var958);
  var673 = var1165;
  vamp::FloatVector<8, 1> var1167;
  var1167 = var1167 + (var654 * 1.0f);
  var674 = var1167;
  vamp::FloatVector<8, 1> var1169;
  var1169 = var1169 + (var654 * 0.115974999964237f);
  var1169 = var1169 + (var657 * 1.0f);
  var675 = var1169;
  vamp::FloatVector<8, 1> var1171;
  var1171 = var1171 + (var659 * var953);
  var1171 = var1171 + (var660 * var957);
  var676 = var1171;
  vamp::FloatVector<8, 1> var1173;
  var1173 = var1173 + (var659 * var954);
  var1173 = var1173 + (var660 * var958);
  var677 = var1173;
  vamp::FloatVector<8, 1> var1175;
  var1175 = var1175 + (var658 * 1.0f);
  var678 = var1175;
  vamp::FloatVector<8, 1> var1177;
  var1177 = var1177 + (var658 * 0.115974999964237f);
  var1177 = var1177 + (var661 * 1.0f);
  var679 = var1177;
  var812[8ll] = ((var668 * 0.0f) + (var669 * 0.0f)) + (var670 * -0.0149999996647239f);
  var813[8ll] = ((var672 * 0.0f) + (var673 * 0.0f)) + (var674 * -0.0149999996647239f);
  var814[8ll] = ((var676 * 0.0f) + (var677 * 0.0f)) + (var678 * -0.0149999996647239f);
  var812[8ll] = var812[8ll] + var671;
  var813[8ll] = var813[8ll] + var675;
  var814[8ll] = var814[8ll] + var679;
  var815[8ll] = 0.104999996721745f;
  var816[8ll] = 2ll;
  var825[0ll] = ((var668 * 0.0f) + (var669 * 0.0f)) + (var670 * 0.0199999995529652f);
  var858[0ll] = ((var672 * 0.0f) + (var673 * 0.0f)) + (var674 * 0.0199999995529652f);
  var891[0ll] = ((var676 * 0.0f) + (var677 * 0.0f)) + (var678 * 0.0199999995529652f);
  var825[0ll] = var825[0ll] + var671;
  var858[0ll] = var858[0ll] + var675;
  var891[0ll] = var891[0ll] + var679;
  var924[0ll] = 0.0700000002980232f;
  var825[1ll] = ((var668 * 0.0f) + (var669 * 0.0f)) + (var670 * -0.0399999991059303f);
  var858[1ll] = ((var672 * 0.0f) + (var673 * 0.0f)) + (var674 * -0.0399999991059303f);
  var891[1ll] = ((var676 * 0.0f) + (var677 * 0.0f)) + (var678 * -0.0399999991059303f);
  var825[1ll] = var825[1ll] + var671;
  var858[1ll] = var858[1ll] + var675;
  var891[1ll] = var891[1ll] + var679;
  var924[1ll] = 0.0799999982118607f;
  int var1179;
  var1179 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924);
  if (var1179)
    return 0; //collision pair: 0,8 : torso_0,left_wrist_0
  var1179 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924);
  if (var1179)
    return 0; //collision pair: 1,8 : head_0,left_wrist_0
  var1179 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924);
  if (var1179)
    return 0; //collision pair: 2,8 : left_upper_shoulder_0,left_wrist_0
  var1179 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924);
  if (var1179)
    return 0; //collision pair: 3,8 : left_lower_shoulder_0,left_wrist_0
  var1179 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924);
  if (var1179)
    return 0; //collision pair: 4,8 : left_upper_elbow_0,left_wrist_0
  var1179 = ctup_runtime::link_vs_environment_collision(var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, arg4);
  if (var1179)
    return 0;
  var812[9ll] = ((var668 * 0.00999999977648258f) + (var669 * 0.0f)) + (var670 * 0.0935499966144562f);
  var813[9ll] = ((var672 * 0.00999999977648258f) + (var673 * 0.0f)) + (var674 * 0.0935499966144562f);
  var814[9ll] = ((var676 * 0.00999999977648258f) + (var677 * 0.0f)) + (var678 * 0.0935499966144562f);
  var812[9ll] = var812[9ll] + var671;
  var813[9ll] = var813[9ll] + var675;
  var814[9ll] = var814[9ll] + var679;
  var815[9ll] = 0.0500000007450581f;
  var816[9ll] = 1ll;
  var826[0ll] = ((var668 * 0.00999999977648258f) + (var669 * 0.0f)) + (var670 * 0.0935499966144562f);
  var859[0ll] = ((var672 * 0.00999999977648258f) + (var673 * 0.0f)) + (var674 * 0.0935499966144562f);
  var892[0ll] = ((var676 * 0.00999999977648258f) + (var677 * 0.0f)) + (var678 * 0.0935499966144562f);
  var826[0ll] = var826[0ll] + var671;
  var859[0ll] = var859[0ll] + var675;
  var892[0ll] = var892[0ll] + var679;
  var925[0ll] = 0.0500000007450581f;
  int var1180;
  var1180 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925);
  if (var1180)
    return 0; //collision pair: 0,9 : torso_0,left_hand_0
  var1180 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925);
  if (var1180)
    return 0; //collision pair: 1,9 : head_0,left_hand_0
  var1180 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925);
  if (var1180)
    return 0; //collision pair: 2,9 : left_upper_shoulder_0,left_hand_0
  var1180 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925);
  if (var1180)
    return 0; //collision pair: 3,9 : left_lower_shoulder_0,left_hand_0
  var1180 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925);
  if (var1180)
    return 0; //collision pair: 4,9 : left_upper_elbow_0,left_hand_0
  var1180 = ctup_runtime::link_vs_environment_collision(var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, arg4);
  if (var1180)
    return 0;
  var812[10ll] = ((var668 * 0.0f) + (var669 * 0.0f)) + (var670 * 0.138549998402596f);
  var813[10ll] = ((var672 * 0.0f) + (var673 * 0.0f)) + (var674 * 0.138549998402596f);
  var814[10ll] = ((var676 * 0.0f) + (var677 * 0.0f)) + (var678 * 0.138549998402596f);
  var812[10ll] = var812[10ll] + var671;
  var813[10ll] = var813[10ll] + var675;
  var814[10ll] = var814[10ll] + var679;
  var815[10ll] = 0.0599999986588955f;
  var816[10ll] = 2ll;
  var827[0ll] = ((var668 * 0.0f) + (var669 * 0.0199999995529652f)) + (var670 * 0.138549998402596f);
  var860[0ll] = ((var672 * 0.0f) + (var673 * 0.0199999995529652f)) + (var674 * 0.138549998402596f);
  var893[0ll] = ((var676 * 0.0f) + (var677 * 0.0199999995529652f)) + (var678 * 0.138549998402596f);
  var827[0ll] = var827[0ll] + var671;
  var860[0ll] = var860[0ll] + var675;
  var893[0ll] = var893[0ll] + var679;
  var926[0ll] = 0.0399999991059303f;
  var827[1ll] = ((var668 * 0.0f) + (var669 * -0.0199999995529652f)) + (var670 * 0.138549998402596f);
  var860[1ll] = ((var672 * 0.0f) + (var673 * -0.0199999995529652f)) + (var674 * 0.138549998402596f);
  var893[1ll] = ((var676 * 0.0f) + (var677 * -0.0199999995529652f)) + (var678 * 0.138549998402596f);
  var827[1ll] = var827[1ll] + var671;
  var860[1ll] = var860[1ll] + var675;
  var893[1ll] = var893[1ll] + var679;
  var926[1ll] = 0.0399999991059303f;
  int var1181;
  var1181 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926);
  if (var1181)
    return 0; //collision pair: 0,10 : torso_0,left_gripper_base_0
  var1181 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926);
  if (var1181)
    return 0; //collision pair: 1,10 : head_0,left_gripper_base_0
  var1181 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926);
  if (var1181)
    return 0; //collision pair: 2,10 : left_upper_shoulder_0,left_gripper_base_0
  var1181 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926);
  if (var1181)
    return 0; //collision pair: 3,10 : left_lower_shoulder_0,left_gripper_base_0
  var1181 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926);
  if (var1181)
    return 0; //collision pair: 4,10 : left_upper_elbow_0,left_gripper_base_0
  var1181 = ctup_runtime::link_vs_environment_collision(var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, arg4);
  if (var1181)
    return 0;
  var812[11ll] = ((var668 * -0.00499999988824129f) + (var669 * 0.0693330019712448f)) + (var670 * 0.166549995541573f);
  var813[11ll] = ((var672 * -0.00499999988824129f) + (var673 * 0.0693330019712448f)) + (var674 * 0.166549995541573f);
  var814[11ll] = ((var676 * -0.00499999988824129f) + (var677 * 0.0693330019712448f)) + (var678 * 0.166549995541573f);
  var812[11ll] = var812[11ll] + var671;
  var813[11ll] = var813[11ll] + var675;
  var814[11ll] = var814[11ll] + var679;
  var815[11ll] = 0.0270000007003546f;
  var816[11ll] = 2ll;
  var828[0ll] = ((var668 * -0.00499999988824129f) + (var669 * 0.0813329964876175f)) + (var670 * 0.166549995541573f);
  var861[0ll] = ((var672 * -0.00499999988824129f) + (var673 * 0.0813329964876175f)) + (var674 * 0.166549995541573f);
  var894[0ll] = ((var676 * -0.00499999988824129f) + (var677 * 0.0813329964876175f)) + (var678 * 0.166549995541573f);
  var828[0ll] = var828[0ll] + var671;
  var861[0ll] = var861[0ll] + var675;
  var894[0ll] = var894[0ll] + var679;
  var927[0ll] = 0.0149999996647239f;
  var828[1ll] = ((var668 * -0.00499999988824129f) + (var669 * 0.0573330000042915f)) + (var670 * 0.166549995541573f);
  var861[1ll] = ((var672 * -0.00499999988824129f) + (var673 * 0.0573330000042915f)) + (var674 * 0.166549995541573f);
  var894[1ll] = ((var676 * -0.00499999988824129f) + (var677 * 0.0573330000042915f)) + (var678 * 0.166549995541573f);
  var828[1ll] = var828[1ll] + var671;
  var861[1ll] = var861[1ll] + var675;
  var894[1ll] = var894[1ll] + var679;
  var927[1ll] = 0.0149999996647239f;
  int var1182;
  var1182 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927);
  if (var1182)
    return 0; //collision pair: 0,11 : torso_0,l_gripper_l_finger_0
  var1182 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927);
  if (var1182)
    return 0; //collision pair: 2,11 : left_upper_shoulder_0,l_gripper_l_finger_0
  var1182 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927);
  if (var1182)
    return 0; //collision pair: 3,11 : left_lower_shoulder_0,l_gripper_l_finger_0
  var1182 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927);
  if (var1182)
    return 0; //collision pair: 4,11 : left_upper_elbow_0,l_gripper_l_finger_0
  var1182 = ctup_runtime::link_vs_environment_collision(var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, arg4);
  if (var1182)
    return 0;
  var812[12ll] = ((var668 * 0.0f) + (var669 * 0.0863329991698265f)) + (var670 * 0.208550006151199f);
  var813[12ll] = ((var672 * 0.0f) + (var673 * 0.0863329991698265f)) + (var674 * 0.208550006151199f);
  var814[12ll] = ((var676 * 0.0f) + (var677 * 0.0863329991698265f)) + (var678 * 0.208550006151199f);
  var812[12ll] = var812[12ll] + var671;
  var813[12ll] = var813[12ll] + var675;
  var814[12ll] = var814[12ll] + var679;
  var815[12ll] = 0.0320000015199184f;
  var816[12ll] = 3ll;
  var829[0ll] = ((var668 * 0.0f) + (var669 * 0.0865830034017563f)) + (var670 * 0.188549995422363f);
  var862[0ll] = ((var672 * 0.0f) + (var673 * 0.0865830034017563f)) + (var674 * 0.188549995422363f);
  var895[0ll] = ((var676 * 0.0f) + (var677 * 0.0865830034017563f)) + (var678 * 0.188549995422363f);
  var829[0ll] = var829[0ll] + var671;
  var862[0ll] = var862[0ll] + var675;
  var895[0ll] = var895[0ll] + var679;
  var928[0ll] = 0.0120000001043081f;
  var829[1ll] = ((var668 * 0.0f) + (var669 * 0.0865830034017563f)) + (var670 * 0.208550006151199f);
  var862[1ll] = ((var672 * 0.0f) + (var673 * 0.0865830034017563f)) + (var674 * 0.208550006151199f);
  var895[1ll] = ((var676 * 0.0f) + (var677 * 0.0865830034017563f)) + (var678 * 0.208550006151199f);
  var829[1ll] = var829[1ll] + var671;
  var862[1ll] = var862[1ll] + var675;
  var895[1ll] = var895[1ll] + var679;
  var928[1ll] = 0.0120000001043081f;
  var829[2ll] = ((var668 * 0.0f) + (var669 * 0.0865830034017563f)) + (var670 * 0.228550001978874f);
  var862[2ll] = ((var672 * 0.0f) + (var673 * 0.0865830034017563f)) + (var674 * 0.228550001978874f);
  var895[2ll] = ((var676 * 0.0f) + (var677 * 0.0865830034017563f)) + (var678 * 0.228550001978874f);
  var829[2ll] = var829[2ll] + var671;
  var862[2ll] = var862[2ll] + var675;
  var895[2ll] = var895[2ll] + var679;
  var928[2ll] = 0.0120000001043081f;
  int var1183;
  var1183 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928);
  if (var1183)
    return 0; //collision pair: 0,12 : torso_0,l_gripper_l_finger_2_0
  var1183 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928);
  if (var1183)
    return 0; //collision pair: 2,12 : left_upper_shoulder_0,l_gripper_l_finger_2_0
  var1183 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928);
  if (var1183)
    return 0; //collision pair: 3,12 : left_lower_shoulder_0,l_gripper_l_finger_2_0
  var1183 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928);
  if (var1183)
    return 0; //collision pair: 4,12 : left_upper_elbow_0,l_gripper_l_finger_2_0
  var1183 = ctup_runtime::link_vs_environment_collision(var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, arg4);
  if (var1183)
    return 0;
  var812[13ll] = ((var668 * 0.0f) + (var669 * 0.0825830027461052f)) + (var670 * 0.256249994039536f);
  var813[13ll] = ((var672 * 0.0f) + (var673 * 0.0825830027461052f)) + (var674 * 0.256249994039536f);
  var814[13ll] = ((var676 * 0.0f) + (var677 * 0.0825830027461052f)) + (var678 * 0.256249994039536f);
  var812[13ll] = var812[13ll] + var671;
  var813[13ll] = var813[13ll] + var675;
  var814[13ll] = var814[13ll] + var679;
  var815[13ll] = 0.0280000008642673f;
  var816[13ll] = 4ll;
  var830[0ll] = ((var668 * 0.00999999977648258f) + (var669 * 0.0820830017328262f)) + (var670 * 0.266250014305115f);
  var863[0ll] = ((var672 * 0.00999999977648258f) + (var673 * 0.0820830017328262f)) + (var674 * 0.266250014305115f);
  var896[0ll] = ((var676 * 0.00999999977648258f) + (var677 * 0.0820830017328262f)) + (var678 * 0.266250014305115f);
  var830[0ll] = var830[0ll] + var671;
  var863[0ll] = var863[0ll] + var675;
  var896[0ll] = var896[0ll] + var679;
  var929[0ll] = 0.0140000004321337f;
  var830[1ll] = ((var668 * -0.00999999977648258f) + (var669 * 0.0820830017328262f)) + (var670 * 0.266250014305115f);
  var863[1ll] = ((var672 * -0.00999999977648258f) + (var673 * 0.0820830017328262f)) + (var674 * 0.266250014305115f);
  var896[1ll] = ((var676 * -0.00999999977648258f) + (var677 * 0.0820830017328262f)) + (var678 * 0.266250014305115f);
  var830[1ll] = var830[1ll] + var671;
  var863[1ll] = var863[1ll] + var675;
  var896[1ll] = var896[1ll] + var679;
  var929[1ll] = 0.0140000004321337f;
  var830[2ll] = ((var668 * -0.00999999977648258f) + (var669 * 0.0820830017328262f)) + (var670 * 0.246250003576279f);
  var863[2ll] = ((var672 * -0.00999999977648258f) + (var673 * 0.0820830017328262f)) + (var674 * 0.246250003576279f);
  var896[2ll] = ((var676 * -0.00999999977648258f) + (var677 * 0.0820830017328262f)) + (var678 * 0.246250003576279f);
  var830[2ll] = var830[2ll] + var671;
  var863[2ll] = var863[2ll] + var675;
  var896[2ll] = var896[2ll] + var679;
  var929[2ll] = 0.0140000004321337f;
  var830[3ll] = ((var668 * 0.00999999977648258f) + (var669 * 0.0820830017328262f)) + (var670 * 0.246250003576279f);
  var863[3ll] = ((var672 * 0.00999999977648258f) + (var673 * 0.0820830017328262f)) + (var674 * 0.246250003576279f);
  var896[3ll] = ((var676 * 0.00999999977648258f) + (var677 * 0.0820830017328262f)) + (var678 * 0.246250003576279f);
  var830[3ll] = var830[3ll] + var671;
  var863[3ll] = var863[3ll] + var675;
  var896[3ll] = var896[3ll] + var679;
  var929[3ll] = 0.0140000004321337f;
  int var1184;
  var1184 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1184)
    return 0; //collision pair: 0,13 : torso_0,l_gripper_l_finger_tip_0
  var1184 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1184)
    return 0; //collision pair: 1,13 : head_0,l_gripper_l_finger_tip_0
  var1184 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1184)
    return 0; //collision pair: 2,13 : left_upper_shoulder_0,l_gripper_l_finger_tip_0
  var1184 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1184)
    return 0; //collision pair: 3,13 : left_lower_shoulder_0,l_gripper_l_finger_tip_0
  var1184 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1184)
    return 0; //collision pair: 4,13 : left_upper_elbow_0,l_gripper_l_finger_tip_0
  var1184 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1184)
    return 0; //collision pair: 5,13 : left_lower_elbow_0,l_gripper_l_finger_tip_0
  var1184 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1184)
    return 0; //collision pair: 6,13 : left_upper_forearm_0,l_gripper_l_finger_tip_0
  var1184 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1184)
    return 0; //collision pair: 7,13 : left_lower_forearm_0,l_gripper_l_finger_tip_0
  var1184 = ctup_runtime::link_vs_environment_collision(var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, arg4);
  if (var1184)
    return 0;
  var812[14ll] = ((var668 * 0.00499999988824129f) + (var669 * -0.0693330019712448f)) + (var670 * 0.166549995541573f);
  var813[14ll] = ((var672 * 0.00499999988824129f) + (var673 * -0.0693330019712448f)) + (var674 * 0.166549995541573f);
  var814[14ll] = ((var676 * 0.00499999988824129f) + (var677 * -0.0693330019712448f)) + (var678 * 0.166549995541573f);
  var812[14ll] = var812[14ll] + var671;
  var813[14ll] = var813[14ll] + var675;
  var814[14ll] = var814[14ll] + var679;
  var815[14ll] = 0.025000000372529f;
  var816[14ll] = 2ll;
  var831[0ll] = ((var668 * 0.00499999988824129f) + (var669 * -0.0593330003321171f)) + (var670 * 0.166549995541573f);
  var864[0ll] = ((var672 * 0.00499999988824129f) + (var673 * -0.0593330003321171f)) + (var674 * 0.166549995541573f);
  var897[0ll] = ((var676 * 0.00499999988824129f) + (var677 * -0.0593330003321171f)) + (var678 * 0.166549995541573f);
  var831[0ll] = var831[0ll] + var671;
  var864[0ll] = var864[0ll] + var675;
  var897[0ll] = var897[0ll] + var679;
  var930[0ll] = 0.0149999996647239f;
  var831[1ll] = ((var668 * 0.00499999988824129f) + (var669 * -0.0793329998850822f)) + (var670 * 0.166549995541573f);
  var864[1ll] = ((var672 * 0.00499999988824129f) + (var673 * -0.0793329998850822f)) + (var674 * 0.166549995541573f);
  var897[1ll] = ((var676 * 0.00499999988824129f) + (var677 * -0.0793329998850822f)) + (var678 * 0.166549995541573f);
  var831[1ll] = var831[1ll] + var671;
  var864[1ll] = var864[1ll] + var675;
  var897[1ll] = var897[1ll] + var679;
  var930[1ll] = 0.0149999996647239f;
  int var1185;
  var1185 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930);
  if (var1185)
    return 0; //collision pair: 0,14 : torso_0,l_gripper_r_finger_0
  var1185 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930);
  if (var1185)
    return 0; //collision pair: 1,14 : head_0,l_gripper_r_finger_0
  var1185 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930);
  if (var1185)
    return 0; //collision pair: 2,14 : left_upper_shoulder_0,l_gripper_r_finger_0
  var1185 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930);
  if (var1185)
    return 0; //collision pair: 3,14 : left_lower_shoulder_0,l_gripper_r_finger_0
  var1185 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930);
  if (var1185)
    return 0; //collision pair: 4,14 : left_upper_elbow_0,l_gripper_r_finger_0
  var1185 = ctup_runtime::link_vs_environment_collision(var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, arg4);
  if (var1185)
    return 0;
  var812[15ll] = ((var668 * 0.0f) + (var669 * -0.0863329991698265f)) + (var670 * 0.208550006151199f);
  var813[15ll] = ((var672 * 0.0f) + (var673 * -0.0863329991698265f)) + (var674 * 0.208550006151199f);
  var814[15ll] = ((var676 * 0.0f) + (var677 * -0.0863329991698265f)) + (var678 * 0.208550006151199f);
  var812[15ll] = var812[15ll] + var671;
  var813[15ll] = var813[15ll] + var675;
  var814[15ll] = var814[15ll] + var679;
  var815[15ll] = 0.0320000015199184f;
  var816[15ll] = 3ll;
  var832[0ll] = ((var668 * 0.0f) + (var669 * -0.0865830034017563f)) + (var670 * 0.188549995422363f);
  var865[0ll] = ((var672 * 0.0f) + (var673 * -0.0865830034017563f)) + (var674 * 0.188549995422363f);
  var898[0ll] = ((var676 * 0.0f) + (var677 * -0.0865830034017563f)) + (var678 * 0.188549995422363f);
  var832[0ll] = var832[0ll] + var671;
  var865[0ll] = var865[0ll] + var675;
  var898[0ll] = var898[0ll] + var679;
  var931[0ll] = 0.0120000001043081f;
  var832[1ll] = ((var668 * 0.0f) + (var669 * -0.0865830034017563f)) + (var670 * 0.208550006151199f);
  var865[1ll] = ((var672 * 0.0f) + (var673 * -0.0865830034017563f)) + (var674 * 0.208550006151199f);
  var898[1ll] = ((var676 * 0.0f) + (var677 * -0.0865830034017563f)) + (var678 * 0.208550006151199f);
  var832[1ll] = var832[1ll] + var671;
  var865[1ll] = var865[1ll] + var675;
  var898[1ll] = var898[1ll] + var679;
  var931[1ll] = 0.0120000001043081f;
  var832[2ll] = ((var668 * 0.0f) + (var669 * -0.0865830034017563f)) + (var670 * 0.228550001978874f);
  var865[2ll] = ((var672 * 0.0f) + (var673 * -0.0865830034017563f)) + (var674 * 0.228550001978874f);
  var898[2ll] = ((var676 * 0.0f) + (var677 * -0.0865830034017563f)) + (var678 * 0.228550001978874f);
  var832[2ll] = var832[2ll] + var671;
  var865[2ll] = var865[2ll] + var675;
  var898[2ll] = var898[2ll] + var679;
  var931[2ll] = 0.0120000001043081f;
  int var1186;
  var1186 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931);
  if (var1186)
    return 0; //collision pair: 0,15 : torso_0,l_gripper_r_finger_2_0
  var1186 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931);
  if (var1186)
    return 0; //collision pair: 1,15 : head_0,l_gripper_r_finger_2_0
  var1186 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931);
  if (var1186)
    return 0; //collision pair: 2,15 : left_upper_shoulder_0,l_gripper_r_finger_2_0
  var1186 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931);
  if (var1186)
    return 0; //collision pair: 3,15 : left_lower_shoulder_0,l_gripper_r_finger_2_0
  var1186 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931);
  if (var1186)
    return 0; //collision pair: 4,15 : left_upper_elbow_0,l_gripper_r_finger_2_0
  var1186 = ctup_runtime::link_vs_environment_collision(var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, arg4);
  if (var1186)
    return 0;
  var812[16ll] = ((var668 * 0.0f) + (var669 * -0.0825830027461052f)) + (var670 * 0.256249994039536f);
  var813[16ll] = ((var672 * 0.0f) + (var673 * -0.0825830027461052f)) + (var674 * 0.256249994039536f);
  var814[16ll] = ((var676 * 0.0f) + (var677 * -0.0825830027461052f)) + (var678 * 0.256249994039536f);
  var812[16ll] = var812[16ll] + var671;
  var813[16ll] = var813[16ll] + var675;
  var814[16ll] = var814[16ll] + var679;
  var815[16ll] = 0.0280000008642673f;
  var816[16ll] = 4ll;
  var833[0ll] = ((var668 * 0.00999999977648258f) + (var669 * -0.0820830017328262f)) + (var670 * 0.266250014305115f);
  var866[0ll] = ((var672 * 0.00999999977648258f) + (var673 * -0.0820830017328262f)) + (var674 * 0.266250014305115f);
  var899[0ll] = ((var676 * 0.00999999977648258f) + (var677 * -0.0820830017328262f)) + (var678 * 0.266250014305115f);
  var833[0ll] = var833[0ll] + var671;
  var866[0ll] = var866[0ll] + var675;
  var899[0ll] = var899[0ll] + var679;
  var932[0ll] = 0.0140000004321337f;
  var833[1ll] = ((var668 * -0.00999999977648258f) + (var669 * -0.0820830017328262f)) + (var670 * 0.266250014305115f);
  var866[1ll] = ((var672 * -0.00999999977648258f) + (var673 * -0.0820830017328262f)) + (var674 * 0.266250014305115f);
  var899[1ll] = ((var676 * -0.00999999977648258f) + (var677 * -0.0820830017328262f)) + (var678 * 0.266250014305115f);
  var833[1ll] = var833[1ll] + var671;
  var866[1ll] = var866[1ll] + var675;
  var899[1ll] = var899[1ll] + var679;
  var932[1ll] = 0.0140000004321337f;
  var833[2ll] = ((var668 * -0.00999999977648258f) + (var669 * -0.0820830017328262f)) + (var670 * 0.246250003576279f);
  var866[2ll] = ((var672 * -0.00999999977648258f) + (var673 * -0.0820830017328262f)) + (var674 * 0.246250003576279f);
  var899[2ll] = ((var676 * -0.00999999977648258f) + (var677 * -0.0820830017328262f)) + (var678 * 0.246250003576279f);
  var833[2ll] = var833[2ll] + var671;
  var866[2ll] = var866[2ll] + var675;
  var899[2ll] = var899[2ll] + var679;
  var932[2ll] = 0.0140000004321337f;
  var833[3ll] = ((var668 * 0.00999999977648258f) + (var669 * -0.0820830017328262f)) + (var670 * 0.246250003576279f);
  var866[3ll] = ((var672 * 0.00999999977648258f) + (var673 * -0.0820830017328262f)) + (var674 * 0.246250003576279f);
  var899[3ll] = ((var676 * 0.00999999977648258f) + (var677 * -0.0820830017328262f)) + (var678 * 0.246250003576279f);
  var833[3ll] = var833[3ll] + var671;
  var866[3ll] = var866[3ll] + var675;
  var899[3ll] = var899[3ll] + var679;
  var932[3ll] = 0.0140000004321337f;
  int var1187;
  var1187 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1187)
    return 0; //collision pair: 0,16 : torso_0,l_gripper_r_finger_tip_0
  var1187 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1187)
    return 0; //collision pair: 1,16 : head_0,l_gripper_r_finger_tip_0
  var1187 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1187)
    return 0; //collision pair: 2,16 : left_upper_shoulder_0,l_gripper_r_finger_tip_0
  var1187 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1187)
    return 0; //collision pair: 3,16 : left_lower_shoulder_0,l_gripper_r_finger_tip_0
  var1187 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1187)
    return 0; //collision pair: 4,16 : left_upper_elbow_0,l_gripper_r_finger_tip_0
  var1187 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1187)
    return 0; //collision pair: 5,16 : left_lower_elbow_0,l_gripper_r_finger_tip_0
  var1187 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1187)
    return 0; //collision pair: 6,16 : left_upper_forearm_0,l_gripper_r_finger_tip_0
  var1187 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1187)
    return 0; //collision pair: 7,16 : left_lower_forearm_0,l_gripper_r_finger_tip_0
  var1187 = ctup_runtime::link_vs_environment_collision(var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, arg4);
  if (var1187)
    return 0;
  vamp::FloatVector<8, 1> var1188 = arg5[7ll];
  var432 = var1188.sin();
  var433 = var1188.cos();
  var416 = var433;
  var417 = -(var432);
  var420 = var432;
  var421 = var433;
  vamp::FloatVector<8, 1> var1189;
  var1189 = var1189 + (0.707105457782745f * var416);
  var1189 = var1189 + (0.707108080387115f * var420);
  var949 = var1189;
  vamp::FloatVector<8, 1> var1191;
  var1191 = var1191 + (0.707105457782745f * var417);
  var1191 = var1191 + (0.707108080387115f * var421);
  var950 = var1191;
  vamp::FloatVector<8, 1> var1193;
  var1193 = var1193 + (-0.707108080387115f * var416);
  var1193 = var1193 + (0.707105457782745f * var420);
  var953 = var1193;
  vamp::FloatVector<8, 1> var1195;
  var1195 = var1195 + (-0.707108080387115f * var417);
  var1195 = var1195 + (0.707105457782745f * var421);
  var954 = var1195;
  var686 = var949;
  var687 = var950;
  var690 = var953;
  var691 = var954;
  var812[18ll] = ((var686 * 0.0f) + (var687 * 0.0f)) + (0.0f * 0.174999997019768f);
  var813[18ll] = ((var690 * 0.0f) + (var691 * 0.0f)) + (0.0f * 0.174999997019768f);
  var814[18ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * 0.174999997019768f);
  var812[18ll] = var812[18ll] + 0.0640272423624992f;
  var813[18ll] = var813[18ll] + -0.259027391672134f;
  var814[18ll] = var814[18ll] + 0.129626005887985f;
  var815[18ll] = 0.174999997019768f;
  var816[18ll] = 2ll;
  var835[0ll] = ((var686 * 0.0f) + (var687 * 0.0f)) + (0.0f * 0.25f);
  var868[0ll] = ((var690 * 0.0f) + (var691 * 0.0f)) + (0.0f * 0.25f);
  var901[0ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * 0.25f);
  var835[0ll] = var835[0ll] + 0.0640272423624992f;
  var868[0ll] = var868[0ll] + -0.259027391672134f;
  var901[0ll] = var901[0ll] + 0.129626005887985f;
  var934[0ll] = 0.100000001490116f;
  var835[1ll] = ((var686 * 0.0f) + (var687 * 0.0f)) + (0.0f * 0.100000001490116f);
  var868[1ll] = ((var690 * 0.0f) + (var691 * 0.0f)) + (0.0f * 0.100000001490116f);
  var901[1ll] = ((0.0f * 0.0f) + (0.0f * 0.0f)) + (1.0f * 0.100000001490116f);
  var835[1ll] = var835[1ll] + 0.0640272423624992f;
  var868[1ll] = var868[1ll] + -0.259027391672134f;
  var901[1ll] = var901[1ll] + 0.129626005887985f;
  var934[1ll] = 0.100000001490116f;
  int var1197;
  var1197 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1197)
    return 0; //collision pair: 7,18 : left_lower_forearm_0,right_upper_shoulder_0
  var1197 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1197)
    return 0; //collision pair: 8,18 : left_wrist_0,right_upper_shoulder_0
  var1197 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1197)
    return 0; //collision pair: 9,18 : left_hand_0,right_upper_shoulder_0
  var1197 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1197)
    return 0; //collision pair: 10,18 : left_gripper_base_0,right_upper_shoulder_0
  var1197 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1197)
    return 0; //collision pair: 11,18 : l_gripper_l_finger_0,right_upper_shoulder_0
  var1197 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1197)
    return 0; //collision pair: 12,18 : l_gripper_l_finger_2_0,right_upper_shoulder_0
  var1197 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1197)
    return 0; //collision pair: 13,18 : l_gripper_l_finger_tip_0,right_upper_shoulder_0
  var1197 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1197)
    return 0; //collision pair: 14,18 : l_gripper_r_finger_0,right_upper_shoulder_0
  var1197 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1197)
    return 0; //collision pair: 15,18 : l_gripper_r_finger_2_0,right_upper_shoulder_0
  var1197 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1197)
    return 0; //collision pair: 16,18 : l_gripper_r_finger_tip_0,right_upper_shoulder_0
  var1197 = ctup_runtime::link_vs_environment_collision(var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, arg4);
  if (var1197)
    return 0;
  vamp::FloatVector<8, 1> var1198 = arg5[8ll];
  var450 = var1198.sin();
  var451 = var1198.cos();
  var434 = var451;
  var435 = -(var450);
  var438 = var450;
  var439 = var451;
  vamp::FloatVector<8, 1> var1199;
  var1199 = var1199 + (1.0f * var434);
  var949 = var1199;
  vamp::FloatVector<8, 1> var1201;
  var1201 = var1201 + (1.0f * var435);
  var950 = var1201;
  vamp::FloatVector<8, 1> var1203;
  var1203 = var1203 + (-1.0f * var438);
  var957 = var1203;
  vamp::FloatVector<8, 1> var1205;
  var1205 = var1205 + (-1.0f * var439);
  var958 = var1205;
  vamp::FloatVector<8, 1> var1207;
  var1207 = var1207 + (var686 * var949);
  var704 = var1207;
  vamp::FloatVector<8, 1> var1209;
  var1209 = var1209 + (var686 * var950);
  var705 = var1209;
  vamp::FloatVector<8, 1> var1211;
  var1211 = var1211 + (var687 * 1.0f);
  var706 = var1211;
  vamp::FloatVector<8, 1> var1213;
  var1213 = var1213 + (var686 * 0.0689999982714653f);
  var1213 = var1213 + (0.0640272423624992f * 1.0f);
  var707 = var1213;
  vamp::FloatVector<8, 1> var1215;
  var1215 = var1215 + (var690 * var949);
  var708 = var1215;
  vamp::FloatVector<8, 1> var1217;
  var1217 = var1217 + (var690 * var950);
  var709 = var1217;
  vamp::FloatVector<8, 1> var1219;
  var1219 = var1219 + (var691 * 1.0f);
  var710 = var1219;
  vamp::FloatVector<8, 1> var1221;
  var1221 = var1221 + (var690 * 0.0689999982714653f);
  var1221 = var1221 + (-0.259027391672134f * 1.0f);
  var711 = var1221;
  vamp::FloatVector<8, 1> var1223;
  var1223 = var1223 + (1.0f * var957);
  var712 = var1223;
  vamp::FloatVector<8, 1> var1225;
  var1225 = var1225 + (1.0f * var958);
  var713 = var1225;
  var812[19ll] = ((var704 * 0.0f) + (var705 * 0.0f)) + (var706 * 0.0f);
  var813[19ll] = ((var708 * 0.0f) + (var709 * 0.0f)) + (var710 * 0.0f);
  var814[19ll] = ((var712 * 0.0f) + (var713 * 0.0f)) + (0.0f * 0.0f);
  var812[19ll] = var812[19ll] + var707;
  var813[19ll] = var813[19ll] + var711;
  var814[19ll] = var814[19ll] + 0.399976015090942f;
  var815[19ll] = 0.100000001490116f;
  var816[19ll] = 0ll;
  int var1227;
  var1227 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 5,19 : left_lower_elbow_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 6,19 : left_upper_forearm_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 7,19 : left_lower_forearm_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 8,19 : left_wrist_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 9,19 : left_hand_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 10,19 : left_gripper_base_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 11,19 : l_gripper_l_finger_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 12,19 : l_gripper_l_finger_2_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 13,19 : l_gripper_l_finger_tip_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 14,19 : l_gripper_r_finger_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 15,19 : l_gripper_r_finger_2_0,right_lower_shoulder_0
  var1227 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1227)
    return 0; //collision pair: 16,19 : l_gripper_r_finger_tip_0,right_lower_shoulder_0
  var1227 = ctup_runtime::link_vs_environment_collision(var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, arg4);
  if (var1227)
    return 0;
  vamp::FloatVector<8, 1> var1228 = arg5[9ll];
  var468 = var1228.sin();
  var469 = var1228.cos();
  var452 = var469;
  var453 = -(var468);
  var456 = var468;
  var457 = var469;
  vamp::FloatVector<8, 1> var1229;
  var1229 = var1229 + (1.0f * var452);
  var953 = var1229;
  vamp::FloatVector<8, 1> var1231;
  var1231 = var1231 + (1.0f * var453);
  var954 = var1231;
  vamp::FloatVector<8, 1> var1233;
  var1233 = var1233 + (1.0f * var456);
  var957 = var1233;
  vamp::FloatVector<8, 1> var1235;
  var1235 = var1235 + (1.0f * var457);
  var958 = var1235;
  vamp::FloatVector<8, 1> var1237;
  var1237 = var1237 + (var705 * var953);
  var1237 = var1237 + (var706 * var957);
  var722 = var1237;
  vamp::FloatVector<8, 1> var1239;
  var1239 = var1239 + (var705 * var954);
  var1239 = var1239 + (var706 * var958);
  var723 = var1239;
  vamp::FloatVector<8, 1> var1241;
  var1241 = var1241 + (var704 * 1.0f);
  var724 = var1241;
  vamp::FloatVector<8, 1> var1243;
  var1243 = var1243 + (var704 * 0.101999998092651f);
  var1243 = var1243 + (var707 * 1.0f);
  var725 = var1243;
  vamp::FloatVector<8, 1> var1245;
  var1245 = var1245 + (var709 * var953);
  var1245 = var1245 + (var710 * var957);
  var726 = var1245;
  vamp::FloatVector<8, 1> var1247;
  var1247 = var1247 + (var709 * var954);
  var1247 = var1247 + (var710 * var958);
  var727 = var1247;
  vamp::FloatVector<8, 1> var1249;
  var1249 = var1249 + (var708 * 1.0f);
  var728 = var1249;
  vamp::FloatVector<8, 1> var1251;
  var1251 = var1251 + (var708 * 0.101999998092651f);
  var1251 = var1251 + (var711 * 1.0f);
  var729 = var1251;
  vamp::FloatVector<8, 1> var1253;
  var1253 = var1253 + (var713 * var953);
  var730 = var1253;
  vamp::FloatVector<8, 1> var1255;
  var1255 = var1255 + (var713 * var954);
  var731 = var1255;
  vamp::FloatVector<8, 1> var1257;
  var1257 = var1257 + (var712 * 1.0f);
  var732 = var1257;
  vamp::FloatVector<8, 1> var1259;
  var1259 = var1259 + (var712 * 0.101999998092651f);
  var1259 = var1259 + (0.399976015090942f * 1.0f);
  var733 = var1259;
  var812[20ll] = ((var722 * -0.00999999977648258f) + (var723 * 0.0f)) + (var724 * 0.109999999403954f);
  var813[20ll] = ((var726 * -0.00999999977648258f) + (var727 * 0.0f)) + (var728 * 0.109999999403954f);
  var814[20ll] = ((var730 * -0.00999999977648258f) + (var731 * 0.0f)) + (var732 * 0.109999999403954f);
  var812[20ll] = var812[20ll] + var725;
  var813[20ll] = var813[20ll] + var729;
  var814[20ll] = var814[20ll] + var733;
  var815[20ll] = 0.189999997615814f;
  var816[20ll] = 3ll;
  var837[0ll] = ((var722 * -0.0199999995529652f) + (var723 * 0.0f)) + (var724 * 0.219999998807907f);
  var870[0ll] = ((var726 * -0.0199999995529652f) + (var727 * 0.0f)) + (var728 * 0.219999998807907f);
  var903[0ll] = ((var730 * -0.0199999995529652f) + (var731 * 0.0f)) + (var732 * 0.219999998807907f);
  var837[0ll] = var837[0ll] + var725;
  var870[0ll] = var870[0ll] + var729;
  var903[0ll] = var903[0ll] + var733;
  var936[0ll] = 0.0799999982118607f;
  var837[1ll] = ((var722 * -0.00999999977648258f) + (var723 * 0.0f)) + (var724 * 0.109999999403954f);
  var870[1ll] = ((var726 * -0.00999999977648258f) + (var727 * 0.0f)) + (var728 * 0.109999999403954f);
  var903[1ll] = ((var730 * -0.00999999977648258f) + (var731 * 0.0f)) + (var732 * 0.109999999403954f);
  var837[1ll] = var837[1ll] + var725;
  var870[1ll] = var870[1ll] + var729;
  var903[1ll] = var903[1ll] + var733;
  var936[1ll] = 0.0799999982118607f;
  var837[2ll] = ((var722 * 0.0f) + (var723 * 0.0f)) + (var724 * 0.0f);
  var870[2ll] = ((var726 * 0.0f) + (var727 * 0.0f)) + (var728 * 0.0f);
  var903[2ll] = ((var730 * 0.0f) + (var731 * 0.0f)) + (var732 * 0.0f);
  var837[2ll] = var837[2ll] + var725;
  var870[2ll] = var870[2ll] + var729;
  var903[2ll] = var903[2ll] + var733;
  var936[2ll] = 0.0799999982118607f;
  int var1261;
  var1261 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 5,20 : left_lower_elbow_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 6,20 : left_upper_forearm_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 7,20 : left_lower_forearm_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 8,20 : left_wrist_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 9,20 : left_hand_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 10,20 : left_gripper_base_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 11,20 : l_gripper_l_finger_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 12,20 : l_gripper_l_finger_2_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 13,20 : l_gripper_l_finger_tip_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 14,20 : l_gripper_r_finger_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 15,20 : l_gripper_r_finger_2_0,right_upper_elbow_0
  var1261 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1261)
    return 0; //collision pair: 16,20 : l_gripper_r_finger_tip_0,right_upper_elbow_0
  var1261 = ctup_runtime::link_vs_environment_collision(var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, arg4);
  if (var1261)
    return 0;
  vamp::FloatVector<8, 1> var1262 = arg5[10ll];
  var486 = var1262.sin();
  var487 = var1262.cos();
  var470 = var487;
  var471 = -(var486);
  var474 = var486;
  var475 = var487;
  vamp::FloatVector<8, 1> var1263;
  var1263 = var1263 + (1.0f * var474);
  var949 = var1263;
  vamp::FloatVector<8, 1> var1265;
  var1265 = var1265 + (1.0f * var475);
  var950 = var1265;
  vamp::FloatVector<8, 1> var1267;
  var1267 = var1267 + (1.0f * var470);
  var957 = var1267;
  vamp::FloatVector<8, 1> var1269;
  var1269 = var1269 + (1.0f * var471);
  var958 = var1269;
  vamp::FloatVector<8, 1> var1271;
  var1271 = var1271 + (var722 * var949);
  var1271 = var1271 + (var724 * var957);
  var740 = var1271;
  vamp::FloatVector<8, 1> var1273;
  var1273 = var1273 + (var722 * var950);
  var1273 = var1273 + (var724 * var958);
  var741 = var1273;
  vamp::FloatVector<8, 1> var1275;
  var1275 = var1275 + (var723 * 1.0f);
  var742 = var1275;
  vamp::FloatVector<8, 1> var1277;
  var1277 = var1277 + (var722 * 0.0689999982714653f);
  var1277 = var1277 + (var724 * 0.262419998645782f);
  var1277 = var1277 + (var725 * 1.0f);
  var743 = var1277;
  vamp::FloatVector<8, 1> var1279;
  var1279 = var1279 + (var726 * var949);
  var1279 = var1279 + (var728 * var957);
  var744 = var1279;
  vamp::FloatVector<8, 1> var1281;
  var1281 = var1281 + (var726 * var950);
  var1281 = var1281 + (var728 * var958);
  var745 = var1281;
  vamp::FloatVector<8, 1> var1283;
  var1283 = var1283 + (var727 * 1.0f);
  var746 = var1283;
  vamp::FloatVector<8, 1> var1285;
  var1285 = var1285 + (var726 * 0.0689999982714653f);
  var1285 = var1285 + (var728 * 0.262419998645782f);
  var1285 = var1285 + (var729 * 1.0f);
  var747 = var1285;
  vamp::FloatVector<8, 1> var1287;
  var1287 = var1287 + (var730 * var949);
  var1287 = var1287 + (var732 * var957);
  var748 = var1287;
  vamp::FloatVector<8, 1> var1289;
  var1289 = var1289 + (var730 * var950);
  var1289 = var1289 + (var732 * var958);
  var749 = var1289;
  vamp::FloatVector<8, 1> var1291;
  var1291 = var1291 + (var731 * 1.0f);
  var750 = var1291;
  vamp::FloatVector<8, 1> var1293;
  var1293 = var1293 + (var730 * 0.0689999982714653f);
  var1293 = var1293 + (var732 * 0.262419998645782f);
  var1293 = var1293 + (var733 * 1.0f);
  var751 = var1293;
  var812[21ll] = ((var740 * 0.0f) + (var741 * 0.0f)) + (var742 * 0.0f);
  var813[21ll] = ((var744 * 0.0f) + (var745 * 0.0f)) + (var746 * 0.0f);
  var814[21ll] = ((var748 * 0.0f) + (var749 * 0.0f)) + (var750 * 0.0f);
  var812[21ll] = var812[21ll] + var743;
  var813[21ll] = var813[21ll] + var747;
  var814[21ll] = var814[21ll] + var751;
  var815[21ll] = 0.100000001490116f;
  var816[21ll] = 0ll;
  int var1295;
  var1295 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 0,21 : torso_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 1,21 : head_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 3,21 : left_lower_shoulder_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 4,21 : left_upper_elbow_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 5,21 : left_lower_elbow_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 6,21 : left_upper_forearm_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 7,21 : left_lower_forearm_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 8,21 : left_wrist_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 9,21 : left_hand_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 10,21 : left_gripper_base_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 11,21 : l_gripper_l_finger_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 12,21 : l_gripper_l_finger_2_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 13,21 : l_gripper_l_finger_tip_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 14,21 : l_gripper_r_finger_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 15,21 : l_gripper_r_finger_2_0,right_lower_elbow_0
  var1295 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1295)
    return 0; //collision pair: 16,21 : l_gripper_r_finger_tip_0,right_lower_elbow_0
  var1295 = ctup_runtime::link_vs_environment_collision(var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937, arg4);
  if (var1295)
    return 0;
  vamp::FloatVector<8, 1> var1296 = arg5[11ll];
  var504 = var1296.sin();
  var505 = var1296.cos();
  var488 = var505;
  var489 = -(var504);
  var492 = var504;
  var493 = var505;
  vamp::FloatVector<8, 1> var1297;
  var1297 = var1297 + (1.0f * var488);
  var953 = var1297;
  vamp::FloatVector<8, 1> var1299;
  var1299 = var1299 + (1.0f * var489);
  var954 = var1299;
  vamp::FloatVector<8, 1> var1301;
  var1301 = var1301 + (1.0f * var492);
  var957 = var1301;
  vamp::FloatVector<8, 1> var1303;
  var1303 = var1303 + (1.0f * var493);
  var958 = var1303;
  vamp::FloatVector<8, 1> var1305;
  var1305 = var1305 + (var741 * var953);
  var1305 = var1305 + (var742 * var957);
  var758 = var1305;
  vamp::FloatVector<8, 1> var1307;
  var1307 = var1307 + (var741 * var954);
  var1307 = var1307 + (var742 * var958);
  var759 = var1307;
  vamp::FloatVector<8, 1> var1309;
  var1309 = var1309 + (var740 * 1.0f);
  var760 = var1309;
  vamp::FloatVector<8, 1> var1311;
  var1311 = var1311 + (var740 * 0.103589996695518f);
  var1311 = var1311 + (var743 * 1.0f);
  var761 = var1311;
  vamp::FloatVector<8, 1> var1313;
  var1313 = var1313 + (var745 * var953);
  var1313 = var1313 + (var746 * var957);
  var762 = var1313;
  vamp::FloatVector<8, 1> var1315;
  var1315 = var1315 + (var745 * var954);
  var1315 = var1315 + (var746 * var958);
  var763 = var1315;
  vamp::FloatVector<8, 1> var1317;
  var1317 = var1317 + (var744 * 1.0f);
  var764 = var1317;
  vamp::FloatVector<8, 1> var1319;
  var1319 = var1319 + (var744 * 0.103589996695518f);
  var1319 = var1319 + (var747 * 1.0f);
  var765 = var1319;
  vamp::FloatVector<8, 1> var1321;
  var1321 = var1321 + (var749 * var953);
  var1321 = var1321 + (var750 * var957);
  var766 = var1321;
  vamp::FloatVector<8, 1> var1323;
  var1323 = var1323 + (var749 * var954);
  var1323 = var1323 + (var750 * var958);
  var767 = var1323;
  vamp::FloatVector<8, 1> var1325;
  var1325 = var1325 + (var748 * 1.0f);
  var768 = var1325;
  vamp::FloatVector<8, 1> var1327;
  var1327 = var1327 + (var748 * 0.103589996695518f);
  var1327 = var1327 + (var751 * 1.0f);
  var769 = var1327;
  var812[22ll] = ((var758 * 0.0f) + (var759 * 0.0f)) + (var760 * 0.109999999403954f);
  var813[22ll] = ((var762 * 0.0f) + (var763 * 0.0f)) + (var764 * 0.109999999403954f);
  var814[22ll] = ((var766 * 0.0f) + (var767 * 0.0f)) + (var768 * 0.109999999403954f);
  var812[22ll] = var812[22ll] + var761;
  var813[22ll] = var813[22ll] + var765;
  var814[22ll] = var814[22ll] + var769;
  var815[22ll] = 0.189999997615814f;
  var816[22ll] = 3ll;
  var839[0ll] = ((var758 * 0.0f) + (var759 * 0.0f)) + (var760 * 0.0f);
  var872[0ll] = ((var762 * 0.0f) + (var763 * 0.0f)) + (var764 * 0.0f);
  var905[0ll] = ((var766 * 0.0f) + (var767 * 0.0f)) + (var768 * 0.0f);
  var839[0ll] = var839[0ll] + var761;
  var872[0ll] = var872[0ll] + var765;
  var905[0ll] = var905[0ll] + var769;
  var938[0ll] = 0.0799999982118607f;
  var839[1ll] = ((var758 * 0.0f) + (var759 * 0.0f)) + (var760 * 0.219999998807907f);
  var872[1ll] = ((var762 * 0.0f) + (var763 * 0.0f)) + (var764 * 0.219999998807907f);
  var905[1ll] = ((var766 * 0.0f) + (var767 * 0.0f)) + (var768 * 0.219999998807907f);
  var839[1ll] = var839[1ll] + var761;
  var872[1ll] = var872[1ll] + var765;
  var905[1ll] = var905[1ll] + var769;
  var938[1ll] = 0.0799999982118607f;
  var839[2ll] = ((var758 * 0.0f) + (var759 * 0.0f)) + (var760 * 0.109999999403954f);
  var872[2ll] = ((var762 * 0.0f) + (var763 * 0.0f)) + (var764 * 0.109999999403954f);
  var905[2ll] = ((var766 * 0.0f) + (var767 * 0.0f)) + (var768 * 0.109999999403954f);
  var839[2ll] = var839[2ll] + var761;
  var872[2ll] = var872[2ll] + var765;
  var905[2ll] = var905[2ll] + var769;
  var938[2ll] = 0.0799999982118607f;
  int var1329;
  var1329 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 0,22 : torso_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 1,22 : head_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 3,22 : left_lower_shoulder_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 4,22 : left_upper_elbow_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 5,22 : left_lower_elbow_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 6,22 : left_upper_forearm_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 7,22 : left_lower_forearm_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 8,22 : left_wrist_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 9,22 : left_hand_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 10,22 : left_gripper_base_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 11,22 : l_gripper_l_finger_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 12,22 : l_gripper_l_finger_2_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 13,22 : l_gripper_l_finger_tip_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 14,22 : l_gripper_r_finger_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 15,22 : l_gripper_r_finger_2_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 16,22 : l_gripper_r_finger_tip_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 17,22 : pedestal_0,right_upper_forearm_0
  var1329 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1329)
    return 0; //collision pair: 18,22 : right_upper_shoulder_0,right_upper_forearm_0
  var1329 = ctup_runtime::link_vs_environment_collision(var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938, arg4);
  if (var1329)
    return 0;
  vamp::FloatVector<8, 1> var1330 = arg5[12ll];
  var522 = var1330.sin();
  var523 = var1330.cos();
  var506 = var523;
  var507 = -(var522);
  var510 = var522;
  var511 = var523;
  vamp::FloatVector<8, 1> var1331;
  var1331 = var1331 + (1.0f * var510);
  var949 = var1331;
  vamp::FloatVector<8, 1> var1333;
  var1333 = var1333 + (1.0f * var511);
  var950 = var1333;
  vamp::FloatVector<8, 1> var1335;
  var1335 = var1335 + (1.0f * var506);
  var957 = var1335;
  vamp::FloatVector<8, 1> var1337;
  var1337 = var1337 + (1.0f * var507);
  var958 = var1337;
  vamp::FloatVector<8, 1> var1339;
  var1339 = var1339 + (var758 * var949);
  var1339 = var1339 + (var760 * var957);
  var776 = var1339;
  vamp::FloatVector<8, 1> var1341;
  var1341 = var1341 + (var758 * var950);
  var1341 = var1341 + (var760 * var958);
  var777 = var1341;
  vamp::FloatVector<8, 1> var1343;
  var1343 = var1343 + (var759 * 1.0f);
  var778 = var1343;
  vamp::FloatVector<8, 1> var1345;
  var1345 = var1345 + (var758 * 0.00999999977648258f);
  var1345 = var1345 + (var760 * 0.270700007677078f);
  var1345 = var1345 + (var761 * 1.0f);
  var779 = var1345;
  vamp::FloatVector<8, 1> var1347;
  var1347 = var1347 + (var762 * var949);
  var1347 = var1347 + (var764 * var957);
  var780 = var1347;
  vamp::FloatVector<8, 1> var1349;
  var1349 = var1349 + (var762 * var950);
  var1349 = var1349 + (var764 * var958);
  var781 = var1349;
  vamp::FloatVector<8, 1> var1351;
  var1351 = var1351 + (var763 * 1.0f);
  var782 = var1351;
  vamp::FloatVector<8, 1> var1353;
  var1353 = var1353 + (var762 * 0.00999999977648258f);
  var1353 = var1353 + (var764 * 0.270700007677078f);
  var1353 = var1353 + (var765 * 1.0f);
  var783 = var1353;
  vamp::FloatVector<8, 1> var1355;
  var1355 = var1355 + (var766 * var949);
  var1355 = var1355 + (var768 * var957);
  var784 = var1355;
  vamp::FloatVector<8, 1> var1357;
  var1357 = var1357 + (var766 * var950);
  var1357 = var1357 + (var768 * var958);
  var785 = var1357;
  vamp::FloatVector<8, 1> var1359;
  var1359 = var1359 + (var767 * 1.0f);
  var786 = var1359;
  vamp::FloatVector<8, 1> var1361;
  var1361 = var1361 + (var766 * 0.00999999977648258f);
  var1361 = var1361 + (var768 * 0.270700007677078f);
  var1361 = var1361 + (var769 * 1.0f);
  var787 = var1361;
  var812[23ll] = ((var776 * 0.0f) + (var777 * 0.0f)) + (var778 * 0.0f);
  var813[23ll] = ((var780 * 0.0f) + (var781 * 0.0f)) + (var782 * 0.0f);
  var814[23ll] = ((var784 * 0.0f) + (var785 * 0.0f)) + (var786 * 0.0f);
  var812[23ll] = var812[23ll] + var779;
  var813[23ll] = var813[23ll] + var783;
  var814[23ll] = var814[23ll] + var787;
  var815[23ll] = 0.100000001490116f;
  var816[23ll] = 2ll;
  var840[0ll] = ((var776 * 0.0f) + (var777 * 0.0f)) + (var778 * 0.0299999993294477f);
  var873[0ll] = ((var780 * 0.0f) + (var781 * 0.0f)) + (var782 * 0.0299999993294477f);
  var906[0ll] = ((var784 * 0.0f) + (var785 * 0.0f)) + (var786 * 0.0299999993294477f);
  var840[0ll] = var840[0ll] + var779;
  var873[0ll] = var873[0ll] + var783;
  var906[0ll] = var906[0ll] + var787;
  var939[0ll] = 0.0700000002980232f;
  var840[1ll] = ((var776 * 0.0f) + (var777 * 0.0f)) + (var778 * -0.0299999993294477f);
  var873[1ll] = ((var780 * 0.0f) + (var781 * 0.0f)) + (var782 * -0.0299999993294477f);
  var906[1ll] = ((var784 * 0.0f) + (var785 * 0.0f)) + (var786 * -0.0299999993294477f);
  var840[1ll] = var840[1ll] + var779;
  var873[1ll] = var873[1ll] + var783;
  var906[1ll] = var906[1ll] + var787;
  var939[1ll] = 0.0700000002980232f;
  int var1363;
  var1363 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 0,23 : torso_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 1,23 : head_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 2,23 : left_upper_shoulder_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 3,23 : left_lower_shoulder_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 4,23 : left_upper_elbow_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 5,23 : left_lower_elbow_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 6,23 : left_upper_forearm_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 7,23 : left_lower_forearm_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 8,23 : left_wrist_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 9,23 : left_hand_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 10,23 : left_gripper_base_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 11,23 : l_gripper_l_finger_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 12,23 : l_gripper_l_finger_2_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 13,23 : l_gripper_l_finger_tip_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 14,23 : l_gripper_r_finger_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 15,23 : l_gripper_r_finger_2_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 16,23 : l_gripper_r_finger_tip_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 17,23 : pedestal_0,right_lower_forearm_0
  var1363 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1363)
    return 0; //collision pair: 18,23 : right_upper_shoulder_0,right_lower_forearm_0
  var1363 = ctup_runtime::link_vs_environment_collision(var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939, arg4);
  if (var1363)
    return 0;
  vamp::FloatVector<8, 1> var1364 = arg5[13ll];
  var540 = var1364.sin();
  var541 = var1364.cos();
  var524 = var541;
  var525 = -(var540);
  var528 = var540;
  var529 = var541;
  vamp::FloatVector<8, 1> var1365;
  var1365 = var1365 + (1.0f * var524);
  var953 = var1365;
  vamp::FloatVector<8, 1> var1367;
  var1367 = var1367 + (1.0f * var525);
  var954 = var1367;
  vamp::FloatVector<8, 1> var1369;
  var1369 = var1369 + (1.0f * var528);
  var957 = var1369;
  vamp::FloatVector<8, 1> var1371;
  var1371 = var1371 + (1.0f * var529);
  var958 = var1371;
  vamp::FloatVector<8, 1> var1373;
  var1373 = var1373 + (var777 * var953);
  var1373 = var1373 + (var778 * var957);
  var794 = var1373;
  vamp::FloatVector<8, 1> var1375;
  var1375 = var1375 + (var777 * var954);
  var1375 = var1375 + (var778 * var958);
  var795 = var1375;
  vamp::FloatVector<8, 1> var1377;
  var1377 = var1377 + (var776 * 1.0f);
  var796 = var1377;
  vamp::FloatVector<8, 1> var1379;
  var1379 = var1379 + (var776 * 0.115974999964237f);
  var1379 = var1379 + (var779 * 1.0f);
  var797 = var1379;
  vamp::FloatVector<8, 1> var1381;
  var1381 = var1381 + (var781 * var953);
  var1381 = var1381 + (var782 * var957);
  var798 = var1381;
  vamp::FloatVector<8, 1> var1383;
  var1383 = var1383 + (var781 * var954);
  var1383 = var1383 + (var782 * var958);
  var799 = var1383;
  vamp::FloatVector<8, 1> var1385;
  var1385 = var1385 + (var780 * 1.0f);
  var800 = var1385;
  vamp::FloatVector<8, 1> var1387;
  var1387 = var1387 + (var780 * 0.115974999964237f);
  var1387 = var1387 + (var783 * 1.0f);
  var801 = var1387;
  vamp::FloatVector<8, 1> var1389;
  var1389 = var1389 + (var785 * var953);
  var1389 = var1389 + (var786 * var957);
  var802 = var1389;
  vamp::FloatVector<8, 1> var1391;
  var1391 = var1391 + (var785 * var954);
  var1391 = var1391 + (var786 * var958);
  var803 = var1391;
  vamp::FloatVector<8, 1> var1393;
  var1393 = var1393 + (var784 * 1.0f);
  var804 = var1393;
  vamp::FloatVector<8, 1> var1395;
  var1395 = var1395 + (var784 * 0.115974999964237f);
  var1395 = var1395 + (var787 * 1.0f);
  var805 = var1395;
  var812[24ll] = ((var794 * 0.0f) + (var795 * 0.0f)) + (var796 * -0.0149999996647239f);
  var813[24ll] = ((var798 * 0.0f) + (var799 * 0.0f)) + (var800 * -0.0149999996647239f);
  var814[24ll] = ((var802 * 0.0f) + (var803 * 0.0f)) + (var804 * -0.0149999996647239f);
  var812[24ll] = var812[24ll] + var797;
  var813[24ll] = var813[24ll] + var801;
  var814[24ll] = var814[24ll] + var805;
  var815[24ll] = 0.104999996721745f;
  var816[24ll] = 2ll;
  var841[0ll] = ((var794 * 0.0f) + (var795 * 0.0f)) + (var796 * 0.0199999995529652f);
  var874[0ll] = ((var798 * 0.0f) + (var799 * 0.0f)) + (var800 * 0.0199999995529652f);
  var907[0ll] = ((var802 * 0.0f) + (var803 * 0.0f)) + (var804 * 0.0199999995529652f);
  var841[0ll] = var841[0ll] + var797;
  var874[0ll] = var874[0ll] + var801;
  var907[0ll] = var907[0ll] + var805;
  var940[0ll] = 0.0700000002980232f;
  var841[1ll] = ((var794 * 0.0f) + (var795 * 0.0f)) + (var796 * -0.0399999991059303f);
  var874[1ll] = ((var798 * 0.0f) + (var799 * 0.0f)) + (var800 * -0.0399999991059303f);
  var907[1ll] = ((var802 * 0.0f) + (var803 * 0.0f)) + (var804 * -0.0399999991059303f);
  var841[1ll] = var841[1ll] + var797;
  var874[1ll] = var874[1ll] + var801;
  var907[1ll] = var907[1ll] + var805;
  var940[1ll] = 0.0799999982118607f;
  int var1397;
  var1397 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 0,24 : torso_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 1,24 : head_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 2,24 : left_upper_shoulder_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 3,24 : left_lower_shoulder_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 4,24 : left_upper_elbow_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 5,24 : left_lower_elbow_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 6,24 : left_upper_forearm_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 7,24 : left_lower_forearm_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 8,24 : left_wrist_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 9,24 : left_hand_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 10,24 : left_gripper_base_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 11,24 : l_gripper_l_finger_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 12,24 : l_gripper_l_finger_2_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 13,24 : l_gripper_l_finger_tip_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 14,24 : l_gripper_r_finger_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 15,24 : l_gripper_r_finger_2_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 16,24 : l_gripper_r_finger_tip_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 17,24 : pedestal_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 18,24 : right_upper_shoulder_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 19,24 : right_lower_shoulder_0,right_wrist_0
  var1397 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1397)
    return 0; //collision pair: 20,24 : right_upper_elbow_0,right_wrist_0
  var1397 = ctup_runtime::link_vs_environment_collision(var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940, arg4);
  if (var1397)
    return 0;
  var812[25ll] = ((var794 * 0.00999999977648258f) + (var795 * 0.0f)) + (var796 * 0.0935499966144562f);
  var813[25ll] = ((var798 * 0.00999999977648258f) + (var799 * 0.0f)) + (var800 * 0.0935499966144562f);
  var814[25ll] = ((var802 * 0.00999999977648258f) + (var803 * 0.0f)) + (var804 * 0.0935499966144562f);
  var812[25ll] = var812[25ll] + var797;
  var813[25ll] = var813[25ll] + var801;
  var814[25ll] = var814[25ll] + var805;
  var815[25ll] = 0.0500000007450581f;
  var816[25ll] = 1ll;
  var842[0ll] = ((var794 * 0.00999999977648258f) + (var795 * 0.0f)) + (var796 * 0.0935499966144562f);
  var875[0ll] = ((var798 * 0.00999999977648258f) + (var799 * 0.0f)) + (var800 * 0.0935499966144562f);
  var908[0ll] = ((var802 * 0.00999999977648258f) + (var803 * 0.0f)) + (var804 * 0.0935499966144562f);
  var842[0ll] = var842[0ll] + var797;
  var875[0ll] = var875[0ll] + var801;
  var908[0ll] = var908[0ll] + var805;
  var941[0ll] = 0.0500000007450581f;
  int var1398;
  var1398 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 0,25 : torso_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 1,25 : head_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 2,25 : left_upper_shoulder_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 3,25 : left_lower_shoulder_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 4,25 : left_upper_elbow_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 5,25 : left_lower_elbow_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 6,25 : left_upper_forearm_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 7,25 : left_lower_forearm_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 8,25 : left_wrist_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 9,25 : left_hand_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 10,25 : left_gripper_base_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 11,25 : l_gripper_l_finger_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 12,25 : l_gripper_l_finger_2_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 13,25 : l_gripper_l_finger_tip_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 14,25 : l_gripper_r_finger_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 15,25 : l_gripper_r_finger_2_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 16,25 : l_gripper_r_finger_tip_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 17,25 : pedestal_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 18,25 : right_upper_shoulder_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 19,25 : right_lower_shoulder_0,right_hand_0
  var1398 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1398)
    return 0; //collision pair: 20,25 : right_upper_elbow_0,right_hand_0
  var1398 = ctup_runtime::link_vs_environment_collision(var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941, arg4);
  if (var1398)
    return 0;
  var812[26ll] = ((var794 * 0.0f) + (var795 * 0.0f)) + (var796 * 0.138549998402596f);
  var813[26ll] = ((var798 * 0.0f) + (var799 * 0.0f)) + (var800 * 0.138549998402596f);
  var814[26ll] = ((var802 * 0.0f) + (var803 * 0.0f)) + (var804 * 0.138549998402596f);
  var812[26ll] = var812[26ll] + var797;
  var813[26ll] = var813[26ll] + var801;
  var814[26ll] = var814[26ll] + var805;
  var815[26ll] = 0.0599999986588955f;
  var816[26ll] = 2ll;
  var843[0ll] = ((var794 * 0.0f) + (var795 * 0.0199999995529652f)) + (var796 * 0.138549998402596f);
  var876[0ll] = ((var798 * 0.0f) + (var799 * 0.0199999995529652f)) + (var800 * 0.138549998402596f);
  var909[0ll] = ((var802 * 0.0f) + (var803 * 0.0199999995529652f)) + (var804 * 0.138549998402596f);
  var843[0ll] = var843[0ll] + var797;
  var876[0ll] = var876[0ll] + var801;
  var909[0ll] = var909[0ll] + var805;
  var942[0ll] = 0.0399999991059303f;
  var843[1ll] = ((var794 * 0.0f) + (var795 * -0.0199999995529652f)) + (var796 * 0.138549998402596f);
  var876[1ll] = ((var798 * 0.0f) + (var799 * -0.0199999995529652f)) + (var800 * 0.138549998402596f);
  var909[1ll] = ((var802 * 0.0f) + (var803 * -0.0199999995529652f)) + (var804 * 0.138549998402596f);
  var843[1ll] = var843[1ll] + var797;
  var876[1ll] = var876[1ll] + var801;
  var909[1ll] = var909[1ll] + var805;
  var942[1ll] = 0.0399999991059303f;
  int var1399;
  var1399 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 0,26 : torso_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 1,26 : head_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 2,26 : left_upper_shoulder_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 3,26 : left_lower_shoulder_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 4,26 : left_upper_elbow_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 5,26 : left_lower_elbow_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 6,26 : left_upper_forearm_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 7,26 : left_lower_forearm_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 8,26 : left_wrist_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 9,26 : left_hand_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 10,26 : left_gripper_base_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 11,26 : l_gripper_l_finger_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 12,26 : l_gripper_l_finger_2_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 13,26 : l_gripper_l_finger_tip_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 14,26 : l_gripper_r_finger_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 15,26 : l_gripper_r_finger_2_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 16,26 : l_gripper_r_finger_tip_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 17,26 : pedestal_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 18,26 : right_upper_shoulder_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 19,26 : right_lower_shoulder_0,right_gripper_base_0
  var1399 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1399)
    return 0; //collision pair: 20,26 : right_upper_elbow_0,right_gripper_base_0
  var1399 = ctup_runtime::link_vs_environment_collision(var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942, arg4);
  if (var1399)
    return 0;
  var812[27ll] = ((var794 * -0.00499999988824129f) + (var795 * 0.0693330019712448f)) + (var796 * 0.166549995541573f);
  var813[27ll] = ((var798 * -0.00499999988824129f) + (var799 * 0.0693330019712448f)) + (var800 * 0.166549995541573f);
  var814[27ll] = ((var802 * -0.00499999988824129f) + (var803 * 0.0693330019712448f)) + (var804 * 0.166549995541573f);
  var812[27ll] = var812[27ll] + var797;
  var813[27ll] = var813[27ll] + var801;
  var814[27ll] = var814[27ll] + var805;
  var815[27ll] = 0.0270000007003546f;
  var816[27ll] = 2ll;
  var844[0ll] = ((var794 * -0.00499999988824129f) + (var795 * 0.0813329964876175f)) + (var796 * 0.166549995541573f);
  var877[0ll] = ((var798 * -0.00499999988824129f) + (var799 * 0.0813329964876175f)) + (var800 * 0.166549995541573f);
  var910[0ll] = ((var802 * -0.00499999988824129f) + (var803 * 0.0813329964876175f)) + (var804 * 0.166549995541573f);
  var844[0ll] = var844[0ll] + var797;
  var877[0ll] = var877[0ll] + var801;
  var910[0ll] = var910[0ll] + var805;
  var943[0ll] = 0.0149999996647239f;
  var844[1ll] = ((var794 * -0.00499999988824129f) + (var795 * 0.0573330000042915f)) + (var796 * 0.166549995541573f);
  var877[1ll] = ((var798 * -0.00499999988824129f) + (var799 * 0.0573330000042915f)) + (var800 * 0.166549995541573f);
  var910[1ll] = ((var802 * -0.00499999988824129f) + (var803 * 0.0573330000042915f)) + (var804 * 0.166549995541573f);
  var844[1ll] = var844[1ll] + var797;
  var877[1ll] = var877[1ll] + var801;
  var910[1ll] = var910[1ll] + var805;
  var943[1ll] = 0.0149999996647239f;
  int var1400;
  var1400 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 0,27 : torso_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 2,27 : left_upper_shoulder_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 3,27 : left_lower_shoulder_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 4,27 : left_upper_elbow_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 5,27 : left_lower_elbow_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 6,27 : left_upper_forearm_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 7,27 : left_lower_forearm_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 8,27 : left_wrist_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 9,27 : left_hand_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 10,27 : left_gripper_base_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 11,27 : l_gripper_l_finger_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 12,27 : l_gripper_l_finger_2_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 13,27 : l_gripper_l_finger_tip_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 14,27 : l_gripper_r_finger_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 15,27 : l_gripper_r_finger_2_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 16,27 : l_gripper_r_finger_tip_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 17,27 : pedestal_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 18,27 : right_upper_shoulder_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 19,27 : right_lower_shoulder_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1400)
    return 0; //collision pair: 20,27 : right_upper_elbow_0,r_gripper_l_finger_0
  var1400 = ctup_runtime::link_vs_environment_collision(var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943, arg4);
  if (var1400)
    return 0;
  var812[28ll] = ((var794 * 0.0f) + (var795 * 0.0863329991698265f)) + (var796 * 0.208550006151199f);
  var813[28ll] = ((var798 * 0.0f) + (var799 * 0.0863329991698265f)) + (var800 * 0.208550006151199f);
  var814[28ll] = ((var802 * 0.0f) + (var803 * 0.0863329991698265f)) + (var804 * 0.208550006151199f);
  var812[28ll] = var812[28ll] + var797;
  var813[28ll] = var813[28ll] + var801;
  var814[28ll] = var814[28ll] + var805;
  var815[28ll] = 0.0320000015199184f;
  var816[28ll] = 3ll;
  var845[0ll] = ((var794 * 0.0f) + (var795 * 0.0865830034017563f)) + (var796 * 0.188549995422363f);
  var878[0ll] = ((var798 * 0.0f) + (var799 * 0.0865830034017563f)) + (var800 * 0.188549995422363f);
  var911[0ll] = ((var802 * 0.0f) + (var803 * 0.0865830034017563f)) + (var804 * 0.188549995422363f);
  var845[0ll] = var845[0ll] + var797;
  var878[0ll] = var878[0ll] + var801;
  var911[0ll] = var911[0ll] + var805;
  var944[0ll] = 0.0120000001043081f;
  var845[1ll] = ((var794 * 0.0f) + (var795 * 0.0865830034017563f)) + (var796 * 0.208550006151199f);
  var878[1ll] = ((var798 * 0.0f) + (var799 * 0.0865830034017563f)) + (var800 * 0.208550006151199f);
  var911[1ll] = ((var802 * 0.0f) + (var803 * 0.0865830034017563f)) + (var804 * 0.208550006151199f);
  var845[1ll] = var845[1ll] + var797;
  var878[1ll] = var878[1ll] + var801;
  var911[1ll] = var911[1ll] + var805;
  var944[1ll] = 0.0120000001043081f;
  var845[2ll] = ((var794 * 0.0f) + (var795 * 0.0865830034017563f)) + (var796 * 0.228550001978874f);
  var878[2ll] = ((var798 * 0.0f) + (var799 * 0.0865830034017563f)) + (var800 * 0.228550001978874f);
  var911[2ll] = ((var802 * 0.0f) + (var803 * 0.0865830034017563f)) + (var804 * 0.228550001978874f);
  var845[2ll] = var845[2ll] + var797;
  var878[2ll] = var878[2ll] + var801;
  var911[2ll] = var911[2ll] + var805;
  var944[2ll] = 0.0120000001043081f;
  int var1401;
  var1401 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 0,28 : torso_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 2,28 : left_upper_shoulder_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 3,28 : left_lower_shoulder_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 4,28 : left_upper_elbow_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 5,28 : left_lower_elbow_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 6,28 : left_upper_forearm_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 7,28 : left_lower_forearm_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 8,28 : left_wrist_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 9,28 : left_hand_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 10,28 : left_gripper_base_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 11,28 : l_gripper_l_finger_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 12,28 : l_gripper_l_finger_2_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 13,28 : l_gripper_l_finger_tip_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 14,28 : l_gripper_r_finger_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 15,28 : l_gripper_r_finger_2_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 16,28 : l_gripper_r_finger_tip_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 17,28 : pedestal_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 18,28 : right_upper_shoulder_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 19,28 : right_lower_shoulder_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1401)
    return 0; //collision pair: 20,28 : right_upper_elbow_0,r_gripper_l_finger_2_0
  var1401 = ctup_runtime::link_vs_environment_collision(var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944, arg4);
  if (var1401)
    return 0;
  var812[29ll] = ((var794 * 0.0f) + (var795 * 0.0825830027461052f)) + (var796 * 0.256249994039536f);
  var813[29ll] = ((var798 * 0.0f) + (var799 * 0.0825830027461052f)) + (var800 * 0.256249994039536f);
  var814[29ll] = ((var802 * 0.0f) + (var803 * 0.0825830027461052f)) + (var804 * 0.256249994039536f);
  var812[29ll] = var812[29ll] + var797;
  var813[29ll] = var813[29ll] + var801;
  var814[29ll] = var814[29ll] + var805;
  var815[29ll] = 0.0280000008642673f;
  var816[29ll] = 4ll;
  var846[0ll] = ((var794 * 0.00999999977648258f) + (var795 * 0.0820830017328262f)) + (var796 * 0.266250014305115f);
  var879[0ll] = ((var798 * 0.00999999977648258f) + (var799 * 0.0820830017328262f)) + (var800 * 0.266250014305115f);
  var912[0ll] = ((var802 * 0.00999999977648258f) + (var803 * 0.0820830017328262f)) + (var804 * 0.266250014305115f);
  var846[0ll] = var846[0ll] + var797;
  var879[0ll] = var879[0ll] + var801;
  var912[0ll] = var912[0ll] + var805;
  var945[0ll] = 0.0140000004321337f;
  var846[1ll] = ((var794 * -0.00999999977648258f) + (var795 * 0.0820830017328262f)) + (var796 * 0.266250014305115f);
  var879[1ll] = ((var798 * -0.00999999977648258f) + (var799 * 0.0820830017328262f)) + (var800 * 0.266250014305115f);
  var912[1ll] = ((var802 * -0.00999999977648258f) + (var803 * 0.0820830017328262f)) + (var804 * 0.266250014305115f);
  var846[1ll] = var846[1ll] + var797;
  var879[1ll] = var879[1ll] + var801;
  var912[1ll] = var912[1ll] + var805;
  var945[1ll] = 0.0140000004321337f;
  var846[2ll] = ((var794 * -0.00999999977648258f) + (var795 * 0.0820830017328262f)) + (var796 * 0.246250003576279f);
  var879[2ll] = ((var798 * -0.00999999977648258f) + (var799 * 0.0820830017328262f)) + (var800 * 0.246250003576279f);
  var912[2ll] = ((var802 * -0.00999999977648258f) + (var803 * 0.0820830017328262f)) + (var804 * 0.246250003576279f);
  var846[2ll] = var846[2ll] + var797;
  var879[2ll] = var879[2ll] + var801;
  var912[2ll] = var912[2ll] + var805;
  var945[2ll] = 0.0140000004321337f;
  var846[3ll] = ((var794 * 0.00999999977648258f) + (var795 * 0.0820830017328262f)) + (var796 * 0.246250003576279f);
  var879[3ll] = ((var798 * 0.00999999977648258f) + (var799 * 0.0820830017328262f)) + (var800 * 0.246250003576279f);
  var912[3ll] = ((var802 * 0.00999999977648258f) + (var803 * 0.0820830017328262f)) + (var804 * 0.246250003576279f);
  var846[3ll] = var846[3ll] + var797;
  var879[3ll] = var879[3ll] + var801;
  var912[3ll] = var912[3ll] + var805;
  var945[3ll] = 0.0140000004321337f;
  int var1402;
  var1402 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 0,29 : torso_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 1,29 : head_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 2,29 : left_upper_shoulder_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 3,29 : left_lower_shoulder_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 4,29 : left_upper_elbow_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 5,29 : left_lower_elbow_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 6,29 : left_upper_forearm_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 7,29 : left_lower_forearm_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 8,29 : left_wrist_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 9,29 : left_hand_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 10,29 : left_gripper_base_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 11,29 : l_gripper_l_finger_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 12,29 : l_gripper_l_finger_2_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 13,29 : l_gripper_l_finger_tip_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 14,29 : l_gripper_r_finger_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 15,29 : l_gripper_r_finger_2_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 16,29 : l_gripper_r_finger_tip_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 17,29 : pedestal_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 18,29 : right_upper_shoulder_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 19,29 : right_lower_shoulder_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 20,29 : right_upper_elbow_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 21,29 : right_lower_elbow_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 22,29 : right_upper_forearm_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::self_collision_link_vs_link(23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1402)
    return 0; //collision pair: 23,29 : right_lower_forearm_0,r_gripper_l_finger_tip_0
  var1402 = ctup_runtime::link_vs_environment_collision(var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945, arg4);
  if (var1402)
    return 0;
  var812[30ll] = ((var794 * 0.00499999988824129f) + (var795 * -0.0693330019712448f)) + (var796 * 0.166549995541573f);
  var813[30ll] = ((var798 * 0.00499999988824129f) + (var799 * -0.0693330019712448f)) + (var800 * 0.166549995541573f);
  var814[30ll] = ((var802 * 0.00499999988824129f) + (var803 * -0.0693330019712448f)) + (var804 * 0.166549995541573f);
  var812[30ll] = var812[30ll] + var797;
  var813[30ll] = var813[30ll] + var801;
  var814[30ll] = var814[30ll] + var805;
  var815[30ll] = 0.025000000372529f;
  var816[30ll] = 2ll;
  var847[0ll] = ((var794 * 0.00499999988824129f) + (var795 * -0.0593330003321171f)) + (var796 * 0.166549995541573f);
  var880[0ll] = ((var798 * 0.00499999988824129f) + (var799 * -0.0593330003321171f)) + (var800 * 0.166549995541573f);
  var913[0ll] = ((var802 * 0.00499999988824129f) + (var803 * -0.0593330003321171f)) + (var804 * 0.166549995541573f);
  var847[0ll] = var847[0ll] + var797;
  var880[0ll] = var880[0ll] + var801;
  var913[0ll] = var913[0ll] + var805;
  var946[0ll] = 0.0149999996647239f;
  var847[1ll] = ((var794 * 0.00499999988824129f) + (var795 * -0.0793329998850822f)) + (var796 * 0.166549995541573f);
  var880[1ll] = ((var798 * 0.00499999988824129f) + (var799 * -0.0793329998850822f)) + (var800 * 0.166549995541573f);
  var913[1ll] = ((var802 * 0.00499999988824129f) + (var803 * -0.0793329998850822f)) + (var804 * 0.166549995541573f);
  var847[1ll] = var847[1ll] + var797;
  var880[1ll] = var880[1ll] + var801;
  var913[1ll] = var913[1ll] + var805;
  var946[1ll] = 0.0149999996647239f;
  int var1403;
  var1403 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 0,30 : torso_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 1,30 : head_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 2,30 : left_upper_shoulder_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 3,30 : left_lower_shoulder_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 4,30 : left_upper_elbow_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 5,30 : left_lower_elbow_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 6,30 : left_upper_forearm_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 7,30 : left_lower_forearm_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 8,30 : left_wrist_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 9,30 : left_hand_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 10,30 : left_gripper_base_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 11,30 : l_gripper_l_finger_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 12,30 : l_gripper_l_finger_2_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 13,30 : l_gripper_l_finger_tip_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 14,30 : l_gripper_r_finger_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 15,30 : l_gripper_r_finger_2_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 16,30 : l_gripper_r_finger_tip_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 17,30 : pedestal_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 18,30 : right_upper_shoulder_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 19,30 : right_lower_shoulder_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1403)
    return 0; //collision pair: 20,30 : right_upper_elbow_0,r_gripper_r_finger_0
  var1403 = ctup_runtime::link_vs_environment_collision(var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946, arg4);
  if (var1403)
    return 0;
  var812[31ll] = ((var794 * 0.0f) + (var795 * -0.0863329991698265f)) + (var796 * 0.208550006151199f);
  var813[31ll] = ((var798 * 0.0f) + (var799 * -0.0863329991698265f)) + (var800 * 0.208550006151199f);
  var814[31ll] = ((var802 * 0.0f) + (var803 * -0.0863329991698265f)) + (var804 * 0.208550006151199f);
  var812[31ll] = var812[31ll] + var797;
  var813[31ll] = var813[31ll] + var801;
  var814[31ll] = var814[31ll] + var805;
  var815[31ll] = 0.0320000015199184f;
  var816[31ll] = 3ll;
  var848[0ll] = ((var794 * 0.0f) + (var795 * -0.0865830034017563f)) + (var796 * 0.188549995422363f);
  var881[0ll] = ((var798 * 0.0f) + (var799 * -0.0865830034017563f)) + (var800 * 0.188549995422363f);
  var914[0ll] = ((var802 * 0.0f) + (var803 * -0.0865830034017563f)) + (var804 * 0.188549995422363f);
  var848[0ll] = var848[0ll] + var797;
  var881[0ll] = var881[0ll] + var801;
  var914[0ll] = var914[0ll] + var805;
  var947[0ll] = 0.0120000001043081f;
  var848[1ll] = ((var794 * 0.0f) + (var795 * -0.0865830034017563f)) + (var796 * 0.208550006151199f);
  var881[1ll] = ((var798 * 0.0f) + (var799 * -0.0865830034017563f)) + (var800 * 0.208550006151199f);
  var914[1ll] = ((var802 * 0.0f) + (var803 * -0.0865830034017563f)) + (var804 * 0.208550006151199f);
  var848[1ll] = var848[1ll] + var797;
  var881[1ll] = var881[1ll] + var801;
  var914[1ll] = var914[1ll] + var805;
  var947[1ll] = 0.0120000001043081f;
  var848[2ll] = ((var794 * 0.0f) + (var795 * -0.0865830034017563f)) + (var796 * 0.228550001978874f);
  var881[2ll] = ((var798 * 0.0f) + (var799 * -0.0865830034017563f)) + (var800 * 0.228550001978874f);
  var914[2ll] = ((var802 * 0.0f) + (var803 * -0.0865830034017563f)) + (var804 * 0.228550001978874f);
  var848[2ll] = var848[2ll] + var797;
  var881[2ll] = var881[2ll] + var801;
  var914[2ll] = var914[2ll] + var805;
  var947[2ll] = 0.0120000001043081f;
  int var1404;
  var1404 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 0,31 : torso_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 1,31 : head_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 2,31 : left_upper_shoulder_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 3,31 : left_lower_shoulder_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 4,31 : left_upper_elbow_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 5,31 : left_lower_elbow_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 6,31 : left_upper_forearm_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 7,31 : left_lower_forearm_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 8,31 : left_wrist_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 9,31 : left_hand_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 10,31 : left_gripper_base_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 11,31 : l_gripper_l_finger_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 12,31 : l_gripper_l_finger_2_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 13,31 : l_gripper_l_finger_tip_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 14,31 : l_gripper_r_finger_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 15,31 : l_gripper_r_finger_2_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 16,31 : l_gripper_r_finger_tip_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 17,31 : pedestal_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 18,31 : right_upper_shoulder_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 19,31 : right_lower_shoulder_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1404)
    return 0; //collision pair: 20,31 : right_upper_elbow_0,r_gripper_r_finger_2_0
  var1404 = ctup_runtime::link_vs_environment_collision(var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947, arg4);
  if (var1404)
    return 0;
  var812[32ll] = ((var794 * 0.0f) + (var795 * -0.0825830027461052f)) + (var796 * 0.256249994039536f);
  var813[32ll] = ((var798 * 0.0f) + (var799 * -0.0825830027461052f)) + (var800 * 0.256249994039536f);
  var814[32ll] = ((var802 * 0.0f) + (var803 * -0.0825830027461052f)) + (var804 * 0.256249994039536f);
  var812[32ll] = var812[32ll] + var797;
  var813[32ll] = var813[32ll] + var801;
  var814[32ll] = var814[32ll] + var805;
  var815[32ll] = 0.0280000008642673f;
  var816[32ll] = 4ll;
  var849[0ll] = ((var794 * 0.00999999977648258f) + (var795 * -0.0820830017328262f)) + (var796 * 0.266250014305115f);
  var882[0ll] = ((var798 * 0.00999999977648258f) + (var799 * -0.0820830017328262f)) + (var800 * 0.266250014305115f);
  var915[0ll] = ((var802 * 0.00999999977648258f) + (var803 * -0.0820830017328262f)) + (var804 * 0.266250014305115f);
  var849[0ll] = var849[0ll] + var797;
  var882[0ll] = var882[0ll] + var801;
  var915[0ll] = var915[0ll] + var805;
  var948[0ll] = 0.0140000004321337f;
  var849[1ll] = ((var794 * -0.00999999977648258f) + (var795 * -0.0820830017328262f)) + (var796 * 0.266250014305115f);
  var882[1ll] = ((var798 * -0.00999999977648258f) + (var799 * -0.0820830017328262f)) + (var800 * 0.266250014305115f);
  var915[1ll] = ((var802 * -0.00999999977648258f) + (var803 * -0.0820830017328262f)) + (var804 * 0.266250014305115f);
  var849[1ll] = var849[1ll] + var797;
  var882[1ll] = var882[1ll] + var801;
  var915[1ll] = var915[1ll] + var805;
  var948[1ll] = 0.0140000004321337f;
  var849[2ll] = ((var794 * -0.00999999977648258f) + (var795 * -0.0820830017328262f)) + (var796 * 0.246250003576279f);
  var882[2ll] = ((var798 * -0.00999999977648258f) + (var799 * -0.0820830017328262f)) + (var800 * 0.246250003576279f);
  var915[2ll] = ((var802 * -0.00999999977648258f) + (var803 * -0.0820830017328262f)) + (var804 * 0.246250003576279f);
  var849[2ll] = var849[2ll] + var797;
  var882[2ll] = var882[2ll] + var801;
  var915[2ll] = var915[2ll] + var805;
  var948[2ll] = 0.0140000004321337f;
  var849[3ll] = ((var794 * 0.00999999977648258f) + (var795 * -0.0820830017328262f)) + (var796 * 0.246250003576279f);
  var882[3ll] = ((var798 * 0.00999999977648258f) + (var799 * -0.0820830017328262f)) + (var800 * 0.246250003576279f);
  var915[3ll] = ((var802 * 0.00999999977648258f) + (var803 * -0.0820830017328262f)) + (var804 * 0.246250003576279f);
  var849[3ll] = var849[3ll] + var797;
  var882[3ll] = var882[3ll] + var801;
  var915[3ll] = var915[3ll] + var805;
  var948[3ll] = 0.0140000004321337f;
  int var1405;
  var1405 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 0,32 : torso_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 1,32 : head_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 2,32 : left_upper_shoulder_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 3,32 : left_lower_shoulder_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 4,32 : left_upper_elbow_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 5,32 : left_lower_elbow_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 6,32 : left_upper_forearm_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 7,32 : left_lower_forearm_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 8,32 : left_wrist_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 9,32 : left_hand_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 10,32 : left_gripper_base_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 11,32 : l_gripper_l_finger_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 12,32 : l_gripper_l_finger_2_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 13,32 : l_gripper_l_finger_tip_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 14,32 : l_gripper_r_finger_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 15,32 : l_gripper_r_finger_2_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 16,32 : l_gripper_r_finger_tip_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 17,32 : pedestal_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 18,32 : right_upper_shoulder_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 19,32 : right_lower_shoulder_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 20,32 : right_upper_elbow_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 21,32 : right_lower_elbow_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 22,32 : right_upper_forearm_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::self_collision_link_vs_link(23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1405)
    return 0; //collision pair: 23,32 : right_lower_forearm_0,r_gripper_r_finger_tip_0
  var1405 = ctup_runtime::link_vs_environment_collision(var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948, arg4);
  if (var1405)
    return 0;
  return 1;
}

}
