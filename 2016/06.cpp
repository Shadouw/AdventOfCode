#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "eedadn",
	"drvtee",
	"eandsr",
	"raavrd",
	"atevrs",
	"tsrnev",
	"sdttsa",
	"rasrtv",
	"nssdts",
	"ntnada",
	"svetve",
	"tesnvt",
	"vntsnd",
	"vrdear",
	"dvrsen",
	"enarar"};

const vector<string> inputData = {
    "bztzdacg",
	"xyjtwqap",
	"arsiwubu",
	"cjwvfwtp",
	"dpdymenf",
	"kbedgnri",
	"gsrrprxn",
	"ojdxafjb",
	"umujtcwg",
	"fcpqbkti",
	"hfhxzhdt",
	"oradqnqo",
	"pjfgpkgz",
	"fagrqjrn",
	"xjkujuks",
	"iisbsyvl",
	"narthccx",
	"sjbnbbxp",
	"ljaemgip",
	"sdlenzfu",
	"zhzlsmgw",
	"sbdndyku",
	"ekcktelc",
	"vxgoapax",
	"bhepszpx",
	"hozlfbdm",
	"fkjgygrj",
	"keutuund",
	"agzrwrzb",
	"mgcucvkn",
	"wiguuvtm",
	"bnyviixq",
	"ybsozbss",
	"cxaqckwv",
	"ulnksnjj",
	"dsrvvmbs",
	"azfnwcdk",
	"hwtwbilm",
	"lieglyxh",
	"vpqfjxcv",
	"sfwxiyqr",
	"hqifjldw",
	"icnsplkz",
	"oxnqizfs",
	"nzfwhwyu",
	"ygaoadfd",
	"dctauvvs",
	"zmtgvtxg",
	"wwzpvoym",
	"cwhcqxvu",
	"rmcvjkzu",
	"yhpwofcb",
	"nulkmdbi",
	"kdppiqlw",
	"awwysfhc",
	"wutwcxvv",
	"haivrowg",
	"mfmsgbsl",
	"fwmphkmm",
	"mjzwenbv",
	"fkvyebad",
	"sprgbbet",
	"mvndpyjx",
	"azwiuvxc",
	"jysrvsaa",
	"dbdhmylh",
	"bgtahasz",
	"rxvnuzdh",
	"abuhtxpr",
	"sicbkalw",
	"ivrdycpj",
	"zhnmrmhl",
	"wauhlrzq",
	"qvdvzigy",
	"exaihdzw",
	"enmyjluj",
	"pzbmvacm",
	"kwiiicwu",
	"caxviljd",
	"fnpjelcd",
	"sekexsoz",
	"yjpdqfte",
	"lbscrmze",
	"hczfunor",
	"hdvlprev",
	"muyeuczq",
	"eyfcvwhv",
	"wnajxlxv",
	"qovjvytl",
	"nrbzwhsf",
	"qgwbxlqh",
	"djvueone",
	"tjbxisce",
	"fwrbhzrk",
	"wesdwdmd",
	"ssumqhxi",
	"kkbxbgyg",
	"ghlmwlkn",
	"nwqprhnc",
	"zothmtwq",
	"xlxhmpvb",
	"wlyckxvt",
	"bmgdhtoc",
	"zkysylxx",
	"paoxzqpo",
	"dpufpfkq",
	"rehmrtqi",
	"zpwyfvdk",
	"kwdpimya",
	"ipnjkoso",
	"mxqxkokf",
	"rsczwsfd",
	"rqrpctlq",
	"geozhplt",
	"ajyatmjk",
	"vkbycpap",
	"pmoftkvg",
	"tzjsvaiy",
	"shoghugz",
	"zbkifgyr",
	"pbkpbmev",
	"mlodbiog",
	"ceemnpgc",
	"rnhmanzi",
	"mkbwwvbx",
	"iwgnsett",
	"utbnohwb",
	"ddxtrdje",
	"mcpjzqws",
	"nrixbssl",
	"tdwjqjgc",
	"pyjyaost",
	"ktslndcw",
	"jseutzlp",
	"aipejffr",
	"iwcjyacs",
	"lshhpbdq",
	"gpenffaf",
	"cukufmfp",
	"ghwjsabp",
	"tmxtxsmw",
	"dhyfbhne",
	"pngepnxe",
	"pojchoea",
	"gtgiogrp",
	"xydkeazh",
	"vqwnnjvx",
	"azjcxxbj",
	"iteaqkgn",
	"nnfhcbhc",
	"oqrlizro",
	"nexqvoak",
	"rglnpjny",
	"ygzhhlqc",
	"mikoaotl",
	"jrhixpef",
	"eikwdvag",
	"wjinncla",
	"ldkfliro",
	"vkmadbkm",
	"loxctpok",
	"iicuxdes",
	"utkriebm",
	"mohvgmkt",
	"fgsaycsy",
	"xmvkgduq",
	"rqhboixq",
	"pgvrtlnh",
	"ztahypot",
	"vmiwyimf",
	"jcgwncls",
	"yiyusdvo",
	"ucqjaxze",
	"bxjgpahy",
	"uginqzlk",
	"nlaxigbi",
	"fpgrsfym",
	"bnanuhpw",
	"uapzqpix",
	"ntebfqhr",
	"defunben",
	"ructvovh",
	"aqhymxge",
	"gdzxxnvd",
	"xauqzcfd",
	"fhrqlybl",
	"erlyajtu",
	"xsqdriep",
	"tjkoykqt",
	"osjeelqi",
	"clofyxny",
	"lhwssjlj",
	"fhaqhrki",
	"cxgocyms",
	"dbfqhwbk",
	"fqpxxtdc",
	"drxiflgp",
	"athtumkv",
	"wpdjptpu",
	"ofqtdaja",
	"fapibvfg",
	"icohxeds",
	"jgmgzzsd",
	"vogagqfx",
	"qelzldjl",
	"qrdlgaqb",
	"woncwuof",
	"sdltdgrl",
	"hwwvgjoz",
	"itrqkyhw",
	"slmehuaw",
	"uxhtcxyc",
	"lsrgmwcr",
	"ligjqlcx",
	"unzkbdhh",
	"vmssbxos",
	"plkfxaqr",
	"zmmeokxo",
	"rgupyiig",
	"psqalimc",
	"zkpdxmny",
	"ctkzxvob",
	"eumydwul",
	"zmzfsjwx",
	"vsdqjfwn",
	"xywlcgzx",
	"yfxinykj",
	"xzfmavcq",
	"uotgqrnu",
	"mhgclvyn",
	"qqetjpeo",
	"bjvmylzy",
	"iruxfcrz",
	"jvldgohm",
	"qvevmjjb",
	"gbobtgrq",
	"iwesuoas",
	"wqkdnzpt",
	"iqhlvjyk",
	"gyqyoolp",
	"wvacvumq",
	"caqzoruh",
	"ftpxpkpr",
	"wvcztqyk",
	"qfqjtgey",
	"croanejb",
	"cbqjdcyz",
	"kxewlwwi",
	"fqarbziw",
	"pepzgqha",
	"cqaeejem",
	"rzezjxhr",
	"ouzyjmdj",
	"sxkmzmqg",
	"txdyoycu",
	"shuzdzke",
	"tyblgetz",
	"troqvtbc",
	"vtkjnqzf",
	"qkzksiui",
	"yvitrrnb",
	"orustrih",
	"dckmcabj",
	"rzkgzwwa",
	"stqdalzw",
	"qlfrvdfx",
	"tbbywjpk",
	"rgmptpyt",
	"oywgrgnf",
	"mczqsszo",
	"bqcllnsw",
	"ryungzti",
	"hsdhzcsq",
	"qlwwnjao",
	"gebhrhss",
	"auelxsel",
	"ooibpinr",
	"hvbwkafc",
	"wyxniwnp",
	"yuniddtp",
	"lkfmtxet",
	"uzvwegaf",
	"mooyfrwz",
	"zbzziowo",
	"udyxjlih",
	"husurpur",
	"oufjezde",
	"dhhqhhvu",
	"ggpiyvdj",
	"pnwosfne",
	"dydoaomg",
	"jigdybwi",
	"jrezqnyp",
	"uqhjltum",
	"mqtfqsez",
	"yebfabmm",
	"vvvvbrta",
	"uvppafsf",
	"sllgpeix",
	"ulgeznra",
	"ifpvbsql",
	"mzdrgkrt",
	"xolsjkcy",
	"azusnhor",
	"hyfnelhw",
	"becqefpj",
	"epyokhod",
	"tqojzdgz",
	"ckjqztth",
	"aweeqxmd",
	"fehhuhve",
	"bjrgsmrc",
	"zmqofcvf",
	"zfjfaomq",
	"bssvmrde",
	"xfdblalt",
	"qhywbzba",
	"mtgsvemd",
	"wvberfyb",
	"mjxkmqul",
	"aytkyusz",
	"sabuotpk",
	"uacviqis",
	"jolhhusp",
	"xbjvogig",
	"gatwogxo",
	"taxbkfxi",
	"fhvejhkr",
	"mlmbhjis",
	"zuezkkhq",
	"cdwcwuvv",
	"jmlprdmv",
	"ydwyooiu",
	"exqatqjs",
	"eunwnucj",
	"hkrnsana",
	"tmfeymay",
	"tcnogxpv",
	"lnlrpnzt",
	"vavbgplk",
	"kjymlakj",
	"tmlseyul",
	"zfowvrum",
	"yzvwvrmw",
	"qntgqett",
	"vwwqkqdt",
	"xlfedyzg",
	"ehxpxwjn",
	"wmijbqgj",
	"idftxkgo",
	"mymigedt",
	"bmouaruq",
	"bxnbmvxz",
	"jqmgqwta",
	"idawdbub",
	"opxennsn",
	"jeotjdhx",
	"sojzqnpa",
	"xouarvap",
	"yjuoninr",
	"vqjogzjl",
	"khzkueji",
	"ndoiuxtm",
	"wifnoizv",
	"afzkeddd",
	"pfyyvihg",
	"pcsrligt",
	"xnsxcyrz",
	"gzququlr",
	"vihfqqdo",
	"lsbsitur",
	"kqrkamdr",
	"peludmha",
	"dfvkfbyu",
	"zscdzqua",
	"lumijqbx",
	"hzkwiitz",
	"yatolkoh",
	"ikbbpwdh",
	"emamjtmc",
	"eqioawcx",
	"bfkrcrfp",
	"ksntxvee",
	"bnslkpji",
	"tblktbpn",
	"gvqfksyi",
	"caplwhtr",
	"jtcllupx",
	"ployzvxi",
	"gygpdyfb",
	"twdijfma",
	"yrzmyoza",
	"gymlehrc",
	"bppycuib",
	"uftzoycx",
	"uxokapsw",
	"jpiwwboy",
	"eciicuyo",
	"hgyuxrfj",
	"hjdhthqg",
	"cexcqher",
	"vsjolhue",
	"odqcfrkk",
	"gkypgguj",
	"xuthrpos",
	"nkzpsbqv",
	"erofbehb",
	"pnxcwqyk",
	"gcwhkxjo",
	"npbnukjp",
	"qmshmgej",
	"txrcdgeo",
	"xttdifgz",
	"vkqihmqf",
	"rlaqduzu",
	"hcjjkhxu",
	"qctdznju",
	"yvekncrn",
	"cajupqki",
	"nccbcgcq",
	"byxxgvjk",
	"zidpfckc",
	"bzeawgwe",
	"omyegefy",
	"ythcjpbj",
	"kcxohucy",
	"wkigkolb",
	"ntvrrpqn",
	"qxcxwtuc",
	"idxsnspd",
	"nvivszfy",
	"tkqlznph",
	"vxnsojrk",
	"kralcfwl",
	"hfkgjwds",
	"wuzgluwn",
	"jwltajll",
	"vpcbpboa",
	"bnrrdjry",
	"uurpkisf",
	"qbjniyrw",
	"einiyjjk",
	"gwmmewnm",
	"erxoycqf",
	"uwdvnnwd",
	"rjqfozcv",
	"nvnjlmum",
	"kuirunnm",
	"moguesgh",
	"luiabxha",
	"xeuaetvy",
	"zcijrciq",
	"dxyawjfe",
	"bxxaytah",
	"firlwpxz",
	"akepeyho",
	"xneohwpu",
	"wrhemsyg",
	"gbafuemn",
	"kzrlkkdd",
	"xsgupnkf",
	"xbqaoosg",
	"dlkuzeqc",
	"hidzsgot",
	"emftjwln",
	"tvwbrngp",
	"habctvij",
	"idzmgcue",
	"flyyevlb",
	"orhdasvb",
	"qwgsvokg",
	"rgpcvtee",
	"jvwyfziw",
	"lzikmdqh",
	"dsyvnfaj",
	"inrlcdst",
	"ehzxjtin",
	"pdnhilac",
	"cvfbcuyz",
	"vtcmfsbh",
	"lnmgmfzw",
	"vovbxstv",
	"opvfvcnx",
	"zlyaoifj",
	"ziumzwqh",
	"phtmspff",
	"jijqudod",
	"jtistrvr",
	"oucmojll",
	"lfjckzhn",
	"fkaodyev",
	"qgspkigk",
	"ypstmrav",
	"kxmxsxrg",
	"egmkleby",
	"ogralaup",
	"klguxwmz",
	"sdpqwdcl",
	"pctkiaws",
	"tvsrfgix",
	"myyrujrq",
	"lzluftpg",
	"rbvscsuk",
	"jfjfdstb",
	"lexiumav",
	"nyvrxexy",
	"jioktbzf",
	"arubkmmm",
	"fnvimawa",
	"dwncnkfi",
	"hyfpywbn",
	"wootqtvb",
	"ktlnzuyh",
	"qpbackvb",
	"reaqetoi",
	"edmnonic",
	"nlpdmqfu",
	"osfsybtk",
	"asnfzlnn",
	"lzsspajo",
	"qanbwzel",
	"lblvbkof",
	"uvurrekd",
	"kshqoiqw",
	"oosxudql",
	"orakdrgn",
	"yotzryse",
	"rpuhmeau",
	"cqchkvbo",
	"ajcaluhy",
	"sabvtxiq",
	"sctoapgf",
	"ihhznfmd",
	"yenlgcmo",
	"dihxrbos",
	"tfusfxad",
	"sdmdfhxa",
	"kodcikxm",
	"cfvvcfum",
	"ynnrmqiw",
	"rbsepvwv",
	"npmdblpf",
	"jgltfwgq",
	"guitdsvy",
	"nfyzuhgv",
	"dgjghspu"};

class SignalsAndNoise
{
public:
    SignalsAndNoise(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input)
        {
            frequencylength = elem.size();
            for ( int i=0; i < frequencylength; ++i )
                characterfrequency[make_pair(i,elem[i])]++;
        }
    }

    string getRepetitionCode()
    {
        string RepetitionCode;

        for ( int i=0; i < frequencylength; ++i )
        {
            int maxcount = 0;
            char maxchar = '.';

            for ( char c='a'; c<='z'; ++c )
            {
                if (characterfrequency[make_pair(i,c)] > maxcount)
                {
                    maxcount = characterfrequency[make_pair(i,c)];
                    maxchar = c;
                }
            }
            RepetitionCode += maxchar;
        }

        cout << "RepetitionCode: " << RepetitionCode << endl;
        return RepetitionCode;
    }
    
    string getModifiedRepitionCode()
    {
        string ModifiedRepitionCode;

        for ( int i=0; i < frequencylength; ++i )
        {
            int maxcount = INT_MAX;
            char maxchar = '.';

            for ( char c='a'; c<='z'; ++c )
            {
                if (characterfrequency[make_pair(i,c)] != 0 && characterfrequency[make_pair(i,c)] < maxcount)
                {
                    maxcount = characterfrequency[make_pair(i,c)];
                    maxchar = c;
                }
            }
            ModifiedRepitionCode += maxchar;
        }

        cout << "ModifiedRepitionCode: " << ModifiedRepitionCode << endl;
        return ModifiedRepitionCode;
    }

private:
    const vector<string> input;

    int frequencylength = 0;
    map<std::pair<int,char>, int> characterfrequency;
};

TEST_CASE("Testdata")
{
    SignalsAndNoise SignalsAndNoiseData(inputTestdata);
    REQUIRE("easter" == SignalsAndNoiseData.getRepetitionCode());
    REQUIRE("advent" == SignalsAndNoiseData.getModifiedRepitionCode());
}

TEST_CASE("SignalsAndNoise")
{
    SignalsAndNoise SignalsAndNoiseData(inputData);
    REQUIRE("mshjnduc" == SignalsAndNoiseData.getRepetitionCode());
    REQUIRE("apfeeebz" == SignalsAndNoiseData.getModifiedRepitionCode());
}