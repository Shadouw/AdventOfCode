#include <iostream>
#include <string>
#include <vector>

#include <stringtovector.h>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "0 3 6 9 12 15",
    "1 3 6 10 15 21",
    "10 13 16 21 30 45"
};

const vector<string> inputData = {
    "14 26 47 96 208 446 930 1893 3779 7407 14241 26832 49537 89675 159354 278299 478132 808704 1347259 2211424 3577270",
    "11 35 81 158 275 441 665 956 1323 1775 2321 2970 3731 4613 5625 6776 8075 9531 11153 12950 14931",
    "18 27 40 59 81 91 50 -122 -568 -1521 -3336 -6527 -11809 -20145 -32798 -51388 -77954 -115021 -165672 -233625 -323315",
    "7 10 19 34 55 82 115 154 199 250 307 370 439 514 595 682 775 874 979 1090 1207",
    "11 32 70 137 253 449 772 1300 2190 3797 6927 13359 26967 56231 119897 259515 566513 1239226 2700380 5834113 12454133",
    "5 20 64 149 285 480 740 1069 1469 1940 2480 3085 3749 4464 5220 6005 6805 7604 8384 9125 9805",
    "7 28 64 127 256 545 1192 2577 5377 10726 20428 37231 65170 109987 179636 284881 439995 663568 979432 1417711 2016004",
    "-2 -3 -4 -5 -6 -7 -8 -9 -10 -11 -12 -13 -14 -15 -16 -17 -18 -19 -20 -21 -22",
    "18 45 90 155 249 397 664 1212 2414 5058 10686 22128 44309 85428 158632 284335 493362 831131 1363122 2181921 3416169",
    "10 14 9 5 21 93 304 858 2242 5556 13150 29813 64971 136807 280216 562651 1116306 2203618 4348835 8596161 17001841",
    "21 41 85 180 374 742 1405 2583 4714 8699 16393 31574 61822 122106 241587 476607 935964 1831346 3580258 7018773 13841427",
    "5 2 6 30 95 234 491 915 1554 2457 3703 5523 8713 15826 34179 82647 205703 500400 1165216 2584176 5465751",
    "24 36 60 106 187 320 521 806 1235 2077 4242 10247 26211 65806 157892 361020 790614 1669390 3420164 6835692 13387759",
    "27 36 43 64 142 360 868 1954 4203 8802 18064 36259 70860 134374 247150 442223 774975 1344404 2341497 4158158 7625686",
    "3 26 65 124 213 352 591 1063 2089 4356 9191 18956 37591 71334 129649 226395 381271 621574 984309 1518692 2289089",
    "14 11 19 50 128 315 763 1807 4114 8903 18251 35500 65780 116663 198963 327697 523222 812563 1230947 1823558 2647528",
    "7 25 55 96 147 207 275 350 431 517 607 700 795 891 987 1082 1175 1265 1351 1432 1507",
    "4 20 52 102 172 264 380 522 692 892 1124 1390 1692 2032 2412 2834 3300 3812 4372 4982 5644",
    "12 12 26 79 205 448 871 1577 2742 4665 7868 13347 23205 42121 80471 160487 327720 671410 1359366 2695903 5215645",
    "0 -5 -19 -42 -56 -11 190 707 1780 3747 7063 12320 20268 31837 48160 70597 100760 140539 192129 258058 341216",
    "-2 -8 -4 20 70 145 240 357 523 807 1311 2072 2738 1758 -5346 -29249 -92392 -237526 -539350 -1117924 -2149630",
    "-5 -10 -11 8 77 246 598 1278 2554 4945 9495 18359 36020 71695 143811 287798 568801 1101338 2079037 3821332 6855171",
    "4 3 21 80 211 461 917 1759 3353 6408 12262 23439 44729 85167 161385 302817 559054 1009141 1771607 3012302 4944411",
    "22 34 50 86 170 359 784 1749 3934 8783 19198 40724 83538 165840 319898 603491 1122806 2079904 3872226 7299442 13984490",
    "23 30 48 88 163 300 570 1157 2507 5632 12710 28259 61453 130759 273345 564318 1156141 2359172 4805190 9776416 19859989",
    "-8 -12 -15 -17 -18 -18 -17 -15 -12 -8 -3 3 10 18 27 37 48 60 73 87 102",
    "12 14 23 45 102 247 580 1269 2578 4894 8728 14643 23033 33638 44646 51286 44214 9398 -64873 -158619 -131618",
    "11 17 25 37 50 57 63 140 567 2132 6711 18277 44524 99329 206393 404850 759118 1379591 2472170 4462351 8302561",
    "20 30 52 106 228 481 966 1833 3292 5624 9192 14452 21964 32403 46570 65403 89988 121570 161564 211566 273364",
    "19 35 62 100 148 202 264 372 654 1399 3129 6654 13105 23978 41297 68130 109885 177091 290752 491872 857410",
    "26 53 92 147 230 362 569 880 1356 2228 4324 10158 26391 68939 172950 411497 929690 2005975 4161296 8352141 16309216",
    "14 28 53 109 222 414 702 1129 1859 3378 6861 14805 32108 67918 138842 274682 529326 1003298 1894435 3617291 7086724",
    "0 10 48 129 283 568 1090 2035 3720 6689 11927 21355 38926 72920 140574 277328 555542 1123404 2287945 4694976 9719897",
    "6 12 20 37 75 160 354 801 1812 4008 8543 17429 33981 63405 113625 196746 332414 556348 941370 1645501 3013355",
    "17 23 29 35 41 47 53 59 65 71 77 83 89 95 101 107 113 119 125 131 137",
    "13 27 50 83 129 193 298 531 1133 2647 6138 13499 27857 54093 99490 174523 293805 477203 751138 1150083 1718273",
    "28 43 58 73 88 103 118 133 148 163 178 193 208 223 238 253 268 283 298 313 328",
    "11 9 4 -6 -32 -95 -222 -437 -733 -973 -600 2069 11356 37240 101235 247946 568267 1246553 2656208 5549892 11427768",
    "25 46 78 121 175 240 316 403 501 610 730 861 1003 1156 1320 1495 1681 1878 2086 2305 2535",
    "17 28 57 125 276 592 1206 2313 4189 7247 12190 20366 34490 59973 107187 195096 356793 647598 1156487 2021731 3451720",
    "24 45 84 157 299 582 1135 2162 3951 6861 11277 17571 26268 39002 61652 112657 242756 579095 1420548 3439575 8102595",
    "21 38 57 74 91 122 210 467 1155 2840 6683 15001 32365 67738 138540 278114 548921 1064986 2028733 3789476 6933575",
    "8 19 49 99 166 247 345 489 795 1610 3796 9226 21579 47536 98494 192930 359562 641469 1101347 1828093 2944924",
    "13 32 68 127 228 417 781 1462 2671 4702 7946 12905 20206 30615 45051 64600 90529 124300 167584 222275 290504",
    "13 23 35 45 59 104 245 624 1547 3653 8200 17500 35563 69181 130275 241965 454837 889032 1837669 4008880 9069103",
    "13 18 24 33 50 93 221 590 1552 3829 8843 19391 41067 85240 175168 358274 730288 1481876 2987401 5972131 11825257",
    "14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34",
    "8 28 71 152 288 498 803 1226 1792 2528 3463 4628 6056 7782 9843 12278 15128 18436 22247 26608 31568",
    "2 -3 -2 20 86 241 589 1370 3115 6958 15253 32753 68782 141126 282900 554641 1065785 2013448 3754005 6938327 12772443",
    "8 8 -1 -29 -91 -197 -333 -435 -345 303 2402 8180 23048 59530 145226 338410 757762 1637618 3428041 6971393 13805807",
    "25 40 71 134 245 417 659 984 1442 2209 3797 7534 16663 38852 91816 215490 497315 1122518 2469919 5287326 11001021",
    "24 36 54 96 192 399 831 1704 3396 6522 12024 21276 36204 59421 94377 145524 218496 320304 459546 646632 894024",
    "-5 -3 0 5 27 110 355 969 2345 5199 10832 21665 42319 81683 156661 298762 565880 1064795 1998131 3769177 7221916",
    "20 39 64 88 98 79 29 -13 69 503 1659 4090 8641 16751 31174 57485 106922 201351 381434 719436 1338532",
    "9 26 43 56 69 113 292 872 2425 6031 13527 27773 52881 94324 158808 253751 386169 560720 776603 1022950 1272285",
    "-2 -6 -8 10 86 287 734 1656 3486 7012 13596 25474 46150 80897 137378 226400 362814 566574 863968 1289034 1885174",
    "-6 -7 3 42 139 350 790 1683 3432 6711 12581 22632 39153 65332 105488 165337 252294 375813 547767 782870 1099143",
    "10 12 25 75 201 455 898 1591 2587 3943 5792 8557 13497 24070 49367 112747 273115 675713 1669042 4064338 9691456",
    "11 11 22 47 90 164 314 668 1529 3521 7802 16357 32384 60786 108782 186650 308615 493895 767918 1163723 1723558",
    "12 12 22 61 149 303 533 838 1202 1590 1944 2179 2179 1793 831 -940 -3800 -8080 -14166 -22503 -33599",
    "6 29 65 123 230 439 837 1553 2766 4713 7697 12095 18366 27059 38821 54405 74678 100629 133377 174179 224438",
    "-5 2 13 22 19 -10 -82 -207 -352 -353 260 2569 8758 22849 51755 106730 205305 373808 650575 1089968 1767325",
    "25 43 75 135 246 440 764 1306 2262 4070 7648 14810 29044 57125 112717 224571 454763 937541 1958001 4103569 8542006",
    "20 27 29 18 -21 -116 -301 -571 -753 -215 2708 11746 34424 84806 187656 384517 742318 1365239 2410695 4110442 6797961",
    "28 56 113 214 387 685 1205 2128 3805 6925 12813 23938 44815 83763 156604 294617 561270 1085954 2128813 4199674 8267127",
    "3 11 19 27 35 43 51 59 67 75 83 91 99 107 115 123 131 139 147 155 163",
    "16 22 25 25 22 16 7 -5 -20 -38 -59 -83 -110 -140 -173 -209 -248 -290 -335 -383 -434",
    "17 46 92 156 243 380 643 1200 2393 4915 10199 21248 44360 92691 193674 404589 845141 1764532 3675990 7618200 15646565",
    "5 23 62 139 281 543 1047 2052 4068 8043 15704 30263 57977 111583 217564 430738 862051 1729007 3443254 6756899 12998645",
    "5 6 13 33 83 196 431 902 1858 3872 8237 17722 37904 79344 160881 314223 589739 1062794 1838981 3055015 4869649",
    "21 39 72 145 299 592 1106 1971 3418 5879 10177 17908 32225 59414 111963 214427 414671 805855 1570414 3069167 6021443",
    "12 22 39 81 189 449 1030 2249 4676 9302 17822 33142 60321 108356 193645 346944 627879 1156029 2178028 4211058 8343188",
    "2 9 41 110 239 484 980 2034 4304 9141 19249 39957 81621 164010 324008 628617 1196110 2229297 4066273 7255760 12666283",
    "11 20 50 118 251 485 866 1458 2363 3758 5954 9482 15211 24503 39410 62918 99243 154184 235538 353582 521627",
    "7 -2 -16 -38 -68 -102 -139 -199 -356 -796 -1911 -4410 -9318 -17446 -27227 -28206 16213 211334 830958 2541314 6883432",
    "25 34 44 63 109 217 445 873 1582 2600 3823 4993 6005 8235 18431 58333 186163 541390 1433202 3508147 8056737",
    "22 31 55 107 200 354 617 1108 2089 4072 7966 15268 28301 50501 86754 143783 230584 358909 543793 804121 1163230",
    "-4 1 20 61 138 273 495 836 1324 1973 2770 3659 4522 5157 5253 4362 1868 -3047 -11440 -24647 -44326",
    "26 51 98 174 298 523 971 1896 3796 7611 15084 29440 56668 107887 203553 380634 704358 1286739 2314822 4092474 7100598",
    "28 52 98 193 377 697 1196 1897 2782 3766 4666 5165 4771 2771 -1820 -10315 -24416 -46280 -78590 -124631 -188371",
    "3 11 24 61 165 425 1023 2315 4948 10006 19169 34862 60368 99882 158494 242110 357353 511533 712838 970979 1298623",
    "5 15 53 147 346 734 1449 2700 4766 7957 12530 18600 26207 36006 51812 88055 189285 477498 1260375 3266770 8137126",
    "4 7 13 23 52 140 362 836 1741 3392 6491 12809 26807 59168 134039 303207 672818 1452161 3040389 6177303 12200838",
    "-8 -3 22 78 175 320 517 781 1199 2112 4564 11295 28799 71422 169312 383553 834506 1753964 3579140 7117715 13828691",
    "25 33 33 19 -10 -46 -75 -91 -116 -205 -381 -359 1302 9515 38559 126226 365970 976291 2443528 5803537 13177521",
    "26 41 56 71 86 101 116 131 146 161 176 191 206 221 236 251 266 281 296 311 326",
    "0 4 10 24 63 170 440 1058 2350 4848 9370 17116 29781 49686 79928 124550 188732 279004 403482 572128 797035",
    "4 3 6 14 22 25 43 170 654 2033 5393 12885 28748 61258 126333 254163 501624 976195 1883076 3618592 6953490",
    "22 33 42 43 44 97 343 1086 2929 7033 15611 32876 66900 133364 263271 518834 1025692 2036469 4052068 8045173 15858136",
    "18 30 39 49 73 146 364 977 2576 6439 15166 33887 72656 151295 309176 624662 1252945 2498224 4949126 9729671 18960358",
    "10 26 62 127 223 344 474 591 705 997 2198 6470 19248 52808 132800 309727 678524 1411248 2810806 5398157 10052261",
    "9 24 48 88 157 282 528 1047 2177 4658 10117 22122 48348 104795 223662 467634 955421 1907256 3726322 7145624 13494603",
    "2 1 10 48 139 312 601 1045 1688 2579 3772 5326 7305 9778 12819 16507 20926 26165 32318 39484 47767",
    "14 26 53 104 199 384 750 1457 2783 5252 9944 19154 37646 74842 148395 289719 552188 1022870 1838831 3209228 5444609",
    "17 16 25 67 174 387 756 1340 2207 3434 5107 7321 10180 13797 18294 23802 30461 38420 47837 58879 71722",
    "4 6 24 75 184 389 759 1450 2843 5837 12411 26626 56327 115965 231261 446985 840062 1541700 2774406 4912701 8580026",
    "9 26 64 127 219 343 497 667 817 876 722 163 -1085 -3423 -7397 -13729 -23351 -37442 -57468 -85225 -122885",
    "18 47 94 168 291 509 904 1620 2941 5492 10671 21464 43866 89277 178551 348989 666692 1248617 2301796 4191988 7561173",
    "25 47 95 183 325 535 827 1215 1713 2335 3095 4007 5085 6343 7795 9455 11337 13455 15823 18455 21365",
    "9 22 35 48 61 74 87 100 113 126 139 152 165 178 191 204 217 230 243 256 269",
    "16 26 40 58 80 106 136 170 208 250 296 346 400 458 520 586 656 730 808 890 976",
    "14 18 23 30 40 54 73 98 130 170 219 278 348 430 525 634 758 898 1055 1230 1424",
    "22 47 87 152 259 441 761 1333 2355 4160 7307 12792 22603 41153 78748 159440 337800 732977 1594851 3427508 7211535",
    "26 46 78 143 272 515 964 1789 3288 5964 10671 18936 33722 61281 115612 228819 474022 1013362 2193352 4725041 10009284",
    "23 47 81 125 179 243 317 401 495 599 713 837 971 1115 1269 1433 1607 1791 1985 2189 2403",
    "19 44 86 153 270 505 1009 2065 4147 8013 14899 26953 48180 86441 157631 294374 563979 1104929 2199278 4412142 8851878",
    "27 42 71 143 303 613 1153 2035 3460 5871 10286 18936 36386 71384 139766 268846 503841 917024 1620465 2783413 4655593",
    "24 41 73 128 210 319 451 598 748 885 989 1036 998 843 535 34 -704 -1727 -3087 -4840 -7046",
    "-7 -15 -19 -17 -12 2 68 308 979 2543 5751 11741 22150 39240 66038 106490 165629 249757 366641 525723 738344",
    "7 12 36 98 227 462 852 1456 2343 3592 5292 7542 10451 14138 18732 24372 31207 39396 49108 60522 73827",
    "11 25 48 89 153 236 320 368 319 83 -464 -1485 -3187 -5826 -9712 -15214 -22765 -32867 -46096 -63107 -84639",
    "8 14 30 79 187 374 638 927 1094 828 -455 -3799 -11053 -25524 -53195 -104919 -200212 -373550 -684440 -1232997 -2183333",
    "9 28 53 84 121 164 213 268 329 396 469 548 633 724 821 924 1033 1148 1269 1396 1529",
    "15 29 58 121 257 543 1139 2382 4963 10251 20886 41850 82327 158757 299574 552284 994087 1748873 3017478 5136931 8701877",
    "-7 -1 11 31 77 197 481 1072 2181 4129 7487 13484 25034 49038 101091 214393 455493 950327 1924467 3760853 7075295",
    "-5 -6 -7 -8 -9 -10 -11 -12 -13 -14 -15 -16 -17 -18 -19 -20 -21 -22 -23 -24 -25",
    "-7 -8 -10 0 61 264 808 2102 4937 10772 22217 43862 83713 155717 284373 513702 925934 1682313 3113525 5917809 11583494",
    "2 0 -7 -16 -12 38 191 534 1190 2324 4149 6932 11000 16746 24635 35210 49098 67016 89777 118296 153596",
    "13 21 32 55 115 259 562 1133 2121 3721 6180 9803 14959 22087 31702 44401 60869 81885 108328 141183 181547",
    "9 18 48 119 260 518 978 1794 3234 5749 10092 17559 30554 54009 98935 190916 389291 828028 1798244 3906903 8369100",
    "8 22 51 103 183 293 432 596 778 968 1153 1317 1441 1503 1478 1338 1052 586 -97 -1037 -2277",
    "6 16 50 134 314 659 1265 2265 3848 6287 9984 15580 24280 38746 65263 118441 230546 468730 965038 1966202 3912990",
    "16 39 76 132 223 384 673 1171 1978 3205 4962 7342 10401 14134 18447 23125 27796 31891 34600 34824 31123",
    "10 17 28 46 90 208 501 1174 2638 5695 11846 23770 46030 86070 155575 272274 462274 763021 1226992 1926230 2957842",
    "20 36 67 120 206 358 672 1395 3112 7132 16249 36172 78103 163236 330419 648963 1239736 2309436 4205547 7503272 13141120",
    "16 33 53 67 61 16 -78 -183 -129 558 3009 9739 26128 63370 144182 313540 658314 1342251 2666789 5174343 9819879",
    "13 17 21 40 106 272 616 1245 2299 3955 6431 9990 14944 21658 30554 42115 56889 75493 98617 127028 161574",
    "10 20 41 94 213 464 978 2003 3981 7668 14348 26259 47469 85632 155317 283877 520928 952044 1715507 3016640 5125441",
    "-4 -6 -2 16 72 221 564 1263 2556 4772 8346 13834 21928 33471 49472 71121 99804 137118 184886 245172 320296",
    "0 4 13 33 74 157 326 671 1375 2805 5674 11308 22059 41912 77341 138476 240650 406402 668019 1070707 1676488",
    "16 34 66 125 241 471 903 1663 2947 5109 8845 15534 27854 50938 94712 179032 345723 687730 1419893 3047749 6758676",
    "6 28 60 100 153 244 445 932 2108 4860 11071 24608 53201 111996 230261 464071 920475 1804042 3507549 6790264 13129978",
    "7 29 68 130 237 445 877 1780 3613 7175 13792 25618 46221 81943 145280 263148 496108 980618 2017113 4245291 8979258",
    "9 11 15 16 20 72 300 982 2645 6215 13280 26652 51702 99534 194211 388433 796263 1659636 3481287 7287877 15148046",
    "-1 11 34 73 133 216 318 441 648 1204 2865 7406 18542 43561 96420 204128 420762 859094 1761789 3658468 7702212",
    "12 34 72 130 208 309 449 678 1131 2146 4523 10069 22697 50543 109858 231849 474214 939874 1806386 3370764 6115982",
    "19 23 27 31 35 39 43 47 51 55 59 63 67 71 75 79 83 87 91 95 99",
    "3 6 16 37 73 128 206 311 447 618 828 1081 1381 1732 2138 2603 3131 3726 4392 5133 5953",
    "4 3 15 53 130 259 453 725 1088 1555 2139 2853 3710 4723 5905 7269 8828 10595 12583 14805 17274",
    "19 38 64 107 192 361 683 1285 2434 4725 9470 19464 40478 84190 173982 356414 723833 1458723 2920749 5818959 11557206",
    "-4 -9 -15 -24 -29 -2 119 461 1296 3215 7455 16452 34707 70066 135529 251717 450140 777423 1300661 2114088 3347259",
    "24 41 63 89 123 187 352 805 1986 4859 11425 25635 54903 112442 220659 415917 755333 1327550 2273056 3828714 6431712",
    "10 14 25 52 112 230 439 780 1302 2062 3125 4564 6460 8902 11987 15820 20514 26190 32977 41012 50440",
    "5 9 30 88 223 518 1132 2343 4601 8591 15306 26130 42931 68164 104984 157369 230253 329669 462902 638652 867207",
    "-4 8 35 77 134 206 293 395 512 644 791 953 1130 1322 1529 1751 1988 2240 2507 2789 3086",
    "12 15 32 80 197 451 940 1782 3097 4986 7515 10715 14612 19304 25105 32779 43890 61297 89826 137154 214943",
    "8 27 57 116 236 463 857 1492 2456 3851 5793 8412 11852 16271 21841 28748 37192 47387 59561 73956 90828",
    "17 39 70 123 232 465 948 1910 3761 7214 13472 24547 43889 77697 137546 245226 440843 795256 1428293 2536897 4448110",
    "6 25 49 81 138 258 514 1045 2123 4286 8581 16999 33314 64915 127152 253782 521352 1103663 2388049 5213473 11340118",
    "15 22 48 108 222 431 826 1607 3209 6554 13507 27623 55262 107123 200271 361049 630542 1077985 1836685 3197221 5833573",
    "9 10 13 14 11 14 57 214 641 1713 4411 11251 28247 68675 159767 353925 746617 1503812 2902641 5389948 9664531",
    "19 30 45 73 127 228 408 724 1318 2589 5582 12746 29268 65253 139091 282431 547269 1015752 1813403 3126583 5225125",
    "16 20 29 55 129 311 712 1553 3307 7003 14827 31254 65116 133287 267071 522905 999563 1864490 3391876 6014067 10385116",
    "2 -7 -23 -41 -38 37 273 807 1834 3617 6497 10903 17362 26509 39097 56007 78258 107017 143609 189527 246442",
    "15 22 29 41 69 142 334 816 1954 4492 9890 20944 42922 85648 167321 321469 609457 1142602 2120483 3895851 7082139",
    "-1 -10 -21 -18 40 232 698 1683 3612 7213 13728 25306 45799 82489 150000 279284 538074 1076412 2225283 4704589 10050857",
    "-4 -10 -18 -28 -35 -18 87 447 1444 3852 9073 19389 38127 69546 118134 186844 273596 365122 426928 387786 116745",
    "1 13 37 84 190 444 1033 2304 4840 9544 17725 31197 52476 85390 137021 223308 383639 715667 1452493 3123430 6871382",
    "-4 -2 10 35 76 136 218 325 460 626 826 1063 1340 1660 2026 2441 2908 3430 4010 4651 5356",
    "11 7 -1 -12 -25 -39 -53 -66 -77 -85 -89 -88 -81 -67 -45 -14 27 79 143 220 311",
    "16 24 27 30 51 126 327 799 1815 3834 7516 13592 22403 32809 40023 31750 -18103 -158498 -471154 -1071166 -2065238",
    "4 21 58 122 227 408 749 1434 2836 5683 11399 22831 45762 91910 184594 369052 730792 1427817 2746864 5201140 9699217",
    "16 33 63 118 209 342 516 733 1051 1749 3734 9417 24442 60908 143137 317692 670346 1354185 2635169 4964488 9091191",
    "11 20 38 69 119 197 312 472 701 1108 2076 4697 11669 29001 69050 155648 332375 675404 1312794 2452645 4423163",
    "10 14 18 32 96 301 813 1907 4040 8034 15525 29998 59020 118782 242925 499187 1020334 2061362 4105208 8057644 15603992",
    "7 20 41 70 104 142 207 402 1035 2880 7693 19179 44724 98427 206472 417101 820287 1588368 3061397 5924796 11570032",
    "4 16 46 109 232 472 956 1952 3994 8110 16239 31970 61792 117108 217337 394505 699808 1212716 2053276 3398363 5502720",
    "26 39 56 82 121 184 315 656 1594 4068 10170 24277 55162 119964 251726 513673 1025774 2012673 3886936 7387644 13801107",
    "3 2 1 0 -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 -11 -12 -13 -14 -15 -16 -17",
    "1 6 25 73 167 341 680 1377 2814 5665 11015 20479 36279 61179 98065 148758 211323 274636 308233 244417 -51845",
    "7 29 77 175 369 743 1445 2726 4995 8893 15389 25901 42445 67815 105797 161420 241247 353709 509485 721931 1007561",
    "22 35 48 61 74 87 100 113 126 139 152 165 178 191 204 217 230 243 256 269 282",
    "6 1 -4 -9 -14 -19 -24 -29 -34 -39 -44 -49 -54 -59 -64 -69 -74 -79 -84 -89 -94",
    "11 36 79 151 269 457 759 1277 2247 4166 7983 15367 29065 53363 94663 162189 268835 432168 675599 1029735 1533925",
    "8 4 -8 -27 -34 26 266 885 2220 4879 10095 20601 42610 89951 192129 409116 857116 1751451 3475128 6684512 12466550",
    "21 48 95 172 291 470 745 1193 1979 3471 6526 13143 27827 60277 130556 279024 585537 1206562 2446161 4889006 9643099",
    "16 25 43 93 225 531 1171 2431 4846 9450 18274 35317 68393 132584 256690 495465 953348 1831239 3518957 6776005 13077649",
    "17 32 50 83 153 296 571 1074 1957 3452 5900 9785 15773 24756 37901 56704 83049 119272 168230 233375 318833",
    "15 41 92 173 294 480 788 1338 2379 4446 8722 17800 37143 77674 160140 322316 631027 1202867 2241168 4103331 7423512",
    "10 28 70 157 328 649 1220 2177 3692 5989 9418 14662 23194 38152 65860 118292 216854 397946 720862 1278691 2212996",
    "9 22 54 108 197 357 667 1290 2559 5148 10391 20847 41279 80390 154106 292254 552762 1052003 2028105 3968007 7851354",
    "-9 1 20 46 95 223 555 1321 2899 5865 11050 19604 33067 53447 83305 125847 185023 265633 373440 515290 699239",
    "9 26 71 162 317 548 866 1325 2149 4001 8463 18793 40994 85147 166798 307943 536900 886355 1389742 2079103 2994882",
    "28 41 59 93 169 339 690 1356 2547 4618 8210 14504 25638 45346 79887 139341 239358 403455 665965 1075751 1700807",
    "-2 9 47 139 329 683 1301 2348 4137 7328 13358 25311 49614 99285 200148 402908 807231 1611069 3213546 6430795 12946438",
    "19 43 90 174 320 568 972 1594 2493 3709 5242 7026 8898 10562 11548 11166 8455 2127 -9494 -28538 -57660",
    "12 12 13 26 66 155 333 677 1328 2526 4653 8284 14246 23685 38141 59631 90740 134720 195597 278286 388714",
    "8 31 65 110 166 233 311 400 500 611 733 866 1010 1165 1331 1508 1696 1895 2105 2326 2558",
    "10 27 69 153 308 595 1155 2299 4654 9379 18465 35133 64344 113435 192895 317295 506386 786379 1191421 1765281 2563260",
    "8 28 59 101 154 218 293 379 476 584 703 833 974 1126 1289 1463 1648 1844 2051 2269 2498",
    "5 22 59 130 264 522 1029 2034 4008 7798 14892 27949 51974 96999 184112 358605 717667 1466714 3030153 6262196 12835776",
    "21 25 31 54 123 285 609 1190 2153 3657 5899 9118 13599 19677 27741 38238 51677 68633 89751 115750 147427",
    "12 13 20 45 102 210 414 844 1841 4201 9636 21638 47071 99020 201708 398665 765810 1431701 2607932 4633523 8038172",
    "24 38 52 66 80 94 108 122 136 150 164 178 192 206 220 234 248 262 276 290 304",
    "23 34 41 44 43 38 29 16 -1 -22 -47 -76 -109 -146 -187 -232 -281 -334 -391 -452 -517",
    "-10 -2 34 116 266 512 899 1528 2651 4869 9519 19415 40283 83642 172850 356227 735942 1531350 3215650 6804080 14446002",
    "6 18 37 58 86 150 335 844 2108 4981 11097 23545 48168 96068 188401 365462 703738 1347664 2568293 4870656 9187810",
    "4 5 25 75 166 320 596 1144 2313 4873 10491 22771 49495 107288 230943 491377 1029170 2115773 4263265 8418391 16301188",
    "1 -8 -10 15 110 361 933 2132 4500 8944 16898 30544 53235 90606 153713 267462 491595 969324 2033158 4422897 9713628",
    "18 33 59 97 148 213 293 389 502 633 783 953 1144 1357 1593 1853 2138 2449 2787 3153 3548"
};

class History {
public:
    History(const string _input)
        : input(_input)
    {
        auto parsedinput(stringtovector(input, ' '));
        for (auto e : parsedinput)
            history.push_back(stol(e));

        differences.push_back(getDifferences(history));

        while ( !checkZero(differences.back()) )
            differences.push_back(getDifferences(differences.back()));

        extrapolate();
    }

    vector<long> getDifferences(const vector<long> &hist)
    {
        vector<long> ret;
        for ( long i=1; i<hist.size(); ++i)
            ret.push_back(hist[i]-hist[i-1]);

        return ret;
    }

    bool checkZero( const vector<long> &hist)
    {
        for ( auto e: hist)
            if (0!= e)
                return false;
        return true;
    }

    void extrapolate()
    {
        long epvalue = 0;
        for (auto v = differences.rbegin(); v != differences.rend(); ++v) {
            auto lastvalue = v->back();
            epvalue = lastvalue + epvalue;
            v->push_back(epvalue);
        }

        history.push_back(history.back() + epvalue);
    }

    long getResultA()
    {
        long resultA = history.back();

        return resultA;
    }

    long getResultB()
    {
        long resultB = 0;

        return resultB;
    }

    string getString() { return input; }

    friend bool operator<(const History& l, const History& r)
    {
        return l.input < r.input;
    }

private:
    string input;
    vector<long> history;
    vector<vector<long>> differences;

    friend class MirageMaintenance;
};

class MirageMaintenance {
public:
    MirageMaintenance(const vector<string>& _input)
        : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input)
            Historys.push_back(History(elem));
    }

    long getResultA()
    {
        long resultA = 0;
        for (auto e : Historys)
            resultA += e.getResultA();

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = 0;
        for (auto e : Historys)
            resultB += e.getResultB();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    vector<History> Historys;
};

TEST_CASE("Testdata")
{
    MirageMaintenance MirageMaintenanceData(inputTestdata);
    REQUIRE(114 == MirageMaintenanceData.getResultA());
    REQUIRE(0 == MirageMaintenanceData.getResultB());
}

TEST_CASE("MirageMaintenance")
{
    MirageMaintenance MirageMaintenanceData(inputData);
    REQUIRE(0 == MirageMaintenanceData.getResultA());
    REQUIRE(0 == MirageMaintenanceData.getResultB());
}