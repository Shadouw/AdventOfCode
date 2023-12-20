#include <iostream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "2413432311323",
    "3215453535623",
    "3255245654254",
    "3446585845452",
    "4546657867536",
    "1438598798454",
    "4457876987766",
    "3637877979653",
    "4654967986887",
    "4564679986453",
    "1224686865563",
    "2546548887735",
    "4322674655533"
};

const vector<string> inputData = {
    "534415514135453124461333615152111172677134533636656271274236365616565137415273525511165575327363331241741557653113666233613115623152664423332",
    "143153553532652144244555514665734545167762313231334475322557762622752145154167727645126513352223423415651656133121126453225343466255353344324",
    "431231423644152164112135132615556326276246113351777544176256511561764724256562566422367116247525362264766445567115621232144511654116644221442",
    "425112541336332234654342545214351652572172316456737222125677244536164452131262721226545725765227744454452372645522325411234233321414435114313",
    "333322512434455165453611427363633244553411531716322136116465566556725287838862767327666631213226747356156745324362547346612431145111316162222",
    "111514411336235512434444722163142532326377265214477474772227434242342487248563656855381764455575443361236276175665733434666412316634222625432",
    "141463114244415543252465174452177273546126747241275378348335524748634687254422624326485536775674735465743152735472613365122645655326361561134",
    "134653525652435431235625115231515114422634276355327264488345322457327577336525263756684486556413673514652631745334477413724124144242416562364",
    "434616262562242243346234454655134362454141337665258437457763523262865265676844582783487233862482357347212322641527462516415365134321145512424",
    "353433635165154445216737761473212433367151711344884646786288727388682537235754633528622423642343267676557653373252736324131431534241261612624",
    "535615234511545246516346262344152117454443774583448446657364527357552232352434576756858266262525523551653164511467127723215346233625622165551",
    "231653426453544512572173275441612612663732727322537445574356487336284775283336572372467376626887535687344753435441261141761331551664333532444",
    "236225356626321263631234733432532122217863566633725667447746588453345684243745863267773675523574827578685136411344611122414161343312335613311",
    "461442663642664613611212153714523655525727747886855882872352268628385875675656428682784745474866528478767465675454576242747556364563365533345",
    "235516112452617534221523251215633327684642774455582744454432653632663385788245473237856636588357775688555238612412764126237253373113125451211",
    "554126643325367353521466261744747333266574465262885865853664734835482232538827357464886342245884668488367534426742241621543122316311112143422",
    "234522524632163352713473132442554535244857335254754323244728372383524234632427343647438643288777723723447538538615457651524666555651133323553",
    "421261554413571373672433437574763482622586677388856845274774733653638779985648352732582782737337656453244353668867347455116615321754152551355",
    "351353342433572637145116624252437536486848242228584277342375854365493384594846835984253244438886785788423556782746626274532164152146451226411",
    "565564361172562162776327653656863878722422532276353247372336695938495676348577649877684384837355375252568666257834754374124472421164745256131",
    "244511514517375224665667415847488385867364744587645684567444899478367948453936433569898389277444822526553582555486471615744231363254776235525",
    "652231123276743453446765525768842635466257223326886959596965566977563679848768499386497935598725883564386578773876634317334376155476666666361",
    "345245346674114223653527462553638552564535727362364779936457969678493778946455544457554389938484785583632352473458263377762577143336473411611",
    "552332356127765265621174358564476888342482685288793375874696375865674397583436676496484594945959478537283242536427332483772374442134361626422",
    "544664154661637774671612856388833878588423434648656685779644585788369889539486837853367399757586957553246638464678374575426354675242173655231",
    "654664761756144662472474835855834643337643575954956454756888897566975879739687869679786677345687377654535233778635684687343237313445644316444",
    "634263424461271713551624366344576823288866938748445439359877487884667939977686534597945454845343888437227462467826648523786264337622226424353",
    "534213415514342132746272734737285627552459769494464677468358863997994876588384483784739443348534988434378735687243754252855245121611566552414",
    "355122664125227723657584672235778528835855996686857953596859554477547545793379466677864667539765633798988738384337784377745844677363654711732",
    "451422325171376461588422835654277873234597573963797648867697393465575359953985779866763935693657849885757872484472473354663766413125123116425",
    "147512513322221371582375845384746648976378649874469584566595439686588489397678738389363874888787646358993454837457822373726841637442143353742",
    "141735646163156428677787384268725769963479764954588699845558585487948796686489987745673587973768987468385489355376788865856366613213654642522",
    "753142372125655585458574476773623265377969854865338398634936774994444787445789948859777953686746484454675675365823773583453376314747433723146",
    "245741165457173375367474328273434489385936398553965897588676978864769895578556886689947899495557637368566938547737843727884854462267733116641",
    "375613234515634846466545642777365755453795357393577876695598897969846468468757674479655854896963498535988548556884652834655883682273147214633",
    "142334425663573763233676275843345697938553477537467464759569946578798565897685987549445888756748388657745485353386387227663425726776264536222",
    "767564476241124338562456283854764739563737343884848945786455459845865496987449966895748566577466368579359389887952773245638552665132432146247",
    "463376163734176445652626262675644877754446893657676454885864956448597499596686574544755588954697934488587684477693475458385324487421611722637",
    "342263463322646282757665638336586388666363837365679874675594977548656457484664755756449795469544648453994873854766476823882727678327753752743",
    "536735332312235682776826877553783699856378966889699966964784774876756656679464757499987699857775754777588835773395653723474737584784771111721",
    "443513421717782325685558455497447743798687484455746587687747485885766987648766946954747479956749563458637769787338496582846624785448364647457",
    "753474227124465665228478489473453899744356575469654569946744854954696845858878886794954758694657954647954959359669534873827685747672462515251",
    "666773657666348378827647379355936767948876947679556799489679669887486989565944456998489745848976699833349738396944355876672352832784464241155",
    "756277546626222245745368635866653447957845659595945845964659549947779889564878974487597446755956577666834539874978976947744422768766342631762",
    "213661414175386688225557549883756493984535966564858545675566765767967458947595746584954979759645588548965987873866369433574824364356865647623",
    "475232731233284282888284484565363366854689844644559645854858965885998559657775565656679845577769445767474378576883467978675588438642445244432",
    "445647145645642768385568686576858797736745578979749486765468599999556569859957586964459448744975555869754353886453585955777834222765323133664",
    "235557456253733727462485575776539655933954878445957898577958678785688955658676975698446975555979758765866654847379636544738687474828783113272",
    "441372758738567556557625995886765974997749798977978794644557558767698589685779599899994999758975985566995499676738695977574876455787484716541",
    "146433637657867633765369346677397965347675847545447969976699698765578679859577678599769555498554784889764585463945539556948842545685753217125",
    "465127582384587626363646996473775434854584597874669459767899976889775798699556986755887764558478744444746967385964594636358623772878283275312",
    "151364275768688482822979887983978368654988768445746678758856765576868669675879885597558755767789998644949765834357767477494467458587344836537",
    "215531732828587567752369839346579495474669469744599658997967678556589896568896657958858659968457946865556597877453984466747252368346276516124",
    "662513728842323542737634683376379586556864484999656685889895969958566559986958987679565696566878756558849448986596735353794443787685584781252",
    "523446885357236827248577378664659478999586866569477867567587565985576698568569978878667979896968799564757896656863973977667228857834256787356",
    "211311884258626284489634536357978888579475494697566565795757569957586575757796797578599577866597984997467449883986653574698538555647534287251",
    "466661736853662848357464753659894795557649797784959886857678779997585959769867956588896986875957765797784655855635599667948468453722587887424",
    "111312365225863284499986968566548849484466674544878859578796979586865777977957757786986685978765856785499976687845486996664586788738244423427",
    "516676232254833262768769468757544474889845796794857959656857589568567676676559755656595755999566644699458844654584566995859664754525573234734",
    "431142623233528247835635939793968687846795798578859585665955655988868989686778666789959685775667864978499688654474448688566477562428766376575",
    "744752732382447637675557544774786594864499878475668596965857658778796686969977999569658996578959569745955454969837788494794634734558736487132",
    "745342438238877336974635656794496898467587849466887659568588856668989766678967969767695687797676587769779978678649784653697586326842567744757",
    "511558425343666383989888374386845497985549767768967776755699897886788867978667789896579678595757995757496455586689746785665356436272232274874",
    "517388482454756428856774849647395997579444576876897597585987668967798887896997976778799576687969958694694854655977863788946485328384573885735",
    "155525775783888322494779755836365964487665989767965777789868897676786967888999779678689955858757585974447454596449973893339893782477456554345",
    "414135583473533472348796677746964957485456999888876886978878867989878879796668879768779987857879598649464456497568553563768898657327774852562",
    "246563665666434567734566795899959969765465859885787878875779998789878799977986699799886588579598585684648468775454978847495646436564862266347",
    "721765872733376428447398733987854688575957784658585756595579899978798676999789777896769855579956955785484477688985838887639387584372744832576",
    "341267842585563327386548739577954889658787478868695888556986986967777686799667787987787967788779888969877845885783658434554537828385837475276",
    "647534578864453238839885598334466485548987775569868585786968796867888687886696998667976959767685685944955987949584359764888686542226662533651",
    "671352655352423376848587599896565946785588687679956555697996776978667779886676887789757788869968589469558989978946388453573439338588887878575",
    "773347877454647328958545345989878475547689855769779777768687798877667978869777666976798975668879698976886584747859948554857358365342558386816",
    "474222633223386649873683946337959475569879697859679695685969688889676866766789669897986569977559865798649575968845737734358453445225752538565",
    "734467526268754489657844754745965979978964547997979588665888667899667697979898789768659996578766666944678859757965755398776564884633847735653",
    "121635723655736356439854587856574674598859567967966776767879686996799776986978688969866666756969667769446546744988563845954365564646683574555",
    "553455564664244582435793979683957776576876865887967759897698789999666687879899979698585896798579557958476764754784576974545345666646433535277",
    "572443376682437452569986763786684547947897485976779589778657867776787666897979678799679598969685998989485689596557473689736833583338772538443",
    "355425735685624285949664656689995695676798668687965568578886678869967776797779766887685857986666569958784694964779774856434534847876427833327",
    "256284528623652482678475496864775444668567778666576878556765687678999787666687677887789658995855559788699676996784683863948594435583773584317",
    "432667672286323844358788783784588999789488677779585956875668886679766678989799987958587975856757945794994794898559396639498895525555644526733",
    "721724477828346855977584387867654488494568456658999995559578567698877888778869798887875596896656695566667678969648968889583556446566785763656",
    "233724586442255363567669586745447976955569465769957895779599677688876686688668786687678655889858966644846877945979493333393586577565636285525",
    "164353383342837643243375573743785446587559644956655955757566675986989898899987776879557587755665465586846646587385947987459473277882686624217",
    "565615552853548658278684574495354868999778544646978987765787679877899696787798596865895767996788599979989457684345498537575466425857363577344",
    "345638656252748342759783375933956756584488888986977766989675895676799876877979565767968679686657454499856869988397765894994384562834667838467",
    "276464633643688525438848963996375876497759667649769967578577669575896777986785878556998565889979488447994498764798335873755946387647386525512",
    "556476548384684684747839463487747747677594499474576595898779999758866796585776759886965858755746846995766795976653668969959783533624474561716",
    "212147855848323775377774944587656698488794555859875598967989976985776588555555866698867577855796489796658644767835876766963823363486365587214",
    "263673778857574832648764734449445535744567448497459778677597566599869766656765857565896859999754658478975558478437475958444847845847476273744",
    "277173245483827546468738785757338546567649554479645655778957867866885995999596876955756998578487955486445556845876385553656278548368864853454",
    "346622225346485386555887553995389694598779685745655457756998757568777958966656676577999899779867655555897748584497989646873248468664855317362",
    "121564532233277785467583753698673764456478674948986445897598689759578886895878667796686599977686774986855974495963669656476725728684486246475",
    "727267373755567234376783444575783936676494959979964475575799866659969599756897976779865798845686498947858797884997685366438227426452525727224",
    "544314154452746278626779683776698388496656999794774878869686876989756687798859856569695546696654764997484765564793465593753756657424673645112",
    "426334173466474242576326976455988688774685598898876688474698698979878587678998978597959695499547657974957477634488643644654628642357645126715",
    "221164646742527333275258865488838554956796776454656649569655779675656956557679868979645596759877659969744684986483833796438784776777672444535",
    "276773631343388587538634786573364646757487464586455968447964488679899658757786667689855967648769967859789443377996348585427678846354674212555",
    "412765711352782282523537643489439646353657994468687664775658997986888668585558574847556486456575465684879488438554765376688766665652463231145",
    "261643766725828834835638353374944685754898794868958698974454889895556459864545868669699787965474688468757583763786935964575437863524456322324",
    "564744461547572345735766567587446969793798476859565846596869976868878595958645887698544979978858894564375459466569977587258267757583654755145",
    "571152457224545346785462736537659578388976485556494478497954994558794789449685487859545444867446674765565576834674976582237633633755833115657",
    "544243742657483528734476824455854585749959795549655554846777644449849755744784554768597599469549458535943659586549738764722227627247113674533",
    "465376454533465887782328464373539496444433376689568748879656679588657875979985754945479847494748669788474957993333495558862754882275517361356",
    "522322621562252546456278536847398793876444788798479684547767588595964476664494759564646558548687735683493588967658367324433447742287124454551",
    "754745177477547553447757642226496337774335895487988979857586455669469949769584688854546474799653989849543935898756576788787244358555631262267",
    "633716767167335633763823625659365464497635598768968988675757846669944657566444448944894694548848755879443674867377788377845564463846113372711",
    "771625161217123842748632367334558488575798675445794844994847467476867898555785468779759775667837969887446476385485428386854428238364656353455",
    "573163124275667733438428834356369879356846584785868438896479748788856645964966576548996869998837788758379474737453724553526238556135763452246",
    "723727545315762283447867476368348546385496955666674787875779994759568468957968989785798984436755669889954879796643463367436326236154445266135",
    "156132757137733552887547588722543874834866897443745339749665794586776885646899759884584467788768667369853963736858737556473582214663236721114",
    "671632221275173663768228645264555369399877384695855538534899854756498556779495697973457398593784783948455643485833583822838565253723565135257",
    "237655473243421665433644822854475846473746974765644955347585495667859979545876696958644443788537855668768449276543236877674458174341257711127",
    "435731365262641316665227486587283844346756574775677874499534998487987876689437557554456777386439768536843756462758384658258887726313711521241",
    "613311751267562472536846342365762357378444474497983935978575885936676364899959755856796583435534363867736547388663236457476351272751176751375",
    "423547215173421762125786572864653546375545683657564783447553476753478893688997596663438344697986539575784854728585287672742255751124541643323",
    "145515235317411572656357743633528662878548667354387847553686684498963934448633598365367766599766345873424334334778388678587173751363223615711",
    "232312761271227562413536578564848447252466393677443365548367793388663535648748559489934935578793686778233778252633832748575255475244651351716",
    "213221411636634731216722487428847864847744695445996383364364793899585686979695863867435549754853446436686745446562628572315154461516146515446",
    "132437367352246256527565357274656758625674565487337575895389538763857649765979488594697888867965394684274457388743764736571536116317224551224",
    "256346535731162646453573832224772648433633836785443833895633889444975577855979868348375559365635772233224556774552353753711414261632746143455",
    "134366355344175664142754446752768464562652524244249688948586897574665539499888694974745958535823367455382233686324826863721774142563453162543",
    "232521167626233775674441775355572237756262555387486675966785484954744857865639973874877576583274725757437785544482535171662457115144131356642",
    "535523551677464635576122764546285443426583345447328647379446733349879869463979947986693897776576274368676368623374463441224713635166567656322",
    "322554246276744511612756773585582344584388533824364675266783345399793854674435693886332378487228564643287886653285571223561126164434676232635",
    "133151525444131721267152434745367582475624526577543485874827268553547956497948985558268636462824482738878374373247745611327722224223516562164",
    "631113666321523115544756536623447836378675737477388484657467785742258365867785875347648572646383235437573357658646277371715771412637614613564",
    "613454432142746143246236746677746258526435255322868367366533448387566444222856357666444777253388426544473752443317652243566214327345531415111",
    "612552142334225716575367613772135736285434643266582676644278553428734447252373746338245386648224378542235327641417474274764425114344236654561",
    "566521154163322457512764656442315247474444466623647758737853344443466222847728583745538822776482775667884627272364424271734721746325642142641",
    "525433525365543323574127647653346564184466665437544833374488864824774274448577747533783768553354232856364621565362631775234372425263465413634",
    "641232642454261355565153272414365552253574756623558626286358742284346768687345838623743224473827446863626763421574575143445115131445425342443",
    "565615644253346552353573323243171115674268236734574476384323835756863446337746238734754823364243344332315322433524256212217414414524316232321",
    "144411644624563614616335155521431617445252863366554358636555762225656385543542577285355663277745374226126252535743144236225222326151213162114",
    "164465123453311466631745437761513754736163113523342655835562534742636588426578375584884542574286746172215171731433726362521252526125226316644",
    "266412313626412456352255523122162552246467472564672572624335752886865853443364264337252488686566447241463771242574574646723632616631165231566",
    "125243416621545466254631426261643517757142337233365327537426344452743478323433545334333776886455363744322261161533367475226466455121145421555",
    "243636124536216413242417371755621123365122522612246447676874322547422775322663555232775224452767462351722432314711417511366165335354121363443",
    "552314332145641535152245776413475576234176511166111374535652333587354682554337348283541653553653477621777653427172723523115611616466341145443",
    "433356555154161312562332651636363533565751644223741645722355435554442236322545558476342436565143746544227225743667122345363463455414415536235",
    "423154245165125624414155562224431557461334117361562221661757752155721727456434522371755771164266243445632653752753526633124126431462336111334",
    "124444552364152561665532531634233615724764471561612226344134256716317667432613647737247777667745522756612542716752564161336133565445451234112"
};

class item {
public:
    item(const string _input)
        : input(_input)
    {
    }

    long getResultA()
    {
        long resultA = 0;

        return resultA;
    }

    long getResultB()
    {
        long resultB = 0;

        return resultB;
    }

    string getString() { return input; }

    friend bool operator<(const item& l, const item& r)
    {
        return l.input < r.input;
    }

private:
    string input;

    friend class ClumsyCrucible;
};

class ClumsyCrucible {
public:
    ClumsyCrucible(const vector<string>& _input)
        : input(_input)
        , rows(_input[0].size())
        , cols(_input[0].size())
    {
        cout << "Size of Input: " << rows << " rows " << cols << " cols " << endl;

        // Parse data
        for (auto elem : input)
            items.push_back(item(elem));
    }

    long getResultA()
    {
        long resultA = 0;
        for (auto e : items)
            resultA += e.getResultA();

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = 0;
        for (auto e : items)
            resultB += e.getResultB();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    const long rows;
    const long cols;
    vector<item> items;
};

TEST_CASE("Testdata")
{
    ClumsyCrucible problemData(inputTestdata);
    REQUIRE(0 == problemData.getResultA());
    REQUIRE(0 == problemData.getResultB());
}

TEST_CASE("ClumsyCrucible")
{
    ClumsyCrucible problemData(inputData);
    REQUIRE(0 == problemData.getResultA());
    REQUIRE(0 == problemData.getResultB());
}