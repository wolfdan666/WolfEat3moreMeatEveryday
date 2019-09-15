#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define PER(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define x first
#define y second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head



#ifdef ONLINE_JUDGE
const int N = 1e6+50;
#else
const int N = 1e2+10;
#endif


const int ans[]={0,0,1,6,12,40,30,84,224,144,135,715,627,1326,1274,420,480,2720,5202,16530,3800,2590,924,16951,552,9300,68575,82134,21168,24360,165300,3720,45632,199584,2244,22015,2520,29304,77330,57798,398320,1285760,4255062,81270,41624,48510,97290,1479889,106032,11760,180075,132600,3254004,429936,1267866,38115,2293060,20948298,40667106,299425,208860,2325320,344162,7394058,7636608,82875520,8580,305118,4013836,171258,173880,11850965,70320672,1866318,14396330,4872900,17100,895356,468468,499122,252800,20509200,7012845,1391827,578676,25229190,26418340,211474989,784847184,497121123,15339150,49140,393484,1972158,821748,2924575,53598240,55872,45638306,15086610,753390000,50040450,417498852,18788230,1649648,1168440,1202040,63736369,2461428,68719050,162308630,564673856,24864,5916680,12882,83753235,89751520,869785371,124424274,827222264,916501173,142157979,2679303,3661464,39416252,40718500,31500,4096512,135201152,132178560,5399940,191928100,764103895,303683688,755446880,403450390,878166801,7620488,63013698,181404174,188003060,1490370,40044,7198477,2965248,73807320,222581380,897305600,3241644,486312756,838638473,668099857,87240552,277345965,3652110,279481895,569777520,909958004,17438618,102598248,6080160,331917600,704201656,12886128,6522608,11108130,856576600,6916639,773139192,393768648,453484704,5029110,10088316,597113652,30102,2755725,479740800,6824611,490800468,6727676,453731610,810770040,174453052,127995139,76742980,579462920,6400260,197469008,621276832,63131059,3519180,655161515,315686842,28570176,246855106,708291090,7567560,468395047,15329358,7998606,803840600,57548093,624161197,809432154,689858065,197982428,630455180,357065367,320910720,936082576,87780,963476640,74767476,379431305,9754548,380663735,10031040,156955682,25639852,20815512,5347980,198166963,886901487,225570529,242056473,501024386,533868153,603037815,920524624,245275990,718210895,212520,12540528,543375195,461026027,32361615,540843679,392427831,168324999,208713599,700359503,28225920,380401421,67909312,81646278,630637420,1293931,889031838,949548624,259817649,549967486,898626104,686911972,56583450,24419560,817851652,16842240,891525490,17040642,862442760,43568980,561311662,17984466,437032941,809577120,18959160,388056851,262408964,560202110,38713404,657023276,821728799,818922105,190585256,635328541,948130242,157183696,704797050,309867908,277830386,51523419,134870012,749747645,184738215,448245518,318027562,275886879,333883532,395070958,48524256,475894014,49114980,236370917,784569639,979573108,921821882,773970379,110038107,105145128,235499832,26910000,64267522,208632348,110356236,214584532,461333294,560051640,903997718,590609103,218012655,780213045,692419287,439786580,279209594,383153779,93074310,814843017,988535918,205584668,145543973,54218796,420841210,489026136,101531951,476789328,74482200,664404815,556029323,35179968,106293320,217140,72747180,127035152,215692694,111253064,388964221,61191507,848268878,659514248,487518216,265388569,771127213,748161940,681164077,541338475,70311036,85182422,882943718,804827001,59357303,21376250,43611750,43737408,807625711,44111586,713948361,860057995,984432333,137008032,883198273,305220824,581376307,283279826,758860975,670467540,619538990,874650824,656833322,504482780,851303417,791600048,321615528,207289111,969710687,224897578,969569932,975009846,12704182,147213128,181988425,550724752,138047730,536076394,19423120,474768550,534347422,277774654,873715625,305094536,448946783,855709629,60538530,209522824,693786590,927479183,18760111,123571800,467930686,548061617,339961478,377197825,929122116,510292238,260505648,898560496,606820688,73823363,167968493,753754165,643514715,617757502,468134774,139190904,429596203,499872283,804316856,158784988,500436898,330820304,833779290,309908865,798032191,19144628,330236216,227597688,791835097,548987726,78035958,933622580,464458901,606535622,336637759,837971159,466100351,501035131,722499131,998404247,40098260,401772714,106748090,42495200,86735880,877149,383556205,196692,263769300,896584125,250541410,706926755,322185268,663522473,595974710,915622764,342038221,55675413,585447394,719165182,809889789,569918083,97217522,72682038,663560186,103370673,909754905,634643969,791101815,701424289,688651692,481800017,873272360,331481464,944159323,607048176,450140201,307580852,633067279,507471325,680972531,932698257,847108034,329935200,841861733,931230222,86653572,298186557,317306433,382511484,941206421,998651093,269587042,223414638,901347339,381257681,299192826,716507553,865165128,88498570,843173027,268662409,919135809,671588778,222222296,816798687,794783532,382042584,329002916,363573101,606409032,111669003,820596994,868832953,599417016,293953140,806616576,764889370,63761101,853583648,276375792,65522872,998575523,883199315,676000997,149580165,348663191,678678481,255020512,485229036,109282577,448477583,149990544,76877264,304513527,150568236,655124776,151988148,534097455,270093859,221569978,619992276,544538574,150812922,389192157,202124556,637466796,904314865,928886810,154958903,986123802,493231088,174281319,670239135,620110933,863183249,934326167,819168264,7982499,709372942,504356707,254984246,388526852,40220645,796202131,485121798,860777029,845478466,228206320,616806504,373998577,548461368,270464656,47395831,356441469,376758112,144582797,511930601,460865219,191102400,759228371,706166393,656083619,483915676,233711788,334721218,366744996,256254932,939464893,820630126,744833546,727795522,280642674,886252016,350529523,205557637,252080132,562214776,526787415,474826371,467447759,426265164,903873639,814861053,652325400,373440437,687691947,369572971,323140786,69302116,43642259,660284932,778084009,340284840,31054896,788787168,688336753,145029237,985504152,789054774,962884714,395571569,233780504,168115571,494552394,67447035,202266088,798703541,395891121,135046153,403981400,159247666,143493859,798227695,55224865,357009419,454515132,150274489,178570260,210983813,498819674,361042201,426347031,720670392,170511627,29604571,941026002,196725873,117997015,558944842,993648602,775173055,482897329,216451053,588351508,69968544,839465698,267745819,497919246,707866547,515002033,457109086,791806544,756143730,501423063,621969865,65435703,1760928,294520520,295850520,171480964,75037306,746533086,735283669,993956457,761593809,576182646,29796753,307091250,750194451,127938676,113624041,684683623,559264596,910352698,632570004,922079143,700674648,107768085,12803389,315230643,69719392,684737497,713196061,500895558,489199334,118998513,154225376,601094140,605921272,635704768,226235052,487165332,520733089,660828412,510296466,70596855,87989882,814956472,989764782,509684340,105100373,56635131,878945228,75750103,889601833,805395626,1018164,550074525,591104443,507686325,106832893,121280127,252901789,754281360,55124492,539232854,378979248,37596279,871423269,46434673,303502248,831327476,682341354,984281639,518822386,209012379,373818194,280886837,200784330,835954781,952391185,708363654,854813534,31991942,892048110,573477097,726697464,481008185,838200926,184369893,235370739,451975003,442549874,346154363,664956781,751500417,766800077,612475552,603329623,900187875,480110290,124363866,359437181,75806737,428987741,280183261,255034614,138883350,744685088,284786294,118056680,857162814,86710025,111734528,902382760,671383828,390551308,330049507,268637353,432803347,734228779,52835114,1215240,794111495,169789549,974873498,2455488,7533512,434190168,275570612,631324980,694449373,796264418,520361981,566911084,141925319,310049960,259421112,389584998,465612970,741650255,15626799,817985602,955298916,373067244,749792253,519072048,709957667,352435327,307806691,103532642,931274568,55054546,508958223,334183064,784907041,514706626,765771029,654170840,327024525,265119102,997643052,198350910,662827123,380189614,818560301,792090648,648806412,565603500,370645480,697510117,191781902,714187644,68919578,775673314,802156026,327313830,981974078,353487139,356667790,612781218,123314900,720381882,234631072,725805855,662954402,249842351,851066342,815392996,425744774,876287207,974652300,945822500,514375749,436698245,389982090,638765679,953468095,254442313,374933677,546717955,718111373,785286672,40983236,854513483,869334736,706111287,760755468,477779463,106101468,555653287,467970542,448928923,244409126,132202982,45032659,183576156,723789448,331709380,646468723,7618074,634316500,507395929,739563824,358168213,307141879,906239919,383552291,603072554,927872338,992793541,106993994,959368012,239359520,958645519,97766556,731202273,524097717,897101113,696767626,119789136,506989682,454761793,260903034,924524905,436819382,460758311,350337118,742856580,632420149,647647472,119844310,736127169,625054057,951065689,523298143,55071410,495972022,948411706,661284847,543872197,327608264,717372706,816254369,365398585,849672317,892787726,91534997,561260042,200048155,615104795,893042933,398432214,686351665,720195287,512767529,354028115,730207706,758504201,989913501,338764389,727411977,595038002,181853274,396483757,432243270,485643332,877319158,140454505,745000975,611498115,395296858,292419313,191311267,853411926,446691238,580623351,397273986,740302027,954140674,368525042,496213255,99729633,819445721,223561524,791028285,725818523,391350585,1864380,471961435,460468174,110523007,188242539,601916944,869058584,154915878,373400807,566756325,525860165,283085347,96330146,735389956,947087381,931924086,914515318,998942683,972426722,825933663,917666394,34729893,639560602,6392083,997565381,357134307,688692967,810741123,779912339,146525680,451628321,76797290,548922635,837490667,170994838,423345877,129090457,818477932,59887299,921448552,696661704,376243808,23624929,593822289,7631378,669643487,457636516,966360400,169535581,221258907,804640886,946579310,759818681,502069767,488732898,189768562,874303301,139105262,74788345,342563828,814987229,518441160,486616097,264157861,781755606,220233735,293262794,47192702,744589011,502087245,644009612,698703472,933094451,437047482,973869717,353009606,311989248,891410657,574727666,112067918,586375307,881918259,178185268,777795697,383723936,833629481,705150479,74265245,146538580,8917416,364089236,603597984,669065439,56801053,340987474,491430879,167637977,795083390,514321126,628034835,73435079,331767,587868050,925257726,296025157,4583880,94548187,27129928,687485123,153476345,971505419,240975411,655010663,784968058,730969296,549515837,190402315,812520333,837233823,580225672,214692760,968382817,349551304,872030955,913289980,727860843,904421703,525699547,718377743,86469381,290404560,349078279,893847202,18047457,532613704,687247627,2426604,48290411,565094863,952919356,929554956,331258640,442063720,109848068,546344621,689175476,639256606,61256976,666659774,900152643,609635265,59764974,747453865,82276239,608996864,188466878,754517941,873055451,767056914,376133080,452677803,236489791,894446733,124367604,798555100,929966018,218211120,159167283,832017848,764662630,12452848,291468549,310525484,224341245,461404668,171786431,424308103,659875206,914488331,233375053,88095382,705038270,127859679,727692572,845393508,275751707,924561422,821163746,823207036,198946905,361117238,855245947,882535045,661613930,922227576,132563739,700201660,134187592,378134320,206304426,647483758,446869221,537761316,836501507,737942573,101462914,254976945,984195498,820249000,513006904,883675686,557168210,450052408,525873517,546387405,452391975,919501853,832568757,15771841,484526551,175134775,16034822,211327375,330263119,617274503,691022710,7120151,858681594,335637869,433252481,458555250,651254990,663858506,194778510,921937639,458334254,851969973,369221056,832965539,224982723,278741460,208135475,527091615,13727746,933648460,979217271,977908109,699347534,605275061,680006844,138207385,476420524,454337834,432857762,329129493,249917198,635207838,925775672,319266038,887064863,955698465,800487244,890273204,197837460,772046625,448568903,994270983,2202083,337825364,314855310,571777590,100930605,804271258,896561440,209505045,636202604,654077994,354744867,654916048,892346636,900874886,875082407,820397405,744408326,319524142,857109769,825251278,139189036,740415394,734723593,549082845,449981465,682193071,264849052,548097428,256591101,904105174,216886060,546346517,925358843,354864453,722718671,321846273,425509709,550501155,887998324,242630205,341203401,567799310,945919477,234461536,992565773,532984267,706692878,477501163,907735581,385409880,24084117,152826686,535828167,505728432,576019572,637926206,63597142,486048180,175547747,204747271,448146096,457727918,488912075,108205956,810889345,741657960,989265235,90709325,667608082,363714689,842189216,938344764,621625602,73955312,150044362,114626882,431495595,507500775,572205175,382879956,114216690,806893429,210570498,455186137,425417333,386398714,596827545,263703787,703382548,761557694,277792423,862325960,812639623,493319930,395541306,568546355,292602262,842784527,988275384,5275735,9710626,591395332,275741918,827299964,84102555,794676041,449558369,968205208,118854753,217545063,638934535,577554378,445509020,359426758,531701358,413836019,645845897,478408830,210980547,484616283,736453663,134784663,230072569,594470544,199456481,687245914,944400397,367422508,502407246,327525248,2409329,637838117,460451360,620429823,385772555,444059169,663166708,905797888,150216305,925211932,967581856,856604826,633524252,818608774,779154260,351933796,241245687,539079581,380121579,358363358,656464946,744407036,445509866,623576335,552371119,243859757,767639129,916565394,780997900,345270688,45337896,365937901,918769991,737716077,872053942,745882925,304107437,742913162,152591197,504005602,745963069,339027008,648158708,356979055,251658644,350267449,218396195,528325581,853128591,61960438,934101045,545726740,164051638,318390731,344462276,628428015,941306094,416249377,403965815,124891583,493241663,719780684,704028812,738481155,477766621,480078395,205758213,788722302,940576196,530403854,644491372,147765447,730407129,526483058,839247469,953647876,230174645,738401499,252016089,839168584,318135333,691236099,522885642,57852387,665872925,610449631,335587637,38225843,873941520,860129357,411876821,650600889,78154329,249283617,234331961,768939567,213615420,941385655,948215702,330205876,110301667,511776193,237458114,833816311,732543873,332144563,824338191,344405298,255873062,268201855,388755074,530063844,725604699,437231399,767499657,412006069,727898630,959761288,368963259,753594261,941168673,895390098,324029172,223503548,123695774,708347793,234357695,276680917,874921399,808351598,185838366,689388859,374465797,188032072,909068155,8103993,921653969,110434802,23592891,863079363,530641790,745174775,398849683,982492459,30669775,460755580,676159524,466381915,171201376,490088863,626115977,339492394,260661008,808962706,783494263,757057702,650205840,671600850,395289600,268699433,200749052,760092115,854974626,617918852,146480360,367958301,665443459,651958596,591996333,529141385,103042755,635875078,229543266,975622787,990059255,526296735,124207077,779086258,127431824,478615557,194940896,549034158,838633292,630929695,992660528,179905595,797408180,286079740,54997013,531739658,160399507,533581146,669649060,567027529,834300318,782811285,834852547,268762765,673491579,752621948,181327100,987648234,994705061,935860549,48395022,549649238,26096245,67139606,533925322,615363850,889938131,470733890,13002602,532459537,409148235,584397893,586072331,858764587,427977500,110641909,831590950,906744401,917704525,342763113,428849488,998462639,578275833,51671902,834310940,843525388,170077969,421311707,774941292,372210264,957332890,938318941,756823220,249986665,281293021,190083027,500167713,567291252,587178315,300549645,806113912,516253563,55634069,401950511,317126622,369911780,652840113,995547002,333897128,746359351,76209238,839552484,118141423,241283438,751474087,203444846,32164240,638177450,547414034,894616496,106931614,637581208,52040668,331409981,670064014,759726278,373057342,728961125,398421321,600741147,664406486,873395333,828186101,682634524,599791867,210650856,704668342,771258344,593207903,637940973,832297357,711254335,228743345,561644275,741275954,152879080,765704746,886538877,264033059,769721022,452249881,765404529,263878981,529906201,424675564,123370262,862734196,275732613,108121357,168897336,745259944,275432564,804959304,921962888,725908689,337253841,190937005,954433122,319125904,951881672,279216420,978112731,790310060,418123021,341506955,879497486,439639234,309283317,811120551,5175526,502449372,515256688,579419243,229419994,995589181,866246760,26610876,516875986,37065936,507816804,365834308,441987874,965406799,366042511,245802532,264579631,651328115,533437999,978270999,902688496,948335674,938252023,548615466,866583655,192236829,469532833,608959286,829987660,98460012,350364548,353524134,273438762,751361525,104696494,724719530,635381352,873474376,24492933,870561443,890772582,64841777,188736251,708591998,434240511,586686106,995174017,919069658,422661660,989767876,779664326,568742428,555571170,331095961,743189129,679638082,173723643,795843190,843437031,191954921,164546533,709767378,530779693,951738508,37529444,830757701,851230860,336572181,464724213,806214991,103681548,482107178,779781178,568834211,828359381,794619755,119224858,144284441,221489584,217832265,409643065,666067174,17805710,847806650,884710707,79469595,650370309,416226143,460498390,964744198,772525458,823037564,978423245,642109060,291791327,887427390,691797252,460317501,245566383,305470990,87733481,353487672,824102564,991301856,711556084,531020430,720557952,844714453,491631445,63851524,434703155,2435425,790404246,904657164,438661023,151033395,396172161,418835087,206614697,457074720,608773629,264116201,223275367,245993799,496965931,565076367,537794619,367113924,252100958,709127314,955740165,717448530,994033575,401632962,479531706,771835736,582097172,974725684,120159476,176935535,370842860,230417041,443706478,623894274,125138058,847667397,965552842,503036584,238729727,771366596,846308038,385665487,144000504,971774721,862963782,676308938,306748904,214162181,798645022,965147303,221783444,968638180,596118398,613689375,440199970,326609542,200407677,188180453,311644091,437387952,492429919,295268147,207642414,387827252,387204044,286727804,992211167,801906940,182465008,717529343,109496137,56346212,817066611,722093165,278338119,125519775,339560430,95097088,954781013,606165034,440895227,323946877,322883952,204899821,242128720,987880142,420098921,37923330,958225089,122221704,772855662,688733852,719240677,623219519,368476454,826744655,121794566,580055217,21017408,58334458,723669214,646117361,919270103,713591804,414167117,749255488,387744086,481431314,778935000,765824383,99751371,290751602,99100808,745302997,150845735,285271048,640059268,72688131,885179308,563557137,627116239,467926228,154038981,855078908,239847057,224974902,122188560,630966900,948703110,111762527,643314729,458317020,347201947,12260974,290362454,634790741,326860120,762906451,189110897,144685453,338136139,486192267,542560718,390360006,768623878,555237875,200618633,411646662,640902819,375122720,859840755,926440334,983901029,644361167,557768887,471531181,839019911,492236151,302466426,619067868,105040990,331785240,925654069,57844772,692034765,48498242,173578244,330210638,604566249,943490380,769799859,66924496,614397810,483134411,548440861,611172651,182043044,836488615,267112763,36899421,170177389,284124493,209747550,646096654,66428152,640009911,417026703,204258590,680746748,368803537,249840809,924665621,411817689,558003974,349799126,315013999,572137860,120833284,174118387,790884748,611641624,245313746,493071659,149624586,26381110,755522217,21853784,220111412,180053444,457340982,886562009,173724526,951327622,926270785,220543246,980743241,758691577,520939772,920838631,205931308,939756328,127209836,49345476,427346061,157072463,788168698,789011320,387408827,805584922,520587768,344833484,944402100,505371045,858708031,721939765,123885123,181672954,984166396,544325554,902088524,63682305,743280884,98282317,705755871,446819467,514887133,787448645,217889683,121213294,427078898,708917990,878460076,455497803,188688702,32845539,148203353,739564502,962381246,730353844,350822169,300896832,593976448,58898711,876865498,803005309,104990357,367204649,502881890,125815409,111510829,435176333,509278129,501575299,39102238,823765969,946483679,306248971,708800537,662005514,323003352,262757830,660921811,609033158,806699587,376532152,653905608,771074077,403966670,699051879,751148442,667523617,293892043,216700826,475523317,611175855,349750403,397122770,600991650,811873949,490600655,56091305,341631112,7687611,644789227,306289630,385652175,51610979,146413842,345076831,318654777,659542972,358176183,728989702,403151556,135326157,485219462,322725678,893250857,199042878,42398970,225008067,20707686,910835055,281018401,869115498,560751993,570799146,186189152,82012912,446308901,116332513,407369447,439749755,803681666,423959206,967926299,802286977,315528585,643645200,264777346,571374721,133368312,389173633,899240221,174467132,412823343,21849670,366777395,337371546,824215722,407041089,766446890,426284226,309134906,45999942,585261605,689507865,546107746,961896000,636500332,135133533,295001698,981121543,310622632,646664316,853242302,286506103,830315517,164079343,157584893,98928198,714493736,846792037,118567936,524596615,742292678,718601928,882939162,530683041,82716066,419412605,241084210,127563843,496286870,168923909,497701150,64884037,907404815,412595578,243295012,64070595,847374357,108407193,285510730,105702210,512649952,586758748,761333635,579114732,580055349,965005046,650791737,33850971,119466849,550688638,140298310,717293427,712850525,100756288,810543135,246124914,863189769,337306457,249857916,531007670,139659082,866771448,97020004,662357536,105708199,767804835,532480484,350672723,866120656,377313835,961461578,714816787,888420842,562365416,793124261,676364684,535627784,345437779,588558905,947122281,185010198,122699228,448688298,401386588,769858791,158355617,702201105,877622978,489166721,851037457,113428131,164322101,711992816,296377603,126433807,180450232,146837392,607717358,563604593,356043954,922055014,319182365,174193926,377458326,18507492,143952738,823582808,911429426,440611855,182016880,489811390,453582279,501061568,265897023,242575754,590437149,701707491,368361266,873217515,206915966,477560642,195945276,800255933,146328848,238086060,64124447,568639082,825639698,37835610,459285599,405655713,264184088,811118450,771538314,758568653,67288752,442678232,513740510,249153131,631804884,745225615,303368839,92091573,907775472,192991161,236563759,25776285,131890473,21132408,847102938,149488348,148778253,843822831,163190499,283941706,842734246,29230259,744428930,144384672,350981976,369149228,499015910,998276706,923782806,583341467,887420440,547851984,944178640,925745128,259534405,676669256,21008387,595626741,795993673,687487400,878932432,262993325,132916880,288019935,303500548,798425037,967539431,130866909,690889743,2256339,47921417,167151952,172000018,569932621,181260821,854724929,615055120,990557991,184519647,696726312,165633744,18611998,94903228,108907137,784609625,46356688,111175813,95565207,921448284,965725965,629304430,34924296,21198028,797483283,212669536,976406737,352447176,218531740,655441606,771430154,792985102,270095956,395491706,631203998,141112477,129095841,713050733,361092102,582080861,989296009,765944610,449622199,562260454,60008778,924177229,730633959,531523490,305988364,137309655,467422290,59364172,245102202,884904070,851933726,8498945,363027638,478241543,376816288,647176824,900548916,714776422,398586738,754134414,949513695,812482309,738765334,96373561,456583815,778396146,824708228,169241669,18513247,248953188,866649542,925833075,879168660,686521069,294429425,678005040,225667101,476975131,563022008,257669221,359816064,964823152,949198453,942487694,550498060,149911444,265842716,848412399,712541894,262004030,990279140,397094833,385436353,349417395,343346366,793922093,505807774,206700717,923970484,617836626,654647686,92296771,656850619,106462179,332302661,395494094,300769295,416862903,250124878,328061056,363399471,89342190,996824166,110025828,493324057,340271519,515307727,500719764,296308480,375927426,99937293,739326961,171481824,603207978,317624308,824560460,718392046,473621824,658907409,120298672,935512512,957477156,550497051,314368608,79592957,735904230,947458707,97663817,516391131,936369964,201869156,148854868,105101392,757013867,579559607,867993522,590082342,654916098,232871119,497801638,795057605,879031953,20536976,984651426,417681904,618101543,827509797,22145237,558974756,571472687,729136028,934819037,408198760,660348706,490104187,672922042,265997754,160698662,665096775,199606210,738727709,902511005,738641098,951490713,170465881,791853629,603824480,869243557,874763267,794397707,547857170,653126256,846302493,774655222,599648854,236412620,912437371,32727778,554859775,25994353,271780454,292906854,378285222,233557402,751320564,529931475,371953160,533539382,463597568,470933499,916267699,929447279,645679550,928931634,594083681,892537734,388048241,839147883,340716716,799113275,600857249,293924167,868198295,556913221,912657133,120917217,870176863,96911369,456964969,969501857,96227060,137468292,12325728,844016408,51534403,656437267,868256084,200485713,568923513,439337409,852619174,634116035,356331473,644072860,608828254,679830843,408364825,819994273,708409577,33289493,729955094,596908384,552676290,804063672,642210283,87969249,139856655,573837082,585204162,709919080,62019450,690340904,134375538,239873992,248897451,344866625,929545102,553885732,378658393,844885049,839814934,567317169,38067232,429000062,781481111,237895107,782073191,337473894,141506057,492977927,460288582,745195402,482110822,102004165,152293447,685882358,485879386,848080146,599355957,488608364,19053402,423318689,471333487,188166164,302107539,372743633,177700432,978971079,366701808,401596902,927509072,171361096,95127688,424301456,399542853,768237456,601860578,499990629,187805495,191279700,481600043,305424704,222429969,602590712,904063876,842352983,944208736,819657360,49463685,538026209,906352779,419674963,930518965,778141124,255585286,33994747,519787112,79986460,226108045,524476702,27656221,255579862,646238174,847099521,272965646,865493485,385727148,126314306,37843618,788938122,618363112,928198145,400264960,871653169,62240715,364773082,617467205,972975522,710291243,636653364,440799981,141210740,57867049,423646746,714493511,177625722,617783970,274650380,687499716,611743818,664745550,378779532,204366492,162895731,549949937,442481335,525455322,740477352,481424096,305714815,51047601,438699099,262169947,133720731,478955102,436063979,595492260,936083246,863122159,945175103,263539607,510732407,282342468,686191734,492765857,436266853,1776510,904247837,612920718,48007182,239884386,11204682,40517916,620896715,428051563,228035641,81480630,987941217,506734291,827420210,315533927,873321075,194012513,701591193,469021066,977224823,287810653,418116475,229914328,680362293,685870845,221377050,217438428,436976820,956610315,609746286,995059943,834130154,620333413,129424212,85123869,684341657,372232483,849850868,39008962,334692007,441172896,441332548,832399170,559399752,817223339,368656463,508150161,982500386,805756404,361093783,782516904,227697402,552864398,376648315,131219359,824310464,88378402,105093721,931111394,978424570,462045876,775812495,375392919,974899300,472606090,544185580,50284084,401130151,414301598,593630705,917370510,658630453,411490799,178655844,380745385,325174122,3082222,682403282,550267455,841077458,610783619,361233023,793693746,460107087,799438353,760107599,52044074,119468097,44303927,132339297,573405675,272388138,43419227,411058183,220220432,611745919,805350568,970746014,764062232,393882739,983284303,272507287,577270472,846617654,491819287,206119318,521558324,910021282,639310249,620356611,64059745,687961292,625991240,25907400,59892214,88040640,776895239,818968695,160783525,954869542,293693723,468987937,446082996,916942884,311292313,658592565,634756596,70358162,210975824,253238476,832920931,963525669,882776534,763829888,717755102,134562859,992220619,532109146,425961811,493677646,107786653,207818522,196066339,111474900,257644627,274562332,307727812,717836315,326865766,873090201,124492385,846032717,722268565,757127484,332116994,432329903,443274582,610441402,698528081,310044953,260046011,554112619,703742007,402774419,292306979,760774539,402066147,752998364,271696960,177313912,309878494,540104932,779043454,569185053,160233288,325474984,756301940,892820990,500053160,231334896,794606267,404678875,980732369,283755839,368386613,86296858,67762572,75074675,991932675,688983358,913104550,786957021,879078663,146575829,191767008,638549864,146213572,79225954,65949125,267399617,616601372,31296380,534786460,871570500,417735380,771785110,376385944,154401309,234734748,631694290,542886380,102226975,785537721,242796494,777292172,650777687,121632024,490436396,331066103,939668693,433716263,980024850,797678562,305812176,982021027,688100320,829876446,125002285,364614521,219921143,245211624,309829642,43455167,364536486,85737790,425628595,859372492,471784346,403385340,96571820,837277437,386811318,745690100,28585286,438708382,6635488,915376438,487080701,247830110,935059609,76336473,816549921,272103268,768416972,859456661,463819251,32608561,698776266,688501880,939605786,5192087,844383395,550698387,396220525,25232358,122324978,874042807,493690026,447201459,855822480,585455069,894491961,989605241,539114271,273794598,517458429,753561258,41854924,936179443,534463507,784177424,645763670,839030396,385673367,619137125,536106422};


int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
}