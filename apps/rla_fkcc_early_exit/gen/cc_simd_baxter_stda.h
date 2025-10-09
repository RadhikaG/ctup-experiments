// clang-format off
#include <vamp/vector.hh>

#include "ctup/typedefs.h"

#include "rla_fkcc_early_exit/runtime/typedefs.h"

#include "rla_fkcc_early_exit/runtime/vamp_collision_stda.h"

namespace ctup_gen {

template <size_t rake>
static int fkcc_franken (vamp::collision::Environment<vamp::FloatVector<rake>> const& arg4, vamp::FloatVector<rake, 14> const& arg5) {
  vamp::FloatVector<rake> var290;
  vamp::FloatVector<rake> var291;
  vamp::FloatVector<rake> var294;
  vamp::FloatVector<rake> var295;
  vamp::FloatVector<rake> var306;
  vamp::FloatVector<rake> var307;
  vamp::FloatVector<rake> var308;
  vamp::FloatVector<rake> var309;
  vamp::FloatVector<rake> var312;
  vamp::FloatVector<rake> var313;
  vamp::FloatVector<rake> var324;
  vamp::FloatVector<rake> var325;
  vamp::FloatVector<rake> var326;
  vamp::FloatVector<rake> var327;
  vamp::FloatVector<rake> var330;
  vamp::FloatVector<rake> var331;
  vamp::FloatVector<rake> var342;
  vamp::FloatVector<rake> var343;
  vamp::FloatVector<rake> var344;
  vamp::FloatVector<rake> var345;
  vamp::FloatVector<rake> var348;
  vamp::FloatVector<rake> var349;
  vamp::FloatVector<rake> var360;
  vamp::FloatVector<rake> var361;
  vamp::FloatVector<rake> var362;
  vamp::FloatVector<rake> var363;
  vamp::FloatVector<rake> var366;
  vamp::FloatVector<rake> var367;
  vamp::FloatVector<rake> var378;
  vamp::FloatVector<rake> var379;
  vamp::FloatVector<rake> var380;
  vamp::FloatVector<rake> var381;
  vamp::FloatVector<rake> var384;
  vamp::FloatVector<rake> var385;
  vamp::FloatVector<rake> var396;
  vamp::FloatVector<rake> var397;
  vamp::FloatVector<rake> var398;
  vamp::FloatVector<rake> var399;
  vamp::FloatVector<rake> var402;
  vamp::FloatVector<rake> var403;
  vamp::FloatVector<rake> var414;
  vamp::FloatVector<rake> var415;
  vamp::FloatVector<rake> var416;
  vamp::FloatVector<rake> var417;
  vamp::FloatVector<rake> var420;
  vamp::FloatVector<rake> var421;
  vamp::FloatVector<rake> var432;
  vamp::FloatVector<rake> var433;
  vamp::FloatVector<rake> var434;
  vamp::FloatVector<rake> var435;
  vamp::FloatVector<rake> var438;
  vamp::FloatVector<rake> var439;
  vamp::FloatVector<rake> var450;
  vamp::FloatVector<rake> var451;
  vamp::FloatVector<rake> var452;
  vamp::FloatVector<rake> var453;
  vamp::FloatVector<rake> var456;
  vamp::FloatVector<rake> var457;
  vamp::FloatVector<rake> var468;
  vamp::FloatVector<rake> var469;
  vamp::FloatVector<rake> var470;
  vamp::FloatVector<rake> var471;
  vamp::FloatVector<rake> var474;
  vamp::FloatVector<rake> var475;
  vamp::FloatVector<rake> var486;
  vamp::FloatVector<rake> var487;
  vamp::FloatVector<rake> var488;
  vamp::FloatVector<rake> var489;
  vamp::FloatVector<rake> var492;
  vamp::FloatVector<rake> var493;
  vamp::FloatVector<rake> var504;
  vamp::FloatVector<rake> var505;
  vamp::FloatVector<rake> var506;
  vamp::FloatVector<rake> var507;
  vamp::FloatVector<rake> var510;
  vamp::FloatVector<rake> var511;
  vamp::FloatVector<rake> var522;
  vamp::FloatVector<rake> var523;
  vamp::FloatVector<rake> var524;
  vamp::FloatVector<rake> var525;
  vamp::FloatVector<rake> var528;
  vamp::FloatVector<rake> var529;
  vamp::FloatVector<rake> var540;
  vamp::FloatVector<rake> var541;
  vamp::FloatVector<rake> var560;
  vamp::FloatVector<rake> var561;
  vamp::FloatVector<rake> var564;
  vamp::FloatVector<rake> var565;
  vamp::FloatVector<rake> var578;
  vamp::FloatVector<rake> var579;
  vamp::FloatVector<rake> var580;
  vamp::FloatVector<rake> var581;
  vamp::FloatVector<rake> var582;
  vamp::FloatVector<rake> var583;
  vamp::FloatVector<rake> var584;
  vamp::FloatVector<rake> var585;
  vamp::FloatVector<rake> var586;
  vamp::FloatVector<rake> var587;
  vamp::FloatVector<rake> var596;
  vamp::FloatVector<rake> var597;
  vamp::FloatVector<rake> var598;
  vamp::FloatVector<rake> var599;
  vamp::FloatVector<rake> var600;
  vamp::FloatVector<rake> var601;
  vamp::FloatVector<rake> var602;
  vamp::FloatVector<rake> var603;
  vamp::FloatVector<rake> var604;
  vamp::FloatVector<rake> var605;
  vamp::FloatVector<rake> var606;
  vamp::FloatVector<rake> var607;
  vamp::FloatVector<rake> var614;
  vamp::FloatVector<rake> var615;
  vamp::FloatVector<rake> var616;
  vamp::FloatVector<rake> var617;
  vamp::FloatVector<rake> var618;
  vamp::FloatVector<rake> var619;
  vamp::FloatVector<rake> var620;
  vamp::FloatVector<rake> var621;
  vamp::FloatVector<rake> var622;
  vamp::FloatVector<rake> var623;
  vamp::FloatVector<rake> var624;
  vamp::FloatVector<rake> var625;
  vamp::FloatVector<rake> var632;
  vamp::FloatVector<rake> var633;
  vamp::FloatVector<rake> var634;
  vamp::FloatVector<rake> var635;
  vamp::FloatVector<rake> var636;
  vamp::FloatVector<rake> var637;
  vamp::FloatVector<rake> var638;
  vamp::FloatVector<rake> var639;
  vamp::FloatVector<rake> var640;
  vamp::FloatVector<rake> var641;
  vamp::FloatVector<rake> var642;
  vamp::FloatVector<rake> var643;
  vamp::FloatVector<rake> var650;
  vamp::FloatVector<rake> var651;
  vamp::FloatVector<rake> var652;
  vamp::FloatVector<rake> var653;
  vamp::FloatVector<rake> var654;
  vamp::FloatVector<rake> var655;
  vamp::FloatVector<rake> var656;
  vamp::FloatVector<rake> var657;
  vamp::FloatVector<rake> var658;
  vamp::FloatVector<rake> var659;
  vamp::FloatVector<rake> var660;
  vamp::FloatVector<rake> var661;
  vamp::FloatVector<rake> var668;
  vamp::FloatVector<rake> var669;
  vamp::FloatVector<rake> var670;
  vamp::FloatVector<rake> var671;
  vamp::FloatVector<rake> var672;
  vamp::FloatVector<rake> var673;
  vamp::FloatVector<rake> var674;
  vamp::FloatVector<rake> var675;
  vamp::FloatVector<rake> var676;
  vamp::FloatVector<rake> var677;
  vamp::FloatVector<rake> var678;
  vamp::FloatVector<rake> var679;
  vamp::FloatVector<rake> var686;
  vamp::FloatVector<rake> var687;
  vamp::FloatVector<rake> var690;
  vamp::FloatVector<rake> var691;
  vamp::FloatVector<rake> var704;
  vamp::FloatVector<rake> var705;
  vamp::FloatVector<rake> var706;
  vamp::FloatVector<rake> var707;
  vamp::FloatVector<rake> var708;
  vamp::FloatVector<rake> var709;
  vamp::FloatVector<rake> var710;
  vamp::FloatVector<rake> var711;
  vamp::FloatVector<rake> var712;
  vamp::FloatVector<rake> var713;
  vamp::FloatVector<rake> var722;
  vamp::FloatVector<rake> var723;
  vamp::FloatVector<rake> var724;
  vamp::FloatVector<rake> var725;
  vamp::FloatVector<rake> var726;
  vamp::FloatVector<rake> var727;
  vamp::FloatVector<rake> var728;
  vamp::FloatVector<rake> var729;
  vamp::FloatVector<rake> var730;
  vamp::FloatVector<rake> var731;
  vamp::FloatVector<rake> var732;
  vamp::FloatVector<rake> var733;
  vamp::FloatVector<rake> var740;
  vamp::FloatVector<rake> var741;
  vamp::FloatVector<rake> var742;
  vamp::FloatVector<rake> var743;
  vamp::FloatVector<rake> var744;
  vamp::FloatVector<rake> var745;
  vamp::FloatVector<rake> var746;
  vamp::FloatVector<rake> var747;
  vamp::FloatVector<rake> var748;
  vamp::FloatVector<rake> var749;
  vamp::FloatVector<rake> var750;
  vamp::FloatVector<rake> var751;
  vamp::FloatVector<rake> var758;
  vamp::FloatVector<rake> var759;
  vamp::FloatVector<rake> var760;
  vamp::FloatVector<rake> var761;
  vamp::FloatVector<rake> var762;
  vamp::FloatVector<rake> var763;
  vamp::FloatVector<rake> var764;
  vamp::FloatVector<rake> var765;
  vamp::FloatVector<rake> var766;
  vamp::FloatVector<rake> var767;
  vamp::FloatVector<rake> var768;
  vamp::FloatVector<rake> var769;
  vamp::FloatVector<rake> var776;
  vamp::FloatVector<rake> var777;
  vamp::FloatVector<rake> var778;
  vamp::FloatVector<rake> var779;
  vamp::FloatVector<rake> var780;
  vamp::FloatVector<rake> var781;
  vamp::FloatVector<rake> var782;
  vamp::FloatVector<rake> var783;
  vamp::FloatVector<rake> var784;
  vamp::FloatVector<rake> var785;
  vamp::FloatVector<rake> var786;
  vamp::FloatVector<rake> var787;
  vamp::FloatVector<rake> var794;
  vamp::FloatVector<rake> var795;
  vamp::FloatVector<rake> var796;
  vamp::FloatVector<rake> var797;
  vamp::FloatVector<rake> var798;
  vamp::FloatVector<rake> var799;
  vamp::FloatVector<rake> var800;
  vamp::FloatVector<rake> var801;
  vamp::FloatVector<rake> var802;
  vamp::FloatVector<rake> var803;
  vamp::FloatVector<rake> var804;
  vamp::FloatVector<rake> var805;
  vamp::FloatVector<rake> var812[33];
  vamp::FloatVector<rake> var813[33];
  vamp::FloatVector<rake> var814[33];
  float var815[33];
  unsigned long int var816[33];
  std::array<vamp::FloatVector<rake>, 3> var817;
  std::array<vamp::FloatVector<rake>, 1> var818;
  std::array<vamp::FloatVector<rake>, 2> var819;
  std::array<vamp::FloatVector<rake>, 0> var820;
  std::array<vamp::FloatVector<rake>, 3> var821;
  std::array<vamp::FloatVector<rake>, 0> var822;
  std::array<vamp::FloatVector<rake>, 3> var823;
  std::array<vamp::FloatVector<rake>, 2> var824;
  std::array<vamp::FloatVector<rake>, 2> var825;
  std::array<vamp::FloatVector<rake>, 1> var826;
  std::array<vamp::FloatVector<rake>, 2> var827;
  std::array<vamp::FloatVector<rake>, 2> var828;
  std::array<vamp::FloatVector<rake>, 3> var829;
  std::array<vamp::FloatVector<rake>, 4> var830;
  std::array<vamp::FloatVector<rake>, 2> var831;
  std::array<vamp::FloatVector<rake>, 3> var832;
  std::array<vamp::FloatVector<rake>, 4> var833;
  std::array<vamp::FloatVector<rake>, 1> var834;
  std::array<vamp::FloatVector<rake>, 2> var835;
  std::array<vamp::FloatVector<rake>, 0> var836;
  std::array<vamp::FloatVector<rake>, 3> var837;
  std::array<vamp::FloatVector<rake>, 0> var838;
  std::array<vamp::FloatVector<rake>, 3> var839;
  std::array<vamp::FloatVector<rake>, 2> var840;
  std::array<vamp::FloatVector<rake>, 2> var841;
  std::array<vamp::FloatVector<rake>, 1> var842;
  std::array<vamp::FloatVector<rake>, 2> var843;
  std::array<vamp::FloatVector<rake>, 2> var844;
  std::array<vamp::FloatVector<rake>, 3> var845;
  std::array<vamp::FloatVector<rake>, 4> var846;
  std::array<vamp::FloatVector<rake>, 2> var847;
  std::array<vamp::FloatVector<rake>, 3> var848;
  std::array<vamp::FloatVector<rake>, 4> var849;
  std::array<vamp::FloatVector<rake>, 3> var850;
  std::array<vamp::FloatVector<rake>, 1> var851;
  std::array<vamp::FloatVector<rake>, 2> var852;
  std::array<vamp::FloatVector<rake>, 0> var853;
  std::array<vamp::FloatVector<rake>, 3> var854;
  std::array<vamp::FloatVector<rake>, 0> var855;
  std::array<vamp::FloatVector<rake>, 3> var856;
  std::array<vamp::FloatVector<rake>, 2> var857;
  std::array<vamp::FloatVector<rake>, 2> var858;
  std::array<vamp::FloatVector<rake>, 1> var859;
  std::array<vamp::FloatVector<rake>, 2> var860;
  std::array<vamp::FloatVector<rake>, 2> var861;
  std::array<vamp::FloatVector<rake>, 3> var862;
  std::array<vamp::FloatVector<rake>, 4> var863;
  std::array<vamp::FloatVector<rake>, 2> var864;
  std::array<vamp::FloatVector<rake>, 3> var865;
  std::array<vamp::FloatVector<rake>, 4> var866;
  std::array<vamp::FloatVector<rake>, 1> var867;
  std::array<vamp::FloatVector<rake>, 2> var868;
  std::array<vamp::FloatVector<rake>, 0> var869;
  std::array<vamp::FloatVector<rake>, 3> var870;
  std::array<vamp::FloatVector<rake>, 0> var871;
  std::array<vamp::FloatVector<rake>, 3> var872;
  std::array<vamp::FloatVector<rake>, 2> var873;
  std::array<vamp::FloatVector<rake>, 2> var874;
  std::array<vamp::FloatVector<rake>, 1> var875;
  std::array<vamp::FloatVector<rake>, 2> var876;
  std::array<vamp::FloatVector<rake>, 2> var877;
  std::array<vamp::FloatVector<rake>, 3> var878;
  std::array<vamp::FloatVector<rake>, 4> var879;
  std::array<vamp::FloatVector<rake>, 2> var880;
  std::array<vamp::FloatVector<rake>, 3> var881;
  std::array<vamp::FloatVector<rake>, 4> var882;
  std::array<vamp::FloatVector<rake>, 3> var883;
  std::array<vamp::FloatVector<rake>, 1> var884;
  std::array<vamp::FloatVector<rake>, 2> var885;
  std::array<vamp::FloatVector<rake>, 0> var886;
  std::array<vamp::FloatVector<rake>, 3> var887;
  std::array<vamp::FloatVector<rake>, 0> var888;
  std::array<vamp::FloatVector<rake>, 3> var889;
  std::array<vamp::FloatVector<rake>, 2> var890;
  std::array<vamp::FloatVector<rake>, 2> var891;
  std::array<vamp::FloatVector<rake>, 1> var892;
  std::array<vamp::FloatVector<rake>, 2> var893;
  std::array<vamp::FloatVector<rake>, 2> var894;
  std::array<vamp::FloatVector<rake>, 3> var895;
  std::array<vamp::FloatVector<rake>, 4> var896;
  std::array<vamp::FloatVector<rake>, 2> var897;
  std::array<vamp::FloatVector<rake>, 3> var898;
  std::array<vamp::FloatVector<rake>, 4> var899;
  std::array<vamp::FloatVector<rake>, 1> var900;
  std::array<vamp::FloatVector<rake>, 2> var901;
  std::array<vamp::FloatVector<rake>, 0> var902;
  std::array<vamp::FloatVector<rake>, 3> var903;
  std::array<vamp::FloatVector<rake>, 0> var904;
  std::array<vamp::FloatVector<rake>, 3> var905;
  std::array<vamp::FloatVector<rake>, 2> var906;
  std::array<vamp::FloatVector<rake>, 2> var907;
  std::array<vamp::FloatVector<rake>, 1> var908;
  std::array<vamp::FloatVector<rake>, 2> var909;
  std::array<vamp::FloatVector<rake>, 2> var910;
  std::array<vamp::FloatVector<rake>, 3> var911;
  std::array<vamp::FloatVector<rake>, 4> var912;
  std::array<vamp::FloatVector<rake>, 2> var913;
  std::array<vamp::FloatVector<rake>, 3> var914;
  std::array<vamp::FloatVector<rake>, 4> var915;
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
  vamp::FloatVector<rake> var949;
  vamp::FloatVector<rake> var950;
  vamp::FloatVector<rake> var953;
  vamp::FloatVector<rake> var954;
  vamp::FloatVector<rake> var957;
  vamp::FloatVector<rake> var958;
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
  vamp::FloatVector<rake> var970 = arg5[0ll];
  var306 = var970.sin();
  var307 = var970.cos();
  var290 = var307;
  var291 = -(var306);
  var294 = var306;
  var295 = var307;
  vamp::FloatVector<rake> var971;
  var971 = var971 + (0.707105457782745f * var290);
  var971 = var971 + (-0.707108080387115f * var294);
  var949 = var971;
  vamp::FloatVector<rake> var972;
  var972 = var972 + (0.707105457782745f * var291);
  var972 = var972 + (-0.707108080387115f * var295);
  var950 = var972;
  vamp::FloatVector<rake> var973;
  var973 = var973 + (0.707108080387115f * var290);
  var973 = var973 + (0.707105457782745f * var294);
  var953 = var973;
  vamp::FloatVector<rake> var974;
  var974 = var974 + (0.707108080387115f * var291);
  var974 = var974 + (0.707105457782745f * var295);
  var954 = var974;
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
  int var975;
  var975 = ctup_runtime::link_vs_environment_collision(var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, arg4);
  if (var975)
    return 0;
  vamp::FloatVector<rake> var976 = arg5[1ll];
  var324 = var976.sin();
  var325 = var976.cos();
  var308 = var325;
  var309 = -(var324);
  var312 = var324;
  var313 = var325;
  vamp::FloatVector<rake> var977;
  var977 = var977 + (1.0f * var308);
  var949 = var977;
  vamp::FloatVector<rake> var978;
  var978 = var978 + (1.0f * var309);
  var950 = var978;
  vamp::FloatVector<rake> var979;
  var979 = var979 + (-1.0f * var312);
  var957 = var979;
  vamp::FloatVector<rake> var980;
  var980 = var980 + (-1.0f * var313);
  var958 = var980;
  vamp::FloatVector<rake> var981;
  var981 = var981 + (var560 * var949);
  var578 = var981;
  vamp::FloatVector<rake> var982;
  var982 = var982 + (var560 * var950);
  var579 = var982;
  vamp::FloatVector<rake> var983;
  var983 = var983 + (var561 * 1.0f);
  var580 = var983;
  vamp::FloatVector<rake> var984;
  var984 = var984 + (var560 * 0.0689999982714653f);
  var984 = var984 + (0.0640272423624992f * 1.0f);
  var581 = var984;
  vamp::FloatVector<rake> var985;
  var985 = var985 + (var564 * var949);
  var582 = var985;
  vamp::FloatVector<rake> var986;
  var986 = var986 + (var564 * var950);
  var583 = var986;
  vamp::FloatVector<rake> var987;
  var987 = var987 + (var565 * 1.0f);
  var584 = var987;
  vamp::FloatVector<rake> var988;
  var988 = var988 + (var564 * 0.0689999982714653f);
  var988 = var988 + (0.259027391672134f * 1.0f);
  var585 = var988;
  vamp::FloatVector<rake> var989;
  var989 = var989 + (1.0f * var957);
  var586 = var989;
  vamp::FloatVector<rake> var990;
  var990 = var990 + (1.0f * var958);
  var587 = var990;
  var812[3ll] = ((var578 * 0.0f) + (var579 * 0.0f)) + (var580 * 0.0f);
  var813[3ll] = ((var582 * 0.0f) + (var583 * 0.0f)) + (var584 * 0.0f);
  var814[3ll] = ((var586 * 0.0f) + (var587 * 0.0f)) + (0.0f * 0.0f);
  var812[3ll] = var812[3ll] + var581;
  var813[3ll] = var813[3ll] + var585;
  var814[3ll] = var814[3ll] + 0.399976015090942f;
  var815[3ll] = 0.100000001490116f;
  var816[3ll] = 0ll;
  int var991;
  var991 = ctup_runtime::link_vs_environment_collision(var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, arg4);
  if (var991)
    return 0;
  vamp::FloatVector<rake> var992 = arg5[2ll];
  var342 = var992.sin();
  var343 = var992.cos();
  var326 = var343;
  var327 = -(var342);
  var330 = var342;
  var331 = var343;
  vamp::FloatVector<rake> var993;
  var993 = var993 + (1.0f * var326);
  var953 = var993;
  vamp::FloatVector<rake> var994;
  var994 = var994 + (1.0f * var327);
  var954 = var994;
  vamp::FloatVector<rake> var995;
  var995 = var995 + (1.0f * var330);
  var957 = var995;
  vamp::FloatVector<rake> var996;
  var996 = var996 + (1.0f * var331);
  var958 = var996;
  vamp::FloatVector<rake> var997;
  var997 = var997 + (var579 * var953);
  var997 = var997 + (var580 * var957);
  var596 = var997;
  vamp::FloatVector<rake> var998;
  var998 = var998 + (var579 * var954);
  var998 = var998 + (var580 * var958);
  var597 = var998;
  vamp::FloatVector<rake> var999;
  var999 = var999 + (var578 * 1.0f);
  var598 = var999;
  vamp::FloatVector<rake> var1000;
  var1000 = var1000 + (var578 * 0.101999998092651f);
  var1000 = var1000 + (var581 * 1.0f);
  var599 = var1000;
  vamp::FloatVector<rake> var1001;
  var1001 = var1001 + (var583 * var953);
  var1001 = var1001 + (var584 * var957);
  var600 = var1001;
  vamp::FloatVector<rake> var1002;
  var1002 = var1002 + (var583 * var954);
  var1002 = var1002 + (var584 * var958);
  var601 = var1002;
  vamp::FloatVector<rake> var1003;
  var1003 = var1003 + (var582 * 1.0f);
  var602 = var1003;
  vamp::FloatVector<rake> var1004;
  var1004 = var1004 + (var582 * 0.101999998092651f);
  var1004 = var1004 + (var585 * 1.0f);
  var603 = var1004;
  vamp::FloatVector<rake> var1005;
  var1005 = var1005 + (var587 * var953);
  var604 = var1005;
  vamp::FloatVector<rake> var1006;
  var1006 = var1006 + (var587 * var954);
  var605 = var1006;
  vamp::FloatVector<rake> var1007;
  var1007 = var1007 + (var586 * 1.0f);
  var606 = var1007;
  vamp::FloatVector<rake> var1008;
  var1008 = var1008 + (var586 * 0.101999998092651f);
  var1008 = var1008 + (0.399976015090942f * 1.0f);
  var607 = var1008;
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
  int var1009;
  var1009 = ctup_runtime::link_vs_environment_collision(var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, arg4);
  if (var1009)
    return 0;
  vamp::FloatVector<rake> var1010 = arg5[3ll];
  var360 = var1010.sin();
  var361 = var1010.cos();
  var344 = var361;
  var345 = -(var360);
  var348 = var360;
  var349 = var361;
  vamp::FloatVector<rake> var1011;
  var1011 = var1011 + (1.0f * var348);
  var949 = var1011;
  vamp::FloatVector<rake> var1012;
  var1012 = var1012 + (1.0f * var349);
  var950 = var1012;
  vamp::FloatVector<rake> var1013;
  var1013 = var1013 + (1.0f * var344);
  var957 = var1013;
  vamp::FloatVector<rake> var1014;
  var1014 = var1014 + (1.0f * var345);
  var958 = var1014;
  vamp::FloatVector<rake> var1015;
  var1015 = var1015 + (var596 * var949);
  var1015 = var1015 + (var598 * var957);
  var614 = var1015;
  vamp::FloatVector<rake> var1016;
  var1016 = var1016 + (var596 * var950);
  var1016 = var1016 + (var598 * var958);
  var615 = var1016;
  vamp::FloatVector<rake> var1017;
  var1017 = var1017 + (var597 * 1.0f);
  var616 = var1017;
  vamp::FloatVector<rake> var1018;
  var1018 = var1018 + (var596 * 0.0689999982714653f);
  var1018 = var1018 + (var598 * 0.262419998645782f);
  var1018 = var1018 + (var599 * 1.0f);
  var617 = var1018;
  vamp::FloatVector<rake> var1019;
  var1019 = var1019 + (var600 * var949);
  var1019 = var1019 + (var602 * var957);
  var618 = var1019;
  vamp::FloatVector<rake> var1020;
  var1020 = var1020 + (var600 * var950);
  var1020 = var1020 + (var602 * var958);
  var619 = var1020;
  vamp::FloatVector<rake> var1021;
  var1021 = var1021 + (var601 * 1.0f);
  var620 = var1021;
  vamp::FloatVector<rake> var1022;
  var1022 = var1022 + (var600 * 0.0689999982714653f);
  var1022 = var1022 + (var602 * 0.262419998645782f);
  var1022 = var1022 + (var603 * 1.0f);
  var621 = var1022;
  vamp::FloatVector<rake> var1023;
  var1023 = var1023 + (var604 * var949);
  var1023 = var1023 + (var606 * var957);
  var622 = var1023;
  vamp::FloatVector<rake> var1024;
  var1024 = var1024 + (var604 * var950);
  var1024 = var1024 + (var606 * var958);
  var623 = var1024;
  vamp::FloatVector<rake> var1025;
  var1025 = var1025 + (var605 * 1.0f);
  var624 = var1025;
  vamp::FloatVector<rake> var1026;
  var1026 = var1026 + (var604 * 0.0689999982714653f);
  var1026 = var1026 + (var606 * 0.262419998645782f);
  var1026 = var1026 + (var607 * 1.0f);
  var625 = var1026;
  var812[5ll] = ((var614 * 0.0f) + (var615 * 0.0f)) + (var616 * 0.0f);
  var813[5ll] = ((var618 * 0.0f) + (var619 * 0.0f)) + (var620 * 0.0f);
  var814[5ll] = ((var622 * 0.0f) + (var623 * 0.0f)) + (var624 * 0.0f);
  var812[5ll] = var812[5ll] + var617;
  var813[5ll] = var813[5ll] + var621;
  var814[5ll] = var814[5ll] + var625;
  var815[5ll] = 0.100000001490116f;
  var816[5ll] = 0ll;
  int var1027;
  var1027 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921);
  if (var1027)
    return 0; //collision pair: 0,5 : torso_0,left_lower_elbow_0
  var1027 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921);
  if (var1027)
    return 0; //collision pair: 1,5 : head_0,left_lower_elbow_0
  var1027 = ctup_runtime::link_vs_environment_collision(var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, arg4);
  if (var1027)
    return 0;
  vamp::FloatVector<rake> var1028 = arg5[4ll];
  var378 = var1028.sin();
  var379 = var1028.cos();
  var362 = var379;
  var363 = -(var378);
  var366 = var378;
  var367 = var379;
  vamp::FloatVector<rake> var1029;
  var1029 = var1029 + (1.0f * var362);
  var953 = var1029;
  vamp::FloatVector<rake> var1030;
  var1030 = var1030 + (1.0f * var363);
  var954 = var1030;
  vamp::FloatVector<rake> var1031;
  var1031 = var1031 + (1.0f * var366);
  var957 = var1031;
  vamp::FloatVector<rake> var1032;
  var1032 = var1032 + (1.0f * var367);
  var958 = var1032;
  vamp::FloatVector<rake> var1033;
  var1033 = var1033 + (var615 * var953);
  var1033 = var1033 + (var616 * var957);
  var632 = var1033;
  vamp::FloatVector<rake> var1034;
  var1034 = var1034 + (var615 * var954);
  var1034 = var1034 + (var616 * var958);
  var633 = var1034;
  vamp::FloatVector<rake> var1035;
  var1035 = var1035 + (var614 * 1.0f);
  var634 = var1035;
  vamp::FloatVector<rake> var1036;
  var1036 = var1036 + (var614 * 0.103589996695518f);
  var1036 = var1036 + (var617 * 1.0f);
  var635 = var1036;
  vamp::FloatVector<rake> var1037;
  var1037 = var1037 + (var619 * var953);
  var1037 = var1037 + (var620 * var957);
  var636 = var1037;
  vamp::FloatVector<rake> var1038;
  var1038 = var1038 + (var619 * var954);
  var1038 = var1038 + (var620 * var958);
  var637 = var1038;
  vamp::FloatVector<rake> var1039;
  var1039 = var1039 + (var618 * 1.0f);
  var638 = var1039;
  vamp::FloatVector<rake> var1040;
  var1040 = var1040 + (var618 * 0.103589996695518f);
  var1040 = var1040 + (var621 * 1.0f);
  var639 = var1040;
  vamp::FloatVector<rake> var1041;
  var1041 = var1041 + (var623 * var953);
  var1041 = var1041 + (var624 * var957);
  var640 = var1041;
  vamp::FloatVector<rake> var1042;
  var1042 = var1042 + (var623 * var954);
  var1042 = var1042 + (var624 * var958);
  var641 = var1042;
  vamp::FloatVector<rake> var1043;
  var1043 = var1043 + (var622 * 1.0f);
  var642 = var1043;
  vamp::FloatVector<rake> var1044;
  var1044 = var1044 + (var622 * 0.103589996695518f);
  var1044 = var1044 + (var625 * 1.0f);
  var643 = var1044;
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
  int var1045;
  var1045 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922);
  if (var1045)
    return 0; //collision pair: 0,6 : torso_0,left_upper_forearm_0
  var1045 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922);
  if (var1045)
    return 0; //collision pair: 1,6 : head_0,left_upper_forearm_0
  var1045 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922);
  if (var1045)
    return 0; //collision pair: 2,6 : left_upper_shoulder_0,left_upper_forearm_0
  var1045 = ctup_runtime::link_vs_environment_collision(var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, arg4);
  if (var1045)
    return 0;
  vamp::FloatVector<rake> var1046 = arg5[5ll];
  var396 = var1046.sin();
  var397 = var1046.cos();
  var380 = var397;
  var381 = -(var396);
  var384 = var396;
  var385 = var397;
  vamp::FloatVector<rake> var1047;
  var1047 = var1047 + (1.0f * var384);
  var949 = var1047;
  vamp::FloatVector<rake> var1048;
  var1048 = var1048 + (1.0f * var385);
  var950 = var1048;
  vamp::FloatVector<rake> var1049;
  var1049 = var1049 + (1.0f * var380);
  var957 = var1049;
  vamp::FloatVector<rake> var1050;
  var1050 = var1050 + (1.0f * var381);
  var958 = var1050;
  vamp::FloatVector<rake> var1051;
  var1051 = var1051 + (var632 * var949);
  var1051 = var1051 + (var634 * var957);
  var650 = var1051;
  vamp::FloatVector<rake> var1052;
  var1052 = var1052 + (var632 * var950);
  var1052 = var1052 + (var634 * var958);
  var651 = var1052;
  vamp::FloatVector<rake> var1053;
  var1053 = var1053 + (var633 * 1.0f);
  var652 = var1053;
  vamp::FloatVector<rake> var1054;
  var1054 = var1054 + (var632 * 0.00999999977648258f);
  var1054 = var1054 + (var634 * 0.270700007677078f);
  var1054 = var1054 + (var635 * 1.0f);
  var653 = var1054;
  vamp::FloatVector<rake> var1055;
  var1055 = var1055 + (var636 * var949);
  var1055 = var1055 + (var638 * var957);
  var654 = var1055;
  vamp::FloatVector<rake> var1056;
  var1056 = var1056 + (var636 * var950);
  var1056 = var1056 + (var638 * var958);
  var655 = var1056;
  vamp::FloatVector<rake> var1057;
  var1057 = var1057 + (var637 * 1.0f);
  var656 = var1057;
  vamp::FloatVector<rake> var1058;
  var1058 = var1058 + (var636 * 0.00999999977648258f);
  var1058 = var1058 + (var638 * 0.270700007677078f);
  var1058 = var1058 + (var639 * 1.0f);
  var657 = var1058;
  vamp::FloatVector<rake> var1059;
  var1059 = var1059 + (var640 * var949);
  var1059 = var1059 + (var642 * var957);
  var658 = var1059;
  vamp::FloatVector<rake> var1060;
  var1060 = var1060 + (var640 * var950);
  var1060 = var1060 + (var642 * var958);
  var659 = var1060;
  vamp::FloatVector<rake> var1061;
  var1061 = var1061 + (var641 * 1.0f);
  var660 = var1061;
  vamp::FloatVector<rake> var1062;
  var1062 = var1062 + (var640 * 0.00999999977648258f);
  var1062 = var1062 + (var642 * 0.270700007677078f);
  var1062 = var1062 + (var643 * 1.0f);
  var661 = var1062;
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
  int var1063;
  var1063 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923);
  if (var1063)
    return 0; //collision pair: 0,7 : torso_0,left_lower_forearm_0
  var1063 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923);
  if (var1063)
    return 0; //collision pair: 1,7 : head_0,left_lower_forearm_0
  var1063 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923);
  if (var1063)
    return 0; //collision pair: 2,7 : left_upper_shoulder_0,left_lower_forearm_0
  var1063 = ctup_runtime::link_vs_environment_collision(var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, arg4);
  if (var1063)
    return 0;
  vamp::FloatVector<rake> var1064 = arg5[6ll];
  var414 = var1064.sin();
  var415 = var1064.cos();
  var398 = var415;
  var399 = -(var414);
  var402 = var414;
  var403 = var415;
  vamp::FloatVector<rake> var1065;
  var1065 = var1065 + (1.0f * var398);
  var953 = var1065;
  vamp::FloatVector<rake> var1066;
  var1066 = var1066 + (1.0f * var399);
  var954 = var1066;
  vamp::FloatVector<rake> var1067;
  var1067 = var1067 + (1.0f * var402);
  var957 = var1067;
  vamp::FloatVector<rake> var1068;
  var1068 = var1068 + (1.0f * var403);
  var958 = var1068;
  vamp::FloatVector<rake> var1069;
  var1069 = var1069 + (var651 * var953);
  var1069 = var1069 + (var652 * var957);
  var668 = var1069;
  vamp::FloatVector<rake> var1070;
  var1070 = var1070 + (var651 * var954);
  var1070 = var1070 + (var652 * var958);
  var669 = var1070;
  vamp::FloatVector<rake> var1071;
  var1071 = var1071 + (var650 * 1.0f);
  var670 = var1071;
  vamp::FloatVector<rake> var1072;
  var1072 = var1072 + (var650 * 0.115974999964237f);
  var1072 = var1072 + (var653 * 1.0f);
  var671 = var1072;
  vamp::FloatVector<rake> var1073;
  var1073 = var1073 + (var655 * var953);
  var1073 = var1073 + (var656 * var957);
  var672 = var1073;
  vamp::FloatVector<rake> var1074;
  var1074 = var1074 + (var655 * var954);
  var1074 = var1074 + (var656 * var958);
  var673 = var1074;
  vamp::FloatVector<rake> var1075;
  var1075 = var1075 + (var654 * 1.0f);
  var674 = var1075;
  vamp::FloatVector<rake> var1076;
  var1076 = var1076 + (var654 * 0.115974999964237f);
  var1076 = var1076 + (var657 * 1.0f);
  var675 = var1076;
  vamp::FloatVector<rake> var1077;
  var1077 = var1077 + (var659 * var953);
  var1077 = var1077 + (var660 * var957);
  var676 = var1077;
  vamp::FloatVector<rake> var1078;
  var1078 = var1078 + (var659 * var954);
  var1078 = var1078 + (var660 * var958);
  var677 = var1078;
  vamp::FloatVector<rake> var1079;
  var1079 = var1079 + (var658 * 1.0f);
  var678 = var1079;
  vamp::FloatVector<rake> var1080;
  var1080 = var1080 + (var658 * 0.115974999964237f);
  var1080 = var1080 + (var661 * 1.0f);
  var679 = var1080;
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
  int var1081;
  var1081 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924);
  if (var1081)
    return 0; //collision pair: 0,8 : torso_0,left_wrist_0
  var1081 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924);
  if (var1081)
    return 0; //collision pair: 1,8 : head_0,left_wrist_0
  var1081 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924);
  if (var1081)
    return 0; //collision pair: 2,8 : left_upper_shoulder_0,left_wrist_0
  var1081 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924);
  if (var1081)
    return 0; //collision pair: 3,8 : left_lower_shoulder_0,left_wrist_0
  var1081 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924);
  if (var1081)
    return 0; //collision pair: 4,8 : left_upper_elbow_0,left_wrist_0
  var1081 = ctup_runtime::link_vs_environment_collision(var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, arg4);
  if (var1081)
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
  int var1082;
  var1082 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925);
  if (var1082)
    return 0; //collision pair: 0,9 : torso_0,left_hand_0
  var1082 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925);
  if (var1082)
    return 0; //collision pair: 1,9 : head_0,left_hand_0
  var1082 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925);
  if (var1082)
    return 0; //collision pair: 2,9 : left_upper_shoulder_0,left_hand_0
  var1082 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925);
  if (var1082)
    return 0; //collision pair: 3,9 : left_lower_shoulder_0,left_hand_0
  var1082 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925);
  if (var1082)
    return 0; //collision pair: 4,9 : left_upper_elbow_0,left_hand_0
  var1082 = ctup_runtime::link_vs_environment_collision(var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, arg4);
  if (var1082)
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
  int var1083;
  var1083 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926);
  if (var1083)
    return 0; //collision pair: 0,10 : torso_0,left_gripper_base_0
  var1083 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926);
  if (var1083)
    return 0; //collision pair: 1,10 : head_0,left_gripper_base_0
  var1083 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926);
  if (var1083)
    return 0; //collision pair: 2,10 : left_upper_shoulder_0,left_gripper_base_0
  var1083 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926);
  if (var1083)
    return 0; //collision pair: 3,10 : left_lower_shoulder_0,left_gripper_base_0
  var1083 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926);
  if (var1083)
    return 0; //collision pair: 4,10 : left_upper_elbow_0,left_gripper_base_0
  var1083 = ctup_runtime::link_vs_environment_collision(var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, arg4);
  if (var1083)
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
  int var1084;
  var1084 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927);
  if (var1084)
    return 0; //collision pair: 0,11 : torso_0,l_gripper_l_finger_0
  var1084 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927);
  if (var1084)
    return 0; //collision pair: 2,11 : left_upper_shoulder_0,l_gripper_l_finger_0
  var1084 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927);
  if (var1084)
    return 0; //collision pair: 3,11 : left_lower_shoulder_0,l_gripper_l_finger_0
  var1084 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927);
  if (var1084)
    return 0; //collision pair: 4,11 : left_upper_elbow_0,l_gripper_l_finger_0
  var1084 = ctup_runtime::link_vs_environment_collision(var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, arg4);
  if (var1084)
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
  int var1085;
  var1085 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928);
  if (var1085)
    return 0; //collision pair: 0,12 : torso_0,l_gripper_l_finger_2_0
  var1085 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928);
  if (var1085)
    return 0; //collision pair: 2,12 : left_upper_shoulder_0,l_gripper_l_finger_2_0
  var1085 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928);
  if (var1085)
    return 0; //collision pair: 3,12 : left_lower_shoulder_0,l_gripper_l_finger_2_0
  var1085 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928);
  if (var1085)
    return 0; //collision pair: 4,12 : left_upper_elbow_0,l_gripper_l_finger_2_0
  var1085 = ctup_runtime::link_vs_environment_collision(var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, arg4);
  if (var1085)
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
  int var1086;
  var1086 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1086)
    return 0; //collision pair: 0,13 : torso_0,l_gripper_l_finger_tip_0
  var1086 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1086)
    return 0; //collision pair: 1,13 : head_0,l_gripper_l_finger_tip_0
  var1086 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1086)
    return 0; //collision pair: 2,13 : left_upper_shoulder_0,l_gripper_l_finger_tip_0
  var1086 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1086)
    return 0; //collision pair: 3,13 : left_lower_shoulder_0,l_gripper_l_finger_tip_0
  var1086 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1086)
    return 0; //collision pair: 4,13 : left_upper_elbow_0,l_gripper_l_finger_tip_0
  var1086 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1086)
    return 0; //collision pair: 5,13 : left_lower_elbow_0,l_gripper_l_finger_tip_0
  var1086 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1086)
    return 0; //collision pair: 6,13 : left_upper_forearm_0,l_gripper_l_finger_tip_0
  var1086 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929);
  if (var1086)
    return 0; //collision pair: 7,13 : left_lower_forearm_0,l_gripper_l_finger_tip_0
  var1086 = ctup_runtime::link_vs_environment_collision(var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, arg4);
  if (var1086)
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
  int var1087;
  var1087 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930);
  if (var1087)
    return 0; //collision pair: 0,14 : torso_0,l_gripper_r_finger_0
  var1087 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930);
  if (var1087)
    return 0; //collision pair: 1,14 : head_0,l_gripper_r_finger_0
  var1087 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930);
  if (var1087)
    return 0; //collision pair: 2,14 : left_upper_shoulder_0,l_gripper_r_finger_0
  var1087 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930);
  if (var1087)
    return 0; //collision pair: 3,14 : left_lower_shoulder_0,l_gripper_r_finger_0
  var1087 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930);
  if (var1087)
    return 0; //collision pair: 4,14 : left_upper_elbow_0,l_gripper_r_finger_0
  var1087 = ctup_runtime::link_vs_environment_collision(var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, arg4);
  if (var1087)
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
  int var1088;
  var1088 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931);
  if (var1088)
    return 0; //collision pair: 0,15 : torso_0,l_gripper_r_finger_2_0
  var1088 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931);
  if (var1088)
    return 0; //collision pair: 1,15 : head_0,l_gripper_r_finger_2_0
  var1088 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931);
  if (var1088)
    return 0; //collision pair: 2,15 : left_upper_shoulder_0,l_gripper_r_finger_2_0
  var1088 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931);
  if (var1088)
    return 0; //collision pair: 3,15 : left_lower_shoulder_0,l_gripper_r_finger_2_0
  var1088 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931);
  if (var1088)
    return 0; //collision pair: 4,15 : left_upper_elbow_0,l_gripper_r_finger_2_0
  var1088 = ctup_runtime::link_vs_environment_collision(var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, arg4);
  if (var1088)
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
  int var1089;
  var1089 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1089)
    return 0; //collision pair: 0,16 : torso_0,l_gripper_r_finger_tip_0
  var1089 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1089)
    return 0; //collision pair: 1,16 : head_0,l_gripper_r_finger_tip_0
  var1089 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1089)
    return 0; //collision pair: 2,16 : left_upper_shoulder_0,l_gripper_r_finger_tip_0
  var1089 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1089)
    return 0; //collision pair: 3,16 : left_lower_shoulder_0,l_gripper_r_finger_tip_0
  var1089 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1089)
    return 0; //collision pair: 4,16 : left_upper_elbow_0,l_gripper_r_finger_tip_0
  var1089 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1089)
    return 0; //collision pair: 5,16 : left_lower_elbow_0,l_gripper_r_finger_tip_0
  var1089 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1089)
    return 0; //collision pair: 6,16 : left_upper_forearm_0,l_gripper_r_finger_tip_0
  var1089 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932);
  if (var1089)
    return 0; //collision pair: 7,16 : left_lower_forearm_0,l_gripper_r_finger_tip_0
  var1089 = ctup_runtime::link_vs_environment_collision(var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, arg4);
  if (var1089)
    return 0;
  vamp::FloatVector<rake> var1090 = arg5[7ll];
  var432 = var1090.sin();
  var433 = var1090.cos();
  var416 = var433;
  var417 = -(var432);
  var420 = var432;
  var421 = var433;
  vamp::FloatVector<rake> var1091;
  var1091 = var1091 + (0.707105457782745f * var416);
  var1091 = var1091 + (0.707108080387115f * var420);
  var949 = var1091;
  vamp::FloatVector<rake> var1092;
  var1092 = var1092 + (0.707105457782745f * var417);
  var1092 = var1092 + (0.707108080387115f * var421);
  var950 = var1092;
  vamp::FloatVector<rake> var1093;
  var1093 = var1093 + (-0.707108080387115f * var416);
  var1093 = var1093 + (0.707105457782745f * var420);
  var953 = var1093;
  vamp::FloatVector<rake> var1094;
  var1094 = var1094 + (-0.707108080387115f * var417);
  var1094 = var1094 + (0.707105457782745f * var421);
  var954 = var1094;
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
  int var1095;
  var1095 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1095)
    return 0; //collision pair: 7,18 : left_lower_forearm_0,right_upper_shoulder_0
  var1095 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1095)
    return 0; //collision pair: 8,18 : left_wrist_0,right_upper_shoulder_0
  var1095 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1095)
    return 0; //collision pair: 9,18 : left_hand_0,right_upper_shoulder_0
  var1095 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1095)
    return 0; //collision pair: 10,18 : left_gripper_base_0,right_upper_shoulder_0
  var1095 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1095)
    return 0; //collision pair: 11,18 : l_gripper_l_finger_0,right_upper_shoulder_0
  var1095 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1095)
    return 0; //collision pair: 12,18 : l_gripper_l_finger_2_0,right_upper_shoulder_0
  var1095 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1095)
    return 0; //collision pair: 13,18 : l_gripper_l_finger_tip_0,right_upper_shoulder_0
  var1095 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1095)
    return 0; //collision pair: 14,18 : l_gripper_r_finger_0,right_upper_shoulder_0
  var1095 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1095)
    return 0; //collision pair: 15,18 : l_gripper_r_finger_2_0,right_upper_shoulder_0
  var1095 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934);
  if (var1095)
    return 0; //collision pair: 16,18 : l_gripper_r_finger_tip_0,right_upper_shoulder_0
  var1095 = ctup_runtime::link_vs_environment_collision(var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, arg4);
  if (var1095)
    return 0;
  vamp::FloatVector<rake> var1096 = arg5[8ll];
  var450 = var1096.sin();
  var451 = var1096.cos();
  var434 = var451;
  var435 = -(var450);
  var438 = var450;
  var439 = var451;
  vamp::FloatVector<rake> var1097;
  var1097 = var1097 + (1.0f * var434);
  var949 = var1097;
  vamp::FloatVector<rake> var1098;
  var1098 = var1098 + (1.0f * var435);
  var950 = var1098;
  vamp::FloatVector<rake> var1099;
  var1099 = var1099 + (-1.0f * var438);
  var957 = var1099;
  vamp::FloatVector<rake> var1100;
  var1100 = var1100 + (-1.0f * var439);
  var958 = var1100;
  vamp::FloatVector<rake> var1101;
  var1101 = var1101 + (var686 * var949);
  var704 = var1101;
  vamp::FloatVector<rake> var1102;
  var1102 = var1102 + (var686 * var950);
  var705 = var1102;
  vamp::FloatVector<rake> var1103;
  var1103 = var1103 + (var687 * 1.0f);
  var706 = var1103;
  vamp::FloatVector<rake> var1104;
  var1104 = var1104 + (var686 * 0.0689999982714653f);
  var1104 = var1104 + (0.0640272423624992f * 1.0f);
  var707 = var1104;
  vamp::FloatVector<rake> var1105;
  var1105 = var1105 + (var690 * var949);
  var708 = var1105;
  vamp::FloatVector<rake> var1106;
  var1106 = var1106 + (var690 * var950);
  var709 = var1106;
  vamp::FloatVector<rake> var1107;
  var1107 = var1107 + (var691 * 1.0f);
  var710 = var1107;
  vamp::FloatVector<rake> var1108;
  var1108 = var1108 + (var690 * 0.0689999982714653f);
  var1108 = var1108 + (-0.259027391672134f * 1.0f);
  var711 = var1108;
  vamp::FloatVector<rake> var1109;
  var1109 = var1109 + (1.0f * var957);
  var712 = var1109;
  vamp::FloatVector<rake> var1110;
  var1110 = var1110 + (1.0f * var958);
  var713 = var1110;
  var812[19ll] = ((var704 * 0.0f) + (var705 * 0.0f)) + (var706 * 0.0f);
  var813[19ll] = ((var708 * 0.0f) + (var709 * 0.0f)) + (var710 * 0.0f);
  var814[19ll] = ((var712 * 0.0f) + (var713 * 0.0f)) + (0.0f * 0.0f);
  var812[19ll] = var812[19ll] + var707;
  var813[19ll] = var813[19ll] + var711;
  var814[19ll] = var814[19ll] + 0.399976015090942f;
  var815[19ll] = 0.100000001490116f;
  var816[19ll] = 0ll;
  int var1111;
  var1111 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 5,19 : left_lower_elbow_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 6,19 : left_upper_forearm_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 7,19 : left_lower_forearm_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 8,19 : left_wrist_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 9,19 : left_hand_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 10,19 : left_gripper_base_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 11,19 : l_gripper_l_finger_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 12,19 : l_gripper_l_finger_2_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 13,19 : l_gripper_l_finger_tip_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 14,19 : l_gripper_r_finger_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 15,19 : l_gripper_r_finger_2_0,right_lower_shoulder_0
  var1111 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935);
  if (var1111)
    return 0; //collision pair: 16,19 : l_gripper_r_finger_tip_0,right_lower_shoulder_0
  var1111 = ctup_runtime::link_vs_environment_collision(var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, arg4);
  if (var1111)
    return 0;
  vamp::FloatVector<rake> var1112 = arg5[9ll];
  var468 = var1112.sin();
  var469 = var1112.cos();
  var452 = var469;
  var453 = -(var468);
  var456 = var468;
  var457 = var469;
  vamp::FloatVector<rake> var1113;
  var1113 = var1113 + (1.0f * var452);
  var953 = var1113;
  vamp::FloatVector<rake> var1114;
  var1114 = var1114 + (1.0f * var453);
  var954 = var1114;
  vamp::FloatVector<rake> var1115;
  var1115 = var1115 + (1.0f * var456);
  var957 = var1115;
  vamp::FloatVector<rake> var1116;
  var1116 = var1116 + (1.0f * var457);
  var958 = var1116;
  vamp::FloatVector<rake> var1117;
  var1117 = var1117 + (var705 * var953);
  var1117 = var1117 + (var706 * var957);
  var722 = var1117;
  vamp::FloatVector<rake> var1118;
  var1118 = var1118 + (var705 * var954);
  var1118 = var1118 + (var706 * var958);
  var723 = var1118;
  vamp::FloatVector<rake> var1119;
  var1119 = var1119 + (var704 * 1.0f);
  var724 = var1119;
  vamp::FloatVector<rake> var1120;
  var1120 = var1120 + (var704 * 0.101999998092651f);
  var1120 = var1120 + (var707 * 1.0f);
  var725 = var1120;
  vamp::FloatVector<rake> var1121;
  var1121 = var1121 + (var709 * var953);
  var1121 = var1121 + (var710 * var957);
  var726 = var1121;
  vamp::FloatVector<rake> var1122;
  var1122 = var1122 + (var709 * var954);
  var1122 = var1122 + (var710 * var958);
  var727 = var1122;
  vamp::FloatVector<rake> var1123;
  var1123 = var1123 + (var708 * 1.0f);
  var728 = var1123;
  vamp::FloatVector<rake> var1124;
  var1124 = var1124 + (var708 * 0.101999998092651f);
  var1124 = var1124 + (var711 * 1.0f);
  var729 = var1124;
  vamp::FloatVector<rake> var1125;
  var1125 = var1125 + (var713 * var953);
  var730 = var1125;
  vamp::FloatVector<rake> var1126;
  var1126 = var1126 + (var713 * var954);
  var731 = var1126;
  vamp::FloatVector<rake> var1127;
  var1127 = var1127 + (var712 * 1.0f);
  var732 = var1127;
  vamp::FloatVector<rake> var1128;
  var1128 = var1128 + (var712 * 0.101999998092651f);
  var1128 = var1128 + (0.399976015090942f * 1.0f);
  var733 = var1128;
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
  int var1129;
  var1129 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 5,20 : left_lower_elbow_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 6,20 : left_upper_forearm_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 7,20 : left_lower_forearm_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 8,20 : left_wrist_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 9,20 : left_hand_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 10,20 : left_gripper_base_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 11,20 : l_gripper_l_finger_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 12,20 : l_gripper_l_finger_2_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 13,20 : l_gripper_l_finger_tip_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 14,20 : l_gripper_r_finger_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 15,20 : l_gripper_r_finger_2_0,right_upper_elbow_0
  var1129 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936);
  if (var1129)
    return 0; //collision pair: 16,20 : l_gripper_r_finger_tip_0,right_upper_elbow_0
  var1129 = ctup_runtime::link_vs_environment_collision(var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, arg4);
  if (var1129)
    return 0;
  vamp::FloatVector<rake> var1130 = arg5[10ll];
  var486 = var1130.sin();
  var487 = var1130.cos();
  var470 = var487;
  var471 = -(var486);
  var474 = var486;
  var475 = var487;
  vamp::FloatVector<rake> var1131;
  var1131 = var1131 + (1.0f * var474);
  var949 = var1131;
  vamp::FloatVector<rake> var1132;
  var1132 = var1132 + (1.0f * var475);
  var950 = var1132;
  vamp::FloatVector<rake> var1133;
  var1133 = var1133 + (1.0f * var470);
  var957 = var1133;
  vamp::FloatVector<rake> var1134;
  var1134 = var1134 + (1.0f * var471);
  var958 = var1134;
  vamp::FloatVector<rake> var1135;
  var1135 = var1135 + (var722 * var949);
  var1135 = var1135 + (var724 * var957);
  var740 = var1135;
  vamp::FloatVector<rake> var1136;
  var1136 = var1136 + (var722 * var950);
  var1136 = var1136 + (var724 * var958);
  var741 = var1136;
  vamp::FloatVector<rake> var1137;
  var1137 = var1137 + (var723 * 1.0f);
  var742 = var1137;
  vamp::FloatVector<rake> var1138;
  var1138 = var1138 + (var722 * 0.0689999982714653f);
  var1138 = var1138 + (var724 * 0.262419998645782f);
  var1138 = var1138 + (var725 * 1.0f);
  var743 = var1138;
  vamp::FloatVector<rake> var1139;
  var1139 = var1139 + (var726 * var949);
  var1139 = var1139 + (var728 * var957);
  var744 = var1139;
  vamp::FloatVector<rake> var1140;
  var1140 = var1140 + (var726 * var950);
  var1140 = var1140 + (var728 * var958);
  var745 = var1140;
  vamp::FloatVector<rake> var1141;
  var1141 = var1141 + (var727 * 1.0f);
  var746 = var1141;
  vamp::FloatVector<rake> var1142;
  var1142 = var1142 + (var726 * 0.0689999982714653f);
  var1142 = var1142 + (var728 * 0.262419998645782f);
  var1142 = var1142 + (var729 * 1.0f);
  var747 = var1142;
  vamp::FloatVector<rake> var1143;
  var1143 = var1143 + (var730 * var949);
  var1143 = var1143 + (var732 * var957);
  var748 = var1143;
  vamp::FloatVector<rake> var1144;
  var1144 = var1144 + (var730 * var950);
  var1144 = var1144 + (var732 * var958);
  var749 = var1144;
  vamp::FloatVector<rake> var1145;
  var1145 = var1145 + (var731 * 1.0f);
  var750 = var1145;
  vamp::FloatVector<rake> var1146;
  var1146 = var1146 + (var730 * 0.0689999982714653f);
  var1146 = var1146 + (var732 * 0.262419998645782f);
  var1146 = var1146 + (var733 * 1.0f);
  var751 = var1146;
  var812[21ll] = ((var740 * 0.0f) + (var741 * 0.0f)) + (var742 * 0.0f);
  var813[21ll] = ((var744 * 0.0f) + (var745 * 0.0f)) + (var746 * 0.0f);
  var814[21ll] = ((var748 * 0.0f) + (var749 * 0.0f)) + (var750 * 0.0f);
  var812[21ll] = var812[21ll] + var743;
  var813[21ll] = var813[21ll] + var747;
  var814[21ll] = var814[21ll] + var751;
  var815[21ll] = 0.100000001490116f;
  var816[21ll] = 0ll;
  int var1147;
  var1147 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 0,21 : torso_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 1,21 : head_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 3,21 : left_lower_shoulder_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 4,21 : left_upper_elbow_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 5,21 : left_lower_elbow_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 6,21 : left_upper_forearm_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 7,21 : left_lower_forearm_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 8,21 : left_wrist_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 9,21 : left_hand_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 10,21 : left_gripper_base_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 11,21 : l_gripper_l_finger_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 12,21 : l_gripper_l_finger_2_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 13,21 : l_gripper_l_finger_tip_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 14,21 : l_gripper_r_finger_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 15,21 : l_gripper_r_finger_2_0,right_lower_elbow_0
  var1147 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937);
  if (var1147)
    return 0; //collision pair: 16,21 : l_gripper_r_finger_tip_0,right_lower_elbow_0
  var1147 = ctup_runtime::link_vs_environment_collision(var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937, arg4);
  if (var1147)
    return 0;
  vamp::FloatVector<rake> var1148 = arg5[11ll];
  var504 = var1148.sin();
  var505 = var1148.cos();
  var488 = var505;
  var489 = -(var504);
  var492 = var504;
  var493 = var505;
  vamp::FloatVector<rake> var1149;
  var1149 = var1149 + (1.0f * var488);
  var953 = var1149;
  vamp::FloatVector<rake> var1150;
  var1150 = var1150 + (1.0f * var489);
  var954 = var1150;
  vamp::FloatVector<rake> var1151;
  var1151 = var1151 + (1.0f * var492);
  var957 = var1151;
  vamp::FloatVector<rake> var1152;
  var1152 = var1152 + (1.0f * var493);
  var958 = var1152;
  vamp::FloatVector<rake> var1153;
  var1153 = var1153 + (var741 * var953);
  var1153 = var1153 + (var742 * var957);
  var758 = var1153;
  vamp::FloatVector<rake> var1154;
  var1154 = var1154 + (var741 * var954);
  var1154 = var1154 + (var742 * var958);
  var759 = var1154;
  vamp::FloatVector<rake> var1155;
  var1155 = var1155 + (var740 * 1.0f);
  var760 = var1155;
  vamp::FloatVector<rake> var1156;
  var1156 = var1156 + (var740 * 0.103589996695518f);
  var1156 = var1156 + (var743 * 1.0f);
  var761 = var1156;
  vamp::FloatVector<rake> var1157;
  var1157 = var1157 + (var745 * var953);
  var1157 = var1157 + (var746 * var957);
  var762 = var1157;
  vamp::FloatVector<rake> var1158;
  var1158 = var1158 + (var745 * var954);
  var1158 = var1158 + (var746 * var958);
  var763 = var1158;
  vamp::FloatVector<rake> var1159;
  var1159 = var1159 + (var744 * 1.0f);
  var764 = var1159;
  vamp::FloatVector<rake> var1160;
  var1160 = var1160 + (var744 * 0.103589996695518f);
  var1160 = var1160 + (var747 * 1.0f);
  var765 = var1160;
  vamp::FloatVector<rake> var1161;
  var1161 = var1161 + (var749 * var953);
  var1161 = var1161 + (var750 * var957);
  var766 = var1161;
  vamp::FloatVector<rake> var1162;
  var1162 = var1162 + (var749 * var954);
  var1162 = var1162 + (var750 * var958);
  var767 = var1162;
  vamp::FloatVector<rake> var1163;
  var1163 = var1163 + (var748 * 1.0f);
  var768 = var1163;
  vamp::FloatVector<rake> var1164;
  var1164 = var1164 + (var748 * 0.103589996695518f);
  var1164 = var1164 + (var751 * 1.0f);
  var769 = var1164;
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
  int var1165;
  var1165 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 0,22 : torso_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 1,22 : head_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 3,22 : left_lower_shoulder_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 4,22 : left_upper_elbow_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 5,22 : left_lower_elbow_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 6,22 : left_upper_forearm_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 7,22 : left_lower_forearm_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 8,22 : left_wrist_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 9,22 : left_hand_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 10,22 : left_gripper_base_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 11,22 : l_gripper_l_finger_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 12,22 : l_gripper_l_finger_2_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 13,22 : l_gripper_l_finger_tip_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 14,22 : l_gripper_r_finger_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 15,22 : l_gripper_r_finger_2_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 16,22 : l_gripper_r_finger_tip_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 17,22 : pedestal_0,right_upper_forearm_0
  var1165 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938);
  if (var1165)
    return 0; //collision pair: 18,22 : right_upper_shoulder_0,right_upper_forearm_0
  var1165 = ctup_runtime::link_vs_environment_collision(var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938, arg4);
  if (var1165)
    return 0;
  vamp::FloatVector<rake> var1166 = arg5[12ll];
  var522 = var1166.sin();
  var523 = var1166.cos();
  var506 = var523;
  var507 = -(var522);
  var510 = var522;
  var511 = var523;
  vamp::FloatVector<rake> var1167;
  var1167 = var1167 + (1.0f * var510);
  var949 = var1167;
  vamp::FloatVector<rake> var1168;
  var1168 = var1168 + (1.0f * var511);
  var950 = var1168;
  vamp::FloatVector<rake> var1169;
  var1169 = var1169 + (1.0f * var506);
  var957 = var1169;
  vamp::FloatVector<rake> var1170;
  var1170 = var1170 + (1.0f * var507);
  var958 = var1170;
  vamp::FloatVector<rake> var1171;
  var1171 = var1171 + (var758 * var949);
  var1171 = var1171 + (var760 * var957);
  var776 = var1171;
  vamp::FloatVector<rake> var1172;
  var1172 = var1172 + (var758 * var950);
  var1172 = var1172 + (var760 * var958);
  var777 = var1172;
  vamp::FloatVector<rake> var1173;
  var1173 = var1173 + (var759 * 1.0f);
  var778 = var1173;
  vamp::FloatVector<rake> var1174;
  var1174 = var1174 + (var758 * 0.00999999977648258f);
  var1174 = var1174 + (var760 * 0.270700007677078f);
  var1174 = var1174 + (var761 * 1.0f);
  var779 = var1174;
  vamp::FloatVector<rake> var1175;
  var1175 = var1175 + (var762 * var949);
  var1175 = var1175 + (var764 * var957);
  var780 = var1175;
  vamp::FloatVector<rake> var1176;
  var1176 = var1176 + (var762 * var950);
  var1176 = var1176 + (var764 * var958);
  var781 = var1176;
  vamp::FloatVector<rake> var1177;
  var1177 = var1177 + (var763 * 1.0f);
  var782 = var1177;
  vamp::FloatVector<rake> var1178;
  var1178 = var1178 + (var762 * 0.00999999977648258f);
  var1178 = var1178 + (var764 * 0.270700007677078f);
  var1178 = var1178 + (var765 * 1.0f);
  var783 = var1178;
  vamp::FloatVector<rake> var1179;
  var1179 = var1179 + (var766 * var949);
  var1179 = var1179 + (var768 * var957);
  var784 = var1179;
  vamp::FloatVector<rake> var1180;
  var1180 = var1180 + (var766 * var950);
  var1180 = var1180 + (var768 * var958);
  var785 = var1180;
  vamp::FloatVector<rake> var1181;
  var1181 = var1181 + (var767 * 1.0f);
  var786 = var1181;
  vamp::FloatVector<rake> var1182;
  var1182 = var1182 + (var766 * 0.00999999977648258f);
  var1182 = var1182 + (var768 * 0.270700007677078f);
  var1182 = var1182 + (var769 * 1.0f);
  var787 = var1182;
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
  int var1183;
  var1183 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 0,23 : torso_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 1,23 : head_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 2,23 : left_upper_shoulder_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 3,23 : left_lower_shoulder_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 4,23 : left_upper_elbow_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 5,23 : left_lower_elbow_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 6,23 : left_upper_forearm_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 7,23 : left_lower_forearm_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 8,23 : left_wrist_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 9,23 : left_hand_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 10,23 : left_gripper_base_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 11,23 : l_gripper_l_finger_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 12,23 : l_gripper_l_finger_2_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 13,23 : l_gripper_l_finger_tip_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 14,23 : l_gripper_r_finger_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 15,23 : l_gripper_r_finger_2_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 16,23 : l_gripper_r_finger_tip_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 17,23 : pedestal_0,right_lower_forearm_0
  var1183 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939);
  if (var1183)
    return 0; //collision pair: 18,23 : right_upper_shoulder_0,right_lower_forearm_0
  var1183 = ctup_runtime::link_vs_environment_collision(var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939, arg4);
  if (var1183)
    return 0;
  vamp::FloatVector<rake> var1184 = arg5[13ll];
  var540 = var1184.sin();
  var541 = var1184.cos();
  var524 = var541;
  var525 = -(var540);
  var528 = var540;
  var529 = var541;
  vamp::FloatVector<rake> var1185;
  var1185 = var1185 + (1.0f * var524);
  var953 = var1185;
  vamp::FloatVector<rake> var1186;
  var1186 = var1186 + (1.0f * var525);
  var954 = var1186;
  vamp::FloatVector<rake> var1187;
  var1187 = var1187 + (1.0f * var528);
  var957 = var1187;
  vamp::FloatVector<rake> var1188;
  var1188 = var1188 + (1.0f * var529);
  var958 = var1188;
  vamp::FloatVector<rake> var1189;
  var1189 = var1189 + (var777 * var953);
  var1189 = var1189 + (var778 * var957);
  var794 = var1189;
  vamp::FloatVector<rake> var1190;
  var1190 = var1190 + (var777 * var954);
  var1190 = var1190 + (var778 * var958);
  var795 = var1190;
  vamp::FloatVector<rake> var1191;
  var1191 = var1191 + (var776 * 1.0f);
  var796 = var1191;
  vamp::FloatVector<rake> var1192;
  var1192 = var1192 + (var776 * 0.115974999964237f);
  var1192 = var1192 + (var779 * 1.0f);
  var797 = var1192;
  vamp::FloatVector<rake> var1193;
  var1193 = var1193 + (var781 * var953);
  var1193 = var1193 + (var782 * var957);
  var798 = var1193;
  vamp::FloatVector<rake> var1194;
  var1194 = var1194 + (var781 * var954);
  var1194 = var1194 + (var782 * var958);
  var799 = var1194;
  vamp::FloatVector<rake> var1195;
  var1195 = var1195 + (var780 * 1.0f);
  var800 = var1195;
  vamp::FloatVector<rake> var1196;
  var1196 = var1196 + (var780 * 0.115974999964237f);
  var1196 = var1196 + (var783 * 1.0f);
  var801 = var1196;
  vamp::FloatVector<rake> var1197;
  var1197 = var1197 + (var785 * var953);
  var1197 = var1197 + (var786 * var957);
  var802 = var1197;
  vamp::FloatVector<rake> var1198;
  var1198 = var1198 + (var785 * var954);
  var1198 = var1198 + (var786 * var958);
  var803 = var1198;
  vamp::FloatVector<rake> var1199;
  var1199 = var1199 + (var784 * 1.0f);
  var804 = var1199;
  vamp::FloatVector<rake> var1200;
  var1200 = var1200 + (var784 * 0.115974999964237f);
  var1200 = var1200 + (var787 * 1.0f);
  var805 = var1200;
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
  int var1201;
  var1201 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 0,24 : torso_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 1,24 : head_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 2,24 : left_upper_shoulder_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 3,24 : left_lower_shoulder_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 4,24 : left_upper_elbow_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 5,24 : left_lower_elbow_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 6,24 : left_upper_forearm_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 7,24 : left_lower_forearm_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 8,24 : left_wrist_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 9,24 : left_hand_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 10,24 : left_gripper_base_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 11,24 : l_gripper_l_finger_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 12,24 : l_gripper_l_finger_2_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 13,24 : l_gripper_l_finger_tip_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 14,24 : l_gripper_r_finger_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 15,24 : l_gripper_r_finger_2_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 16,24 : l_gripper_r_finger_tip_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 17,24 : pedestal_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 18,24 : right_upper_shoulder_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 19,24 : right_lower_shoulder_0,right_wrist_0
  var1201 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 24ll, var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940);
  if (var1201)
    return 0; //collision pair: 20,24 : right_upper_elbow_0,right_wrist_0
  var1201 = ctup_runtime::link_vs_environment_collision(var812[24ll], var813[24ll], var814[24ll], var815[24ll], var816[24ll], var841, var874, var907, var940, arg4);
  if (var1201)
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
  int var1202;
  var1202 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 0,25 : torso_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 1,25 : head_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 2,25 : left_upper_shoulder_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 3,25 : left_lower_shoulder_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 4,25 : left_upper_elbow_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 5,25 : left_lower_elbow_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 6,25 : left_upper_forearm_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 7,25 : left_lower_forearm_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 8,25 : left_wrist_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 9,25 : left_hand_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 10,25 : left_gripper_base_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 11,25 : l_gripper_l_finger_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 12,25 : l_gripper_l_finger_2_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 13,25 : l_gripper_l_finger_tip_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 14,25 : l_gripper_r_finger_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 15,25 : l_gripper_r_finger_2_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 16,25 : l_gripper_r_finger_tip_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 17,25 : pedestal_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 18,25 : right_upper_shoulder_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 19,25 : right_lower_shoulder_0,right_hand_0
  var1202 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 25ll, var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941);
  if (var1202)
    return 0; //collision pair: 20,25 : right_upper_elbow_0,right_hand_0
  var1202 = ctup_runtime::link_vs_environment_collision(var812[25ll], var813[25ll], var814[25ll], var815[25ll], var816[25ll], var842, var875, var908, var941, arg4);
  if (var1202)
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
  int var1203;
  var1203 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 0,26 : torso_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 1,26 : head_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 2,26 : left_upper_shoulder_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 3,26 : left_lower_shoulder_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 4,26 : left_upper_elbow_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 5,26 : left_lower_elbow_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 6,26 : left_upper_forearm_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 7,26 : left_lower_forearm_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 8,26 : left_wrist_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 9,26 : left_hand_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 10,26 : left_gripper_base_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 11,26 : l_gripper_l_finger_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 12,26 : l_gripper_l_finger_2_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 13,26 : l_gripper_l_finger_tip_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 14,26 : l_gripper_r_finger_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 15,26 : l_gripper_r_finger_2_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 16,26 : l_gripper_r_finger_tip_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 17,26 : pedestal_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 18,26 : right_upper_shoulder_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 19,26 : right_lower_shoulder_0,right_gripper_base_0
  var1203 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 26ll, var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942);
  if (var1203)
    return 0; //collision pair: 20,26 : right_upper_elbow_0,right_gripper_base_0
  var1203 = ctup_runtime::link_vs_environment_collision(var812[26ll], var813[26ll], var814[26ll], var815[26ll], var816[26ll], var843, var876, var909, var942, arg4);
  if (var1203)
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
  int var1204;
  var1204 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 0,27 : torso_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 2,27 : left_upper_shoulder_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 3,27 : left_lower_shoulder_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 4,27 : left_upper_elbow_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 5,27 : left_lower_elbow_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 6,27 : left_upper_forearm_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 7,27 : left_lower_forearm_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 8,27 : left_wrist_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 9,27 : left_hand_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 10,27 : left_gripper_base_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 11,27 : l_gripper_l_finger_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 12,27 : l_gripper_l_finger_2_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 13,27 : l_gripper_l_finger_tip_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 14,27 : l_gripper_r_finger_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 15,27 : l_gripper_r_finger_2_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 16,27 : l_gripper_r_finger_tip_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 17,27 : pedestal_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 18,27 : right_upper_shoulder_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 19,27 : right_lower_shoulder_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 27ll, var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943);
  if (var1204)
    return 0; //collision pair: 20,27 : right_upper_elbow_0,r_gripper_l_finger_0
  var1204 = ctup_runtime::link_vs_environment_collision(var812[27ll], var813[27ll], var814[27ll], var815[27ll], var816[27ll], var844, var877, var910, var943, arg4);
  if (var1204)
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
  int var1205;
  var1205 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 0,28 : torso_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 2,28 : left_upper_shoulder_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 3,28 : left_lower_shoulder_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 4,28 : left_upper_elbow_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 5,28 : left_lower_elbow_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 6,28 : left_upper_forearm_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 7,28 : left_lower_forearm_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 8,28 : left_wrist_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 9,28 : left_hand_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 10,28 : left_gripper_base_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 11,28 : l_gripper_l_finger_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 12,28 : l_gripper_l_finger_2_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 13,28 : l_gripper_l_finger_tip_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 14,28 : l_gripper_r_finger_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 15,28 : l_gripper_r_finger_2_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 16,28 : l_gripper_r_finger_tip_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 17,28 : pedestal_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 18,28 : right_upper_shoulder_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 19,28 : right_lower_shoulder_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 28ll, var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944);
  if (var1205)
    return 0; //collision pair: 20,28 : right_upper_elbow_0,r_gripper_l_finger_2_0
  var1205 = ctup_runtime::link_vs_environment_collision(var812[28ll], var813[28ll], var814[28ll], var815[28ll], var816[28ll], var845, var878, var911, var944, arg4);
  if (var1205)
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
  int var1206;
  var1206 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 0,29 : torso_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 1,29 : head_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 2,29 : left_upper_shoulder_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 3,29 : left_lower_shoulder_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 4,29 : left_upper_elbow_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 5,29 : left_lower_elbow_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 6,29 : left_upper_forearm_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 7,29 : left_lower_forearm_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 8,29 : left_wrist_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 9,29 : left_hand_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 10,29 : left_gripper_base_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 11,29 : l_gripper_l_finger_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 12,29 : l_gripper_l_finger_2_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 13,29 : l_gripper_l_finger_tip_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 14,29 : l_gripper_r_finger_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 15,29 : l_gripper_r_finger_2_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 16,29 : l_gripper_r_finger_tip_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 17,29 : pedestal_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 18,29 : right_upper_shoulder_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 19,29 : right_lower_shoulder_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 20,29 : right_upper_elbow_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 21,29 : right_lower_elbow_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 22,29 : right_upper_forearm_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::self_collision_link_vs_link(23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939, 29ll, var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945);
  if (var1206)
    return 0; //collision pair: 23,29 : right_lower_forearm_0,r_gripper_l_finger_tip_0
  var1206 = ctup_runtime::link_vs_environment_collision(var812[29ll], var813[29ll], var814[29ll], var815[29ll], var816[29ll], var846, var879, var912, var945, arg4);
  if (var1206)
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
  int var1207;
  var1207 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 0,30 : torso_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 1,30 : head_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 2,30 : left_upper_shoulder_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 3,30 : left_lower_shoulder_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 4,30 : left_upper_elbow_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 5,30 : left_lower_elbow_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 6,30 : left_upper_forearm_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 7,30 : left_lower_forearm_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 8,30 : left_wrist_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 9,30 : left_hand_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 10,30 : left_gripper_base_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 11,30 : l_gripper_l_finger_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 12,30 : l_gripper_l_finger_2_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 13,30 : l_gripper_l_finger_tip_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 14,30 : l_gripper_r_finger_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 15,30 : l_gripper_r_finger_2_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 16,30 : l_gripper_r_finger_tip_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 17,30 : pedestal_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 18,30 : right_upper_shoulder_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 19,30 : right_lower_shoulder_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 30ll, var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946);
  if (var1207)
    return 0; //collision pair: 20,30 : right_upper_elbow_0,r_gripper_r_finger_0
  var1207 = ctup_runtime::link_vs_environment_collision(var812[30ll], var813[30ll], var814[30ll], var815[30ll], var816[30ll], var847, var880, var913, var946, arg4);
  if (var1207)
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
  int var1208;
  var1208 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 0,31 : torso_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 1,31 : head_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 2,31 : left_upper_shoulder_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 3,31 : left_lower_shoulder_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 4,31 : left_upper_elbow_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 5,31 : left_lower_elbow_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 6,31 : left_upper_forearm_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 7,31 : left_lower_forearm_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 8,31 : left_wrist_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 9,31 : left_hand_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 10,31 : left_gripper_base_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 11,31 : l_gripper_l_finger_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 12,31 : l_gripper_l_finger_2_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 13,31 : l_gripper_l_finger_tip_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 14,31 : l_gripper_r_finger_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 15,31 : l_gripper_r_finger_2_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 16,31 : l_gripper_r_finger_tip_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 17,31 : pedestal_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 18,31 : right_upper_shoulder_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 19,31 : right_lower_shoulder_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 31ll, var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947);
  if (var1208)
    return 0; //collision pair: 20,31 : right_upper_elbow_0,r_gripper_r_finger_2_0
  var1208 = ctup_runtime::link_vs_environment_collision(var812[31ll], var813[31ll], var814[31ll], var815[31ll], var816[31ll], var848, var881, var914, var947, arg4);
  if (var1208)
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
  int var1209;
  var1209 = ctup_runtime::self_collision_link_vs_link(0ll, var812[0ll], var813[0ll], var814[0ll], var815[0ll], var816[0ll], var817, var850, var883, var916, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 0,32 : torso_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(1ll, var812[1ll], var813[1ll], var814[1ll], var815[1ll], var816[1ll], var818, var851, var884, var917, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 1,32 : head_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(2ll, var812[2ll], var813[2ll], var814[2ll], var815[2ll], var816[2ll], var819, var852, var885, var918, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 2,32 : left_upper_shoulder_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(3ll, var812[3ll], var813[3ll], var814[3ll], var815[3ll], var816[3ll], var820, var853, var886, var919, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 3,32 : left_lower_shoulder_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(4ll, var812[4ll], var813[4ll], var814[4ll], var815[4ll], var816[4ll], var821, var854, var887, var920, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 4,32 : left_upper_elbow_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(5ll, var812[5ll], var813[5ll], var814[5ll], var815[5ll], var816[5ll], var822, var855, var888, var921, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 5,32 : left_lower_elbow_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(6ll, var812[6ll], var813[6ll], var814[6ll], var815[6ll], var816[6ll], var823, var856, var889, var922, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 6,32 : left_upper_forearm_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(7ll, var812[7ll], var813[7ll], var814[7ll], var815[7ll], var816[7ll], var824, var857, var890, var923, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 7,32 : left_lower_forearm_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(8ll, var812[8ll], var813[8ll], var814[8ll], var815[8ll], var816[8ll], var825, var858, var891, var924, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 8,32 : left_wrist_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(9ll, var812[9ll], var813[9ll], var814[9ll], var815[9ll], var816[9ll], var826, var859, var892, var925, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 9,32 : left_hand_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(10ll, var812[10ll], var813[10ll], var814[10ll], var815[10ll], var816[10ll], var827, var860, var893, var926, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 10,32 : left_gripper_base_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(11ll, var812[11ll], var813[11ll], var814[11ll], var815[11ll], var816[11ll], var828, var861, var894, var927, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 11,32 : l_gripper_l_finger_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(12ll, var812[12ll], var813[12ll], var814[12ll], var815[12ll], var816[12ll], var829, var862, var895, var928, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 12,32 : l_gripper_l_finger_2_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(13ll, var812[13ll], var813[13ll], var814[13ll], var815[13ll], var816[13ll], var830, var863, var896, var929, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 13,32 : l_gripper_l_finger_tip_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(14ll, var812[14ll], var813[14ll], var814[14ll], var815[14ll], var816[14ll], var831, var864, var897, var930, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 14,32 : l_gripper_r_finger_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(15ll, var812[15ll], var813[15ll], var814[15ll], var815[15ll], var816[15ll], var832, var865, var898, var931, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 15,32 : l_gripper_r_finger_2_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(16ll, var812[16ll], var813[16ll], var814[16ll], var815[16ll], var816[16ll], var833, var866, var899, var932, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 16,32 : l_gripper_r_finger_tip_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(17ll, var812[17ll], var813[17ll], var814[17ll], var815[17ll], var816[17ll], var834, var867, var900, var933, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 17,32 : pedestal_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(18ll, var812[18ll], var813[18ll], var814[18ll], var815[18ll], var816[18ll], var835, var868, var901, var934, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 18,32 : right_upper_shoulder_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(19ll, var812[19ll], var813[19ll], var814[19ll], var815[19ll], var816[19ll], var836, var869, var902, var935, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 19,32 : right_lower_shoulder_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(20ll, var812[20ll], var813[20ll], var814[20ll], var815[20ll], var816[20ll], var837, var870, var903, var936, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 20,32 : right_upper_elbow_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(21ll, var812[21ll], var813[21ll], var814[21ll], var815[21ll], var816[21ll], var838, var871, var904, var937, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 21,32 : right_lower_elbow_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(22ll, var812[22ll], var813[22ll], var814[22ll], var815[22ll], var816[22ll], var839, var872, var905, var938, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 22,32 : right_upper_forearm_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::self_collision_link_vs_link(23ll, var812[23ll], var813[23ll], var814[23ll], var815[23ll], var816[23ll], var840, var873, var906, var939, 32ll, var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948);
  if (var1209)
    return 0; //collision pair: 23,32 : right_lower_forearm_0,r_gripper_r_finger_tip_0
  var1209 = ctup_runtime::link_vs_environment_collision(var812[32ll], var813[32ll], var814[32ll], var815[32ll], var816[32ll], var849, var882, var915, var948, arg4);
  if (var1209)
    return 0;
  return 1;
}

}
