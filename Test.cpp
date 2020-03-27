/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
	string text = "xxx happy yyy";
	CHECK(find(text, "happy") == string("happy"));
	CHECK(find(text, "habby") == string("happy"));
	CHECK(find(text, "hapby") == string("happy"));
	CHECK(find(text, "habpy") == string("happy"));
	text = "xxx beeper yyy";
	CHECK(find(text, "peeper") == string("beeper"));
	CHECK(find(text, "peeber") == string("beeper"));
	CHECK(find(text, "beeber") == string("beeper"));
	text = "xxx habpy yyy";
	CHECK(find(text, "happy") == string("habpy"));
	CHECK(find(text, "hapby") == string("habpy"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
	string text = "Happi xxx yyy";
	CHECK(find(text, "happi") == string("Happi"));
	CHECK(find(text, "Happi") == string("Happi"));
	CHECK(find(text, "HAPPI") == string("Happi"));
	CHECK(find(text, "HaPpI") == string("Happi"));
	CHECK(find(text, "haPpi") == string("Happi"));
	CHECK(find(text, "hApPI") == string("Happi"));
	text = "xxx beeper yyy";
	CHECK(find(text, "BeePer") == string("beeper"));
	CHECK(find(text, "Beeper") == string("beeper"));
	CHECK(find(text, "beePer") == string("beeper"));
	CHECK(find(text, "BEePeR") == string("beeper"));
	CHECK(find(text, "BeEpEr") == string("beeper"));
	CHECK(find(text, "BEEPER") == string("beeper"));
	CHECK(find(text, "BEEpER") == string("beeper"));
	CHECK(find(text, "BeePEr") == string("beeper"));
	CHECK(find(text, "beEpER") == string("beeper"));
}

TEST_CASE("Test replacement of b and f") {
	string text = "banana for breakfast";
	CHECK(find(text, "fanana") == string("banana"));
	CHECK(find(text, "bor") == string("for"));
	CHECK(find(text, "freakfast") == string("breakfast"));
	CHECK(find(text, "breakbast") == string("breakfast"));
	CHECK(find(text, "freakbast") == string("breakfast"));
	text = "xxx yyy freakbast";
	CHECK(find(text, "breakfast") == string("freakbast"));
	CHECK(find(text, "breakbast") == string("freakbast"));
	CHECK(find(text, "freakfast") == string("freakbast"));
	text = "xxx facebook website";
	CHECK(find(text, "bacebook") == string("facebook"));
	CHECK(find(text, "facefook") == string("facebook"));
	CHECK(find(text, "bacefook") == string("facebook"));
	CHECK(find(text, "wefsite") == string("website"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
	string text = "banana for breakfast";
	CHECK(find(text, "bANaNA") == string("banana"));
	CHECK(find(text, "BANANA") == string("banana"));
	CHECK(find(text, "Banana") == string("banana"));
	CHECK(find(text, "For") == string("for"));
	CHECK(find(text, "FOR") == string("for"));
	CHECK(find(text, "BREAKFAST") == string("breakfast"));
	CHECK(find(text, "bREaKfAsT") == string("breakfast"));;
	CHECK(find(text, "BreakFast") == string("breakfast"));
	text = "xxx facebook website";
	CHECK(find(text, "FACEBOOK") == string("facebook"));
	CHECK(find(text, "FaceBook") == string("facebook"));
	CHECK(find(text, "fACEbOOK") == string("facebook"));
	CHECK(find(text, "weBsite") == string("website"));
	CHECK(find(text, "WEbSITE") == string("website"));
	CHECK(find(text, "WEBSITE") == string("website"));
	text = "xxx yyy freakbast";
	CHECK(find(text, "FREAKBAST") == string("freakbast"));
	CHECK(find(text, "fREAKbAST") == string("freakbast"));
	CHECK(find(text, "FreakBast") == string("freakbast"));
	CHECK(find(text, "FrEaKbAsT") == string("freakbast"));

}

TEST_CASE("Test replacement of f and p") {
	string text = "popcorn for supper";
	CHECK(find(text, "fopcorn") == string("popcorn"));
	CHECK(find(text, "pofcorn") == string("popcorn"));
	CHECK(find(text, "fofcorn") == string("popcorn"));
	CHECK(find(text, "por") == string("for"));
	CHECK(find(text, "sufper") == string("supper"));
	CHECK(find(text, "supfer") == string("supper"));
	CHECK(find(text, "suffer") == string("supper"));
	text = "fofcorn xxx yyyy";
	CHECK(find(text, "popcorn") == string("fofcorn"));
	CHECK(find(text, "fopcorn") == string("fofcorn"));
	CHECK(find(text, "pofcorn") == string("fofcorn"));
	text = "xxx suffer yyy";
	CHECK(find(text, "supper") == string("suffer"));
	CHECK(find(text, "supfer") == string("suffer"));
	CHECK(find(text, "sufper") == string("suffer"));
	text = "xxx supfer yyy";
	CHECK(find(text, "supper") == string("supfer"));
	CHECK(find(text, "suffer") == string("supfer"));
	CHECK(find(text, "sufper") == string("supfer"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
	string text = "popcorn for supper";
	CHECK(find(text, "POPCORN") == string("popcorn"));
	CHECK(find(text, "PoPcorn") == string("popcorn"));
	CHECK(find(text, "pOpCORN") == string("popcorn"));
	CHECK(find(text, "PoPcOrN") == string("popcorn"));
	CHECK(find(text, "pOpCoRN") == string("popcorn"));
	CHECK(find(text, "For") == string("for"));
	CHECK(find(text, "fOR") == string("for"));
	CHECK(find(text, "FOR") == string("for"));
	CHECK(find(text, "SUPPER") == string("supper"));
	CHECK(find(text, "suPPer") == string("supper"));
	CHECK(find(text, "SUppER") == string("supper"));
	CHECK(find(text, "SuPpEr") == string("supper"));
	CHECK(find(text, "sUpPeR") == string("supper"));
	text = "fofcorn xxx yyyy";
	CHECK(find(text, "FoFcorn") == string("fofcorn"));
	CHECK(find(text, "FOFCORN") == string("fofcorn"));
	CHECK(find(text, "fOfCORN") == string("fofcorn"));
	text = "xxx suffer yyy";
	CHECK(find(text, "SUFFER") == string("suffer"));
	CHECK(find(text, "suFFer") == string("suffer"));
	CHECK(find(text, "SUffER") == string("suffer"));
	text = "PopCorn for suPPer";
	CHECK(find(text, "SUPPER") == string("suPPer"));
	CHECK(find(text, "supper") == string("suPPer"));
	CHECK(find(text, "POPCORN") == string("PopCorn"));
	CHECK(find(text, "popcorn") == string("PopCorn"));
}

TEST_CASE("Test replacement of v and w") {
	string text = "we use windows";
	CHECK(find(text, "ve") == string("we"));
	CHECK(find(text, "vindows") == string("windows"));
	CHECK(find(text, "windovs") == string("windows"));
	CHECK(find(text, "vindovs") == string("windows"));
	text = "xxx yyy vindows";
	CHECK(find(text, "windows") == string("vindows"));
	CHECK(find(text, "vindovs") == string("vindows"));
	CHECK(find(text, "windovs") == string("vindows"));
}

TEST_CASE("Test replacement of g and j") {
	string text = "xxx google gallery";
	CHECK(find(text, "joogle") == string("google"));
	CHECK(find(text, "goojle") == string("google"));
	CHECK(find(text, "joojle") == string("google"));
	CHECK(find(text, "jallery") == string("gallery"));
	text = "xxx joojle yyy";
	CHECK(find(text, "google") == string("joojle"));
	CHECK(find(text, "joogle") == string("joojle"));
	CHECK(find(text, "goojle") == string("joojle"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
	string text = "xxx google gallery";
	CHECK(find(text, "GOogLe") == string("google"));
	CHECK(find(text, "GooJle") == string("google"));
	CHECK(find(text, "JoOJlE") == string("google"));
	CHECK(find(text, "jAlLEry") == string("gallery"));
	text = "xxx joojle yyy";
	CHECK(find(text, "GOOGLE") == string("joojle"));
	CHECK(find(text, "JooGLe") == string("joojle"));
	CHECK(find(text, "GooJle") == string("joojle"));
	text = "xxx GooGle GallEry";
	CHECK(find(text, "joogle") == string("GooGle"));
	CHECK(find(text, "GOOjle") == string("GooGle"));
	CHECK(find(text, "jOOJLe") == string("GooGle"));
	CHECK(find(text, "JallERY") == string("GallEry"));
	text = "xxx JooJle yyy";
	CHECK(find(text, "gOOGLe") == string("JooJle"));
	CHECK(find(text, "joOGle") == string("JooJle"));
	CHECK(find(text, "GOOGLE") == string("JooJle"));
}

TEST_CASE("Test replacement of c and k") {
	string text = "xxx accident yyy";
	CHECK(find(text, "akkident") == string("accident"));
	CHECK(find(text, "akcident") == string("accident"));
	CHECK(find(text, "ackident") == string("accident"));
	text = "xxx clock yyy";
	CHECK(find(text, "clokc") == string("clock"));
	CHECK(find(text, "klock") == string("clock"));
	CHECK(find(text, "klokc") == string("clock"));
	text = "xxx klokc yyy";
	CHECK(find(text, "clock") == string("klokc"));
	CHECK(find(text, "clokc") == string("klokc"));
	CHECK(find(text, "klock") == string("klokc"));
	text = "xxx ackident yyy";
	CHECK(find(text, "accident") == string("ackident"));
	CHECK(find(text, "akkident") == string("ackident"));
	CHECK(find(text, "akcident") == string("ackident"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
	string text = "xxx accident yyy";
	CHECK(find(text, "aCCident") == string("accident"));
	CHECK(find(text, "aKCIDEnt") == string("accident"));
	CHECK(find(text, "AcKiDeNt") == string("accident"));
	text = "xxx clock yyy";
	CHECK(find(text, "CLOCK") == string("clock"));
	CHECK(find(text, "KlOcK") == string("clock"));
	CHECK(find(text, "KLokC") == string("clock"));
	text = "xxx KlokC yyy";
	CHECK(find(text, "ClOck") == string("KlokC"));
	CHECK(find(text, "cLOKc") == string("KlokC"));
	CHECK(find(text, "KloCK") == string("KlokC"));
	text = "xxx aCKidEnt yyy";
	CHECK(find(text, "ACCIDENT") == string("aCKidEnt"));
	CHECK(find(text, "aKkIdEnT") == string("aCKidEnt"));
	CHECK(find(text, "AkCiDeNt") == string("aCKidEnt"));
}

TEST_CASE("Test replacement of c and q") {
	string text = "xxx quickly yyy";
	CHECK(find(text, "cuiqkly") == string("quickly"));
	CHECK(find(text, "quiqkly") == string("quickly"));
	CHECK(find(text, "cuiqkly") == string("quickly"));
	text = "xxx accident yyy";
	CHECK(find(text, "aqqident") == string("accident"));
	CHECK(find(text, "aqcident") == string("accident"));
	CHECK(find(text, "acqident") == string("accident"));
	text = "xxx cuickly yyy";
	CHECK(find(text, "quickly") == string("cuickly"));
	CHECK(find(text, "cuiqkly") == string("cuickly"));
	CHECK(find(text, "quiqkly") == string("cuickly"));
	text = "xxx aqcident yyy";
	CHECK(find(text, "accident") == string("aqcident"));
	CHECK(find(text, "acqident") == string("aqcident"));
	CHECK(find(text, "aqqident") == string("aqcident"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
	string text = "xxx quickly yyy";
	CHECK(find(text, "CUiQKlY") == string("quickly"));
	CHECK(find(text, "qUiQkLy") == string("quickly"));
	CHECK(find(text, "CuIqKlY") == string("quickly"));
	text = "xxx accident yyy";
	CHECK(find(text, "aCCident") == string("accident"));
	CHECK(find(text, "aQCiDEnt") == string("accident"));
	CHECK(find(text, "ACQIDENT") == string("accident"));
	text = "xxx QuICKly yyy";
	CHECK(find(text, "quickly") == string("QuICKly"));
	CHECK(find(text, "CuIqKLy") == string("QuICKly"));
	CHECK(find(text, "QUiQklY") == string("QuICKly"));
	text = "xxx aQCIdENT yyy";
	CHECK(find(text, "accident") == string("aQCIdENT"));
	CHECK(find(text, "AcQiDeNt") == string("aQCIdENT"));
	CHECK(find(text, "aQQident") == string("aQCIdENT"));
}

TEST_CASE("Test replacement of k and q") {
	string text = "xxx quickly yyy";
	CHECK(find(text, "kuicqly") == string("quickly"));
	CHECK(find(text, "quicqly") == string("quickly"));
	CHECK(find(text, "kuickly") == string("quickly"));
	text = "xxx clock yyy";
	CHECK(find(text, "clocq") == string("clock"));
	text = "xxx kuicqly yyy";
	CHECK(find(text, "quickly") == string("kuicqly"));
	CHECK(find(text, "kuickly") == string("kuicqly"));
	CHECK(find(text, "quicqly") == string("kuicqly"));
	text = "xxx clocq yyy";
	CHECK(find(text, "clock") == string("clocq"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
	string text = "xxx quickly yyy";
	CHECK(find(text, "QUICQLY") == string("quickly"));
	CHECK(find(text, "qUIcQly") == string("quickly"));
	CHECK(find(text, "KuIcKlY") == string("quickly"));
	text = "xxx clock yyy";
	CHECK(find(text, "ClOcK") == string("clock"));
	CHECK(find(text, "ClOCK") == string("clock"));
	CHECK(find(text, "clOck") == string("clock"));
	text = "xxx KuicQly yyy";
	CHECK(find(text, "quickly") == string("KuicQly"));
	CHECK(find(text, "KuIcKlY") == string("KuicQly"));
	CHECK(find(text, "Quicqly") == string("KuicQly"));
	text = "xxx CLOCQ yyy";
	CHECK(find(text, "CLOCK") == string("CLOCQ"));
	CHECK(find(text, "clock") == string("CLOCQ"));
	CHECK(find(text, "clOcK") == string("CLOCQ"));
}


TEST_CASE("Test replacement of s and z") {
    string text = "xxx SOS yyy";
    CHECK(find(text, "SOS") == string("SOS"));
    CHECK(find(text, "ZOS") == string("SOS"));
    CHECK(find(text, "ZOZ") == string("SOS"));
    CHECK(find(text, "SOZ") == string("SOS"));
    text = "xxx ZOS yyy";
    CHECK(find(text, "SOS") == string("ZOS"));
    CHECK(find(text, "ZOS") == string("ZOS"));
    CHECK(find(text, "ZOZ") == string("ZOS"));
    CHECK(find(text, "SOZ") == string("ZOS"));
    text = "xxx ZOZ yyy";
    CHECK(find(text, "SOS") == string("ZOZ"));
    CHECK(find(text, "ZOS") == string("ZOZ"));
    CHECK(find(text, "ZOZ") == string("ZOZ"));
    CHECK(find(text, "SOZ") == string("ZOZ"));
    text = "xxx SOZ yyy";
    CHECK(find(text, "SOS") == string("SOZ"));
    CHECK(find(text, "ZOS") == string("SOZ"));
    CHECK(find(text, "ZOZ") == string("SOZ"));
    CHECK(find(text, "SOZ") == string("SOZ"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "xxx SOS yyy";
    CHECK(find(text, "sOS") == string("SOS"));
    CHECK(find(text, "soS") == string("SOS"));
    CHECK(find(text, "SoS") == string("SOS"));
    CHECK(find(text, "SOs") == string("SOS"));
    CHECK(find(text, "sos") == string("SOS"));
    CHECK(find(text, "SOS") == string("SOS"));
    CHECK(find(text, "sOs") == string("SOS"));
    CHECK(find(text, "Sos") == string("SOS"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "Dont touch me";
    CHECK(find(text, "Dont") == string("Dont"));
    CHECK(find(text, "Tont") == string("Dont"));
    CHECK(find(text, "Tond") == string("Dont"));
    CHECK(find(text, "Dond") == string("Dont"));
    CHECK(find(text, "touch") == string("touch"));
    CHECK(find(text, "douch") == string("touch"));
    text = "Dond douch me";
    CHECK(find(text, "Dont") == string("Dond"));
    CHECK(find(text, "Tont") == string("Dond"));
    CHECK(find(text, "Tond") == string("Dond"));
    CHECK(find(text, "Dond") == string("Dond"));
    CHECK(find(text, "touch") == string("douch"));
    CHECK(find(text, "douch") == string("douch"));
    text = "Tont touch me";
    CHECK(find(text, "Dont") == string("Tont"));
    CHECK(find(text, "Tont") == string("Tont"));
    CHECK(find(text, "Tond") == string("Tont"));
    CHECK(find(text, "Dond") == string("Tont"));
    text = "Dond touch me";
    CHECK(find(text, "Dont") == string("Dond"));
    CHECK(find(text, "Tont") == string("Dond"));
    CHECK(find(text, "Tond") == string("Dond"));
    CHECK(find(text, "Dond") == string("Dond"));
    text = "Tond douch me";
    CHECK(find(text, "Dont") == string("Tond"));
    CHECK(find(text, "Tont") == string("Tond"));
    CHECK(find(text, "Tond") == string("Tond"));
    CHECK(find(text, "Dond") == string("Tond"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Dont touch me";
    CHECK(find(text, "Dont") == string("Dont"));
    CHECK(find(text, "DOnt") == string("Dont"));
    CHECK(find(text, "DONt") == string("Dont"));
    CHECK(find(text, "DONT") == string("Dont"));
    CHECK(find(text, "dONT") == string("Dont"));
    CHECK(find(text, "doNT") == string("Dont"));
    CHECK(find(text, "donT") == string("Dont"));
    CHECK(find(text, "dont") == string("Dont"));
    CHECK(find(text, "touch") == string("touch"));
    CHECK(find(text, "Touch") == string("touch"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "How are you";    
    CHECK(find(text, "How") == string("How"));
    CHECK(find(text, "Huw") == string("How"));
    CHECK(find(text, "you") == string("you"));
    CHECK(find(text, "yoo") == string("you"));
    CHECK(find(text, "yuu") == string("you"));
    CHECK(find(text, "yuo") == string("you"));
    text = "Huw are yuu";    
    CHECK(find(text, "How") == string("Huw"));
    CHECK(find(text, "Huw") == string("Huw"));
    CHECK(find(text, "you") == string("yuu"));
    CHECK(find(text, "yoo") == string("yuu"));
    CHECK(find(text, "yuu") == string("yuu"));
    CHECK(find(text, "yuo") == string("yuu"));
    text = "Huw are yuo";    
    CHECK(find(text, "you") == string("yuo"));
    CHECK(find(text, "yoo") == string("yuo"));
    CHECK(find(text, "yuu") == string("yuo"));
    CHECK(find(text, "yuo") == string("yuo"));
    text = "How are yoo";    
    CHECK(find(text, "you") == string("yoo"));
    CHECK(find(text, "yoo") == string("yoo"));
    CHECK(find(text, "yuu") == string("yoo"));
    CHECK(find(text, "yuo") == string("yoo"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "How are you";    
    CHECK(find(text, "How") == string("How"));
    CHECK(find(text, "HOw") == string("How"));
    CHECK(find(text, "HOW") == string("How"));
    CHECK(find(text, "hOW") == string("How"));
    CHECK(find(text, "hoW") == string("How"));
    CHECK(find(text, "how") == string("How"));
    CHECK(find(text, "you") == string("you"));
    CHECK(find(text, "yoU") == string("you"));
    CHECK(find(text, "yOU") == string("you"));
    CHECK(find(text, "YOU") == string("you"));
    CHECK(find(text, "You") == string("you"));
    CHECK(find(text, "YOu") == string("you"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "Why am I inside";
    CHECK(find(text, "Why") == string("Why"));
    CHECK(find(text, "Whi") == string("Why"));
    CHECK(find(text, "I") == string("I"));
    CHECK(find(text, "y") == string("I"));
    CHECK(find(text, "Y") == string("I"));
    CHECK(find(text, "inside") == string("inside"));
    CHECK(find(text, "insyde") == string("inside"));
    CHECK(find(text, "ynside") == string("inside"));
    CHECK(find(text, "ynsyde") == string("inside"));
    text = "Whi am I inside";
    CHECK(find(text, "Why") == string("Whi"));
    CHECK(find(text, "Whi") == string("Whi"));
    CHECK(find(text, "inside") == string("inside"));
    CHECK(find(text, "insyde") == string("inside"));
    CHECK(find(text, "ynside") == string("inside"));
    CHECK(find(text, "ynsyde") == string("inside"));
    text = "Why am Y insyde";
    CHECK(find(text, "I") == string("Y"));
    CHECK(find(text, "y") == string("Y"));
    CHECK(find(text, "Y") == string("Y"));
    CHECK(find(text, "inside") == string("insyde"));
    CHECK(find(text, "insyde") == string("insyde"));
    CHECK(find(text, "ynside") == string("insyde"));
    CHECK(find(text, "ynsyde") == string("insyde"));
    text = "Why am Y ynside";
    CHECK(find(text, "inside") == string("ynside"));
    CHECK(find(text, "insyde") == string("ynside"));
    CHECK(find(text, "ynside") == string("ynside"));
    CHECK(find(text, "ynsyde") == string("ynside"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Why am I inside";
    CHECK(find(text, "Why") == string("Why"));
    CHECK(find(text, "WHy") == string("Why"));
    CHECK(find(text, "WHY") == string("Why"));
    CHECK(find(text, "why") == string("Why"));
    CHECK(find(text, "I") == string("I"));
    CHECK(find(text, "i") == string("I"));
    CHECK(find(text, "inside") == string("inside"));
    CHECK(find(text, "insIde") == string("inside"));
    CHECK(find(text, "InsIde") == string("inside"));
    CHECK(find(text, "Inside") == string("inside"));
}

TEST_CASE("Test exception") {
	string text = "banana for breakfast";
	CHECK_THROWS(find(text, "banan"));
	CHECK_THROWS(find(text, "fob"));
	CHECK_THROWS(find(text, "yaara"));
	CHECK_THROWS(find(text, "break"));
	text = "xxx google gallery";
	CHECK_THROWS(find(text, "joog"));
	CHECK_THROWS(find(text, "goo"));
	CHECK_THROWS(find(text, "raam"));
	text = "xxx quickly yyy";
	CHECK_THROWS(find(text, "quic"));
	CHECK_THROWS(find(text, "ickly"));
	text = "";
    CHECK_THROWS(find(text, ""));

}
