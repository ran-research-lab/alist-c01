#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() 
#include "catch.hpp"
#include "List.h"
#include "AList.h"
#include <vector>

using namespace std;


int highestFrequency( const vector<int> &v ) {
    return 0;
}

TEST_CASE( "Testing the highestFrequency() function", "[highestFrequency]" ) {
    //REQUIRE( highestFrequency(vector<int> {100, 45, 98, 45, 78, 45})  == 3);
    AList L;
    L.append(10);
    L.append(20);
    CHECK(L.to_string()=="<|10,20>");
    L.next();
    CHECK(L.to_string()=="<10|20>");
    L.next();
    CHECK(L.to_string()=="<10,20|>");
    L.next();
    CHECK(L.to_string()=="<10,20|>");
    L.append(30);
    CHECK(L.to_string()=="<10,20|30>");
    L.remove();
    CHECK(L.to_string()=="<10,20|>");
    L.prev();
    L.prev();
    L.remove();
    CHECK(L.to_string()=="<|20>");
    L.append(40); L.append(50); L.append(60);
    L.moveToPos(4);
    CHECK(L.to_string()=="<20,40,50,60|>");

}
