#ifndef POSITION_FOR_GRAOHICS_H
#define POSITION_FOR_GRAOHICS_H

#include<QMap>
#include<QString>

struct position_for_graphics{
    double x,y;
};

class positions{
public:
    positions();
    QMap<QString, position_for_graphics> map_l;

};

inline positions::positions()
{
    map_l.insert("1",{348,73});
    map_l.insert("2",{405,73});
    map_l.insert("28",{522,73});
    map_l.insert("26",{551,124});
    map_l.insert("27",{609,124});
    map_l.insert("3",{348,174});
    map_l.insert("4",{405,174});
    map_l.insert("5",{464,174});
    map_l.insert("25",{580,174});
    map_l.insert("6",{319,224});
    map_l.insert("7",{377,224});
    map_l.insert("8",{435,224});
    map_l.insert("9",{493,224});
    map_l.insert("24",{609,224});
    map_l.insert("10",{290,274});
    map_l.insert("11",{348,274});
    map_l.insert("12",{405,274});
    map_l.insert("13",{464,274});
    map_l.insert("14",{522,274});
    map_l.insert("15",{319,324});
    map_l.insert("16",{377,324});
    map_l.insert("17",{435,324});
    map_l.insert("18",{493,324});
    map_l.insert("23",{609,324});
    map_l.insert("19",{348,374});
    map_l.insert("20",{405,374});
    map_l.insert("21",{464,374});
    map_l.insert("22",{580,374});

    map_l.insert("-1",{261,224});
    map_l.insert("-2",{290,174});
    map_l.insert("-3",{319,124});
    map_l.insert("-4",{377,124});
    map_l.insert("-5",{435,124});
    map_l.insert("-6",{493,124});
    map_l.insert("-7",{522,174});
    map_l.insert("-8",{551,224});
    map_l.insert("-9",{580,274});
    map_l.insert("-10",{551,324});
    map_l.insert("-11",{522,374});
    map_l.insert("-12",{493,424});
    map_l.insert("-36",{435,424});
    map_l.insert("-35",{377,424});
    map_l.insert("-34",{319,424});
    map_l.insert("-33",{290,375});
    map_l.insert("-32",{261,325});
    map_l.insert("-31",{232,275});



}


#endif // POSITION_FOR_GRAOHICS_H
