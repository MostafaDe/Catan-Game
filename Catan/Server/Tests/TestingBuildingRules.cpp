#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include<QJsonObject>
#include"Server/RoulsOfBuildHome.h"
#include"Server/gamedata.h"
#include"Server/Tranlate.h"
#include"Server/RoulsOfBiuldRoad.h"
#include"Server/RoulOfBuildBigCity.h"


using testing::Eq;

namespace  {
class ClassDec:public testing::Test {


public:

    ClassDec(){
        QMap<Color,Player> colorToPlayer;
        if(true){
        Competitor comp1;
        Competitor comp2;
        comp1.setColor(Color::Green);
        comp2.setColor(Color::Blue);
        Player player;
        player.setColor(Color::Red);
        player.setSocketDescriptor(1);
        player.setIsTurn(true);
        colorToPlayer[Color::Red] = player;

    }
        if(true){
            Competitor comp1;
            Competitor comp2;
            comp1.setColor(Color::Red);
            comp2.setColor(Color::Blue);
            Player player;
            player.setColor(Color::Green);
            player.setSocketDescriptor(2);
            colorToPlayer[Color::Green] = player;


    }
        if(true){
            Competitor comp1;
            Competitor comp2;
            comp1.setColor(Color::Red);
            comp2.setColor(Color::Green);
            Player player;
            player.setColor(Color::Blue);
            player.setSocketDescriptor(3);
            colorToPlayer[Color::Blue] = player;

    }
        GameData::setColorToPlayer(colorToPlayer);
        Board* b = new Board1();
        GameData::setBoard(b);


    }
};
}
TEST_F(ClassDec,numberOfTheTest3){




        Tranlate trans(GameData::getBoard()->mede_neiberhod_and_get());

        RoulsOfBuildHome rule(GameData::getBoard()->mede_neiberhod_and_get());
        RoulsOfBiuldRoad rule2(GameData::getBoard()->mede_neiberhod_and_get());
        RoulOfBuildBigCity rule3(GameData::getBoard()->mede_neiberhod_and_get());
        int  a[3];
        a[0] = 19;// some number
        a[1] = 16;// some number
        a[2] = 20;// some number

        bool a1 = rule.check_make(trans.getPositionOfLand(a),"red");
        EXPECT_TRUE(a1);
        int b[2];
        b[0] = 16;  // some number
        b[1] = 20; // some number

        bool b1 = rule2.check_make(trans.getPositionOfRoad(b),"red");
        EXPECT_TRUE(b1);

        a[0] = -10 ;  // some number
        a[1] = 14; // some number
        a[2] = 18; // some number
        bool a2 = rule.check_make(trans.getPositionOfLand(a),"yellow");
        EXPECT_TRUE(a2);


        b[0] = -10;  // some number
        b[1] = 14; // some number

        bool b2 = rule2.check_make(trans.getPositionOfRoad(b),"yellow");
        EXPECT_TRUE(b2);

        a[0] = 11 ;  // some number
        a[1] = 15; // some number
        a[2] = 16; // some number
        bool a3= rule.check_make(trans.getPositionOfLand(a),"green");
        EXPECT_TRUE(a3);


        b[0] = 11;  // some number
        b[1] = 15; // some number

        bool b3 = rule2.check_make(trans.getPositionOfRoad(b),"green");
        EXPECT_TRUE(b3);
        a[0] = 11 ;  // some number
        a[1] = 6; // some number
        a[2] = 7; // some number

        bool a4= rule.check_make(trans.getPositionOfLand(a),"green");
        EXPECT_TRUE(a4);


        b[0] = 11;  // some number
        b[1] = 7; // some number

        bool b4 = rule2.check_make(trans.getPositionOfRoad(b),"green");
        EXPECT_TRUE(b4);

        a[0] = 8 ;  // some number
        a[1] = 9; // some number
        a[2] = 13; // some number
        bool a5= rule.check_make(trans.getPositionOfLand(a),"yellow");
        EXPECT_TRUE(a5);


        b[0] = 8;  // some number
        b[1] = 9; // some number

        bool b5 = rule2.check_make(trans.getPositionOfRoad(b),"yellow");
        EXPECT_TRUE(b5);

        a[0] = 12;// some number
        a[1] = 16;// some number
        a[2] = 17;// some number
        bool a6= rule.check_make(trans.getPositionOfLand(a),"red");
        EXPECT_TRUE(a6);


        b[0] = 12;// some number
        b[1] = 17;// some number

        bool b6 = rule2.check_make(trans.getPositionOfRoad(b),"red");
        EXPECT_TRUE(b6);
        a[0] = 12;// some number
        a[1] = 13;// some number
        a[2] = 17;// some number
        bool a7= rule.check_make(trans.getPositionOfLand(a),"red");
        EXPECT_FALSE(a7);


        b[0] = 12;// some number
        b[1] = 13;// some number

        bool b7 = rule2.check_make(trans.getPositionOfRoad(b),"red");
        EXPECT_TRUE(b7);

        a[0] = 12;// some number
        a[1] = 13;// some number
        a[2] = 8;// some number
        bool a8= rule.check_make(trans.getPositionOfLand(a),"red");
        EXPECT_FALSE(a8);

        b[0] = 12;// some number
        b[1] = 7;// some number
        bool b9 = rule2.check_make(trans.getPositionOfRoad(b),"green");
        EXPECT_TRUE(b9);

        a[0] = 4;// some number
        a[1] = 7;// some number
        a[2] = 8;// some number
        bool a9= rule.check_make(trans.getPositionOfLand(a),"red");

        EXPECT_FALSE(a9);
        a[0] = 12;// some number
        a[1] = 7;// some number
        a[2] = 8;// some number
        bool a11= rule.check_make(trans.getPositionOfLand(a),"red");
        EXPECT_FALSE(a11);

        a[0] = 12;// some number
        a[1] = 7;// some number
        a[2] = 8;// some number
        bool a10= rule.check_make(trans.getPositionOfLand(a),"green");
        EXPECT_TRUE(a10);
        a[0] = 12;// some number
        a[1] = 16;// some number
        a[2] = 17;// some number
        bool a12= rule3.check_make(trans.getPositionOfLand(a),"yellow");
        EXPECT_FALSE(a12);

        b[0] = 8;// some number
        b[1] = 7;// some number
        bool b10 = rule2.check_make(trans.getPositionOfRoad(b),"red");
        EXPECT_FALSE(b10);

        b[0] = 8;// some number
        b[1] = 7;// some number
        bool b11 = rule2.check_make(trans.getPositionOfRoad(b),"green");
        EXPECT_TRUE(b11);

        a[0] = 8;// some number
        a[1] = 9;// some number
        a[2] = 13;// some number
        bool a13= rule3.check_make(trans.getPositionOfLand(a),"red");
        EXPECT_FALSE(a13);

        a[0] = 8;// some number
        a[1] = 9;// some number
        a[2] = 13;// some number
        bool a14= rule3.check_make(trans.getPositionOfLand(a),"yellow");
        EXPECT_TRUE(a14);






















}
