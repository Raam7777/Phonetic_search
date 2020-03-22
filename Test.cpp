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
    /* Add more checks here */
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
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
