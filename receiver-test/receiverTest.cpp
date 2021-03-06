#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "../receiver/functions.h"

using namespace functions;

TEST_CASE("remove number from given string") {
    string str="12testing282 number93 removal1",str2="testing 282another number93 removal2";
    functions::removeNums(str);functions::removeNums(str2);
    REQUIRE( str  == "testing number removal");
    REQUIRE( str2 == "testing another number removal");
}

TEST_CASE("remove special characters from given string") {
    string str="test[ing s^peci]al charac(ter removal 1",str2="te%sting spec#ial chara!cter re[moval 2";
    functions::removeSpecialChar(str);functions::removeSpecialChar(str2);
    REQUIRE( str  == "testing special character removal 1");
    REQUIRE( str2 == "testing special character removal 2");
}

TEST_CASE("converting from upper case to lower") {
    string str="CoNvErTiNg To LoWeR CaSE",str2="ChEcK aNoTHeR StrING";
    functions::ToLowerChar(str);functions::ToLowerChar(str2);
    REQUIRE( str  == "converting to lower case");
    REQUIRE( str2 == "check another string");
}



 TEST_CASE("Removing leading and trailing spaces in the string")
 {
     string str="   Check removing leading space",str2="Check removing trailing space   ";
     functions::trim(str);functions::trim(str2);
    REQUIRE( str  == "Check removing leading space");
    REQUIRE( str2 == "Check removing trailing space");
 }

SCENARIO("Removing stop words and insert non stop-words into map")
{
    GIVEN("string which has stop-words and non stop-words,  a map to insert")
    {
        string s1="don't remove stop word when i call this function";
        unordered_map<string, int> m;
        
        WHEN("removeStopWords FUNCTION called")
        {
            removeStopWords(s1,m);
        
            THEN("pushIntoMap FUNCTION also called within removeStopWords FUNCTION")
            {
                REQUIRE(m.find("don't")==m.end());
                REQUIRE(m.find("remove")!=m.end());
                REQUIRE(m.find("stop")!=m.end());
                REQUIRE(m.find("word")!=m.end());
                REQUIRE(m.find("when")==m.end());
                REQUIRE(m.find("i")==m.end());
                REQUIRE(m.find("call")!=m.end());
                REQUIRE(m.find("this")==m.end());
                REQUIRE(m.find("function")!=m.end());
            }
        }
    }
}
SCENARIO("Pushing Words into unordered map")
{
	GIVEN("string and unordered_map")
	{
	unordered_map<string, int> m ;
	unordered_map<string, int>::iterator it;
	string s="testing";
		WHEN("insert string into map for first time")
		{
		pushIntoMap( s,  m);
			THEN("the given string is inserted into map")
			{
				REQUIRE(m.find("testing") != m.end());
			}
		}
		
		WHEN("insert string into map which is already present in map")
		{
		pushIntoMap( s,  m);pushIntoMap( s,  m);

			THEN("the corresponding count of given string is increased by 1")
			{
				it=m.find("testing");int val =2;
				REQUIRE(it->second == val);
			}
		}
		
	}

}
TEST_CASE("CSV file creation and values inserted into that file from given unordered map")
{
    unordered_map<string, int> m = { {"abc", 100} };
    printMapAndCreateCSV(m);
    ifstream file("./output.csv", ios::in);
    string str;
    getline(file,str);
    REQUIRE(str == "abc,100");
}
