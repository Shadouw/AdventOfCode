#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include <hextoint.h>
#include <stringtovector.h>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "R 6 (#70c710)",
    "D 5 (#0dc571)",
    "L 2 (#5713f0)",
    "D 2 (#d2c081)",
    "R 2 (#59c680)",
    "D 2 (#411b91)",
    "L 5 (#8ceee2)",
    "U 2 (#caa173)",
    "L 1 (#1b58a2)",
    "U 2 (#caa171)",
    "R 2 (#7807d2)",
    "U 3 (#a77fa3)",
    "L 2 (#015232)",
    "U 2 (#7a21e3)"
};

const vector<string> inputData = {
    "L 5 (#0760b2)",
    "U 4 (#058b53)",
    "L 3 (#d05a12)",
    "D 4 (#058b51)",
    "L 6 (#12ee82)",
    "U 6 (#63c403)",
    "L 4 (#065a12)",
    "U 8 (#a44373)",
    "L 7 (#7581c2)",
    "U 7 (#334ec3)",
    "L 3 (#35e792)",
    "U 5 (#079963)",
    "L 3 (#1737b0)",
    "U 4 (#29a7a3)",
    "L 2 (#705a02)",
    "U 5 (#7151e3)",
    "L 4 (#705a00)",
    "U 4 (#43f5a3)",
    "L 5 (#1737b2)",
    "U 8 (#61a8c3)",
    "L 5 (#6005d2)",
    "D 3 (#20f4c1)",
    "L 3 (#4aa812)",
    "D 3 (#8163b1)",
    "L 4 (#80ac22)",
    "D 4 (#5e64c1)",
    "L 7 (#cb5430)",
    "D 5 (#7ac2d1)",
    "R 7 (#920132)",
    "D 6 (#a44371)",
    "L 6 (#944582)",
    "U 3 (#bc3423)",
    "L 5 (#71c1b2)",
    "U 4 (#88e6f3)",
    "L 4 (#0e35f2)",
    "U 5 (#11fa31)",
    "L 8 (#6ab312)",
    "U 5 (#5c3df1)",
    "R 8 (#40be22)",
    "U 3 (#5c3df3)",
    "R 9 (#42e412)",
    "U 6 (#11fa33)",
    "R 5 (#178f02)",
    "U 10 (#88e6f1)",
    "L 2 (#cff5f2)",
    "U 6 (#41fb73)",
    "L 5 (#247782)",
    "U 4 (#8d6d73)",
    "L 5 (#139492)",
    "U 8 (#6360d3)",
    "R 4 (#1688c2)",
    "U 2 (#28eb43)",
    "R 5 (#7d6230)",
    "U 6 (#769093)",
    "R 3 (#7d6232)",
    "U 5 (#487383)",
    "L 5 (#4fe4c2)",
    "U 4 (#784971)",
    "L 7 (#649a42)",
    "U 3 (#81c8d1)",
    "L 6 (#3e8422)",
    "U 5 (#2e26f3)",
    "L 5 (#880bd2)",
    "U 4 (#cbeb53)",
    "L 6 (#3c3a82)",
    "U 3 (#990203)",
    "L 8 (#18ce92)",
    "U 6 (#3bd723)",
    "L 10 (#8b17c2)",
    "U 5 (#931f03)",
    "R 7 (#56b4b2)",
    "U 3 (#1c3d03)",
    "R 2 (#693490)",
    "U 7 (#a5d813)",
    "L 4 (#693492)",
    "U 7 (#454523)",
    "R 8 (#749e20)",
    "U 3 (#b6ecd3)",
    "L 8 (#1e69b0)",
    "U 6 (#0cd813)",
    "R 4 (#a286d0)",
    "U 8 (#8249a3)",
    "R 6 (#c431e0)",
    "U 10 (#64b5d3)",
    "R 3 (#26fee0)",
    "U 7 (#3a6403)",
    "R 7 (#44c0a2)",
    "U 8 (#574291)",
    "R 2 (#9bf502)",
    "U 5 (#574293)",
    "R 5 (#0a7b22)",
    "U 8 (#12e553)",
    "R 2 (#67c0e0)",
    "U 3 (#ab6f63)",
    "R 7 (#922b60)",
    "D 6 (#680283)",
    "R 5 (#637c90)",
    "D 5 (#b10343)",
    "R 3 (#954ed0)",
    "D 8 (#254333)",
    "L 8 (#3f16a0)",
    "D 3 (#55f2c3)",
    "R 4 (#2465e0)",
    "D 9 (#6b7461)",
    "R 6 (#8b2b00)",
    "D 7 (#6b7463)",
    "R 5 (#7ae9f0)",
    "D 3 (#584e33)",
    "R 3 (#4fd2d2)",
    "D 4 (#30e451)",
    "R 3 (#682c22)",
    "D 3 (#30e453)",
    "R 4 (#727be2)",
    "D 8 (#85b173)",
    "L 4 (#3a8c50)",
    "D 3 (#004a23)",
    "R 2 (#6eef60)",
    "D 3 (#92b8d3)",
    "R 5 (#bdb140)",
    "U 8 (#8500b3)",
    "R 5 (#2e42f2)",
    "D 8 (#531953)",
    "R 3 (#9358a2)",
    "D 5 (#14d4b3)",
    "R 6 (#b19aa2)",
    "D 8 (#14d4b1)",
    "R 8 (#3e0d32)",
    "U 8 (#274023)",
    "R 3 (#b2d1a2)",
    "U 3 (#274021)",
    "R 8 (#206d02)",
    "U 6 (#2d02d3)",
    "R 4 (#0bd782)",
    "U 3 (#483403)",
    "R 9 (#7d6fc0)",
    "U 5 (#717513)",
    "R 9 (#5e63a0)",
    "U 6 (#614071)",
    "R 6 (#6df500)",
    "U 9 (#6f14e1)",
    "R 5 (#9229d0)",
    "U 5 (#6f14e3)",
    "L 5 (#0993b0)",
    "U 4 (#614073)",
    "L 3 (#aad3a0)",
    "U 7 (#2aed13)",
    "L 7 (#117f30)",
    "U 8 (#b185d3)",
    "L 3 (#a39640)",
    "U 10 (#a408b1)",
    "L 5 (#1e31b0)",
    "U 4 (#5af491)",
    "L 3 (#43ff50)",
    "U 4 (#125121)",
    "R 5 (#2321b0)",
    "U 4 (#4a6de1)",
    "R 6 (#80c430)",
    "U 5 (#4a6de3)",
    "L 5 (#8fe3b0)",
    "U 4 (#483d91)",
    "R 8 (#012050)",
    "U 3 (#3730e1)",
    "R 5 (#d36d12)",
    "U 8 (#7d5761)",
    "R 7 (#d36d10)",
    "U 7 (#21b1c1)",
    "R 9 (#8ea5e2)",
    "U 7 (#602a01)",
    "R 8 (#aae3f2)",
    "U 5 (#8d2981)",
    "R 5 (#263f72)",
    "U 5 (#2a3471)",
    "R 7 (#263f70)",
    "U 2 (#88ea21)",
    "R 3 (#3f5f62)",
    "U 6 (#5e1cc1)",
    "R 5 (#adffb0)",
    "U 6 (#104941)",
    "R 5 (#073230)",
    "U 4 (#25be03)",
    "L 9 (#1a2fd0)",
    "U 5 (#3d1233)",
    "R 9 (#879540)",
    "U 4 (#5c9671)",
    "L 2 (#6ad9e0)",
    "U 8 (#5c9673)",
    "L 7 (#3bb750)",
    "U 3 (#3d1231)",
    "R 11 (#080ca0)",
    "U 4 (#25be01)",
    "R 4 (#50a100)",
    "U 5 (#163541)",
    "L 5 (#27ff80)",
    "U 3 (#ab8481)",
    "R 4 (#549890)",
    "U 7 (#010511)",
    "L 4 (#749c72)",
    "U 4 (#46cfe1)",
    "L 5 (#a03822)",
    "D 5 (#594361)",
    "L 2 (#12a9f0)",
    "D 9 (#509f91)",
    "L 3 (#c051f0)",
    "U 3 (#509f93)",
    "L 7 (#41d8b0)",
    "D 3 (#80af51)",
    "L 3 (#549892)",
    "D 9 (#29c701)",
    "L 5 (#58fe00)",
    "D 5 (#4ef833)",
    "R 5 (#4ad860)",
    "D 7 (#aa4b13)",
    "L 7 (#6d6810)",
    "D 8 (#774e21)",
    "L 6 (#631140)",
    "U 8 (#4c9b31)",
    "L 4 (#4a8a50)",
    "D 3 (#61b9d1)",
    "L 6 (#665fd0)",
    "D 5 (#4edd51)",
    "R 6 (#46f5d0)",
    "D 3 (#109bd1)",
    "L 6 (#896f50)",
    "D 5 (#3ab8e1)",
    "L 3 (#6f6ce0)",
    "D 4 (#5acd11)",
    "L 5 (#1d15b2)",
    "U 4 (#032e23)",
    "L 10 (#8d6c92)",
    "U 3 (#032e21)",
    "R 10 (#4e59f2)",
    "U 5 (#70a541)",
    "L 5 (#1102a0)",
    "U 8 (#8b66f1)",
    "L 5 (#871710)",
    "U 10 (#be4e51)",
    "R 3 (#871712)",
    "U 11 (#1182c1)",
    "R 3 (#1102a2)",
    "D 9 (#493441)",
    "R 8 (#7a6b80)",
    "D 4 (#c3daa1)",
    "R 3 (#8a38d0)",
    "U 3 (#07ac71)",
    "R 4 (#131b90)",
    "U 5 (#34c6e1)",
    "R 4 (#914cf2)",
    "U 5 (#0e9af1)",
    "R 3 (#6c62d2)",
    "U 3 (#3af801)",
    "L 6 (#0018c0)",
    "U 7 (#2b7361)",
    "L 4 (#55fb20)",
    "U 5 (#8a33c1)",
    "R 4 (#a79be0)",
    "U 4 (#59acf1)",
    "R 7 (#bb8240)",
    "D 5 (#77ca71)",
    "R 7 (#894bd0)",
    "U 5 (#a12ff1)",
    "R 3 (#437630)",
    "D 4 (#1dbba1)",
    "R 10 (#4c87b0)",
    "U 6 (#9ea131)",
    "R 2 (#4c87b2)",
    "U 4 (#19f7e1)",
    "L 11 (#85c770)",
    "U 4 (#220631)",
    "L 9 (#224540)",
    "U 5 (#d4ac83)",
    "L 4 (#421610)",
    "U 3 (#23ae63)",
    "L 9 (#8259c0)",
    "D 4 (#1b4b51)",
    "R 6 (#b84e80)",
    "D 11 (#9b8e41)",
    "L 6 (#29c310)",
    "D 4 (#9cba93)",
    "L 6 (#2e33e0)",
    "U 10 (#1d8b03)",
    "L 5 (#2578e2)",
    "U 7 (#0c7911)",
    "L 2 (#6112e2)",
    "U 2 (#0c7913)",
    "L 7 (#621cb2)",
    "D 8 (#4164f3)",
    "L 4 (#080dd2)",
    "U 11 (#574773)",
    "R 7 (#6ab252)",
    "U 3 (#4224b3)",
    "R 3 (#898930)",
    "U 2 (#c88f51)",
    "R 4 (#798b30)",
    "U 11 (#c88f53)",
    "R 4 (#585430)",
    "U 5 (#3832c3)",
    "R 3 (#4fee20)",
    "U 6 (#b69301)",
    "R 10 (#8cec10)",
    "U 8 (#bc9fd1)",
    "L 6 (#8cec12)",
    "U 2 (#5a1691)",
    "L 7 (#084160)",
    "U 7 (#164633)",
    "L 7 (#3cbba0)",
    "U 5 (#3e9073)",
    "R 8 (#9a4ce0)",
    "U 5 (#6202f3)",
    "R 4 (#133000)",
    "U 6 (#60c5f1)",
    "R 4 (#74b6b0)",
    "D 6 (#6ab6a1)",
    "R 4 (#25f5c0)",
    "U 6 (#9fac91)",
    "R 7 (#707bb2)",
    "U 7 (#d176c1)",
    "R 8 (#7ecfd2)",
    "D 3 (#348d21)",
    "R 4 (#582b12)",
    "D 3 (#583831)",
    "R 2 (#3cd532)",
    "D 8 (#583833)",
    "R 6 (#67b552)",
    "D 10 (#813bd1)",
    "R 2 (#1fe0d0)",
    "D 4 (#37af51)",
    "R 5 (#807980)",
    "D 4 (#37af53)",
    "R 6 (#6bfb10)",
    "D 4 (#48bf11)",
    "L 6 (#6d20d0)",
    "D 4 (#a44a91)",
    "L 5 (#020f30)",
    "D 10 (#270741)",
    "L 4 (#0e8270)",
    "D 9 (#a5d781)",
    "R 4 (#8f64c0)",
    "D 3 (#c06611)",
    "R 6 (#574250)",
    "U 10 (#7c7d13)",
    "R 5 (#c4e490)",
    "D 8 (#58a503)",
    "R 3 (#869e62)",
    "D 4 (#302873)",
    "R 4 (#716f60)",
    "D 2 (#96bdb3)",
    "R 9 (#579f30)",
    "D 6 (#3ae6d3)",
    "R 2 (#59c002)",
    "D 6 (#5f2243)",
    "R 6 (#6f4e92)",
    "D 2 (#5effd3)",
    "R 5 (#869e60)",
    "D 9 (#72a4c3)",
    "R 5 (#040640)",
    "U 3 (#4b1523)",
    "R 8 (#a6bc50)",
    "U 8 (#363643)",
    "R 7 (#897d90)",
    "D 4 (#5f6cc1)",
    "R 7 (#3cb430)",
    "D 8 (#431931)",
    "R 6 (#5ec560)",
    "D 7 (#1f9831)",
    "R 5 (#8ff6c0)",
    "D 4 (#4efe31)",
    "R 7 (#5b1802)",
    "D 2 (#645e71)",
    "R 8 (#5b1800)",
    "D 7 (#271021)",
    "L 4 (#749b40)",
    "D 3 (#a6a101)",
    "L 2 (#40cd30)",
    "D 10 (#210bc1)",
    "L 3 (#70fd00)",
    "U 10 (#8095f1)",
    "L 3 (#1db8e0)",
    "U 3 (#969461)",
    "L 3 (#80ea40)",
    "D 4 (#0d9f41)",
    "L 8 (#47fc40)",
    "U 5 (#0a7ed1)",
    "L 5 (#2dc420)",
    "D 5 (#6614d1)",
    "L 5 (#499120)",
    "D 5 (#2dedd1)",
    "L 5 (#7eb2c0)",
    "D 3 (#0b4331)",
    "L 7 (#075d50)",
    "D 4 (#9357e1)",
    "L 5 (#196f62)",
    "D 7 (#6148d1)",
    "L 4 (#49cc32)",
    "U 8 (#1074b1)",
    "L 2 (#0f1812)",
    "U 6 (#448f53)",
    "L 5 (#3a2852)",
    "D 6 (#4a85a3)",
    "L 3 (#a83322)",
    "U 7 (#4a85a1)",
    "L 6 (#152012)",
    "D 7 (#827293)",
    "L 3 (#24bbe2)",
    "D 3 (#c701e1)",
    "R 12 (#15c452)",
    "D 5 (#a53e01)",
    "L 3 (#4aab42)",
    "D 4 (#a7ac61)",
    "L 11 (#635062)",
    "D 4 (#6bb071)",
    "L 2 (#03e0b2)",
    "D 6 (#6a9ce1)",
    "R 5 (#6052d2)",
    "D 4 (#5a3341)",
    "L 5 (#314be2)",
    "D 4 (#26e621)",
    "L 5 (#945112)",
    "D 3 (#9612d1)",
    "R 4 (#20d072)",
    "D 6 (#0714d1)",
    "R 6 (#a00062)",
    "D 5 (#22f091)",
    "R 10 (#3f49c0)",
    "D 2 (#4aa3f1)",
    "R 7 (#030530)",
    "D 9 (#115f21)",
    "R 2 (#363192)",
    "D 3 (#40b6f1)",
    "L 7 (#b66fa2)",
    "D 2 (#642471)",
    "L 4 (#195292)",
    "D 10 (#38e091)",
    "L 8 (#cfc230)",
    "D 9 (#1acfc1)",
    "R 3 (#363190)",
    "D 3 (#579531)",
    "R 6 (#030532)",
    "D 8 (#17df01)",
    "R 2 (#3f49c2)",
    "D 5 (#13eb81)",
    "R 9 (#c0d0d0)",
    "D 7 (#3d1a81)",
    "R 8 (#2cf6a2)",
    "U 7 (#990ba1)",
    "R 2 (#280182)",
    "U 12 (#151693)",
    "R 6 (#6a9612)",
    "D 7 (#151691)",
    "R 10 (#833942)",
    "D 2 (#990ba3)",
    "R 4 (#0aa312)",
    "D 4 (#74b4b1)",
    "L 5 (#9cefb2)",
    "D 3 (#0aebc3)",
    "L 9 (#7d2300)",
    "D 3 (#bae673)",
    "R 8 (#7d2302)",
    "D 5 (#6b2643)",
    "R 4 (#1ad422)",
    "D 12 (#a511e3)",
    "R 4 (#640b02)",
    "U 4 (#bace03)",
    "R 5 (#812422)",
    "U 5 (#128b13)",
    "R 8 (#3d8f62)",
    "U 6 (#cd5893)",
    "R 11 (#802072)",
    "D 6 (#30e411)",
    "R 5 (#8985a2)",
    "D 4 (#217371)",
    "R 5 (#5fb102)",
    "U 7 (#76cd11)",
    "R 4 (#019092)",
    "D 7 (#764f53)",
    "R 7 (#1991f2)",
    "D 5 (#200673)",
    "R 3 (#c4df72)",
    "D 2 (#12fbe3)",
    "R 10 (#239232)",
    "D 4 (#2d6823)",
    "L 4 (#2bbfc0)",
    "D 11 (#58adf3)",
    "L 4 (#2bbfc2)",
    "D 5 (#5d0073)",
    "L 4 (#34b482)",
    "D 5 (#bfb221)",
    "L 5 (#05eac2)",
    "D 8 (#84cb91)",
    "L 5 (#05eac0)",
    "U 11 (#47ea71)",
    "L 3 (#2ffbb2)",
    "U 7 (#0968c3)",
    "L 7 (#2a09e2)",
    "U 11 (#382063)",
    "L 5 (#523622)",
    "D 10 (#502c23)",
    "L 2 (#22a8e0)",
    "D 6 (#4f68e3)",
    "L 3 (#22a8e2)",
    "U 11 (#5f7063)",
    "L 3 (#61a142)",
    "U 6 (#90dcc1)",
    "L 4 (#8ee7b2)",
    "D 4 (#a3c391)",
    "L 9 (#8ee7b0)",
    "D 5 (#028571)",
    "R 9 (#aea642)",
    "D 4 (#0780f3)",
    "L 2 (#9eb382)",
    "D 4 (#090683)",
    "L 6 (#7f5882)",
    "D 3 (#cbd233)",
    "L 4 (#3ef000)",
    "D 2 (#5a4be3)",
    "L 7 (#572c50)",
    "D 8 (#c3b7a1)",
    "L 5 (#7c8430)",
    "U 8 (#c3b7a3)",
    "L 3 (#1c43d0)",
    "U 2 (#944203)",
    "L 7 (#89b852)",
    "D 10 (#128611)",
    "L 8 (#25a0b2)",
    "D 6 (#128613)",
    "R 4 (#7f8b52)",
    "D 3 (#3836c3)",
    "R 6 (#b96892)",
    "D 5 (#59a813)",
    "R 4 (#671590)",
    "U 4 (#108741)",
    "R 4 (#c47fa0)",
    "D 4 (#108743)",
    "R 5 (#abdf60)",
    "D 5 (#7f8903)",
    "R 6 (#c5fd02)",
    "D 5 (#0fe7a3)",
    "L 6 (#62c892)",
    "D 3 (#95f933)",
    "L 11 (#b77762)",
    "D 3 (#a0bff3)",
    "R 6 (#444872)",
    "D 6 (#730533)",
    "R 4 (#295162)",
    "U 6 (#a27af3)",
    "R 5 (#b41db2)",
    "D 4 (#5df303)",
    "R 2 (#c1a730)",
    "D 3 (#39f573)",
    "R 5 (#000ef0)",
    "D 3 (#593163)",
    "L 8 (#2a99b0)",
    "D 6 (#5a9631)",
    "L 5 (#0326a0)",
    "D 3 (#767951)",
    "L 5 (#d43c00)",
    "D 4 (#1ebf01)",
    "L 5 (#300a00)",
    "D 4 (#0cd251)",
    "L 2 (#101d60)",
    "D 5 (#6b6901)",
    "L 10 (#bbfbb0)",
    "D 8 (#5c6c61)",
    "L 6 (#cc1912)",
    "D 10 (#4b0fb1)",
    "L 8 (#5935a0)",
    "D 7 (#37a1e1)",
    "L 4 (#c146d0)",
    "D 10 (#104103)",
    "L 7 (#6fc450)",
    "D 8 (#2c8903)",
    "L 4 (#44bce0)",
    "D 5 (#88eba3)",
    "L 4 (#44bce2)",
    "D 2 (#3e5c83)",
    "L 8 (#1dd540)",
    "D 5 (#102cb3)",
    "R 3 (#41e720)",
    "D 7 (#5d8523)",
    "R 5 (#83e9d0)",
    "U 5 (#518603)",
    "R 3 (#125412)",
    "U 4 (#35aee3)",
    "R 4 (#125410)",
    "D 5 (#4e2ef3)",
    "R 8 (#1c9c60)",
    "D 4 (#593161)",
    "R 3 (#103c30)",
    "D 7 (#5b8993)",
    "R 6 (#9eac70)",
    "D 8 (#435fb3)",
    "L 8 (#894ad0)",
    "D 3 (#8ae413)",
    "L 4 (#51f0e2)",
    "D 9 (#755d61)",
    "L 5 (#a55d12)",
    "D 4 (#755d63)",
    "R 5 (#1c6f72)",
    "D 3 (#1332b3)",
    "R 12 (#1439e2)",
    "D 3 (#5c1e03)",
    "R 6 (#685ab2)",
    "D 3 (#844351)",
    "L 7 (#a8c6b2)",
    "D 5 (#13b3f1)",
    "L 3 (#2af6d2)",
    "D 7 (#3b43d1)",
    "L 4 (#7f2e72)",
    "D 7 (#a19111)",
    "L 3 (#aa2540)",
    "U 4 (#5009a1)",
    "L 3 (#ac9422)",
    "U 10 (#1e4901)",
    "L 3 (#0ac0b2)",
    "D 5 (#75dc13)",
    "L 4 (#810712)",
    "U 5 (#50e203)",
    "L 5 (#6bafe2)",
    "U 7 (#8b0a43)",
    "R 6 (#6bafe0)",
    "U 4 (#13f013)",
    "L 6 (#810710)",
    "U 7 (#7d6663)",
    "L 6 (#cfc8c2)",
    "D 8 (#13b173)",
    "L 6 (#3e6882)",
    "D 5 (#c7c4a3)",
    "L 11 (#09a232)",
    "U 5 (#a8a233)",
    "L 5 (#8e1632)",
    "D 6 (#5cd3d1)",
    "L 4 (#a044c2)",
    "U 7 (#a688e1)",
    "L 3 (#8e58f2)",
    "U 5 (#091d61)",
    "L 5 (#7dd0b2)",
    "U 7 (#0ac043)",
    "L 7 (#9e5aa2)",
    "U 3 (#9f9d63)",
    "L 12 (#8d64d2)",
    "U 4 (#1df793)",
    "L 4 (#0189e2)",
    "U 4 (#4424e3)",
    "L 10 (#02fe02)",
    "U 7 (#71b7d3)"
};

class item {
public:
    item(const string _input)
        : input(_input)
    {
        vector<string> tokens(stringtovector(input, ' '));
        dir = tokens[0][0];
        steps = stol(tokens[1]);
        rgb = tokens[2].substr(2, 6);
    }

    void parseRGB()
    {
        steps = hextoint(rgb.substr(0, rgb.size() - 1));
        switch (rgb[5]) {
        case '0':
            dir = 'R';
            break;
        case '1':
            dir = 'D';
            break;
        case '2':
            dir = 'L';
            break;
        case '3':
            dir = 'U';
            break;
        default:
            cout << "Illegal rgb value: " << rgb << endl;
            break;
        }
    }

    string getString() { return input; }

    friend bool operator<(const item& l, const item& r)
    {
        return l.input < r.input;
    }

private:
    string input;

    char dir;
    long steps;
    string rgb;

    friend class LavaductLagoon;
};

class LavaductLagoon {
public:
    LavaductLagoon(const vector<string>& _input)
        : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input)
            items.push_back(item(elem));
    }

    long long dig()
    {
        long long count = 0;
        long row = 0, col = 0;
        for (auto i : items) {
            for (int j = 0; j < i.steps; ++j) {
                switch (i.dir) {
                case 'U':
                    --row;
                    break;
                case 'D':
                    ++row;
                    break;
                case 'L':
                    --col;
                    break;
                case 'R':
                    ++col;
                    break;

                default:
                    break;
                }
                if (trench[{ row, col }] == '#')
                    cout << "Kollision" << endl;
                trench[{ row, col }] = '#';
                ++count;
            }
        }
        return count;
    }
    /*
    long long dig()
    {
        long long count = 0;
        long row = 0, col = 0;
        for (auto i : items) {
            switch (i.dir) {
            case 'U':
                for (int j = 0; j < i.steps; ++j) {
                    --row;
                    trench[{ row, col }] = '#';
                    ++count;
                }
                break;
            case 'D':
                for (int j = 0; j < i.steps; ++j) {
                    ++row;
                    trench[{ row, col }] = '#';
                    ++count;
                }
                break;
            case 'L':
                col -= i.steps;
                count -= i.steps;
                trench[{ row, col }] = '#';
                break;
            case 'R':
                col += i.steps;
                count += i.steps;
                trench[{ row, col }] = '#';
                break;
            default:
                break;
            }
        }

        cout << "Digged: " << count << endl;

        return count;
    }*/

    long long fillTrench()
    {
        long long countrow = 0;

        map<long, set<long>> rowcounter;
        for (auto e : trench)
            rowcounter[e.first.first].insert(e.first.second);

        //vector<pair<long, long>> fillpoints;

        for (auto e : rowcounter) {
            // Count elements in Row

            /* if (e.second.size() == 2) {
                auto iter = e.second.begin();
                long l = *iter;
                ++iter;
                long r = *iter;

                if (r - l > 1)
                    fillpoints.push_back({ e.first, l + 1 });
            } */

            long long lws = LONG_LONG_MAX; // Left Wall Start
            long long lwe = LONG_LONG_MAX; // Left Wall End
            long long rws = LONG_LONG_MAX; // Right Wall Start
            long long rwe = LONG_LONG_MAX; // Right Wall End

            for (auto rc : e.second) {
                if (LONG_LONG_MAX == lws) {
                    lws = rc;
                    lwe = rc;
                } else {
                    if (lwe + 1 == rc) {
                        lwe = rc;
                    } else {
                        if (LONG_LONG_MAX == rws) {
                            rws = rc;
                            rwe = rc;
                        } else if (rwe + 1 == rc) {
                            rwe = rc;
                        } else {
                            // Now it counts....
                            countrow = rwe - lws + 1;
                            lws = LONG_LONG_MAX;
                            lwe = LONG_LONG_MAX;
                            rws = LONG_LONG_MAX;
                            rwe = LONG_LONG_MAX;
                        }
                    }
                }
            }

            // Count final element
            if ( LONG_LONG_MAX == rws )
                countrow += lwe - lws + 1;
            else
                countrow += rwe - lws +1;
        }

        /* 
        while (fillpoints.size()) {
            pair<long, long> fillpoint(fillpoints.back());
            fillpoints.pop_back();

            if ('#' != trench[{ fillpoint.first, fillpoint.second }] && '*' != trench[{ fillpoint.first, fillpoint.second }]) {
                trench[{ fillpoint.first, fillpoint.second }] = '*';
                fillpoints.push_back({ fillpoint.first - 1, fillpoint.second });
                fillpoints.push_back({ fillpoint.first + 1, fillpoint.second });
                fillpoints.push_back({ fillpoint.first, fillpoint.second - 1 });
                fillpoints.push_back({ fillpoint.first, fillpoint.second + 1 });
            }
        } */

        return countrow;
    }

    long countTrench()
    {
        long c = 0;
        for (auto t : trench)
            ++c;

        return c;
    }

    long getResultA()
    {
        trench.clear();
        count = dig();
        fillTrench();

        long resultA = countTrench();

        cout << "resultA: " << resultA << endl;
        return resultA;
    }

    long getResultB()
    {
        trench.clear();
        for (auto& e : items)
            e.parseRGB();

        count == dig();
        fillTrench();

        long resultB = countTrench();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    vector<item> items;
    map<pair<long, long>, char> trench;
    long long count;
};

TEST_CASE("Testdata")
{
    LavaductLagoon LavaductLagoonData(inputTestdata);
    REQUIRE(62 == LavaductLagoonData.getResultA());
    REQUIRE(0 == LavaductLagoonData.getResultB());
}

TEST_CASE("LavaductLagoon")
{
    LavaductLagoon LavaductLagoonData(inputData);
    REQUIRE(49897 == LavaductLagoonData.getResultA());
    REQUIRE(0 == LavaductLagoonData.getResultB());
}